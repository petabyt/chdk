#include "lolevel.h"
#include "platform.h"
#include "keyboard.h"
#include "kbd_common.h"

long kbd_new_state[3] =  { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_prev_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_mod_state[3] =  { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };

extern void _GetKbdState(long *dst);

int get_usb_bit() 
{
    long usb_physw[3];
    usb_physw[USB_IDX] = 0;
    _kbd_read_keys_r2(usb_physw);
    return(( usb_physw[USB_IDX] & USB_MASK)==USB_MASK) ; 
}

KeyMap keymap[] = {
    /* tiny bug: key order matters. see kbd_get_pressed_key() */
    { 2, KEY_PLAYBACK   ,     0x00000800 },
    { 2, KEY_SHOOT_FULL ,     0x00000300 },
    { 2, KEY_SHOOT_FULL_ONLY, 0x00000200 },
    { 2, KEY_SHOOT_HALF ,     0x00000100 },
    { 2, KEY_UP         ,     0x00000080 },
    { 2, KEY_DOWN       ,     0x00000040 },
    { 2, KEY_LEFT       ,     0x00000010 },
    { 2, KEY_RIGHT      ,     0x00000020 },
    { 2, KEY_ZOOM_IN    ,     0x00000004 },
    { 2, KEY_ZOOM_OUT   ,     0x00000008 },
    { 2, KEY_MENU       ,     0x00000001 },
    { 0, KEY_DISPLAY    ,     0x00000008 },
    { 0, KEY_SET        ,     0x00000004 },
    /*
    { 2, KEY_PWR_SHOOT      , 0x00000400 },
    { 2, KEY_BATTERY_DOOR   , 0x00008000 },
    { 0, KEY_SW_AUTO        , 0x00000001 },
    { 0, KEY_SW_MANUAL      , 0x00000000 },
    { 0, KEY_SW_VIDEO       , 0x00000002 },
    */
    { 0, 0, 0 }
};


long __attribute__((naked,noinline)) wrap_kbd_p1_f()
{
    asm volatile(
                "STMFD   SP!, {R1-R5,LR}\n"
                "MOV     R4, #0\n"
                "BL      my_kbd_read_keys\n"
                "B       _kbd_p1_f_cont\n"
    );
    return 0; // shut up the compiler
}

void __attribute__((noinline)) mykbd_task()
{
    while (physw_run){
        _SleepTask(10);

        if (wrap_kbd_p1_f() == 1){ // autorepeat ?
            _kbd_p2_f();
        }
    }
    _ExitTask();
}


void my_kbd_read_keys()
{
    kbd_update_key_state();

    _kbd_read_keys_r2(physw_status);

    kbd_update_physw_bits();
}


void kbd_fetch_data(long *dst)
{
    _GetKbdState(dst);
    _kbd_read_keys_r2(dst);
}

