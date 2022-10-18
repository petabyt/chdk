#include "lolevel.h"
#include "platform.h"
#include "core.h"
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

int get_hdmi_hpd_bit() {
    long hpd_physw[3];
    hpd_physw[HDMI_HPD_IDX] = 0;
    _GetKbdState(hpd_physw);
    return( ((hpd_physw[HDMI_HPD_IDX] & HDMI_HPD_FLAG)==HDMI_HPD_FLAG)?0:1) ;
}

int get_analog_av_bit() {
    long av_physw[3];
    av_physw[ANALOG_AV_IDX] = 0;
    _GetKbdState(av_physw);
    return( ((av_physw[ANALOG_AV_IDX] & ANALOG_AV_FLAG)==ANALOG_AV_FLAG)?0:1) ;
}

KeyMap keymap[] = {
    // Order IS important. kbd_get_pressed_key will walk down this table
    // and take the first matching mask. Notice that KEY_SHOOT_HALF is
    // always pressed if KEY_SHOOT_FULL is. --MarcusSt
    { 0, KEY_DISPLAY         ,0x80000000 }, // Found @0xffba4ac4, levent 0x0a
    { 1, KEY_DOWN            ,0x80000000 }, // Found @0xffba4b0c, levent 0x05
    { 1, KEY_UP              ,0x40000000 }, // Found @0xffba4b04, levent 0x04
    { 1, KEY_SHOOT_FULL      ,0x30000000 }, // Found @0xffba4afc, levent 0x01
    { 1, KEY_SHOOT_FULL_ONLY ,0x20000000 }, // Found @0xffba4afc, levent 0x01
    { 1, KEY_SHOOT_HALF      ,0x10000000 }, // Found @0xffba4af4, levent 0x00
    { 1, KEY_ERASE           ,0x08000000 },
    { 1, KEY_MENU            ,0x00800000 }, // Found @0xffba4ae4, levent 0x09
    { 1, KEY_SET             ,0x00000001 }, // Found @0xffba4acc, levent 0x08
    { 2, KEY_LEFT            ,0x00002000 }, // Found @0xffba4b4c, levent 0x06
    { 2, KEY_RIGHT           ,0x00001000 }, // Found @0xffba4b44, levent 0x07
    { 2, KEY_ZOOM_IN         ,0x00000080 }, // Found @0xffba4b34, levent 0x02
    { 2, KEY_ZOOM_OUT        ,0x00000040 }, // Found @0xffba4b2c, levent 0x03
    { 2, KEY_POWER           ,0x00000020 }, // Found @0xffba4b24, levent 0x100
    { 2, KEY_PLAYBACK        ,0x00000008 }, // Found @0xffba4b1c, levent 0x101
    { 2, KEY_VIDEO           ,0x00000001 },
    { 0, 0, 0 }
};

//volatile int jogdial_stopped=0;
int jogdial_stopped=0;

long __attribute__((naked,noinline)) wrap_kbd_p1_f() {

    //sx160 100a @ 0xff829238
    asm volatile(
                "STMFD   SP!, {R1-R7,LR}\n"
                "MOV     R5, #0\n"
                "BL      my_kbd_read_keys\n"
                "B       _kbd_p1_f_cont\n"
    );

    return 0;
}

static void __attribute__((noinline)) mykbd_task_proceed() {
    while (physw_run) {
        _SleepTask(physw_sleep_delay);

        if (wrap_kbd_p1_f() == 1) {             // autorepeat ?
            _kbd_p2_f();
        }
    }
}

// no stack manipulation needed here, since we create the task directly
void __attribute__((naked,noinline)) mykbd_task() {
    mykbd_task_proceed();

// function can be modified to restore SP here...
    _ExitTask();
}

// Pointer to stack location where jogdial task records previous and current
// jogdial positions
extern short* jog_position;
extern short rear_dial_position;

void jogdial_control(int n) {
    if (jogdial_stopped && !n) {
        // If re-enabling jogdial set the task code current & previous positions to the actual
        // dial positions so that the change won't get processed by the firmware
        jog_position[0] = jog_position[2] = rear_dial_position;   // Rear dial
    }
    jogdial_stopped = n;
}

void kbd_fetch_data(long *state) {
    _GetKbdState(state);
    _kbd_read_keys_r2(state);
}
void my_kbd_read_keys()
{
    kbd_update_key_state();
    kbd_update_physw_bits();
}

static short new_jogdial = 0, old_jogdial = 0;

long get_jogdial_direction(void)
{
    old_jogdial = new_jogdial;
    new_jogdial = rear_dial_position;

    if      (old_jogdial > new_jogdial)     return JOGDIAL_RIGHT;
    else if (old_jogdial < new_jogdial)     return JOGDIAL_LEFT;
    else                                    return 0;
}
