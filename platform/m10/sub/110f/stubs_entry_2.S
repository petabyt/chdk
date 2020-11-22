#include "stubs_asm.h"

// BEWARE: thumb functions NEED the thumb bit in the below list
 
#define NULL_SUB 0xfc0204a1 // movs r0, #0; bx lr

// shifted above ~ 0xfc2929d0 when compared to 110d

NHSTUB(DeleteDirectory_Fut,                    0xfc38a1b9)
NHSTUB(DeleteFile_Fut,                         0xfc38a16f)
NHSTUB(EnterToCompensationEVF,                 0xfc2a5f9f)
NHSTUB(ExitFromCompensationEVF,                0xfc2a5fe1)
NHSTUB(ExpCtrlTool_StartContiAE,               0xfc2bb64f)
NHSTUB(ExpCtrlTool_StopContiAE,                0xfc2bb7e5)
NHSTUB(Feof_Fut,                               0xfc38a35d)
NHSTUB(Fflush_Fut,                             0xfc38a385)
NHSTUB(GetDrive_TotalClusters,                 0xFC38938F)
//NHSTUB(GetDrive_FreeClusters,                  0xfc076ab3) // also updates while recording, but is rather heavy
NHSTUB(GetFocusLensSubjectDistanceFromLens,    NULL_SUB) // useless, returns zero
NHSTUB(MoveFocusLensToDistance,                NULL_SUB) // MoveFocusLensWithDistance_FW, seems to do nothing useful (calls lots of emptied functions)
NHSTUB(PT_PlaySound,                           0xfc38c953) // no longer an eventproc?
NHSTUB(RenameFile_Fut,                         0xfc38a10d)
NHSTUB(Restart,                                0xfc12790b)
NHSTUB(ScreenLock,                             0xfc38c539)
NHSTUB(ScreenUnlock,                           0xfc38c56f)
NHSTUB(SetFileAttributes,                      0xfc389b4d)
NHSTUB(SetFileTimeStamp,                       0xfc389b05)
NHSTUB(SetParameterData,                       0xfc27e64f) // PTM_BackupUIProperty_FW
NHSTUB(WriteSDCard,                            0x10e2c9d)  // found @ fc388ab8
NHSTUB(apex2us,                                0xFC1B1D07)
NHSTUB(reboot_fw_update, NULL_SUB) // todo
NHSTUB(strtolx,                                0xfc13b209)
NHSTUB(CancelHPTimer,                          0xfc1faa7d)
NHSTUB(SetHPTimerAfterNow,                     0xfc1fa9e5)
//SetHPTimerAfterTimeout 0xfc1faa2b

// additional
NHSTUB(displaybusyonscreen,                    0xfc327407)
NHSTUB(undisplaybusyonscreen,                  0xfc32749d)
NHSTUB(displayblankscreen,                     0xFC3274D5)
NHSTUB(undisplayblankscreen,                   0xFC327575)
NHSTUB(MakeSDCardBootable,                     0xfc38971d)
NHSTUB(GetImageFolder,                         0xfc3134f1)
NHSTUB(GetLensCurrentFocalLength,              0xfc43fab5)
NHSTUB(GetLensWideFocalLength,                 0xfc43fac7)
//NHSTUB(GetLensTeleFocalLength,                 0xfc43fad9)
// GetDisplayType 0xfc1f0252, see "DisplayType : %d"

NHSTUB(LogCameraEvent,                         0xfc362abf)
NHSTUB(GetLogToFile,                           0xfc18db55)
