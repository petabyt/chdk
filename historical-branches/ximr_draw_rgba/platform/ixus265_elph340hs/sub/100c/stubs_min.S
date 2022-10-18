#include "stubs_asm.h"
DEF(playrec_mode,                   0x00003794)  //* sub_FF09A658

DEF(file_counter_var,               0x8404)         //* loc_FF1E59CC

DEF(active_palette_buffer,          0x6B2C+0x8)     // 
DEF(palette_buffer_ptr,             0x6B2C+0x2C)    //* sub_FF18F10C

DEF(active_viewport_buffer,         0x21898)         //* 0x2185C @FF05045C  +  0x3C @FF0508F0  =  0x21898  

DEF(viewport_buffers,               0xFF5F7904)     //* 

DEF(active_bitmap_buffer,           0x3C58+0x20)    //* 0x3C58 + 0x20  sub_FF0AE038 
DEF(bitmap_buffer,                  0x3C58+0x28)    //* 0x3C58 + 0x28  sub_FF0AEE28 

DEF(recreview_hold,                 0xBDD0+0x18)    //* sub_FF27D49C

DEF(_nrflag, 0xDFC4) //* 0xDFC0 + 0x4 sub_FF2EA464  


