#ifndef PLATFORM_KBD_H
#define PLATFORM_KBD_H
// plaform specific keyboard defines, see core/kbd_common.c for documentation

#define KEYS_MASK0 (0x00000000)
// KEYS_MASK1 is a variable, needed by the extra button hack
#define KEYS_MASK1 keys_mask1
#define KEYS_MASK2 (0x4EEF)

#define SD_READONLY_FLAG    0x00020000 // Found @0xffaeeb8c, levent 0x90a
#define SD_READONLY_IDX     2
#define USB_MASK            0x00080000 // Found @0xffaeeba4, levent 0x902
#define USB_IDX             2

extern int keys_mask1;
#endif
