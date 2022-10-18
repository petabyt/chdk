#include "stubs_asm.h"

// BEWARE: thumb functions NEED the thumb bit in the below list

#define NULL_SUB 0xe0020929 // bx lr

NHSTUB(GetImageFolder                         ,0xe0355015)
NHSTUB(RenameFile_Fut                         ,0xe0370e69)
NHSTUB(Restart                                ,0xe005b973)  // Does not work - only accepts 7 as the parameter value (firmware update)
NHSTUB(SetFileTimeStamp                       ,0xe0374179)
NHSTUB(TurnOffBackLight                       ,NULL_SUB)
NHSTUB(TurnOnBackLight                        ,NULL_SUB)
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

// Does not exist
NHSTUB(EngDrvRead                           ,NULL_SUB)             // EngDrvRead code merged into EngDrvRead_FW !!! TODO: enable use of EngDrvRead_FW in code

DEF(task_FsIoNotifyTask                     ,0xe00f2b5d)

NHSTUB(get_ptp_buf_size                     ,0xe053364b)
NHSTUB(get_ptp_file_buf                     ,0xe0556e1f)
