#ifndef PLATFORM_KBD_H
#define PLATFORM_KBD_H
// plaform specific keyboard defines, see core/kbd_common.c for documentation

#define KEYS_MASK0 (0x80000000) //Logic OR of group 0 Keymap values
#define KEYS_MASK1 (0xF8800001) //Logic OR of group 1 Keymap values
#define KEYS_MASK2 (0x000030C9) //Logic OR of group 2 Keymap values

#define SD_READONLY_FLAG    0x02000000 // Found @0xffba4b8c, levent 0x20a
#define SD_READONLY_IDX     2
#define USB_MASK            0x10000000 // Found @0xffba4b9c, levent 0x202
#define USB_IDX             2
#define HDMI_HPD_FLAG       0x20000000
#define HDMI_HPD_IDX        0
#define ANALOG_AV_FLAG      0x00002000 // levent 0x200
#define ANALOG_AV_IDX       0

#endif
