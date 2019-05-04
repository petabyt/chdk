#ifndef PLATFORM_KBD_H
#define PLATFORM_KBD_H
// plaform specific keyboard defines, see core/kbd_common.c for documentation

#define KEYS_MASK0          0x00000000
#define KEYS_MASK1          0x00000000
#define KEYS_MASK2          0x0000FA7F

#define SD_READONLY_FLAG    0x02000000 // Found @0xffba9140, levent 0x20a
#define SD_READONLY_IDX     2
#define USB_MASK            0x10000000 // Found @0xffba9150, levent 0x202
#define USB_IDX             2

#endif
