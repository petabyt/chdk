#include "stubs_asm.h"

DEF(physw_status, 0x54238)
DEF(physw_run, 0x7D20)

DEF(zoom_busy, 0x7DC54)
DEF(focus_busy, 0x7D3B8)  //  maybe wrong, it can be tested later
DEF(playrec_mode, 0xC2C0)
DEF(FlashParamsTable,0xFFED3430)
DEF(canon_menu_active,0x2EDC)
DEF(canon_shoot_menu_active,0x2795)
DEF(recreview_hold, 0x2598)
DEF(movie_status, 0xA2780)  
DEF(some_flag_for_af_scan, 0xBFA8)
DEF(zoom_status, 0x2660)
DEF(some_f_for_dng, 0x665C) 
DEF(second_ext_for_dng, 0x6680) // ".THM"
DEF(levent_table,0xFFEC4568)
DEF(sys_mempart_id, 0x4998) // calloc
