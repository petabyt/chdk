#include "stubs_asm.h"
DEF(file_counter_var,0x7570) // found by searching RAM :<
DEF(palette_control,0x87a0) // guessed based on similarity to g12 (first byte of palette related struct)
DEF(bitmap_buffer,0x3f80) // from browsing ram
DEF(active_bitmap_buffer,0x3f78) // similar to g12, checking ram
DEF(active_viewport_buffer,0x258c) // sub_FF073A04
DEF(viewport_buffers,0xFF4FB210) // sub_FF073A04, guessed
