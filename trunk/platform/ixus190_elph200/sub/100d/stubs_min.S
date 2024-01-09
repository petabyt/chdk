#include "stubs_asm.h"

DEF(playrec_mode,                   0x00003b08) //* sub_FF0A12F0

DEF(file_counter_var,               0x7208) //* loc_FF1C2A84

DEF(active_palette_buffer,          0x6780+0x8)

DEF(palette_buffer_ptr,             0x6780+0x2C) //*  sub_FF1858D0

DEF(active_viewport_buffer,         0x1c06c+0x3c) //* @sub_FF0519C0 0x1C06C + 0x3c @loc_FF051E34 

DEF(viewport_buffers,               0xFF5B93E0)     //* 

DEF(bitmap_buffer,                  0x4010+0x34)    //* sub_FF0B4520
 
DEF(active_bitmap_buffer,           0x4010+0x2C)    //* sub_FF0B383C

DEF(recreview_hold,                 0x976C+0x1C)    //* sub_FF249020
 
DEF(_nrflag,                        0xA7E0+0x4) //* sub_FF29A684 






