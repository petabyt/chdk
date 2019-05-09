#include "stubs_asm.h"
DEF(playrec_mode,                   0x00003be4)  //sub_FF0A0778 blackhole

DEF(file_counter_var,               0x8c2c)         //loc_FF1ED408 blackhole

DEF(active_palette_buffer,          0x722c+0x8)     // 
DEF(palette_buffer_ptr,             0x722c+0x2c)    //sub_FF196D94 blackhole

DEF(active_viewport_buffer,         0x21c18)         // 0x21bdc sub_FF04FD50 + 0x3c loc_FF05020C  =  0x21c18  blackhole

DEF(viewport_buffers,               0xFF63556C)     //blackhole

DEF(viewport_fb_d,                  0x378c+0x54)    //sub_FF08D1B4  ??? blackhole

DEF(bitmap_buffer,                  0x40b0+0x30)    // 0x40b0 + 0x30  sub_FF0B4F9C blackhole
DEF(active_bitmap_buffer,           0x40b0+0x20)    // 0x40b0 + 0x20  sub_FF0B41AC blackhole

DEF(recreview_hold,                 0xc5e0+0x1c)    //sub_FF289D6C blackhole

DEF(_nrflag, 0xd894)    //sub_FF2E1150 blackhole

DEF(viewport_fb_d,					0x378c+0x54)

//DEF(video_compression_rate, 0xa3e4) // sub_FF2127A0 blackhole

