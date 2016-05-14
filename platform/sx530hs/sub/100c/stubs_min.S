#include "stubs_asm.h"
DEF(playrec_mode                            ,0x00003b60) // 0xff0a4118 

DEF(file_counter_var,               0x00008c0c) // found by searching for "FileBackupProperty.c"

DEF(palette_buffer_ptr,             0x7280+0x2C) //FF191A20 blackhole

DEF(active_viewport_buffer,         0x000022d08) // 0xff0503fc 0x22ccc + 0xff050890  0x3c = 0x22d08  search for "LiveImage.c"
DEF(viewport_buffers,               0xff63dfe8) // by comparison to sx510hs

DEF(viewport_fb_d,                  0x000036ac) // Found @0xff067204 (0x3658) + @0xff08c634 (0x54) 

DEF(bitmap_buffer,                  0x000040b8) //  0x4090 + 0x28 = 0x40b8  0xff0b89bc
DEF(active_bitmap_buffer,           0x000040b0) //  0x4090 + 0x20 = 0x40b0  0xff0b7bc4

DEF(recreview_hold,                 0x00002a2c+0x84) //@0xff06aa9c + 0x84 (offset used by A2500)

// see NRTBL.SetDarkSubType, ineffective for the next photo (it 'lags') 0xec68 + 0x4
DEF(_nrflag, 0xEC6C)

//TODO
DEF(rear_dial_position,        0xC0240106)  //To do


DEF(video_compression_rate, 0xa588+0x7c) // found at 0xFF215E8C

DEF(video_target_framesize, 0x11074+0x2c) // found in sub_FF3CA70C
DEF(video_target_framesize2, 0x11074+0x28) // approx. 2*video_target_framesize (for intraframes?), found in sub_FF3CA70C
//DEF(video_framesize, 0xa588+0x104) // most recent frame's compressed size, found at 0xFF215E88
//DEF(video_frame_data, 0xa588+0x108) // most recent frame's RAM address
