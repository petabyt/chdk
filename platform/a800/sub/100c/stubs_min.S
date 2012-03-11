#include "stubs_asm.h"

DEF(physw_status, 0x2f048)							// DEF(physw_status                            ,0x0002f048) // Found @0xffc23c3c, ** != ** stubs_min = 0x0002e7f4 (0x2E7F4)ok, Search "GpioStatus "<===
DEF(physw_run, 0x1BF8)								// ROM:FFC237FC (FFC2378C)
DEF(FlashParamsTable,0xffeea13c)					// ROM:ffe267d4 (FFE0AA80)
DEF(zoom_busy, 0x55f8 + 0x14)						// ROM:ffd15018:(000055f8) próximo a "ZoomLens":  ROM:ffd09bbc:(0x00005410) (Obs o+ xx está na instrução para acesso ao valor
DEF(focus_busy, 0x5514 + 8)							// ROM:ffd12678:(00005514) acho similaridades entre labels "FocusLensController.c": e "FocusLens": ROM:ffd070f4:(0000532c)
DEF(canon_menu_active, 0x2A94 + 4)					// ROM: ffc6c44c acho(código parecido e referência próxima a label Module.c Ok ROM:FFC6A11C
DEF(canon_shoot_menu_active, 0x000068a8+1)			// em stub_entry.S Found @0xffd4c494 INDICA 68a8   ?? Found on ROM:FFC77758 taskcreate_DSITask<===
DEF(recreview_hold, 0x30d4)							// em stub_entry.S 30D4 <-> ROM: ffd3fee4 acho(similar próximo a "_ExecuteStopContiShooting") ROM:FFD34410 (0x6308)
DEF(zoom_status, 0x0000a050)					    //ROM: ffe298f0: (0000a050) acho (similaridades e próximo ao label "TerminateDeliverToZoomController" ROM:ffe0d644 (0x00009648)
DEF(movie_status, 0x56b8)							// retirado de stub_min.S Unknown <=== 
DEF(enabled_refresh_physical_screen, 0x360c)		// ROM:ffc814ec(0000360c) acho (similaridade próximo a *"ScreenLock")  ROM:FFD7C7B4(000073ac)
DEF(playrec_mode, 0x27E0+0x4)						// ROM:ffc5d8f4 ->ffc5fc5c:(000027e0) ROM:FFC27ACC "MenuIn" ROM:FFC5D8F4 -> ffc5dbec:(00002794)
DEF(levent_table, 0xffeba314)						// ROM:ffd36634:->ffd3663c: (ffeba314) acima de *"UiEvnt.c" ROM: ffd2ab4c:->ffd2ab54: (ffea2d14)Ok
DEF(some_flag_for_af_scan, 0x5a70)					// já em 495 (Correct?) ROM:ffd1b9e4:->ffd1b538: (00005a70) abaixo de último **"SsPrepareSeqBase.c" Correct? ROM:FFD0F9DC->ffd0f504: (00005848)
DEF(full_screen_refresh, 0x7810)					// ROM:ffd88dc4:(00007810) analogia por número de referências e valores de campos no entorno (proximidade "remota" com *"Not found icon resource.")ROM:FFD7A9FC->ffd7abf8:(00007370) called by RefreshPhysicalScreen()
