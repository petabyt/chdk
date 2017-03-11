#ifndef PLATFORM_KBD_H
#define PLATFORM_KBD_H
// plaform specific keyboard defines, see core/kbd_common.c for documentation
#define KEYS_MASK0 (0x003FFC00)
#define KEYS_MASK1 (0x00800000)
#define KEYS_MASK2 (0x000C8800)

#define SD_READONLY_FLAG    0x00000002 // Found @0xff4a0da4, levent 0x20a
#define SD_READONLY_IDX     1
#define USB_MASK            0x10000000 // Found @0xff4a0e0c, levent 0x202
#define USB_IDX             2
#endif
