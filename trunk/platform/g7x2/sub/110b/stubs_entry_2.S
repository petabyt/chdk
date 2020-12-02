#include "stubs_asm.h"

// BEWARE: thumb functions NEED the thumb bit in the below list

#define NULL_SUB 0xe0020929 // bx lr

NHSTUB(EnterToCompensationEVF                 ,0xe0298d6d)  // function that uses "ExpON" string
NHSTUB(ExitFromCompensationEVF                ,0xe0298dad)  // function that uses "ExpOff" string
NHSTUB(ExpCtrlTool_StartContiAE               ,0xe02a1a91)  // function that uses "StartContiAE" string
NHSTUB(ExpCtrlTool_StopContiAE                ,0xe02a1bfd)  // function that uses "StopContiAE" string
NHSTUB(Feof_Fut                               ,0xe03710c1)
NHSTUB(Fflush_Fut                             ,0xe03710eb)
NHSTUB(GetDrive_TotalClusters                 ,0xe0375125)  // function immediately before GetDrive_FreeClusters in ROM
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xe0372eeb)  // Calls 'GetFocusLensSubjectDistance', a couple of functions before 'GetFocusLensAvCoefficient_FW'
NHSTUB(GetImageFolder                         ,0xe0355015)
NHSTUB(MakeSDCardBootable                     ,NULL_SUB)
NHSTUB(RenameFile_Fut                         ,0xe0370e69)
NHSTUB(Restart                                ,0xe005b973)  // Does not work - only accepts 7 as the parameter value (firmware update)
NHSTUB(SetFileTimeStamp                       ,0xe0374179)
NHSTUB(TurnOffBackLight                       ,NULL_SUB)
NHSTUB(TurnOnBackLight                        ,NULL_SUB)
NHSTUB(apex2us                                ,0xe0067ab3)
//NHSTUB(err_init_task                          ,NULL_SUB)
//NHSTUB(mkdir                                  ,NULL_SUB)
//NHSTUB(realloc                                ,NULL_SUB)
NHSTUB(reboot_fw_update                       ,0xe0526843)  // Does not work !!! Asserts if try to load PS.FI2 file.
NHSTUB(CancelHPTimer                          ,0xe03f4b5b)

NHSTUB(VTMLock                                ,0xe03780bf)  // OK
NHSTUB(VTMUnlock                              ,0xe03781d7)  // ??? VTMUnlock string not in FW

NHSTUB(GetActiveViewportBuffer                ,0xe03aa70b)

// These don't exist
NHSTUB(PT_PlaySound                           ,NULL_SUB)
NHSTUB(ScreenLock                             ,NULL_SUB)
NHSTUB(ScreenUnlock                           ,NULL_SUB)
NHSTUB(SetFileAttributes                      ,NULL_SUB)
NHSTUB(SetZoomActuatorSpeedPercent            ,NULL_SUB)
NHSTUB(UnsetZoomForMovie                      ,NULL_SUB)
NHSTUB(WriteSDCard                            ,NULL_SUB)

// Use overide function for GetPropertyCase to handle high-speed continuous mode
IGNORE(GetPropertyCase)
NHSTUB(GetPropertyCase_FW                   ,0xe036af69)

// Incorrect by finsig - need to check

// Does not exist
NHSTUB(EngDrvRead                           ,NULL_SUB)             // EngDrvRead code merged into EngDrvRead_FW !!! TODO: enable use of EngDrvRead_FW in code

// Missed by finsig - need to check
NHSTUB(_sqrt                                ,0xdffcf241)
NHSTUB(SetHPTimerAfterNow                   ,0xe03f4ac1)
NHSTUB(strcat                               ,0xe0484f7b)
NHSTUB(strchr                               ,0xe045197f)

DEF(task_FsIoNotifyTask                     ,0xe00f2b5d)

NHSTUB(get_ptp_buf_size                     ,0xe053364b)
NHSTUB(get_ptp_file_buf                     ,0xe0556e1f)
