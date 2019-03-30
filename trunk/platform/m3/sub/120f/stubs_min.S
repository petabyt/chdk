#include "stubs_asm.h"

DEF(file_counter_var,              0x00012484) //@ found by searching for "FileBackupProperty.c"

// Camera has 3 RAW buffers @ 0x4464F8C8, 0x46FB98A8, 0x49923888
DEF(raw_buffers                   ,0xfc6cb914) // Found @0xFC4073F0
DEF(active_raw_buffer             ,0x0000b3d4) // Found @0xFC143BF2 - 0x18, 0xffffffff when uninited...

DEF(simple_movie_status           ,0x0000b190) // @ 0xFC13FBD6, via sub_fc13fac8 from task_MovieRecord
FAKEDEF(video_compression_rate    ,1)
DEF(full_screen_refresh           ,0x00012a94) // not correct
DEF(canon_menu_active             ,0x0000c1ac) // @ Found @0xfc32df3c
FAKEDEF(canon_shoot_menu_active   ,1) // ??? not found
FAKEDEF(zoom_status               ,1) // ??? not found

DEF(recreview_hold                ,0x000097d4) // Found @fc34b9da
FAKEDEF(zoom_busy                 ,1)
FAKEDEF(focus_busy                ,1)

DEF(bitmap_buffer                 ,0xc174) //@ active_bitmap_buffer + 8
DEF(active_bitmap_buffer          ,0xC16C) // Found @0xFC37F0E8
DEF(current_viewport_buffer       ,0x0000889C) // Found @FC133ECA
DEF(viewport_buffers              ,0xfc5f9320) //from memory search
DEF(current_fb_d                  ,0x0000FA20) //@ Found at 0xFC178644

DEF(jog_position                  ,0xdb48) // 0xdb34 +0x14, +0x18
DEF(jog_hw_pos                    ,0xd9854004) // found by browsing the 0xd985xxxx range...

DEF(displaytype                   ,0x9990) // found  @ 0xFC35DF44

DEF(palette_buffer_ptr            ,0x136e0) // FC3549F2, FC354A0E
DEF(active_palette_buffer         ,0x136d8) // FC3549F2, FC3549F6
DEF(palette_control               ,0x136c8) // FC354B56, FC354B76
