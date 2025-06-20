#include "stubs_asm.h"
#define NULL_SUB 0xFF810958

// Override stubs_entry.S
NSTUB(PutInNdFilter,                0xFFA0C4E0)
NSTUB(PutOutNdFilter,               0xFFA0C518)
NHSTUB(kbd_pwr_off,                 NULL_SUB)
NHSTUB(kbd_pwr_on,                  NULL_SUB)
NHSTUB(rename,                      0xFF825600)
NHSTUB(strcmp,                      0xFF81E7F4)
NHSTUB(write,                       0xff81a3d8)

// These don't exist
NHSTUB(SetZoomActuatorSpeedPercent, NULL_SUB)
NHSTUB(TurnOffMic,                  NULL_SUB)
NHSTUB(TurnOnMic,                   NULL_SUB)

// Additional
NHSTUB(MakeAFScan,                  0xFFA44960)
NHSTUB(PostLEDMessage,              0xFF848910)
NHSTUB(closefastdir,                0xffa2cc0c)
NHSTUB(ints_disable,                0xFF810578)
NHSTUB(ints_enable,                 0xFF8105A0)
