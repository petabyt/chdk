#include "platform.h"

void *hook_raw_fptr()
{
    return (void*)0x345B8;
}

void *hook_raw_ret_addr()
{
    return (void*)0xFF8D4788;
}

char *hook_raw_image_addr()
{
    return (char*)(0x105B8AC0);
}

void *vid_get_viewport_live_fb()
{
//    return (void*)0;
    void **fb=(void **)0x54e8;
    unsigned char buff = *((unsigned char*)0x54f8);
    if (buff == 0) {
        buff = 2;
    }
    else {
        buff--;
    }
    return fb[buff];
}

void *vid_get_bitmap_fb()
{
    return (void*)0x103C79A0;
}

void *vid_get_viewport_fb()
{
    return (void*)0x105f17a0; //0x105599A0;
}

void *vid_get_viewport_fb_d()
{
    return (void*)(*(int*)0x60134);
}

extern int _GetVRAMHPixelsSize();
extern int _GetVRAMVPixelsSize();

int vid_get_viewport_width() {
    if (camera_info.state.mode_play) {
        return 360;
    }
    return _GetVRAMHPixelsSize()>>1;
}

long vid_get_viewport_height() {
    if (camera_info.state.mode_play) {
        return 240;
    }
    return _GetVRAMVPixelsSize();
}

int vid_get_viewport_height_proper() {
    return vid_get_viewport_height();
}

int vid_get_viewport_fullscreen_height() {
    return vid_get_viewport_height(); // this should be _proper, but they're the same so skip the extra call
}

char *camera_jpeg_count_str()
{
    return (char*)0x6BC28;
}
