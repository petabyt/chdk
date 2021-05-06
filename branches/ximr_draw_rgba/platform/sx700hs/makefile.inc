# force FI2 off because FI2 of issues with orientation sensor and crashing when hybrid auto is enabled
override OPT_FI2=
# 0x3285
PLATFORMID=12933 

# mandatory for DIGIC 6
THUMB_FW=1

PLATFORMOS=dryos
# 54 p3
PLATFORMOSVER=54 

# start of firmware
ROMBASEADDR=0xFC000000

# TODO
MAXRAMADDR=0x1fffffff

# works, but crashes in hybrid auto
KEYSYS=d4h
# OK
NEED_ENCODED_DISKBOOT=12

ARAM_HEAP_START=0x006ce000
ARAM_HEAP_SIZE=0x00022000

# next line is for the compatibility check, as comment
# PLATFORMID @ 0xfff20040
# below 2 commented lines are used by tools/compatbuilder.sh
#BLINK_LED_CONTROL=4
#BLINK_LED_GPIO=0xd20b0994


# Force ARAM on, but don't load CHDK in ARAM, because size is marginal for core
override OPT_ARAM_MALLOC=1
override OPT_CHDK_IN_ARAM=


DIGIC = 60

