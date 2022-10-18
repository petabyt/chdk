// G16 1.01a

#include "stubs_asm.h"

// BEWARE: thumb functions NEED the thumb bit set in the below list (i.e odd addresses only (0x00000001) )

#define NULL_SUB 0xfc0210b9

NHSTUB(apex2us                                ,0xfc33797f) // Shutter.c asserts in sub_fc2e0ca2, similar to sx280 sub_fc2a63d6 and g7x sub_fc16e57e
NHSTUB(CancelHPTimer                          ,0xfc158795) // at 0xfc103e76, in section with "LcdSequence.c" , after TakeSemaphoreStrictly calls
NHSTUB(EnterToCompensationEVF                 ,0xfc254c6d) // search for "ExpOn"
NHSTUB(ExitFromCompensationEVF                ,0xfc254ca9) // search for "ExpOff"
NHSTUB(ExpCtrlTool_StartContiAE               ,0xfc2428f9) // search for "ExpCtrl.c" followed by "StartContiAE"
NHSTUB(ExpCtrlTool_StopContiAE                ,0xfc2429d9) // search for "ExpCtrl.c" followed by "StopContiAE"
NHSTUB(Feof_Fut                               ,0xfc2b038d) // next after after Fseek a jump table
NHSTUB(Fflush_Fut                             ,0xfc2b03b5) // directly after Feof_Fut in ROM
NHSTUB(GetDrive_TotalClusters                 ,0xfc309325) // function immediately before GetDrive_FreeClusters in ROM
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xfc2c77d9) // in "FocusLensController.c" just before a call to GetFocusLensSubjectDistance
NHSTUB(GetImageFolder                         ,0xfc2abc39) //?matches SX60 - close on G7x or SX280 - search routines with "CobjMngr.c" and compare each find to code for SX60
NHSTUB(MakeSDCardBootable                     ,0xfc309733) // in function before ref to "SCRIPT" @0xfc3092ae                                              
NHSTUB(realloc                                ,0xfc4c5acd) // called just before string "fatal error - scanner input buffer overflow"                                              
NHSTUB(reboot_fw_update                       ,0xfc390561) // look for "FirmUpgrade.c"                                              
//NHSTUB(RefreshPhysicalScreen                  ,0xfc15a367) // look for "Reduce ScreenUnLock"
NHSTUB(RenameFile_Fut                         ,0xfc2b013d) // found after a call to PrepareDirectory_1
NHSTUB(Restart                                ,0xfc0b59b5) // one of the calls to StopRedirectUART_FW
NHSTUB(SetFileAttributes                      ,0xfc309ab1) // function following SetFileTimeStamp in ROM
NHSTUB(SetFileTimeStamp                       ,0xfc309a9d) // from ref to 0x12cea600 @0xfc309ab0, similar to g7x & sx280hs
NHSTUB(SetHPTimerAfterNow                     ,0xfc1586fd) // call before "BattAdjust.c"
NHSTUB(SetParameterData                       ,0xfc0ccdf1) // same as PTM_BackupUIProperty_FW
NHSTUB(WriteSDCard                            ,0xfc10e525) // above the first occurance of the string "Mounter.c"
NHSTUB(err_init_task                          ,0xfc523811) // search for "\n-- %s() error in init_task() -"
NHSTUB(get_dial_hw_position                   ,0xfc42faa7) // match to g7x address  ( search for 0xd9850000 until you find a match )
NHSTUB(LogCameraEvent                         ,0xfc308517)
NHSTUB(captseq_raw_addr_init                  ,0xfc155347) // from code hooked in capt_seq.c 
NHSTUB(SetZoomActuatorSpeedPercent            ,NULL_SUB)   // most recent cams don't support this

//******* values below need to be checked *************
//NHSTUB(refresh_bitmap_buf_from                ,NULL_SUB)


