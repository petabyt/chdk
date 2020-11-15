# force FI2 off because FI2 of hardware initialization issues 
override OPT_FI2=
# mandatory for DIGIC 6
THUMB_FW=1

PLATFORMID=12953

PLATFORMOS=dryos

# start of firmware
ROMBASEADDR=0xFC000000

MAXRAMADDR = 0x1fffffff

# Found @
NEED_ENCODED_DISKBOOT=14

# Found @
KEYSYS=d4h

PLATFORMOSVER=55

# mandatory for DIGIC 6
MEMBASEADDR=0x8000

# next line is for the compatibility check, as comment
# PLATFORMID @ 0xfff20040
# below 2 commented lines are used by tools/compatbuilder.sh
# BLINK_LED_CONTROL=4
# BLINK_LED_GPIO=0xd20b0994

DIGIC = 60

