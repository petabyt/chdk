#include "stubs_asm.h"
#define NULL_SUB 0xFF966BC4

// Override stubs_entry.S
NHSTUB(EnterToCompensationEVF,      NULL_SUB)
NHSTUB(ExitFromCompensationEVF,     NULL_SUB)
NHSTUB(MakeAFScan,                  0xFF95FDEC)
NHSTUB(free,                        0xFFB0EFDC)
NHSTUB(kbd_pwr_off,                 0xFF827F0C)
NHSTUB(kbd_pwr_on,                  0xFF827ECC)

// These don't exist
NHSTUB(SetZoomActuatorSpeedPercent, NULL_SUB)

// Additional
NHSTUB(ExpCtrlTool_StartContiAE,    0xFF903524)
NHSTUB(ExpCtrlTool_StopContiAE,     0xFF903554)
NHSTUB(GetVRAMHPixelsSize,0xFFACAE60) // by find_eventproc name @ 0xFFB2BCD8
NHSTUB(GetVRAMVPixelsSize,0xFFACAE6C) // by find_eventproc name @ 0xFFB2BCE0
