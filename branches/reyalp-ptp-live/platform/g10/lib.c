#include "platform.h"
#include "lolevel.h"

void vid_bitmap_refresh()    // G10 : ixus980_sd990 version seems to work well
{
	_ScreenLock();
    _RefreshPhysicalScreen(1);
}


void shutdown()    // G10 sub_FF829EC8
{
	volatile long *p = (void*)0xC022001C;    // G10 @ 0xFF829EE4,0xFF829EE8 & 0xFF829EEC 
	
	asm(
		"MRS     R1, CPSR\n"
		"AND     R0, R1, #0x80\n"
		"ORR     R1, R1, #0x80\n"
		"MSR     CPSR_cf, R1\n"
		:::"r1","r0");
	
	*p = 0x44;  // power off.
	
	while(1);
}


// 0xC02200D0  G10 ISO select dial LED
// 0xC02200D4  G10 direct print button LED
// 0xC02200D8  G10 exposure compensation dial LED
// 0xC02200DC  G10 power LED
// 0xC0220130  G10 Upper Indicator Orange (looks yellow if both upper indicators lit)
// 0xC0220134  G10 Upper Indicator Green
// 0xC0220138  G10 Lower Indicator Yellow
#define LED_PR 	0xC02200D4	//  G10 direct print button LED

void debug_led(int state)
{
  *(int*)LED_PR=state ? 0x46 : 0x44;
}

// G10 has 8 led values - tested with uBasic  set_led n, 1   (no brightness control implemented)
// #  Index   LED
// 1   0      Upper indicator Green
// 2   1      Upper indicator Orange
// 3   2      Lower indicator Yellow
// 4   3      Power LED Green
// 5   8      Blue print button LED
// 6   9      AF Assist Lamp
//     10     "
//     11     "
// 7   14     ISO LED
// 8   15     EV LED

void camera_set_led(int led, int state, int bright) {
 static char led_table[8]={0,1,2,3,8,9,14,15};
 _LEDDrive(led_table[led%sizeof(led_table)], state<=1 ? !state : state);
}

int get_flash_params_count(void){
 return 0x78 ;		// G10 per SD990 & finsig2 - _sub_FF971C10__PropertyTableManagerCore.c__6 value at 0xff971c50 in 1.02a
 // found in GetParameterData
}

void JogDial_CW(void){
 _PostLogicalEventForNotPowerType(0x86E, 1);  // RotateJogDialRight (G10 1.02A table @ FFB43EEC)
}

void JogDial_CCW(void){
 _PostLogicalEventForNotPowerType(0x86F, 1);  // RotateJogDialLeft (G10 1.02A table @ FFB43EF8)
}

// Viewport and Bitmap values that shouldn't change across firmware versions.
// Values that may change are in lib.c for each firmware version.

int vid_get_viewport_width()
{
	return 360 ;   //  G10
}

long vid_get_viewport_height()
{
   return 240;    //  G10
}

// Y multiplier for cameras with 480 pixel high viewports (CHDK code assumes 240)
int vid_get_viewport_yscale() {
	return 2;               // G10 viewport is 480 pixels high
}

// looks like 256 byte from sub_FF8F3270
int vid_get_palette_type() { return 3; }
int vid_get_palette_size() { return 256*4; }

// TODO actual value probably varies in some cases
int vid_get_viewport_height_proper() { return 480; }
int vid_get_viewport_fullscreen_height() { return 480; }
