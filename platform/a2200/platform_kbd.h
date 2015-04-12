#ifndef PLATFORM_KBD_H
#define PLATFORM_KBD_H
// plaform specific keyboard defines, see core/kbd_common.c for documentation

#define KEYS_MASK0			(0x05000000|0x00800000)
#define KEYS_MASK1			(0x00000001|0x00000002|0x00000003|0x00001000|0x00002000|0x00004000|0x00008000|0x00010000|0x00020000|0x00040000|0x00080000)
#define KEYS_MASK2			(0x00000000)

#define SD_READONLY_FLAG	0x00020000 // Found @0xffb56264 (1.00B), levent 0x90a
#define SD_READONLY_IDX		2

#define USB_MASK			0x04000000 // Found @0xffb5628c (1.00B), levent 0x902
#define USB_IDX				2
#endif
