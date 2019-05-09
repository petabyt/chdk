#include "stubs_asm.h"
#define NULL_SUB 0xFF8117EC

// Override stubs_entry.S
NHSTUB(EnterToCompensationEVF,      NULL_SUB)
NHSTUB(ExitFromCompensationEVF,     NULL_SUB)
NHSTUB(GetDrive_FreeClusters,       0xFF867C04)
NHSTUB(MakeAFScan,                  NULL_SUB)
NHSTUB(free,                        0xFFB0B858)
NHSTUB(kbd_pwr_on,                  0xFF827E3C)
NHSTUB(kbd_pwr_off,                 0xFF827E7C)
NHSTUB(GetKbdState,                 0xFF827DF8)

// These don't exist
NHSTUB(SetZoomActuatorSpeedPercent, NULL_SUB)

// Additional
//NHSTUB(kbd_read_keys,               0xFF826D30)

NHSTUB(printf,                      0xFFB07970)
NHSTUB(taskNameToId,                0xFFB18DB0)
NHSTUB(GetVRAMHPixelsSize,0xFFAC8268) // by find_eventproc name @ 0xFFB28578
NHSTUB(GetVRAMVPixelsSize,0xFFAC8274) // by find_eventproc name @ 0xFFB28580
