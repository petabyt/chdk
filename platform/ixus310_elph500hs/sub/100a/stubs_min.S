#include "stubs_asm.h"

DEF(active_bitmap_buffer,               0xA45C)         // 0xA448+0x14 (1.00a sub_FF249A94 -> FF249A98 + FF249AF0)
DEF(bitmap_buffer,                      0xA464)         // FF249AEC (1.00a)
DEF(palette_control,                    0xA424)         // sub_FF244A48 (1.00a)
DEF(active_palette_buffer,              0xA42C)         // sub_FF244990 (1.00a)
DEF(palette_buffer,                     0xC7DEC)        // sub_FF244E28 (1.00a)
DEF(viewport_buffers,                   0xFF3D0418)     // 1.00a sub_FF0435C8 (FF043978)
DEF(active_viewport_buffer,             0x2104)         // 1.00a sub_FF0435C8 (FF0435CC & FF043A28)
DEF(canon_play_menu_active,             0x0000e784)
DEF(touch_screen_x,                     0x000028f0)
DEF(touch_screen_y,                     0x000028f2)
DEF(touch_screen_active,                0x000028c4)
DEF(cds_gain_value,                     0x0000abd0)
