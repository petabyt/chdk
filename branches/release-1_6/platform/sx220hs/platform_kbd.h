#ifndef PLATFORM_KBD_H
#define PLATFORM_KBD_H
// plaform specific keyboard defines, see core/kbd_common.c for documentation
#define KEYS_MASK0 (0x000FFC0F)     // sx220 physw_status[0]
#define KEYS_MASK1 (0x00200000)
#define KEYS_MASK2 (0x00002182)     // sx220 physw_status[2]

#define SD_READONLY_FLAG (0x20000)
#define SD_READONLY_IDX     2

#define USB_MASK (0x4000000)
#define USB_IDX  2

#define BATTCOVER_FLAG      0x00008000 // Found @0xff3b18a4, levent 0x905
#define BATTCOVER_IDX       2
#endif
