#include "stubs_asm.h"

// Found manually
DEF(focus_len_table, 0xFFF4A7B4)			// Search for min & max zoom
DEF(zoom_busy, 0x2E10 + 0x1C)				// 1.00g sub_FF071C6C (FF071C70 & FF071CA8)
DEF(focus_busy,0x8D00 + 0x8)				// 1.00g sub_FF1BBCF0 (FF1BBCF4 & FF1BBD10)
DEF(recreview_hold, 0x40FC + 0xF0)			// 1.00g sub_FF0A2F98 (FF0A2F9C & FF0A2FB4)
DEF(active_bitmap_buffer, 0xC300+0x14)		// 1.00g sub_FF295414 (FF295418 & FF295470)
DEF(bitmap_buffer, 0xC31C)					// 1.00g sub_FF295414 (FF29546C)
DEF(palette_control, 0xC2D8)				// 1.00g sub_FF29175C
DEF(active_palette_buffer, 0xC2E0)			// 1.00g sub_FF29175C
DEF(palette_buffer, 0xDF7F0)				// 1.00g sub_FF291BE4 (FF291C28)
DEF(viewport_buffers, 0xFF43457C)			// 1.00g sub_FF045D2C (FF0460F0)
DEF(active_viewport_buffer, 0x215C)			// 1.00g sub_FF045D2C (FF045D30 & FF04611C)

DEF(rear_dial_position, 0xC0240106)
