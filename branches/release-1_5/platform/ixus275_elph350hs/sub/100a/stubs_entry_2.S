#include "stubs_asm.h"
#define NULLSUB 0xFF0333E4  //

// Override stubs_entry.S
NHSTUB(MakeDirectory_Fut,                   0xFF027494) // mkdir. This requires #define MKDIR_RETURN_ONE_ON_SUCCESS


// Additional
NHSTUB(TurnOffE1,                           NULLSUB) // for shutdown(), to complicated to emulate 

// Not needed
NHSTUB(RefreshPhysicalScreen,               NULLSUB)

// These don't exist
NHSTUB(kbd_pwr_off,                         NULLSUB)
NHSTUB(kbd_pwr_on,                          NULLSUB)
NHSTUB(SetZoomActuatorSpeedPercent,         NULLSUB)

// temporary measure
NHSTUB(init_focus_eventflag,                0xFF4CADE0) //
NHSTUB(init_nd_eventflag,                   0xFF379290) //
NHSTUB(init_nd_semaphore,                   0xFF3C0618) //

