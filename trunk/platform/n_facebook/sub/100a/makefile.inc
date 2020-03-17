
# Powershot N Facebook

PLATFORMID=12939
PLATFORMOS=dryos
PLATFORMOSVER=52

ROMBASEADDR=0xff000000
MAXRAMADDR = 0x0fffffff
MEMISOSTART = 0x002f8aec

# Note, ROM copied to RAM :- from 0xff8e8f64, to 0x00685000, len 44551 words.

# Set up size variables for AgentRAM
ARAM_HEAP_START = 0x5ce000# Found @ 0xff2490e4
ARAM_HEAP_SIZE  = 0x22000# Found @ 0xff2490a8

# type of diskboot encoding
NEED_ENCODED_DISKBOOT=10
# type of FI2 encoding
KEYSYS=d4d


