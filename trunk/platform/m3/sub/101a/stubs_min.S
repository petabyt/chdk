#include "stubs_asm.h"

DEF(file_counter_var,              0x00012460) //@ found by searching for "FileBackupProperty.c"

// Camera has 3 RAW buffers @ 0x4464F8C8, 0x46FB98A8, 0x49923888
DEF(raw_buffers                   ,0xFC6CB874) // Found @0xFC4071F8 & 0xFC407080
DEF(active_raw_buffer             ,0x0000B3B4) //@ ??? , 0xffffffff when uninited...
//DEF(error_table                             ,0xFC63812C) //@ Found @0xFC18E1A0
DEF(simple_movie_status           ,0x0000b170) // 0x0000b088 + 0x80 + 0x68 @ fc13faf8, via sub_fc13fac8 from task_MovieRecord
FAKEDEF(video_compression_rate    ,1)
DEF(full_screen_refresh           ,0x00012a94) // Found @0xfc2b0f5c
DEF(canon_menu_active             ,0x0000C18C) //@ Found @0xFC32DD9C
FAKEDEF(canon_shoot_menu_active   ,1) // ??? not found
FAKEDEF(zoom_status               ,1) // Found @0xfc30e61c

DEF(recreview_hold                ,0x000097B8) //@ Found @FC34B83A
FAKEDEF(zoom_busy                 ,1)
FAKEDEF(focus_busy                ,1)

DEF(bitmap_buffer                 ,0xC154) //@ active_bitmap_buffer + 8
DEF(active_bitmap_buffer          ,0xC14C) //@ xac10) // or 0xac14? just a guess
DEF(current_viewport_buffer       ,0x0000889C) //8878?  Found @FC133DE2
DEF(viewport_buffers              ,0xFC5F8DE8) // from memory search, refs to FC5F8DD8
DEF(current_fb_d                  ,0x0000FA00) //@ Found at 0xFC17851C

DEF(jog_position                  ,0xdb48) // 0xdb34 +0x14, +0x18
DEF(jog_hw_pos                    ,0xd9854004) // found by browsing the 0xd985xxxx range...

DEF(displaytype                   ,0x9974) //@ 0x9934 + 0x40, found  @ 0xFC35DD56 (GetDisplayType)

DEF(palette_buffer_ptr            ,0x136c0) // FC354852, FC35486E
DEF(active_palette_buffer         ,0x136b8) // FC354852, FC354856
DEF(palette_control               ,0x136a8) // FC3549B6, FC3549D6
