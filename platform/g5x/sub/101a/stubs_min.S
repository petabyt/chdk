#include "stubs_asm.h"

DEF(opacity_buffer                  ,0xfc108c18)    // OK Found after BmpDDev.c string

DEF(dial_positions                  ,0x000e9880)    // OK keyboard code @fc0a3ee4 after call to get_dial_hw_position

DEF(zoom_status                     ,0x00010C8C)    // OK found @FC107CF8 search for "TerminateDeliverToZoomController"
DEF(recreview_hold                  ,0x000095F0)    // OK found @fc38f86c search for "ShootCon_NotifyComplete"

DEF(palette_buffer_ptr              ,0x15AF8) // FC378202 in 100c
DEF(active_palette_buffer           ,0x15AF0) // FC3781EA in 100c
DEF(palette_control                 ,0x15AE0) // FC378366 in 100c

DEF(simple_movie_status             ,0x0000c180)    // 0x0000c088 + 0x80 + 0x78 found @fc0b3eb0 sub_fc0b3e80 via task_MovieRecord. 1 when recording or busy after, 0 otherwise

// TODO:

FAKEDEF(video_compression_rate, 1)
FAKEDEF(canon_shoot_menu_active, 1) // ??? not found
