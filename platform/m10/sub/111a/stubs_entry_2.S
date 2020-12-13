#include "stubs_asm.h"

// BEWARE: thumb functions NEED the thumb bit in the below list
 
#define NULL_SUB 0xfc0204a1 // movs r0, #0; bx lr

// starts shifting above ~ 0xfc168b90 when compared to 110f

NHSTUB(DeleteDirectory_Fut,                    0xFC38A1E9)
NHSTUB(DeleteFile_Fut,                         0xFC38A19F)
NHSTUB(EnterToCompensationEVF,                 0xfc2a5fcf)
NHSTUB(ExitFromCompensationEVF,                0xfc2a6011)
NHSTUB(ExpCtrlTool_StartContiAE,               0xfc2bb67f)
NHSTUB(ExpCtrlTool_StopContiAE,                0xfc2bb815)
NHSTUB(Feof_Fut,                               0xfc38a38d)
NHSTUB(Fflush_Fut,                             0xfc38a3b5)
NHSTUB(GetDrive_TotalClusters,                 0xFC3893BF)
//NHSTUB(GetDrive_FreeClusters,                  0xfc076ab3) // also updates while recording, but is rather heavy
NHSTUB(GetFocusLensSubjectDistanceFromLens,    NULL_SUB) // useless, returns zero
NHSTUB(MoveFocusLensToDistance,                NULL_SUB) // MoveFocusLensWithDistance_FW, seems to do nothing useful (calls lots of emptied functions)
NHSTUB(RenameFile_Fut,                         0xfc38a13d)
NHSTUB(Restart,                                0xfc12790b)
NHSTUB(SetFileAttributes,                      0xfc389b7d)
NHSTUB(SetFileTimeStamp,                       0xfc389b35)
NHSTUB(SetParameterData,                       0xfc27e67f) // PTM_BackupUIProperty_FW
NHSTUB(WriteSDCard,                            0x10e2c9d)  // found @ fc388ab8
NHSTUB(apex2us,                                0xFC1B1D0F)
NHSTUB(reboot_fw_update, NULL_SUB) // todo
NHSTUB(CancelHPTimer,                          0xfc1faa85)
NHSTUB(SetHPTimerAfterNow,                     0xfc1fa9ed)
//SetHPTimerAfterTimeout 0x

// additional
NHSTUB(displaybusyonscreen,                    0xfc327437)
NHSTUB(undisplaybusyonscreen,                  0xfc3274cd)
NHSTUB(displayblankscreen,                     0xFC327505)
NHSTUB(undisplayblankscreen,                   0xFC3275a5)
NHSTUB(MakeSDCardBootable,                     0xfc38974d)
NHSTUB(GetImageFolder,                         0xfc313521)
NHSTUB(GetLensCurrentFocalLength,              0xfc43fae5)
NHSTUB(GetLensWideFocalLength,                 0xfc43faf7)
//NHSTUB(GetLensTeleFocalLength,                 0x)
// GetDisplayType 0x, see "DisplayType : %d"

NHSTUB(LogCameraEvent,                         0xfc362aef)
NHSTUB(GetLogToFile,                           0xfc18db5d)
