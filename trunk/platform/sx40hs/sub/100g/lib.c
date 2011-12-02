#include "platform.h"

char *hook_raw_image_addr()
{
	// Appears to be two raw buffers (this returns active buffer)
	// Addresses below found in table at FF445CFC used in sub_FF0ECCEC 
	// [0x3148 + 0xC] --> defines which buffer is active

	if (*((int*)0x3154) != 0)
		return (char*) 0x4ADB54A0;
	else
		return (char*) 0x44000000;	// found at (FF3E3930) [search CRAW BUF]
}

char *hook_alt_raw_image_addr()
{
	// Appears to be two raw buffers (this returns inactive buffer)
	// Addresses below found in table at FF445CFC used in sub_FF0ECCEC 
	// [0x3148 + 0xC] --> defines which buffer is active

	if (*((int*)0x3154) == 0)
		return (char*) 0x4ADB54A0;
	else
		return (char*) 0x44000000;	// found at (FF3E3930) [search CRAW BUF]
}


char *camera_jpeg_count_str()    { return (char*)0x000df0e8; } // Found @0xff285438
long hook_raw_size()             { return 0x01247a60; }        // Found @0xff3e393c


void *vid_get_viewport_fb_d()
{
	return (void*)(*(int*)(0x2CA0+0x58)); // @FF06BFAC & FF06BFE4
}
