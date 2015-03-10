#ifndef PLATFORM_KBD_H
#define PLATFORM_KBD_H

#define KEYS_MASK0 (0x00000000)
// from original kbd.c code, no keymap keys are in group 1
// possible copy/paste error from a560
#define KEYS_MASK1 (0xc0000000)
#define KEYS_MASK2 (0x1FFF)

#define SD_READONLY_IDX 2
#define SD_READONLY_FLAG 0x20000

#define USB_IDX  2    
#define USB_MASK (0x40000)
#endif
