#include "stubs_asm.h"

DEF(active_bitmap_buffer                    ,0xC314)					
DEF(bitmap_buffer                           ,0xC31C)
DEF(palette_control                         ,0xC2D8)
DEF(active_palette_buffer                   ,0xC2E0)
DEF(palette_buffer                          ,0xDF7F0)
DEF(viewport_buffers                        ,0xFF43457C)    // 1.00g sub_FF045D2C (FF0460F0)
DEF(active_viewport_buffer                  ,0x215C)        // 1.00g sub_FF045D2C (FF045D30 & FF04611C)
DEF(some_flag_for_af_scan                   ,0x9970 + 0x8)  //NOT SURE SX40 FF1D63F8 
DEF(led_table                               ,0x2614 + 0x04) //FF056E5C SX40 
DEF(enabled_refresh_physical_screen         ,0x47F0 + 0x14) // FF0B138C + FF0B13B0 SX40 
DEF(rear_dial_position                      ,0xC0240106)
