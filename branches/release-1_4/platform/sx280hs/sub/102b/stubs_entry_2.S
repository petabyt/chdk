#include "stubs_asm.h"

// BEWARE: thumb functions NEED the thumb bit in the below list

#define NULL_SUB 0xfc021059 // bx lr

NHSTUB(AllocateUncacheableMemory              ,0xfc15a7e5)
NHSTUB(Close                                  ,0xfc2a50fd)
NHSTUB(CreateBinarySemaphore                  ,0x010c5915)
//NHSTUB(CreateTaskStrictly                   ,0x010c5ae5) // 0xfc251c0c is the ARM veneer
NHSTUB(CreateTask                             ,0x010c51fd) // 0xfc251904 is the ARM veneer
DEF(orig_CreateTask                           ,0x010c51fd)
NHSTUB(DebugAssert                            ,0xfc251d14)
NHSTUB(DeleteDirectory_Fut                    ,0xfc28fd4d)
NHSTUB(DeleteFile_Fut                         ,0xfc28fd03)
NHSTUB(DoAELock                               ,0xfc20df41)
NHSTUB(DoAFLock                               ,0xfc20dc47)
NHSTUB(EnterToCompensationEVF                 ,0xfc20deb7)
NHSTUB2(ExecuteEventProcedure                  ,0xfc29ab19) // needs ARM wrapper due to CHDK call_func_ptr calls
NHSTUB(ExitFromCompensationEVF                ,0xfc20def3)
NHSTUB(ExitTask                               ,0xfc2512b1) // thumb!!
NHSTUB(ExpCtrlTool_StartContiAE               ,0xfc204f97)
NHSTUB(ExpCtrlTool_StopContiAE                ,0xfc205077)
NHSTUB(Fclose_Fut                             ,0xfc28fdaf)
NHSTUB(Feof_Fut                               ,0xfc28fef1)
NHSTUB(Fflush_Fut                             ,0xfc28ff19)
NHSTUB(Fgets_Fut                              ,0xfc28fe8d)
NHSTUB(Fopen_Fut                              ,0xfc28fd87)
NHSTUB(Fread_Fut                              ,0xfc28fe21)
NHSTUB(FreeUncacheableMemory                  ,0xfc15a811)
NHSTUB(Fseek_Fut                              ,0xfc28febf)
NHSTUB(Fwrite_Fut                             ,0xfc28fe57)
NHSTUB(GetBatteryTemperature                  ,0xFC138F45)
NHSTUB(GetCCDTemperature                      ,0xFC138F43)
NHSTUB(GetCurrentAvValue                      ,0xfc19e9b9)
NHSTUB(GetDrive_ClusterSize                   ,0xfc2a4637)
NHSTUB(GetDrive_FreeClusters                  ,0xfc2a4b8b)
NHSTUB(GetDrive_TotalClusters                 ,0xfc057747)
NHSTUB(GetFocusLensSubjectDistance            ,0xfc28c58b)
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xfc28c84f)
NHSTUB(GetImageFolder                         ,0xfc25d4d9)
NHSTUB(GetKbdState                            ,0xfc05f577)
NHSTUB(GetMemInfo                             ,0xfc12dfb1)
NHSTUB(GetOpticalTemperature                  ,0xFC138F41)
NHSTUB(GetParameterData                       ,0xfc09091f)
NHSTUB(GetPropertyCase                        ,0xfc297839)
NHSTUB(GetSystemTime                          ,0xfc3b980d) // _GetSystemTime fc2a555e
NHSTUB(GetVRAMHPixelsSize                     ,0xfc134981)
NHSTUB(GetVRAMVPixelsSize                     ,0xfc134989)
NHSTUB(GetZoomLensCurrentPoint                ,0xfc1a0c71)
NHSTUB(GetZoomLensCurrentPosition             ,0xfc1a0c05)
NHSTUB(GiveSemaphore                          ,0xfc251c3c) // arm
NHSTUB(IsStrobeChargeCompleted                ,0xfc17196b)
NHSTUB(LEDDrive                               ,0xfc1a73d9)
NHSTUB(LocalTime                              ,0xfc251b54) // arm
NHSTUB(LockMainPower                          ,0xfc142d85)
NHSTUB(MakeDirectory_Fut                      ,0xfc2a536f) // mkdir
NHSTUB(MakeSDCardBootable                     ,0xfc2a4f67)
NHSTUB(MoveFocusLensToDistance                ,0xfc3de38b)
NHSTUB(MoveIrisWithAv                         ,0xfc3b7d89)
NHSTUB(MoveZoomLensWithPoint                  ,0xfc3b850f)
NHSTUB(Open                                   ,0xfc2a50fb)
NHSTUB(PB2Rec                                 ,0xfc0c0985)
NHSTUB(PT_MoveDigitalZoomToWide               ,0xfc20d741)
NHSTUB(PT_MoveOpticalZoomAt                   ,0xfc1a827d)
NHSTUB(PT_PlaySound                           ,0xfc148f2d)
NHSTUB(PostLogicalEventForNotPowerType        ,0xfc2a60e1)
NHSTUB(PostLogicalEventToUI                   ,0xfc2a610d)
NHSTUB(PutInNdFilter                          ,0xfc3dd8f9)
NHSTUB(PutOutNdFilter                         ,0xfc3dd91f)
NHSTUB(Read                                   ,0xfc0ba575) // j_Read fc2a519f
NHSTUB(ReadFastDir                            ,0xfc1081d1)
NHSTUB(Rec2PB                                 ,0xfc0c09b7)
NHSTUB(RefreshPhysicalScreen                  ,0xfc143599)
NHSTUB(RenameFile_Fut                         ,0xfc28fca1)
NHSTUB(Restart                                ,0xfc095c41)
NHSTUB(ScreenLock                             ,0xfc143bd3)
NHSTUB(ScreenUnlock                           ,0xfc143c0b)
NHSTUB(SetAE_ShutterSpeed                     ,0xfc3e0505)
NHSTUB(SetAutoShutdownTime                    ,0xfc142dd1)
NHSTUB(SetCurrentCaptureModeType              ,0xfc27666d)
NHSTUB(SetFileAttributes                      ,0xfc2a5319)
NHSTUB(SetFileTimeStamp                       ,0xfc2a52d1)
NHSTUB(SetLogicalEventActive                  ,0xfc2b00db)
NHSTUB(SetParameterData                       ,0xfc09089f)
NHSTUB(SetPropertyCase                        ,0xfc297713)
NHSTUB(SetScriptMode                          ,0xfc2b0113)
NHSTUB(SleepTask                              ,0xfc251cb4) // arm
NHSTUB(TakeSemaphore                          ,0xfc251c24) // arm
NHSTUB(TurnOffBackLight                       ,0xfc0d2997)
NHSTUB(TurnOnBackLight                        ,0xfc0d2985)
NHSTUB(TurnOnDisplay                          ,0xfc136d45)
NHSTUB(TurnOffDisplay                         ,0xfc136d4f)
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xfc1b1dc3)
NHSTUB(UnlockAE                               ,0xfc20df5f)
NHSTUB(UnlockAF                               ,0xfc20dc6f)
NHSTUB(UnlockMainPower                        ,0xfc142d25)
NHSTUB(VbattGet                               ,0xfc12ec71)
NHSTUB(Write                                  ,0xfc2a51a3)
NHSTUB(WriteSDCard                            ,0xfc19bb17)
NHSTUB(_log                                   ,0x010dbe08) // arm, has no veneer
NHSTUB(_log10                                 ,0xfc251b7c) // arm
NHSTUB(_pow                                   ,0xfc251b2c) // arm
NHSTUB(_sqrt                                  ,0x010de238) // arm, has no veneer
NHSTUB(add_ptp_handler                        ,0xfc0df5c3)
NHSTUB(apex2us                                ,0xfc0a950f)
NHSTUB(close                                  ,0xfc0ba46f)
NHSTUB(err_init_task                          ,0xfc04f3b9)
NHSTUB(exmem_alloc                            ,0xfc062729)
NHSTUB(exmem_free                             ,0xfc062779)
NHSTUB(free                                   ,0xfc2b7eeb)
NHSTUB(kbd_p1_f                               ,0xfc0604e5)
NHSTUB(kbd_p1_f_cont                          ,0xfc0604ed)
NHSTUB(kbd_p2_f                               ,0xfc05ffc1)
NHSTUB(kbd_read_keys                          ,0xfc0604af)
NHSTUB(kbd_read_keys_r2                       ,0xfc06091d)
NHSTUB(lseek                                  ,0xfc2a51e1)
NHSTUB(malloc                                 ,0xfc2b7eb5)
NHSTUB(memcmp                                 ,0xfc2b7f93)
NHSTUB(memcpy                                 ,0xfc0d32e1)
NHSTUB(memset                                 ,0xfc2be999)
NHSTUB(mkdir                                  ,0xfc2a536f)
NHSTUB(mktime_ext                             ,0xfc14a5dd)
NHSTUB(open                                   ,0xfc0ba3ff)
NHSTUB(OpenFastDir                            ,0xfc108131)
NHSTUB(closedir                               ,0xfc1080f9)
NHSTUB(qsort                                  ,0xfc2be953)
NHSTUB(rand                                   ,0xfc0d32c3)
NHSTUB(realloc                                ,0xfc42adb1)
NHSTUB(reboot_fw_update                       ,0xfc335235)
NHSTUB(set_control_event                      ,0xfc2afe21)
NHSTUB(srand                                  ,0xfc0d32bd)
NHSTUB(stat                                   ,0xfc2a5219)
NHSTUB(strcat                                 ,0xfc14a9c9)
NHSTUB(strchr                                 ,0xfc0d3375)
NHSTUB(strcmp                                 ,0xfc2b7dd1)
NHSTUB(strcpy                                 ,0xfc2b7e19)
NHSTUB(strftime                               ,0xfc14a60d)
NHSTUB(strlen                                 ,0xfc2b7e29)
NHSTUB(strncmp                                ,0xfc14aa15)
NHSTUB(strncpy                                ,0xfc2b7df5)
NHSTUB(strrchr                                ,0xfc0d3387)
NHSTUB(strtol                                 ,0xfc09b63b)
NHSTUB(strtolx                                ,0xfc09b4f9)
   DEF(task_CaptSeq                           ,0xfc0cdb9f)
   DEF(task_ExpDrv                            ,0xfc1e93c9)
   DEF(task_FileWrite                         ,0xfc05509d)
   DEF(task_InitFileModules                   ,0xfc088221)
   DEF(task_MovieRecord                       ,0xfc1a5d09)
   DEF(task_PhySw                             ,0xfc0601f5)
   DEF(task_DvlpSeq                           ,0xfc1aa7fb)
NHSTUB(time                                   ,0xfc251c9c) // arm
NHSTUB(vsprintf                               ,0xfc09b4cb)
NHSTUB(EngDrvRead                             ,0xfc2b7cab)
NHSTUB(CancelHPTimer                          ,0xfc1423c9)
NHSTUB(SetHPTimerAfterNow                     ,0xfc142331)
NHSTUB(PT_MFOn                                ,0xfc20ee17)
NHSTUB(PT_MFOff                               ,0xfc20ee47)
NHSTUB(GetAdChValue                           ,0xfc0c33c7)
NHSTUB(PTM_GetCurrentItem                     ,0xfc2b064f)
NHSTUB(get_fstype                             ,0xfc2a45d1)


// additional...
NHSTUB(displaybusyonscreen,                    0xfc14a149)
NHSTUB(undisplaybusyonscreen,                  0xfc14a27f)

// trial
NHSTUB(refresh_bitmap_buf_from,                0xfc143435)

// These don't exist
NHSTUB(SetZoomActuatorSpeedPercent, NULL_SUB)
NHSTUB(UnsetZoomForMovie,           NULL_SUB)

