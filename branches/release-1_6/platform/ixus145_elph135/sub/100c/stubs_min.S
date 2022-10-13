#include "stubs_asm.h"

//http://chdk.setepontos.com/index.php?topic=10617.msg104869#msg104869
DEF(file_counter_var,0x688c) // found by searching for "FileBackupProperty.c"

DEF(palette_control,                0x000078dc) // Found @0xff9b1024
DEF(active_palette_buffer,          0x000078dc+0x8) // Found @0xff9b11a8 (loc_ff9b119c)
DEF(palette_buffer_ptr,             0x000078dc+0xC) // Guess palette_control+0xC
DEF(palette_buffer,                 0x000d1864) // Found @0xff9b15a0

DEF(active_viewport_buffer,         0x000185e4) // found @0xff84d544
DEF(viewport_buffers,               0xffba8610) // by comparison to sx170is

DEF(bitmap_buffer,                  0x000039e0+0x20) // Found @0xff89fa4c (0x39e0) + @0x (0x20) - by comparison to ixus140
DEF(active_bitmap_buffer,           0x000039e0+0x24) // Found @0xff89fa4c (0x39e0) + @0x (0x24) - by comparison to ixus140

DEF(recreview_hold,                 0x00002738+0x84) // @0xff860010 +0x84 (offset used by A2500)
