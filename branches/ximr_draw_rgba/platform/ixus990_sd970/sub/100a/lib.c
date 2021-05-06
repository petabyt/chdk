#include "platform.h"

char *hook_raw_image_addr()
{
	//sd970 100A searched in Ghidra for function AttachIntegCrawData_FW
	//sd780 was: 0x424AD900 -> we find the decompile: FUN_ff8488a4("INTEGCRW",&DAT_424ad900,uVar2);
	//and for sd970: FUN_ff849c5c("INTEGCRW",&DAT_41ec0600,uVar2);
	return (char*)0x41ec0600;
}

void *vid_get_viewport_live_fb()
{
    void **fb=(void **)0x4094;
    unsigned char buff = *((unsigned char*)0x3F00);
    if (buff == 0) buff = 2;  else buff--;    
    return fb[buff];
}

void *vid_get_bitmap_fb()        { return (void*)0x403f1000; }             // sd970 100A: Found @0xff83db4c
void *vid_get_viewport_fb()      { return (void*)0x4126f570; }             // sd970 100A: Found @0xffaba6cc
void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x2754+0x58)); } // sd970 100A: Found @0xff85505c & 0xff855094
char *camera_jpeg_count_str()    { return (char*)0x000345e0; }             // sd970 100A: Found @0xff9a6de8

void *vid_get_bitmap_active_buffer()
{
    return (void*)(*(int*)(0x5168+0x14)); // "Add: %p Width : %ld Height : %ld", sd970: 0xff8cee34
}
