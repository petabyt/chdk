#include "stubs_asm.h"

// BEWARE: thumb functions NEED the thumb bit in the below list

#define NULL_SUB 0xfc0008fb // bx lr
#DEF(orig_CreateTask                           ,0x010E5089)
NHSTUB(LogCameraEvent                        ,0xfc3362cb) //x
NHSTUB(displaybusyonscreen                   , 0xfc319685) //x
NHSTUB(undisplaybusyonscreen                   ,0xfc31971d)//x
NHSTUB(SetZoomActuatorSpeedPercent                   , NULL_SUB)
NHSTUB(MakeSDCardBootable                   , 0xfc33280d) //x
NHSTUB(GetImageFolder                   , 0xfc30ba07)
NHSTUB(EnterToCompensationEVF                ,0xFC2766c5) //100f is wrong needs plus 1
NHSTUB(ExitFromCompensationEVF               ,0xFC27670f) //x
NHSTUB(ExpCtrlTool_StartContiAE              ,0xFC264e15)//x
NHSTUB(ExpCtrlTool_StopContiAE               ,0xFC264f57) //x
NHSTUB(Feof_Fut                              ,0xFC301Dc1) //x
NHSTUB(Fflush_Fut                            ,0xFC301De9) //x
NHSTUB(get_dial_hw_position                  ,0xfc119805) //x same as 100f
NHSTUB(GetDrive_TotalClusters               ,0xfc3324ff) //x
//NHSTUB(GetFocusLensSubjectDistance          ,0xfc4b4a73)
//NHSTUB(GetFocusLensSubjectDistance          ,0xfc2fa8df) //stubs_entry.S
NHSTUB(GetFocusLensSubjectDistanceFromLens  ,0xFC2FABd5) //x
//NHSTUB(PT_PlaySound                         ,0xFC333df1)
NHSTUB(RenameFile_Fut                       ,0xFC301B71) //x
NHSTUB(Restart                              ,0xFC0B96E5) //x
NHSTUB(SetFileAttributes                    ,0xFC332C15) //x
NHSTUB(SetFileTimeStamp                     ,0xFC332Bcd) //x
NHSTUB(SetParameterData                     ,0xfc322ae3) //x
//NHSTUB(TurnOffBackLight                     ,0xFC0E786B)
//NHSTUB(TurnOnBackLight                      ,0xFC0E7859)
NHSTUB(WriteSDCard                          ,0xFCD1D6a7) //x
NHSTUB(apex2us                              ,0xFC3468cf) //x
//NHSTUB(rand                                 ,0xFC1619CF)
NHSTUB(reboot_fw_update                     ,0xfc3a118b) //x wrong in 100f should be fc3a1177
//NHSTUB(srand                                ,0xFC1619C1)
NHSTUB(CancelHPTimer                        ,0xFC15BBFD) //x
//NHSTUB(SetHPTimerAfterNow                   ,0xFC15BB65)
// required because DryOS >=54 functions assert on unitialized event flag, sem etc
// see https://chdk.setepontos.com/index.php?topic=12516.0
NHSTUB(init_focus_eventflag,    0xfc4b54ff) // InitializeAdjustmentSystem->fc39f884->fc4b54fe event flag matches MoveFocusLensToDistance
NHSTUB(init_nd_eventflag,               0xfc4b55e1) // InitializeAdjustmentSystem->fc3d31c4->fc4b55e0 event flag matches PutInNdFilter
NHSTUB(CreateBinarySemaphoreStrictly,0x010e5b8b) // for av_override_semaphore
NHSTUB(captseq_raw_addr_init, 0xfc154c1b); //compare to g7x fc152772 + 1

