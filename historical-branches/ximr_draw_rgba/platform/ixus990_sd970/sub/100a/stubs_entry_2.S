#include "stubs_asm.h"
#define NULL_SUB 0xff8B374C

// These don't exist or were not found
NHSTUB(SetZoomActuatorSpeedPercent, NULL_SUB) //sd780 didn't exist
NHSTUB(drvInfo,                     NULL_SUB) //sd780 0xff81e33c

// Additional
NHSTUB(EdidDump,                    0xff8429b4)
NHSTUB(GetCurrentTargetDistance,    0xff918d48)
NHSTUB(HdmiRegDump,                 0xff842a7c)
NHSTUB(MakeAFScan,                  0xff85ca6c)
NHSTUB(MoveIrisFullClose,           0xffab4db4)
NHSTUB(OpLog_Get,                   0xff86df5c)
NHSTUB(ScreenLock,                  0xff9b7d74)
NHSTUB(ShowAllTaskInfo,             0xff9224d4)
NHSTUB(blah,                        0xff8476a8)
NHSTUB(open2,                       0xff823c70)
NHSTUB(qprintf,                     0xff8115a8)
NHSTUB(stdioSetup,                  0xff813578)
