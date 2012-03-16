#include "platform.h"
#include "keyboard.h"

void *hook_raw_fptr()
{
    return (void*)0x349CC; // a420 found in taskcreate_ImageSensorTask
}

void *hook_raw_ret_addr()
{
    return (void*)0xFFCAFCB0; // a420 ok
}

char *hook_raw_image_addr()
{
    return (char*)0x10577E28;  // same in a420 ok
}

long hook_raw_size()
{
    return 0x4FEED0;   //same in a420 @0xffe68a38    // ?? "CRAW BUF","WBIntegPrm.c" -  1/3" 4 MPix -  (2272*1704*10/8=0x49D7C0)
}

/*
void *vid_get_viewport_live_fb()
{
    return (void*)0;
}
*/

void *vid_get_viewport_live_fb() // from a540
{
       void **fb=(void **)0x4FE0; // a420 @0xFFC8BE74
       unsigned char buff = *((unsigned char*)0x4FF0); //a420 @0xFFC8BE70
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
    return (void*)0x103C79A0; // i guess OK in a420 (@ffd0791c), same as in a430
}

void *vid_get_viewport_fb()
{
    return (void*)0x105F2830; // also OK in a420, same as in a430 (find on "VRAM Address  : %p")
}

void *vid_get_viewport_fb_d()
{
    return (void*)(*(int*)0x715C8); // a420 @ffd0bb14
}

long vid_get_bitmap_screen_width()
{
    return 360;
}

long vid_get_bitmap_screen_height()
{
    return 240;
}

long vid_get_viewport_height()
{
    // return ((mode_get()&MODE_MASK) == MODE_PLAY) ? 240 : 230;
    return 240;
}

char *camera_jpeg_count_str()
{
    return (char*)0x7C060; //a420 @ffdfe088
} 

long vid_get_bitmap_buffer_width() { return 360; }

long vid_get_bitmap_buffer_height() { return 240; }
/*
int vid_get_viewport_width_proper()             { return ((mode_get()&MODE_MASK) == MODE_PLAY)?720:*(int*)0x34100;} //sub_ffc8e690
int vid_get_viewport_height_proper()            { return vid_get_viewport_height(); }
*/