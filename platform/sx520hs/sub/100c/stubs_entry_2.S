#include "stubs_asm.h"
#define NULLSUB 0xff05ad58

// Override stubs_entry.S
NHSTUB(DeleteFile_Fut                       ,0xff026928) //  1 90%    *** != 0xff006c18
NHSTUB(GetFocusLensSubjectDistanceFromLens  ,0xff203998) //  3 90%    *** != 0xff1c481c
NHSTUB(MakeDirectory_Fut                    ,0xff027438) //0xff007728 0xff027438 used from mkdir NHSTUB
NHSTUB(RefreshPhysicalScreen                ,NULLSUB)    //--- ---    *** != 0x00000000
NHSTUB(WriteSDCard                          ,0x6ba7ec)

// Additional
NHSTUB(TurnOffE1,NULLSUB)
NHSTUB(SetZoomActuatorSpeedPercent,NULLSUB)
NHSTUB(init_focus_eventflag, 0xff4d70f0)


// Not needed



// These don't exist

