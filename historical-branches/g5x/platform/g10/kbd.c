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
    { 0, KEY_SHOOT_FULL      , 0x00000003 }, // Found @0xffb0f7c0, levent 0x01
    { 0, KEY_SHOOT_FULL_ONLY , 0x00000002 }, // http://chdk.setepontos.com/index.php?topic=1444.msg70223#msg70223
    { 0, KEY_SHOOT_HALF      , 0x00000001 }, // Found @0xffb0f7b4, levent 0x00
    { 1, KEY_ZOOM_OUT        , 0x00000008 }, // Found @0xffb0f82c, levent 0x03
    { 1, KEY_ZOOM_IN         , 0x00000010 }, // Found @0xffb0f838, levent 0x02
    { 1, KEY_PRINT           , 0x00000200 }, //
    { 1, KEY_LEFT            , 0x00000400 }, // Found @0xffb0f880, levent 0x06
    { 1, KEY_SET             , 0x00000800 }, // Found @0xffb0f88c, levent 0x08
    { 1, KEY_RIGHT           , 0x00001000 }, // Found @0xffb0f898, levent 0x07
    { 1, KEY_DOWN            , 0x00002000 }, // Found @0xffb0f8a4, levent 0x05
    { 1, KEY_UP              , 0x00004000 }, // Found @0xffb0f8b0, levent 0x04
    { 1, KEY_METERING        , 0x00008000 }, //
    { 1, KEY_ERASE           , 0x00010000 }, //
    { 1, KEY_DISPLAY         , 0x00020000 }, // Found @0xffb0f8d4, levent 0x0a
    { 1, KEY_MENU            , 0x00040000 }, // Found @0xffb0f8e0, levent 0x09
    { 1, KEY_AE_LOCK         , 0x00080000 }, //
/*  
    { 0, KEY_PWR_PLAYBACK   , 0x80000000 }, // inverted
    { 0, KEY_PWR_SHOOT      , 0x40000000 }, // inverted
    { 0, KEY_BATTERY_DOOR   , 0x00008000 }, // inverted
*/  
    { 0, 0, 0 }
};

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

void __attribute__((noinline)) mykbd_task()
{
    while (physw_run){
        _SleepTask(10) ;  //    *((int*)(0x1c30+0x14)));

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


int jogdial_stopped=0;
static int new_jogdial=0, old_jogdial=0;

void jogdial_control(int n)
{
    jogdial_stopped = n;
}

int Get_JogDial(void)
{
    return (*(int*)0xC0240104)>>16;        // G10 okay
}

long get_jogdial_direction(void) 
{
    old_jogdial=new_jogdial;
    new_jogdial=Get_JogDial();
    if (old_jogdial<new_jogdial) return JOGDIAL_LEFT;
    else if (old_jogdial>new_jogdial) return JOGDIAL_RIGHT;
    else return 0;
}
