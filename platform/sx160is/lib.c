#include "platform.h"
#include "platform_palette.h"
#include "lolevel.h"

char *hook_raw_image_addr() {
    return (char*) 0x420F6420; //Found @0xffb5a2f4  search for "BJPEG BUFF"
}

// no battery temp
int _GetBatteryTemperature()     { return -99;}

char *camera_jpeg_count_str()
{
    extern char jpeg_count_str[];
    return jpeg_count_str;
}

void shutdown()
{
    extern void __attribute__((noreturn)) _finish_shutdown(void);
    _finish_shutdown();
}

#define LED_PR 0xC0220120
void debug_led(int state)
{
    // using power LED, which defaults to on
    // for debugging turn LED off if state is 1 and on for state = 0
    *(int*)LED_PR=state ? 0x46 : 0x44;
}

// SX160 IS has two 'lights' - Power LED, and AF assist lamp
// Power Led = first entry in table (led 0)
// AF Assist Lamp = second entry in table (led 1)
void camera_set_led(int led, int state, int bright) {
    static char led_table[2]={0,4};
    if(state<=1) _LEDDrive(led_table[led%sizeof(led_table)], (!state)&1);
}

int get_flash_params_count(void)
{
    return 0xA6;
}

void JogDial_CW(void)
{
    _PostLogicalEventToUI(0x872, 1);  // RotateJogDialRight (in table @ ffc1b298, fw 1.00a)
}

void JogDial_CCW(void)
{
    _PostLogicalEventToUI(0x873, 1);  // RotateJogDialLeft (in table @ ffc1b2a4, fw 1.00a)
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
    if (camera_info.state.mode_play)
    {
        return 240;
    }
    extern int _GetVRAMVPixelsSize();
    return _GetVRAMVPixelsSize();

}

// only X offset appears to be required, for 1:1
// buffer and display
int vid_get_viewport_xoffset()
{
    if (camera_info.state.mode_play)
    {
        return 0;
    }
    if (camera_info.state.mode_video || is_video_recording()) {
        return 0;
    }
    if(shooting_get_prop(PROPCASE_ASPECT_RATIO) == 3) { // 1:1 appears to use X offset
        return 44;
    }
    return 0;
}

// Viewport and Bitmap values that shouldn't change across firmware versions.
// Values that may change are in lib.c for each firmware version.
extern char active_viewport_buffer;
extern void* viewport_buffers[];

void *vid_get_viewport_fb()
{
    // Return first viewport buffer - for case when vid_get_viewport_live_fb not defined
    return viewport_buffers[0];
}

void *vid_get_viewport_live_fb()
{
    if (camera_info.state.mode_video || is_video_recording())
        return viewport_buffers[0];     // Video only seems to use the first viewport buffer.

    // Hopefully return the most recently used viewport buffer so that motion detect, histogram, zebra and edge overly are using current image data
    return viewport_buffers[(active_viewport_buffer-1)&3];
}

void *vid_get_viewport_fb_d()
{
    extern char *viewport_fb_d;
    return viewport_fb_d;
}


extern int active_bitmap_buffer;
extern char* bitmap_buffer[];

void *vid_get_bitmap_fb()
{
    // Return first bitmap buffer address
    return bitmap_buffer[0];
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

void *vid_get_bitmap_active_palette()
{
    extern int active_palette_buffer;
    extern int** palette_buffer_ptr;
    int *p = palette_buffer_ptr[active_palette_buffer];
    // active_palette_buffer can point at null when
    // func and menu are opened for the first time
    if(!p) {
        p = palette_buffer_ptr[0];
        if(!p) {
            return (void *)0;
        }
    }
    return (p+1);
}

void *vid_get_bitmap_active_buffer()
{
    return bitmap_buffer[active_bitmap_buffer];
}

#ifdef CAM_LOAD_CUSTOM_COLORS
// Function to load CHDK custom colors into active Canon palette

void load_chdk_palette()
{
    extern int active_palette_buffer;
    // Only load for the standard record and playback palettes
    if ((active_palette_buffer == 0) || (active_palette_buffer == 5))
    {
        int *pal = (int*)vid_get_bitmap_active_palette();
        if (pal && pal[CHDK_COLOR_BASE+0] != 0x3F3ADF62)
        {
            pal[CHDK_COLOR_BASE+0]  = 0x3F3ADF62;  // Red
            pal[CHDK_COLOR_BASE+1]  = 0x3F26EA40;  // Dark Red
            pal[CHDK_COLOR_BASE+2]  = 0x3F4CD57F;  // Light Red
            pal[CHDK_COLOR_BASE+3]  = 0x3F73BFAE;  // Green
            pal[CHDK_COLOR_BASE+4]  = 0x3F4BD6CA;  // Dark Green
            pal[CHDK_COLOR_BASE+5]  = 0x3F95AB95;  // Light Green
            pal[CHDK_COLOR_BASE+6]  = 0x3F4766F0;  // Blue
            pal[CHDK_COLOR_BASE+7]  = 0x3F1250F3;  // Dark Blue
            pal[CHDK_COLOR_BASE+8]  = 0x3F7F408F;  // Cyan
            pal[CHDK_COLOR_BASE+9]  = 0x3F512D5B;  // Magenta
            pal[CHDK_COLOR_BASE+10] = 0x3FA9A917;  // Yellow
            pal[CHDK_COLOR_BASE+11] = 0x3F819137;  // Dark Yellow
            pal[CHDK_COLOR_BASE+12] = 0x3FDED115;  // Light Yellow

            extern char palette_control;
            palette_control = 1;
            vid_bitmap_refresh();
        }
    }
}
#endif

// Functions for PTP Live View system
int vid_get_palette_type()                      { return 3; }
int vid_get_palette_size()                      { return 256 * 4; }
