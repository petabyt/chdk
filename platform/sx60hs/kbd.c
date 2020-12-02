#include "lolevel.h"
#include "platform.h"
#include "keyboard.h"
#include "kbd_common.h"

long kbd_new_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_prev_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_mod_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };

extern void _GetKbdState(long*);
extern void _LogCameraEvent(int id, const char *fmt,...);



int get_usb_bit() {
    long usb_physw[3];
    usb_physw[USB_IDX] = 0;
    _kbd_read_keys_r2(usb_physw);
    return(( usb_physw[USB_IDX] & USB_MASK)==USB_MASK) ;
}
/* some other keys
  shortcut 0x4000 bit 14

  AvExpress/Trash 0x400 bit 10
  AFFrame 0x800 bit 11
  Assist  0x2 bit 1
  FIS 0x4 bit 2
*/
KeyMap keymap[] = {
    { 0, KEY_SHOOT_FULL      ,0x00040001 }, // Found @0xfc5cfb3c, levent 0x01
    { 0, KEY_SHOOT_HALF      ,0x00040000 }, // Found @0xfc5cfbc4, levent 0x00
    { 0, KEY_SHOOT_FULL_ONLY ,0x00000001 }, // Found @0xfc5cfb3c, levent 0x01
    { 0, KEY_VIDEO           ,0x00000008 }, // Found @0xfc5cfb54, levent 0x02
    { 0, KEY_MENU            ,0x00000010 }, // Found @0xfc5cfb5c, levent 0x14
    { 0, KEY_UP              ,0x00000020 }, // Found @0xfc5cfb64, levent 0x06
    { 0, KEY_DOWN            ,0x00000040 }, // Found @0xfc5cfb6c, levent 0x07
    { 0, KEY_RIGHT           ,0x00000080 }, // Found @0xfc5cfb74, levent 0x09
    { 0, KEY_LEFT            ,0x00000100 }, // Found @0xfc5cfb7c, levent 0x08
    { 0, KEY_SET             ,0x00000200 }, // Found @0xfc5cfb84, levent 0x0a
    { 0, KEY_ERASE           ,0x00000400 }, //found by testing 
    { 0, KEY_WIFI            ,0x00002000 }, // found by testing 
    { 0, KEY_FACE            ,0x00000800 },
    { 0, KEY_PRINT           ,0x00004000 },
    { 0, KEY_FRAMING_ASSIST  ,0x00000002 },
    { 0, KEY_ZOOM_ASSIST     ,0x00000004 },
    { 0, KEY_PLAYBACK        ,0x00010000 }, // Found @0xfc5cfbb4, levent 0x101
//    { 0, KEY_POWER           ,0x00020000 }, // Found @0xfc5cfbbc, levent 0x100
    { 2, KEY_ZOOM_OUT        ,0x00000008 }, // full speed
    { 2, KEY_ZOOM_OUT        ,0x00000018 }, // middle speed
    { 2, KEY_ZOOM_OUT        ,0x00000010 }, // low speed
    { 2, KEY_ZOOM_IN         ,0x00000002 }, // full speed
    { 2, KEY_ZOOM_IN         ,0x00000006 }, // middle speed
    { 2, KEY_ZOOM_IN         ,0x00000004 }, // low speed

    { 0, 0, 0 }
};
long __attribute__((naked,noinline)) wrap_kbd_p1_f() {

    asm volatile(
        "push    {r1-r7, lr}\n"
        "movs    r4, #0\n"
        "bl      my_kbd_read_keys\n"
        "b       _kbd_p1_f_cont\n"
    );

    return 0;
}

// no stack manipulation needed here, since we create the task directly
void __attribute__((noinline)) mykbd_task() {
    extern void kbd_p2_f_my();
    while (physw_run) {
        _SleepTask(physw_sleep_delay);

        if (wrap_kbd_p1_f() == 1) {
            kbd_p2_f_my();                      // replacement of _kbd_p2_f (in sub/<fwver>/boot.c)
        }
    }

    _ExitTask();
}

// sx60hs jogdial hw counter (19 bits) 0xd9854004 
// 0x7fff8 .. 0x7fffc .. 0 (start pos) .. 4
// intermediate positions are also available, but they are ignored by the fw for a good reason
int jogdial_stopped = 0;
extern int _get_dial_hw_position(int dial);
int get_dial_hw_position(int dial)
{
    // mask low bits
    return _get_dial_hw_position(dial)&~3;
}

extern long dial_positions[4];
extern long jog_hw_pos;
int get_jogdial_counter() {
    int p;
   p = get_dial_hw_position(5);
//    _LogCameraEvent(0x20,"jd: p: %08x %08x ",jog_hw_pos, p);
//    p = jog_hw_pos & 0x7fffc;
/*
    if (p > 0x3fffc) {
        p |= 0xfff80000;
    }
*/
    return p;
}
long get_jogdial_direction(void) {
    static int new_jogdial=0, old_jogdial=0 ;

    old_jogdial=new_jogdial;
    new_jogdial=get_jogdial_counter();

//    _LogCameraEvent(0x20,"gjdd:  f:%08x %08x", old_jogdial, new_jogdial );
    if (old_jogdial>new_jogdial) return JOGDIAL_RIGHT;
    else if (old_jogdial<new_jogdial) return JOGDIAL_LEFT;
    else return 0;
}
int handle_jogdial() {
    // return 0 to prevent fw dial handler
//    _LogCameraEvent(0x20,"hjd: %i %08x", jogdial_stopped, dial_positions[0]);
    if (jogdial_stopped) {
        // update positions in RAM
        dial_positions[0] = dial_positions[2] = get_jogdial_counter();

        return 0;
    }
    return 1;
}

void jogdial_control(int c) {
    jogdial_stopped = c;
}

void my_kbd_read_keys() {
    kbd_update_key_state();
    kbd_update_physw_bits();
}

void kbd_fetch_data(long *dst)
{
    _GetKbdState(dst);
    _kbd_read_keys_r2(dst);
//     if (dst[0] != 0x00077fff || dst[1] != 0x20808030 || dst[2] != 0x1480043e ) {
 //     _LogCameraEvent(0x20,"kb: %08x %08x %08x",  dst[0], dst[1], dst[2]);
  //  } 
}
