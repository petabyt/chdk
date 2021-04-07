# License: GPL
#
# Copyright 2021 reyalp (at) gmail.com
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
#
from __main__ import *

from ghidra.program.model.data import Pointer32DataType

from chdklib.logutil import infomsg, warn

from chdklib.analyzeutil import get_valid_pointer_at, get_cstring_at

def is_print_char(b):
    return b > 0x31 and b < 0x7F

def init_levent_table():
    addr = toAddr('levent_table')
    if addr is None:
        raise ValueError('levent_table not found, check stubs or run ImportCHDKStubs.py')

    cnt = 0
    while True:
        try:
            pname = get_valid_pointer_at(addr)
            if pname is None or getInt(addr.add(4)) == -1:
                infomsg(0,'break\n')
                break

            clearListing(addr, addr.add(11))

            b = getByte(pname)
            # if it looks like a string
            if is_print_char(b):
                # if preceding is null, and address isn't already inside data, make string
                if getByte(pname.add(-1)) == 0 and getDataContaining(pname) == None:
                    createAsciiString(pname)

            createData(addr, Pointer32DataType())

            createDwords(addr.add(4),2)
            addr = addr.add(12)
            cnt += 1

        except(ghidra.program.model.mem.MemoryAccessException):
            warn("Memory access exception at %s"%(addr))
            break

    infomsg(0,'levent_table %s %d entries\n'%(toAddr('levent_table'),cnt))

def get_levent_def_at(addr):
    pname = get_valid_pointer_at(addr)
    evid = getInt(addr.add(4))
    if pname is None or evid == -1:
        return

    name = get_cstring_at(pname)
    if name is None:
        name = ''

    r={
        'name': name,
        'id': evid & 0xffffffff,
        'param':getInt(addr.add(8)) & 0xffffffff,
    }

    return r

class LeventData():
    def __init__(self):
        addr = toAddr('levent_table')
        if addr is None:
            raise ValueError('levent_table not found, check stubs or run ImportCHDKStubs.py')

        self.list=[]
        self.by_name = {}
        self.by_id = {}
        while True:
            evdef = get_levent_def_at(addr)
            if evdef is None:
                break

            self.list.append(evdef)

            if evdef['id'] not in self.by_id:
                self.by_id[evdef['id']] = evdef
            else:
                warn("dupe event id %x"%(evdef['id']))

            if evdef['name'] != '':
                if evdef['name'] not in self.by_name:
                    self.by_name[evdef['name']] = evdef
                else:
                    warn("dupe event name %s"%(evdef['name']))

            addr = addr.add(12)

