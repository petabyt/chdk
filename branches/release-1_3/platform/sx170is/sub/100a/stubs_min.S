#include "stubs_asm.h"

//http://chdk.setepontos.com/index.php?topic=10617.msg104869#msg104869
DEF(file_counter_var,               0x00006de8) // ?? found by searching for "FileBackupProperty.c"

DEF(palette_control,                0x00007cd8) // Found @0xff9b0df4 Some instructions before loading Palette colour tables value 
DEF(active_palette_buffer,          0x00007ce0) // Found @0xff9b0f50
DEF(palette_buffer_ptr,             0x00007ce4) // Found @0xff9b1370 : Guess palette_control+0xC
DEF(palette_buffer,                 0x000c67f4) // Found @0xff9b1374

DEF(active_viewport_buffer,         0x00002164) // sub_ff83cf5c - by comparison to ixus140
DEF(viewport_buffers,               0xffbac5c8) // by comparison to ixus140 !! Check this!!!

DEF(viewport_fb_d,                  0x000034D4) // ??? Found @0xff8701b4 (0x3380) + @0xff8701f0 (0x54) 

DEF(bitmap_buffer,                  0x00003ee8) // Found @0xff892df8 (0x3ec0) + @0x (0x28) - by comparison to ixus140
DEF(active_bitmap_buffer,           0x00003ee4) // Found @0xff892df8 (0x3ec0) + @0x (0x24) - by comparison to ixus140

DEF(recreview_hold,                 0x00002894+0x84) // @0xff8507bc +0x84 (offset used by A2500)

//TODO
DEF(rear_dial_position,             0xC0240106)  //To do
