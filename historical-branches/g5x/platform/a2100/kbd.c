/*
###########################################################
###########################################################
#############[ FINISHED ] #################################
###########################################################
###########################################################
*/


#include "lolevel.h"
#include "platform.h"
#include "keyboard.h"
#include "kbd_common.h"

// changed for A2100IS
#define LED_PWR 0xC0220014      // A2100IS Green - power led 
#define LED_DP 0xC0220018		// A2100IS Blue - Direct Print led 
#define LED_AF 0xC022000C		// A2100IS Red - AutoFocus led 
#define DELAY 5000000

/* 
// #define KEYS_MASK0 (0x00000000)
// #define KEYS_MASK1 (0x11111111)
// #define KEYS_MASK2 (0x00000001) 

// PS2_orig: 0x7f1424eb
// PS2_mod:  0x  1404eb
// MSK: 0x07000000
// DFF: 0x7f002000


// originally:
// PS1: 0x3000{1,9,d}882
// PS2: 0x7f{1,0}424eb
// PS3: 0x224f3e

//aftermod:
// #define KEYS_MASK1 (0x07000000)
// #define KEYS_MASK2 (0x00000F48) 
// PS1: 0x30001882
// PS2: 0x{_,1}404eb
// PS3: 0x20400c

// on PWR_BTN press PS3: 	0x20404c
// on SHOOT HALF press PS3:	0x204008
// on SHOOT FULL press PS3:	0x204000
// on PLAY press PS3: 		0x20408c

// #define KEYS_MASK0 (0x00000003)
// #define KEYS_MASK1 (0x000FFE18)
// #define KEYS_MASK2 (0x00000000) 


// #define KEYS_MASK0 (0x00000000)
// #define KEYS_MASK1 (0x7000000)
// #define KEYS_MASK2 (0xF48) 



orig:
PS1: 0x30001882
PS2: 0x7f0424eb
PS3: 0x224f3e
							 0x7f0424eb
Disp btn pressed:		PS2: 0x7b0424eb
Menu btn pressed:		PS2: 0x7d0424eb
DP btn   pressed:		PS2: 0x770424eb
FUNC set pressed:		PS2: 0x7e0424eb

// with commented functions:
PS1: 0x20000102
PS2: 0x7f0025a3
PS3: 0x224f3e

// with custom reader:
PS1: 0x30001882
PS2: 0x1404eb
PS3: 0x22400c

PS2df: 0x7EF02000
PS3df:	  f32	

  1000000000000000000000000
 10000000000000000000000000
100000000000000000000000000
111000000000000000000000000

KEY_MASK1=7000000
KEY_MASK2=F3C
       10000
      100000
   100000000
  1000000000
 10000000000
100000000000
        1100
        1000
         100 
111100111100 = F3C
*/

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



/*
PS2: 0xFF1424EB

On "Smile" PS2: 0xEF1424EB
on DP		PS2:0xF71424EB
@0xffe71624, levent 0x08 0x1010238, 8, 1,


PS3 normal:	  0x204f3f
PS3 on PLAY	: 0x204fbf



  { 1, KEY_PRINT         ,0x08000000 }, // Found manually
*/
KeyMap keymap[] = {
   { 1, KEY_SET             ,0x01000000 }, // Found @0xffe71624, levent 0x08 0x1010238, 8, 1,
   { 1, KEY_MENU            ,0x02000000 }, // Found @0xffe71630, levent 0x09
   { 1, KEY_DISPLAY         ,0x04000000 }, // Found @0xffe7163c, levent 0x0a 0x101023A, 0xA, 1
   { 1, KEY_PRINT           ,0x08000000 }, // Found manually
   { 1, KEY_FACE            ,0x10000000 }, // Found manually
   { 2, KEY_ZOOM_IN         ,0x00000010 }, // Found @0xffe716b4, levent 0x02
   { 2, KEY_ZOOM_OUT        ,0x00000020 }, // Found @0xffe716c0, levent 0x03 0x1010245, 3, 1
   { 2, KEY_UP              ,0x00000100 }, // Found @0xffe716e4, levent 0x04 0x1010248, 4, 1,
   { 2, KEY_DOWN            ,0x00000200 }, // Found @0xffe716f0, levent 0x05 0x1010249, 5, 1
   { 2, KEY_RIGHT           ,0x00000400 }, // Found @0xffe716fc, levent 0x07
   { 2, KEY_LEFT            ,0x00000800 }, // Found @0xffe71708, levent 0x06
   { 2, KEY_SHOOT_FULL      ,0x0000000c }, // Found @0xffe716a8, levent 0x01
   { 2, KEY_SHOOT_FULL_ONLY ,0x00000008 }, // Found @0xffe716a8, levent 0x01
   { 2, KEY_SHOOT_HALF      ,0x00000004 }, // Found @0xffe7169c, levent 0x00
   { 0, 0, 0 }
};

long __attribute__((naked)) wrap_kbd_p1_f() ;

// no stack manipulation needed here, since we create the task directly
void __attribute__((noinline)) mykbd_task() {
// volatile long *p1 = (void*)LED_PWR;
// volatile long *p2 = (void*)LED_DP;
// int counter;	
// // DEBUG: blink led
// counter = DELAY; *p1 = 0x46;*p2 = 0x46;  while (counter--) { asm("nop\n nop\n"); };
// counter = DELAY; *p1 = 0x44;*p2 = 0x44;  while (counter--) { asm("nop\n nop\n"); }; 

	while (physw_run){
		_SleepTask(10) ;  //	*((int*)(0x1c30+0x14)));
/*
		// asm volatile (
		// "LDR R5, =0xC0220018\n"
		// "MOV R6, #0x46\n"
		// "STR R6,[R5]\n"
		// );
		// counter = 2000000; while (counter--) { asm("nop\n nop\n"); };
		// asm volatile (
		// "LDR R5, =0xC0220018\n"
		// "MOV R6, #0x44\n"
		// "STR R6,[R5]\n"
		// );
		// counter = 2000000; while (counter--) { asm("nop\n nop\n"); };
*/
		
		 if (wrap_kbd_p1_f() == 1){ // autorepeat ?
			_kbd_p2_f();
		 }
	}

    _ExitTask();
}

long __attribute__((naked,noinline)) wrap_kbd_p1_f() {
	asm volatile(
		"STMFD   SP!, {R1-R5,LR}\n"
		"MOV     R4, #0\n"
	//	"BL      _kbd_read_keys \n"
		"BL		my_kbd_read_keys\n" // replaced temporary
		"B       _kbd_p1_f_cont\n"
	);
	return 0; // shut up the compiler
}


void kbd_fetch_data(long *dst){
	_GetKbdState(dst);
	

	/* Get the rest of the buttons */
	// NSTUB(kbd_read_keys                           ,0xffc11a0c) //109
	// NSTUB(kbd_read_keys_r2                        ,0xffc304dc) //109
	_kbd_read_keys_r2(dst); // without this PS3 is almost empty: PS3: 0x400c

    /*
    volatile long *mmio0 = (void*)0xc0220200;
    volatile long *mmio1 = (void*)0xc0220204;
    volatile long *mmio2 = (void*)0xc0220208;

    dst[0] = *mmio0;
    dst[1] = *mmio1;// | 0x7EF02000;
    dst[2] = *mmio2;// | 0xf32;
//  dst[2] = *mmio2;
*/
}

void my_kbd_read_keys() {
	_kbd_pwr_on();  // i.e. kbd_pwr_on	ROM:FFC11A28                 BL      _sub_FFC30B94__PhySwGpio.c__0 ; LOCATION: PhySwGpio.c:0
    kbd_update_key_state();
    kbd_update_physw_bits();
// _kbd_pwr_off();
}


