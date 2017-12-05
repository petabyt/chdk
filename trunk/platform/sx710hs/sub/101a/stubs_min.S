#include "stubs_asm.h"
DEF(file_counter_var,              0x00013398) // found @fc16e6d4 by searching for "FileBackupProperty.c", similar to g7x 

// TODO g7x C&P
// first raw buffer when canon raw enabled 0x4427bfa0, possibly 0x46063fa0, more?
//DEF(raw_buffers_canon_raw         ,0xfc66e8e0) // Found @fc184334, near DevelopAddress.c assert, after GetPropertyCase similar to sx280hs
// canon raw disabled, uses 0x435ee300 0x453d6300 0x471be300
//DEF(raw_buffers_jpeg              ,0xfc66ed78) // Found based on partial image in raw enabled buffer, refs @fc184cf6, fc14c6be
//DEF(active_raw_buffer             ,0x0000be08+0xc) // Found @fc152724, similar to sx280hs 0xffffffff when uninited, seems valid range 0-2

// SX710
DEF(av_override_semaphore         ,0x00020bdc) // Found in MoveIrisWithAv, required for bracketing Created by Mecha.Create in fc54057c
DEF(canon_menu_active             ,0x0000c690+0x4) // found @fc2d1e88, via call to sub_fc2d1e82, near ref to "MviCon_ClrEvt" @fc2ff64a, just after PT_PlaySound call

// TODO g7x C&P
// via sub_fc13b3da, struct ref'd by 0x880c-0x58 near start.
// Contains viewport address that updates at ~30fps in rec mode, 0 or last rec value in pb
//DEF(current_viewport_buffer       ,0x000087f0)
//DEF(viewport_buffers              ,0xfc612b84) // from memory search, refs to fc612b74

// SX710
// originally by searching https://chdk.setepontos.com/index.php?topic=12532.msg129914#msg129914
// fc0f11a6 from "ImgDDev.c", similar to g7x
DEF(current_fb_d                  ,0x0000fd4c+0x24) 
DEF(simple_movie_status           ,0x13da4) // 0x00013cd8 + 0x80 + 0x4c found @fc0a09fe sub_fc0a09e4 via task_MovieRecord fc0a38ea. TODO verify 1 when recording or busy after, 0 otherwise
FAKEDEF(video_compression_rate, 1)
FAKEDEF(canon_shoot_menu_active, 1)
DEF(zoom_status                             ,0x0001d094+0x4) // Found @fc1f0898 via "TerminateDeliverToZoomController", unclear which offset should be used

// TODO g7x C&P
// below is 1 for both timed review and hold 0xfc33be5e "StartRecReviewTimer", goes to 0 when time expires even if button held
//DEF(recreview_hold              ,0x91D4) 
// 0xfc33aea0 "ShtCon_StopReview" originally from https://chdk.setepontos.com/index.php?topic=12692.msg130261#msg130261 
// 1 for both timed review and hold 0xfc33be5e "StartRecReviewTimer", stays 1 after time expires if shutter held
//DEF(recreview_hold                ,0x9194)
FAKEDEF(recreview_hold                ,1)

// SX710
// based on search for 4500 100
// 226 entries?, 2 words each, first is fl
DEF(focus_len_table                ,0xfdf3167c)
DEF(bitmap_buffer, 0xc62c+0x3c) // struct starts @ 0xc62c, from sub @0xfc309cd4 after "VTM SW", +0x3c @fc309d6e
DEF(dial_positions,0x0000fe84) // from sub_fc08b6f6, Jogdial at 0x0000fe84 0x0000fe88

// TODO g7x C&P
// to hook asserts for debugging
//DEF(assert_handler,0x00008434) // from DebugAssert, 0x010e5cb8 in RAM code

// TODO sx280 C&P
//DEF(led_table,)
//DEF(error_table                             ,0xfc512234) // Found @0xfc1abf24
// DEF(jog_hw_pos,                             0xd9854004) // found by browsing the 0xd985xxxx range...
//FAKEDEF(enabled_refresh_physical_screen,    1)
//DEF(displaytype,                            0x8eb8) //0x8ea4 + 0x14, found  @ fc135f2a (GetDisplayType)
