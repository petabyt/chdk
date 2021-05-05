#include "stubs_asm.h"

// BEWARE: thumb functions NEED the thumb bit in the below list

#define NULL_SUB 0xFC066A49 // bx lr

NHSTUB(EnterToCompensationEVF                 ,0xFC2D38E5)
NHSTUB(ExitFromCompensationEVF                ,0xFC2D3927)
NHSTUB(ExpCtrlTool_StartContiAE               ,0xFC2CDB5B)
NHSTUB(ExpCtrlTool_StopContiAE                ,0xFC2CDD4D)
NHSTUB(Feof_Fut                               ,0xfc3b8fdd)
NHSTUB(Fflush_Fut                             ,0xfc3b9005)
NHSTUB(GetDrive_TotalClusters                 ,0xfc3b738f) // function immediately before GetDrive_FreeClusters in ROM
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xfc3ba223)
NHSTUB(GetImageFolder                         ,0xfc39d655)
NHSTUB(MakeSDCardBootable                     ,0xfc3b68af)
NHSTUB(RenameFile_Fut                         ,0xfc3b8d8d)
NHSTUB(SetFileTimeStamp                       ,0xfc3b5f07)
NHSTUB(TurnOffBackLight                       ,0xFC15BB35)  // Does not do anything?
NHSTUB(TurnOnBackLight                        ,0xFC15BB31)  // Does not do anything?
NHSTUB(apex2us                                ,0xfc25f5cb)
NHSTUB(err_init_task                          ,0xFC06647B)
NHSTUB(mkdir                                  ,0xfc3b5fbf)
NHSTUB(realloc                                ,0xfc5e535d)
NHSTUB(reboot_fw_update                       ,0xFC28B97D)
NHSTUB(CancelHPTimer                          ,0xFC165D89)

NHSTUB(VTMLock                                ,0xfc3be3bf)
NHSTUB(VTMUnlock                              ,0xfc3be5e7)

NHSTUB(GetActiveViewportBuffer                ,0xfc108e67)

NHSTUB(displayblankscreen,                     0xFC3532E7)
NHSTUB(undisplayblankscreen,                   0xFC353385)

// Does not work - use workaround in lib.c
IGNORE(Restart)
//NHSTUB(Restart                                ,0xFC0C306F)

// Ignore event proc versions, use inner functions from wrapper
IGNORE(PutInNdFilter)
IGNORE(PutOutNdFilter)
IGNORE(MoveFocusLensToDistance)
NHSTUB(PutInNdFilter_FW                       ,0xfc1ca7fb)
NHSTUB(PutOutNdFilter_FW                      ,0xfc1ca825)
NHSTUB(MoveFocusLensToDistance_FW             ,0xfc667c4b)

//// required because DryOS >=54 functions assert on unitialized event flag, sem etc
//// see https://chdk.setepontos.com/index.php?topic=12516.0
//NHSTUB(init_focus_eventflag                   ,0xfc667e47) // InitializeAdjustmentSystem->fc662948->fc667e0a event flag matches MoveFocusLensToDistance
//NHSTUB(init_nd_eventflag                      ,0xfc667f49) // InitializeAdjustmentSystem->fc662948->fc667f1c event flag matches PutInNdFilter

// gets raw address and other stuff for next shot, stores in structure pointed to by r1
// via sub_fc08ec20, sub_fc1e56a6 called from capt_seq_task. Calls sub_fc0d3b56 to get raw address
NHSTUB(captseq_raw_addr_init                  ,0xfc09bf49)

// To find these values it is easiest to use the Ghidra de-compile window.
   DEF(debug_logging_ptr                      ,0x00022078)  // RAM address of function called by mzrm_sendmsg for logging
                                                            // To find debug_logging_ptr:
                                                            //   Start at the mzrm_sendmsg function.
                                                            //   Find the function call via memory pointer with first parameter = "SendMsg   : %d\n" string
                                                            //   debug_logging_ptris the memory address that contains the pointer used to make this function call
   DEF(debug_logging_flag                     ,0x00022070)  // RAM address of flag to enable logging call
                                                            // To find debug_logging_flag:
                                                            //   Just before the debug_logging_ptrfound above there is an if statement that tests both a memory value and
                                                            //   the debug_logging_ptrvalue.
                                                            //   debug_logging_flag is the memory address of the flag value in the if statement.
   DEF(mzrm_sendmsg_ret_adr                   ,0xfc361fa9)  // Thumb address to check against LR register to detect mzrm_sendmag call from Canon UI update
                                                            //   This is the address immediately after the call to debug_logging_ptrin mzrm_sendmsg (+1 for thumb)
   DEF(hdmi_buffer_check_adr                  ,0x41141000)  // For HDMI output we only want to flag UI updates when layer 0 is set to this buffer address
                                                            //   Start at the transfer_src_overlay function, then go to the last function called
                                                            //   Now find the function call just after the "MakeOsdVram.c" DebugAssert call.
                                                            //   The value is the second parameter to this function.

// These don't exist
NHSTUB(PT_PlaySound                           ,NULL_SUB)
NHSTUB(ScreenLock                             ,NULL_SUB)
NHSTUB(ScreenUnlock                           ,NULL_SUB)
NHSTUB(SetFileAttributes                      ,NULL_SUB)
NHSTUB(SetZoomActuatorSpeedPercent            ,NULL_SUB)
NHSTUB(UnsetZoomForMovie                      ,NULL_SUB)
NHSTUB(WriteSDCard                            ,NULL_SUB)
