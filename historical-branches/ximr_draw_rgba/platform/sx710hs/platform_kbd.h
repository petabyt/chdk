#ifndef PLATFORM_KBD_H
#define PLATFORM_KBD_H

// plaform specific keyboard defines, see core/kbd_common.c for documentation
#define KEYS_MASK0 (0x0001E30E)
#define KEYS_MASK1 (0x0000042C)
#define KEYS_MASK2 (0x0000001E)

// from stubs_entry.S
#define SD_READONLY_FLAG    0x00000100 // Found @0xfc5bfae0, levent 0x20a
#define SD_READONLY_IDX     1
#define USB_MASK            0x00400000 // Found @0xfc5bfb78, levent 0x202
#define USB_IDX             2
#define HDMI_HPD_FLAG       0x00000020
#define HDMI_HPD_IDX        0
#define ANALOG_AV_FLAG      0x00008000 // levent 0x200
#define ANALOG_AV_IDX       1

// standard fw doesn't care about bat door, doesn't seem to have switch
/*
#define BATTCOVER_FLAG      0x00200000 // Found @0xfc5bfb70, levent 0x205
#define BATTCOVER_IDX       2
*/

#endif
