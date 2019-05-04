#include "stubs_asm.h"
#define NULLSUB 0xFF029558  //blackhole

// Override stubs_entry.S
NHSTUB(MakeDirectory_Fut,                   0xFF0277AC) //blackhole
NHSTUB(open,0xFF023CB8) //blackhole
NHSTUB(close,0xFF023D68) //blackhole


// Additional
NHSTUB(TurnOffE1,                           0xFF0377E4) //blackhole, for shutdown(), to complicated to emulate 

// Not needed
NHSTUB(RefreshPhysicalScreen,               NULLSUB)

// These don't exist
NHSTUB(kbd_pwr_off,                         NULLSUB)
NHSTUB(kbd_pwr_on,                          NULLSUB)
NHSTUB(SetZoomActuatorSpeedPercent,         NULLSUB)

NHSTUB(TurnOffBackLight, NULLSUB)
NHSTUB(TurnOnBackLight, NULLSUB)

// temporary measure
NHSTUB(init_focus_eventflag,                0xFF4681D4) //blackhole
NHSTUB(init_nd_eventflag,                   0xFF33506C) //blackhole
NHSTUB(init_nd_semaphore,                   0xFF371910) //blackhole


