#include "platform.h"
#include "platform_palette.h"
#include "lolevel.h"

extern  int     active_raw_buffer;
extern  char*   raw_buffers[];

char *hook_raw_image_addr()
{
    return raw_buffers[active_raw_buffer];
}

char *hook_alt_raw_image_addr()
{
    return raw_buffers[(active_raw_buffer^1)];
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

void *vid_get_bitmap_fb()        { return (void*)0x406f1000; }             // Found @0xff049118
int get_flash_params_count(void) { return 0x99; }                          // Found @0xff1eb3e4


void debug_led(int state)
{
    volatile long *p=(void*)LED_PR;
    if (state)
        p[0]=0x46;
    else
        p[0]=0x44;
}

void camera_set_led(int led, int state, int bright) {
    static char led_table[]={0,12}; // status, AF
    _LEDDrive(led_table[led%sizeof(led_table)], state<=1 ? !state : state);
}

extern char active_viewport_buffer;
extern void* viewport_buffers[];

void *vid_get_viewport_fb()
{
    // Return first viewport buffer - for case when vid_get_viewport_live_fb not defined
    return viewport_buffers[0];
}

void *vid_get_viewport_fb_d()
{
    extern char *viewport_fb_d;
    return viewport_fb_d;
}

void *vid_get_viewport_live_fb()
{
    if (MODE_IS_VIDEO(mode_get()) || is_video_recording())
        return viewport_buffers[0];     // Video only seems to use the first viewport buffer.

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

int vid_get_viewport_fulllscreen_width()
{
    return 720;
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


#ifdef CAM_LOAD_CUSTOM_COLORS
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
            pal[CHDK_COLOR_BASE+10] = 0x3F7F408F;  // Cyan
            pal[CHDK_COLOR_BASE+11] = 0x3F512D5B;  // Magenta
            pal[CHDK_COLOR_BASE+12] = 0x3FA9A917;  // Yellow
            pal[CHDK_COLOR_BASE+13] = 0x3F819137;  // Dark Yellow
            pal[CHDK_COLOR_BASE+14] = 0x3FDED115;  // Light Yellow

            extern char palette_control;
            palette_control = 1;
            vid_bitmap_refresh();
        }
    }
}
#endif

void JogDial_CW(void)
{
    _PostLogicalEventToUI(0x872, 1);  // RotateJogDialRight (in table @ ????, fw 1.01a)
}

void JogDial_CCW(void)
{
    _PostLogicalEventToUI(0x873, 1);  // RotateJogDialLeft (in table @ ???, fw 1.01a)
}
