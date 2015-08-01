#ifndef PLATFORM_KBD_H
#define PLATFORM_KBD_H
// plaform specific keyboard defines, see core/kbd_common.c for documentation

//#define KEYS_MASK0         (0x00008F42)
#define KEYS_MASK0 0xDF42 //Logic OR of group 0 Keymap values
#define KEYS_MASK1 0x0000 //Logic OR of group 1 Keymap values
#define KEYS_MASK2 0x0033 //Logic OR of group 2 Keymap values

#define SD_READONLY_FLAG    0x02000000 // Found @0xffbc0ba0, levent 0x20a
#define SD_READONLY_IDX     2
#define USB_MASK            0x10000000 // Found @0xffbc0bb0, levent 0x202
#define USB_IDX             2
#define BATTCOVER_FLAG      0x04000000 // Found @0xffbc0ba8, levent 0x205
#define BATTCOVER_IDX       2

#endif

