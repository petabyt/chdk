#include "stubs_asm.h"
#define NULLSUB 0xff89ab0c

// Override stubs_entry.S
NHSTUB(MakeDirectory_Fut,                   0xff827fb0) // mkdir. This requires #define MKDIR_RETURN_ONE_ON_SUCCESS
NHSTUB(CreateTask_low,                      0x006B15A4)
DEF(hook_CreateTask_low,                    0x006B15A4)

// Additional
NHSTUB(TurnOffE1,                           0xff838614) // for shutdown(), to complicated to emulate

// Not needed
NHSTUB(RefreshPhysicalScreen,               NULLSUB)

// These don't exist
NHSTUB(kbd_pwr_off,                         NULLSUB)
NHSTUB(kbd_pwr_on,                          NULLSUB)
NHSTUB(SetZoomActuatorSpeedPercent,         NULLSUB)

// temporary measure
NHSTUB(init_focus_eventflag,                0xffba5c18)
//NHSTUB(init_nd_eventflag,                   0xffba5da8)
//NHSTUB(init_nd_semaphore,                   0xffaff000)
NHSTUB(CreateBinarySemaphoreStrictly,0xff8266a0) // for av_override_semaphore

DEF(task_LiveImageTask,                     0xff914f9c)

IGNORE(MakeAFScan)  // Custom version in lib.c, ignore firmware version
