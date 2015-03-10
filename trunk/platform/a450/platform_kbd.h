#ifndef PLATFORM_KBD_H
#define PLATFORM_KBD_H

#define KEYS_MASK0 0x00000000
#define KEYS_MASK1 0x00000000

// copied from old code, key map doesn't use all bits
#define KEYS_MASK2 0x00001fff

#define SD_READONLY_IDX 2
#define SD_READONLY_FLAG 0x20000

#define USB_MASK 0x40000
#define USB_IDX 2

#endif
