#ifndef PLATFORM_KBD_H
#define PLATFORM_KBD_H

#define KEYS_MASK0          0x0000DF42
#define KEYS_MASK1          0x00000000
#define KEYS_MASK2          0x000002F3

#define SD_READONLY_FLAG    0x02000000 // Found @0xffbf4c44, levent 0x20a
#define SD_READONLY_IDX     2

#define USB_MASK            0x10000000 // Found @0xffbf4c54, levent 0x202
#define USB_IDX             2

#define BATTCOVER_FLAG      0x04000000 // Found @0xffbf4c4c, levent 0x205
#define BATTCOVER_IDX       2

#endif
