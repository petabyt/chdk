#include "stubs_asm.h"

DEF(dial_positions                  ,0x000109a8)    // OK keyboard code @e0516ef0 after call to get_dial_hw_position

DEF(simple_movie_status             ,0x0000bec0)    // 0x0000bde8 + 0x80 + 0x58 found @e038c01c sub_e038bfec via task_MovieRecord. 1 when recording or busy after, 0 otherwise

// TODO:

DEF(zoom_status                     ,0x00032818)    // OK found @e024f38a search for "TerminateDeliverToZoomController"
DEF(recreview_hold                  ,0x00009564)    // OK found @e036417e search for "ShootCon_NotifyComplete"

FAKEDEF(video_compression_rate, 1)
FAKEDEF(canon_shoot_menu_active, 1) // ??? not found
