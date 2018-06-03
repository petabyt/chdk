#include "stubs_asm.h"
#define NULL_SUB 0xFF829478

NHSTUB(MakeDirectory_Fut,0xff8277a4) // mkdir, requires #define MKDIR_RETURN_ONE_ON_SUCCESS

NHSTUB(RefreshPhysicalScreen, NULL_SUB)
NHSTUB(SetZoomActuatorSpeedPercent, NULL_SUB)
NHSTUB(UnsetZoomForMovie, NULL_SUB)

NHSTUB(TurnOffE1, 0xFF836A38)

// temporary measure

NHSTUB(init_focus_eventflag,                0xFFB97BD8)
NHSTUB(init_nd_eventflag,                   0xFFAB76DC)
NHSTUB(init_nd_semaphore,                   0xFFAE6424)
// debug stuff
//NHSTUB(standard_assert_handler, 0xFF89480C)
//NHSTUB(get_task_ID, 0x6B1B68) // returns ID
//NHSTUB(get_taskinfo, 0x6B21AC) // void get_taskinfo(int ID, void *task_info_struct)
//DEF(assert_handler, 0x1A6C)

//DEF(hook_DebugAssert ,0x006b59c0)

NHSTUB(LogCameraEvent ,0xff834994)


NHSTUB(TurnOffBackLight, NULL_SUB)
NHSTUB(TurnOnBackLight, NULL_SUB)

NHSTUB(open,  0xFF823CB0)
NHSTUB(close, 0xFF823D60)

// 	 	srsa_4c recommendation 
//NHSTUB(TurnOnDisplay, 0xff859ef0) // "DispSwCon_TurnOnDisplay"
//NHSTUB(TurnOffDisplay, 0xff85a8b4) // "DispSwCon_TurnOffDisplay"
NHSTUB(TurnOnDisplay, 0xff859ef0) // "DispSwCon_TurnOnDisplay"
NHSTUB(TurnOffDisplay, 0xff85a8b4) // "DispSwCon_TurnOffDisplay"
