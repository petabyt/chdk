#include "platform.h"
#include "platform_palette.h"
#include "lolevel.h"

#define LED_PR 0xc022d1fc
#define LED_AF 0xc022d200

void debug_led(int state)
{
	*(int*)LED_PR=state ? 0x93d800 : 0x83dc00;
}

char *hook_raw_image_addr()
{
    return (char*)0x454a8d60; 
}


char *camera_jpeg_count_str()
{
    extern char jpeg_count_str[];
    return jpeg_count_str;
}

void vid_bitmap_refresh()
{
    extern int full_screen_refresh;
    extern void _ScreenLock();
    extern void _ScreenUnlock();

    full_screen_refresh |= 3;
    _ScreenLock();
    _ScreenUnlock();
}


void shutdown()
{
    extern void _TurnOffE1(void);
    _TurnOffE1();
    while(1);
}


int get_flash_params_count(void) { return 0x10f; } //?10f

void camera_set_led(int led, int state, int bright) {
    static char led_table[]={0,4}; // status, AF
    _LEDDrive(led_table[led%sizeof(led_table)], state<=1 ? !state : state);
}


void *vid_get_bitmap_fb()        { return (void*)0x40711000; }
void *vid_get_viewport_fb()      { return (void*)0x40866b80; }             

void *vid_get_viewport_fb_d()
{
    extern char *viewport_fb_d;
    return viewport_fb_d;
}

extern char active_viewport_buffer;
extern void* viewport_buffers[];

void *vid_get_viewport_live_fb()
{
    if (MODE_IS_VIDEO(mode_get()) || is_video_recording())
        return viewport_buffers[0];     // Video only seems to use the first viewport buffer.

    // Hopefully return the most recently used viewport buffer so that motion detect, histogram, zebra and edge overly are using current image data
    // verified -1 gives best response
    return viewport_buffers[(active_viewport_buffer-1)&3];
}

extern int _GetVRAMHPixelsSize();
extern int _GetVRAMVPixelsSize();

//taken from n
int vid_get_viewport_width()
{
    if ((mode_get() & MODE_MASK) == MODE_PLAY)
    {
        return 360;
    }
    return _GetVRAMHPixelsSize() >> 1;
}
// taken from n
long vid_get_viewport_height()
{
  if ((mode_get() & MODE_MASK) == MODE_PLAY)
  {
       return 240;
  }
  return _GetVRAMVPixelsSize();
}

// viewport width offset table for each aspect ratio
// 0 = 4:3, 1 = 16:9, 2 = 3:2, 3 = 1:1
static long vp_xo[4] = { 0, 0, 0, 44 };        // should all be even values for edge overlay

int vid_get_viewport_display_xoffset()
{
    int m = mode_get();
    int aspect_ratio=shooting_get_prop(PROPCASE_ASPECT_RATIO);

    if ((m & MODE_MASK) != MODE_PLAY) {
        return (vp_xo[aspect_ratio]);
    }
    else
        return 0;
}

//int vid_get_viewport_display_xoffset_proper()   { return vid_get_viewport_display_xoffset()<<1; }
//int vid_get_viewport_display_yoffset_proper()   { return vid_get_viewport_display_yoffset()<<1; }
//int vid_get_viewport_height_proper()            { return vid_get_viewport_height() * 2; }
//int vid_get_viewport_fullscreen_height()        { return 240; }
//int vid_get_viewport_fulllscreen_width()        { return 720; }
int vid_get_palette_type()                      { return 3; }
int vid_get_palette_size()                      { return 256 * 4; }

// Defined in stubs_min.S
extern int active_bitmap_buffer;
extern char* bitmap_buffer[];
void *vid_get_bitmap_active_buffer()
{
    return bitmap_buffer[active_bitmap_buffer];
}

void *vid_get_bitmap_active_palette()
{
    extern void *palette_buffer_ptr;
    return palette_buffer_ptr;
}

