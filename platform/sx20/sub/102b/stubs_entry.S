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
//   KEYSYS = d4                 // Found @ 0xffff35a0
//   NEED_ENCODED_DISKBOOT = 3   // Found @ 0xffff35b0

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NSTUB(DoAFLock                              ,0xff836a9c) //102        *** != 0xff8796b4
//NSTUB(TurnOffBackLight                      ,0xff8a5ae0) //104        *** != 0xff89b6a4
//NSTUB(UIFS_WriteFirmInfoToFile              ,0xff9799bc) //105        *** != 0xdeadc0de
//NSTUB(UnlockAF                              ,0xff836b38) //102        *** != 0xff8796c4
//NSTUB(VbattGet                              ,0xff831cec) //103        *** != 0xff95d0c0
//NSTUB(kbd_pwr_off                           ,0xff85f2c4) //  2 60%    *** != 0x00000000
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

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x403f1000; }             // Found @0xff859684
//void *vid_get_viewport_fb()      { return (void*)0x41020120; }             // Found @0xffb0328c
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x2a30+0x58)); } // Found @0xff870840 & 0xff870878
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
//static long *nrflag = (long*)(0x7918-0x08);  // Found @ ff9623ec & ff962408

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NSTUB(AllocateMemory                          ,0xffa9b66c) //101
NSTUB(AllocateUncacheableMemory               ,0xff838de8) //112
NSTUB(Close                                   ,0xff83527c) //101
NSTUB(CreateTask                              ,0xff81e5b4) //101
NSTUB(DebugAssert                             ,0xff81e88c) //111
NSTUB(DeleteDirectory_Fut                     ,0xff834cec) //116
NSTUB(DeleteFile_Fut                          ,0xff834c08) //112
NSTUB(EnterToCompensationEVF                  ,0xff836d84) //104
NSTUB(ExecuteEventProcedure                   ,0xff88b548) //104
NSTUB(ExitFromCompensationEVF                 ,0xff836dc8) //104
NSTUB(ExitTask                                ,0xff81e844) //101
NSTUB(ExpCtrlTool_StartContiAE                ,0xff84465c) //104
NSTUB(ExpCtrlTool_StopContiAE                 ,0xff844734) //104
NSTUB(Fclose_Fut                              ,0xff834d84) //101
NSTUB(Feof_Fut                                ,0xff834f70) //  1
NSTUB(Fflush_Fut                              ,0xff834fac) //  1
NSTUB(Fgets_Fut                               ,0xff834ed8) //  1
NSTUB(Fopen_Fut                               ,0xff834d44) //101
NSTUB(Fread_Fut                               ,0xff834e30) //101
NSTUB(FreeMemory                              ,0xffa9b664) //101
NSTUB(FreeUncacheableMemory                   ,0xff838e28) //112
NSTUB(Fseek_Fut                               ,0xff834f24) //101
NSTUB(Fwrite_Fut                              ,0xff834e84) //101
NSTUB(GetBatteryTemperature                   ,0xff862744) //102
NSTUB(GetCCDTemperature                       ,0xff8626d0) //102
NSTUB(GetCurrentAvValue                       ,0xff95251c) //102
NSTUB(GetDrive_ClusterSize                    ,0xff86f1c8) //  3
NSTUB(GetDrive_FreeClusters                   ,0xff86f228) //  3
NSTUB(GetDrive_TotalClusters                  ,0xff86f1fc) //  3
NSTUB(GetFocusLensSubjectDistance             ,0xff950a10) //102
NSTUB(GetFocusLensSubjectDistanceFromLens     ,0xff950e44) //  3
NSTUB(GetImageFolder                          ,0xff933518) //106
NSTUB(GetKbdState                             ,0xff85f11c) //109
NSTUB(GetMemInfo                              ,0xff81a070) //115
NSTUB(GetOpticalTemperature                   ,0xff8627b8) //102
NSTUB(GetParameterData                        ,0xff9905e4) //101
NSTUB(GetPropertyCase                         ,0xff88f2dc) //102
NSTUB(GetSystemTime                           ,0xffa9b6c4) //101
NSTUB(GetVRAMHPixelsSize                      ,0xff84f904) //102
NSTUB(GetVRAMVPixelsSize                      ,0xff84f910) //102
NSTUB(GetZoomLensCurrentPoint                 ,0xff9566a8) //102
NSTUB(GetZoomLensCurrentPosition              ,0xffa8eb50) //102
NSTUB(GiveSemaphore                           ,0xff838804) //112
NSTUB(IsStrobeChargeCompleted                 ,0xff8ce3a4) //102
NSTUB(LEDDrive                                ,0xff85e338) //103
NSTUB(LocalTime                               ,0xff888ebc) //115
NSTUB(LockMainPower                           ,0xff896eac) //103
NSTUB(Lseek                                   ,0xff835398) //101
NSTUB(MakeDirectory_Fut                       ,0xff834c7c) //116
NSTUB(MoveFocusLensToDistance                 ,0xffaff554) //102
NSTUB(MoveIrisWithAv                          ,0xffa96fec) //102
NSTUB(MoveZoomLensWithPoint                   ,0xffa97714) //102
NSTUB(NewTaskShell                            ,0xff88eda0) //103
NSTUB(Open                                    ,0xff835224) //101
NSTUB(PB2Rec                                  ,0xff899de8) //104
NSTUB(PT_MoveDigitalZoomToWide                ,0xff879664) //102
NSTUB(PT_MoveOpticalZoomAt                    ,0xff87963c) //102
NSTUB(PT_PlaySound                            ,0xff884058) //102
NSTUB(PostLogicalEventForNotPowerType         ,0xff894da8) //103
NSTUB(PostLogicalEventToUI                    ,0xff894df4) //103
NSTUB(PutInNdFilter                           ,0xffa97598) //102
NSTUB(PutOutNdFilter                          ,0xffa975bc) //102
NSTUB(Read                                    ,0xff81ab78) //101
NSTUB(ReadFastDir                             ,0xffa7d518) //  3
NSTUB(Rec2PB                                  ,0xff898854) //104
NSTUB(RefreshPhysicalScreen                   ,0xffa0491c) //104
NSTUB(Remove                                  ,0xff8352b0) //  4
NSTUB(RenameFile_Fut                          ,0xff834b74) //116
NSTUB(Restart                                 ,0xff83a53c) //106
NSTUB(ScreenLock                              ,0xffa048e8) //  8
NSTUB(ScreenUnlock                            ,0xffa0498c) //  8
NSTUB(SetAE_ShutterSpeed                      ,0xffb02404) //102
NSTUB(SetAutoShutdownTime                     ,0xff896f20) //103
NSTUB(SetCurrentCaptureModeType               ,0xff89eb28) //101
NSTUB(SetFileAttributes                       ,0xff83554c) //  3
NSTUB(SetFileTimeStamp                        ,0xff835508) //  3
NSTUB(SetLogicalEventActive                   ,0xff896bfc) //101
NSTUB(SetParameterData                        ,0xff9904c0) //101
NSTUB(SetPropertyCase                         ,0xff88f1e0) //102
NSTUB(SetScriptMode                           ,0xff896c4c) //101
NSTUB(SleepTask                               ,0xff838a6c) //101
NSTUB(TakeSemaphore                           ,0xff838734) //101
NSTUB(TurnOnBackLight                         ,0xff8a5ac8) //104
NSTUB(UnlockMainPower                         ,0xff896e00) //103
NSTUB(UpdateMBROnFlash                        ,0xff86f048) //105
NSTUB(Write                                   ,0xff83530c) //101
NSTUB(WriteSDCard                             ,0xff940b80) //108
NSTUB(_log                                    ,0xffb37d1c) //111
NSTUB(_log10                                  ,0xffb36c60) //112
NSTUB(_pow                                    ,0xffb36dd0) //114
NSTUB(_sqrt                                   ,0xffb39084) //  1
NSTUB(add_ptp_handler                         ,0xffa49164) //  3
NSTUB(apex2us                                 ,0xffa080a8) //  4
NSTUB(close                                   ,0xff81a990) //  1
NSTUB(closedir                                ,0xffa7d3a0) //  3
NSTUB(err_init_task                           ,0xff815f28) //111
NSTUB(exmem_alloc                             ,0xff889d7c) //103
NSTUB(free                                    ,0xff814138) //112
NSTUB(kbd_p1_f                                ,0xff833498) //109
NSTUB(kbd_p1_f_cont                           ,0xff8334a4) //109
NSTUB(kbd_p2_f                                ,0xff832d58) //109
NSTUB(kbd_read_keys                           ,0xff83341c) //109
NSTUB(kbd_read_keys_r2                        ,0xff85e850) //109
NSTUB(lseek                                   ,0xff835398) //101
NSTUB(malloc                                  ,0xff8140dc) //112
NSTUB(memcmp                                  ,0xff8203d8) //101
NSTUB(memcpy                                  ,0xff83e458) //101
NSTUB(memset                                  ,0xffa070f8) //101
NSTUB(mkdir                                   ,0xff8356f0) //109
NSTUB(mktime_ext                              ,0xff8ad0c0) //  1
NSTUB(open                                    ,0xff81a8e0) //  1
NSTUB(OpenFastDir                             ,0xffa7d3e4) //  3
NSTUB(qsort                                   ,0xffaeb4a0) //  1
NSTUB(rand                                    ,0xff8204e0) //  1
NSTUB(read                                    ,0xff81ab78) //101
NSTUB(reboot_fw_update                        ,0xffa82a28) //106
NSTUB(set_control_event                       ,0xff896850) //111
NSTUB(srand                                   ,0xff8204d4) //  1
NSTUB(stat                                    ,0xff8353d4) //109
NSTUB(strcat                                  ,0xff8ac87c) //  1
NSTUB(strchr                                  ,0xff813fc0) //  1
NSTUB(strcmp                                  ,0xff820394) //101
NSTUB(strcpy                                  ,0xff82037c) //101
NSTUB(strftime                                ,0xff8acac8) //  1
NSTUB(strlen                                  ,0xff81400c) //101
NSTUB(strncmp                                 ,0xff813f74) //  1
NSTUB(strncpy                                 ,0xff813f38) //  1
NSTUB(strrchr                                 ,0xff813fe4) //  1
NSTUB(strtol                                  ,0xff83e738) //101
NSTUB(strtolx                                 ,0xff83e53c) //109
  DEF(task_CaptSeq                            ,0xff87cd40) //107
  DEF(task_ExpDrv                             ,0xff8c1430) //110
  DEF(task_InitFileModules                    ,0xff89a8cc) //107
  DEF(task_MovieRecord                        ,0xff879034) //107
  DEF(task_PhySw                              ,0xff833088) //107
  DEF(task_RotaryEncoder                      ,0xff85f3cc) //107
NSTUB(time                                    ,0xff889434) //109
NSTUB(vsprintf                                ,0xff820340) //115
NSTUB(write                                   ,0xff83530c) //101
