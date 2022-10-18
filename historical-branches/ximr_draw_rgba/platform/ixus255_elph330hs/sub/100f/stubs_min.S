#include "stubs_asm.h"
DEF(file_counter_var,0x8e54) // sub_FF20E694
DEF(palette_control,0xa0d4) // 0xff24d088 (near "SCM.c"); guessed based on comparison with ELPH 130
DEF(bitmap_buffer,0x40d8) // a few lines below "Re ScreenUnLock"
DEF(active_bitmap_buffer,0x40d0) // similar to ELPH 130
DEF(active_viewport_buffer,0x25b8) // sub_FF075D70
DEF(viewport_buffers,0xff5b7c54) // guessed based on comparison with ELPH 130
// from sub_FF3D574C, value stored in sig finder video_compression_rate is stored here
// both are adjusted continuously by canon firmware
//DEF(video_compression_rate2,0x112c0+0x1c) 
