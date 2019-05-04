#include "stubs_asm.h"
#define NULL_SUB 0xFF810B7C

// Override stubs_entry.S
NHSTUB(DeleteFile_Fut,            0xff82d058)
NHSTUB(kbd_pwr_off,                 NULL_SUB)
NHSTUB(kbd_pwr_on,                  NULL_SUB)
NHSTUB(MakeDirectory_Fut,         0xff82db68) //mkdir. This requires #define MKDIR_RETURN_ONE_ON_SUCCESS

// Additional
NHSTUB(TurnOffE1,                 0xff831210) // for shutdown(), to complicated to emulate


// These don't exist
NHSTUB(SetZoomActuatorSpeedPercent, NULL_SUB)
NHSTUB(RefreshPhysicalScreen,       NULL_SUB)
NHSTUB(UnsetZoomForMovie,           NULL_SUB)