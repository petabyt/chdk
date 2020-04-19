#include "stubs_asm.h"

DEF(dial_positions                  ,0x000109a8)    // OK keyboard code @e0516ef0 after call to get_dial_hw_position

DEF(viewport_buffers                ,0xe05d89f8)    // OK found by searching for "VRAM Address"
DEF(current_fb_d                    ,0x0001082c)    // OK @e03aa714 search for "ImgDDev.c" and look up

DEF(current_viewport_buffer         ,0x00010388)    // OK search RAM for first viewport_buffer, second address

DEF(simple_movie_status             ,0x0000bec0)    // 0x0000bde8 + 0x80 + 0x58 found @e038c01c sub_e038bfec via task_MovieRecord. 1 when recording or busy after, 0 otherwise

// TODO:

DEF(zoom_status                     ,0x00032818)    // OK found @e024f38a search for "TerminateDeliverToZoomController"
DEF(recreview_hold                  ,0x00009564)    // OK found @e036417e search for "ShootCon_NotifyComplete"

FAKEDEF(video_compression_rate, 1)
FAKEDEF(canon_shoot_menu_active, 1) // ??? not found
