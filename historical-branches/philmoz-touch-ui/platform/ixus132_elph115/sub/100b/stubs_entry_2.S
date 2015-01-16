#include "stubs_asm.h"
#define NULLSUB 0xFF0017D8

// Override stubs_entry.S
NHSTUB(DeleteFile_Fut,                      0xff033b68)
NHSTUB(MakeDirectory_Fut,                   0xff034678) //mkdir. This requires #define MKDIR_RETURN_ONE_ON_SUCCESS
// NHSTUB(Restart,                             0xff038240) // Untested

// Additional
NHSTUB(TurnOffE1,                           0xff037fe4) // for shutdown(), to complicated to emulate

// Not needed
NHSTUB(RefreshPhysicalScreen,               NULLSUB)

// these don't exist
NHSTUB(kbd_pwr_off,                         NULLSUB)
NHSTUB(kbd_pwr_on,                          NULLSUB)
NHSTUB(SetZoomActuatorSpeedPercent,         NULLSUB)
