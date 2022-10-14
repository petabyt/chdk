#include "stubs_asm.h"

DEF(active_raw_buffer                       ,0x0000babc) // xFound @0xFC154b5c, 0xffffffff when uninited (0xC offset added similar to sx280)  
DEF(raw_buffers_canon_raw                   ,0xfc631850) // found @fc177ede
DEF(raw_buffers_jpeg                         ,0xfc631be0) //near DevelopPipeline.c at fc178752 

DEF(current_fb_d                           ,0xfa9c) // found by searching near fa78
DEF(current_viewport_buffer                ,0x8810) //found by searching near 0x875a
DEF(viewport_buffers                       ,0xfc5cf040)//memory search refs to fc5cf028

FAKEDEF(movie_status                       ,1)
FAKEDEF(video_compression_rate             ,1)
FAKEDEF(full_screen_refresh                ,1)    // ,0x00014BD4) // xFound @0xFC333f00
FAKEDEF(canon_shoot_menu_active             ,1) // ??? not found
DEF(zoom_status                             ,0x00021C66) //x could be wrong in both 100f and 100b shoud be 21C80-24 Found @0xFC3752e8 or g7x wildly different

DEF(recreview_hold                          ,0x000091f0) 
//above found using rmem -i32 0x9100 64 near 0x914c

DEF(dial_positions,0x0000fc88) //guess base is 00fc6c

// not porting the following
DEF(jog_position,                           0xfc8c) // 
DEF(jog_hw_pos,                             0xd9854004) // todo found by browsing the 0xd985xxxx range...

DEF(simple_movie_status, 0x13b18) // using rmem from looking at addresses in task-movie-re

