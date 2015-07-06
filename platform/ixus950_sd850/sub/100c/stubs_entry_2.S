#include "stubs_asm.h"
#define NULL_SUB 0xFF9B4BA4

// Override stubs_entry.S
NHSTUB(AllocateMemory,              0xFF818664)
NHSTUB(DisplayImagePhysicalScreen,  0xFFA2CFCC)
NHSTUB(EnterToCompensationEVF,      NULL_SUB)
NHSTUB(ExitFromCompensationEVF,     NULL_SUB)
NHSTUB(FreeMemory,                  0xFF818650)
NHSTUB(free,                        0xFF92BA0C)
NHSTUB(kbd_pwr_off,                 0xFFA38C14)
NHSTUB(kbd_pwr_on,                  0xFFA38BD4)

// These don't exist
NHSTUB(SetZoomActuatorSpeedPercent, NULL_SUB)

// Additional
NHSTUB(ExpCtrlTool_StartContiAE,    0xFF971628)
NHSTUB(ExpCtrlTool_StopContiAE,     0xFF971658)
NHSTUB(MFOff,                       0xFFB0B1B0)
NHSTUB(MFOn,                        0xFFB0B14C)

NHSTUB(taskNameToId,                0xFF935A64)
NHSTUB(GetVRAMHPixelsSize,0xFFA5EE78) // by find_eventproc name @ 0xFFBA2F30
NHSTUB(GetVRAMVPixelsSize,0xFFA5EE84) // by find_eventproc name @ 0xFFBA2F38
