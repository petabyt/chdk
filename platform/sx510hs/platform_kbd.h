#ifndef PLATFORM_KBD_H
#define PLATFORM_KBD_H
// plaform specific keyboard defines, see core/kbd_common.c for documentation
// override key and feather bits to avoid feather osd messing up chdk display in ALT mode
#define KEYS_MASK0 (0x000FBD40) //Logic OR of group 0 Keymap values
#define KEYS_MASK1 (0x00000000) //Logic OR of group 1 Keymap values
#define KEYS_MASK2 (0x00000608) //Logic OR of group 2 Keymap values

#define SD_READONLY_FLAG    0x02000000 // Found @0xff568748, levent 0x20a  sx510 101a
#define SD_READONLY_IDX     2
#define USB_MASK            0x10000000 // Found @0xff568758, levent 0x202  sx510 101a
#define USB_IDX             2

#endif
