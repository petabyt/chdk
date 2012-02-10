// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R47 (DRYOS version 2.3, release #0047)
//   Firmware Ver GM1.01A
//   Canon PowerShot SX220 HS

// Values for makefile.inc
//   PLATFORMID = 12844 (0x322c) // Found @ 0xfff40040
//   MAXRAMADDR = 0x07ffffff
//   KEYSYS = d4c                // Found @ 0xffff3610
//   NEED_ENCODED_DISKBOOT = 6   // Found @ 0xffff3620

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NSTUB(kbd_pwr_off                           ,0xff0565ac) //  2 60%    *** != 0x00000000
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0x00000000
//NSTUB(write                                 ,0xff0270d8) //101        *** != 0xff00adb8

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff0953cc -> ff091c94 -> ff1b2368 -> ff318d4c -> ff48a468
// Current modemap entry not found in firmware - MODE_SCN_MONOCHROME       8754
// Current modemap entry not found in firmware - MODE_SCN_TOY_CAMERA       8751
// Current modemap entry not found in firmware - MODE_SCN_SUPER_VIVID      8742
// Current modemap entry not found in firmware - MODE_SCN_MINIATURE        8748
// Current modemap entry not found in firmware - MODE_SCN_FISHEYE          8747
// Current modemap entry not found in firmware - MODE_SCN_POSTER_EFFECT    8743
// Current modemap entry not found in firmware - MODE_SCN_COLOR_SWAP       8734
// Current modemap entry not found in firmware - MODE_SCN_COLOR_ACCENT     8733

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x000357a8) // Found @0xff024960
DEF(physw_run                               ,0x00001c40) // Found @0xff0244f4
DEF(levent_table                            ,0xff416484) // Found @0xff416484
DEF(FlashParamsTable                        ,0xff48a6b4) // Found @0xff48a6b4
DEF(movie_status                            ,0x00008594) // Found @0xff187064
DEF(full_screen_refresh                     ,0x0000b35c) // Found @0xff23d628
DEF(canon_menu_active                       ,0x00004274) // Found @0xff08b3f4
DEF(canon_shoot_menu_active                 ,0x000098e9) // Found @0xff1ce4f8
DEF(playrec_mode                            ,0x00003fa8) // Found @0xff07d778
//DEF(zoom_status                             ,0x0000f5c4) // Found @0xff31c404, ** != ** stubs_min = 0x0000f5a4 (0xF5A4)
DEF(some_flag_for_af_scan                   ,0x00008998) // Found @0xff18b738
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 3 int value(s), the first is the zoom focus length.
// there are 126 entries in the table - set NUM_FL to 126
DEF(focus_len_table                         ,0xfff4a3dc) // Found @0xfff4a3dc
DEF(zoom_busy                               ,0x000084bc) // Found @0xff1821e8
DEF(focus_busy                              ,0x00008338) // Found @0xff17c768
//DEF(recreview_hold                          ,0x00004d80) // Found @0xff09e130, ** != ** stubs_min = 0x000094c4 (0x93D4+0xF0)

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x40471000; }             // Found @0xff050f20
//void *vid_get_viewport_fb()      { return (void*)0x405d7980; }             // Found @0xff371ea4
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x3c70+0x58)); } // Found @0xff06d2c8 & 0xff06d300
//char *camera_jpeg_count_str()    { return (char*)0x000ca790; }             // Found @0xff2327fc
//long hook_raw_size()             { return 0x0123eaf0; }                    // Found @0xff3753b8
//int get_flash_params_count(void) { return 0xa0; }                          // Found @0xff1b33a0

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xff3b18b4, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x04000000 // Found @0xff3b18e4, levent 0x902
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_DISPLAY         ,0x00000800 }, // Found @0xff3b1824, levent 0x0a
//    { 0, KEY_UP              ,0x00001000 }, // Found @0xff3b182c, levent 0x04
//    { 0, KEY_RIGHT           ,0x00004000 }, // Found @0xff3b183c, levent 0x07
//    { 0, KEY_SET             ,0x00010000 }, // Found @0xff3b184c, levent 0x08
//    { 0, KEY_DOWN            ,0x00020000 }, // Found @0xff3b1854, levent 0x05
//    { 0, KEY_MENU            ,0x00040000 }, // Found @0xff3b185c, levent 0x09
//    { 2, KEY_LEFT            ,0x00000100 }, // Found @0xff3b188c, levent 0x06
//    { 2, KEY_SHOOT_FULL      ,0x00002002 }, // Found @0xff3b187c, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00002000 }, // Found @0xff3b189c, levent 0x00
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000002 }, // Found @0xff3b187c, levent 0x01
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#define CAM_RAW_ROWPIX    4168 // Found @0xff15290c
//#define CAM_RAW_ROWS      3060 // Found @0xff152918
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff02b88c

// Misc stuff
DEF(ctypes, 0xff3aff2a)

// For capt_seq.c
//static long *nrflag = (long*)(0x89d4+0x08);  // Found @ ff1903bc & ff190428
//#define NR_AUTO (0)                          // have to explictly reset value back to 0 to enable auto

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NSTUB(AllocateMemory                          ,0xff3075e8) //101
NSTUB(AllocateUncacheableMemory               ,0xff02b844) //112
NSTUB(Close                                   ,0xff027084) //101
NSTUB(CreateTask                              ,0xff00e9b0) //101
NSTUB(DebugAssert                             ,0xff00ec88) //111
NSTUB(DeleteDirectory_Fut                     ,0xff026a80) //  1
NSTUB(DeleteFile_Fut                          ,0xff02699c) //112
NSTUB(DoAFLock                                ,0xff028bd8) //102
NSTUB(EnterToCompensationEVF                  ,0xff028e74) //104
NSTUB(ExecuteEventProcedure                   ,0xff086bdc) //  1
NSTUB(ExitFromCompensationEVF                 ,0xff028eb8) //104
NSTUB(ExitTask                                ,0xff00ec40) //101
NSTUB(ExpCtrlTool_StartContiAE                ,0xff037fe4) //104
NSTUB(ExpCtrlTool_StopContiAE                 ,0xff0380bc) //104
NSTUB(Fclose_Fut                              ,0xff026b18) //101
NSTUB(Feof_Fut                                ,0xff026d04) //  1
NSTUB(Fflush_Fut                              ,0xff026d40) //  1
NSTUB(Fgets_Fut                               ,0xff026c6c) //  6
NSTUB(Fopen_Fut                               ,0xff026ad8) //101
NSTUB(Fread_Fut                               ,0xff026bc4) //101
NSTUB(FreeMemory                              ,0xff3075e0) //101
NSTUB(FreeUncacheableMemory                   ,0xff02b884) //112
NSTUB(Fseek_Fut                               ,0xff026cb8) //101
NSTUB(Fwrite_Fut                              ,0xff026c18) //101
NSTUB(GetBatteryTemperature                   ,0xff05d010) //102
NSTUB(GetCCDTemperature                       ,0xff05cf9c) //102
NSTUB(GetCurrentAvValue                       ,0xff17f15c) //102
NSTUB(GetDrive_ClusterSize                    ,0xff06adbc) //  6
NSTUB(GetDrive_FreeClusters                   ,0xff06ae14) //  6
NSTUB(GetDrive_TotalClusters                  ,0xff06adec) //  6
NSTUB(GetFocusLensSubjectDistance             ,0xff17d3ec) //102
NSTUB(GetFocusLensSubjectDistanceFromLens     ,0xff17d84c) //  3
NSTUB(GetImageFolder                          ,0xff1598b8) //  6
NSTUB(GetKbdState                             ,0xff056474) //109
NSTUB(GetMemInfo                              ,0xff00a29c) //  3
NSTUB(GetOpticalTemperature                   ,0xff05d084) //102
NSTUB(GetParameterData                        ,0xff1b3360) //101
NSTUB(GetPropertyCase                         ,0xff08a944) //102
NSTUB(GetSystemTime                           ,0xff307640) //101
NSTUB(GetZoomLensCurrentPoint                 ,0xff182660) //102
NSTUB(GetZoomLensCurrentPosition              ,0xff2f14cc) //102
NSTUB(GiveSemaphore                           ,0xff02b23c) //112
NSTUB(IsStrobeChargeCompleted                 ,0xff0e0cd0) //102
NSTUB(LEDDrive                                ,0xff0557c0) //101
NSTUB(LocalTime                               ,0xff08446c) //  6
NSTUB(LockMainPower                           ,0xff091884) //103
NSTUB(Lseek                                   ,0xff0272a0) //101
NSTUB(MakeDirectory_Fut                       ,0xff026a10) //  6
NSTUB(MakeSDCardBootable                      ,0xff06b04c) //105
NSTUB(MoveFocusLensToDistance                 ,0xff36e1a0) //102
NSTUB(MoveIrisWithAv                          ,0xff303650) //102
NSTUB(MoveZoomLensWithPoint                   ,0xff303e14) //102
NSTUB(NewTaskShell                            ,0xff08a38c) //101
NSTUB(Open                                    ,0xff026fbc) //101
NSTUB(PB2Rec                                  ,0xff094a5c) //104
NSTUB(PT_MoveDigitalZoomToWide                ,0xff0746e8) //102
NSTUB(PT_MoveOpticalZoomAt                    ,0xff0746c0) //102
NSTUB(PT_PlaySound                            ,0xff07f848) //  6
NSTUB(PostLogicalEventForNotPowerType         ,0xff08f3a8) //103
NSTUB(PostLogicalEventToUI                    ,0xff08f3f4) //103
NSTUB(PutInNdFilter                           ,0xff36bdec) //102
NSTUB(PutOutNdFilter                          ,0xff36be24) //102
NSTUB(Read                                    ,0xff00ad58) //101
NSTUB(ReadFastDir                             ,0xff2dd404) //  6
NSTUB(Rec2PB                                  ,0xff0931fc) //104
NSTUB(RefreshPhysicalScreen                   ,0xff0aa058) //104
NSTUB(Remove                                  ,0xff0271f8) //  6
NSTUB(RenameFile_Fut                          ,0xff026908) //  6
NSTUB(Restart                                 ,0xff02d058) //106
NSTUB(ScreenLock                              ,0xff0ab250) //  4
NSTUB(ScreenUnlock                            ,0xff0ab2b4) //  3
NSTUB(SetAE_ShutterSpeed                      ,0xff37101c) //102
NSTUB(SetAutoShutdownTime                     ,0xff0918f8) //103
NSTUB(SetCurrentCaptureModeType               ,0xff09ae08) //101
NSTUB(SetFileAttributes                       ,0xff027488) //  6
NSTUB(SetFileTimeStamp                        ,0xff027410) //  6
NSTUB(SetLogicalEventActive                   ,0xff0915c0) //101
NSTUB(SetParameterData                        ,0xff1b32d0) //101
NSTUB(SetPropertyCase                         ,0xff08a828) //102
NSTUB(SetScriptMode                           ,0xff091610) //101
NSTUB(SleepTask                               ,0xff02b4e8) //101
NSTUB(TakeSemaphore                           ,0xff02b16c) //101
NSTUB(TurnOffBackLight                        ,0xff0a21b8) //104
NSTUB(TurnOnBackLight                         ,0xff0a21a0) //104
NSTUB(UIFS_WriteFirmInfoToFile                ,0xff1a4414) //101
NSTUB(UnlockAF                                ,0xff028c10) //102
NSTUB(UnlockMainPower                         ,0xff0917d8) //103
NSTUB(VbattGet                                ,0xff023040) //101
NSTUB(Write                                   ,0xff0270d8) //101
NSTUB(WriteSDCard                             ,0xff16c828) //108
NSTUB(_log                                    ,0xff3ac790) //111
NSTUB(_log10                                  ,0xff3accd0) //112
NSTUB(_pow                                    ,0xff3ace48) //114
NSTUB(_sqrt                                   ,0xff3aed2c) //  6
NSTUB(add_ptp_handler                         ,0xff28aa1c) //  6
NSTUB(apex2us                                 ,0xff246bec) //  4
NSTUB(close                                   ,0xff00abb4) //  6
NSTUB(closedir                                ,0xff2dd260) //  4
NSTUB(err_init_task                           ,0xff005fd4) //  4
NSTUB(exmem_alloc                             ,0xff085434) //101
NSTUB(free                                    ,0xff004244) //112
NSTUB(kbd_p1_f                                ,0xff0249dc) //109
NSTUB(kbd_p1_f_cont                           ,0xff0249e8) //109
NSTUB(kbd_p2_f                                ,0xff0241c4) //109
NSTUB(kbd_read_keys                           ,0xff024960) //109
NSTUB(kbd_read_keys_r2                        ,0xff055c78) //109
NSTUB(lseek                                   ,0xff0272a0) //101
NSTUB(malloc                                  ,0xff0041ec) //112
NSTUB(memcmp                                  ,0xff0108f4) //101
NSTUB(memcpy                                  ,0xff030fec) //101
NSTUB(memset                                  ,0xff245bec) //101
NSTUB(mkdir                                   ,0xff027520) //  6
NSTUB(mktime_ext                              ,0xff0ac0c8) //  1
NSTUB(open                                    ,0xff00ab04) //  6
NSTUB(opendir                                 ,0xff2dd2b0) //  6
NSTUB(openfastdir                             ,0xff2dd2b0) //  6
NSTUB(qsort                                   ,0xff359490) //  6
NSTUB(rand                                    ,0xff245d2c) //  6
NSTUB(read                                    ,0xff00ad58) //101
NSTUB(reboot_fw_update                        ,0xff2e28a0) //  6
NSTUB(rename                                  ,0xff026908) //  6
NSTUB(set_control_event                       ,0xff0911b8) //111
NSTUB(srand                                   ,0xff245d20) //  6
NSTUB(stat                                    ,0xff0272e8) //  3
NSTUB(strcat                                  ,0xff0ab880) //  1
NSTUB(strchr                                  ,0xff0040b8) //  1
NSTUB(strcmp                                  ,0xff0108b0) //101
NSTUB(strcpy                                  ,0xff010898) //101
NSTUB(strftime                                ,0xff0abac8) //113
NSTUB(strlen                                  ,0xff004104) //101
NSTUB(strncmp                                 ,0xff00406c) //  1
NSTUB(strncpy                                 ,0xff004030) //  1
NSTUB(strrchr                                 ,0xff0040dc) //  1
NSTUB(strtol                                  ,0xff0312ec) //101
NSTUB(strtolx                                 ,0xff0310f0) //109
  DEF(task_CaptSeq                            ,0xff077628) //110
  DEF(task_ExpDrv                             ,0xff0c3e54) //110
  DEF(task_InitFileModules                    ,0xff095240) //110
  DEF(task_MovieRecord                        ,0xff1882f0) //110
  DEF(task_PhySw                              ,0xff0244f0) //110
  DEF(task_RotaryEncoder                      ,0xff05671c) //110
NSTUB(time                                    ,0xff084a48) //  6
NSTUB(vsprintf                                ,0xff010858) //  6
