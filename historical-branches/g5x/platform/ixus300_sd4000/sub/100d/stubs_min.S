#include "stubs_asm.h"

DEF(active_palette_buffer,      0x00009274)     // found at 0xffa11498
DEF(palette_buffer_ptr,         0x0000927c)     // found at 0xffa11160

DEF(active_bitmap_buffer,       0x00004044)     // 0xff8abb44 & 0xff8abb4c  (0x4030 + 0x0014 = 0x4044)
DEF(bitmap_buffer,              0x00004054)     // found at ff8abc10

DEF(rear_dial_position,         0xC0240106)

// ROM:FF860864                 LDR     R0, =0x24A4 <---
// ROM:FF860868                 STMFD   SP!, {R4,LR}
// ROM:FF86086C                 LDR     R0, [R0,#8] <---
// ROM:FF860870                 BL      sub_FF839B50
// ROM:FF860874                 TST     R0, #1
// ROM:FF860878                 LDMNEFD SP!, {R4,LR}
// ROM:FF86087C                 MOVNE   R1, #0x42
// ROM:FF860880                 ADRNE   R0, aLeddrv_c   ; "LEDDrv.c"
// ROM:FF860884                 BNE     DebugAssert
// ROM:FF860888                 LDMFD   SP!, {R4,PC}
DEF(led_table,                          0x24AC) // R0 -> 0x24A4 + 0x8

// like SX210
// ROM:FFA1356C ScreenLock                              ; CODE XREF: sub_FFA121C0
// ROM:FFA1356C                 STMFD   SP!, {R4,LR}
// ROM:FFA13570                 LDR     R4, =0x92AC <---
// ROM:FFA13574                 LDR     R0, [R4,#0x20] <---
// ROM:FFA13578                 CMP     R0, #0
// ROM:FFA1357C                 BNE     loc_FFA13590
// ROM:FFA13580                 ADR     R1, aScreenlock ; "ScreenLock"
// ROM:FFA13584                 MOV     R0, #0x60
// ROM:FFA13588                 BL      CameraLog       ; LOCATION: CameraLog.c:237
// ROM:FFA1358C                 BL      sub_FF8ABEF8
DEF(enabled_refresh_physical_screen,    0x92CC) // ROM:FFA1339C or ROM:FFA13570, 0x92AC + 0x20 = 0x92CC

