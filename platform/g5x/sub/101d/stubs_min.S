#include "stubs_asm.h"

DEF(opacity_buffer                  ,0xfc108c18)    // OK Found after BmpDDev.c string

DEF(dial_positions                  ,0x000e9880)    // OK keyboard code @fc0a3ee4 after call to get_dial_hw_position

DEF(zoom_status                     ,0x00010C8C)    // OK found @FC107CF8 search for "TerminateDeliverToZoomController"
DEF(recreview_hold                  ,0x000095F0)    // OK found @fc38f8be search for "ShootCon_NotifyComplete"

DEF(displaytype                     ,0x9794)        // OK 0x9738 + 0x5c, found @ fc15a792 (GetDisplayType)

DEF(palette_buffer_ptr              ,0x15AF8) // FC378202 in 100c
DEF(active_palette_buffer           ,0x15AF0) // FC3781EA in 100c
DEF(palette_control                 ,0x15AE0) // FC378366 in 100c

// TODO:

DEF(movie_status                    ,0x00010b08) // ???

FAKEDEF(video_compression_rate, 1)
FAKEDEF(canon_shoot_menu_active, 1) // ??? not found
