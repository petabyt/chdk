// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R23 (DRYOS version 2.3, release #0023)
//   Firmware Ver GM1.00E
//   Canon PowerShot A470

// Values for makefile.inc
//   PLATFORMOSVER = 23
//   PLATFORMID = 12666 (0x317a) // Found @ 0xfffe0130
//   MAXRAMADDR = 0x01ffffff
//   MEMISOSTART = 0x000a5718  (*** DOES NOT MATCH MAKEFILE VALUE 0x000a5798***)
//   KEYSYS = d3enc              // Found @ 0xffff1a98
//   NEED_ENCODED_DISKBOOT = 1   // Found @ 0xffff1a78

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NHSTUB(PutInNdFilter                        ,0xffdd6fc4) //102        *** != 0xffe267b4
//NHSTUB(PutOutNdFilter                       ,0xffdd6fe8) //102        *** != 0xffe267ec
//NHSTUB(kbd_pwr_off                          ,0xffc30b30) //  2 67%    *** != 0x00000000
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ffc5ed6c -> ffc5b950 -> ffd28c20 -> ffde7148 -> ffe8fab4
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x0001007c) // Found @0xffc11c0c
DEF(physw_run                               ,0x00001bf0) // Found @0xffc118a8
DEF(physw_sleep_delay                       ,0x00001bee) // Found @0xffc118a8
DEF(levent_table                            ,0xffe72ec8) // Found @0xffe72ec8
DEF(FlashParamsTable                        ,0xffe8fc68) // Found @0xffe8fc68
DEF(movie_status                            ,0x000051d8) // Found @0xffc45174
DEF(canon_menu_active                       ,0x00009014) // Found @0xffd1eec4
DEF(canon_shoot_menu_active                 ,0x000097e1) // Found @0xffd37684
DEF(playrec_mode                            ,0x00005348) // Found @0xffc4b760
DEF(zoom_status                             ,0x0000d020) // Found @0xffde8948
DEF(some_flag_for_af_scan                   ,0x0000cd9c) // Found @0xffdd73a8
DEF(zoom_busy                               ,0x000083a4) // Found @0xffd05d3c
DEF(focus_busy                              ,0x000082b0) // Found @0xffd018d0
DEF(recreview_hold                          ,0x00005b3c) // Found @0xffc63e24
// Camera appears to have only 1 RAW buffer @ 0x10f06b20 (Found @0xffe2db28)

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x10361000; }             // Found @0xffc2cc48
//void *vid_get_viewport_fb()      { return (void*)0x10659d50; }             // Found @0xffe2b908
DEF(viewport_fb_d                           ,0x000050cc) // Found 0x5080 (@0xffc40488) + 0x4c (@0xffc404c0)
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x5080+0x4c)); } // Found @0xffc40488 & 0xffc404c0
DEF(jpeg_count_str                          ,0x00049a00) // Found @0xffd5de80
//char *camera_jpeg_count_str()    { return (char*)0x00049a00; }             // Found @0xffd5de80
//long hook_raw_size()             { return 0x008d0a68; }                    // Found @0xffe2db84
//int get_flash_params_count(void) { return 0x73; }                          // Found @0xffd29cdc

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffe51bbc, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x00040000 // Found @0xffe51bc4, levent 0x902
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 1, KEY_POWER           ,0x04000000 }, // Found @0xffe51b2c, levent 0x600 (uses inverted logic in physw_status)
//    { 2, KEY_UP              ,0x00000001 }, // Found @0xffe51b3c, levent 0x04
//    { 2, KEY_DOWN            ,0x00000002 }, // Found @0xffe51b44, levent 0x05
//    { 2, KEY_RIGHT           ,0x00000004 }, // Found @0xffe51b4c, levent 0x07
//    { 2, KEY_LEFT            ,0x00000008 }, // Found @0xffe51b54, levent 0x06
//    { 2, KEY_SHOOT_FULL      ,0x00000030 }, // Found @0xffe51b64, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000020 }, // Found @0xffe51b64, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00000010 }, // Found @0xffe51b5c, levent 0x00
//    { 2, KEY_SET             ,0x00000100 }, // Found @0xffe51b7c, levent 0x08
//    { 2, KEY_MENU            ,0x00000400 }, // Found @0xffe51b84, levent 0x09
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_RAW_ROWPIX    3152 // Found @0xffe25328
//#define CAM_RAW_ROWS      2346 // Found @0xffe2532c
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x10000000 // Found @0xffc17e54

// Misc stuff
DEF(ctypes, 0xffe5171a)

// For capt_seq.c
DEF(_nrflag,0x8888) // Found @ ffd0cb54 (0x8888)
//static long *nrflag = (long*)(0x8888);       // Found @ ffd0cb54

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
//NHSTUB(CreateJumptable                      ,0xffe2dd4c) //  1
//NHSTUB(_uartr_req                           ,0xffc0ce68) //111
//NHSTUB(StartRecModeMenu                     ,0xffd1eec0) //102
//NHSTUB(AllocateMemory                       ,0xffdda868) //101
NHSTUB(AllocateUncacheableMemory              ,0xffc17e18) //112
NHSTUB(Close                                  ,0xffc13b5c) //101
//NHSTUB(CreateBinarySemaphore                ,0xffc0b608) //115
//NHSTUB(CreateCountingSemaphore              ,0xffc0b670) //105
NHSTUB(CreateTask                             ,0xffc0b8e0) //101
NHSTUB(DebugAssert                            ,0xffc0bdb8) //111
NHSTUB(DeleteDirectory_Fut                    ,0xffc134ec) //116
NHSTUB(DeleteFile_Fut                         ,0xffc13408) //112
//NHSTUB(DeleteSemaphore                      ,0xffc0b6c8) //105
NHSTUB(DoAFLock                               ,0xffc157a0) //102
NHSTUB(EnterToCompensationEVF                 ,0xffc15a90) //104
NHSTUB(ExecuteEventProcedure                  ,0xffc53308) //104
NHSTUB(ExitFromCompensationEVF                ,0xffc15bdc) //104
NHSTUB(ExitTask                               ,0xffc0bb70) //101
NHSTUB(ExpCtrlTool_StartContiAE               ,0xffc218c8) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xffc21a0c) //104
NHSTUB(Fclose_Fut                             ,0xffc13584) //101
NHSTUB(Feof_Fut                               ,0xffc13770) //  1
NHSTUB(Fflush_Fut                             ,0xffc137ac) //  1
NHSTUB(Fgets_Fut                              ,0xffc136d8) //  1
NHSTUB(Fopen_Fut                              ,0xffc13544) //101
NHSTUB(Fread_Fut                              ,0xffc13630) //101
//NHSTUB(FreeMemory                           ,0xffdda860) //101
NHSTUB(FreeUncacheableMemory                  ,0xffc17e4c) //112
NHSTUB(Fseek_Fut                              ,0xffc13724) //101
NHSTUB(Fwrite_Fut                             ,0xffc13684) //101
NHSTUB(GetBatteryTemperature                  ,0xffc32bd8) //102
NHSTUB(GetCCDTemperature                      ,0xffc32b68) //102
NHSTUB(GetCurrentAvValue                      ,0xffd032e4) //102
NHSTUB(GetDrive_ClusterSize                   ,0xffc3c8d0) //  1
NHSTUB(GetDrive_FreeClusters                  ,0xffc3c938) //  1
NHSTUB(GetDrive_TotalClusters                 ,0xffc3c904) //  1
NHSTUB(GetFocusLensSubjectDistance            ,0xffd023dc) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xffd026e8) //  1
NHSTUB(GetKbdState                            ,0xffc30b18) //109
NHSTUB(GetMemInfo                             ,0xffc03c40) //115
NHSTUB(GetOpticalTemperature                  ,0xffc32c48) //102
NHSTUB(GetParameterData                       ,0xffd29c9c) //101
NHSTUB(GetPropertyCase                        ,0xffc56f08) //102
NHSTUB(GetSystemTime                          ,0xffdda8c0) //101
NHSTUB(GetVRAMHPixelsSize                     ,0xffca18c0) //102
NHSTUB(GetVRAMVPixelsSize                     ,0xffca18cc) //102
NHSTUB(GetZoomLensCurrentPoint                ,0xffd060a0) //102
NHSTUB(GetZoomLensCurrentPosition             ,0xffdd1c94) //102
NHSTUB(GiveSemaphore                          ,0xffc0b844) //112
NHSTUB(IsStrobeChargeCompleted                ,0xffc97108) //102
NHSTUB(LEDDrive                               ,0xffc303c0) //103
NHSTUB(LocalTime                              ,0xffc51028) //115
NHSTUB(LockMainPower                          ,0xffc5b568) //103
//NHSTUB(Lseek                                ,0xffc13c9c) //101
NHSTUB(MakeDirectory_Fut                      ,0xffc1347c) //116
NHSTUB(MoveFocusLensToDistance                ,0xffe28454) //102
NHSTUB(MoveIrisWithAv                         ,0xffdd6bdc) //102
NHSTUB(MoveZoomLensWithPoint                  ,0xffdd7160) //102
//NHSTUB(NewTaskShell                         ,0xffc569cc) //103
NHSTUB(Open                                   ,0xffc13b34) //101
NHSTUB(PB2Rec                                 ,0xffc5e188) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xffc467e8) //102
NHSTUB(PT_MoveOpticalZoomAt                   ,0xffc467c0) //102
NHSTUB(PT_PlaySound                           ,0xffc460d4) //102
NHSTUB(PostLogicalEventForNotPowerType        ,0xffc5abd8) //103
NHSTUB(PostLogicalEventToUI                   ,0xffc5ac24) //103
NHSTUB(Read                                   ,0xffc0a15c) //101
NHSTUB(ReadFastDir                            ,0xffdc4160) //  1
NHSTUB(Rec2PB                                 ,0xffc5e1b8) //104
NHSTUB(RefreshPhysicalScreen                  ,0xffd66e5c) //104
//NHSTUB(Remove                               ,0xffc13ba4) //  1
NHSTUB(RenameFile_Fut                         ,0xffc133b4) //  1
NHSTUB(Restart                                ,0xffc19690) //106
NHSTUB(SetAE_ShutterSpeed                     ,0xffe2ab18) //102
NHSTUB(SetAutoShutdownTime                    ,0xffc5b5dc) //103
NHSTUB(SetCurrentCaptureModeType              ,0xffc61880) //101
NHSTUB(SetFileAttributes                      ,0xffc13e88) //  1
NHSTUB(SetFileTimeStamp                       ,0xffc13e38) //  1
NHSTUB(SetLogicalEventActive                  ,0xffc5b304) //  1
NHSTUB(SetParameterData                       ,0xffd29c0c) //101
NHSTUB(SetPropertyCase                        ,0xffc56e08) //102
NHSTUB(SetScriptMode                          ,0xffc5b354) //101
NHSTUB(SleepTask                              ,0xffc17c9c) //101
NHSTUB(TakeSemaphore                          ,0xffc0b774) //101
NHSTUB(TurnOffBackLight                       ,0xffc65db0) //104
NHSTUB(TurnOnBackLight                        ,0xffc65d98) //104
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xffd1f7a4) //103
NHSTUB(UnlockAF                               ,0xffc158b8) //102
NHSTUB(UnlockMainPower                        ,0xffc5b4bc) //103
NHSTUB(UnsetZoomForMovie                      ,0xffd2ed10) //104
NHSTUB(UpdateMBROnFlash                       ,0xffc3c710) //105
NHSTUB(VbattGet                               ,0xffc105d0) //103
NHSTUB(Write                                  ,0xffc13c08) //101
NHSTUB(WriteSDCard                            ,0xffcf8a00) //108
NHSTUB(_log                                   ,0xffe4f520) //111
NHSTUB(_log10                                 ,0xffe4e464) //112
NHSTUB(_pow                                   ,0xffe4e5d4) //114
NHSTUB(_sqrt                                  ,0xffe50888) //  1
NHSTUB(add_ptp_handler                        ,0xffd960e4) //  1
NHSTUB(apex2us                                ,0xffd68398) //  4
NHSTUB(close                                  ,0xffc09f74) //  1
NHSTUB(closedir                               ,0xffdc4230) //  1
NHSTUB(err_init_task                          ,0xffc04e98) //111
NHSTUB(exmem_alloc                            ,0xffc51af0) //103
NHSTUB(exmem_free                             ,0xffc51b68) //103
NHSTUB(free                                   ,0xffc03a98) //112
NHSTUB(kbd_p1_f                               ,0xffc11d08) //109
NHSTUB(kbd_p1_f_cont                          ,0xffc11d14) //109
NHSTUB(kbd_p2_f                               ,0xffc11548) //109
NHSTUB(kbd_read_keys                          ,0xffc11c0c) //109
NHSTUB(kbd_read_keys_r2                       ,0xffc30728) //109
NHSTUB(lseek                                  ,0xffc13c9c) //101
NHSTUB(malloc                                 ,0xffc039c4) //112
NHSTUB(memcmp                                 ,0xffc0d90c) //101
NHSTUB(memcpy                                 ,0xffc6e698) //101
NHSTUB(memset                                 ,0xffd67210) //101
NHSTUB(mkdir                                  ,0xffc13f00) //109
NHSTUB(mktime_ext                             ,0xffc6ef04) //  1
NHSTUB(open                                   ,0xffc09ec4) //  1
NHSTUB(OpenFastDir                            ,0xffdc40cc) //  1
NHSTUB(qsort                                  ,0xffd67718) //  1
NHSTUB(rand                                   ,0xffc0da14) //  1
//NHSTUB(read                                 ,0xffc0a15c) //101
NHSTUB(realloc                                ,0xffc03b78) //115
NHSTUB(reboot_fw_update                       ,0xffdc8a34) //106
NHSTUB(set_control_event                      ,0xffc5b058) //  1
NHSTUB(srand                                  ,0xffc0da08) //  1
NHSTUB(stat                                   ,0xffc13d68) //  1
NHSTUB(strcat                                 ,0xffc6e484) //  1
NHSTUB(strchr                                 ,0xffc6e50c) //  1
NHSTUB(strcmp                                 ,0xffc0d8a4) //101
NHSTUB(strcpy                                 ,0xffc0d88c) //101
NHSTUB(strftime                               ,0xffc6e90c) //  1
NHSTUB(strlen                                 ,0xffc0d8e8) //101
NHSTUB(strncmp                                ,0xffc6e4c0) //  1
NHSTUB(strncpy                                ,0xffc1d81c) //  1
NHSTUB(strrchr                                ,0xffc6e530) //  1
NHSTUB(strtol                                 ,0xffc1da54) //101
NHSTUB(strtolx                                ,0xffc1d858) //109
   DEF(task_CaptSeq                           ,0xffc488a4) //110
   DEF(task_ExpDrv                            ,0xffc900b8) //110
   DEF(task_FileWrite                         ,0xffdc0ea8) //110
   DEF(task_InitFileModules                   ,0xffc5ebf8) //110
   DEF(task_MovieRecord                       ,0xffc453d8) //110
   DEF(task_PhySw                             ,0xffc118a4) //110
NHSTUB(time                                   ,0xffc50edc) //109
NHSTUB(vsprintf                               ,0xffc0d80c) //115
//NHSTUB(write                                ,0xffc13c08) //101
//NHSTUB(EngDrvIn                             ,0xffc12b40) //102
//NHSTUB(EngDrvOut                            ,0xffc12b28) //102
//NHSTUB(EngDrvRead                           ,0xffc12b48) //102
//NHSTUB(EngDrvBits                           ,0xffc12b5c) //102
//NHSTUB(CreateTaskStrictly                   ,0xffc0bbb8) //107
//NHSTUB(CreateMessageQueue                   ,0xffc17528) //109
//NHSTUB(CreateRecursiveLock                  ,0xffc178b0) //109
//NHSTUB(GetSemaphoreValue                    ,0xffc0b87c) //119
//NHSTUB(TryTakeSemaphore                     ,0xffc0b720) //119
//NHSTUB(CreateMessageQueueStrictly           ,0xffc0bbec) //119
//NHSTUB(CreateEventFlagStrictly              ,0xffc0bc10) //119
//NHSTUB(CreateBinarySemaphoreStrictly        ,0xffc0bc34) //119
//NHSTUB(CreateCountingSemaphoreStrictly      ,0xffc0bc58) //119
//NHSTUB(CreateRecursiveLockStrictly          ,0xffc0bc7c) //119
//NHSTUB(TakeSemaphoreStrictly                ,0xffc0bca0) //119
//NHSTUB(ReceiveMessageQueueStrictly          ,0xffc0bccc) //119
//NHSTUB(PostMessageQueueStrictly             ,0xffc0bcf8) //119
//NHSTUB(WaitForAnyEventFlagStrictly          ,0xffc0bd24) //119
//NHSTUB(WaitForAllEventFlagStrictly          ,0xffc0bd50) //119
//NHSTUB(AcquireRecursiveLockStrictly         ,0xffc0bd7c) //119
//NHSTUB(DeleteMessageQueue                   ,0xffc175ac) //119
//NHSTUB(PostMessageQueue                     ,0xffc17764) //109
//NHSTUB(ReceiveMessageQueue                  ,0xffc1763c) //119
//NHSTUB(TryReceiveMessageQueue               ,0xffc176e8) //119
//NHSTUB(TryPostMessageQueue                  ,0xffc17800) //119
//NHSTUB(GetNumberOfPostedMessages            ,0xffc17840) //119
//NHSTUB(DeleteRecursiveLock                  ,0xffc17900) //119
//NHSTUB(AcquireRecursiveLock                 ,0xffc17950) //119
//NHSTUB(ReleaseRecursiveLock                 ,0xffc17a54) //119
//NHSTUB(WaitForAnyEventFlag                  ,0xffc1724c) //109
//NHSTUB(WaitForAllEventFlag                  ,0xffc172f0) //109
//NHSTUB(ClearEventFlag                       ,0xffc173ec) //112
//NHSTUB(SetEventFlag                         ,0xffc173b8) //112
//NHSTUB(GetEventFlagValue                    ,0xffc17424) //119
//NHSTUB(CreateEventFlag                      ,0xffc17114) //109
//NHSTUB(DeleteEventFlag                      ,0xffc1716c) //119
//NHSTUB(CheckAnyEventFlag                    ,0xffc171bc) //119
//NHSTUB(CheckAllEventFlag                    ,0xffc17204) //119
//NHSTUB(GetSDProtect                         ,0xffc11bec) //103
//NHSTUB(DispCon_ShowBitmapColorBar           ,0xffc2cc14) //102
//NHSTUB(ResetZoomLens                        ,0xffdd70b4) //102
//NHSTUB(ResetFocusLens                       ,0xffdd60b8) //102
//NHSTUB(NR_GetDarkSubType                    ,0xffd0dc80) //102
//NHSTUB(NR_SetDarkSubType                    ,0xffd0dc0c) //102
//NHSTUB(SavePaletteData                      ,0xffe2cb74) //102
