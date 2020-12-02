#include "platform.h"
#include "platform_palette.h"
#include "lolevel.h"

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

// TODO not really complete, last call from task_Bye
void shutdown()
{
    extern void _TurnOffE1(void);
    _TurnOffE1();
    while(1);
}

//TODO check LED address
#define LED_PR 0xC0220094 // Green (only non-AF)

void debug_led(int state)
{
    volatile long *p=(void*)LED_PR;
    if (state)
        p[0]=0x46;
    else
        p[0]=0x44;
}

void camera_set_led(int led, int state, __attribute__ ((unused))int bright) {
 static char led_table[]={0,12}; // status, AF
 _LEDDrive(led_table[led%sizeof(led_table)], state<=1 ? !state : state);
}

int vid_get_viewport_width()     { return 360;  }
long vid_get_viewport_height()   { return 240;  }

int get_flash_params_count(void) { return 0x91; }                          // Found @0xff207154

void *vid_get_bitmap_fb()        { return (void*)0x406b1000; }             // Found @0xff08b488
void *vid_get_viewport_fb()      { return (void*)0x40806b80; }             // Found @0xff411fc8
void *vid_get_viewport_fb_d()
{
    extern char *viewport_fb_d;
    return viewport_fb_d;
}

void *vid_get_viewport_live_fb()
{
    extern char active_viewport_buffer;
    extern void* viewport_buffers[];

    // no distinct video mode
    if (/*mode_is_video(mode_get())*/ get_movie_status() == VIDEO_RECORD_IN_PROGRESS)
        return viewport_buffers[0];     // Video only seems to use the first viewport buffer.
    // Hopefully return the most recently used viewport buffer so that motion detect, histogram, zebra and edge overly are using current image data
    // verified -1 gives best response
    return viewport_buffers[(active_viewport_buffer-1)&3];
}


char *hook_raw_image_addr()
{
    return (char*)0x42365c30; // Found @0xff4138e0
}

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

#ifdef CAM_LOAD_CUSTOM_COLORS
// Function to load CHDK custom colors into active Canon palette
void load_chdk_palette()
{
    extern int active_palette_buffer;
    // Only load for the standard record and playback palettes
    // 0 = rec, 4 = func menu, 5 = playback, 6 = menu (play or rec), 
    if ((active_palette_buffer == 0) || (active_palette_buffer == 5) || (active_palette_buffer == 4))
    {
        int *pal = (int*)vid_get_bitmap_active_palette();
        if (pal[CHDK_COLOR_BASE+0] != 0x33ADF62)
        {
            pal[CHDK_COLOR_BASE+0]  = 0x33ADF62;  // Red
            pal[CHDK_COLOR_BASE+1]  = 0x326EA40;  // Dark Red
            pal[CHDK_COLOR_BASE+2]  = 0x34CD57F;  // Light Red
            pal[CHDK_COLOR_BASE+3]  = 0x373BFAE;  // Green
            pal[CHDK_COLOR_BASE+4]  = 0x34BD6CA;  // Dark Green
            pal[CHDK_COLOR_BASE+5]  = 0x395AB95;  // Light Green
            pal[CHDK_COLOR_BASE+6]  = 0x34766F0;  // Blue
            pal[CHDK_COLOR_BASE+7]  = 0x31250F3;  // Dark Blue
            pal[CHDK_COLOR_BASE+8]  = 0x37F408F;  // Cyan
            pal[CHDK_COLOR_BASE+9]  = 0x3512D5B;  // Magenta
            pal[CHDK_COLOR_BASE+10] = 0x3A9A917;  // Yellow
            pal[CHDK_COLOR_BASE+11] = 0x3819137;  // Dark Yellow
            pal[CHDK_COLOR_BASE+12] = 0x3DED115;  // Light Yellow

            extern char palette_control;
            palette_control = 1; // note appears to be a bitmask, bit 2 is also used
            vid_bitmap_refresh();
        }
    }
}
#endif

