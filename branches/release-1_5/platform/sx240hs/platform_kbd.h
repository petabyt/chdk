#ifndef PLATFORM_KBD_H
#define PLATFORM_KBD_H
// plaform specific keyboard defines, see core/kbd_common.c for documentation

#define KEYS_MASK0 (0x00000000)     
#define KEYS_MASK1 (0x3F800000)     // SX 240
#define KEYS_MASK2 (0x00001FE0)     // SX 240

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
#define SD_READONLY_FLAG    0x00080000 // Found @0xff441600, levent 0x20a
#define SD_READONLY_IDX     2
#define USB_MASK            0x10000000 // Found @0xff441638, levent 0x202
#define USB_IDX             2
#endif
