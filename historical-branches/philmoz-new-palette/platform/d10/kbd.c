#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "keyboard.h"
#include "conf.h"

typedef struct {
	short grp;
	short hackkey;
	long canonkey;
} KeyMap;


long kbd_new_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
static long kbd_prev_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
static long kbd_mod_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };

static KeyMap keymap[];

extern int forced_usb_port;

// OK, GetKbdState
#define KEYS_MASK0 (0x00000000)
#define KEYS_MASK1 (0xA0000000)
#define KEYS_MASK2 (0x0FFF)

// D10 verified
#define SD_READONLY_FLAG (0x20000)

// D10 verified physw in PTP mode
#define USB_MASK (0x80000)
#define USB_IDX  2

/*
battery door switch, 0: door open
forcing to one allows camera to run with door open.
Informational only for now,
making the camera boot with door open requires some ugly changes in boot.c
see http://chdk.setepontos.com/index.php?topic=5744.0
found via GetBatteryCoverClose (which looks in a table that tells it the physw word and bit)
*/
#define BATTCOVER_IDX  2
#define BATTCOVER_FLAG (0x8000)

int get_usb_bit() 
{
	long usb_physw[3];
	usb_physw[USB_IDX] = 0;
	_kbd_read_keys_r2(usb_physw);
	return(( usb_physw[USB_IDX] & USB_MASK)==USB_MASK) ; 
}

void kbd_fetch_data(long*);

long __attribute__((naked)) wrap_kbd_p1_f() ;

static void __attribute__((noinline)) mykbd_task_proceed()
{
	while (physw_run){ 
		_SleepTask(10);

		if (wrap_kbd_p1_f() == 1){ // autorepeat ?
			_kbd_p2_f();
		}
	}
}

// no stack manipulation needed here, since we create the task directly
void __attribute__((naked,noinline))
mykbd_task()
{
    mykbd_task_proceed();

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
    kbd_prev_state[0] = kbd_new_state[0];
    kbd_prev_state[1] = kbd_new_state[1];
    kbd_prev_state[2] = kbd_new_state[2];

    _kbd_pwr_on();

    kbd_fetch_data(kbd_new_state);

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
    _kbd_read_keys_r2(physw_status);

#ifdef CAM_ALLOWS_USB_PORT_FORCING
    if ( forced_usb_port )  physw_status[USB_IDX] = (physw_status[USB_IDX]& ~(SD_READONLY_FLAG)) | USB_MASK ;
    else if (conf.remote_enable)
                            physw_status[USB_IDX] =  physw_status[USB_IDX] & ~(SD_READONLY_FLAG  | USB_MASK);
         else               physw_status[USB_IDX] =  physw_status[USB_IDX] & ~SD_READONLY_FLAG;
#else
    if (conf.remote_enable) physw_status[USB_IDX] =  physw_status[USB_IDX] & ~(SD_READONLY_FLAG  | USB_MASK);
    else                    physw_status[USB_IDX] =  physw_status[USB_IDX] & ~SD_READONLY_FLAG;
#endif

// hide battery door status
#if defined(OPT_RUN_WITH_BATT_COVER_OPEN)
    physw_status[BATTCOVER_IDX] = physw_status[BATTCOVER_IDX] | BATTCOVER_FLAG;
#endif

    _kbd_pwr_off();
}

void kbd_key_press(long key)
{
    int i;
    for (i=0;keymap[i].hackkey;i++){
	if (keymap[i].hackkey == key){
	    kbd_mod_state[keymap[i].grp] &= ~keymap[i].canonkey;
	    return;
	}
    }
}

void kbd_key_release(long key)
{
    int i;
    for (i=0;keymap[i].hackkey;i++){
	if (keymap[i].hackkey == key){
	    kbd_mod_state[keymap[i].grp] |= keymap[i].canonkey;
	    return;
	}
    }
}

void kbd_key_release_all()
{
  kbd_mod_state[0] |= KEYS_MASK0;
  kbd_mod_state[1] |= KEYS_MASK1;
  kbd_mod_state[2] |= KEYS_MASK2;
}

long kbd_is_key_pressed(long key)
{
    int i;
    for (i=0;keymap[i].hackkey;i++){
	if (keymap[i].hackkey == key){
	    return ((kbd_new_state[keymap[i].grp] & keymap[i].canonkey) == 0) ? 1:0;
	}
    }
    return 0;
}

long kbd_is_key_clicked(long key)
{
    int i;
    for (i=0;keymap[i].hackkey;i++){
	if (keymap[i].hackkey == key){
	    return ((kbd_prev_state[keymap[i].grp] & keymap[i].canonkey) != 0) &&
		    ((kbd_new_state[keymap[i].grp] & keymap[i].canonkey) == 0);
	}
    }
    return 0;
}

long kbd_get_pressed_key()
{
    int i;
    for (i=0;keymap[i].hackkey;i++){
	if ((kbd_new_state[keymap[i].grp] & keymap[i].canonkey) == 0){
	    return keymap[i].hackkey;
	}
    }
    return 0;
}

long kbd_get_clicked_key()
{
    int i;
    for (i=0;keymap[i].hackkey;i++){
	if (((kbd_prev_state[keymap[i].grp] & keymap[i].canonkey) != 0) &&
	    ((kbd_new_state[keymap[i].grp] & keymap[i].canonkey) == 0)){
	    return keymap[i].hackkey;
	}
    }
    return 0;
}

#ifdef CAM_USE_ZOOM_FOR_MF
long kbd_use_zoom_as_mf() {
    static long v;
    static long zoom_key_pressed = 0;

    if (kbd_is_key_pressed(KEY_ZOOM_IN) && (mode_get()&MODE_MASK) == MODE_REC) {
        get_property_case(PROPCASE_FOCUS_MODE, &v, 4);
        if (v) {
            kbd_key_release_all();
            kbd_key_press(KEY_RIGHT);
            zoom_key_pressed = KEY_ZOOM_IN;
            return 1;
        }
    } else {
        if (zoom_key_pressed==KEY_ZOOM_IN) {
            kbd_key_release(KEY_RIGHT);
            zoom_key_pressed = 0;
            return 1;
        }
    }
    if (kbd_is_key_pressed(KEY_ZOOM_OUT) && (mode_get()&MODE_MASK) == MODE_REC) {
        get_property_case(PROPCASE_FOCUS_MODE, &v, 4);
        if (v) {
            kbd_key_release_all();
            kbd_key_press(KEY_LEFT);
            zoom_key_pressed = KEY_ZOOM_OUT;
            return 1;
        }
    } else {
        if (zoom_key_pressed==KEY_ZOOM_OUT) {
            kbd_key_release(KEY_LEFT);
            zoom_key_pressed = 0;
            return 1;
        }
    }
    return 0;
}
#endif

static KeyMap keymap[] = {
    /* tiny bug: key order matters. see kbd_get_pressed_key()
     * for example
     */
	// D10 Verified
	{ 2, KEY_UP		    , 0x00000080 }, 
	{ 2, KEY_DOWN		, 0x00000040 },
	{ 2, KEY_LEFT		, 0x00000010 },
	{ 2, KEY_RIGHT		, 0x00000020 },
	{ 2, KEY_SET		, 0x00000100 },
	{ 2, KEY_SHOOT_FULL	, 0x00000003 },
    { 2, KEY_SHOOT_FULL_ONLY, 0x00000002 },
	{ 2, KEY_SHOOT_HALF	, 0x00000001 }, 
	{ 2, KEY_ZOOM_IN	, 0x00000004 },
	{ 2, KEY_ZOOM_OUT	, 0x00000008 },
	{ 2, KEY_MENU		, 0x00000400 },
	{ 2, KEY_DISPLAY	, 0x00000200 },
	{ 2, KEY_PRINT		, 0x00000800 },
	{ 1, KEY_MODE		, 0x20000000 }, // D10 mode select 
	{ 1, KEY_PLAYBACK	, 0x80000000 }, // D10 play button
	{ 0, 0, 0 }
};


void kbd_fetch_data(long *dst)
{
	// OK, FF8470CC
    volatile long *mmio0 = (void*)0xc0220200;
    volatile long *mmio1 = (void*)0xc0220204;
    volatile long *mmio2 = (void*)0xc0220208;

    dst[0] = *mmio0;
    dst[1] = *mmio1;
    dst[2] = *mmio2 & 0xffff;
}
