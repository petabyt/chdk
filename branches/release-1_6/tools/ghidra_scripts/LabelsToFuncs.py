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
from ghidra.program.model.symbol.Namespace import GLOBAL_NAMESPACE_ID

from chdklib.logutil import infomsg, warn
from chdklib.analyzeutil import (
    is_likely_func_start,
    is_likely_tail_call,
    is_push_lr,
    is_pop_lr,
    get_insn_desc,
    set_tmode_reg_at
)

g_options = {
    'pretend':False,
    'verbose':False,
}

def do_make_func(addr):
    #infomsg(0,'func %s\n'%(addr));
    if not g_options['pretend']:
        return createFunction(addr,None) != None
    return True

def process_thumb_insn_label(addr):
    # already part of a function, done
    # TODO could check for incorrect inclusion from tail call
    if getFunctionContaining(addr):
        return False
    # normal function start, already disassembled
    # without push seems OK, switches excluded in main loop
    if is_likely_func_start(addr, require_push = False, disassemble = False):
        if g_options['verbose']:
            if not is_push_lr(getInstructionAt(addr)):
               infomsg(0,'%s thumb data notpush\n'%(addr));
            else:
               infomsg(0,'%s thumb data func\n'%(addr));
        return do_make_func(addr)

    return False

def process_thumb_notdis_label(addr,t_addr):
    # no instruction, look for possible code
    for ref in getReferencesTo(t_addr):
        idesc = get_insn_desc(ref.getFromAddress())
        if idesc is None:
            continue
        # tbb instructions create weird refs
        # also don't want anything ref'd by lrdb
        # mvn almost always constants that look like addresses
        # mov could be suspect, but also valid since ghidra tracks load + mov
        mne = idesc.get_mne()
        if mne == 'tbb' or mne == 'tbh' or mne == 'ldrb' or mne == 'mvn':
            # infomsg(0,"%s skip ref %s\n"%(addr,mne))
            return False

    if not is_likely_func_start(addr, require_push = False, disassemble = True, tmode = True):
        return False

    # infomsg(0,"%s dis thumb\n"%(addr))
    bad_data = getDataAt(t_addr)
    if bad_data:
        if g_options['verbose']:
            infomsg(0,'%s remove data %s\n'%(t_addr,bad_data))
        if not g_options['pretend']:
            removeData(bad_data)
    else:
        # check for data containing
        bad_data = getDataContaining(addr)
        # if it's also unaligned, assume bad
        # could check for other signs of validity, but already have valid func start
        if bad_data and (bad_data.getAddress().getOffset() & 1 == 1):
            if g_options['verbose']:
                infomsg(0,'%s remove containing data %s\n'%(t_addr,bad_data))
            if not g_options['pretend']:
                removeData(bad_data)

    # if existing function without disassembled code, remove and try to recreate
    old_fn = getFunctionAt(addr)
    if old_fn:
        # infomsg(0,'%s remove func\n'%(addr))
        if not g_options['pretend']:
            removeFunction(old_fn)

    if not g_options['pretend']:
        # set thumb since this case is only used when address has thumb bit set
        set_tmode_reg_at(addr,1)
        if not disassemble(addr):
            warn("%s dis fail"%(addr))
            return False

    if g_options['verbose']:
        infomsg(0,'%s thumb data dis func\n'%(addr));
    return do_make_func(addr)


def process_thumb_label(s):
    t_addr = s.getAddress()
    addr = t_addr.subtract(1)
    if getInstructionAt(addr):
        return process_thumb_insn_label(addr)
    else:
        return process_thumb_notdis_label(addr,t_addr)

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
        if s.getParentNamespace().getID() != GLOBAL_NAMESPACE_ID:
            continue

        addr = s.getAddress()

        # skip bad addresses and non-exec blocks
        mb = mem.getBlock(addr)
        if not mb or not mb.isExecute():
            continue

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

        # creating functions appears to reset monitor state
        if monitor.getMaximum() != prog_max:
            monitor.setMaximum(prog_max)
            monitor.setProgress(symbol_count)


    infomsg(0,"symbols %d checked %d created %d in %0.1f sec\n"%(
        symbol_count,
        found_count,
        create_count,
        (datetime.datetime.now()-t0).total_seconds()))

labels_to_funcs_main()
