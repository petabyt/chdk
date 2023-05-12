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
    return (char*)0x43924c60;
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


int get_flash_params_count(void) { return 0xf1; }



void camera_set_led(int led, int state, __attribute__ ((unused))int bright) {
    static char led_table[]={0,4}; // status, AF
    _LEDDrive(led_table[led%sizeof(led_table)], state<=1 ? !state : state);
}


void *vid_get_bitmap_fb()        { return (void*)0x40711000; }             // Found @0xff06c888
 void *vid_get_viewport_fb()      { return (void*)0x40866b80; }             // Found @0xff438b5c
void *vid_get_viewport_fb_d()
{
    extern char *viewport_fb_d;
    return viewport_fb_d;
}

extern char active_viewport_buffer;
extern void* viewport_buffers[];

void *vid_get_viewport_live_fb()
{
//    if (MODE_IS_VIDEO(mode_get()) || is_video_recording())
//        return viewport_buffers[0];     // Video only seems to use the first viewport buffer.

    // Hopefully return the most recently used viewport buffer so that motion detect, histogram, zebra and edge overly are using current image data
    // verified -1 gives best response
    return viewport_buffers[(active_viewport_buffer-1)&3];
}

extern int _GetVRAMHPixelsSize(void);
extern int _GetVRAMVPixelsSize(void);
extern int _GetVideoOutType(void);

// playback is 480 / 576 for NTSC / PAL respectively
int vid_get_viewport_yscale() {
    if (camera_info.state.mode_play && _GetVideoOutType() != 0) {
        return 2;
    }
    return 1;
}

//taken from n
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
  if (camera_info.state.mode_play)
  {
       if(_GetVideoOutType() == 2) { // PAL
           return 288; // 576
       }
       // rec or NTSC
       return 240;
  }
  return _GetVRAMVPixelsSize();
}

int vid_get_viewport_yoffset()
{
    if (camera_info.state.mode_play)
    {
        return 0;
    }
    // no distinct video mode, video uses its own aspect ratio, not still ratio of current mode
    if (is_video_recording())
    {
        if(shooting_get_prop(PROPCASE_VIDEO_RESOLUTION) == 2) { // 640x480
            return 0;// 4:3 video, no offset
        } else {
            return 30; // 16:9 video
        }
    }
    // UI doesn't have aspect ratio setting, but setting image size to W sets aspect prop to 16:9
    if(shooting_get_prop(PROPCASE_ASPECT_RATIO) == 1) {
        return 30;
    }
    return 0;
}

int vid_get_viewport_height_proper()            { return vid_get_viewport_height() * vid_get_viewport_yscale(); }

int vid_get_viewport_fullscreen_height()
{
    if (camera_info.state.mode_play) {
        int vot = _GetVideoOutType();
        if(vot == 2) {
            return 576; // PAL in playback is 576
        } else if(vot == 1) {
            return 480; // NTSC is 480
        } else {
            return 240; // normal is 240
        }
    } else {
        return 240;
    }
}

int vid_get_palette_type()                      { return 3; }
int vid_get_palette_size()                      { return 256 * 4; }

// Defined in stubs_min.S
extern int active_bitmap_buffer;
extern char* bitmap_buffer[];
void *vid_get_bitmap_active_buffer() {
    return bitmap_buffer[active_bitmap_buffer&1];
}


void *vid_get_bitmap_active_palette()
{
    extern void *palette_buffer_ptr;
    return palette_buffer_ptr;
}

