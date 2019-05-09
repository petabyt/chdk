#ifndef PLATFORM_KBD_H
#define PLATFORM_KBD_H

#define KEYS_MASK0          0x0000890C
#define KEYS_MASK1          0x00000000
#define KEYS_MASK2          0x0000FEC0

// DryOS r58-> levent 0x000003xx
#define SD_READONLY_FLAG    0x01000000 //levent 0x0000030a, 0x01000000, index 2
#define SD_READONLY_IDX     2

#define USB_MASK            0x04000000 //levent 0x00000302, 0x04000000, index 2
#define USB_IDX             2

#define BATTCOVER_FLAG      0x02000000 //levent 0x00000305, 0x02000000, index 2
#define BATTCOVER_IDX       2

#endif
