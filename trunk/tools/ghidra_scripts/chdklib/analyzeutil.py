# Ghidra needs this in a module to access standard stuff
from __main__ import *

from chdklib.logutil import infomsg, warn

from java.math import BigInteger 
import ghidra.program.model.mem.MemoryBufferImpl as MemoryBufferImpl
# or ProgramProcessorContext ?
from ghidra.program.model.lang import ProcessorContextImpl
import ghidra.app.util.PseudoInstruction as PseudoInstruction

# rougly based on Ghidra/Features/Base/ghidra_scripts/AssemblyThrasherDevScript.java
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

def is_likely_func_start(addr,tmode = None):
    """check if code at addr looks like a function start, or trivial function. tmode taken from program if not set"""
    if tmode is None:
        tmode = get_tmode_reg_at(addr)

    pi = get_pinsn_at(addr,tmode)
    if not pi:
        return False

    # check for a few common instructions before push
    # mov or ldr r0-r3
    # sub sp,sp ... (old firmware)
    # add / sub r0-r3,#const
    # using string operands is probably fragile
    for i in range(0,2):
        op = pi.getMnemonicString()
        a0 = pi.getDefaultOperandRepresentation(0)
        a1 = pi.getDefaultOperandRepresentation(1)
        a2 = pi.getDefaultOperandRepresentation(2)
        if ((re.match('mov|ldr',op) and re.match('r[0-3]',a0))
            or (re.match('add|sub',op) and re.match('r[0-3]',a0) and re.match('r[0-3]',a1) and re.match('#',a2))
            or (re.match('add|sub',op) and re.match('r[0-3]',a0) and re.match('#',a1))
            or (op == 'sub' and a0 == 'sp')):
            addr = addr.add(pi.length)
            pi = get_pinsn_at(addr,tmode)
            if not pi:
                return False
        else:
            break

    if tmode:
        if op == 'push':
            return True
    else:
        if ((op == 'stmdb' and a0[0:3] == 'sp!') or (op == 'str' and  a0 == 'lr' and a1 == '[sp,#-0x4]!')):
            return True

    # not a push, check immediate return
    if (op == 'bx' and a0 == 'lr') or (op == 'mov' and a0 == 'pc' and a1 == 'lr'):
        return True

    # TODO veneers, trivial wrappers like foo(x) => bar(1,x)

    return False

