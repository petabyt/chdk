#include "stubs_asm.h"

DEF(file_counter_var                            ,0x00011ee4) // found by searching for "FileBackupProperty.c"

// Camera has 6(?) RAW buffers (@0xfc63614c, obviously overlapping):
// 43CC8A00 45BE18E0 47AFA7C0 459AFF80 478C8E60 497E1D40
DEF(raw_buffers                                 ,0xfc63614c) // Found @0xfc151cf4
DEF(active_raw_buffer                           ,0x0000B254) // 0xb248+0xc, 0xffffffff when uninited...

DEF(_nrflag                                     ,0x29c00) // see NRTBL.SetDarkSubType

//DEF(error_table                               ,0xfc660780) // around ExxTbl.c

FAKEDEF(video_compression_rate, 1)

DEF(canon_menu_active                           ,0x0000b9a8) // found @0xfc35d3c8 (0xb9a4+4)
FAKEDEF(canon_shoot_menu_active, 1) // todo

FAKEDEF(zoom_status ,1)

DEF(recreview_hold                              ,0x000095a0) // found @fc36a376, 0x9550 + 0x50
FAKEDEF(zoom_busy ,1)
FAKEDEF(focus_busy ,1)

DEF(bitmap_buffer                               ,0xb968) // by RAM search for known buf addresses, buffers in reverse order

// FAKEDEF(active_viewport_buffer, 1) // ?
DEF(current_viewport_buffer                     ,0x00008810) // found @fc12a516, 0x8754 + 0x80 + 0x3c
// 42CF6A00 430EB200 434DFA00 438D4200, 720x480 in 736x480 buffer when using LCD, there's space for 1920x1080 uyvy
DEF(viewport_buffers                            ,0xfc62318c) // ref to fc62317c + 0x10 @ fc1296c2

//FAKEDEF(enabled_refresh_physical_screen, 1)

DEF(displaytype                                 ,0x9740) // 0x96f0 + 0x50, GetDisplayType

DEF(current_fb_d                                ,0xF564) // @fc177872, 0xf53c + 0x28

DEF(simple_movie_status                         ,0xb000) // 0xaf10 + 0x80 + 0x70 @FC0FDA32

DEF(jog_position                                ,0xf6dc)
DEF(jog_hw_pos                                  ,0xd9855004) // see GetRotaryEncPulseCounter_FW

DEF(canon_gui_started_flag                      ,0xb918) // see GUISrv_StartGUISystem_FW

DEF(palette_buffer_ptr                          ,0x13540) // FC3599BC, FC3599D8
DEF(active_palette_buffer                       ,0x13538) // FC3599BC, FC3599C0
DEF(palette_control                             ,0x13528) // FC359B20, FC359B40
