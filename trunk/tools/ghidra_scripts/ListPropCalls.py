# Ghidra script to list propcase related calls in the console
# Propset is specified by selecting corresponding platform_camera.h or propsetN.h
# propcases to be listed can be specified by name, like TV or PROPCASE_TV or number
# or '*' for all propcases defined in propset
#
# Jump to location by double clicking the address
#

#@category CHDK
#@author reyalp
#@menupath Tools.CHDK.List Prop Calls

# License: GPL
#
# Copyright 2020 reyalp (at) gmail.com
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

from chdklib.logutil import infomsg, warn
from chdklib.defines_loader import PropsetData

from chdklib.calldescriber import PropCallDescriber

def list_prop_calls():
    filename = str(askFile("platform_camera.h or propsetN.h","select"))
    instr = str(askString("Propcases","Names, numbers or *")).upper()
    pd = PropsetData(filename)
    prop_ids = []
    do_all = False

    for s in re.split('[ ,]+',instr):
        if s == '*':
            do_all = True
        elif re.match('0x[0-9a-f]+$',s,re.I):
            prop_ids.append(int(s,16))
        elif re.match('[0-9]+$',s):
            prop_ids.append(int(s,10))
        else:
            if re.match('^PROPCASE_',s):
                prop_name = s
            else:
                prop_name = 'PROPCASE_' + s
            prop_id = pd.by_name.get(prop_name)
            if prop_id is None:
                warn('ignoring unknown propcase id %s'%(prop_name))
            else:
                prop_ids.append(prop_id)

        if len(prop_ids) == 0 and not do_all:
            warn('no valid IDs specified, exiting')
            return

    infomsg(0,"Searching for")
    msg = []
    if do_all:
        msg.append('all known')
    for prop_id in prop_ids:
        if prop_id in pd.by_id:
            msg.append("%s (%d)"%(pd.by_id[prop_id],prop_id))
        else:
            msg.append("%d"%(prop_id))

    infomsg(0," %s from propset %d\n"%(', '.join(msg),pd.propset))

    cd = PropCallDescriber(filename)
    funcs = ['GetPropertyCase','SetPropertyCase']
    for fname in funcs:
        for ref in getReferencesTo(getSymbol(fname,None).getAddress()):
            if not ref.getReferenceType().isCall():
                continue
            addr = ref.getFromAddress()
            desc = cd.describe_call(addr,fname)
            if desc is None:
                continue
            prop_id = desc[0]['val']
            if (do_all and pd.by_id.get(prop_id)) or prop_id in prop_ids:
                infomsg(0,'%s %s(%s,%s,%s)\n'%(addr,fname,desc[0]['desc'],desc[1]['desc'],desc[2]['desc']))


list_prop_calls()
