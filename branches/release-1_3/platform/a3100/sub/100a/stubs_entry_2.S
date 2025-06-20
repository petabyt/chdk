#include "stubs_asm.h"
#define NULL_SUB 0xff869b0c

// Override stubs_entry.S
NHSTUB(kbd_pwr_off,                 NULL_SUB)

// These don't exist
NHSTUB(SetZoomActuatorSpeedPercent, NULL_SUB)

// Additional
//NHSTUB(GetLogToFile,                0xFFD1A618)
NHSTUB(MakeAFScan,                  0xff930894)
//NHSTUB(closefastdir,                0xFFDF61C4)
//NHSTUB(readfastdir,                 0xFFDF6368)
NHSTUB(TurnOnMic,                   0xff854d68)
NHSTUB(TurnOffMic,                  0xff854d94)
