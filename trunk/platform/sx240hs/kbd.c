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

// Using Finsig
KeyMap keymap[] = {
    { 1, KEY_PLAYBACK        ,0x00800000 }, // Found @0xff441550, levent 0x101
    { 1, KEY_SHOOT_FULL      ,0x03000000 }, // Found @0xff441560, levent 0x01
    { 1, KEY_SHOOT_FULL_ONLY ,0x02000000 }, // Found @0xff441560, levent 0x01
    { 1, KEY_SHOOT_HALF      ,0x01000000 }, // Found @0xff441558, levent 0x00
    { 1, KEY_ZOOM_OUT        ,0x0C000000 },    // From sx260hs
    { 1, KEY_ZOOM_OUT        ,0x04000000 },
    { 1, KEY_ZOOM_OUT        ,0x08000000 },
    { 1, KEY_ZOOM_IN         ,0x30000000 },
    { 1, KEY_ZOOM_IN         ,0x10000000 },
    { 1, KEY_ZOOM_IN         ,0x20000000 },
    { 2, KEY_VIDEO           ,0x00000020 }, // Found @0xff4415b0, levent 0x1a
    { 2, KEY_MENU            ,0x00000040 }, // Found @0xff4415b8, levent 0x09
    { 2, KEY_DISPLAY         ,0x00000080 }, // Found @0xff4415c0, levent 0x0a
    { 2, KEY_UP              ,0x00000100 }, // Found @0xff4415c8, levent 0x04
    { 2, KEY_DOWN            ,0x00000200 }, // Found @0xff4415d0, levent 0x05
    { 2, KEY_RIGHT           ,0x00000400 }, // Found @0xff4415d8, levent 0x07
    { 2, KEY_LEFT            ,0x00000800 }, // Found @0xff4415e0, levent 0x06
    { 2, KEY_SET             ,0x00001000 }, // Found @0xff4415e8, levent 0x08
    { 0, 0, 0 }
};


#if 0
void my_blinkk(void) {
    int i;
    while(1) {
        *((volatile int *) 0xC0220130) = 0x46;  // Turn on LED
        for (i=0; i<0x200000; i++) { asm volatile ( "nop\n" ); }

        *((volatile int *) 0xC0220130) = 0x44;  // Turn off LED
        for (i=0; i<0x200000; i++) { asm volatile ( "nop\n" ); }

        *((volatile int *) 0xC0220130) = 0x46;  // Turn on LED
        for (i=0; i<0x200000; i++) { asm volatile ( "nop\n" ); }

        *((volatile int *) 0xC0220130) = 0x44;  // Turn off LED
        for (i=0; i<0x900000; i++) { asm volatile ( "nop\n" ); }
    }
}
#endif

int jogdial_stopped=0;

long __attribute__((naked,noinline)) wrap_kbd_p1_f() {

    asm volatile(
                "STMFD   SP!, {R1-R7,LR}\n"
                "MOV     R5, #0\n"
                "BL      my_kbd_read_keys\n"
                "B       _kbd_p1_f_cont\n"
    );

    return 0;
}

// no stack manipulation needed here, since we create the task directly
void __attribute__((noinline)) mykbd_task() {
    while (physw_run) {
        _SleepTask(physw_sleep_delay);

        if (wrap_kbd_p1_f() == 1) {             // autorepeat ?
            _kbd_p2_f();
        }
    }

    _ExitTask();
}

// copied from g12 and sx30, thx to philmoz
// Pointer to stack location where jogdial task records previous and current
// jogdial positions

extern short* jog_position;

void jogdial_control(int n) {
    if (jogdial_stopped && !n) {
        // If re-enabling jogdial set the task code current & previous positions to the actual
        // dial positions so that the change won't get processed by the firmware
        jog_position[0] = jog_position[2] = (*(short*)0xC0240106);  //TODO SX230 CODE  Rear dial
    }
    jogdial_stopped = n;
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

///
int Get_JogDial(void) {
    return (*(int*)0xC0240104)>>16;     //TODO SX230 CODE 0xC0240000 + 0x104
}

static int new_jogdial = 0, old_jogdial = 0;

long get_jogdial_direction(void) {
    old_jogdial=new_jogdial;
    new_jogdial=Get_JogDial();

    if (old_jogdial<new_jogdial) {
        return JOGDIAL_LEFT;
    } else if (old_jogdial>new_jogdial) {
        return JOGDIAL_RIGHT;
    } else {
        return 0;
    }
}
