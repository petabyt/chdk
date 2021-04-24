#include "stubs_asm.h"

// BEWARE: thumb functions NEED the thumb bit in the below list

#define NULL_SUB 0xFC066A49 // bx lr

NHSTUB(EnterToCompensationEVF                 ,0xfc2d390d)
NHSTUB(ExitFromCompensationEVF                ,0xfc2d394f)
NHSTUB(ExpCtrlTool_StartContiAE               ,0xfc2cdb83)
NHSTUB(ExpCtrlTool_StopContiAE                ,0xfc2cdd75)
NHSTUB(Feof_Fut                               ,0xfc3b9005)
NHSTUB(Fflush_Fut                             ,0xfc3b902d)
NHSTUB(GetDrive_TotalClusters                 ,0xfc3b73b7) // function immediately before GetDrive_FreeClusters in ROM
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xfc3ba24b)
NHSTUB(GetImageFolder                         ,0xfc39d67d)
NHSTUB(MakeSDCardBootable                     ,0xfc3b68d7)
NHSTUB(RenameFile_Fut                         ,0xfc3b8db5)
NHSTUB(SetFileTimeStamp                       ,0xfc3b5f2f)
NHSTUB(TurnOffBackLight                       ,0xFC15BB35)  // Does not do anything?
NHSTUB(TurnOnBackLight                        ,0xFC15BB31)  // Does not do anything?
NHSTUB(apex2us                                ,0xfc25f5f3)
NHSTUB(err_init_task                          ,0xFC06647B)
NHSTUB(mkdir                                  ,0xfc3b5fe7)
NHSTUB(realloc                                ,0xfc5e5385)
NHSTUB(reboot_fw_update                       ,0xfc28b9a5)
NHSTUB(CancelHPTimer                          ,0xFC165D89)

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

// gets raw address and other stuff for next shot, stores in structure pointed to by r1
// via sub_fc08ec20, sub_fc1e56a6 called from capt_seq_task. Calls sub_fc0d3b56 to get raw address
NHSTUB(captseq_raw_addr_init                  ,0xfc09bf49)

   DEF(hook_dry_memcpy                        ,0x010f4bf0)  // ARM address of RAM dry_memcpy function for patching
   DEF(canon_ui_update_ret_adr                ,0xfc237ab5)  // Thumb address to check against LR register to detect dry_memcpy call from Canon UI update

// These don't exist
NHSTUB(PT_PlaySound                           ,NULL_SUB)
NHSTUB(ScreenLock                             ,NULL_SUB)
NHSTUB(ScreenUnlock                           ,NULL_SUB)
NHSTUB(SetFileAttributes                      ,NULL_SUB)
NHSTUB(SetZoomActuatorSpeedPercent            ,NULL_SUB)
NHSTUB(UnsetZoomForMovie                      ,NULL_SUB)
NHSTUB(WriteSDCard                            ,NULL_SUB)
