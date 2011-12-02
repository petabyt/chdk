#include "stubs_asm.h"

// Found manually
DEF(focus_len_table, 0xFFFEA5CC)					// search for 150500 (longest focus length in micrometers) & 4300 (shortest length)
DEF(zoom_busy, 0x342c + 0x1c)						// found by trial and error in the zoom lens controller code
DEF(focus_busy,0x7A6C + 0x8)						// found by trial and error in the focus controller code
DEF(recreview_hold, 0x933C + 0xF0)					// in FF9C4900 (comp s95)

DEF(rear_dial_position, 0xC0240106)

DEF(active_bitmap_buffer, 0xB1CC)					// 0xB1B8+0x14 (1.00h sub_FFA4A814 -> FFA4A818 + FFA4A868)
DEF(bitmap_buffer, 0xB1D4)							// FFA4A864
DEF(palette_control, 0xB198)						// sub_FFA4698C (1.00h)
DEF(active_palette_buffer, 0xB1A0)					// sub_FFA468D4 (1.00h)
DEF(palette_buffer, 0xCF9B4)						// sub_FFA46DC8 (1.00h)
DEF(viewport_buffers, 0xFFB968C4)			// 1.00h sub_FF851C44 (FF851F2C)
DEF(active_viewport_buffer, 0x20A8)			// 1.00h sub_FF851C44 (FF851C48 & FF851F58)
