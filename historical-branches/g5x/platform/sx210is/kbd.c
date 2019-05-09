#include "lolevel.h"
#include "platform.h"
#include "keyboard.h"
#include "kbd_common.h"

long kbd_new_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_prev_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_mod_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };

KeyMap keymap[] = {

		//play button doesn't alter anything here...????

		//door open a19b -> 219b
		//power b -> 3
	{ 0, KEY_SHOOT_FULL	, 0x00002002 },
	{ 0, KEY_SHOOT_FULL_ONLY	, 0x00000002 },  //   b ->    9
	{ 0, KEY_SHOOT_HALF	, 0x00002000 },  //a19b -> 819b
	{ 0, KEY_UP		    , 0x00000080 },  // 9b -> 1b
	{ 0, KEY_DOWN		, 0x00000100 },  // 19b -> 09b
	{ 0, KEY_PLAYBACK	, 0x00800000 }, // Found @0xffb6586c, levent 0x601 

//                             0x000FC005   #1 Mask
//	{ 1, KEY_UP		         , 0x00000400 },  // fff -> bff
//	{ 1, KEY_DOWN		     , 0x00000800 },  // fff -> 7ff
	{ 1, KEY_LEFT		     , 0x00008000 },  // ffff -> efff --> 6fff (hard)  test ef3f ->633f
	{ 1, KEY_RIGHT		     , 0x00004000 },  // ffff -> dfff --> 9fff (hard)  test df3f ->d73f  -> f7ff -> ffff was 4000
//	{ 1, KEY_UP_SOFT         , 0x00000400 },  // fff -> bff     //Must add to keyboard.h for use
//	{ 1, KEY_DOWN_SOFT	     , 0x00000800 },  // fff -> 7ff     //Must add to keyboard.h for use
//	{ 1, KEY_LEFT_SOFT	     , 0x00001000 },  // ffff -> efff   //Must add to keyboard.h for use
//	{ 1, KEY_RIGHT_SOFT	     , 0x00002000 },  // ffff -> dfff   //Must add to keyboard.h for use
	{ 1, KEY_SET		     , 0x00010000 },  // ASM1989 tested (JH) - fffff -> effff
//	{ 1, KEY_ZOOM_IN_FASTER  , 0x00000008 },  // f -> 3 (fast) (ORd in with normal)   //Must add to keyboard.h for use
//	{ 1, KEY_ZOOM_OUT_FASTER , 0x00000002 },  // f -> c (fast) (ORd in with normal)   //Must add to keyboard.h for use
	{ 1, KEY_ZOOM_IN         , 0x00000004 },  // f -> b (slow)
	{ 1, KEY_ZOOM_OUT        , 0x00000001 },  // f -> e (slow)
	{ 1, KEY_MENU		     , 0x00040000 },  // ASM1989 tested (JH) - fffff -> bffff
	{ 1, KEY_DISPLAY         , 0x00020000 },  // ASM1989 tested (JH) - fffff -> dffff
	{ 1, KEY_PRINT		     , 0x00080000 },  // ASM1989 tested (JH) - fffff -> 7ffff
	{ 1, KEY_VIDEO		     , 0x00080000 },
    { 0, 0, 0 }
};
/*
In Review mode   physw_status      0      1      2
iddle   <>   880a19b   <>   fff3f   <>   400000


hard press
right   <>   880a19b   <>   fd73f   <>   400000
left   <>   880a19b   <>   f633f   <>   400000
up   <>   880a11b   <>   feb3f   <>   400000
down   <>   880a09b   <>   fe73f   <>   400000


iddle Manual   <>   880a19b   <>   fff3f   <>   400000
iddle AV   <>   880a19b   <>   fff1f   <>   400000
iddle TV   <>   880a19b   <>   fff5f   <>   400000
iddle P   <>   880a19b   <>   fffdf   <>   400000
iddle auto   <>   880a19b   <>   fffff   <>   400000
iddle heart   <>   880a19b   <>   fff7f   <>   400000
iddle portriat   <>   880a19b   <>   ffe7f   <>   400000
iddle landscap   <>   880a19b   <>   ffeff   <>   400000
iddle mountain   <>   880a19b   <>   ffe9f   <>   400000
iddle dog   <>   880a19b   <>   ffcdf   <>   400000
iddle fireworks   <>   880a19b   <>   ffddf   <>   400000
iddle SCN   <>   880a19b   <>   ffdff   <>   400000
iddle video   <>   880a19b   <>   ffddf   <>   400000
iddle none   <>   880a19b   <>   ffebf   <>   400000
*/

#define NEW_SS (0x2000)

static char kbd_stack[NEW_SS];

int get_usb_bit() 
{
	long usb_physw[3];
	usb_physw[USB_IDX] = 0;
	_kbd_read_keys_r2(usb_physw);
	return(( usb_physw[USB_IDX] & USB_MASK)==USB_MASK) ; 
}


int jogdial_stopped=0;

long __attribute__((naked)) wrap_kbd_p1_f();

static void __attribute__((noinline)) mykbd_task_proceed() {
    while (physw_run) {
        _SleepTask(10);

        if (wrap_kbd_p1_f() == 1) {   // autorepeat ?
            _kbd_p2_f();
        }
    }
}

void __attribute__((naked,noinline)) mykbd_task() {
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

// ROM:FF83484C, like SX110
long __attribute__((naked,noinline)) wrap_kbd_p1_f() {
    asm volatile(
                "STMFD   SP!, {R1-R5,LR}\n"
                "MOV     R4, #0\n"
//                "BL      _kbd_read_keys\n"
                "BL      my_kbd_read_keys\n"     // +
                "B       _kbd_p1_f_cont\n"       // continue at ROM:FF834858
    );
    return 0;   // shut up the compiler
}

extern void _GetKbdState(long *dst);

void my_kbd_read_keys() {
    kbd_update_key_state();
    kbd_update_physw_bits();
}

void kbd_fetch_data(long *dst)
{
    _GetKbdState(dst);
    _kbd_read_keys_r2(dst);
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
    return (*(int*)0xC0240104)>>16;     // 0xC0240000 + 0x104
}

static int new_jogdial=0, old_jogdial=0;

long get_jogdial_direction(void) {
    old_jogdial=new_jogdial;
    new_jogdial=Get_JogDial();

    if (old_jogdial<new_jogdial) {
        //return JOGDIAL_LEFT;
        return JOGDIAL_RIGHT;
    } else if (old_jogdial>new_jogdial) {
        return JOGDIAL_LEFT;
        //return JOGDIAL_RIGHT;
    } else {
        return 0;
    }
}

