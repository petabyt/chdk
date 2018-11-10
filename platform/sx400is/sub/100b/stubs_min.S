#include "stubs_asm.h"

//http://chdk.setepontos.com/index.php?topic=10617.msg104869#msg104869
DEF(file_counter_var,               0x6d3c)         // Found @0xff985e38 by searching for "FileBackupProperty.c"

DEF(palette_control,                0x8414)         // Found @0xff9d1720 Some instructions before loading Palette colour tables value 
DEF(active_palette_buffer,          0x8414+0x8)     // Found @0x: Guess!!!
DEF(palette_buffer_ptr,             0x8414+0xC)     // Found @0xff9d15ac or 0xff9d1bf0 : Guess palette_control+0xC
DEF(palette_buffer,                 0x106330)       // Found @0xff9d1bf4 check this!!

//DEF(active_viewport_buffer,         0x1af0c)        // By comparison to sx510hs, used near to LiveImage.c string
//DEF(active_viewport_buffer,         0x2108) //@ff84f438  By comparison to a2500
DEF(active_viewport_buffer,         0x1af0c+0x3c)  //@ff84f478 + @ff84fda8, by comparison to sx410

DEF(viewport_buffers,               0xffbf409c)     // ????

DEF(viewport_fb_d,                  0x3420+0x54)    // Found @0xff8831ec (0x3420) + @0xff88322c (0x54) 

DEF(bitmap_buffer,                  0x3b18+0x24)    // Found @0xff8a73bc - by comparison to ixus140
DEF(active_bitmap_buffer,           0x3b18+0x20)    // Found @0xff8a73b0 - by comparison to ixus140

DEF(recreview_hold,                 0x9288+0x1C)    //@sub 0xffa0aaf0

DEF(_nrflag,                        0xB01C+0x04)    // Found @0xffa4d668 - by comparison to ixus410is

DEF(video_compression_rate, 0x75AC) // @ff9a8770: 0x7530+0x80-0x4 by comparison to sx410 100c 
DEF(video_target_framesize, 0xCD44+0x2C) // found in sub_ffafc2f4 by comparison to sx410 100c
DEF(video_target_framesize2, 0xCD44+0x28) // approx. 2*video_target_framesize (for intraframes?), found in sub_ffafc2f4 by comparison to sx410 100c

DEF(av_override_semaphore         ,0xcef0) // MoveIrisWithAv

// the original some_flag_for_af_scan should not be used, as the fw's MakeAFScan function is not called
.globl some_flag_for_af_scan
some_flag_for_af_scan: .long 0
