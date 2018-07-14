#ifndef PLATFORM_KBD_H
#define PLATFORM_KBD_H
// plaform specific keyboard defines, see core/kbd_common.c for documentation
#define KEYS_MASK0 (0x00000001)
#define KEYS_MASK1 (0xB5000000)
#define KEYS_MASK2 (0x0000003F)

#define SD_READONLY_FLAG (0x20000)
#define SD_READONLY_IDX     2

#define USB_MASK (0x4000000)
#define USB_IDX             2

#define HDMI_HPD_FLAG       0x00400000
#define HDMI_HPD_IDX        1

#endif
