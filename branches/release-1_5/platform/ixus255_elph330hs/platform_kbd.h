#ifndef PLATFORM_KBD_H
#define PLATFORM_KBD_H
// plaform specific keyboard defines, see core/kbd_common.c for documentation
// Ignores power button
#define KEYS_MASK0 (0x00000ce3)
#define KEYS_MASK1 (0x00b00000)
#define KEYS_MASK2 (0x00005000)

#define SD_READONLY_FLAG    0x02000000 // Found @0xff5b8984, levent 0x20a
#define SD_READONLY_IDX     1

#define USB_MASK            0x10000000 // Found @0xff5b89c4, levent 0x202
#define USB_IDX             2

#define BATTCOVER_FLAG      0x04000000 // Found @0xff5b89b4, levent 0x205
#define BATTCOVER_IDX       2
#endif
