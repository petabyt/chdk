# other settings in platform level makefile.inc

# Force ARAM on for sd970, and load CHDK in ARAM
override OPT_ARAM_MALLOC=1
override OPT_CHDK_IN_ARAM=1

# checked for sd970
ifdef OPT_CHDK_IN_ARAM
MEMISOSTART=$(ARAM_HEAP_START)
else
MEMISOSTART=0x001487c4
endif
