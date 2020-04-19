#ifndef PLATFORM_KBD_H
#define PLATFORM_KBD_H

// TODO:
// plaform specific keyboard defines, see core/kbd_common.c for documentation
#define KEYS_MASK0 (0x005F8000)
#define KEYS_MASK1 (0x00000000)
#define KEYS_MASK2 (0x00003E60)

#define SD_READONLY_FLAG    0x00000020 // Found @0xe05df0f8, levent 0x30a
#define SD_READONLY_IDX     1
#define USB_MASK            0x00400000 // Found @0xe05df1b0, levent 0x302
#define USB_IDX             2
#define BATTCOVER_FLAG      0x00200000 // Found @0xe05df1a8, levent 0x305
#define BATTCOVER_IDX       2

// TODO:
#define CAM_HAS_JOGDIAL     1

#endif
