#ifndef PLATFORM_KBD_H
#define PLATFORM_KBD_H

#define KEYS_MASK0          0x0000F0C8
#define KEYS_MASK1          0x00000000
#define KEYS_MASK2          0x0000C360

#define SD_READONLY_FLAG    0x00400000 // Found @0xff694f54, levent 0x30a
#define SD_READONLY_IDX     2
#define USB_MASK            0x01000000 // Found @0xff694f64, levent 0x302
#define USB_IDX             2
#define BATTCOVER_FLAG      0x00800000 // Found @0xff694f5c, levent 0x305
#define BATTCOVER_IDX       2
#define ANALOG_AV_FLAG      0x00000002 // Found @0xff694e9c, levent 0x300 (non-inverted logic)
#define ANALOG_AV_IDX       0


#endif

