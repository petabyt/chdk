#include "stubs_asm.h"
#define NULL_SUB 0xFFC00B20

// Override stubs_entry.S
NHSTUB(kbd_pwr_on,                  NULL_SUB)
NHSTUB(kbd_pwr_off,                 NULL_SUB)

// These don't exist
NHSTUB(SetZoomActuatorSpeedPercent, NULL_SUB)

// Additional
NHSTUB(LockAndRefresh,              0xFFD7B04C)
NHSTUB(MakeAFScan,                  0xFFD0F178)
NHSTUB(TurnOffMic,                  0xFFC43C30) // Doesn't work
NHSTUB(TurnOnMic,                   0xFFC43C5C) // Doesn't work
NHSTUB(UnlockAndRefresh,            0xFFD7B090)
