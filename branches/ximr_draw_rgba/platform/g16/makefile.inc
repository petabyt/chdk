# force FI2 off because FI2 of digic 6 hardware initialization issues
override OPT_FI2=
# mandatory for DIGIC 6
THUMB_FW=1

PLATFORMID=12916
PLATFORMOSVER=52
PLATFORMOS=dryos

NEED_ENCODED_DISKBOOT=11
KEYSYS=d4e

ROMBASEADDR=0xFC000000
MAXRAMADDR =0x0fffffff
ARAM_HEAP_START = 0x006ce000 #  Found @0xfc111e9c
ARAM_HEAP_SIZE = 0x00022000  #  Found @0xfc111e76

# below 2 commented lines are used by tools/compatbuilder.sh
# BLINK_LED_CONTROL=4
# BLINK_LED_GPIO=0xd20b0994
# PLATFORMID @ 0xfff20040

DIGIC = 60

