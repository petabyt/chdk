#include "platform.h"

void *vid_get_bitmap_fb()        { return (void*)0x40685000; }             // Found @0xff051fbc
void *vid_get_viewport_fb()      { return (void*)0x407dab80; }             // Found @0xff3fc0d0
void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x3da0+0x58)); } // Found @0xff07007c & 0xff0700b4
char *camera_jpeg_count_str()    { return (char*)0x000cf0cc; }             // Found @0xff289050
long hook_raw_size()             { return 0x01297380; }                    // Found @0xff3feed8
int get_flash_params_count(void) { return 0x9f; }                          // Found @0xff206d58

char *hook_raw_image_addr()
{
	// Appears to be two raw buffers (this returns active buffer)
	// Addresses below found in table at ff467f78 used in sub_ff0f26b8 
	// [0x40E0 + 0xC] --> defines which buffer is active

	if (*((int*)0x40EC) != 0)
		return (char*) 0x4AD65BC0;
	else
		return (char*) 0x44000000;	// found at (ff3feed4) [search CRAW BUF]
}

char *hook_alt_raw_image_addr()
{
	// Appears to be two raw buffers (this returns active buffer)
	// Addresses below found in table at ff467f78 used in sub_ff0f26b8 
	// [0x40E0 + 0xC] --> defines which buffer is active

	if (*((int*)0x40EC) == 0)
		return (char*) 0x4AD65BC0;
	else
		return (char*) 0x44000000;	// found at (ff3feed4) [search CRAW BUF]
}

