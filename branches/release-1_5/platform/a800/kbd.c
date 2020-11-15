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

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
KeyMap keymap[] = {
    { 0, KEY_PLAYBACK        ,0x00020000 }, // Playback => ALT Mode
    { 2, KEY_ZOOM_OUT        ,0x00000040 }, // Found @0xffe9db40, levent 0x03
    { 2, KEY_ZOOM_IN         ,0x00000080 }, // Found @0xffe9db48, levent 0x02
    { 2, KEY_SET             ,0x00000100 }, // Found @0xffe9db50, levent 0x08
    { 2, KEY_RIGHT           ,0x00000200 }, // Found @0xffe9db58, levent 0x07
    { 2, KEY_UP              ,0x02000000 }, // Found @0xffe9db90, levent 0x04
    { 2, KEY_DOWN            ,0x04000000 }, // Found @0xffe9db98, levent 0x05
    { 2, KEY_LEFT            ,0x08000000 }, // Found @0xffe9dba0, levent 0x06
    { 2, KEY_MENU            ,0x20000000 }, // Found @0xffe9dbb0, levent 0x09
    { 2, KEY_SHOOT_FULL      ,0x00000030 }, // Found @0xffe9db38, levent 0x01
    { 2, KEY_SHOOT_FULL_ONLY ,0x00000020 }, // Found @0xffe9db38, levent 0x01
    { 2, KEY_SHOOT_HALF      ,0x00000010 }, // Found @0xffe9db30, levent 0x00
    { 2, KEY_MODE            ,0x10000000 }, // OSD
    { 0, 0, 0 }
};


long __attribute__((naked)) wrap_kbd_p1_f();


void __attribute__((noinline)) mykbd_task()
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
	_ExitTask();
}


long __attribute__((naked,noinline)) wrap_kbd_p1_f()
{
	asm volatile(
			"STMFD   SP!, {R1-R7,LR}\n"	// anterior "STMFD   SP!, {R1-R7,LR}\n"
			"MOV     R5, #0\n" // anterior "MOV     R4, #0\n"
			//"BL      _kbd_read_keys\n"       // replaces kbd_fetch_data()
			"BL      my_kbd_read_keys\n"     // +
			"B       _kbd_p1_f_cont\n"       // continue
	);
	
	return 0; // shut up the compiler
}


void my_kbd_read_keys()
{
	kbd_prev_state[0] = kbd_new_state[0];
	//kbd_prev_state[1] = kbd_new_state[1];
	kbd_prev_state[2] = kbd_new_state[2];
	
    extern void _kbd_read_keys(void);
    _kbd_read_keys();
	
	kbd_new_state[0] = physw_status[0];
	kbd_new_state[1] = physw_status[1];
	kbd_new_state[2] = physw_status[2] ^ KEYS_INV2;

	if (kbd_process() == 0){//core\kbd.c =>pode simular outras teclas (kbd_key_press/release)
		// leave it alone...
	} else {
        // override keys
        physw_status[0] = (kbd_new_state[0] | KEYS_MASK0) & (~KEYS_MASK0 | kbd_mod_state[0]);
        //physw_status[1] = (kbd_new_state[1] | KEYS_MASK1) & (~KEYS_MASK1 | kbd_mod_state[1]);
        physw_status[2] = ((kbd_new_state[2] | KEYS_MASK2) & (~KEYS_MASK2 | kbd_mod_state[2])) ^ KEYS_INV2;
	}
    // usb and SD read-only are standard
    kbd_update_physw_bits();
}
