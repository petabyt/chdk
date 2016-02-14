#include "stubs_asm.h"

DEF(file_counter_var,              0x0001385c) // found @fc1d0ff4 by searching for "FileBackupProperty.c", similar to sx280hs 
FAKEDEF(movie_status,0)
FAKEDEF(video_compression_rate, 1)
FAKEDEF(canon_menu_active,	0)
FAKEDEF(canon_shoot_menu_active, 1)
FAKEDEF(full_screen_refresh, 0)
DEF(zoom_status                             ,0x0000fdb0+4) // Found @0xfc1b5116, unclear which offset should be used
FAKEDEF(zoom_busy                               ,0)
FAKEDEF(focus_busy                              ,0)
FAKEDEF(recreview_hold                          ,0)
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
