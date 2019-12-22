#include "stubs_asm.h"
DEF(current_viewport_buffer       ,0x86e8+0x50) // refs in two functions directly after GetMovieJpegVRAMVPixelsSize in ROM, similar to sx710
DEF(viewport_buffers              ,0xfc637064) // 100d fc0dffbe == 100c fc0dff96, 
DEF(current_fb_d                  ,0x10248+0x28)  // 100d fc16728e == 100c fc167266
DEF(simple_movie_status           ,0x14190+0x78) // 100d fc1872b0  == 100c fc187288
// carried over from sx710
FAKEDEF(video_compression_rate, 1)
FAKEDEF(canon_shoot_menu_active, 1)
DEF(zoom_status                             ,0x000dde40+0x4) // via "TerminateDeliverToZoomController", 100d fc0a2e8e == 100c fc0a2e66

// via "ShtCon_StopReview", similar to g7x https://chdk.setepontos.com/index.php?topic=12692.msg130261#msg130261
DEF(recreview_hold                ,0x94ec+0x50) // "ShtCon_StopReview", 100d fc33a53e == 100c fc33a516

// based on search for 4300 100 = cc 10 00 00 64 00 00 00
// 127 entries, 2 words each, first is fl
DEF(focus_len_table                ,0xfdf3167c)

DEF(dial_positions,0x000103f0) //  100d fc50add6 ==  100c fc50adae

// to hook asserts for debugging
//DEF(assert_handler,0x000082a0) // from DebugAssert, fc3a8938

// TODO sx280 C&P
//DEF(error_table                             ,0xfc512234) // Found @0xfc1abf24
//DEF(displaytype,                            0x8eb8) //0x8ea4 + 0x14, found  @ fc135f2a (GetDisplayType)

