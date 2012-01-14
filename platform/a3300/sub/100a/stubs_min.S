#include "stubs_asm.h"

//DEF(active_palette_buffer		,0x9174)	 // FFA06C98		a3300is
//DEF(palette_buffer			,0xB4754)	 // FFA06DB0		a3300is
//DEF(palette_control			,0x916C)	 // FFA06DAC		a3300is

DEF(enabled_refresh_physical_screen	,0x3B04) //(0x3B00+0x4) @FF8A53B4 a3300is

DEF(focus_len_table				,0xFFFE2F88) // search for 70000 (longest focus length in micrometers) & 5000 (shortest length)  //a3300is

