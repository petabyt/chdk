#ifndef PLATFORM_KBD_H
#define PLATFORM_KBD_H
// plaform specific keyboard defines, see core/kbd_common.c for documentation

#define KEYS_MASK0 (0x0000000C)
#define KEYS_MASK1 (0x00000000)
#define KEYS_MASK2 (0x00000BFD)

#define SD_READONLY_FLAG (0x20000)  // SD-Card Lock Status (locked / unlocked)
#define SD_READONLY_IDX     2  
#define USB_MASK (0x80000)          // USB-Power (triggered around 3,5V)
#define USB_IDX             2 

#endif
