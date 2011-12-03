#include "stubs_asm.h"

# Addresses for firmware task handlers (used in taskHook)


# Addresses for firmware functions
NHSTUB(closefastdir,0xffaca118)
NHSTUB(kbd_pwr_on,0xff865570)


////All pointed to NULL -> changed to call a "BX LR" instruction
NHSTUB(SetZoomActuatorSpeedPercent, 0xFF841798)
