
# points to the start of the memory pool used by the firmware
MEMISOSTART=0x39124C

# values for ARAM, from sig finder
ARAM_HEAP_START=0x006ce000
ARAM_HEAP_SIZE=0x00022000

# Force ARAM on, but don't load CHDK in ARAM, because size is marginal for core
override OPT_ARAM_MALLOC=1
override OPT_CHDK_IN_ARAM=
