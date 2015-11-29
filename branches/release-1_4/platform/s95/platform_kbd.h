#ifndef PLATFORM_KBD_H
#define PLATFORM_KBD_H
// plaform specific keyboard defines, see core/kbd_common.c for documentation

#define KEYS_MASK0 (0x00000000)
#define KEYS_MASK1 (0x0000FF30)
#define KEYS_MASK2 (0x00004B00)

#define SD_READONLY_FLAG (0x20000)  	// in physw_status[2]
#define SD_READONLY_IDX 2
#define USB_MASK (0x4000000)  			// in physw_status[2]
#define USB_IDX  2

#endif
