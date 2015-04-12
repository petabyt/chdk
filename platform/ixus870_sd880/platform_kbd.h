#ifndef PLATFORM_KBD_H
#define PLATFORM_KBD_H
// plaform specific keyboard defines, see core/kbd_common.c for documentation
// each mask should be the xor of all key values in the corresponding group
#define KEYS_MASK0 (0x00000000)
#define KEYS_MASK1 (0x00000000)
#define KEYS_MASK2 (0x00000FFF)

#define SD_READONLY_FLAG (0x20000)
#define SD_READONLY_IDX 2

#define USB_MASK (0x40000)
#define USB_IDX  2

#endif
