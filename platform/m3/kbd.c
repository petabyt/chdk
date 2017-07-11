#include "lolevel.h"
#include "platform.h"
#include "keyboard.h"
#include "kbd_common.h"

long kbd_new_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_prev_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_mod_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };

extern void _GetKbdState(long*);

int get_usb_bit() {
    long usb_physw[3];
    usb_physw[USB_IDX] = 0;
    _kbd_read_keys_r2(usb_physw);
    return(( usb_physw[USB_IDX] & USB_MASK)==USB_MASK) ;
}


//EOS M3  addr = 0xD20BF4A0
KeyMap keymap[] = {
//    { 0, KEY_PLAYBACK        ,0x00000002 }, // inverted physw_status[0]
    { 1, KEY_SHOOT_FULL      ,0x00040001 },
    { 1, KEY_SHOOT_FULL_ONLY ,0x00000001 },
    { 1, KEY_SHOOT_HALF      ,0x00040000 },
    { 1, KEY_ZOOM_OUT        ,0x00001000 }, // AE Lock / Index (playback zoom out)
    { 1, KEY_ZOOM_IN         ,0x00000800 }, // AF Adjust / Magnify (playback zoom in)
    { 1, KEY_VIDEO           ,0x00000008 },
    { 1, KEY_MENU            ,0x00000010 },
    { 1, KEY_DISPLAY         ,0x00000400 }, // INFO button (lower left)
    { 1, KEY_UP              ,0x00000020 },
    { 1, KEY_DOWN            ,0x00000040 },
    { 1, KEY_RIGHT           ,0x00000080 },
    { 1, KEY_LEFT            ,0x00000100 },
    { 1, KEY_SET             ,0x00000200 },
	{ 1, KEY_PRINT           ,0x00002000 },
//	{ 0, KEY_MFN             ,0x00002000 },

//	addr = 0xD20BF4A0 + 0x38
//	{ 0, SD_lock             ,0x20000000 },

    { 0, 0, 0 }
};



/* void __attribute__((naked,noinline)) my2_kbd_read_keys() {

    asm volatile(
"      ldr     r2, =physw_status\n"
"      movs    r0, #2\n"
"      movs    r1, #0\n"
"      push    {r4,lr}\n"
"	loc_fc083e7e:\n"
"      str.w   r1, [r2,r0,lsl#2]\n"
"      subs    r0, r0, #1\n"
"      bpl     loc_fc083e7e\n"
"      ldr     r0, =physw_status\n"
"      BL      _GetKbdState\n"
"      pop.w   {r4,lr}\n"
"      ldr     r0, =physw_status\n"

"      ldr     r1, [r0,#4]\n"
"	   bic.w   r1, r1, #0x20000000\n" //clear SD LOCK bit
"      str     r1, [r0,#4]\n"

"      b.w     _kbd_read_keys_r2\n"
    );

} */

/* long __attribute__((naked,noinline)) wrap_kbd_p1_f() {

    asm volatile(
        "push    {r1-r7, lr}\n"
        "movs    r4, #0\n"
        "bl      my_kbd_read_keys\n"
//        "bl      my2_kbd_read_keys\n"
        "b       _kbd_p1_f_cont\n"
    );
    return 0;
} */



static void __attribute__((noinline)) mykbd_task_proceed() {

    extern void kbd_p2_f_my();
	extern long wrap_kbd_p1_f();

    while (physw_run) {
        _SleepTask(physw_sleep_delay);
		if ( wrap_kbd_p1_f() == 1) {
//            kbd_p2_f_my();                      // replacement of _kbd_p2_f (in sub/<fwver>/boot.c)
	          _kbd_p2_f();                      // replacement of _kbd_p2_f (in sub/<fwver>/boot.c)
        }
    }
}

// no stack manipulation needed here, since we create the task directly
void __attribute__((naked,noinline)) mykbd_task() {
    mykbd_task_proceed();

    _ExitTask();
}

// sx280 jogdial hw counter (19 bits) 0xd9854004
// 0x7fff8 .. 0x7fffc .. 0 (start pos) .. 4
// intermediate positions are also available, but they are ignored by the fw for a good reason

int jogdial_stopped=0;

extern long jog_position[2];
extern long jog_hw_pos;

int get_jogdial_counter() {
    int p;
    p = jog_hw_pos & 0x7fffc;
    if (p > 0x3fffc) {
        p |= 0xfff80000;
    }
    return p;
}

long get_jogdial_direction(void) {
    static int new_jogdial=0, old_jogdial=0;

    old_jogdial=new_jogdial;
    new_jogdial=get_jogdial_counter();
    if (old_jogdial>new_jogdial) return JOGDIAL_LEFT;
    else if (old_jogdial<new_jogdial) return JOGDIAL_RIGHT;
    else return 0;
}

int handle_jogdial() {
    // return 0 to prevent fw jogdial handler
    if (jogdial_stopped) {
        // update jog position in RAM
        jog_position[0] = jog_position[1] = get_jogdial_counter();
        return 0;
    }
    return 1;
}

void jogdial_control(int c) {
    jogdial_stopped = c;
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


