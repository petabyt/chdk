#ifndef PLATFORM_KBD_H
#define PLATFORM_KBD_H
// plaform specific keyboard defines, see core/kbd_common.c for documentation
#define KEYS_MASK0 (0x00802182)     // physw_status[0]
// override key and feather bits to avoid feather osd messing up chdk display in ALT mode
// manual confirms this camera has touch wheel feature
#define KEYS_MASK1 (0x000FFC05)
#define KEYS_MASK2 (0x00000000)  // physw_status[2]

#define SD_READONLY_FLAG    0x00020000 // Found @0xffb65924, levent 0x90a
#define SD_READONLY_IDX     2

#define USB_MASK            0x00080000 // Found @0xffb6592c, levent 0x902
#define USB_IDX             2
#endif
