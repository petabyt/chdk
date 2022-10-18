#include "platform.h"

// Documentation stripped, please refer to the S5IS 1.01b lib.c if you
// need it, or wait until someone feels like updating the documentation for this
// particular model.

char *hook_raw_image_addr()
{
	return (char*)0x1163B8E0;
}

void *vid_get_viewport_live_fb()
{
	return (void*)0x0;
}

void *vid_get_bitmap_fb()
{
	return (void*)0x10361000; 
}

void *vid_get_viewport_fb()
{
	return (void*)0x10D29360;
}

void *vid_get_viewport_fb_d()
{
	return (void*)(*(int*)0x5724);  // 0x56D8 + 0x4C
}

long vid_get_viewport_height()
{
	return 240;
}

char *camera_jpeg_count_str()
{
	return (char*)0x58304;
}
