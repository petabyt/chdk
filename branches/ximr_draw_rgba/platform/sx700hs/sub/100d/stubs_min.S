#include "stubs_asm.h"
// RAM addresses assumed unchanged from 100e based on sigfinder, refer to 100e port for comments

DEF(file_counter_var,              0x00013128)

DEF(av_override_semaphore         ,0x00022784)

DEF(canon_menu_active             ,0x0000c7b0+0x4)

DEF(current_fb_d                  ,0x0000fb58+0x24)

DEF(simple_movie_status           ,0x13ac8)

DEF(zoom_status                   ,0x0001ec38)

DEF(recreview_hold                ,0x8ebc)

// based on search for 4500 100
// 112 entries, 2 words each, first is fl
DEF(focus_len_table                ,0xfdf2ce94)

DEF(bitmap_buffer, 0xc754+0x34)

// Camera has 2 RAW buffers @ ?? & ??
DEF(raw_buffers                             ,0xfc5d93dc) // sx700v100d found @fc160f0e

DEF(active_raw_buffer                       ,0x0000baf4)

DEF(current_viewport_buffer       ,0x00008788+0x38)

// from 100e, should contain: 0x43312300 0x433c0b00 0x4346f300 0x4351db00
DEF(viewport_buffers              ,0xfc568dA8) // sx700v100d found @0xfc11f448 0xfc568d90 + 0x10 + 0x8 similar to 100e

DEF(dial_positions                ,0x0000fcf0)

DEF(displaytype,                              0x8f98)

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
