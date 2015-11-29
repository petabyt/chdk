#include "lolevel.h"
#include "platform.h"
#include "keyboard.h"
#include "kbd_common.h"

// the MODE dial is in Gray code
// the following are informational, not used
/*
#define DIAL_Movie	(0x00000600)
#define DIAL_Discreet	(0x00000200)
#define DIAL_FishEye	(0x00000000)
#define DIAL_Scene	(0x00000100)
#define DIAL_Easy	(0x00000300)
#define DIAL_Auto	(0x00000700)
#define DIAL_Live	(0x00000500)
#define DIAL_Program	(0x00000400)
*/

long kbd_new_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_prev_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_mod_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };

extern void _GetKbdState(long*);


//#define LED_AF 0xC02200F4

int get_usb_bit() 
{
	long usb_physw[3];
	usb_physw[USB_IDX] = 0;
	_kbd_read_keys_r2(usb_physw);
	return(( usb_physw[USB_IDX] & USB_MASK)==USB_MASK) ; 
}

KeyMap keymap[] = {
    { 0, KEY_PLAYBACK        ,0x00002000 }, 
    { 2, KEY_SHOOT_FULL      ,0x00003000 }, // Found @0xffb5dc9c, levent 0x01
    { 2, KEY_SHOOT_HALF      ,0x00001000 }, // Found @0xffb5dc94, levent 0x00
    { 2, KEY_SHOOT_FULL_ONLY ,0x00002000 }, // Found @0xffb5dc9c, levent 0x01
    { 2, KEY_FACE            ,0x00000040 }, // 
    { 2, KEY_UP              ,0x00000001 }, // Found @0xffb5dc3c, levent 0x04
    { 2, KEY_DOWN            ,0x00000002 }, // Found @0xffb5dc44, levent 0x05
    { 2, KEY_LEFT            ,0x00000004 }, // Found @0xffb5dc4c, levent 0x06
    { 2, KEY_RIGHT           ,0x00000008 }, // Found @0xffb5dc54, levent 0x07
    { 2, KEY_SET             ,0x00000010 }, // Found @0xffb5dc5c, levent 0x08
    { 2, KEY_DISPLAY         ,0x00000020 }, // Found @0xffb5dc64, levent 0x0a
    { 2, KEY_MENU            ,0x00000080 }, // Found @0xffb5dc74, levent 0x09
    { 2, KEY_ZOOM_OUT        ,0x00004000 }, // Found @0xffb5dca4, levent 0x03
    { 2, KEY_ZOOM_IN         ,0x00008000 }, // Found @0xffb5dcac, levent 0x02
    { 0, 0, 0 }
};



extern long __attribute__((naked)) wrap_kbd_p1_f() {
	asm volatile(
		"STMFD	SP!, {R1-R7,LR} \n"
		"MOV	R5, #0 \n"
		//"BL		_kbd_read_keys \n"
		"BL		my_kbd_read_keys \n"	// pacthed
		"B		_kbd_p1_f_cont \n"
	);
	return 0; // shut up the compiler
}
	
	
// no stack manipulation needed here, since we create the task directly
void __attribute__((noinline)) mykbd_task() {
	while (physw_run) {
        _SleepTask(physw_sleep_delay); //  @FF834160 + FF834168

		if (wrap_kbd_p1_f() == 1) {   // autorepeat ?
        	_kbd_p2_f();
        }
    }
	_ExitTask();
}

void my_kbd_read_keys() {
    kbd_update_key_state();
    kbd_update_physw_bits();
}

void kbd_fetch_data(long *dst) {
    _GetKbdState(dst);
    _kbd_read_keys_r2(dst);
}
