#ifndef PLATFORM_KBD_H
#define PLATFORM_KBD_H

// plaform specific keyboard defines, see core/kbd_common.c for documentation
#define KEYS_MASK0 (0x00050FFF)
#define KEYS_MASK1 (0x00000000)
#define KEYS_MASK2 (0x00000000)

#define SD_READONLY_FLAG    0x20000000 // Found @0xfc6137f4, levent 0x20a
#define SD_READONLY_IDX     1
#define USB_MASK            0x10000000 // Found @0xfc613834, levent 0x202
#define USB_IDX             2
#define HDMI_HPD_FLAG       0x00000020
#define HDMI_HPD_IDX        2
#define ANALOG_AV_FLAG      0x00008000
#define ANALOG_AV_IDX       1


// standard fw doesn't care about bat door, doesn't seem to have switch
/*
#define BATTCOVER_FLAG      0x04000000 // Found @0xfc61382c, levent 0x205
#define BATTCOVER_IDX       2
*/

#endif
