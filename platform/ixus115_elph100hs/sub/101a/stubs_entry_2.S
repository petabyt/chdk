#include "stubs_asm.h"

NHSTUB(LockAndRefresh, 0xFF8B18F4)
NHSTUB(UnlockAndRefresh, 0xFF8B1958)

// pointed to nullsub_20

NHSTUB(SetZoomActuatorSpeedPercent, 0xFF907390)
NHSTUB(kbd_pwr_on, 0xFF907390)

IGNORE(MakeAFScan)  // Custom version in lib.c, ignore firmware version
