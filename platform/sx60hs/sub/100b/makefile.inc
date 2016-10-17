# points to the start of the memory pool used by the firmware
MAXRAMADDR=0x1fffffff
MEMISOSTART=0x3a8bb0
ifdef OPT_CHDK_IN_ARAM
MEMIOSTART=$(ARAM_HEAP_START)
endif
