#ifndef PLATFORM_KBD_H
#define PLATFORM_KBD_H

// plaform specific keyboard defines, see core/kbd_common.c for documentation
#define KEYS_MASK0 (0x00056fff)
//#define KEYS_MASK0 (0x00050fff)
#define KEYS_MASK1 (0x00000000)
#define KEYS_MASK2 (0x0000001e)
#define SD_READONLY_FLAG    0x20000000 // Found @0xfc5cfc1c, levent 0x20a
#define SD_READONLY_IDX     1
#define USB_MASK            0x10000000 // Found @0xfc5cfc8c, levent 0x202
#define USB_IDX             2
#define BATTCOVER_FLAG      0x04000000 // Found @0xfc5cfc84, levent 0x205
#define BATTCOVER_IDX       2
#define HOTSHOE_FLAG        0x00000800 // Found @0xfc5cfbf4, levent 0x204
#define HOTSHOE_IDX         1
#endif
