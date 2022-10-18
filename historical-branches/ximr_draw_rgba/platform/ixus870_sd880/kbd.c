#include "lolevel.h"
#include "platform.h"
#include "keyboard.h"
#include "kbd_common.h"

long kbd_new_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_prev_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_mod_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };

extern void _platformsub_kbd_fetch_data(long*);

#define NEW_SS (0x2000)

// from sub_FF846198 (via aSdProtect (just above it))
// LDR  R1, =dword_FFAD6F20     R1 = 0xFFAD6F20 = a
// MOV  R3, #1                  R3 = 1
// LDRB R2, [R1,#0x114]         R2 = a[0x114] = 0x51
// LDRB R1, [R1,#0x114]         R1 = a[0x114] = 0x51
// MOV  R2, R2,LSR#5            R2 = 0x51 >> 5 = 2 = SD_READONLY_REG
// LDR  R0, [R0,R2,LSL#2]       R0 = R0[2] = b[2]
// AND  R1, R1, #0x1F           R1 = 0x51 & 0x1F = 0x11
// AND  R0, R0, R3,LSL R1       R0 = b[2] & (1 << 0x11)
// MOV  R0, R0,LSR R1           R0 = (b[2] & (1 << 0x11)) >> 0x11
// AND  R0, R0, #1              R0 = ((b[2] & (1 << 0x11)) >> 0x11) & 0x1
// BX   LR                      return

int get_usb_bit() 
{
	long usb_physw[3];
	usb_physw[USB_IDX] = 0;
	_kbd_read_keys_r2(usb_physw);
	return(( usb_physw[USB_IDX] & USB_MASK)==USB_MASK) ; 
}


static char kbd_stack[NEW_SS];

KeyMap keymap[] = {
	/* tiny bug: key order matters. see kbd_get_pressed_key()
	 * for example
         * KEY_SHOOT_FULL and KEY_SHOOT_HALF overlap and the first has precedence
	 */

    // (note: key is in group i if it changes a bit in physw_status[i])
    // group, CHDK key      , mask
    { 2, KEY_SHOOT_FULL	, 0x00000003 },
    { 2, KEY_SHOOT_FULL_ONLY, 0x00000002 },
    { 2, KEY_SHOOT_HALF	, 0x00000001 },

    { 2, KEY_UP		, 0x00000080 },
    { 2, KEY_DOWN		, 0x00000040 },
    { 2, KEY_LEFT		, 0x00000010 },
    { 2, KEY_RIGHT		, 0x00000020 },
    { 2, KEY_SET		, 0x00000100 },
    { 2, KEY_ZOOM_IN	, 0x00000004 },
    { 2, KEY_ZOOM_OUT	, 0x00000008 },
    { 2, KEY_MENU		, 0x00000400 },
    { 2, KEY_DISPLAY	, 0x00000200 },
    { 2, KEY_PRINT	 	, 0x00000800 },
    { 0, 0, 0 }
};


long __attribute__((naked)) wrap_kbd_p1_f();


static void __attribute__((noinline)) mykbd_task_proceed()
{
	while (physw_run){
		_SleepTask(10);
		
		if (wrap_kbd_p1_f() == 1){ // autorepeat ?
			_kbd_p2_f();
		}
	}
}

void __attribute__((naked,noinline)) mykbd_task()
{
    /* WARNING
     * Stack pointer manipulation performed here!
     * This means (but not limited to):
     *	function arguments destroyed;
     *	function CAN NOT return properly;
     *	MUST NOT call or use stack variables before stack
     *	is setup properly;
     *
     */

	register int i;
	register long *newstack;

	newstack = (void*)kbd_stack;

	for (i=0;i<NEW_SS/4;i++)
		newstack[i]=0xdededede;

	asm volatile (
		"MOV	SP, %0"
		:: "r"(((char*)newstack)+NEW_SS)
		: "memory"
	);

	mykbd_task_proceed();

	/* function can be modified to restore SP here...
	 */

	_ExitTask();
}


long __attribute__((naked,noinline)) wrap_kbd_p1_f()
{
        // first three lines from kbd_p1_f plus a jump to the fourth
	asm volatile(
		"STMFD   SP!, {R1-R5,LR}\n"
		"MOV     R4, #0\n"
		"BL      my_kbd_read_keys\n"
		"B       _kbd_p1_f_cont\n"
	);
	return 0; // shut up the compiler
}

int jogdial_stopped=0;

void my_kbd_read_keys()
{
    _kbd_pwr_on();

    kbd_update_key_state();

    _kbd_read_keys_r2(physw_status);

    kbd_update_physw_bits();

    _kbd_pwr_off();
}

void kbd_fetch_data(long *dst)
{
    _platformsub_kbd_fetch_data(dst);
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

/****************/


static int new_jogdial=0, old_jogdial=0;

int Get_JogDial(void){
 // address from sub above aJogdail (sub_FF84B8D8)
 return (*(int*)0xC0240104)>>16;
}

long get_jogdial_direction(void) {
 // XXX this seems to have a overflow bug: old=MIN_INT, new = old-1 = MAX_INT  ->  old-1 < old < new = old - 1
 // not likely to happen though (very long runs with a bias for tuning one direction; bias is probably to the right due to menus)
 old_jogdial=new_jogdial;
 new_jogdial=Get_JogDial();
 if (old_jogdial<new_jogdial) return JOGDIAL_RIGHT; 
 else if (old_jogdial>new_jogdial) return JOGDIAL_LEFT;
 else return 0;
}
