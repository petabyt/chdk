#include "stubs_asm.h"

NHSTUB(LockAndRefresh, 0xFF8B18F4)
NHSTUB(UnlockAndRefresh, 0xFF8B1958)

//All pointed to nullsub_20 (NULL)

NHSTUB(kbd_pwr_on, 0xFF907390)
NHSTUB(SetZoomActuatorSpeedPercent, 0xFF907390)

IGNORE(MakeAFScan)  // Custom version in lib.c, ignore firmware version
