# Attempt to create functions for labels that look like function starts

#@category CHDK
#@author reyalp
#@menupath Tools.CHDK.Labels To Funcs

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

from ghidra.program.model.symbol import SymbolType

from chdklib.logutil import infomsg, warn
from chdklib.analyzeutil import is_likely_func_start, is_likely_tail_call, is_push_lr, is_pop_lr

g_options = {
    'pretend':False,
}

def do_make_func(addr):
    #infomsg(0,'func %s\n'%(addr));
    if not g_options['pretend']:
        return createFunction(addr,None) != None
    return True

def process_label(s):
    # check references to address:
    for ref in s.getReferences():
        # if there's a jump, check if it looks like the start of a function (push et al)
        # if reference type is call, Ghidra should have already detected function
        # don't check for unconditional vs conditional since conditional is somewhat common
        if ref.getReferenceType().isJump():
            addr = s.getAddress()
            if is_likely_func_start(addr, require_push = True, disassemble = False):
                # for inspecting non-trivial cases
                # if not is_push_lr(getInstructionAt(addr)):
                #    infomsg(0,'%s notpush\n'%(addr));
                # else:
                #    infomsg(0,'%s func\n'%(addr));
                return do_make_func(addr)

            # if source looks like a tail call, don't require func start include push
            if is_likely_tail_call(ref.getFromAddress()) and is_likely_func_start(addr, require_push = False, disassemble = False):
                # for inspecting non-trivial cases
                # prev_insn = getInstructionAt(ref.getFromAddress()).getPrevious()
                # if not is_pop_lr(prev_insn):
                #   infomsg(0,'%s notpop\n'%(addr));
                #else:
                #   infomsg(0,'%s tailcall\n'%(addr));
                return do_make_func(addr)

# TODO id veneers/thunks

    return False

def labels_to_funcs_main():
    found_count = 0
    create_count = 0
    # LAB_ labels are "dynamic" labels, no obvious way to iterate over them
    # without iterating over everything
    st = currentProgram.getSymbolTable()
    # getNumSymbols doesn't return dynamic, so not really accurate
    monitor.initialize(st.getNumSymbols()*2)
    for s in st.getAllSymbols(True):
        monitor.incrementProgress(1)
        monitor.checkCanceled()

        # already a function, skip
        if s.getSymbolType() == SymbolType.FUNCTION:
            continue
        # not already defined as code, skip
        # TODO should check address -1 for thumb pointers
        if not getInstructionAt(s.getAddress()):
            continue

        monitor.setMessage(s.getName())
        found_count += 1
        if process_label(s):
            create_count += 1

    infomsg(0,"found %d created %d\n"%(found_count, create_count))

labels_to_funcs_main()
