#include "stubs_asm.h"
DEF(playrec_mode,                   0x00003794)  //* sub_FF09AB00

DEF(file_counter_var,               0x8410)         //* loc_FF1E620C

DEF(active_palette_buffer,          0x6B38+0x8)     //
DEF(palette_buffer_ptr,             0x6B38+0x2C)    //* sub_FF18FA58

DEF(active_viewport_buffer,         0x218F0)         //* 0x218B4 @FF050518  +  0x3C @FF0509AC  =  0x218F0

DEF(viewport_buffers,               0xFF5F927C)     //*

DEF(active_bitmap_buffer,           0x3C58+0x20)    //* 0x3C58 + 0x20  sub_FF0AE4E4
DEF(bitmap_buffer,                  0x3C58+0x28)    //* 0x3C58 + 0x28  sub_FF0AF2D4

DEF(recreview_hold,                 0xBDE8+0x18)    //* sub_FF27DFC0

DEF(_nrflag, 0xDFEC) //* 0xDFE8 + 0x4 sub_FF2EB634


