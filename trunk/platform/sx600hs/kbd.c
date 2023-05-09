#include "lolevel.h"
#include "platform.h"
#include "keyboard.h"
#include "kbd_common.h"

long kbd_new_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_prev_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_mod_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };

extern void _GetKbdState(long*);


 KeyMap keymap[] = {
    { 0, KEY_MENU            ,0x00000200 }, // Found @0xff5fa02c, levent 0x0e
    { 0, KEY_VIDEO           ,0x00000400 }, // Found @0xff5fa034, levent 0x02
    { 0, KEY_SET             ,0x00000800 }, // Found @0xff5fa03c, levent 0x0a
    { 0, KEY_LEFT            ,0x00001000 }, // Found @0xff5fa044, levent 0x08
    { 0, KEY_UP              ,0x00002000 }, // Found @0xff5fa04c, levent 0x06
    { 0, KEY_RIGHT           ,0x00004000 }, // Found @0xff5fa054, levent 0x09
    { 0, KEY_DOWN            ,0x00008000 }, // Found @0xff5fa05c, levent 0x07
    { 2, KEY_SHOOT_FULL      ,0x00000060 }, // Found @0xff5fa074, levent 0x01
    { 2, KEY_SHOOT_FULL_ONLY ,0x00000040 }, // Found @0xff5fa074, levent 0x01
    { 2, KEY_SHOOT_HALF      ,0x00000020 }, // Found @0xff5fa06c, levent 0x00
    { 2, KEY_PLAYBACK        ,0x00000080 }, // Found @0xff5fa07c, levent 0x101
//    { 2, KEY_POWER           ,0x00000100 }, // Found @0xff5fa084, levent 0x100
	{ 2, KEY_WIFI            ,0x00000200 },
	{ 2, KEY_ZOOM_OUT        ,0x00008000 }, //full speed
    { 2, KEY_ZOOM_OUT        ,0x00004000 }, //low speed
	{ 2, KEY_ZOOM_IN         ,0x00002000 }, //full speed
    { 2, KEY_ZOOM_IN         ,0x00001000 }, //low speed
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

    //sx510 101a found @ 0xff00c114
    asm volatile(
        "STMFD   SP!, {R1-R7,LR}\n"
        "MOV     R5, #0\n"
        "BL      my_kbd_read_keys\n"
        "B       _kbd_p1_f_cont\n"
    );

    return 0; // shut up the compiler
}

// no stack manipulation needed here, since we create the task directly
void __attribute__((noinline)) mykbd_task() {
    while (physw_run){
        _SleepTask(physw_sleep_delay);
        if (wrap_kbd_p1_f() == 1){ // autorepeat ?
            _kbd_p2_f();
        }
    }
    _ExitTask();
}

void my_kbd_read_keys()
{
    kbd_update_key_state();
    kbd_update_physw_bits();
}


void kbd_fetch_data(long *dst)
{
    _GetKbdState(dst);
    _kbd_read_keys_r2(dst);
}

