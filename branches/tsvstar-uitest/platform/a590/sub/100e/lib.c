#include "platform.h"

void *hook_raw_fptr()
{
    return (void*)0;
}

void *hook_raw_ret_addr()
{
    return (void*)0;
}

char *hook_raw_image_addr()
{
    return (char*)0x10F63920; //found at 0xFFD987A8
}

long hook_raw_size()
{
//3264*2448 jpg file
	return 0x9DCCE0; //for draw compatibility
	//return 0x9E6FC4; //OK!!!! //3336*2490 greater area respect to jpg
}

void *vid_get_viewport_live_fb()
{
    void **fb=(void **)0x2168;
    unsigned char buff = *((unsigned char*)0x1FE8); //0x1fe8 found at 0xFFC294D
    if (buff == 0) {
        buff = 2;
    }
    else {
        buff--;
    }
    return fb[buff];
}

void *vid_get_bitmap_fb()  //OSD buffer     
{
    return (void*)0x10361000; //ok found at FFDC0F84
}

void *vid_get_viewport_fb()
{
	 return (void*)0x10659E80; //ok found at 0xFFC2BCB0
}

void *vid_get_viewport_fb_d()
{

	//return (void*)(*(int*)0x5228);
	//520c+1c
	// http://chdk.setepontos.com/index.php/topic,2361.msg27125.html#msg27125
	// sub_FFC45328
	return (void*)(*(int*)(0x520C+0x4C));  //0x5258
	
}

char *camera_jpeg_count_str()
{
    return (char*)0x49344; // ok found at FFD727B0
}

// PTP display stuff
void *vid_get_bitmap_active_palette() {
    return (void *)0x3D518; // GetPaletteFromPhysicalScreen
}

void *vid_get_bitmap_active_buffer()
{
    return (void*)(*(int*)0x761C); // DisplayPhysicalScreenWithYUVPalette
}
