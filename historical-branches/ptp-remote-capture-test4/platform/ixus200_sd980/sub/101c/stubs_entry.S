// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R39 (DRYOS version 2.3, release #0039)
//   Firmware Ver GM1.01C
//   Canon DIGITAL IXUS 200 IS

// Values for makefile.inc
//   PLATFORMOSVER = 39
//   PLATFORMID = 12773 (0x31e5) // Found @ 0xfffe0130
//   MAXRAMADDR = 0x03ffffff
//   KEYSYS = d4                 // Found @ 0xffff3564
//   NEED_ENCODED_DISKBOOT = 3   // Found @ 0xffff3574

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
NHSTUB(kbd_pwr_off                            ,0xff85ae98) //  2 64%
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff894674 -> ff890d94 -> ff978aa0 -> ffaab250 -> ffbda9ac
// Mode 32774 in firmware but not in current modemap
// Mode 33288 in firmware but not in current modemap
// Mode 33307 in firmware but not in current modemap
// Mode 33308 in firmware but not in current modemap
// Mode 32797 in firmware but not in current modemap
// Mode 32786 in firmware but not in current modemap
// Mode 32788 in firmware but not in current modemap
// Mode 32789 in firmware but not in current modemap
// Mode 32785 in firmware but not in current modemap
// Mode 33295 in firmware but not in current modemap
// Mode 32784 in firmware but not in current modemap
// Mode  2601 in firmware but not in current modemap
// Mode  2602 in firmware but not in current modemap
// Current modemap entry not found in firmware - MODE_SCN_COLOR_SWAP      16924
// Current modemap entry not found in firmware - MODE_SCN_COLOR_ACCENT    16923
// Current modemap entry not found in firmware - MODE_SCN_ISO_3200        16413
// Current modemap entry not found in firmware - MODE_SCN_BEACH           16405
// Current modemap entry not found in firmware - MODE_SCN_SNOW            16404
// Current modemap entry not found in firmware - MODE_SCN_SUNSET          16402
// Current modemap entry not found in firmware - MODE_SCN_INDOOR          16401
// Current modemap entry not found in firmware - MODE_SCN_NIGHT_SCENE     16398
// Current modemap entry not found in firmware - MODE_SPORTS              33287
// Current modemap entry not found in firmware - MODE_VIDEO_STD            3622
// Current modemap entry not found in firmware - MODE_LANDSCAPE           32780
// Current modemap entry not found in firmware - MODE_M                   32769
// Current modemap entry not found in firmware - MODE_AV                  32770
// Current modemap entry not found in firmware - MODE_TV                  32771

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00044558) // Found @0xff8335a8
DEF(physw_run                               ,0x00001c44) // Found @0xff833200
DEF(physw_sleep_delay                       ,0x00001c42) // Found @0xff833200
DEF(levent_table                            ,0xffb7a2a0) // Found @0xffb7a2a0
DEF(FlashParamsTable                        ,0xffbdab94) // Found @0xffbdab94
DEF(movie_status                            ,0x000067e0) // Found @0xff94ac20
DEF(full_screen_refresh                     ,0x0001b2dc) // Found @0xff9f751c
DEF(canon_menu_active                       ,0x00002ec8) // Found @0xff889704
DEF(canon_shoot_menu_active                 ,0x00007b09) // Found @0xff98d9ac
DEF(playrec_mode                            ,0x00002bfc) // Found @0xff87bbdc
DEF(zoom_status                             ,0x0001e3d4) // Found @0xffaadcdc
DEF(some_flag_for_af_scan                   ,0x00006cd4) // Found @0xff94dc3c
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 3 int value(s), the first is the zoom focus length.
// there are 12 entries in the table - set NUM_FL to 12
DEF(focus_len_table                         ,0xfffe2ac8) // Found @0xfffe2ac8
DEF(zoom_busy                               ,0x0000670c) // Found @0xff946e00
DEF(focus_busy                              ,0x00006608) // Found @0xff941f28
DEF(recreview_hold                          ,0x00003818) // Found @0xff89a778

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x40431000; }             // Found @0xff853588
//void *vid_get_viewport_fb()      { return (void*)0x408cb700; }             // Found @0xffb0b880
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x28f0+0x58)); } // Found @0xff86d354 & 0xff86d38c
//char *camera_jpeg_count_str()    { return (char*)0x00084ca4; }             // Found @0xff9e8aa8
//long hook_raw_size()             { return 0x011ca240; }                    // Found @0xffb0e710
//int get_flash_params_count(void) { return 0x84; }                          // Found @0xff979b5c

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffb404e8, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x00100000 // Found @0xffb40500, levent 0x902
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 2, KEY_MENU            ,0x00000001 }, // Found @0xffb40440, levent 0x09
//    { 2, KEY_SET             ,0x00000002 }, // Found @0xffb4044c, levent 0x08
//    { 2, KEY_ZOOM_IN         ,0x00000004 }, // Found @0xffb40458, levent 0x02
//    { 2, KEY_ZOOM_OUT        ,0x00000008 }, // Found @0xffb40464, levent 0x03
//    { 2, KEY_LEFT            ,0x00000010 }, // Found @0xffb40470, levent 0x06
//    { 2, KEY_RIGHT           ,0x00000020 }, // Found @0xffb4047c, levent 0x07
//    { 2, KEY_DOWN            ,0x00000040 }, // Found @0xffb40488, levent 0x05
//    { 2, KEY_UP              ,0x00000080 }, // Found @0xffb40494, levent 0x04
//    { 2, KEY_SHOOT_FULL      ,0x00000300 }, // Found @0xffb404ac, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000200 }, // Found @0xffb404ac, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00000100 }, // Found @0xffb404a0, levent 0x00
//    { 2, KEY_POWER           ,0x00000400 }, // Found @0xffb404b8, levent 0x600
//    { 2, KEY_PLAYBACK        ,0x00000800 }, // Found @0xffb404c4, levent 0x601
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_RAW_ROWPIX    4080 // Found @0xff91bfbc
//#define CAM_RAW_ROWS      3048 // Found @0xff91bfc4
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff838a1c

// Misc stuff
DEF(ctypes, 0xffb3eb3e)

// For capt_seq.c
DEF(_nrflag,0x6cb0) // Found @ ff94ff04 (0x6cb8) & ff94ff24 (-0x08)
//static long *nrflag = (long*)(0x6cb8-0x08);  // Found @ ff94ff04 & ff94ff20

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
//NHSTUB(CreateJumptable                      ,0xffb0f1b8) //  1
//NHSTUB(_uartr_req                           ,0xff81f964) //111
//NHSTUB(AllocateMemory                       ,0xffa9edb0) //101
NHSTUB(AllocateUncacheableMemory              ,0xff8389d8) //112
NHSTUB(Close                                  ,0xff835408) //101
NHSTUB(CreateTask                             ,0xff81e5b4) //101
NHSTUB(DebugAssert                            ,0xff81e88c) //111
NHSTUB(DeleteDirectory_Fut                    ,0xff834e78) //116
NHSTUB(DeleteFile_Fut                         ,0xff834d94) //112
NHSTUB(DoAFLock                               ,0xff8368f0) //102
NHSTUB(EnterToCompensationEVF                 ,0xff836ae0) //104
NHSTUB(ExecuteEventProcedure                  ,0xff884de0) //104
NHSTUB(ExitFromCompensationEVF                ,0xff836b24) //104
NHSTUB(ExitTask                               ,0xff81e844) //101
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff844254) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff84432c) //104
NHSTUB(Fclose_Fut                             ,0xff834f10) //101
NHSTUB(Feof_Fut                               ,0xff8350fc) //  1
NHSTUB(Fflush_Fut                             ,0xff835138) //  1
NHSTUB(Fgets_Fut                              ,0xff835064) //  1
NHSTUB(Fopen_Fut                              ,0xff834ed0) //101
NHSTUB(Fread_Fut                              ,0xff834fbc) //101
//NHSTUB(FreeMemory                           ,0xffa9eda8) //101
NHSTUB(FreeUncacheableMemory                  ,0xff838a18) //112
NHSTUB(Fseek_Fut                              ,0xff8350b0) //101
NHSTUB(Fwrite_Fut                             ,0xff835010) //101
NHSTUB(GetBatteryTemperature                  ,0xff85e2ac) //102
NHSTUB(GetCCDTemperature                      ,0xff85e238) //102
NHSTUB(GetCurrentAvValue                      ,0xff9446cc) //102
NHSTUB(GetDrive_ClusterSize                   ,0xff86bb04) //  3
NHSTUB(GetDrive_FreeClusters                  ,0xff86bb64) //  3
NHSTUB(GetDrive_TotalClusters                 ,0xff86bb38) //  3
NHSTUB(GetFocusLensSubjectDistance            ,0xff942ca0) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff9430e8) //  3
NHSTUB(GetImageFolder                         ,0xff923de8) //106
NHSTUB(GetKbdState                            ,0xff85ae80) //109
NHSTUB(GetMemInfo                             ,0xff81a070) //115
NHSTUB(GetOpticalTemperature                  ,0xff85e320) //102
NHSTUB(GetParameterData                       ,0xff979b1c) //101
NHSTUB(GetPropertyCase                        ,0xff888b48) //102
NHSTUB(GetSystemTime                          ,0xffa9ee08) //101
NHSTUB(GetVRAMHPixelsSize                     ,0xff8e1e14) //102
NHSTUB(GetVRAMVPixelsSize                     ,0xff8e1e20) //102
NHSTUB(GetZoomLensCurrentPoint                ,0xff947174) //102
NHSTUB(GetZoomLensCurrentPosition             ,0xffa904f8) //102
NHSTUB(GiveSemaphore                          ,0xff8383f4) //112
NHSTUB(IsStrobeChargeCompleted                ,0xff8c3a24) //102
NHSTUB(LEDDrive                               ,0xff85a31c) //103
NHSTUB(LocalTime                              ,0xff882754) //115
NHSTUB(LockMainPower                          ,0xff8909b0) //103
//NHSTUB(Lseek                                ,0xff835524) //101
NHSTUB(MakeDirectory_Fut                      ,0xff834e08) //116
NHSTUB(MoveFocusLensToDistance                ,0xffb08268) //102
NHSTUB(MoveIrisWithAv                         ,0xffa9c344) //102
NHSTUB(MoveZoomLensWithPoint                  ,0xffa9c990) //102
//NHSTUB(NewTaskShell                         ,0xff8885f4) //103
NHSTUB(Open                                   ,0xff8353b0) //101
NHSTUB(PB2Rec                                 ,0xff8939dc) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff8747cc) //102
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff8747a4) //102
NHSTUB(PT_PlaySound                           ,0xff87d8a8) //102
NHSTUB(PostLogicalEventForNotPowerType        ,0xff88e7b8) //103
NHSTUB(PostLogicalEventToUI                   ,0xff88e804) //103
NHSTUB(PutInNdFilter                          ,0xffb05ec8) //102
NHSTUB(PutOutNdFilter                         ,0xffb05f00) //102
NHSTUB(Read                                   ,0xff81ab78) //101
NHSTUB(ReadFastDir                            ,0xffa7e1f4) //  3
NHSTUB(Rec2PB                                 ,0xff893a1c) //104
NHSTUB(RefreshPhysicalScreen                  ,0xff9f8694) //104
//NHSTUB(Remove                               ,0xff83543c) //  4
NHSTUB(RenameFile_Fut                         ,0xff834d00) //116
NHSTUB(Restart                                ,0xff83a130) //106
NHSTUB(ScreenLock                             ,0xff9f98b4) //  3
NHSTUB(ScreenUnlock                           ,0xff9f98dc) //  3
NHSTUB(SetAE_ShutterSpeed                     ,0xffb0a9f8) //102
NHSTUB(SetAutoShutdownTime                    ,0xff890a24) //103
NHSTUB(SetCurrentCaptureModeType              ,0xff897d04) //101
NHSTUB(SetFileAttributes                      ,0xff8356d8) //  3
NHSTUB(SetFileTimeStamp                       ,0xff835694) //  3
NHSTUB(SetLogicalEventActive                  ,0xff8906fc) //101
NHSTUB(SetParameterData                       ,0xff979a8c) //101
NHSTUB(SetPropertyCase                        ,0xff888a44) //102
NHSTUB(SetScriptMode                          ,0xff89074c) //101
NHSTUB(SleepTask                              ,0xff83865c) //101
NHSTUB(TakeSemaphore                          ,0xff838324) //101
NHSTUB(TurnOffBackLight                       ,0xff89e2b8) //104
NHSTUB(TurnOnBackLight                        ,0xff89e2a0) //104
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff9642c8) //105
NHSTUB(UnlockAF                               ,0xff836928) //102
NHSTUB(UnlockMainPower                        ,0xff890904) //103
NHSTUB(UnsetZoomForMovie                      ,0xff97fdd8) //104
NHSTUB(UpdateMBROnFlash                       ,0xff86b984) //105
NHSTUB(VbattGet                               ,0xff831e04) //103
NHSTUB(Write                                  ,0xff835498) //101
NHSTUB(WriteSDCard                            ,0xff933968) //108
NHSTUB(_log                                   ,0xffb3bc6c) //111
NHSTUB(_log10                                 ,0xffb3a8f8) //112
NHSTUB(_pow                                   ,0xffb3aa68) //114
NHSTUB(_sqrt                                  ,0xffb3d8f0) //  1
NHSTUB(add_ptp_handler                        ,0xffa3f98c) //  3
NHSTUB(apex2us                                ,0xff9fd42c) //  4
NHSTUB(close                                  ,0xff81a990) //  1
NHSTUB(closedir                               ,0xffa7e07c) //  3
NHSTUB(err_init_task                          ,0xff815f28) //111
NHSTUB(exmem_alloc                            ,0xff883614) //103
NHSTUB(exmem_free                             ,0xff88368c) //103
NHSTUB(free                                   ,0xff814138) //112
NHSTUB(kbd_p1_f                               ,0xff833624) //109
NHSTUB(kbd_p1_f_cont                          ,0xff833630) //109
NHSTUB(kbd_p2_f                               ,0xff832ecc) //109
NHSTUB(kbd_read_keys                          ,0xff8335a8) //109
NHSTUB(kbd_read_keys_r2                       ,0xff85a83c) //109
NHSTUB(lseek                                  ,0xff835524) //101
NHSTUB(malloc                                 ,0xff8140dc) //112
NHSTUB(memcmp                                 ,0xff8203e8) //101
NHSTUB(memcpy                                 ,0xff83df94) //101
NHSTUB(memset                                 ,0xff9fbfa0) //101
NHSTUB(mkdir                                  ,0xff83587c) //109
NHSTUB(mktime_ext                             ,0xff8a5d68) //  1
NHSTUB(open                                   ,0xff81a8e0) //  1
NHSTUB(OpenFastDir                            ,0xffa7e0c0) //  3
NHSTUB(qsort                                  ,0xff9fc560) //  1
NHSTUB(rand                                   ,0xff8204f0) //  1
//NHSTUB(read                                 ,0xff81ab78) //101
NHSTUB(realloc                                ,0xff9fc01c) //115
NHSTUB(reboot_fw_update                       ,0xffa83704) //106
NHSTUB(set_control_event                      ,0xff89032c) //111
NHSTUB(srand                                  ,0xff8204e4) //  1
NHSTUB(stat                                   ,0xff835560) //109
NHSTUB(strcat                                 ,0xff8a5524) //  1
NHSTUB(strchr                                 ,0xff813fc0) //  1
NHSTUB(strcmp                                 ,0xff8203a4) //101
NHSTUB(strcpy                                 ,0xff82038c) //101
NHSTUB(strftime                               ,0xff8a5770) //  1
NHSTUB(strlen                                 ,0xff81400c) //101
NHSTUB(strncmp                                ,0xff813f74) //  1
NHSTUB(strncpy                                ,0xff813f38) //  1
NHSTUB(strrchr                                ,0xff813fe4) //  1
NHSTUB(strtol                                 ,0xff83e274) //101
NHSTUB(strtolx                                ,0xff83e078) //109
   DEF(task_CaptSeq                           ,0xff876e70) //107
   DEF(task_ExpDrv                            ,0xff8ba2d4) //110
   DEF(task_FileWrite                         ,0xffa79a50) //107
   DEF(task_InitFileModules                   ,0xff894500) //107
   DEF(task_MovieRecord                       ,0xff94af08) //107
   DEF(task_PhySw                             ,0xff8331fc) //107
   DEF(task_RotaryEncoder                     ,0xff85afb0) //107
   DEF(task_TouchPanel                        ,0xff85e89c) //107
NHSTUB(time                                   ,0xff882ccc) //109
NHSTUB(vsprintf                               ,0xff820350) //115
//NHSTUB(write                                ,0xff835498) //101
//NHSTUB(EngDrvIn                             ,0xff834464) //102
//NHSTUB(EngDrvOut                            ,0xff83444c) //102
//NHSTUB(EngDrvRead                           ,0xff83446c) //102
//NHSTUB(EngDrvBits                           ,0xff834480) //102
//NHSTUB(GetSDProtect                         ,0xff833580) //103
//NHSTUB(StartRecModeMenu                     ,0xff889700) //102
//NHSTUB(DispCon_ShowBitmapColorBar           ,0xff853540) //102
//NHSTUB(ResetZoomLens                        ,0xffa9c8e4) //102
//NHSTUB(ResetFocusLens                       ,0xffa9b5ec) //102
//NHSTUB(NR_GetDarkSubType                    ,0xff9525c8) //102
//NHSTUB(NR_SetDarkSubType                    ,0xff952520) //102
//NHSTUB(SavePaletteData                      ,0xffb0cd78) //102
//NHSTUB(GUISrv_StartGUISystem                ,0xff8a52a4) //101
