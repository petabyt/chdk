#include "stubs_asm.h"
#define NULLSUB 0xFF0331D8  //blackhole

// Override stubs_entry.S
NHSTUB(MakeDirectory_Fut,                   0xFF027494) // mkdir. This requires #define MKDIR_RETURN_ONE_ON_SUCCESS blackhole


// Additional
NHSTUB(TurnOffE1,                           NULLSUB) // for shutdown(), to complicated to emulate---sx610_100a sub_FF0372B0  ??? blackhole

// Not needed
NHSTUB(RefreshPhysicalScreen,               NULLSUB)

// These don't exist
NHSTUB(kbd_pwr_off,                         NULLSUB)
NHSTUB(kbd_pwr_on,                          NULLSUB)
NHSTUB(SetZoomActuatorSpeedPercent,         NULLSUB)

// temporary measure
NHSTUB(init_focus_eventflag,                0xFF4CAD94) //blackhole
NHSTUB(init_nd_eventflag,                   0xFF37A0B8) //blackhole
NHSTUB(init_nd_semaphore,                   0xFF3C15AC) //blackhole FF3C15AC

NHSTUB(LogCameraEvent,                   	0xff035200) // csv, for debug
