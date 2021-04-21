# Ghidra needs this in a module to access standard stuff
from __main__ import *

import re

from chdklib.logutil import infomsg, warn

from java.math import BigInteger
import ghidra.program.model.mem.MemoryBufferImpl as MemoryBufferImpl
# or ProgramProcessorContext ?
from ghidra.program.model.lang import ProcessorContextImpl
import ghidra.app.util.PseudoInstruction as PseudoInstruction

# roughly based on Ghidra/Features/Base/ghidra_scripts/AssemblyThrasherDevScript.java
# unclear if this is a good way to do it
# https://ghidra.re/ghidra_docs/api/ghidra/app/util/PseudoInstruction.html
# https://ghidra.re/ghidra_docs/api/ghidra/program/model/lang/InstructionPrototype.html
def get_pinsn_at(address, thumb=False):
    """
    attempt to dissemble adr, return PseudoInstruction or None
    for pre-analysis without affecting program

    """
    # NOTE in modules used from interpreter window, using the currentProgram
    # variable fails on tab switches (currentProgram is set at import time)
    cp = getCurrentProgram()
    mbi = MemoryBufferImpl(cp.getMemory(),address)
    # API changed in 9.2
    if ghidra.framework.ApplicationVersion(getGhidraVersion()) >= ghidra.framework.ApplicationVersion('9.2'):
        pci = ProcessorContextImpl(cp.getLanguage())
    else:
        pci = ProcessorContextImpl(cp.getProgramContext().getRegisters())

    treg = pci.getRegister('TMode')

    # don't try to set thumb reg if firmware not loaded as t
    if treg:
        if thumb:
            pci.setValue(pci.getRegister('TMode'),BigInteger("1"))
        else:
            pci.setValue(pci.getRegister('TMode'),BigInteger("0"))
    elif thumb:
        warn("ignoring Thumb set on non-t processor")

    try:
        ip = cp.getLanguage().parse(mbi,pci,False)
        pi = PseudoInstruction(address,ip,mbi,pci)
        return pi
    except (ghidra.program.model.lang.UnknownInstructionException,
            ghidra.program.model.lang.InsufficientBytesException,
            ghidra.program.model.address.AddressOverflowException):
        return None

def set_tmode_reg_at(address, tmode):
    """attempt to set thumb mode register at address, true if register set"""
    # for thumb "register" value, will be None if not a thumb capable processor
    progCtx = getCurrentProgram().getProgramContext()
    tmodeReg = progCtx.getRegister("TMode")
    try:
        if tmode == 1:
            if tmodeReg:
                progCtx.setValue(tmodeReg,address,address,BigInteger("1"))
            else:
                warn("Thumb bit set without TMode register %s"%(address))
        else:
            progCtx.setValue(tmodeReg,address,address,BigInteger("0"))
        return True
    except ghidra.program.model.listing.ContextChangeException:
        warn("Set tmode failed at %s"%(address))
        return False

def get_tmode_reg_at(address):
    """get thumb mode at address, return true if set, false if not or not thumb proc"""
    progCtx = getCurrentProgram().getProgramContext()
    tmodeReg = progCtx.getRegister("TMode")
    # just return not thumb if TMode not present
    if not tmodeReg:
        return 0

    return int(progCtx.getValue(tmodeReg,address,False))

def get_insn_ops_text(insn):
    """return nmnemonic and operands as list of strings"""
    r=[]
    i = 0
    while True:
        op = insn.getDefaultOperandRepresentation(i)
        if op == '<UNSUPPORTED>':
            return r
        r.append(op)
        i += 1

def is_likely_before_push_insn(insn):
    """
    is instruction likely to appear before push in a function
    note conditionals are allowed and occasionally appear
    not comprehensive or rigorous
    """
    mne = insn.getMnemonicString()
    ops = get_insn_ops_text(insn)

    # all matched instructions have at least mnemonic + 2 operands
    if len(ops) <= 1:
        return False

    # special case for sub sp,#const / sub sp,sp,#const, before checks below
    if mne == 'sub' and ops[0] == 'sp' and re.match('sp|#',ops[1]):
        return True

    # if ops 0-3 are reg > r3, bail
    # technically r12/ip could be allowed
    # shifters are part of the operand in ghidra
    if re.match('r[4-9]|r1[0-5]|sp|ip|lr|pc',ops[0]):
        return False

    if re.match('r[4-9]|r1[0-5]|sp|ip|lr|pc',ops[1]):
        return False

    # shift by non-allowed reg
    if re.search('(?:lsr|lsl|asr|ror) (?:r[4-9]|r1[0-5]|sp|ip|lr|pc)',ops[1]):
        return False

    if len(ops) > 2:
        if re.match('r[4-9]|r1[0-5]|sp|ip|lr|pc',ops[2]):
            return False
        if re.search('(?:lsr|lsl|asr|ror) (?:r[4-9]|r1[0-5]|sp|ip|lr|pc)',ops[2]):
            return False

    # in armv5 ghidra treats register offset ldr/str as a signle operand, like [r1,r2,lsl #0x2]
    if (mne[0:3] == 'ldr' or mne[0:3] == 'str') and re.search(',(r[4-9]|r1[0-5]|sp|ip|lr|pc)',ops[1]):
        return False

    # special case to bail early on common bad instructions
    # mov r0,r0 is all zeros in thumb
    if len(ops) == 2 and mne == 'mov' and ops[0] == 'r0' and ops[1] == 'r0':
        return False

    # all zeros in arm
    if len(ops) == 3 and mne == 'andeq' and ops[0] == 'r0' and ops[1] == 'r0' and ops[2] == 'r0':
        return False

    # could be valid but rare and don't want to hit ldr/str cases below
    if mne[0:4] == 'ldrd':
        return False

    if mne[0:4] == 'strd':
        return False

    # ldr, ldrh etc into r0-r3, from r0-r3, or PC
    # ghidra formats ldr rn, [pc...] as ldr rn, [0xblah]
    # on others, [rn,#disp], even if disp is 0x0
    if mne[0:3] == 'ldr' and re.match('\[(?:0x|r[0-3],)',ops[1]):
        return True

    # ghidra treats register offset as 3 reg args and constant,
    # out of range regs would be caught above
    if mne[0:3] == 'ldr' and len(ops) == 4:
        return True

    # str uncommon before push, but legal and common funcs without push
    if mne[0:3] == 'str' and re.match('\[r[0-3],',ops[1]):
        return True

    # ghidra treats register offset as 3 reg args and constant,
    # out of range regs would be caught above
    if mne[0:3] == 'str' and len(ops) == 4:
        return True

    # ghidra uses adr, adr.w mnemonics
    if mne[0:3] == 'adr':
        return True

    # the following all rely on the initial address checks to ensure
    # up to 3 reg or shifter operands are acceptable
    # grouped for readability only

    # moves
    if re.match('mov|cpy|mvn',mne):
        return True

    # arithmetic
    if re.match('add|rsb|sub',mne):
        return True

    # bitwise
    if re.match('and|asr|bic|bfi|eor|lsl|lsr|orr|ror|ubfx',mne):
        return True

    # comparisons
    if re.match('cmn|cmp|teq|tst',mne):
        return True

    return False

# mostly copy/paste from is_likely_before_push_insn
def is_likely_after_pop_insn(insn):
    """
    is instruction likely to appear after pop, before tail call
    conditionals are allowed
    not comprehensive or rigorous
    """
    mne = insn.getMnemonicString()
    ops = get_insn_ops_text(insn)

    # all matched instructions have at least mnemonic + 2 operands
    if len(ops) <= 1:
        return False

    # if ops 0-3 are reg > r3, bail
    # technically r12/ip could be allowed
    # shifters are part of the operand in ghidra
    if re.match('r[4-9]|r1[0-5]|sp|ip|lr|pc',ops[0]):
        return False

    if re.match('r[4-9]|r1[0-5]|sp|ip|lr|pc',ops[1]):
        return False

    # shift by non-allowed reg
    if re.search('(?:lsr|lsl|asr|ror) (?:r[4-9]|r1[0-5]|sp|ip|lr|pc)',ops[1]):
        return False

    if len(ops) > 2:
        if re.match('r[4-9]|r1[0-5]|sp|ip|lr|pc',ops[2]):
            return False
        if re.search('(?:lsr|lsl|asr|ror) (?:r[4-9]|r1[0-5]|sp|ip|lr|pc)',ops[2]):
            return False

    # in armv5 ghidra treats register offset ldr/str as a signle operand, like [r1,r2,lsl #0x2]
    if (mne[0:3] == 'ldr' or mne[0:3] == 'str') and re.search(',(r[4-9]|r1[0-5]|sp|ip|lr|pc)',ops[1]):
        return False

    # special case to bail early on common bad instructions
    # mov r0,r0 is all zeros in thumb
    if len(ops) == 2 and mne == 'mov' and ops[0] == 'r0' and ops[1] == 'r0':
        return False

    # all zeros in arm
    if len(ops) == 3 and mne == 'andeq' and ops[0] == 'r0' and ops[1] == 'r0' and ops[2] == 'r0':
        return False

    # could be valid but rare and don't want to hit ldr/str cases below
    if mne[0:4] == 'ldrd':
        return False

    if mne[0:4] == 'strd':
        return False

    # ldr, ldrh etc into r0-r3, from r0-r3, or PC
    # ghidra formats ldr rn, [pc...] as ldr rn, [0xblah]
    # on others, [rn,#disp], even if disp is 0x0
    if mne[0:3] == 'ldr' and re.match('\[(?:0x|r[0-3],)',ops[1]):
        return True

    # ghidra treats register offset as 3 reg args and constant,
    # out of range regs would be caught above
    if mne[0:3] == 'ldr' and len(ops) == 4:
        return True

    # str uncommon before push, but legal and common funcs without push
    if mne[0:3] == 'str' and re.match('\[r[0-3],',ops[1]):
        return True

    # ghidra treats register offset as 3 reg args and constant,
    # out of range regs would be caught above
    if mne[0:3] == 'str' and len(ops) == 4:
        return True

    # ghidra uses adr, adr.w mnemonics
    if mne[0:3] == 'adr':
        return True

    # the following all rely on the initial address checks to ensure
    # up to 3 reg or shifter operands are acceptable
    # grouped for readability only

    # moves
    if re.match('mov|cpy|mvn',mne):
        return True

    # arithmetic
    if re.match('add|rsb|sub',mne):
        return True

    # bitwise
    if re.match('and|asr|bic|bfi|eor|lsl|lsr|orr|ror|ubfx',mne):
        return True

    # comparisons
    if re.match('cmn|cmp|teq|tst',mne):
        return True

    return False


def is_push_lr(insn):
    mne = insn.getMnemonicString()
    ops = get_insn_ops_text(insn)
    # NOTE includes conditionals
    if re.match('push',mne) and re.search('lr',ops[0]):
        return True
    if ((re.match('stmdb',mne) and ops[0][0:3] == 'sp!' and re.search('lr',ops[0]))
        or (re.match('str',mne) and ops[0] == 'lr' and ops[1] == '[sp,#-0x4]!')):
        return True
    return False

def is_pop_lr(insn):
    mne = insn.getMnemonicString()
    ops = get_insn_ops_text(insn)
    # NOTE includes conditionals
    if re.match('pop',mne) and re.search('lr',ops[0]):
        return True
    if ((re.match('ldmia',mne) and ops[0][0:3] == 'sp!' and re.search('lr',ops[0]))
        or (re.match('ldr',mne) and ops[0] == 'lr' and ops[1] == '[sp],#0x4')):
        return True
    return False


def is_likely_func_start(addr,tmode = None, require_push = False, disassemble = True):
    """
    check if code at addr looks like a function start, or trivial function.
    tmode taken from program if not set
    if disassemble is false, assumes program is already disassembled, tmode ignored
    """
    if disassemble:
        if tmode is None:
            tmode = get_tmode_reg_at(addr)

        insn = get_pinsn_at(addr,tmode)
    else:
        insn = getInstructionAt(addr)

    if not insn:
        return False

    # check for a few common instructions before push
    for i in range(0,3):
        if is_likely_before_push_insn(insn):
            addr = addr.add(insn.length)
            if disassemble:
                insn = get_pinsn_at(addr,tmode)
            else:
                insn = getInstructionAt(addr)
            if not insn:
                return False
        else:
            break

    if is_push_lr(insn):
        return True

    if require_push:
        return False

    mne = insn.getMnemonicString()
    ops = get_insn_ops_text(insn)

    # not a push, check immediate return
    if (mne == 'bx' and ops[0] == 'lr') or (mne == 'mov' and ops[0] == 'pc' and ops[1] == 'lr'):
        return True

    return False

# similar to above, but requires instructions be disassembled because
# needs to go backwards
def is_likely_tail_call(addr, allow_conditional = True, allow_start_no_pop = False):
    """
    check if code at and preceding addr looks like a jump after a pop
    code must already be disassembled
    """
    insn = getInstructionAt(addr)
    if not insn:
        return False

    mne = insn.getMnemonicString()

    # TODO could allow ldr pc etc, but firmware generally uses b
    if mne != 'b' and mne != 'b.w':
        if not allow_conditional:
            return False

    if not re.match('b(eq|ne|cs|cc|mi|pl|vs|vc|hi|ls|ge|lt|gt|le)?',mne):
        return False


    # branch is at function start
    # probably a veneer, which will be handled elsewhere
    if getFunctionAt(addr):
        return False

    # check for a few common instructions between branch and pop
    for i in range(0,3):
        insn = insn.getPrevious()
        if not insn:
            return False
        if is_likely_after_pop_insn(insn):
            # don't backtrack past the start of a function
            if getFunctionAt(insn.getAddress()):
                if allow_start_no_pop:
                    return True
                else:
                    return False

        else:
            break

    if is_pop_lr(insn):
        return True

    return False


# get the int at addr and return it as an addr
def get_pointer_at(addr):
    # convert to unsigned
    return toAddr(getInt(addr) & 0xffffffff)

# return pointer at addr, if value is inside a valid memory block and not null
# otherwise None
def get_valid_pointer_at(addr):
    paddr = get_pointer_at(addr)
    if getCurrentProgram().getMemory().contains(paddr) and addr.getOffset != 0:
        return paddr

# get null terminated string starting at addr as python string
# return None if length exceeds maxlen or invalid address encountered
# empty strings are returned
def get_cstring_at(addr, maxlen = 256):
    chrs = []
    l = 0
    while l < maxlen:
        if not getCurrentProgram().getMemory().contains(addr):
            break
        try:
            b = getByte(addr)
            if b == 0:
                return ''.join(chrs)

            # chr expects unsigned
            chrs.append(chr(b & 0xff))
            l += 1
            addr = addr.add(1)

        except ghidra.program.model.mem.MemoryAccessException:
            break

# iterator over references from function body
# loosely based on FunctionDB.java getReferencesFromBody
def get_refs_from_addrset(addrs):
    refman = getCurrentProgram().getReferenceManager()
    for addr in addrs.getAddresses(True):
        refs = refman.getReferencesFrom(addr)
        for r in refs:
            yield r

