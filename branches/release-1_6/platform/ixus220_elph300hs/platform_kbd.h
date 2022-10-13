#ifndef PLATFORM_KBD_H
#define PLATFORM_KBD_H
// plaform specific keyboard defines, see core/kbd_common.c for documentation
#define KEYS_MASK0 0
#define KEYS_MASK1 0
#define KEYS_MASK2 0x00004BFF

#define SD_READONLY_FLAG (0x00020000)
#define SD_READONLY_IDX 2

#define USB_MASK (0x04000000)
#define USB_IDX  2

#define BATTCOVER_IDX  2
#define BATTCOVER_FLAG 0x8000

#endif
