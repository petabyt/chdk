#ifndef PLATFORM_KBD_H
#define PLATFORM_KBD_H
// plaform specific keyboard defines, see core/kbd_common.c for documentation

#define KEYS_MASK0 0x0000DF42 //Logic OR of group 0 Keymap values KEY_POWER is not included,comment out this in kbd.c
#define KEYS_MASK1 0x0000 //Logic OR of group 1 Keymap values
#define KEYS_MASK2 0x00000033 //Logic OR of group 2 Keymap values 0x00000036 

#define SD_READONLY_FLAG    0x02000000 // Found @0xFFBE3A2C, levent 0x30a
#define SD_READONLY_IDX     2
#define USB_MASK            0x10000000 // Found @0xFFBE3A3C, levent 0x302
#define USB_IDX             2
#define BATTCOVER_FLAG      0x04000000 // Found @0xFFBE3A34, levent 0x305
#define BATTCOVER_IDX       2
#define ANALOG_AV_FLAG      0x00002000 // Found @0xffbe39dc, levent 0x300 (non-inverted logic)
#define ANALOG_AV_IDX       0

#endif

