#include "stubs_asm.h"

DEF(current_viewport_buffer         ,0x00010388)    // OK search RAM for first viewport_buffer, second address
DEF(viewport_buffers                ,0xfc6cdba0)    // OK found by searching for "VRAM Address"
DEF(current_fb_d                    ,0x00011048)    // OK @fc108e70 search for "ImgDDev.c" and look up

// Menu & main OSD bitmap
//DEF(bitmap_buffer1                  ,0x41D81000)            // OK
//DEF(bitmap_buffer2                  ,0x41D81000 + 864*4)    // OK
// Grid & AF frame bitmap
//DEF(bitmap_buffer3                  ,0x41F48A00)
//DEF(bitmap_buffer4                  ,0x41F48A00 + 864*4)

//DEF(yuv_buffer1                     ,0x5fe80000)  // OK search for "BmpDDev.c"
//DEF(yuv_buffer2                     ,0x5fd00000)  // OK Display values from yuv_buffers
DEF(bitmap_buffer                   ,0xd140)        // OK Usage of param to transfer_src_overlay

DEF(dial_positions                  ,0x000e9880)    // OK keyboard code

DEF(canon_menu_active               ,0x0000D180)    // OK found @FC364404 + FC364408 start of StartRecModeMenu_FW
DEF(file_counter_var                ,0x000146EC)    // OK found @FC111EF4 by searching for "FileBackupProperty.c"
DEF(zoom_status                     ,0x00010C8C)    // OK found @FC107CF8 search for "TerminateDeliverToZoomController"
DEF(recreview_hold                  ,0x000095F0)    // OK found @FC38F854 search for "ShootCon_NotifyComplete"

// TODO:

DEF(movie_status                    ,0x00010b08) // ???

FAKEDEF(video_compression_rate, 1)
FAKEDEF(canon_shoot_menu_active, 1) // ??? not found
