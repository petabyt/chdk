#ifndef PLATFORM_KBD_H
#define PLATFORM_KBD_H
// plaform specific keyboard defines, see core/kbd_common.c for documentation
// platform code handles reading, updating physw
#define KBD_CUSTOM_UPDATE_KEY_STATE 1
#define KBD_CUSTOM_UPDATE_PHYSW_BITS 1
#define KBD_USB_OVERRIDE_FUNC 1
#define KEYS_MASK0 0
#define KEYS_MASK1 0x2FFE
#define KEYS_MASK2 0

// not used, copied from original kbd.c code
//#define SD_READONLY_FLAG (0x20000)

#define USB_MASK 0x40

#define USB_MMIO 0xc0220204
#endif
