#include "stubs_asm.h"
#define NULL_SUB 0xff834544

// Looks good enough...
NHSTUB(DeleteFile_Fut, 0xff8274a4)
NHSTUB(GetFocusLensSubjectDistanceFromLens, 0xff98e69c)

NHSTUB(MakeDirectory_Fut,0xff827fb4) // mkdir. This required #define MKDIR_RETURN_ONE_ON_SUCCESS

// Knowing that
//NHSTUB(_log        ,0x006bb388) //111
//NHSTUB(_pow        ,0x006bba40) //121
//NHSTUB(_sqrt       ,0x006bd6e0) //  6
// _log10 should be near that ?
NHSTUB(_log10        ,0x006bb8c8) // Random guess


NHSTUB(RefreshPhysicalScreen, NULL_SUB)
NHSTUB(SetZoomActuatorSpeedPercent, NULL_SUB)
NHSTUB(UnsetZoomForMovie, NULL_SUB)

NHSTUB(CreateTask_low,          0x006B15A4)
DEF(hook_CreateTask_low,        0x006B15A4)

// Additional
NHSTUB(TurnOffE1,               0xff838320) // for shutdown(), to complicated to emulate

// temporary measure
NHSTUB(init_focus_eventflag,                0xFFB6DBC8)
NHSTUB(init_nd_eventflag,                   0xFFAA1664)
NHSTUB(init_nd_semaphore,                   0xFFACEFAC)
