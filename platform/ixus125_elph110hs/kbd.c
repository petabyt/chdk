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
	// always pressed if KEY_SHOOT_FULL is.
    { 0, KEY_ZOOM_IN         ,0x00000008 }, // Found @0xff4137ac, levent 0x02
    { 0, KEY_ZOOM_OUT        ,0x00000004 }, // Found @0xff4137a4, levent 0x03
    { 0, KEY_SET             ,0x00000002 }, // Found @0xff41379c, levent 0x08
    { 0, KEY_MENU            ,0x00000001 }, // Found @0xff413794, levent 0x09
    { 0, KEY_DISPLAY         ,0x00000040 }, // VIDEO button is used as DISPLAY button
    { 0, KEY_VIDEO           ,0x00000040 }, // Found @0xff4137bc, levent 0x1a
    { 0, KEY_RIGHT           ,0x00000200 }, // Found @0xff4137cc, levent 0x07
    { 0, KEY_UP              ,0x00000100 }, // Found @0xff4137c4, levent 0x04
    { 0, KEY_LEFT            ,0x00000400 }, // Found @0xff4137d4, levent 0x06    
    { 0, KEY_DOWN            ,0x00000800 }, // Found @0xff4137dc, levent 0x05
    { 1, KEY_PLAYBACK        ,0x00800000 }, // Found @0xff413804, levent 0x101    
    { 1, KEY_SHOOT_FULL      ,0x00300000 }, // Found @0xff4137f4, levent 0x01
    { 1, KEY_SHOOT_FULL_ONLY ,0x00200000 }, // Found @0xff4137f4, levent 0x01
    { 1, KEY_SHOOT_HALF      ,0x00100000 }, // Found @0xff4137ec, levent 0x00
    { 0, 0, 0 }
};


long __attribute__((naked,noinline)) wrap_kbd_p1_f() {
	
	//ixus125 100d @0xFF01E89C
	asm volatile(
		"STMFD	SP!, {R1-R7,LR} \n"
		"MOV	R5, #0 \n"
		"BL		my_kbd_read_keys \n"	// patched
		"B		_kbd_p1_f_cont \n"
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
void kbd_fetch_data(long *dst) {
    _GetKbdState(dst);
    _kbd_read_keys_r2(dst);
}
