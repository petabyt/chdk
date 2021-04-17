#include "stubs_asm.h"

//DEF(led_table,)
DEF(jpeg_count_str,                0x000e4308) // Found @0xfc0fc46c
DEF(file_counter_var,              0x000102dc) // found by searching for "FileBackupProperty.c" 
DEF(ctypes, 0xfc481088)

// Camera has 2 RAW buffers @ 0x44000000 & 0x4adb54a0
DEF(raw_buffers                   ,0xfc4fa954) // Found @0xfc16d43e
DEF(active_raw_buffer             ,0x0000a08c) // Found @0xfc13fa6c, 0xffffffff when uninited...
DEF(fileio_semaphore              ,0x000103b4) // Found @0xfc05ccb0

DEF(physw_status                            ,0x0002ae70) // Found @0xfc0604ae
DEF(physw_run                               ,0x00008328) // Found @0xfc0601f6
DEF(physw_sleep_delay                       ,0x00008330) // Found @0xfc0601f6

//DEF(error_table                             ,0xfc512234) // Found @0xfc1abf24

DEF(levent_table                            ,0xfc512594) // Found @0xfc0a4b40
DEF(FlashParamsTable                        ,0xfc7313a0) // 0xfc730610 -> 0xfc7313a0
DEF(simple_movie_status                     ,0x00010af8) // one from 3 candidates, based on ram snooping, 1 when recording, 0 when not
FAKEDEF(video_compression_rate, 1)
DEF(full_screen_refresh                     ,0x00012a94) // Found @0xfc2b0f5c
DEF(canon_menu_active                       ,0x0000ac58) // Found @0xfc27d0bc
FAKEDEF(canon_shoot_menu_active, 1) // ??? not found
DEF(playrec_mode                            ,0x0000a140) // Found @0xfc27937e
DEF(zoom_status                             ,0x00018b04) // Found @0xfc30e61c
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 2 int value(s), the first is the zoom focus length.
// there are 102 entries in the table - set NUM_FL to 101
DEF(focus_len_table                         ,0xfdf6ad20)
DEF(zoom_busy                               ,0x00010814) // Found @0xfc1a0998
DEF(focus_busy                              ,0x00010694) // Found @0xfc28b964
DEF(recreview_hold                          ,0x00008DE4) // Found @0xfc2a2c22
//DEF_CONST(uiprop_count                      ,0x00000083) // Found @0xfc090268

DEF(bitmap_buffer, 0xac18) // ?, struct starts @ 0xabdc

//.globl bitmap_buffer; bitmap_buffer: ; .long 0x427e3000 ; .long 0x42621000 ;


// FAKEDEF(active_viewport_buffer, 1) // ?
DEF(current_fb_d                            ,0x0000d960) // 0xd940 + 0x20, found @0xfc186624 (102b), similar to 0xfc1ba452 in g7x 100d
DEF(current_viewport_buffer                 ,0x000087b4) // 0x86f4 + 0xc0 (@0xfc1349a4), contains viewport address that updates at ~30fps in rec mode, 0 or last rec value in pb
DEF(viewport_buffers                        ,0xfc4d3568) // from memory search

DEF(jog_position,                           0xdb48) // 0xdb34 +0x14, +0x18
DEF(jog_hw_pos,                             0xd9854004) // found by browsing the 0xd985xxxx range...


//FAKEDEF(enabled_refresh_physical_screen,    1)

DEF(displaytype,                            0x8eb8) //0x8ea4 + 0x14, found  @ fc135f2a (GetDisplayType)

DEF(task_AGPSDownloader, 0xFC07BA67)
