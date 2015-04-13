#include "lolevel.h"
#include "platform.h"
#include "keyboard.h"
#include "kbd_common.h"

long kbd_new_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_prev_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_mod_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };

extern void _GetKbdState(long*);

int get_usb_bit() 
{
	long usb_physw[3];
	usb_physw[USB_IDX] = 0;
	_kbd_read_keys_r2(usb_physw);
	return(( usb_physw[USB_IDX] & USB_MASK)==USB_MASK) ; 
}

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
KeyMap keymap[] = {
    { 0, KEY_PLAYBACK        ,0x00000100 }, // Found @0xffea7a88, levent 0x601
//    { 0, KEY_POWER           ,0x00000200 }, // Found @0xffea7a94, levent 0x600
    { 0, KEY_MENU            ,0x00000400 }, // Found @0xffea7aa0, levent 0x09
    { 1, KEY_LEFT            ,0x08000000 }, // Found @0xffea7adc, levent 0x06
    { 1, KEY_ZOOM_OUT        ,0x10000000 }, // Found @0xffea7ae8, levent 0x03
    { 1, KEY_ZOOM_IN         ,0x20000000 }, // Found @0xffea7af4, levent 0x02
    { 2, KEY_SET             ,0x00000001 }, // Found @0xffea7b00, levent 0x08
    { 2, KEY_DOWN            ,0x00000002 }, // Found @0xffea7b0c, levent 0x05
    { 2, KEY_DISPLAY         ,0x00000008 }, // Found @0xffea7b18, levent 0x0a
    { 2, KEY_RIGHT           ,0x00000400 }, // Found @0xffea7b24, levent 0x07
    { 2, KEY_UP              ,0x00000800 }, // Found @0xffea7b30, levent 0x04
    { 2, KEY_SHOOT_FULL      ,0x00005000 }, // Found @0xffea7b3c, levent 0x01
    { 2, KEY_SHOOT_HALF      ,0x00004000 }, // Found @0xffea7b48, levent 0x00
    { 2, KEY_SHOOT_FULL_ONLY ,0x00001000 }, // Found @0xffea7b3c, levent 0x01
    { 0, 0, 0 }
};

long __attribute__((naked,noinline)) wrap_kbd_p1_f()
{
	asm volatile(
		"STMFD   SP!, {R1-R5,LR}\n"
		"MOV     R4, #0\n"
		"BL      my_kbd_read_keys\n"
		"B       _kbd_p1_f_cont\n"
	);
	return 0; // shut up the compiler
}

void __attribute__((noinline)) mykbd_task()
{
	while (physw_run){
        _SleepTask(10);

		if (wrap_kbd_p1_f() == 1){ // autorepeat ?
			_kbd_p2_f();
		}
	}
	_ExitTask();
}

void my_kbd_read_keys()
{
    kbd_update_key_state();

    _kbd_read_keys_r2(physw_status);

    kbd_update_physw_bits();
}


void kbd_fetch_data(long *dst)
{
    _GetKbdState(dst);
}
