#include "stubs_asm.h"
#define NULL_SUB 0xffc017e8

// Override stubs_entry.S
NHSTUB(DoAFLock,                    0xffd312e4)
NHSTUB(EnterToCompensationEVF,      0xffd33148)
NHSTUB(ExitFromCompensationEVF,     0xffd331a8)
NHSTUB(GetDrive_ClusterSize,        0xFFC5DC88)
NHSTUB(MakeAFScan,                  0xFFD35C10)
NHSTUB(UnlockAF,                    0xffd31328)
NHSTUB(VbattGet,                    0xffc1c000)
NHSTUB(WriteSDCard,                 0xFFC6D0CC)
NHSTUB(free,                        0xFFECB53C)

// These don't exist
NHSTUB(SetZoomActuatorSpeedPercent, NULL_SUB)

// Additional
NHSTUB(ExpCtrlTool_StartContiAE,    0xFFCE0A28)
NHSTUB(ExpCtrlTool_StopContiAE,     0xFFCE0A58)
NHSTUB(SetScriptMode,               0xFFD45B50)
NHSTUB(TurnOffMic,                  0xffc1e774)
NHSTUB(TurnOnMic,                   0xffc1e738)
