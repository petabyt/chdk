#include "stubs_asm.h"

// BEWARE: thumb functions NEED the thumb bit in the below list

#define NULL_SUB 0xfc0008fb // bx lr
#DEF(orig_CreateTask                           ,0x010E5089)
NHSTUB(LogCameraEvent                        ,0xfc3362b7 + 0x28)
NHSTUB(displaybusyonscreen                   , 0xfc319699) //0xfc31987d?
NHSTUB(undisplaybusyonscreen                   ,0xfc319731)//0xfc3198fb ?
NHSTUB(SetZoomActuatorSpeedPercent                   , NULL_SUB)
NHSTUB(MakeSDCardBootable                   , 0xfc33284d + 0x28)
NHSTUB(GetImageFolder                   , 0xfc30ba5d + 0x28)
NHSTUB(EnterToCompensationEVF                ,0xfc2766c5 + 0x28) //corrected,from 0xFC2766c4)
NHSTUB(ExitFromCompensationEVF               ,0xFC2766ff + 0x28)
NHSTUB(ExpCtrlTool_StartContiAE              ,0xFC264e5b + 0x28)
NHSTUB(ExpCtrlTool_StopContiAE               ,0xFC264F47 + 0x28)
NHSTUB(Feof_Fut                              ,0xFC301Dad + 0x28)
NHSTUB(Fflush_Fut                            ,0xFC301Dd5 + 0x28)
NHSTUB(get_dial_hw_position                  ,0xfc119805 )  //no +28 thanks srsa_4c
NHSTUB(GetDrive_TotalClusters               ,0xfc3324eb + 0x28)
//NHSTUB(GetFocusLensSubjectDistance          ,0xfc4b4a73)
//NHSTUB(GetFocusLensSubjectDistance          ,0xfc2fa8df) //stubs_entry.S
NHSTUB(GetFocusLensSubjectDistanceFromLens  ,0xFC2FABc1 + 0x28)
//NHSTUB(PT_PlaySound                         ,0xFC333df1)
NHSTUB(RenameFile_Fut                       ,0xFC301B5d + 0x28)
NHSTUB(Restart                              ,0xFC0B96E5 )
NHSTUB(SetFileAttributes                    ,0xFC332C01 + 0x28)
NHSTUB(SetFileTimeStamp                     ,0xFC332Bb9 + 0x28)
NHSTUB(SetParameterData                     ,0xfc322acf + 0x28)
//NHSTUB(TurnOffBackLight                     ,0xFC0E786B)
//NHSTUB(TurnOnBackLight                      ,0xFC0E7859)
NHSTUB(WriteSDCard                          ,0xFCD1D6B7 + 0x28)
NHSTUB(apex2us                              ,0xFC3468bb + 0x28)
//NHSTUB(rand                                 ,0xFC1619CF)
NHSTUB(reboot_fw_update                     ,0xfc3a1177 + 0x28 ) // xxxcorrected from,0xfc3a1175)
//NHSTUB(srand                                ,0xFC1619C1)
NHSTUB(CancelHPTimer                        ,0xFC15BBFD)
//NHSTUB(SetHPTimerAfterNow                   ,0xFC15BB65)
// required because DryOS >=54 functions assert on unitialized event flag, sem etc
// see https://chdk.setepontos.com/index.php?topic=12516.0
NHSTUB(init_focus_eventflag,    0xfc4b550f) //by comparing to 100f +28
NHSTUB(init_nd_eventflag,               0xfc4b55f1) // +28
NHSTUB(CreateBinarySemaphoreStrictly,0x010e5b8b) // for av_override_semaphore
//NHSTUB(CreateBinarySemaphore,0x010e5939)
//NHSTUB(bzero,           0x01106b1c)//zero memory 
//NHSTUB(memset32,		0x01106b20)//entry point in bzero to take 4 byte pattern
//NHSTUB(j_PostMessageQueueStrictly,          0xfc2cf220 + 0x28);
//NHSTUB(j_CreateMessageQueueStrictly,          0xfc2cf338);
NHSTUB(j_CreateBinarySemaphoreStrictly,       0xfc2cf368 + 0x28);
//NHSTUB(j_CreateEventFlagStrictly,             0xfc2cf3c8);
NHSTUB(captseq_raw_addr_init, 0xfc154c1b); //compare to g7x fc152772 + 1
DEF(task_LiveImageTask,                    0xfc198165 +0x28);

