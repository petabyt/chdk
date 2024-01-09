#include "stubs_asm.h"

DEF(playrec_mode,                   0x00003b08) //* sub_FF0A12F0

DEF(file_counter_var,               0x7234) //* loc_FF1C2B28

DEF(active_palette_buffer,          0x67AC+0x8)

DEF(palette_buffer_ptr,             0x67AC+0x2C) //*  sub_FF185974

DEF(active_viewport_buffer,         0x1c06c+0x3c) //* @sub_FF0519C0 0x1C0CC + 0x3c @loc_FF051E34 

DEF(viewport_buffers,               0xFF5D1AE8)     //*

DEF(bitmap_buffer,                  0x4010+0x34)    //* sub_FF0B4520
 
DEF(active_bitmap_buffer,           0x4010+0x2C)    //* sub_FF0B383C

DEF(recreview_hold,                 0x979C+0x1C)    //* sub_FF2490C4
 
DEF(_nrflag,                        0xA840+0x4) //* sub_ FF29A9C8






