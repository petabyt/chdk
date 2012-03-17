#include "stubs_asm.h"
#define NULL_SUB 0xFF810B1C

// Override stubs_entry.S
NHSTUB(kbd_pwr_on,                      NULL_SUB)

// These don't exist
NHSTUB(SetZoomActuatorSpeedPercent,     NULL_SUB)

// Additional
NHSTUB(LockAndRefresh,                  0xFFA1ED98)
NHSTUB(MakeAFScan,                      0xFF970F5C)
NHSTUB(UnlockAndRefresh,                0xFFA1EDDC)

// Fixed errors in compiler
STUB(FFB5FA88)
STUB(FF813404)
STUB(FF810B20)
STUB(FF81A244)
STUB(FF815A94)
STUB(FF815B7C)
STUB(FF872F20)
