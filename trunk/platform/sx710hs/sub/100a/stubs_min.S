#include "stubs_asm.h"
// below found by sig finder now
//DEF(file_counter_var,              0x00013398) // found @fc16e6d4 by searching for "FileBackupProperty.c", similar to g7x 
//DEF(av_override_semaphore         ,0x00020bdc) // Found in MoveIrisWithAv, required for bracketing Created by Mecha.Create in fc540574
//DEF(canon_menu_active             ,0x0000c690+0x4) // found @fc2d1e80, via call to sub_fc2d1e7a, near ref to "MviCon_ClrEvt" @fc2ff642, just after PT_PlaySound call

// via fc0d1ce4 (similar g7x fc13b3da), 101a by searching mem near 0x86de for known vp buffer 0x42cafe00
// Contains viewport address that updates at ~30fps in rec mode, 0 or last rec value in pb
DEF(current_viewport_buffer       ,0x00008794)
DEF(viewport_buffers              ,0xfc5befd0) // in dump near 101a address (original 0xfc500000-0xfc800000 for values seen in current_*)

// originally by searching https://chdk.setepontos.com/index.php?topic=12532.msg129914#msg129914
// fc0f11a6 from "ImgDDev.c", similar to g7x
DEF(current_fb_d                  ,0x0000fd4c+0x24) 
DEF(simple_movie_status           ,0x13da4) // 0x00013cd8 + 0x80 + 0x4c found @fc0a09fe sub_fc0a09e4 via task_MovieRecord fc0a38ea
FAKEDEF(video_compression_rate, 1)
FAKEDEF(canon_shoot_menu_active, 1)
DEF(zoom_status                             ,0x0001d094+0x4) // Found @fc1f0890 via "TerminateDeliverToZoomController", unclear which offset should be used

// fc2fc490 via "ShtCon_StopReview", similar to g7x https://chdk.setepontos.com/index.php?topic=12692.msg130261#msg130261
DEF(recreview_hold                ,0x9090+0x50)

// based on search for 4500 100
// 112 entries, 2 words each, first is fl
//DEF(focus_len_table                ,0xfdf3167c)
//DEF(bitmap_buffer, 0xc62c+0x3c) // struct starts @ 0xc62c, from sub @0xfc309ccc after "VTM SW", +0x3c @fc309d66
DEF(dial_positions,0x0000fe84) // from sub_fc08b6f6, Jogdial at 0x0000fe84 0x0000fe88

// to hook asserts for debugging
//DEF(assert_handler,0x00008418) // from DebugAssert, 0x010e100 in RAM code

// TODO sx280 C&P
//DEF(error_table                             ,0xfc512234) // Found @0xfc1abf24
//DEF(displaytype,                            0x8eb8) //0x8ea4 + 0x14, found  @ fc135f2a (GetDisplayType)
