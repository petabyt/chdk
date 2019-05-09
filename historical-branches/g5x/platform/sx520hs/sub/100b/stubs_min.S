#include "stubs_asm.h"
DEF(playrec_mode                            ,0x00003b58) // 0xff0a40f4

DEF(file_counter_var,               0x00008c04) // found by searching for "FileBackupProperty.c"

DEF(palette_buffer_ptr,             0x7278+0x2C)

DEF(active_viewport_buffer,         0x000022d08) // 0xff0503fc 0x22ccc + 0xff050890  0x3c = 0x22d08  search for "LiveImage.c"
DEF(viewport_buffers,               0xff63df84) // by comparison to sx510hs

DEF(viewport_fb_d,                  0x000036a8) // Found @0xff08c2c8 (0x3654)

DEF(bitmap_buffer,                  0x000040b0) //  0x4088 + 0x28
DEF(active_bitmap_buffer,           0x000040a8) //  0x4088 + 0x20

DEF(recreview_hold,                 0x00002a28+0x84)

// see NRTBL.SetDarkSubType, ineffective for the next photo (it 'lags') 0xec60 + 0x4
DEF(_nrflag, 0xEC64)

//TODO
DEF(rear_dial_position,        0xC0240106)  //To do


DEF(video_compression_rate, 0xa580+0x7c)

DEF(video_target_framesize, 0x1106c+0x2c)
DEF(video_target_framesize2, 0x1106c+0x28)
//DEF(video_framesize, 0xa580+0x104)
//DEF(video_frame_data, 0xa580+0x108)
