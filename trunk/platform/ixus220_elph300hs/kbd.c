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

KeyMap keymap[] = {
	/* tiny bug: key order matters. see kbd_get_pressed_key() */

    { 2, KEY_SHOOT_FULL      ,0x00000300 }, // Found @0xffba2b80, levent 0x01
    { 2, KEY_SHOOT_FULL_ONLY ,0x00000200 }, // Found @0xffba2b80, levent 0x01
    { 2, KEY_SHOOT_HALF      ,0x00000100 }, // Found @0xffba2b78, levent 0x00
    { 2, KEY_MENU            ,0x00000001 }, // Found @0xffba2b38, levent 0x09
    { 2, KEY_SET             ,0x00000002 }, // Found @0xffba2b40, levent 0x08
    { 2, KEY_ZOOM_IN         ,0x00000004 }, // Found @0xffba2b48, levent 0x02
    { 2, KEY_ZOOM_OUT        ,0x00000008 }, // Found @0xffba2b50, levent 0x03
    { 2, KEY_LEFT            ,0x00000010 }, // Found @0xffba2b58, levent 0x06
    { 2, KEY_RIGHT           ,0x00000020 }, // Found @0xffba2b60, levent 0x07
    { 2, KEY_DOWN            ,0x00000040 }, // Found @0xffba2b68, levent 0x05
    { 2, KEY_UP              ,0x00000080 }, // Found @0xffba2b70, levent 0x04
	{ 2, KEY_VIDEO		     ,0x00004000 },
	{ 2, KEY_PLAYBACK        ,0x00000800 },
    { 0, 0, 0 }
};


long __attribute__((naked)) wrap_kbd_p1_f() ;

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


long __attribute__((naked,noinline)) wrap_kbd_p1_f()
{
	asm volatile(
        "STMFD   SP!, {R1-R7,LR}\n"
        "MOV     R5, #0\n"	
		"BL      my_kbd_read_keys\n"

		"B       _kbd_p1_f_cont\n" // address is automatically taken from stubs_entry.S
	);

	 return 0; // shut up the compiler
}

void kbd_fetch_data(long *dst)
{
    _GetKbdState(dst);
    _kbd_read_keys_r2(dst);
}

void my_kbd_read_keys()
{
    kbd_update_key_state();
    kbd_update_physw_bits();
}


