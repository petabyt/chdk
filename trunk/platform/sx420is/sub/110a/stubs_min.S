#include "stubs_asm.h"

DEF(playrec_mode,                   0x00003a18) // reyalp - same as 100a

DEF(file_counter_var,               0x7760)         // reyalp - FUN_ff1c4354 = 100a FUN_ff1c42b8

DEF(active_palette_buffer,          0x6d0c+0x8)     // reyalp - FUN_ff187154 = 100a FUN_ff1870b8
DEF(palette_buffer_ptr,             0x6d0c+0x2C)    // reyalp - base address above, offset from 100a


DEF(active_viewport_buffer,         0x1de18)         // reyalp - ghidra implied match

DEF(viewport_buffers,               0xff5fd388)     // reyalp - ghidra implied match

DEF(bitmap_buffer,                  0x3EF8+0x2C)    // reyalp - ghidra implied match, FUN_ff0af824 in both
DEF(active_bitmap_buffer,           0x3EF8+0x24)    // reyalp - base address above, offset from 100a

DEF(recreview_hold,                 0xA208+0x1C)   // reyalp - ghidra implied match, FUN_ff25cdc8 = 100a FUN_ff25cd2c

DEF(_nrflag, 0xb4c8) // reyalp - ghidra implied match, FUN_ff2ade58 = 100a FUN_ff2adb1c

DEF(av_override_semaphore         ,0x0000d914) // reyalp - ghidra implied match, MoveIrisWithAv


