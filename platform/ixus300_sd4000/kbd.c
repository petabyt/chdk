#include "lolevel.h"
#include "platform.h"
#include "keyboard.h"
#include "kbd_common.h"

long kbd_new_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_prev_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_mod_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };

// Base values in Play Mode
// physw_status[0] = 0x800C91F      // 1
// physw_status[1] = 0xFFE          // 2 (Mode Switch: Auto)
// physw_status[2] = 0x400000       // 3
// Mode Switch:
// physw_status[1] 0x1 Auto Mode
// physw_status[1] 0x0 Photo Mode
// physw_status[1] 0x2 Video Mode
// physw_status[2] 0x20000 SD-Card READONLY
KeyMap keymap[] = {
    { 0, KEY_UP         , 0x00000004 },
    { 0, KEY_DOWN       , 0x00000001 },
    { 0, KEY_LEFT       , 0x00000008 },
    { 0, KEY_RIGHT      , 0x00000002 },
    { 0, KEY_POWER      , 0x00000010 },
    { 0, KEY_PLAYBACK   , 0x00004000 },    
    { 0, KEY_SHOOT_FULL , 0x00000900 },   // 0x00000800 (KEY_SHOOT_FULL_ONLY) + 0x00000100 (KEY_SHOOT_HALF)
    { 0, KEY_SHOOT_FULL_ONLY, 0x00000800 },
    { 0, KEY_SHOOT_HALF , 0x00000100 },
    { 1, KEY_SET        , 0x00000040 },
    { 1, KEY_ZOOM_IN    , 0x00000010 },
    { 1, KEY_ZOOM_OUT   , 0x00000020 },
    { 1, KEY_MENU       , 0x00000080 },
    { 0, 0, 0 }
};

extern void _GetKbdState(long *dst);

int get_usb_bit() 
{
	long usb_physw[3];
	usb_physw[USB_IDX] = 0;
	_kbd_read_keys_r2(usb_physw);
	return(( usb_physw[USB_IDX] & USB_MASK)==USB_MASK) ; 
}

long __attribute__((naked)) wrap_kbd_p1_f();

// no stack manipulation needed here, since we create the task directly
void __attribute__((noinline)) mykbd_task() {
    while (physw_run) {
        _SleepTask(physw_sleep_delay);

        if (wrap_kbd_p1_f() == 1) {   // autorepeat ?
            _kbd_p2_f();
        }
    }
    _ExitTask();
}

// ROM:FF83484C, like SX110
long __attribute__((naked,noinline)) wrap_kbd_p1_f() {
    asm volatile(
        "STMFD   SP!, {R1-R5,LR}\n"
        "MOV     R4, #0\n"
//        "BL      _kbd_read_keys\n"
        "BL      my_kbd_read_keys\n"     // +
        "B       _kbd_p1_f_cont\n"       // continue at ROM:FF834858
    );
    return 0;   // shut up the compiler
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

int jogdial_stopped=0;
extern short* jog_position;
extern short rear_dial_position;

void jogdial_control(int n) {
   
    if (jogdial_stopped && !n) {
        // If re-enabling jogdial set the task code current & previous positions to the actual
        // dial positions so that the change won't get processed by the firmware
        jog_position[2] = jog_position[4] = rear_dial_position;   // Rear dial
    }
    
    jogdial_stopped = n;
}


static int new_jogdial=0, old_jogdial=0;

long get_jogdial_direction(void) {
    
    old_jogdial=new_jogdial;
    new_jogdial=rear_dial_position; // Get_JogDial();

    if (old_jogdial<new_jogdial) return JOGDIAL_RIGHT;
    if (old_jogdial>new_jogdial) return JOGDIAL_LEFT;
    return 0;
}
