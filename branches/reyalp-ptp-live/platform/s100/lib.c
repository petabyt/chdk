#include "platform.h"
#include "lolevel.h"

static char*    frame_buffer[2];

void vid_bitmap_refresh()
{
	extern int full_screen_refresh;
	extern void _ScreenUnlock();
	extern void _ScreenLock();

	full_screen_refresh |= 3;
	_ScreenLock();
	_ScreenUnlock();
}

void shutdown()
{
	volatile long *p = (void*)0xC022001C; //TODO: didn't check this

	asm(
		"MRS     R1, CPSR\n"
		"AND     R0, R1, #0x80\n"
		"ORR     R1, R1, #0x80\n"
		"MSR     CPSR_cf, R1\n"
		:::"r1","r0");

	*p = 0x44;  // power off.

	while(1);
}

#define LED_PR 0xC022C30C	// Power LED (@FF15B178 & @FF15B1CC)

void debug_led(int state)
{
	// using power LED, which defaults to on
	// for debugging turn LED off if state is 1 and on for state = 0
	// leaves LED on at end of debugging
    volatile long *p = (void*)LED_PR;
    *p = (*p & 0xFFFFFFCF) | ((state) ? 0x00 : 0x20);
}

// S100 has two 'lights' - Power LED, and AF assist lamp
// Power Led = first entry in table (led 0)
// AF Assist Lamp = second entry in table (led 1)
void camera_set_led(int led, int state, int bright) {
 static char led_table[2]={7,10};
 _LEDDrive(led_table[led%sizeof(led_table)], state<=1 ? !state : state);
}

void shutdown_soft()
{
   _PostLogicalEventForNotPowerType(0x1005,0);
}

void JogDial_CW(void){ //TODO: find correct value
	_PostLogicalEventForNotPowerType(0x874, 1);  // RotateJogDialRight
}

void JogDial_CCW(void){ //TODO: find correct value
	_PostLogicalEventForNotPowerType(0x875, 1);  // RotateJogDialLeft
}

int vid_get_viewport_width()
{
	return 360;
}

long vid_get_viewport_height()
{
   return 240;
}

// Y multiplier for cameras with 480 pixel high viewports (CHDK code assumes 240)
int vid_get_viewport_yscale() {
	return 2;
}

void *vid_get_viewport_live_fb()
{
    return vid_get_viewport_fb();
}

