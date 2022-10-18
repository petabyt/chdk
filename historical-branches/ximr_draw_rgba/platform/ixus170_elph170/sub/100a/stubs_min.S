#include "stubs_asm.h"

// same location as in ixus160
//DEF(focus_len_table                         ,0xffffae7c)

DEF(zoom_busy                               ,0x00007018) // Found @0xff990c98 (0x6ff8 + 0x20)
DEF(focus_busy                              ,0x00006ee0) // Found @0xff98d01c (0x6ed8 + 8)

// as in ixus160
DEF(recreview_hold, 0x000027E4)

// 0xff883bac (0x32bc), 0xff883be8 (0x54); see ixus140 0xff0a7858, 0xff0a7890
DEF(viewport_fb_d, 0x00003310)

// see NRTBL.SetDarkSubType_FW (this will likely "lag")
DEF(_nrflag, 0xa728)


DEF(viewport_buffers,               0xFFBF8510)     // blackhole
// from LiveImageTool.Jump_FW
//DEF(active_viewport_buffer, 0x2108)
DEF(active_viewport_buffer, 0x19160)   //@0xFF84EDE0 (0x19124) + @0xFF84F22C (0x3c) =0x19160

DEF(bitmap_buffer, 0x3b7c) // @0xff8a58bc (0x3b58) + 0x24 (@0xff8a652c)
DEF(active_bitmap_buffer, 0x3b74) // 0x3b58 + 0x1c (@0xff8a58c4)

DEF(active_palette_buffer, 0x7e04) // @0xff9bc8ec (0x7dfc+8); see sx170 100a @0xff9b0f70
DEF(palette_buffer_ptr, 0x7e08) // @0xff9bc914
DEF(palette_control, 0x7dfc)

DEF(file_counter_var, 0x6bd8) // found by searching for "FileBackupProperty.c"