// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R39 (DRYOS version 2.3, release #0039)
//   Firmware Ver GM1.02B
//   Canon PowerShot SX20 IS

// Values for makefile.inc
//   PLATFORMOSVER = 39
//   PLATFORMID = 12772 (0x31e4) // Found @ 0xfffe0130
//   MAXRAMADDR = 0x03ffffff
//   MEMISOSTART = 0x0013dd6c
//   KEYSYS = d4                 // Found @ 0xffff35a0
//   NEED_ENCODED_DISKBOOT = 3   // Found @ 0xffff35b0

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NHSTUB(DoAFLock                             ,0xff836a9c) //102        *** != 0xff8796b4
//NHSTUB(TurnOffBackLight                     ,0xff8a5ae0) //104        *** != 0xff89b6a4
//NHSTUB(UIFS_WriteFirmInfoToFile             ,0xff9799bc) //105        *** != 0xdeadc0de
//NHSTUB(UnlockAF                             ,0xff836b38) //102        *** != 0xff8796c4
//NHSTUB(VbattGet                             ,0xff831cec) //103        *** != 0xff95d0c0
//NHSTUB(kbd_pwr_off                          ,0xff85f2c4) //  2 60%    *** != 0x00000000
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff89aa40 -> ff897290 -> ff98f024 -> ffaac758 -> ffbe85f8
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00032464) // Found @0xff83341c
DEF(physw_run                               ,0x00001c44) // Found @0xff83308c
DEF(physw_sleep_delay                       ,0x00001c42) // Found @0xff83308c
DEF(levent_table                            ,0xffba31ec) // Found @0xffba31ec
DEF(FlashParamsTable                        ,0xffbe87e0) // Found @0xffbe87e0
DEF(movie_status                            ,0x00002c30) // Found @0xff878db0
DEF(video_compression_rate                  ,0x00002c5c) // Found @0xff878fb8
DEF(full_screen_refresh                     ,0x00009cf4) // Found @0xffa025bc
DEF(canon_menu_active                       ,0x0000312c) // Found @0xff88fe90
DEF(canon_shoot_menu_active                 ,0x00008845) // Found @0xff9aa028
DEF(playrec_mode                            ,0x00002e58) // Found @0xff882228
DEF(zoom_status                             ,0x0000c6c0) // Found @0xffaaf48c
DEF(some_flag_for_af_scan                   ,0x00007934) // Found @0xff95fb44
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 1 int value, which is the the zoom focus length.
// there are 6 entries in the table - set NUM_FL to 6
DEF(focus_len_table                         ,0xffbadb68) // Found @0xffbadb68
DEF(zoom_busy                               ,0x00006ec0) // Found @0xff955d40
DEF(focus_busy                              ,0x00006d50) // Found @0xff94fed4
//DEF(recreview_hold                          ,0x00003d2c) // Found @0xff8a1b60, ** != ** stubs_min = 0x000083d8 (0x82E0+0xF8)
// Palette colour tables  found @ 0xffbbbf9c
DEF(active_palette_buffer                   ,0x00009cfc) // Found @0xffa024f8
DEF(palette_buffer_ptr                      ,0x00009d08) // Found @0xffa021cc
// Offset from start of palette_buffer to color data = 8 (Found @0xffae57dc)
// Camera appears to have only 1 RAW buffer @ 0x41f723e0 (Found @0xffb05994)

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x403f1000; }             // Found @0xff859684
//void *vid_get_viewport_fb()      { return (void*)0x41020120; }             // Found @0xffb0328c
DEF(viewport_fb_d                           ,0x00002a88) // Found 0x2a30 (@0xff870840) + 0x58 (@0xff870878)
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x2a30+0x58)); } // Found @0xff870840 & 0xff870878
DEF(jpeg_count_str                          ,0x00072dfc) // Found @0xff9f71ac
//char *camera_jpeg_count_str()    { return (char*)0x00072dfc; }             // Found @0xff9f71ac
//long hook_raw_size()             { return 0x011ca240; }                    // Found @0xffb059f0
//int get_flash_params_count(void) { return 0x84; }                          // Found @0xff990624

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffb44bc8, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x00040000 // Found @0xffb44bd4, levent 0x902
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_SHOOT_FULL      ,0x00000003 }, // Found @0xffb44a60, levent 0x01
//    { 0, KEY_SHOOT_FULL_ONLY ,0x00000002 }, // Found @0xffb44a60, levent 0x01
//    { 0, KEY_SHOOT_HALF      ,0x00000001 }, // Found @0xffb44a54, levent 0x00
//    { 0, KEY_POWER           ,0x00002000 }, // Found @0xffb44a6c, levent 0x600
//    { 0, KEY_PLAYBACK        ,0x00004000 }, // Found @0xffb44a78, levent 0x601
//    { 1, KEY_VIDEO           ,0x00000020 }, // Found @0xffb44acc, levent 0x12
//    { 1, KEY_SET             ,0x00000100 }, // Found @0xffb44af0, levent 0x08
//    { 1, KEY_DISPLAY         ,0x00000200 }, // Found @0xffb44afc, levent 0x0a
//    { 1, KEY_UP              ,0x00000400 }, // Found @0xffb44b08, levent 0x04
//    { 1, KEY_DOWN            ,0x00000800 }, // Found @0xffb44b14, levent 0x05
//    { 1, KEY_RIGHT           ,0x00001000 }, // Found @0xffb44b20, levent 0x07
//    { 1, KEY_LEFT            ,0x00002000 }, // Found @0xffb44b2c, levent 0x06
//    { 1, KEY_MENU            ,0x00004000 }, // Found @0xffb44b38, levent 0x09
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_RAW_ROWPIX    4080 // Found @0xff92b6d4
//#define CAM_RAW_ROWS      3048 // Found @0xff92b6dc
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff838e2c

// Misc stuff
DEF(ctypes, 0xffb3a25a)

// For capt_seq.c
DEF(_nrflag,0x7910) // Found @ ff9623ec (0x7918) & ff96240c (-0x08)
//static long *nrflag = (long*)(0x7918-0x08);  // Found @ ff9623ec & ff962408

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
//NHSTUB(CreateJumptable                      ,0xffb06418) //  1
//NHSTUB(_uartr_req                           ,0xff81f954) //111
//NHSTUB(StartRecModeMenu                     ,0xff88fe8c) //102
//NHSTUB(AllocateMemory                       ,0xffa9b66c) //101
NHSTUB(AllocateUncacheableMemory              ,0xff838de8) //112
NHSTUB(Close                                  ,0xff83527c) //101
NHSTUB(CreateTask                             ,0xff81e5b4) //101
NHSTUB(DebugAssert                            ,0xff81e88c) //111
NHSTUB(DeleteDirectory_Fut                    ,0xff834cec) //116
NHSTUB(DeleteFile_Fut                         ,0xff834c08) //112
NHSTUB(EnterToCompensationEVF                 ,0xff836d84) //104
NHSTUB(ExecuteEventProcedure                  ,0xff88b548) //104
NHSTUB(ExitFromCompensationEVF                ,0xff836dc8) //104
NHSTUB(ExitTask                               ,0xff81e844) //101
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff84465c) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff844734) //104
NHSTUB(Fclose_Fut                             ,0xff834d84) //101
NHSTUB(Feof_Fut                               ,0xff834f70) //  1
NHSTUB(Fflush_Fut                             ,0xff834fac) //  1
NHSTUB(Fgets_Fut                              ,0xff834ed8) //  1
NHSTUB(Fopen_Fut                              ,0xff834d44) //101
NHSTUB(Fread_Fut                              ,0xff834e30) //101
//NHSTUB(FreeMemory                           ,0xffa9b664) //101
NHSTUB(FreeUncacheableMemory                  ,0xff838e28) //112
NHSTUB(Fseek_Fut                              ,0xff834f24) //101
NHSTUB(Fwrite_Fut                             ,0xff834e84) //101
NHSTUB(GetBatteryTemperature                  ,0xff862744) //102
NHSTUB(GetCCDTemperature                      ,0xff8626d0) //102
NHSTUB(GetCurrentAvValue                      ,0xff95251c) //102
NHSTUB(GetDrive_ClusterSize                   ,0xff86f1c8) //  3
NHSTUB(GetDrive_FreeClusters                  ,0xff86f228) //  3
NHSTUB(GetDrive_TotalClusters                 ,0xff86f1fc) //  3
NHSTUB(GetFocusLensSubjectDistance            ,0xff950a10) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff950e44) //  3
NHSTUB(GetImageFolder                         ,0xff933518) //106
NHSTUB(GetKbdState                            ,0xff85f11c) //109
NHSTUB(GetMemInfo                             ,0xff81a070) //115
NHSTUB(GetOpticalTemperature                  ,0xff8627b8) //102
NHSTUB(GetParameterData                       ,0xff9905e4) //101
NHSTUB(GetPropertyCase                        ,0xff88f2dc) //102
NHSTUB(GetSystemTime                          ,0xffa9b6c4) //101
NHSTUB(GetVRAMHPixelsSize                     ,0xff84f904) //102
NHSTUB(GetVRAMVPixelsSize                     ,0xff84f910) //102
NHSTUB(GetZoomLensCurrentPoint                ,0xff9566a8) //102
NHSTUB(GetZoomLensCurrentPosition             ,0xffa8eb50) //102
NHSTUB(GiveSemaphore                          ,0xff838804) //112
NHSTUB(IsStrobeChargeCompleted                ,0xff8ce3a4) //102
NHSTUB(LEDDrive                               ,0xff85e338) //103
NHSTUB(LocalTime                              ,0xff888ebc) //115
NHSTUB(LockMainPower                          ,0xff896eac) //103
//NHSTUB(Lseek                                ,0xff835398) //101
NHSTUB(MakeDirectory_Fut                      ,0xff834c7c) //116
NHSTUB(MoveFocusLensToDistance                ,0xffaff554) //102
NHSTUB(MoveIrisWithAv                         ,0xffa96fec) //102
NHSTUB(MoveZoomLensWithPoint                  ,0xffa97714) //102
//NHSTUB(NewTaskShell                         ,0xff88eda0) //103
NHSTUB(Open                                   ,0xff835224) //101
NHSTUB(PB2Rec                                 ,0xff899de8) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff879664) //102
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff87963c) //102
NHSTUB(PT_PlaySound                           ,0xff884058) //102
NHSTUB(PostLogicalEventForNotPowerType        ,0xff894da8) //103
NHSTUB(PostLogicalEventToUI                   ,0xff894df4) //103
NHSTUB(PutInNdFilter                          ,0xffa97598) //102
NHSTUB(PutOutNdFilter                         ,0xffa975bc) //102
NHSTUB(Read                                   ,0xff81ab78) //101
NHSTUB(ReadFastDir                            ,0xffa7d518) //  3
NHSTUB(Rec2PB                                 ,0xff898854) //104
NHSTUB(RefreshPhysicalScreen                  ,0xffa0491c) //104
//NHSTUB(Remove                               ,0xff8352b0) //  4
NHSTUB(RenameFile_Fut                         ,0xff834b74) //116
NHSTUB(Restart                                ,0xff83a53c) //106
NHSTUB(ScreenLock                             ,0xffa048e8) //117
NHSTUB(ScreenUnlock                           ,0xffa0498c) //117
NHSTUB(SetAE_ShutterSpeed                     ,0xffb02404) //102
NHSTUB(SetAutoShutdownTime                    ,0xff896f20) //103
NHSTUB(SetCurrentCaptureModeType              ,0xff89eb28) //101
NHSTUB(SetFileAttributes                      ,0xff83554c) //  3
NHSTUB(SetFileTimeStamp                       ,0xff835508) //  3
NHSTUB(SetLogicalEventActive                  ,0xff896bfc) //101
NHSTUB(SetParameterData                       ,0xff9904c0) //101
NHSTUB(SetPropertyCase                        ,0xff88f1e0) //102
NHSTUB(SetScriptMode                          ,0xff896c4c) //101
NHSTUB(SleepTask                              ,0xff838a6c) //101
NHSTUB(TakeSemaphore                          ,0xff838734) //101
NHSTUB(TurnOnBackLight                        ,0xff8a5ac8) //104
NHSTUB(UnlockMainPower                        ,0xff896e00) //103
NHSTUB(UpdateMBROnFlash                       ,0xff86f048) //105
NHSTUB(Write                                  ,0xff83530c) //101
NHSTUB(WriteSDCard                            ,0xff940b80) //108
NHSTUB(_log                                   ,0xffb37d1c) //111
NHSTUB(_log10                                 ,0xffb36c60) //112
NHSTUB(_pow                                   ,0xffb36dd0) //114
NHSTUB(_sqrt                                  ,0xffb39084) //  1
NHSTUB(add_ptp_handler                        ,0xffa49164) //  3
NHSTUB(apex2us                                ,0xffa080a8) //  4
NHSTUB(close                                  ,0xff81a990) //  1
NHSTUB(closedir                               ,0xffa7d3a0) //  3
NHSTUB(err_init_task                          ,0xff815f28) //111
NHSTUB(exmem_alloc                            ,0xff889d7c) //103
NHSTUB(exmem_free                             ,0xff889df4) //103
NHSTUB(free                                   ,0xff814138) //112
NHSTUB(kbd_p1_f                               ,0xff833498) //109
NHSTUB(kbd_p1_f_cont                          ,0xff8334a4) //109
NHSTUB(kbd_p2_f                               ,0xff832d58) //109
NHSTUB(kbd_read_keys                          ,0xff83341c) //109
NHSTUB(kbd_read_keys_r2                       ,0xff85e850) //109
NHSTUB(lseek                                  ,0xff835398) //101
NHSTUB(malloc                                 ,0xff8140dc) //112
NHSTUB(memcmp                                 ,0xff8203d8) //101
NHSTUB(memcpy                                 ,0xff83e458) //101
NHSTUB(memset                                 ,0xffa070f8) //101
NHSTUB(mkdir                                  ,0xff8356f0) //109
NHSTUB(mktime_ext                             ,0xff8ad0c0) //  1
NHSTUB(open                                   ,0xff81a8e0) //  1
NHSTUB(OpenFastDir                            ,0xffa7d3e4) //  3
NHSTUB(qsort                                  ,0xffaeb4a0) //  1
NHSTUB(rand                                   ,0xff8204e0) //  1
//NHSTUB(read                                 ,0xff81ab78) //101
NHSTUB(realloc                                ,0xffa07174) //115
NHSTUB(reboot_fw_update                       ,0xffa82a28) //106
NHSTUB(set_control_event                      ,0xff896850) //111
NHSTUB(srand                                  ,0xff8204d4) //  1
NHSTUB(stat                                   ,0xff8353d4) //109
NHSTUB(strcat                                 ,0xff8ac87c) //  1
NHSTUB(strchr                                 ,0xff813fc0) //  1
NHSTUB(strcmp                                 ,0xff820394) //101
NHSTUB(strcpy                                 ,0xff82037c) //101
NHSTUB(strftime                               ,0xff8acac8) //  1
NHSTUB(strlen                                 ,0xff81400c) //101
NHSTUB(strncmp                                ,0xff813f74) //  1
NHSTUB(strncpy                                ,0xff813f38) //  1
NHSTUB(strrchr                                ,0xff813fe4) //  1
NHSTUB(strtol                                 ,0xff83e738) //101
NHSTUB(strtolx                                ,0xff83e53c) //109
   DEF(task_CaptSeq                           ,0xff87cd40) //110
   DEF(task_ExpDrv                            ,0xff8c1430) //110
   DEF(task_InitFileModules                   ,0xff89a8cc) //110
   DEF(task_MovieRecord                       ,0xff879034) //110
   DEF(task_PhySw                             ,0xff833088) //110
   DEF(task_RotaryEncoder                     ,0xff85f3cc) //110
NHSTUB(time                                   ,0xff889434) //109
NHSTUB(vsprintf                               ,0xff820340) //115
//NHSTUB(write                                ,0xff83530c) //101
//NHSTUB(EngDrvIn                             ,0xff8342d8) //102
//NHSTUB(EngDrvOut                            ,0xff8342c0) //102
//NHSTUB(EngDrvRead                           ,0xff8342e0) //102
//NHSTUB(EngDrvBits                           ,0xff8342f4) //102
//NHSTUB(GetSDProtect                         ,0xff8333f4) //103
//NHSTUB(DispCon_ShowBitmapColorBar           ,0xff85963c) //102
//NHSTUB(ResetZoomLens                        ,0xffa97668) //102
//NHSTUB(ResetFocusLens                       ,0xffa96530) //102
//NHSTUB(NR_GetDarkSubType                    ,0xff964a28) //102
//NHSTUB(NR_SetDarkSubType                    ,0xff964980) //102
//NHSTUB(SavePaletteData                      ,0xffb04758) //102
//NHSTUB(GUISrv_StartGUISystem                ,0xff8ac5fc) //101
