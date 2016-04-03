# No Digic6 finsig utility in trunk yet
#override OPT_GEN_STUBS=
#override FORCE_GEN_STUBS=

# 0x329D
PLATFORMID=12957

# mandatory for DIGIC 6
THUMB_FW=1

PLATFORMOS=dryos
# 55 p6
PLATFORMOSVER=55

# start of firmware
ROMBASEADDR=0xFC000000

# TODO
# MAXRAMADDR = 0x0fffffff

# TODO "update file error"
KEYSYS=d4h
# OK
NEED_ENCODED_DISKBOOT=14

# mandatory for DIGIC 6
MEMBASEADDR=0x8000

# values for ARAM, from sig finder
ARAM_HEAP_START=0x006ce000
ARAM_HEAP_SIZE=0x00022000

# Force ARAM on, but don't load CHDK in ARAM, because size is marginal for core
override OPT_ARAM_MALLOC=1
override OPT_CHDK_IN_ARAM=

# next line is for the compatibility check, as comment
# PLATFORMID @ 0xfff20040
# below 2 commented lines are used by tools/compatbuilder.sh
# BLINK_LED_CONTROL=4
# BLINK_LED_GPIO=0xd20b0994
