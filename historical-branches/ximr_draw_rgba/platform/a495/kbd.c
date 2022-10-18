#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "conf.h"
#include "keyboard.h"
#include "kbd_common.h"

long kbd_new_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_prev_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_mod_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };

int get_usb_bit() 
{
	long usb_physw[3];
	usb_physw[USB_IDX] = 0;
	_kbd_read_keys_r2(usb_physw);
	return(( usb_physw[USB_IDX] & USB_MASK)==USB_MASK) ; 
}

KeyMap keymap[] = {
    /* tiny bug: key order matters. see kbd_get_pressed_key()
    * for example
    */
//    { 0, KEY_POWER           ,0x00800000 }, // Found @0xffe84ed4, levent 0x600
    { 0, KEY_PLAYBACK        ,0x00020000 }, // Found @0xffe84ebc, levent 0x601
    { 2, KEY_MENU            ,0x01000000 }, // Found @0xffe84f88, levent 0x09 (uses inverted logic in physw_status)
    { 2, KEY_MODE            ,0x00800000 }, // mode select                    (uses inverted logic in physw_status)
    { 2, KEY_LEFT            ,0x00400000 }, // Found @0xffe84f70, levent 0x06 (uses inverted logic in physw_status)
    { 2, KEY_DOWN            ,0x00200000 }, // Found @0xffe84f64, levent 0x05 (uses inverted logic in physw_status)
    { 2, KEY_UP              ,0x00100000 }, // Found @0xffe84f58, levent 0x04 (uses inverted logic in physw_status)
    { 2, KEY_SET             ,0x00000100 }, // Found @0xffe84f1c, levent 0x08
    { 2, KEY_ZOOM_IN         ,0x00000080 }, // Found @0xffe84f10, levent 0x02
    { 2, KEY_ZOOM_OUT        ,0x00000040 }, // Found @0xffe84f04, levent 0x03
    { 2, KEY_SHOOT_FULL      ,0x00000030 }, // Found @0xffe84ef8, levent 0x01
    { 2, KEY_SHOOT_FULL_ONLY ,0x00000020 }, // Found @0xffe84ef8, levent 0x01
    { 2, KEY_SHOOT_HALF      ,0x00000010 }, // Found @0xffe84eec, levent 0x00
    { 2, KEY_RIGHT           ,0x00000004 }, // Found @0xffe84ee0, levent 0x07
    { 0, 0, 0 }
};


long __attribute__((naked)) wrap_kbd_p1_f() ;


static void __attribute__((noinline)) mykbd_task_proceed()
{
	/* Initialize our own kbd_new_state[] array with the
	   current physical status. (inspired by the S90 port)
	   */
	kbd_new_state[0] = physw_status[0];
	kbd_new_state[1] = physw_status[1];
	kbd_new_state[2] = physw_status[2] ^ KEYS_INV2;
	while (physw_run){
		_SleepTask(physw_sleep_delay);
		
		if (wrap_kbd_p1_f() == 1){ // autorepeat ?
			_kbd_p2_f();
		}
	}
}

// no stack manipulation needed here, since we create the task directly
void __attribute__((naked,noinline)) mykbd_task()
{
	mykbd_task_proceed();
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
    // TODO currently does not use common kbd_update_key_state, because read into physw and need to xor
	kbd_prev_state[0] = kbd_new_state[0];
	kbd_prev_state[1] = kbd_new_state[1];
	kbd_prev_state[2] = kbd_new_state[2];
	
    extern void _kbd_read_keys(void);
    _kbd_read_keys();
	
	//_platformsub_kbd_fetch_data(kbd_new_state);
	kbd_new_state[0] = physw_status[0];
	kbd_new_state[1] = physw_status[1];
	kbd_new_state[2] = physw_status[2] ^ KEYS_INV2;
	
	if (kbd_process() == 0){
		// leave it alone...
	} else {
        // override keys
        physw_status[0] = (kbd_new_state[0] | KEYS_MASK0) & (~KEYS_MASK0 | kbd_mod_state[0]);
        physw_status[1] = (kbd_new_state[1] | KEYS_MASK1) & (~KEYS_MASK1 | kbd_mod_state[1]);
        physw_status[2] = ((kbd_new_state[2] | KEYS_MASK2) & (~KEYS_MASK2 | kbd_mod_state[2])) ^ KEYS_INV2;
	}
	
    // usb and SD read-only are standard
    kbd_update_physw_bits();
}
