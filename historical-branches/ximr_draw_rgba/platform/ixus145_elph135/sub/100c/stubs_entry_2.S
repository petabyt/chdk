#include "stubs_asm.h"
#define NULL_SUB 0xFF893210

// Override stubs_entry.S
NHSTUB(MakeDirectory_Fut,           0xff82760c) //mkdir. This requires #define MKDIR_RETURN_ONE_ON_SUCCESS

// Additional
NHSTUB(TurnOffE1,                   0xff8362b4) // for shutdown(), to complicated to emulate

// These don't exist
NHSTUB(SetZoomActuatorSpeedPercent, NULL_SUB)
NHSTUB(RefreshPhysicalScreen,       NULL_SUB)
NHSTUB(UnsetZoomForMovie,           NULL_SUB)

// temporary measure
NHSTUB(init_focus_eventflag,        0xFFB6A58C)
NHSTUB(init_nd_eventflag,           0xFFA98F28)
NHSTUB(init_nd_semaphore,           0xFFAC69B4) 

