# Clean up some common errors in Thumb2 firmware analysis
#  * Data at +1 from where disassembly failed, usually thumb pointers
#  * Functions with no references disassembled as ARM, which ended due to
#    disassembly errors. Firmware is mostly thumb, so these usually come from
#    bytes that match either
#  * Data with no references blocking disassembly
#  * Unaligned data blocking disassembly, usually thumb pointer refs

#@category CHDK
#@author reyalp
#@menupath Tools.CHDK.Thumb2 bookmark cleanup

# License: GPL
#
# Copyright 2019 reyalp (at) gmail.com
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

import re
from java.math import BigInteger

from chdklib.logutil import infomsg, warn
from chdklib.analyzeutil import set_tmode_reg_at, get_tmode_reg_at

g_options = {
    'pretend':False,
    'remove_resolved':True,
}

def check_thumb_data_conflict(b):
    m = re.match('Failed to disassemble at ([0-9a-fA-F]{8}) due to conflicting data at ([0-9a-fA-F]{8})',b.getComment())
    # Not this kind of bookmark
    if not m:
        return False

    # check if data conflict is at +1. i_addr should be the same as bookmark, but number
    i_addr = int(m.group(1),16)
    d_addr = int(m.group(2),16)
    if d_addr != i_addr + 1:
        return False

    b_addr = b.getAddress()

    # thumb instruction already there, assume resolved
    if getInstructionAt(b_addr):
        if get_tmode_reg_at(b_addr):
            infomsg(0,"%s looks resolved!\n"%(b_addr))
            return True
        else:
            # ARM instruction, likely a different problem
            return False

    bad_data = getDataAt(toAddr(d_addr))
    if bad_data:
        infomsg(0,'remove data %s\n'%(bad_data))
        if not g_options['pretend']:
            removeData(bad_data)
    infomsg(0,"Dis thumb %s\n"%(b_addr))
    if not g_options['pretend']:
        # assume thumb if data was at +1
        set_tmode_reg_at(b_addr,1)
        if disassemble(b_addr):
            return True
        else:
            infomsg(0,"Dis failed %s\n"%(b_addr))
            return False

def check_arm_without_caller(b):
    # currently everything handled is in this category
    if b.getCategory() != 'Bad Instruction':
        return False

    b_addr = b.getAddress()
    # thumb, not this problem
    if get_tmode_reg_at(b_addr) == 1:
        infomsg(4,"arm_without_caller already tmode %s\n"%(b.getAddress()))
        return False

    # is there a function associated with this address?
    fn = getFunctionContaining(b_addr)
    if not fn:
        m = re.match('Unable to resolve constructor at ([0-9A-Fa-f]{8}) \(flow from ([0-9A-Fa-f]{8})\)',b.getComment())
        if not m:
            infomsg(4,"arm_without_caller no fun %s\n"%(b.getAddress()))
            return False

        i_addr = int(m.group(1),16)
        f_addr = int(m.group(2),16)
        # did it flow directly from preceding code?
        if f_addr < i_addr and f_addr - i_addr <= 4:
            fn = getFunctionContaining(toAddr(f_addr))
            if not fn:
                infomsg(4,"arm_without_caller no fun2 %s\n"%(b.getAddress()))
                return False


    for r in getReferencesTo(fn.getEntryPoint()):
        # function was called from somewhere, maybe legit ARM
        if r.getReferenceType().isCall():
            infomsg(4,"arm_without_caller has caller %s\n"%(b.getAddress()))
            return False

    # also check for data at +1
    bad_data = getDataAt(b_addr.add(1))
    if bad_data:
        infomsg(0,'remove data %s\n'%(bad_data))
        if not g_options['pretend']:
            removeData(bad_data)

    infomsg(0,"Clear function %s and disassemble thumb\n"%(fn))
    if not g_options['pretend']:
        clearListing(fn.getBody())
        set_tmode_reg_at(fn.getEntryPoint(),1)
        if disassemble(fn.getEntryPoint()):
            return True
        else:
            infomsg(0,"Dis failed %s\n"%(fn.getEntryPoint()))
            return False

def check_other_data_conflict(b):
    # currently everything handled is in this category
    if b.getCategory() != 'Bad Instruction':
        return False

    m = re.match('Failed to disassemble at ([0-9A-Fa-f]{8}) due to conflicting data(?: at ([0-9A-Fa-f]{8}))? \(flow from ([0-9A-Fa-f]{8})\)',b.getComment())
    # Not this kind of bookmark
    if not m:
        return False

    b_addr = b.getAddress()

    # only check if we're doing thumb code
    if get_tmode_reg_at(b_addr) == 0:
        flow_addr = int(m.group(3),16)
        if get_tmode_reg_at(toAddr(flow_addr)) == 0 and flow_addr != b_addr.getOffset():
            infomsg(4,"check_other_data_conflict not in thumb %s\n"%(b.getAddress()))
            return False

    # is data at +1?
    bad_data = getDataAt(b_addr.add(1))

    # check for unaligned data containing the instruction
    # or data with no references
    if not bad_data:
        bad_data = getDataContaining(b_addr)
        if not bad_data:
            infomsg(4,"check_other_data_conflict no bad data %s\n"%(b.getAddress()))
            return False

        if bad_data.getAddress().getOffset() & 1 == 0 and len(getReferencesTo(bad_data.getAddress())) != 0:
            infomsg(4,"check_other_data_conflict aligned or refs %s\n"%(b.getAddress()))
            return False

    infomsg(0,'remove data %s\n'%(bad_data))
    if not g_options['pretend']:
        removeData(bad_data)

    infomsg(0,"Dis thumb %s\n"%(b_addr))
    if not g_options['pretend']:
        # assume thumb if data was at +1
        set_tmode_reg_at(b_addr,1)
        if disassemble(b_addr):
            return True
        else:
            infomsg(0,"Dis failed %s\n"%(b_addr))
            return False

def check_bookmark(b):
    if check_thumb_data_conflict(b):
        return True
    if check_arm_without_caller(b):
        return True
    if check_other_data_conflict(b):
        return True

    return False

def thumb_bookmark_cleanup_main():
    bmm = getCurrentProgram().getBookmarkManager()
    # cleanup triggers more disassembly, which can create more of the same kind of errors
    # try a few times or until nothing cleanable was found
    for clean_pass in range(1,11):
        check_count = 0
        clean_count = 0
        for b in bmm.getBookmarksIterator("Error"):
            check_count += 1
            if check_bookmark(b):
                clean_count += 1
                if g_options['remove_resolved'] and not g_options['pretend']:
                    bmm.removeBookmark(b)


        infomsg(0,"pass %d checked %d cleaned %d\n"%(clean_pass, check_count, clean_count))
        if clean_count == 0:
            break
        # wait for analysis to complete before next pass
        analyzeChanges(getCurrentProgram())

thumb_bookmark_cleanup_main()

