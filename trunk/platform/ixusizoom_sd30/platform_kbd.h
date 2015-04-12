#ifndef PLATFORM_KBD_H
#define PLATFORM_KBD_H
// plaform specific keyboard defines, see core/kbd_common.c for documentation
#define KEYS_MASK0 0
#define KEYS_MASK1 0
#define KEYS_MASK2 0x17FF

#define SD_READONLY_FLAG (0x20000)
#define SD_READONLY_IDX 2

//USB port is special: http://chdk.setepontos.com/index.php?topic=11723.msg114947#msg114947
// remote probably not useful on this camera, but USB status can be detected
#define USB_MASK 0x08000000 	
#define USB_IDX 1

#define USB_MMIO 0xc0220204
#endif
