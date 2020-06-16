#include "platform.h"
#include "lolevel.h"

void vid_bitmap_refresh()
{
	extern int enabled_refresh_physical_screen;
	extern int full_screen_refresh;

	// i've tried refreshphysical screen (screen unlock) and that caused the canon and
	// function menu to not display at all. This seems to work and is called in a similar
	// way in other places where original OSD should be refreshed.
	extern void _ScreenLock();
	extern void _ScreenUnlock();

	_ScreenLock();

	enabled_refresh_physical_screen=1;
	full_screen_refresh=3; //found in ScreenUnlock underneath a CameraLog.c call sub_FFA02598

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

#define LED_PR 0xC02200B6  // tally

void debug_led(int state)
{
 //*(int*)LED_PR=state ? 0x46 : 0x44;
}

void camera_set_led(int led, int state, int bright) {
 static char led_table[5]={4,5,7,8,9};
 _LEDDrive(led_table[led%sizeof(led_table)], state<=1 ? !state : state);
}

int get_flash_params_count(void){
 return 120; 
}

void JogDial_CW(void){
	_PostLogicalEventToUI(0x876, 1);  // RotateJogDialRight
}

void JogDial_CCW(void){
	_PostLogicalEventToUI(0x877, 1);  // RotateJogDialLeft
}

void *vid_get_viewport_live_fb() // found in sub_FF84DDB8
{
  void **fb=(void **)0x222C;
  unsigned char buff = *((unsigned char*)0x206C);
  if (buff == 0) buff = 2;  else buff--;    
  return fb[buff];
}

//TODO
// Functions for PTP Live View system
int vid_get_palette_type()                      { return 3 ; }
int vid_get_palette_size()                      { return 256 * 4 ; }

void *vid_get_bitmap_active_palette()
{
    extern int active_palette_buffer;
    extern char** palette_buffer_ptr;
    return palette_buffer_ptr[active_palette_buffer]+8;
}
