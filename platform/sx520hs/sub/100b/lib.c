#include "platform.h"

void *vid_get_bitmap_active_palette()
{
    return (void *)*(unsigned int*)(0x7278+0x2C);//ff191a04
}
