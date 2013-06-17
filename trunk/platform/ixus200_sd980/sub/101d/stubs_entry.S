// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R39 (DRYOS version 2.3, release #0039)
//   Firmware Ver GM1.01D
//   Canon PowerShot SD980 IS

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
// Firmware modemap table found @ff8946c4 -> ff890de4 -> ff978c5c -> ffaab40c -> ffbdab64
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
DEF(file_system_started                     ,0x000028a8) // Found @0xff86a070
DEF(physw_status                            ,0x00044558) // Found @0xff8335a8
DEF(physw_run                               ,0x00001c44) // Found @0xff833200
DEF(physw_sleep_delay                       ,0x00001c42) // Found @0xff833200
DEF(levent_table                            ,0xffb7a458) // Found @0xffb7a458
DEF(FlashParamsTable                        ,0xffbdad4c) // Found @0xffbdad4c
DEF(movie_status                            ,0x000067e0) // Found @0xff94addc
DEF(video_compression_rate                  ,0x0000680c) // Found @0xff94b048
DEF(full_screen_refresh                     ,0x0001b2dc) // Found @0xff9f76d8
DEF(canon_menu_active                       ,0x00002ec8) // Found @0xff889754
DEF(canon_shoot_menu_active                 ,0x00007b09) // Found @0xff98db68
DEF(playrec_mode                            ,0x00002bfc) // Found @0xff87bc2c
DEF(zoom_status                             ,0x0001e3d4) // Found @0xffaade98
DEF(some_flag_for_af_scan                   ,0x00006cd4) // Found @0xff94ddf8
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 3 int value(s), the first is the zoom focus length.
// there are 12 entries in the table - set NUM_FL to 12
DEF(focus_len_table                         ,0xfffe2ac8) // Found @0xfffe2ac8
DEF(zoom_busy                               ,0x0000670c) // Found @0xff946fbc
DEF(focus_busy                              ,0x00006608) // Found @0xff9420e4
DEF(recreview_hold                          ,0x00003818) // Found @0xff89a7c8
// Palette colour tables  found @ 0xffb9403c
DEF(active_palette_buffer                   ,0x0001b2e4) // Found @0xff9f7614
DEF(palette_buffer_ptr                      ,0x0001b2f0) // Found @0xff9f72e8
// Offset from start of palette_buffer to color data = 8 (Found @0xffae54e8)

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x40431000; }             // Found @0xff853588
//void *vid_get_viewport_fb()      { return (void*)0x408cb700; }             // Found @0xffb0ba3c
DEF(viewport_fb_d                           ,0x00002948) // Found 0x28f0 (@0xff86d3a4) + 0x58 (@0xff86d3dc)
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x28f0+0x58)); } // Found @0xff86d3a4 & 0xff86d3dc
DEF(jpeg_count_str                          ,0x00084ca4) // Found @0xff9e8c64
//char *camera_jpeg_count_str()    { return (char*)0x00084ca4; }             // Found @0xff9e8c64
//long hook_raw_size()             { return 0x011ca240; }                    // Found @0xffb0e8cc
//int get_flash_params_count(void) { return 0x84; }                          // Found @0xff979d18

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffb406a4, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x00100000 // Found @0xffb406bc, levent 0x902
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 2, KEY_MENU            ,0x00000001 }, // Found @0xffb405fc, levent 0x09
//    { 2, KEY_SET             ,0x00000002 }, // Found @0xffb40608, levent 0x08
//    { 2, KEY_ZOOM_IN         ,0x00000004 }, // Found @0xffb40614, levent 0x02
//    { 2, KEY_ZOOM_OUT        ,0x00000008 }, // Found @0xffb40620, levent 0x03
//    { 2, KEY_LEFT            ,0x00000010 }, // Found @0xffb4062c, levent 0x06
//    { 2, KEY_RIGHT           ,0x00000020 }, // Found @0xffb40638, levent 0x07
//    { 2, KEY_DOWN            ,0x00000040 }, // Found @0xffb40644, levent 0x05
//    { 2, KEY_UP              ,0x00000080 }, // Found @0xffb40650, levent 0x04
//    { 2, KEY_SHOOT_FULL      ,0x00000300 }, // Found @0xffb40668, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000200 }, // Found @0xffb40668, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00000100 }, // Found @0xffb4065c, levent 0x00
//    { 2, KEY_POWER           ,0x00000400 }, // Found @0xffb40674, levent 0x600
//    { 2, KEY_PLAYBACK        ,0x00000800 }, // Found @0xffb40680, levent 0x601
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_RAW_ROWPIX    4080 // Found @0xff91c00c
//#define CAM_RAW_ROWS      3048 // Found @0xff91c014
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff838a1c

// Misc stuff
DEF(ctypes, 0xffb3ecfa)

// For capt_seq.c
DEF(_nrflag,0x6cb0) // Found @ ff9500c0 (0x6cb8) & ff9500e0 (-0x08)
//static long *nrflag = (long*)(0x6cb8-0x08);  // Found @ ff9500c0 & ff9500dc

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
//NHSTUB(CreateJumptable                      ,0xffb0f374) //  1
//NHSTUB(_uartr_req                           ,0xff81f964) //111
//NHSTUB(StartRecModeMenu                     ,0xff889750) //102
//NHSTUB(AllocateMemory                       ,0xffa9ef6c) //101
NHSTUB(AllocateUncacheableMemory              ,0xff8389d8) //112
NHSTUB(Close                                  ,0xff835408) //101
NHSTUB(CreateTask                             ,0xff81e5b4) //101
NHSTUB(DebugAssert                            ,0xff81e88c) //111
NHSTUB(DeleteDirectory_Fut                    ,0xff834e78) //116
NHSTUB(DeleteFile_Fut                         ,0xff834d94) //112
NHSTUB(DoAFLock                               ,0xff8368f0) //102
NHSTUB(EnterToCompensationEVF                 ,0xff836ae0) //104
NHSTUB(ExecuteEventProcedure                  ,0xff884e30) //104
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
//NHSTUB(FreeMemory                           ,0xffa9ef64) //101
NHSTUB(FreeUncacheableMemory                  ,0xff838a18) //112
NHSTUB(Fseek_Fut                              ,0xff8350b0) //101
NHSTUB(Fwrite_Fut                             ,0xff835010) //101
NHSTUB(GetBatteryTemperature                  ,0xff85e2ac) //102
NHSTUB(GetCCDTemperature                      ,0xff85e238) //102
NHSTUB(GetCurrentAvValue                      ,0xff944888) //102
NHSTUB(GetDrive_ClusterSize                   ,0xff86bb04) //  3
NHSTUB(GetDrive_FreeClusters                  ,0xff86bb64) //  3
NHSTUB(GetDrive_TotalClusters                 ,0xff86bb38) //  3
NHSTUB(GetFocusLensSubjectDistance            ,0xff942e5c) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff9432a4) //  3
NHSTUB(GetImageFolder                         ,0xff923e38) //106
NHSTUB(GetKbdState                            ,0xff85ae80) //109
NHSTUB(GetMemInfo                             ,0xff81a070) //115
NHSTUB(GetOpticalTemperature                  ,0xff85e320) //102
NHSTUB(GetParameterData                       ,0xff979cd8) //101
NHSTUB(GetPropertyCase                        ,0xff888b98) //102
NHSTUB(GetSystemTime                          ,0xffa9efc4) //101
NHSTUB(GetVRAMHPixelsSize                     ,0xff8e1e64) //102
NHSTUB(GetVRAMVPixelsSize                     ,0xff8e1e70) //102
NHSTUB(GetZoomLensCurrentPoint                ,0xff947330) //102
NHSTUB(GetZoomLensCurrentPosition             ,0xffa906b4) //102
NHSTUB(GiveSemaphore                          ,0xff8383f4) //112
NHSTUB(IsStrobeChargeCompleted                ,0xff8c3a74) //102
NHSTUB(LEDDrive                               ,0xff85a31c) //103
NHSTUB(LocalTime                              ,0xff8827a4) //115
NHSTUB(LockMainPower                          ,0xff890a00) //103
//NHSTUB(Lseek                                ,0xff835524) //101
NHSTUB(MakeDirectory_Fut                      ,0xff834e08) //116
NHSTUB(MoveFocusLensToDistance                ,0xffb08424) //102
NHSTUB(MoveIrisWithAv                         ,0xffa9c500) //102
NHSTUB(MoveZoomLensWithPoint                  ,0xffa9cb4c) //102
//NHSTUB(NewTaskShell                         ,0xff888644) //103
NHSTUB(Open                                   ,0xff8353b0) //101
NHSTUB(PB2Rec                                 ,0xff893a2c) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff87481c) //102
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff8747f4) //102
NHSTUB(PT_PlaySound                           ,0xff87d8f8) //102
NHSTUB(PostLogicalEventForNotPowerType        ,0xff88e808) //103
NHSTUB(PostLogicalEventToUI                   ,0xff88e854) //103
NHSTUB(PutInNdFilter                          ,0xffb06084) //102
NHSTUB(PutOutNdFilter                         ,0xffb060bc) //102
NHSTUB(Read                                   ,0xff81ab78) //101
NHSTUB(ReadFastDir                            ,0xffa7e3b0) //  3
NHSTUB(Rec2PB                                 ,0xff893a6c) //104
NHSTUB(RefreshPhysicalScreen                  ,0xff9f8850) //104
//NHSTUB(Remove                               ,0xff83543c) //  4
NHSTUB(RenameFile_Fut                         ,0xff834d00) //116
NHSTUB(Restart                                ,0xff83a130) //106
NHSTUB(ScreenLock                             ,0xff9f9a70) //117
NHSTUB(ScreenUnlock                           ,0xff9f9a98) //117
NHSTUB(SetAE_ShutterSpeed                     ,0xffb0abb4) //102
NHSTUB(SetAutoShutdownTime                    ,0xff890a74) //103
NHSTUB(SetCurrentCaptureModeType              ,0xff897d54) //101
NHSTUB(SetFileAttributes                      ,0xff8356d8) //  3
NHSTUB(SetFileTimeStamp                       ,0xff835694) //  3
NHSTUB(SetLogicalEventActive                  ,0xff89074c) //101
NHSTUB(SetParameterData                       ,0xff979c48) //101
NHSTUB(SetPropertyCase                        ,0xff888a94) //102
NHSTUB(SetScriptMode                          ,0xff89079c) //101
NHSTUB(SleepTask                              ,0xff83865c) //101
NHSTUB(TakeSemaphore                          ,0xff838324) //101
NHSTUB(TurnOffBackLight                       ,0xff89e308) //104
NHSTUB(TurnOnBackLight                        ,0xff89e2f0) //104
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff964484) //105
NHSTUB(UnlockAF                               ,0xff836928) //102
NHSTUB(UnlockMainPower                        ,0xff890954) //103
NHSTUB(UnsetZoomForMovie                      ,0xff97ff94) //104
NHSTUB(UpdateMBROnFlash                       ,0xff86b984) //105
NHSTUB(VbattGet                               ,0xff831e04) //103
NHSTUB(Write                                  ,0xff835498) //101
NHSTUB(WriteSDCard                            ,0xff933a1c) //108
NHSTUB(_log                                   ,0xffb3be28) //111
NHSTUB(_log10                                 ,0xffb3aab4) //112
NHSTUB(_pow                                   ,0xffb3ac24) //114
NHSTUB(_sqrt                                  ,0xffb3daac) //  1
NHSTUB(add_ptp_handler                        ,0xffa3fb48) //  3
NHSTUB(apex2us                                ,0xff9fd5e8) //  4
NHSTUB(close                                  ,0xff81a990) //  1
NHSTUB(closedir                               ,0xffa7e238) //  3
NHSTUB(err_init_task                          ,0xff815f28) //111
NHSTUB(exmem_alloc                            ,0xff883664) //103
NHSTUB(exmem_free                             ,0xff8836dc) //103
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
NHSTUB(memset                                 ,0xff9fc15c) //101
NHSTUB(mkdir                                  ,0xff83587c) //109
NHSTUB(mktime_ext                             ,0xff8a5db8) //  1
NHSTUB(open                                   ,0xff81a8e0) //  1
NHSTUB(OpenFastDir                            ,0xffa7e27c) //  3
NHSTUB(qsort                                  ,0xff9fc71c) //  1
NHSTUB(rand                                   ,0xff8204f0) //  1
//NHSTUB(read                                 ,0xff81ab78) //101
NHSTUB(realloc                                ,0xff9fc1d8) //115
NHSTUB(reboot_fw_update                       ,0xffa838c0) //106
NHSTUB(set_control_event                      ,0xff89037c) //111
NHSTUB(srand                                  ,0xff8204e4) //  1
NHSTUB(stat                                   ,0xff835560) //109
NHSTUB(strcat                                 ,0xff8a5574) //  1
NHSTUB(strchr                                 ,0xff813fc0) //  1
NHSTUB(strcmp                                 ,0xff8203a4) //101
NHSTUB(strcpy                                 ,0xff82038c) //101
NHSTUB(strftime                               ,0xff8a57c0) //  1
NHSTUB(strlen                                 ,0xff81400c) //101
NHSTUB(strncmp                                ,0xff813f74) //  1
NHSTUB(strncpy                                ,0xff813f38) //  1
NHSTUB(strrchr                                ,0xff813fe4) //  1
NHSTUB(strtol                                 ,0xff83e274) //101
NHSTUB(strtolx                                ,0xff83e078) //109
   DEF(task_CaptSeq                           ,0xff876ec0) //110
   DEF(task_ExpDrv                            ,0xff8ba324) //110
   DEF(task_InitFileModules                   ,0xff894550) //110
   DEF(task_MovieRecord                       ,0xff94b0c4) //110
   DEF(task_PhySw                             ,0xff8331fc) //110
   DEF(task_RotaryEncoder                     ,0xff85afb0) //110
   DEF(task_TouchPanel                        ,0xff85e89c) //110
NHSTUB(time                                   ,0xff882d1c) //109
NHSTUB(vsprintf                               ,0xff820350) //115
//NHSTUB(write                                ,0xff835498) //101
//NHSTUB(EngDrvIn                             ,0xff834464) //102
//NHSTUB(EngDrvOut                            ,0xff83444c) //102
//NHSTUB(EngDrvRead                           ,0xff83446c) //102
//NHSTUB(EngDrvBits                           ,0xff834480) //102
//NHSTUB(GetSDProtect                         ,0xff833580) //103
//NHSTUB(DispCon_ShowBitmapColorBar           ,0xff853540) //102
//NHSTUB(ResetZoomLens                        ,0xffa9caa0) //102
//NHSTUB(ResetFocusLens                       ,0xffa9b7a8) //102
//NHSTUB(NR_GetDarkSubType                    ,0xff952784) //102
//NHSTUB(NR_SetDarkSubType                    ,0xff9526dc) //102
//NHSTUB(SavePaletteData                      ,0xffb0cf34) //102
//NHSTUB(GUISrv_StartGUISystem                ,0xff8a52f4) //101
