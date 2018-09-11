#include "stubs_asm.h"
#define NULLSUB 0xFF83483C  //blackhole

// Override stubs_entry.S
NHSTUB(MakeDirectory_Fut,                   0xFF827FB4) // mkdir. This requires #define MKDIR_RETURN_ONE_ON_SUCCESS blackhole
NHSTUB(CreateTask_low,                      0x006B15A4)
DEF(hook_CreateTask_low,                    0x006B15A4)

// Additional
NHSTUB(TurnOffE1,                           0xFF838618) // for shutdown(), to complicated to emulate  blackhole

// Not needed
NHSTUB(RefreshPhysicalScreen,               NULLSUB)

// These don't exist
NHSTUB(kbd_pwr_off,                         NULLSUB)
NHSTUB(kbd_pwr_on,                          NULLSUB)
NHSTUB(SetZoomActuatorSpeedPercent,         NULLSUB)

// temporary measure
NHSTUB(init_focus_eventflag,                0xFFBAAC74) //blackhole
NHSTUB(init_nd_eventflag,                   0xFFAC8214) //blackhole
NHSTUB(init_nd_semaphore,                   0xFFB042F0) //blackhole
NHSTUB(CreateBinarySemaphoreStrictly,0xff8266a4) // for av_override_semaphore

DEF(task_LiveImageTask, 0xFF915268)

IGNORE(MakeAFScan)  // Custom version in lib.c, ignore firmware version
