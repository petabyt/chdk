#include "stubs_asm.h"

DEF(playrec_mode,                   0x00003ac8) //blackhole sub_FF032978--> sub_FF0A1D10

DEF(file_counter_var,                   0x73c4)         //blackhole  loc_FF1C9B04

DEF(active_palette_buffer,          0x693c+0x8)     // 

DEF(palette_buffer_ptr,             0x693c+0x2C)    //blackhole sub_FF18C494 

DEF(active_viewport_buffer,         0x1D6E0)         //blackhole 0x1D6A4 @FF051F08  +  0x3C loc_FF052334  =  0x1AFE8 

DEF(viewport_buffers,               0xFF5F6628)     //blackhole 

DEF(bitmap_buffer,                  0x3FD0+0x34)    //blackhole 0x3FDO + 0x34 sub_FF0B4F1C
 
DEF(active_bitmap_buffer,           0x3FD0+0x2C)    //blackhole 0x3FD0 + 0x2C  sub_FF0B4238 

DEF(recreview_hold,                 0x9F80+0x1C)    //blackhole sub_FF261FDC

// see NRTBL.SetDarkSubType, 0xB120 + 0x4 sub_FF2B6598 blackhole 
DEF(_nrflag, 0xB124)

DEF(av_override_semaphore         ,0x0000d618) // MoveIrisWithAv




