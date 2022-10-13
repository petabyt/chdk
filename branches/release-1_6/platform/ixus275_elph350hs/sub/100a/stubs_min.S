#include "stubs_asm.h"
DEF(playrec_mode,                   0x00003bb4)  //sub_FF0A0720 

DEF(file_counter_var,               0x8ABC)         // Found @loc_FF1ECBA4  by searching for "FileBackupProperty.c" 

DEF(active_palette_buffer,          0x70C0+0x8)     // 
DEF(palette_buffer_ptr,             0x70C0+0x2C)    // Found @ sub_FF196608 

DEF(active_viewport_buffer,         0x21B68)         // 0x21B2C @FF0504A4  +  0x3C @FF050938  =  0x21B68  

DEF(viewport_buffers,               0xFF636388)     // 

DEF(viewport_fb_d,                  0x3778+0x54)    // sub_FF08D6A4 

DEF(bitmap_buffer,                  0x4080+0x30)    // 0x4080 + 0x30  sub_FF0B4FF0 
DEF(active_bitmap_buffer,           0x4080+0x28)    // 0x4080 + 0x28  sub_FF0B4274 

DEF(recreview_hold,                 0xC478+0x1C)    //sub_FF2896C4 

DEF(_nrflag, 0xD734) // 0xD730 + 0x4  sub_FF2E0694


