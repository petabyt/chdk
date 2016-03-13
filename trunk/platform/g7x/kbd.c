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

KeyMap keymap[] = {
    { 0, KEY_SHOOT_FULL      ,0x00040001 }, // Found @0xfc613714, levent 0x01
    { 0, KEY_SHOOT_HALF      ,0x00040000 }, // Found @0xfc61378c, levent 0x00
    { 0, KEY_SHOOT_FULL_ONLY ,0x00000001 }, // Found @0xfc613714, levent 0x01
    { 0, KEY_ZOOM_OUT        ,0x00000002 }, // Found @0xfc61371c, levent 0x04
    { 0, KEY_ZOOM_IN         ,0x00000004 }, // Found @0xfc613724, levent 0x03
    { 0, KEY_VIDEO           ,0x00000008 }, // Found @0xfc61372c, levent 0x02
    { 0, KEY_MENU            ,0x00000010 }, // Found @0xfc613734, levent 0x14
    { 0, KEY_UP              ,0x00000020 }, // Found @0xfc61373c, levent 0x06
    { 0, KEY_DOWN            ,0x00000040 }, // Found @0xfc613744, levent 0x07
    { 0, KEY_RIGHT           ,0x00000080 }, // Found @0xfc61374c, levent 0x09
    { 0, KEY_LEFT            ,0x00000100 }, // Found @0xfc613754, levent 0x08
    { 0, KEY_SET             ,0x00000200 }, // Found @0xfc61375c, levent 0x0a
    { 0, KEY_ERASE           ,0x00000400 }, // ring func / erase, from watching  physw
    { 0, KEY_PLAYBACK        ,0x00000800 }, // Found @0xfc61376c, levent 0x101
    { 0, KEY_WIFI            ,0x00010000 }, // wifi button, from watching physw
//    { 0, KEY_POWER           ,0x00020000 }, // Found @0xfc613784, levent 0x100
    { 0, 0, 0 }
};
// ev comp and mode dial is in word 1, lower bits, encoding unclear
// flash open word 0, 0x00004000 = open
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

        if (wrap_kbd_p1_f() == 1) {             // autorepeat ?
            _kbd_p2_f();
// TODO SX280
//            kbd_p2_f_my();                      // replacement of _kbd_p2_f (in sub/<fwver>/boot.c)
        }
    }

    _ExitTask();
}

// TODO
#if 0
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
