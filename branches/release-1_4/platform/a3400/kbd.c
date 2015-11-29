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
    { 0, KEY_ZOOM_IN         ,0x00002000 }, // Found @0xffb2fd64, levent 0x02
    { 0, KEY_ZOOM_OUT        ,0x00001000 }, // Found @0xffb2fd5c, levent 0x03
    { 1, KEY_DOWN            ,0x00800000 }, // Found @0xffb2fd84, levent 0x05
    { 1, KEY_UP              ,0x00400000 }, // Found @0xffb2fd7c, levent 0x04
    { 1, KEY_SHOOT_FULL      ,0x00300000 }, // Found @0xffb2fd74, levent 0x01
    { 1, KEY_SHOOT_FULL_ONLY ,0x00200000 }, // Found @0xffb2fd74, levent 0x01
    { 1, KEY_SHOOT_HALF      ,0x00100000 }, // Found @0xffb2fd6c, levent 0x00
    { 1, KEY_SET             ,0x08000000 }, // Found @0xffb2fda4, levent 0x08
    { 1, KEY_MENU            ,0x04000000 }, // Found @0xffb2fd9c, levent 0x09
    { 1, KEY_LEFT            ,0x02000000 }, // Found @0xffb2fd94, levent 0x06
    { 1, KEY_RIGHT           ,0x01000000 }, // Found @0xffb2fd8c, levent 0x07
    { 1, KEY_PLAYBACK        ,0x80000000 }, // Found @0xffb2fdc4, levent 0x101
//    { 1, KEY_POWER           ,0x40000000 }, // Found @0xffb2fdbc, levent 0x100
    { 1, KEY_HELP            ,0x20000000 }, // Found @0xffb2fdb4, levent 0x14
    { 1, KEY_VIDEO           ,0x10000000 }, // Found @0xffb2fdac, levent 0x1a
    { 0, 0, 0 }
};


long __attribute__((naked,noinline)) wrap_kbd_p1_f() {
	asm volatile(
		"STMFD	SP!, {R1-R7,LR} \n"
		"MOV	R5, #0 \n"
		"BL		my_kbd_read_keys \n"	// patched
		"B		_kbd_p1_f_cont \n"
	);
	
	return 0; // shut up the compiler
}

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

    extern void state_check_for_movie_af();
    state_check_for_movie_af(); // hack to prevent the "invisible af lock" caused by the movie af scan hack
}

void kbd_fetch_data(long *dst)
{
    _GetKbdState(dst);
    _kbd_read_keys_r2(dst);
}

#if 0
// very basic touch screen support
// since this camera has a full set of physical buttons, full CHDK touch screen support is not needed
// the code here (and in boot.c) is currently disabled, since the only use is to prevent passing touch events
// to the Canon fw
// could be used to drive a virtual keyboard, if one ever gets implemented
// 0xc0220200 bit11: 1 when idle, 0 when "heavy" touch, bit7: 1 when idle, 0 when "soft" touch, anywhere on screen

static unsigned short touchx = 0, touchy = 0;
static unsigned int touchcnt = 0;

void get_touch_data(unsigned short *x, unsigned short *y, unsigned int *cnt)
{
    *x=touchx;
    *y=touchy;
    *cnt=touchcnt;
}

// Called from hooked touch panel task (boot.c)
// Return 0 to allow touch event to pass onto firmware, 1 to block event from firmware.
int chdk_process_touch()
{
    touchcnt++;
    extern unsigned short touch_screen_x, touch_screen_y;
    // Touch co-ordinate
    touchx = ((touch_screen_x & 0x7FFF) >> 5) ^ 0x3FF;
    touchy = ((touch_screen_y & 0x7FFF) >> 5) ^ 0x3FF;

    // If in alt mode block event from firmware
    return !camera_info.state.gui_mode_none;
}
#endif
