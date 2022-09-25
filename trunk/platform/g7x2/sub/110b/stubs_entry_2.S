#include "stubs_asm.h"

// BEWARE: thumb functions NEED the thumb bit in the below list

#define NULL_SUB 0xe0020929 // bx lr

NHSTUB(EnterToCompensationEVF                 ,0xe0298d6d)  // function that uses "ExpON" string
NHSTUB(ExitFromCompensationEVF                ,0xe0298dad)  // function that uses "ExpOff" string
NHSTUB(ExpCtrlTool_StartContiAE               ,0xe02a1a91)  // function that uses "StartContiAE" string
NHSTUB(ExpCtrlTool_StopContiAE                ,0xe02a1bfd)  // function that uses "StopContiAE" string
NHSTUB(Feof_Fut                               ,0xe03710c1)
NHSTUB(Fflush_Fut                             ,0xe03710eb)
NHSTUB(GetImageFolder                         ,0xe0355015)
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
NHSTUB(WriteSDCard                            ,0xe051e963)

NHSTUB(VTMLock                                ,0xe03780bf)  // OK
NHSTUB(VTMUnlock                              ,0xe03781d7)  // ??? VTMUnlock string not in FW

NHSTUB(GetActiveViewportBuffer                ,0xe03aa70b)

// These don't exist
NHSTUB(ScreenLock                             ,NULL_SUB)
NHSTUB(ScreenUnlock                           ,NULL_SUB)
NHSTUB(SetFileAttributes                      ,NULL_SUB)
NHSTUB(SetZoomActuatorSpeedPercent            ,NULL_SUB)
NHSTUB(UnsetZoomForMovie                      ,NULL_SUB)

// Use overide function for GetPropertyCase to handle high-speed continuous mode
IGNORE(GetPropertyCase)
NHSTUB(GetPropertyCase_FW                     ,0xe036af69)

//// required because DryOS >=54 functions assert on unitialized event flag, sem etc
//// see https://chdk.setepontos.com/index.php?topic=12516.0
NHSTUB(init_focus_eventflag                   ,0xe05923d9)
NHSTUB(init_nd_eventflag                      ,0xe05924f1)
NHSTUB(CreateBinarySemaphoreStrictly          ,0xdffca245)

// To find these values it is easiest to use the Ghidra de-compile window.
   DEF(hdmi_buffer_check_adr                  ,0x4196a000)  // For HDMI output we only want to flag UI updates when layer 0 is set to this buffer address
                                                            //   Start at the transfer_src_overlay function, then go to the last function called
                                                            //   Now find the function call just after the "MakeOsdVram.c" DebugAssert call.
                                                            //   The value is the second parameter to this function.

// Does not exist
NHSTUB(EngDrvRead                           ,NULL_SUB)             // EngDrvRead code merged into EngDrvRead_FW !!! TODO: enable use of EngDrvRead_FW in code

DEF(task_FsIoNotifyTask                     ,0xe00f2b5d)

NHSTUB(get_ptp_buf_size                     ,0xe053364b)
NHSTUB(get_ptp_file_buf                     ,0xe0556e1f)
