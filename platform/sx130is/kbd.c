#include "lolevel.h"
#include "platform.h"
#include "keyboard.h"
#include "kbd_common.h"

long kbd_new_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_prev_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_mod_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };

KeyMap keymap[] = {
	// Order IS important. kbd_get_pressed_key will walk down this table  
	// and take the first matching mask. Notice that KEY_SHOOT_HALF is  
	// always pressed if KEY_SHOOT_FULL is. --MarcusSt
	//{ 0, KEY_FLASH     , 0x80000000 },
	{ 2, KEY_MENU      , 0x00002000 },
	{ 2, KEY_UP        , 0x00000100 },
	{ 2, KEY_DOWN      , 0x00000200 },
	{ 2, KEY_LEFT      , 0x00000800 },
	{ 2, KEY_RIGHT     , 0x00000400 },
	{ 2, KEY_SET       , 0x00001000 },
	// { 1, KEY_FACE      , 0x10000000 },
	{ 1, KEY_PRINT     , 0x10000000 }, // Face -> Print
	{ 2, KEY_ERASE     , 0x00008000 },
	{ 2, KEY_DISPLAY   , 0x00004000 },
	{ 2, KEY_ZOOM_IN   , 0x00000010 },
	{ 2, KEY_ZOOM_OUT  , 0x00000020 },
	{ 2, KEY_SHOOT_FULL, 0x0000000C },
    { 2, KEY_SHOOT_FULL_ONLY, 0x00000008 },
	{ 2, KEY_SHOOT_HALF, 0x00000004 },
	{ 0, 0, 0 }
};

int jogdial_stopped=0;

int get_usb_bit() 
{
	long usb_physw[3];
	usb_physw[USB_IDX] = 0;
	_kbd_read_keys_r2(usb_physw);
	return(( usb_physw[USB_IDX] & USB_MASK)==USB_MASK) ; 
}

extern void _GetKbdState(long* buffer);

long __attribute__((naked)) wrap_kbd_p1_f();

void __attribute__((noinline))
mykbd_task(long ua, long ub, long uc, long ud, long ue, long uf)
{
    (void)ua; (void)ub; (void)uc; (void)ud; (void)ue; (void)uf;
	/* Initialize our own kbd_new_state[] array with the
	   current physical status.
	   */
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
    kbd_update_key_state();

    _kbd_read_keys_r2(physw_status);

    kbd_update_physw_bits();
}

void kbd_fetch_data(long *dst)
{
    _GetKbdState(dst);
}

void jogdial_control(int n) {
    // this camera did not have jog_position defined
    /*
    if (jogdial_stopped && !n) {
        // If re-enabling jogdial set the task code current & previous positions to the actual
        // dial positions so that the change won't get processed by the firmware
        jog_position[0] = jog_position[2] = rear_dial_position;   // Rear dial
    }
    */
    jogdial_stopped = n;
}


int Get_JogDial(void) {
 return (*(int*)0xC0240104)>>16;
}

long get_jogdial_direction(void) {
	static int new_jogdial = 0;
	int old_jogdial = 0;

	old_jogdial = new_jogdial;
	new_jogdial = Get_JogDial();

	if (old_jogdial < new_jogdial)
		return JOGDIAL_LEFT;
	else if (old_jogdial > new_jogdial)
		return JOGDIAL_RIGHT;
	else
		return 0;
}
