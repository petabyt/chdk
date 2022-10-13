#include "stubs_asm.h"
#define NULLSUB 0xFF829FC8  //*

// Override stubs_entry.S
NHSTUB(CreateTask_low,                      0x006B15A0) //*
DEF(hook_CreateTask_low,                    0x006B15A0) //*
NHSTUB(exmem_alloc                         ,0xFF8345B8) //*
//NHSTUB(exmem_free                          ,0xff834610) //*
NHSTUB(exmem_ualloc                        ,0xFF8344E0) //*
NHSTUB(exmem_ufree                         ,0xFF834578) //*
NHSTUB(open                                ,0xFF823DAC) //*
NHSTUB(close                               ,0xFF823E5C) //*
NHSTUB(MakeDirectory_Fut,                   0xFF827984) //*


// Additional
NHSTUB(TurnOffE1,                           0xFF83778C) //* for shutdown(), to complicated to emulate 
//NHSTUB(LogCameraEvent,                      0xff8356e8) // Testing, from csv

// Not needed
NHSTUB(RefreshPhysicalScreen,               NULLSUB)

// These don't exist
NHSTUB(kbd_pwr_off,                         NULLSUB)
NHSTUB(kbd_pwr_on,                          NULLSUB)
NHSTUB(SetZoomActuatorSpeedPercent,         NULLSUB)
NHSTUB(TurnOffBackLight,                    NULLSUB) 
NHSTUB(TurnOnBackLight,                     NULLSUB)

// temporary measure
NHSTUB(init_focus_eventflag,                0xFFBA8CF0) //*
NHSTUB(init_nd_eventflag,                   0xFFAC8148) //*
NHSTUB(init_nd_semaphore,                   0xFFAF697C) //*

