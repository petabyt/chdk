#include "stubs_asm.h"

// BEWARE: thumb functions NEED the thumb bit in the below list
 
#define NULL_SUB 0xfc0204a1 // movs r0, #0; bx lr

NHSTUB(DeleteDirectory_Fut,                    0xfc38a185) // found @ fc081a3a
NHSTUB(DeleteFile_Fut,                         0xfc38a13b)
NHSTUB(EnterToCompensationEVF,                 0xfc2a5f6b)
NHSTUB(ExitFromCompensationEVF,                0xfc2a5fad)
NHSTUB(ExpCtrlTool_StartContiAE,               0xfc2bb61b)
NHSTUB(ExpCtrlTool_StopContiAE,                0xfc2bb7b1)
NHSTUB(Feof_Fut,                               0xfc38a329)
NHSTUB(Fflush_Fut,                             0xfc38a351)
NHSTUB(GetDrive_TotalClusters,                 0xfc076ab3)
NHSTUB(GetFocusLensSubjectDistanceFromLens,    0xfc360e8b) // useless, returns zero
NHSTUB(MoveFocusLensToDistance,                0xfc43e66f) // MoveFocusLensWithDistance_FW, seems to do nothing useful (calls lots of emptied functions)
NHSTUB(PT_PlaySound,                           0xfc38c91f) // no longer an eventproc?
NHSTUB(RefreshPhysicalScreen,                  NULL_SUB)
NHSTUB(RenameFile_Fut,                         0xfc38a0d9)
NHSTUB(Restart,                                0xfc12790b)
NHSTUB(ScreenLock,                             0xfc38c505)
NHSTUB(ScreenUnlock,                           0xfc38c53b)
NHSTUB(SetFileAttributes,                      0xfc389b19)
NHSTUB(SetFileTimeStamp,                       0xfc389ad1)
NHSTUB(SetParameterData,                       0xfc27e64f) // PTM_BackupUIProperty_FW
NHSTUB(WriteSDCard,                            0x10e2c9d)  // found @ fc388a84
NHSTUB(apex2us,                                0xFC1B1D07)
NHSTUB(reboot_fw_update, NULL_SUB) // todo
NHSTUB(strtolx,                                0xfc13b209)
NHSTUB(CancelHPTimer,                          0xfc1faa7d)
NHSTUB(SetHPTimerAfterNow,                     0xfc1fa9e5)
//SetHPTimerAfterTimeout 0xfc1faa2b

// additional
NHSTUB(displaybusyonscreen,                    0xfc3273d3)
NHSTUB(undisplaybusyonscreen,                  0xfc327469)
NHSTUB(MakeSDCardBootable,                     0xfc3896e9)
NHSTUB(GetImageFolder,                         0xfc3134bd)
NHSTUB(GetLensCurrentFocalLength,              0xfc43fa81)
NHSTUB(GetLensWideFocalLength,                 0xfc43fa93)
//NHSTUB(GetLensTeleFocalLength,                 0xfc43faa5)
// GetDisplayType 0xfc1f0252, see "DisplayType : %d"
// vramtransfermanager_lock 0xfc38b9eb
// vramtransfermanager_unlock 0xfc38b9db

NHSTUB(LogCameraEvent,                         0xfc362a8b)
NHSTUB(GetLogToFile,                           0xfc18db55)

// These don't exist
NHSTUB(SetZoomActuatorSpeedPercent,              NULL_SUB)
NHSTUB(UnsetZoomForMovie,                        NULL_SUB)

// Dysfunctional
NHSTUB(PT_MoveOpticalZoomAt,                     NULL_SUB)
NHSTUB(MoveZoomLensWithPoint,                    NULL_SUB)
