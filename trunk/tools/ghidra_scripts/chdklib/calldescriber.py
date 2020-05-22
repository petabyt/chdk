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

# Ghidra needs this in a module to access standard stuff
from __main__ import *

# to set verbosity
import chdklib.logutil
from chdklib.logutil import infomsg, warn
from chdklib.defines_loader import PropsetData

from chdklib.regsanalyzer import RegsAnalyzer

funcdesc = {
    'GetPropertyCase':{
        'r0':{
            'type':'PROPCASE_ID',
        },
        'r1':{
            'type':'OUT_PTR',
        },
        'r2':{
            'type':'INT',
        },
    },
    'SetPropertyCase':{
        'r0':{
            'type':'PROPCASE_ID',
        },
        'r1':{
            'type':'IN_PTR',
        },
        'r2':{
            'type':'INT',
        },
    },
}

class CallDescriber:
    def __init__(self,filename):
        self.pd = PropsetData(filename)
        self.ra = RegsAnalyzer(currentProgram, monitor)

    def describe_call(self,addr,fname):
        # TODO could pick up func name from Ghidra by getting target of b/bl at addr
        fdesc = funcdesc.get(fname)
        if not fdesc:
            raise ValueError('unknown func %s'%(fname))
            
        reg_ids = sorted(list(fdesc))
        regs = self.ra.getRegs(reg_ids,addr)
        if not regs:
            # worth printing since user can potentially fix (may want to supress though)
            infomsg(0,'%s %s Call not in function?\n'%(addr,fname))
            return

        res = {}

        results = []
        for r in reg_ids:
            arg_type = fdesc[r]['type']
            reg = regs[r]
            res = {
                'type':arg_type,
            }
            results.append(res)

            if reg is None:
                res['desc'] = 'unk'
                res['val'] = None
                if arg_type == 'PROPCASE_ID':
                    res['prop_name'] = ''
                continue

            res['val'] = reg.getValue()

            if arg_type == 'PROPCASE_ID':
                res['prop_name'] = ''
                if reg.isRegisterRelativeValue():
                    infomsg(2,'%s reg rel PROPCASE_ID %s for %s\n'%(addr,r,fname))
                    res['desc'] = 'unk'
                else:
                    prop_id = reg.getValue()
                    if prop_id in self.pd.by_id:
                        res['prop_name'] = self.pd.by_id.get(prop_id,str(prop_id))
                        res['desc'] = '%s (%d)'%(res['prop_name'],prop_id)
                    else:
                        res['desc'] = str(prop_id)
            elif arg_type == 'INT':
                if reg.isRegisterRelativeValue():
                    infomsg(2,'%s reg rel INT %s for %s\n'%(addr,r,fname))
                    res['desc'] = 'unk'
                else:
                    res['desc'] = str(reg.getValue())
            # TODO strings and things
            else:
                if reg.isRegisterRelativeValue():
                    res['desc'] = str(reg.getRelativeRegister()) + ' %#x'%(reg.getValue())
                else:
                    res['desc'] = '%#x'%(reg.getValue())

        return results
