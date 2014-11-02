#include "stubs_asm.h"

//TODO: this is a copy of ixus140.  All entries have to be checked

//http://chdk.setepontos.com/index.php?topic=10617.msg104869#msg104869
DEF(file_counter_var,               0x00007570) // Found @0xff1d32c0 found by searching for "FileBackupProperty.c"


DEF(palette_control,                0x000087a0) // Found @0xff20efe0 Some instructions before loading Palette colour tables value

DEF(bitmap_buffer,                  0x3f80) // TODO:
DEF(active_bitmap_buffer,           0x3f78) // TODO:

DEF(active_viewport_buffer,         0x0000258c)   // sub_FF073A04 ixus132.100b
DEF(viewport_buffers,               0xff4fab98)   // TODO: Check this

//DEF(viewport_buffers,               0xff1351c4) // TODO: Check this Error???
