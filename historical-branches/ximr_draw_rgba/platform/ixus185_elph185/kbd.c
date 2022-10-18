#include "lolevel.h"
#include "platform.h"
#include "keyboard.h"
#include "kbd_common.h"

extern void _GetKbdState(long *);

long kbd_new_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_prev_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_mod_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };

KeyMap keymap[] = { // copy from ixus175_elph180
    { 0, KEY_VIDEO           ,0x00000002 },
//    { 0, KEY_POWER           ,0x00000020 },
    { 0, KEY_PLAYBACK        ,0x00000040 },
    { 0, KEY_SET             ,0x00000100 },
    { 0, KEY_UP              ,0x00000200 },
    { 0, KEY_RIGHT           ,0x00000400 },
    { 0, KEY_DOWN            ,0x00000800 },
    { 0, KEY_LEFT            ,0x00001000 },
    { 0, KEY_ERASE           ,0x00004000 }, // actually "auto zoom"
    { 0, KEY_MENU            ,0x00008000 },
    { 2, KEY_SHOOT_FULL      ,0x00000003 },
    { 2, KEY_SHOOT_FULL_ONLY ,0x00000002 },
    { 2, KEY_SHOOT_HALF      ,0x00000001 },
    { 2, KEY_ZOOM_OUT        ,0x00000010 },
    { 2, KEY_ZOOM_IN         ,0x00000020 },
    { 0, 0, 0 }
};

int get_usb_bit()
{
    long usb_physw[3];
    usb_physw[USB_IDX] = 0;
    _kbd_read_keys_r2(usb_physw);
    return(( usb_physw[USB_IDX] & USB_MASK)==USB_MASK);
}

int get_analog_av_bit() {
    long av_physw[3];
    av_physw[ANALOG_AV_IDX] = 0;
    _GetKbdState(av_physw);
    return( ((av_physw[ANALOG_AV_IDX] & ANALOG_AV_FLAG)==ANALOG_AV_FLAG)?0:1) ;
}

long __attribute__((naked,noinline)) wrap_kbd_p1_f() {
    // ixus150 100c 0xff82bdf8
    asm volatile(
        "STMFD  SP!, {R1-R7,LR} \n"
        "MOV    R5, #0 \n"
        "BL     my_kbd_read_keys \n"    // patched
        //"B      _kbd_p1_f_cont \n"    // -
        "B      kbd_p1_f_cont_my \n"    // additional override in boot.c
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

static long kbdxtra = 0;

// callback, to be called from kbd_p1_f_cont_my (see boot.c)
long xtra_kbd_cb()
{
    if (kbdxtra)
    {
        kbdxtra = 0;
        return physw_status[2] & 0xffff; // firmware specific value, see 0xff86ba38 in 100c
    }
    return -1;
}

void my_kbd_read_keys() {
    long status = kbd_update_key_state();

    if (status)
    {
        kbdxtra = 1;
    }

    kbd_update_physw_bits();
}

void kbd_fetch_data(long *dst)
{
    _GetKbdState(dst);
    _kbd_read_keys_r2(dst);
}
