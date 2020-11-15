# Attempt to create functions for somethings that are bookmarked by analysis

#@category CHDK
#@author reyalp
#@menupath Tools.CHDK.Function bookmark cleanup

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

import ghidra.program.model.symbol.FlowType as FlowType
import ghidra.program.model.symbol.SymbolType as SymbolType
import ghidra.program.model.address.AddressSet as AddressSet
import ghidra.program.model.symbol.SourceType as SourceType
import re

from chdklib.logutil import infomsg, warn
from chdklib.analyzeutil import get_pinsn_at, get_tmode_reg_at, is_likely_func_start

g_options = {
    'pretend':False,
    'remove_resolved':True,
}

def do_make_func(addr):
    infomsg(0,'make func %s\n'%(addr));
    fc = getFunctionContaining(addr)
    f_addr = None
    if fc:
        infomsg(0,'%s already part of function %s\n'%(addr, fc.getName()))
        fb = fc.getBody()
        # check if containing function is non-contiguous (often, but not always incorrect)
        if fb.getNumAddressRanges() > 1:
            r = fb.getRangeContaining(addr)
            # if our func is start of non-contiguous func, remove it
            if r.getMinAddress() == addr:
                infomsg(0,'remove %s from %s %s\n'%(addr,fc.getName(),fc.getSymbol().address))
                if not g_options['pretend']:
                    s = fc.getSymbol()
                    if s.getSource() == SourceType.ANALYSIS or s.getSource() == SourceType.DEFAULT:
                        f_addr = fc.getSymbol().address
                        removeFunction(fc)
                    else:
                        infomsg(0,'not removing non-default source function %s\n'%(fc.getName()))
                    # removing from fc body doesn't seem reliable, works for some?
                    # fb.delete(r)
                    # fc.setBody(AddressSet(fb))
                    # analyzeChanges(currentProgram)


    if g_options['pretend']:
        return True

    f = createFunction(addr,None)
    if f_addr:
        fr = createFunction(f_addr,None)
        if fr:
            infomsg(0,'recreated %s at %s\n'%(fr.getName(),f_addr))
        else:
            infomsg(0,'failed to re-create function at %s\n'%(f_addr))

    if f:
        return True
    else:
        warn('create function failed %s'%(addr))
        return False

def clean_func_exists(b):
    jump_ref = False;
    addr = b.getAddress()

    # check if function has already been created starting at this address
    sym = getSymbolAt(addr)
    if sym and sym.getSymbolType() == SymbolType.FUNCTION: 
        infomsg(0,'already a function %s\n'%(addr));
        return True

    # check references to address:
    for ref in getReferencesTo(addr):
        # if the reference is a call, assume this is a valid function start
        if ref.getReferenceType().isCall():
            return do_make_func(addr)
        if ref.getReferenceType().isJump():
            jump_ref = ref

    # if there's a jump, check if it looks like the start of a function (push et al)
    if jump_ref and is_likely_func_start(addr):
        return do_make_func(addr)

    return False

def clean_code_from_opref(b):
    addr = b.getAddress()

    # opref on thumb code has thumb bit set
    tmode = get_tmode_reg_at(addr)
    if tmode and addr.getUnsignedOffset() & 1:
        addr = addr.add(-1)

    # check if function has already been created starting at this address
    sym = getSymbolAt(addr)
    if sym and sym.getSymbolType() == SymbolType.FUNCTION: 
        infomsg(0,'already a function %s\n'%(addr));
        return True

    if is_likely_func_start(addr):
        return do_make_func(addr)

    return False

def func_bookmark_clean_main():
    bmm = getCurrentProgram().getBookmarkManager()
    check_count = 0
    clean_count = 0
    for b in bmm.getBookmarksIterator("Analysis"):
        if (b.getCategory() == 'Function Start Search delayed Overlap'
            and b.getComment() == 'Function exists at probable good function start'):
            check_count += 1
            status = clean_func_exists(b)
        elif (b.getCategory() ==  'Found Code'
            and b.getComment() == 'Found code from operand reference'):
            check_count += 1
            status = clean_code_from_opref(b)
        else:
            status = False

        if status:
            clean_count += 1
            if g_options['remove_resolved'] and not g_options['pretend']:
                bmm.removeBookmark(b)
    
    infomsg(0,"checked %d cleaned %d\n"%(check_count, clean_count))

func_bookmark_clean_main()
