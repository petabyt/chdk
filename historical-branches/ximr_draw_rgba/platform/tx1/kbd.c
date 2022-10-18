#include "lolevel.h"
#include "platform.h"
#include "keyboard.h"
#include "kbd_common.h"

long kbd_new_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_prev_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_mod_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };

KeyMap keymap[] = {
	{1, KEY_UP	      , 0x00000001 },
	{1, KEY_DOWN	, 0x00000002 },
	{1, KEY_LEFT	, 0x00000008 },
	{1, KEY_RIGHT	, 0x00000004 },
	{1, KEY_SET	      , 0x00000010 },
	{2, KEY_SHOOT_FULL, 0x00003000 }, // note 3 here!
    {2, KEY_SHOOT_FULL_ONLY, 0x00002000 },
	{2, KEY_SHOOT_HALF, 0x00001000 },
	{1, KEY_ZOOM_IN	, 0x00040000 },
	{1, KEY_ZOOM_OUT  , 0x00010000 },
	{1, KEY_MENU	, 0x00000400 },
	{1, KEY_DISPLAY	, 0x00000200 },
	{1, KEY_PRINT	, 0x00000100 },
	{1, KEY_VIDEO	, 0x00000800 },
	{0, 0, 0 }
};

// TODO - special bit used below
#define SCREEN_CLOSED_FLAG 0x100000;

int get_usb_bit() 
{
	long usb_physw[3];
	usb_physw[USB_IDX] = 0;
	_kbd_read_keys_r2(usb_physw);
	return(( usb_physw[USB_IDX] & USB_MASK)==USB_MASK) ; 
}

#define NEW_SS (0x2000)

static char kbd_stack[NEW_SS];

long __attribute__((naked)) wrap_kbd_p1_f();

static void __attribute__((noinline)) mykbd_task_proceed()

{
    while (physw_run)
    {
	_SleepTask(10);

	if (wrap_kbd_p1_f() == 1)
      {                           // autorepeat ?
	    _kbd_p2_f();
	}
    }
}


void __attribute__((naked,noinline)) mykbd_task(long ua, long ub, long uc, long ud, long ue, long uf)
{
    (void)ua; (void)ub; (void)uc; (void)ud; (void)ue; (void)uf;


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

    _ExitTask();
}


long __attribute__((naked,noinline)) wrap_kbd_p1_f()
{

    asm volatile(
                "STMFD   SP!, {R4-R7,LR}\n"
                "SUB     SP, SP, #0xC\n"
                "BL      my_kbd_read_keys\n"
		"B	 _kbd_p1_f_cont\n"
    );
    return 0; // shut up the compiler
}


void my_kbd_read_keys()
{
    kbd_update_key_state();
    kbd_update_physw_bits();
	
    // TODO special code found in original port kbd.c
    // not clear it should always be overriden
    physw_status[1] = physw_status[1] & ~ SCREEN_CLOSED_FLAG;
}

void kbd_fetch_data(long *dst)
{
    volatile long *mmio0 = (void*)0xc0220200;
    volatile long *mmio1 = (void*)0xc0220204;
    volatile long *mmio2 = (void*)0xc0220208;
    dst[0] = *mmio0;
    dst[1] = *mmio1;
    dst[2] = *mmio2 & 0xffff;

    _kbd_read_keys_r2(dst);
}
