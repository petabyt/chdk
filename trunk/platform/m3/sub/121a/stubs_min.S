#include "stubs_asm.h"

// Camera has 3 RAW buffers @ 0x4464F8C8, 0x46FB98A8, 0x49923888
DEF(raw_buffers                   ,0xFC6CB944) // Found 0xFC407420
DEF(active_raw_buffer             ,0x0000b3d4) // Found 0xFC143BFA - 0x18, 0xffffffff when uninited...

DEF(simple_movie_status           ,0x0000b190) //  0xFC13FBDE, via task_MovieRecord
FAKEDEF(video_compression_rate    ,1)
DEF(full_screen_refresh           ,0x00012a94) // not correct

FAKEDEF(canon_shoot_menu_active   ,1) // ??? not found
FAKEDEF(zoom_status               ,1) // ??? not found

DEF(recreview_hold                ,0x000097d4) // Found FC34BA0A
FAKEDEF(zoom_busy                 ,1)
FAKEDEF(focus_busy                ,1)

DEF(current_viewport_buffer       ,0x0000889C) // Found FC133ED2
DEF(viewport_buffers              ,0xFC5F9350) //from memory search
DEF(current_fb_d                  ,0x0000FA20) // Found at 0xFC17864C

DEF(jog_position                  ,0xdb48) // 0xdb34 +0x14, +0x18
DEF(jog_hw_pos                    ,0xd9854004) // found by browsing the 0xd985xxxx range...

