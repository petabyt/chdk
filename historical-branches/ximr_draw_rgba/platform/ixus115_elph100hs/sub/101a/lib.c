#include "platform.h"

char *hook_raw_image_addr()
{
	// Appears to be two raw buffers (this returns active buffer)
	// Addresses below found in table at 0xFFB9AE20 used in sub_FF883610
	// checks [0x2E30 + 0xc] --> defines which buffer is active

	if (*((int*)0x2E3C) != 0)		// [0x2E30+0xC] look at routine starting at FF883610
		return (char*) 0x46000000;	// these two addresses found in table FFB9AE20 (used in FF883610)
	else
		return (char*) 0x413391A0;	//

}

char *hook_alt_raw_image_addr()
{

	if (*((int*)0x2E3C) == 0)
		return (char*) 0x46000000;
	else
		return (char*) 0x413391A0;

}

// OSD buffer
void *vid_get_bitmap_fb()
{
	//elph100
	//FF92668C                 LDR     R0, =0x40471000
	return (void*)0x40471000;
}

void *vid_get_viewport_fb_d()
{
	//FF876518 dword_FF876518  DCD 0x3C70
	//FF877298                 STR     R12, [R5,#0x58]
	return (void*)(*(int*)(0x2BA0+0x58));

}

char *camera_jpeg_count_str()
{
	//FFA2629C         LDR     R0, =0xBB3A8 (near to "9999")
	return (void*)0xBB3A8;

}

void *vid_get_bitmap_active_buffer()
{
    return (void*)(*(int*)(0x5AC4+0x18)); //found @ loc_ff9267ac ixus115 101a
}
