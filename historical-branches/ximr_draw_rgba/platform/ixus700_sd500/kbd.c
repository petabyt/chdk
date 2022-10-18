#include "lolevel.h"
#include "platform.h"
#include "conf.h"
#include "core.h"
#include "keyboard.h"
#include "kbd_common.h"

long kbd_new_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_prev_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_mod_state [3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };

KeyMap keymap[] = {
    /* tiny bug: key order matters. see kbd_get_pressed_key()
     * for example
     */
	{1, KEY_UP	, 0x00000020 },
	{1, KEY_DOWN	, 0x00000040 },
	{1, KEY_LEFT	, 0x00000080 },
	{1, KEY_RIGHT	, 0x00000100 },
	{1, KEY_SET	, 0x00000200 },
	{1, KEY_SHOOT_FULL, 0x00000006 }, // note 6 here!
    {1, KEY_SHOOT_FULL_ONLY, 0x00000004 }, 
	{1, KEY_SHOOT_HALF, 0x00000002 },
	{1, KEY_ZOOM_IN	, 0x00000008 },
	{1, KEY_ZOOM_OUT	, 0x00000010 },
	{1, KEY_MENU	, 0x00000400 },
	{1, KEY_DISPLAY	, 0x00000800 },
	{1, KEY_PRINT	, 0x00002000 },
	{0, 0, 0 }
};


#define NEW_SS (0x2000)

static char kbd_stack[NEW_SS];

extern void _platformsub_kbd_fetch_data(long*);
long __attribute__((naked)) wrap_kbd_p1_f();
void __attribute__((naked,noinline)) mykbd_task_proceed_2();
extern void h_kbd_p2_f();


static void __attribute__((noinline)) mykbd_task_proceed()
{
    asm volatile(
                 "STMFD   SP!, {R4,LR}\n"
		 "B	  mykbd_task_proceed_2\n"
	);
}




void __attribute__((noinline)) mykbd_task_proceed_2()
{
    asm volatile(
"loc_FF828ED8:\n"
                 "MOV     R0, #0xA\n"
                 "BL      _SleepTask\n"
                 "BL      wrap_kbd_p1_f\n"
                 "CMP     R0, #1\n"
                 "BNE     loc_FF828ED8\n"
		 "B	  h_kbd_p2_f\n"
	);
}


void __attribute__((naked,noinline))
mykbd_task(long ua, long ub, long uc, long ud, long ue, long uf)
{
    (void)ua; (void)ub; (void)uc; (void)ud; (void)ue; (void)uf;
    /* WARNING
     * Stack pointer manipulation performed here!
     * This means (but not limited to):
     *	function arguments destroyed;
     *	function CAN NOT return properly;
     *	MUST NOT call or use stack variables before stack
     *	is setup properly;
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
//    kbd_prev_state[0] = kbd_new_state[0];
    kbd_prev_state[1] = kbd_new_state[1];
//    kbd_prev_state[2] = kbd_new_state[2];

    asm volatile(
                 "STMFD   SP!, {R4-R10,LR}\n"
                 "LDR     R4, =physw_status-0x10\n"
                 "SUB     SP, SP, #0x18\n"
                 "BL      _kbd_p1_1\n"
                 "BL      _kbd_p1_2\n"
                 "MOV     R0, #0x32\n"
                 "BL      _kbd_p1_3\n"
                 "MOV     R0, R4\n"
                 "BL      _platformsub_kbd_fetch_data_my\n"
                 "B       _kbd_p1_f_cont\n"

    );
    return 0; // shut up the compiler
}



long my_kbd_read_keys(long x)
{
 
 kbd_new_state[1]=x & 0xFFFF;
 if (kbd_process() == 0) return x; else return (kbd_new_state[1]&~KEYS_MASK1) | (kbd_mod_state[1] & KEYS_MASK1);
}

