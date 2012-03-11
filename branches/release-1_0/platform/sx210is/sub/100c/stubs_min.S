#include "stubs_asm.h"

DEF(physw_status, 0x336C4)                 // found at FF834360  -> ASM1989 08.20.2010
DEF(physw_run, 0x1C24 + 0x0C)             // found at FF8342C4  and FF8342E0 -> ASM1989 08.20.2010
DEF(focus_busy, 0x6FC0 + 8)               // found at FF9639D4 -> ASM1989 08.20.2010  -> 09.19.10  looks like 8 at FF963A30 , same as sx20 FF94FED4
DEF(zoom_busy, 0x7124 + 0x1C)             // found at FF969464 -> ASM1989 08.20.2010     ?doubt? 0x14 or 0x1C  ### pixeldoc: ROM:FF9693D0 0x7124 + 0x1C ### and FF96A0BC like in sx20
DEF(canon_menu_active, 0x3688 + 4)        // StarRecModeMenu @FF891C4C -> ASM1989 08.21.2010 ?guesswork found at FF891B4C  -> ASM1989 08.21.2010 ?guesswork, and FF892194 like in sx20
DEF(canon_shoot_menu_active, 0x8510 + 1)  // sub_FF9B57E4 -> ASM1989 08.21.2010 ?guesswork  why +1 ??   -> OK 09.19.10 FF9B59B0  Like in sx20
DEF(recreview_hold, 0x804C + 0xF8)        //  ASM1989 08.30.2010 looks like FF9A0B38 0x804C  but not sure about 0x0C -> Not Ok 09.19.10 FF9A1684 like in sx20  was F8
DEF(zoom_status, 0xD524)                 // ASM1989  09.19.10 -> FFAD4E40  Like in sx20 at FFAAF3EC search for "TerminateDeliverToZoomController"
DEF(movie_status, 0x71D0 + 0x3C)          //  ASM1989  09.19.10 -> FF96DAE0  Like in sx20 at FF878924 its a call from  task_MovieRecord
DEF(playrec_mode, 0x33B8+0x4)              // found at FF884178 -> ASM1989 08.21.2010 ?guesswork  why +0x4 ???  ### pixeldoc: answer -> ROM:FF883E58 0x33B8 + 0x4 ###  and FF883E64
DEF(levent_table,0xFFBC1084)               // found at FF99A820  -> ASM1989 08.21.2010 ?guesswork please confirm it   ### pixeldoc: OK ### and FF99A818
DEF(full_screen_refresh, 0x9D08)	// found in FFA1CF40  in sx20: FFA02598, based on work found in the sd980 port
DEF(enabled_refresh_physical_screen, 0x9D48+0x20) //found at FFA1EE18 and FFA1EFB4 and FFA1EE5C -> ASM1989 08.21.2010 ?guesswork, FFA1EDDC  ->0x20  , but maybe 24???
DEF(FlashParamsTable,0xFFC095BC)          // found at FFAD195C -> ASM1989 08.20.2010, double checked
DEF(some_flag_for_af_scan, 0x75D8)	       //found at FF971750  & FF970D5C -> ASM1989 08.21.2010 double checked
DEF(led_table, 0x24A0 + 0x04)              // found at FF860EF0 & FF860EEC  -> ASM1989 08.21.2010 double checked




//DEF(movie_status, 0xA470 + 8)          // (Wrong data from SX200 = found at found at FFC4C12 (bad address)) SX210 Pending ??? ### pixeldoc: maybe ROM:FFA4E2B4 0xA470 + 8 ###
//DEF(zoom_status, 0x7124 + 0x1C)                  // (Wrong data from SX200 = found at FFA77128 ) SX210 Pending ??? ### pixeldoc: maybe ROM:FF9693D0 0x7124 + 0x1C ###


