#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "keyboard.h"
#include "conf.h"
#include "kbd_common.h"

KeyMap keymap[] = {
    /* tiny bug: key order matters. see kbd_get_pressed_key()
     * for example
     */
    { 1, KEY_POWER           ,0x00000001 }, // Found @0xffaeea90, levent 0x600
    { 1, KEY_ZOOM_OUT        ,0x00002000 }, // Found @0xffaeeab4, levent 0x03
    { 1, KEY_ZOOM_IN         ,0x00004000 }, // Found @0xffaeeac0, levent 0x02
    { 1, KEY_SHOOT_FULL      ,0x00009000 }, // Found @0xffaeeacc, levent 0x01
    { 1, KEY_SHOOT_FULL_ONLY ,0x00008000 }, // Found @0xffaeeacc, levent 0x01
    { 1, KEY_SHOOT_HALF      ,0x00001000 }, // Found @0xffaeeaa8, levent 0x00
    { 2, KEY_LEFT            ,0x00000020 }, // Found @0xffaeeb14, levent 0x06
    { 2, KEY_RIGHT           ,0x00000040 }, // Found @0xffaeeb20, levent 0x07
    { 2, KEY_DOWN            ,0x00000080 }, // Found @0xffaeeb2c, levent 0x05
    { 2, KEY_UP              ,0x00000200 }, // Found @0xffaeeb44, levent 0x04
    { 2, KEY_SET             ,0x00000400 }, // Found @0xffaeeb50, levent 0x08
    { 2, KEY_MENU            ,0x00000800 }, // Found @0xffaeeb5c, levent 0x09
    { 2, KEY_PLAYBACK        ,0x00004000 }, // Found @0xffaeeb68, levent 0x601
//    { 2, KEY_LEFT_SOFT       ,0x00000001 },
//    { 2, KEY_RIGHT_SOFT      ,0x00000002 },
//    { 2, KEY_DOWN_SOFT       ,0x00000004 },
//    { 2, KEY_UP_SOFT         ,0x00000008 },
    { 0, 0                   ,0x00000000 }, // placeholder for the fake key
    { 0, 0, 0 }
};


long kbd_new_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_prev_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_mod_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };

int keys_mask1=0x0000F000;
static int set_fake_key=0;

int get_usb_bit() 
{
    long usb_physw[3];
    usb_physw[USB_IDX] = 0;
    _kbd_read_keys_r2(usb_physw);
    return(( usb_physw[USB_IDX] & USB_MASK)==USB_MASK) ; 
}

long __attribute__((naked,noinline)) wrap_kbd_p1_f()
{

    asm volatile(
                "STMFD   SP!, {R1-R5,LR}\n"
                "MOV     R4, #0\n"
                "BL      my_kbd_read_keys\n"
                   "B     _kbd_p1_f_cont\n"
    );
    return 0; // shut up the compiler
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

extern void _GetKbdState(long*);
long get_jogdial_direction();
int jogdial_stopped=0;
void enable_extra_button(short);

void kbd_fetch_data(long *state) {
    _GetKbdState(state);
    _kbd_read_keys_r2(state);
}

void my_kbd_read_keys()
{
    kbd_update_key_state();
    kbd_update_physw_bits();

    if (set_fake_key & 0x10000000) {
        enable_extra_button((short)(set_fake_key & 0xffff));
        set_fake_key=0;
    }
}

void enable_extra_button(short key) {
/*
 * enable or disable the additional "fake" button
 * in this case, the power button will be re-mapped in ALT mode
 * called from the kbd task
 * beware: the "placeholder" in keymap[] is directly addressed here
 * the placeholder has to be the last entry before the terminating { 0, 0, 0 }, if it is ever set to { 0, 0, 0 }
 */
    if (key) {
        keys_mask1=0x0000F001;
        keymap[13].grp=1;
        keymap[13].canonkey=0x00000001;
        keymap[13].hackkey=key;
    }
    else {
        keys_mask1=0x0000F000;
        keymap[13].grp=0;
        keymap[13].canonkey=0;
        keymap[13].hackkey=0;
    }
}

void kbd_set_extra_button(short key) { // called by core
    set_fake_key=key|0x10000000;    
}

void jogdial_control(int n) {
    jogdial_stopped = n;
}

static int new_jogdial=0, old_jogdial=0;

int Get_JogDial(void){
 return (*(int*)0xC0240104)>>16; // OK, ixus110
}

long get_jogdial_direction(void) { 
 old_jogdial=new_jogdial;
 new_jogdial=Get_JogDial();
 if (old_jogdial<new_jogdial) return JOGDIAL_RIGHT; 
 else if (old_jogdial>new_jogdial) return JOGDIAL_LEFT;
 else return 0;
}
