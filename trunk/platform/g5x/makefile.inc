PLATFORMID=12979
PLATFORMOS=dryos
PLATFORMOSVER=58
DIGIC = 60

# values for ARAM, from sig finder
ARAM_HEAP_START=0x006ce000
ARAM_HEAP_SIZE=0x00022000

# Force ARAM on, but don't load CHDK in ARAM, because size is marginal for core
override OPT_ARAM_MALLOC=1
override OPT_CHDK_IN_ARAM=

override OPT_EXMEM_MALLOC=1
EXMEM_BUFFER_SIZE=0x400000

# start of firmware
ROMBASEADDR=0xFC000000

# end of RAM
MAXRAMADDR = 0x3fffffff

# Found @FC0044D8
NEED_ENCODED_DISKBOOT=15

# Found @FC003FC8 & @FCC8FD64
KEYSYS=d5

# generated FI2 needs word-based checksum
FI2FLAGS=W

# next line is for the compatibility check, as comment
# PLATFORMID @ 0xFDF20270
# below 2 commented lines are used by tools/compatbuilder.sh
# BLINK_LED_CONTROL=4
# BLINK_LED_GPIO=0xd20b0994
