// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R47 (DRYOS version 2.3, release #0047)
//   Firmware Ver GM1.00B
//   Canon PowerShot A2200

// Values for makefile.inc
//   PLATFORMOSVER = 47
//   PLATFORMID = 12842 (0x322a) // Found @ 0xfffe0040
//   MAXRAMADDR = 0x03ffffff
//   MEMISOSTART = 0x001698cc
//   KEYSYS = d4c                // Found @ 0xffff350c
//   NEED_ENCODED_DISKBOOT = 6   // Found @ 0xffff351c

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
NHSTUB(kbd_pwr_off                            ,0xff8602cc) //  2 60%
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff89353c -> ff88fde8 -> ff98d574 -> ffac1350 -> ffbe5140
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00032914) // Found @0xff834658
DEF(physw_run                               ,0x00001c30) // Found @0xff834218
DEF(physw_sleep_delay                       ,0x00001c38) // Found @0xff834218
DEF(levent_table                            ,0xffb97b94) // Found @0xffb97b94
DEF(FlashParamsTable                        ,0xffbe537c) // Found @0xffbe537c
DEF(movie_status                            ,0x000065ec) // Found @0xff96367c
DEF(video_compression_rate                  ,0x0000662c) // Found @0xff963934
DEF(full_screen_refresh                     ,0x00009010) // Found @0xffa006a8
DEF(canon_menu_active                       ,0x00002eec) // Found @0xff88b5b8
DEF(canon_shoot_menu_active                 ,0x00007aa1) // Found @0xff9a7580
DEF(playrec_mode                            ,0x00002c18) // Found @0xff87da48
DEF(zoom_status                             ,0x0000cb38) // Found @0xffac4a24
DEF(some_flag_for_af_scan                   ,0x000069c4) // Found @0xff967364
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 3 int value(s), the first is the zoom focus length.
// there are 8 entries in the table - set NUM_FL to 8
DEF(focus_len_table                         ,0xfffe2a98) // Found @0xfffe2a98
DEF(zoom_busy                               ,0x00006544) // Found @0xff9600c0
DEF(focus_busy                              ,0x00006454) // Found @0xff95d4a0
DEF(recreview_hold                          ,0x000034c0) // Found @0xff898ac8
// Palette colour tables  found @ 0xffbad938
DEF(palette_control                         ,0x00009010) // Found @0xffa00624
DEF(active_palette_buffer                   ,0x00009018) // Found @0xffa00628
DEF(palette_buffer_ptr                      ,0x0000901c) // Found @0xffa009cc
DEF(palette_buffer                          ,0x000b41e4) // Found @0xffa009dc
// Offset from start of palette_buffer to color data = 8 (Found @0xffaf5904)
DEF(viewport_buffers                        ,0xffb552c8) // Found @0xff85198c
DEF(active_viewport_buffer                  ,0x000020d0) // Found @0xff851700
// Camera appears to have only 1 RAW buffer @ 0x421316c0 (Found @0xffb1a77c)

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x403f1000; }             // Found @0xff85b81c
//void *vid_get_viewport_fb()      { return (void*)0x40546b80; }             // Found @0xffb17310
DEF(viewport_fb_d                           ,0x000029f8) // Found 0x29a0 (@0xff871344) + 0x58 (@0xff87137c)
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x29a0+0x58)); } // Found @0xff871344 & 0xff87137c
DEF(jpeg_count_str                          ,0x000b3b14) // Found @0xff9f71c8
//char *camera_jpeg_count_str()    { return (char*)0x000b3b14; }             // Found @0xff9f71c8
//long hook_raw_size()             { return 0x014d2400; }                    // Found @0xffb1a7d4
//int get_flash_params_count(void) { return 0xa0; }                          // Found @0xff98e5ac

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffb56264, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x04000000 // Found @0xffb5628c, levent 0x902
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_PLAYBACK        ,0x01000000 }, // Found @0xffb561d4, levent 0x601
//    { 0, KEY_POWER           ,0x02000000 }, // Found @0xffb561dc, levent 0x600
//    { 0, KEY_MENU            ,0x04000000 }, // Found @0xffb561e4, levent 0x09
//    { 1, KEY_SHOOT_FULL      ,0x00000003 }, // Found @0xffb5620c, levent 0x01
//    { 1, KEY_SHOOT_FULL_ONLY ,0x00000002 }, // Found @0xffb5620c, levent 0x01
//    { 1, KEY_SHOOT_HALF      ,0x00000001 }, // Found @0xffb56204, levent 0x00
//    { 1, KEY_UP              ,0x00001000 }, // Found @0xffb56214, levent 0x04
//    { 1, KEY_RIGHT           ,0x00002000 }, // Found @0xffb5621c, levent 0x07
//    { 1, KEY_DOWN            ,0x00004000 }, // Found @0xffb56224, levent 0x05
//    { 1, KEY_LEFT            ,0x00008000 }, // Found @0xffb5622c, levent 0x06
//    { 1, KEY_ZOOM_OUT        ,0x00010000 }, // Found @0xffb56234, levent 0x03
//    { 1, KEY_ZOOM_IN         ,0x00020000 }, // Found @0xffb5623c, levent 0x02
//    { 1, KEY_SET             ,0x00040000 }, // Found @0xffb56244, levent 0x08
//    { 1, KEY_DISPLAY         ,0x00080000 }, // Found @0xffb5624c, levent 0x0a
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#define CAM_RAW_ROWPIX    4416 // Found @0xff937b24
//#define CAM_RAW_ROWS      3296 // Found @0xff937b2c
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff83a6a8

// Misc stuff
DEF(ctypes, 0xffb54b4a)

// For capt_seq.c
DEF(_nrflag,0x6a00) // Found @ ff96b6d0 (0x69f8) & ff96b70c (+0x08)
//static long *nrflag = (long*)(0x69f8+0x08);  // Found @ ff96b6d0 & ff96b70c
//#define NR_AUTO (0)                          // have to explictly reset value back to 0 to enable auto

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
//NHSTUB(CreateJumptable                      ,0xffb1a9a0) //  1
//NHSTUB(_uartr_req                           ,0xff81fd98) //111
//NHSTUB(StartRecModeMenu                     ,0xff88b5b4) //102
//NHSTUB(AllocateMemory                       ,0xffaafd20) //101
NHSTUB(AllocateUncacheableMemory              ,0xff83a660) //112
NHSTUB(Close                                  ,0xff836d7c) //101
//NHSTUB(CreateBinarySemaphore                ,0xff839e1c) //115
//NHSTUB(CreateCountingSemaphore              ,0xff839e84) //105
NHSTUB(CreateTask                             ,0xff81e9b0) //101
NHSTUB(DebugAssert                            ,0xff81ec88) //111
NHSTUB(DeleteDirectory_Fut                    ,0xff836778) //116
NHSTUB(DeleteFile_Fut                         ,0xff836694) //112
//NHSTUB(DeleteSemaphore                      ,0xff839edc) //105
NHSTUB(DoAFLock                               ,0xff8384c8) //102
NHSTUB(EnterToCompensationEVF                 ,0xff838724) //104
NHSTUB(ExecuteEventProcedure                  ,0xff886db8) //104
NHSTUB(ExitFromCompensationEVF                ,0xff838768) //104
NHSTUB(ExitTask                               ,0xff81ec40) //101
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff846c78) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff846d50) //104
NHSTUB(Fclose_Fut                             ,0xff836810) //101
NHSTUB(Feof_Fut                               ,0xff8369fc) //  1
NHSTUB(Fflush_Fut                             ,0xff836a38) //  1
NHSTUB(Fgets_Fut                              ,0xff836964) //  6
NHSTUB(Fopen_Fut                              ,0xff8367d0) //101
NHSTUB(Fread_Fut                              ,0xff8368bc) //101
//NHSTUB(FreeMemory                           ,0xffaafd18) //101
NHSTUB(FreeUncacheableMemory                  ,0xff83a6a0) //112
NHSTUB(Fseek_Fut                              ,0xff8369b0) //101
NHSTUB(Fwrite_Fut                             ,0xff836910) //101
NHSTUB(GetBatteryTemperature                  ,0xff8621dc) //102
NHSTUB(GetCCDTemperature                      ,0xff862168) //102
NHSTUB(GetCurrentAvValue                      ,0xff95f060) //102
NHSTUB(GetDrive_ClusterSize                   ,0xff86fca8) //  6
NHSTUB(GetDrive_FreeClusters                  ,0xff86fd00) //  6
NHSTUB(GetDrive_TotalClusters                 ,0xff86fcd8) //  6
NHSTUB(GetFocusLensSubjectDistance            ,0xff95e124) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff95e584) //  3
NHSTUB(GetImageFolder                         ,0xff93e9ac) //  6
NHSTUB(GetKbdState                            ,0xff8602b4) //109
NHSTUB(GetMemInfo                             ,0xff81a29c) //115
NHSTUB(GetOpticalTemperature                  ,0xff862250) //102
NHSTUB(GetParameterData                       ,0xff98e56c) //101
NHSTUB(GetPropertyCase                        ,0xff88ab20) //102
NHSTUB(GetSystemTime                          ,0xffaafd78) //101
NHSTUB(GetVRAMHPixelsSize                     ,0xff853bf0) //102
NHSTUB(GetVRAMVPixelsSize                     ,0xff853bfc) //102
NHSTUB(GetZoomLensCurrentPoint                ,0xff960444) //102
NHSTUB(GetZoomLensCurrentPosition             ,0xffa9d884) //102
NHSTUB(GiveSemaphore                          ,0xff83a058) //112
NHSTUB(IsStrobeChargeCompleted                ,0xff8d66c4) //102
NHSTUB(LEDDrive                               ,0xff85f8c8) //101
NHSTUB(LocalTime                              ,0xff8846a8) //115
NHSTUB(LockMainPower                          ,0xff88f9dc) //103
//NHSTUB(Lseek                                ,0xff836f98) //101
NHSTUB(MakeDirectory_Fut                      ,0xff836708) //116
NHSTUB(MakeSDCardBootable                     ,0xff86ff38) //105
NHSTUB(MoveFocusLensToDistance                ,0xffb1366c) //102
NHSTUB(MoveIrisWithAv                         ,0xffaad658) //102
NHSTUB(MoveZoomLensWithPoint                  ,0xffaadd00) //102
//NHSTUB(NewTaskShell                         ,0xff88a568) //101
NHSTUB(Open                                   ,0xff836cb4) //101
NHSTUB(PB2Rec                                 ,0xff892ba4) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff8761b4) //102
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff87618c) //102
NHSTUB(PT_PlaySound                           ,0xff87f6ec) //  6
NHSTUB(PostLogicalEventForNotPowerType        ,0xff88f1a8) //103
NHSTUB(PostLogicalEventToUI                   ,0xff88f1f4) //103
NHSTUB(PutInNdFilter                          ,0xffaadb48) //102
NHSTUB(PutOutNdFilter                         ,0xffaadb6c) //102
NHSTUB(Read                                   ,0xff81ad58) //101
NHSTUB(ReadFastDir                            ,0xffa8b014) //  6
NHSTUB(Rec2PB                                 ,0xff892be4) //104
NHSTUB(RefreshPhysicalScreen                  ,0xff8a3468) //104
//NHSTUB(Remove                               ,0xff836ef0) //  6
NHSTUB(RenameFile_Fut                         ,0xff836600) //116
NHSTUB(Restart                                ,0xff83be70) //106
NHSTUB(ScreenLock                             ,0xff8a46a0) //117
NHSTUB(ScreenUnlock                           ,0xff8a4704) //117
NHSTUB(SetAE_ShutterSpeed                     ,0xffb164e8) //102
NHSTUB(SetAutoShutdownTime                    ,0xff88fa50) //103
NHSTUB(SetCurrentCaptureModeType              ,0xff89675c) //101
NHSTUB(SetFileAttributes                      ,0xff837180) //  6
NHSTUB(SetFileTimeStamp                       ,0xff837108) //  6
NHSTUB(SetLogicalEventActive                  ,0xff88f754) //101
NHSTUB(SetParameterData                       ,0xff98e4dc) //101
NHSTUB(SetPropertyCase                        ,0xff88aa04) //102
NHSTUB(SetScriptMode                          ,0xff88f7a4) //101
NHSTUB(SleepTask                              ,0xff83a304) //101
NHSTUB(TakeSemaphore                          ,0xff839f88) //101
NHSTUB(TurnOffBackLight                       ,0xff89beb8) //104
NHSTUB(TurnOnBackLight                        ,0xff89bea0) //104
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff97fad8) //101
NHSTUB(UnlockAF                               ,0xff838500) //102
NHSTUB(UnlockMainPower                        ,0xff88f930) //103
NHSTUB(UnsetZoomForMovie                      ,0xff99797c) //104
NHSTUB(VbattGet                               ,0xff832e20) //101
NHSTUB(Write                                  ,0xff836dd0) //101
NHSTUB(WriteSDCard                            ,0xff94e7cc) //108
NHSTUB(_log                                   ,0xffb51670) //111
NHSTUB(_log10                                 ,0xffb51bb0) //112
NHSTUB(_pow                                   ,0xffb51d28) //114
NHSTUB(_sqrt                                  ,0xffb5394c) //  6
NHSTUB(add_ptp_handler                        ,0xffa40c00) //  6
NHSTUB(apex2us                                ,0xffa05a10) //  4
NHSTUB(close                                  ,0xff81abb4) //  6
NHSTUB(closedir                               ,0xffa8ae70) //  4
NHSTUB(err_init_task                          ,0xff815fd4) //111
NHSTUB(exmem_alloc                            ,0xff885670) //101
NHSTUB(exmem_free                             ,0xff8856e8) //101
NHSTUB(free                                   ,0xff814244) //112
NHSTUB(kbd_p1_f                               ,0xff8346d4) //109
NHSTUB(kbd_p1_f_cont                          ,0xff8346e0) //109
NHSTUB(kbd_p2_f                               ,0xff833ee8) //109
NHSTUB(kbd_read_keys                          ,0xff834658) //109
NHSTUB(kbd_read_keys_r2                       ,0xff85fd0c) //109
NHSTUB(lseek                                  ,0xff836f98) //101
NHSTUB(malloc                                 ,0xff8141ec) //112
NHSTUB(memcmp                                 ,0xff8208bc) //101
NHSTUB(memcpy                                 ,0xff83fce0) //101
NHSTUB(memset                                 ,0xffa04a10) //101
NHSTUB(mkdir                                  ,0xff837218) //109
NHSTUB(mktime_ext                             ,0xff8a54e4) //  1
NHSTUB(open                                   ,0xff81ab04) //  6
NHSTUB(OpenFastDir                            ,0xffa8aec0) //  6
NHSTUB(qsort                                  ,0xffaf64f4) //  6
NHSTUB(rand                                   ,0xffa04b50) //  6
//NHSTUB(read                                 ,0xff81ad58) //101
NHSTUB(realloc                                ,0xffa04a8c) //115
NHSTUB(reboot_fw_update                       ,0xffa904b0) //106
NHSTUB(set_control_event                      ,0xff88f418) //111
NHSTUB(srand                                  ,0xffa04b44) //  6
NHSTUB(stat                                   ,0xff836fe0) //109
NHSTUB(strcat                                 ,0xff8a4c9c) //  1
NHSTUB(strchr                                 ,0xff8140b8) //  1
NHSTUB(strcmp                                 ,0xff820878) //101
NHSTUB(strcpy                                 ,0xff820860) //101
NHSTUB(strftime                               ,0xff8a4ee4) //113
NHSTUB(strlen                                 ,0xff814104) //101
NHSTUB(strncmp                                ,0xff81406c) //  1
NHSTUB(strncpy                                ,0xff814030) //  1
NHSTUB(strrchr                                ,0xff8140dc) //  1
NHSTUB(strtol                                 ,0xff83ffe0) //101
NHSTUB(strtolx                                ,0xff83fde4) //109
   DEF(task_CaptSeq                           ,0xff8788f0) //110
   DEF(task_ExpDrv                            ,0xff8bbe80) //110
   DEF(task_FileWrite                         ,0xffa88ec4) //110
   DEF(task_InitFileModules                   ,0xff8933bc) //110
   DEF(task_MovieRecord                       ,0xff964148) //110
   DEF(task_PhySw                             ,0xff834214) //110
NHSTUB(time                                   ,0xff884c84) //109
NHSTUB(vsprintf                               ,0xff820820) //115
//NHSTUB(write                                ,0xff836dd0) //101
//NHSTUB(EngDrvIn                             ,0xff835518) //102
//NHSTUB(EngDrvOut                            ,0xff835500) //102
//NHSTUB(EngDrvRead                           ,0xff835520) //102
//NHSTUB(EngDrvBits                           ,0xff835534) //102
//NHSTUB(_GetSystemTime                       ,0xff83a8fc) //109
//NHSTUB(SetTimerAfter                        ,0xff83aa34) //119
//NHSTUB(SetTimerWhen                         ,0xff83aab4) //119
//NHSTUB(CancelTimer                          ,0xff83ab18) //119
//NHSTUB(CancelHPTimer                        ,0xff8864a0) //119
//NHSTUB(SetHPTimerAfterTimeout               ,0xff886418) //115
//NHSTUB(SetHPTimerAfterNow                   ,0xff886398) //119
//NHSTUB(CreateTaskStrictly                   ,0xff83a3a4) //107
//NHSTUB(CreateMessageQueue                   ,0xff839a58) //109
//NHSTUB(CreateRecursiveLock                  ,0xff882ae4) //109
//NHSTUB(GetSemaphoreValue                    ,0xff83a090) //119
//NHSTUB(TryTakeSemaphore                     ,0xff839f34) //119
//NHSTUB(CreateMessageQueueStrictly           ,0xff83a3d8) //119
//NHSTUB(CreateEventFlagStrictly              ,0xff83a3fc) //119
//NHSTUB(CreateBinarySemaphoreStrictly        ,0xff83a420) //119
//NHSTUB(CreateCountingSemaphoreStrictly      ,0xff83a444) //119
//NHSTUB(CreateRecursiveLockStrictly          ,0xff83a468) //119
//NHSTUB(TakeSemaphoreStrictly                ,0xff83a48c) //119
//NHSTUB(ReceiveMessageQueueStrictly          ,0xff83a4b8) //119
//NHSTUB(PostMessageQueueStrictly             ,0xff83a4e4) //119
//NHSTUB(WaitForAnyEventFlagStrictly          ,0xff83a510) //119
//NHSTUB(WaitForAllEventFlagStrictly          ,0xff83a53c) //119
//NHSTUB(AcquireRecursiveLockStrictly         ,0xff83a568) //119
//NHSTUB(DeleteMessageQueue                   ,0xff839adc) //119
//NHSTUB(PostMessageQueue                     ,0xff839cb8) //109
//NHSTUB(ReceiveMessageQueue                  ,0xff839b6c) //119
//NHSTUB(TryReceiveMessageQueue               ,0xff839c34) //119
//NHSTUB(TryPostMessageQueue                  ,0xff839d70) //119
//NHSTUB(GetNumberOfPostedMessages            ,0xff839db0) //119
//NHSTUB(DeleteRecursiveLock                  ,0xff882b34) //119
//NHSTUB(AcquireRecursiveLock                 ,0xff882b84) //119
//NHSTUB(ReleaseRecursiveLock                 ,0xff882ca4) //119
//NHSTUB(WaitForAnyEventFlag                  ,0xff882754) //109
//NHSTUB(WaitForAllEventFlag                  ,0xff882838) //109
//NHSTUB(ClearEventFlag                       ,0xff88292c) //112
//NHSTUB(SetEventFlag                         ,0xff8828f8) //112
//NHSTUB(GetEventFlagValue                    ,0xff882964) //119
//NHSTUB(CreateEventFlag                      ,0xff88261c) //109
//NHSTUB(DeleteEventFlag                      ,0xff882674) //119
//NHSTUB(CheckAnyEventFlag                    ,0xff8826c4) //119
//NHSTUB(CheckAllEventFlag                    ,0xff88270c) //119
//NHSTUB(RegisterInterruptHandler             ,0xff81e948) //107
//NHSTUB(UnregisterInterruptHandler           ,0xff81e96c) //119
//NHSTUB(GetSRAndDisableInterrupt             ,0xff81e984) //119
//NHSTUB(SetSR                                ,0xff81e988) //119
//NHSTUB(EnableInterrupt                      ,0xff81e9a8) //119
//NHSTUB(GetSDProtect                         ,0xff83461c) //101
//NHSTUB(DispCon_ShowBitmapColorBar           ,0xff85b7ec) //102
//NHSTUB(ResetZoomLens                        ,0xffaadc54) //102
//NHSTUB(ResetFocusLens                       ,0xffaac930) //102
//NHSTUB(NR_GetDarkSubType                    ,0xff96b790) //102
//NHSTUB(NR_SetDarkSubType                    ,0xff96b6c8) //102
//NHSTUB(SavePaletteData                      ,0xffb188fc) //102
//NHSTUB(GUISrv_StartGUISystem                ,0xff8a2ce0) //101
