#include "stubs_asm.h"

// Found manually

DEF(rear_dial_position, 0xC0240106)
DEF(front_dial_position, 0xC0240306)

// bitmap_buffer & acive_bitmap_buffer (1.00c)
//	0xa610 = 0 or 1, used as index into 0xa618
//	0xa618 = 0x40471000
//	0xa61c = 0x404b0480 = 0x40471000 + bitmap size
DEF(active_bitmap_buffer, 0xA610)					// 0xA5FC+0x14 (1.00c sub_FFA57B64 -> FFA57B68 + FFA57BB8)
DEF(bitmap_buffer, 0xA618)							// FFA57BB4
DEF(palette_control, 0xA5DC)						// sub_FFA53CDC (1.00c)
DEF(active_palette_buffer, 0xA5E4)					// sub_FFA53C24 (1.00c)
DEF(palette_buffer, 0xBBF5C)						// sub_FFA54118 (1.00c)
DEF(viewport_buffers, 0xFFBB822C)			// 1.00c sub_FF852148 (FF85243C)
DEF(active_viewport_buffer, 0x20AC)			// 1.00c sub_FF852148 (FF85214C & FF852468)
