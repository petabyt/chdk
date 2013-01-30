#include "platform.h"

char *hook_raw_image_addr()     {return (char*) 0x420B7FC0;}   //Found @0xffae0828 a2300
char *hook_alt_raw_image_addr() {return (char*) 0x420B7FC0;}   //Found @0xffae0828 a2300

//To do:
void *vid_get_viewport_live_fb()
{
    return 0x0;
}

/*Auto generated for a2300 100e*/
void *vid_get_bitmap_fb()        { return (void*)0x40411000; }             // Found @0xff852ebc
void *vid_get_viewport_fb()      { return (void*)0x40566b80; }             // Found @0xffaddf88
void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x2970+0x54)); } // Found @0xff867dc0 & 0xff867df8
char *camera_jpeg_count_str()    { return (char*)0x000b376c; }             // Found @0xff9c91d8
long hook_raw_size()             { return 0x01794300; }                    // Found @0xffae0dbc
int get_flash_params_count(void) { return 0xa6; }                          // Found @0xff9859bc
