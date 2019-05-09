#include "lolevel.h"
#include "platform.h"
#include "keyboard.h"
#include "kbd_common.h"

long kbd_new_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_prev_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_mod_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };

extern void _GetKbdState(long*);
extern void _LogCameraEvent(int id, const char *fmt,...);



int get_usb_bit() {
    long usb_physw[3];
    usb_physw[USB_IDX] = 0;
    _kbd_read_keys_r2(usb_physw);
    return(( usb_physw[USB_IDX] & USB_MASK)==USB_MASK) ;
}

KeyMap keymap[] = {
//    { 0, KEY_POWER           ,0x00000001 }, // Found @0xfc5693dc, levent 0x100
    { 0, KEY_PLAYBACK        ,0x00000002 }, // Found @0xfc5693e4, levent 0x101
    { 0, KEY_SHOOT_FULL      ,0x0000000c }, // Found @0xfc5693f4, levent 0x01
    { 0, KEY_SHOOT_FULL_ONLY ,0x00000008 }, // Found @0xfc5693f4, levent 0x01
    { 0, KEY_SHOOT_HALF      ,0x00000004 }, // Found @0xfc5693ec, levent 0x00
    { 0, KEY_VIDEO           ,0x00000100 }, // Found @0xfc5693fc, levent 0x02
    { 0, KEY_MENU            ,0x00000200 }, // Found @0xfc569404, levent 0x0e
    { 0, KEY_DISPLAY         ,0x00002000 }, // Found @0xfc56940c, levent 0x0d
    { 0, KEY_UP              ,0x00004000 }, // Found @0xfc569414, levent 0x06
    { 0, KEY_DOWN            ,0x00008000 }, // Found @0xfc56941c, levent 0x07
    { 0, KEY_RIGHT           ,0x00010000 }, // Found @0xfc569424, levent 0x09
    { 1, KEY_LEFT            ,0x00000004 }, // Found @0xfc56942c, levent 0x08
    { 1, KEY_SET             ,0x00000008 }, // Found @0xfc569434, levent 0x0a
//
    { 1, KEY_WIFI            ,0x00000020 },
    { 1, KEY_FRAMING_ASSIST  ,0x00000010 },
    { 2, KEY_ZOOM_IN         ,0x00000002 }, // full speed
    { 2, KEY_ZOOM_IN         ,0x00000004 }, // low speed
    { 2, KEY_ZOOM_OUT        ,0x00000008 }, // full speed
    { 2, KEY_ZOOM_OUT        ,0x00000010 }, // low speed
    { 0, 0, 0 }
};

// flash open word 1, 0x00000200 = open
// no battery door switch, cam runs with door open, no physw change

long __attribute__((naked,noinline)) wrap_kbd_p1_f() {

    asm volatile(
        "push    {r1-r7, lr}\n"
        "movs    r4, #0\n"
        "bl      my_kbd_read_keys\n"
        "b       _kbd_p1_f_cont\n"
    );

    return 0;
}

// no stack manipulation needed here, since we create the task directly
void __attribute__((noinline)) mykbd_task() {
    extern void kbd_p2_f_my();
    while (physw_run) {
        _SleepTask(physw_sleep_delay);

        if (wrap_kbd_p1_f() == 1) {
#ifdef CAM_HAS_JOGDIAL
            kbd_p2_f_my();                      // replacement of _kbd_p2_f (in sub/<fwver>/boot.c)
#else
            _kbd_p2_f();
#endif
        }
    }

    _ExitTask();
}

// Copied from sx710hs
// jogdial hw counters (19 bits) are at 0xd9854004 and 0xd9855004, use fw func t
// o read + sign extend them
// 0x7fff8 .. 0x7fffc .. 0 (start pos) .. 4
// intermediate positions are also available, but they are ignored by the fw for
//  a good reason
#ifdef CAM_HAS_JOGDIAL
extern int _get_dial_hw_position(int dial);
#define DIAL_HW_REAR  4
int get_dial_hw_position(int dial)
{
    // mask low bits
    return _get_dial_hw_position(dial)&~3;
}
int jogdial_stopped=0;

extern long dial_positions[2];

long get_jogdial_direction(void) {
    static int new_jogdial=0, old_jogdial=0;
    
    old_jogdial=new_jogdial;
    new_jogdial=get_dial_hw_position(DIAL_HW_REAR);

// Reverse directions
//    if (old_jogdial>new_jogdial) return JOGDIAL_RIGHT; 
//    else if (old_jogdial<new_jogdial) return JOGDIAL_LEFT;
    if (old_jogdial>new_jogdial) return JOGDIAL_LEFT; 
    else if (old_jogdial<new_jogdial) return JOGDIAL_RIGHT;
    else return 0;
}

int handle_jogdial() {
    // return 0 to prevent fw dial handler
    if (jogdial_stopped) {
        // update positions in RAM
        dial_positions[0] = dial_positions[1] = get_dial_hw_position(DIAL_HW_REAR);
        return 0;
    }
    return 1;
}

void jogdial_control(int c) {
    jogdial_stopped = c;
}
#endif

void my_kbd_read_keys() {
    kbd_update_key_state();
    kbd_update_physw_bits();
}

void kbd_fetch_data(long *dst)
{
    _GetKbdState(dst);
    _kbd_read_keys_r2(dst);
}
