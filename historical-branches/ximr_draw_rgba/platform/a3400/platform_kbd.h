#ifndef PLATFORM_KBD_H
#define PLATFORM_KBD_H
// plaform specific keyboard defines, see core/kbd_common.c for documentation
#define KEYS_MASK0         (0x00003000) //Logic OR of group 0 Keymap values
#define KEYS_MASK1         (0xBFF00000) //Logic OR of group 1 Keymap values
#define KEYS_MASK2         (0x00000000) //Logic OR of group 2 Keymap values

#define SD_READONLY_FLAG    0x00020000 // Found @0xffb10078, levent 0x20a
#define SD_READONLY_IDX     2
#define USB_MASK            0x00040000 // Found @0xffb10080, levent 0x202
#define USB_IDX             2
#define BATTCOVER_FLAG      0x00080000 // Found @0xffb2fddc, levent 0x205
#define BATTCOVER_IDX       2
#define ANALOG_AV_FLAG      0x00000200 // Found @0xffb2fd4c, levent 0x200 (non-inverted logic)
#define ANALOG_AV_IDX       0
#endif
