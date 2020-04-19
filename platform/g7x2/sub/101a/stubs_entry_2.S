#include "stubs_asm.h"

// BEWARE: thumb functions NEED the thumb bit in the below list

#define NULL_SUB 0xe0020929 // bx lr

NHSTUB(EnterToCompensationEVF                 ,NULL_SUB)
NHSTUB(ExitFromCompensationEVF                ,NULL_SUB)
NHSTUB(ExpCtrlTool_StartContiAE               ,NULL_SUB)
NHSTUB(ExpCtrlTool_StopContiAE                ,NULL_SUB)
NHSTUB(Feof_Fut                               ,0xe03710c1)
NHSTUB(Fflush_Fut                             ,0xe03710eb)
NHSTUB(GetDrive_TotalClusters                 ,0xe0375125)  // function immediately before GetDrive_FreeClusters in ROM
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,NULL_SUB)
NHSTUB(GetImageFolder                         ,0xe0355015)
NHSTUB(MakeSDCardBootable                     ,NULL_SUB)
NHSTUB(RenameFile_Fut                         ,0xe0370e69)
NHSTUB(Restart                                ,NULL_SUB)
NHSTUB(SetFileTimeStamp                       ,0xe0374179)
NHSTUB(TurnOffBackLight                       ,NULL_SUB)
NHSTUB(TurnOnBackLight                        ,NULL_SUB)
NHSTUB(apex2us                                ,NULL_SUB)
//NHSTUB(err_init_task                          ,NULL_SUB)
//NHSTUB(mkdir                                  ,NULL_SUB)
//NHSTUB(realloc                                ,NULL_SUB)
NHSTUB(reboot_fw_update                       ,NULL_SUB)
NHSTUB(CancelHPTimer                          ,0xe03f4b5b)

NHSTUB(VTMLock                                ,0xe03780bf)  // OK
NHSTUB(VTMUnlock                              ,0xe03781d7)  // ??? VTMUnlock string not in FW

// gets raw address and other stuff for next shot, stores in structure pointed to by r1
// via sub_fc08ec20, sub_fc1e56a6 called from capt_seq_task. Calls sub_fc0d3b56 to get raw address
NHSTUB(captseq_raw_addr_init                  ,NULL_SUB)

// These don't exist
NHSTUB(PT_PlaySound                           ,NULL_SUB)
NHSTUB(ScreenLock                             ,NULL_SUB)
NHSTUB(ScreenUnlock                           ,NULL_SUB)
NHSTUB(SetFileAttributes                      ,NULL_SUB)
NHSTUB(SetZoomActuatorSpeedPercent            ,NULL_SUB)
NHSTUB(UnsetZoomForMovie                      ,NULL_SUB)
NHSTUB(WriteSDCard                            ,NULL_SUB)

// Incorrect by finsig - need to check

// Does not exist
NHSTUB(EngDrvRead                           ,NULL_SUB)             // EngDrvRead code merged into EngDrvRead_FW !!! TODO: enable use of EngDrvRead_FW in code

// Missed by finsig - need to check
NHSTUB(_sqrt                                ,0xdffcf241)
NHSTUB(SetHPTimerAfterNow                   ,0xe03f4ac1)
NHSTUB(strcat                               ,0xe04968ad)
NHSTUB(strchr                               ,0xe045197f)
