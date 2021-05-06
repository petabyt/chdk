#include "platform.h"
#include "lolevel.h"
#include "leds.h"

void shutdown()
{
	// 0xC0220000+0x1C @ FF829C28
	volatile long *p = (void*)0xC022001C;

	asm(
		"MRS     R1, CPSR\n"
		"AND     R0, R1, #0x80\n"
		"ORR     R1, R1, #0x80\n"
		"MSR     CPSR_cf, R1\n"
		:::"r1","r0");

	*p = 0x44;

	while(1);
}

// 0x73 @ FF95D974
int get_flash_params_count(void) { return 115; }

void debug_led(int state)
{
	*(int*)LED_PR = state ? 0x46 : 0x44;
}

void camera_set_led(int led, int state, __attribute__ ((unused))int bright)
{
	static char led_table[5]={4,5,7,8,9};
	_LEDDrive(led_table[led%sizeof(led_table)], state<=1 ? !state : state);
}

void JogDial_CW(void)
{
	_PostLogicalEventToUI(0x866, 2);  // RotateJogDialRight
}

void JogDial_CCW(void)
{
	_PostLogicalEventToUI(0x867, 2);  // RotateJogDialLeft
}

// PTP display stuff
// TODO type may not be correct
int vid_get_palette_type() { return 1; }
int vid_get_palette_size() { return 16*4; }

void *vid_get_bitmap_active_palette() 
{
    return (void *)0x3ef90;        //100b Found @ 0xff8eaa40 - Two refs to "BmpDDev"
}

void *vid_get_bitmap_active_buffer() 
{
    return (void*)(*(int*)0x7EC4); //100b Found @ 0xff8eaa40 - Two refs to "BmpDDev"
}

