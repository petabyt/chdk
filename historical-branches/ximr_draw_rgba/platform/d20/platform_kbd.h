#ifndef PLATFORM_KBD_H
#define PLATFORM_KBD_H
// plaform specific keyboard defines, see core/kbd_common.c for documentation
#define KEYS_MASK0         (0x00000000) //Logic OR of group 0 Keymap values
#define KEYS_MASK1         (0x00000000) //Logic OR of group 1 Keymap values
#define KEYS_MASK2         (0x000047FF) //Logic OR of group 2 Keymap values

#define SD_READONLY_FLAG    0x00020000 // Found @0xff3a2994, levent 0x20a
#define SD_READONLY_IDX     2
#define USB_MASK            0x04000000 // Found @0xff3a29bc, levent 0x202
#define USB_IDX             2
#endif
