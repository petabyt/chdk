#include "platform.h"

char *hook_raw_image_addr()
{
		return (char*) 0x421316C0;		//Search for JPEG BUFF
}

char *hook_alt_raw_image_addr() 
{
		return (char*) 0x421316C0;		//Search for JPEG BUFF
}

void *vid_get_viewport_live_fb()
{
	return (void*)(*(int*)(0x20D0+0x138));		//FF850CA0 + FF850CF0  a3200is 100c
}     

//Found by findsig  a3200 100a
void *vid_get_bitmap_fb()        { return (void*)0x403f1000; }             // Found @0xff85b834
void *vid_get_viewport_fb()      { return (void*)0x40546b80; }             // Found @0xffb1db4c
void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x29a0+0x58)); } // Found @0xff871340 & 0xff871378
char *camera_jpeg_count_str()    { return (char*)0x000b44d4; }             // Found @0xff9fd22c
long hook_raw_size()             { return 0x014d2400; }                    // Found @0xffb21010
//int get_flash_params_count(void) { return 0xa0; }                          // Found @0xff9941e4
