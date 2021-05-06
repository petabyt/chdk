#include "stubs_asm.h"
DEF(playrec_mode,                   0x00003cc0)  //* sub_FF0A3F94 

DEF(file_counter_var,               0x8cec)         //* loc_FF1F6184

DEF(active_palette_buffer,          0x72d8+0x8)     // 
DEF(palette_buffer_ptr,             0x72d8+0x2c)    //* sub_FF19F498

DEF(active_viewport_buffer,         0x21658)         //* 0x2161c sub_FF04EFEC + 0x3c loc_FF04F4A8  =  0x21658

DEF(viewport_buffers,               0xFF69A220)     //*

DEF(bitmap_buffer,                  0x41a0+0x30)    //* 0x41a0 + 0x30  sub_FF0B8E50
DEF(active_bitmap_buffer,           0x41a0+0x28)    //* 0x41a0 + 0x28  sub_FF0B80D4

DEF(recreview_hold,                 0xce20+0x1c)    //* sub_FF29BD80

DEF(_nrflag,                        0xe1e4)    //* sub_FF2F18DC





