#include "platform.h"

char *camera_jpeg_count_str() { return (char*)0x000c75f4; } // Found @0xff236e4c
long hook_raw_size()          { return 0x0123eaf0; }        // Found @0xff38eaec

char *hook_raw_image_addr()
{
	// Appears to be two raw buffers (this returns active buffer)
	// Addresses below found in table at FF3D1BB4 used in sub_FF0770FC
	// checks [0x2F80 + 0xc] --> defines which buffer is active

	if (*((int*)0x2F8C) != 0)
		return (char*) 0x46000000;
	else
		return (char*) 0x413591F0;	// found at (FF38EA94) [search CRAW BUF]
}

char *hook_alt_raw_image_addr()
{
	// Appears to be two raw buffers (this returns active buffer)
	// Addresses below found in table at FF3D1BB4 used in sub_FF0770FC
	// checks [0x2F80 + 0xc] --> defines which buffer is active

	if (*((int*)0x2F8C) == 0)
		return (char*) 0x46000000;
	else
		return (char*) 0x413591F0;	// found at (FF38EA94) [search CRAW BUF]
}


void *vid_get_viewport_fb_d()
{
	return (void*)(*(int*)(0x2CE8+0x58)); // @FF06A728 & FF06A760
}
