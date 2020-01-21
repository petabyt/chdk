#ifndef PLATFORM_KBD_H
#define PLATFORM_KBD_H

// plaform specific keyboard defines, see core/kbd_common.c for documentation
#define KEYS_MASK0 (0x00013FFE)
#define KEYS_MASK1 (0x00000C00)
#define KEYS_MASK2 (0x00000000)

// from stubs_entry.S
#define SD_READONLY_FLAG    0x20000000 // Found @0xfc637ee0, levent 0x30a
#define SD_READONLY_IDX     1
#define USB_MASK            0x00800000 // Found @0xfc637f28, levent 0x302
#define USB_IDX             2

// HDMI hotplug, from watching physw_status and jumping pins
#define HDMI_HPD_FLAG       0x00000020
#define HDMI_HPD_IDX        2

// standard fw doesn't care about bat door
/*
#define BATTCOVER_FLAG      0x00400000 // Found @0xfc637f20, levent 0x305
#define BATTCOVER_IDX       2
*/

#endif
