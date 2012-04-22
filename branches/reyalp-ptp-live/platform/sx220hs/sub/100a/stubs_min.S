#include "stubs_asm.h"

DEF(active_bitmap_buffer,               0xB394)  // 0xB380+0x14 (1.01a sub_FF2426A8 -> FF2426AC + FF242704)
DEF(bitmap_buffer,                      0xB39C)  // FF242700
DEF(active_palette_buffer,              0xB35C)  // sub_FF23D5A4 (1.01a)
DEF(palette_buffer,                     0xCAE40) // loc_FF23DA3C (1.01a)
DEF(recreview_hold,                     0x93D4 + 0xF0)  // FF1B6640
DEF(led_table,                          0x258C + 0x04)  // FF0557C4
