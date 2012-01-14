#include "stubs_asm.h"
#define NULL_SUB 0xFF810B24

// Override stubs_entry.S

NHSTUB(kbd_pwr_off,					0xFF810B24)
NHSTUB(kbd_pwr_on,          		0xFF810B24)
NHSTUB(SetZoomActuatorSpeedPercent, 0xFF810B24)

// These don't exist/aren't found in dryos
NHSTUB(UnsetZoomForMovie,           0xff99dd04)  	// a3300is
NHSTUB(MakeAFScan,					0xFF190E5C)  	// a3300is
NHSTUB(SetFileAttributes,       	0xFF83C338) 	// a3300is
