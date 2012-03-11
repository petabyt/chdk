#include "stubs_asm.h"

// Misc stuff
DEF(ctypes, 0xffe70516)

NHSTUB(ScreenLock,0xFFD6BDDC)
NHSTUB(ScreenUnlock,0xFFD6BE30)
NHSTUB(SleepTask,0xffc16b1c) //101

NHSTUB(RefreshPhysicalScreen                 ,0xffd6be30) //104       
NHSTUB(kbd_pwr_off                           ,0xffc30bd4) //  2 64%    
NHSTUB(kbd_pwr_on                            ,0xffc30b94) //  2 82%    
NHSTUB(GetKbdState                             ,0xffc30b60) //109




// FFDECE54 SetZoomActuatorSpeedPPS
NHSTUB(SetZoomActuatorSpeedPercent, 0xFFDECE54)


