#include "stubs_asm.h"

DEF(dial_positions                  ,0x000109a8)    // OK keyboard code @e0516ef0 after call to get_dial_hw_position

DEF(simple_movie_status             ,0x0000bec0)    // 0x0000bde8 + 0x80 + 0x58 found @e038c01c sub_e038bfec via task_MovieRecord. 1 when recording or busy after, 0 otherwise

DEF(raw_buffer_table                ,0xe05d8594)    // Reference @ 0xe023dc6c
DEF(raw_buffer_index                ,0x00008578)    // Reference @ 0xe023dc6e

// TODO:

// Does not behave like other cameras - set to 4 when reviewing. Value calculated in kbd.c to simulate expected behaviour.
DEF(_recreview_hold                 ,0x00009564)    // OK found @e036417e search for "ShootCon_NotifyComplete"

FAKEDEF(video_compression_rate, 1)
FAKEDEF(canon_shoot_menu_active, 1) // ??? not found
