#ifndef PLATFORM_KBD_H
#define PLATFORM_KBD_H
// plaform specific keyboard defines, see core/kbd_common.c for documentation
#define KEYS_MASK0 (0x00CFFDE0)
#define KEYS_MASK1 (0x00000000)
#define KEYS_MASK2 (0x0000C000) 

#define SD_READONLY_FLAG    0x00000002 // Found @0xff49e5dc, levent 0x20a
#define SD_READONLY_IDX     1

#define USB_MASK            0x10000000 // Found @0xff49e64c, levent 0x202
#define USB_IDX             2

#define HOTSHOE_FLAG        0x00080000 // Found @0xff49e624, levent 0x204
#define HOTSHOE_IDX         2
#endif
