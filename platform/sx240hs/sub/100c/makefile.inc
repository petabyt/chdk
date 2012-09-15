# 0x3244 Found @ 0xfff40040
PLATFORMID=12868

PLATFORMOS=dryos

# address where wif or diskboot code will be loaded by camera
MEMBASEADDR=0x1900

# size of memory region for CHDK
RESTARTSTART=0x50000

# points to the start of the memory pool used by the firmware
MEMISOSTART=0x193A24

# start of firmware
ROMBASEADDR=0xFF000000

MAXRAMADDR = 0x0fffffff

# Found @ 0xffff3cf0
NEED_ENCODED_DISKBOOT=8

PLFLAGS=-DMEMBASEADDR=$(MEMBASEADDR) -DMEMISOSTART=$(MEMISOSTART) -DMEMISOSIZE=$(MEMISOSIZE)
PLFLAGS+=-DRESTARTSTART=$(RESTARTSTART)

# Found @ 0xffff3ce0
KEYSYS=d4c
