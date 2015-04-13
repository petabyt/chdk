#include "lolevel.h"
#include "platform.h"
#include "keyboard.h"
#include "kbd_common.h"

long kbd_new_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_prev_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_mod_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };

// TODO aliases for direction keys probably not good
// power probably shouldn't be included at all
// Found in RAM
KeyMap keymap[] = {
    { 0, KEY_UP              , 0x00000040 },
    { 0, KEY_EXPO_CORR       , 0x00000040 },
    { 0, KEY_DOWN            , 0x00000800 },
    { 0, KEY_DISPLAY         , 0x00000800 },
    { 0, KEY_LEFT            , 0x00000400 },
    { 0, KEY_MACRO           , 0x00000400 },
    { 0, KEY_RIGHT           , 0x00000080 },
    { 0, KEY_FLASH           , 0x00000080 },
    { 0, KEY_MENU            , 0x00000001 },
    { 0, KEY_SET             , 0x00000002 },
    { 0, KEY_VIDEO           , 0x00000020 },
    { 1, KEY_SHOOT_FULL      , 0x00300000 },
    { 1, KEY_SHOOT_FULL_ONLY , 0x00200000 },
    { 1, KEY_SHOOT_HALF      , 0x00100000 },
    { 1, KEY_POWER           , 0x00400000 },
    { 1, KEY_PLAYBACK        , 0x00800000 },
    { 2, KEY_ZOOM_IN         , 0x00001000 },
    { 2, KEY_ZOOM_OUT        , 0x00004000 },
    { 0, 0, 0 }
};
// Note: auto/manual switch is 0x00000010 in word index 0

extern void _GetKbdState(long*);

int get_usb_bit() 
{
	long usb_physw[3];
	usb_physw[USB_IDX] = 0;
	_kbd_read_keys_r2(usb_physw);
	return(( usb_physw[USB_IDX] & USB_MASK)==USB_MASK) ; 
}


void kbd_fetch_data(long*);

long __attribute__((naked)) wrap_kbd_p1_f();

// no stack manipulation needed here, since we create the task directly
void __attribute__((noinline))
mykbd_task()
{
	while (physw_run){ 
		_SleepTask(physw_sleep_delay); // =0x1DEC + 8 @FF030F14

		if (wrap_kbd_p1_f() == 1){ // autorepeat ?
			_kbd_p2_f();
		}
	}

    _ExitTask();
}


long __attribute__((naked,noinline)) wrap_kbd_p1_f()
{
    asm volatile(
                "STMFD   SP!, {R1-R7,LR} \n"
                "MOV     R5, #0 \n"
                "BL      my_kbd_read_keys \n"
               	"B	     _kbd_p1_f_cont \n"
    );
    return 0;
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
