#PLATFORMID=0x31E4
PLATFORMID=12772

PLATFORMOS=dryos

# Force ARAM on for SX20, and load CHDK in ARAM
override OPT_ARAM_MALLOC=1
override OPT_CHDK_IN_ARAM=1

ROMBASEADDR=0xFF810000
MAXRAMADDR=0x03FFFFFF

# Set up size variables for AgentRAM
ARAM_HEAP_START=0x34e000
ARAM_HEAP_SIZE=0x32000

# Set up size variables for EXMEM
EXMEM_HEAP_SKIP=0x2F7600	#(0x48000000-0x47D08A00) from sub_FF890270 = size of video buffers in EXMEM area
EXMEM_BUFFER_SIZE=0x400000	# Amount of EXMEM memory to allocate for CHDK = 4MB

ifdef OPT_CHDK_IN_ARAM
MEMISOSTART=$(ARAM_HEAP_START)
else
ifdef OPT_CHDK_IN_EXMEM
MEMISOSTART=0x39089e0		# MAXRAMADDR+1 - EXMEM_HEAP_SKIP - EXMEM_BUFFER_SIZE - 32 (exmem allocates 64 bytes extra, 32 before and 32 after block allocated)
else
MEMISOSTART=0x13DD6C
endif
endif

#suppress FI2 since it doesn't work
override OPT_FI2=

NEED_ENCODED_DISKBOOT=3

KEYSYS=d4

PLATFORMOSVER=39
