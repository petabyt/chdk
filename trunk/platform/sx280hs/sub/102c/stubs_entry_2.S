#include "stubs_asm.h"

// BEWARE: thumb functions NEED the thumb bit in the below list

#define NULL_SUB 0xfc021059 // bx lr

NHSTUB(Close                                  ,0xfc2a5179)
//NHSTUB(CreateTaskStrictly                   ,0x010c5ae5) // 0xfc251c94 is the ARM veneer
DEF(orig_CreateTask                           ,0x010c51fd)
NHSTUB(DebugAssert                            ,0xfc251d9c) // arm
NHSTUB(EnterToCompensationEVF                 ,0xfc20decb)
NHSTUB(ExitFromCompensationEVF                ,0xfc20df07)
NHSTUB(ExitTask                               ,0xfc251339) // thumb!!
NHSTUB(ExpCtrlTool_StartContiAE               ,0xfc204fab)
NHSTUB(ExpCtrlTool_StopContiAE                ,0xfc20508b)
NHSTUB(Feof_Fut                               ,0xfc28ff61)
NHSTUB(Fflush_Fut                             ,0xfc28ff89)
NHSTUB(GetBatteryTemperature                  ,0xFC138F45)
NHSTUB(GetCCDTemperature                      ,0xFC138F43)
NHSTUB(GetDrive_TotalClusters                 ,0xfc057747)
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xfc28c8d7)
NHSTUB(GetImageFolder                         ,0xfc25d561)
NHSTUB(GetOpticalTemperature                  ,0xfc138f41)
NHSTUB(GiveSemaphore                          ,0xfc251cc4) // arm
NHSTUB(LocalTime                              ,0xfc251bdc) // arm
NHSTUB(MakeSDCardBootable                     ,0xfc2a4fe3)
NHSTUB(Open                                   ,0xfc2a5177)
NHSTUB(PT_PlaySound                           ,0xfc148f2d)
NHSTUB(RefreshPhysicalScreen                  ,0xfc143599)
NHSTUB(RenameFile_Fut                         ,0xfc28fd11)
NHSTUB(Restart                                ,0xfc095c41)
NHSTUB(SetFileAttributes                      ,0xfc2a5395)
NHSTUB(SetFileTimeStamp                       ,0xfc2a534d)
NHSTUB(SetParameterData                       ,0xfc09089f)
NHSTUB(SleepTask                              ,0xfc251d3c) // arm
NHSTUB(TakeSemaphore                          ,0xfc251cac) // arm
NHSTUB(TurnOffBackLight                       ,0xfc0d2997)
NHSTUB(TurnOnBackLight                        ,0xfc0d2985)
NHSTUB(Write                                  ,0xfc2a521f)
NHSTUB(WriteSDCard                            ,0xfc19bb17)
NHSTUB(_log10                                 ,0xfc251c04) // arm
NHSTUB(_pow                                   ,0xfc251bb4) // arm
NHSTUB(apex2us                                ,0xfc0a950f)
NHSTUB(err_init_task                          ,0xfc04f3b9)
NHSTUB(mkdir                                  ,0xfc2a53eb)
NHSTUB(rand                                   ,0xfc0d32c3)
NHSTUB(realloc                                ,0xfc42ae41)
NHSTUB(reboot_fw_update                       ,0xfc3352b1)
NHSTUB(srand                                  ,0xfc0d32bd)
NHSTUB(strcmp                                 ,0xfc2b7e4d)
   DEF(task_DvlpSeq                           ,0xfc1aa80f)
NHSTUB(time                                   ,0xfc251d24) // arm
NHSTUB(CancelHPTimer                          ,0xfc1423c9)
NHSTUB(SetHPTimerAfterNow                     ,0xfc142331)

// trial
//NHSTUB(refresh_bitmap_buf_from,                0xfc143435)

// These don't exist
NHSTUB(SetZoomActuatorSpeedPercent, NULL_SUB)
NHSTUB(UnsetZoomForMovie,           NULL_SUB)

