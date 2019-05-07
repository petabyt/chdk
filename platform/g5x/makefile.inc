# mandatory for DIGIC 6
THUMB_FW=1

PLATFORMID=12979

PLATFORMOS=dryos

PLATFORMOSVER=58

# mandatory for DIGIC 6
MEMBASEADDR=0x8000

# start of firmware
ROMBASEADDR=0xFC000000

# end of RAM
MAXRAMADDR = 0x0fffffff

# force FI2 off - does not work
override OPT_FI2=

# Found @FC0044D8
NEED_ENCODED_DISKBOOT=15

# Found @FC003FC8 & @FCC8FD64
KEYSYS=d5

# next line is for the compatibility check, as comment
# PLATFORMID @ 0xfdf20040
# below 2 commented lines are used by tools/compatbuilder.sh
# BLINK_LED_CONTROL=4
# BLINK_LED_GPIO=0xd20b0994
