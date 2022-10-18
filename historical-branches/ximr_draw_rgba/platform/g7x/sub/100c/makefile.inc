# see platform/g7x/makefile.inc for other defines
# points to the start of the memory pool used by the firmware
# from fc064300
ifdef OPT_CHDK_IN_ARAM
MEMISOSTART=$(ARAM_HEAP_START)
else
MEMISOSTART=0x36a354
endif
