# Ghidra script to list "Logical Event" related calls in the console
# events to be listed can be specified by name (case insensitive)
# like ConnectVideoCable, by number, or '*' for all known
#
# Jump to location by double clicking the address
#

#@category CHDK
#@author reyalp
#@menupath Tools.CHDK.List Levent Calls

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

from chdklib.calldescriber import LeventCallDescriber

def list_levent_calls():
    cd = LeventCallDescriber()

    instr = str(askString("Event","Names, numbers or *")).upper()
    event_ids = []
    do_all = False

    for s in re.split('[ ,]+',instr):
        if s == '*':
            do_all = True
        elif re.match('0x[0-9a-f]+$',s,re.I):
            event_ids.append(int(s,16))
        elif re.match('[0-9]+$',s):
            event_ids.append(int(s,10))
        else:
            event_id = cd.ld.by_name.get(s)
            if event_id is None:
                # iterate over list for case insensitive compare
                for evdef in cd.ld.list:
                    if evdef['name'].lower() == s.lower():
                        event_id = evdef['id']
                        break

            if event_id is None:
                warn('ignoring unknown event id %s'%(s))
            else:
                event_ids.append(event_id)

    if len(event_ids) == 0 and not do_all:
        warn('no valid IDs specified, exiting')
        return

    infomsg(0,"Searching for")
    msg = []
    if do_all:
        msg.append('all known')
    for event_id in event_ids:
        if event_id in cd.ld.by_id and cd.ld.by_id[event_id]['name'] !='':
            msg.append("%s (%d)"%(cd.ld.by_id[event_id]['name'],event_id))
        else:
            msg.append("%d"%(event_id))

    infomsg(0," %s\n"%(', '.join(msg)))

    for desc in cd.describe_all_calls():
        event_id = desc.args[0].val
        if (do_all and cd.ld.by_id.get(event_id)) or event_id in event_ids:
            infomsg(0,'%s %s(%s'%(desc.addr,desc.fname,desc.args[0].desc))
            if len(desc.args) == 2:
                infomsg(0,', %s'%(desc.args[1].desc))
            infomsg(0,')\n')


list_levent_calls()
