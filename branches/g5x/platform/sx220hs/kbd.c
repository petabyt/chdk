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

    /* tiny bug: key order matters. see kbd_get_pressed_key()
    * for example*/

    { 0, KEY_ZOOM_OUT        , 0x00000003 },
    { 0, KEY_ZOOM_OUT        , 0x00000001 },
    { 0, KEY_ZOOM_OUT        , 0x00000002 },
    { 0, KEY_ZOOM_IN         , 0x0000000C },
    { 0, KEY_ZOOM_IN         , 0x00000004 },
    { 0, KEY_ZOOM_IN         , 0x00000008 },
    { 0, KEY_DISPLAY         , 0x00000800 },
    { 0, KEY_UP              , 0x00001000 },
    { 0, KEY_RIGHT           , 0x00006000 },
    { 0, KEY_SET             , 0x00010000 },
    { 0, KEY_DOWN            , 0x00020000 },
    { 0, KEY_MENU            , 0x00040000 },
    { 0, KEY_VIDEO           , 0x00080000 },
 //   { 0, KEY_RIGHT_SOFT      , 0x00002000 },  //soft keys commented out but still counted in the keymasks, seems to disable them like we want.
 //   { 0, KEY_UP_SOFT         , 0x00000400 },  //if enabled can cause unintentional button presses in alt menu when rotating the jogdial really fast.
 //   { 0, KEY_DOWN_SOFT       , 0x00008000 },

    { 1, KEY_PRINT           , 0x00200000 }, // playback = alt button
    { 1, KEY_PLAYBACK        , 0x00200000 },

 //   { 2, KEY_LEFT_SOFT       , 0x00000080 },
    { 2, KEY_LEFT            , 0x00000100 },
    { 2, KEY_SHOOT_FULL      , 0x00002002 },
    { 2, KEY_SHOOT_FULL_ONLY , 0x00000002 },
    { 2, KEY_SHOOT_HALF      , 0x00002000 },

    { 0, 0, 0 }
};


#if 0
void my_blinkk(void) {
    int i;
    while(1) {
        *((volatile int *) 0xC0220130) = 0x46; // Turn on LED
        for (i=0; i<0x200000; i++) { asm volatile ( "nop\n" ); }

        *((volatile int *) 0xC0220130) = 0x44; // Turn off LED
        for (i=0; i<0x200000; i++) { asm volatile ( "nop\n" ); }

        *((volatile int *) 0xC0220130) = 0x46; // Turn on LED
        for (i=0; i<0x200000; i++) { asm volatile ( "nop\n" ); }

        *((volatile int *) 0xC0220130) = 0x44; // Turn off LED
        for (i=0; i<0x900000; i++) { asm volatile ( "nop\n" ); }
    }
}
#endif

// Set to 1 to disable jogdial events from being processed in firmware
int jogdial_stopped=0;

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

// 
long __attribute__((naked,noinline)) wrap_kbd_p1_f() {
    asm volatile(
                "STMFD   SP!, {R1-R7,LR}\n"       //SX220 modified
                "MOV     R5, #0\n"
            //    "BL      _kbd_read_keys\n"       // replaces kbd_fetch_data()
                "BL      my_kbd_read_keys\n"     // +
                "B       _kbd_p1_f_cont\n"       // continue
    );

    return 0;   // shut up the compiler
}

// copied from g12 and sx30, thx to philmoz
// Pointer to stack location where jogdial task records previous and current
// jogdial positions
extern short* jog_position;

void jogdial_control(int n)
{
    if (jogdial_stopped && !n)
    {
        // If re-enabling jogdial set the task code current & previous positions to the actual
        // dial positions so that the change won't get processed by the firmware
        jog_position[0] = jog_position[2] = (*(short*)0xC0240106);  // Rear dial
    }
    jogdial_stopped = n;
}

// like SX30 and g12
void my_kbd_read_keys() {
    kbd_update_key_state();
    kbd_update_physw_bits();
}

void kbd_fetch_data(long *dst)
{
    _GetKbdState(dst);
    _kbd_read_keys_r2(dst);
}

int Get_JogDial(void) {
    return (*(int*)0xC0240104)>>16;     // 0xC0240000 + 0x104
}

static int new_jogdial=0, old_jogdial=0;

long get_jogdial_direction(void) {
    old_jogdial=new_jogdial;
    new_jogdial=Get_JogDial();

    if (old_jogdial<new_jogdial) {
        return JOGDIAL_RIGHT;
    } else if (old_jogdial>new_jogdial) {
        return JOGDIAL_LEFT;
    } else {
        return 0;
    }
}
