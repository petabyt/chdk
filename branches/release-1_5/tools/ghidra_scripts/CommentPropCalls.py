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

from chdklib.calldescriber import CallDescriber

def comment_prop_calls():
    filename = str(askFile("platform_camera.h or propsetN.h","select"))
    pd = PropsetData(filename) 

    cd = CallDescriber(filename)
    funcs = ['GetPropertyCase','SetPropertyCase']
    for fname in funcs:
        for ref in getReferencesTo(getSymbol(fname,None).getAddress()):
            if not ref.getReferenceType().isCall():
                continue
            addr = ref.getFromAddress()
            desc = cd.describe_call(addr,fname)
            if desc is None:
                continue
            # TODO might want to label all, for calculated values?
            if desc[0].get('prop_name'):
                # TODO handle existing?
                setEOLComment(addr,'%s,%s,%s'%(desc[0]['desc'],desc[1]['desc'],desc[2]['desc']))


comment_prop_calls()
