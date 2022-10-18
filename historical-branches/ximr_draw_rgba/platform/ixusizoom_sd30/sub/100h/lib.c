#include "platform.h"

char *hook_raw_image_addr()
{
    return (char*)0x10584DF4; //OK	=aA08x_crw  Found @  0xff91e35c
}

// buffer of live picture when shoot button is not pressed
void *vid_get_viewport_live_fb()
{
	return (void*)0;	//????????????????????????????
}

/**
 * OSD screen
  */
void *vid_get_bitmap_fb()
{
    return (void*) 0x103C79A0; //OK		=aA08x_dat
}

/**
 * IMG viewport in 'rec' mode
 */
// buffer of live picture when shoot button is (half-)pressed.
void *vid_get_viewport_fb()
{
    return (void*)0x106027C8;	//OK	loc_FF921AD0
}

/**
 * IMG viewport in 'play' mode
 */
// buffer of picture in play mode
void *vid_get_viewport_fb_d()
{
	return (void*)0x7B6A8; 	//OK	sub_FF9243CC
}

long vid_get_viewport_height()
{
    return ((mode_get()&MODE_MASK) == MODE_PLAY)?240:230;
}

char *camera_jpeg_count_str()
{
    return (char*)0x88860; //OK
}
