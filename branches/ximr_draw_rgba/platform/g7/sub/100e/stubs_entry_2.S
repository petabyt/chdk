#include "stubs_asm.h"
#define NULL_SUB 0xFF8117E8

// Override stubs_entry.S
NHSTUB(EnterToCompensationEVF,      NULL_SUB)
NHSTUB(ExitFromCompensationEVF,     NULL_SUB)
NHSTUB(Restart,                     0xFF823ABC)
NHSTUB(WriteSDCard,                 0xFF88BE6C)
NHSTUB(free,                        0xFFB9EA6C)
NHSTUB(kbd_read_keys_r2,            0xFF828E70)

// These don't exist
NHSTUB(SetZoomActuatorSpeedPercent, NULL_SUB)

// Additional
NHSTUB(ExpCtrlTool_StartContiAE,    0xFF925EE8)
NHSTUB(ExpCtrlTool_StopContiAE,     0xFF925F18)
NHSTUB(platformsub_kbd_fetch_data,  0xFF8293AC)

NHSTUB(taskNameToId,                0xFFBAB5A4)
NHSTUB(GetVRAMHPixelsSize,0xFFB5665C) // by find_eventproc name @ 0xFFBBBE40
NHSTUB(GetVRAMVPixelsSize,0xFFB56668) // by find_eventproc name @ 0xFFBBBE48
