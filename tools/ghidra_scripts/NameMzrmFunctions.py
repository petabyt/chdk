# Name functions that call mzrm_createmsg exactly once based on message id
#

#@category CHDK
#@author reyalp
#@menupath Tools.CHDK.Name Mzrm Functions

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

import ghidra.program.model.symbol.SourceType as SourceType

from chdklib.logutil import infomsg, warn

from chdklib.loadmzrmids import MzrmMsgList
from chdklib.calldescriber import MzrmCallDescriber
from chdklib.analyzeutil import get_refs_from_addrset

g_options = {
    'pretend':False,
}


def process_call(desc, mzrm_createmsg_addr):
    # should always have a function, since call describer won't find if not
    fn = currentProgram.getListing().getFunctionContaining(desc.addr)

    mzrm_name = desc.args[2].mzrm_name
    if mzrm_name == '':
        mzrm_name = 'mzrm_unk_%d'%(desc.args[2].val)

    # if the function already has a non-default name, leave it
    sym_source = fn.getSymbol().getSource()
    if not (sym_source == SourceType.ANALYSIS or sym_source == SourceType.DEFAULT):
        # TODO could add repeatable comment
        infomsg(0,"%s %s no-default source %s\n"%(fn.getEntryPoint(),fn.getName(), sym_source))
        return False

    n = 0
    for ref in get_refs_from_addrset(fn.getBody()):
        if ref.getToAddress() == mzrm_createmsg_addr:
            n += 1

    # only attempt to name if function has exactly one ref to mzrm_createmsg
    if n != 1:
        infomsg(0,'%s %s skip, has %d mzrm_createmsg calls\n'%(fn.getEntryPoint(),mzrm_name,n))
        return False


    # check for existing uses of this name
    mzrm_name_base = mzrm_name
    name_count = 0
    while True:
        n_syms = 0
        # could be multiple
        for sym in getSymbols(mzrm_name,None):
            # if already used with our address, done!
            if sym.getAddress() == fn.getEntryPoint():
                infomsg(0,'%s already %s\n'%(fn.getEntryPoint(),mzrm_name))
                return True
            n_syms += 1

        # if none, found a free name
        if n_syms == 0:
            break

        name_count += 1
        mzrm_name = '%s_%d'%(mzrm_name_base,name_count)

    infomsg(0,'%s %s\n'%(fn.getEntryPoint(),mzrm_name))
    if not g_options['pretend']:
        fn.setName(mzrm_name, SourceType.ANALYSIS)

    return True


def name_mzrm_functions():
    sym = getSymbol('mzrm_createmsg',None)
    if not sym:
        warnf('mzrm_createmsg not present')
        return

    mzrm_createmsg_addr = sym.getAddress()

    filename = str(askFile("mzrm id list","select"))

    mzrmlist = MzrmMsgList(filename)

    cd = MzrmCallDescriber(mzrmlist)

    found_count = 0
    named_count = 0

    for desc in cd.describe_all_calls():
        if process_call(desc, mzrm_createmsg_addr):
            named_count += 1
        found_count += 1

    infomsg(0,"found %d named %d\n"%(found_count, named_count))

name_mzrm_functions()
