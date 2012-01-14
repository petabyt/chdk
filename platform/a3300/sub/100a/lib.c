#include "platform.h"

char *hook_raw_image_addr()   
{
	if (*((int*)0x3A7D) != 0)   //FF887A64
	{
		return (char*) 0x48000000;  //FF969340
	}
	else
	{
		return (char*) 0x4207DB20;
	}
}

char *hook_alt_raw_image_addr() 
{
	if (*((int*)0x3A7D) == 0)	//FF887A64
		return (char*) 0x48000000;   //FF969340
	else
		return (char*) 0x4207DB20;
}

long hook_raw_size()
{
	return 0x01794300; 
}

char *camera_jpeg_count_str()
{
	 return (void*)0xb40d4;                                      
}


void *vid_get_bitmap_fb()
{	
	return (void*)0x403f1000; 
}	                           


void *vid_get_viewport_fb_d()
{
	return (void*)(*(int*)(0x29A0+0x58));                  
}



void *vid_get_viewport_live_fb()
{
	if ((mode_get()&MODE_MASK) == MODE_REC)
		return (void*)((void*)(*(int*)(0x2258))-vid_get_viewport_xoffset()*3);
	
	return (void*)(void*)(*(int*)(0x2258));
}

                 
void *vid_get_viewport_fb()
{	
	if ((mode_get()&MODE_MASK) == MODE_REC)
		return (void*)(0x40546b80-vid_get_viewport_xoffset()*3);  

	return (void*)0x40546b80;                 
}


long vid_get_viewport_height()
{
	return 240;
}
