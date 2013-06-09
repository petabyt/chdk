#include "stubs_asm.h"

DEF(physw_status                            ,0x000386bc) // Found @0xff024db0,          stubs_min = 0x000386bc (0x000386bc)
DEF(physw_run                               ,0x00001c3c) // Found @0xff02493c,          stubs_min = 0x00001c3c (0x00001c3c)
DEF(levent_table                            ,0xff5905cc) // Found @0xff5905cc,          stubs_min = 0xff5905cc (0xff5905cc)
DEF(FlashParamsTable                        ,0xff6267b4) // Found @0xff6267b4,          stubs_min = 0xff6267b4 (0xff6267b4)
DEF(movie_status                            ,0x00009bfc) // Found @0xff1cb1b0,          stubs_min = 0x00009bfc (0x00009bfc)
DEF(full_screen_refresh                     ,0x0000ca28) // Found @0xff297af0,          stubs_min = 0x0000ca28 (0x0000ca28)
DEF(canon_menu_active                       ,0x00004484) // Found @0xff0924cc,          stubs_min = 0x00004484 (0x00004484)
DEF(canon_shoot_menu_active                 ,0x0000b291) // Found @0xff22ca24,          stubs_min = 0x0000b291 (0x0000b291)
DEF(playrec_mode                            ,0x000041a4) // Found @0xff083ca8,          stubs_min = 0x000041a4 (0x000041a4)
DEF(zoom_status                             ,0x0000ad6c) // Found @0xff213958,          stubs_min = 0x0000ad6c (0x0000ad6c)
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 2 int value(s), the first is the zoom focus length.
// there are 121 entries in the table - set NUM_FL to 121
DEF(focus_len_table                         ,0xfff4a4f8) // Found @0xfff4a4f8,          stubs_min = 0xfff4a4f8 (0xfff4a4f8)
DEF(zoom_busy                               ,0x00009b24) // Found @0xff1c6118,          stubs_min = 0x00009b24 (0x00009b24)
DEF(focus_busy                              ,0x00009940) // Found @0xff1bef10,          stubs_min = 0x00009940 (0x00009940)
DEF(recreview_hold                          ,0x00005008) // Found @0xff0a51b0,          stubs_min = 0x00005008 (0x00005008)

DEF(rear_dial_position                      ,0xC0240106) // TODO: this is from sx40hs
