#include "stubs_asm.h"
DEF(file_counter_var,              0x0001385c) // unchanged from 100d - found @fc1d0ff4 by searching for "FileBackupProperty.c", similar to sx280hs 
// first raw buffer when canon raw enabled 0x4427bfa0, possibly 0x46063fa0, more?
DEF(raw_buffers_canon_raw         ,0xfc66e8b4) // equivalent to 100d - Found @fc184334, near DevelopAddress.c assert, after GetPropertyCase similar to sx280hs
// canon raw disabled, uses 0x435ee300 0x453d6300 0x471be300
DEF(raw_buffers_jpeg              ,0xfc66ed4c) // equivalent to 100d @fc184cf6 - Found based on partial image in raw enabled buffer, refs @fc184cf6, fc14c6be
DEF(active_raw_buffer             ,0x0000be08+0xc) // unchanged from 100d - Found @fc152724, similar to sx280hs 0xffffffff when uninited, seems valid range 0-2
DEF(av_override_semaphore         ,0x0002708c) // unchanged from 100d - Found in MoveIrisWithAv 0xfc3d1aed, required for bracketing Created by Mecha.Create in fc3d1a74
DEF(canon_menu_active             ,0x0000ca70+0x8) // unchanged from 100d - found @fc31dda4, via call to sub_fc31dd9e, near ref to "MviCon_ClrEvt" @fc33a80e
// unchanged from 100d - via sub_fc13b3da, struct ref'd by 0x880c-0x58 near start.
// Contains viewport address that updates at ~30fps in rec mode, 0 or last rec value in pb
DEF(current_viewport_buffer       ,0x000087f0)
DEF(viewport_buffers              ,0xfc612b58) // via fc13b25c ref to fc612b48 vs 100d ref to fc612b74, assume x+0x10
DEF(current_fb_d                  ,0x00010140) // assumed same as 100d - https://chdk.setepontos.com/index.php?topic=12532.msg129914#msg129914
//FAKEDEF(movie_status,1)
DEF(simple_movie_status,0xbbb4) // unchanged from 100d - 0x0000bae8 + 0x80 + 0x4c found @fc14a03c sub_fc14a00c via task_MovieRecord. 1 when recording or busy after, 0 otherwise
FAKEDEF(video_compression_rate, 1)
FAKEDEF(canon_shoot_menu_active, 1)
FAKEDEF(full_screen_refresh, 1)
DEF(zoom_status                             ,0x0000fdb0+4) // unchanged from 100d - Found @0xfc1b5116, unclear which offset should be used
// below is 1 for both timed review and hold 0xfc33be5e "StartRecReviewTimer", goes to 0 when time expires even if button held
//DEF(recreview_hold              ,0x91D4) 
// 0xfc33aea0 "ShtCon_StopReview" originally from https://chdk.setepontos.com/index.php?topic=12692.msg130261#msg130261 
// 1 for both timed review and hold 0xfc33be5e "StartRecReviewTimer", stays 1 after time expires if shutter held
DEF(recreview_hold                ,0x9194)
// based on search for 8800 100
// unchanged from 100d - 101 entries, 2 words each, first is fl
DEF(focus_len_table                         ,0xfdf2deb4)
DEF(bitmap_buffer, 0xca3c) // equivalent to 100d - struct starts @ 0xca04, from sub @0xfc361a75
DEF(dial_positions,0x00010320) //  equivalent to 100d - from sub_fc0774e4, Jogdial at 0x00010320 0x00010328, front dial at 0x00010324 0x0001032c

// to hook asserts for debugging
//DEF(assert_handler,0x00008434) // from DebugAssert, 0x010e5cb8 in RAM code

// TODO sx280 C&P
//DEF(led_table,)
//DEF(error_table                             ,0xfc512234) // Found @0xfc1abf24
// DEF(jog_hw_pos,                             0xd9854004) // found by browsing the 0xd985xxxx range...
//FAKEDEF(enabled_refresh_physical_screen,    1)
//DEF(displaytype,                            0x8eb8) //0x8ea4 + 0x14, found  @ fc135f2a (GetDisplayType)
