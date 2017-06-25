#include "platform.h"

char *camera_jpeg_current_filename() {
     return (void*)0x000D922C;                 //TODO: incorrect
}

void *vid_get_viewport_fb_d()    { 
//return *(int*)0x000088BC; 
//return *(int*)0x000F3138; 
return (void*)0x5E278000; 
} // TODO: incorrect 0x43115100
char *camera_jpeg_count_str()    { return (char*)0x000e4308; }
long hook_raw_size()             { return 0x124AB50; }

#ifdef CAM_HAS_GPS // TODO
char * camera_jpeg_current_latitude() {     //asm1989 way to calculate it is camera_jpeg_current_filename  + 0x78
    return (void*)0xD92A4;
}

char * camera_jpeg_current_longitude() {    //asm1989 way to calculate it is camera_jpeg_current_filename  + 0x94
    return (void*)0xD92C0;
}

char * camera_jpeg_current_height() {
    return (void*)0xD909C;
}
#endif
