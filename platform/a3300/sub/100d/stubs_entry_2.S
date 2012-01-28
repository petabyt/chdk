#include "stubs_asm.h"
#define NULL_SUB 0xFF810B24

// Not found
NHSTUB(kbd_pwr_off,					NULL_SUB)
NHSTUB(kbd_pwr_on,          		NULL_SUB)

// Override stubs_entry.S
NHSTUB(SetZoomActuatorSpeedPercent, 0xFFAA1D88)		//	a3300is
NHSTUB(MakeAFScan,					0xFF8DC610)  	//	a3300is
