#include "stubs_asm.h"
#define NULL_SUB 0xff810b64

// Override stubs_entry.S
NHSTUB(MakeDirectory_Fut,                   0xff8176e0) //mkdir. This requires #define MKDIR_RETURN_ONE_ON_SUCCESS
NHSTUB(WriteSDCard,                         0xff86e074)
NHSTUB(MakeSDCardBootable,                  0xff820718)
NHSTUB(GetFocusLensSubjectDistanceFromLens, 0xff983bfc)
NHSTUB(DeleteFile_Fut,                      0xff816bd0)
NHSTUB(CancelHPTimer,                       0xff8877b8)
NHSTUB(SetHPTimerAfterNow,                  0xff8876b0)

// Additional
NHSTUB(TurnOffE1,                           0xff8269e0) // for shutdown(), to complicated to emulate
DEF(task_DvlpSeqTask,                       0xff99581c)

// Not needed
NHSTUB(RefreshPhysicalScreen,       NULL_SUB)

// These don't exist
NHSTUB(kbd_pwr_off,                 NULL_SUB)
NHSTUB(kbd_pwr_on,                  NULL_SUB)
NHSTUB(SetZoomActuatorSpeedPercent, NULL_SUB)

//TODO
NHSTUB(UnsetZoomForMovie,           NULL_SUB)

