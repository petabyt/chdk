# List calls to a function with any of specified constant args
#
# Jump to location by double clicking the address
#
# NOTE: May not pick up conditional calls

#@category CHDK
#@author reyalp
#@menupath Tools.CHDK.List Calls with Args

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


import os
import re

from chdklib.logutil import infomsg, warn

from chdklib.calldescriber import CallDescriber

from ghidra.program.model.symbol import SymbolType

def list_calls_main():

    funcstr = str(askString("Function","Name or address"))
    s = getSymbol(funcstr,None)
    if s:
        if s.getSymbolType() != SymbolType.FUNCTION:
            warn('symbol %s is not a function, exiting'%(s))
            return
        addr = s.getAddress()
    else:
        addr = toAddr(funcstr)
        if not addr:
            warn('%s could not be converted to address, exiting'%(funcstr))
            return

    func = getFunctionAt(addr)
    if not func:
        warn('no function at %s, exiting'%(addr))
        return

    argstr = str(askString("Arguments 0-3","numbers or - to ignore")).upper()

    n = 0
    matches=[]
    regs={}
    msg = []
    for s in re.split('[ ,]+',argstr):
        if n > 3:
            warn('too many arguments, exiting'%(addr))
            return

        if s == '-':
            match_val = None
        elif re.match('0x[0-9a-f]+$',s,re.I):
            match_val = int(s,16)
        elif re.match('[0-9]+$',s):
            match_val = int(s,10)
        else:
            warn('did not understand %s, exiting'%(s))
            return

        regs['r%d'%(n)] = {
            'type':'int'
        }
        matches.append(match_val)
        if match_val is not None:
            msg.append('0x%x'%(match_val))
        else:
            msg.append('-')

        n += 1


    if len(regs) == 0:
        warn('no arguments, exiting'%(s))

    infomsg(0,"Searching for %s(%s)\n"%(func.getName(),', '.join(msg)))

    funcdesc={
        func.getName():regs
    }

    cd = CallDescriber(funcdesc)

    for desc in cd.describe_all_calls():
        match = False
        res = []
        for i,v in enumerate(matches):
            if v is None:
                res.append('-')
                continue

            if v == desc.args[i].val:
                res.append('0x%x'%(v))
                match = True

        if match:
            infomsg(0,'%s %s(%s)\n'%(desc.addr,desc.fname,', '.join(res)))

list_calls_main()
