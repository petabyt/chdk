// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R39 (DRYOS version 2.3, release #0039)
//   Firmware Ver GM1.00C
//   Canon DIGITAL IXUS 200 IS

// Values for makefile.inc
//   PLATFORMOSVER = 39
//   PLATFORMID = 12773 (0x31e5) // Found @ 0xfffe0130
//   MAXRAMADDR = 0x03ffffff
//   KEYSYS = d4                 // Found @ 0xffff3564
//   NEED_ENCODED_DISKBOOT = 3   // Found @ 0xffff3574

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
NSTUB(kbd_pwr_off                             ,0xff85ae98) //  2 64%
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff894674 -> ff890d94 -> ff978aa0 -> ffaab240 -> ffbda99c
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
DEF(levent_table                            ,0xffb7a290) // Found @0xffb7a290
DEF(FlashParamsTable                        ,0xffbdab84) // Found @0xffbdab84
//DEF(movie_status                            ,0x000067e0) // Found @0xff94ac20,          stubs_min = 0x000067e0 (0x000067e0)
DEF(full_screen_refresh                     ,0x0001b2dc) // Found @0xff9f751c
DEF(canon_menu_active                       ,0x00002ec8) // Found @0xff889704
DEF(canon_shoot_menu_active                 ,0x00007b09) // Found @0xff98d9ac
DEF(playrec_mode                            ,0x00002bfc) // Found @0xff87bbdc
DEF(zoom_status                             ,0x0001e3d4) // Found @0xffaadccc
DEF(some_flag_for_af_scan                   ,0x00006cd4) // Found @0xff94dc3c
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 3 int value(s), the first is the zoom focus length.
// there are 12 entries in the table - set NUM_FL to 12
DEF(focus_len_table                         ,0xfffe2ac8) // Found @0xfffe2ac8
DEF(zoom_busy                               ,0x0000670c) // Found @0xff946e00
DEF(focus_busy                              ,0x00006608) // Found @0xff941f28
//DEF(recreview_hold                          ,0x00003818) // Found @0xff89a778,          stubs_min = 0x00003818 (0x00003818)

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x40431000; }             // Found @0xff853588
//void *vid_get_viewport_fb()      { return (void*)0x408cb700; }             // Found @0xffb0b870
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x28f0+0x58)); } // Found @0xff86d354 & 0xff86d38c
//char *camera_jpeg_count_str()    { return (char*)0x00084ca4; }             // Found @0xff9e8aa8
//long hook_raw_size()             { return 0x011ca240; }                    // Found @0xffb0e700
//int get_flash_params_count(void) { return 0x84; }                          // Found @0xff979b5c

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffb404d8, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x00100000 // Found @0xffb404f0, levent 0x902
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 2, KEY_MENU            ,0x00000001 }, // Found @0xffb40430, levent 0x09
//    { 2, KEY_SET             ,0x00000002 }, // Found @0xffb4043c, levent 0x08
//    { 2, KEY_ZOOM_IN         ,0x00000004 }, // Found @0xffb40448, levent 0x02
//    { 2, KEY_ZOOM_OUT        ,0x00000008 }, // Found @0xffb40454, levent 0x03
//    { 2, KEY_LEFT            ,0x00000010 }, // Found @0xffb40460, levent 0x06
//    { 2, KEY_RIGHT           ,0x00000020 }, // Found @0xffb4046c, levent 0x07
//    { 2, KEY_DOWN            ,0x00000040 }, // Found @0xffb40478, levent 0x05
//    { 2, KEY_UP              ,0x00000080 }, // Found @0xffb40484, levent 0x04
//    { 2, KEY_SHOOT_FULL      ,0x00000300 }, // Found @0xffb4049c, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000200 }, // Found @0xffb4049c, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00000100 }, // Found @0xffb40490, levent 0x00
//    { 2, KEY_POWER           ,0x00000400 }, // Found @0xffb404a8, levent 0x600
//    { 2, KEY_PLAYBACK        ,0x00000800 }, // Found @0xffb404b4, levent 0x601
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
DEF(ctypes, 0xffb3eb2e)

// For capt_seq.c
//static long *nrflag = (long*)(0x6cb8-0x08);  // Found @ ff94ff04 & ff94ff20

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NSTUB(AllocateMemory                          ,0xffa9eda0) //101
NSTUB(AllocateUncacheableMemory               ,0xff8389d8) //112
NSTUB(Close                                   ,0xff835408) //101
NSTUB(CreateTask                              ,0xff81e5b4) //101
NSTUB(DebugAssert                             ,0xff81e88c) //111
NSTUB(DeleteDirectory_Fut                     ,0xff834e78) //  1
NSTUB(DeleteFile_Fut                          ,0xff834d94) //112
NSTUB(DoAFLock                                ,0xff8368f0) //102
NSTUB(EnterToCompensationEVF                  ,0xff836ae0) //104
NSTUB(ExecuteEventProcedure                   ,0xff884de0) //  1
NSTUB(ExitFromCompensationEVF                 ,0xff836b24) //104
NSTUB(ExitTask                                ,0xff81e844) //101
NSTUB(ExpCtrlTool_StartContiAE                ,0xff844254) //104
NSTUB(ExpCtrlTool_StopContiAE                 ,0xff84432c) //104
NSTUB(Fclose_Fut                              ,0xff834f10) //101
NSTUB(Feof_Fut                                ,0xff8350fc) //  1
NSTUB(Fflush_Fut                              ,0xff835138) //  1
NSTUB(Fgets_Fut                               ,0xff835064) //  1
NSTUB(Fopen_Fut                               ,0xff834ed0) //101
NSTUB(Fread_Fut                               ,0xff834fbc) //101
NSTUB(FreeMemory                              ,0xffa9ed98) //101
NSTUB(FreeUncacheableMemory                   ,0xff838a18) //112
NSTUB(Fseek_Fut                               ,0xff8350b0) //101
NSTUB(Fwrite_Fut                              ,0xff835010) //101
NSTUB(GetBatteryTemperature                   ,0xff85e2ac) //102
NSTUB(GetCCDTemperature                       ,0xff85e238) //102
NSTUB(GetCurrentAvValue                       ,0xff9446cc) //102
NSTUB(GetDrive_ClusterSize                    ,0xff86bb04) //  3
NSTUB(GetDrive_FreeClusters                   ,0xff86bb64) //  3
NSTUB(GetDrive_TotalClusters                  ,0xff86bb38) //  3
NSTUB(GetFocusLensSubjectDistance             ,0xff942ca0) //102
NSTUB(GetFocusLensSubjectDistanceFromLens     ,0xff9430e8) //  3
NSTUB(GetImageFolder                          ,0xff923de8) //106
NSTUB(GetKbdState                             ,0xff85ae80) //109
NSTUB(GetMemInfo                              ,0xff81a070) //  3
NSTUB(GetOpticalTemperature                   ,0xff85e320) //102
NSTUB(GetParameterData                        ,0xff979b1c) //101
NSTUB(GetPropertyCase                         ,0xff888b48) //102
NSTUB(GetSystemTime                           ,0xffa9edf8) //101
NSTUB(GetVRAMHPixelsSize                      ,0xff8e1e14) //102
NSTUB(GetVRAMVPixelsSize                      ,0xff8e1e20) //102
NSTUB(GetZoomLensCurrentPoint                 ,0xff947174) //102
NSTUB(GetZoomLensCurrentPosition              ,0xffa904e8) //102
NSTUB(GiveSemaphore                           ,0xff8383f4) //112
NSTUB(IsStrobeChargeCompleted                 ,0xff8c3a24) //102
NSTUB(LEDDrive                                ,0xff85a31c) //103
NSTUB(LocalTime                               ,0xff882754) //  1
NSTUB(LockMainPower                           ,0xff8909b0) //103
NSTUB(Lseek                                   ,0xff835524) //101
NSTUB(MakeDirectory_Fut                       ,0xff834e08) //  1
NSTUB(MoveFocusLensToDistance                 ,0xffb08258) //102
NSTUB(MoveIrisWithAv                          ,0xffa9c334) //102
NSTUB(MoveZoomLensWithPoint                   ,0xffa9c980) //102
NSTUB(NewTaskShell                            ,0xff8885f4) //103
NSTUB(Open                                    ,0xff8353b0) //101
NSTUB(PB2Rec                                  ,0xff8939dc) //104
NSTUB(PT_MoveDigitalZoomToWide                ,0xff8747cc) //102
NSTUB(PT_MoveOpticalZoomAt                    ,0xff8747a4) //102
NSTUB(PT_PlaySound                            ,0xff87d8a8) //102
NSTUB(PostLogicalEventForNotPowerType         ,0xff88e7b8) //103
NSTUB(PostLogicalEventToUI                    ,0xff88e804) //103
NSTUB(PutInNdFilter                           ,0xffb05eb8) //102
NSTUB(PutOutNdFilter                          ,0xffb05ef0) //102
NSTUB(Read                                    ,0xff81ab78) //101
NSTUB(ReadFastDir                             ,0xffa7e1e4) //  3
NSTUB(Rec2PB                                  ,0xff893a1c) //104
NSTUB(RefreshPhysicalScreen                   ,0xff9f8694) //104
NSTUB(Remove                                  ,0xff83543c) //  4
NSTUB(RenameFile_Fut                          ,0xff834d00) //  4
NSTUB(Restart                                 ,0xff83a130) //106
NSTUB(ScreenLock                              ,0xff9f98b4) //  3
NSTUB(ScreenUnlock                            ,0xff9f98dc) //  3
NSTUB(SetAE_ShutterSpeed                      ,0xffb0a9e8) //102
NSTUB(SetAutoShutdownTime                     ,0xff890a24) //103
NSTUB(SetCurrentCaptureModeType               ,0xff897d04) //101
NSTUB(SetFileAttributes                       ,0xff8356d8) //  3
NSTUB(SetFileTimeStamp                        ,0xff835694) //  3
NSTUB(SetLogicalEventActive                   ,0xff8906fc) //101
NSTUB(SetParameterData                        ,0xff979a8c) //101
NSTUB(SetPropertyCase                         ,0xff888a44) //102
//NSTUB(SetScriptMode                         ,0xff89074c) //101            == 0xff89074c
NSTUB(SleepTask                               ,0xff83865c) //101
NSTUB(TakeSemaphore                           ,0xff838324) //101
NSTUB(TurnOffBackLight                        ,0xff89e2b8) //104
NSTUB(TurnOnBackLight                         ,0xff89e2a0) //104
NSTUB(UIFS_WriteFirmInfoToFile                ,0xff9642c8) //105
NSTUB(UnlockAF                                ,0xff836928) //102
NSTUB(UnlockMainPower                         ,0xff890904) //103
NSTUB(UnsetZoomForMovie                       ,0xff97fdd8) //104
NSTUB(UpdateMBROnFlash                        ,0xff86b984) //105
NSTUB(VbattGet                                ,0xff831e04) //103
NSTUB(Write                                   ,0xff835498) //101
NSTUB(WriteSDCard                             ,0xff933968) //108
NSTUB(_log                                    ,0xffb3bc5c) //111
NSTUB(_log10                                  ,0xffb3a8e8) //112
NSTUB(_pow                                    ,0xffb3aa58) //114
NSTUB(_sqrt                                   ,0xffb3d8e0) //  1
NSTUB(add_ptp_handler                         ,0xffa3f97c) //  3
NSTUB(apex2us                                 ,0xff9fd42c) //  4
NSTUB(close                                   ,0xff81a990) //  1
NSTUB(closedir                                ,0xffa7e06c) //  3
NSTUB(err_init_task                           ,0xff815f28) //  4
NSTUB(exmem_alloc                             ,0xff883614) //103
NSTUB(free                                    ,0xff814138) //112
NSTUB(kbd_p1_f                                ,0xff833624) //109
NSTUB(kbd_p1_f_cont                           ,0xff833630) //109
NSTUB(kbd_p2_f                                ,0xff832ecc) //109
NSTUB(kbd_read_keys                           ,0xff8335a8) //109
NSTUB(kbd_read_keys_r2                        ,0xff85a83c) //109
NSTUB(lseek                                   ,0xff835524) //101
NSTUB(malloc                                  ,0xff8140dc) //112
NSTUB(memcmp                                  ,0xff8203e8) //101
NSTUB(memcpy                                  ,0xff83df94) //101
NSTUB(memset                                  ,0xff9fbfa0) //101
NSTUB(mkdir                                   ,0xff83587c) //  3
NSTUB(mktime_ext                              ,0xff8a5d68) //  1
NSTUB(open                                    ,0xff81a8e0) //  1
NSTUB(opendir                                 ,0xffa7e0b0) //  3
NSTUB(openfastdir                             ,0xffa7e0b0) //  3
NSTUB(qsort                                   ,0xff9fc560) //  1
NSTUB(rand                                    ,0xff8204f0) //  1
NSTUB(read                                    ,0xff81ab78) //101
NSTUB(reboot_fw_update                        ,0xffa836f4) //  1
NSTUB(rename                                  ,0xff834d00) //  4
NSTUB(set_control_event                       ,0xff89032c) //111
NSTUB(srand                                   ,0xff8204e4) //  1
NSTUB(stat                                    ,0xff835560) //  3
// ALT: NSTUB(stat, 0xff868f48) // 3 31/0
NSTUB(strcat                                  ,0xff8a5524) //  1
NSTUB(strchr                                  ,0xff813fc0) //  1
NSTUB(strcmp                                  ,0xff8203a4) //101
NSTUB(strcpy                                  ,0xff82038c) //101
NSTUB(strftime                                ,0xff8a5770) //  1
NSTUB(strlen                                  ,0xff81400c) //101
NSTUB(strncmp                                 ,0xff813f74) //  1
NSTUB(strncpy                                 ,0xff813f38) //  1
NSTUB(strrchr                                 ,0xff813fe4) //  1
NSTUB(strtol                                  ,0xff83e274) //101
NSTUB(strtolx                                 ,0xff83e078) //109
  DEF(task_CaptSeq                            ,0xff876e70) //107
  DEF(task_ExpDrv                             ,0xff8ba2d4) //110
  DEF(task_InitFileModules                    ,0xff894500) //107
  DEF(task_MovieRecord                        ,0xff94af08) //107
  DEF(task_PhySw                              ,0xff8331fc) //107
  DEF(task_RotaryEncoder                      ,0xff85afb0) //107
NSTUB(time                                    ,0xff882ccc) //  2
NSTUB(vsprintf                                ,0xff820350) //  1
NSTUB(write                                   ,0xff835498) //101
