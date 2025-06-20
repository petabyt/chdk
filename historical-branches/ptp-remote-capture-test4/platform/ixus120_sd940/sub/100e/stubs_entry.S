// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R39 (DRYOS version 2.3, release #0039)
//   Firmware Ver GM1.00E
//   Canon DIGITAL IXUS 120 IS

// Values for makefile.inc
//   PLATFORMOSVER = 39
//   PLATFORMID = 12774 (0x31e6) // Found @ 0xfffe0130
//   MAXRAMADDR = 0x03ffffff
//   KEYSYS = d4                 // Found @ 0xffff3564
//   NEED_ENCODED_DISKBOOT = 3   // Found @ 0xffff3574

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NHSTUB(kbd_pwr_off                          ,0xff858e10) //  2 64%    *** != 0x00000000
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff88e694 -> ff88ae44 -> ff96a330 -> ffa759ac -> ffb970c0
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00031b78) // Found @0xff833554
DEF(physw_run                               ,0x00001c44) // Found @0xff8331c8
DEF(physw_sleep_delay                       ,0x00001c42) // Found @0xff8331c8
DEF(levent_table                            ,0xffb41ee0) // Found @0xffb41ee0
DEF(FlashParamsTable                        ,0xffb972a8) // Found @0xffb972a8
DEF(movie_status                            ,0x00006260) // Found @0xff93d344
DEF(full_screen_refresh                     ,0x00008bb0) // Found @0xff9cf9a0
DEF(canon_menu_active                       ,0x00002d48) // Found @0xff8854d4
DEF(canon_shoot_menu_active                 ,0x0000774d) // Found @0xff97b980
DEF(playrec_mode                            ,0x00002a7c) // Found @0xff877af0
DEF(zoom_status                             ,0x0000b9dc) // Found @0xffa78244
DEF(some_flag_for_af_scan                   ,0x0000673c) // Found @0xff940334
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 3 int value(s), the first is the zoom focus length.
// there are 10 entries in the table - set NUM_FL to 10
DEF(focus_len_table                         ,0xfffe2a8c) // Found @0xfffe2a8c
DEF(zoom_busy                               ,0x000061cc) // Found @0xff93a418
DEF(focus_busy                              ,0x00006078) // Found @0xff934990
DEF(recreview_hold                          ,0x000033a4) // Found @0xff8942c8

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x403f1000; }             // Found @0xff8532dc
//void *vid_get_viewport_fb()      { return (void*)0x4088b700; }             // Found @0xffad4700
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x2790+0x58)); } // Found @0xff869dec & 0xff869e24
//char *camera_jpeg_count_str()    { return (char*)0x000700b0; }             // Found @0xff9c40fc
//long hook_raw_size()             { return 0x011ca240; }                    // Found @0xffad6e88
//int get_flash_params_count(void) { return 0x84; }                          // Found @0xff96b3ec

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffb0c720, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x00080000 // Found @0xffb0c738, levent 0x902
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_SET             ,0x00000004 }, // Found @0xffb0c660, levent 0x08
//    { 0, KEY_DISPLAY         ,0x00000008 }, // Found @0xffb0c66c, levent 0x0a
//    { 2, KEY_MENU            ,0x00000001 }, // Found @0xffb0c684, levent 0x09
//    { 2, KEY_ZOOM_IN         ,0x00000004 }, // Found @0xffb0c690, levent 0x02
//    { 2, KEY_ZOOM_OUT        ,0x00000008 }, // Found @0xffb0c69c, levent 0x03
//    { 2, KEY_LEFT            ,0x00000010 }, // Found @0xffb0c6a8, levent 0x06
//    { 2, KEY_RIGHT           ,0x00000020 }, // Found @0xffb0c6b4, levent 0x07
//    { 2, KEY_DOWN            ,0x00000040 }, // Found @0xffb0c6c0, levent 0x05
//    { 2, KEY_UP              ,0x00000080 }, // Found @0xffb0c6cc, levent 0x04
//    { 2, KEY_SHOOT_FULL      ,0x00000300 }, // Found @0xffb0c6e4, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000200 }, // Found @0xffb0c6e4, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00000100 }, // Found @0xffb0c6d8, levent 0x00
//    { 2, KEY_POWER           ,0x00000400 }, // Found @0xffb0c6f0, levent 0x600
//    { 2, KEY_PLAYBACK        ,0x00000800 }, // Found @0xffb0c6fc, levent 0x601
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_RAW_ROWPIX    4080 // Found @0xff9111d4
//#define CAM_RAW_ROWS      3048 // Found @0xff9111dc
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff8388dc

// Misc stuff
DEF(ctypes, 0xffb0b1da)

// For capt_seq.c
DEF(_nrflag,0x6718) // Found @ ff94249c (0x6720) & ff9424bc (-0x08)
//static long *nrflag = (long*)(0x6720-0x08);  // Found @ ff94249c & ff9424b8

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
//NHSTUB(CreateJumptable                      ,0xffad7910) //  1
//NHSTUB(_uartr_req                           ,0xff81f954) //111
//NHSTUB(AllocateMemory                       ,0xffa69c80) //101
NHSTUB(AllocateUncacheableMemory              ,0xff838898) //112
NHSTUB(Close                                  ,0xff8353b4) //101
NHSTUB(CreateTask                             ,0xff81e5b4) //101
NHSTUB(DebugAssert                            ,0xff81e88c) //111
NHSTUB(DeleteDirectory_Fut                    ,0xff834e24) //116
NHSTUB(DeleteFile_Fut                         ,0xff834d40) //112
NHSTUB(DoAFLock                               ,0xff83687c) //102
NHSTUB(EnterToCompensationEVF                 ,0xff8369d4) //104
NHSTUB(ExecuteEventProcedure                  ,0xff880bf8) //104
NHSTUB(ExitFromCompensationEVF                ,0xff836a18) //104
NHSTUB(ExitTask                               ,0xff81e844) //101
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff844034) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff84410c) //104
NHSTUB(Fclose_Fut                             ,0xff834ebc) //101
NHSTUB(Feof_Fut                               ,0xff8350a8) //  1
NHSTUB(Fflush_Fut                             ,0xff8350e4) //  1
NHSTUB(Fgets_Fut                              ,0xff835010) //  1
NHSTUB(Fopen_Fut                              ,0xff834e7c) //101
NHSTUB(Fread_Fut                              ,0xff834f68) //101
//NHSTUB(FreeMemory                           ,0xffa69c78) //101
NHSTUB(FreeUncacheableMemory                  ,0xff8388d8) //112
NHSTUB(Fseek_Fut                              ,0xff83505c) //101
NHSTUB(Fwrite_Fut                             ,0xff834fbc) //101
NHSTUB(GetBatteryTemperature                  ,0xff85bd0c) //102
NHSTUB(GetCCDTemperature                      ,0xff85bc98) //102
NHSTUB(GetCurrentAvValue                      ,0xff93653c) //102
NHSTUB(GetDrive_ClusterSize                   ,0xff868774) //  3
NHSTUB(GetDrive_FreeClusters                  ,0xff8687d4) //  3
NHSTUB(GetDrive_TotalClusters                 ,0xff8687a8) //  3
NHSTUB(GetFocusLensSubjectDistance            ,0xff935708) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff935b50) //  3
NHSTUB(GetImageFolder                         ,0xff919000) //106
NHSTUB(GetKbdState                            ,0xff858df8) //109
NHSTUB(GetMemInfo                             ,0xff81a070) //115
NHSTUB(GetOpticalTemperature                  ,0xff85bd80) //102
NHSTUB(GetParameterData                       ,0xff96b3ac) //101
NHSTUB(GetPropertyCase                        ,0xff884948) //102
NHSTUB(GetSystemTime                          ,0xffa69cd8) //101
NHSTUB(GetVRAMHPixelsSize                     ,0xff8da2c8) //102
NHSTUB(GetVRAMVPixelsSize                     ,0xff8da2d4) //102
NHSTUB(GetZoomLensCurrentPoint                ,0xff93a78c) //102
NHSTUB(GetZoomLensCurrentPosition             ,0xffa5d8e8) //102
NHSTUB(GiveSemaphore                          ,0xff8382b4) //112
NHSTUB(IsStrobeChargeCompleted                ,0xff8bc24c) //102
NHSTUB(LEDDrive                               ,0xff8582f4) //103
NHSTUB(LocalTime                              ,0xff87e56c) //115
NHSTUB(LockMainPower                          ,0xff88aa60) //103
//NHSTUB(Lseek                                ,0xff8354d0) //101
NHSTUB(MakeDirectory_Fut                      ,0xff834db4) //116
NHSTUB(MoveFocusLensToDistance                ,0xffad108c) //102
NHSTUB(MoveIrisWithAv                         ,0xffa677c0) //102
NHSTUB(MoveZoomLensWithPoint                  ,0xffa67d4c) //102
//NHSTUB(NewTaskShell                         ,0xff88440c) //103
NHSTUB(Open                                   ,0xff83535c) //101
NHSTUB(PB2Rec                                 ,0xff88d9fc) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff870934) //102
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff87090c) //102
NHSTUB(PT_PlaySound                           ,0xff879708) //102
NHSTUB(PostLogicalEventForNotPowerType        ,0xff88a298) //103
NHSTUB(PostLogicalEventToUI                   ,0xff88a2e4) //103
NHSTUB(PutInNdFilter                          ,0xffa67bb0) //102
NHSTUB(PutOutNdFilter                         ,0xffa67bd4) //102
NHSTUB(Read                                   ,0xff81ab78) //101
NHSTUB(ReadFastDir                            ,0xffa4d0a0) //  3
NHSTUB(Rec2PB                                 ,0xff88da3c) //104
NHSTUB(RefreshPhysicalScreen                  ,0xff9d1e70) //104
//NHSTUB(Remove                               ,0xff8353e8) //  4
NHSTUB(RenameFile_Fut                         ,0xff834cac) //116
NHSTUB(Restart                                ,0xff839ff0) //106
NHSTUB(ScreenLock                             ,0xff9d1c48) // 10
NHSTUB(ScreenUnlock                           ,0xff9d1c88) //  3
NHSTUB(SetAE_ShutterSpeed                     ,0xffad3878) //102
NHSTUB(SetAutoShutdownTime                    ,0xff88aad4) //103
NHSTUB(SetCurrentCaptureModeType              ,0xff891b0c) //101
NHSTUB(SetFileAttributes                      ,0xff835684) //  3
NHSTUB(SetFileTimeStamp                       ,0xff835640) //  3
NHSTUB(SetLogicalEventActive                  ,0xff88a7dc) //101
NHSTUB(SetParameterData                       ,0xff96b31c) //101
NHSTUB(SetPropertyCase                        ,0xff88484c) //102
NHSTUB(SetScriptMode                          ,0xff88a82c) //101
NHSTUB(SleepTask                              ,0xff83851c) //101
NHSTUB(TakeSemaphore                          ,0xff8381e4) //101
NHSTUB(TurnOffBackLight                       ,0xff89764c) //104
NHSTUB(TurnOnBackLight                        ,0xff897634) //104
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff956720) //105
NHSTUB(UnlockAF                               ,0xff8368b4) //102
NHSTUB(UnlockMainPower                        ,0xff88a9b4) //103
NHSTUB(UnsetZoomForMovie                      ,0xff9712b8) //104
NHSTUB(UpdateMBROnFlash                       ,0xff8685f4) //105
NHSTUB(VbattGet                               ,0xff831df4) //103
NHSTUB(Write                                  ,0xff835444) //101
NHSTUB(WriteSDCard                            ,0xff926644) //108
NHSTUB(_log                                   ,0xffb08c9c) //111
NHSTUB(_log10                                 ,0xffb07be0) //112
NHSTUB(_pow                                   ,0xffb07d50) //114
NHSTUB(_sqrt                                  ,0xffb0a004) //  1
NHSTUB(add_ptp_handler                        ,0xffa16dec) //  3
NHSTUB(apex2us                                ,0xff9d5360) //  4
NHSTUB(close                                  ,0xff81a990) //  1
NHSTUB(closedir                               ,0xffa4cf28) //  3
NHSTUB(err_init_task                          ,0xff815f28) //111
NHSTUB(exmem_alloc                            ,0xff87f42c) //103
NHSTUB(exmem_free                             ,0xff87f4a4) //103
NHSTUB(free                                   ,0xff814138) //112
NHSTUB(kbd_p1_f                               ,0xff8335d0) //109
NHSTUB(kbd_p1_f_cont                          ,0xff8335dc) //109
NHSTUB(kbd_p2_f                               ,0xff832e94) //109
NHSTUB(kbd_read_keys                          ,0xff833554) //109
NHSTUB(kbd_read_keys_r2                       ,0xff8587b8) //109
NHSTUB(lseek                                  ,0xff8354d0) //101
NHSTUB(malloc                                 ,0xff8140dc) //112
NHSTUB(memcmp                                 ,0xff8203d8) //101
NHSTUB(memcpy                                 ,0xff83de48) //101
NHSTUB(memset                                 ,0xff9d43b0) //101
NHSTUB(mkdir                                  ,0xff835828) //109
NHSTUB(mktime_ext                             ,0xff89ea7c) //  1
NHSTUB(open                                   ,0xff81a8e0) //  1
NHSTUB(OpenFastDir                            ,0xffa4cf6c) //  3
NHSTUB(qsort                                  ,0xffab56b4) //  1
NHSTUB(rand                                   ,0xff8204e0) //  1
//NHSTUB(read                                 ,0xff81ab78) //101
NHSTUB(realloc                                ,0xff9d442c) //115
NHSTUB(reboot_fw_update                       ,0xffa525b0) //106
NHSTUB(set_control_event                      ,0xff88a500) //111
NHSTUB(srand                                  ,0xff8204d4) //  1
NHSTUB(stat                                   ,0xff83550c) //109
NHSTUB(strcat                                 ,0xff89e238) //  1
NHSTUB(strchr                                 ,0xff813fc0) //  1
NHSTUB(strcmp                                 ,0xff820394) //101
NHSTUB(strcpy                                 ,0xff82037c) //101
NHSTUB(strftime                               ,0xff89e484) //  1
NHSTUB(strlen                                 ,0xff81400c) //101
NHSTUB(strncmp                                ,0xff813f74) //  1
NHSTUB(strncpy                                ,0xff813f38) //  1
NHSTUB(strrchr                                ,0xff813fe4) //  1
NHSTUB(strtol                                 ,0xff83e128) //101
NHSTUB(strtolx                                ,0xff83df2c) //109
   DEF(task_CaptSeq                           ,0xff872f84) //107
   DEF(task_ExpDrv                            ,0xff8b2f58) //110
   DEF(task_FileWrite                         ,0xffa488fc) //107
   DEF(task_InitFileModules                   ,0xff88e520) //107
   DEF(task_MovieRecord                       ,0xff93d62c) //107
   DEF(task_PhySw                             ,0xff8331c4) //107
NHSTUB(time                                   ,0xff87eae4) //109
NHSTUB(vsprintf                               ,0xff820340) //115
//NHSTUB(write                                ,0xff835444) //101
//NHSTUB(EngDrvIn                             ,0xff834410) //102
//NHSTUB(EngDrvOut                            ,0xff8343f8) //102
//NHSTUB(EngDrvRead                           ,0xff834418) //102
//NHSTUB(EngDrvBits                           ,0xff83442c) //102
//NHSTUB(GetSDProtect                         ,0xff83352c) //103
//NHSTUB(StartRecModeMenu                     ,0xff8854d0) //102
//NHSTUB(DispCon_ShowBitmapColorBar           ,0xff853294) //102
//NHSTUB(ResetZoomLens                        ,0xffa67ca0) //102
//NHSTUB(ResetFocusLens                       ,0xffa66ac4) //102
//NHSTUB(NR_GetDarkSubType                    ,0xff944ab4) //102
//NHSTUB(NR_SetDarkSubType                    ,0xff944a0c) //102
//NHSTUB(SavePaletteData                      ,0xffad5be0) //102
//NHSTUB(GUISrv_StartGUISystem                ,0xff89dfb8) //101
