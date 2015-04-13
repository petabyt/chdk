#include "lolevel.h"
#include "platform.h"
#include "keyboard.h"
#include "kbd_common.h"


long kbd_new_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_prev_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_mod_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };;

#define NEW_SS (0x2000)

int get_usb_bit()
{
	long usb_physw[3];
	usb_physw[USB_IDX] = 0;
	_kbd_read_keys_r2(usb_physw);
	return(( usb_physw[USB_IDX] & USB_MASK)==USB_MASK) ; 
}

extern void _GetKbdState(long *dst);

static char kbd_stack[NEW_SS];


KeyMap keymap[] = {
	/* tiny bug: key order matters. see kbd_get_pressed_key()
	 * for example
	 */
// physw_status[1] total mask: 0x7F3F7860
//	{ 1, ??           , 0x80000000 }, // Default 0, unused?
	{ 1, KEY_MACRO    , 0x40000000 }, 
	{ 1, KEY_MF       , 0x20000000 }, 
	{ 1, KEY_ZOOM_IN  , 0x10000000 }, // Zoom_in_fast  = 0x08000000 | 0x10000000
//	{ 1, KEY_ZOOMFIN  , 0x08000000 }, // Not defined in CHDK
//	{ 1, KEY_ZOOMFOUT , 0x04000000 }, // Not defined in CHDK
	{ 1, KEY_TIMER    , 0x02000000 }, 
	{ 1, KEY_ZOOM_OUT , 0x01000000 }, // Zoom_out_fast = 0x04000000 | 0x01000000
//	{ 1, ??           , 0x00800000 }, // Default 0, unused?
//	{ 1, ??           , 0x00400000 }, // Default 1, unused?
	{ 1, KEY_RIGHT    , 0x00200000 }, 
	{ 1, KEY_UP       , 0x00100000 }, 
	{ 1, KEY_DOWN     , 0x00080000 }, 
	{ 1, KEY_MENU     , 0x00040000 }, 
	{ 1, KEY_DISPLAY  , 0x00020000 }, 
	{ 1, KEY_SET      , 0x00010000 }, 
//	{ 1, ??           , 0x00008000 }, // Default 0, unused?
	{ 1, KEY_ERASE    , 0x00004000 }, 
	{ 1, KEY_VIDEO    , 0x00002000 }, 
	{ 1, KEY_LEFT     , 0x00001000 }, 
	{ 1, KEY_ISO      , 0x00000800 }, 
//	{ 1, ??           , 0x00000400 }, // Default 1, unused?
//	{ 1, KEY_DISP_ROTA, 0x00000200 }, // Indicates whether or not display is rotated, not defined, though used in CHDK
//   { 1, KEY_DISP_OPEN, 0x00000100 }, // Indicates whether or not display is attached to body (i.e. not 'opened'), not defined, though used in CHDK
//	{ 1, ??           , 0x00000080 }, // Default 0, unused?
	{ 1, KEY_PRINT    , 0x00000040 }, 
	{ 1, KEY_FLASH    , 0x00000020 }, 
//	{ 1, KEY_FL_RAISED, 0x00000010 }, // Indicates whether or not the flash is raised, not defined in CHDK
//	{ 1, KEY_MODE_DIAL, 0x0000000F }, // Listed for completeness of the keymap
//   { 1, MODE_DIAL_P         , 0x00000007 },
//   { 1, MODE_DIAL_TV        , 0x00000003 },
//   { 1, MODE_DIAL_AV        , 0x00000002 },
//   { 1, MODE_DIAL_M         , 0x00000006 },
//   { 1, MODE_DIAL_C         , 0x00000004 },
//   { 1, MODE_DIAL_AUTO      , 0x0000000F },
//   { 1, MODE_DIAL_PORTRAIT  , 0x0000000E },
//   { 1, MODE_DIAL_LANDSCAPE , 0x0000000A },
//   { 1, MODE_DIAL_NIGHT     , 0x0000000B },
//   { 1, MODE_DIAL_SPORTS    , 0x00000009 },
//   { 1, MODE_DIAL_SPECIAL   , 0x00000001 },
//   { 1, MODE_DIAL_STITCH    , 0x00000005 },
//   { 1, MODE_DIAL_MOVIE     , 0x0000000D },
//   { 1, MODE_DIAL_EMPTY     , 0x0000000C },
// 0 and 8 appear to be unused


// physw_status[0] // 6 listed keys seem to fully cover [0], though some appear to use negative logic so can't be certain.
//	{ 0, KEY_OFF       , 0x00020000 }, // Not defined in CHDK
//	{ 0, KEY_OPEN_BATT , 0x00008000 }, // Indicates whether or not the battery compartment is about to be opened (slider is a button). Camera does not retract lens, though, shame. Not defined in CHDK
//	{ 0, KEY_M_DISPLAY , 0x00000008 }, // Switch to display mode, not defined in CHDK (negative? Default 0, 1 when switching)
//	{ 0, KEY_M_SHOOT   , 0x00000004 }, // Switch to shoot mode, not defined in CHDK (negative? Default 0, 1 when switching)
//	{ 0, KEY_SHOOT_FULL, 0x00000002 }, // Listed for completeness, this is the 'single' key.
	{ 0, KEY_SHOOT_FULL, 0x00000003 }, // This is SHOOT_FULL_ONLY | SHOOT_HALF.
    { 0, KEY_SHOOT_FULL_ONLY, 0x00000002 }, 
	{ 0, KEY_SHOOT_HALF, 0x00000001 }, 


// physw_status[2]
//	{ 2, USB_ATTACH    , 0x00200000 }, // 0 = no USB, 1 = USB attached
//	{ 2, FLASH_ATTACH  , 0x00080000 }, // 0 = no flash, 1 = Hotshoe external flash attached
//   { 2, TVOUT_ATTACH  , 0x00040000 }, // 1 = no tvout, 0 = tvout attached
//	{ 2, SD_LOCK       , 0x00020000 }, // 0 = unlocked, 1 = locked


// I don't really remember whether or not this is correct, listed for completeness
// Shoot mode   = (*((long *)0xC0220200) & 0xD) == 0xD
// Display mode = (*((long *)0xC0220200) & 0xD) == 0x0

	{0, 0, 0 }
};


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

void __attribute__((naked,noinline)) mykbd_task()
{
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
//		"BL      _kbd_read_keys\n"
		"BL      my_kbd_read_keys\n"
		"B       _kbd_p1_f_cont\n"
	);
	return 0; // shut up the compiler
}


void my_kbd_read_keys()
{
    kbd_update_key_state();
    kbd_update_physw_bits();
}

void kbd_fetch_data(long *dst)
{
    _GetKbdState(dst);
    _kbd_read_keys_r2(dst);
}

