#include "stubs_asm.h"

// Found manually
DEF(focus_len_table, 0xFFFEA5CC)					// ok (comp 1.00h)
DEF(zoom_busy, 0x342c + 0x1c)						// ok (comp 1.00h)
DEF(focus_busy,0x7A6C + 0x8)						// ok (comp 1.00h)
DEF(recreview_hold, 0x933C + 0xF0)					// ok (comp 1.00h)

DEF(rear_dial_position, 0xC0240106)

DEF(active_bitmap_buffer, 0xB1CC)					// 0xB1B8+0x14 (1.00l sub_FFA4A9BC -> FFA4A9C0 + FFA4AA10)
DEF(bitmap_buffer, 0xB1D4)							// FFA4AA0C
DEF(palette_control, 0xB198)						// sub_FFA4698C (1.00h)
DEF(active_palette_buffer, 0xB1A0)					// sub_FFA468D4 (1.00h)
DEF(palette_buffer, 0xCF9B4)						// sub_FFA46DC8 (1.00h)
DEF(viewport_buffers, 0xFFB96A6C)			// 1.00h sub_FF851C44 (FF851F2C)
DEF(active_viewport_buffer, 0x20A8)			// 1.00h sub_FF851C44 (FF851C48 & FF851F58)
