#include "stubs_asm.h"

// guessed from sub_ff9e885c (see string in sub_ff85fde8)
DEF(recreview_hold, 0x00008898)

// 0xff8803a8 (0x3228), 0xff8803e0 (0x54)
DEF(viewport_fb_d, 0x0000327c)

// see NRTBL.SetDarkSubType_FW (this will likely "lag")
DEF(_nrflag, 0xa39c)

// found by searching RAM
DEF(active_viewport_buffer, 0x188a4) // 0x18868 (@0xFF84D164) + 0x3c (@0xFF84D5B0)
DEF(viewport_buffers, 0xFFB989CC)

// search for "Window_EmergencyRefresh" (compare to ixus140)
DEF(bitmap_buffer, 0x3ae4) // @0xff8a2b80, 0x3ac0 + 0x24
DEF(active_bitmap_buffer, 0x3adc) // 0x3ac0 + 0x1c (@0xff8a1f28)

DEF(active_palette_buffer, 0x7b3c) // @0xff9b5220 (0x7b34+8)
DEF(palette_buffer_ptr, 0x7b40) // add 0x4
DEF(palette_control, 0x7b34)

DEF(file_counter_var, 0x691c) // found by searching for "FileBackupProperty.c"

DEF(video_compression_rate, 0x70a0) // found at 0xff993d78

DEF(video_target_framesize, 0xBDB4) // found in sub_FFAB938C
DEF(video_target_framesize2, 0xBDB0) // approx. 2*video_target_framesize (for intraframes?), found in sub_FFAB938C
//DEF(video_framesize, 0x70f0) // most recent frame's compressed size, found at 0xFF993D74
//DEF(video_frame_data, 0x70f4) // most recent frame's RAM address
