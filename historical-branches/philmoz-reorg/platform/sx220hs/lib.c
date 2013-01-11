#include "platform.h"
#include "lolevel.h"

void vid_bitmap_refresh()
{
 	extern int full_screen_refresh;
	extern void _LockAndRefresh(); // wrapper function for screen lock
	extern void _UnlockAndRefresh(); // wrapper function for screen unlock

	full_screen_refresh |= 3; //found in ScreenUnlock
	_LockAndRefresh();	
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

#define LED_PR 0xC0220130


void debug_led(int state)
{
 *(int*)LED_PR=state ? 0x46 : 0x44;
}

void camera_set_led(int led, int state, int bright) {
 static char led_table[2]={0,9};
 _LEDDrive(led_table[led%sizeof(led_table)], state<=1 ? !state : state);
}

int get_flash_params_count(void){
 return 0xA0;  //@FF1B33A0 in GetParameterData
}

void JogDial_CW(void){
 _PostLogicalEventForNotPowerType(0x86E, 1);  // @FF416880
}

void JogDial_CCW(void){
 _PostLogicalEventForNotPowerType(0x86F, 1);  // @FF41688C
}


// Viewport and Bitmap values that shouldn't change across firmware versions.
// Values that may change are in lib.c for each firmware version.

// Defined in stubs_min.S
extern int active_bitmap_buffer;
extern char* bitmap_buffer[];

// Physical width of viewport row in bytes
int vid_get_viewport_byte_width() {
	return 960 * 6 / 4;     // SX220HS - wide screen LCD is 960 pixels wide, each group of 4 pixels uses 6 bytes (UYVYYY)
}

// Y multiplier for cameras with 480 pixel high viewports (CHDK code assumes 240)
int vid_get_viewport_yscale() {
	return 2;               // SX220HS viewport is 480 pixels high
}


int vid_get_viewport_width()
{
	// viewport width table for each image size
	// 0 = 4:3, 1 = 16:9, 2 = 3:2, 3 = 1:1
	static long vp_w[4] = { 360, 480, 360, 272 };
    if((mode_get()&MODE_MASK) == MODE_PLAY) {
        return 480;
    }
	return vp_w[shooting_get_prop(PROPCASE_ASPECT_RATIO)];
}

int vid_get_viewport_display_xoffset()
{
	// viewport width offset table for each image size
	// 0 = 4:3, 1 = 16:9, 2 = 3:2, 3 = 1:1
	static long vp_w[4] = { 60, 0, 36, 104 };				// should all be even values for edge overlay
    if((mode_get()&MODE_MASK) == MODE_PLAY) {
        return 0;
    }
	return vp_w[shooting_get_prop(PROPCASE_ASPECT_RATIO)];
}

long vid_get_viewport_height(){ return 240; }

// Functions for PTP Live View system

int vid_get_viewport_height_proper()            { return 480; }
int vid_get_viewport_buffer_width_proper()                { return 960; }
int vid_get_viewport_fullscreen_height()               { return 480; }
int vid_get_palette_type()                      { return 3; }
int vid_get_palette_size()                      { return 256 * 4; }
int vid_get_aspect_ratio()                      { return 1; }

void *vid_get_bitmap_active_buffer()
{
    return bitmap_buffer[active_bitmap_buffer];
}

void *vid_get_bitmap_active_palette()
{
    extern int active_palette_buffer;
    extern char* palette_buffer[];
    return (palette_buffer[active_palette_buffer]+8);
}
