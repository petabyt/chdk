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
NHSTUB(GetPropertyCase_FW                     ,0xe036af69)

// To find these values it is easiest to use the Ghidra de-compile window.
   DEF(debug_logging_ptr                      ,0x000254f4)  // RAM address of function called by mzrm_sendmsg for logging
                                                            // To find debug_logging_ptr:
                                                            //   Start at the mzrm_sendmsg function.
                                                            //   Find the function call via memory pointer with first parameter = "SendMsg   : %d\n" string
                                                            //   debug_logging_ptris the memory address that contains the pointer used to make this function call
   DEF(debug_logging_flag                     ,0x000254fc)  // RAM address of flag to enable logging call
                                                            // To find debug_logging_flag:
                                                            //   Just before the debug_logging_ptrfound above there is an if statement that tests both a memory value and
                                                            //   the debug_logging_ptrvalue.
                                                            //   debug_logging_flag is the memory address of the flag value in the if statement.
   DEF(mzrm_sendmsg_ret_adr                   ,0xe030671b)  // Thumb address to check against LR register to detect mzrm_sendmag call from Canon UI update
                                                            //   This is the address immediately after the call to debug_logging_ptrin mzrm_sendmsg (+1 for thumb)
   DEF(hdmi_buffer_check_adr                  ,0x4196a000)  // For HDMI output we only want to flag UI updates when layer 0 is set to this buffer address
                                                            //   Start at the transfer_src_overlay function, then go to the last function called
                                                            //   Now find the function call just after the "MakeOsdVram.c" DebugAssert call.
                                                            //   The value is the second parameter to this function.

// Incorrect by finsig - need to check

// Does not exist
NHSTUB(EngDrvRead                           ,NULL_SUB)             // EngDrvRead code merged into EngDrvRead_FW !!! TODO: enable use of EngDrvRead_FW in code

// Missed by finsig - need to check
NHSTUB(_sqrt                                ,0xdffcf241)
NHSTUB(SetHPTimerAfterNow                   ,0xe03f4ac1)

DEF(task_FsIoNotifyTask                     ,0xe00f2b5d)

NHSTUB(get_ptp_buf_size                     ,0xe053364b)
NHSTUB(get_ptp_file_buf                     ,0xe0556e1f)
