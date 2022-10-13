# points to the start of the memory pool used by the firmware
MEMISOSTART=0x35bb28
MAXRAMADDR=0x1fffffff
ifdef OPT_CHDK_IN_ARAM
MEMIOSTART=$(ARAM_HEAP_START)
endif
