#include "lolevel.h"
#include "platform.h"
#include "keyboard.h"
#include "kbd_common.h"

long kbd_new_state[3] =  { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_prev_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_mod_state[3] =  { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };

extern void _GetKbdState(long*);

int get_usb_bit()
{
    long usb_physw[3];
    usb_physw[USB_IDX] = 0;
    _kbd_read_keys_r2(usb_physw);
    return(( usb_physw[USB_IDX] & USB_MASK)==USB_MASK) ;
}

KeyMap keymap[] =
{
    { 0, KEY_ZOOM_OUT        ,0x00000002 }, // Found @0xfc571a18, levent 0x04
    { 0, KEY_ZOOM_IN         ,0x00000004 }, // Found @0xfc571a20, levent 0x03
    { 0, KEY_VIDEO           ,0x00000008 }, // Found @0xfc571a28, levent 0x02
    { 0, KEY_MENU            ,0x00000010 }, // Found @0xfc571a30, levent 0x0b
    { 0, KEY_UP              ,0x00000020 }, // Found @0xfc571a38, levent 0x06
    { 0, KEY_DOWN            ,0x00000040 }, // Found @0xfc571a40, levent 0x07
//  { 0, KEY_DISPLAY         ,0x00000040 }, // KEY_DISPLAY is also KEY_DOWN
    { 0, KEY_RIGHT           ,0x00000080 }, // Found @0xfc571a48, levent 0x09
    { 0, KEY_LEFT            ,0x00000100 }, // Found @0xfc571a50, levent 0x08
    { 0, KEY_SET             ,0x00000200 }, // Found @0xfc571a58, levent 0x0a
    { 0, KEY_PLAYBACK        ,0x00010000 }, // Found @0xfc571a80, levent 0x101
    { 0, KEY_POWER           ,0x00020000 }, // Found @0xfc571a88, levent 0x100
    { 0, KEY_SHOOT_FULL      ,0x000c0000 }, // Found @0xfc571a98, levent 0x01
    { 0, KEY_SHOOT_FULL_ONLY ,0x00080000 }, // Found @0xfc571a98, levent 0x01
    { 0, KEY_SHOOT_HALF      ,0x00040000 }, // Found @0xfc571a90, levent 0x00
    { 0, KEY_PRINT           ,0x00002000 }, // G16 shortcut key
    { 0, KEY_ERASE           ,0x00001000 }, // G16 erase or ISO key
    { 0, KEY_AE_LOCK         ,0x00000800 }, // G16 * or AE Lock
    { 0, KEY_WIFI            ,0x00000400 }, // G16 WiFI or AF frame select
    { 0, 0, 0 }
};


long __attribute__((naked,noinline)) wrap_kbd_p1_f()
{
    asm volatile(
        "push    {r1-r7, lr}\n"
        "movs    r4, #0\n"
        "bl      my_kbd_read_keys\n"
        "b       _kbd_p1_f_cont\n"
    );
    return 0;
}

static void __attribute__((noinline)) mykbd_task_proceed()
{
    extern void kbd_p2_f_my();

    while (physw_run) {
        _SleepTask(physw_sleep_delay);
        if (wrap_kbd_p1_f() == 1) {             // autorepeat ?
            kbd_p2_f_my();                      // replacement of _kbd_p2_f (in sub/<fwver>/boot.c)
        }
    }
}

void __attribute__((naked,noinline)) mykbd_task()
{
    mykbd_task_proceed();
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

#define DIAL_HW_REAR  4
#define DIAL_HW_FRONT 5

extern int _get_dial_hw_position(int dial);
extern long dial_positions[4];

int jogdial_stopped=0;

int get_dial_hw_position(int dial)
{
    return _get_dial_hw_position(dial)&~3;     // note : mask low bits
}

long get_jogdial_direction(void)
{
    static int new_jogdial=0, old_jogdial=0, new_frontdial=0, old_frontdial=0;

    old_jogdial=new_jogdial;
    new_jogdial=get_dial_hw_position(DIAL_HW_REAR);
    old_frontdial=new_frontdial;
    new_frontdial=get_dial_hw_position(DIAL_HW_FRONT);

    if (old_jogdial>new_jogdial)          return JOGDIAL_LEFT;
    else if (old_jogdial<new_jogdial)     return JOGDIAL_RIGHT;
    if (old_frontdial>new_frontdial)      return FRONTDIAL_RIGHT;
    else if (old_frontdial<new_frontdial) return FRONTDIAL_LEFT;
    else                                  return 0;
}

int handle_jogdial()
{
    if (jogdial_stopped) {
        // update positions in RAM
        dial_positions[0] = dial_positions[2] = get_dial_hw_position(DIAL_HW_REAR);
        dial_positions[1] = dial_positions[3] = get_dial_hw_position(DIAL_HW_FRONT);
        return 0;      // return 0 to disable fw's dial handler
    }
    return 1;
}

void jogdial_control(int c)
{
    jogdial_stopped = c;
}
