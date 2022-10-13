#include "lolevel.h"
#include "platform.h"
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

long __attribute__((naked)) wrap_kbd_p1_f();

void __attribute__((noinline)) mykbd_task()
{
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
                "STMFD   SP!, {R1-R7,LR}\n"
                "MOV     R5, #0\n"
                "BL      my_kbd_read_keys\n"
               	"B	 _kbd_p1_f_cont\n"
    );
    return 0; // shut up the compiler
}


void my_kbd_read_keys()
{
    kbd_update_key_state();

//    _kbd_read_keys_r2(physw_status);

    kbd_update_physw_bits();
}


KeyMap keymap[] = {
    { 2, KEY_ZOOM_IN         ,0x00008000 },
    { 2, KEY_VIDEO           ,0x00002000 },
    { 2, KEY_ZOOM_OUT        ,0x00004000 },
    { 2, KEY_MENU            ,0x00001000 }, // Found @0xffba90b8, levent 0x09 (from ixus145)
    { 2, KEY_HELP            ,0x00000800 },
    { 2, KEY_PLAYBACK        ,0x00000200 }, // Found @0xffba90f0, levent 0x101 (from ixus145)
//    { 2, KEY_POWER           ,0x00000100 },
    { 2, KEY_SHOOT_FULL      ,0x00000060 }, // Found @0xffba90d8, levent 0x01 (from ixus145)
    { 2, KEY_SHOOT_FULL_ONLY ,0x00000040 }, // Found @0xffba90d8, levent 0x01 (from ixus145)
    { 2, KEY_SHOOT_HALF      ,0x00000020 }, // Found @0xffba90d0, levent 0x00 (from ixus145)
    { 2, KEY_LEFT            ,0x00000010 },
	{ 2, KEY_DOWN            ,0x00000008 },
	{ 2, KEY_RIGHT           ,0x00000004 },
    { 2, KEY_UP              ,0x00000002 },
    { 2, KEY_SET             ,0x00000001 },
    { 0, 0, 0 }
};

extern void _GetKbdState(long *);
void kbd_fetch_data(long *dst)
{
    _GetKbdState(dst);
    _kbd_read_keys_r2(dst);
}
