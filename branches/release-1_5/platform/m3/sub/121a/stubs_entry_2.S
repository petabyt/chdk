#include "stubs_asm.h"

// BEWARE: thumb functions NEED the thumb bit in the below list

#define NULL_SUB 0xFC0211F1 // bx lr

NHSTUB(DeleteDirectory_Fut                  ,0xFC3742B5)
NHSTUB(DeleteFile_Fut                       ,0xFC37426B)
NHSTUB(EnterToCompensationEVF               ,0xFC0AA66B)
NHSTUB(ExitFromCompensationEVF              ,0xFC0AA6A7)
NHSTUB(ExpCtrlTool_StartContiAE             ,0xFC2AABA5)
NHSTUB(ExpCtrlTool_StopContiAE              ,0xFC2AADF9)
NHSTUB(Feof_Fut                             ,0xFC374459)
NHSTUB(Fflush_Fut                           ,0xFC374481)
NHSTUB(GetDrive_TotalClusters               ,0xFC06BF33)
NHSTUB(GetFocusLensSubjectDistanceFromLens  ,0xFC35FF47)
NHSTUB(GetImageFolder                       ,0xFC303C95)
NHSTUB(MakeSDCardBootable                   ,0xFC37A6ED)
NHSTUB(MoveFocusLensToDistance              ,0xFC44BBCD)
NHSTUB(PutInNdFilter                        ,0xFC44D271)
NHSTUB(PutOutNdFilter                       ,0xFC44D28B)
//NHSTUB(RefreshPhysicalScreen                ,0xfc37f30f)
NHSTUB(RenameFile_Fut                       ,0xFC374209)
NHSTUB(Restart                              ,0xFC1312CD)
NHSTUB(ScreenUnlock                         ,0xFC37F9B9)
NHSTUB(SetFileAttributes                    ,0xFC37AB35)
NHSTUB(SetFileTimeStamp                     ,0xFC37AAED)
NHSTUB(SetParameterData                     ,0xFC2783F1)
NHSTUB(WriteSDCard                          ,0xFCC9A3A3)
NHSTUB(apex2us                              ,0xFC3F457F)
NHSTUB(displaybusyonscreen                  ,0xFC3331C7)
NHSTUB(err_init_task                        ,0xFC06316B)
NHSTUB(realloc                              ,0xFC4FA339)
NHSTUB(reboot_fw_update                     ,0xFC4504E1)
NHSTUB(strtolx                              ,0xFC14C1D5)
NHSTUB(undisplaybusyonscreen                ,0xFC33325D)
NHSTUB(CancelHPTimer                        ,0xFC1FCC29)
NHSTUB(SetHPTimerAfterNow                   ,0xFC1FCB91)

DEF(orig_CreateTask                           ,0xBFE14A31)

// additional...

NHSTUB(CreateBinarySemaphore                  ,0xBFE1530D) //0xFCCBECDC)
//NHSTUB(TakeSemaphore                          ,0xFC3018B3)
NHSTUB(TryTakeSemaphore                       ,0xBFE153D1) // FC3017BB)

NHSTUB(LogCameraEvent,			       0xFC361CCF)  

NHSTUB(LCDMsg_Create				,0xFC51FADF)
NHSTUB(LCDMsg_SetStr				,0xFC51F813)
//NHSTUB(System.Create				,0xFC189AE3)
//NHSTUB(sprintf 						,0xFC380163)

NHSTUB(GetLensFocalLengthAll                  ,0xFC25CFF3)

NHSTUB(displayblankscreen,                     0xFC333295)
NHSTUB(undisplayblankscreen,                   0xFC33331B)



