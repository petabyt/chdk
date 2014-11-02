#include "stubs_asm.h"
#define NULLSUB 0xFF04C054

// Override stubs_entry.S
NHSTUB(DeleteFile_Fut,                      0xff020a70)
NHSTUB(MakeDirectory_Fut,                   0xff021580) // mkdir. This requires #define MKDIR_RETURN_ONE_ON_SUCCESS
NHSTUB(LEDDrive,                            0xff04bcf0)     //Untested!!

// Additional
NHSTUB(TurnOffE1,                           0xff0259dc) // for shutdown(), to complicated to emulate
NHSTUB(GPS_UpdateData,                      0xff11ca18) //Untested!!


// Not needed
NHSTUB(RefreshPhysicalScreen,               NULLSUB)

// These don't exist
NHSTUB(kbd_pwr_off,                         NULLSUB)
NHSTUB(kbd_pwr_on,                          NULLSUB)
NHSTUB(SetZoomActuatorSpeedPercent,         NULLSUB)
