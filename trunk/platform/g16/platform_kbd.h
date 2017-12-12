// G16
#ifndef PLATFORM_KBD_H
#define PLATFORM_KBD_H

// plaform specific keyboard defines, see core/kbd_common.c for documentation

#define SD_READONLY_FLAG    0x20000000 // Found @0xfc571b08, levent 0x20a
#define SD_READONLY_IDX     1

#define USB_MASK            0x10000000 // Found @0xfc571b38, levent 0x202
#define USB_IDX             2

#define BATTCOVER_FLAG      0x00000200 // Found @0xfc571b18, levent 0x205
#define BATTCOVER_IDX       2

#define HOTSHOE_FLAG        0x00000010 // Found @0xfc571ac0, levent 0x204
#define HOTSHOE_IDX         1

#define KEYS_MASK0 (0x000D3FFE)
#define KEYS_MASK1 (0x00000000)
#define KEYS_MASK2 (0x00000000)

#endif
