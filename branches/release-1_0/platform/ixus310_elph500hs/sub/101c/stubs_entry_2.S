#include "stubs_asm.h"
#define NULL_SUB 0xFF055974

// Override stubs_entry.S
NHSTUB(SetFileAttributes,				NULL_SUB)
NHSTUB(kbd_pwr_on,						NULL_SUB)
NHSTUB(reboot_fw_update                ,0xff2e99cc)

// These don´t exist/aren´t found in dryos
NHSTUB(SetZoomActuatorSpeedPercent,		NULL_SUB)

// Additional
NHSTUB(SetCDSGain,						0xFF384A50)
NHSTUB(GetCdsGainValue,					0xFF3849B0)

DEF(task_TouchPanel,					0xFF059E84)
