#include "lolevel.h"
#include "platform.h"
#include "keyboard.h"
#include "kbd_common.h"

long kbd_new_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_prev_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_mod_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };

KeyMap keymap[] = {
//	{ grp,       hackkey, canonkey  }
	{ 2, KEY_UP				, 0x00000010 },
	{ 2, KEY_DOWN			, 0x00000020 },
	{ 2, KEY_LEFT			, 0x00000080 },
	{ 2, KEY_RIGHT			, 0x00000040 },
	{ 2, KEY_SET			, 0x00000100 },
	{ 2, KEY_SHOOT_FULL		, 0x00000003 },
	{ 2, KEY_SHOOT_FULL_ONLY, 0x00000002 },
	{ 2, KEY_SHOOT_HALF		, 0x00000001 },
	{ 2, KEY_ZOOM_IN		, 0x00000004 },
	{ 2, KEY_ZOOM_OUT		, 0x00000008 },
	{ 2, KEY_MENU			, 0x00000200 },
	{ 2, KEY_DISPLAY		, 0x00000400 },
	{ 2, KEY_PRINT			, 0x00000800 }, // Face Key
	{ 0, 0, 0 }
};

int get_usb_bit() 
{
	long usb_physw[3];
	usb_physw[USB_IDX] = 0;
	_kbd_read_keys_r2(usb_physw);
	return(( usb_physw[USB_IDX] & USB_MASK)==USB_MASK); 
}

long __attribute__((naked)) wrap_kbd_p1_f();

void __attribute__((noinline))
mykbd_task(long ua, long ub, long uc, long ud, long ue, long uf)
{
    (void)ua; (void)ub; (void)uc; (void)ud; (void)ue; (void)uf;
	/* Initialize our own kbd_new_state[] array with the
	   current physical status. 
	   */
    // TODO not clear if canon firmware would have initialized at this point?
	kbd_new_state[0] = physw_status[0];
	kbd_new_state[1] = physw_status[1];
	kbd_new_state[2] = physw_status[2];

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
    _kbd_pwr_on();

    kbd_update_key_state();

    _kbd_read_keys_r2(physw_status);

    kbd_update_physw_bits();

//    NULLSUB'd in stubs_entry_2
//    _kbd_pwr_off();

}


void kbd_fetch_data(long *dst)
{
	// OK, FF8470CC
    volatile long *mmio0 = (void*)0xc0220200;
    volatile long *mmio1 = (void*)0xc0220204;
    volatile long *mmio2 = (void*)0xc0220208;

    dst[0] = *mmio0;
    dst[1] = *mmio1;
    dst[2] = *mmio2;// & 0xffff;
}
