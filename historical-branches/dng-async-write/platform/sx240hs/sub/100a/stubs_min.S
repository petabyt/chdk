#include "stubs_asm.h"

DEF(viewport_buffers,                   0xFF44102C)    // 1.00a sub_FF03DB84 (FF03DF88)
DEF(active_viewport_buffer,             0x21B0)        // 1.00a sub_FF03DB84 (FF03DB88 & FF03E13C)
DEF(led_table,                          0x2604 + 0x04) // 1.00a sub_FF04D06C (FF04D070 + FF04D090)
DEF(enabled_refresh_physical_screen,    0x4668 + 0x14) // 1.00a sub_FF0A1170 (FF0A1170 + FF0A1198)
