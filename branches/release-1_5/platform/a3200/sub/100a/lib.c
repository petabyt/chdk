#include "platform.h"

char *hook_raw_image_addr()
{
		return (char*) 0x421316C0;		//Search for JPEG BUFF
}

char *hook_alt_raw_image_addr() 
{
		return (char*) 0x421316C0;		//Search for JPEG BUFF
}

//Found by findsig  a3200 100a
void *vid_get_bitmap_fb()        { return (void*)0x403f1000; }             // Found @0xff85b834
void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x29a0+0x58)); } // Found @0xff871340 & 0xff871378
char *camera_jpeg_count_str()    { return (char*)0x000b44d4; }             // Found @0xff9fd22c

void *vid_get_bitmap_active_buffer()
{
    return (void*)(*(int*)(0x5680+0x18)); //found @ 0xff9152d4 a3200 100d, same in 100a
}
