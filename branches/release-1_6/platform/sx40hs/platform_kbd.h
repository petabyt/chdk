#ifndef PLATFORM_KBD_H
#define PLATFORM_KBD_H
// plaform specific keyboard defines, see core/kbd_common.c for documentation

#define KEYS_MASK0          0x00CFFDE0
#define KEYS_MASK1          0x00000000
#define KEYS_MASK2          0x0000C000

#define SD_READONLY_FLAG    0x00000002 // Found @0xff434b6c, levent 0x20a
#define SD_READONLY_IDX     1

#define USB_MASK            0x40000000 // Found @0xff434be4, levent 0x202
#define USB_IDX             2

#define BATTCOVER_FLAG      0x00002000 // Found @0xff434b9c, levent 0x205
#define BATTCOVER_IDX       2

#define CAM_HAS_JOGDIAL     1

#endif
