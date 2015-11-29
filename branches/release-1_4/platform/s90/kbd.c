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

KeyMap keymap[] = {
    { 1, KEY_UP         , 0x00004000 },
    { 1, KEY_DOWN       , 0x00000400 },
    { 1, KEY_LEFT       , 0x00000100 },
    { 1, KEY_RIGHT      , 0x00000200 },
    { 1, KEY_SET        , 0x00008000 },
    { 0, KEY_SHOOT_FULL , 0x00000300 },
    { 0, KEY_SHOOT_FULL_ONLY, 0x00000200 },
    { 0, KEY_SHOOT_HALF , 0x00000100 },
    { 1, KEY_ZOOM_IN    , 0x00000010 },
    { 1, KEY_ZOOM_OUT   , 0x00000020 },
    { 1, KEY_MENU       , 0x00002000 },
    { 1, KEY_DISPLAY    , 0x00001000 },
    { 1, KEY_PRINT      , 0x00000800 }, // S Key
//  { 0, KEY_PLAY       , 0x00000800 }, 
//  { 1, KEY_RING_FUNC  , 0x00000040 }, 
    { 0, 0, 0 }
};

long __attribute__((naked,noinline)) wrap_kbd_p1_f()
{
    asm volatile(
                "STMFD   SP!, {R1-R5,LR}\n"
                "MOV     R4, #0\n"
                "BL      my_kbd_read_keys\n"
                "B   _kbd_p1_f_cont\n"  

    );
    return 0;
}

void __attribute__((noinline)) mykbd_task()
{
    while (physw_run){ 
        _SleepTask(10);
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

int jogdial_stopped=0;
static int new_jogdial=0, old_jogdial=0;

void jogdial_control(int n)
{
    jogdial_stopped = n;
}

int Get_JogDial(void)
{
 return (*(int*)0xC0240104)>>16;
}

long get_jogdial_direction(void) 
{ 
 old_jogdial=new_jogdial;
 new_jogdial=Get_JogDial();
 if (old_jogdial<new_jogdial) return JOGDIAL_LEFT; 
 else if (old_jogdial>new_jogdial) return JOGDIAL_RIGHT;
 else return 0;
}

