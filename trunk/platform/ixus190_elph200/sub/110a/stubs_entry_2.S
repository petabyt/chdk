#include "stubs_asm.h"
#define NULLSUB 0xFF02A01C  //*

// Override stubs_entry.S
NHSTUB(CreateTask_low,                      0x006B15A0) //*loc_FF0251BC
DEF(hook_CreateTask_low,                    0x006B15A0) //*
NHSTUB(exmem_alloc                         ,0xFF0350B0) //*
NHSTUB(exmem_ualloc                        ,0xFF034FD8) //*
NHSTUB(exmem_ufree                         ,0xFF035070) //*
NHSTUB(open                                ,0xFF023DB0) //*
NHSTUB(close                               ,0xFF023E60) //*
NHSTUB(MakeDirectory_Fut,                   0xFF027988) //*


// Additional
NHSTUB(TurnOffE1,                           0xFF038284) //* for shutdown(), to complicated to emulate 

// Not needed
NHSTUB(RefreshPhysicalScreen,               NULLSUB)

// These don't exist
NHSTUB(kbd_pwr_off,                         NULLSUB)
NHSTUB(kbd_pwr_on,                          NULLSUB)
NHSTUB(SetZoomActuatorSpeedPercent,         NULLSUB)
NHSTUB(TurnOffBackLight,                    NULLSUB) 
NHSTUB(TurnOnBackLight,                     NULLSUB)

// temporary measure
NHSTUB(init_focus_eventflag,                0xFF4481D0) //*
NHSTUB(init_nd_eventflag,                   0xFF31E6E4) //*
NHSTUB(init_nd_semaphore,                   0xFF3594E8) //*

