#include "stubs_asm.h"
#define NULL_SUB 0xFF810B4C

// Override stubs_entry.S
NSTUB(DeleteFile_Fut,               0xff82fa00)
NHSTUB(kbd_pwr_off,                 NULL_SUB)
NHSTUB(kbd_pwr_on,                  NULL_SUB)
NHSTUB(MakeDirectory_Fut,           0xff8305a4) // mkdir. Requires MKDIR_RETURN_ONE_ON_SUCCESS defined
 NSTUB(GetBatteryTemperature,       NULL_SUB)   // Does not work in A1200, SX130, A800 & A810 (included dummy in sub/100c/lib.c)

// Additional
NHSTUB(MakeAFScan,                   0xff95f0b0) //Obtained comparing code to a495 100f - Camera makes one AF, then crashes.
//NHSTUB(MakeAFScan,                  0xff831a04) //This is address of DoAFLock
NHSTUB(LockAndRefresh,              0xff895a28)
NHSTUB(UnlockAndRefresh,            0xff895a8c)
NHSTUB(platformsub_kbd_fetch_data,  0xff856648)

// These don't exist
NHSTUB(SetZoomActuatorSpeedPercent, NULL_SUB)
 NSTUB(srand,                       NULL_SUB)  //overridable function
 NSTUB(rand,                        NULL_SUB)  //overridable function
