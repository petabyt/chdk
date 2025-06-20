// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R43 (DRYOS version 2.3, release #0043)
//   Firmware Ver GM1.00C
//   Canon PowerShot A3000 IS

// Values for makefile.inc
//   PLATFORMOSVER = 43
//   PLATFORMID = 12786 (0x31f2) // Found @ 0xfffe0130
//   MAXRAMADDR = 0x01ffffff
//   KEYSYS = d4a                // Found @ 0xffff1aac
//   NEED_ENCODED_DISKBOOT = 4   // Found @ 0xffff1abc

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NSTUB(DoAFLock                              ,0xffc27744) //102        *** != 0xffc59f78
//NSTUB(GetDrive_FreeClusters                 ,0xffc239b8) //  3        *** != 0xffc524a0
// ALT: NSTUB(GetDrive_FreeClusters, 0xffc524a0) // 4 9/0
//NSTUB(LEDDrive                              ,0xffc43a04) //103        *** != 0xffc43acc
//NSTUB(ScreenLock                            ,0xffd86d9c) //  3        *** != 0xffd86fa4
//NSTUB(ScreenUnlock                          ,0xffd86de0) //  7        *** != 0xffd85c54
//NSTUB(SetScriptMode                         ,0xffc6fd38) //101        *** != 0xffc00f70
//NSTUB(UnlockAF                              ,0xffc2777c) //102        *** != 0xffc59f88
//NSTUB(kbd_pwr_off                           ,0xffc445a0) //  2 64%    *** != 0x00000000
NSTUB(kbd_pwr_on                              ,0xffc44560) //  2 82%
//NSTUB(rename                                ,0xffc25b9c) //  4        *** != 0xffc26394

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ffc73838 -> ffc70368 -> ffd35c94 -> ffe16228 -> ffeddb84
// Mode  2609 in firmware but not in current modemap

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x0002eed4) // Found @0xffc23cd4
DEF(physw_run                               ,0x00001bf0) // Found @0xffc23938
DEF(physw_sleep_delay                       ,0x00001bf8) // Found @0xffc23938
DEF(levent_table                            ,0xffeafe20) // Found @0xffeafe20
DEF(FlashParamsTable                        ,0xffeddd7c) // Found @0xffeddd7c
DEF(movie_status                            ,0x000056f8) // Found @0xffd13678
DEF(full_screen_refresh                     ,0x000076cc) // Found @0xffd8520c
DEF(canon_menu_active                       ,0x00002b7c) // Found @0xffc6d20c
DEF(canon_shoot_menu_active                 ,0x000068b1) // Found @0xffd4825c
DEF(playrec_mode                            ,0x000028d8) // Found @0xffc60944
DEF(zoom_status                             ,0x00009cd8) // Found @0xffe18568
DEF(some_flag_for_af_scan                   ,0x00005aa0) // Found @0xffd16004
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 3 int value(s), the first is the zoom focus length.
// there are 8 entries in the table - set NUM_FL to 8
DEF(focus_len_table                         ,0xfffe29b0) // Found @0xfffe29b0
DEF(zoom_busy                               ,0x00005648) // Found @0xffd0f784
DEF(focus_busy                              ,0x000054ec) // Found @0xffd0b1b0
//DEF(recreview_hold                          ,0x00003174) // Found @0xffc78d30, ** != ** stubs_min = 0x00006598 (0x64CC+0xCC)

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x10361000; }             // Found @0xffc3fc80
//void *vid_get_viewport_fb()      { return (void*)0x10650100; }             // Found @0xffe62758
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x2620+0x54)); } // Found @0xffc53a98 & 0xffc53ad0
//char *camera_jpeg_count_str()    { return (char*)0x00075120; }             // Found @0xffd7bd90
//long hook_raw_size()             { return 0x00ec04f0; }                    // Found @0xffe65ae8
//int get_flash_params_count(void) { return 0x94; }                          // Found @0xffd36d50

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffe9177c, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x00040000 // Found @0xffe91788, levent 0x902
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 1, KEY_POWER           ,0x00000400 }, // Found @0xffe91674, levent 0x600
//    { 1, KEY_PLAYBACK        ,0x20000000 }, // Found @0xffe9168c, levent 0x601
//    { 2, KEY_SHOOT_FULL      ,0x00000003 }, // Found @0xffe916bc, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000002 }, // Found @0xffe916bc, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00000001 }, // Found @0xffe916b0, levent 0x00
//    { 2, KEY_ZOOM_IN         ,0x00000004 }, // Found @0xffe916c8, levent 0x02
//    { 2, KEY_ZOOM_OUT        ,0x00000008 }, // Found @0xffe916d4, levent 0x03
//    { 2, KEY_UP              ,0x00000010 }, // Found @0xffe916e0, levent 0x04
//    { 2, KEY_DOWN            ,0x00000020 }, // Found @0xffe916ec, levent 0x05
//    { 2, KEY_RIGHT           ,0x00000040 }, // Found @0xffe916f8, levent 0x07
//    { 2, KEY_LEFT            ,0x00000080 }, // Found @0xffe91704, levent 0x06
//    { 2, KEY_SET             ,0x00000100 }, // Found @0xffe91710, levent 0x08
//    { 2, KEY_MENU            ,0x00000200 }, // Found @0xffe9171c, levent 0x09
//    { 2, KEY_DISPLAY         ,0x00000400 }, // Found @0xffe91728, levent 0x0a
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_RAW_ROWPIX    3720 // Found @0xffcee63c
//#define CAM_RAW_ROWS      2772 // Found @0xffcee648
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x10000000 // Found @0xffc296f0

// Misc stuff
DEF(ctypes, 0xffe90f92)

// For capt_seq.c
//static long *nrflag = (long*)(0x5a88-0x08);  // Found @ ffd17f90 & ffd17fac

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NSTUB(AllocateMemory                          ,0xffe08260) //101
NSTUB(AllocateUncacheableMemory               ,0xffc296ac) //112
NSTUB(Close                                   ,0xffc262b8) //101
NSTUB(CreateTask                              ,0xffc0f110) //101
NSTUB(DebugAssert                             ,0xffc0f5e8) //111
NSTUB(DeleteDirectory_Fut                     ,0xffc25d14) //  1
NSTUB(DeleteFile_Fut                          ,0xffc25c30) //112
NSTUB(EnterToCompensationEVF                  ,0xffc277f4) //104
NSTUB(ExecuteEventProcedure                   ,0xffc68958) //  1
NSTUB(ExitFromCompensationEVF                 ,0xffc27838) //104
NSTUB(ExitTask                                ,0xffc0f3a0) //101
NSTUB(ExpCtrlTool_StartContiAE                ,0xffc35110) //104
NSTUB(ExpCtrlTool_StopContiAE                 ,0xffc351e8) //104
NSTUB(Fclose_Fut                              ,0xffc25dac) //101
NSTUB(Feof_Fut                                ,0xffc25f98) //  1
NSTUB(Fflush_Fut                              ,0xffc25fd4) //  1
NSTUB(Fgets_Fut                               ,0xffc25f00) //  1
NSTUB(Fopen_Fut                               ,0xffc25d6c) //101
NSTUB(Fread_Fut                               ,0xffc25e58) //101
NSTUB(FreeMemory                              ,0xffe08258) //101
NSTUB(FreeUncacheableMemory                   ,0xffc296ec) //112
NSTUB(Fseek_Fut                               ,0xffc25f4c) //101
NSTUB(Fwrite_Fut                              ,0xffc25eac) //101
NSTUB(GetBatteryTemperature                   ,0xffc46680) //102
NSTUB(GetCCDTemperature                       ,0xffc4660c) //102
NSTUB(GetCurrentAvValue                       ,0xffd0ca30) //102
NSTUB(GetDrive_ClusterSize                    ,0xffc52440) //  4
NSTUB(GetDrive_TotalClusters                  ,0xffc52474) //  3
NSTUB(GetFocusLensSubjectDistance             ,0xffd0bd28) //102
NSTUB(GetFocusLensSubjectDistanceFromLens     ,0xffd0c180) //  3
NSTUB(GetImageFolder                          ,0xffcf55f8) //106
NSTUB(GetKbdState                             ,0xffc4452c) //109
NSTUB(GetMemInfo                              ,0xffc0a760) //  3
NSTUB(GetOpticalTemperature                   ,0xffc466f4) //102
NSTUB(GetParameterData                        ,0xffd36d10) //101
NSTUB(GetPropertyCase                         ,0xffc6c664) //102
NSTUB(GetSystemTime                           ,0xffe082b8) //101
NSTUB(GetVRAMHPixelsSize                      ,0xffcba764) //102
NSTUB(GetVRAMVPixelsSize                      ,0xffcba770) //102
NSTUB(GetZoomLensCurrentPoint                 ,0xffd0fafc) //102
NSTUB(GetZoomLensCurrentPosition              ,0xffdff8ec) //102
NSTUB(GiveSemaphore                           ,0xffc0f06c) //112
NSTUB(IsStrobeChargeCompleted                 ,0xffcaac70) //102
NSTUB(LocalTime                               ,0xffc66668) //  1
NSTUB(LockMainPower                           ,0xffc6ff70) //103
NSTUB(Lseek                                   ,0xffc263d4) //101
NSTUB(MakeDirectory_Fut                       ,0xffc25ca4) //  1
NSTUB(MoveFocusLensToDistance                 ,0xffe5f1d8) //102
NSTUB(MoveIrisWithAv                          ,0xffe050ac) //102
NSTUB(MoveZoomLensWithPoint                   ,0xffe0563c) //102
NSTUB(NewTaskShell                            ,0xffc6c070) //103
NSTUB(Open                                    ,0xffc2624c) //101
NSTUB(PB2Rec                                  ,0xffc72d38) //104
NSTUB(PT_MoveDigitalZoomToWide                ,0xffc59f28) //102
NSTUB(PT_MoveOpticalZoomAt                    ,0xffc59f00) //102
NSTUB(PT_PlaySound                            ,0xffc624e8) //  7
NSTUB(PostLogicalEventForNotPowerType         ,0xffc6f7a0) //103
NSTUB(PostLogicalEventToUI                    ,0xffc6f7ec) //103
NSTUB(PutInNdFilter                           ,0xffe054a0) //102
NSTUB(PutOutNdFilter                          ,0xffe054c4) //102
NSTUB(Read                                    ,0xffc0b270) //101
NSTUB(ReadFastDir                             ,0xffdf6414) //  4
NSTUB(Rec2PB                                  ,0xffc72d78) //104
NSTUB(RefreshPhysicalScreen                   ,0xffd85bf0) //104
NSTUB(Remove                                  ,0xffc262ec) //  4
NSTUB(RenameFile_Fut                          ,0xffc25b9c) //  4
NSTUB(Restart                                 ,0xffc2ae90) //106
NSTUB(SetAE_ShutterSpeed                      ,0xffe61968) //102
NSTUB(SetAutoShutdownTime                     ,0xffc6ffe4) //103
NSTUB(SetCurrentCaptureModeType               ,0xffc76674) //101
NSTUB(SetFileAttributes                       ,0xffc265b0) //  3
NSTUB(SetFileTimeStamp                        ,0xffc26554) //  4
NSTUB(SetLogicalEventActive                   ,0xffc6fce8) //101
NSTUB(SetParameterData                        ,0xffd36c80) //101
NSTUB(SetPropertyCase                         ,0xffc6c534) //102
NSTUB(SleepTask                               ,0xffc29530) //101
NSTUB(TakeSemaphore                           ,0xffc0ef9c) //101
NSTUB(TurnOffBackLight                        ,0xffc7b440) //104
NSTUB(TurnOnBackLight                         ,0xffc7b428) //104
NSTUB(UIFS_WriteFirmInfoToFile                ,0xffd27398) //103
NSTUB(UnlockMainPower                         ,0xffc6fec4) //103
NSTUB(UnsetZoomForMovie                       ,0xffd3cc54) //104
NSTUB(UpdateMBROnFlash                        ,0xffc522c0) //105
NSTUB(VbattGet                                ,0xffc22cf0) //103
NSTUB(Write                                   ,0xffc26348) //101
NSTUB(WriteSDCard                             ,0xffd00d4c) //108
NSTUB(_log                                    ,0xffe8eaf4) //111
NSTUB(_log10                                  ,0xffe8da38) //112
NSTUB(_pow                                    ,0xffe8dba8) //114
NSTUB(_sqrt                                   ,0xffe8fe5c) //  1
NSTUB(add_ptp_handler                         ,0xffdc8e94) //  3
NSTUB(apex2us                                 ,0xffd880ec) //  4
NSTUB(close                                   ,0xffc0b088) //  1
NSTUB(closedir                                ,0xffdf6270) //  4
NSTUB(err_init_task                           ,0xffc05f50) //  4
NSTUB(exmem_alloc                             ,0xffc67308) //103
NSTUB(free                                    ,0xffc04160) //112
NSTUB(kbd_p1_f                                ,0xffc23d54) //109
NSTUB(kbd_p1_f_cont                           ,0xffc23d60) //109
NSTUB(kbd_p2_f                                ,0xffc23604) //109
NSTUB(kbd_read_keys                           ,0xffc23cd4) //109
NSTUB(kbd_read_keys_r2                        ,0xffc43eac) //109
NSTUB(lseek                                   ,0xffc263d4) //101
NSTUB(malloc                                  ,0xffc04104) //112
NSTUB(memcmp                                  ,0xffc11280) //101
NSTUB(memcpy                                  ,0xffc2ec8c) //101
NSTUB(memset                                  ,0xffd87124) //101
NSTUB(mkdir                                   ,0xffc26754) //  4
NSTUB(mktime_ext                              ,0xffc806fc) //  1
NSTUB(open                                    ,0xffc0afd8) //  1
NSTUB(opendir                                 ,0xffdf62c0) //  4
NSTUB(openfastdir                             ,0xffdf62c0) //  4
NSTUB(qsort                                   ,0xffe4724c) //  4
NSTUB(rand                                    ,0xffc11388) //  1
NSTUB(read                                    ,0xffc0b270) //101
NSTUB(reboot_fw_update                        ,0xffdf7c88) //  1
NSTUB(set_control_event                       ,0xffc6fa08) //111
NSTUB(srand                                   ,0xffc1137c) //  1
NSTUB(stat                                    ,0xffc2641c) //  3
NSTUB(strcat                                  ,0xffc7feb8) //  1
NSTUB(strchr                                  ,0xffc03fe8) //  1
NSTUB(strcmp                                  ,0xffc1123c) //101
NSTUB(strcpy                                  ,0xffc11224) //101
NSTUB(strftime                                ,0xffc80104) //113
NSTUB(strlen                                  ,0xffc04034) //101
NSTUB(strncmp                                 ,0xffc03f9c) //  1
NSTUB(strncpy                                 ,0xffc03f60) //  1
NSTUB(strrchr                                 ,0xffc0400c) //  1
NSTUB(strtol                                  ,0xffc2ef6c) //101
NSTUB(strtolx                                 ,0xffc2ed70) //109
  DEF(task_CaptSeq                            ,0xffc5c1e8) //107
  DEF(task_ExpDrv                             ,0xffc95048) //110
  DEF(task_InitFileModules                    ,0xffc736c4) //107
  DEF(task_MovieRecord                        ,0xffd138cc) //107
  DEF(task_PhySw                              ,0xffc23934) //107
NSTUB(time                                    ,0xffc6651c) //  1
NSTUB(vsprintf                                ,0xffc111e8) //  4
NSTUB(write                                   ,0xffc26348) //101
