#include "stubs_asm.h"
#define NULL_SUB 0xFF810B24

// Override stubs_entry.S
NHSTUB(kbd_pwr_off,                 NULL_SUB)  //from a3300
NHSTUB(kbd_pwr_on,                  NULL_SUB)  //from a3300

// Additional
NHSTUB(SetZoomActuatorSpeedPercent, 0xFFAA164C ) //from a3200
NHSTUB(MakeAFScan,                  0xFF8DC52C)  //from a3200
