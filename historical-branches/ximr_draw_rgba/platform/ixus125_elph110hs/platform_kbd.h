#ifndef PLATFORM_KBD_H
#define PLATFORM_KBD_H
// plaform specific keyboard defines, see core/kbd_common.c for documentation

#define KEYS_MASK0 (0x00000F4F)     //Logic OR of group 0 Keymap values
#define KEYS_MASK1 (0x00B00000)     //Logic OR of group 1 Keymap values
#define KEYS_MASK2 (0x00000000)     //Logic OR of group 2 Keymap values

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags
#define SD_READONLY_FLAG    0x02000000 // Found @0xff413814, levent 0x20a IXUS125 100e
#define SD_READONLY_IDX     1
#define USB_MASK            0x40000000 // Found @0xff41384c, levent 0x202 IXUS125 100e
#define USB_IDX             2
#endif
