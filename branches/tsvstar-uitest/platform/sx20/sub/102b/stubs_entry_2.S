#include "stubs_asm.h"
#define NULL_SUB 0xFF810B04

// Override stubs_entry.S
NHSTUB(DoAFLock,                    0xFF8796B4)
NHSTUB(TurnOffBackLight,            0xFF89B6A4)
NHSTUB(UIFS_WriteFirmInfoToFile,    0xDEADC0DE)
NHSTUB(UnlockAF,                    0xFF8796C4)
NHSTUB(VbattGet,                    0xff95d0c0)
NHSTUB(kbd_pwr_off,                 NULL_SUB)
NHSTUB(kbd_pwr_on,                  NULL_SUB)
NHSTUB(openfastdir,                 0xDEADC0DE)
NHSTUB(rename,                      0xDEADC0DE)

// These don't exist
NHSTUB(SetZoomActuatorSpeedPercent, NULL_SUB)

// Additional
NHSTUB(LockAndRefresh,              0xFFA048E8)
NHSTUB(UnlockAndRefresh,            0xFFA0498C)
NHSTUB(platformsub_kbd_fetch_data,  0xFF85F11C)
