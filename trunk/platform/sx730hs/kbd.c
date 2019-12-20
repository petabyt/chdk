#include "lolevel.h"
#include "platform.h"
#include "keyboard.h"
#include "kbd_common.h"

long kbd_new_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_prev_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_mod_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };

extern void _GetKbdState(long*);

int get_usb_bit() {
    long usb_physw[3];
    usb_physw[USB_IDX] = 0;
    _kbd_read_keys_r2(usb_physw);
    return(( usb_physw[USB_IDX] & USB_MASK)==USB_MASK) ;
}

#if CAM_REMOTE_HDMI_HPD 
int get_hdmi_hpd_bit() {
    long hpd_physw[3];
    hpd_physw[HDMI_HPD_IDX] = 0;
    _GetKbdState(hpd_physw);
    return( ((hpd_physw[HDMI_HPD_IDX] & HDMI_HPD_FLAG)==HDMI_HPD_FLAG)?0:1) ;
}
#endif

#if CAM_REMOTE_ANALOG_AV
int get_analog_av_bit() {
    long av_physw[3];
    av_physw[ANALOG_AV_IDX] = 0;
    _GetKbdState(av_physw);
    return( ((av_physw[ANALOG_AV_IDX] & ANALOG_AV_FLAG)==ANALOG_AV_FLAG)?0:1) ;
}
#endif

// from sig finder
KeyMap keymap[] = {
    { 0, KEY_MENU            ,0x00000020 }, // Found @0xfc637e40, levent 0x15
    { 0, KEY_UP              ,0x00000040 }, // Found @0xfc637e48, levent 0x06
    { 0, KEY_DOWN            ,0x00000080 }, // Found @0xfc637e50, levent 0x07
    { 0, KEY_RIGHT           ,0x00000100 }, // Found @0xfc637e58, levent 0x09
    { 0, KEY_SET             ,0x00000200 }, // Found @0xfc637e60, levent 0x0a
    { 0, KEY_LEFT            ,0x00000400 }, // Found @0xfc637e68, levent 0x08
    { 0, KEY_PLAYBACK        ,0x00000800 }, // Found @0xfc637e70, levent 0x101
    { 0, KEY_ERASE           ,0x00001000 }, // Found @0xfc637e78, levent 0x0b
    { 0, KEY_VIDEO           ,0x00002000 }, // Found @0xfc637e80, levent 0x02
    { 0, KEY_WIFI            ,0x00010000 }, // Found @0xfc637e88, levent 0x103
    { 0, KEY_ZOOM_OUT        ,0x00000004 }, // full speed
    { 0, KEY_ZOOM_OUT        ,0x00000002 }, // low speed
    { 0, KEY_ZOOM_IN         ,0x00000010 }, // full speed
    { 0, KEY_ZOOM_IN         ,0x00000008 }, // low speed
//  { 0, KEY_POWER           ,0x00020000 }, // Found @0xfc637e90, levent 0x100
    { 1, KEY_SHOOT_FULL      ,0x00000c00 }, // Found @0xfc637ed0, levent 0x01
    { 1, KEY_SHOOT_FULL_ONLY ,0x00000800 }, // Found @0xfc637ed0, levent 0x01
    { 1, KEY_SHOOT_HALF      ,0x00000400 }, // Found @0xfc637ec8, levent 0x00

    { 0, 0, 0 }
};


// no battery door switch, cam runs with door open, no physw change

long __attribute__((naked,noinline)) wrap_kbd_p1_f() {

    asm volatile(
        "push    {r1-r7, lr}\n"
        "movs    r4, #0\n"
        "bl      my_kbd_read_keys\n"
        "b       kbd_p1_f_cont_my\n" // extra hook needed for shutter keys, see boot.c
//        "b       _kbd_p1_f_cont\n"
    );

    return 0;
}

// no stack manipulation needed here, since we create the task directly
void __attribute__((noinline)) mykbd_task() {
    extern void kbd_p2_f_my();

    while (physw_run) {
        _SleepTask(physw_sleep_delay);

        int r = wrap_kbd_p1_f();
        if (r == 1) {
#ifdef CAM_HAS_JOGDIAL
            kbd_p2_f_my();                      // replacement of _kbd_p2_f (in sub/<fwver>/boot.c)
#else
            _kbd_p2_f();
#endif
        }
    }

    _ExitTask();
}


// jogdial hw counters (19 bits) are at 0xd9854004 and 0xd9855004, use fw func to read + sign extend them
// 0x7fff8 .. 0x7fffc .. 0 (start pos) .. 4
// intermediate positions are also available, but they are ignored by the fw for a good reason
// directions reversed compared to sx710
#ifdef CAM_HAS_JOGDIAL
extern int _get_dial_hw_position(int dial);
#define DIAL_HW_REAR  4
int get_dial_hw_position(int dial)
{
    // mask low bits
    return _get_dial_hw_position(dial)&~3;
}
int jogdial_stopped=0;

extern long dial_positions[2];

long get_jogdial_direction(void) {
    static int new_jogdial=0, old_jogdial=0;
    
    old_jogdial=new_jogdial;
    new_jogdial=get_dial_hw_position(DIAL_HW_REAR);

    if (old_jogdial<new_jogdial) return JOGDIAL_RIGHT; 
    else if (old_jogdial>new_jogdial) return JOGDIAL_LEFT;
    else return 0;
}

int handle_jogdial() {
    // return 0 to prevent fw dial handler
    if (jogdial_stopped) {
        // update positions in RAM
        dial_positions[0] = dial_positions[1] = get_dial_hw_position(DIAL_HW_REAR);
        return 0;
    }
    return 1;
}

void jogdial_control(int c) {
    jogdial_stopped = c;
}
#endif

int physw_override;

void my_kbd_read_keys() {
    if(kbd_update_key_state()) {
        physw_override = 0;
    } else {
        // behavior of fc506140 (fw 100d) varies depending on value set by caller fc589620
        // if -1, shutter half and full shoot are ignored. Used in override in boot.c
        physw_override = -1;
    }
    kbd_update_physw_bits();
}

void kbd_fetch_data(long *dst)
{
    _GetKbdState(dst);
    _kbd_read_keys_r2(dst);
}
