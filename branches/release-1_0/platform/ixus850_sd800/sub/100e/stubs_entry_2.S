#include "stubs_asm.h"
#define NULL_SUB 0xFF8117E8

// Override stubs_entry.S
NHSTUB(AllocateMemory,              0xFF81AD84)
NHSTUB(ExitFromCompensationEVF,     0xFF99552C)
NHSTUB(FreeMemory,                  0xFF81AD70)
NHSTUB(GetDrive_ClusterSize,        0xFF879BF8)
NHSTUB(GetDrive_FreeClusters,       0xFF879C70)
NHSTUB(UnlockAF,                    0xff995364)
NHSTUB(WriteSDCard,                 0xFF8896FC)
NHSTUB(free,                        0xFFB617C0)
NHSTUB(kbd_pwr_off,                 0xFF82930C)
NHSTUB(kbd_pwr_on,                  0xFF8292CC)

// Additional
NHSTUB(ExpCtrlTool_StartContiAE,    0xFF926EE0)
NHSTUB(ExpCtrlTool_StopContiAE,     0xFF926F10)
NHSTUB(MFOff,                       0xFF9961C8)
NHSTUB(MFOn,                        0xFF996198)
NHSTUB(Rename,                      0xFF87A4CC)
NHSTUB(SetScriptMode,               0xFF9ABC48)
NHSTUB(SetZoomActuatorSpeedPercent, 0xFF8E68F4)
