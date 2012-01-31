#include "stubs_asm.h"

DEF(physw_status, 0x1007C) //Found for A470 (GPIOStatus)
DEF(physw_run, 0x1BF0) //Found for A470 in task_PhySw, same as A590
DEF(FlashParamsTable,  0xffe8fc64) // 101b ok
DEF(zoom_busy, 0x83a4)  // from sig finder
DEF(focus_busy, 0x82B0) // 0x82A8+0x08 found in sub_FFD02310

DEF(canon_menu_active,0x9014)		// 0x9010+4

//-

DEF(canon_shoot_menu_active,0x97e1) // from sig finder

DEF(recreview_hold, 0x5b3c) // from sig finder

DEF(movie_status, 0x51d8)  // from sig finder
DEF(some_flag_for_af_scan, 0xcd9c)  // from sig finder
DEF(zoom_status, 0xd020) // from sig finder
DEF(led_table, 0x22AC) //Found using LEDDrv.c
DEF(levent_table,0xFFE72EC4)
DEF(playrec_mode,0x5344+4) // SSAPI:MenuIn
