#include "platform.h"

void *vid_get_viewport_fb_d()    { 
//return *(int*)0x000088BC; 
//return *(int*)0x000F3138; 
return (void*)0x5E278000; 
} // TODO: incorrect 0x43115100
char *camera_jpeg_count_str()    { return (char*)0x000e4308; }
