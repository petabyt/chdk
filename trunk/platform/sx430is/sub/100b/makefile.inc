PLATFORMID=13013
PLATFORMOS=dryos
PLATFORMOSVER=59

# address where wif or diskboot code will be loaded by camera
MEMBASEADDR=0x1900


# start of firmware
ROMBASEADDR=0xff010000


# points to the start of the memory pool used by the firmware
MEMISOSTART=0x002b9464

# type of FI2 encoding
KEYSYS = d4j
# type of diskboot encoding
NEED_ENCODED_DISKBOOT = 17

# generated FI2 needs word-based checksum
FI2FLAGS=W

