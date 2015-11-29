#include "stubs_asm.h"
#define NULL_SUB 0xFF8117EC

// Override stubs_entry.S
NHSTUB(EnterToCompensationEVF,      0xff978b78)
NHSTUB(ExitFromCompensationEVF,     0xff978bd8)
NHSTUB(MakeAFScan,                  NULL_SUB)
NHSTUB(UnsetZoomForMovie,           NULL_SUB)
NHSTUB(WriteSDCard,                 0xFF87FFF8)
NHSTUB(free,                        0xFFB571E4)
NHSTUB(kbd_read_keys_r2,            0xFF827BC0)

// Additional
NHSTUB(SetZoomActuatorSpeedPercent, 0xFFAE83F8)
NHSTUB(UniqueLedOff,                0xFF82DCA0)
NHSTUB(UniqueLedOn,                 0xFF82DC3C)
NHSTUB(platformsub_kbd_fetch_data,  0xFF8281C4)
NHSTUB(GetVRAMHPixelsSize,0xFFB112AC) // by find_eventproc name @ 0xFFB74984
NHSTUB(GetVRAMVPixelsSize,0xFFB112B8) // by find_eventproc name @ 0xFFB7498C

// New finsig_vxworks differences?
NHSTUB(kbd_pwr_off, 0xff829214)
