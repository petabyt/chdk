#include "stubs_asm.h"

DEF(playrec_mode,                   0x00003b38) //*sub_FF09FF88

DEF(file_counter_var,               0x8B4C) //*loc_FF1F1678

DEF(active_palette_buffer,          0x7154+0x8)     // Found @0x: Guess!!!
DEF(palette_buffer_ptr,             0x7154+0x2C)    //*sub_FF19AEBC


DEF(active_viewport_buffer,         0x21440)       //*0x21404 + 0x3c sub_FF04EFF4 + loc_FF04F4B0       

DEF(viewport_buffers,               0xFF693DD0)    //*

DEF(active_bitmap_buffer,           0x4018+0x28)   //*sub_FF0B40E8
DEF(bitmap_buffer,                  0x4018+0x30)   //*sub_FF0B4E64

DEF(recreview_hold,                 0xCC24+0x1C)   //*sub_FF2965C4

DEF(_nrflag, 0xDFD4) //*sub_FF2EB814


