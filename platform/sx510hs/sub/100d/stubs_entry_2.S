#include "stubs_asm.h"
#define NULLSUB 0xff001948

// Override stubs_entry.S
NHSTUB(MakeDirectory_Fut,                   0xff007728) // mkdir. This requires #define MKDIR_RETURN_ONE_ON_SUCCESS
NHSTUB(DeleteFile_Fut,                      0xff006c18)
NHSTUB(WriteSDCard,                         0xff06506c)
NHSTUB(MakeSDCardBootable,                  0xff010f3c)
NHSTUB(GetFocusLensSubjectDistanceFromLens, 0xff1c481c)
NHSTUB(DebugAssert,                         0x006b5a58)
NHSTUB(Restart,                             0xff01786c)

// Additional
// NHSTUB(LogCameraEvent,                        0xff015564) // camera log debugging
NHSTUB(TurnOffE1,                           0xff017610) // for shutdown(), to complicated to emulate


// Not needed
NHSTUB(RefreshPhysicalScreen,               NULLSUB)

// These don't exist
NHSTUB(kbd_pwr_off,                         NULLSUB)
NHSTUB(kbd_pwr_on,                          NULLSUB)
NHSTUB(SetZoomActuatorSpeedPercent,         NULLSUB)
