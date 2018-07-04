#ifndef PLATFORM_KBD_H
#define PLATFORM_KBD_H
// plaform specific keyboard defines, see core/kbd_common.c for documentation

#define KEYS_MASK0 0x00000000
#define KEYS_MASK1 0x00000000
#define KEYS_MASK2 0x77FE

#define SD_READONLY_FLAG    0x02000000 // Found @0xff4fbaf0, levent 0x20a
#define SD_READONLY_IDX     2
#define USB_MASK            0x10000000 // Found @0xff4fbb00, levent 0x202
#define USB_IDX             2
#define ANALOG_AV_FLAG      0x02000000 // Found @0xff4fba58, levent 0x200 (non-inverted logic)
#define ANALOG_AV_IDX       1

#endif
