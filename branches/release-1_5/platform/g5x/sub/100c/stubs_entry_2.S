#include "stubs_asm.h"

// BEWARE: thumb functions NEED the thumb bit in the below list

#define NULL_SUB 0xFC066A49 // bx lr

NHSTUB(EnterToCompensationEVF                 ,0xFC2D38E5)
NHSTUB(ExitFromCompensationEVF                ,0xFC2D3927)
NHSTUB(ExpCtrlTool_StartContiAE               ,0xFC2CDB5B)
NHSTUB(ExpCtrlTool_StopContiAE                ,0xFC2CDD4D)
NHSTUB(Feof_Fut                               ,0xFC3B8FA1)
NHSTUB(Fflush_Fut                             ,0xFC3B8FC9)
NHSTUB(GetDrive_TotalClusters                 ,0xFC3B7353) // function immediately before GetDrive_FreeClusters in ROM
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xFC3BA1E7)
NHSTUB(GetImageFolder                         ,0xfc39d619)
NHSTUB(MakeSDCardBootable                     ,0xFC3B6873)
NHSTUB(RenameFile_Fut                         ,0xFC3B8D51)
NHSTUB(SetFileTimeStamp                       ,0xFC3B5ECB)
NHSTUB(TurnOffBackLight                       ,0xFC15BB35)  // Does not do anything?
NHSTUB(TurnOnBackLight                        ,0xFC15BB31)  // Does not do anything?
NHSTUB(apex2us                                ,0xfc25f5cb)
NHSTUB(err_init_task                          ,0xFC06647B)
NHSTUB(mkdir                                  ,0xFC3B5F83)
NHSTUB(realloc                                ,0xFC5E5321)
NHSTUB(reboot_fw_update                       ,0xFC28B97D)
NHSTUB(CancelHPTimer                          ,0xFC165D89)

NHSTUB(VTMLock                                ,0xFC3BE383)
NHSTUB(VTMUnlock                              ,0xFC3BE5AB)

NHSTUB(GetActiveViewportBuffer                ,0xfc108e67)

NHSTUB(displayblankscreen,                     0xFC3532CF)
NHSTUB(undisplayblankscreen,                   0xFC35336D)

// Does not work - use workaround in lib.c
IGNORE(Restart)
//NHSTUB(Restart                                ,0xFC0C306F)

// Ignore event proc versions, use inner functions from wrapper
IGNORE(PutInNdFilter)
IGNORE(PutOutNdFilter)
IGNORE(MoveFocusLensToDistance)
NHSTUB(PutInNdFilter_FW                       ,0xfc1ca7fb)
NHSTUB(PutOutNdFilter_FW                      ,0xfc1ca825)
NHSTUB(MoveFocusLensToDistance_FW             ,0xfc667c0f)

//// required because DryOS >=54 functions assert on unitialized event flag, sem etc
//// see https://chdk.setepontos.com/index.php?topic=12516.0
//NHSTUB(init_focus_eventflag                   ,0xfc667e0b) // InitializeAdjustmentSystem->fc662948->fc667e0a event flag matches MoveFocusLensToDistance
//NHSTUB(init_nd_eventflag                      ,0xfc667f1d) // InitializeAdjustmentSystem->fc662948->fc667f1c event flag matches PutInNdFilter
NHSTUB(CreateBinarySemaphoreStrictly          ,0xbfe15557)

// gets raw address and other stuff for next shot, stores in structure pointed to by r1
// via sub_fc08ec20, sub_fc1e56a6 called from capt_seq_task. Calls sub_fc0d3b56 to get raw address
NHSTUB(captseq_raw_addr_init                  ,0xfc09bf49)

// These don't exist
NHSTUB(PT_PlaySound                           ,NULL_SUB)
NHSTUB(ScreenLock                             ,NULL_SUB)
NHSTUB(ScreenUnlock                           ,NULL_SUB)
NHSTUB(SetFileAttributes                      ,NULL_SUB)
NHSTUB(SetZoomActuatorSpeedPercent            ,NULL_SUB)
NHSTUB(UnsetZoomForMovie                      ,NULL_SUB)
NHSTUB(WriteSDCard                            ,NULL_SUB)
