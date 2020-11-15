#include "stubs_asm.h"

// BEWARE: thumb functions NEED the thumb bit in the below list

#define NULL_SUB 0xfc021059 // bx lr

//NHSTUB(CreateTaskStrictly                   ,0x010c5ae5) // 0xfc251c0c is the ARM veneer
NHSTUB(EnterToCompensationEVF                 ,0xfc20deb7)
NHSTUB(ExitFromCompensationEVF                ,0xfc20def3)
NHSTUB(ExpCtrlTool_StartContiAE               ,0xfc204f97)
NHSTUB(ExpCtrlTool_StopContiAE                ,0xfc205077)
NHSTUB(Feof_Fut                               ,0xfc28fef1)
NHSTUB(Fflush_Fut                             ,0xfc28ff19)
NHSTUB(GetDrive_TotalClusters                 ,0xfc2a4b67)
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xfc28c84f)
NHSTUB(GetImageFolder                         ,0xfc25d4d9)
NHSTUB(MakeSDCardBootable                     ,0xfc2a4f67)
//NHSTUB(RefreshPhysicalScreen                  ,0xfc143599)
NHSTUB(RenameFile_Fut                         ,0xfc28fca1)
NHSTUB(Restart                                ,0xfc095c41)
NHSTUB(SetFileAttributes                      ,0xfc2a5319)
NHSTUB(SetFileTimeStamp                       ,0xfc2a52d1)
NHSTUB(SetParameterData                       ,0xfc09089f)
NHSTUB(TurnOffBackLight                       ,0xfc0d2997)
NHSTUB(TurnOnBackLight                        ,0xfc0d2985)
NHSTUB(WriteSDCard                            ,0xfc19bb17)
NHSTUB(apex2us                                ,0xfc0a950f)
NHSTUB(err_init_task                          ,0xfc04f3b9)
NHSTUB(realloc                                ,0xfc42adb1)
NHSTUB(reboot_fw_update                       ,0xfc335235)
NHSTUB(CancelHPTimer                          ,0xfc1423c9)
NHSTUB(SetHPTimerAfterNow                     ,0xfc142331)

// These don't exist
NHSTUB(SetZoomActuatorSpeedPercent, NULL_SUB)
NHSTUB(UnsetZoomForMovie,           NULL_SUB)

