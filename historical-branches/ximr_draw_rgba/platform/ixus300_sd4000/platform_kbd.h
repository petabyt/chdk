#ifndef PLATFORM_KBD_H
#define PLATFORM_KBD_H
// plaform specific keyboard defines, see core/kbd_common.c for documentation
#define KEYS_MASK0 (0x0000490F)     // physw_status[0]
// override key and feather bits to avoid feather osd messing up chdk display in ALT mode
#define KEYS_MASK1 (0x00000FF0)     // physw_status[1], override 0xF0 (keys) + 0xF00 (feather)
#define KEYS_MASK2 (0x00000000)     // physw_status[2]

#define SD_READONLY_FLAG    (0x00020000)    // SD-Card Lock Status (locked / unlocked)
#define SD_READONLY_IDX     2

#define USB_MASK            (0x00080000)    // USB-Power (triggered around 3,5V)
#define USB_IDX  2
#endif
