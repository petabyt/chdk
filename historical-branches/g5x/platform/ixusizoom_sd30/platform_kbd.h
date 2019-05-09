#ifndef PLATFORM_KBD_H
#define PLATFORM_KBD_H
// plaform specific keyboard defines, see core/kbd_common.c for documentation
#define KEYS_MASK0 0
#define KEYS_MASK1 0
#define KEYS_MASK2 0x17FF

#define SD_READONLY_FLAG (0x20000)
#define SD_READONLY_IDX 2

/*
USB port is special: http://chdk.setepontos.com/index.php?topic=11723.msg114947#msg114947
To use USB remote with the proprietary CS-DC1 cradle you must either switch to record mode using
switch_mode_usb or using the following event proc calls
  call_event_proc'UI_RegistDebugEventProc'
  call_event_proc'UiEvnt_StartDisguiseCradleStatus'

Other cradle related bits in physw_status[1] from http://chdk.setepontos.com/index.php?topic=12382.msg122778#msg122778
inside cradle  0xZ0@9AF80
outside cradle 0xZ0@9FF80

The first 0 is the USB bit which becomes 8 upon USB plug-in.
Z and @ I put for values that fluctuate between two possible ones and seem unrelated. @: C/5   Z: 3/2
Unplugging the power plug changes A to B.
Plugging an earphone cable into the AV plug changes the 9 before the green A to an 8.
*/
#define USB_MASK 0x08000000 	
#define USB_IDX 1

#define USB_MMIO 0xc0220204
#endif
