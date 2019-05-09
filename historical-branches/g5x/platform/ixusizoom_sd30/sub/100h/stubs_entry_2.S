#include "stubs_asm.h"
#define NULL_SUB 0xFF8118C0

// Override stubs_entry.S
NHSTUB(DisplayImagePhysicalScreen,  0xff9222e0)
NHSTUB(EnterToCompensationEVF,      0xff94ad48)
NHSTUB(ExitFromCompensationEVF,     0xff94ada8)
NHSTUB(free,                        0xffad39f4)
NHSTUB(kbd_pwr_off,                 0xFF828E84)
NHSTUB(kbd_pwr_on,                  0xFF828E44)
NHSTUB(kbd_read_keys_r2,            0xFF828950)
NHSTUB(GetKbdState,                 0xFF828E10)

NHSTUB(SetZoomActuatorSpeedPercent, 0xffa71640)
