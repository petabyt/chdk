# Document mzrm_createmsg
# Comments are added as EOL comments, to display in the decompiler view
# adjust edit->tool options->decompiler->display
#

#@category CHDK
#@author reyalp
#@menupath Tools.CHDK.Comment Mzrm Calls

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

from chdklib.loadmzrmids import MzrmMsgList
from chdklib.calldescriber import MzrmCallDescriber

def comment_mzrm_create_calls():
    filename = str(askFile("mzrm id list","select"))

    mzrmlist = MzrmMsgList(filename)

    cd = MzrmCallDescriber(mzrmlist)

    for desc in cd.describe_all_calls():
        if desc.args[2].mzrm_name != '':
            setEOLComment(desc.addr,'%s,%s,%s,%s'%( desc.args[0].desc, desc.args[1].desc, desc.args[2].desc, desc.args[3].desc))

comment_mzrm_create_calls()
