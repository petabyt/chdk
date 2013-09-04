#include "platform.h"
#include "lolevel.h"

void vid_bitmap_refresh()
{
    extern int full_screen_refresh;
    extern void _ScreenLock();
    extern void _ScreenUnlock();

    full_screen_refresh |= 3;
    _ScreenLock();
    _ScreenUnlock();
}

// TODO not really complete, last call from task_Bye
void shutdown()
{
    extern void _finish_shutdown(void);
    _finish_shutdown();
    while(1);
}


// TODO AF led for now
#define LED_PR 0xc0223030 // red LED, no DP

void debug_led(int state)
{
    volatile long *p=(void*)LED_PR;
    if (state)
	p[0]=0x46;
    else
	p[0]=0x44;
}

// TODO
void camera_set_led(int led, int state, int bright) {
 /*
 static char led_table[]={0,1,9};
 _LEDDrive(led_table[led%sizeof(led_table)], state<=1 ? !state : state);
 */
}

char *camera_jpeg_count_str()
{
    extern char jpeg_count_str[];
	return jpeg_count_str;
}

int get_flash_params_count(void) { return 0x91; }                          // Found @0xff2075ac


void *vid_get_bitmap_fb()        { return (void*)0x406b1000; }             // Found @0xff08b550
void *vid_get_viewport_fb()      { return (void*)0x40806b80; }             // Found @0xff412680
void *vid_get_viewport_live_fb() { return (void *)0;} // TODO
void *vid_get_viewport_fb_d()
{
    extern char *viewport_fb_d;
	return viewport_fb_d;
}


char *hook_raw_image_addr()
{
    return (char*)0x42365c30; //(Found @0xff413f98)
}

long hook_raw_size()             { return 0x01794300; }                    // Found @0xff413ff0

// TODO 
// Y multiplier for cameras with 480 pixel high viewports (CHDK code assumes 240)
int vid_get_viewport_yscale() {
	return 2;               // G12 viewport is 480 pixels high
}

int vid_get_viewport_width()
{
    if ((mode_get() & MODE_MASK) == MODE_PLAY)
    {
        return 360;
    }
    extern int _GetVRAMHPixelsSize();
    return _GetVRAMHPixelsSize() >> 1;
}

long vid_get_viewport_height()
{
    if ((mode_get() & MODE_MASK) == MODE_PLAY)
    {
        return 240;
    }
    extern int _GetVRAMVPixelsSize();
    return _GetVRAMVPixelsSize() >> 1;
}

// viewport width offset table for each image size
// 0 = 4:3, 1 = 16:9, 2 = 3:2, 3 = 1:1
static long vp_xo[5] = { 0, 0, 0, 44 };				// should all be even values for edge overlay

int vid_get_viewport_xoffset()
{
    int m = mode_get();
    if ((m & MODE_MASK) == MODE_PLAY)
    {
        return 0;
    }
    else if ((m & MODE_SHOOTING_MASK) == MODE_STITCH)
    {
        return 0;
    }
    else
    {
        return 0;
//	    return vp_xo[shooting_get_prop(PROPCASE_ASPECT_RATIO)];
    }
}

int vid_get_viewport_display_xoffset()
{
    int m = mode_get();
    if ((m & MODE_MASK) == MODE_PLAY)
    {
        return 0;
    }
    else if ((m & MODE_SHOOTING_MASK) == MODE_STITCH)
    {
        if (shooting_get_prop(PROPCASE_STITCH_DIRECTION) == 0)      // Direction check
            if (shooting_get_prop(PROPCASE_STITCH_SEQUENCE) == 0)   // Shot already taken?
                return 40;
            else
                return 140;
        else
            if (shooting_get_prop(PROPCASE_STITCH_SEQUENCE) == 0)   // Shot already taken?
                return 140;
            else
                return 40;
    }
    else
    {
	    return vp_xo[shooting_get_prop(PROPCASE_ASPECT_RATIO)];
    }
}

// viewport height offset table for each image size
// 0 = 4:3, 1 = 16:9, 2 = 3:2, 3 = 1:1
static long vp_yo[5] = { 0, 30, 13, 0 };

int vid_get_viewport_yoffset()
{
    int m = mode_get();
    if ((m & MODE_MASK) == MODE_PLAY)
    {
        return 0;
    }
    else if ((m & MODE_SHOOTING_MASK) == MODE_STITCH)
    {
        return 0;
    }
    else if (mode_is_video(m))
    {
        return 0;
    }
    else
    {
	    return vp_yo[shooting_get_prop(PROPCASE_ASPECT_RATIO)];
    }
}

int vid_get_viewport_display_yoffset()
{
    int m = mode_get();
    if ((m & MODE_MASK) == MODE_PLAY)
    {
        return 0;
    }
    else if ((m & MODE_SHOOTING_MASK) == MODE_STITCH)
    {
        return 72;
    }
    else if (mode_is_video(m))
    {
        return 30;
    }
    else
    {
	    return vp_yo[shooting_get_prop(PROPCASE_ASPECT_RATIO)];
    }
}

int vid_get_viewport_display_yoffset_proper()   { return vid_get_viewport_display_yoffset() * 2; }
int vid_get_viewport_height_proper()            { return vid_get_viewport_height() * 2; }
int vid_get_viewport_fullscreen_height()        { return 480; }

int vid_get_palette_type()                      { return 3; }
int vid_get_palette_size()                      { return 256 * 4; }

// TODO not found
/*
void *vid_get_bitmap_active_buffer()
{
    return bitmap_buffer[active_bitmap_buffer];
}
*/

void *vid_get_bitmap_active_palette()
{
    extern int active_palette_buffer;
    extern int** palette_buffer_ptr;
    return (palette_buffer_ptr[active_palette_buffer]+1);
}

// TODO void load_chdk_palette(), palette_control not found
