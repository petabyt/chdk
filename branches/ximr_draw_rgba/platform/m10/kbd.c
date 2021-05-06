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

KeyMap keymap[] = {
//    { 0, KEY_POWER           ,0x00000001 }, // Found @0xfc623cfc, levent 0x100 (uses inverted logic in physw_status)
    { 0, KEY_PLAYBACK        ,0x00000002 }, // Found @0xfc623d04, levent 0x101 (uses inverted logic in physw_status)
    { 0, KEY_WIFI            ,0x00000004 }, // Found @0xfc623d0c, levent 0x103 (uses inverted logic in physw_status)
    { 1, KEY_SHOOT_FULL      ,0x00040001 }, // Found @0xfc623d2c, levent 0x01
    { 1, KEY_SHOOT_HALF      ,0x00040000 }, // Found @0xfc623d7c, levent 0x00
    { 1, KEY_SHOOT_FULL_ONLY ,0x00000001 }, // Found @0xfc623d2c, levent 0x01
    { 1, KEY_VIDEO           ,0x00000008 }, // Found @0xfc623d34, levent 0x02
    { 1, KEY_UP              ,0x00000020 }, // Found @0xfc623d3c, levent 0x06
    { 1, KEY_DOWN            ,0x00000040 }, // Found @0xfc623d44, levent 0x07
    { 1, KEY_RIGHT           ,0x00000080 }, // Found @0xfc623d4c, levent 0x09
    { 1, KEY_LEFT            ,0x00000100 }, // Found @0xfc623d54, levent 0x08
    { 1, KEY_SET             ,0x00000200 }, // Found @0xfc623d5c, levent 0x0a
    { 1, KEY_MENU            ,0x00001000 }, // Found @0xfc623d74, levent 0x14
    { 0, 0, 0 }
};

long __attribute__((naked,noinline)) wrap_kbd_p1_f() {

    asm volatile(
        "push    {r1-r7, lr}\n"
        "movs    r4, #0\n"
        "bl      my_kbd_read_keys\n"
        //"b       _kbd_p1_f_cont\n"
        "b       kbd_p1_f_cont_my\n"
    );

    return 0;
}

static void __attribute__((noinline)) mykbd_task_proceed() {

    extern void kbd_p2_f_my();

    /* Initialize our own kbd_new_state[] array with the
    current physical status.*/
    kbd_new_state[0] = physw_status[0] ^ KEYS_INV0;
    kbd_new_state[1] = physw_status[1];
    kbd_new_state[2] = physw_status[2];

    while (physw_run) {
        _SleepTask(physw_sleep_delay);

        if (wrap_kbd_p1_f() == 1) {             // autorepeat ?
            kbd_p2_f_my();                      // replacement of _kbd_p2_f (in sub/<fwver>/boot.c)
        }
    }
}

// no stack manipulation needed here, since we create the task directly
void __attribute__((naked,noinline)) mykbd_task() {
    mykbd_task_proceed();

    _ExitTask();
}

// jogdial hw counter (19 bits) 0xd9855004
// 0x7fff8 .. 0x7fffc .. 0 (start pos) .. 4
// intermediate positions are also available, but they are ignored by the fw for a good reason

int jogdial_stopped=0;

extern long jog_position[2];
extern long jog_hw_pos;

int get_jogdial_counter() {
    int p;
    p = jog_hw_pos & 0x7fffc;
    if (p > 0x3fffc) {
        p |= 0xfff80000;
    }
    return p;
}

long get_jogdial_direction(void) {
    static int new_jogdial=0, old_jogdial=0;
    
    old_jogdial=new_jogdial;
    new_jogdial=get_jogdial_counter();
    if (old_jogdial>new_jogdial) return JOGDIAL_RIGHT; 
    else if (old_jogdial<new_jogdial) return JOGDIAL_LEFT;
    else return 0;
}

int handle_jogdial() {
    // return 0 to prevent fw jogdial handler
    if (jogdial_stopped) {
        // update jog position in RAM
        jog_position[0] = jog_position[1] = get_jogdial_counter();
        return 0;
    }
    return 1;
}

void jogdial_control(int c) {
    jogdial_stopped = c;
}

static int startuptask_done = 0;
static int initfilemodules_done = 0;

void ifm_done()
{
    initfilemodules_done = 1;
}

void sut_done()
{
    startuptask_done = 1; 
}

static long kbdxtra = 0;

// callback, to be called from later part of kbd_p1_f (see boot.c)
long xtra_kbd_cb()
{
    if (kbdxtra)
    {
        kbdxtra = 0;
        return physw_status[1] & 0x41fe9; // mask found @ 0xfc07f02a (110d fw), also in GetKbdState
    }
    return -1;
}

void my_kbd_read_keys()
{
    kbd_prev_state[0] = kbd_new_state[0];
    kbd_prev_state[1] = kbd_new_state[1];
    kbd_prev_state[2] = kbd_new_state[2];

#ifdef CAM_TOUCHSCREEN_UI
    kbd_prev_state[3] = kbd_new_state[3];
#endif

    // note assumed kbd_pwr_on has been called if needed
    kbd_fetch_data(physw_status); // has to be physw_status

    kbd_new_state[0] = physw_status[0] ^ KEYS_INV0; // invert button(s) for CHDK use
    kbd_new_state[1] = physw_status[1];
    kbd_new_state[2] = physw_status[2];

    long status = kbd_process();
    if (status == 0){
        // leave it alone...
#ifdef CAM_HAS_JOGDIAL
        jogdial_control(0);
#endif
    } else {
        // override keys

        // invert button(s) before writing back to physw_status
        physw_status[0] = ((kbd_new_state[0] & (~KEYS_MASK0)) | (kbd_mod_state[0] & KEYS_MASK0)) ^ KEYS_INV0;

        physw_status[1] = (kbd_new_state[1] & (~KEYS_MASK1)) | (kbd_mod_state[1] & KEYS_MASK1);

        physw_status[2] = (kbd_new_state[2] & (~KEYS_MASK2)) | (kbd_mod_state[2] & KEYS_MASK2);

        kbdxtra = 1;

#ifdef CAM_HAS_JOGDIAL
        if ((jogdial_stopped==0) && !camera_info.state.state_kbd_script_run) {
            jogdial_control(1);
            get_jogdial_direction();
        }
        else if (jogdial_stopped && camera_info.state.state_kbd_script_run) {
            jogdial_control(0);
        }
#endif
    }
    // usb and SD read-only are standard
    kbd_update_physw_bits();

    // attempt to delay spytask so it doesn't crash the camera (crash reason is not known)
    extern int canon_gui_started_flag;
    extern void core_spytask_can_start();
    if (canon_gui_started_flag && initfilemodules_done && startuptask_done) {
        core_spytask_can_start();
        // re-use a variable to prevent multiple execution
        startuptask_done = 0;
    }
}

void kbd_fetch_data(long *dst)
{
    _GetKbdState(dst);
    _kbd_read_keys_r2(dst);
}
