#ifndef PLATFORM_KBD_H
#define PLATFORM_KBD_H
// plaform specific keyboard defines, see core/kbd_common.c for documentation

#define KEYS_MASK0 (0x0000000C) // for sd970
#define KEYS_MASK1 (0x00000000) // for sd970
#define KEYS_MASK2 (0x00000BFF) // for sd970

#define SD_READONLY_FLAG    0x00020000 // sd970: Found @0xffaf1330, levent 0x90a
#define SD_READONLY_IDX     2

#define USB_MASK            0x00080000 // sd970: Found @0xffaf1348, levent 0x902
#define USB_IDX  2

#define BATTCOVER_FLAG      0x00008000 // sd970: Found @0xffaf1318, levent 0x905
#define BATTCOVER_IDX       2

#define ANALOG_AV_FLAG      0x00040000 // sd970: Found @0xffaf133c, levent 0x900 (non-inverted logic)
#define ANALOG_AV_IDX       2
#endif
