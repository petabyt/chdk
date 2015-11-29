#include "stubs_asm.h"
#define NULL_SUB 0xff8201e0

NHSTUB(MakeDirectory_Fut,0xff82760c) // mkdir, requires #define MKDIR_RETURN_ONE_ON_SUCCESS

NHSTUB(RefreshPhysicalScreen, NULL_SUB)
NHSTUB(SetZoomActuatorSpeedPercent, NULL_SUB)
NHSTUB(UnsetZoomForMovie, NULL_SUB)

// temporary measure
NHSTUB(init_focus_eventflag, 0xFFB59A7C)
NHSTUB(init_nd_eventflag, 0xFFA921D4)
NHSTUB(init_nd_semaphore, 0xFFABF2B0)

// debug stuff
NHSTUB(standard_assert_handler, 0xFF89480C)
NHSTUB(get_task_ID, 0x6B1B68) // returns ID
NHSTUB(get_taskinfo, 0x6B21AC) // void get_taskinfo(int ID, void *task_info_struct)
DEF(assert_handler, 0x1A6C)

DEF(hook_DebugAssert ,0x006b59c0)
