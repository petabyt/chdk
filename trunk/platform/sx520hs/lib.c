#include "platform.h"
#include "platform_palette.h"
#include "lolevel.h"

extern  int     active_raw_buffer;
extern  char*   raw_buffers[];

char *hook_raw_image_addr()
{
    return raw_buffers[active_raw_buffer & 1];
}

char *hook_alt_raw_image_addr()
{
    return raw_buffers[((active_raw_buffer & 1)^1)];
}

//char *camera_jpeg_count_str() jeronymo
//{
//    extern char jpeg_count_str[];
//    return jpeg_count_str;
//}

void vid_bitmap_refresh()
{
    extern int full_screen_refresh;
    extern void _ScreenLock();
    extern void _ScreenUnlock();

    full_screen_refresh |= 3;
    _ScreenLock();
    _ScreenUnlock();
}

#define LED_PR 0xC022D1FC
#define AF_LED 0xC022D034
void shutdown()
{
    extern void _TurnOffE1(void);
    _TurnOffE1();
    while(1);
}
void *vid_get_bitmap_fb()        { return (void*)0x40711000; }             // Found @0xff06e5f8
int get_flash_params_count(void) { return 0xdc; }                          // Found @0xff23513c
void *vid_get_viewport_fb()      { return (void*)0x40866b80; }             // Found @0xff4d2e04

char *camera_jpeg_count_str()
{
    extern char jpeg_count_str[];
    return jpeg_count_str;
}

void debug_led(int state)
{
    volatile long *p=(void*)LED_PR;
    if (state)
        p[0]=0x93d800;
    else
        p[0]=0x83dc00;
}

void camera_set_led(int led, int state, __attribute__ ((unused))int bright) {
    static char led_table[]={0,12}; // status, AF
    _LEDDrive(led_table[led%sizeof(led_table)], state<=1 ? !state : state);
}

extern char active_viewport_buffer;
extern void* viewport_buffers[];

void *vid_get_viewport_fb_d()
{
    extern char *viewport_fb_d;
    return viewport_fb_d;    
}

void *vid_get_viewport_live_fb()
{
    //if (MODE_IS_VIDEO(mode_get()) || is_video_recording())
    //    return viewport_buffers[0];     // Video only seems to use the first viewport buffer.

    // Hopefully return the most recently used viewport buffer so that motion detect, histogram, zebra and edge overly are using current image data
    // verified -1 gives best response
    return viewport_buffers[(active_viewport_buffer-1)&3];
}

// Y multiplier for cameras with 480 pixel high viewports (CHDK code assumes 240)
int vid_get_viewport_yscale() {
    return 2;
}

int vid_get_viewport_width()
{
    if (camera_info.state.mode_play)
    {
        return 360;
    }
    extern int _GetVRAMHPixelsSize();
    return _GetVRAMHPixelsSize() >> 1;
}

long vid_get_viewport_height()
{

    int m = mode_get();
    int aspect_ratio=shooting_get_prop(PROPCASE_ASPECT_RATIO);

    if (MODE_IS_VIDEO(m) || is_video_recording())
        return 240;

    if ((m & MODE_MASK) != MODE_PLAY) 
    {
        // 0 = 4:3, 1 = 16:9, 2 = 3:2, 3 = 1:1
        if (aspect_ratio==1 || aspect_ratio==2)
            return 240;
    }
    extern int _GetVRAMVPixelsSize();    
    return ((m & MODE_MASK) == MODE_PLAY)?240:_GetVRAMVPixelsSize()>>1;
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

int vid_get_viewport_display_xoffset_proper()   { return vid_get_viewport_display_xoffset()<<1; }
int vid_get_viewport_display_yoffset_proper()   { return vid_get_viewport_display_yoffset()<<1; }
int vid_get_viewport_height_proper()            { return vid_get_viewport_height() * 2; }
int vid_get_viewport_fullscreen_height()        { return 480; }
int vid_get_palette_type()                      { return 3; }
int vid_get_palette_size()                      { return 256 * 4; }

void *vid_get_bitmap_active_palette()
{
    extern void *palette_buffer_ptr;
    return palette_buffer_ptr;
}

extern int active_bitmap_buffer;
extern char* bitmap_buffer[];

void *vid_get_bitmap_active_buffer() {
    return bitmap_buffer[active_bitmap_buffer&1];
}




//TODO-----------------------------------------------------------------------------------
void JogDial_CW(void)
{
    _PostLogicalEventToUI(0x872, 1);  // RotateJogDialRight (in table @ ????, fw 1.01a)
}

void JogDial_CCW(void)
{
    _PostLogicalEventToUI(0x873, 1);  // RotateJogDialLeft (in table @ ???, fw 1.01a)
}
