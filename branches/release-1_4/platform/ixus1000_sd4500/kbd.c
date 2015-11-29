#include "lolevel.h"
#include "platform.h"
#include "keyboard.h"
#include "kbd_common.h"

long kbd_new_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_prev_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_mod_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };

KeyMap keymap[] = {
    { 2, KEY_SHOOT_FULL      ,0x00002002 }, // Found @0xffb8d554, levent 0x01
    { 2, KEY_SHOOT_HALF      ,0x00002000 }, // Found @0xffb8d56c, levent 0x00
    { 2, KEY_SHOOT_FULL_ONLY ,0x00000002 }, // Found @0xffb8d554, levent 0x01
    { 2, KEY_POWER           ,0x00000008 }, // Found @0xffb8d55c, levent 0x600
    { 2, KEY_PLAYBACK        ,0x00000100 }, // Found @0xffb8d564, levent 0x601

    { 1, KEY_VIDEO           ,0x00000080 }, // Found @0xffb8d4e4, levent 0x12
    { 1, KEY_UP              ,0x00000400 }, // Found @0xffb8d4fc, levent 0x04
    { 1, KEY_RIGHT           ,0x00000800 }, // Found @0xffb8d504, levent 0x07
    { 1, KEY_SET             ,0x00001000 }, // Found @0xffb8d50c, levent 0x08
    { 1, KEY_UP_SOFT         ,0x00002000 },
    { 1, KEY_RIGHT_SOFT      ,0x00004000 },
    { 1, KEY_LEFT            ,0x00008000 }, // Found @0xffb8d524, levent 0x06
    { 1, KEY_MENU            ,0x00010000 }, // Found @0xffb8d52c, levent 0x09
    { 1, KEY_DOWN            ,0x00020000 }, // Found @0xffb8d534, levent 0x05
    { 1, KEY_LEFT_SOFT       ,0x00040000 },
    { 1, KEY_DOWN_SOFT       ,0x00080000 },

    // 2 bits used and 4 values per direction, like sx30
    { 1, KEY_ZOOM_IN         , 0x00000004 }, // 0->4->c->8
    { 1, KEY_ZOOM_IN         , 0x00000008 },
    { 1, KEY_ZOOM_OUT        , 0x00000001 }, // 0->1->3->2
    { 1, KEY_ZOOM_OUT        , 0x00000002 },

    { 0, 0, 0 }
};

#define NEW_SS (0x2000)

int get_usb_bit() 
{
	long usb_physw[3];
	usb_physw[USB_IDX] = 0;
	_kbd_read_keys_r2(usb_physw);
	return(( usb_physw[USB_IDX] & USB_MASK)==USB_MASK) ; 
}

static char kbd_stack[NEW_SS];

extern void _GetKbdState(long *dst);

int jogdial_stopped=0;

long __attribute__((naked)) wrap_kbd_p1_f();

static void __attribute__((noinline)) mykbd_task_proceed() {
    while (physw_run) {
        _SleepTask(physw_sleep_delay);

        if (wrap_kbd_p1_f() == 1) {   // autorepeat ?
            _kbd_p2_f();
        }
    }
}

void __attribute__((naked,noinline)) mykbd_task() {
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
        return JOGDIAL_LEFT;
    } else if (old_jogdial>new_jogdial) {
        return JOGDIAL_RIGHT;
    } else {
        return 0;
    }
}
