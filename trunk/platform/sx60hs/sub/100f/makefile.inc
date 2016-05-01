#override OPT_GEN_STUBS=
#override FORCE_GEN_STUBS=

PLATFORMID=12954

PLATFORMOS=dryos

# points to the start of the memory pool used by the firmware
MEMISOSTART=0x3a8bb0
ifdef OPT_CHDK_IN_ARAM
MEMIOSTART=$(ARAM_HEAP_START)
endif
# start of firmware
ROMBASEADDR=0xFC000000

MAXRAMADDR = 0x0fffffff

# Found @
NEED_ENCODED_DISKBOOT=14

# Found @
KEYSYS=d4d

PLATFORMOSVER=55

# mandatory for DIGIC 6
MEMBASEADDR=0x8000
