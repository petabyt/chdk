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
    // Order IS important. kbd_get_pressed_key will walk down this table
    // and take the first matching mask. Notice that KEY_SHOOT_HALF is
    // always pressed if KEY_SHOOT_FULL is. --MarcusSt
    { 2, KEY_HELP            ,0x00008000 }, // Found during brute-force testing.
    { 2, KEY_VIDEO           ,0x00004000 }, // Found with CHDK OSD.
    { 2, KEY_MENU            ,0x00002000 }, // Found during brute-force testing.
    { 2, KEY_SET             ,0x00001000 }, // SET was working as DISPLAY (RIGHT) while testing.
    { 2, KEY_LEFT            ,0x00000400 }, // LEFT was working as SET while testing.
    { 2, KEY_RIGHT           ,0x00000200 }, // RIGHT was working as MENU while testing.
//  { 2, KEY_FLASH           ,0x00000200 }, // Since Flash and Right are the same key.
    { 2, KEY_DOWN            ,0x00000100 }, // DOWN was working as RIGHT while testing.
//  { 2, KEY_DISPLAY         ,0x00000100 }, // Since DOWN and DISPLAY are the same key.
    { 2, KEY_UP              ,0x00000080 }, // Found with CHDK OSD.
    { 2, KEY_ZOOM_OUT        ,0x00000040 }, // Found with CHDK OSD.
    { 2, KEY_ZOOM_IN         ,0x00000010 }, // Confirmed by replacing with KEY_UP.
    { 2, KEY_SHOOT_FULL      ,0x0000000c }, // Found @0xffb49154, levent 0x01
    { 2, KEY_SHOOT_FULL_ONLY ,0x00000008 }, // Found @0xffb49154, levent 0x01
    { 2, KEY_SHOOT_HALF      ,0x00000004 }, // Found @0xffb4914c, levent 0x00
    { 2, KEY_PLAYBACK        ,0x00000002 }, // Found @0xffb49144, levent 0x101
//  { 2, KEY_POWER           ,0x00000001 }, // Found @0xffb4913c, levent 0x100
    { 0, 0, 0 }
};


long __attribute__((naked,noinline)) wrap_kbd_p1_f() {

    //a2500 100a @0xff82af6c
    asm volatile(
        "STMFD  SP!, {R1-R7,LR} \n"
        "MOV    R5, #0 \n"
        "BL     my_kbd_read_keys \n"    // pached
        "B      _kbd_p1_f_cont \n"
    );

    return 0; // shut up the compiler
}

void __attribute__((noinline)) mykbd_task() {
    while (physw_run) {
        _SleepTask(physw_sleep_delay);
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
