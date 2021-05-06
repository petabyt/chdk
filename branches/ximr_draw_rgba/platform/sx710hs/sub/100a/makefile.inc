# see platform/sx710hs/makefile.inc for other defines
# points to the start of the memory pool used by the firmware
ifdef OPT_CHDK_IN_ARAM
MEMISOSTART=$(ARAM_HEAP_START)
else
# from sigfinder
MEMISOSTART=0x3c3998
endif
