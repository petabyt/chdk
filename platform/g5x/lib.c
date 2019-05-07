
#include "platform.h"
#include "lolevel.h"
#include "live_view.h"

extern int active_bitmap_buffer;
extern char* bitmap_buffer[];

void vid_bitmap_refresh()
{
    extern void _transfer_src_overlay(int);
    extern void _VTMLock();
    extern void _VTMUnlock();
    _VTMLock();
    _transfer_src_overlay(active_bitmap_buffer);
    _VTMUnlock();
}

void *vid_get_bitmap_fb()
{
    // For live view send YUV instead of RGBA
    return bitmap_buffer[active_bitmap_buffer&1];
}

// the opacity buffer defines opacity for the bitmap overlay's pixels
// found near BmpDDev.c
void *opacity_buffer[2] = { (void*)0x5FC40000, (void*)0x5FB80000 };

void *vid_get_opacity_active_buffer()
{
    return opacity_buffer[active_bitmap_buffer&1];
}

char *camera_jpeg_count_str()
{
    extern char jpeg_count_str[];
    return jpeg_count_str;
}

void shutdown()
{
    // TODO:
    while (1)
        ;
}

#define LED_PR 0xd20b0994 // green LED on the back

void debug_led(int state) {
    volatile long *p = (void*) LED_PR;
    *p = ((state) ? 0x4d0002 : 0x4c0003);
}

// Power Led = first entry in table (led 0)
// AF Assist Lamp = second entry in table (led 1)
void camera_set_led(int led, int state, int bright) {
    static char led_table[2] = { 0, 4 };
    _LEDDrive(led_table[led % sizeof(led_table)], state <= 1 ? !state : state);
}

//TODO:
void shutdown_soft()
{
    _PostLogicalEventForNotPowerType(0x1005, 0);
}

//TODO:
int get_flash_params_count(void)
{
    return 241;
}

//TODO:
void JogDial_CW(void)
{
    _PostLogicalEventToUI(0x872, 1);    //RotateJogDialRight
}

//TODO:
void JogDial_CCW(void)
{
    _PostLogicalEventToUI(0x873, 1);    //RotateJogDialLeft
}

// updated by using function in capt_seq, valid between shot start and raw hook end
extern  char*   current_raw_addr;

char *hook_raw_image_addr()
{
    /*
     43dbfca0   - RAW & RAW + JPEG
     43e4a000   - JPEG only
     */
    return current_raw_addr;
}

// TODO:
//char *hook_alt_raw_image_addr()
//{
//}

extern void* viewport_buffers[];
extern void *current_viewport_buffer;

void *vid_get_viewport_fb_d()
{
    extern void *current_fb_d;
    return current_fb_d;
}

void *vid_get_viewport_fb()
{
    return viewport_buffers[0];
}

void *vid_get_viewport_live_fb()
{
    int i;
    for(i=0;i<4;i++) {
        if(current_viewport_buffer == viewport_buffers[i]) {
            return viewport_buffers[(i+1)&3];
        }
    }
    return 0;
}

int vid_get_viewport_width() {
    extern int _GetVRAMHPixelsSize();
    extern int _GetVRAMHPixelsSize();
    if (camera_info.state.mode_play)
    {
        return 720;
    }
    return _GetVRAMHPixelsSize();
}

long vid_get_viewport_height()
{
    extern int _GetVRAMVPixelsSize();
    if (camera_info.state.mode_play)
    {
        return 480;
    }
    return _GetVRAMVPixelsSize();
}

int vid_get_viewport_yscale()
{
    return 1;
}

int vid_get_viewport_byte_width()
{
    return 736*2;     // buffer is 736 wide (720 image pixels) UYVY
}

// Functions for PTP Live View system
int vid_get_viewport_display_xoffset_proper()   { return vid_get_viewport_display_xoffset(); }
int vid_get_viewport_display_yoffset_proper()   { return vid_get_viewport_display_yoffset(); }
int vid_get_viewport_width_proper()             { return vid_get_viewport_width(); }
int vid_get_viewport_height_proper()            { return vid_get_viewport_height(); }
int vid_get_viewport_fullscreen_width()         { return 720; }
int vid_get_viewport_fullscreen_height()        { return 480; }
int vid_get_viewport_buffer_width_proper()      { return 736; }
int vid_get_viewport_type()                     { return LV_FB_YUV8B; }
int vid_get_aspect_ratio()                      { return LV_ASPECT_3_2; }
