#ifndef PLATFORM_KBD_H
#define PLATFORM_KBD_H

// plaform specific keyboard defines, see core/kbd_common.c for documentation
// non-standard key state update to handle inverted keys, etc
#define KBD_CUSTOM_UPDATE_KEY_STATE 1

#define KEYS_MASK0 (0x00000006)
#define KEYS_MASK1 (0x000413E9)
#define KEYS_MASK2 (0x00000000)
#define KEYS_INV0  (0x00000006)

#define SD_READONLY_FLAG    0x20000000 // Found @0xfc623d8c, levent 0x20a
#define SD_READONLY_IDX     1
#define USB_MASK            0x10000000 // Found @0xfc623dec, levent 0x202
#define USB_IDX             2
#define HDMI_HPD_FLAG       0x00000010
#define HDMI_HPD_IDX        2
#endif
