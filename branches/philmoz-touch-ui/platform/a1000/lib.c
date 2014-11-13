#include "platform.h"
#include "lolevel.h"

void shutdown()
{
    volatile long *p = (void*)0xc02200a0;
	
	asm(
		"MRS     R1, CPSR\n"
		"AND     R0, R1, #0x80\n"
		"ORR     R1, R1, #0x80\n"
		"MSR     CPSR_cf, R1\n"
		:::"r1","r0");
	
    *p = 0x44;
	
	while(1);
}


#define LED_PR 0xc02200C4

void debug_led(int state)
{
    volatile long *p=(void*)LED_PR;
	if (state)
	p[0]=0x46;
	else
	p[0]=0x44;
}

#define LED_AF 0xc0220080

int get_flash_params_count(void){
	return 119; // Found at ROM:FF972F9C (S5IS 1.01b) => ROM:FF93D3E4
}

char *camera_jpeg_count_str()
{
    extern char jpeg_count_str[];
    return jpeg_count_str;
}

void camera_set_led(int led, int state, int bright) { 
        struct led_control led_c; 
        char convert_table[11]={0,1,2,3,0,2,3,1,8,10,10};  // s3 to a710 (and a720) convert table

        //char convert_table[6]={0,1,2,3,8,10};  // Test a720, values 0-5 are valid

        // 0 gr  
        // 1 red 
        // 2 yel 
        // 3 pw  
        // 8 dp  
        // 9 af  

        led_c.led_num=convert_table[led%11]; 
        led_c.action=state<=1 ? !state : state; 
        led_c.brightness=bright; 
        led_c.blink_count=255; 
        _PostLEDMessage(&led_c); 
} 

void vid_bitmap_refresh() //as used in other models
{
        extern int enabled_refresh_physical_screen;
        enabled_refresh_physical_screen=1;
        _RefreshPhysicalScreen(1);
}

// PTP display stuff
// 64 entry palette based on 100a 0xffcc4f24 by comparison to a495 100f
int vid_get_palette_type() { return 4; }
int vid_get_palette_size() { return 16*4; }

void *vid_get_bitmap_active_palette() {
    return (void *)*(unsigned int*)(0x7534+0x20);  // 100a/100b: sub_ffcc4f24, via sub_ffd75e50 two refs to "Palette Class."
}
void *vid_get_bitmap_active_buffer()
{
    return (void*)(*(int*)(0x7534+0x0c)); // 100a/100b: sub_ffcc4fe8, via "Add: %p Width : %ld Hight : %ld"
}


// Viewport and Bitmap values that shouldn't change across firmware versions.
// Values that may change are in lib.c for each firmware version.

void *vid_get_viewport_fb_d()
{
    extern char *viewport_fb_d;
    return viewport_fb_d;
}

void *vid_get_bitmap_fb(){
    return (void*)0x10361000;
}

void *vid_get_viewport_fb()
{
	return (void*)0x10659DE0;
}

int vid_get_viewport_yoffset() {
    return 0;
}

extern int _GetVRAMHPixelsSize();
extern int _GetVRAMVPixelsSize();

int vid_get_viewport_width() {
    return 360;
}

int vid_get_viewport_width_proper() {
    return ((mode_get()&MODE_MASK) == MODE_PLAY)?720:_GetVRAMHPixelsSize();
}

long vid_get_viewport_height() {
    return 240;
}

int vid_get_viewport_height_proper() {
    int m = mode_get();
    // special case: W resolution
    if ((m&MODE_MASK) != MODE_PLAY && shooting_get_prop(PROPCASE_RESOLUTION) == 8) {
        return 240;
    }
    return ((mode_get()&MODE_MASK) == MODE_PLAY)?240:_GetVRAMVPixelsSize();
}

int vid_get_viewport_fullscreen_height() {
    int m = mode_get();
    // special case: W resolution
    if ((m&MODE_MASK) != MODE_PLAY && shooting_get_prop(PROPCASE_RESOLUTION) == 8) {
        return 120;
    }
    return ((mode_get()&MODE_MASK) == MODE_PLAY)?240:_GetVRAMVPixelsSize();
}

int vid_get_viewport_display_xoffset_proper()   { return vid_get_viewport_display_xoffset(); }
int vid_get_viewport_display_yoffset_proper()   { return vid_get_viewport_display_yoffset(); }

