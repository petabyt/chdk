# for non-ghidra
from __future__ import print_function

# tiny hokey module to share verbosity between modules
# printf used to send to main ghidra console, no EOL
import sys

# allow use from non-ghidra
if 'ghidra.python' in sys.modules:
    # Ghidra needs this in a module to access stuff like printf
    from __main__ import *
    is_ghidra = True
else:
    is_ghidra = False

verbosity = 0
if is_ghidra:
    def warn(msg):
        printf("WARNING: %s\n",msg)

    def infomsg(level,msg):
        if verbosity >= level:
            printf("%s",msg)
else:
    def warn(msg):
        print("WARNING: "+str(msg))

    def infomsg(level,msg):
        if verbosity >= level:
            print(msg,end='')

