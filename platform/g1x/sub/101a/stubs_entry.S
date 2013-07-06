// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R49 (DRYOS version 2.3, release #0049)
//   Firmware Ver GM1.01A
//   Canon PowerShot G1 X

// Values for makefile.inc
//   PLATFORMOSVER = 49
//   PLATFORMID = 12851 (0x3233) // Found @ 0xfff40040
//   MAXRAMADDR = 0x0fffffff
//   MEMISOSTART = 0x0018c7b4
//   KEYSYS = d4c                // Found @ 0xffff3bb0
//   NEED_ENCODED_DISKBOOT = 7   // Found @ 0xffff3bc0

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
// ERROR: kbd_pwr_off is not found.                        //--- ---    *** != 0x00000000
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff09ab38 -> ff097164 -> ff20518c -> ff388e1c -> ff63a38c
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00038c1c) // Found @0xff023c4c
DEF(physw_run                               ,0x00001bf4) // Found @0xff0237dc
DEF(physw_sleep_delay                       ,0x00001bfc) // Found @0xff0237dc
DEF(levent_table                            ,0xff59e2ec) // Found @0xff59e2ec
DEF(FlashParamsTable                        ,0xff63a5f0) // Found @0xff63a5f0
DEF(movie_status                            ,0x00009de4) // Found @0xff1c8b6c
DEF(video_compression_rate                  ,0x00009e24) // Found @0xff1ca014
DEF(full_screen_refresh                     ,0x0000cda4) // Found @0xff29af08
DEF(canon_menu_active                       ,0x0000446c) // Found @0xff090558
DEF(canon_shoot_menu_active                 ,0x0000b4f9) // Found @0xff22c730
DEF(playrec_mode                            ,0x0000418c) // Found @0xff081e14
DEF(zoom_status                             ,0x0000b020) // Found @0xff21376c
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 2 int value(s), the first is the zoom focus length.
// there are 101 entries in the table - set NUM_FL to 101
DEF(focus_len_table                         ,0xfff4a6c8) // Found @0xfff4a6c8
DEF(zoom_busy                               ,0x00009c9c) // Found @0xff1c3864
DEF(focus_busy                              ,0x00009aec) // Found @0xff1bd384
DEF(recreview_hold                          ,0x0000514c) // Found @0xff0a3198
// Palette colour tables  found @ 0xff5badb0
DEF(palette_control                         ,0x0000cda4) // Found @0xff29ae84
DEF(active_palette_buffer                   ,0x0000cdac) // Found @0xff29ae88
DEF(palette_buffer_ptr                      ,0x0000cdb0) // Found @0xff29b340
DEF(palette_buffer                          ,0x000cc858) // Found @0xff29b350
// Offset from start of palette_buffer to color data = 4 (Found @0xff3cb084)
DEF(bitmap_buffer                           ,0x0000cde8) // Found @0xff29eb94
DEF(active_bitmap_buffer                    ,0x0000cde0) // Found @0xff29eb98
DEF(viewport_buffers                        ,0xff464c7c) // Found @0xff045214
DEF(active_viewport_buffer                  ,0x00002150) // Found @0xff044ee8
// Camera has 2 RAW buffers @ 0x44000000 & 0x4a6ba6a0
//  Note: active buffer --> raw_buffers[active_raw_buffer]
//        other buffer  --> raw_buffers[active_raw_buffer^1]
DEF(raw_buffers                             ,0xff47686c) // Found @0xff47686c
DEF(active_raw_buffer                       ,0x000040dc) // Found @0xff07dad0

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x40685000; }             // Found @0xff0501b8
//void *vid_get_viewport_fb()      { return (void*)0x407dab80; }             // Found @0xff408024
DEF(viewport_fb_d                           ,0x00003de8) // Found 0x3d90 (@0xff06e538) + 0x58 (@0xff06e570)
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x3d90+0x58)); } // Found @0xff06e538 & 0xff06e570
DEF(jpeg_count_str                          ,0x000cc108) // Found @0xff28c9f0
//char *camera_jpeg_count_str()    { return (char*)0x000cc108; }             // Found @0xff28c9f0
//long hook_raw_size()             { return 0x01941be8; }                    // Found @0xff40ae40
//int get_flash_params_count(void) { return 0x9f; }                          // Found @0xff206780

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00000002 // Found @0xff465334, levent 0x20a
//#define SD_READONLY_IDX     1
//#define USB_MASK            0x10000000 // Found @0xff4653ac, levent 0x202
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_SET             ,0x00000800 }, // Found @0xff4652bc, levent 0x08
//    { 0, KEY_RIGHT           ,0x00001000 }, // Found @0xff4652c4, levent 0x07
//    { 0, KEY_DOWN            ,0x00002000 }, // Found @0xff4652cc, levent 0x05
//    { 0, KEY_MENU            ,0x00004000 }, // Found @0xff4652d4, levent 0x09
//    { 0, KEY_LEFT            ,0x00008000 }, // Found @0xff4652dc, levent 0x06
//    { 0, KEY_UP              ,0x00040000 }, // Found @0xff4652f4, levent 0x04
//    { 0, KEY_VIDEO           ,0x00080000 }, // Found @0xff4652fc, levent 0x19
//    { 0, KEY_ZOOM_IN         ,0x00100000 }, // Found @0xff465304, levent 0x02
//    { 0, KEY_ZOOM_OUT        ,0x00200000 }, // Found @0xff46530c, levent 0x03
//    { 2, KEY_POWER           ,0x00000800 }, // Found @0xff46534c, levent 0x100
//    { 2, KEY_PLAYBACK        ,0x00008000 }, // Found @0xff46536c, levent 0x101
//    { 2, KEY_SHOOT_FULL      ,0x000c0000 }, // Found @0xff46537c, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00080000 }, // Found @0xff46537c, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00040000 }, // Found @0xff465374, levent 0x00
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#define CAM_RAW_ROWPIX    4496 // Found @0xff190cd0
//#define CAM_RAW_ROWS      3366 // Found @0xff190cdc
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff02ac74

// Misc stuff
DEF(ctypes, 0xff463fe6)

// For capt_seq.c
DEF(_nrflag,0xcec0) // Found @ ff2a79e4 (0xcebc) & ff2a7a20 (+0x04)
//static long *nrflag = (long*)(0xcebc+0x04);  // Found @ ff2a79e4 & ff2a7a20
//#define NR_AUTO (0)                          // have to explictly reset value back to 0 to enable auto

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
//NHSTUB(CreateJumptable                      ,0xff40b008) //  1
// ALT: NHSTUB(CreateJumptable, 0xff40d28c) // 1 32/0
//NHSTUB(_uartr_req                           ,0xff00fef8) //111
//NHSTUB(StartRecModeMenu                     ,0xff090554) //102
//NHSTUB(AllocateMemory                       ,0xff374d50) //101
NHSTUB(AllocateUncacheableMemory              ,0xff02ac2c) //112
NHSTUB(Close                                  ,0xff026458) //101
//NHSTUB(CreateBinarySemaphore                ,0xff02a158) //115
//NHSTUB(CreateCountingSemaphore              ,0xff02a1c0) //105
NHSTUB(CreateTask                             ,0xff00eaf0) //101
NHSTUB(DebugAssert                            ,0xff00edc8) //111
NHSTUB(DeleteDirectory_Fut                    ,0xff025e54) //116
NHSTUB(DeleteFile_Fut                         ,0xff025d70) //112
//NHSTUB(DeleteSemaphore                      ,0xff02a218) //105
NHSTUB(DoAFLock                               ,0xff0280d0) //102
NHSTUB(EnterToCompensationEVF                 ,0xff0284a4) //104
NHSTUB(ExecuteEventProcedure                  ,0xff08b9f4) //104
NHSTUB(ExitFromCompensationEVF                ,0xff0284e8) //104
NHSTUB(ExitTask                               ,0xff00ed80) //101
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff036ba4) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff036c84) //104
NHSTUB(Fclose_Fut                             ,0xff025eec) //101
NHSTUB(Feof_Fut                               ,0xff0260d8) //  1
NHSTUB(Fflush_Fut                             ,0xff026114) //  1
NHSTUB(Fgets_Fut                              ,0xff026040) //  6
NHSTUB(Fopen_Fut                              ,0xff025eac) //101
NHSTUB(Fread_Fut                              ,0xff025f98) //101
//NHSTUB(FreeMemory                           ,0xff374d48) //101
NHSTUB(FreeUncacheableMemory                  ,0xff02ac6c) //112
NHSTUB(Fseek_Fut                              ,0xff02608c) //101
NHSTUB(Fwrite_Fut                             ,0xff025fec) //101
NHSTUB(GetBatteryTemperature                  ,0xff05de30) //102
NHSTUB(GetCCDTemperature                      ,0xff05ddbc) //102
NHSTUB(GetCurrentAvValue                      ,0xff1c02bc) //102
NHSTUB(GetDrive_ClusterSize                   ,0xff06cbec) //  6
NHSTUB(GetDrive_FreeClusters                  ,0xff06cc44) //  6
NHSTUB(GetDrive_TotalClusters                 ,0xff06cc1c) //  6
NHSTUB(GetFocusLensSubjectDistance            ,0xff1be100) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff1be550) //  3
NHSTUB(GetImageFolder                         ,0xff19a46c) //  6
NHSTUB(GetKbdState                            ,0xff05726c) //109
NHSTUB(GetMemInfo                             ,0xff00a2b8) //115
NHSTUB(GetOpticalTemperature                  ,0xff05dea4) //102
NHSTUB(GetParameterData                       ,0xff206740) //101
NHSTUB(GetPropertyCase                        ,0xff08fa94) //102
NHSTUB(GetSystemTime                          ,0xff374da8) //101
NHSTUB(GetVRAMHPixelsSize                     ,0xff047814) //102
NHSTUB(GetVRAMVPixelsSize                     ,0xff047820) //102
NHSTUB(GetZoomLensCurrentPoint                ,0xff1c3cdc) //102
NHSTUB(GetZoomLensCurrentPosition             ,0xff3612dc) //102
NHSTUB(GiveSemaphore                          ,0xff02a394) //112
NHSTUB(IsStrobeChargeCompleted                ,0xff0f244c) //102
NHSTUB(LEDDrive                               ,0xff056488) //101
NHSTUB(LocalTime                              ,0xff0893b8) //115
NHSTUB(LockMainPower                          ,0xff096d5c) //103
//NHSTUB(Lseek                                ,0xff026674) //101
NHSTUB(MakeDirectory_Fut                      ,0xff025de4) //116
NHSTUB(MakeSDCardBootable                     ,0xff06ce7c) //105
NHSTUB(MoveFocusLensToDistance                ,0xff40425c) //102
NHSTUB(MoveIrisWithAv                         ,0xff3714f8) //102
NHSTUB(MoveZoomLensWithPoint                  ,0xff371e88) //102
//NHSTUB(NewTaskShell                         ,0xff08f414) //101
NHSTUB(Open                                   ,0xff026390) //101
NHSTUB(PB2Rec                                 ,0xff09a108) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff078130) //102
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff078108) //102
NHSTUB(PT_PlaySound                           ,0xff083e28) //  6
NHSTUB(PostLogicalEventForNotPowerType        ,0xff0945c8) //103
NHSTUB(PostLogicalEventToUI                   ,0xff094614) //103
NHSTUB(PutInNdFilter                          ,0xff371c60) //102
NHSTUB(PutOutNdFilter                         ,0xff371c84) //102
NHSTUB(Read                                   ,0xff00ad74) //101
NHSTUB(ReadFastDir                            ,0xff34cb58) //115
NHSTUB(Rec2PB                                 ,0xff09a148) //104
NHSTUB(RefreshPhysicalScreen                  ,0xff0b308c) //104
//NHSTUB(Remove                               ,0xff0265cc) //  6
NHSTUB(RenameFile_Fut                         ,0xff025cdc) //116
NHSTUB(Restart                                ,0xff02c444) //106
NHSTUB(ScreenLock                             ,0xff0b42b8) //117
NHSTUB(ScreenUnlock                           ,0xff0b431c) //117
NHSTUB(SetAE_ShutterSpeed                     ,0xff40719c) //102
NHSTUB(SetAutoShutdownTime                    ,0xff096dd0) //103
NHSTUB(SetCurrentCaptureModeType              ,0xff0a0284) //101
NHSTUB(SetFileAttributes                      ,0xff02685c) //  6
NHSTUB(SetFileTimeStamp                       ,0xff0267e4) //  6
NHSTUB(SetLogicalEventActive                  ,0xff096aa8) //101
NHSTUB(SetParameterData                       ,0xff20661c) //101
NHSTUB(SetPropertyCase                        ,0xff08f90c) //102
NHSTUB(SetScriptMode                          ,0xff096af8) //101
NHSTUB(SleepTask                              ,0xff02a640) //101
NHSTUB(TakeSemaphore                          ,0xff02a2c4) //101
NHSTUB(TurnOffBackLight                       ,0xff0aab7c) //104
NHSTUB(TurnOnBackLight                        ,0xff0aab64) //104
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff1f0934) //101
NHSTUB(UnlockAF                               ,0xff028108) //102
NHSTUB(UnlockMainPower                        ,0xff096cb0) //103
NHSTUB(VbattGet                               ,0xff022338) //101
NHSTUB(Write                                  ,0xff0264ac) //101
NHSTUB(WriteSDCard                            ,0xff1aeda4) //108
NHSTUB(_log                                   ,0xff4607d0) //111
NHSTUB(_log10                                 ,0xff460d10) //112
NHSTUB(_pow                                   ,0xff460e88) //114
NHSTUB(_sqrt                                  ,0xff462de8) //  6
NHSTUB(add_ptp_handler                        ,0xff2ebca4) //  6
NHSTUB(apex2us                                ,0xff2a1360) //  4
NHSTUB(close                                  ,0xff00abd0) //  6
NHSTUB(closedir                               ,0xff34c9b4) //  4
NHSTUB(err_init_task                          ,0xff00602c) //111
NHSTUB(exmem_alloc                            ,0xff08a378) //101
NHSTUB(exmem_free                             ,0xff08a3f0) //101
NHSTUB(free                                   ,0xff004264) //112
NHSTUB(kbd_p1_f                               ,0xff023c9c) //109
NHSTUB(kbd_p1_f_cont                          ,0xff023ca8) //109
NHSTUB(kbd_p2_f                               ,0xff023474) //109
NHSTUB(kbd_read_keys                          ,0xff023c4c) //109
NHSTUB(kbd_read_keys_r2                       ,0xff056960) //109
NHSTUB(lseek                                  ,0xff026674) //101
NHSTUB(malloc                                 ,0xff00420c) //112
NHSTUB(memcmp                                 ,0xff010a1c) //101
NHSTUB(memcpy                                 ,0xff0304a4) //101
NHSTUB(memset                                 ,0xff29f384) //101
NHSTUB(mkdir                                  ,0xff0268f4) //109
NHSTUB(mktime_ext                             ,0xff0b51d4) //  1
NHSTUB(open                                   ,0xff00ab20) //  6
NHSTUB(OpenFastDir                            ,0xff34ca04) //115
NHSTUB(qsort                                  ,0xff3cbc48) //  6
NHSTUB(rand                                   ,0xff29f4c0) //  6
//NHSTUB(read                                 ,0xff00ad74) //101
NHSTUB(realloc                                ,0xff29f400) //115
NHSTUB(reboot_fw_update                       ,0xff3522ac) //106
NHSTUB(set_control_event                      ,0xff09669c) //111
NHSTUB(srand                                  ,0xff29f4b4) //  6
NHSTUB(stat                                   ,0xff0266bc) //109
NHSTUB(strcat                                 ,0xff0b498c) //  1
NHSTUB(strchr                                 ,0xff0040d8) //  1
NHSTUB(strcmp                                 ,0xff0109d8) //101
NHSTUB(strcpy                                 ,0xff0109c0) //101
NHSTUB(strftime                               ,0xff0b4bd4) //113
NHSTUB(strlen                                 ,0xff004124) //101
NHSTUB(strncmp                                ,0xff00408c) //  1
NHSTUB(strncpy                                ,0xff004050) //  1
NHSTUB(strrchr                                ,0xff0040fc) //  1
NHSTUB(strtol                                 ,0xff0307a4) //101
NHSTUB(strtolx                                ,0xff0305a8) //109
   DEF(task_CaptSeq                           ,0xff07b364) //110
   DEF(task_ExpDrv                            ,0xff0cda24) //110
   DEF(task_FileWrite                         ,0xff34a94c) //110
   DEF(task_InitFileModules                   ,0xff09a9ac) //110
   DEF(task_MovieRecord                       ,0xff1ca8a4) //110
   DEF(task_PhySw                             ,0xff0237d8) //110
   DEF(task_RotaryEncoder                     ,0xff0575cc) //110
NHSTUB(time                                   ,0xff089994) //109
NHSTUB(vsprintf                               ,0xff010980) //115
//NHSTUB(write                                ,0xff0264ac) //101
//NHSTUB(EngDrvIn                             ,0xff024ac0) //102
//NHSTUB(EngDrvOut                            ,0xff024aa8) //102
//NHSTUB(EngDrvRead                           ,0xff024ac8) //102
//NHSTUB(EngDrvBits                           ,0xff024adc) //102
//NHSTUB(CreateTaskStrictly                   ,0xff02a6e0) //107
//NHSTUB(CreateMessageQueue                   ,0xff029d94) //109
//NHSTUB(CreateRecursiveLock                  ,0xff087750) //109
//NHSTUB(GetSemaphoreValue                    ,0xff02a3cc) //119
//NHSTUB(TryTakeSemaphore                     ,0xff02a270) //119
//NHSTUB(CreateMessageQueueStrictly           ,0xff02a714) //119
//NHSTUB(CreateEventFlagStrictly              ,0xff02a738) //119
//NHSTUB(CreateBinarySemaphoreStrictly        ,0xff02a75c) //119
//NHSTUB(CreateCountingSemaphoreStrictly      ,0xff02a780) //119
//NHSTUB(CreateRecursiveLockStrictly          ,0xff02a7a4) //119
//NHSTUB(TakeSemaphoreStrictly                ,0xff02a7c8) //119
//NHSTUB(ReceiveMessageQueueStrictly          ,0xff02a7f4) //119
//NHSTUB(PostMessageQueueStrictly             ,0xff02a820) //119
//NHSTUB(WaitForAnyEventFlagStrictly          ,0xff02a84c) //119
//NHSTUB(WaitForAllEventFlagStrictly          ,0xff02a878) //119
//NHSTUB(AcquireRecursiveLockStrictly         ,0xff02a8a4) //119
//NHSTUB(DeleteMessageQueue                   ,0xff029e18) //119
//NHSTUB(PostMessageQueue                     ,0xff029ff4) //109
//NHSTUB(ReceiveMessageQueue                  ,0xff029ea8) //119
//NHSTUB(TryReceiveMessageQueue               ,0xff029f70) //119
//NHSTUB(TryPostMessageQueue                  ,0xff02a0ac) //119
//NHSTUB(GetNumberOfPostedMessages            ,0xff02a0ec) //119
//NHSTUB(DeleteRecursiveLock                  ,0xff0877a0) //119
//NHSTUB(AcquireRecursiveLock                 ,0xff0877f0) //119
//NHSTUB(ReleaseRecursiveLock                 ,0xff087910) //119
//NHSTUB(WaitForAnyEventFlag                  ,0xff0873c0) //109
//NHSTUB(WaitForAllEventFlag                  ,0xff0874a4) //109
//NHSTUB(ClearEventFlag                       ,0xff087598) //112
//NHSTUB(SetEventFlag                         ,0xff087564) //112
//NHSTUB(GetEventFlagValue                    ,0xff0875d0) //119
//NHSTUB(CreateEventFlag                      ,0xff087288) //109
//NHSTUB(DeleteEventFlag                      ,0xff0872e0) //119
//NHSTUB(CheckAnyEventFlag                    ,0xff087330) //119
//NHSTUB(CheckAllEventFlag                    ,0xff087378) //119
//NHSTUB(GetSDProtect                         ,0xff023c04) //101
//NHSTUB(DispCon_ShowBitmapColorBar           ,0xff050174) //102
//NHSTUB(ResetZoomLens                        ,0xff371ddc) //102
//NHSTUB(ResetFocusLens                       ,0xff3706d8) //102
//NHSTUB(NR_GetDarkSubType                    ,0xff2a7aa4) //102
//NHSTUB(NR_SetDarkSubType                    ,0xff2a79dc) //102
//NHSTUB(SavePaletteData                      ,0xff1ce1a4) //102
//NHSTUB(GUISrv_StartGUISystem                ,0xff0b28a4) //101
