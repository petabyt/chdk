#include "platform.h"

/*
IXUS230HS / ELPH310HS
full 19131120
0x1048 *  BF4   =  C29CA0
4168 * 3060 = 12754080 
*/

char *hook_raw_image_addr()
{
	if (*((int*)(0x2EF8 + 0xC)) != 0) // FF0795BC
		return (char*) 0x46000000;  // 
	else
		return (char*) 0x413391A0; // FF368444

}

char *hook_alt_raw_image_addr()
{
	if (*((int*)(0x2EF8 + 0xC)) == 0) // FF0795BC
		return (char*) 0x46000000;  // 
	else
		return (char*) 0x413391A0; // FF368444

}

long hook_raw_size()
{
	//FF36849C
	return 0x0123eaf0;
	
}

void *vid_get_viewport_live_fb()
{
	return (void*)(void*)(*(int*)(0x2158)); // FF044208
}

// OSD buffer
void *vid_get_bitmap_fb()
{	
	//FF053204
	return (void*)0x40471000;
}	                           

// Live picture buffer (shoot half-pressed)
void *vid_get_viewport_fb()
{
	return (void*)0x405c6b80;  					                   // found by search for VRAM Address @FF365654
}

void *vid_get_viewport_fb_d()
{
	//FF06C234
	//FF06C26C
	return (void*)(*(int*)(0x2C58+0x58));                  

}

char *camera_jpeg_count_str()
{
	//FF226398
	return (void*)0x000B9574;                                      

}

