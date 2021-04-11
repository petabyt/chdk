# List mzrm_createmsg calls in the console
# calls to be listed can be specified by name (case insensitive)
# by number, or '*' for all known
#
# For information about generating handler list
# https://chdk.setepontos.com/index.php?topic=11316.msg129104#msg129104
#
# Jump to location by double clicking the address
#

#@category CHDK
#@author reyalp
#@menupath Tools.CHDK.List Mzrm Calls

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


import os
import re

from chdklib.logutil import infomsg, warn

from chdklib.calldescriber import MzrmCallDescriber
from chdklib.loadmzrmids import MzrmMsgList

def list_mzrm_create_calls():

    filename = str(askFile("mzrm id list","select"))

    mzrmlist = MzrmMsgList(filename)

    cd = MzrmCallDescriber(mzrmlist)

    instr = str(askString("MZRM Messages","Names, numbers or *")).upper()
    mzrm_ids = []
    do_all = False

    for s in re.split('[ ,]+',instr):
        if s == '*':
            do_all = True
        elif re.match('0x[0-9a-f]+$',s,re.I):
            mzrm_ids.append(int(s,16))
        elif re.match('[0-9]+$',s):
            mzrm_ids.append(int(s,10))
        else:
            mzrm_msg = mzrmlist.by_name.get(s)
            if mzrm_msg is None:
                # iterate over list for case insensitive compare
                for mzrm_id in mzrmlist.by_id:
                    if mzrmlist.by_id[mzrm_id].name.lower() == s.lower():
                        mzrm_msg = mzrmlist.by_id[mzrm_id]
                        break

            if mzrm_msg is None:
                warn('ignoring unknown mesasge id %s'%(s))
            else:
                mzrm_ids.append(mzrm_msg.mid)

    if len(mzrm_ids) == 0 and not do_all:
        warn('no valid IDs specified, exiting')
        return

    infomsg(0,"Searching for")
    msg = []
    if do_all:
        msg.append('all known')
    for mzrm_id in mzrm_ids:
        if mzrm_id in mzrmlist.by_id and not mzrmlist.by_id[mzrm_id].unk:
            msg.append("%s (%d)"%(mzrmlist.by_id[mzrm_id].name,mzrm_id))
        else:
            msg.append("%d"%(mzrm_id))

    infomsg(0," %s\n"%(', '.join(msg)))

    for desc in cd.describe_all_calls():
        mzrm_id = desc.args[2].val
        if (do_all and mzrmlist.by_id.get(mzrm_id)) or mzrm_id in mzrm_ids:
            infomsg(0,'%s %s(%s,%s,%s,%s)\n'%(desc.addr,desc.fname,
                    desc.args[0].desc,
                    desc.args[1].desc,
                    desc.args[2].desc,
                    desc.args[3].desc))


list_mzrm_create_calls()
