#include "stubs_asm.h"
#define NULL_SUB 0xFF810B1C

// Override stubs_entry.S
NSTUB(GetBatteryTemperature,        NULL_SUB)
NHSTUB(kbd_pwr_off,                 NULL_SUB)
NHSTUB(kbd_pwr_on,                  NULL_SUB)

// These don't exist/aren't found in dryos
NHSTUB(SetZoomActuatorSpeedPercent, NULL_SUB)

// Additional
NHSTUB(LockAndRefresh,              0xFF8A8DB4)
NHSTUB(UnlockAndRefresh,            0xFF8A8D90)
NHSTUB(closefastdir,                0xFFA8C2E4)
