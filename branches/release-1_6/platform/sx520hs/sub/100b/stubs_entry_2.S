#include "stubs_asm.h"
#define NULLSUB 0xff05ad58

// Override stubs_entry.S
NHSTUB(DeleteFile_Fut                       ,0xff026928)
NHSTUB(GetFocusLensSubjectDistanceFromLens  ,0xff203974)
NHSTUB(MakeDirectory_Fut                    ,0xff027438)
NHSTUB(RefreshPhysicalScreen                ,NULLSUB)

// Additional
NHSTUB(TurnOffE1,NULLSUB)
NHSTUB(SetZoomActuatorSpeedPercent,NULLSUB)
NHSTUB(init_focus_eventflag, 0xff4d70cc)

DEF(task_LiveImageTask, 0xff134978)

// Not needed



// These don't exist

