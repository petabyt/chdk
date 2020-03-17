# 0x32d6
PLATFORMID=13014

# mandatory for DIGIC 6
THUMB_FW=1

PLATFORMOS=dryos
# 59 p4
PLATFORMOSVER=59

# start of firmware
ROMBASEADDR=0xFC000000

# memory values repeat at 0x20000000 intervals
MAXRAMADDR = 0x1fffffff

# verified
KEYSYS=d4j
FI2FLAGS=W

# verified in ROM
NEED_ENCODED_DISKBOOT=17

# mandatory for DIGIC 6
MEMBASEADDR=0x8000

# next line is for the compatibility check - verified
# PLATFORMID @ 0xfff20270
# below 2 commented lines are used by tools/compatbuilder.sh
# BLINK_LED_CONTROL=4
# BLINK_LED_GPIO=0xd20b0994

DIGIC = 60

