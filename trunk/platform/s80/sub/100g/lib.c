#include "platform.h"

char *hook_raw_image_addr()
{
    return (char*)0x1056B960;       // aA08x_crw, followed sd30
}

long hook_raw_size()
{
    return 0x9E6F10;                // aA08x_crw, followed sd30
}

void *vid_get_viewport_live_fb()
{
       void **fb=(void **)0x5364; //@FF8AB03C
       unsigned char buff = *((unsigned char*)0x537c); //@FF8AB010
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
   return (void*)0x103C79A0;        // seems to be the same with a620 and sd30
}

void *vid_get_viewport_fb()
{
    return (void*) 0x105F2C4C;  //s80
}

void *vid_get_viewport_fb_d()
{
    return (void*)(*(int*)0x72fdc); //s80
}

int vid_get_viewport_width_proper() {
    int m = mode_get();
    if((m&MODE_MASK) == MODE_PLAY) {
        return 720; //no tv-out
    }
    // return hard coded width since mode doesn't update at the same time as GetVRAMHPixelsSize
    if((m&MODE_SHOOTING_MASK) == MODE_STITCH) {
        return 360;
    }
    return *(int*)0x36630; // hopefully
}

int vid_get_viewport_height_proper() {
    int m = mode_get();
    if((m&MODE_MASK) == MODE_PLAY) {
        return 240; //no tv-out
    }
    // return hard coded width since mode doesn't update at the same time as GetVRAMHPixelsSize
    if((m&MODE_SHOOTING_MASK) == MODE_STITCH) {
        return 120; 
    }
    return *(int*)0x36634; // hopefully
}

char *camera_jpeg_count_str()
{
    return (char*)0x81c70;
}

void *vid_get_bitmap_active_palette() {
    return (void *)0x72cf8; // GetPaletteFromPhysicalScreen
}

void *vid_get_bitmap_active_buffer()
{
    return (void*)(*(int*)0x6adc); // @FF92A7D0 DisplayPhysicalScreenWithYUVPalette
}

