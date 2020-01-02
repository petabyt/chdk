# module to load information from CHDK stubs.S and csv files

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

class StubsFileParser:
    """Class for parsing CHDK stubs_*.S files"""
    # no current files should use regular NSTUB
    # don't currently use DEF_CONST
    stub_re = re.compile('\s*(DEF|NHSTUB|NSTUB|DEF_CONST|NHSTUB2)\s*\(\s*([A-Za-z_0-9]+)\s*,\s*([0\dXx0-9A-Fa-f]+)(\s*\+\s*[0\dXx0-9A-Fa-f]+)?\)\s*(?://\s*([^\s].*))?$')

    comment_section_ids = {
        'Camera info:':'CAM_INFO',
        'Values for makefile.inc':'MAKEFILE_INC',
        'Detected address ranges:':'ADR_RANGES',
        'Zico Xtensa blobs:':'ZICO_BLOBS',
        "Values below go in 'platform_camera.h':":'CAMERA_H',
    }
    stubs_entry_header = '// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!'

    def __init__(self, fname, stubs_data, process_comments=None):
        self.fname = fname
        self.src_name = os.path.basename(self.fname)

        # if not specified, default to on for stubs_entry
        if process_comments == None and re.match('stubs_entry\.[sS](\.err)?',self.src_name):
            process_comments = True

        self.stubs_data = stubs_data
        self.process_comments = process_comments
        self.commment_section = None
        self.gen_header_seen = None
        self.comment_data = {
            'main_fw_start':None,
            'os_info':None,
            'makefile_vals':{},
            'adr_ranges':[],
            'zico_blobs':[],
            'misc_vals':[],
            'camera_h_vals':{},
        }
        self.func_count = 0
        self.data_count = 0
        self.const_count = 0


    def process_cam_info(self,body):
        m = re.match('Main firmware start: 0x([0-9A-Fa-f]{8})$',body)
        if m:
            self.comment_data['main_fw_start'] = int(m.group(1),16)
            self.stubs_data.infomsg(0,"found main_fw_start %x\n"%(self.comment_data['main_fw_start']))
            return

        m = re.match('DRYOS R([0-9]+) (\([^)]+\))(?: @ 0x([0-9A-Fa-f]{8}) ref @ 0x([0-9A-Fa-f]{8}))?',body)
        if m:
            if m.group(3):
                verstr_adr = int(m.group(3),16)
            else:
                verstr_adr = None

            if m.group(4):
                verstr_adr_ref = int(m.group(3),16)
            else:
                verstr_adr_ref = None

            self.comment_data['os_info'] = {
                'os':'DRYOS',
                'rel':int(m.group(1)),
                'verstr':m.group(2),
                'verstr_adr':verstr_adr,
                'verstr_adr_ref':verstr_adr_ref,
            }
        # everything else in section is ignored for now

    def process_makefile_val(self,body):
        m = re.match('([^\s]+)\s*=\s*([^\s]+)(?:\s+(.*))?',body)
        # should all be formated like makefile lines
        if not m:
            self.section=None
            return

        # TODO might want to parse out comment more
        self.comment_data['makefile_vals'][m.group(1)] = {
            'name':m.group(1),
            'val':m.group(2),
            'comment':m.group(3),
        }

        self.stubs_data.infomsg(0,"found makefile_val %s = %s\n"%(m.group(1),m.group(2)))

    def process_adr_range(self,body,key):
        m = re.match('([A-Z0-9a-z_ ]+?[A-Z0-9a-z_]+)\s+0x([0-9A-Fa-f]{8}) - 0x([0-9A-Fa-f]{8})(?: copied from 0x([0-9A-Fa-f]{8}))?(?: \(\s*([0-9]+)\s+bytes\))',body)
        # should all be formated as adr ranges
        if not m:
            self.section=None
            return

        start_adr = int(m.group(2),16)

        # NOTE stubs inconsistent whether end_adr is final address, or start + len
        # consistent final address value calculated from size
        end_adr_parsed = int(m.group(3),16)

        if m.group(4):
            src_adr = int(m.group(4),16)
        else:
            src_adr = None

        size = int(m.group(5),10)
        last_adr = start_adr + (size - 1)

        self.comment_data[key].append({
            'name':m.group(1),
            'start_adr':start_adr,
            'last_adr':last_adr,
            'end_adr_parsed':end_adr_parsed,
            'src_adr':src_adr,
            'size':size,
        })

        self.stubs_data.infomsg(0,"found adr range %s = 0x%08x - 0x%08x"%(m.group(1),start_adr,last_adr))
        if src_adr:
            self.stubs_data.infomsg(0," source 0x%08x"%(src_adr))
        self.stubs_data.infomsg(0,'\n')

    def process_misc(self,body):
        m = re.match('(physw_event_table|canon_mode_list)\s+0x([0-9A-Fa-f]{8})\s+(Found @0x[0-9A-Fa-f]{8})?',body)
        if m:
            self.comment_data['misc_vals'].append({
                'name':m.group(1),
                'adr':int(m.group(2),16),
                'comment':m.group(3),
                'type':'data',
            })
            self.stubs_data.infomsg(0,"found %s %s %s\n"%(m.group(1),m.group(2),m.group(3)))
            return

        m = re.match('Firmware modemap table found @([0-9A-Fa-f]{8}) -> ([0-9A-Fa-f]{8})',body)
        if m:
            self.stubs_data.infomsg(0,"found modemap %s\n"%(m.group(2)))
            self.comment_data['misc_vals'].append({
                'name':'canon_mode_list',
                'adr':int(m.group(2),16),
                'comment':'Found @ '+m.group(1),
                'type':'data',
            })

    def process_camera_h_val(self,body):
        m = re.match('#define\s+([^\s]+)\s+([^\s]+)(?:\s+// ([^\s].*))?',body)
        if not m:
            # ignore undefs, also special case for iris
            # anything else ends section
            if not re.match('#undef|Camera has an iris',body):
                self.section=None
            return

        #if re.match('0x[0-9A-Fa-f]+$',m.group(2)):
        #    val = int(m.group(2),16)
        #elif re.match('[0-9]+$',m.group(2)): 
        #    val = int(m.group(2),10)
        #else:
        #    val = m.group(2)

        # TODO might want to parse out comment more
        self.comment_data['camera_h_vals'][m.group(1)] = {
            'name':m.group(1),
            'val':m.group(2),
            'comment':m.group(3),
        }

        self.stubs_data.infomsg(0,"found platform_camera.h val %s = %s\n"%(m.group(1),m.group(2)))

    def process_comment(self,line):
        if not self.process_comments:
            return

        if not self.gen_header_seen:
            return

        body = re.sub('^//\s*','',line)
        # found a section, no additional data on this line
        if body in self.comment_section_ids:
            self.section = self.comment_section_ids[body]
            self.stubs_data.infomsg(0,"found section %s\n"%(self.section))
        elif self.section == 'CAM_INFO':
            self.process_cam_info(body)
        elif self.section == 'MAKEFILE_INC':
            self.process_makefile_val(body)
        elif self.section == 'ADR_RANGES':
            self.process_adr_range(body,'adr_ranges')
        elif self.section == 'ZICO_BLOBS':
            self.process_adr_range(body,'zico_blobs')
        elif self.section == 'CAMERA_H':
            self.process_camera_h_val(body)
        else:
            self.process_misc(body)

    def process_stub(self,line):
        m = self.stub_re.match(line)
        if not m:
            return

        op = m.group(1)
        name = m.group(2)
        adr_str = m.group(3)
        adradj_str = m.group(4) # None if not present
        comment = m.group(5)
        # don't bother including sigfinder number codes
        # TODO maybe filter out in process_list instead
        if comment and re.match('^[0-9\s%]+$',comment):
            comment = None
        adr = int(adr_str,0)
        if adradj_str:
            adradj_str = re.sub('\+\s*','',adradj_str)
            adradj = int(adradj_str,0)
        else:
            adradj = 0
        if op in ['NHSTUB','NHSTUB2']:
            if adradj != 0:
                self.stubs_data.warn("func stub with addition O_o %s %s %s"%(name , adrstr, adradj_str))
            self.stubs_data.add_stubs_value('func',self.src_name,op,name,adr,comment,adradj)
            self.func_count += 1
        elif op == 'DEF':
            # TODO tasks shouldn't be labeled as vars,
            # should normally be picked up from CSV but shouldn't hurt
            if re.match('task_',name):
                self.stubs_data.add_stubs_value('func',self.src_name,op,name,adr,comment,adradj)
                self.func_count += 1
            else:
                self.stubs_data.add_stubs_value('data',self.src_name,op,name,adr,comment,adradj)
                self.data_count += 1
        # not actually used for now
        elif op == 'DEF_CONST':
            self.stubs_data.add_stubs_value('const',self.src_name,op,name,adr,comment,adradj)
            self.const_count += 1

        if self.stubs_data.print_loaded_stubs:
            self.stubs_data.infomsg(0,'%s %s %s'%(op, name, adr_str))
            adradj_str and self.stubs_data.infomsg(0,"+%s"%(adradj_str))
            comment and self.stubs_data.infomsg(0," # %s"%(comment))
            self.stubs_data.infomsg(0,"\n")

    def process_line(self,line):
        # trim any trailing CR or LF for simplicity
        line = re.sub('\r?\n?$','',line)

        # check for header generated header that ids stubs_entry.S, must be on first line
        if self.process_comments and self.gen_header_seen == None:
            if line == self.stubs_entry_header:
                self.stubs_data.infomsg(0,"found header\n")
                self.gen_header_seen = True
            else:
                self.gen_header_seen = False
            return

        # comment
        if re.match('\s*//',line):
            self.process_comment(line)
            return

        # anything else breaks comment section
        self.comment_section = None

        # empty line
        if len(line) == 0:
            return

        self.process_stub(line)

    # take stub-like values scraped from comments and turn add them to stubs_data
    def add_comment_misc_to_stubs(self):
        for cmisc in self.stubs_data.stubs_entry_misc['misc_vals']:
            # only data so far
            if cmisc['type'] == 'data':
                self.stubs_data.add_stubs_value('data',self.src_name,'COMMENT',cmisc['name'],cmisc['adr'],cmisc['comment'],0)

    def process_file(self):
        for line in file(self.fname):
            self.process_line(line)

        # hacky - will clobber any data from previous loads, but should only be one stubs_entry.S / .S.err
        if self.process_comments and self.gen_header_seen:
            self.stubs_data.stubs_entry_misc = self.comment_data
            # TODO should maybe be optional
            self.add_comment_misc_to_stubs()

def _dummy_log(*args):
    pass

class StubsData:
    """Class to load and access CHDK stubs_entry*.S and funcs_*.csv data"""
    def __init__(self, print_loaded_stubs=False, infofunc=None, warnfunc=None):
        if infofunc:
            self.infomsg = infofunc
        else:
            self.infomsg = _dummy_log

        if warnfunc:
            self.warn = warnfunc
        else:
            self.warn = _dummy_log

        self.print_loaded_stubs = print_loaded_stubs
        self.list = []
        self.stubs_entry_misc = {}
        self.name_map = {}
        self.adr_map = {}

# vtype = func, data, const
# src = source file
# srctype = NHSTUB, DEF etc or CSV
# name = funtion / var name
# adrbase = address, possibly modified by adr_offset 
# comment = comment scraped from source file or generated
# adr_offset = offset from adr recorded in stub value for documentation purposes
    def add_stubs_value(self, vtype, src, srctype, name, adr_base, comment=None,adr_offset=0):
        adr = adr_base + adr_offset
        sval = {
            'name':name,
            'adr_base':adr_base,
            'adr_offset':adr_offset,
            'adr':adr,
            'type':vtype,
            'src':src,
            'srctype':srctype,
            'comment':comment,
        }
        self.list.append(sval)
        if name in self.name_map:
            self.name_map[name].append(sval)
        else:
            self.name_map[name] = [sval]
        if adr in self.adr_map:
            self.adr_map[adr].append(sval)
        else:
            self.adr_map[adr] = [sval]

    def load_funcs_csv(self,fname):
        self.infomsg(0,"Load csv %s\n"%(fname))
        src_name = os.path.basename(fname)
        rows = 0
        for r in csv.reader(file(fname)):
            adr = int(r[0],16)
            name = r[1].rstrip()
            # (stubs_entry_2) column
            if len(r) > 2:
                comment = r[2]
                # infomsg(0,"%08x %s # %s\n"%(adr, name, comment))
            else:
                comment = None
            self.add_stubs_value('func', src_name, 'CSV',name, adr, comment)
            rows += 1
        self.infomsg(0,"Loaded %d functions from %s\n"%(rows,fname))


    def add_guess_adr_range(self,name,start_adr,size):
        ar_desc = {
            'name':name.upper(),
            'start_adr':start_adr,
            'last_adr':start_adr + (size-1),
            'end_adr_parsed':start_adr + (size-1),
            'src_adr':None,
            'size':size,
        }
        self.stubs_entry_misc['adr_ranges_extra'].append(ar_desc)
        self.stubs_entry_misc['ar_'+name.lower()] = ar_desc

    def guess_platform_vals(self):
        """Set inferred values in stubs_entry_misc based on values from comments"""
        smisc = self.stubs_entry_misc
        # only finsig_thumb2 sets this
        if smisc['main_fw_start']:
            smisc['thumb2'] = True
            # currently, all known d7 are at 0xe..., while d6 are at 0xf...
            if smisc['main_fw_start'] < 0xf0000000:
                self.infomsg(0,'digic 7\n')
                smisc['digic'] = 7
                smisc['max_ram_addr'] = 0x3fffffff # 1 GB, unclear if correct for all?
            else:
                self.infomsg(0,'digic 6\n')
                smisc['digic'] = 6
                smisc['max_ram_addr'] = 0x1fffffff # 512 MB, seems to be true on all known

        else:
            self.infomsg(0,'digic 5 or below\n')
            # TODO could distinguish 3 and below by uncached bit?
            smisc['digic'] = 5
            # should only be missing for vx
            if not smisc['os_info']:
                smisc['os_info'] = {
                    'os':'VXWORKS',
                    'os_rel':5, # actually 5.5, but less than any relevant dry ver
                    'verstr':None,
                    'verstr_adr':None,
                    'verstr_adr_ref':None,
                }
            if 'MAXRAMADDR' in smisc['makefile_vals']:
                smisc['max_ram_addr'] = int(smisc['makefile_vals']['MAXRAMADDR']['val'],16)
            else:
                if smisc['os_info']['os'] == 'DRYOS':
                    if smisc['os_info']['rel'] < 55:
                        smisc['max_ram_addr'] = 0x0fffffff
                    else:
                        # 512 M, highest known pre-digic 6 dryos (ixus285), should be OK if real is smaller
                        smisc['max_ram_addr'] = 0x1fffffff
                else:
                    # highest known vx (g7)?
                    smisc['max_ram_addr'] = 0x03ffffff
                warn("MAXRAMADDR unknown, defaulted to 0x%08x"%(smisc['max_ram_addr']))

        # make known address ranges available by name
        for ar in smisc['adr_ranges']:
            if ar['name'] == 'ROM':
                smisc['ar_rom'] = ar
            elif ar['name'] == 'RAM data':
                smisc['ar_ramdata'] = ar
            elif ar['name'] == 'RAM code':
                if ar['start_adr'] < smisc['max_ram_addr']:
                    smisc['ar_ramcode'] = ar
                else: # older finsig_thumb2 version didn't label TCM
                    smisc['ar_btcmcode'] = ar
            elif ar['name'] == 'TCM code':
                smisc['ar_btcmcode'] = ar
            elif ar['name'] == 'EVEC':
                smisc['ar_evec'] = ar

        if not 'adr_ranges_extra' in smisc:
            smisc['adr_ranges_extra'] = []

        if 'CAM_UNCACHED_BIT' in smisc['camera_h_vals']:
            ucadr = int(smisc['camera_h_vals']['CAM_UNCACHED_BIT']['val'],16)
        elif smisc['os_info']['os'] == 'VXWORKS':
            # all known vx cams use this, not detected by sig finder
            ucadr = 0x10000000
        else:
            ucadr = False

        if 'max_ram_addr' in smisc and ucadr:
            self.add_guess_adr_range('uncached',ucadr,smisc['max_ram_addr']+1)

        # main MMIO for digic < 6, d6 and d7 still have some there
        self.add_guess_adr_range('mmio',0xC0000000,0x01000000)

        if smisc['digic'] < 6:
            self.add_guess_adr_range('itcm',0,0x1000)
            if ucadr == 0x40000000:
                self.add_guess_adr_range('dtcm',0x80000000,0x1000)
            elif ucadr == 0x10000000:
                self.add_guess_adr_range('dtcm',0x40000000,0x1000)
            elif ucadr:
                self.warn('unexpected uncached adr 0x%08x'%(ucadr))
        else:
            # 2M starting at 0xdfe00000 is a different region (Omar TCM), d7 have TCM? in 0xdff
            self.add_guess_adr_range('mmio_0xd', 0xD0000000, 0x10000000 - 0x200000)
            # D6 has a few in the range 0xc8000000 - 0xc8200000
            if smisc['digic'] == 6:
                self.add_guess_adr_range('mmio_0xc8', 0xc8000000, 0x00300000)
            elif smisc['digic'] == 7:
                # D7 has some in the ranges 0xc1000000 - 0xc2xxxxxx
                self.add_guess_adr_range('mmio_0xc1', 0xc1000000, 0x02000000)
                # and 0xc8000000 - 0xc9xxxxxx
                self.add_guess_adr_range('mmio_0xc8', 0xc8000000, 0x02000000)

            self.add_guess_adr_range('atcm',0,0x4000)
            # TODO BTCM varies by model (dry ver?, d7), is part of copied code on later cams


        if smisc['digic'] >= 6:
            smisc['main_fw_code_end'] =  smisc['os_info']['verstr_adr'] - 1
        elif smisc['os_info']['os'] == 'DRYOS':
            # ctypes is a reasonable proxy on older firmware
            if 'ctypes' in self.name_map:
                smisc['main_fw_code_end'] =  self.name_map['ctypes'][0]['adr'] - 1

        else: # vxworks
            if 'ar_ramdata' in smisc:
                # vxworks copied data follows code
                smisc['main_fw_code_end'] = smisc['ar_ramdata']['src_adr'] - 1

        if not 'main_fw_code_end' in smisc:
            warn('failed to identify firmware code end')


    def load_stubs_s(self,fname,process_comments=None):
        """load contents of stubs file fname into dict stubs_data"""
        self.infomsg(0, "Load stubs %s\n"%(fname))

        loader = StubsFileParser(fname,self,process_comments)
        loader.process_file()

        self.infomsg(0,"Loaded %d functions, %d vars, %d constants from %s\n"%(loader.func_count, loader.data_count, loader.const_count, fname))

