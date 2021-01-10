PLATFORMID=12979

PLATFORMOS=dryos

PLATFORMOSVER=58

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

DIGIC = 60

