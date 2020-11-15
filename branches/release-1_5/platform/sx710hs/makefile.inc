#0x32A6
PLATFORMID=12966

# mandatory for DIGIC 6
THUMB_FW=1

PLATFORMOS=dryos
PLATFORMOSVER=57

# start of firmware
ROMBASEADDR=0xFC000000

MAXRAMADDR = 0x1fffffff

NEED_ENCODED_DISKBOOT=13

KEYSYS=d4g

MEMBASEADDR=0x8000

#
# next line is for the compatibility check, as comment
# PLATFORMID @ 0xfff20270
# below 2 commented lines are used by tools/compatbuilder.sh
# BLINK_LED_CONTROL=4
# BLINK_LED_GPIO=0xd20b0994

ARAM_HEAP_START = 0x006ce000 #  Found @0xfc4ad1e0
ARAM_HEAP_SIZE = 0x00022000 #  Found @0xfc4ad1ba

# Force ARAM on, but don't load CHDK in ARAM, because size is marginal for core
override OPT_ARAM_MALLOC=1
override OPT_CHDK_IN_ARAM=

DIGIC = 60

