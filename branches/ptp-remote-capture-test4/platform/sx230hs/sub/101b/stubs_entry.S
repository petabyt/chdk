// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R47 (DRYOS version 2.3, release #0047)
//   Firmware Ver GM1.01B
//   Canon PowerShot SX230 HS

// Values for makefile.inc
//   PLATFORMOSVER = 47
//   PLATFORMID = 12840 (0x3228) // Found @ 0xfff40040
//   MAXRAMADDR = 0x07ffffff
//   KEYSYS = d4c                // Found @ 0xffff3610
//   NEED_ENCODED_DISKBOOT = 6   // Found @ 0xffff3620

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NHSTUB(Restart                              ,0xff02d4d4) //106        *** != 0xff02d3d8
//NHSTUB(kbd_pwr_off                          ,0xff05783c) //  2 60%    *** != 0x00000000
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff097158 -> ff093580 -> ff1b8470 -> ff3232b8 -> ff4957e0
// Mode 16936 in firmware but not in current modemap
// Mode 16938 in firmware but not in current modemap

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x000358e8) // Found @0xff024d18
DEF(physw_run                               ,0x00001c44) // Found @0xff0248ac
DEF(physw_sleep_delay                       ,0x00001c4c) // Found @0xff0248ac
DEF(levent_table                            ,0xff421560) // Found @0xff421560
DEF(FlashParamsTable                        ,0xff495a2c) // Found @0xff495a2c
DEF(movie_status                            ,0x00008624) // Found @0xff18c740
DEF(full_screen_refresh                     ,0x0000b440) // Found @0xff244a0c
DEF(canon_menu_active                       ,0x000042d4) // Found @0xff08ca7c
DEF(canon_shoot_menu_active                 ,0x00009995) // Found @0xff1d4744
DEF(playrec_mode                            ,0x00004008) // Found @0xff07ed44
//DEF(zoom_status                             ,0x0000f6bc) // Found @0xff326970, ** != ** stubs_min = 0x0000f69c (0xF69C)
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
DEF(viewport_buffers                        ,0xff3bc0f8) // Found @0xff043e50
DEF(active_viewport_buffer                  ,0x00002108) // Found @0xff043b10

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x40471000; }             // Found @0xff0514cc
//void *vid_get_viewport_fb()      { return (void*)0x405d7980; }             // Found @0xff37c5ec
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x3cd0+0x58)); } // Found @0xff06e884 & 0xff06e8bc
//char *camera_jpeg_count_str()    { return (char*)0x000ce488; }             // Found @0xff2399d4
//long hook_raw_size()             { return 0x0123eaf0; }                    // Found @0xff37fb00
//int get_flash_params_count(void) { return 0xa0; }                          // Found @0xff1b94a8

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xff3bd250, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x04000000 // Found @0xff3bd288, levent 0x902
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_DISPLAY         ,0x00000800 }, // Found @0xff3bd1c0, levent 0x0a
//    { 0, KEY_UP              ,0x00001000 }, // Found @0xff3bd1c8, levent 0x04
//    { 0, KEY_RIGHT           ,0x00004000 }, // Found @0xff3bd1d8, levent 0x07
//    { 0, KEY_SET             ,0x00010000 }, // Found @0xff3bd1e8, levent 0x08
//    { 0, KEY_DOWN            ,0x00020000 }, // Found @0xff3bd1f0, levent 0x05
//    { 0, KEY_MENU            ,0x00040000 }, // Found @0xff3bd1f8, levent 0x09
//    { 0, KEY_VIDEO           ,0x00080000 }, // Found @0xff3bd200, levent 0x12
//    { 1, KEY_PLAYBACK        ,0x00200000 }, // Found @0xff3bd208, levent 0x601
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000002 }, // Found @0xff3bd218, levent 0x01
//    { 2, KEY_LEFT            ,0x00000100 }, // Found @0xff3bd228, levent 0x06
//    { 2, KEY_POWER           ,0x00000800 }, // Found @0xff3bd230, levent 0x600
//    { 2, KEY_SHOOT_FULL      ,0x00002002 }, // Found @0xff3bd218, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00002000 }, // Found @0xff3bd238, levent 0x00
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
DEF(ctypes, 0xff3ba71a)

// For capt_seq.c
DEF(_nrflag,0x8a6c) // Found @ ff195c0c (0x8a64) & ff195c48 (+0x08)
//static long *nrflag = (long*)(0x8a64+0x08);  // Found @ ff195c0c & ff195c48
//#define NR_AUTO (0)                          // have to explictly reset value back to 0 to enable auto

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
//NHSTUB(CreateJumptable                      ,0xff37fccc) //  1
//NHSTUB(_uartr_req                           ,0xff00fe0c) //111
//NHSTUB(AllocateMemory                       ,0xff311a70) //101
NHSTUB(AllocateUncacheableMemory              ,0xff02bc78) //112
NHSTUB(Close                                  ,0xff0274b8) //101
NHSTUB(CreateTask                             ,0xff00e9b0) //101
NHSTUB(DebugAssert                            ,0xff00ec88) //111
NHSTUB(DeleteDirectory_Fut                    ,0xff026eb4) //116
NHSTUB(DeleteFile_Fut                         ,0xff026dd0) //112
NHSTUB(DoAFLock                               ,0xff02900c) //102
NHSTUB(EnterToCompensationEVF                 ,0xff0292a8) //104
NHSTUB(ExecuteEventProcedure                  ,0xff0881a8) //104
NHSTUB(ExitFromCompensationEVF                ,0xff0292ec) //104
NHSTUB(ExitTask                               ,0xff00ec40) //101
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff038584) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff03865c) //104
NHSTUB(Fclose_Fut                             ,0xff026f4c) //101
NHSTUB(Feof_Fut                               ,0xff027138) //  1
NHSTUB(Fflush_Fut                             ,0xff027174) //  1
NHSTUB(Fgets_Fut                              ,0xff0270a0) //  6
NHSTUB(Fopen_Fut                              ,0xff026f0c) //101
NHSTUB(Fread_Fut                              ,0xff026ff8) //101
//NHSTUB(FreeMemory                           ,0xff311a68) //101
NHSTUB(FreeUncacheableMemory                  ,0xff02bcb8) //112
NHSTUB(Fseek_Fut                              ,0xff0270ec) //101
NHSTUB(Fwrite_Fut                             ,0xff02704c) //101
NHSTUB(GetBatteryTemperature                  ,0xff05e568) //102
NHSTUB(GetCCDTemperature                      ,0xff05e4f4) //102
NHSTUB(GetCurrentAvValue                      ,0xff184838) //102
NHSTUB(GetDrive_ClusterSize                   ,0xff06c38c) //  6
NHSTUB(GetDrive_FreeClusters                  ,0xff06c3e4) //  6
NHSTUB(GetDrive_TotalClusters                 ,0xff06c3bc) //  6
NHSTUB(GetFocusLensSubjectDistance            ,0xff182ac8) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff182f28) //  3
NHSTUB(GetImageFolder                         ,0xff15d3f0) //  6
NHSTUB(GetKbdState                            ,0xff057704) //109
NHSTUB(GetMemInfo                             ,0xff00a29c) //115
NHSTUB(GetOpticalTemperature                  ,0xff05e5dc) //102
NHSTUB(GetParameterData                       ,0xff1b9468) //101
NHSTUB(GetPropertyCase                        ,0xff08bf50) //102
NHSTUB(GetSystemTime                          ,0xff311ac8) //101
NHSTUB(GetVRAMHPixelsSize                     ,0xff0465b0) //102
NHSTUB(GetVRAMVPixelsSize                     ,0xff0465bc) //102
NHSTUB(GetZoomLensCurrentPoint                ,0xff187d3c) //102
NHSTUB(GetZoomLensCurrentPosition             ,0xff2fb1a4) //102
NHSTUB(GiveSemaphore                          ,0xff02b670) //112
NHSTUB(IsStrobeChargeCompleted                ,0xff0e2d14) //102
NHSTUB(LEDDrive                               ,0xff056a38) //101
NHSTUB(LocalTime                              ,0xff085a38) //115
NHSTUB(LockMainPower                          ,0xff093170) //103
//NHSTUB(Lseek                                ,0xff0276d4) //101
NHSTUB(MakeDirectory_Fut                      ,0xff026e44) //116
NHSTUB(MakeSDCardBootable                     ,0xff06c60c) //105
NHSTUB(MoveFocusLensToDistance                ,0xff3788e8) //102
NHSTUB(MoveIrisWithAv                         ,0xff30dad8) //102
NHSTUB(MoveZoomLensWithPoint                  ,0xff30e29c) //102
//NHSTUB(NewTaskShell                         ,0xff08b958) //101
NHSTUB(Open                                   ,0xff0273f0) //101
NHSTUB(PB2Rec                                 ,0xff096634) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff075cb0) //102
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff075c88) //102
NHSTUB(PT_PlaySound                           ,0xff080e14) //  6
NHSTUB(PostLogicalEventForNotPowerType        ,0xff090c88) //103
NHSTUB(PostLogicalEventToUI                   ,0xff090cd4) //103
NHSTUB(PutInNdFilter                          ,0xff376534) //102
NHSTUB(PutOutNdFilter                         ,0xff37656c) //102
NHSTUB(Read                                   ,0xff00ad58) //101
NHSTUB(ReadFastDir                            ,0xff2e70dc) //  6
NHSTUB(Rec2PB                                 ,0xff094d40) //104
NHSTUB(RefreshPhysicalScreen                  ,0xff0ac09c) //104
//NHSTUB(Remove                               ,0xff02762c) //  6
NHSTUB(RenameFile_Fut                         ,0xff026d3c) //116
NHSTUB(ScreenLock                             ,0xff0ad294) //  4
NHSTUB(ScreenUnlock                           ,0xff0ad2f8) //  3
NHSTUB(SetAE_ShutterSpeed                     ,0xff37b764) //102
NHSTUB(SetAutoShutdownTime                    ,0xff0931e4) //103
NHSTUB(SetCurrentCaptureModeType              ,0xff09ce48) //101
NHSTUB(SetFileAttributes                      ,0xff0278bc) //  6
NHSTUB(SetFileTimeStamp                       ,0xff027844) //  6
NHSTUB(SetLogicalEventActive                  ,0xff092eac) //101
NHSTUB(SetParameterData                       ,0xff1b93d8) //101
NHSTUB(SetPropertyCase                        ,0xff08be24) //102
NHSTUB(SetScriptMode                          ,0xff092efc) //101
NHSTUB(SleepTask                              ,0xff02b91c) //101
NHSTUB(TakeSemaphore                          ,0xff02b5a0) //101
NHSTUB(TurnOffBackLight                       ,0xff0a41f8) //104
NHSTUB(TurnOnBackLight                        ,0xff0a41e0) //104
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff1a9b08) //101
NHSTUB(UnlockAF                               ,0xff029044) //102
NHSTUB(UnlockMainPower                        ,0xff0930c4) //103
NHSTUB(VbattGet                               ,0xff02307c) //101
NHSTUB(Write                                  ,0xff02750c) //101
NHSTUB(WriteSDCard                            ,0xff171f04) //108
NHSTUB(_log                                   ,0xff3b6f80) //111
NHSTUB(_log10                                 ,0xff3b74c0) //112
NHSTUB(_pow                                   ,0xff3b7638) //114
NHSTUB(_sqrt                                  ,0xff3b951c) //  6
NHSTUB(add_ptp_handler                        ,0xff291e00) //  6
NHSTUB(apex2us                                ,0xff24dfd0) //  4
NHSTUB(close                                  ,0xff00abb4) //  6
NHSTUB(closedir                               ,0xff2e6f38) //  4
NHSTUB(err_init_task                          ,0xff005fd4) //111
NHSTUB(exmem_alloc                            ,0xff086a00) //101
NHSTUB(exmem_free                             ,0xff086a78) //101
NHSTUB(free                                   ,0xff004244) //112
NHSTUB(kbd_p1_f                               ,0xff024d94) //109
NHSTUB(kbd_p1_f_cont                          ,0xff024da0) //109
NHSTUB(kbd_p2_f                               ,0xff02457c) //109
NHSTUB(kbd_read_keys                          ,0xff024d18) //109
NHSTUB(kbd_read_keys_r2                       ,0xff056f04) //109
NHSTUB(lseek                                  ,0xff0276d4) //101
NHSTUB(malloc                                 ,0xff0041ec) //112
NHSTUB(memcmp                                 ,0xff010930) //101
NHSTUB(memcpy                                 ,0xff03158c) //101
NHSTUB(memset                                 ,0xff24cfd0) //101
NHSTUB(mkdir                                  ,0xff027954) //109
NHSTUB(mktime_ext                             ,0xff0ae10c) //  1
NHSTUB(open                                   ,0xff00ab04) //  6
NHSTUB(OpenFastDir                            ,0xff2e6f88) //  6
NHSTUB(qsort                                  ,0xff3639fc) //  6
NHSTUB(rand                                   ,0xff24d110) //  6
//NHSTUB(read                                 ,0xff00ad58) //101
NHSTUB(realloc                                ,0xff24d04c) //115
NHSTUB(reboot_fw_update                       ,0xff2ec578) //106
NHSTUB(set_control_event                      ,0xff092aa4) //111
NHSTUB(srand                                  ,0xff24d104) //  6
NHSTUB(stat                                   ,0xff02771c) //109
NHSTUB(strcat                                 ,0xff0ad8c4) //  1
NHSTUB(strchr                                 ,0xff0040b8) //  1
NHSTUB(strcmp                                 ,0xff0108ec) //101
NHSTUB(strcpy                                 ,0xff0108d4) //101
NHSTUB(strftime                               ,0xff0adb0c) //113
NHSTUB(strlen                                 ,0xff004104) //101
NHSTUB(strncmp                                ,0xff00406c) //  1
NHSTUB(strncpy                                ,0xff004030) //  1
NHSTUB(strrchr                                ,0xff0040dc) //  1
NHSTUB(strtol                                 ,0xff03188c) //101
NHSTUB(strtolx                                ,0xff031690) //109
   DEF(task_CaptSeq                           ,0xff078bf0) //110
   DEF(task_ExpDrv                            ,0xff0c5e98) //110
   DEF(task_InitFileModules                   ,0xff096fcc) //110
   DEF(task_MovieRecord                       ,0xff18d9cc) //110
   DEF(task_PhySw                             ,0xff0248a8) //110
   DEF(task_RotaryEncoder                     ,0xff0579ac) //110
NHSTUB(time                                   ,0xff086014) //109
NHSTUB(vsprintf                               ,0xff010894) //115
//NHSTUB(write                                ,0xff02750c) //101
//NHSTUB(EngDrvIn                             ,0xff025c54) //102
//NHSTUB(EngDrvOut                            ,0xff025c3c) //102
//NHSTUB(EngDrvRead                           ,0xff025c5c) //102
//NHSTUB(EngDrvBits                           ,0xff025c70) //102
//NHSTUB(GetSDProtect                         ,0xff024cdc) //101
//NHSTUB(StartRecModeMenu                     ,0xff08ca78) //102
//NHSTUB(DispCon_ShowBitmapColorBar           ,0xff051488) //102
//NHSTUB(ResetZoomLens                        ,0xff30e1f0) //102
//NHSTUB(ResetFocusLens                       ,0xff30cd84) //102
//NHSTUB(NR_GetDarkSubType                    ,0xff195ccc) //102
//NHSTUB(NR_SetDarkSubType                    ,0xff195c04) //102
//NHSTUB(SavePaletteData                      ,0xff37dc10) //102
//NHSTUB(GUISrv_StartGUISystem                ,0xff0ab8b4) //101
