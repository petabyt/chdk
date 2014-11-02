#include "stubs_asm.h"

DEF(led_table, 0x11258) //OK
DEF(physw_run, 0x1FBC) //OK
DEF(physw_status, 0x10FF0) //OK
DEF(canon_menu_active,0x8B5C) //OK

//should be ok
DEF(zoom_busy, 0x6E230)
DEF(zoom_status, 0x7124)
        
//a bit unsure but might be ok
DEF(focus_busy, 0x6E488) 
//DEF(movie_status, 0x67108)

//DEF(FlashParamsTable,0xFF958138) // dk


//Not tested:
DEF(canon_menu_active,  0x00008b5c)     //Found in sub_ff9ed320
DEF(canon_shoot_menu_active,0x7ef4+1)   //Found in sub_ff99d8d8
DEF(recreview_hold,     0x00086400)     //Found in sub_ff990b58
DEF(some_f_for_dng,     0x000099d4)     //Found in sub_ffa2bce8 by comparison to ixusw_sd430 110a
DEF(second_ext_for_dng, 0x000099f8)     //some_f_for_dng + 0x24?
DEF(movie_status,       0x0007c970)     //Found @ 0xff941abc by comparison to ixusw_sd430 110a


DEF(playrec_mode, 0x6DA0) // "MenuIn"

DEF(sys_mempart_id, 0xea18)
