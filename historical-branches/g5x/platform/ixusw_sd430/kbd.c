#include "lolevel.h"
#include "platform.h"
#include "keyboard.h"
#include "kbd_common.h"

#define NEW_SS (0x2000)

long kbd_new_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_prev_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_mod_state[3]  = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };

KeyMap keymap[] = {
    /* tiny bug: key order matters. see kbd_get_pressed_key()
     * for example
     */
    {2, KEY_UP,                0x00000020 },
    {2, KEY_DOWN,              0x00000040 },
    {2, KEY_LEFT,              0x00000080 },
    {2, KEY_RIGHT,             0x00000100 },
    {2, KEY_SET,               0x00000200 },
    {2, KEY_SHOOT_FULL,        0x00000006 },
    {2, KEY_SHOOT_FULL_ONLY,   0x00000004 },
    {2, KEY_SHOOT_HALF,        0x00000002 },
    {2, KEY_ZOOM_IN,           0x00000008 },
    {2, KEY_ZOOM_OUT,          0x00000010 },
    {2, KEY_MENU,              0x00000400 },
    {2, KEY_DISPLAY,           0x00000800 },
    {2, KEY_PRINT,             0x00002000 },
    {0,  0, 0 }
};


static char kbd_stack[NEW_SS];

long __attribute__((naked)) wrap_kbd_p1_f();

static void __attribute__((noinline)) mykbd_task_proceed()
{
    while (physw_run){
        // was 5 in original port, but firmware uses 10
        _SleepTask(10);

        if (wrap_kbd_p1_f() == 1) // Readout key state via camera function
        {
        _kbd_p2_f();
        }
    }
}

void __attribute__((naked,noinline)) mykbd_task()
{
    /* WARNING
     * Stack pointer manipulation performed here!
     * This means (but not limited to):
     *  function arguments destroyed;
     *  function CAN NOT return properly;
     *  MUST NOT call or use stack variables before stack
     *  is setup properly;
     *
     */

    register int i;
    register long *newstack;

    newstack = (void*)kbd_stack;

    for (i=0;i<NEW_SS/4;i++)
        newstack[i]=0xdededede;

    asm volatile (
    "MOV	SP, %0"
    :: "r"(((char*)newstack)+NEW_SS)
    : "memory"
    );

    mykbd_task_proceed();

    /* function can be modified to restore SP here...
     */

    _ExitTask();
}


long __attribute__((naked,noinline)) wrap_kbd_p1_f()
{
    //found @ 0xff829c94
    asm volatile(
        "STMFD   SP!, {R4-R7,LR}\n"
        "SUB     SP, SP, #0xC\n"
//                "BL      _kbd_read_keys\n"
                "BL      my_kbd_read_keys\n"
                "B       _kbd_p1_f_cont\n"        // Continue original function execution
    );
    return 0; // shut up the compiler
}



/**
 * Handles and forwards key settings to key processing routines
 */
void my_kbd_read_keys()
{
    kbd_update_key_state();
    kbd_update_physw_bits();
}

extern void _GetKbdState(long *dst);
void kbd_fetch_data(long *dst)
{
    _kbd_pwr_on();
    _GetKbdState(dst);

// kbd_read_keys_r2 is just a RET on this firmware
  //  _kbd_read_keys_r2(dst);
    _kbd_pwr_off();
}



