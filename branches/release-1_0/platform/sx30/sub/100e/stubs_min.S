#include "stubs_asm.h"

DEF(rear_dial_position,                 0xC0240106)

DEF(active_bitmap_buffer,               0xB1CC)         // 0xB1B8+0x14 (1.00e sub_FFA4A758 -> FFA4A75C + FFA4A7AC)
DEF(bitmap_buffer,                      0xB1D4)         // FFA4A7A8
DEF(palette_control,                    0xB198)         // sub_FFA4698C (1.00h)
DEF(active_palette_buffer,              0xB1A0)         // sub_FFA468D4 (1.00h)
DEF(palette_buffer,                     0xCF9B4)        // sub_FFA46DC8 (1.00h)
DEF(viewport_buffers,                   0xFFB96808)     // 1.00h sub_FF851C44 (FF851F2C)
DEF(active_viewport_buffer,             0x20A8)         // 1.00h sub_FF851C44 (FF851C48 & FF851F58)
