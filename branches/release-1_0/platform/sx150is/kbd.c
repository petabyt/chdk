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


static long kbd_new_state[3];
static long kbd_prev_state[3];
static long kbd_mod_state[3];
static KeyMap keymap[];
static long last_kbd_key = 0;
static int usb_power=0;
static int remote_key, remote_count;
static int shoot_counter=0;
volatile int jogdial_stopped=0;

#define DELAY_TIMEOUT 10000

#define KEYS_MASK0 (0x00000000)
#define KEYS_MASK1 (0x0000F000)
#define KEYS_MASK2 (0x00007F50)

#define SD_READONLY_FLAG    (0x20000) // Found @0xffb90df0, levent 0x20a
#define SD_READONLY_IDX     2

#define USB_MASK              (0x00040000) // Found @0xffb90df8, levent 0x202
#define USB_IDX             2

extern void _platformsub_kbd_fetch_data(long*);
extern void _GetKbdState(long* buffer);
//extern void _GetKbdState2(long* buffer);

static KeyMap keymap[] = {
	// Order IS important. kbd_get_pressed_key will walk down this table  
	// and take the first matching mask. Notice that KEY_SHOOT_HALF is  
	// always pressed if KEY_SHOOT_FULL is. --MarcusSt
    { 2, KEY_VIDEO     , 0x00000010 },
    { 2, KEY_PRINT     , 0x00000040 }, // playback
    { 2, KEY_PLAYBACK  , 0x00000040 }, // alias so script can use it TODO not clear if wee need PRINT version
	{ 2, KEY_UP        , 0x00000100 },
	{ 2, KEY_DOWN      , 0x00000200 },
	{ 2, KEY_RIGHT     , 0x00000400 },
	{ 2, KEY_LEFT      , 0x00000800 },
	{ 2, KEY_SET       , 0x00001000 },
	{ 2, KEY_MENU      , 0x00002000 },
	{ 2, KEY_DISPLAY   , 0x00004000 },
	{ 2, KEY_ERASE     , 0x00008000 },
	{ 1, KEY_ZOOM_IN   , 0x00004000 },
	{ 1, KEY_ZOOM_OUT  , 0x00008000 },
	{ 1, KEY_SHOOT_FULL, 0x00003000 },
    { 1, KEY_SHOOT_FULL_ONLY, 0x00002000 },
	{ 1, KEY_SHOOT_HALF, 0x00001000 },
	{ 0, 0, 0 }
};

void kbd_fetch_data(long*);

long __attribute__((naked)) wrap_kbd_p1_f() ;

void wait_until_remote_button_is_released(void)
{
int count1;
int count2;
int tick,tick2,tick3;
int nSW;
int prev_usb_power,cur_usb_power;

// ------ add by Masuji SUTO (start) --------------
    static int nMode;
 // ------ add by Masuji SUTO (end)   --------------

asm volatile ("STMFD SP!, {R0-R11,LR}\n"); // store R0-R11 and LR in stack

debug_led(1);
tick = get_tick_count();
tick2 = tick;
static long usb_physw[3];
if (conf.synch_enable && conf.ricoh_ca1_mode && conf.remote_enable && (!shooting_get_drive_mode()|| (shooting_get_drive_mode()==1) || ((shooting_get_drive_mode()==2) && state_shooting_progress != SHOOTING_PROGRESS_PROCESSING)))
// if (conf.synch_enable && conf.ricoh_ca1_mode && conf.remote_enable)                                         // synch mode enable so wait for USB to disconnect
  {
// ------ add by Masuji SUTO (start) --------------
        nMode=0;
        usb_physw[2] = 0;                                             // makes sure USB bit is cleared.
        _kbd_read_keys_r2(usb_physw);
        if((usb_physw[2] & USB_MASK)==USB_MASK) nMode=1;
// ------ add by Masuji SUTO (end)   --------------

if(conf.ricoh_ca1_mode && conf.remote_enable)
{
	if(shooting_get_drive_mode() ==1 && state_shooting_progress == SHOOTING_PROGRESS_PROCESSING){			//continuous-shooting mode
		if(conf.bracket_type>2){
			if(shoot_counter<2) shutter_int=3;
			shoot_counter--;
			}
		else{
		prev_usb_power=0;
		nSW = 0;
		do
			{
            usb_physw[2] = 0;                                             // makes sure USB bit is cleared.
           _kbd_read_keys_r2(usb_physw);
			cur_usb_power = (usb_physw[2] & USB_MASK)==USB_MASK;
			if(cur_usb_power){
				if(!prev_usb_power){
					tick2 = get_tick_count();
					prev_usb_power=cur_usb_power;
					}
				else{
					if((int)get_tick_count()-tick2>1000) {debug_led(0);}
					}
				}
			else{
				if(prev_usb_power){
					tick3 = (int)get_tick_count()-tick2;
					if(nSW==10) {
						if(tick3>50) shutter_int=1;
						nSW=20;
						}
					if(nSW==0 && tick3>0) {
						if(tick3<50) {
						nSW=10;
						}
					else{
						if(tick3>1000) shutter_int=1;
							nSW=20;
						}
					}
					prev_usb_power=cur_usb_power;
					}
				}

			if((int)get_tick_count()-tick >= DELAY_TIMEOUT) {nSW=20;shutter_int=2;}
			}
		 while(nSW<20);
		 }
		} 		//continuous-shooting mode
	else{		//nomal mode
			shoot_counter=0;
			if(conf.bracket_type>2){
				shoot_counter=(conf.bracket_type-2)*2;
				}
   do
         {
            usb_physw[2] = 0;                                             // makes sure USB bit is cleared.
           _kbd_read_keys_r2(usb_physw);
           }
 //  while(((usb_physw[2] & USB_MASK)==USB_MASK) && ((int)get_tick_count()-tick < DELAY_TIMEOUT));
// ------ modif by Masuji SUTO (start) --------------
        while(((((usb_physw[2] & USB_MASK)!=USB_MASK) && (nMode==0)) || (((usb_physw[2] & USB_MASK)==USB_MASK) && (nMode==1))) && ((int)get_tick_count()-tick < DELAY_TIMEOUT));
// ------ modif by Masuji SUTO (end)   --------------
 	}
 }

else
   {

      do
          {
            usb_physw[2] = 0;                                             // makes sure USB bit is cleared.
           _kbd_read_keys_r2(usb_physw);

           }
        while((usb_physw[2]&USB_MASK) &&  ((int)get_tick_count()-tick < DELAY_TIMEOUT));
    }

  }

if (conf.synch_delay_enable && conf.synch_delay_value>0)                                // if delay is switched on and greater than 0
  {
    for (count1=0;count1<conf.synch_delay_value+(conf.synch_delay_coarse_value*1000);count1++) // wait delay_value * 0.1ms
    {
      for (count2=0;count2<1400;count2++)            // delay approx. 0.1ms
        {
        }
     }
  }

debug_led(0);
asm volatile ("LDMFD SP!, {R0-R11,LR}\n"); // restore R0-R11 and LR from stack
}

static void __attribute__((noinline)) mykbd_task_proceed()
{

	/* Initialize our own kbd_new_state[] array with the
	   current physical status.
	   */
	kbd_new_state[0] = physw_status[0];
	kbd_new_state[1] = physw_status[1];
	kbd_new_state[2] = physw_status[2];

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
	
	mykbd_task_proceed();
    /* function can be modified to restore SP here...
     */
    _ExitTask();

}

long __attribute__((naked,noinline)) wrap_kbd_p1_f()
{
	// Modified to reflect sx150 code @FF8345D0
    asm volatile(
		"STMFD   SP!, {R1-R7,LR}\n"
		"MOV     R5, #0\n"
		"BL      my_kbd_read_keys\n"
		"B	 _kbd_p1_f_cont\n"
    );

 return 0; // shut up the compiler
}


void my_kbd_read_keys()
{
	static long i=0;

	kbd_prev_state[0] = kbd_new_state[0];
	kbd_prev_state[1] = kbd_new_state[1];
	kbd_prev_state[2] = kbd_new_state[2];

	_GetKbdState(kbd_new_state);

	if (kbd_process() == 0) {
		// leave it alone...
		physw_status[0] = kbd_new_state[0];
		physw_status[1] = kbd_new_state[1];
		physw_status[2] = kbd_new_state[2];
		jogdial_stopped=0;
	}
	else {
		// override keys
		physw_status[0] = (kbd_new_state[0] & (~KEYS_MASK0)) | (kbd_mod_state[0] & KEYS_MASK0);
		physw_status[1] = (kbd_new_state[1] & (~KEYS_MASK1)) | (kbd_mod_state[1] & KEYS_MASK1);
		physw_status[2] = (kbd_new_state[2] & (~KEYS_MASK2)) | (kbd_mod_state[2] & KEYS_MASK2);
		if (!jogdial_stopped && !state_kbd_script_run) {
			jogdial_stopped=1;
			get_jogdial_direction();
		}
		else if (jogdial_stopped && state_kbd_script_run)
			jogdial_stopped=0;
	}

	_kbd_read_keys_r2(physw_status);

	remote_key = (physw_status[2] & USB_MASK)==USB_MASK;


// hack to ignore battery door state
//physw_status[2] |= 0x8000;

	if (remote_key)
		remote_count += 1;
	else if (remote_count) {
		usb_power = remote_count;
		remote_count = 0;
	}

	if (conf.remote_enable)
		physw_status[2] = physw_status[2] & ~(SD_READONLY_FLAG | USB_MASK);
	else
		physw_status[2] = physw_status[2] & ~SD_READONLY_FLAG;
}

int get_usb_power(int edge)
{
	int x;

	if (edge) return remote_key;
	x = usb_power;
	usb_power = 0;
	return x;
}


// NOP
void kbd_set_alt_mode_key_mask(long key)
{
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



long kbd_use_zoom_as_mf() {
	return 0;
}



int Get_JogDial(void) {
 return (*(int*)0xC0240104)>>16;
}



long get_jogdial_direction(void) {
	static int new_jogdial = 0;
	int old_jogdial = 0;

	old_jogdial = new_jogdial;
	new_jogdial = Get_JogDial();

	if (old_jogdial < new_jogdial)
		return JOGDIAL_LEFT;
	else if (old_jogdial > new_jogdial)
		return JOGDIAL_RIGHT;
	else
		return 0;
}
