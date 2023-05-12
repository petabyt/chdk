#include "stubs_asm.h"

DEF(playrec_mode,                   0x00003a44) //*sub_FF09C988

DEF(file_counter_var,               0x7604) //*loc_FF1BF918

DEF(active_palette_buffer,          0x7154+0x8)     // Found @0x: Guess!!!
DEF(palette_buffer_ptr,             0x6b40+0x2C)    //*sub_FF180ADC


DEF(active_viewport_buffer,         0x1c250)       //*0x1c214 + 0x3c sub_FF04E1A0 + loc_FF04E614       

DEF(viewport_buffers,               0xFF5AD4DC)    //*

DEF(active_bitmap_buffer,           0x3f28+0x24)   //*sub_FF0AEA4C
DEF(bitmap_buffer,                  0x3f28+0x2c)   //*sub_FF0AF6C4

DEF(recreview_hold,                 0x9aa4+0x1c)   //*sub_FF2464B4

DEF(_nrflag, 0xabd0) //*sub_FF292944


