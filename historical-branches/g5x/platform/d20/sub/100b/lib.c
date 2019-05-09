#include "platform.h"

/*
// camera has two raw buffers, see platform lib.c
char *hook_raw_image_addr()     {return (char*) 0x4138AE00;}   //Found @0xff363310 d20 100b Search on JPEG BUFF
*/

char *camera_jpeg_current_filename() {
     return (void*)0xBD06C;                 //0xFF1E2E88 search for  "%03d-%04d"
}

char *camera_jpeg_current_gps() {
    return (void*)0xBD0E0;
}


//Found by finsig d20 100b
void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x2c80+0x54)); } // Found @0xff05f434 & 0xff05f46c
char *camera_jpeg_count_str()    { return (char*)0x000c0a08; }             // Found @0xff21bf70


