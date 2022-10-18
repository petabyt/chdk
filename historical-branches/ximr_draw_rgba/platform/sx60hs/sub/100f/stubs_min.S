#include "stubs_asm.h"

DEF(active_raw_buffer                       ,0x0000babc) // xFound @0xFC154b5c, 0xffffffff when uninited (0xC offset added similar to sx280)  
DEF(raw_buffers_canon_raw                   ,0xfc631864) //near DevelopAddress.c
DEF(raw_buffers_jpeg                         ,0xfc631bf4) //near DevelopPipeline.c 0xfc631c00

DEF(current_fb_d                           ,0xfa9c) // found by searching near fa78
DEF(current_viewport_buffer                ,0x8810) //found by searching near 0x875a
DEF(viewport_buffers                       ,0xfc5cf054)//memory search refs to fc5cf03c

FAKEDEF(movie_status                       ,1)
FAKEDEF(video_compression_rate             ,1)
FAKEDEF(full_screen_refresh                ,1)    // ,0x00014BD4) // xFound @0xFC333f00
FAKEDEF(canon_shoot_menu_active             ,1) // ??? not found
DEF(zoom_status                             ,0x00021C66) //x or 21C80-24 Found @0xFC3752d4

DEF(recreview_hold                          ,0x000091f0) //x found @0xFC31B670 above ShtCon_Shut xxx
//above found by using     rmem -i32 0x9100 64 (near 914c)

DEF(dial_positions,0x0000fc88)

// not porting the following
DEF(jog_position,                           0xfc8c) // 
DEF(jog_hw_pos,                             0xd9854004) // todo found by browsing the 0xd985xxxx range...

DEF(simple_movie_status, 0x13b18) // using rmem from looking at addresses in task-movie-re
