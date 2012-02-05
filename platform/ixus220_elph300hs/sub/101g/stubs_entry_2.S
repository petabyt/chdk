#include "stubs_asm.h"
#define NULL_SUB 0xFF841798

// Override stubs_entry.S
NHSTUB(SetFileAttributes,           NULL_SUB)
NHSTUB(kbd_pwr_on,                  NULL_SUB)

// These don't exist
NHSTUB(SetZoomActuatorSpeedPercent, NULL_SUB)

// Additional
