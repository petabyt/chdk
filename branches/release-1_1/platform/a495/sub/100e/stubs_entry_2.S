#include "stubs_asm.h"
#define NULL_SUB 0xffc00b20

// Override stubs_entry.S
NHSTUB(GetDrive_FreeClusters,       0xffc51320)
NHSTUB(SetScriptMode,               0xffc00f70)
NHSTUB(kbd_pwr_on,                  NULL_SUB)

// These don't exist/aren't found in dryos
NHSTUB(SetZoomActuatorSpeedPercent, NULL_SUB)

// Additional
NHSTUB(MakeAFScan,                  0xffd0f2ac)
NHSTUB(TurnOnMic,                   0xffc43c28)
NHSTUB(TurnOffMic,                  0xffc43c54)
NHSTUB(closefastdir,                0xffdebb00)
NHSTUB(platformsub_kbd_fetch_data,  0xffc435cc)
