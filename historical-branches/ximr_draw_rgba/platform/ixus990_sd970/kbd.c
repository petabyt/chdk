#include "lolevel.h"
#include "platform.h"
#include "keyboard.h"
#include "kbd_common.h"

long kbd_new_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_prev_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_mod_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };

// sd970: CHDKPTP key checking: rmem -i32 0x0000edf8 3
// exectude both for pressed and not pressed state and compare
KeyMap keymap[] = {
    /* tiny bug: key order matters. see kbd_get_pressed_key()
     * for example
     */
    { 0, KEY_SET             ,0x00000004 }, // sd970: Found @0xffaf1264, levent 0x08
    { 0, KEY_DISPLAY         ,0x00000008 }, // sd970: Found @0xffaf1270, levent 0x0a
    { 2, KEY_MENU            ,0x00000001 }, // sd970: Found @0xffaf1288, levent 0x09
	{ 2, KEY_PRINT           ,0x00000002 }, // checked on sd970
    { 2, KEY_ZOOM_IN         ,0x00000004 }, // sd970: Found @0xffaf12a0, levent 0x02
    { 2, KEY_ZOOM_OUT        ,0x00000008 }, // sd970: Found @0xffaf12ac, levent 0x03
    { 2, KEY_LEFT            ,0x00000010 }, // sd970: Found @0xffaf12b8, levent 0x06
    { 2, KEY_RIGHT           ,0x00000020 }, // sd970: Found @0xffaf12c4, levent 0x07
    { 2, KEY_DOWN            ,0x00000040 }, // sd970: Found @0xffaf12d0, levent 0x05
    { 2, KEY_UP              ,0x00000080 }, // sd970: Found @0xffaf12dc, levent 0x04
    { 2, KEY_SHOOT_FULL      ,0x00000300 }, // sd970: Found @0xffaf12f4, levent 0x01
    { 2, KEY_SHOOT_FULL_ONLY ,0x00000200 }, // sd970: Found @0xffaf12f4, levent 0x01
    { 2, KEY_SHOOT_HALF      ,0x00000100 }, // sd970: Found @0xffaf12e8, levent 0x00
//    { 2, KEY_POWER           ,0x00000400 }, // sd970: Found @0xffaf1300, levent 0x600
    { 2, KEY_PLAYBACK        ,0x00000800 }, // sd970: Found @0xffaf130c, levent 0x601
    { 0, 0, 0 }
};

int get_usb_bit() 
{
	long usb_physw[3];
	usb_physw[USB_IDX] = 0;
	_kbd_read_keys_r2(usb_physw);
	return(( usb_physw[USB_IDX] & USB_MASK)==USB_MASK) ; 
}

int jogdial_stopped=0;

void kbd_fetch_data(long*);

long __attribute__((naked)) wrap_kbd_p1_f();

// no stack manipulation needed here, since we create the task directly
void __attribute__((noinline))
mykbd_task()
{
    while (physw_run){
        _SleepTask(10);

        if (wrap_kbd_p1_f() == 1){ // autorepeat ?
            _kbd_p2_f();
        }
    }
    _ExitTask();
}

long __attribute__((naked,noinline)) wrap_kbd_p1_f()
{

    asm volatile(
                "STMFD   SP!, {R1-R5,LR}\n"
                "MOV     R4, #0\n"
                "BL      my_kbd_read_keys\n"
               	"B	 _kbd_p1_f_cont\n"
    );
    return 0; // shut up the compiler
}

void my_kbd_read_keys()
{
    kbd_update_key_state();

    _kbd_read_keys_r2(physw_status);

    kbd_update_physw_bits();
}

extern short rear_dial_position;
// jog_position hack does not appear to be needed on older cams
void jogdial_control(int n) {
    jogdial_stopped = n;
}

void kbd_fetch_data(long *dst)
{
	//sd970: 0xFF843f6c GetKbdState
    volatile long *mmio0 = (void*)0xc0220200;
    volatile long *mmio1 = (void*)0xc0220204;
    volatile long *mmio2 = (void*)0xc0220208;

    dst[0] = *mmio0;
    dst[1] = *mmio1;
    dst[2] = *mmio2 & 0xffff;
}

static short new_jogdial = 0, old_jogdial = 0;

int Get_JogDial(void){
 return (*(int*)0xC0240104)>>16; //sd970: Address checked
}

long get_jogdial_direction(void) { 
 old_jogdial=new_jogdial;
 new_jogdial=Get_JogDial();
 if (old_jogdial<new_jogdial) return JOGDIAL_LEFT; 
 else if (old_jogdial>new_jogdial) return JOGDIAL_RIGHT;
 else return 0;
}


