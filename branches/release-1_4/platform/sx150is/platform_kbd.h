#ifndef PLATFORM_KBD_H
#define PLATFORM_KBD_H
// plaform specific keyboard defines, see core/kbd_common.c for documentation
#define KEYS_MASK0 (0x00000000)
#define KEYS_MASK1 (0x0000F000)
#define KEYS_MASK2 (0x0000FF50)

#define SD_READONLY_FLAG    (0x20000) // Found @0xffb90df0, levent 0x20a
#define SD_READONLY_IDX     2

#define USB_MASK              (0x00040000) // Found @0xffb90df8, levent 0x202
#define USB_IDX             2
#endif
