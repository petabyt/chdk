PLATFORMID=13012
PLATFORMOS=dryos
PLATFORMOSVER=59


# start of firmware
ROMBASEADDR=0xff810000


# points to the start of the memory pool used by the firmware
MEMISOSTART=0x0018aa24

# type of FI2 encoding
KEYSYS = d4j
# type of diskboot encoding
NEED_ENCODED_DISKBOOT = 17

# generated FI2 needs word-based checksum
FI2FLAGS=W

