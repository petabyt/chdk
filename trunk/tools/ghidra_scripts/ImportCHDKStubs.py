# Ghidra python script to import function and variable definitions from CHDK "stubs" files
# 
# Variables and functions copied to out of ROM require that you have created a memory map with the appropriate
# address space defined. The InitCHDKMemMap.py script may be used to create an initial memory map.
#
# This script prompts for a platform/sub directory, looks for any of
#  stubs_entry.S, stubs_entry.err.S, stubs_entry_2.S, stubs_min.S, funcs_by_address.csv
# and prompts for which ones to load.
#
# NOTE: If you are starting a port and have copied stubs_min.S or stubs_entry_2.S, you SHOULD NOT
# select these files unless all incorrect / unknown stubs are commented out. Additionally, stubs_entry_2.S
# overrides can be picked up in funcs_by_address.csv, so should be commented out when building
# stubs.
#
# By default, the script prompts whether to create entry points only, disassemble, or use whatever is set in
# the config file. Entry points mode is intended for use before auto-analysis has been run. Disassemble
# should be used if the dump is already analyzed. This selection overrides the create_entrypoints and
# disassemble_functions config options.
#
# Additional behavior can be controlled by an ini format configuration file, which is created automatically in
# the same directory as the script if not present. The default cfg includes a description of each option, and
# can be created by starting the script and cancelling any of the dialogs.
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
# The script also tries to fix up an issues where auto-analysis creates data that interferes with disassembly. 
# This can happens when it detects bytes that look like an string overlapping the function start, or in thumb2
# firmware, where pointers with the thumb bit set are interpreted as data pointers.
# These are controlled by the clean_func_conflict_data and clean_thumb_data options, respectively.
#
# By default, the script tries to add labels at the start of ROM and ROMSTARTER entry points, to aid
# disassembly. 
# The add_boot_entries option controls this.
#
# The prompt to select mode is controlled by askmode option
#
#@category CHDK
#@author reyalp
#@menupath Tools.CHDK.Import Stubs

# License: GPL
#
# Copyright 2019-2020 reyalp (at) gmail.com
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
from chdklib.logutil import infomsg, warn
from chdklib.stubs_loader import StubsData
import chdklib.optionsutil as optionsutil
from chdklib.analyzeutil import get_pinsn_at

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
        'name':'askmode',
        'type':'bool',
        'default':True,
        'desc':"""\
# Prompt for preset mode when run
""",
    },
    {
        'name':'disassemble_functions',
        'type':'bool',
        'default':True,
        'desc':"""\
# Attempt disassembly at function addresses if not already disassembled
""",
    },
    {
        'name':'clean_thumb_data',
        'type':'bool',
        'default':True,
        'desc':"""\
# Undefine data +1 from thumb func adr
""",
    },
    {
        'name':'clean_func_conflict_data',
        'type':'bool',
        'default':True,
        'desc':"""\
# Undefine data which contains function entry point
""",
    },
    {
        'name':'create_entrypoints',
        'type':'bool',
        'default':False,
        'desc':"""\
# Add entry points at function addresses, can be used to aid auto-analysis
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
    {
        'name':'add_boot_entries',
        'type':'bool',
        'default':True,
        'desc':"""\
# Attempt to add entry points for main firmware boot and romstarter
""",
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
            infomsg(0,'Missing %s\n'%(fullpath))
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
                infomsg(0, "Delete existing conflicting %s %s != %s\n"%(name, address, s.getAddress()))
                if not g_options['pretend']:
                    s.delete()

    if how == 'unique':
        conflict_names = getSymbols(name,None)
        new_name = name

        for s in conflict_names:
            if s.getAddress() != address:
                infomsg(0, "Conflicting %s %s != %s\n"%(new_name, address, s.getAddress()))
                new_name = '{}_stubs_{:08x}'.format(new_name,cval['adr'])
                infomsg(0,"Rename incoming %s = %s\n"%(name, new_name))
                break

        return new_name

    if how == 'skip':
        for s in getSymbols(name,None):
            if s.getAddress() != address:
                infomsg(0, "Skip conflicting %s %s != %s\n"%(name, address, s.getAddress()))
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
            infomsg(0,"%s %s\n"%(cval['gh_adr'],' '.join(created_names)))

def clean_data_for_disassemble(cval):
    adr = cval['adr']
    address = cval['gh_adr']

    if g_options['clean_func_conflict_data']:
        bad_data = getDataContaining(address) # ghidra address, has thumb bit off
        if bad_data:
            infomsg(0,'remove conflict data %s\n'%(bad_data))
            if not g_options['pretend']:
                removeData(bad_data)

    if g_options['clean_thumb_data'] and adr & 1 == 1:
        bad_data = getDataAt(toAddr(adr)) # from *thumb* address, +1 of func
        if bad_data:
            infomsg(0,'remove data %s\n'%(bad_data))
            if not g_options['pretend']:
                removeData(bad_data)

def set_thumb_reg_for_cval(cval):
    address = cval['gh_adr']

    # for thumb "register" value
    progCtx = currentProgram.getProgramContext()
    tmodeReg = progCtx.getRegister("TMode")
    try:
        if cval['adr'] & 1 == 1:
            if tmodeReg:
                infomsg(0,"Set thumb %s\n"%(address))
                if not g_options['pretend']:
                    progCtx.setValue(tmodeReg,address,address,BigInteger("1"))
            else:
                warn("Thumb bit set without TMode register %s"%(address))
        else:
            infomsg(0,"Set ARM %s\n"%(address))
            if tmodeReg and not g_options['pretend']:
                progCtx.setValue(tmodeReg,address,address,BigInteger("0"))
        return True
    except ghidra.program.model.listing.ContextChangeException:
        warn("Set tmode failed at %s"%(address))
        return False

def process_func_cval(cval):
    address = cval['gh_adr']
    if g_options['create_entrypoints'] and not g_options['pretend']:
        addEntryPoint(address);

    # following only relevant if not already disassembled
    if getInstructionAt(address):
        return

    clean_data_for_disassemble(cval)

    if set_thumb_reg_for_cval(cval) and g_options['disassemble_functions']:
        # NOTE disassemble will happen even if no labels created,
        # should be harmless
        if not g_options['pretend']:
            disassemble(address)

def do_create_stubs(items,stype):
    monitor.initialize(len(items))
    if stype == 'func':
        desc = 'functions'
    else:
        desc = 'data items'

    infomsg(0,"Processing %d %s\n"%(len(items),desc))
    for cval in items:
        monitor.checkCanceled()
        monitor.setMessage(str(cval['gh_adr'])+ ' ' + cval['pri_name']) 
        create_cval_symbols(cval)
        if stype == 'func':
            process_func_cval(cval)

        monitor.incrementProgress(1)

# check for duplicate names with different addresses and handle according to how
def handle_stubs_name_conflict(stubs_data,sval,how):
    in_name = sval['name']
    if how == 'create':
        return in_name

    # check for stubs with the same name and different address
    for osval in stubs_data.name_map[in_name]:
        if osval['adr'] == sval['adr']:
            continue
        if how == 'unique':
            infomsg(0, "Conflicting stubs %s %08x != %08x\n"%(in_name, sval['adr'], osval['adr']))
            new_name = '{}_stubs_{:08x}'.format(in_name,sval['adr'])
            infomsg(0,"Rename %s = %s\n"%(in_name, new_name))
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
    for adr in stubs_data.adr_map:
        svlist = stubs_data.adr_map[adr]
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
                warn('Conflicting types at %x %s:%s != %s'%(adr,sval['name'],sval['type'],cval['type']))

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
            warn("%s not in defined memory block %s %s"%(cval['type'],cval['pri_name'], gh_adr))
            continue

        if g_options['stubs_comments'] and len(cval['comments']):
            cval['comment'] = '\n'.join(cval['comments'])

        cval['gh_adr'] = gh_adr

        to_create[cval['type']].append(cval)

    return to_create

def do_mode_choice():
    if not g_options['askmode']:
        return

    mode_options = ['Entry points only (un-analyzed dump)','Load and disassemble (analyzed dump)','Whatever is in the config']
    # default to un-analyzed if there are only a few functions
    default_mode = 0
    # 20 because exception vectors sometimes ID by address alone
    if getCurrentProgram().getFunctionManager().getFunctionCount() > 20:
        default_mode = 1
    # ghidra widget seems to remember previous choices, but we tried :(
    mode_choice = askChoice("Select mode preset",
        "Mode (askmode=0 in config to disable)",
        mode_options,mode_options[default_mode])
    if mode_choice == mode_options[0]:
        g_options['create_entrypoints']=True
        g_options['disassemble_functions']=False
    elif mode_choice == mode_options[1]:
        g_options['create_entrypoints']=False
        g_options['disassemble_functions']=True

def add_boot_entries(stubs_data):
    if not g_options['add_boot_entries']:
        return

    stubs_data.guess_platform_vals()
    smisc = stubs_data.stubs_entry_misc
    if 'ar_rom' in smisc:
        rom_start = smisc['ar_rom']['start_adr']
    else:
        rom_start = None

    # digic 6 / 7 have thumb jump at main fw start, identified by sig finder
    if smisc['digic'] >= 60:
        if 'main_fw_start' in smisc:
            stubs_data.add_stubs_value('func','ImportCHDKStubs','-','main_firmware_boot',smisc['main_fw_start']+1,'',0)
        else:
            infomsg(0,'add_boot_entries: main_fw_start not found\n')
        # romstarter stuff depends on identified ROM region
        if not rom_start:
            infomsg(0,'add_boot_entries: ar_rom not found\n')
            return

        # digic 6 firmware appears to have a pointer into romstarter at start of ROM
        if smisc['digic'] == 60:
            p1 = getInt(toAddr(smisc['ar_rom']['start_adr']))&0xffffffff
            if p1 > rom_start and p1 - rom_start < 0x6000:
                stubs_data.add_stubs_value('func','ImportCHDKStubs','-','romstarter_entry',p1,'',0)
        # digic 7 appears to have an ARM code
        elif smisc['digic'] == 70: 
            stubs_data.add_stubs_value('func','ImportCHDKStubs','-','romstarter_entry',rom_start,'',0)
    else:
        if not rom_start:
            infomsg(0,'add_boot_entries: ar_rom not found\n')
            return

        main_fw_boot_addr = None
        if smisc['os_info']['os'] == 'VXWORKS':
            main_fw_boot_addr = rom_start
        else:
            # look for b_ preceding "gaonisoy"
            for match_addr in findBytes(toAddr(rom_start),"gaonisoy",10,4):
                pi = get_pinsn_at(match_addr.add(-4))
                if pi and pi.getMnemonicString() == 'b':
                    opstr = pi.getDefaultOperandRepresentation(0)
                    if opstr == '0x'+str(match_addr.add(8)):
                        main_fw_boot_addr = match_addr.add(-4).getOffset()
        if main_fw_boot_addr:
            stubs_data.add_stubs_value('func','ImportCHDKStubs','-','main_firmware_boot',main_fw_boot_addr,'',0)


        # don't bother adding romstarter entries for digic < 6, Ghidra should pick up high exception vector if
        # it's at 0xffff0000

def import_chdk_stubs_main():
    init_options()

    stubs_data = StubsData(print_loaded_stubs=g_options['print_loaded_stubs'], warnfunc=warn, infofunc=infomsg)

    # whatever askDirectory returns isn't actually string
    sub_dir = str(askDirectory("CHDK platform sub","select"))
    available_files = get_available_files(sub_dir)
    if len(available_files) == 0:
        warn('No stubs files found')
        return

    selected_files = askChoices("Select files","Choose stubs to import",available_files)
    if len(selected_files) == 0:
        infomsg(0,'Nothing to do!\n')
        return

    do_mode_choice()

    # TODO could add other that lets you pick arbitrary s/csv
    for fname in selected_files:
        base, ext = os.path.splitext(fname)
        if ext == '.csv':
            stubs_data.load_funcs_csv(os.path.join(sub_dir,fname))
        elif ext == '.S' or ext == '.s' or ext == '.err':
            stubs_data.load_stubs_s(os.path.join(sub_dir,fname))

    add_boot_entries(stubs_data)

    to_create = process_list(stubs_data)

    do_create_stubs(to_create['data'],'data')
    do_create_stubs(to_create['func'],'func')

import_chdk_stubs_main()
