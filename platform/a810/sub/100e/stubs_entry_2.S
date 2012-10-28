#include "stubs_asm.h"
#define NULL_SUB 0xFF810B4C

// Override stubs_entry.S
NSTUB(DeleteFile_Fut,               0xff82fa00)
NSTUB(PT_PlaySound,                 0xff87503c)
NHSTUB(Remove,                      0xff830248)
NHSTUB(kbd_pwr_off,                 NULL_SUB)
NHSTUB(kbd_pwr_on,                  NULL_SUB)
NHSTUB(MakeDirectory_Fut,           0xff8305a4)
NHSTUB(mkdir,                       0xff8305a4)
NHSTUB(reboot_fw_update,            0xffa59aa0)
 NSTUB(GetBatteryTemperature,       NULL_SUB)   // Does not work in A1200, SX130, A800 & A810 (included dummy in sub/100c/lib.c)

// Additional
NHSTUB(MakeAFScan,                   0xff95f260) //Obtained using chdk-pt comparing to 100d
//NHSTUB(MakeAFScan,                  0xff831a04) //This is address of DoAFLock
NHSTUB(LockAndRefresh,              0xff895b34)
NHSTUB(UnlockAndRefresh,            0xff895b98)
NHSTUB(platformsub_kbd_fetch_data,  0xff856648)

// These don't exist
NHSTUB(SetZoomActuatorSpeedPercent, NULL_SUB)
 NSTUB(srand,                       NULL_SUB)  //overridable function
 NSTUB(rand,                        NULL_SUB)  //overridable function
