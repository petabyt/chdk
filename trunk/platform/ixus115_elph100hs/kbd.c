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

int get_hdmi_hpd_bit() {
    long hpd_physw[3];
    hpd_physw[HDMI_HPD_IDX] = 0;
    _GetKbdState(hpd_physw);
    return( ((hpd_physw[HDMI_HPD_IDX] & HDMI_HPD_FLAG)==HDMI_HPD_FLAG)?0:1) ;
}

KeyMap keymap[] = {

	// tiny bug: key order matters. KEY_SHOOT_FULL needs to come before KEY_SHOOT_HALF and KEY_SHOOT_FULL_ONLY

	{ 0, KEY_PLAYBACK    ,0x00000001 },
	{ 1, KEY_MENU        ,0x01000000 }, // Found @0xffb99680, levent 0x09
	{ 1, KEY_SET         ,0x04000000 }, // Found @0xffb99688, levent 0x08
	{ 1, KEY_ZOOM_OUT    ,0x10000000 }, // Found @0xffb99690, levent 0x03
	{ 1, KEY_ZOOM_IN     ,0x20000000 }, // Found @0xffb99698, levent 0x02
	{ 1, KEY_VIDEO       ,0x80000000 },
	{ 2, KEY_UP          ,0x00000001 }, // Found @0xffb996b0, levent 0x04
	{ 2, KEY_DOWN        ,0x00000002 }, // Found @0xffb996b8, levent 0x05
	{ 2, KEY_LEFT        ,0x00000004 }, // Found @0xffb996c0, levent 0x06
	{ 2, KEY_RIGHT       ,0x00000008 }, // Found @0xffb996c8, levent 0x07
	{ 2, KEY_SHOOT_FULL  ,0x00000030 }, // Found @0xffb996d8, levent 0x01
	{ 2, KEY_SHOOT_FULL_ONLY  ,0x00000020 },
	{ 2, KEY_SHOOT_HALF  ,0x00000010 }, // Found @0xffb996d0, levent 0x00
	{ 0, 0, 0 }
};


long __attribute__((naked)) wrap_kbd_p1_f();

// no stack manipulation needed here, since we create the task directly
void __attribute__((noinline)) mykbd_task() {

	while (physw_run) {
		_SleepTask(physw_sleep_delay);// @FF834508

		if (wrap_kbd_p1_f() == 1) {   // autorepeat ?
			_kbd_p2_f();
		}
	}

	_ExitTask();
}

//
long __attribute__((naked,noinline)) wrap_kbd_p1_f() {
	asm volatile(
				"STMFD   SP!, {R1-R7,LR}\n"       //SX220 modified
				"MOV     R5, #0\n"
				"BL      my_kbd_read_keys\n"     // +
				"B       _kbd_p1_f_cont\n"       // continue
	);

	return 0;   // shut up the compiler
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
