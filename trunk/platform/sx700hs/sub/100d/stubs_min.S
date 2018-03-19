#include "stubs_asm.h"
// based on 100e, RAM addresses assumed unchanged based on sigfinder

// **** Found ***

DEF(file_counter_var,              0x00013128) // sx700v100e found @fc1a82b8 by searching for "FileBackupProperty.c", similar to G7X 

DEF(av_override_semaphore         ,0x00022784) // sx700v100e found in MoveIrisWithAv, required for bracketing Created by Mecha.Create in fc40cb82

DEF(canon_menu_active             ,0x0000c7b0+0x4) // sx700v100e found @fc3d64c0, via call to sub_fc3d64be, near ref to "MviCon_ClrEvt" @fc2f186e, just after PT_PlaySound call

// originally by searching https://chdk.setepontos.com/index.php?topic=12532.msg129914#msg129914
// fc19194a from "ImgDDev.c", similar to g7x
DEF(current_fb_d                  ,0x0000fb58+0x24) // sx700v100e found 

DEF(simple_movie_status           ,0x13ac8) // sx700v100e found 0x00013a20 + 0x80 + 0x28 @fc1b1e62 sub_fc1b1e48 via task_MovieRecord 0xfc1b40e3

DEF(zoom_status                             ,0x0001ec38) // sx700v100e found 0x0001ec58 - 0x20  @fc343122 via "TerminateDeliverToZoomController", unclear which offset should be used

// fc2fc470 via "ShtCon_StopReview", similar to g7x https://chdk.setepontos.com/index.php?topic=12692.msg130261#msg130261
// ftm: @fc3037a6 used the sx280 method near ShootCon_NotifyStartReviewHold
DEF(recreview_hold                ,0x8ebc) // sx700v100e found 0x8df0 + 0x80 + 0x4c

// based on search for 4500 100
// 112 entries, 2 words each, first is fl
DEF(focus_len_table                ,0xfdf2ce94)

DEF(bitmap_buffer, 0xc754+0x34) // sx700v100e found struct starts @ 0xc754, from sub @0xfc30ccdc after "VTM SW", +0x34 @fc30cd74

// Camera has 2 RAW buffers @ ?? & ??
DEF(raw_buffers                             ,0xfc5d93dc) // sx700v100d found @fc160f0e

DEF(active_raw_buffer                       ,0x0000baf4) // sx700v100e found  @0xfc12fe98, 0xffffffff when uninited (0xC offset added similar to sx280)

// Contains viewport address that updates at ~30fps in rec mode, 0 or last rec value in pb
DEF(current_viewport_buffer       ,0x00008788+0x38) // sx700v100e found @0xfc12008c -- 0x00008788 + 0x38 (Same as G16 search GetMovieJpegVRAMVPixelsSize_FW)

// from 100e, should contain: 0x43312300 0x433c0b00 0x4346f300 0x4351db00
DEF(viewport_buffers              ,0xfc568dA8) // sx700v100d found @0xfc11f448 0xfc568d90 + 0x10 + 0x8 similar to 100e

DEF(dial_positions                ,0x0000fcf0)

// Search for ActionStopRecordMovie, then go till next branchtable
DEF(displaytype,                              0x8f98) // sx700v100e Similar to sx280 0x8f54 + 0x44 found @0xfc120a38  (GetDisplayType)

// *** Not Found *** 

FAKEDEF(video_compression_rate, 1)

FAKEDEF(canon_shoot_menu_active, 1)


// *** Probably Not Needed ***

// to hook asserts for debugging
//DEF(assert_handler,0x00008418) // from DebugAssert, 0x010e100 in RAM code

// TODO sx280 C&P
//DEF(error_table                             ,0xfc512234) // Found @0xfc1abf24

// Camera does not have canon_raw? No DevelopPipeline.c in sx700v100e

//DEF(raw_buffers_canon_raw                   ,0xfc631864) //xfound near DevelopAddress.c
//DEF(raw_buffers_jpeg                         ,0xfc631bf4) //xfound near DevelopPipeline.c 0xfc631c00
