#include "platform.h"

char *hook_raw_image_addr()
{
	return (char*) (*(int*)(0x55CC+0x18) ? 0x424F1948 : 0x40F65B18);
}

void *vid_get_viewport_live_fb()
{
    void **fb=(void **)0x227C;
    unsigned char buff = *((unsigned char*)0x20D0); // sub_FF839DD8	
    if (buff == 0) buff = 2;  else buff--;    
    return fb[buff];
}

void *vid_get_bitmap_fb()
{
	return (void*)0x403B1000; 
}

void *vid_get_viewport_fb()
{
	return (void*)0x4070D9D0;
}

