#ifndef PLATFORM_KBD_H
#define PLATFORM_KBD_H
// plaform specific keyboard defines, see core/kbd_common.c for documentation

#define KEYS_MASK0 0x30000000
#define KEYS_MASK1 0x00000000
#define KEYS_MASK2 0x00030330

// Micro SD, no read only bit
#define KBD_SKIP_READONLY_BIT
//#define SD_READONLY_IDX  
//#define SD_READONLY_FLAG 
// uses SD door for autoboot. SD door is different from battery door
#define SD_DOOR_OVERRIDE 1
#define SD_DOOR_FLAG    0x00080000 // SD card door switch
#define SD_DOOR_IDX     2

#define USB_MASK 0x10000000
#define USB_IDX  2

// simulate video button with levents
#define KBD_SIMULATE_VIDEO_KEY 1

#endif
