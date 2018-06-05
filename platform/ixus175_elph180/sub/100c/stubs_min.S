#include "stubs_asm.h"

// //@FF863700 0x2934+0x80 ShootCon_NotifyCompleteReviewHold
DEF(recreview_hold, 0x000029b4) 

// see NRTBL.SetDarkSubType_FW (this will likely "lag")
DEF(_nrflag, 0x9A58) //0x9A54+4 plus 4 like reference port ixus 145,160

// found by searching RAM, observed values 0-3, 0x179A4+0x3C in liveimg.c @FF84D24C
DEF(active_viewport_buffer, 0x179E0) 
DEF(viewport_buffers, 0xFFBE2D90) //guess with ixus 150 blackhole

// search for "Window_EmergencyRefresh" (compare to ixus160)
DEF(bitmap_buffer, 0x3CE4) // @0xFF8A5C28 (0x3CB8) + @0xFF8A5C38 (0x2c)
DEF(active_bitmap_buffer, 0x3CE0) // 0x3CB8 + 0x28 

DEF(active_palette_buffer, 0x7DD4)  // found at FF9CD85C =0x7DCC + 8 by search window_emergency_refresh
DEF(palette_buffer_ptr, 0x7DD8) // add 0x4
//DEF(palette_control, 0x3D00)0x3D00=0x3CF4+0xC //search Window Reduce MuteOff. ixus150 method (difference method between ixus 160 and ixus 150)
DEF(palette_control, 0x7DCC) //ixus160 method

DEF(file_counter_var, 0x6CFC) // found by searching for "FileBackupProperty.c"

//DEF(video_compression_rate, 0x70a0) // found at 0xff993d78

DEF(video_target_framesize, 0xBDB4) // found in sub_FFAB938C //must change
DEF(video_target_framesize2, 0xBDB0) // approx. 2*video_target_framesize (for intraframes?), found in sub_FFAB938C //must change
//DEF(video_framesize, 0x70f0) // most recent frame's compressed size, found at 0xFF993D74
//DEF(video_frame_data, 0x70f4) // most recent frame's RAM address


