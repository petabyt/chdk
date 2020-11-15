#include "platform.h"
#include "platform_palette.h"
#include "lolevel.h"

char *hook_raw_image_addr()
{
    return (char*)0x42fb5130; //Found @0xff8758cc and 0xffa655d8 (Search for A/%08x.CRW)
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

#define LED_PR 0xC022302C
#define AF_LED 0xC0223030
void shutdown()
{
    extern void _TurnOffE1(void);
    _TurnOffE1();
    while(1);
}

void *vid_get_bitmap_fb()        { return (void*)0x40711000; }             // Found @0xff865754
int get_flash_params_count(void) { return 0xd4; }                          // Found @0xff9c7eb4

void debug_led(int state)
{
    volatile long *p=(void*)LED_PR;
    if (state)
        p[0]=0x46;
    else
        p[0]=0x44;
}

// SX400IS has two 'lights' - Power LED, and AF assist lamp
// Power Led = first entry in table (led 0)
// AF Assist Lamp = second entry in table (led 1)
// State
// 0 = LED Off
// 1 = LED On
// 2 = LED blinks slowly
// 3 = LED blinks fast
// 5 = LED blinks fast (3 times)
void camera_set_led(int led, int state, int bright) {
    static char led_table[]={0,4}; // status, AF
    _LEDDrive(led_table[led%sizeof(led_table)], state<=1 ? !state : state);
}

void *vid_get_viewport_fb()      { return (void*)0x40866b80; }             // Found @0xffba1ce8
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
    return ((m & MODE_MASK) == MODE_PLAY)?240:_GetVRAMVPixelsSize();
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
    extern int active_palette_buffer;
    extern int** palette_buffer_ptr;
    int *p = palette_buffer_ptr[active_palette_buffer];
    // active_palette_buffer can point at null when
    // func and menu are opened for the first time
    if(!p) {
        p = palette_buffer_ptr[0]; // rec mode buffer appears to always be initialized
    }
    return (p+1);
}

// Function to load CHDK custom colors into active Canon palette
void load_chdk_palette()
{
    extern int active_palette_buffer;
    // Only load for the standard record and playback palettes
    if ((active_palette_buffer == 0) || (active_palette_buffer == 5))
    {
        int *pal = (int*)vid_get_bitmap_active_palette();
        if (pal[CHDK_COLOR_BASE+0] != 0x3F3ADF62)
        {
            pal[CHDK_COLOR_BASE+0]  = 0x3F3ADF62;  // Red
            pal[CHDK_COLOR_BASE+1]  = 0x3F26EA40;  // Dark Red
            pal[CHDK_COLOR_BASE+2]  = 0x3F4CD57F;  // Light Red
            pal[CHDK_COLOR_BASE+5]  = 0x3F73BFAE;  // Green
            pal[CHDK_COLOR_BASE+6]  = 0x3F4BD6CA;  // Dark Green
            pal[CHDK_COLOR_BASE+7]  = 0x3F95AB95;  // Light Green
            pal[CHDK_COLOR_BASE+8]  = 0x3F4766F0;  // Blue
            pal[CHDK_COLOR_BASE+9]  = 0x3F1250F3;  // Dark Blue
            pal[CHDK_COLOR_BASE+10]  = 0x3F7F408F;  // Cyan
            pal[CHDK_COLOR_BASE+11]  = 0x3F512D5B;  // Magenta
            pal[CHDK_COLOR_BASE+12] = 0x3FA9A917;  // Yellow
            pal[CHDK_COLOR_BASE+13] = 0x3F819137;  // Dark Yellow
            pal[CHDK_COLOR_BASE+14] = 0x3FDED115;  // Light Yellow
            pal[CHDK_COLOR_BASE+15] = 0x00090000;  // Transparent dark grey

            extern char palette_control;
            palette_control = 1;
            vid_bitmap_refresh();
        }
    }
}

// following routines help preventing the "invisible af lock" caused by the movie af scan hack
static int af_locked_in_movierec = 0;

void _MakeAFScan(int *a, int b) {
    _DoAFLock();
    af_locked_in_movierec = 1;
}

void state_check_for_movie_af() {
    if ((get_movie_status() != VIDEO_RECORD_IN_PROGRESS) && af_locked_in_movierec) {
        af_locked_in_movierec = 0;
        _UnlockAF();
    }
}
