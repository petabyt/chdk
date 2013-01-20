#include "stubs_asm.h"
#define NULL_SUB 0xFF810B4C

// Override stubs_entry.S
NHSTUB(kbd_pwr_off,                 NULL_SUB)
NHSTUB(kbd_pwr_on,                  NULL_SUB)
NHSTUB(MakeDirectory_Fut,           0xff831974) //mkdir requires #define MKDIR_RETURN_ONE_ON_SUCCESS

// Additional
NHSTUB(LockAndRefresh,              0xff899d20)
NHSTUB(UnlockAndRefresh,            0xff899d84)

// These don't exist
NHSTUB(SetZoomActuatorSpeedPercent, NULL_SUB)
 NSTUB(srand,                       NULL_SUB)  //overridable function
 NSTUB(rand,                        NULL_SUB)  //overridable function
