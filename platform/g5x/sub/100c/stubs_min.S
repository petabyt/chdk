#include "stubs_asm.h"

DEF(bitmap_buffer                   ,0xd140)        // OK Usage of param to transfer_src_overlay
DEF(opacity_buffer                  ,0xfc108c18)    // OK Found after BmpDDev.c string

DEF(dial_positions                  ,0x000e9880)    // OK keyboard code @fc0a3ee4 after call to get_dial_hw_position

DEF(canon_menu_active               ,0x0000D180)    // OK found @FC364404 + FC364408 start of StartRecModeMenu_FW
DEF(file_counter_var                ,0x000146EC)    // OK found @FC111EF4 by searching for "FileBackupProperty.c"
DEF(zoom_status                     ,0x00010C8C)    // OK found @FC107CF8 search for "TerminateDeliverToZoomController"
DEF(recreview_hold                  ,0x000095F0)    // OK found @FC38F854 search for "ShootCon_NotifyComplete"
DEF(evf_active                      ,0x00010c0d)    // OK found @fc2d9ea8, called @fc1b6d66 after check for ActiveEyeSensor levent id 0x113a [byte value]

// TODO:

DEF(movie_status                    ,0x00010b08) // ???

FAKEDEF(video_compression_rate, 1)
FAKEDEF(canon_shoot_menu_active, 1) // ??? not found
