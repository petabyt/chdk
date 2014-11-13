PLATFORMID=12919
PLATFORMOS=dryos
PLATFORMOSVER=52

ROMBASEADDR=0xff000000

# TODO
# Set up size variables for EXMEM
#EXMEM_HEAP_SKIP=0xFD200	#(0x44000000-0x43F02E00) from sub_FF86CAA8 = size of video buffers in EXMEM area (?)
#EXMEM_BUFFER_SIZE=0x300000	# Amount of EXMEM memory to allocate for CHDK = 3MB

MAXRAMADDR=0x07ffffff # 128 MB

# TODO d10 c&p
#ifdef OPT_CHDK_IN_EXMEM
#MEMISOSTART=0x3C02DE0		# MAXRAMADDR+1 - EXMEM_HEAP_SKIP - EXMEM_BUFFER_SIZE - 32 (exmem allocates 64 bytes extra, 32 before and 32 after block allocated)
#else
MEMISOSTART=0x00265a28
#endif

# type of diskboot encoding
NEED_ENCODED_DISKBOOT=11
# type of FI2 encoding
KEYSYS=d4e

