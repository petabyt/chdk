PLATFORMID=12993
PLATFORMOS=dryos
PLATFORMOSVER=58

# address where wif or diskboot code will be loaded by camera
MEMBASEADDR=0x1900

# start of firmware
ROMBASEADDR=0xFF810000


MAXRAMADDR=0x07ffffff

# type of FI2 encoding
KEYSYS=d4i
# type of diskboot encoding
NEED_ENCODED_DISKBOOT=16

# generated FI2 needs word-based checksum
FI2FLAGS=W

# force FI2 build off until keys are in the autobuild
override OPT_FI2=

# below 2 commented lines are used by tools/compatbuilder.sh
# BLINK_LED_CONTROL=3
# BLINK_LED_GPIO=0xc022d1fc
#

