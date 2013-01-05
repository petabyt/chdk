#include "stubs_asm.h"
#define NULL_SUB 0xFF810B24

// Override stubs_entry.S
NHSTUB(kbd_pwr_off,                 NULL_SUB)
NHSTUB(kbd_pwr_on,                  NULL_SUB)

// Additional
NHSTUB(SetZoomActuatorSpeedPercent, 0xFFAA164C) //from a3200 100d
NHSTUB(MakeAFScan,                  0xFF8DC52C) //from a3200 100d
NHSTUB(LockAndRefresh,              0xFF8A6B78) //from a3200 100d
NHSTUB(UnlockAndRefresh,            0xFF8A6BDC) //from a3200 100d
NHSTUB(platformsub_kbd_fetch_data,  0xFF860268) //from a3200 100d
