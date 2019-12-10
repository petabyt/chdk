# Ghidra python script to import function and variable definitions from CHDK "stubs" files
#
# This script prompts for a platform/sub directory, looks for any of
#  stubs_entry.S, stubs_entry.err.S, stubs_min.S func_by_address.csv
# and prompts for which ones to load.
#
# It then attempts to create labels for the loaded function and variable definitions, and start disassembly on the
# functions if they aren't already disassembled. By default, it also attempts to copy EOL comments from stubs,
# and clean up incorrect data definitions related to thumb pointers. This can be controlled with options
# described below.
# 
# Variable definitions require that you have created a memory map with the appropriate address space.
#
# It currently loads but does not do anything with DEF_CONST values
#
# Some behavior can be controlled by an ini format configuration file, which is created automatically in the same
# directory as the script if not present. The default cfg includes a description of each option, and can be
# created by just running the script and cancelling.
#
# By default, if multiple different names refer to the same address, the script creates multiple labels. This is
# convenient since you can jump to any of them, and see in the listing when multiple names refer to the same
# function. 
# The create_dupe_names option controls this.
#
# There are also options to handle conflicts where one name refers to multiple addresses, both in the stubs files
# (generally from the csv, where tasks or eventprocs can appear defined with multiple addresses) and pre-existing
# labels in the Ghidra program (e.g from previous runs with different stubs)
#
# The default is for stubs conflicts (same name with two different addresses) to be named with a suffix like
#  _stubs_<address>.
# The conflict_stubs option controls this.
#
# For conflicts between the incoming stubs and the existing program, the default is to delete the one in the program,
# so if you had a stub wrong, running the script again with corrected stubs will update it.
# The conflict_names option controls this.
#
# By default, comments from stubs files that don't look like auto generated match type or score will be added to the
# program as pre-comments. Any existing comment of the same type will be overwritten. This can be controlled with the
# stubs_comments and stubs_comments_type options
#
# The script also tries to fix up an issue I noticed on thumb2 firmware, where the analysis can end up creating data
# at the second byte of a thumb function if it happens to look like a string, do to interpreting a thumb pointer as a
# possible data address.
# The clean_thumb_data option controls this.
#
#@category CHDK
#@author reyalp

# License: GPL
#
# Copyright 2019 reyalp (at) gmail.com
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version 2
# of the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# with CHDK. If not, see <http://www.gnu.org/licenses/>.


import os
import csv
import re
from java.math import BigInteger 
import ghidra.program.model.symbol as ProgramSymbol

# to set verbosity
import chdklib.logutil
from chdklib.logutil import infomsgf, warnf
import chdklib.stubs_loader as stubs_loader
import chdklib.optionsutil as optionsutil

# for thumb "register" value
progCtx = currentProgram.getProgramContext()
tmodeReg = progCtx.getRegister("TMode")

# global options, filled by init_options
g_options = {
# quick overrides for testing
    'skip_create_config':False,
    'skip_load_config':False,
}

# options defaults, descriptions
# used directly if skip_load_config
g_options_spec = [
    {
        'name':'clean_thumb_data',
        'type':'bool',
        'default':True,
        'desc':"""\
# Undefine data +1 from thumb func adr
""",
    },
    {
        'name':'create_dupe_names',
        'type':'bool',
        'default':True,
        'desc':"""\
# Create duplicate names for a given address (i.e. _FW and not)
""",
    },
    {
        'name':'conflict_names',
        'type':'enum',
        'default':'remove',
        'vals':['remove','create','unique','skip'],
        'desc':'''\
# How to handle stubs that have a different address for name that already
# exists in the program (including earlier applied stubs)
#  'remove'= remove other symbols with this name
#  'create' = create anyway
#  'unique' = use unique suffix SomeFunction_stubs_ffff1234
#  'skip' = do not add
''',
    },
    {
        'name':'conflict_stubs',
        'type':'enum',
        'default':'unique',
        'vals':['create','unique','skip'],
        'desc':'''\
# How to handle multiple stubs with same name, different address
#  'create' = create all
#  'unique' = use unique suffix SomeFunction_stubs_ffff1234
#  'skip' = don't add any affected stubs
''',
    },
    {
        'name':'stubs_comments',
        'type':'bool',
        'default':True,
        'desc':'''\
# Set comment on symbol address from stubs comments (exluding finsig method/score)
''',
    },
    {
        'name':'stubs_comment_type',
        'type':'enum',
        'default':'eol',
        'vals':['pre','eol'],
        'desc':'''\
# Type of comment to use: 'eol' or 'pre'. eol are hard to see if long
''',
    },
    {
        'name':'pretend',
        'type':'bool',
        'default':False,
        'desc':'''\
# Just log without doing
''',
    },
    {
        'name':'verbose',
        'type':'int',
        'default':1,
        'desc':'''\
# 0 = :|, 1= blah blah, 2= blah blah blah
''',
    },
    {
        'name':'symbol_source',
        'type':'enum',
        'default':'IMPORTED',
        'vals':['ANALYSIS', 'DEFAULT', 'IMPORTED', 'USER_DEFINED'],
        'desc':'''\
# One of ANALYSIS, DEFAULT, IMPORTED, USER_DEFINED
# these are displayed an prioritized differently in Ghirdra
''',
    },
    {
        'name':'print_loaded_stubs',
        'type':'bool',
        'default':False,
        'desc':'''\
# Print loaded stubs
''',
    },
    {
        'name':'print_created_stubs',
        'type':'bool',
        'default':False,
        'desc':'''\
# Print created stubs
''',
    },
]

# hack, call wants type not string
g_sym_src_map = {
    'ANALYSIS': ProgramSymbol.SourceType.ANALYSIS,
    'DEFAULT': ProgramSymbol.SourceType.DEFAULT,
    'IMPORTED': ProgramSymbol.SourceType.IMPORTED,
    'USER_DEFINED': ProgramSymbol.SourceType.USER_DEFINED,
}


def init_options():
    scriptfile = getSourceFile().getAbsolutePath()
    base, ext = os.path.splitext(scriptfile)
    cfgfile = base + '.cfg'

    secname = 'ImportCHDKStubs'

    # rewrite config if not present or missing sections / values
    if optionsutil.load_options(secname,cfgfile,g_options_spec,g_options):
       optionsutil.write_options(secname,cfgfile,g_options_spec,g_options)

    chdklib.logutil.verbosity = g_options['verbose']


def get_available_files(sub_dir):
    available_files = []
    possible_files = ['funcs_by_address.csv','stubs_entry.S','stubs_entry.S.err','stubs_entry_2.S','stubs_min.S']
    for fname in possible_files:
        fullpath = os.path.join(sub_dir,fname)
        if os.path.isfile(fullpath):
            available_files.append(fname)
        elif fname != 'stubs_entry.S.err':
            infomsgf(0,'Missing %s\n',fullpath)
    return available_files

# check for existing symbols with the same name and different addresses
# return a name to be used or None depending on how
def handle_conflict_name(cval,name,how):
    if how == 'create':
        return name

    address = cval['gh_adr']
    if how == 'remove':
        for s in getSymbols(name,None):
            if s.getAddress() != address:
                infomsgf(0, "Delete existing conflicting %s %s != %s\n", name, address, s.getAddress())
                if not g_options['pretend']:
                    s.delete()

    if how == 'unique':
        conflict_names = getSymbols(name,None)
        new_name = name

        for s in conflict_names:
            if s.getAddress() != address:
                infomsgf(0, "Conflicting %s %s != %s\n", new_name, address, s.getAddress())
                new_name = '{}_stubs_{:08x}'.format(new_name,cval['adr'])
                infomsgf(0,"Rename incoming %s = %s\n", name, new_name)
                break

        return new_name

    if how == 'skip':
        for s in getSymbols(name,None):
            if s.getAddress() != address:
                infomsgf(0, "Skip conflicting %s %s != %s\n", name, address, s.getAddress())
                return None
        return name

# TODO unknown option is equivalent to 'create'
    return name

def do_create_label(cval,name):
    primary = (name == cval['pri_name'])

    name = handle_conflict_name(cval, name, g_options['conflict_names'])
    if name:
        if not g_options['pretend']:
            createLabel(cval['gh_adr'], name, primary, g_sym_src_map[g_options['symbol_source']])

    # TODO maybe better to return symbols (but wouldn't work with pretend)
    return name

def create_cval_symbols(cval):
    created_names = []

    created_names.append(do_create_label(cval,cval['pri_name']))

    if g_options['create_dupe_names']:
        for name in cval['alt_names']:
            created_names.append(do_create_label(cval,name))

    if not  g_options['pretend']:
        if g_options['stubs_comments'] and cval['comment']:
            if g_options['stubs_comment_type'].lower() == 'eol':
                setEOLComment(cval['gh_adr'],cval['comment'])
            elif g_options['stubs_comment_type'].lower() == 'pre':
                setPreComment(cval['gh_adr'],cval['comment'])
 

    if len(created_names):
        if g_options['print_created_stubs']:
            infomsgf(0,"%s %s\n",cval['gh_adr'],' '.join(created_names))

def disassemble_cval(cval):
    adr = cval['adr']
    address = cval['gh_adr']

    if getInstructionAt(address):
        return

# if thumb, try to set default context reg
# had trouble with setValue throwing ContextChangeException for reasons that aren't clear
    try:
        if adr & 1 == 1:
            infomsgf(0,"Dis thumb %s\n",address)
            if g_options['clean_thumb_data']:
                bad_data = getDataAt(toAddr(adr)) # from *thumb* address, +1 of func
                if bad_data:
                    infomsgf(0,'remove data %s\n',bad_data)
                    if not g_options['pretend']:
                        removeData(bad_data)
            if not g_options['pretend']:
                progCtx.setValue(tmodeReg,address,address,BigInteger("1"))
        else:
            infomsgf(0,"Dis ARM %s\n",address)
            if not g_options['pretend']:
                progCtx.setValue(tmodeReg,address,address,BigInteger("0"))
        if not g_options['pretend']:
            disassemble(address)
    except ghidra.program.model.listing.ContextChangeException:
        warnf("Set tmode failed at %s\n",address)

def do_create_stubs(stubs_data,stype):
    items = stubs_data['create'][stype]
    monitor.initialize(len(items))
    if stype == 'func':
        desc = 'functions'
    else:
        desc = 'data items'

    infomsgf(0,"Processing %d %s\n",len(items),desc)
    for cval in items:
        monitor.checkCanceled()
        monitor.setMessage(str(cval['gh_adr'])+ ' ' + cval['pri_name']) 
        create_cval_symbols(cval)
        if stype == 'func':
            # NOTE disassemble will happen even if no labels created,
            # should be harmless
            disassemble_cval(cval)

        monitor.incrementProgress(1)

# check for duplicate names with different addresses and handle according to how
def handle_stubs_name_conflict(stubs_data,sval,how):
    in_name = sval['name']
    if how == 'create':
        return in_name

    # check for stubs with the same name and different address
    for osval in stubs_data['name_map'][in_name]:
        if osval['adr'] == sval['adr']:
            continue
        if how == 'unique':
            infomsgf(0, "Conflicting stubs %s %08x != %08x\n", in_name, sval['adr'], osval['adr'])
            new_name = '{}_stubs_{:08x}'.format(in_name,sval['adr'])
            infomsgf(0,"Rename %s = %s\n", in_name, new_name)
            return new_name

        elif how == 'skip':
            return None

    return in_name

# take the list of loaded values and build a list of labels to create at unique addresses
def process_list(stubs_data):
    to_create={
        'func':[],
        'data':[],
    }
    for adr in stubs_data['adr_map']:
        svlist = stubs_data['adr_map'][adr]
        # structure describing value to create
        cval = {
            'adr':adr,
            'pri_name':svlist[0]['name'], # default first found, functions adjust below
            'names':[], # all names, ordered to match sources, comments
            'alt_names':[],
            'sources':[],
            'comments':[],
            'comment':None,
            'type':svlist[0]['type'],
        }
        for sval in svlist:
            if sval['type'] == 'const':
                continue
            if sval['type'] != cval['type']:
                warnf('Conflicting types at %x %s:%s != %s\n',adr,sval['name'],sval['type'],cval['type'])

            create_name = handle_stubs_name_conflict(stubs_data,sval,g_options['conflict_stubs'])

            if not create_name:
                continue

            if create_name != sval['name'] and cval['pri_name'] == sval['name']:
                cval['pri_name'] = create_name

            cval['names'].append(create_name)
            cval['sources'].append(sval['src'])
            if sval['comment']:
                cval['comments'].append(sval['comment'])

        # may be empty because consts are skipped or conflict resolution
        if len(cval['names']) == 0:
            continue

        # Pick primary name for function
        # prefer the non _FW name, if present
        # for PTP opcodes, prefer standard / known names
        # TODO prefer stubs_entry source?
        if cval['type'] == 'func':
            for name in cval['names']:
                if not re.search('^handle_PTP_OC_0x|^handle_PTP_OC_CANON|_FW(_stubs_[0-9a-fA-F]{8})?$|^hook_CreateTask$',name):
                    cval['pri_name'] = name

        # unique alt names
        for name in cval['names']:
            if name != cval['pri_name'] and not name in cval['alt_names']:
                cval['alt_names'].append(name)

        if cval['type'] == 'func':
            gh_adr = toAddr(adr & 0xfffffffe)
        else:
            gh_adr = toAddr(adr)

        # Skip if address isn't in defined memory
        if not getMemoryBlock(gh_adr):
            warnf("%s not in defined memory block %s %s\n",cval['type'],cval['pri_name'], gh_adr)
            continue

        if g_options['stubs_comments'] and len(cval['comments']):
            cval['comment'] = '\n'.join(cval['comments'])

        cval['gh_adr'] = gh_adr

        to_create[cval['type']].append(cval)

    return to_create


def import_chdk_stubs_main():
    init_options()

    stubs_data = stubs_loader.initialize(g_options)

    # whatever askDirectory returns isn't actually string
    sub_dir = str(askDirectory("CHDK platform sub","select"))
    available_files = get_available_files(sub_dir)
    if len(available_files) == 0:
        warnf('No stubs files found\n')
        return

    selected_files = askChoices("Select files","Choose stubs to import",available_files)
    if len(selected_files) == 0:
        infomsgf(0,'Nothing to do!\n')
        return

    # TODO could add other that lets you pick arbitrary s/csv
    for fname in selected_files:
        base, ext = os.path.splitext(fname)
        if ext == '.csv':
            stubs_loader.load_funcs_csv(os.path.join(sub_dir,fname),stubs_data)
        elif ext == '.S' or ext == '.s' or ext == '.err':
            stubs_loader.load_stubs_s(os.path.join(sub_dir,fname),stubs_data)

    stubs_data['create'] = process_list(stubs_data)

    do_create_stubs(stubs_data,'data')
    do_create_stubs(stubs_data,'func')

import_chdk_stubs_main()
