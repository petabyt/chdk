#include "platform.h"
#include "lolevel.h"

/*
void vid_bitmap_refresh() //ASM1989
{
 extern int enabled_refresh_physical_screen;
 enabled_refresh_physical_screen=1;
 *(int*)0x9D08=3;//this is set somewhere in a function called by RefreshPhysicalScreen, should be easy to find
 _RefreshPhysicalScreen(1);
}

*/


void vid_bitmap_refresh()
{
	extern int enabled_refresh_physical_screen;
	extern int full_screen_refresh;

	// i've tried refreshphysical screen (screen unlock) and that caused the canon and
	// function menu to not display at all. This seems to work and is called in a similar
	// way in other places where original OSD should be refreshed.
	extern void _LockAndRefresh(); // wrapper function for screen lock
	extern void _UnlockAndRefresh(); // wrapper function for screen unlock

	_LockAndRefresh();

	enabled_refresh_physical_screen=1;
	full_screen_refresh=3; //found in ScreenUnlock underneath a CameraLog.c call sub_FFA02598

	_UnlockAndRefresh();
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

#define LED_PR 0xC0220130    // -> C0223030 front led ASM1989 08.24.2010 found at  FF8E73F0  in sx200 was FF91E09C


void debug_led(int state)
{
 *(int*)LED_PR=state ? 0x46 : 0x44;
}

void camera_set_led(int led, int state, int bright) {
 static char led_table[5]={4,5,7,8,9};
 _LEDDrive(led_table[led%sizeof(led_table)], state<=1 ? !state : state);
}

int get_flash_params_count(void){
 return 120;
}

void JogDial_CW(void){
 _PostLogicalEventForNotPowerType(0x875, 2);  // RotateJogDialRight  old 874 old 877 ???
}

void JogDial_CCW(void){
 _PostLogicalEventForNotPowerType(0x876, 2);  // RotateJogDialLeft  old 875
}


//ASm1989 like sx30 testing

// Viewport and Bitmap values that shouldn't change across firmware versions.
// Values that may change are in lib.c for each firmware version.

long vid_get_bitmap_screen_width() { return 480; }
long vid_get_bitmap_screen_height() { return 240; }
long vid_get_bitmap_buffer_width() { return 960; }
long vid_get_bitmap_buffer_height() { return 270; }



//This cam is 0 -> 16:9,  1 -> 4:3

int vid_get_viewport_width()
{
	// viewport width table for each image size
	// 0 = 4:3, 1 = 16:9, 2 = 3:2, 3 = 1:1, 4 = 4:5
	static long vp_w[5] = { 480, 360, 360, 272, 216 };
	return vp_w[shooting_get_prop(PROPCASE_ASPECT_RATIO)];
}

int vid_get_viewport_xoffset()
{
	// viewport width offset table for each image size
	// 0 = 4:3, 1 = 16:9, 2 = 3:2, 3 = 1:1, 4 = 4:5
	static long vp_w[5] = { 0, 60, 0, 44, 72 };				// should all be even values for edge overlay
	return vp_w[shooting_get_prop(PROPCASE_ASPECT_RATIO)];
}

long vid_get_viewport_height()
{
	// viewport height table for each image size
	// 0 = 4:3, 1 = 16:9, 2 = 3:2, 3 = 1:1, 4 = 4:5
	static long vp_h[5] = { 240, 240, 214, 240, 240 };
	return vp_h[shooting_get_prop(PROPCASE_ASPECT_RATIO)];
}

int vid_get_viewport_yoffset()
{
	// viewport height offset table for each image size
	// 0 = 4:3, 1 = 16:9, 2 = 3:2, 3 = 1:1, 4 = 4:5
	static long vp_h[5] = { 0, 0, 13, 0, 0 };
	return vp_h[shooting_get_prop(PROPCASE_ASPECT_RATIO)];
}
