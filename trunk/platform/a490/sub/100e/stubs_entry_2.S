#include "stubs_asm.h"

NHSTUB(MakeAFScan, 0xFFD0F178)					// Ok
NHSTUB(UnlockAndRefresh, 0xFFD7B090)			// "Window.c"
NHSTUB(LockAndRefresh, 0xFFD7B04C)				// "Window.c"
NHSTUB(TurnOffMic, 0xFFC43C30)					// Doesn't work
NHSTUB(TurnOnMic, 0xFFC43C5C)					// Doesn't work
NHSTUB(SetZoomActuatorSpeedPercent, 0xFFC00B20)		// nullsub_1
NHSTUB(kbd_pwr_on, 0xFFC00B20)
NHSTUB(kbd_pwr_off, 0xFFC00B20)
