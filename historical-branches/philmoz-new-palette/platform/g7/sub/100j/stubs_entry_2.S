#include "stubs_asm.h"
#define NULL_SUB 0xFF9EA4EC

// Override stubs_entry.S
NHSTUB(ExitFromCompensationEVF,     0xff99b244)
NHSTUB(Restart,                     0xFF823ABC)
NHSTUB(WriteSDCard,                 0xFF88BE6C)
NHSTUB(free,                        0xFFB9ECCC)
NHSTUB(kbd_read_keys_r2,            0xFF828E70)

// These don't exist
NHSTUB(SetZoomActuatorSpeedPercent, NULL_SUB)

// Additional
NHSTUB(ExpCtrlTool_StartContiAE,    0xFF925F0C)
NHSTUB(ExpCtrlTool_StopContiAE,     0xFF925F3C)
NHSTUB(platformsub_kbd_fetch_data,  0xFF8293AC)

NHSTUB(taskNameToId,                0xFFBAB804)
NHSTUB(GetVRAMHPixelsSize,0xFFB5686C) // by find_eventproc name @ 0xFFBBC0A0
NHSTUB(GetVRAMVPixelsSize,0xFFB56878) // by find_eventproc name @ 0xFFBBC0A8
