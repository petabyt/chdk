#ifndef PLATFORM_KBD_H
#define PLATFORM_KBD_H

#define KEYS_MASK0          0x0000890C
#define KEYS_MASK1          0x00000000
#define KEYS_MASK2          0x0000FEC0

#define SD_READONLY_FLAG    0x01000000 // physw_bits.txt, levent 0x30a 0xFF5F76CC
#define SD_READONLY_IDX     2

#define USB_MASK            0x04000000 // physw_bits.txt, levent 0x302
#define USB_IDX             2

#define BATTCOVER_FLAG      0x02000000 // physw_bits.txt, levent 0x305
#define BATTCOVER_IDX       2

#endif
