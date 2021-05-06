#include "stubs_asm.h"

DEF(file_counter_var                        ,0x00013148) // xfound by searching for "FileBackupProperty.c" 
DEF(active_raw_buffer                       ,0x0000babc) // xFound @0xFC154b5c, 0xffffffff when uninited (0xC offset added similar to sx280)  
DEF(raw_buffers_canon_raw                   ,0xfc631864 + 0x28) //near DevelopAddress.c
DEF(raw_buffers_jpeg                         ,0xfc631bf4 + 0x28) //near DevelopPipeline.c 0xfc631c00
DEF(av_override_semaphore                     ,0x0002569c) //x found at 0xfc39d516 near aIrisCoeafficient
//DEF(fileio_semaphore                        ,0x00013294) // xFound @0xfc06e61a

//DEF(physw_status                            ,0x00033F64) // xFound @0xFC073368
//DEF(physw_run                               ,0x000082C8) // xFound @0xFC07306a
//DEF(physw_sleep_delay                       ,0x000083d0) // xFound @0xFC073068
//DEF(physw_sleep_delay                       ,0x000082d0) // xFound @0xFC073068
//DEF(levent_table                            ,0xFC66AA18) // xFound @0xFC0CC574
//DEF(FlashParamsTable                        ,0xFC9021f4) // xFound at FC1198DC
//DEF(movie_status                            ,0x00013a60) // xFund at fc1d4fc6
DEF(current_fb_d                           ,0xfa9c) // found by searching near fa78
DEF(current_viewport_buffer                ,0x8810) //found by searching near 0x875a
DEF(viewport_buffers                       ,0xfc5cf054)// no change from 100f memory search? but this indicates change  refs to fc5cf03c + 28 = fc5cf064
FAKEDEF(movie_status                       ,1)
FAKEDEF(video_compression_rate             ,1)
FAKEDEF(full_screen_refresh                ,1)    // ,0x00014BD4) // xFound @0xFC333f00
DEF(canon_menu_active                       ,0x0000c238 + 0x8) // found at 0xfc255c8 
FAKEDEF(canon_shoot_menu_active             ,1) // ??? not found
DEF(zoom_status                             ,0x00021C66) //x or 21C80-24 Found @0xFC3752d4

//DEF(error_table                             ,0xFC66A6D8) // Found @0xFC1E0E4C NOTMIGRATED

DEF(focus_len_table                         ,0xfdf317ec ) // did not change from 100f
DEF(recreview_hold                          ,0x000091f0) //x found @0xFC31B670 above ShtCon_Shut xxx
//above found by using     rmem -i32 0x9100 64 (near 914c)
//DEF_CONST(uiprop_count                      ,0x000000C7) //x Found @0xFC0AA514

DEF(bitmap_buffer, 0xc204) // look at 0xfc33701a 
DEF(active_bitmap_buffer, 0xc1fc) // subtract 8
DEF(dial_positions,0x0000fc88)

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
DEF(displaytype,                              0x9284) // 0x923c + 0x48 found @0xfc304708 (42 refs)
DEF(simple_movie_status, 0x13b18) // using rmem from looking at addresses in task-movie-re
