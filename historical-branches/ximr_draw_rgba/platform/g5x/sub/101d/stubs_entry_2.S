#include "stubs_asm.h"

// BEWARE: thumb functions NEED the thumb bit in the below list

#define NULL_SUB 0xFC066A49 // bx lr

NHSTUB(GetImageFolder                         ,0xfc39d67d)
NHSTUB(RenameFile_Fut                         ,0xfc3b8db5)
NHSTUB(SetFileTimeStamp                       ,0xfc3b5f2f)
NHSTUB(TurnOffBackLight                       ,0xFC15BB35)  // Does not do anything?
NHSTUB(TurnOnBackLight                        ,0xFC15BB31)  // Does not do anything?
NHSTUB(mkdir                                  ,0xfc3b5fe7)
NHSTUB(realloc                                ,0xfc5e5385)
NHSTUB(reboot_fw_update                       ,0xfc28b9a5)

NHSTUB(VTMLock                                ,0xfc3be3e7)
NHSTUB(VTMUnlock                              ,0xfc3be60f)

NHSTUB(GetActiveViewportBuffer                ,0xfc108e67)

NHSTUB(displayblankscreen,                     0xFC35330F)
NHSTUB(undisplayblankscreen,                   0xFC3533AD)

// Does not work - use workaround in lib.c
IGNORE(Restart)
//NHSTUB(Restart                                ,0xFC0C306F)

// Ignore event proc versions, use inner functions from wrapper
IGNORE(PutInNdFilter)
IGNORE(PutOutNdFilter)
IGNORE(MoveFocusLensToDistance)
NHSTUB(PutInNdFilter_FW                       ,0xfc1ca823)
NHSTUB(PutOutNdFilter_FW                      ,0xfc1ca84d)
NHSTUB(MoveFocusLensToDistance_FW             ,0xfc667c73)

//// required because DryOS >=54 functions assert on unitialized event flag, sem etc
//// see https://chdk.setepontos.com/index.php?topic=12516.0
//NHSTUB(init_focus_eventflag                   ,0xfc667e5f) // InitializeAdjustmentSystem->fc662948->fc667e0a event flag matches MoveFocusLensToDistance
//NHSTUB(init_nd_eventflag                      ,0xfc667f71) // InitializeAdjustmentSystem->fc662948->fc667f1c event flag matches PutInNdFilter
NHSTUB(CreateBinarySemaphoreStrictly          ,0xbfe15557)

// gets raw address and other stuff for next shot, stores in structure pointed to by r1
// via sub_fc08ec20, sub_fc1e56a6 called from capt_seq_task. Calls sub_fc0d3b56 to get raw address
NHSTUB(captseq_raw_addr_init                  ,0xfc09bf49)

// These don't exist
NHSTUB(ScreenLock                             ,NULL_SUB)
NHSTUB(ScreenUnlock                           ,NULL_SUB)
NHSTUB(SetFileAttributes                      ,NULL_SUB)
NHSTUB(SetZoomActuatorSpeedPercent            ,NULL_SUB)
NHSTUB(UnsetZoomForMovie                      ,NULL_SUB)
NHSTUB(WriteSDCard                            ,NULL_SUB)
