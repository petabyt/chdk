#include "stubs_asm.h"

// BEWARE: thumb functions NEED the thumb bit in the below list

#define NULL_SUB 0xFC0211F1 // bx lr

NHSTUB(DeleteDirectory_Fut                  ,0xfc374285)
NHSTUB(DeleteFile_Fut                       ,0xfc37423b)
NHSTUB(EnterToCompensationEVF               ,0xfc0aa66b)
NHSTUB(ExitFromCompensationEVF              ,0xfc0aa6a7)
NHSTUB(ExpCtrlTool_StartContiAE             ,0xfc2aab75)
NHSTUB(ExpCtrlTool_StopContiAE              ,0xfc2aadc9)
NHSTUB(Feof_Fut                             ,0xfc374429)
NHSTUB(Fflush_Fut                           ,0xfc374451)
NHSTUB(GetDrive_TotalClusters               ,0xfc06bf33)
NHSTUB(GetFocusLensSubjectDistanceFromLens  ,0xfc35ff17)
NHSTUB(GetImageFolder                       ,0xfc303c65)
NHSTUB(MakeSDCardBootable                   ,0xfc37a6bd)
NHSTUB(MoveFocusLensToDistance              ,0xfc44bb9d)
NHSTUB(PutInNdFilter                        ,0xfc44d241)
NHSTUB(PutOutNdFilter                       ,0xfc44d25b)
NHSTUB(RefreshPhysicalScreen                ,0xfc37f30f)
NHSTUB(RenameFile_Fut                       ,0xfc3741d9)
NHSTUB(Restart                              ,0xfc1312c5)
NHSTUB(ScreenUnlock                         ,0xfc37f989)
NHSTUB(SetFileAttributes                    ,0xfc37ab05)
NHSTUB(SetFileTimeStamp                     ,0xfc37aabd)
NHSTUB(SetParameterData                     ,0xfc2783c1)
NHSTUB(WriteSDCard                          ,0xfcc9a373)
NHSTUB(apex2us                              ,0xfc3f454f)
NHSTUB(displaybusyonscreen                  ,0xfc333197)
NHSTUB(err_init_task                        ,0xfc06316b)
NHSTUB(realloc                              ,0xfc4fa309)
NHSTUB(reboot_fw_update                     ,0xfc4504b1)
NHSTUB(strtolx                              ,0xfc14c1cd)
NHSTUB(undisplaybusyonscreen                ,0xfc33322d)
NHSTUB(CancelHPTimer                        ,0xfc1fcc21)
NHSTUB(SetHPTimerAfterNow                   ,0xfc1fcb89)

DEF(orig_CreateTask                           ,0xbfe14a31)

// additional...

NHSTUB(CreateBinarySemaphore                  ,0xbfe1530d) //0xFCCBECDC)
//NHSTUB(TakeSemaphore                          ,0xFC3018B3)
NHSTUB(TryTakeSemaphore                       ,0xbfe153d1) // FC3017BB)

NHSTUB(LogCameraEvent,			       0xfc361c9f)  

NHSTUB(LCDMsg_Create				,0xfc51faaf)
NHSTUB(LCDMsg_SetStr				,0xfc51f7e3)
//NHSTUB(System.Create				,0xFC189AE3)
//NHSTUB(sprintf 						,0xFC380163)

NHSTUB(GetLensFocalLengthAll                  ,0xfc25cfc3)

NHSTUB(displayblankscreen,                     0xFC333265)
NHSTUB(undisplayblankscreen,                   0xFC3332EB)

// trial
NHSTUB(refresh_bitmap_buf_from,                0xfc143435)

// These don't exist
NHSTUB(SetZoomActuatorSpeedPercent, NULL_SUB)
NHSTUB(UnsetZoomForMovie,           NULL_SUB)

// Dysfunctional
NHSTUB(PT_MoveOpticalZoomAt,                     NULL_SUB)
NHSTUB(MoveZoomLensWithPoint,                    NULL_SUB)
