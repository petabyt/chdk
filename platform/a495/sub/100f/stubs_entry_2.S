#include "stubs_asm.h"
#define NULL_SUB 0xFFC00B20

// Override stubs_entry.S
NHSTUB(GetDrive_FreeClusters,       0xFFC51320)
NHSTUB(GetImageFolder,              0xffcf1428) // function before 'GetCameraObjectTmpPath ERROR' string
NHSTUB(SetScriptMode,               0xFFC00F70)
NHSTUB(kbd_pwr_on,                  NULL_SUB)

// These don't exist
NHSTUB(SetZoomActuatorSpeedPercent, NULL_SUB)

// Additional
NHSTUB(LockAndRefresh,              0xFFD7C5A8)
NHSTUB(MakeAFScan,                  0xFFD0F2AC)
NHSTUB(TurnOffMic,                  0xFFC43C28) // Doesn't work
NHSTUB(TurnOnMic,                   0xFFC43C54) // Doesn't work
NHSTUB(UnlockAndRefresh,            0xFFD7C5EC)
NHSTUB(closefastdir,                0xFFDEBA54)
NHSTUB(platformsub_kbd_fetch_data,  0xFFC435CC)
