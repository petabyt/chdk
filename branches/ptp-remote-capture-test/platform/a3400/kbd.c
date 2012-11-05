#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "conf.h"
#include "keyboard.h"

typedef struct {
	short grp;
	short hackkey;
	long canonkey;
} KeyMap;

long kbd_new_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
static long kbd_prev_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
static long kbd_mod_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };

static long last_kbd_key = 0;

extern void _GetKbdState(long*);

//#define DELAY_TIMEOUT 10000
// override key and feather bits to avoid feather osd messing up chdk display in ALT mode
#define KEYS_MASK0         (0x00003000) //Logic OR of group 0 Keymap values
#define KEYS_MASK1         (0xBFF00000) //Logic OR of group 1 Keymap values
#define KEYS_MASK2         (0x00000000) //Logic OR of group 2 Keymap values

#define SD_READONLY_FLAG    0x00020000 // Found @0xffb10078, levent 0x20a
#define SD_READONLY_IDX     2
#define USB_MASK            0x00040000 // Found @0xffb10080, levent 0x202
#define USB_IDX             2

extern void usb_remote_key( void ) ;

int get_usb_bit()
{
        long usb_physw[3];
        usb_physw[USB_IDX] = 0;
        _kbd_read_keys_r2(usb_physw);
        return(( usb_physw[USB_IDX] & USB_MASK)==USB_MASK) ;
}

static KeyMap keymap[] = {
	// Order IS important. kbd_get_pressed_key will walk down this table  
	// and take the first matching mask. Notice that KEY_SHOOT_HALF is  
	// always pressed if KEY_SHOOT_FULL is. --MarcusSt
    { 0, KEY_ZOOM_IN         ,0x00002000 }, // Found @0xffb2fd64, levent 0x02
    { 0, KEY_ZOOM_OUT        ,0x00001000 }, // Found @0xffb2fd5c, levent 0x03
    { 1, KEY_PRINT           ,0x80000000 }, // KEY Playback for ALT menu
    { 1, KEY_DOWN            ,0x00800000 }, // Found @0xffb2fd84, levent 0x05
    { 1, KEY_UP              ,0x00400000 }, // Found @0xffb2fd7c, levent 0x04
    { 1, KEY_SHOOT_FULL      ,0x00300000 }, // Found @0xffb2fd74, levent 0x01
    { 1, KEY_SHOOT_FULL_ONLY ,0x00200000 }, // Found @0xffb2fd74, levent 0x01
    { 1, KEY_SHOOT_HALF      ,0x00100000 }, // Found @0xffb2fd6c, levent 0x00
    { 1, KEY_SET             ,0x08000000 }, // Found @0xffb2fda4, levent 0x08
    { 1, KEY_MENU            ,0x04000000 }, // Found @0xffb2fd9c, levent 0x09
    { 1, KEY_LEFT            ,0x02000000 }, // Found @0xffb2fd94, levent 0x06
    { 1, KEY_RIGHT           ,0x01000000 }, // Found @0xffb2fd8c, levent 0x07
    { 1, KEY_PLAYBACK        ,0x80000000 }, // Found @0xffb2fdc4, levent 0x101
//    { 1, KEY_POWER           ,0x40000000 }, // Found @0xffb2fdbc, levent 0x100
    { 1, KEY_HELP            ,0x20000000 }, // Found @0xffb2fdb4, levent 0x14
    { 1, KEY_VIDEO           ,0x10000000 }, // Found @0xffb2fdac, levent 0x1a
    { 0, 0, 0 }
};

// NOP
void kbd_set_alt_mode_key_mask(long key)
{
}

long __attribute__((naked,noinline)) wrap_kbd_p1_f() {
	
	//a810 @0xFF82D9BC
	asm volatile(
		"STMFD	SP!, {R1-R7,LR} \n"
		"MOV	R5, #0 \n"
		"BL		my_kbd_read_keys \n"	// pached
		"B		_kbd_p1_f_cont \n"
	);
	
	return 0; // shut up the compiler
}

static void __attribute__((noinline)) mykbd_task_proceed() {
	
	while (physw_run) {
		_SleepTask(*((int*)(0x1C18 + 0x8))); //   @FF82E980 + FF82E988  a3400 101a
		if (wrap_kbd_p1_f() == 1) {   // autorepeat ?
			_kbd_p2_f();
		}
	}
}

void __attribute__((naked,noinline)) mykbd_task() {
	
	mykbd_task_proceed();

	_ExitTask();
}

void my_kbd_read_keys() {

	kbd_prev_state[0] = kbd_new_state[0];
	kbd_prev_state[1] = kbd_new_state[1];
	kbd_prev_state[2] = kbd_new_state[2];

	_GetKbdState(kbd_new_state);
	_kbd_read_keys_r2(kbd_new_state);
	
	if (kbd_process() == 0) {
		// we read keyboard state with _kbd_read_keys()
		physw_status[0] = kbd_new_state[0];
		physw_status[1] = kbd_new_state[1];
		physw_status[2] = kbd_new_state[2];
	} else {
		// override keys
		physw_status[0] = (kbd_new_state[0] | KEYS_MASK0) & (~KEYS_MASK0 | kbd_mod_state[0]); 
		physw_status[1] = (kbd_new_state[1] | KEYS_MASK1) & (~KEYS_MASK1 | kbd_mod_state[1]); 
		physw_status[2] = (kbd_new_state[2] | KEYS_MASK2) & (~KEYS_MASK2 | kbd_mod_state[2]);
	}

        usb_remote_key() ;

        if (conf.remote_enable) {
                physw_status[USB_IDX] = physw_status[USB_IDX] & ~(SD_READONLY_FLAG | USB_MASK);
        } else {
                physw_status[USB_IDX] = physw_status[USB_IDX] & ~SD_READONLY_FLAG;
        }

}


void kbd_key_press(long key) {
	
	int i;
	
	for (i=0;keymap[i].hackkey;i++) {
		if (keymap[i].hackkey == key) {
			kbd_mod_state[keymap[i].grp] &= ~keymap[i].canonkey;
			return;
		}
	}
}

void kbd_key_release(long key) {
	
	int i;
	
	for (i=0;keymap[i].hackkey;i++) {
		if (keymap[i].hackkey == key) {
			kbd_mod_state[keymap[i].grp] |= keymap[i].canonkey;
			return;
		}
	}
}

void kbd_key_release_all() {

	kbd_mod_state[0] |= KEYS_MASK0;
	kbd_mod_state[1] |= KEYS_MASK1;
	kbd_mod_state[2] |= KEYS_MASK2;
}

long kbd_is_key_pressed(long key) {
	
	int i;
	
	for (i=0;keymap[i].hackkey;i++) {
		if (keymap[i].hackkey == key) {
			return ((kbd_new_state[keymap[i].grp] & keymap[i].canonkey) == 0) ? 1:0;
		}
	}
	return 0;
}

long kbd_is_key_clicked(long key) {
	
	int i;
	
	for (i=0;keymap[i].hackkey;i++) {
		if (keymap[i].hackkey == key) {
			return ((kbd_prev_state[keymap[i].grp] & keymap[i].canonkey) != 0) &&
			((kbd_new_state[keymap[i].grp] & keymap[i].canonkey) == 0);
		}
	}
	return 0;
}

long kbd_get_pressed_key() {
	
	int i;
	
	for (i=0;keymap[i].hackkey;i++) {
		if ((kbd_new_state[keymap[i].grp] & keymap[i].canonkey) == 0) {
			return keymap[i].hackkey;
		}
	}
	return 0;
}

long kbd_get_clicked_key() {
	
	int i;
	
	for (i=0;keymap[i].hackkey;i++) {
		if (((kbd_prev_state[keymap[i].grp] & keymap[i].canonkey) != 0) &&
		((kbd_new_state[keymap[i].grp] & keymap[i].canonkey) == 0)) {
			return keymap[i].hackkey;
		}
	}
	return 0;
}

void kbd_reset_autoclicked_key() {
	last_kbd_key = 0;
}

long kbd_get_autoclicked_key() {
	
	static long last_kbd_time = 0, press_count = 0;
	register long key, t;
	
	key=kbd_get_clicked_key();
	if (key) {
		last_kbd_key = key;
		press_count = 0;
		last_kbd_time = get_tick_count();
		return key;
	} else {
		if (last_kbd_key && kbd_is_key_pressed(last_kbd_key)) {
			t = get_tick_count();
			if (t-last_kbd_time>((press_count)?175:500)) {
				++press_count;
				last_kbd_time = t;
				return last_kbd_key;
			} else {
				return 0;
			}
		} else {
			last_kbd_key = 0;
			return 0;
		}
	}
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


