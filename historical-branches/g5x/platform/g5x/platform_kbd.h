#ifndef PLATFORM_KBD_H
#define PLATFORM_KBD_H

// plaform specific keyboard defines, see core/kbd_common.c for documentation
#define KEYS_MASK0 (0x00050FFF)
#define KEYS_MASK1 (0x00000010)
#define KEYS_MASK2 (0x00000000)

#define SD_READONLY_FLAG    0x20000000 // Found @FC6CEA8C, levent 0x30a
#define SD_READONLY_IDX     1
#define USB_MASK            0x00800000 // Found @FC6CEADC, levent 0x302
#define USB_IDX             2

#define CAM_HAS_JOGDIAL     1

#endif
