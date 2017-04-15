#include "stubs_asm.h"

// BEWARE: thumb functions NEED the thumb bit in the below list

#define NULL_SUB 0xFC0211F1 // bx lr

NHSTUB(AllocateUncacheableMemory              ,0xFC1536A5)
NHSTUB(Close                                  ,0xFC37A579)
//NHSTUB(CreateTaskStrictly                   ,0xBFE15509) // 0xfc251c0c is the ARM veneer
NHSTUB(CreateTask                             ,0xBFE14A31) // 0xfc251904 is the ARM veneer
DEF(orig_CreateTask                           ,0xBFE14A31)
NHSTUB(DebugAssert                            ,0xFC302410)
NHSTUB(DeleteDirectory_Fut                    ,0xFC373F15)
NHSTUB(DeleteFile_Fut                         ,0xFC373ECB)
NHSTUB(DoAELock                               ,0xFC0AA83F)
NHSTUB(DoAFLock                               ,0xFC0AA4A1)
NHSTUB(EnterToCompensationEVF                 ,0xFC0AA66B)
NHSTUB2(ExecuteEventProcedure                 ,0xFC327CC5) // needs ARM wrapper due to CHDK call_func_ptr calls
NHSTUB(ExitFromCompensationEVF                ,0xFC0AA6A7)
NHSTUB(ExitTask                               ,0xFC3022C8) // thumb!!
NHSTUB(ExpCtrlTool_StartContiAE               ,0xFC2AAC61)
NHSTUB(ExpCtrlTool_StopContiAE                ,0xFC2AAEB5)
NHSTUB(Fclose_Fut                             ,0xFC373F77)
NHSTUB(Feof_Fut                               ,0xFC3740B9)
NHSTUB(Fflush_Fut                             ,0xFC3740E1)
NHSTUB(Fgets_Fut                              ,0xFC374055)
NHSTUB(Fopen_Fut                              ,0xFC373F4F)
NHSTUB(Fread_Fut                              ,0xFC373FE9)
NHSTUB(FreeUncacheableMemory                  ,0xFC1536D1)
NHSTUB(Fseek_Fut                              ,0xFC374087)
NHSTUB(Fwrite_Fut                             ,0xFC37401F)
NHSTUB(GetBatteryTemperature                  ,0xFC1F6261)
NHSTUB(GetCCDTemperature                      ,0xFC1F625F)
NHSTUB(GetCurrentAvValue                      ,0xFC318E87) // or FC318E2F
NHSTUB(GetDrive_ClusterSize                   ,0xFC379ADF)
NHSTUB(GetDrive_FreeClusters                  ,0xFC379FE3)
NHSTUB(GetDrive_TotalClusters                 ,0xFC06BF33)
NHSTUB(GetFocusLensSubjectDistance            ,0xFC35FB2B)
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xFC35FCAB) //???
NHSTUB(GetImageFolder                         ,0xFC303C41) //???
NHSTUB(GetKbdState                            ,0xFC07425B)
NHSTUB(GetMemInfo                             ,0xFC5A136D)
NHSTUB(GetOpticalTemperature                  ,0xFC1F625D)
NHSTUB(GetParameterData                       ,0xFC278531)
NHSTUB(GetPropertyCase                        ,0xFC373499)
NHSTUB(GetSystemTime                          ,0xFC450A01) // _GetSystemTime fc2a555e
NHSTUB(GetVRAMHPixelsSize                     ,0xFC133D9D)
NHSTUB(GetVRAMVPixelsSize                     ,0xFC133DA5)
NHSTUB(GetZoomLensCurrentPoint                ,0xFC1861CF)
NHSTUB(GetZoomLensCurrentPosition             ,0xFC186183)
NHSTUB(GiveSemaphore                          ,0xBFE15479) //FC302310) // arm
NHSTUB(IsStrobeChargeCompleted                ,0xFC4F3041)
NHSTUB(LEDDrive                               ,0xFC188F59)
NHSTUB(LocalTime                              ,0xFCCAC3FD) // ??? !arm -> thumb
NHSTUB(LockMainPower                          ,0xFC1FD09F)
NHSTUB(MakeDirectory_Fut                      ,0xFC37A7EB) // mkdir
NHSTUB(MakeSDCardBootable                     ,0xFC37A34D)
NHSTUB(MoveFocusLensToDistance                ,0xFC44B80D) // MoveFocusLensWithDistance
NHSTUB(MoveIrisWithAv                         ,0xFC44C48D)
NHSTUB(MoveZoomLensWithPoint                  ,0xFC44D049)
NHSTUB(Open                                   ,0xFC37A577)
NHSTUB(PB2Rec                                 ,0xFC32A941)
NHSTUB(PT_MoveDigitalZoomToWide               ,0xFC0A9E45)
NHSTUB(PT_MoveOpticalZoomAt                   ,0xFC189EC1)
NHSTUB(PT_PlaySound                           ,0xFC37763B) // ???
NHSTUB(PostLogicalEventForNotPowerType        ,0xFC37E801)
NHSTUB(PostLogicalEventToUI                   ,0xFC37E835)
NHSTUB(PutInNdFilter                          ,0xFC44CEB1) // TurnOnNdFilter
NHSTUB(PutOutNdFilter                         ,0xFC44CECB) // TurnOffNdFilter
NHSTUB(Read                                   ,0xFC1EE4B5) // j_Read fc2a519f
NHSTUB(ReadFastDir                            ,0xFC11C63D)
NHSTUB(Rec2PB                                 ,0xFC32A987)
NHSTUB(RefreshPhysicalScreen                  ,0xFC37EF9F) // FC37F03F) //FC37EF19) //FC37EF9F) // ???
NHSTUB(RenameFile_Fut                         ,0xFC373E69)
NHSTUB(Restart                                ,0xFC1311DD)
NHSTUB(ScreenLock                             ,0xFC37F5DB)
NHSTUB(ScreenUnlock                           ,0xFC37F619)
NHSTUB(SetAE_ShutterSpeed                     ,0xFC5A4FE1)
NHSTUB(SetAutoShutdownTime                    ,0xFC1FD0EB)
NHSTUB(SetCurrentCaptureModeType              ,0xFC36CAC9)
NHSTUB(SetFileAttributes                      ,0xFC37A795)
NHSTUB(SetFileTimeStamp                       ,0xFC37A74D)
NHSTUB(SetLogicalEventActive                  ,0xFC363471)
NHSTUB(SetParameterData                       ,0xFC2784BD)
NHSTUB(SetPropertyCase                        ,0xFC373347)
NHSTUB(SetScriptMode                          ,0xFC3634A9)
NHSTUB(SleepTask                              ,0xFC3022E0) // arm
NHSTUB(TakeSemaphore                          ,0xBFE15401) //0xFC302318) // arm
NHSTUB(TurnOffBackLight                       ,0xFC14B9E7)
NHSTUB(TurnOnBackLight                        ,0xFC14B9D5)
NHSTUB(TurnOnDisplay                          ,0xFC14B9AD)
NHSTUB(TurnOffDisplay                         ,0xFC14B9C3)
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xFC38B533)
NHSTUB(UnlockAE                               ,0xFC0AA85D)
NHSTUB(UnlockAF                               ,0xFC0AA4D1)
NHSTUB(UnlockMainPower                        ,0xFC1FD037)
NHSTUB(VbattGet                               ,0xFC188F55)
NHSTUB(Write                                  ,0xFC37A61F)
NHSTUB(WriteSDCard                            ,0xFCCAD9EB)
NHSTUB(_log                                   ,0x01102BC8) // arm, has no veneer
NHSTUB(_log10                                 ,0xFC302380) // arm
NHSTUB(_pow                                   ,0xFC3017A8) // arm
NHSTUB(_sqrt                                  ,0x011052D0) // arm, has no veneer
NHSTUB(add_ptp_handler                        ,0xFC16B9D7) 
NHSTUB(apex2us                                ,0xFC3F41DF) //???
NHSTUB(close                                  ,0xFC1EE3AF)
NHSTUB(err_init_task                          ,0xFC06316B)
NHSTUB(exmem_alloc                            ,0xFC078D63)
NHSTUB(exmem_free                             ,0xFC078DA3)
NHSTUB(free                                   ,0xFC37FE8B)
NHSTUB(kbd_p1_f                               ,0xFC083EAD)
NHSTUB(kbd_p1_f_cont                          ,0xFC083EB5)
NHSTUB(kbd_p2_f                               ,0xFC083915)
NHSTUB(kbd_read_keys                          ,0xFC083E77)
NHSTUB(kbd_read_keys_r2                       ,0xFC074EB7)
NHSTUB(lseek                                  ,0xFC37A65D)
NHSTUB(malloc                                 ,0xFC37FE55)
NHSTUB(memcmp                                 ,0xFC3800D9)
NHSTUB(memcpy                                 ,0xFC200331)
NHSTUB(memset                                 ,0xFC1159E5)
NHSTUB(mkdir                                  ,0xFC37A7EB)
NHSTUB(mktime_ext                             ,0xFC1FFF41)
NHSTUB(open                                   ,0xFC1EE33F)
NHSTUB(OpenFastDir                            ,0xFC11C59D)
NHSTUB(closedir                               ,0xFC11C565)
NHSTUB(qsort                                  ,0xFC3C86AD)
NHSTUB(rand                                   ,0xFC0FC1AB)
NHSTUB(realloc                                ,0xFC4F9F61)
NHSTUB(reboot_fw_update                       ,0xFC450121)
NHSTUB(set_control_event                      ,0xFC3631E5)
NHSTUB(srand                                  ,0xFC0FC1A5)
NHSTUB(stat                                   ,0xFC37A695)
NHSTUB(strcat                                 ,0xFC37FEBD)
NHSTUB(strchr                                 ,0xFC200419)
NHSTUB(strcmp                                 ,0xFC37FFF1)
NHSTUB(strcpy                                 ,0xFC37FEDF)
NHSTUB(strftime                               ,0xFC1FFF71)
NHSTUB(strlen                                 ,0xFC380063)
NHSTUB(strncmp                                ,0xFC2003EF)
NHSTUB(strncpy                                ,0xFC37BEFD)
NHSTUB(strrchr                                ,0xFC14C22D)
NHSTUB(strtol                                 ,0xFC14C21F)
NHSTUB(strtolx                                ,0xFC14C0DD)
   DEF(task_CaptSeq                           ,0xFC0BD907) //???
   DEF(task_ExpDrv                            ,0xFC2BC92D)
   DEF(task_FileWrite                         ,0xFC068B89)
   DEF(task_InitFileModules                   ,0xFC0F79A1)
   DEF(task_MovieRecord                       ,0xFC142AD5)
   DEF(task_PhySw                             ,0xFC083BC5)
   DEF(task_DvlpSeq                           ,0xFC110A77)
NHSTUB(time                                   ,0xFC302048) // arm 
NHSTUB(vsprintf                               ,0xFC0D7383)
NHSTUB(EngDrvRead                             ,0xFC37FF31)
NHSTUB(CancelHPTimer                          ,0xFC1FCBB1)
NHSTUB(SetHPTimerAfterNow                     ,0xFC1FCB19)
NHSTUB(PT_MFOn                                ,0xFC0AB61D)
NHSTUB(PT_MFOff                               ,0xFC0AB651)
NHSTUB(GetAdChValue                           ,0xFC1F3577)
NHSTUB(PTM_GetCurrentItem                     ,0xFC36E567)
NHSTUB(get_fstype                             ,0xFC379A79)


// additional...
NHSTUB(displaybusyonscreen,                    0xFC332FF7)
NHSTUB(undisplaybusyonscreen,                  0xFC33308D)

NHSTUB(CreateBinarySemaphore                  ,0xBFE1530D) //0xFCCBECDC)
//NHSTUB(TakeSemaphore                          ,0xFC3018B3)
NHSTUB(TryTakeSemaphore                       ,0xBFE153D1) // FC3017BB)

NHSTUB(LogCameraEvent,			       0xFC361A33)  

NHSTUB(LCDMsg_Create				,0xFC51F6CB)
NHSTUB(LCDMsg_SetStr				,0xFC51F3FF)
//NHSTUB(System.Create				,0xFC189AE3)
//NHSTUB(sprintf 						,0xFC380163)

NHSTUB(GetLensFocalLengthAll                  ,0xFC25D0BF)

// trial
NHSTUB(refresh_bitmap_buf_from,                0xfc143435)

// These don't exist
NHSTUB(SetZoomActuatorSpeedPercent, NULL_SUB)
NHSTUB(UnsetZoomForMovie,           NULL_SUB)

