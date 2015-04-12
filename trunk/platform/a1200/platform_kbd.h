#ifndef PLATFORM_KBD_H
#define PLATFORM_KBD_H
// plaform specific keyboard defines, see core/kbd_common.c for documentation

#define KEYS_MASK0  (0x00000000)
#define KEYS_MASK1  (0x00000000)
#define KEYS_MASK2  (0x00000002|0x00000004|0x00000008|0x00000010|0x00000020|0x00000080|0x00000100|0x00000200|0x000000400|0x00000800|0x00001000|0x00002000|0x00004000)

#define SD_READONLY_FLAG    0x00020000 // Found @0xffb57a34, levent 0x90a
#define SD_READONLY_IDX     2
#define USB_MASK            0x04000000 // Found @0xffb57a5c, levent 0x902
#define USB_IDX             2

#endif
