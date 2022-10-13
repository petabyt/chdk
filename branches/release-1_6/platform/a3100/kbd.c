#include "lolevel.h"
#include "platform.h"
#include "keyboard.h"
#include "kbd_common.h"

long kbd_new_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_prev_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_mod_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };

KeyMap keymap[] = {
//	{ grp,       hackkey, canonkey  }
    { 1, KEY_PLAYBACK        ,0x20000000 }, // Found @0xffad9820, levent 0x601
    { 2, KEY_FACE			, 0x00000800 }, // Face Key
    { 2, KEY_DISPLAY         ,0x00000400 }, // Found @0xffad98bc, levent 0x0a
    { 2, KEY_SHOOT_FULL      ,0x00000003 }, // Found @0xffad9850, levent 0x01
    { 2, KEY_SHOOT_HALF      ,0x00000001 }, // Found @0xffad9844, levent 0x00
    { 2, KEY_SHOOT_FULL_ONLY ,0x00000002 }, // Found @0xffad9850, levent 0x01
    { 2, KEY_ZOOM_IN         ,0x00000004 }, // Found @0xffad985c, levent 0x02
    { 2, KEY_ZOOM_OUT        ,0x00000008 }, // Found @0xffad9868, levent 0x03
    { 2, KEY_UP              ,0x00000010 }, // Found @0xffad9874, levent 0x04
    { 2, KEY_DOWN            ,0x00000020 }, // Found @0xffad9880, levent 0x05
    { 2, KEY_RIGHT           ,0x00000040 }, // Found @0xffad988c, levent 0x07
    { 2, KEY_LEFT            ,0x00000080 }, // Found @0xffad9898, levent 0x06
    { 2, KEY_SET             ,0x00000100 }, // Found @0xffad98a4, levent 0x08
    { 2, KEY_MENU            ,0x00000200 }, // Found @0xffad98b0, levent 0x09
	{ 0, 0, 0 }
};

extern void _GetKbdState(long *dst);

int get_usb_bit() 
{
	long usb_physw[3];
	usb_physw[USB_IDX] = 0;
	_kbd_read_keys_r2(usb_physw);
	return(( usb_physw[USB_IDX] & USB_MASK)==USB_MASK) ; 
}





long __attribute__((naked)) wrap_kbd_p1_f();


void __attribute__((noinline)) mykbd_task()
{
	/* Initialize our own kbd_new_state[] array with the
	   current physical status. (inspired by the S90 port)
	   */
	kbd_new_state[0] = physw_status[0];
	kbd_new_state[1] = physw_status[1];
	kbd_new_state[2] = physw_status[2];
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
			"STMFD   SP!, {R1-R5,LR}\n"
			"MOV     R4, #0\n"
			//"BL      _kbd_read_keys\n"       // replaces kbd_fetch_data()
			"BL      my_kbd_read_keys\n"     // +
			"B       _kbd_p1_f_cont\n"       // continue
	);
	
	return 0; // shut up the compiler
}


void my_kbd_read_keys()
{
    kbd_update_key_state();
    kbd_update_physw_bits();
}

void kbd_fetch_data(long *dst)
{
    _kbd_pwr_on();
    _GetKbdState(dst);
    _kbd_read_keys_r2(dst);
    _kbd_pwr_off();
}
