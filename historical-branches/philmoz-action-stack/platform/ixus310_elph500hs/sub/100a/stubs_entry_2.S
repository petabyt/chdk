#include "stubs_asm.h"
#define NULL_SUB 0xFF055974

// Override stubs_entry.S
NHSTUB(kbd_pwr_on,						NULL_SUB)

// These don´t exist/aren´t found in dryos
NHSTUB(SetZoomActuatorSpeedPercent,		NULL_SUB)

// Additional
NHSTUB(SetCDSGain,						0xFF384A38)
NHSTUB(GetCdsGainValue,					0xFF384998)

DEF(task_TouchPanel,					0xFF059E84)
