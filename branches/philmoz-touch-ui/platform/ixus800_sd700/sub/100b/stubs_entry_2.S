#include "stubs_asm.h"
#define NULL_SUB 0xFF8117EC

// Override stubs_entry.S
NHSTUB(EnterToCompensationEVF,      NULL_SUB)
NHSTUB(ExitFromCompensationEVF,     NULL_SUB)
NHSTUB(MakeAFScan,                  0xFF95FDE8)
NHSTUB(free,                        0xFFB0EFE4)
NHSTUB(kbd_pwr_off,                 0xFF827F08)
NHSTUB(kbd_pwr_on,                  0xFF827EC8)

// These don't exist
NHSTUB(SetZoomActuatorSpeedPercent, NULL_SUB)

// Additional
NHSTUB(ExpCtrlTool_StartContiAE,    0xFF903520)
NHSTUB(ExpCtrlTool_StopContiAE,     0xFF903550)
NHSTUB(GetVRAMHPixelsSize,0xFFACAE68) // by find_eventproc name @ 0xFFB2BCD8
NHSTUB(GetVRAMVPixelsSize,0xFFACAE74) // by find_eventproc name @ 0xFFB2BCE0
