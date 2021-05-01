#include "stubs_asm.h"

// BEWARE: thumb functions NEED the thumb bit in the below list

#define NULL_SUB 0xe0020929 // bx lr

NHSTUB(EnterToCompensationEVF                 ,0xe0298d6d)
NHSTUB(ExitFromCompensationEVF                ,0xe0298dad)
NHSTUB(ExpCtrlTool_StartContiAE               ,0xe02a1a91)
NHSTUB(ExpCtrlTool_StopContiAE                ,0xe02a1bfd)
NHSTUB(Feof_Fut                               ,0xe03710c1)
NHSTUB(Fflush_Fut                             ,0xe03710eb)
NHSTUB(GetDrive_TotalClusters                 ,0xe0375125)  // function immediately before GetDrive_FreeClusters in ROM
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xe0372eeb)
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
NHSTUB(reboot_fw_update                       ,0xe0526847)  // Does not work !!! Asserts if try to load PS.FI2 file.
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
NHSTUB(GetPropertyCase_FW                     ,0xe036af69)

   DEF(hook_dry_memcpy                        ,0xdffcc598)  // ARM address of RAM dry_memcpy function for patching. Use 'dry_memcpy' address from sig finder.
   DEF(canon_ui_update_ret_adr                ,0xe01c572f)  // Thumb address to check against LR register to detect dry_memcpy call from Canon UI update
                                                            // To find canon_ui_update_ret_adr it is easiest to use the Ghidra de-compile window.
                                                            //   Start at the transfer_src_overlay function, then go to the last function called
                                                            //   In this function again go to the last function called.
                                                            //   Now go to the function called near the end; just before the check of param_6 != 100
                                                            //   This function should be calling mzrm_createmsg then dry_memcpy.
                                                            //   Use the address after the dry_memcpy call for the value of canon_ui_update_ret_adr (add 1 for thumb address)

// Incorrect by finsig - need to check

// Does not exist
NHSTUB(EngDrvRead                           ,NULL_SUB)             // EngDrvRead code merged into EngDrvRead_FW !!! TODO: enable use of EngDrvRead_FW in code

// Missed by finsig - need to check
NHSTUB(_sqrt                                ,0xdffcf241)
NHSTUB(SetHPTimerAfterNow                   ,0xe03f4ac1)

DEF(task_FsIoNotifyTask                     ,0xe00f2b5d)

NHSTUB(get_ptp_buf_size                     ,0xe053364f)
NHSTUB(get_ptp_file_buf                     ,0xe0556e23)
