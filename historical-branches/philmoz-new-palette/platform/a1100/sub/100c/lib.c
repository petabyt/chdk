#include "platform.h"

char *hook_raw_image_addr()
{
	return (char*) 0x4139E56C; // "CRAW BUFF"---fixed
}

void *vid_get_viewport_live_fb()
{
    void **fb=(void **)0x4094;//-----> fixed
    unsigned char buff = *((unsigned char*)0x3F00); //   -----fixed
    if (buff == 0) buff = 2;  else buff--;    
    return fb[buff];
}

void *vid_get_bitmap_fb()
{
	return (void*)0x403F1000; // "BmpDDev.c"----fixed
}

void *vid_get_viewport_fb()
{
	return (void*)0x4076FCC0;  // "VRAM Address"----fixed
}

void *vid_get_viewport_fb_d()
{
	return (void*)(*(int*)(0x2630+0x58)); // sub_FFC3C050   ---fixed
//	return (void*)(*(int*)(0x2630+0x54)); // sub_FFC3C050   ---fixed
}

long vid_get_viewport_height()
{
	return 240;
}

char *camera_jpeg_count_str()
{
	return (char*)0x2F4A8;  // "9999"-----fixed
}

/*
void *vid_get_bitmap_active_palette() {
    return (void *)*(unsigned int*)(0x4988+0x28);  // sub_FFCAD2C0, via sub_FFD669A8 two refs to "Palette Class."
}
*/

void *vid_get_bitmap_active_buffer()
{
    return (void*)(*(int*)(0x4988+0x14)); //SaveBmpVRAMData "Add: %p Width : %ld Hight : %ld", sub_FFCAD36C
}
