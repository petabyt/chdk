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

import datetime
from ghidra.program.model.symbol import SymbolType

from chdklib.logutil import infomsg, warn
from chdklib.analyzeutil import is_likely_func_start, is_likely_tail_call, is_push_lr, is_pop_lr

g_options = {
    'pretend':False,
    'verbose':False,
}

def do_make_func(addr):
    #infomsg(0,'func %s\n'%(addr));
    if not g_options['pretend']:
        return createFunction(addr,None) != None
    return True

def process_thumb_label(s):
    t_addr = s.getAddress()
    addr = t_addr.subtract(1)
    # already part of a function, done
    if getFunctionContaining(addr):
        return False
    # normal function start, already disassembled
    # TODO without push probably OK for ptr refs (switches may be bad?)
    if is_likely_func_start(addr, require_push = False, disassemble = False):
        if g_options['verbose']:
            if not is_push_lr(getInstructionAt(addr)):
               infomsg(0,'%s thumb data notpush\n'%(addr));
            else:
               infomsg(0,'%s thumb data func\n'%(addr));
        return do_make_func(addr)

    # TODO check conflicting data and disassemble if needed

    return False

def process_insn_label(s):
    # check references to address:
    addr = s.getAddress()
    jump_refs = None
    for ref in s.getReferences():
        # data is least restrictive conditions, so process immediately
        if ref.getReferenceType().isData():
            # Pointer refs should mostly be a function if code, don't require push
            # note switches have both jump and data, but should be eliminated in main loop
            if is_likely_func_start(addr, require_push = False, disassemble = False):
                if g_options['verbose']:
                    if not is_push_lr(getInstructionAt(addr)):
                       infomsg(0,'%s data notpush\n'%(addr));
                    else:
                       infomsg(0,'%s data func\n'%(addr));
                return do_make_func(addr)
        # if there's a jump, check if it looks like the start of a function (push et al)
        # if reference type is call, Ghidra should have already detected function
        # don't check for unconditional vs conditional since conditional is somewhat common
        elif ref.getReferenceType().isJump():
            if not jump_refs:
                jump_refs = [ref]
            else:
                jump_refs.append(ref)

    if jump_refs is None:
        return False

    # if target is valid sequence with a push lr, done
    if is_likely_func_start(addr, require_push = True, disassemble = False):
        if g_options['verbose']:
            if not is_push_lr(getInstructionAt(addr)):
               infomsg(0,'%s notpush\n'%(addr));
            else:
               infomsg(0,'%s func\n'%(addr));
        return do_make_func(addr)

    # check for valid start without push
    if not is_likely_func_start(addr, require_push = False, disassemble = False):
        return False

    # check if any jump ref is a likely tail call
    for ref in jump_refs:
        if is_likely_tail_call(ref.getFromAddress()):
            if g_options['verbose']:
                prev_insn = getInstructionAt(ref.getFromAddress()).getPrevious()
                if not is_pop_lr(prev_insn):
                   infomsg(0,'%s notpop\n'%(addr));
                else:
                   infomsg(0,'%s tailcall\n'%(addr));
            return do_make_func(addr)

    return False

def labels_to_funcs_main():
    t0 = datetime.datetime.now()
    is_thumb2 =  str(currentProgram.getLanguageID())[-2:] == 'v7'
    symbol_count = 0
    found_count = 0
    create_count = 0
    # LAB_ labels are "dynamic" labels, no obvious way to iterate over them
    # without iterating over everything
    st = currentProgram.getSymbolTable()
    mem = currentProgram.getMemory()
    # getNumSymbols doesn't return dynamic, so not really accurate
    prog_max = long(st.getNumSymbols()*2.5)
    monitor.initialize(prog_max)
    for s in st.getAllSymbols(True):
        symbol_count += 1
        monitor.incrementProgress(1)
        monitor.checkCanceled()

        # already a function, skip
        if s.getSymbolType() == SymbolType.FUNCTION:
            continue

        # ignore non-global symbols like switch cases
        if str(s.getParentNamespace()) != 'Global':
            continue

        addr = s.getAddress()

        # skip bad addresses and non-exec blocks
        mb = mem.getBlock(addr)
        if not mb or not mb.isExecute():
            continue

        # creating functions appears to reset monitor state
        if monitor.getMaximum() != prog_max:
            monitor.setMaximum(prog_max)
            monitor.setProgress(symbol_count)

        found_count += 1
        if is_thumb2 and (addr.offset & 1):
            monitor.setMessage(s.getName())
            if process_thumb_label(s):
                create_count += 1
        else:
            # already defined as code
            if getInstructionAt(addr):
                monitor.setMessage(s.getName())
                if process_insn_label(s):
                    create_count += 1

    infomsg(0,"symbols %d checked %d created %d in %0.1f sec\n"%(
        symbol_count,
        found_count,
        create_count,
        (datetime.datetime.now()-t0).total_seconds()))

labels_to_funcs_main()
