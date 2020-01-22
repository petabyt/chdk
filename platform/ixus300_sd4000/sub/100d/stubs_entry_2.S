#include "stubs_asm.h"
#define NULL_SUB 0xFF810B1C

// These don't exist
NHSTUB(SetZoomActuatorSpeedPercent, NULL_SUB)
NHSTUB(UnsetZoomForMovie,           NULL_SUB)

// Additional
NHSTUB(GetLogToFile,                0xFF975780)
NHSTUB(LockAndRefresh,              0xFFA13354)
NHSTUB(LogCameraEvent,                   0xFF88C920)
NHSTUB(PostLEDMessage,              0xFF860C6C)
NHSTUB(ScreenUnLock,                0xFFA12124)
NHSTUB(UnlockAndRefresh,            0xFFA13398)
NHSTUB(closefastdir,                0xFFA95C40)
NHSTUB(dumpMemoryToFile,            0xFF836004)
NHSTUB(get_ptp_handler,             0xFFA4EC7C)
NHSTUB(get_task_info,               0xFF813A38)
NHSTUB(get_task_lists,              0xFF83544C)
NHSTUB(remove_ptp_handler,          0xFFA4EBB0)
NHSTUB(taskResume,                  0xFF8955C4)
