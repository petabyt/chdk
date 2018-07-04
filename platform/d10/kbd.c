#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "keyboard.h"
#include "kbd_common.h"

extern void _GetKbdState(long *);

KeyMap keymap[] = {
    /* tiny bug: key order matters. see kbd_get_pressed_key()
     * for example
     */
    // D10 Verified
    { 2, KEY_UP		    , 0x00000080 }, 
    { 2, KEY_DOWN		, 0x00000040 },
    { 2, KEY_LEFT		, 0x00000010 },
    { 2, KEY_RIGHT		, 0x00000020 },
    { 2, KEY_SET		, 0x00000100 },
    { 2, KEY_SHOOT_FULL	, 0x00000003 },
    { 2, KEY_SHOOT_FULL_ONLY, 0x00000002 },
    { 2, KEY_SHOOT_HALF	, 0x00000001 }, 
    { 2, KEY_ZOOM_IN	, 0x00000004 },
    { 2, KEY_ZOOM_OUT	, 0x00000008 },
    { 2, KEY_MENU		, 0x00000400 },
    { 2, KEY_DISPLAY	, 0x00000200 },
    { 2, KEY_PRINT		, 0x00000800 },
    { 1, KEY_MODE		, 0x20000000 }, // D10 mode select 
    { 1, KEY_PLAYBACK	, 0x80000000 }, // D10 play button
    { 0, 0, 0 }
};


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

int get_analog_av_bit() {
    long av_physw[3];
    av_physw[ANALOG_AV_IDX] = 0;
    _GetKbdState(av_physw);
    return( ((av_physw[ANALOG_AV_IDX] & ANALOG_AV_FLAG)==ANALOG_AV_FLAG)?0:1) ;
}

long __attribute__((naked)) wrap_kbd_p1_f();

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
                "STMFD   SP!, {R1-R5,LR}\n"
                "MOV     R4, #0\n"
                "BL      my_kbd_read_keys\n"
               	"B	 _kbd_p1_f_cont\n"
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
    _GetKbdState(dst);
    _kbd_read_keys_r2(dst);
}

/*
// kb MMIOs, FF8470CC
volatile long *mmio0 = (void*)0xc0220200;
volatile long *mmio1 = (void*)0xc0220204;
volatile long *mmio2 = (void*)0xc0220208;

dst[0] = *mmio0;
dst[1] = *mmio1;
dst[2] = *mmio2 & 0xffff;
*/
