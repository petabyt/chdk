#include "stubs_asm.h"
#define NULLSUB 0xFF029558  //*

// Override stubs_entry.S
NHSTUB(MakeDirectory_Fut,               0xFF0277AC) //*
NHSTUB(open,0xFF023CB8) //*
NHSTUB(close,0xFF023D68) //*


// Additional
NHSTUB(TurnOffE1,                        0xFF037C18) //*for shutdown(), to complicated to emulate 

// Not needed
NHSTUB(RefreshPhysicalScreen,               NULLSUB)

// These don't exist
NHSTUB(kbd_pwr_off,                         NULLSUB)
NHSTUB(kbd_pwr_on,                          NULLSUB)
NHSTUB(SetZoomActuatorSpeedPercent,         NULLSUB)

NHSTUB(TurnOffBackLight, NULLSUB)
NHSTUB(TurnOnBackLight, NULLSUB)

// temporary measure
NHSTUB(init_focus_eventflag,                0xFF4F1B98) //*
NHSTUB(init_nd_eventflag,                   0xFF387070) //*
NHSTUB(init_nd_semaphore,                   0xFF3D7268) //*


