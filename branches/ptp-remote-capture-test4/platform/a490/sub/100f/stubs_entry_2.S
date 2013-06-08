#include "stubs_asm.h"
#define NULL_SUB 0xFFC00B20

// Override stubs_entry.S
NHSTUB(GetDrive_FreeClusters,       0xFFC5131C)
NHSTUB(kbd_pwr_on,                  NULL_SUB)

// These don't exist
NHSTUB(SetZoomActuatorSpeedPercent, NULL_SUB)

// Additional
NHSTUB(LockAndRefresh,              0xFFD7B04C)
NHSTUB(MakeAFScan,                  0xFFD0F178)
NHSTUB(TurnOffMic,                  0xFFC43C30) // Doesn't work
NHSTUB(TurnOnMic,                   0xFFC43C5C) // Doesn't work
NHSTUB(UnlockAndRefresh,            0xFFD7B090)
NHSTUB(closefastdir,                0xFFDE8CA0) // Same as closedir
NHSTUB(platformsub_kbd_fetch_data,  0xFFC435D4)
