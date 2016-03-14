#include "stubs_asm.h"
DEF(file_counter_var,              0x0001385c) // found @fc1d0ff4 by searching for "FileBackupProperty.c", similar to sx280hs 
// first raw buffer when canon raw enabled 0x4427bfa0, possibly 0x46063fa0, more?
DEF(raw_buffers_canon_raw         ,0xfc66e8e0) // Found @fc184334, near DevelopAddress.c assert, after GetPropertyCase similar to sx280hs
// canon raw disabled, uses 0x435ee300 0x453d6300 0x471be300
DEF(raw_buffers_jpeg              ,0xfc66ed78) // Found based on partial image in raw enabled buffer, refs @fc184cf6, fc14c6be
DEF(active_raw_buffer             ,0x0000be08+0xc) // Found @fc152724, similar to sx280hs 0xffffffff when uninited, seems valid range 0-2
DEF(focus_busy                    ,0x00013ba8+0x8) // Found @fc31eedc, last func called by MoveFocusLensToTerminate
DEF(av_override_semaphore         ,0x0002708c) // Found in MoveIrisWithAv 0xfc3d1aed, required for bracketing Created by Mecha.Create in fc3d1a74

FAKEDEF(movie_status,1)
FAKEDEF(video_compression_rate, 1)
FAKEDEF(canon_menu_active,    1)
FAKEDEF(canon_shoot_menu_active, 1)
FAKEDEF(full_screen_refresh, 1)
DEF(zoom_status                             ,0x0000fdb0+4) // Found @0xfc1b5116, unclear which offset should be used
FAKEDEF(recreview_hold                          ,1)
// based on search for 8800 100
// 101 entries, 2 words each, first is fl
DEF(focus_len_table                         ,0xfdf2deb4)
DEF(bitmap_buffer, 0xca3c) // struct starts @ 0xca04, from sub @0xfc361a75
DEF(active_bitmap_buffer, 0xca34) // guess, based on similarity to sx280

// TODO sx280 C&P
//DEF(led_table,)
//DEF(error_table                             ,0xfc512234) // Found @0xfc1abf24
// DEF(jog_position,                           0xdb48) // 0xdb34 +0x14, +0x18
// DEF(jog_hw_pos,                             0xd9854004) // found by browsing the 0xd985xxxx range...
//FAKEDEF(enabled_refresh_physical_screen,    1)
//DEF(displaytype,                            0x8eb8) //0x8ea4 + 0x14, found  @ fc135f2a (GetDisplayType)
