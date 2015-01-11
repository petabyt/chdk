#SX160IS P-ID (0x325a) // Found @ 0xfffe0040
PLATFORMID=12890

PLATFORMOS=dryos
PLATFORMOSVER=51

# Force EXMEM on for sx160is - can run without but slightly low, ~470k free at start with ARAM
override OPT_EXMEM_MALLOC=1
override OPT_CHDK_IN_EXMEM=1

override OPT_ARAM_MALLOC=1
# not enough room for CHDK in ARAM
override OPT_CHDK_IN_ARAM=

# start of firmware
ROMBASEADDR=0xFF810000

# highest RAM address
MAXRAMADDR=0x03FFFFFF

# Set up size variables for EXMEM
EXMEM_HEAP_SKIP=0x2DB400	#(0x44000000-0x43D24C00) from sub_FF88FC9C = size of video buffers in EXMEM area
EXMEM_BUFFER_SIZE=0x80000 	# Amount of EXMEM memory to allocate for CHDK; 40000=256KB, 80000=512KB, A0000=640kb, C0000=768KB, 100000=1MB

# points to the start of the memory pool used by the firmware
ifdef OPT_CHDK_IN_EXMEM
MEMISOSTART=0x3CA4BE0		# MAXRAMADDR+1 - EXMEM_HEAP_SKIP - EXMEM_BUFFER_SIZE - 32 (exmem allocates 64 bytes extra, 32 before and 32 after block allocated)
else
MEMISOSTART=0x1639D4
endif
ARAM_HEAP_START=0x38e000
ARAM_HEAP_SIZE=0x22000


NEED_ENCODED_DISKBOOT=9
KEYSYS=d4c
