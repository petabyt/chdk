/*
*********************
SX150IS
********************** 
*/

/*
SX150
LED address:
orange 0xC0220010
AF      0xC022000C
*/
#define LED_AF		0xC022000C
#define LED_GREEN	0xC0220014

#define LED_ON 		*((long*) LED_GREEN) = 0x46
#define LED_OFF		*((long*) LED_GREEN) = 0x44

void debug_led(int state)
{
    if (state)
		LED_ON;
    else
		LED_OFF;
} 

#include "platform.h"
#include "lolevel.h"

void vid_bitmap_refresh()
{
	extern int full_screen_refresh;
	extern void _Screenlock();
	extern void _ScreenUnlock();

	full_screen_refresh |= 3;
	_ScreenLock();
	_ScreenUnlock();
}

void shutdown()
{
	volatile long *p = (void*)0xC022001C;    
	
	asm(
		"MRS     R1, CPSR\n"
		"AND     R0, R1, #0x80\n"
		"ORR     R1, R1, #0x80\n"
		"MSR     CPSR_cf, R1\n"
		:::"r1","r0");
	
	*p = 0x44;  // power off.
	
	while(1);
}


/*
7 = green indicator
9 = AF
*/
void camera_set_led(int led, int state, __attribute__ ((unused))int bright) {
 static char led_table[]={7,9};
 _LEDDrive(led_table[led%sizeof(led_table)], state<=1 ? !state : state);
}

int get_flash_params_count(void){
 return 0x9f; 
}

void JogDial_CW(void){
  _PostLogicalEventToUI(0x872, 1);  // RotateJogDialRight, 2nd parameter = number of clicks
}

void JogDial_CCW(void){
  _PostLogicalEventToUI(0x873, 1);  // RotateJogDialLeft, 2nd parameter = number of clicks
}


// Functions for PTP Live View system
int vid_get_palette_type()                      { return 3; }
int vid_get_palette_size()                      { return 256 * 4; }

void *vid_get_bitmap_active_buffer()
{
    extern int active_bitmap_buffer;
    extern char* bitmap_buffer[];
    return bitmap_buffer[active_bitmap_buffer];
}

void *vid_get_bitmap_active_palette()
{
    extern int active_palette_buffer;
    extern char* palette_buffer[];
    void* p = palette_buffer[active_palette_buffer];
    // Don't add offset if value is 0
    if (p) p += 4;
    return p;
}
