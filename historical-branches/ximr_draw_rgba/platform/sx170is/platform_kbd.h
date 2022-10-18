#ifndef PLATFORM_KBD_H
#define PLATFORM_KBD_H
// plaform specific keyboard defines, see core/kbd_common.c for documentation
#define KEYS_MASK0 (0x80000000) //Logic OR of group 0 Keymap values
#define KEYS_MASK1 (0xF8800001) //Logic OR of group 1 Keymap values
#define KEYS_MASK2 (0x000030C9) //Logic OR of group 2 Keymap values

#define SD_READONLY_FLAG    0x02000000 // Found @0xffbacbf8, levent 0x20a OK
#define SD_READONLY_IDX     2
#define USB_MASK            0x10000000 // Found @0xffbacc08, levent 0x202 OK
#define USB_IDX             2
#endif
