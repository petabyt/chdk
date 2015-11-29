#include "stubs_asm.h"
#define NULL_SUB 0xFF869B58

// Override stubs_entry.S
NHSTUB(kbd_pwr_off,                 0xFF85472C)

// These don't exist
NHSTUB(SetZoomActuatorSpeedPercent, NULL_SUB)

// Additional
//NHSTUB(GetLogToFile,                0xFFD1A618)
NHSTUB(MakeAFScan,                  0xFF930944)
//NHSTUB(closefastdir,                0xFFDF61C4)
//NHSTUB(readfastdir,                 0xFFDF6368)
NHSTUB(TurnOnMic,                   0xff854d68)
NHSTUB(TurnOffMic,                  0xff854d94)
