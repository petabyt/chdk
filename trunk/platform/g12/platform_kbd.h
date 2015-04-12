#ifndef PLATFORM_KBD_H
#define PLATFORM_KBD_H
// plaform specific keyboard defines, see core/kbd_common.c for documentation

#define KEYS_MASK0          0x007DFC20
#define KEYS_MASK1          0x00000000
#define KEYS_MASK2          0x00000003

#define SD_READONLY_FLAG    0x00020000 // Found @0xffbb9448, levent 0x90a
#define SD_READONLY_IDX     2

#define USB_MASK            0x04000000 // Found @0xffbb9478, levent 0x902
#define USB_IDX             2

#define BATTCOVER_FLAG      0x00008000 // Found @0xffbb9438, levent 0x905
#define BATTCOVER_IDX       2

#define HOTSHOE_FLAG        0x01000000 // Found @0xffbb9468, levent 0x904
#define HOTSHOE_IDX         2

#define CAM_HAS_JOGDIAL     1

#endif
