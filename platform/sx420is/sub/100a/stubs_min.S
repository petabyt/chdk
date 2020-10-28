#include "stubs_asm.h"

DEF(playrec_mode,                   0x00003a18) //blackhole

DEF(file_counter_var,               0x7734)         //blackhole sub_FF1C42F8

DEF(active_palette_buffer,          0x6CE0+0x8)     // Found @0x: Guess!!!
DEF(palette_buffer_ptr,             0x6CE0+0x2C)    //blackhole sub_FF1874D0 


DEF(active_viewport_buffer,         0x1DDB8)         //blackhole sub_FF04EC20 0x1DD7C + 0x3C

DEF(viewport_buffers,               0xFF5E4A44)     //blackhole 

DEF(bitmap_buffer,                  0x3EF8+0x2C)    //blackhole 0x3EF8 + 0x2C  sub_FF0B0154 
DEF(active_bitmap_buffer,           0x3EF8+0x24)    // 0x3EF8 + 0x24  sub_FF0AF4DC blackhole 

DEF(recreview_hold,                 0xA1D8+0x1C)   //sub_FF25CDB4 blackhole

// see NRTBL.SetDarkSubType, 0xB464 + 0x4  sub_FF2ADB1C blackhole
DEF(_nrflag, 0xB468)

DEF(av_override_semaphore         ,0x0000d8b4) // MoveIrisWithAv


