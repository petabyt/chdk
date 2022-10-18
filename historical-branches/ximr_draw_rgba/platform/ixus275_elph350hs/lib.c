#include "platform.h"
#include "platform_palette.h"
#include "lolevel.h"

#define LED_PR 0xc022d1fc
#define LED_AF 0xc022d1b0

void debug_led(int state)
{
	*(int*)LED_PR=state ? 0x93d800 : 0x83dc00;
}


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


int get_flash_params_count(void) { return 0xe3; }



void camera_set_led(int led, int state, __attribute__ ((unused))int bright) {
    static char led_table[]={0,4}; // status, AF
    _LEDDrive(led_table[led%sizeof(led_table)], state<=1 ? !state : state);
}


void *vid_get_bitmap_fb()        { return (void*)0x40711000; }             // Found @0xff06dff4
void *vid_get_viewport_fb()      { return (void*)0x40866b80; }             // Found @0xff4c6d8c
void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x3778+0x54)); }

extern char active_viewport_buffer;
extern void* viewport_buffers[];

void *vid_get_viewport_live_fb()
{
    // camera appears to use 8 buffers
    // Hopefully return the most recently used viewport buffer so that motion detect, histogram, zebra and edge overly are using current image data
    return viewport_buffers[(active_viewport_buffer-1)&7];
}

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

// viewport width offset table for each aspect ratio
// 0 = 4:3, 1 = 16:9, 2 = 3:2, 3 = 1:1
static long vp_xo[4] = { 0, 0, 0, 44 };        // should all be even values for edge overlay

int vid_get_viewport_display_xoffset()
{
    if(camera_info.state.mode_play) {
        return 0;
    }
    int aspect_ratio=shooting_get_prop(PROPCASE_ASPECT_RATIO);

    return (vp_xo[aspect_ratio]);
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
    if (is_video_recording())
    {
        if(shooting_get_prop(PROPCASE_VIDEO_RESOLUTION) == 2) { // 640x480
            return 0;// 4:3 video, no offset
        } else {
            return 30; // 16:9 video
        }
    }
    return vp_yo[shooting_get_prop(PROPCASE_ASPECT_RATIO)];
}

int vid_get_viewport_display_yoffset()
{
    if (camera_info.state.mode_play)
    {
        return 0;
    }
    if (is_video_recording())
    {
        if(shooting_get_prop(PROPCASE_VIDEO_RESOLUTION) == 2) { // 640x480
            return 0;// 4:3 video, no offset
        } else {
            return 30;
        }
    }
    return vp_yo[shooting_get_prop(PROPCASE_ASPECT_RATIO)];
}

int vid_get_viewport_display_xoffset_proper()   { return vid_get_viewport_display_xoffset()<<1; }
int vid_get_viewport_display_yoffset_proper()   { return vid_get_viewport_display_yoffset() * vid_get_viewport_yscale(); }
int vid_get_viewport_height_proper()            { return vid_get_viewport_height() * vid_get_viewport_yscale(); }

int vid_get_viewport_fullscreen_height()
{
    return 240 * vid_get_viewport_yscale();
}

int vid_get_palette_type()                      { return 3; }
int vid_get_palette_size()                      { return 256 * 4; }

// Defined in stubs_min.S
extern int active_bitmap_buffer;
extern char* bitmap_buffer[];
void *vid_get_bitmap_active_buffer()
{
    return bitmap_buffer[active_bitmap_buffer&1];
}

void *vid_get_bitmap_active_palette()
{
    extern void *palette_buffer_ptr;
    return palette_buffer_ptr;
}

