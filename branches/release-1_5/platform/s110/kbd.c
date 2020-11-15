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
    { 0, KEY_ERASE           ,0x00000001 }, // RING FUNC
    { 0, KEY_DOWN            ,0x00000002 }, // Found @0xf864bbbc, levent 0x05
    { 0, KEY_DISPLAY         ,0x00000002 }, // ^
    { 0, KEY_LEFT            ,0x00000004 }, // Found @0xf864bbc4, levent 0x06
    { 0, KEY_MENU            ,0x00000008 }, // Found @0xf864bbcc, levent 0x09
    { 0, KEY_SET             ,0x00000020 }, // Found @0xf864bbdc, levent 0x08
    { 0, KEY_UP              ,0x00000040 }, // Found @0xf864bbe4, levent 0x04
    { 0, KEY_RIGHT           ,0x00000080 }, // Found @0xf864bbec, levent 0x07
    { 0, KEY_VIDEO           ,0x00000100 },
    { 0, KEY_ZOOM_OUT        ,0x00008000 }, // Found @0xf864bc2c, levent 0x03
    { 0, KEY_ZOOM_IN         ,0x00010000 }, // Found @0xf864bc34, levent 0x02

// Removed since it breaks when shooting with KEY_POWER pressed
//    { 1, KEY_POWER           ,0x00400000 }, // Found @0xf864bc54, levent 0x100
    { 1, KEY_PLAYBACK        ,0x00800000 }, // Found @0xf864bc5c, levent 0x101

    { 2, KEY_SHOOT_FULL      ,0x000000c0 }, // Found @0xf864bc6c, levent 0x01
    { 2, KEY_SHOOT_FULL_ONLY ,0x00000080 }, // Found @0xf864bc6c, levent 0x01
    { 2, KEY_SHOOT_HALF      ,0x00000040 }, // Found @0xf864bc64, levent 0x00
    { 0, 0, 0 }
};

long __attribute__((naked,noinline)) wrap_kbd_p1_f()
{
    asm volatile(
        "STMFD   SP!, {R1-R7,LR}\n"
        "MOV     R5, #0\n"
        //"BL      _kbd_read_keys \n"
        "BL     my_kbd_read_keys\n"
        "B       _kbd_p1_f_cont\n"
    );
    return 0; // shut up the compiler
}

void __attribute__((noinline)) mykbd_task()
{
    while (physw_run){
        _SleepTask(physw_sleep_delay);

        if (wrap_kbd_p1_f() == 1){ // autorepeat ?
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


// ========= Jog Dial ==============

extern short* jog_position;
extern short rear_dial_position;

int jogdial_stopped=0;
static short new_jogdial = 0, old_jogdial = 0;

void jogdial_control(int n)
{
    if (jogdial_stopped && !n)
    {
        jog_position[0] = jog_position[2] = rear_dial_position;   // Rear dial
    }
    jogdial_stopped = n;
}


long get_jogdial_direction(void)
{
    old_jogdial = new_jogdial;
    new_jogdial = rear_dial_position;

    if      (old_jogdial < new_jogdial)     return JOGDIAL_LEFT;
    else if (old_jogdial > new_jogdial)     return JOGDIAL_RIGHT;
    else                                    return 0;
}
