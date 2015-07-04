PLATFORMID=12959
PLATFORMOS=dryos
PLATFORMOSVER=55

ROMBASEADDR=0xff010000

# TODO
# Set up size variables for EXMEM
#EXMEM_HEAP_SKIP=0xFD200	#(0x44000000-0x43F02E00) from sub_FF86CAA8 = size of video buffers in EXMEM area (?)
#EXMEM_BUFFER_SIZE=0x300000	# Amount of EXMEM memory to allocate for CHDK = 3MB
ARAM_HEAP_START = 0x60e000  // Found @ 0xff22c030
ARAM_HEAP_SIZE  = 0x22000   // Found @ 0xff22bff0

MAXRAMADDR=0x0fffffff # 256 MB

# TODO d10 c&p
#ifdef OPT_CHDK_IN_EXMEM
#MEMISOSTART=0x3C02DE0		# MAXRAMADDR+1 - EXMEM_HEAP_SKIP - EXMEM_BUFFER_SIZE - 32 (exmem allocates 64 bytes extra, 32 before and 32 after block allocated)
#else
MEMISOSTART=0x002ff248
#endif

# type of diskboot encoding
NEED_ENCODED_DISKBOOT=14
# type of FI2 encoding
KEYSYS=d4h

