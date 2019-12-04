#include "stubs_asm.h"

// BEWARE: thumb functions NEED the thumb bit in the below list

#define NULL_SUB 0xFC0211F1 // bx lr

NHSTUB(DeleteDirectory_Fut                  ,0xfc373f15)
NHSTUB(DeleteFile_Fut                       ,0xfc373ecb)
NHSTUB(EnterToCompensationEVF               ,0xfc0aa66b)
NHSTUB(ExitFromCompensationEVF              ,0xfc0aa6a7)
NHSTUB(ExpCtrlTool_StartContiAE             ,0xfc2aac61)
NHSTUB(ExpCtrlTool_StopContiAE              ,0xfc2aaeb5)
NHSTUB(Feof_Fut                             ,0xfc3740b9)
NHSTUB(Fflush_Fut                           ,0xfc3740e1)
NHSTUB(GetDrive_TotalClusters               ,0xfc06bf33)
NHSTUB(GetFocusLensSubjectDistanceFromLens  ,0xfc35fcab)
NHSTUB(GetImageFolder                       ,0xfc303c41)
NHSTUB(MakeSDCardBootable                   ,0xfc37a34d)
NHSTUB(MoveFocusLensToDistance              ,0xfc44b80d)
NHSTUB(PutInNdFilter                        ,0xfc44ceb1)
NHSTUB(PutOutNdFilter                       ,0xfc44cecb)
//NHSTUB(RefreshPhysicalScreen                ,0xfc37ef9f)
NHSTUB(RenameFile_Fut                       ,0xfc373e69)
NHSTUB(Restart                              ,0xfc1311dd)
NHSTUB(ScreenUnlock                         ,0xfc37f619)
NHSTUB(SetFileAttributes                    ,0xfc37a795)
NHSTUB(SetFileTimeStamp                     ,0xfc37a74d)
NHSTUB(SetParameterData                     ,0xfc2784bd)
NHSTUB(WriteSDCard                          ,0xfccad9eb)
NHSTUB(apex2us                              ,0xfc3f41df)
NHSTUB(displaybusyonscreen                  ,0xfc332ff7)
NHSTUB(err_init_task                        ,0xfc06316b)
NHSTUB(realloc                              ,0xfc4f9f61)
NHSTUB(reboot_fw_update                     ,0xfc450121)
NHSTUB(strtolx                              ,0xfc14c0dd)
NHSTUB(undisplaybusyonscreen                ,0xfc33308d)
NHSTUB(CancelHPTimer                        ,0xfc1fcbb1)
NHSTUB(SetHPTimerAfterNow                   ,0xfc1fcb19)

DEF(orig_CreateTask                           ,0xBFE14A31)

// additional...

NHSTUB(CreateBinarySemaphore                  ,0xBFE1530D) //0xFCCBECDC)
//NHSTUB(TakeSemaphore                          ,0xFC3018B3)
NHSTUB(TryTakeSemaphore                       ,0xBFE153D1) // FC3017BB)

NHSTUB(LogCameraEvent,			       0xFC361A33)  

NHSTUB(LCDMsg_Create				,0xFC51F6CB)
NHSTUB(LCDMsg_SetStr				,0xFC51F3FF)
//NHSTUB(System.Create				,0xFC189AE3)
//NHSTUB(sprintf 						,0xFC380163)

NHSTUB(GetLensFocalLengthAll                  ,0xFC25D0BF)

NHSTUB(displayblankscreen,                     0xFC3330C5)
NHSTUB(undisplayblankscreen,                   0xFC33314B)

// trial
NHSTUB(refresh_bitmap_buf_from,                0xfc143435)

// These don't exist
NHSTUB(SetZoomActuatorSpeedPercent, NULL_SUB)
NHSTUB(UnsetZoomForMovie,           NULL_SUB)

// Dysfunctional
NHSTUB(PT_MoveOpticalZoomAt,                     NULL_SUB)
NHSTUB(MoveZoomLensWithPoint,                    NULL_SUB)
