#include "stubs_asm.h"

// BEWARE: thumb functions NEED the thumb bit in the below list

#define NULL_SUB 0xfc021059 // bx lr

NHSTUB(Close                                  ,0xfc2a50fd)
//NHSTUB(CreateTaskStrictly                   ,0x010c5ae5) // 0xfc251c0c is the ARM veneer
DEF(orig_CreateTask                           ,0x010c51fd)
NHSTUB(DebugAssert                            ,0xfc251d14)
NHSTUB(EnterToCompensationEVF                 ,0xfc20deb7)
NHSTUB(ExitFromCompensationEVF                ,0xfc20def3)
NHSTUB(ExitTask                               ,0xfc2512b1) // thumb!!
NHSTUB(ExpCtrlTool_StartContiAE               ,0xfc204f97)
NHSTUB(ExpCtrlTool_StopContiAE                ,0xfc205077)
NHSTUB(Feof_Fut                               ,0xfc28fef1)
NHSTUB(Fflush_Fut                             ,0xfc28ff19)
NHSTUB(GetBatteryTemperature                  ,0xFC138F45)
NHSTUB(GetCCDTemperature                      ,0xFC138F43)
NHSTUB(GetDrive_TotalClusters                 ,0xfc057747)
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xfc28c84f)
NHSTUB(GetImageFolder                         ,0xfc25d4d9)
NHSTUB(GetOpticalTemperature                  ,0xFC138F41)
NHSTUB(GiveSemaphore                          ,0xfc251c3c) // arm
NHSTUB(LocalTime                              ,0xfc251b54) // arm
NHSTUB(MakeSDCardBootable                     ,0xfc2a4f67)
NHSTUB(Open                                   ,0xfc2a50fb)
NHSTUB(PT_PlaySound                           ,0xfc148f2d)
NHSTUB(RefreshPhysicalScreen                  ,0xfc143599)
NHSTUB(RenameFile_Fut                         ,0xfc28fca1)
NHSTUB(Restart                                ,0xfc095c41)
NHSTUB(SetFileAttributes                      ,0xfc2a5319)
NHSTUB(SetFileTimeStamp                       ,0xfc2a52d1)
NHSTUB(SetParameterData                       ,0xfc09089f)
NHSTUB(SleepTask                              ,0xfc251cb4) // arm
NHSTUB(TakeSemaphore                          ,0xfc251c24) // arm
NHSTUB(TurnOffBackLight                       ,0xfc0d2997)
NHSTUB(TurnOnBackLight                        ,0xfc0d2985)
NHSTUB(Write                                  ,0xfc2a51a3)
NHSTUB(WriteSDCard                            ,0xfc19bb17)
NHSTUB(_log10                                 ,0xfc251b7c) // arm
NHSTUB(_pow                                   ,0xfc251b2c) // arm
NHSTUB(apex2us                                ,0xfc0a950f)
NHSTUB(err_init_task                          ,0xfc04f3b9)
NHSTUB(mkdir                                  ,0xfc2a536f)
NHSTUB(rand                                   ,0xfc0d32c3)
NHSTUB(realloc                                ,0xfc42adb1)
NHSTUB(reboot_fw_update                       ,0xfc335235)
NHSTUB(srand                                  ,0xfc0d32bd)
NHSTUB(strcmp                                 ,0xfc2b7dd1)
   DEF(task_DvlpSeq                           ,0xfc1aa7fb)
NHSTUB(time                                   ,0xfc251c9c) // arm
NHSTUB(CancelHPTimer                          ,0xfc1423c9)
NHSTUB(SetHPTimerAfterNow                     ,0xfc142331)


// trial
NHSTUB(refresh_bitmap_buf_from,                0xfc143435)

// These don't exist
NHSTUB(SetZoomActuatorSpeedPercent, NULL_SUB)
NHSTUB(UnsetZoomForMovie,           NULL_SUB)

