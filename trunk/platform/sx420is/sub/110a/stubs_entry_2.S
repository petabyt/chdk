#include "stubs_asm.h"
#define NULLSUB 0xFF029558  // reyalp - unchanged from 100a

// Override stubs_entry.S
NHSTUB(MakeDirectory_Fut,                   0xFF0277AC) // reyalp - unchanged from 100a
NHSTUB(open,0xFF023CB8) // reyalp - unchanged from 100a
NHSTUB(close,0xFF023D68) // reyalp - unchanged from 100a


// Additional
NHSTUB(TurnOffE1,                           0xFF0377E4) // reyalp - unchanged from 100a

// Not needed
NHSTUB(RefreshPhysicalScreen,               NULLSUB)

// These don't exist
NHSTUB(kbd_pwr_off,                         NULLSUB)
NHSTUB(kbd_pwr_on,                          NULLSUB)
NHSTUB(SetZoomActuatorSpeedPercent,         NULLSUB)

NHSTUB(TurnOffBackLight, NULLSUB)
NHSTUB(TurnOnBackLight, NULLSUB)

// temporary measure
NHSTUB(init_focus_eventflag,                0xff468ee0) // reyalp - ghidra implied
NHSTUB(init_nd_eventflag,                   0xff3353a8) // reyalp - ghidra implied
NHSTUB(init_nd_semaphore,                   0xff371c4c) // reyalp - ghidra exact mni, implied
NHSTUB(CreateBinarySemaphoreStrictly,0x006b7d0c) // for av_override_semaphore (unchanged form 100a)
