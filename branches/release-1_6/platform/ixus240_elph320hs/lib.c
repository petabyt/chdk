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

int get_flash_params_count(void)
{
    return 0xa6; // Found @0xff24dffc by finsig
}

void vid_bitmap_refresh()
{
    extern int full_screen_refresh;
    extern void _ScreenUnlock();
    extern void _ScreenLock();

    full_screen_refresh |= 3;
    _ScreenLock();
    _ScreenUnlock();
}

//To do: check this!!
void shutdown()
{
    volatile long *p = (void*)0xC022001C;

    asm(
        "MRS     R1, CPSR\n"
        "AND     R0, R1, #0x80\n"
        "ORR     R1, R1, #0x80\n"
        "MSR     CPSR_cf, R1\n"
        :::"r1","r0");

    *p = 0x44;  // power off.

    while(1);
}

//#define LED_PR 0xC022C30C                       // Power LED (@FF15B178 & @FF15B1CC)
//TO DO:
void debug_led(__attribute__ ((unused))int state) {
    // using power LED, which defaults to on
    // for debugging turn LED off if state is 1 and on for state = 0
    // leaves LED on at end of debugging
//    volatile long *p = (void*)LED_PR;
//    *p = (*p & 0xFFFFFFCF) | ((state) ? 0x00 : 0x20);
}

//To do:
// IXUS240 has two 'lights' - Power LED, and AF assist lamp
// Power Led = first entry in table (led 0)
// AF Assist Lamp = second entry in table (led 1)
void camera_set_led(int led, int state, __attribute__ ((unused))int bright) {
    static char led_table[2]={0,4};
    if(state<=1) _LEDDrive(led_table[led%sizeof(led_table)], (!state)&1);
}


// Viewport and Bitmap values that shouldn't change across firmware versions.
// Values that may change are in lib.c for each firmware version.

// Defined in stubs_min.S
extern char active_viewport_buffer;
extern void* viewport_buffers[];

// Y multiplier for cameras with 480 pixel high viewports (CHDK code assumes 240)
// camera appears to use 240 when recording FHD video and Fisheye mode, 480 otherwise
int vid_get_viewport_yscale() {
    if (camera_info.state.mode_play) {
        return 2;
    }
    if (is_video_recording()) {
        // FHD video
        if(shooting_get_prop(PROPCASE_VIDEO_RESOLUTION) == 5) {
            return 1;
        }
        return 2;
    }
    if (camera_info.state.mode_shooting == MODE_FISHEYE) {
        return 1;
    }
    return 2;
}

void *vid_get_viewport_fb()
{
    // Return first viewport buffer - for case when vid_get_viewport_live_fb not defined
    return viewport_buffers[0];
}

void *vid_get_viewport_live_fb()
{
    // only 4 buffers used while video recording
    if (camera_info.state.mode_video || is_video_recording())
        return viewport_buffers[(active_viewport_buffer-1)&3];

    // Hopefully return the most recently used viewport buffer so that motion detect, histogram, zebra and edge overly are using current image data
    // Offset the return value because the viewport is left justified instead of centered on this camera
    return viewport_buffers[(active_viewport_buffer-1)&7];
}

void *vid_get_viewport_fb_d()
{
    extern char *viewport_fb_d;
    return viewport_fb_d;
}

// Defined in stubs_min.S
extern int active_bitmap_buffer;
extern char* bitmap_buffer[];

void *vid_get_bitmap_fb()
{
    // Return first bitmap buffer address
    return bitmap_buffer[0];
}

int vid_get_viewport_width()
{
    if (camera_info.state.mode_play)
    {
        return 480;
    }
    extern int _GetVRAMHPixelsSize();
    return _GetVRAMHPixelsSize() >> 1;
}


long vid_get_viewport_height()
{
    if(camera_info.state.mode_play) {
        return 240;
    }
    extern int _GetVRAMVPixelsSize();
    // FHD video is apparently 180 on a 240 display
    int h = _GetVRAMVPixelsSize();
    if (vid_get_viewport_yscale() == 1) {
        return h;
    }

    return h>>1;
}

int vid_get_viewport_display_xoffset()
{
    if (camera_info.state.mode_play)
    {
        return 0;
    }
    else
    {
        // viewport width offset table for each image size
        // 0 = 4:3, 1 = 16:9, 2 = 3:2, 3 = 1:1
        static long vp_w[5] = { 60, 0, 36, 104 };                // should all be even values for edge overlay
        return vp_w[shooting_get_prop(PROPCASE_ASPECT_RATIO)];
    }
}

// Functions for PTP Live View system

int vid_get_viewport_display_xoffset_proper()   { return vid_get_viewport_display_xoffset() * 2; }
int vid_get_viewport_height_proper()            { return vid_get_viewport_height()*vid_get_viewport_yscale(); }
int vid_get_viewport_buffer_width_proper()      { return 960; }
int vid_get_viewport_fullscreen_height()        { return 240*vid_get_viewport_yscale(); }

int vid_get_palette_type()                      { return 3; }
int vid_get_palette_size()                      { return 256 * 4; }
int vid_get_aspect_ratio()                      { return 1; } /* LV_ASPECT_16_9 */

void *vid_get_bitmap_active_buffer()
{
    return bitmap_buffer[active_bitmap_buffer];
}

void *vid_get_bitmap_active_palette()
{
    extern int active_palette_buffer;
    extern char* palette_buffer[];
    unsigned char color_option;
    // on cameras that allow setting UI color scheme,
    // actual palette is offset by color scheme value
    get_parameter_data(0x1a,&color_option,1); // from 102a sub_ff2ddd74
    char *p = palette_buffer[active_palette_buffer + color_option];
    // if null, don't add +4
    if(p) {
        p+=4;
    }
    return p;
}

#ifdef CAM_LOAD_CUSTOM_COLORS
// Function to load CHDK custom colors into active Canon palette
void load_chdk_palette()
{
    extern int active_palette_buffer;
    // Only load for the standard record and playback palettes
    // per https://chdk.setepontos.com/index.php?topic=9005.msg145877#msg145877
    // rec 0, playback 16, menu 12
    if ((active_palette_buffer == 0) || (active_palette_buffer == 16))
    {
        int *pal = (int*)vid_get_bitmap_active_palette();
        if(pal) {
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

                vid_bitmap_refresh();
            }
        }
    }
}
#endif
