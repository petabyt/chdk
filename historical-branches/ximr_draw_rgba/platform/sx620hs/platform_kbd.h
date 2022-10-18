#ifndef PLATFORM_KBD_H
#define PLATFORM_KBD_H

#define KEYS_MASK0          0x00080C00
#define KEYS_MASK1          0x40000000
#define KEYS_MASK2          0x0000FED8

#define SD_READONLY_FLAG    0x00400000 // Found @0xff69b414, levent 0x30a
#define SD_READONLY_IDX     2

#define USB_MASK            0x01000000 // Found @0xff69b424, levent 0x302
#define USB_IDX             2

#define BATTCOVER_FLAG      0x00800000 // Found @0xff69b41c, levent 0x305
#define BATTCOVER_IDX       2

#endif

