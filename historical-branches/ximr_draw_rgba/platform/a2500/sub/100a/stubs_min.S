#include "stubs_asm.h"

//http://chdk.setepontos.com/index.php?topic=10617.msg104869#msg104869
DEF(file_counter_var,               0x0000652c) // found by searching for "FileBackupProperty.c"

DEF(palette_control,                0x0000759c) // Found @0xff98f200
DEF(palette_buffer,                 0x000c4294) // Found @0xff98f5a4 (loc_ff98f590)

DEF(active_viewport_buffer,         0x00001fd0) // sub_ff8481e0 - by comparison to ixus140
DEF(viewport_buffers,               0xffb48be0) // by comparison to ixus140

//TODO
//DEF(bitmap_buffer,0x) //
//DEF(active_bitmap_buffer,0x) //

