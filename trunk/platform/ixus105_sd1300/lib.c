#include "platform.h"
#include "lolevel.h"

char *hook_raw_image_addr()
{
	//ffe7b424: 	e59f60dc 	ldr	r6, [pc, #220]	; ffe7b508: (41d64ecc)  *"...AJPEG BUFF       %p ( %lx )"
	return (char*)(0x41d64ecc);
}

char *camera_jpeg_count_str()
{
    extern char jpeg_count_str[];
	return jpeg_count_str;
}

void vid_bitmap_refresh()
{
/*  NOTE: This was the old method, i think the new one performs better
    extern int enabled_refresh_physical_screen;
    enabled_refresh_physical_screen=1;
    _RefreshPhysicalScreen(1);
*/
	extern int full_screen_refresh;
	extern void _ScreenUnlock();
	extern void _ScreenLock();

	full_screen_refresh |= 3;
	_ScreenLock();
	_ScreenUnlock();
}

void shutdown()
{
    volatile long *p = (void*)0xc022001C;

    asm(
         "MRS     R1, CPSR\n"
         "AND     R0, R1, #0x80\n"
         "ORR     R1, R1, #0x80\n"
         "MSR     CPSR_cf, R1\n"
         :::"r1","r0");

    *p = 0x44;

    while(1);
}


#define LED_PR 0xC0220108

void debug_led(int state)
{
    volatile long *p=(void*)LED_PR;
    if (state)
	p[0]=0x46;
    else
	p[0]=0x44;
}

void camera_set_led(int led, int state, int bright)
{
  static char led_table[7]={0,0,1,1,1,9,9};
 if(led >=4 && led <= 10)
  _LEDDrive(led_table[(led-4)%sizeof(led_table)], state<=1 ? !state : state);
}

int get_flash_params_count(void){
 return 0x94;
}

// following width and height works for most modes, except: 320x240 video, stitch, maybe more
int vid_get_viewport_width()
{
    return 360;
}

long vid_get_viewport_height()
{
    return 240;
}


// Viewport and Bitmap values that shouldn't change across firmware versions.
// Values that may change are in lib.c for each firmware version.

// Defined in stubs_min.S
extern char active_viewport_buffer;
extern void* viewport_buffers[];

void *vid_get_viewport_fb()
{
    // Return first viewport buffer - for case when vid_get_viewport_live_fb not defined
    return viewport_buffers[0];
}

void *vid_get_viewport_live_fb()
{
    if (camera_info.state.mode_video)
        return viewport_buffers[0];     // Video only seems to use the first viewport buffer.

    // Hopefully return the most recently used viewport buffer so that motion detect, histogram, zebra and edge overly are using current image data
    return viewport_buffers[(active_viewport_buffer)&3];
}

void *vid_get_viewport_fb_d()
{
    extern char *viewport_fb_d;
	return viewport_fb_d;
}

void *vid_get_bitmap_fb()
{
    return (void*)0x403f1000; // Found @0xffc43628
}


// Functions for PTP Live View system
// 256 entry palette based on 100b 
// sub_FFCD6110  <- Called for a function with 2 ref to **"Palette Class.
int vid_get_palette_type()                      { return 3; }
int vid_get_palette_size()                      { return 256 * 4; }

void *vid_get_bitmap_active_buffer()
{   //found @loc_ffcd61b4 ixus105 100b ->Called before *"..<GetBmpVramInfo> Add
    return (void*)(*(int*)(0x4AD0+0x18)); 
}

void *vid_get_bitmap_active_palette() {
        return (void*)(*(int*)(0x4AD0+0x2C));  //Found @ 0xffcd6110 ixus105 100b
}
