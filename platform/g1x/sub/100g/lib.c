#include "platform.h"

char *hook_raw_image_addr()
{
	// Appears to be two raw buffers (this returns active buffer)
	// Addresses below found in table at FF476254 used in sub_FF0EF32C 
	// [0x40C8 + 0xC] --> defines which buffer is active

	if (*((int*)0x40D4) != 0)
		return (char*) 0x4A6BA6A0;
	else
		return (char*) 0x44000000;	// found at (FF40A81C) [search CRAW BUF]
}

char *hook_alt_raw_image_addr()
{
	// Appears to be two raw buffers (this returns inactive buffer)
	// Addresses below found in table at FF476254 used in sub_FF0EF32C 
	// [0x40C8 + 0xC] --> defines which buffer is active

	if (*((int*)0x40D4) == 0)
		return (char*) 0x4A6BA6A0;
	else
		return (char*) 0x44000000;	// found at (FF40A81C) [search CRAW BUF]
}


char *camera_jpeg_count_str()    { return (char*)0x000cc108; }             // Found @0xff28c9cc
long hook_raw_size()             { return 0x01941be8; }                    // Found @0xff40ae1c

void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x3d90+0x58)); } // Found @0xff06e538 & 0xff06e570
