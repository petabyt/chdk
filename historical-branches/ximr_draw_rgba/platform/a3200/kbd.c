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
	// Order IS important. kbd_get_pressed_key will walk down this table  
	// and take the first matching mask. Notice that KEY_SHOOT_HALF is  
	// always pressed if KEY_SHOOT_FULL is. --MarcusSt
    { 0, KEY_PLAYBACK        ,0x00002000 }, // Found @0xffb5d4cc, levent 0x601
//    { 0, KEY_POWER           ,0x00004000 }, // Found @0xffb5d4d4, levent 0x600
    { 2, KEY_SHOOT_FULL      ,0x00003000 }, // Found @0xffb5d544, levent 0x01
    { 2, KEY_SHOOT_HALF      ,0x00001000 }, // Found @0xffb5d53c, levent 0x00
    { 2, KEY_SHOOT_FULL_ONLY ,0x00002000 }, // Found @0xffb5d544, levent 0x01
    { 2, KEY_FACE            ,0x00000040 }, //
    { 2, KEY_UP              ,0x00000001 }, // Found @0xffb5d4e4, levent 0x04
    { 2, KEY_DOWN            ,0x00000002 }, // Found @0xffb5d4ec, levent 0x05
    { 2, KEY_LEFT            ,0x00000004 }, // Found @0xffb5d4f4, levent 0x06
    { 2, KEY_RIGHT           ,0x00000008 }, // Found @0xffb5d4fc, levent 0x07
    { 2, KEY_SET             ,0x00000010 }, // Found @0xffb5d504, levent 0x08
    { 2, KEY_DISPLAY         ,0x00000020 }, // Found @0xffb5d50c, levent 0x0a
    { 2, KEY_MENU            ,0x00000080 }, // Found @0xffb5d51c, levent 0x09
    { 2, KEY_ZOOM_OUT        ,0x00004000 }, // Found @0xffb5d54c, levent 0x03
    { 2, KEY_ZOOM_IN         ,0x00008000 }, // Found @0xffb5d554, levent 0x02    
    { 0, 0, 0 }
};



extern long __attribute__((naked)) wrap_kbd_p1_f() {

    asm volatile(
        "STMFD	SP!, {R1-R7,LR} \n"
        "MOV	R5, #0 \n"
	//"BL	_kbd_read_keys \n"
	"BL	my_kbd_read_keys \n"	// patched
	"B	_kbd_p1_f_cont \n"
	);
	return 0; // shut up the compiler
}

// no stack manipulation needed here, since we create the task directly
void __attribute__((noinline)) mykbd_task() {
	while (physw_run) {
        _SleepTask(physw_sleep_delay);

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

void kbd_fetch_data(long *dst)
{
    _GetKbdState(dst);
    _kbd_read_keys_r2(dst);
}
