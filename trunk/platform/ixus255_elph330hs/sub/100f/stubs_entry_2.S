#include "stubs_asm.h"
#define NULLSUB 0xFF0017D8

NHSTUB(MakeDirectory_Fut, 0xff0355e0) // mkdir: this requires #define MKDIR_RETURN_ONE_ON_SUCCESS
NHSTUB(finish_shutdown,   0xff039424) // (TurnOffE1_FW) for shutdown(), too complicated to emulate

NHSTUB(RefreshPhysicalScreen, NULLSUB)
NHSTUB(SetZoomActuatorSpeedPercent,NULLSUB)
