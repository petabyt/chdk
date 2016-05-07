#include "platform.h"

void *vid_get_bitmap_active_palette()
{
    return (void *)*(unsigned int*)(0x7280+0x2C);//FF191A20 blackhole
}
