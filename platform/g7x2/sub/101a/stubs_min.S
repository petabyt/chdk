#include "stubs_asm.h"

DEF(viewport_buffers                ,0xe05d89f8)    // OK found by searching for "VRAM Address"
DEF(current_fb_d                    ,0x0001082c)    // OK @e03aa714 search for "ImgDDev.c" and look up

// Menu & main OSD bitmap
DEF(bitmap_buffer1                  ,0x425AA000)            // OK found @e037847a
DEF(bitmap_buffer2                  ,0x425AA000 + 864*4)    // OK
// Grid & AF frame bitmap
//DEF(bitmap_buffer3                  ,0x4276C000)
//DEF(bitmap_buffer4                  ,0x4276C000 + 864*4)

//DEF(yuv_buffer1                     ,0x7FE80000)  // OK search for "BmpDDev.c"
//DEF(yuv_buffer2                     ,0x0)  // Display values from yuv_buffers
DEF(bitmap_buffer                   ,0xcdc4)        // OK Usage of param to transfer_src_overlay

DEF(canon_menu_active               ,0x0000ce08)    // OK found @e03756da + e03756de start of StartRecModeMenu_FW
DEF(file_counter_var                ,0x00011084)    // OK found @e0402420 by searching for "FileBackupProperty.c"
DEF(zoom_status                     ,0x00032818)    // OK found @e024f38a search for "TerminateDeliverToZoomController"
DEF(recreview_hold                  ,0x00009498)    // OK found @e036417e search for "ShootCon_NotifyComplete"

// TODO:

DEF(current_viewport_buffer         ,0x00010388)    // OK search RAM for first viewport_buffer, second address

DEF(dial_positions                  ,0x000e9880)

DEF(movie_status                    ,0x00010b08) // ???

FAKEDEF(video_compression_rate, 1)
FAKEDEF(canon_shoot_menu_active, 1) // ??? not found
