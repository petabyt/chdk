#ifndef PLATFORM_KBD_H
#define PLATFORM_KBD_H
// plaform specific keyboard defines, see core/kbd_common.c for documentation
// non-standard key state update to handle inverted keys, etc
#define KBD_CUSTOM_UPDATE_KEY_STATE 1
#define KEYS_MASK0 (0x00020000)
#define KEYS_MASK1 (0x00000000)
#define KEYS_MASK2 (0x3E0003f0)
#define KEYS_INV2  (0x3E000000) //higher  1=pressed (MENU,UP,DOWN,LEFT) =>INTRODUCED
/*
the 4 button states residing in the upper half of physw_status[2] seem to be inverted
to handle these correctly, their value needs to be inverted:
- when reading from physw_status[2] to the state variables
- when writing to physw_status[2] from the state variables
KEYS_INV2 should be used for that
SD_READONLY_FLAG and USB_MASK are not affected by this
 
when idle, physw_status[2] looks like: ""
                         KEYS_MASK2 is "00101110000000000000001111110000"
*/
#define SD_READONLY_FLAG    0x00020000 // Found @0xffe9db68, levent 0x90a
#define SD_READONLY_IDX     2
#define USB_MASK            0x01000000 // Found @0xffe9db88, levent 0x902
#define USB_IDX             2
#endif
