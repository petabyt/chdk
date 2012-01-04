#include "stubs_asm.h"

DEF(physw_status, 0xD148)		//found at ROM:FFC116D8
DEF(physw_run, 0x1BE0 + 0xC)		//found at ROM:FFC1163C and ROM:FFC11658
DEF(FlashParamsTable,0xFFEEC518)	//found at ROM:FFE1DB00
DEF(zoom_busy, 0x60F4+0x14)		//found at ROM:FFD10A1C and ROM:FFD108D4
DEF(focus_busy, 0x5FF4+0x8)		//found at ROM:FFD0B9F0 and ROM:FFD0B940
DEF(canon_menu_active, 0x2E88+0x4)	//found at ROM:FFC61BBC AND ROM:FFC61834
DEF(canon_shoot_menu_active, 0x72D4+0x1)	//found at ROM:FFD4D350 and ROM:FFD4D0CC
DEF(recreview_hold, 0x6E84+0xB0)	//found at ROM:FFD3A884 and ROM:FFD3B378
DEF(zoom_status, 0xA4D4)		//found at ROM:FFE1F038  
DEF(movie_status, 0x61A0+0x38)		//ROM:FFD1399C and ROM:FFD14740
DEF(enabled_refresh_physical_screen, 0x82FC+0x20 )	//found at ROM:FFD90214 and ROM:FFD9094C
DEF(playrec_mode, 0x2BC8+0x4)		//found at ROM:FFC54598 and ROM:FFC542A0
DEF(some_flag_for_af_scan, 0x66AC )	//found at ROM:FFD16FE0

DEF(levent_table,0xFFEB9D1C)

//DEF(led_table, 0x24A8 + 0x04)		//found at ROM:FFC3600C and ROM:FFC36060
