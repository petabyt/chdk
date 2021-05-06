#ifndef PLATFORM_KBD_H
#define PLATFORM_KBD_H
// plaform specific keyboard defines, see core/kbd_common.c for documentation
#define KEYS_MASK0 (0x00004003)
#define KEYS_MASK1 (0x0094FFE0)
#define KEYS_MASK2 (0x00000000)

#define SD_READONLY_FLAG    0x00020000 // Found @0xffb0ad4c, levent 0x90a
#define SD_READONLY_IDX     2

#define USB_MASK            0x00040000 // Found @0xffb0ad58, levent 0x902
#define USB_IDX             2

#define HOTSHOE_FLAG        0x10000000 // Found @0xffb0ad88, levent 0x904
#define HOTSHOE_IDX         2
#endif
