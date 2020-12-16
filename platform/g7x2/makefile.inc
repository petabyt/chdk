# mandatory for DIGIC 6 and later
THUMB_FW=1
# update build rules for Digic 7 ARM changes
DIGIC7=1

PLATFORMID=12988

PLATFORMOS=dryos

PLATFORMOSVER=58

# mandatory for DIGIC 6
MEMBASEADDR=0x8000

# start of firmware
ROMBASEADDR=0xE0000000

# end of RAM
MAXRAMADDR = 0x0fffffff

# Found @e06c2db4
NEED_ENCODED_DISKBOOT=16

# Found @e0018b20 & @e0e74828
KEYSYS=d4i

# generated FI2 needs word-based checksum
FI2FLAGS=W

# next line is for the compatibility check, as comment
# PLATFORMID @ 0xe1f20270
# below 2 commented lines are used by tools/compatbuilder.sh
# BLINK_LED_CONTROL=5
# BLINK_LED_GPIO=0xD20801E4

DIGIC = 70
