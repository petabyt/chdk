#ifndef PLATFORM_KBD_H
#define PLATFORM_KBD_H
// plaform specific keyboard defines, see core/kbd_common.c for documentation
#define KEYS_MASK0 (0x00000300)
#define KEYS_MASK1 (0x0000FFF0)
#define KEYS_MASK2 (0x00000000)

#define SD_READONLY_FLAG (0x20000)
#define SD_READONLY_IDX 2

#define USB_MASK (0x200000)
#define USB_IDX  2

#define BATTCOVER_FLAG      0x00008000 // Found @0xffafe43c, levent 0x905
#define BATTCOVER_IDX       0
#endif
