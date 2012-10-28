#include "stubs_asm.h"
#define NULL_SUB 0xFF810B4C

// Override stubs_entry.S
NHSTUB(DeleteFile_Fut,              0xff830e64)
NHSTUB(PT_PlaySound,                0xff878b24)
NHSTUB(reboot_fw_update,            0xffa6f854)
NHSTUB(kbd_pwr_off,                 NULL_SUB)
NHSTUB(kbd_pwr_on,                  NULL_SUB)
NHSTUB(MakeDirectory_Fut,           0xff831974)

// Additional
NHSTUB(LockAndRefresh,              0xff899d20)
NHSTUB(UnlockAndRefresh,            0xff899d84)

// These don't exist
NHSTUB(SetZoomActuatorSpeedPercent, NULL_SUB)
 NSTUB(srand,                       NULL_SUB)  //overridable function
 NSTUB(rand,                        NULL_SUB)  //overridable function
