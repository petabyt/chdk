#include "stubs_asm.h"

// Found manually

DEF(rear_dial_position, 0xC0240106)
DEF(front_dial_position, 0xC0240306)

DEF(active_bitmap_buffer, 0xA610)					// 0xA5FC+0x14 (1.00f sub_FFA57B70 -> FFA57B74 + FFA57BC4)
DEF(bitmap_buffer, 0xA618)							// FFA57BC0
DEF(palette_control, 0xA5DC)						// sub_FFA53CDC (1.00c)
DEF(active_palette_buffer, 0xA5E4)					// sub_FFA53C24 (1.00c)
DEF(palette_buffer, 0xBBF5C)						// sub_FFA54118 (1.00c)
DEF(viewport_buffers, 0xFFBB83CC)			// 1.00c sub_FF852148 (FF85243C)
DEF(active_viewport_buffer, 0x20AC)			// 1.00c sub_FF852148 (FF85214C & FF852468)
