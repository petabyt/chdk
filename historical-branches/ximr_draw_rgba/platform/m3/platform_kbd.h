#ifndef PLATFORM_KBD_H
#define PLATFORM_KBD_H
#define KEYS_MASK0 (0x00000000)
#define KEYS_MASK1 (0x00043FF9) //(0x0000001e)
#define KEYS_MASK2 (0x00000000)

#define SD_READONLY_FLAG    0x20000000 // Found @0xFC4D3EF4, levent 0x20a
#define SD_READONLY_IDX     1
#define USB_MASK            0x10000000 // Found @0xFC4D3F24, levent 0x202
#define USB_IDX             2
#define BATTCOVER_FLAG      0x01000000 // Found @0xFC4D3F04, levent 0x205
#define BATTCOVER_IDX       0
#define HOTSHOE_FLAG        0x00010000 // Found @0xfc5f9af0, levent 0x204
#define HOTSHOE_IDX         2
#define HDMI_HPD_FLAG       0x00000010
#define HDMI_HPD_IDX        2

#endif
