#include "stubs_asm.h"
#define NULL_SUB 0xFFC0183C

// Override stubs_entry.S
NHSTUB(ExitFromCompensationEVF,     0xffd35ca4)
NHSTUB(free,                        0xFFEC5BCC)

// These don't exist
NHSTUB(SetZoomActuatorSpeedPercent, NULL_SUB)

// Additional
NHSTUB(ExpCtrlTool_StartContiAE,    0xFFCE09F8)
NHSTUB(ExpCtrlTool_StopContiAE,     0xFFCE0A10)
NHSTUB(TurnOffMic,                  0xffc1ec58)
NHSTUB(TurnOnMic,                   0xffc1ec10)
