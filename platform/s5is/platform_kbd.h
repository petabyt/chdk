#ifndef PLATFORM_KBD_H
#define PLATFORM_KBD_H
// plaform specific keyboard defines, see core/kbd_common.c for documentation
#define KEYS_MASK0 (0x00000003)
#define KEYS_MASK1 (0x7F3F7860)
#define KEYS_MASK2 (0x00000000)

#define SD_READONLY_FLAG (0x20000)
#define SD_READONLY_IDX 2

#define USB_MASK (0x200000)
#define USB_IDX  2

#define HOTSHOE_FLAG        0x00080000 // Found @0xffa9cec8, levent 0x904
#define HOTSHOE_IDX         2

#define KBD_ZOOM_FOR_MF_USE_MF_KEY 1
#endif
