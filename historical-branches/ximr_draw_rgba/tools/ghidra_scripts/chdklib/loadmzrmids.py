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

from __main__ import *

import re

from chdklib.logutil import infomsg, warn

class MzrmId:
    def __init__(self,mid,name):
        self.mid = mid
        if name == '(NULL)' or name == '(no name)':
            self.name = 'unk_%03d'%(mid)
            self.unk = True
        else:
            self.name = name
            self.unk = False

# Input file is expected to be in an ordered list
# optionally starting with a head
#ID	NAME (NULL if function is NULL)
# and then
#nnn:	Name
# or
#sub_xxxxxxxx:	Name
# see https://chdk.setepontos.com/index.php?topic=11316.msg129104#msg129104

class MzrmMsgList:
    def __init__(self, fname):
        self.by_name = {}
        self.by_id = {}
        mid = 0
        for line in open(fname):
            line = re.sub('\r?\n?$','',line)
            if mid == 0:
                if re.match('^ID\s',line):
                    continue
                elif not re.match('^(sub|[\d]{3})',line):
                    raise ValueError('unexpected file format')

            m = re.match('^(sub_[A-Fa-f0-9]{8}|[\d]{3}):\s+(.*)',line)

            name = m.group(2)

            mid_obj = MzrmId(mid,name)
            self.by_name[name] = mid_obj
            self.by_id[mid] = mid_obj
            mid += 1

