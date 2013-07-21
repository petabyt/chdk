// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R47 (DRYOS version 2.3, release #0047)
//   Firmware Ver GM1.00C
//   Canon PowerShot SX230 HS

// Values for makefile.inc
//   PLATFORMOSVER = 47
//   PLATFORMID = 12840 (0x3228) // Found @ 0xfff40040
//   MAXRAMADDR = 0x07ffffff
//   MEMISOSTART = 0x0018a7fc
//   KEYSYS = d4c                // Found @ 0xffff3610
//   NEED_ENCODED_DISKBOOT = 6   // Found @ 0xffff3620

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NHSTUB(Restart                              ,0xff02d4cc) //106        *** != 0xff02d3d0
//NHSTUB(kbd_pwr_off                          ,0xff0577e4) //  2 60%    *** != 0x00000000
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff097164 -> ff093588 -> ff1b82c8 -> ff32314c -> ff4954a0
// Mode 16936 in firmware but not in current modemap
// Mode 16938 in firmware but not in current modemap

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x000358e8) // Found @0xff024d10
DEF(physw_run                               ,0x00001c44) // Found @0xff0248a4
DEF(physw_sleep_delay                       ,0x00001c4c) // Found @0xff0248a4
DEF(levent_table                            ,0xff42121c) // Found @0xff42121c
DEF(FlashParamsTable                        ,0xff4956ec) // Found @0xff4956ec
DEF(movie_status                            ,0x00008624) // Found @0xff18c580
DEF(video_compression_rate                  ,0x00008664) // Found @0xff18cffc
DEF(full_screen_refresh                     ,0x0000b440) // Found @0xff244890
DEF(canon_menu_active                       ,0x000042d4) // Found @0xff08ca84
DEF(canon_shoot_menu_active                 ,0x00009995) // Found @0xff1d45b4
DEF(playrec_mode                            ,0x00004008) // Found @0xff07ed14
//DEF(zoom_status                             ,0x0000f6bc) // Found @0xff326800, ** != ** stubs_min = 0x0000f69c (0x0000f69c)
DEF(some_flag_for_af_scan                   ,0x00008a28) // Found @0xff190c5c
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 3 int value(s), the first is the zoom focus length.
// there are 126 entries in the table - set NUM_FL to 126
DEF(focus_len_table                         ,0xfff4a3dc) // Found @0xfff4a3dc
DEF(zoom_busy                               ,0x00008548) // Found @0xff187708
DEF(focus_busy                              ,0x000083c4) // Found @0xff181c8c
//DEF(recreview_hold                          ,0x00004e04) // Found @0xff0a00d8, ** != ** stubs_min = 0x0000956c (0x947C+0xF0)
// Palette colour tables  found @ 0xff4407d8
DEF(palette_control                         ,0x0000b440) // Found @0xff24480c
DEF(active_palette_buffer                   ,0x0000b448) // Found @0xff244810
DEF(palette_buffer_ptr                      ,0x0000b44c) // Found @0xff244cd8
DEF(palette_buffer                          ,0x000ceb38) // Found @0xff244ce8
// Offset from start of palette_buffer to color data = 8 (Found @0xff360bd8)
DEF(bitmap_buffer                           ,0x0000b480) // Found @0xff249960
DEF(active_bitmap_buffer                    ,0x0000b478) // Found @0xff249964
DEF(viewport_buffers                        ,0xff3bbd24) // Found @0xff043e44
DEF(active_viewport_buffer                  ,0x00002108) // Found @0xff043b04
// Camera has 2 RAW buffers @ 0x413591f0 & 0x46000000
//  Note: active buffer --> raw_buffers[ active_raw_buffer   *3]
//        other buffer  --> raw_buffers[(active_raw_buffer^1)*3]
DEF(raw_buffers                             ,0xff3bd710) // Found @0xff3bd710
DEF(active_raw_buffer                       ,0x00003f64) // Found @0xff07b0ec

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x40471000; }             // Found @0xff0514b4
//void *vid_get_viewport_fb()      { return (void*)0x405d7980; }             // Found @0xff37c474
DEF(viewport_fb_d                           ,0x00003d28) // Found 0x3cd0 (@0xff06e82c) + 0x58 (@0xff06e864)
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x3cd0+0x58)); } // Found @0xff06e82c & 0xff06e864
DEF(jpeg_count_str                          ,0x000ce488) // Found @0xff239850
//char *camera_jpeg_count_str()    { return (char*)0x000ce488; }             // Found @0xff239850
//long hook_raw_size()             { return 0x0123eaf0; }                    // Found @0xff37f988
//int get_flash_params_count(void) { return 0xa0; }                          // Found @0xff1b9300

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xff3bcf0c, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x04000000 // Found @0xff3bcf44, levent 0x902
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_DISPLAY         ,0x00000800 }, // Found @0xff3bce7c, levent 0x0a
//    { 0, KEY_UP              ,0x00001000 }, // Found @0xff3bce84, levent 0x04
//    { 0, KEY_RIGHT           ,0x00004000 }, // Found @0xff3bce94, levent 0x07
//    { 0, KEY_SET             ,0x00010000 }, // Found @0xff3bcea4, levent 0x08
//    { 0, KEY_DOWN            ,0x00020000 }, // Found @0xff3bceac, levent 0x05
//    { 0, KEY_MENU            ,0x00040000 }, // Found @0xff3bceb4, levent 0x09
//    { 0, KEY_VIDEO           ,0x00080000 }, // Found @0xff3bcebc, levent 0x12
//    { 1, KEY_PLAYBACK        ,0x00200000 }, // Found @0xff3bcec4, levent 0x601
//    { 2, KEY_SHOOT_FULL      ,0x00002002 }, // Found @0xff3bced4, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00002000 }, // Found @0xff3bcef4, levent 0x00
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000002 }, // Found @0xff3bced4, levent 0x01
//    { 2, KEY_LEFT            ,0x00000100 }, // Found @0xff3bcee4, levent 0x06
//    { 2, KEY_POWER           ,0x00000800 }, // Found @0xff3bceec, levent 0x600
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#define CAM_RAW_ROWPIX    4168 // Found @0xff156314
//#define CAM_RAW_ROWS      3060 // Found @0xff156320
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff02bcb8

// Misc stuff
DEF(ctypes, 0xff3ba346)

// For capt_seq.c
DEF(_nrflag,0x8a6c) // Found @ ff195a50 (0x8a64) & ff195a8c (+0x08)
//static long *nrflag = (long*)(0x8a64+0x08);  // Found @ ff195a50 & ff195a8c
//#define NR_AUTO (0)                          // have to explictly reset value back to 0 to enable auto

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
//NHSTUB(CreateJumptable                      ,0xff37fb54) //  1
//NHSTUB(_uartr_req                           ,0xff00fda8) //111
//NHSTUB(StartRecModeMenu                     ,0xff08ca80) //102
//NHSTUB(AllocateMemory                       ,0xff311904) //101
NHSTUB(AllocateUncacheableMemory              ,0xff02bc70) //112
NHSTUB(Close                                  ,0xff027ae4) //101
//NHSTUB(CreateBinarySemaphore                ,0xff02b42c) //115
//NHSTUB(CreateCountingSemaphore              ,0xff02b494) //105
NHSTUB(CreateTask                             ,0xff00e9a8) //101
NHSTUB(DebugAssert                            ,0xff00ec80) //111
NHSTUB(DeleteDirectory_Fut                    ,0xff026e50) //116
NHSTUB(DeleteFile_Fut                         ,0xff026d6c) //112
//NHSTUB(DeleteSemaphore                      ,0xff02b4ec) //105
NHSTUB(DoAFLock                               ,0xff029004) //102
NHSTUB(EnterToCompensationEVF                 ,0xff0292a0) //104
NHSTUB(ExecuteEventProcedure                  ,0xff088174) //104
NHSTUB(ExitFromCompensationEVF                ,0xff0292e4) //104
NHSTUB(ExitTask                               ,0xff00ec38) //101
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff03857c) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff038654) //104
NHSTUB(Fclose_Fut                             ,0xff026ee8) //101
NHSTUB(Feof_Fut                               ,0xff0270d4) //  1
NHSTUB(Fflush_Fut                             ,0xff027110) //  1
NHSTUB(Fgets_Fut                              ,0xff02703c) //  6
NHSTUB(Fopen_Fut                              ,0xff026ea8) //101
NHSTUB(Fread_Fut                              ,0xff026f94) //101
//NHSTUB(FreeMemory                           ,0xff3118fc) //101
NHSTUB(FreeUncacheableMemory                  ,0xff02bcb0) //112
NHSTUB(Fseek_Fut                              ,0xff027088) //101
NHSTUB(Fwrite_Fut                             ,0xff026fe8) //101
NHSTUB(GetBatteryTemperature                  ,0xff05e554) //102
NHSTUB(GetCCDTemperature                      ,0xff05e4e0) //102
NHSTUB(GetCurrentAvValue                      ,0xff184680) //102
NHSTUB(GetDrive_ClusterSize                   ,0xff06c2dc) //  6
NHSTUB(GetDrive_FreeClusters                  ,0xff06c334) //  6
NHSTUB(GetDrive_TotalClusters                 ,0xff06c30c) //  6
NHSTUB(GetFocusLensSubjectDistance            ,0xff182910) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff182d70) //  3
NHSTUB(GetImageFolder                         ,0xff15d268) //  6
NHSTUB(GetKbdState                            ,0xff0576ac) //109
NHSTUB(GetMemInfo                             ,0xff00a29c) //115
NHSTUB(GetOpticalTemperature                  ,0xff05e5c8) //102
NHSTUB(GetParameterData                       ,0xff1b92c0) //101
NHSTUB(GetPropertyCase                        ,0xff08bf58) //102
NHSTUB(GetSystemTime                          ,0xff31195c) //101
NHSTUB(GetVRAMHPixelsSize                     ,0xff04659c) //102
NHSTUB(GetVRAMVPixelsSize                     ,0xff0465a8) //102
NHSTUB(GetZoomLensCurrentPoint                ,0xff187b80) //102
NHSTUB(GetZoomLensCurrentPosition             ,0xff2fb048) //102
NHSTUB(GiveSemaphore                          ,0xff02b668) //112
NHSTUB(IsStrobeChargeCompleted                ,0xff0e2d10) //102
NHSTUB(LEDDrive                               ,0xff056a24) //101
NHSTUB(LocalTime                              ,0xff085a08) //115
NHSTUB(LockMainPower                          ,0xff093178) //103
//NHSTUB(Lseek                                ,0xff02766c) //101
NHSTUB(MakeDirectory_Fut                      ,0xff026de0) //116
NHSTUB(MakeSDCardBootable                     ,0xff06c5e8) //105
NHSTUB(MoveFocusLensToDistance                ,0xff378764) //102
NHSTUB(MoveIrisWithAv                         ,0xff30d974) //102
NHSTUB(MoveZoomLensWithPoint                  ,0xff30e138) //102
//NHSTUB(NewTaskShell                         ,0xff08b908) //101
NHSTUB(Open                                   ,0xff0273e8) //101
NHSTUB(PB2Rec                                 ,0xff096484) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff075c88) //102
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff075c60) //102
NHSTUB(PT_PlaySound                           ,0xff080de4) //  6
NHSTUB(PostLogicalEventForNotPowerType        ,0xff090c90) //103
NHSTUB(PostLogicalEventToUI                   ,0xff090cdc) //103
NHSTUB(PutInNdFilter                          ,0xff3763a8) //102
NHSTUB(PutOutNdFilter                         ,0xff3763e0) //102
NHSTUB(Read                                   ,0xff00ad58) //101
NHSTUB(ReadFastDir                            ,0xff2e6f5c) //  6
NHSTUB(Rec2PB                                 ,0xff0964c4) //104
NHSTUB(RefreshPhysicalScreen                  ,0xff0abfec) //104
//NHSTUB(Remove                               ,0xff0275d0) //  6
NHSTUB(RenameFile_Fut                         ,0xff026cd8) //116
NHSTUB(ScreenLock                             ,0xff0ad1b4) //117
NHSTUB(ScreenUnlock                           ,0xff0ad218) //117
NHSTUB(SetAE_ShutterSpeed                     ,0xff37b5ec) //102
NHSTUB(SetAutoShutdownTime                    ,0xff0931ec) //103
NHSTUB(SetCurrentCaptureModeType              ,0xff09cd4c) //101
NHSTUB(SetFileAttributes                      ,0xff027854) //  6
NHSTUB(SetFileTimeStamp                       ,0xff0277dc) //  6
NHSTUB(SetLogicalEventActive                  ,0xff092eb4) //101
NHSTUB(SetParameterData                       ,0xff1b9230) //101
NHSTUB(SetPropertyCase                        ,0xff08be2c) //102
NHSTUB(SetScriptMode                          ,0xff092f04) //101
NHSTUB(SleepTask                              ,0xff02b914) //101
NHSTUB(TakeSemaphore                          ,0xff02b598) //101
NHSTUB(TurnOffBackLight                       ,0xff0a4200) //104
NHSTUB(TurnOnBackLight                        ,0xff0a41e8) //104
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff1a994c) //101
NHSTUB(UnlockAF                               ,0xff02903c) //102
NHSTUB(UnlockMainPower                        ,0xff0930cc) //103
NHSTUB(VbattGet                               ,0xff023074) //101
NHSTUB(Write                                  ,0xff0274b0) //101
NHSTUB(WriteSDCard                            ,0xff171d24) //108
NHSTUB(_log                                   ,0xff3b6dc8) //111
NHSTUB(_log10                                 ,0xff3b7290) //112
NHSTUB(_pow                                   ,0xff3b73f4) //114
NHSTUB(_sqrt                                  ,0xff3b915c) //  6
NHSTUB(add_ptp_handler                        ,0xff291c68) //  6
NHSTUB(apex2us                                ,0xff24de4c) //  4
NHSTUB(close                                  ,0xff00abb4) //  6
NHSTUB(closedir                               ,0xff2e6db8) //  4
NHSTUB(err_init_task                          ,0xff005fd4) //111
NHSTUB(exmem_alloc                            ,0xff0869d0) //101
NHSTUB(exmem_free                             ,0xff086a48) //101
NHSTUB(free                                   ,0xff004244) //112
NHSTUB(kbd_p1_f                               ,0xff024d8c) //109
NHSTUB(kbd_p1_f_cont                          ,0xff024d98) //109
NHSTUB(kbd_p2_f                               ,0xff024574) //109
NHSTUB(kbd_read_keys                          ,0xff024d10) //109
NHSTUB(kbd_read_keys_r2                       ,0xff056ef0) //109
NHSTUB(lseek                                  ,0xff02766c) //101
NHSTUB(malloc                                 ,0xff0041ec) //112
NHSTUB(memcmp                                 ,0xff010928) //101
NHSTUB(memcpy                                 ,0xff031584) //101
NHSTUB(memset                                 ,0xff24ce4c) //101
NHSTUB(mkdir                                  ,0xff0278ec) //109
NHSTUB(mktime_ext                             ,0xff0ae114) //  1
NHSTUB(open                                   ,0xff00ab04) //  6
NHSTUB(OpenFastDir                            ,0xff2e6e08) //  6
NHSTUB(qsort                                  ,0xff36386c) //  6
NHSTUB(rand                                   ,0xff24cf8c) //  6
//NHSTUB(read                                 ,0xff00ad58) //101
NHSTUB(realloc                                ,0xff24cec8) //115
NHSTUB(reboot_fw_update                       ,0xff2ec3f4) //106
NHSTUB(set_control_event                      ,0xff092aac) //111
NHSTUB(srand                                  ,0xff24cf80) //  6
NHSTUB(stat                                   ,0xff0276b4) //109
NHSTUB(strcat                                 ,0xff0ad8cc) //  1
NHSTUB(strchr                                 ,0xff0040b8) //  1
NHSTUB(strcmp                                 ,0xff0108e4) //101
NHSTUB(strcpy                                 ,0xff0108cc) //101
NHSTUB(strftime                               ,0xff0adb14) //113
NHSTUB(strlen                                 ,0xff004104) //101
NHSTUB(strncmp                                ,0xff00406c) //  1
NHSTUB(strncpy                                ,0xff004030) //  1
NHSTUB(strrchr                                ,0xff0040dc) //  1
NHSTUB(strtol                                 ,0xff031884) //101
NHSTUB(strtolx                                ,0xff031688) //109
   DEF(task_CaptSeq                           ,0xff078bc8) //110
   DEF(task_ExpDrv                            ,0xff0c5e4c) //110
   DEF(task_FileWrite                         ,0xff2e4f2c) //110
   DEF(task_InitFileModules                   ,0xff096fd8) //110
   DEF(task_MovieRecord                       ,0xff18d7c0) //110
   DEF(task_PhySw                             ,0xff0248a0) //110
   DEF(task_RotaryEncoder                     ,0xff057998) //110
NHSTUB(time                                   ,0xff085fa4) //109
NHSTUB(vsprintf                               ,0xff01088c) //115
//NHSTUB(write                                ,0xff0274b0) //101
//NHSTUB(EngDrvIn                             ,0xff025c4c) //102
//NHSTUB(EngDrvOut                            ,0xff025c34) //102
//NHSTUB(EngDrvRead                           ,0xff025c54) //102
//NHSTUB(EngDrvBits                           ,0xff025c68) //102
//NHSTUB(_GetSystemTime                       ,0xff02bf0c) //109
//NHSTUB(SetTimerAfter                        ,0xff02c044) //119
//NHSTUB(SetTimerWhen                         ,0xff02c0c4) //119
//NHSTUB(CancelTimer                          ,0xff02c128) //119
//NHSTUB(CancelHPTimer                        ,0xff0877fc) //119
//NHSTUB(SetHPTimerAfterTimeout               ,0xff087774) //115
//NHSTUB(SetHPTimerAfterNow                   ,0xff0876f4) //119
//NHSTUB(CreateTaskStrictly                   ,0xff02b9b4) //107
//NHSTUB(CreateMessageQueue                   ,0xff02b068) //109
//NHSTUB(CreateRecursiveLock                  ,0xff083e4c) //109
//NHSTUB(GetSemaphoreValue                    ,0xff02b6a0) //119
//NHSTUB(TryTakeSemaphore                     ,0xff02b544) //119
//NHSTUB(CreateMessageQueueStrictly           ,0xff02b9e8) //119
//NHSTUB(CreateEventFlagStrictly              ,0xff02ba0c) //119
//NHSTUB(CreateBinarySemaphoreStrictly        ,0xff02ba30) //119
//NHSTUB(CreateCountingSemaphoreStrictly      ,0xff02ba54) //119
//NHSTUB(CreateRecursiveLockStrictly          ,0xff02ba78) //119
//NHSTUB(TakeSemaphoreStrictly                ,0xff02ba9c) //119
//NHSTUB(ReceiveMessageQueueStrictly          ,0xff02bac8) //119
//NHSTUB(PostMessageQueueStrictly             ,0xff02baf4) //119
//NHSTUB(WaitForAnyEventFlagStrictly          ,0xff02bb20) //119
//NHSTUB(WaitForAllEventFlagStrictly          ,0xff02bb4c) //119
//NHSTUB(AcquireRecursiveLockStrictly         ,0xff02bb78) //119
//NHSTUB(DeleteMessageQueue                   ,0xff02b0ec) //119
//NHSTUB(PostMessageQueue                     ,0xff02b2c8) //109
//NHSTUB(ReceiveMessageQueue                  ,0xff02b17c) //119
//NHSTUB(TryReceiveMessageQueue               ,0xff02b244) //119
//NHSTUB(TryPostMessageQueue                  ,0xff02b380) //119
//NHSTUB(GetNumberOfPostedMessages            ,0xff02b3c0) //119
//NHSTUB(DeleteRecursiveLock                  ,0xff083e9c) //119
//NHSTUB(AcquireRecursiveLock                 ,0xff083eec) //119
//NHSTUB(ReleaseRecursiveLock                 ,0xff08400c) //119
//NHSTUB(WaitForAnyEventFlag                  ,0xff083abc) //109
//NHSTUB(WaitForAllEventFlag                  ,0xff083ba0) //109
//NHSTUB(ClearEventFlag                       ,0xff083c94) //112
//NHSTUB(SetEventFlag                         ,0xff083c60) //112
//NHSTUB(GetEventFlagValue                    ,0xff083ccc) //119
//NHSTUB(CreateEventFlag                      ,0xff083984) //109
//NHSTUB(DeleteEventFlag                      ,0xff0839dc) //119
//NHSTUB(CheckAnyEventFlag                    ,0xff083a2c) //119
//NHSTUB(CheckAllEventFlag                    ,0xff083a74) //119
//NHSTUB(RegisterInterruptHandler             ,0xff00e940) //107
//NHSTUB(UnregisterInterruptHandler           ,0xff00e964) //119
//NHSTUB(GetSRAndDisableInterrupt             ,0xff00e97c) //119
//NHSTUB(SetSR                                ,0xff00e980) //119
//NHSTUB(EnableInterrupt                      ,0xff00e9a0) //119
//NHSTUB(GetSDProtect                         ,0xff024cd4) //101
//NHSTUB(DispCon_ShowBitmapColorBar           ,0xff051470) //102
//NHSTUB(ResetZoomLens                        ,0xff30e08c) //102
//NHSTUB(ResetFocusLens                       ,0xff30cc20) //102
//NHSTUB(NR_GetDarkSubType                    ,0xff195b10) //102
//NHSTUB(NR_SetDarkSubType                    ,0xff195a48) //102
//NHSTUB(SavePaletteData                      ,0xff37da98) //102
//NHSTUB(GUISrv_StartGUISystem                ,0xff0ab8bc) //101
