override OPT_GEN_STUBS=
override FORCE_GEN_STUBS= 
# points to the start of the memory pool used by the firmware
MEMISOSTART=0x3a8bb0
ifdef OPT_CHDK_IN_ARAM
MEMIOSTART=$(ARAM_HEAP_START)
endif
