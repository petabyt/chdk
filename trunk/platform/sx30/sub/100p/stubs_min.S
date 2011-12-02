#include "stubs_asm.h"

// Found manually
DEF(focus_len_table, 0xFFFEA5CC)
DEF(zoom_busy, 0x342c + 0x1c)
DEF(focus_busy,0x7A6C + 0x8)
DEF(recreview_hold, 0x933C + 0xF0)

DEF(rear_dial_position, 0xC0240106)

DEF(active_bitmap_buffer, 0xB1CC)					// 0xB1B8+0x14 (1.00p sub_FFA4AA40 -> FFA4AA44 + FFA4AA94)
DEF(bitmap_buffer, 0xB1D4)							// FFA4AA90
DEF(palette_control, 0xB198)						// sub_FFA4698C (1.00h)
DEF(active_palette_buffer, 0xB1A0)					// sub_FFA468D4 (1.00h)
DEF(palette_buffer, 0xCF9B4)						// sub_FFA46DC8 (1.00h)
DEF(viewport_buffers, 0xFFB96AC0)			// 1.00h sub_FF851C44 (FF851F2C)
DEF(active_viewport_buffer, 0x20A8)			// 1.00h sub_FF851C44 (FF851C48 & FF851F58)
