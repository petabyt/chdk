#include "stubs_asm.h"

// BEWARE: thumb functions NEED the thumb bit in the below list

#define NULL_SUB 0xe0020929 // bx lr

   DEF(orig_CreateTask                        ,0xdffc93bb)

NHSTUB(EnterToCompensationEVF                 ,NULL_SUB)
NHSTUB(ExitFromCompensationEVF                ,NULL_SUB)
NHSTUB(ExpCtrlTool_StartContiAE               ,NULL_SUB)
NHSTUB(ExpCtrlTool_StopContiAE                ,NULL_SUB)
NHSTUB(Feof_Fut                               ,NULL_SUB)
NHSTUB(Fflush_Fut                             ,NULL_SUB)
NHSTUB(GetDrive_TotalClusters                 ,NULL_SUB) // function immediately before GetDrive_FreeClusters in ROM
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,NULL_SUB)
NHSTUB(GetImageFolder                         ,NULL_SUB)
NHSTUB(MakeSDCardBootable                     ,NULL_SUB)
NHSTUB(RenameFile_Fut                         ,NULL_SUB)
NHSTUB(Restart                                ,NULL_SUB)
NHSTUB(SetFileTimeStamp                       ,NULL_SUB)
NHSTUB(SetParameterData                       ,NULL_SUB)
NHSTUB(TurnOffBackLight                       ,NULL_SUB)
NHSTUB(TurnOnBackLight                        ,NULL_SUB)
NHSTUB(apex2us                                ,NULL_SUB)
//NHSTUB(err_init_task                          ,NULL_SUB)
//NHSTUB(mkdir                                  ,NULL_SUB)
//NHSTUB(realloc                                ,NULL_SUB)
NHSTUB(reboot_fw_update                       ,NULL_SUB)
NHSTUB(CancelHPTimer                          ,NULL_SUB)

NHSTUB(VTMLock                                ,0xe03780be)  // OK
NHSTUB(VTMUnlock                              ,0xe03781d6)  // ??? VTMUnlock string not in FW

NHSTUB(get_dial_hw_position                   ,NULL_SUB)

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

NHSTUB(CreateTask_Alt                         ,0xdffc95d9)

// Incorrect by finsig - need to check

// Does not exist
NHSTUB(EngDrvRead                           ,NULL_SUB)             // EngDrvRead code merged into EngDrvRead_FW !!! TODO: enable use of EngDrvRead_FW in code

// Missed by finsig - need to check
   DEF(task_PhySw                           ,0xe005b319)
NHSTUB(_sqrt                                ,0xdffcf241)
NHSTUB(SetHPTimerAfterNow                   ,0xe03f4ac1)
NHSTUB(strcat                               ,0xe04968ad)
NHSTUB(strchr                               ,0xe045197e)
