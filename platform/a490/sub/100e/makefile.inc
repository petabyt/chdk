#PLATFORMID=0x31F0
PLATFORMID=12784

PLATFORMOS=dryos

# Force ARAM on, and load CHDK in ARAM
override OPT_ARAM_MALLOC=1
override OPT_CHDK_IN_ARAM=1

# Set up size variables for AgentRAM
ARAM_HEAP_START=0x2ce000
ARAM_HEAP_SIZE=0x32000

ifdef OPT_CHDK_IN_ARAM
MEMISOSTART=$(ARAM_HEAP_START)
else
MEMISOSTART=0x129140
endif

# Base address 0xFFC00000 for A
ROMBASEADDR=0xFFC00000

# type of diskboot encoding: undefined = none; 1 = original; 2 = sx200, d10; 3 = ixus200...
# Dancing Bits
NEED_ENCODED_DISKBOOT=4

# FIR (requires correct keys in platform/fi2.inc)
KEYSYS=d4a

PLATFORMOSVER=43
