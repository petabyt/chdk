#include "lolevel.h"
#include "platform.h"
#include "keyboard.h"
#include "kbd_common.h"

long kbd_new_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_prev_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_mod_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
KeyMap keymap[] = {
    { 0, KEY_MENU            ,0x00008000 },
    { 0, KEY_HELP            ,0x00004000 },
    { 0, KEY_LEFT            ,0x00001000 },
    { 0, KEY_DOWN            ,0x00000800 },
    { 0, KEY_RIGHT           ,0x00000400 },
    { 0, KEY_UP              ,0x00000200 },
    { 0, KEY_SET             ,0x00000100 },
    { 0, KEY_PLAYBACK        ,0x00000040 },
    { 0, KEY_VIDEO           ,0x00000002 },
    { 2, KEY_ZOOM_IN         ,0x00000020 },
    { 2, KEY_ZOOM_OUT        ,0x00000010 },
    { 2, KEY_SHOOT_FULL      ,0x00000003 },
    { 2, KEY_SHOOT_FULL_ONLY ,0x00000002 },
    { 2, KEY_SHOOT_HALF      ,0x00000001 },
    { 0, 0, 0 }
};

int get_usb_bit()
{
    long usb_physw[3];
    usb_physw[USB_IDX] = 0;
    _kbd_read_keys_r2(usb_physw);
    return(( usb_physw[USB_IDX] & USB_MASK)==USB_MASK);
}

long __attribute__((naked,noinline)) wrap_kbd_p1_f() {
    // ixus160 100a 0xff82dce8
    asm volatile(
        "STMFD  SP!, {R1-R7,LR} \n"
        "MOV    R5, #0 \n"
        "BL     my_kbd_read_keys \n"    // patched
        "B      _kbd_p1_f_cont \n"
    );

    return 0; // shut up the compiler
}

void __attribute__((naked,noinline)) mykbd_task() {
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

//    _kbd_read_keys_r2(physw_status);

    kbd_update_physw_bits();
}

extern void _GetKbdState(long *);
void kbd_fetch_data(long *dst)
{
    _GetKbdState(dst);
    _kbd_read_keys_r2(dst);
}