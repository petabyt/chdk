#ifndef PLATFORM_KBD_H
#define PLATFORM_KBD_H
// plaform specific keyboard defines, see core/kbd_common.c for documentation

#define KEYS_MASK0          0x013FFC00
#define KEYS_MASK1          0x00000000
#define KEYS_MASK2          0x000C0000

#define SD_READONLY_FLAG    0x00000002 // Found @0xff464d1c, levent 0x20a
#define SD_READONLY_IDX     1

#define USB_MASK            0x10000000 // Found @0xff464d94, levent 0x202
#define USB_IDX             2

#define BATTCOVER_FLAG      0x00000100 // Found @0xff464d24, levent 0x205
#define BATTCOVER_IDX       2

#define HOTSHOE_FLAG        0x00000400 // Found @0xff464d2c, levent 0x204
#define HOTSHOE_IDX         2

#define CAM_HAS_JOGDIAL     1

#endif
