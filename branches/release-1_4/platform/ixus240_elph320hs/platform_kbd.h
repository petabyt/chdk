#ifndef PLATFORM_KBD_H
#define PLATFORM_KBD_H
// TEMP new keyboard code causes hangs for unknown reasons, see 
// http://chdk.setepontos.com/index.php?topic=9005.msg121780#msg121780
#define KBD_CUSTOM_ALL 1
/*
// plaform specific keyboard defines, see core/kbd_common.c for documentation
#define KEYS_MASK0         (0x00000000) //Logic OR of group 0 Keymap values
#define KEYS_MASK1         (0x2F000000) //Logic OR of group 1 Keymap values
#define KEYS_MASK2         (0x00000000) //Logic OR of group 2 Keymap values

#define SD_READONLY_FLAG    0x00008000 // Found @0xff5ac30c, levent 0x20a
#define SD_READONLY_IDX     0
#define USB_MASK            0x40000000 // Found @0xff5ac38c, levent 0x202
#define USB_IDX             2
*/

#endif
