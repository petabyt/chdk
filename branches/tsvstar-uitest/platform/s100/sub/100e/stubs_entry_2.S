#include "stubs_asm.h"
#define NULL_SUB 0xFF02D7E0

// Override stubs_entry.S
NHSTUB(kbd_pwr_off,                 NULL_SUB)
NHSTUB(kbd_pwr_on,                  NULL_SUB)

NHSTUB(SetZoomActuatorSpeedPercent, NULL_SUB)

