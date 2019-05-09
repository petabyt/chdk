#include "stubs_asm.h"
#define NULL_SUB 0xffc00b28

// These don't exist
NHSTUB(GetBatteryTemperature,           NULL_SUB)   // Does not work in SX130 - A800 (included dummy in sub/100c/lib.c)
NHSTUB(kbd_pwr_on,                      NULL_SUB)   // endereço dummy com uma instrução bx lr (um ret, creio)
NHSTUB(srand,                           NULL_SUB)   // See #define CAM_MISSING_RAND in platform_camera.h
NHSTUB(rand,                            NULL_SUB)   // See #define CAM_MISSING_RAND in platform_camera.h
NHSTUB(SetZoomActuatorSpeedPercent,     NULL_SUB)

// Override stubs_entry.S
NHSTUB(MakeAFScan, 0xffd1b2e0)   
NHSTUB(TurnOnMic, 0xffc444ec)
NHSTUB(TurnOffMic, 0xffc44518)
