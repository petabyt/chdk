#include "platform.h"
#include "keyboard.h"

void *hook_raw_fptr()
{
    return (void*)0; 
}

void *hook_raw_ret_addr()
{
    return (void*)0; 
}

// Found at 0xFFA6F66C
char *hook_raw_image_addr()
{
    return (char*)0x10E706A0; 
}

// Found at 0xFFA6499C
long hook_raw_size()
{
    return 0x8CAE10; 
}

void *vid_get_viewport_live_fb()
{
    void **fb=(void **)0x709C; // from sub_FF9CE798
    unsigned char buff = *((unsigned char*)0x70AC);
    if (buff == 0) {
        buff = 2;
    }
    else {
        buff--;
    }
    return fb[buff];
}

// Found at FFA302E0, aBmpddev_c
void *vid_get_bitmap_fb()
{
    return (void*)0x10361000; 
}

// Found at FFA2ED70, aImgddev_c
void *vid_get_viewport_fb()
{
    return (void*)(0x1065BA50); 
}

// Found at , aImageplayer_c
void *vid_get_viewport_fb_d()
{
    return (void*)(*(int*)0x94AE8); 
}

long vid_get_viewport_height()
{
    return ((mode_get()&MODE_MASK) == MODE_PLAY)?240:230;
}

// Found at FF8F95F4
char *camera_jpeg_count_str()
{
    return (char*)0x12600;
}
