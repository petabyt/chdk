#include "stubs_asm.h"

//DEF(physw_status, 0xFB20)
DEF(physw_status, 0x11210)
DEF(led_table, 0x11458)

DEF(zoom_busy, 0x800e8)
DEF(focus_busy, 0x80404)
DEF(canon_menu_active,0x8DD4)
DEF(canon_shoot_menu_active,0x810d)
DEF(recreview_hold, 0x7D2E8)

DEF(zoom_status, 0x7FBC)
DEF(movie_status, 0x7386C)


DEF(physw_run, 0x1FCC)
DEF(playrec_mode,0x6FE8) // "MenuIn"
DEF(sys_mempart_id, 0xec50)

DEF(some_f_for_dng,     0x00009c30)     //Found in sub_ffa2f554 by comparison to ixusw 110a
DEF(second_ext_for_dng, 0x00009c54)     //some_f_for_dng + 0x24?
