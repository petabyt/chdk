#include "stubs_asm.h"
#define NULL_SUB 0xFF8117EC

// Override stubs_entry.S
NHSTUB(EnterToCompensationEVF,      NULL_SUB)
NHSTUB(ExitFromCompensationEVF,     NULL_SUB)
NHSTUB(GetDrive_FreeClusters,       0xFF868AD4)
NHSTUB(MakeAFScan,                  NULL_SUB)
NHSTUB(free,                        0xFFB1551C)
NHSTUB(kbd_pwr_off,                 0xFF827F94)
NHSTUB(kbd_pwr_on,                  0xFF827F54)
NHSTUB(GetKbdState,                 0xFF827F10)
// These don't exist
NHSTUB(SetZoomActuatorSpeedPercent, NULL_SUB)

// Additional
NHSTUB(calloc,                      0xFFB1472C)
//NHSTUB(kbd_read_keys,               0xFF826DB8)
NHSTUB(memmove,                     0xFFB0D584)
NHSTUB(realloc,                     0xFFB1475C)

NHSTUB(printf,                      0xFFB11634)
NHSTUB(taskNameToId,                0xFFB22A74)
NHSTUB(GetVRAMHPixelsSize,0xFFAD1778) // by find_eventproc name @ 0xFFB323AC
NHSTUB(GetVRAMVPixelsSize,0xFFAD1784) // by find_eventproc name @ 0xFFB323B4
