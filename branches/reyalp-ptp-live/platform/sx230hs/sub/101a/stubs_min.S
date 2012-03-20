#include "stubs_asm.h"

DEF(active_bitmap_buffer,               0xB478)  // 0xB464+0x14 (1.01a sub_FF249A8C -> FF249A90 + FF249AE8)
DEF(bitmap_buffer,                      0xB480)  // FF249AE4
DEF(active_palette_buffer,              0xB440)  // sub_FF244988 (1.01a)
DEF(palette_buffer,                     0xCEB38) // loc_FF244E20 (1.01a)
DEF(zoom_status, 			            0xF69C)         // found at FF326964
DEF(recreview_hold, 		            0x947C + 0xF0)  // found at FF1BC74C + FF1BC754  
DEF(led_table, 				            0x25D0 + 0x04)  // found at FF056A3C
DEF(enabled_refresh_physical_screen,	0x544C + 0x14)  // found at FF0ABA04
