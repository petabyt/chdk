
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
    return ((usb_physw[USB_IDX] & USB_MASK)==USB_MASK);
}

// TODO:
KeyMap keymap[] = {
    { 0, KEY_PLAYBACK        ,0x00008000 }, // Found @0xe05df0b0, levent 0x101
    { 0, KEY_VIDEO           ,0x00010000 }, // Found @0xe05df0b8, levent 0x02
    { 0, KEY_ZOOM_IN         ,0x00020000 }, // Found @0xe05df0c0, levent 0x03
    { 0, KEY_ZOOM_OUT        ,0x00040000 }, // Found @0xe05df0c8, levent 0x04
    { 0, KEY_SHOOT_FULL      ,0x00180000 }, // Found @0xe05df0d0, levent 0x01
    { 0, KEY_SHOOT_HALF      ,0x00100000 }, // Found @0xe05df0d8, levent 0x00
    { 0, KEY_SHOOT_FULL_ONLY ,0x00080000 }, // Found @0xe05df0d0, levent 0x01
    { 0, KEY_POWER           ,0x00200000 }, // Found @0xe05df0e0, levent 0x100
    { 0, KEY_WIFI            ,0x00400000 }, // Found @0xe05df0e8, levent 0x103
    { 2, KEY_MENU            ,0x00000020 },
    { 2, KEY_DISPLAY         ,0x00000040 }, // RING FUNC button
    { 2, KEY_UP              ,0x00000200 }, // Found @0xe05df158, levent 0x06
    { 2, KEY_DOWN            ,0x00000400 }, // Found @0xe05df160, levent 0x07
    { 2, KEY_RIGHT           ,0x00000800 }, // Found @0xe05df168, levent 0x09
    { 2, KEY_LEFT            ,0x00001000 }, // Found @0xe05df170, levent 0x08
    { 2, KEY_SET             ,0x00002000 }, // Found @0xe05df178, levent 0x0a
    { 0, 0, 0 }
};

long __attribute__((naked,noinline)) wrap_kbd_p1_f()
{
    asm volatile(
        "push    {r1-r7, lr}\n"
        "movs    r4, #0\n"
        "bl      my_kbd_read_keys\n"
        "b       kbd_p1_f_cont_my\n"
    );

    return 0;
}

// no stack manipulation needed here, since we create the task directly
void __attribute__((naked,noinline)) mykbd_task()
{
    extern void kbd_p2_f_my();

    while (physw_run)
    {
        _SleepTask(physw_sleep_delay);

        if (wrap_kbd_p1_f() == 1)
        {
            kbd_p2_f_my();
        }
    }

    _ExitTask();
}

int jogdial_stopped=0;

int get_dial_hw_position(int dial)
{
    // mask low bits
	extern int _get_dial_hw_position(int dial);
    return _get_dial_hw_position(dial)&~3;
}

// TODO:
extern long dial_positions[4];

int get_jogdial_counter()
{
    int p = get_dial_hw_position(5);
    return p;
}

long get_jogdial_direction(void)
{
    static int new_jogdial=0, old_jogdial=0 ;

    old_jogdial=new_jogdial;
    new_jogdial=get_jogdial_counter();

    if (old_jogdial>new_jogdial) return JOGDIAL_LEFT;
    else if (old_jogdial<new_jogdial) return JOGDIAL_RIGHT;
    else return 0;
}

int handle_jogdial()
{
    // return 0 to prevent fw dial handler
    if (jogdial_stopped)
    {
        // update positions in RAM
        dial_positions[0] = dial_positions[2] = get_jogdial_counter();
        return 0;
    }
    return 1;
}

void jogdial_control(int c)
{
    jogdial_stopped = c;
}

int physw0_override;

void my_kbd_read_keys()
{
    if (kbd_update_key_state())
        physw0_override = physw_status[0];
    else
        physw0_override = -1;
    kbd_update_physw_bits();
}

void kbd_fetch_data(long *dst)
{
    _GetKbdState(dst);
    _kbd_read_keys_r2(dst);
}
