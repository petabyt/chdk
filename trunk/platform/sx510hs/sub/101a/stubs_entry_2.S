#include "stubs_asm.h"
#define NULLSUB 0xff001948

// Override stubs_entry.S
NHSTUB(MakeDirectory_Fut,                   0xff007728) // mkdir. This requires #define MKDIR_RETURN_ONE_ON_SUCCESS
NHSTUB(DeleteFile_Fut,                      0xff006c18)
NHSTUB(apex2us,                             0xff2a7800)
NHSTUB(GetDrive_ClusterSize,                0xff010278)
NHSTUB(WriteSDCard,                         0xff06506c)
NHSTUB(ExpCtrlTool_StartContiAE,            0xff0254d4)
NHSTUB(ExpCtrlTool_StopContiAE,             0xff025648)
NHSTUB(time,                                0x006b9210) // ROM 0xff72146c
NHSTUB(MakeSDCardBootable,                  0xff010f3c)
NHSTUB(GetDrive_TotalClusters,              0xff010a64)
NHSTUB(GetDrive_FreeClusters,               0xff010a90)
NHSTUB(GetFocusLensSubjectDistanceFromLens, 0xff1c481c)
NHSTUB(DebugAssert,                         0x006b5a58)
NHSTUB(Restart,                             0xff01786c)

// Additional
// NHSTUB(LogPrintf,                        0xff015564) // camera log debugging
NHSTUB(TurnOffE1,                           0xff017610) // for shutdown(), to complicated to emulate


// Not needed
NHSTUB(RefreshPhysicalScreen,               NULLSUB)

// These don't exist
NHSTUB(kbd_pwr_off,                         NULLSUB)
NHSTUB(kbd_pwr_on,                          NULLSUB)
NHSTUB(SetZoomActuatorSpeedPercent,         NULLSUB)
