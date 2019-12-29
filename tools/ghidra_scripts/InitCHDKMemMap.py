# Ghidra script to create memory map from CHDK platform files
#
# This script prompts for a platform/sub directory, reads the stubs_entry.S
# or stubs_entry.S.err file, and creates memory blocks based on the values 
# found. It is intended to be run on a freshly loaded firmware dump, before
# auto-analysis has been started.
# The generated memory map aims to
#  * Locate copied code and initialized data at the correct addresses,
#    setting execute bit on code.
#  * Split the ROM into executable and non-executable blocks, to avoid bad
#    disassembly of code that is copied elsewhere or executed by other
#    processors
#  * Create uninitialized regions for areas of address space expected to
#    be accessed by the main core in normal operation
#  * Mark MMIO regions as volatile to make them stand out in decompile
#
# NOTE:
# Attempting to undo this script with the Ghidra Undo button sometimes
# triggers an error like "Unexpected exception in Swing Update Manager"
# The undo appears to appears to still be successful, but in any case
# the script is intended for use on a fresh, un-analyzed dump, so
# you could just start over.
#

#@category CHDK
#@author reyalp
#@menupath Tools.CHDK.Init Memory Map

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
import re

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
        'name':'include_zico',
        'type':'bool',
        'default':False,
        'desc':'''\
# Map copied blobs for Zico Xtensa processor (probably not useful)
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
]

def init_options():
    scriptfile = getSourceFile().getAbsolutePath()
    base, ext = os.path.splitext(scriptfile)
    cfgfile = base + '.cfg'

    secname = 'InitCHDKMemMap'

    # rewrite config if not present or missing sections / values
    if optionsutil.load_options(secname,cfgfile,g_options_spec,g_options):
       optionsutil.write_options(secname,cfgfile,g_options_spec,g_options)

    chdklib.logutil.verbosity = g_options['verbose']


class MBlockOps:
    """Class to collect memory block operations for later execution, or output"""
    mb_types = ['split','bytemap','uninit']

    def __init__(self):
        self.ops = [] # blocks to create
        self.names = {} # list of used names with counters to generate unique
        # initialize with actual memory blocks in program
        for mb in getMemoryBlocks():
            self.names[mb.getName()] = 0

    def make_unique_name(self, name):
        if name in self.names:
            self.names[name] += 1
            new_name = '{}_{}'.format(name,self.names[name])
        else:
            self.names[name] = 0
            new_name = name

        return new_name

    def add(self, mb_type, name, start_adr, size, src_adr, r=True, w=True, x=True, v=False):
        if not mb_type in self.mb_types:
            raise ValueError("mblock "+str(name)+" unknown type "+ str(mb_type))

        if mb_type == 'split' and size:
            raise ValueError("mblock "+str(name)+" type split cannot have size")

        if mb_type != 'split' and not size:
            raise ValueError("mblock "+str(name)+" type "+str(mb_type) +" must have size")

        if mb_type != 'bytemap' and src_adr:
            raise ValueError("mblock "+str(name)+" type "+str(mb_type) +" cannot have src_adr")

        # this would fail on src_adr 0, but not likely on powershots
        if mb_type == 'bytemap' and not src_adr:
            raise ValueError("mblock "+str(name)+" type bytemap must have src_adr")

        self.ops.append({
            'name':self.make_unique_name(name),
            'type':mb_type,
            'start':start_adr,
            'size':size,
            'src':src_adr,
            'r':r,
            'w':w,
            'x':x,
            'v':v,
        })


    def add_split(self, name, start_adr, r=True, w=True, x=True, v=False):
        self.add('split', name, start_adr, None, None, r, w, x, v)

    def add_bytemap(self, name, start_adr, size, src_adr, r=True, w=True, x=True, v=False):
        self.add('bytemap', name, start_adr, size, src_adr, r, w, x, v)

    def add_uninit(self, name, start_adr, size=None, last_adr=None, r=True, w=True, x=False, v=False):
        if size == None and last_adr == None:
            raise ValueError('must set size or last_adr')

        if size and last_adr:
            raise ValueError('must set only one of size and last_adr')

        if last_adr:
            size = last_adr - start_adr + 1
            if size < 1:
                raise ValueError('last_adr < start_adr')

        self.add('uninit', name, start_adr, size, None, r, w, x, v)

    def add_stubs_ar(self, ardesc, name, r=True, w=True, x=False, v=False):
        # silently ignore missing, to allow blindly adding all possible
        if not ardesc:
            return

        if ardesc['src_adr']:
            self.add_bytemap(name, ardesc['start_adr'], ardesc['size'], ardesc['src_adr'], r=r, w=w, x=x, v=v)
        else:
            self.add_uninit(name, ardesc['start_adr'], ardesc['size'], r=r, w=w, x=x, v=v)


    def set_attrs(self, mbdef,mb):
        mb.setRead(mbdef['r'])
        mb.setWrite(mbdef['w'])
        mb.setExecute(mbdef['x'])
        mb.setVolatile(mbdef['v'])
        mb.setSourceName('InitCHDKMemMap')

    def create_split(self, mbdef):
        addr = toAddr(mbdef['start'])
        mb_src = getMemoryBlock(addr)
        if not mb_src:
            warn("mblock %s split no source block found"%(mbdef['name']))
            return

        infomsg(0,"Create split mblock %s 0x%s from %s\n"%(mbdef['name'], addr, mb_src.getName()))
        if g_options['pretend']:
            return

        mem = getCurrentProgram().getMemory()
        mem.split(mb_src, addr)
        mb_new = getMemoryBlock(addr)
        mb_new.setName(mbdef['name'])
        self.set_attrs(mbdef,mb_new)

    def create_bytemap(self, mbdef):
        addr = toAddr(mbdef['start'])
        src_addr = toAddr(mbdef['src'])
        mb_src = getMemoryBlock(src_addr)
        if not mb_src:
            warn("mblock %s bytemap no source block found"%(mbdef['name']))
            return

        infomsg(0,"Create bytemap mblock %s 0x%s 0x%x (%d) from %s %s\n"
            %(mbdef['name'], addr, mbdef['size'], mbdef['size'], mb_src.getName(), src_addr))
        if g_options['pretend']:
            return

        mem = getCurrentProgram().getMemory()
        mem.createByteMappedBlock(mbdef['name'], addr, src_addr, mbdef['size'])
        mb_new = getMemoryBlock(addr)
        self.set_attrs(mbdef, mb_new)

    def create_uninit(self, mbdef):
        infomsg(0,"Create uninit mblock %s 0x%08x 0x%x (%d)\n"%(mbdef['name'], mbdef['start'], mbdef['size'], mbdef['size']))
        if g_options['pretend']:
            return

        mb_new = createMemoryBlock(mbdef['name'],toAddr(mbdef['start']),None,mbdef['size'],False)
        self.set_attrs(mbdef, mb_new)

    def apply_ops(self):
        for mbdef in self.ops:
            if mbdef['type'] == 'split':
                self.create_split(mbdef)
            elif mbdef['type'] == 'bytemap':
                self.create_bytemap(mbdef)
            elif mbdef['type'] == 'uninit':
                self.create_uninit(mbdef)

mbops = MBlockOps()

def make_romstarter_mblock(smisc):
    """check for romstarter and create execuable block if possible"""

    if smisc['digic'] < 6:
        rs_start = 0xffff0000
        rs_start_addr = toAddr(rs_start)
        # TODO size could be found by checking for run of 0xff
        rs_size = 0x4000
        rs_after = rs_start + rs_size
        rs_after_addr = rs_start_addr.add(rs_size)

    elif smisc['digic'] == 6:
        if not 'main_fw_start' in smisc:
            infomsg(0,'make_romstarter_mblock: main fw start not identified\n')
            return

        rs_start = smisc['ar_rom']['start_adr']
        rs_start_addr = toAddr(rs_start)
        rs_size = 0x5000
        rs_after = rs_start + rs_size
        rs_after_addr = rs_start_addr.add(rs_size)

        main_fw_addr = toAddr(smisc['main_fw_start'])

        if smisc['main_fw_start'] < rs_after:
            infomsg(0,'make_romstarter_mblock: main fw start not too close to romstarter\n')
            return

    # TODO d7 unclear
    else:
        return

    # get memory block containing start addr
    mb_src = getMemoryBlock(rs_start_addr)
    if not mb_src:
        infomsg(0,'make_romstarter_mblock: no address containing %s\n',rs_start_addr)
        return

    if mb_src != getMemoryBlock(rs_after_addr):
        infomsg(0,'make_romstarter_mblock: multiple memory blocks in region or too small\n')
        return

    if smisc['digic'] == 6:
        if mb_src != getMemoryBlock(main_fw_addr):
            infomsg(0,'make_romstarter_mblock: multiple memory blocks in region or too small\n')


    # check if there's enough space
    if smisc['ar_rom']['last_adr'] < rs_after:
        infomsg(0,'make_romstarter_mblock: too small\n')
        return

    if smisc['digic'] < 6:
        pi = get_pinsn_at(rs_start_addr)
        if not pi:
            infomsg(0,'make_romstarter_mblock: no instruction found\n')
            return

        if pi.getMnemonicString() != 'b' and pi.getMnemonicString() != 'ldr':
            infomsg(0,'make_romstarter_mblock: unexpected instruction %s\n'%(pi))
            return

        mbops.add_split('ROMSTARTER', rs_start, w=False, x=True)
        mbops.add_split('ROMDATA', rs_after, w=False, x=False)

    elif smisc['digic'] == 6:
        # digic 6 romstarter code doesn't start exactly at rom start, can't do instruction check
        # TODO romstarter will end up with the original ROM name, should have a rename op
        mbops.add_split('ROMDATA', rs_after, w=False, x=False)
        # main code handles splitting main rom code

def init_chdk_mem_map_main():
    init_options()

    stubs_data = StubsData(warnfunc=warn,infofunc=infomsg)

    # whatever askDirectory returns isn't actually string
    sub_dir = str(askDirectory("CHDK platform sub","select"))

    filepath = os.path.join(sub_dir,'stubs_entry.S')
    if not os.path.isfile(filepath):
        infomsg(0,'No stubs_entry.S, trying stubs_entry.S.err\n')
        filepath = os.path.join(sub_dir,'stubs_entry.S.err')
        if not os.path.isfile(filepath):
            warn('No stubs_entry files found')
            return

    stubs_data.load_stubs_s(filepath,process_comments=True)

    stubs_data.guess_platform_vals()

    smisc = stubs_data.stubs_entry_misc

    if not 'ar_rom' in smisc:
        warn('No ROM region identified, giving up')
        return

    if not 'main_fw_code_end' in smisc:
        warn('Main firmware code end not identified, giving up')
        return

    if len(getMemoryBlocks()) > 1:
        warn('Program already has multiple memory blocks, giving up')

    mb_rom = getMemoryBlocks()[0]

    if mb_rom.getStart() != toAddr(smisc['ar_rom']['start_adr']):
        warn('Memory block start does not match ROM, giving up')
        return

    if not mb_rom.isInitialized():
        warn('ROM block not initialized, giving up')
        return

    if mb_rom.getEnd() <= toAddr(smisc['main_fw_code_end']):
        warn('Already initialized? ROM block end <= main fw code end, giving up')
        return

    mbops.add_split('ROMDATA', smisc['main_fw_code_end']+1, w=False, x=False)

    make_romstarter_mblock(smisc)

    # if main firmware doesn't start at rom start, split
    if 'main_fw_start' in smisc and smisc['main_fw_start'] > smisc['ar_rom']['start_adr']:
        mbops.add_split('ROMCODE', smisc['main_fw_start'], w=False, x=True)

    # ignored if not present
    ar_ramcode = smisc.get('ar_ramcode')
    ar_btcmcode = smisc.get('ar_btcmcode')
    ar_ramdata = smisc.get('ar_ramdata')

    mbops.add_stubs_ar(ar_ramdata, 'RAMDATA')
    mbops.add_stubs_ar(ar_ramcode, 'RAMCODE', x=True)
    mbops.add_stubs_ar(ar_btcmcode, 'BTCMCODE', x=True)
    mbops.add_stubs_ar(smisc.get('ar_itcm'), 'ITCM')
    mbops.add_stubs_ar(smisc.get('ar_atcm'), 'ATCM')
    mbops.add_stubs_ar(smisc.get('ar_uncached'), 'UNCACHED')
    mbops.add_stubs_ar(smisc.get('ar_dtcm'), 'DTCM')
    mbops.add_stubs_ar(smisc.get('ar_mmio'), 'MMIO',v=True)
    mbops.add_stubs_ar(smisc.get('ar_mmio_0xd'), 'MMIO',v=True)
    mbops.add_stubs_ar(smisc.get('ar_mmio_0xc1'), 'MMIO',v=True)
    mbops.add_stubs_ar(smisc.get('ar_mmio_0xc8'), 'MMIO',v=True)

    if smisc['digic'] >= 6:
        # RAM between ATCM and copied data
        mbops.add_uninit('RAM', 0x4000, 0x4000)
    else:
        # RAM between ITCM and copied data
        mbops.add_uninit('RAM', 0x1000, 0x900)

    if ar_ramcode:
        # RAM between ram data and code (assumes code after data!)
        mbops.add_uninit('RAM', ar_ramdata['last_adr']+1, last_adr=ar_ramcode['start_adr']-1)
        # RAM from end of code to end of RAM
        mbops.add_uninit('RAM', ar_ramcode['last_adr']+1, last_adr=smisc['max_ram_addr'])
    else:
        # RAM from end of ram data to end of RAM
        mbops.add_uninit('RAM', ar_ramdata['last_adr']+1, last_adr=smisc['max_ram_addr'])

    if smisc['digic'] == 6:
        if ar_btcmcode and ar_btcmcode['start_adr'] == 0xbfe10800:
            # 0x800 before code
            mbops.add_uninit('BTCM', 0xbfe10000, 0x800)
            # from code end to 64k
            mbops.add_uninit('BTCM', ar_btcmcode['last_adr']+1, last_adr=0xbfe20000-1)
    elif smisc['digic'] == 7:
        # per https://chdk.setepontos.com/index.php?topic=11316.msg142197#msg142197
        if ar_btcmcode and ar_btcmcode['start_adr'] == 0xdffc4900:
            # 0x4900 before code. TODO this is actually initialized, could create mapped
            mbops.add_uninit('BTCM', 0xdffc0000, 0x4900)
            # from code end to 256k
            mbops.add_uninit('BTCM', ar_btcmcode['last_adr']+1, last_adr=0xdfffffff)

    if g_options['include_zico']:
        for ardef in smisc['zico_blobs']:
            mbops.add_stubs_ar(ardef, 'ZICO')

    # set whole ROM read-only before splitting
    if not g_options['pretend']:
        mb_rom.setWrite(False)

    mbops.apply_ops()

init_chdk_mem_map_main()
