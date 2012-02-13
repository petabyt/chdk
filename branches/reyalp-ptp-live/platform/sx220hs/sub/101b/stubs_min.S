#include "stubs_asm.h"

DEF(FlashParamsTable,                   0xFF48A4B8)     // 1.01b (was at FF318D50 in 100A)
DEF(zoom_status,                        0xF5A4)         // ff31c404
DEF(recreview_hold,                     0x93D4 + 0xF0)  // FF1B6640
DEF(enabled_refresh_physical_screen,    0x53C4 + 0x14)  //changed to fix error when displaying menu, was 0x20 FF0A99C0 
DEF(led_table,                          0x258C + 0x04)  // FF0557C4
