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
from chdklib.logutil import infomsgf, warnf

g_options={
    'print_loaded_stubs':False,
}

# stubs_data = collected stubs structure
# vtype = func, data, const
# src = source file
# srctype = NHSTUB, DEF etc or CSV
# name = funtion / var name
# adrbase = address, possibly modified by adr_offset 
# comment = comment scraped from source file or generated
# adr_offset = offset from adr recorded in stub value for documentation purposes
def add_stubs_value(stubs_data, vtype, src, srctype, name, adr_base, comment=None,adr_offset=0):
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
    stubs_data['list'].append(sval)
    if name in stubs_data['name_map']:
        stubs_data['name_map'][name].append(sval)
    else:
        stubs_data['name_map'][name] = [sval]
    if adr in stubs_data['adr_map']:
        stubs_data['adr_map'][adr].append(sval)
    else:
        stubs_data['adr_map'][adr] = [sval]

def load_funcs_csv(fname,stubs_data):
    infomsgf(0,"Load csv %s\n",fname)
    src_name = os.path.basename(fname)
    rows = 0
    for r in csv.reader(file(fname)):
        adr = int(r[0],16)
        name = r[1].rstrip()
        # (stubs_entry_2) column
        if len(r) > 2:
            comment = r[2]
            # infomsgf(0,"%08x %s # %s\n",adr, name, comment)
        else:
            comment = None
        add_stubs_value(stubs_data, 'func', src_name, 'CSV',name, adr, comment)
        rows += 1
    infomsgf(0,"Loaded %d functions from %s\n",rows,fname)

def load_stubs_s(fname,stubs_data):
    infomsgf(0, "Load stubs %s\n",fname)
    src_name = os.path.basename(fname)
    # no current files should use regular NSTUB
    # don't currently use DEF_CONST
    stub_re = re.compile('\s*(DEF|NHSTUB|NSTUB|DEF_CONST|NHSTUB2)\s*\(\s*([A-Za-z_0-9]+)\s*,\s*([0\dXx0-9A-Fa-f]+)(\s*\+\s*[0\dXx0-9A-Fa-f]+)?\)\s*(?://\s*([^\s].*))?$')
    # TODO can recognize stubs_entry and scrape a bunch of stuff from comments
    # or just parse the comments whatever file they are in
    func_count = 0
    data_count = 0
    const_count = 0
    for line in file(fname):
        # trim any trailing CR for simplicity
        line = re.sub('\r?$','',line)
        # comments already be ignored by not matching main regex
        if re.match('\s*(//|$)',line):
            continue
        m = stub_re.match(line)
        if not m:
            continue
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
                warnf("func stub with addition O_o %s %s %s\n", name , adrstr, adradj_str)
            add_stubs_value(stubs_data,'func',src_name,op,name,adr,comment,adradj)
            func_count += 1
        elif op == 'DEF':
            # TODO tasks shouldn't be labeled as vars,
            # should normally be picked up from CSV but shouldn't hurt
            if re.match('task_',name):
                add_stubs_value(stubs_data,'func',src_name,op,name,adr,comment,adradj)
                func_count += 1
            else:
                add_stubs_value(stubs_data,'data',src_name,op,name,adr,comment,adradj)
                data_count += 1
        # not actually used for now
        elif op == 'DEF_CONST':
            add_stubs_value(stubs_data,'const',src_name,op,name,adr,comment,adradj)
            const_count += 1

        if g_options['print_loaded_stubs']:
            infomsgf(0,'%s %s %s', op, name, adr_str)
            adradj_str and infomsgf(0,"+%s",adradj_str)
            comment and infomsgf(0," # %s",comment)
            infomsgf(0,"\n")
    infomsgf(0,"Loaded %d functions, %d vars, %d constants from %s\n", func_count, data_count, const_count, fname)

# initialize options and return a hash to store everything in
def initialize(options):
    for k in g_options:
        if k in options:
            g_options[k]=options[k]
    return {
        'list':[],
        'name_map':{},
        'adr_map':{},
    }
    
