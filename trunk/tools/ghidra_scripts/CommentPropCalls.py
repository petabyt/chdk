# Ghidra script to document known propcase IDs in propcase calls
# Propset is specified by selecting corresponding platform_camera.h or propsetN.h
# Comments are added as EOL comments, to display in the decompiler view
# adjust edit->tool options->decompiler->display
#

#@category CHDK
#@author reyalp
#@menupath Tools.CHDK.Comment Prop Calls

# License: GPL
#
# Copyright 2020-2025 reyalp (at) gmail.com
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
import datetime

from chdklib.logutil import infomsg, warn

from chdklib.calldescriber import PropCallDescriber

def comment_prop_calls():
    filename = str(askFile("platform_camera.h or propsetN.h","select"))

    t0 = datetime.datetime.now()
    comment_count = 0
    cd = PropCallDescriber(filename)

    for desc in cd.describe_all_calls():
        if desc.args[0].prop_name != '':
            comment_count += 1
            setEOLComment(desc.addr,'%s,%s,%s'%(desc.args[0].desc,desc.args[1].desc,desc.args[2].desc))

    infomsg(0,'CommentPropCalls found %d commented %d in %0.1f sec\n'%(
        cd.match_count,
        comment_count,
        (datetime.datetime.now()-t0).total_seconds()))

comment_prop_calls()
