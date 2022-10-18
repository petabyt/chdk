#ifndef PLATFORM_KBD_H
#define PLATFORM_KBD_H
// plaform specific keyboard defines, see core/kbd_common.c for documentation

#define KEYS_MASK0 0x00000000
#define KEYS_MASK1 0xA0000000
#define KEYS_MASK2 0x0FFF

#define SD_READONLY_IDX  2
#define SD_READONLY_FLAG 0x20000
#define USB_MASK 0x80000
#define USB_IDX  2

/*
battery door switch, 0: door open
forcing to one allows camera to run with door open.
Informational only for now,
making the camera boot with door open requires some ugly changes in boot.c
see http://chdk.setepontos.com/index.php?topic=5744.0
found via GetBatteryCoverClose (which looks in a table that tells it the physw word and bit)
*/
#define BATTCOVER_IDX  2
#define BATTCOVER_FLAG 0x8000

#define ANALOG_AV_FLAG      0x00002000 // Found @0xffad6268, levent 0x900 (non-inverted logic)
#define ANALOG_AV_IDX       1

#endif
