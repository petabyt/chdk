// Powershot N Facebook

#include "stubs_asm.h"

DEF(touch_screen_active,                0x000031E4)     //+
DEF(touch_screen_x,                     0x000A0EE8)     // FF096018 LDR     R3, =0xA0ED4  (+0x14)
DEF(touch_screen_y,                     0x000A0EEA)     // FF096018 LDR     R3, =0xA0ED4  (+0x16)
DEF(file_counter_var,                   0x00009EEC)     //+ found @ 0xFF217EE8 by searching for "FileBackupProperty.c"
DEF(palette_control,                    0xB0F0)         //+ 0xFF2590F0
DEF(active_palette_buffer,              0xB0F8)         //+ 0xFF2590F8
DEF(palette_buffer_ptr,                 0xB0FC)         //+ 0xFF259120
DEF(viewport_fb_d,                      0x3890)         //+  0x383C (Found @0xFF0AE284) + 0x54 (@0xFF0AE2D4)
DEF(viewport_buffers,                   0xFF5BC9A0 )    //+ Powershot N FB found @ 0xFF076140 (= 0xFF5BC984) plus @ @xFF07614C (=0x001C)
DEF(active_viewport_buffer,             0x000025C0 )    //+ Powershot N FB found @ 0xFF075E3C - 8 buffers in use
DEF(focus_len_table,                    0xFFF4ABE0)     //+ found scanning memory of 0x88 0x13 0x00 0x00 0x64 0x00 0x00 0x00 ( 5000 100 decimal )


   
                   

