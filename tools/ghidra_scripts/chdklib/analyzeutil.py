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
