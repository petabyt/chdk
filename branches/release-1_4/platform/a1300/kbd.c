#include "lolevel.h"
#include "platform.h"
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
    { 0, KEY_ZOOM_IN         ,0x00002000 }, // Found @0xffb10008, levent 0x02
    { 0, KEY_ZOOM_OUT        ,0x00001000 }, // Found @0xffb10000, levent 0x03
    { 1, KEY_SHOOT_FULL      ,0x00300000 }, // Found @0xffb10018, levent 0x01
    { 1, KEY_SHOOT_FULL_ONLY ,0x00200000 }, // Found @0xffb10018, levent 0x01
    { 1, KEY_SHOOT_HALF      ,0x00100000 }, // Found @0xffb10010, levent 0x00
    { 1, KEY_SET             ,0x08000000 }, // Found @0xffb10048, levent 0x08
    { 1, KEY_MENU            ,0x04000000 }, // Found @0xffb10040, levent 0x09
    { 1, KEY_LEFT            ,0x02000000 }, // Found @0xffb10038, levent 0x06
    { 1, KEY_RIGHT           ,0x01000000 }, // Found @0xffb10030, levent 0x07
    { 1, KEY_DOWN            ,0x00800000 }, // Found @0xffb10028, levent 0x05
    { 1, KEY_UP              ,0x00400000 }, // Found @0xffb10020, levent 0x04
    { 1, KEY_PLAYBACK        ,0x80000000 }, // Found @0xffb10068, levent 0x101
//    { 1, KEY_POWER           ,0x40000000 }, // Found @0xffb10060, levent 0x100
    { 1, KEY_HELP            ,0x20000000 }, // Found @0xffb10058, levent 0x14
    { 1, KEY_DISPLAY         ,0x10000000 }, // VIDEO button is used as DISPLAY button
    { 1, KEY_VIDEO           ,0x10000000 }, // Found @0xffb10050, levent 0x1a
    { 0, 0, 0 }
};


long __attribute__((naked,noinline)) wrap_kbd_p1_f() {
	
	//a810 @0xFF82D9BC
	asm volatile(
		"STMFD	SP!, {R1-R7,LR} \n"
		"MOV	R5, #0 \n"
		"BL		my_kbd_read_keys \n"	// pached
		"B		_kbd_p1_f_cont \n"
	);
	
	return 0; // shut up the compiler
}

void __attribute__((noinline)) mykbd_task() {
	while (physw_run) {
		_SleepTask(*((int*)(0x1BF8 + 0x8))); //   @FF82D51C + FF82D524  a810 100b
		if (wrap_kbd_p1_f() == 1) {   // autorepeat ?
			_kbd_p2_f();
		}
	}

	_ExitTask();
}

void my_kbd_read_keys() {
    kbd_update_key_state();
    kbd_update_physw_bits();

    extern void state_check_for_movie_af();
    state_check_for_movie_af(); // hack to prevent the "invisible af lock" caused by the movie af scan hack
}

void kbd_fetch_data(long *dst)
{
    _GetKbdState(dst);
    _kbd_read_keys_r2(dst);
}
