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
    return(( usb_physw[USB_IDX] & USB_MASK)==USB_MASK);
}

KeyMap keymap[] = {
    { 0, KEY_SET             ,0x00000004 }, // Found @0xffb3ea64, levent 0x08    
    { 0, KEY_DISPLAY         ,0x00000008 }, // Found @0xffb3ea70, levent 0x0a 
    { 2, KEY_PLAYBACK        ,0x00000800 }, // Found @0xffb3eb00, levent 0x601       
    { 2, KEY_UP         , 0x00000080 },
    { 2, KEY_DOWN       , 0x00000040 },
    { 2, KEY_LEFT       , 0x00000010 },
    { 2, KEY_RIGHT      , 0x00000020 },
    { 2, KEY_SHOOT_FULL , 0x00000300 },   // 0x00000200(KEY_SHOOT_FULL) + 0x00000100 (KEY_SHOOT_HALF)
    { 2, KEY_SHOOT_FULL_ONLY , 0x00000200 }, 
    { 2, KEY_SHOOT_HALF , 0x00000100 },
    { 2, KEY_ZOOM_IN    , 0x00000004 },
    { 2, KEY_ZOOM_OUT   , 0x00000008 },
    { 2, KEY_MENU       , 0x00000001 },
    { 0, 0, 0 }
};


long __attribute__((naked)) wrap_kbd_p1_f();

// no stack manipulation needed here, since we create the task directly
void __attribute__((noinline)) mykbd_task() {
    while (physw_run) {
        _SleepTask(10);

        if (wrap_kbd_p1_f() == 1) {   // autorepeat ?
            _kbd_p2_f();
        }
    }
    _ExitTask();
}

// ROM:FF83484C, like SX110
long __attribute__((naked,noinline)) wrap_kbd_p1_f() {
    asm volatile(
                "STMFD   SP!, {R1-R5,LR}\n"
                "MOV     R4, #0\n"
                "BL      _kbd_read_keys\n"       // replaces kbd_fetch_data()
                "BL      my_kbd_read_keys\n"     // +
                "B       _kbd_p1_f_cont\n"       // continue at ROM:FF834858
    );
    return 0;   // shut up the compiler
}

// like SX110
void my_kbd_read_keys() {
    kbd_update_key_state();
    kbd_update_physw_bits();
}

void kbd_fetch_data(long *dst)
{
    _GetKbdState(dst);
    _kbd_read_keys_r2(dst);
}
