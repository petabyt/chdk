# force FI2 off because FI2 of issues with orientation sensor and crashing when hybrid auto is enabled
override OPT_FI2=
# 0x329A
PLATFORMID=12954

# mandatory for DIGIC 6
THUMB_FW=1

PLATFORMOS=dryos
# 55 p6
PLATFORMOSVER=55

# start of firmware
ROMBASEADDR=0xFC000000

# TODO
MAXRAMADDR=0x1fffffff

# works, but crashes in hybrid auto
KEYSYS=d4h
# OK
NEED_ENCODED_DISKBOOT=14

# mandatory for DIGIC 6
MEMBASEADDR=0x8000

ARAM_HEAP_START=0x006ce000
ARAM_HEAP_SIZE=0x00022000

# next line is for the compatibility check, as comment
# PLATFORMID @ 0xfff20040
# below 2 commented lines are used by tools/compatbuilder.sh
# BLINK_LED_CONTROL=4
# BLINK_LED_GPIO=0xd20b0884

DIGIC = 60

