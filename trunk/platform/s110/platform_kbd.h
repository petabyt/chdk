#ifndef PLATFORM_KBD_H
#define PLATFORM_KBD_H
// plaform specific keyboard defines, see core/kbd_common.c for documentation

#define KEYS_MASK0 (0x000181EF)
#define KEYS_MASK1 (0x00800000)
#define KEYS_MASK2 (0x000000C0)

#define SD_READONLY_FLAG    0x00000800 // Found @0xf864bc7c, levent 0x20a
#define SD_READONLY_IDX     2
#define USB_MASK            0x10000000 // Found @0xf864bcac, levent 0x202
#define USB_IDX             2

#endif
