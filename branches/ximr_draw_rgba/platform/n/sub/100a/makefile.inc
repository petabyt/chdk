
# Powershot N

PLATFORMID=12894	
PLATFORMOS=dryos
PLATFORMOSVER=52

ROMBASEADDR=0xff000000
MAXRAMADDR = 0x0fffffff
MEMISOSTART = 0x002f8b2c

# Set up size variables for AgentRAM
# Note, ROM copied to RAM :- from 0xff8e9e9c, to 0x00685000, len 44551 words.
ARAM_HEAP_START = 0x5ce000# Found @ 0xff2490b8
ARAM_HEAP_SIZE  = 0x22000# Found @ 0xff24907c

# type of diskboot encoding
NEED_ENCODED_DISKBOOT=10
# type of FI2 encoding
KEYSYS=d4d


