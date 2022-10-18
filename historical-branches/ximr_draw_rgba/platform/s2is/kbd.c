#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "conf.h"
#include "keyboard.h"
#include "kbd_common.h"

long kbd_new_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_prev_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_mod_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };

KeyMap keymap[] = {
    /* tiny bug: key order matters. see kbd_get_pressed_key()
     * for example
     */
    { 1, KEY_UP		, 0x00020000 },
    { 1, KEY_DOWN		, 0x00080000 },
    { 1, KEY_LEFT		, 0x00010000 },
    { 1, KEY_RIGHT		, 0x00040000 },
    { 1, KEY_SET		, 0x00100000 },
    { 0, KEY_SHOOT_FULL	, 0x00000003 },
    { 0, KEY_SHOOT_FULL_ONLY, 0x00000002 },
    { 0, KEY_SHOOT_HALF	, 0x00000001 },
    { 1, KEY_ZOOM_IN	, 0x10000000 },
    { 1, KEY_ZOOM_IN	, 0x18000000 },
    { 1, KEY_ZOOM_OUT	, 0x01000000 },
    { 1, KEY_ZOOM_OUT	, 0x05000000 },
    { 1, KEY_MENU		, 0x00200000 },
    { 1, KEY_DISPLAY	, 0x00002000 },
    { 1, KEY_PRINT		, 0x00004000 },
    { 1, KEY_ERASE		, 0x00400000 },
    { 1, KEY_ISO		, 0x00001000 },
    { 1, KEY_FLASH		, 0x00000008 },
    { 1, KEY_MF		, 0x00000010 },
    { 1, KEY_MACRO		, 0x00000020 },
    { 1, KEY_VIDEO		, 0x40000000 },
    { 1, KEY_TIMER		, 0x02000000 },
    { 0, 0, 0 }
};


long physw_copy[3];

#define NEW_SS (0x2000)

// bit read in kbd update
static long got_usb_bit = 0;

int get_usb_bit() 
{
	return (got_usb_bit == USB_MASK); 
}
 
static char kbd_stack[NEW_SS];

extern void _platformsub_kbd_fetch_data(long*);
long __attribute__((naked)) wrap_kbd_p1_f();
void __attribute__((naked,noinline)) mykbd_task_proceed_2();
extern void h_kbd_p2_f();

static void __attribute__((noinline)) mykbd_task_proceed()
{
    asm volatile(
                 "STMFD   SP!, {R4-R6,LR}\n"
                 "SUB     SP, SP, #4\n"
                 "ADD     R6, SP, #2\n"
		 "B	  mykbd_task_proceed_2\n"
	);
}


void mykbd_task_proceed_2()
{
    asm volatile(
  "loc_FF82934C:"
                 "MOV     R0, #0xA\n"
                 "BL      _SleepTask\n"
                 "BL      wrap_kbd_p1_f\n"
                 "MOV     R5, R0\n"
                 "CMP     R5, #1\n"
	         "BNE     loc_FF82934C\n"
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
    kbd_prev_state[0] = kbd_new_state[0];
    kbd_prev_state[1] = kbd_new_state[1];
    kbd_prev_state[2] = kbd_new_state[2];

    asm volatile(
                "STMFD   SP!, {R4-R10,LR}\n"
                "LDR     R4, =physw_status-0x30\n"
                "MOV     R0, R4\n"
                "SUB     SP, SP, #0x18\n"
                "BL      my_kbd_read_keys\n"
    );

//    physw_status[0] = physw_status[0] & ~SD_READONLY_FLAG;

    asm volatile(
		"B	 _kbd_p1_f_cont\n"
    );
    return 0; // shut up the compiler
}


void __attribute__((naked,noinline)) my_kbd_read_keys()
{
    asm volatile(
                "STMFD   SP!, {R4-R11,LR}\n"
                "LDR     R3, =kbd_const_1\n"
                "SUB     SP, SP, #0x18\n"
                "MOV     R5, R0\n"
                "ADD     R0, SP, #0x0C\n"
                "LDR     R4, [R3]\n"
                "BL      _platformsub_kbd_fetch_data\n"
                "ADD     R0, SP, #0x0C\n"
                "BL      my_kbd_read_keys_cont\n"
		"B	 _kbd_read_keys_r2\n"
    );
}


void my_kbd_read_keys_cont(long *canon_key_state)
{
    kbd_new_state[0] = canon_key_state[0];
    kbd_new_state[1] = canon_key_state[1];
    kbd_new_state[2] = canon_key_state[2];

    got_usb_bit = kbd_new_state[USB_IDX] & USB_MASK;

    physw_copy[0] = kbd_new_state[0];
    physw_copy[1] = kbd_new_state[1];
    physw_copy[2] = kbd_new_state[2];

    if (kbd_process() == 0){
        // leave it alone...
        physw_status[0] = kbd_new_state[0];
        physw_status[1] = kbd_new_state[1];
        physw_status[2] = kbd_new_state[2];
    } else {
        // override keys
        physw_status[0] = (kbd_new_state[0] & (~KEYS_MASK0)) |
                  (kbd_mod_state[0] & KEYS_MASK0);

        physw_status[1] = (kbd_new_state[1] & (~KEYS_MASK1)) |
                  (kbd_mod_state[1] & KEYS_MASK1);

        physw_status[2] = (kbd_new_state[2] & (~KEYS_MASK2)) |
                  (kbd_mod_state[2] & KEYS_MASK2);
    }

    kbd_update_physw_bits();

    canon_key_state[0] = physw_status[0];
    canon_key_state[1] = physw_status[1];
    canon_key_state[2] = physw_status[2];
}

