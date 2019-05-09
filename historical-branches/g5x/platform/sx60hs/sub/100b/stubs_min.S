#include "stubs_asm.h"

DEF(file_counter_var                        ,0x00013148) // xfound by searching for "FileBackupProperty.c" 
DEF(active_raw_buffer                       ,0x0000babc) // xFound @0xFC154b5c, 0xffffffff when uninited (0xC offset added similar to sx280)  
DEF(raw_buffers_canon_raw                   ,0xfc631850) // found @fc177ede
DEF(raw_buffers_jpeg                         ,0xfc631be0) //near DevelopPipeline.c at fc178752 
DEF(av_override_semaphore                     ,0x0002569c) //x found at 0xfc39d52a near aIrisCoeafficient

DEF(current_viewport_buffer                ,0x8810) //found by searching near 0x875a
DEF(viewport_buffers                       ,0xfc5cf040)//memory search refs to fc5cf028

FAKEDEF(movie_status                       ,1)
FAKEDEF(video_compression_rate             ,1)
FAKEDEF(full_screen_refresh                ,1)    // ,0x00014BD4) // xFound @0xFC333f00
DEF(canon_menu_active                  ,0x0000c238 + 0x8) //found at 0xfc2f5560
FAKEDEF(canon_shoot_menu_active             ,1) // ??? not found
DEF(zoom_status                             ,0x00021C66) //x could be wrong in both 100f and 100b shoud be 21C80-24 Found @0xFC3752e8 or g7x wildly different

DEF(focus_len_table                         ,0xfdf317ec) // looks good 380 mmm
DEF(recreview_hold                          ,0x000091f0) 
//above found using rmem -i32 0x9100 64 near 0x914c

DEF(bitmap_buffer, 0xc204) // look at 0xfc33702e  must be some math 0000c1cc
DEF(active_bitmap_buffer, 0xc1fc) // subtract 8
DEF(dial_positions,0x0000fc88) //guess base is 00fc6c
//FAKEDEF(active_bitmap_buffer                ,0)

// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 2 int value(s), the first is the zoom focus length.
// there are 102 entries in the table - set NUM_FL to 101
// TO BE MIGRATED


//.globl bitmap_buffer; bitmap_buffer: ; .long 0x427e3000 ; .long 0x42621000 ;
// FAKEDEF(viewport_buffers, 1) // ?
// FAKEDEF(active_viewport_buffer, 1) // ?

// not porting the following
DEF(jog_position,                           0xfc8c) // 
DEF(jog_hw_pos,                             0xd9854004) // todo found by browsing the 0xd985xxxx range...

//FAKEDEF(enabled_refresh_physical_screen,    1)
//DEF(displaytype,                            0x95dc) //0x95c8 + 0x14, found  @ fc135f2a (GetDisplayType)
DEF(displaytype,                            0x9284)//  (GetDisplayType)
DEF(current_fb_d                           ,0xfa9c) // found by searching near fa78
DEF(simple_movie_status, 0x13b18) // using rmem from looking at addresses in task-movie-re

