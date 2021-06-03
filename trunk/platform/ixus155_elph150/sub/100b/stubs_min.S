#include "stubs_asm.h"

//http://chdk.setepontos.com/index.php?topic=10617.msg104869#msg104869
DEF(file_counter_var,0x693C) // found by searching for "FileBackupProperty.c" !!

DEF(palette_control,                0x00007aec) // Found @ff9b4420
DEF(active_palette_buffer,          0x00007aec+0x8) // Guess based on ixus145

DEF(palette_buffer_ptr,             0x00007aec+0xC) // Guess palette_control+0xC
DEF(palette_buffer,                 0x000Dca1c) // Found @0xff9b4994

DEF(active_viewport_buffer,         0x00018864) // found @0xff84cff4 - by comparison to ixus265
DEF(viewport_buffers,               0xffb96e68) // by comparison to ixus145

DEF(bitmap_buffer,                  0x00003ac0+0x20) // Found @0xff8a2c78 (0x3ac0) + @0x (0x20) - by comparison to ixus145
DEF(active_bitmap_buffer,           0x00003ac0+0x24) // Found @0xff8a2c78 (0x3ac0) + @0x (0x24) - by comparison to ixus145

DEF(recreview_hold,                 0x0000273c+0x84) // @0xff85ff58 +0x84 (offset used by A2500) !!

DEF(focus_len_table,                0xffffae14) // From ixus145
