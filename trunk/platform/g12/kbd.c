#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "conf.h"
#include "kbd_common.h"

KeyMap keymap[] = {

    { 0, KEY_ZOOM_IN    , 0x00000020 },
    { 0, KEY_PRINT      , 0x00000400 },
    { 0, KEY_ZOOM_OUT   , 0x00000800 },
    { 0, KEY_LEFT       , 0x00001000 },
    { 0, KEY_SET        , 0x00002000 },
    { 0, KEY_RIGHT      , 0x00004000 },
    { 0, KEY_DOWN       , 0x00008000 },
    { 0, KEY_UP         , 0x00010000 },
    { 0, KEY_METERING   , 0x00040000 },
    { 0, KEY_ERASE      , 0x00080000 },
    { 0, KEY_DISPLAY    , 0x00100000 },
    { 0, KEY_MENU       , 0x00200000 },
    { 0, KEY_AE_LOCK    , 0x00400000 },

    { 2, KEY_SHOOT_FULL , 0x00000003 },
    { 2, KEY_SHOOT_FULL_ONLY, 0x00000002 },  // http://chdk.setepontos.com/index.php?topic=1444.msg70223#msg70223
    { 2, KEY_SHOOT_HALF , 0x00000001 },
// Commented out since inverted logic breaks CHDK (for now)
//    { 2, KEY_POWER           ,0x00000004 }, // Found @0xffbb9428, levent 0x600 (uses inverted logic in physw_status)
//    { 2, KEY_PLAYBACK        ,0x00000008 }, // Found @0xffbb9430, levent 0x601 (uses inverted logic in physw_status)

    { 0, 0, 0 }
};

long kbd_new_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_prev_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_mod_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };

extern void _GetKbdState(long*);

//void my_blinkk(void) {
//	int i;
////	while(1) {
//		*((volatile int *) 0xC0220134) = 0x46; // Turn on LED
//		for (i=0; i<0x200000; i++) { asm volatile ( "nop\n" ); }
//
//		*((volatile int *) 0xC0220134) = 0x44; // Turn off LED
//		for (i=0; i<0x200000; i++) { asm volatile ( "nop\n" ); }
//
//		*((volatile int *) 0xC0220134) = 0x46; // Turn on LED
//		for (i=0; i<0x200000; i++) { asm volatile ( "nop\n" ); }
//
//		*((volatile int *) 0xC0220134) = 0x44; // Turn off LED
//		for (i=0; i<0x900000; i++) { asm volatile ( "nop\n" ); }
////	}
//}

int get_usb_bit() 
{
	long usb_physw[3];
	usb_physw[USB_IDX] = 0;
	_kbd_read_keys_r2(usb_physw);
	return(( usb_physw[USB_IDX] & USB_MASK)==USB_MASK) ; 
}

void kbd_fetch_data(long *dst)
{
    _GetKbdState(dst);
    _kbd_read_keys_r2(dst);
}

void my_kbd_read_keys()
{
    kbd_update_key_state();
    kbd_update_physw_bits();
}

long __attribute__((naked,noinline)) wrap_kbd_p1_f()
{
    asm volatile(
        "STMFD   SP!, {R1-R5,LR}\n"
        "MOV     R4, #0\n"
        //"BL      _kbd_read_keys \n"
        "BL     my_kbd_read_keys\n"
        "B       _kbd_p1_f_cont\n"
    );
    return 0; // shut up the compiler
}

// no stack manipulation needed here, since we create the task directly
void __attribute__((naked,noinline))
mykbd_task()
{
    while (physw_run){
        _SleepTask(physw_sleep_delay);

        if (wrap_kbd_p1_f() == 1){ // autorepeat ?
            _kbd_p2_f();
        }
    }

    _ExitTask();
}

// Set to 1 to disable jogdial events from being processed in firmware
int jogdial_stopped=0;

// Pointer to stack location where jogdial task records previous and current
// jogdial positions
extern short* jog_position;
extern short rear_dial_position, front_dial_position;

void jogdial_control(int n)
{
    if (jogdial_stopped && !n)
    {
        // If re-enabling jogdial set the task code current & previous positions to the actual
        // dial positions so that the change won't get processed by the firmware
        jog_position[0] = jog_position[2] = rear_dial_position;   // Rear dial
        jog_position[1] = jog_position[3] = front_dial_position;  // Front dial
    }
    jogdial_stopped = n;
}

static short new_jogdial = 0, old_jogdial = 0, new_frontdial = 0, old_frontdial = 0;

long get_jogdial_direction(void)
{
    old_jogdial = new_jogdial;
    new_jogdial = rear_dial_position;

    old_frontdial = new_frontdial;
    new_frontdial = front_dial_position;

    if      (old_jogdial > new_jogdial)     return JOGDIAL_LEFT;
    else if (old_jogdial < new_jogdial)     return JOGDIAL_RIGHT;
    else if (old_frontdial > new_frontdial) return FRONTDIAL_LEFT;
    else if (old_frontdial < new_frontdial) return FRONTDIAL_RIGHT;
    else                                    return 0;
}
