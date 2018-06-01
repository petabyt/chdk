# mandatory for DIGIC 6
THUMB_FW=1

PLATFORMID=12960

PLATFORMOS=dryos

# start of firmware
ROMBASEADDR=0xFC000000

MAXRAMADDR = 0x1fffffff

# Found @
NEED_ENCODED_DISKBOOT=13

# Found @
KEYSYS=d4g

# generated FI2 needs word-based checksum
FI2FLAGS=W

PLATFORMOSVER=57

# mandatory for DIGIC 6
MEMBASEADDR=0x8000

# force FI2 off because of various issues
override OPT_FI2=

# next line is for the compatibility check, as comment
# PLATFORMID @ 0xfff20270
# below 2 commented lines are used by tools/compatbuilder.sh
# BLINK_LED_CONTROL=4
# BLINK_LED_GPIO=0xd20b0994

ARAM_HEAP_START = 0x0074e000 #  Found @0xfc18ec9c
ARAM_HEAP_SIZE = 0x00022000 #  Found @0xfc18ec76
