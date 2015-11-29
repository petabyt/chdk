#include "lolevel.h"
#include "platform.h"
#include "keyboard.h"
#include "kbd_common.h"

long kbd_new_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_prev_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_mod_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };

KeyMap keymap[] = {
    /* tiny bug: key order matters. see kbd_get_pressed_key()
     * for example
     */

	//SD780 - Keymap
	{ 0, KEY_UP		, 0x00000008 },
	{ 0, KEY_DOWN		, 0x00000004 },
	{ 0, KEY_LEFT		, 0x00000001 },
	{ 0, KEY_RIGHT		, 0x00000002 },

	{ 1, KEY_SET		, 0x00004000 },
	{ 1, KEY_MENU		, 0x00000800 },
//	{ 1, KEY_POWER		, 0x00010000 },  //SD780 Power button
	{ 1, KEY_PLAYBACK	, 0x00080000 },  //SD780 Play button

	//xxxf --> xxxd when in movie mode by switch
	//xxxxxxx4 --> xxxxxxx5 when in lens extended recording mode

	{ 2, KEY_SHOOT_FULL	, 0x00001001 },
	{ 2, KEY_SHOOT_FULL_ONLY, 0x00001000 },
	{ 2, KEY_SHOOT_HALF	, 0x00000001 },
	{ 2, KEY_ZOOM_IN	, 0x00004000 },
	{ 2, KEY_ZOOM_OUT	, 0x00002000 },
	{ 2, KEY_DISPLAY	, 0x00000040 },
	{ 0, 0, 0 }
};

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

    _kbd_read_keys_r2(physw_status);

    kbd_update_physw_bits();
}


void kbd_fetch_data(long *dst)
{
	//SD780 0xFF8431EC GetKbdState
    volatile long *mmio0 = (void*)0xc0220200;
    volatile long *mmio1 = (void*)0xc0220204;
    volatile long *mmio2 = (void*)0xc0220208;

    dst[0] = *mmio0;
    dst[1] = *mmio1;
    dst[2] = *mmio2 & 0xffff;
}
