#include "stubs_asm.h"
#define NULLSUB 0xFF02A000  //blackhole

// Override stubs_entry.S
NHSTUB(CreateTask_low,                      0x006B15A0)
DEF(hook_CreateTask_low,                    0x006B15A0)
NHSTUB(exmem_alloc                         ,0xFF035360) //blackhole
NHSTUB(open                                ,0xFF023DB0) //blackhole
NHSTUB(close                               ,0xFF023E60) //blackhole
NHSTUB(MakeDirectory_Fut,                   0xFF027988) //blackhole


// Additional
NHSTUB(TurnOffE1,                           0xFF038534) //blackhole for shutdown(), to complicated to emulate 

// Not needed
NHSTUB(RefreshPhysicalScreen,               NULLSUB)

// These don't exist
NHSTUB(kbd_pwr_off,                         NULLSUB)
NHSTUB(kbd_pwr_on,                          NULLSUB)
NHSTUB(SetZoomActuatorSpeedPercent,         NULLSUB)
NHSTUB(TurnOffBackLight,                    NULLSUB) 
NHSTUB(TurnOnBackLight,                     NULLSUB)

// temporary measure
NHSTUB(init_focus_eventflag,                0xFF477C7C) //blackhole
NHSTUB(init_nd_eventflag,                   0xFF3410F0) //blackhole
NHSTUB(init_nd_semaphore,                   0xFF37FD18) //blackhole
NHSTUB(CreateBinarySemaphoreStrictly,0xff0284cc) // for av_override_semaphore

