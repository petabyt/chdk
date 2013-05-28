// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R31 (DRYOS version 2.3, release #0031)
//   Firmware Ver GM1.00C
//   Canon PowerShot A2000 IS

// Values for makefile.inc
//   PLATFORMOSVER = 31
//   PLATFORMID = 12689 (0x3191) // Found @ 0xfffe0130
//   MAXRAMADDR = 0x03ffffff
//   KEYSYS = d4                 // Found @ 0xffff1a98
//   NEED_ENCODED_DISKBOOT = 1   // Found @ 0xffff1aa8

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NHSTUB(ExecuteEventProcedure                ,0xffc553c4) //104        *** != 0xffc5543c
//NHSTUB(GetBatteryTemperature                ,0xffc33504) //102        *** != 0xffc33494
//NHSTUB(Lseek                                ,0xffc13484) //101        *** != 0xffc1354c
//NHSTUB(Read                                 ,0xffc0a138) //101        *** != 0xffc133ec
//NHSTUB(kbd_pwr_off                          ,0xffc31408) //  2 64%    *** != 0xffc31418
NHSTUB(kbd_pwr_on                             ,0xffc313c8) //  2 82%
//NHSTUB(write                                ,0xffc133f0) //101        *** != 0xffc0a198

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ffc603dc -> ffc5cd98 -> ffd2c470 -> ffdfbf48 -> ffeb9b10
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x0000f418) // Found @0xffc113ec
DEF(physw_run                               ,0x00001be4) // Found @0xffc11064
DEF(physw_sleep_delay                       ,0x00001be2) // Found @0xffc11064
DEF(levent_table                            ,0xffe9ac78) // Found @0xffe9ac78
DEF(FlashParamsTable                        ,0xffeb9cdc) // Found @0xffeb9cdc
DEF(movie_status                            ,0x00005080) // Found @0xffc47950
DEF(canon_menu_active                       ,0x00005460) // Found @0xffc59b98
DEF(canon_shoot_menu_active                 ,0x00009735) // Found @0xffd3bcf4
DEF(playrec_mode                            ,0x00005208) // Found @0xffc4e8ac
DEF(zoom_status                             ,0x0000c0cc) // Found @0xffdfd75c
DEF(some_flag_for_af_scan                   ,0x000085a0) // Found @0xffd0a758
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 3 int value(s), the first is the zoom focus length.
// there are 15 entries in the table - set NUM_FL to 15
DEF(focus_len_table                         ,0xfffe297c) // Found @0xfffe297c
DEF(zoom_busy                               ,0x00007ff8) // Found @0xffd0312c
DEF(focus_busy                              ,0x00007ee4) // Found @0xffcfe824
//DEF(recreview_hold                          ,0x000059c0) // Found @0xffc65674, ** != ** stubs_min = 0x000094c0 (0x9408+0xB8)

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x10361000; }             // Found @0xffc2cea0
//void *vid_get_viewport_fb()      { return (void*)0x10659de0; }             // Found @0xffe44918
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x4ecc+0x54)); } // Found @0xffc413c0 & 0xffc413ec
//char *camera_jpeg_count_str()    { return (char*)0x00045100; }             // Found @0xffd71398
//long hook_raw_size()             { return 0x00ec04f0; }                    // Found @0xffe46cbc
//int get_flash_params_count(void) { return 0x77; }                          // Found @0xffd2d52c

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffe75da0, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x00040000 // Found @0xffe75dac, levent 0x902
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 1, KEY_POWER           ,0x00004000 }, // Found @0xffe75c5c, levent 0x600 (uses inverted logic in physw_status)
//    { 1, KEY_PLAYBACK        ,0x02000000 }, // Found @0xffe75c80, levent 0x601 (uses inverted logic in physw_status)
//    { 1, KEY_SHOOT_FULL      ,0xc0000000 }, // Found @0xffe75cc8, levent 0x01
//    { 1, KEY_SHOOT_FULL_ONLY ,0x80000000 }, // Found @0xffe75cc8, levent 0x01
//    { 1, KEY_SHOOT_HALF      ,0x40000000 }, // Found @0xffe75cbc, levent 0x00
//    { 2, KEY_ZOOM_IN         ,0x00000004 }, // Found @0xffe75cec, levent 0x02
//    { 2, KEY_ZOOM_OUT        ,0x00000008 }, // Found @0xffe75cf8, levent 0x03
//    { 2, KEY_UP              ,0x00000010 }, // Found @0xffe75d04, levent 0x04
//    { 2, KEY_DOWN            ,0x00000020 }, // Found @0xffe75d10, levent 0x05
//    { 2, KEY_RIGHT           ,0x00000040 }, // Found @0xffe75d1c, levent 0x07
//    { 2, KEY_LEFT            ,0x00000080 }, // Found @0xffe75d28, levent 0x06
//    { 2, KEY_SET             ,0x00000100 }, // Found @0xffe75d34, levent 0x08
//    { 2, KEY_MENU            ,0x00000200 }, // Found @0xffe75d40, levent 0x09
//    { 2, KEY_DISPLAY         ,0x00000400 }, // Found @0xffe75d4c, levent 0x0a
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_RAW_ROWPIX    3720 // Found @0xffe3db80
//#define CAM_RAW_ROWS      2772 // Found @0xffe3db88
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x10000000 // Found @0xffc171b8

// Misc stuff
DEF(ctypes, 0xffe75886)

// For capt_seq.c
//static long *nrflag = (long*)(0x8590-0x04);  // Found @ ffd0c3cc & ffd0c3e4

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
//NHSTUB(CreateJumptable                      ,0xffe473f0) //  1
//NHSTUB(_uartr_req                           ,0xffc0ce54) //111
//NHSTUB(AllocateMemory                       ,0xffdf0a50) //101
NHSTUB(AllocateUncacheableMemory              ,0xffc17174) //112
NHSTUB(Close                                  ,0xffc13344) //101
NHSTUB(CreateTask                             ,0xffc0b8c0) //101
NHSTUB(DebugAssert                            ,0xffc0bd98) //111
NHSTUB(DeleteDirectory_Fut                    ,0xffc12cd4) //116
NHSTUB(DeleteFile_Fut                         ,0xffc12bf0) //112
NHSTUB(DoAFLock                               ,0xffc14d9c) //102
NHSTUB(EnterToCompensationEVF                 ,0xffc14fec) //104
NHSTUB(ExitFromCompensationEVF                ,0xffc15030) //104
NHSTUB(ExitTask                               ,0xffc0bb50) //101
NHSTUB(ExpCtrlTool_StartContiAE               ,0xffc1fa68) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xffc1fbac) //104
NHSTUB(Fclose_Fut                             ,0xffc12d6c) //101
NHSTUB(Feof_Fut                               ,0xffc12f58) //  1
NHSTUB(Fflush_Fut                             ,0xffc12f94) //  1
NHSTUB(Fgets_Fut                              ,0xffc12ec0) //  1
NHSTUB(Fopen_Fut                              ,0xffc12d2c) //101
NHSTUB(Fread_Fut                              ,0xffc12e18) //101
//NHSTUB(FreeMemory                           ,0xffdf0a48) //101
NHSTUB(FreeUncacheableMemory                  ,0xffc171b4) //112
NHSTUB(Fseek_Fut                              ,0xffc12f0c) //101
NHSTUB(Fwrite_Fut                             ,0xffc12e6c) //101
NHSTUB(GetCCDTemperature                      ,0xffc33494) //102
NHSTUB(GetCurrentAvValue                      ,0xffd0025c) //102
NHSTUB(GetDrive_ClusterSize                   ,0xffc3fc24) //  1
NHSTUB(GetDrive_FreeClusters                  ,0xffc3fc8c) //  1
NHSTUB(GetDrive_TotalClusters                 ,0xffc3fc58) //  1
NHSTUB(GetFocusLensSubjectDistance            ,0xffcff354) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xffcff660) //  3
NHSTUB(GetKbdState                            ,0xffc31394) //109
NHSTUB(GetMemInfo                             ,0xffc03c28) //115
NHSTUB(GetOpticalTemperature                  ,0xffc33574) //102
NHSTUB(GetParameterData                       ,0xffd2d4ec) //101
NHSTUB(GetPropertyCase                        ,0xffc590ac) //102
NHSTUB(GetSystemTime                          ,0xffdf0aa8) //101
NHSTUB(GetVRAMHPixelsSize                     ,0xffca2058) //102
NHSTUB(GetVRAMVPixelsSize                     ,0xffca2064) //102
NHSTUB(GetZoomLensCurrentPoint                ,0xffd0349c) //102
NHSTUB(GetZoomLensCurrentPosition             ,0xffdea9dc) //102
NHSTUB(GiveSemaphore                          ,0xffc0b81c) //112
NHSTUB(IsStrobeChargeCompleted                ,0xffc8aef4) //102
NHSTUB(LEDDrive                               ,0xffc30a70) //103
NHSTUB(LocalTime                              ,0xffc533c8) //115
NHSTUB(LockMainPower                          ,0xffc5c9b0) //103
NHSTUB(MakeDirectory_Fut                      ,0xffc12c64) //116
NHSTUB(MoveFocusLensToDistance                ,0xffe4135c) //102
NHSTUB(MoveIrisWithAv                         ,0xffded27c) //102
NHSTUB(MoveZoomLensWithPoint                  ,0xffded808) //102
//NHSTUB(NewTaskShell                         ,0xffc58b54) //103
NHSTUB(Open                                   ,0xffc1331c) //101
NHSTUB(PB2Rec                                 ,0xffc5e3ec) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xffc48cec) //102
NHSTUB(PT_MoveOpticalZoomAt                   ,0xffc48cc4) //102
NHSTUB(PT_PlaySound                           ,0xffc488d4) //102
NHSTUB(PostLogicalEventForNotPowerType        ,0xffc5bff0) //103
NHSTUB(PostLogicalEventToUI                   ,0xffc5c03c) //103
NHSTUB(PutInNdFilter                          ,0xffded66c) //102
NHSTUB(PutOutNdFilter                         ,0xffded690) //102
NHSTUB(ReadFastDir                            ,0xffddce7c) //  1
NHSTUB(Rec2PB                                 ,0xffc5e440) //104
NHSTUB(RefreshPhysicalScreen                  ,0xffd7af58) //104
//NHSTUB(Remove                               ,0xffc1338c) //  1
NHSTUB(RenameFile_Fut                         ,0xffc12b9c) //  1
NHSTUB(Restart                                ,0xffc189ec) //106
NHSTUB(SetAE_ShutterSpeed                     ,0xffe43b28) //102
NHSTUB(SetAutoShutdownTime                    ,0xffc5ca24) //103
NHSTUB(SetCurrentCaptureModeType              ,0xffc6301c) //101
NHSTUB(SetFileAttributes                      ,0xffc13670) //  1
NHSTUB(SetFileTimeStamp                       ,0xffc13620) //  1
NHSTUB(SetLogicalEventActive                  ,0xffc5c72c) //101
NHSTUB(SetParameterData                       ,0xffd2d45c) //101
NHSTUB(SetPropertyCase                        ,0xffc58fa4) //102
NHSTUB(SetScriptMode                          ,0xffc5c77c) //101
NHSTUB(SleepTask                              ,0xffc16ff8) //101
NHSTUB(TakeSemaphore                          ,0xffc0b74c) //101
NHSTUB(TurnOffBackLight                       ,0xffc67b10) //104
NHSTUB(TurnOnBackLight                        ,0xffc67af8) //104
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xffd20598) //103
NHSTUB(UnlockAF                               ,0xffc14dd4) //102
NHSTUB(UnlockMainPower                        ,0xffc5c904) //103
NHSTUB(UnsetZoomForMovie                      ,0xffd32ad8) //104
NHSTUB(UpdateMBROnFlash                       ,0xffc3fa64) //105
NHSTUB(VbattGet                               ,0xffc10314) //103
NHSTUB(Write                                  ,0xffc133f0) //101
NHSTUB(WriteSDCard                            ,0xffcf4aa8) //108
NHSTUB(_log                                   ,0xffe7368c) //111
NHSTUB(_log10                                 ,0xffe725d0) //112
NHSTUB(_pow                                   ,0xffe72740) //114
NHSTUB(_sqrt                                  ,0xffe749f4) //  1
NHSTUB(add_ptp_handler                        ,0xffdac444) //  1
NHSTUB(apex2us                                ,0xffd7bf74) //  4
NHSTUB(close                                  ,0xffc09f50) //  1
NHSTUB(closedir                               ,0xffddcf4c) //  1
NHSTUB(err_init_task                          ,0xffc04e84) //111
NHSTUB(exmem_alloc                            ,0xffc53bc8) //103
NHSTUB(exmem_free                             ,0xffc53c40) //103
NHSTUB(free                                   ,0xffc03a80) //112
NHSTUB(kbd_p1_f                               ,0xffc114f0) //109
NHSTUB(kbd_p1_f_cont                          ,0xffc114fc) //109
NHSTUB(kbd_p2_f                               ,0xffc10d04) //109
NHSTUB(kbd_read_keys                          ,0xffc113ec) //109
NHSTUB(kbd_read_keys_r2                       ,0xffc30e84) //109
NHSTUB(lseek                                  ,0xffc13484) //101
NHSTUB(malloc                                 ,0xffc039ac) //112
NHSTUB(memcmp                                 ,0xffc0d8b4) //101
NHSTUB(memcpy                                 ,0xffc6cac8) //101
NHSTUB(memset                                 ,0xffd7b2ac) //101
NHSTUB(mkdir                                  ,0xffc136e8) //109
NHSTUB(mktime_ext                             ,0xffc6d334) //  1
NHSTUB(open                                   ,0xffc09ea0) //  1
NHSTUB(OpenFastDir                            ,0xffddcde8) //  1
NHSTUB(qsort                                  ,0xffe2cb98) //  1
NHSTUB(rand                                   ,0xffc0d9bc) //  1
//NHSTUB(read                                 ,0xffc0a138) //101
NHSTUB(realloc                                ,0xffc03b60) //115
NHSTUB(reboot_fw_update                       ,0xffde1750) //106
NHSTUB(set_control_event                      ,0xffc5c478) //  1
NHSTUB(srand                                  ,0xffc0d9b0) //  1
NHSTUB(stat                                   ,0xffc13550) //  1
NHSTUB(strcat                                 ,0xffc6c8dc) //  1
NHSTUB(strchr                                 ,0xffc6c964) //  1
NHSTUB(strcmp                                 ,0xffc0d84c) //101
NHSTUB(strcpy                                 ,0xffc0d834) //101
NHSTUB(strftime                               ,0xffc6cd3c) //  1
NHSTUB(strlen                                 ,0xffc0d890) //101
NHSTUB(strncmp                                ,0xffc6c918) //  1
NHSTUB(strncpy                                ,0xffc1cb54) //  1
NHSTUB(strrchr                                ,0xffd7b284) //  1
NHSTUB(strtol                                 ,0xffc1cd8c) //101
NHSTUB(strtolx                                ,0xffc1cb90) //109
   DEF(task_CaptSeq                           ,0xffc4ae84) //107
   DEF(task_ExpDrv                            ,0xffc83eb0) //110
   DEF(task_InitFileModules                   ,0xffc60268) //107
   DEF(task_MovieRecord                       ,0xffc47bb4) //107
   DEF(task_PhySw                             ,0xffc11060) //107
NHSTUB(time                                   ,0xffc5327c) //109
NHSTUB(vsprintf                               ,0xffc0d7f8) //115
NHSTUB(EngDrvIn                               ,0xffdbcc5c) //102
NHSTUB(EngDrvOut                              ,0xffdbcc40) //102
NHSTUB(EngDrvRead                             ,0xffdbcc64) //102
NHSTUB(EngDrvBits                             ,0xffdbcc6c) //102
//NHSTUB(GetSDProtect                         ,0xffc113c4) //103
//NHSTUB(StartRecModeMenu                     ,0xffc59b94) //102
//NHSTUB(DispCon_ShowBitmapColorBar           ,0xffc2ce6c) //102
//NHSTUB(ResetZoomLens                        ,0xffded75c) //102
//NHSTUB(ResetFocusLens                       ,0xffdec760) //102
//NHSTUB(NR_GetDarkSubType                    ,0xffd0d778) //102
//NHSTUB(NR_SetDarkSubType                    ,0xffd0d6cc) //102
//NHSTUB(SavePaletteData                      ,0xffe45b94) //102
