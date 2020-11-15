#include "stubs_asm.h"
DEF(current_viewport_buffer       ,0x86e8+0x50) // fc0e0d22 refs in two functions directly after GetMovieJpegVRAMVPixelsSize in ROM, similar to sx710
DEF(viewport_buffers              ,0xfc63708c) // guess, based on similar refs in fc0dfc4c to sx710 fc0d1896, struct base 0343a4 = sx730 370d0
DEF(current_fb_d                  ,0x10248+0x28)  // from fc16728e like sx710 fc0f11a
DEF(simple_movie_status           ,0x14190+0x78) // 0x14110+0x80 +0x78 fc1872b0 similar to sx710 fc0a09e4
// carried over from sx710
FAKEDEF(video_compression_rate, 1)
FAKEDEF(canon_shoot_menu_active, 1)
DEF(zoom_status                             ,0x000dde40+0x4) // Found @ fc0a2e8e via "TerminateDeliverToZoomController" from fc0a2fb8, could also be 0xdde40+8?

// fc2fc470 via "ShtCon_StopReview", similar to g7x https://chdk.setepontos.com/index.php?topic=12692.msg130261#msg130261
DEF(recreview_hold                ,0x94ec+0x50) // "ShtCon_StopReview", fc33a53e

// based on search for 4300 100 = cc 10 00 00 64 00 00 00
// 127 entries, 2 words each, first is fl
DEF(focus_len_table                ,0xfdf3167c)

DEF(dial_positions,0x000103f0) //  SX730 fc50add6 like sx710 fc08b6f0 (ghidra)

// to hook asserts for debugging
//DEF(assert_handler,0x000082a0) // from DebugAssert, fc3a8968

// TODO sx280 C&P
//DEF(error_table                             ,0xfc512234) // Found @0xfc1abf24
//DEF(displaytype,                            0x8eb8) //0x8ea4 + 0x14, found  @ fc135f2a (GetDisplayType)

// unused
//DEF(switchstatus,0x00035798) // kbd_p1_f_cont fc589b7a
