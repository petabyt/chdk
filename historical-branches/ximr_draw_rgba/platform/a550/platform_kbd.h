#ifndef PLATFORM_KBD_H
#define PLATFORM_KBD_H
// plaform specific keyboard defines, see core/kbd_common.c for documentation

#define KEYS_MASK0 (0x00000000)
// original kbd.c code used 0xc0000000 for MASK1. This caused shooting mode to change when entering alt mode
// possible copy/paste error from a560
#define KEYS_MASK1 (0x00000000)
// note bit 0x800 is not in key map, but camera reportedly doesn't boot if omitted
#define KEYS_MASK2 (0x1FFF)

#define SD_READONLY_IDX 2
#define SD_READONLY_FLAG 0x20000

#define USB_IDX  2    
#define USB_MASK (0x40000)
#endif
