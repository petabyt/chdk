#include "lolevel.h"
#include "platform.h"
#include "keyboard.h"
#include "kbd_common.h"

long kbd_new_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_prev_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_mod_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };

extern void _GetKbdState(long*);

int get_usb_bit()
{
        long usb_physw[3];
        usb_physw[USB_IDX] = 0;
        _kbd_read_keys_r2(usb_physw);
        return(( usb_physw[USB_IDX] & USB_MASK)==USB_MASK) ;
}

KeyMap keymap[] = {
    { 2, KEY_FACE            ,0x00000002 }, // guesssed at this one
    { 2, KEY_SHOOT_FULL      ,0x0000000c }, // Found @0xffb579c4, levent 0x01
    { 2, KEY_SHOOT_FULL_ONLY ,0x00000008 }, // Found @0xffb579c4, levent 0x01
    { 2, KEY_SHOOT_HALF      ,0x00000004 }, // Found @0xffb579bc, levent 0x00
    { 2, KEY_ZOOM_IN         ,0x00000010 }, // Found @0xffb579cc, levent 0x02
    { 2, KEY_ZOOM_OUT        ,0x00000020 }, // Found @0xffb579d4, levent 0x03
//  { 2, KEY_POWER           ,0x00000040 }, // Found @0xffb579dc, levent 0x600
    { 2, KEY_PLAYBACK        ,0x00000080 }, // Found @0xffb579e4, levent 0x601
    { 2, KEY_PRINT           ,0x00000080 }, // default ALT key
    { 2, KEY_UP              ,0x00000100 }, // Found @0xffb579ec, levent 0x04
    { 2, KEY_DOWN            ,0x00000200 }, // Found @0xffb579f4, levent 0x05
    { 2, KEY_RIGHT           ,0x00000400 }, // Found @0xffb579fc, levent 0x07
    { 2, KEY_LEFT            ,0x00000800 }, // Found @0xffb57a04, levent 0x06
    { 2, KEY_SET             ,0x00001000 }, // Found @0xffb57a0c, levent 0x08
    { 2, KEY_MENU            ,0x00002000 }, // Found @0xffb57a14, levent 0x09
    { 2, KEY_DISPLAY         ,0x00004000 }, // Found @0xffb57a1c, levent 0x0a
   { 0, 0, 0 }
};

long __attribute__((naked,noinline)) wrap_kbd_p1_f() {

    //FF83438
    asm volatile(
        "STMFD  SP!, {R1-R7,LR} \n"
        "MOV    R5, #0 \n"
        //"BL       _kbd_read_keys \n"
        "BL     my_kbd_read_keys \n"    // pached
        "B      _kbd_p1_f_cont \n"
    );

    return 0; // shut up the compiler
}

void __attribute__((noinline)) mykbd_task() {
    while (physw_run) {
        _SleepTask(*((int*)(0x1C30+0x8)));  // @FF833ED0 (a1200 1.00c)

        if (wrap_kbd_p1_f() == 1) {   // autorepeat ?
            _kbd_p2_f();
        }
    }

    _ExitTask();
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

