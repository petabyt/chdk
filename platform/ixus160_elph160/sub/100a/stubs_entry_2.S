#include "stubs_asm.h"
#define NULL_SUB 0xff83441c

// Looks good enough...
NHSTUB(DeleteFile_Fut, 0xff8274a4)
NHSTUB(GetFocusLensSubjectDistanceFromLens, 0xff98df94)

NHSTUB(MakeDirectory_Fut,0xff827fb4) // mkdir. This required #define MKDIR_RETURN_ONE_ON_SUCCESS

// Try from loc_ff8369cc
// or sub_ff99ee7c
// loc_FF99EEAC looks interesting
// in sub_FF894F98 references to 0x6B...
// try 0x6B21D8
// or sub_ff825374
// 0xff826964
NHSTUB(time, 0xffa1b39c)

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
