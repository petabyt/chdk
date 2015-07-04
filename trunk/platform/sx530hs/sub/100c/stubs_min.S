#include "stubs_asm.h"

DEF(file_counter_var,               0x00008c0c) // found by searching for "FileBackupProperty.c"

//DEF(palette_control,                0x00009a50) // Found @0xff1f6ae4 Some instructions before loading Palette colour tables value 
//DEF(active_palette_buffer,          0x00009a58) // Found @0xff1f6c6c
//DEF(palette_buffer_ptr,             0x00009a5c) // Found @0xff1f6c94 or 0xff1f71a0 : Guess palette_control+0xC
//DEF(palette_buffer,                 0x000ea930) // Found @0xff1f719c check this!!

DEF(active_viewport_buffer,         0x00002174) // 0xff04fe74 - by comparison to sx510hs
DEF(viewport_buffers,               0xff63dfe8) // by comparison to sx510hs

//DEF(viewport_fb_d,                  0x00003438) // Found @0xff067204 (0x33e4) + @0xff067240 (0x54) 
DEF(viewport_fb_d,                  0x000036ac) // Found @0xff067204 (0x3658) + @0xff08c634 (0x54) 

//DEF(bitmap_buffer,                  0x0000413c) //  @0xff08e1c4 - by comparison to ixus140
//DEF(active_bitmap_buffer,           0x00004138) //  @0xff08e1c8 - by comparison to ixus140

DEF(recreview_hold,                 0x00002a2c+0x84) //@0xff06aa9c + 0x84 (offset used by A2500)

//TODO
//DEF(rear_dial_position,        0xC0240106)  //To do
