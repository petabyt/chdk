#include "stubs_asm.h"

// BEWARE: thumb functions NEED the thumb bit in the below list

#define NULL_SUB 0xfc021059 // bx lr

//NHSTUB(CreateTaskStrictly                   ,0x010c5ae5) // 0xfc251c94 is the ARM veneer
NHSTUB(EnterToCompensationEVF                 ,0xfc20decb)
NHSTUB(ExitFromCompensationEVF                ,0xfc20df07)
NHSTUB(ExpCtrlTool_StartContiAE               ,0xfc204fab)
NHSTUB(ExpCtrlTool_StopContiAE                ,0xfc20508b)
NHSTUB(Feof_Fut                               ,0xfc28ff61)
NHSTUB(Fflush_Fut                             ,0xfc28ff89)
NHSTUB(GetDrive_TotalClusters                 ,0xfc2a4be3)
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xfc28c8d7)
NHSTUB(GetImageFolder                         ,0xfc25d561)
NHSTUB(MakeSDCardBootable                     ,0xfc2a4fe3)
NHSTUB(RefreshPhysicalScreen                  ,0xfc143599)
NHSTUB(RenameFile_Fut                         ,0xfc28fd11)
NHSTUB(Restart                                ,0xfc095c41)
NHSTUB(SetFileAttributes                      ,0xfc2a5395)
NHSTUB(SetFileTimeStamp                       ,0xfc2a534d)
NHSTUB(SetParameterData                       ,0xfc09089f)
NHSTUB(TurnOffBackLight                       ,0xfc0d2997)
NHSTUB(TurnOnBackLight                        ,0xfc0d2985)
NHSTUB(WriteSDCard                            ,0xfc19bb17)
NHSTUB(apex2us                                ,0xfc0a950f)
NHSTUB(err_init_task                          ,0xfc04f3b9)
NHSTUB(realloc                                ,0xfc42ae41)
NHSTUB(reboot_fw_update                       ,0xfc3352b1)
NHSTUB(CancelHPTimer                          ,0xfc1423c9)
NHSTUB(SetHPTimerAfterNow                     ,0xfc142331)

NHSTUB(SetEventFlag                           ,0x010c5569)
DEF(task_TricInitTask                         ,0xfc373dc1)

// These don't exist
NHSTUB(SetZoomActuatorSpeedPercent, NULL_SUB)
NHSTUB(UnsetZoomForMovie,           NULL_SUB)

