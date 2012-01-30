#include "stubs_asm.h"

DEF(physw_status, 0x100BC) //Found for A470 (GPIOStatus)
DEF(physw_run, 0x1BF0) //Found for A470 in task_PhySw, same as A590
DEF(FlashParamsTable,0xffe90724)
DEF(zoom_busy, 0x83d4)
DEF(focus_busy, 0x82E0) // 0x82D8+0x08 found in sub_FFD02310

DEF(canon_menu_active,0x9064)		// 0x9060+4
DEF(canon_shoot_menu_active,0x9831)

DEF(recreview_hold, 0x5b64)

DEF(movie_status, 0x5200)  // 0x51C8 + 0x38
DEF(some_flag_for_af_scan, 0xCDEC) 
DEF(zoom_status, 0xD070)
DEF(led_table, 0x22AC) //Found using LEDDrv.c
DEF(levent_table,0xFFE73984)
DEF(playrec_mode,0x536C+4)
