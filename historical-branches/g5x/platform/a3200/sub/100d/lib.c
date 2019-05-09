#include "platform.h"

char *hook_raw_image_addr()
{
		return (char*) 0x421316C0;		//Found at FFB210A4 a3200is
}

char *hook_alt_raw_image_addr() 
{
		return (char*) 0x421316C0;		//Found at FFB210A4 a3200is
}

char *camera_jpeg_count_str()
{
	 return (void*)0x000b44d4;   // Found @0xff9fd22c   a3200is
}


void *vid_get_bitmap_fb()
{	
	return (void*)0x403f1000; // Found @0xff85b834 a3200is
}	                           


void *vid_get_viewport_fb_d()
{
	return (void*)(*(int*)(0x29A0+0x58));     // FF871340 + FF871378  a3200is
}


void *vid_get_bitmap_active_buffer()
{
    return (void*)(*(int*)(0x5680+0x18)); //found @ 0xff9152d4 a3200 100d, same in 100a
}
