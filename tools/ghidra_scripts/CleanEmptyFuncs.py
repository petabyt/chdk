# Attempt to recreate zero length functions, or remove if not in valide
# part of program. Can be used when the Comment*Calls and List*Calls scripts
# report not in a function despite a function name appearing at the expected
# entry point

#@category CHDK
#@author reyalp
#@menupath Tools.CHDK.Clean Empty Funcs

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

from chdklib.logutil import infomsg, warn

g_options = {
    'pretend':False,
}

def clean_empty_func(f):
    f_entry = f.getEntryPoint()
    infomsg(0,'empty func %s\n'%(f_entry))
    if not g_options['pretend']:
        removeFunction(f)

    # if the function is inside data or non-code memory block
    # don't try to recreate
    if getDataContaining(f_entry):
        infomsg(0,'entry inside data %s\n'%(f_entry))
        return True

    # if no instruction, don't re-create
    if not getInstructionAt(f_entry):
        infomsg(0,'entry not code %s\n'%(f_entry))
        return True

    mb = getMemoryBlock(f_entry)
    if not mb:
        infomsg(0,'entry not in memblock!? %s\n'%(f_entry))
        return True

    if not mb.isExecute():
        infomsg(0,'entry in noexec block %s %s\n'%(f_entry,mb.getName()))
        return True

    if not mb.isInitialized() and not mb.isMapped():
        infomsg(0,'entry in uninit block %s %s\n'%(f_entry,mb.getName()))
        return True

    # infomsg(0,'create %s'%(f_entry))
    if g_options['pretend']:
        return True

    f_new = createFunction(f_entry,None)
    if f_new:
        b = f_new.getBody()
        if b.getMinAddress() == b.getMaxAddress():
            infomsg(0,'still zero size %s\n'%(f_entry))
            removeFunction(f)
            return False

        return True

    else:
        infomsg(0,'create failed %s\n'%(f_entry))
        return False


def clean_empty_funcs_main():
    found_count = 0
    clean_count = 0
    fm=currentProgram.getFunctionManager()
    monitor.initialize(fm.getFunctionCount())
    for f in fm.getFunctions(True):
        b = f.getBody()
        if b.getMinAddress() == b.getMaxAddress():
            found_count += 1
            if clean_empty_func(f):
                clean_count += 1

        monitor.incrementProgress(1)
        monitor.checkCanceled()

    infomsg(0,"found %d cleaned %d\n"%(found_count, clean_count))

clean_empty_funcs_main()
