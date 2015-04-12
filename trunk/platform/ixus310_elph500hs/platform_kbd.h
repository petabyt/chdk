#ifndef PLATFORM_KBD_H
#define PLATFORM_KBD_H
// plaform specific keyboard defines, see core/kbd_common.c for documentation

#define KEYS_MASK0              0x00000000
#define KEYS_MASK1              0x00009000
#define KEYS_MASK2              0x00000a00

#define SD_READONLY_FLAG        0x00020000
#define SD_READONLY_IDX         2

#define USB_MASK                0x04000000
#define USB_IDX                 2

#define CAM_TOUCHSCREEN_SYMBOLS 1   // Add 'sc' entry in the KeyMap struct for scale factor when displaying
                                    // symbols in touchscreen buttons instead of text (used for up/down/left/right)
#define KBD_SIMULATE_VIDEO_KEY  1

#endif
