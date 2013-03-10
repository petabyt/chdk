#include "stubs_asm.h"

DEF(viewport_buffers,                   0xFF441054)    // 1.00b sub_FF03DB84 (FF03DF88)
DEF(active_viewport_buffer,             0x21B0)        // 1.00b sub_FF03DB84 (FF03DB88 & FF03E13C)
DEF(led_table,                          0x2604 + 0x04)  // asm1989 found at FF04D070
DEF(enabled_refresh_physical_screen,    0x4668 + 0x14)  // asm1989 found at FF0A1174 + FF0A1198
