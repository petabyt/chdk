# below 2 commented lines are used by tools/compatbuilder.sh
# BLINK_LED_CONTROL=1
# BLINK_LED_GPIO=0xc0220128

# checked for sd970
ROMBASEADDR=0xff810000

# sd970 100A: Found @ 0xffff3574
NEED_ENCODED_DISKBOOT=2

PLATFORMOS=dryos
PLATFORMOSVER=31
# (0x31c1) // sd970: Found @ 0xfffe0130
PLATFORMID=12737
MAXRAMADDR=0x03ffffff
MEMISOSTART=0x001487c4
#  (0x31c1) // sd970: Found @ 0xfffe0130
KEYSYS=d4
#  (0x31c1) // sd970: Found @ 0xfffe0130
NEED_ENCODED_DISKBOOT=2
#  (0x31c1) // sd970: Found @ 0xfffe0130
ARAM_HEAP_START=0x34e000
#  (0x31c1) // sd970: Found @ 0xfffe0130
ARAM_HEAP_SIZE=0x32000
