// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R47 (DRYOS version 2.3, release #0047)
//   Firmware Ver GM1.01A
//   Canon PowerShot SX230 HS

// Values for makefile.inc
//   PLATFORMOSVER = 47
//   PLATFORMID = 12840 (0x3228) // Found @ 0xfff40040
//   MAXRAMADDR = 0x07ffffff
//   KEYSYS = d4c                // Found @ 0xffff3610
//   NEED_ENCODED_DISKBOOT = 6   // Found @ 0xffff3620

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NSTUB(Restart                               ,0xff02d4d4) //106        *** != 0xff02d3d8
//NSTUB(kbd_pwr_off                           ,0xff05783c) //  2 60%    *** != 0x00000000
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff097158 -> ff093580 -> ff1b8470 -> ff3232ac -> ff4957d8
// Mode 16936 in firmware but not in current modemap
// Mode 16938 in firmware but not in current modemap

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x000358e8) // Found @0xff024d18
DEF(physw_run                               ,0x00001c44) // Found @0xff0248ac
DEF(physw_sleep_delay                       ,0x00001c4c) // Found @0xff0248ac
DEF(levent_table                            ,0xff421558) // Found @0xff421558
DEF(FlashParamsTable                        ,0xff495a24) // Found @0xff495a24
DEF(movie_status                            ,0x00008624) // Found @0xff18c740
DEF(full_screen_refresh                     ,0x0000b440) // Found @0xff244a0c
DEF(canon_menu_active                       ,0x000042d4) // Found @0xff08ca7c
DEF(canon_shoot_menu_active                 ,0x00009995) // Found @0xff1d4744
DEF(playrec_mode                            ,0x00004008) // Found @0xff07ed44
//DEF(zoom_status                             ,0x0000f6bc) // Found @0xff326964, ** != ** stubs_min = 0x0000f69c (0xF69C)
DEF(some_flag_for_af_scan                   ,0x00008a28) // Found @0xff190e18
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 3 int value(s), the first is the zoom focus length.
// there are 126 entries in the table - set NUM_FL to 126
DEF(focus_len_table                         ,0xfff4a3dc) // Found @0xfff4a3dc
DEF(zoom_busy                               ,0x00008548) // Found @0xff1878c4
DEF(focus_busy                              ,0x000083c4) // Found @0xff181e44
//DEF(recreview_hold                          ,0x00004e04) // Found @0xff0a0170, ** != ** stubs_min = 0x0000956c (0x947C+0xF0)
DEF(palette_control                         ,0x0000b440) // Found @0xff244988
DEF(active_palette_buffer                   ,0x0000b448) // Found @0xff24498c
DEF(palette_buffer                          ,0x000ceb38) // Found @0xff244e64
DEF(bitmap_buffer                           ,0x0000b480) // Found @0xff249ae4
DEF(active_bitmap_buffer                    ,0x0000b478) // Found @0xff249ae8

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x40471000; }             // Found @0xff0514cc
//void *vid_get_viewport_fb()      { return (void*)0x405d7980; }             // Found @0xff37c5e0
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x3cd0+0x58)); } // Found @0xff06e884 & 0xff06e8bc
//char *camera_jpeg_count_str()    { return (char*)0x000ce488; }             // Found @0xff2399d4
//long hook_raw_size()             { return 0x0123eaf0; }                    // Found @0xff37faf4
//int get_flash_params_count(void) { return 0xa0; }                          // Found @0xff1b94a8

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xff3bd248, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x04000000 // Found @0xff3bd280, levent 0x902
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_DISPLAY         ,0x00000800 }, // Found @0xff3bd1b8, levent 0x0a
//    { 0, KEY_UP              ,0x00001000 }, // Found @0xff3bd1c0, levent 0x04
//    { 0, KEY_RIGHT           ,0x00004000 }, // Found @0xff3bd1d0, levent 0x07
//    { 0, KEY_SET             ,0x00010000 }, // Found @0xff3bd1e0, levent 0x08
//    { 0, KEY_DOWN            ,0x00020000 }, // Found @0xff3bd1e8, levent 0x05
//    { 0, KEY_MENU            ,0x00040000 }, // Found @0xff3bd1f0, levent 0x09
//    { 0, KEY_VIDEO           ,0x00080000 }, // Found @0xff3bd1f8, levent 0x12
//    { 1, KEY_PLAYBACK        ,0x00200000 }, // Found @0xff3bd200, levent 0x601
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000002 }, // Found @0xff3bd210, levent 0x01
//    { 2, KEY_LEFT            ,0x00000100 }, // Found @0xff3bd220, levent 0x06
//    { 2, KEY_POWER           ,0x00000800 }, // Found @0xff3bd228, levent 0x600
//    { 2, KEY_SHOOT_FULL      ,0x00002002 }, // Found @0xff3bd210, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00002000 }, // Found @0xff3bd230, levent 0x00
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#define CAM_RAW_ROWPIX    4168 // Found @0xff156444
//#define CAM_RAW_ROWS      3060 // Found @0xff156450
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff02bcc0

// Misc stuff
DEF(ctypes, 0xff3ba712)

// For capt_seq.c
//static long *nrflag = (long*)(0x8a64+0x08);  // Found @ ff195aa4 & ff195b10
//#define NR_AUTO (0)                          // have to explictly reset value back to 0 to enable auto

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NSTUB(AllocateMemory                          ,0xff311a64) //101
NSTUB(AllocateUncacheableMemory               ,0xff02bc78) //112
NSTUB(Close                                   ,0xff0274b8) //101
NSTUB(CreateTask                              ,0xff00e9b0) //101
NSTUB(DebugAssert                             ,0xff00ec88) //111
NSTUB(DeleteDirectory_Fut                     ,0xff026eb4) //116
NSTUB(DeleteFile_Fut                          ,0xff026dd0) //112
NSTUB(DoAFLock                                ,0xff02900c) //102
NSTUB(EnterToCompensationEVF                  ,0xff0292a8) //104
NSTUB(ExecuteEventProcedure                   ,0xff0881a8) //104
NSTUB(ExitFromCompensationEVF                 ,0xff0292ec) //104
NSTUB(ExitTask                                ,0xff00ec40) //101
NSTUB(ExpCtrlTool_StartContiAE                ,0xff038584) //104
NSTUB(ExpCtrlTool_StopContiAE                 ,0xff03865c) //104
NSTUB(Fclose_Fut                              ,0xff026f4c) //101
NSTUB(Feof_Fut                                ,0xff027138) //  1
NSTUB(Fflush_Fut                              ,0xff027174) //  1
NSTUB(Fgets_Fut                               ,0xff0270a0) //  6
NSTUB(Fopen_Fut                               ,0xff026f0c) //101
NSTUB(Fread_Fut                               ,0xff026ff8) //101
NSTUB(FreeMemory                              ,0xff311a5c) //101
NSTUB(FreeUncacheableMemory                   ,0xff02bcb8) //112
NSTUB(Fseek_Fut                               ,0xff0270ec) //101
NSTUB(Fwrite_Fut                              ,0xff02704c) //101
NSTUB(GetBatteryTemperature                   ,0xff05e568) //102
NSTUB(GetCCDTemperature                       ,0xff05e4f4) //102
NSTUB(GetCurrentAvValue                       ,0xff184838) //102
NSTUB(GetDrive_ClusterSize                    ,0xff06c38c) //  6
NSTUB(GetDrive_FreeClusters                   ,0xff06c3e4) //  6
NSTUB(GetDrive_TotalClusters                  ,0xff06c3bc) //  6
NSTUB(GetFocusLensSubjectDistance             ,0xff182ac8) //102
NSTUB(GetFocusLensSubjectDistanceFromLens     ,0xff182f28) //  3
NSTUB(GetImageFolder                          ,0xff15d3f0) //  6
NSTUB(GetKbdState                             ,0xff057704) //109
NSTUB(GetMemInfo                              ,0xff00a29c) //115
NSTUB(GetOpticalTemperature                   ,0xff05e5dc) //102
NSTUB(GetParameterData                        ,0xff1b9468) //101
NSTUB(GetPropertyCase                         ,0xff08bf50) //102
NSTUB(GetSystemTime                           ,0xff311abc) //101
NSTUB(GetVRAMHPixelsSize                      ,0xff0465b0) //102
NSTUB(GetVRAMVPixelsSize                      ,0xff0465bc) //102
NSTUB(GetZoomLensCurrentPoint                 ,0xff187d3c) //102
NSTUB(GetZoomLensCurrentPosition              ,0xff2fb1a4) //102
NSTUB(GiveSemaphore                           ,0xff02b670) //112
NSTUB(IsStrobeChargeCompleted                 ,0xff0e2d14) //102
NSTUB(LEDDrive                                ,0xff056a38) //101
NSTUB(LocalTime                               ,0xff085a38) //115
NSTUB(LockMainPower                           ,0xff093170) //103
NSTUB(Lseek                                   ,0xff0276d4) //101
NSTUB(MakeDirectory_Fut                       ,0xff026e44) //116
NSTUB(MakeSDCardBootable                      ,0xff06c60c) //105
NSTUB(MoveFocusLensToDistance                 ,0xff3788dc) //102
NSTUB(MoveIrisWithAv                          ,0xff30dacc) //102
NSTUB(MoveZoomLensWithPoint                   ,0xff30e290) //102
NSTUB(NewTaskShell                            ,0xff08b958) //101
NSTUB(Open                                    ,0xff0273f0) //101
NSTUB(PB2Rec                                  ,0xff096634) //104
NSTUB(PT_MoveDigitalZoomToWide                ,0xff075cb0) //102
NSTUB(PT_MoveOpticalZoomAt                    ,0xff075c88) //102
NSTUB(PT_PlaySound                            ,0xff080e14) //  6
NSTUB(PostLogicalEventForNotPowerType         ,0xff090c88) //103
NSTUB(PostLogicalEventToUI                    ,0xff090cd4) //103
NSTUB(PutInNdFilter                           ,0xff376528) //102
NSTUB(PutOutNdFilter                          ,0xff376560) //102
NSTUB(Read                                    ,0xff00ad58) //101
NSTUB(ReadFastDir                             ,0xff2e70dc) //  6
NSTUB(Rec2PB                                  ,0xff094d40) //104
NSTUB(RefreshPhysicalScreen                   ,0xff0ac09c) //104
NSTUB(Remove                                  ,0xff02762c) //  6
NSTUB(RenameFile_Fut                          ,0xff026d3c) //116
NSTUB(ScreenLock                              ,0xff0ad294) //  4
NSTUB(ScreenUnlock                            ,0xff0ad2f8) //  3
NSTUB(SetAE_ShutterSpeed                      ,0xff37b758) //102
NSTUB(SetAutoShutdownTime                     ,0xff0931e4) //103
NSTUB(SetCurrentCaptureModeType               ,0xff09ce48) //101
NSTUB(SetFileAttributes                       ,0xff0278bc) //  6
NSTUB(SetFileTimeStamp                        ,0xff027844) //  6
NSTUB(SetLogicalEventActive                   ,0xff092eac) //101
NSTUB(SetParameterData                        ,0xff1b93d8) //101
NSTUB(SetPropertyCase                         ,0xff08be24) //102
NSTUB(SetScriptMode                           ,0xff092efc) //101
NSTUB(SleepTask                               ,0xff02b91c) //101
NSTUB(TakeSemaphore                           ,0xff02b5a0) //101
NSTUB(TurnOffBackLight                        ,0xff0a41f8) //104
NSTUB(TurnOnBackLight                         ,0xff0a41e0) //104
NSTUB(UIFS_WriteFirmInfoToFile                ,0xff1a9b08) //101
NSTUB(UnlockAF                                ,0xff029044) //102
NSTUB(UnlockMainPower                         ,0xff0930c4) //103
NSTUB(VbattGet                                ,0xff02307c) //101
NSTUB(Write                                   ,0xff02750c) //101
NSTUB(WriteSDCard                             ,0xff171f04) //108
NSTUB(_log                                    ,0xff3b6f78) //111
NSTUB(_log10                                  ,0xff3b74b8) //112
NSTUB(_pow                                    ,0xff3b7630) //114
NSTUB(_sqrt                                   ,0xff3b9514) //  6
NSTUB(add_ptp_handler                         ,0xff291e00) //  6
NSTUB(apex2us                                 ,0xff24dfd0) //  4
NSTUB(close                                   ,0xff00abb4) //  6
NSTUB(closedir                                ,0xff2e6f38) //  4
NSTUB(err_init_task                           ,0xff005fd4) //111
NSTUB(exmem_alloc                             ,0xff086a00) //101
NSTUB(free                                    ,0xff004244) //112
NSTUB(kbd_p1_f                                ,0xff024d94) //109
NSTUB(kbd_p1_f_cont                           ,0xff024da0) //109
NSTUB(kbd_p2_f                                ,0xff02457c) //109
NSTUB(kbd_read_keys                           ,0xff024d18) //109
NSTUB(kbd_read_keys_r2                        ,0xff056f04) //109
NSTUB(lseek                                   ,0xff0276d4) //101
NSTUB(malloc                                  ,0xff0041ec) //112
NSTUB(memcmp                                  ,0xff010930) //101
NSTUB(memcpy                                  ,0xff03158c) //101
NSTUB(memset                                  ,0xff24cfd0) //101
NSTUB(mkdir                                   ,0xff027954) //109
NSTUB(mktime_ext                              ,0xff0ae10c) //  1
NSTUB(open                                    ,0xff00ab04) //  6
NSTUB(OpenFastDir                             ,0xff2e6f88) //  6
NSTUB(qsort                                   ,0xff3639f0) //  6
NSTUB(rand                                    ,0xff24d110) //  6
NSTUB(read                                    ,0xff00ad58) //101
NSTUB(reboot_fw_update                        ,0xff2ec578) //106
NSTUB(set_control_event                       ,0xff092aa4) //111
NSTUB(srand                                   ,0xff24d104) //  6
NSTUB(stat                                    ,0xff02771c) //109
NSTUB(strcat                                  ,0xff0ad8c4) //  1
NSTUB(strchr                                  ,0xff0040b8) //  1
NSTUB(strcmp                                  ,0xff0108ec) //101
NSTUB(strcpy                                  ,0xff0108d4) //101
NSTUB(strftime                                ,0xff0adb0c) //113
NSTUB(strlen                                  ,0xff004104) //101
NSTUB(strncmp                                 ,0xff00406c) //  1
NSTUB(strncpy                                 ,0xff004030) //  1
NSTUB(strrchr                                 ,0xff0040dc) //  1
NSTUB(strtol                                  ,0xff03188c) //101
NSTUB(strtolx                                 ,0xff031690) //109
  DEF(task_CaptSeq                            ,0xff078bf0) //110
  DEF(task_ExpDrv                             ,0xff0c5e98) //110
  DEF(task_InitFileModules                    ,0xff096fcc) //110
  DEF(task_MovieRecord                        ,0xff18d9cc) //110
  DEF(task_PhySw                              ,0xff0248a8) //110
  DEF(task_RotaryEncoder                      ,0xff0579ac) //110
NSTUB(time                                    ,0xff086014) //109
NSTUB(vsprintf                                ,0xff010894) //115
NSTUB(write                                   ,0xff02750c) //101
