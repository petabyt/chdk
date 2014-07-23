#include "stubs_asm.h"
#define NULL_SUB 0xFFC22854

// Override stubs_entry.S
NHSTUB(EnterToCompensationEVF,      0xffd4424c)
NHSTUB(ExitFromCompensationEVF,     0xffd442ac)
NHSTUB(MakeAFScan,                  0xFFD46CF0)
NHSTUB(free,                        0xFFEE84C8)

// These don't exist
NHSTUB(SetZoomActuatorSpeedPercent, NULL_SUB)

// Additional
NHSTUB(ExpCtrlTool_StartContiAE,    0xFFCF1928)
NHSTUB(ExpCtrlTool_StopContiAE,     0xFFCF1958)
NHSTUB(PostLEDMessage,              0xFFC1CF80)
NHSTUB(TurnOffMic,                  0xffc1e100)
NHSTUB(TurnOnMic,                   0xffc1e0c4)
NHSTUB(GetVRAMHPixelsSize,0xFFEA59FC) // by find_eventproc name @ 0xFFF03DB8
NHSTUB(GetVRAMVPixelsSize,0xFFEA5A08) // by find_eventproc name @ 0xFFF03DC0
