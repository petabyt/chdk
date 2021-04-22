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
    return [ insn.getDefaultOperandRepresentation(j) for j in range(0,insn.getNumOperands()) ]

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

class InsnDescriber:
    # to match instructions and split from conditionals etc
    # not comprehensive, not all captures a valid for all instructions
    # note contrary to ARM UAL, ghidra puts S after condition like andeqs
    match_mne_dataproc = re.compile(
        "(add|adc|mla|mls|mul|rsb|sub|sbc|sdiv|udiv"
        "|and|asr|bic|bfi|eor|lsl|lsr|orn|orr|ror|rrx|rsc|sxtb|sxth|ubfx|uxth)"
        "(eq|ne|cs|cc|mi|pl|vs|vc|hi|ls|ge|lt|gt|le)?(s)?(\.w)?"
    )
    match_mne_mov = re.compile(
        "(adr|movt|movw|mov|cpy|mvn)"
        "(eq|ne|cs|cc|mi|pl|vs|vc|hi|ls|ge|lt|gt|le)?(s)?(\.w)?"
    )
    match_mne_cmp = re.compile(
        "(cmn|cmp|teq|tst)"
        "(eq|ne|cs|cc|mi|pl|vs|vc|hi|ls|ge|lt|gt|le)?(\.w)?"
    )
    match_mne_b = re.compile(
        "(bx|blx|bl|b)"
        "(eq|ne|cs|cc|mi|pl|vs|vc|hi|ls|ge|lt|gt|le)?(\.w)?"
    )
    match_mne_cond_misc = re.compile(
        "(mrs|msr)"
        "(eq|ne|cs|cc|mi|pl|vs|vc|hi|ls|ge|lt|gt|le)?"
    )
    match_mne_ldst = re.compile(
        "(ldr|str)([bhd])?(eq|ne|cs|cc|mi|pl|vs|vc|hi|ls|ge|lt|gt|le)?(\.w)?"
    )
    match_mne_pushpop = re.compile(
        "(push|pop)(eq|ne|cs|cc|mi|pl|vs|vc|hi|ls|ge|lt|gt|le)?(\.w)?"
    )
    match_mne_ldmstm = re.compile(
        "(ldm|stm)(db|ia|fd|da|fa|ea|ed)(eq|ne|cs|cc|mi|pl|vs|vc|hi|ls|ge|lt|gt|le)?(\.w)?"
    )
    match_mne_nosfx_misc = re.compile(
        "(cbz|cbnz)"
    )

    likely_before_push_mne_base={
        "add", "adc", "mla", "mls", "mul", "rsb", "sub", "sbc", "sdiv", "udiv",
        "cmn", "cmp", "teq", "tst",
        "and", "asr", "bic", "bfi", "eor", "lsl", "lsr", "orn", "orr", "ror", "rrx", "rsc", "sxtb", "sxth", "ubfx", "uxth",
        "adr", "movt", "movw", "mov", "cpy", "mvn",
        "ldr", "str"
    }
    likely_after_pop_mne_base={
        "add", "adc", "mla", "mls", "mul", "rsb", "sub", "sbc", "sdiv", "udiv",
        "cmn", "cmp", "teq", "tst",
        "and", "asr", "bic", "bfi", "eor", "lsl", "lsr", "orn", "orr", "ror", "rrx", "rsc", "sxtb", "sxth", "ubfx", "uxth",
        "adr", "movt", "movw", "mov", "cpy", "mvn",
        "ldr", "str"
    }

    # match regs allowed to be freely modified in a function
    #match_no_preserve_regs = re.compile(
    #    "(?:^|[^a-z])(?:r[0-3]|r12)(?:[^a-z]|$)"
    #)

    # match regs not allowed to be freely modified in a function
    # sp, pc is questionable, but probably want to handle explicitly
    # r12 not included
    match_preserve_regs = re.compile(
        "(?:^|[^a-z])(?:r[4-9]|r1[01]|sp|lr|pc)(?:[^a-z]|$)"
    )

    def __init__(self,insn, tmode):
        self.insn = insn
        self.tmode = tmode
        self.mnemonic = insn.getMnemonicString()
        self.n_ops = insn.getNumOperands()
        self.ops = [ insn.getDefaultOperandRepresentation(j) for j in range(0,self.n_ops) ]
        self.cache = {}

    def parse_mne(self):
        m = self.match_mne_dataproc.match(self.mnemonic)
        if m:
            self.cache['mne_group'] = 'dataproc'
            self.cache['mne'] = m.group(1)
            self.cache['mne_base'] = m.group(1)
            self.cache['cc'] = m.group(2)
            self.cache['s'] = m.group(3)
            self.cache['q'] = m.group(4)
            return

        m = self.match_mne_mov.match(self.mnemonic)
        if m:
            self.cache['mne_group'] = 'mov'
            self.cache['mne'] = m.group(1)
            self.cache['mne_base'] = m.group(1)
            self.cache['cc'] = m.group(2)
            self.cache['s'] = m.group(3)
            self.cache['q'] = m.group(4)
            return

        # below do not have s suffix
        self.cache['s'] = None

        m = self.match_mne_cmp.match(self.mnemonic)
        if m:
            self.cache['mne_group'] = 'cmp'
            self.cache['mne'] = m.group(1)
            self.cache['mne_base'] = m.group(1)
            self.cache['cc'] = m.group(2)
            self.cache['q'] = m.group(3)
            return

        m = self.match_mne_b.match(self.mnemonic)
        if m:
            self.cache['mne_group'] = 'b'
            self.cache['mne'] = m.group(1)
            self.cache['mne_base'] = m.group(1)
            self.cache['cc'] = m.group(2)
            self.cache['q'] = m.group(3)
            return

        m = self.match_mne_cond_misc.match(self.mnemonic)
        if m:
            self.cache['mne_group'] = 'condmisc'
            self.cache['mne'] = m.group(1)
            self.cache['mne_base'] = m.group(1)
            self.cache['cc'] = m.group(2)
            self.cache['q'] = None
            return

        m = self.match_mne_ldst.match(self.mnemonic)
        if m:
            self.cache['mne_group'] = 'ldst'
            if m.group(2):
                self.cache['mne'] = m.group(1) + m.group(2) # bhd suffix
            else:
                self.cache['mne'] = m.group(1)
            self.cache['mne_base'] = m.group(1)
            self.cache['cc'] = m.group(3)
            self.cache['q'] = m.group(4)
            return

        m = self.match_mne_pushpop.match(self.mnemonic)
        if m:
            self.cache['mne_group'] = 'pushpop'
            self.cache['mne'] = m.group(1)
            self.cache['mne_base'] = m.group(1)
            self.cache['cc'] = m.group(2)
            self.cache['q'] = m.group(3)
            return

        m = self.match_mne_ldmstm.match(self.mnemonic)
        if m:
            self.cache['mne_group'] = 'ldmstm'
            self.cache['mne'] = m.group(1) + m.group(2) #ldm + fd etc
            self.cache['mne_base'] = m.group(1) # ldm/stm alone
            self.cache['cc'] = m.group(3)
            self.cache['q'] = m.group(4)
            return

        self.cache['mne'] = None
        self.cache['mne_group'] = None
        self.cache['mne_base'] = None
        self.cache['cc'] = None
        self.cache['q'] = None

    def get_mne(self):
        if not 'mne' in self.cache:
            self.parse_mne()
        return self.cache['mne']

    def get_mne_base(self):
        if not 'mne_base' in self.cache:
            self.parse_mne()
        return self.cache['mne_base']

    def get_mne_group(self):
        if not 'mne_group' in self.cache:
            self.parse_mne()
        return self.cache['mne_group']

    def get_cc(self):
        if not 'cc' in self.cache:
            self.parse_mne()
        return self.cache['cc']

    def get_s(self):
        if not 's' in self.cache:
            self.parse_mne()
        return self.cache['s']

    def sets_flags(self):
        group = self.get_mne_group()
        if group == 'cmp':
            return True
        if self.get_s() == 's':
            return True
        return False

    def uses_preserve_regs(self):
        if not 'uses_preserve_regs' in self.cache:
            for o in self.ops:
                if self.match_preserve_regs.search(o):
                    self.cache['uses_preserve_regs'] = True
                    return True
            self.cache['uses_preserve_regs'] = False
        return self.cache['uses_preserve_regs']

    def is_likely_bogus_insn(self):
        mne = self.get_mne()
        # all zero instructions
        if self.tmode:
            if mne == 'mov' and self.n_ops == 2 and self.ops[0] == 'r0' and self.ops[1] == 'r0':
                return True
        else:
            if mne == 'and' and self.get_cc() == 'eq' and self.n_ops == 3 and self.ops[0] == 'r0' and self.ops[1] == 'r0' and self.ops[2] == 'r0':
                return True
        # various things that don't make sense with PC
        if self.n_ops > 0 and self.ops[0] == 'pc':
            group = self.get_mne_group()
            # most arimetic / bitwise ops into PC
            if group == 'dataproc' and self.mne != 'add':
                return True

            # load / store other than single word of PC
            if group == 'ldst':
                if mne == 'ldrb' or mne == 'lrdh' or mne == 'ldrd':
                    return True
                if mne == 'strb' or mne == 'strh' or mne == 'strd':
                    return True

            if group == 'cmp':
                return True

            if mne == 'movt':
                return True

        return False

    def is_pop_lr(self):
        if 'pop_lr' in self.cache:
            return self.cache['pop_lr']

        mne = self.get_mne()
        if mne == 'pop' and re.search('lr',self.ops[0]):
            r = True
        elif mne == 'ldmia' and self.ops[0][0:3] == 'sp!' and re.search('lr',self.ops[0]):
            r = True
        elif mne == 'ldr' and self.ops[0] == 'lr' and self.ops[1] == '[sp],#0x4':
            r = True
        else:
            r = False
        self.cache['pop_lr'] = r
        return r

    def is_push_lr(self):
        if 'push_lr' in self.cache:
            return self.cache['push_lr']

        mne = self.get_mne()
        if mne == 'push' and re.search('lr',self.ops[0]):
            r = True
        elif mne == 'stmdb' and self.ops[0][0:3] == 'sp!' and re.search('lr',self.ops[0]):
            r = True
        elif mne == 'str' and self.ops[0] == 'lr' and self.ops[1] == '[sp,#-0x4]!':
            r = True
        else:
            r = False
        self.cache['push_lr'] = r
        return r

    def is_likely_before_push(self):
        if 'likely_before_push' in self.cache:
            return self.cache['likely_before_push']

        mne_base = self.get_mne_base()
        if not mne_base in self.likely_before_push_mne_base:
            r = False
        else:
            mne = self.get_mne()

            # special case for sub sp,#const / sub sp,sp,#const, before checks below
            if mne == 'sub' and self.ops[0] == 'sp' and re.match('sp|#',self.ops[1]):
                r = True
            elif self.uses_preserve_regs():
                r = False
            elif self.is_likely_bogus_insn():
                r = False
            else:
                r = True

        self.cache['likely_before_push'] = r
        return r

    def is_likely_after_pop(self):
        if 'likely_after_pop' in self.cache:
            return self.cache['likely_after_pop']

        mne_base = self.get_mne_base()
        if not mne_base in self.likely_after_pop_mne_base:
            r = False
        else:
            mne = self.get_mne()

            # special case for sub sp,#const / sub sp,sp,#const, before checks below
            if self.uses_preserve_regs():
                r = False
            elif self.is_likely_bogus_insn():
                r = False
            else:
                r = True

        self.cache['likely_after_pop'] = r
        return r

    # is return, excluding pops
    def is_ret(self):
        mne = self.get_mne()
        if (mne == 'bx' and self.ops[0] == 'lr') or (mne == 'mov' and self.ops[0] == 'pc' and self.ops[1] == 'lr'):
            return True

    # is a branch to a constant value, including ldr pc, cb[n]z, excluding switches
    def is_imm_branch(self):
        mne = self.get_mne()

        if mne == 'b':
            return True

        if mne == 'bx' and self.ops[0][0:2] == '0x':
            return True

        if mne == 'ldr' and self.ops[0] == 'pc' and self.ops[1][0:2] == '0x':
            return True

        if self.tmode and (mne == 'cbz' or mne == 'cbnz'):
            return True

        return False


# get InsnDescriber for instruction, address or convertable to address, or None
# if disassemble is true, get instruction from program bytes,
# using arm/thumb state from dis_tmode if set
def get_insn_desc(spec, disassemble=False, dis_tmode=None):
    insn = None
    if spec is None:
        return None
    elif isinstance(spec,ghidra.program.database.code.InstructionDB):
        insn = spec
        tmode = get_tmode_reg_at(insn.getAddress())
    elif isinstance(spec,ghidra.app.util.PseudoInstruction):
        insn = spec
        # for pseudoinstructions, we can't get tmode from insn (or I don't know how without original context)
        if dis_tmode is None:
            tmode = get_tmode_reg_at(addr)
        else:
            tmode = dis_tmode

    elif isinstance(spec,ghidra.program.model.address.GenericAddress):
        addr = spec
    else:
        t = type(spec)
        if t == str or t == int or t == long:
            addr = toAddr(spec)
        else:
            raise ValueError('expected instruction, address, string, int or long')

    if insn is None:
        if disassemble:
            if dis_tmode is None:
                tmode = get_tmode_reg_at(addr)
            else:
                tmode = dis_tmode

            insn = get_pinsn_at(addr,tmode)
        else:
            tmode = get_tmode_reg_at(addr)
            insn = getInstructionAt(addr)

        if insn is None:
            return None

    return InsnDescriber(insn,tmode)

def is_likely_func_start(addr,tmode = None, require_push = False, disassemble = True):
    """
    check if code at addr looks like a function start, or trivial function.
    tmode taken from program if not set
    if disassemble is false, assumes program is already disassembled, tmode ignored
    """
    idesc = get_insn_desc(addr, disassemble = disassemble, dis_tmode = tmode)
    if not idesc:
        return False
    # first instruction of func shouldn't be conditional
    if idesc.get_cc():
        return False
    # check for a few common instructions before push
    for i in range(0,3):
        if idesc.is_likely_before_push():
            addr = addr.add(idesc.insn.length)
            idesc = get_insn_desc(addr, disassemble = disassemble, dis_tmode = tmode)
            if not idesc:
                return False
        else:
            break

    if idesc.is_push_lr():
        return True

    if require_push:
        return False

    # not a push, check immediate return
    if idesc.is_ret():
        return True

    return False

# similar to above, but requires instructions be disassembled because
# needs to go backwards
def is_likely_tail_call(addr, allow_conditional = True, allow_start_no_pop = False):
    """
    check if code at and preceding addr looks like a jump after a pop
    code must already be disassembled
    """
    # branch is at function start
    # probably a veneer, which should be handled separately
    if getFunctionAt(addr):
        return False

    idesc = get_insn_desc(addr)
    if not idesc:
        return False

    if not idesc.is_imm_branch():
        return False

    mne = idesc.get_mne()
    # unlikely for tail calls
    if idesc.tmode and (mne == 'cbz' or mne == 'cbnz'):
        return False

    br_cc = idesc.get_cc()

    if br_cc and not allow_conditional:
        return False

    # check for a few common instructions between branch and pop
    for i in range(0,3):
        idesc = get_insn_desc(idesc.insn.getPrevious())
        if not idesc:
            return False
        if idesc.is_likely_after_pop():
            # Instruction right before tail call shouldn't set flags, unless branch is conditional
            if i == 0 and not br_cc and idesc.sets_flags():
                return False
            # don't backtrack past the start of a function
            if getFunctionAt(idesc.insn.getAddress()):
                if allow_start_no_pop:
                    return True
                else:
                    return False

        else:
            break

    if idesc.is_pop_lr():
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

# iterator over references from function body or other address set
# loosely based on FunctionDB.java getReferencesFromBody
def get_refs_from_addrset(addrs):
    refman = getCurrentProgram().getReferenceManager()
    for addr in addrs.getAddresses(True):
        refs = refman.getReferencesFrom(addr)
        for r in refs:
            yield r

