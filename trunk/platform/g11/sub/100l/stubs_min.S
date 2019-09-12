#include "stubs_asm.h"

DEF(recreview_hold,                     0x7D00 + 0xD8) 
DEF(enabled_refresh_physical_screen,    0x9840)         //G11 at FFA0ECB8
DEF(led_table,                          0x25B4 + 0x04)  // G11 @FF85F278
DEF(active_viewport_buffer,0x20D8) // sub_FF84F820
DEF(viewport_buffers,0x2288) // sub_FF84F820 @FF84FA28

