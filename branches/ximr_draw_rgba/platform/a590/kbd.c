#include "lolevel.h"
#include "platform.h"
#include "keyboard.h"
#include "kbd_common.h"

long kbd_new_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_prev_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_mod_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };

KeyMap keymap[] = {
	/* tiny bug: key order matters. see kbd_get_pressed_key()
	* for example
	*/
	{ 2, KEY_UP			, 0x00000010 }, 
	{ 2, KEY_DOWN		, 0x00000020 }, 
	{ 2, KEY_LEFT		, 0x00000080 }, 
	{ 2, KEY_RIGHT		, 0x00000040 }, 
	{ 2, KEY_SET		, 0x00000100 }, 
	{ 1, KEY_SHOOT_FULL	, 0xC0000000 }, 
    { 1, KEY_SHOOT_FULL_ONLY, 0x80000000 },
	{ 1, KEY_SHOOT_HALF	, 0x40000000 }, 
	{ 2, KEY_ZOOM_IN	, 0x00000004 }, 
	{ 2, KEY_ZOOM_OUT	, 0x00000008 }, 
	{ 2, KEY_MENU		, 0x00000200 }, 
	{ 2, KEY_DISPLAY	, 0x00000400 }, 
	{ 2, KEY_PRINT		, 0x00000800 }, 
	{ 1, KEY_ERASE		, 0x00800000 }, 
	{ 0, 0, 0 }
};

#define NEW_SS (0x2000)

int get_usb_bit() 
{
	long usb_physw[3];
	usb_physw[USB_IDX] = 0;
	_kbd_read_keys_r2(usb_physw);
	return(( usb_physw[USB_IDX] & USB_MASK)==USB_MASK) ; 
}

static char kbd_stack[NEW_SS];

void kbd_fetch_data(long*);

long __attribute__((naked)) wrap_kbd_p1_f();


static void __attribute__((noinline)) mykbd_task_proceed()
{
    while (physw_run){ 
	_SleepTask(10);
	
	if (wrap_kbd_p1_f() == 1){ // autorepeat ?
	    _kbd_p2_f();
	}
    }
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
    _kbd_pwr_on();

    kbd_update_key_state();

    _kbd_read_keys_r2(physw_status);

    kbd_update_physw_bits();

    //__kbd_pwr_off();
}


void kbd_fetch_data(long *dst)
{
	volatile long *mmio0 = (void*)0xc0220200;
	volatile long *mmio1 = (void*)0xc0220204;
	volatile long *mmio2 = (void*)0xc0220208;

	dst[0] = *mmio0;
	dst[1] = *mmio1;
	dst[2] = *mmio2 & 0xffff;
}

