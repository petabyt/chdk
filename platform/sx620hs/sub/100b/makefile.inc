PLATFORMID=12995
PLATFORMOS=dryos
PLATFORMOSVER=58

# address where wif or diskboot code will be loaded by camera
MEMBASEADDR=0x1900

# start of firmware
ROMBASEADDR=0xff010000

# points to the start of the memory pool used by the firmware
MEMISOSTART = 0x0032a990

# type of FI2 encoding
KEYSYS = d4i
# type of diskboot encoding
NEED_ENCODED_DISKBOOT = 16

# generated FI2 needs word-based checksum
FI2FLAGS=W

