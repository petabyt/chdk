#ifndef PLATFORM_KBD_H
#define PLATFORM_KBD_H
// plaform specific keyboard defines, see core/kbd_common.c for documentation
#define KEYS_MASK0 (0x00000000)
#define KEYS_MASK1 (0x00000000)
#define KEYS_MASK2 (0x00000300|0x00000100|0x00000080|0x00000040|0x00000010|0x00000020|0x00000002|0x00000004|0x00000008|0x00000001|0x00000800)

#define SD_READONLY_FLAG (0x20000)
#define SD_READONLY_IDX 2

#define USB_MASK (0x100000)
#define USB_IDX  2
#endif
