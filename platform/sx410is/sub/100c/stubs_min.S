#include "stubs_asm.h"


DEF(file_counter_var,               0x6D68)         // Found @FF986780 by searching for "FileBackupProperty.c" blackhole

//DEF(palette_control,                0x6358)         // ???
DEF(active_palette_buffer,          0x6358+0x8)     // Found @0x: Guess!!!
DEF(palette_buffer_ptr,             0x6358+0x2C)    // Found @FF94ABFC blackhole
//DEF(palette_buffer,                 0x106330)       // ???
                                    

DEF(active_viewport_buffer,         0x1AFE8)         // 0x1AFAC @FF84F96C  +  0x3C @FF84FDB8  =  0x1AFE8 blackhole

DEF(viewport_buffers,               0xFFBF8510)     // blackhole

DEF(viewport_fb_d,                  0x324C+0x54)    // Found @FF88332C (0x324C) + @0xFF883368 (0x54) blackhole

DEF(bitmap_buffer,                  0x3B38+0x24)    // 0x3B38 + 0x24  @FF8A7998 blackhole
DEF(active_bitmap_buffer,           0x3B38+0x1C)    // 0x3B38 + 0x1C  @FF8A6D6C blackhole

DEF(recreview_hold,                 0x92D0+0x1C)   //@sub_FFA0CBE8

// see NRTBL.SetDarkSubType, 0xB034 + 0x4  @FFA4F6B8 blackhole
DEF(_nrflag, 0xB038)

DEF(focus_len_table,                0xffffae7c)     // Found @0xffffae7c blackhole
//DEF(raw_buffers,                    0xFF8E7F04)
//DEF(active_raw_buffer,              0x000035DC)     // @FF892628

DEF(video_compression_rate, 0x75FC) // @FF9AA7A8 blackhole
DEF(video_target_framesize, 0xCD84+0x2C) // found in sub_FFAFF18 blackhole
DEF(video_target_framesize2, 0xCD84+0x28) // approx. 2*video_target_framesize (for intraframes?), found in sub_FFAFF18 blackhole

DEF(av_override_semaphore         ,0x0000cf30) // MoveIrisWithAv

// the original some_flag_for_af_scan should not be used, as the fw's MakeAFScan function is not called
.globl some_flag_for_af_scan
some_flag_for_af_scan: .long 0
