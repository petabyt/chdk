#include "stubs_asm.h"

DEF(active_bitmap_buffer,               0xB478)  // 0xB464+0x14 (1.00c sub_FF249908 -> FF24990C + FF249964)
DEF(bitmap_buffer,                      0xB480)  // FF249960
DEF(active_palette_buffer,              0xB440)  // sub_FF24480C (1.00c)
DEF(palette_buffer,                     0xCEB38) // loc_FF244CA4 (1.00c)
DEF(zoom_status,                        0x0000f69c) 	
DEF(recreview_hold,                     0x947C + 0xF0) 
DEF(led_table,                          0x25D0 + 0x04) 
DEF(enabled_refresh_physical_screen,    0x544C + 0x14) // found at FF0ABA04
