#include "platform.h"
#include "platform_palette.h"
#include "lolevel.h"
#include "gui_draw.h"

void vid_bitmap_refresh()
{
    if(draw_is_suspended()) {
        return;
    }
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
 static char led_table[]={0,4}; // status, AF
 _LEDDrive(led_table[led%sizeof(led_table)], state<=1 ? !state : state);
}

char *camera_jpeg_count_str()
{
    extern char jpeg_count_str[];
	return jpeg_count_str;
}

int get_flash_params_count(void) { return 0x91; }                          // Found @0xff2075ac


void *vid_get_bitmap_fb()        { return (void*)0x406b1000; }             // Found @0xff08b550
void *vid_get_viewport_fb()      { return (void*)0x40806b80; }             // Found @0xff412680
void *vid_get_viewport_fb_d()
{
    extern char *viewport_fb_d;
	return viewport_fb_d;
}

void *vid_get_viewport_live_fb()
{
    extern char active_viewport_buffer;
    extern void* viewport_buffers[];

    int i = active_viewport_buffer - 1;
    // video appears to only use 3 buffers, no distinct video mode
    if (is_video_recording()) {
        if(i < 0) {
            i = 2;
        }
    } else if(i < 0) {
        i = 3;
    }

    // Hopefully return the most recently used viewport buffer so that motion detect, histogram, zebra and edge overly are using current image data
    return viewport_buffers[i];
}


char *hook_raw_image_addr()
{
    return (char*)0x42365c30; //(Found @0xff413f98)
}

extern int _GetVideoOutType(void);
extern int _GetVRAMHPixelsSize(void);
extern int _GetVRAMVPixelsSize(void);

// Y multiplier for cameras with 480 pixel high viewports (CHDK code assumes 240)
// elph130 is 240 when using video out in rec, or in FISHEYE mode
int vid_get_viewport_yscale() {
    if (camera_info.state.mode_play) {
        return 2;
    }
    if(_GetVideoOutType() != 0 || (camera_info.state.mode_shooting == MODE_FISHEYE && !is_video_recording())) {
        return 1;
    }
    return 2;
}

int vid_get_viewport_width()
{
    if (camera_info.state.mode_play)
    {
        return 360;
    }
    return _GetVRAMHPixelsSize() >> 1;
}

long vid_get_viewport_height()
{
    int vot = _GetVideoOutType();
    if (camera_info.state.mode_play)
    {
        if(vot == 2) { // PAL
            return 288; // 576
        }
        return 240;
    }
    return _GetVRAMVPixelsSize() >> (vid_get_viewport_yscale() - 1);
}

// viewport width offset table for each image size
// 0 = 4:3, 1 = 16:9, 2 = 3:2, 3 = 1:1
static long vp_xo[5] = { 0, 0, 0, 44 };				// should all be even values for edge overlay

// elph130 appears to use display offsets exclusively in X
int vid_get_viewport_xoffset()
{
    return 0;
}

int vid_get_viewport_display_xoffset()
{
    if (camera_info.state.mode_play || is_video_recording())
    {
        return 0;
    }
    else if (camera_info.state.mode_shooting == MODE_STITCH)
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
    if (camera_info.state.mode_play)
    {
        return 0;
    }
    // no distinct video mode, video uses its own aspect ratio, not still ratio of current mode
    else if (/*mode_is_video(m)*/ is_video_recording())
    {
        if(shooting_get_prop(PROPCASE_VIDEO_RESOLUTION) == 2) { // 640x480
            return 0;// 4:3 video, no offset
        } else {
            return 30; // 16:9 video
        }
    }
    else if (camera_info.state.mode_shooting == MODE_STITCH)
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
    if (camera_info.state.mode_play)
    {
        return 0;
    }
    else if (/*mode_is_video(m)*/ is_video_recording())
    {
        if(shooting_get_prop(PROPCASE_VIDEO_RESOLUTION) == 2) { // 640x480
            return 0;// 4:3 video, no offset
        } else {
            return 30;
        }
    }
    else if (camera_info.state.mode_shooting == MODE_STITCH)
    {
        return 72;
    }
    else
    {
        return vp_yo[shooting_get_prop(PROPCASE_ASPECT_RATIO)];
    }
}

int vid_get_viewport_display_yoffset_proper()   { return vid_get_viewport_display_yoffset() * vid_get_viewport_yscale(); }
int vid_get_viewport_height_proper()            { return vid_get_viewport_height() * vid_get_viewport_yscale(); }

int vid_get_viewport_fullscreen_height()
{
    if (camera_info.state.mode_play) {
        int vot = _GetVideoOutType();
        if(vot == 2) {
            return 576; // PAL in playback is 576
        } else {
            return 480; // all other playback is 480
        }
    } else {
        return 240<<(vid_get_viewport_yscale()-1);
    }
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
        p = palette_buffer_ptr[0]; // rec mode buffer normally initialized
        if(!p) { // but may be null on video out switch
            return (void *)0;
        }
    }
    return (p+1);
}

// Function to load CHDK custom colors into active Canon palette
void load_chdk_palette()
{
    extern int active_palette_buffer;
    // Only load for the standard record and playback palettes
    // 0 = rec, 4 = func menu, 5 = playback, 6 = menu (play or rec),
    if ((active_palette_buffer == 0) || (active_palette_buffer == 5) || (active_palette_buffer == 4))
    {
        int *pal = (int*)vid_get_bitmap_active_palette();
        if (pal && pal[CHDK_COLOR_BASE+0] != 0x33ADF62)
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
