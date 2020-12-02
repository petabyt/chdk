#include "lolevel.h"
#include "platform.h"
#include "keyboard.h"
#include "kbd_common.h"
extern void _GetKbdState(long* buffer);

long kbd_new_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_prev_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_mod_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF } ;

int jogdial_stopped=0;

KeyMap keymap[] = {
//	{ grp,       hackkey, canonkey  }
	{ 0, KEY_UP			, 0x00004000 }, // g11
	{ 0, KEY_DOWN		, 0x00002000 }, // g11
	{ 0, KEY_LEFT		, 0x00000400 }, // g11
	{ 0, KEY_RIGHT		, 0x00001000 }, // g11
	{ 0, KEY_SET		, 0x00000800 }, // g11
	{ 2, KEY_SHOOT_FULL	, 0x00000003 }, // g11
    { 2, KEY_SHOOT_FULL_ONLY, 0x00000002 },
	{ 2, KEY_SHOOT_HALF	, 0x00000001 }, // g11
	{ 0, KEY_ZOOM_IN	, 0x00000010 }, // g11
	{ 0, KEY_ZOOM_OUT	, 0x00000008 }, // g11
	{ 0, KEY_MENU		, 0x00040000 }, // g11
	{ 0, KEY_DISPLAY	, 0x00020000 }, // g11
	{ 0, KEY_PRINT		, 0x00000200 }, // g11 - S Key
	{ 0, KEY_ERASE		, 0x00010000 }, // g11
	{ 0, KEY_EXPO_CORR  , 0x00008000 }, // g11
	{ 0, KEY_MICROPHONE , 0x00080000 }, // g11
	{ 0, 0, 0 }
};

int get_usb_bit()
{
	long usb_physw[3];
	usb_physw[USB_IDX] = 0;
	_kbd_read_keys_r2(usb_physw);
	return(( usb_physw[USB_IDX] & USB_MASK)==USB_MASK) ; 
}


long __attribute__((naked)) wrap_kbd_p1_f();

void __attribute__((naked,noinline))
mykbd_task(long ua, long ub, long uc, long ud, long ue, long uf)
{
    (void)ua; (void)ub; (void)uc; (void)ud; (void)ue; (void)uf;
	/* Initialize our own kbd_new_state[] array with the
	   current physical status. If we dont do this here,
	   the G11 will immediate switch off at the first call
       of _GetKbdState1/2 with a (uninitialized) array.
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
//				"BL _kbd_p1_sub\n"
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


static int new_jogdial=0, old_jogdial=0;

/* Baseadr 0xC0240000 @FF860940
   Offset 104 @FF860948 in Jogdial.c
*/
int Get_JogDial(void){
 return (*(int*)0xC0240104)>>16;
}

long get_jogdial_direction(void) { 
 old_jogdial=new_jogdial;
 new_jogdial=Get_JogDial();
 if (old_jogdial<new_jogdial) return JOGDIAL_LEFT; 
 else if (old_jogdial>new_jogdial) return JOGDIAL_RIGHT;
 else return 0;
}

void jogdial_control(int n) {
    // TODO jog_position was not defined on this port
    /*
    if (jogdial_stopped && !n) {
        // If re-enabling jogdial set the task code current & previous positions to the actual
        // dial positions so that the change won't get processed by the firmware
        jog_position[0] = jog_position[2] = rear_dial_position;   // Rear dial
    }
    */
    jogdial_stopped = n;
}

