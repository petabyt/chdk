#include "stubs_asm.h"

#define NULLSUB 0xFF810B24

// Not found
//NHSTUB(kbd_pwr_off,				NULLSUB)
NHSTUB(kbd_pwr_on,          		NULLSUB)

// Override stubs_entry.S
NHSTUB(SetZoomActuatorSpeedPercent, 0xFFA9BB08)
NHSTUB(MakeAFScan,					0xFF8DA094)
NHSTUB(LockAndRefresh,				0xFF8A46A0)
NHSTUB(UnlockAndRefresh,			0xFF8A4704)
NHSTUB(platformsub_kbd_fetch_data,	0xFF8602B4)
NHSTUB(mkdir                       ,0xFF836708)

