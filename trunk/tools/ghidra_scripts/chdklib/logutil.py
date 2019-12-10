# tiny hokey module to share verbosity between modules
# printf based wrappers since print is annoying to wrap. Goes to "script console"
# NOTE ghidra Address must be formatted as string, numeric values as %x etc

# Ghidra needs this in a module to access stuff like printf
from __main__ import *
verbosity = 0
def warnf(fmt,*args):
    printf("WARNING: "+fmt,*args)

def infomsgf(level,fmt,*args):
    if verbosity >= level:
        printf(fmt,*args)

