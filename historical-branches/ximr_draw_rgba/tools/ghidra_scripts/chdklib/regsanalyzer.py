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
# 
from __main__ import *

import ghidra.program.util.SymbolicPropogator as SymbolicPropogator
import ghidra.program.util.SymbolicPropogator.Value
import ghidra.app.plugin.core.analysis.ConstantPropagationContextEvaluator as ConstantPropagationContextEvaluator

from chdklib.logutil import infomsg, warn

class RegsAnalyzer:
    """Analyze register values at a given address"""
    def __init__(self,currentProgram,monitor):
        self.currentProgram = currentProgram
        self.monitor = monitor
        self.symprop = SymbolicPropogator(currentProgram)
        self.last_fn = None

    # loosely based on code from https://github.com/0xb0bb/pwndra/blob/master/scripts/lib/Syscalls.py
    def getRegs(self,regs,addr):
        fn = self.currentProgram.getListing().getFunctionContaining(addr)
        if not fn:
            return
        # don't reflow if we already did this function
        if fn != self.last_fn:
            cpce = ConstantPropagationContextEvaluator(True)
            self.symprop.flowConstants(fn.getEntryPoint(), fn.getBody(), cpce, False, self.monitor)
            self.last_fn = fn

        res = {}
        for rname in regs:
            res[rname] = self.symprop.getRegisterValue(addr,self.currentProgram.getRegister(rname))

        return res

    def describe(self,regvals):
        for rname in sorted(list(regvals)):
            reg = regvals[rname]
            if reg is None:
                rval = "Unknown"
            elif reg.isRegisterRelativeValue():
                rval = str(reg.getRelativeRegister()) + ' %#x'%(reg.getValue())
            else:
                rval = '%#x'%(reg.getValue())

            infomsg(-1,'%s %s\n'%(rname,rval))


