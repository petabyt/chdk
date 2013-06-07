// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R47 (DRYOS version 2.3, release #0047)
//   Firmware Ver GM1.00A
//   Canon PowerShot SX220 HS

// Values for makefile.inc
//   PLATFORMOSVER = 47
//   PLATFORMID = 12844 (0x322c) // Found @ 0xfff40040
//   MAXRAMADDR = 0x07ffffff
//   KEYSYS = d4c                // Found @ 0xffff3610
//   NEED_ENCODED_DISKBOOT = 6   // Found @ 0xffff3620

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NHSTUB(kbd_pwr_off                          ,0xff0565ac) //  2 60%    *** != 0x00000000
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0x00000000
//NHSTUB(write                                ,0xff0270d8) //101        *** != 0xff00adb8

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff0953cc -> ff091c94 -> ff1b2368 -> ff318d34 -> ff48a450
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x000357a8) // Found @0xff024960
DEF(physw_run                               ,0x00001c40) // Found @0xff0244f4
DEF(physw_sleep_delay                       ,0x00001c48) // Found @0xff0244f4
DEF(levent_table                            ,0xff41646c) // Found @0xff41646c
DEF(FlashParamsTable                        ,0xff48a69c) // Found @0xff48a69c
DEF(movie_status                            ,0x00008594) // Found @0xff187064
DEF(full_screen_refresh                     ,0x0000b35c) // Found @0xff23d628
DEF(canon_menu_active                       ,0x00004274) // Found @0xff08b3f4
DEF(canon_shoot_menu_active                 ,0x000098e9) // Found @0xff1ce4f8
DEF(playrec_mode                            ,0x00003fa8) // Found @0xff07d778
DEF(zoom_status                             ,0x0000f5c4) // Found @0xff31c3ec
DEF(some_flag_for_af_scan                   ,0x00008998) // Found @0xff18b738
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 3 int value(s), the first is the zoom focus length.
// there are 126 entries in the table - set NUM_FL to 126
DEF(focus_len_table                         ,0xfff4a3dc) // Found @0xfff4a3dc
DEF(zoom_busy                               ,0x000084bc) // Found @0xff1821e8
DEF(focus_busy                              ,0x00008338) // Found @0xff17c768
//DEF(recreview_hold                          ,0x00004d80) // Found @0xff09e130, ** != ** stubs_min = 0x000094c4 (0x93D4+0xF0)
DEF(palette_control                         ,0x0000b35c) // Found @0xff23d5a4
DEF(active_palette_buffer                   ,0x0000b364) // Found @0xff23d5a8
DEF(palette_buffer                          ,0x000cae40) // Found @0xff23da80
DEF(bitmap_buffer                           ,0x0000b39c) // Found @0xff242700
DEF(active_bitmap_buffer                    ,0x0000b394) // Found @0xff242704
DEF(viewport_buffers                        ,0xff3b06b4) // Found @0xff0438ac
DEF(active_viewport_buffer                  ,0x00002104) // Found @0xff04356c

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x40471000; }             // Found @0xff050f20
//void *vid_get_viewport_fb()      { return (void*)0x405d7980; }             // Found @0xff371e8c
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x3c70+0x58)); } // Found @0xff06d2c8 & 0xff06d300
//char *camera_jpeg_count_str()    { return (char*)0x000ca790; }             // Found @0xff2327fc
//long hook_raw_size()             { return 0x0123eaf0; }                    // Found @0xff3753a0
//int get_flash_params_count(void) { return 0xa0; }                          // Found @0xff1b33a0

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xff3b189c, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x04000000 // Found @0xff3b18cc, levent 0x902
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_DISPLAY         ,0x00000800 }, // Found @0xff3b180c, levent 0x0a
//    { 0, KEY_UP              ,0x00001000 }, // Found @0xff3b1814, levent 0x04
//    { 0, KEY_RIGHT           ,0x00004000 }, // Found @0xff3b1824, levent 0x07
//    { 0, KEY_SET             ,0x00010000 }, // Found @0xff3b1834, levent 0x08
//    { 0, KEY_DOWN            ,0x00020000 }, // Found @0xff3b183c, levent 0x05
//    { 0, KEY_MENU            ,0x00040000 }, // Found @0xff3b1844, levent 0x09
//    { 0, KEY_VIDEO           ,0x00080000 }, // Found @0xff3b184c, levent 0x12
//    { 1, KEY_PLAYBACK        ,0x00200000 }, // Found @0xff3b1854, levent 0x601
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000002 }, // Found @0xff3b1864, levent 0x01
//    { 2, KEY_LEFT            ,0x00000100 }, // Found @0xff3b1874, levent 0x06
//    { 2, KEY_POWER           ,0x00000800 }, // Found @0xff3b187c, levent 0x600
//    { 2, KEY_SHOOT_FULL      ,0x00002002 }, // Found @0xff3b1864, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00002000 }, // Found @0xff3b1884, levent 0x00
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
DEF(ctypes, 0xff3aff12)

// For capt_seq.c
DEF(_nrflag,0x89dc) // Found @ ff190524 (0x89d4) & ff190560 (+0x08)
//static long *nrflag = (long*)(0x89d4+0x08);  // Found @ ff190524 & ff190560
//#define NR_AUTO (0)                          // have to explictly reset value back to 0 to enable auto

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
//NHSTUB(CreateJumptable                      ,0xff37556c) //  1
//NHSTUB(_uartr_req                           ,0xff00fdd0) //111
//NHSTUB(AllocateMemory                       ,0xff3075d0) //101
NHSTUB(AllocateUncacheableMemory              ,0xff02b844) //112
NHSTUB(Close                                  ,0xff027084) //101
NHSTUB(CreateTask                             ,0xff00e9b0) //101
NHSTUB(DebugAssert                            ,0xff00ec88) //111
NHSTUB(DeleteDirectory_Fut                    ,0xff026a80) //116
NHSTUB(DeleteFile_Fut                         ,0xff02699c) //112
NHSTUB(DoAFLock                               ,0xff028bd8) //102
NHSTUB(EnterToCompensationEVF                 ,0xff028e74) //104
NHSTUB(ExecuteEventProcedure                  ,0xff086bdc) //104
NHSTUB(ExitFromCompensationEVF                ,0xff028eb8) //104
NHSTUB(ExitTask                               ,0xff00ec40) //101
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff037fe4) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff0380bc) //104
NHSTUB(Fclose_Fut                             ,0xff026b18) //101
NHSTUB(Feof_Fut                               ,0xff026d04) //  1
NHSTUB(Fflush_Fut                             ,0xff026d40) //  1
NHSTUB(Fgets_Fut                              ,0xff026c6c) //  6
NHSTUB(Fopen_Fut                              ,0xff026ad8) //101
NHSTUB(Fread_Fut                              ,0xff026bc4) //101
//NHSTUB(FreeMemory                           ,0xff3075c8) //101
NHSTUB(FreeUncacheableMemory                  ,0xff02b884) //112
NHSTUB(Fseek_Fut                              ,0xff026cb8) //101
NHSTUB(Fwrite_Fut                             ,0xff026c18) //101
NHSTUB(GetBatteryTemperature                  ,0xff05d010) //102
NHSTUB(GetCCDTemperature                      ,0xff05cf9c) //102
NHSTUB(GetCurrentAvValue                      ,0xff17f15c) //102
NHSTUB(GetDrive_ClusterSize                   ,0xff06adbc) //  6
NHSTUB(GetDrive_FreeClusters                  ,0xff06ae14) //  6
NHSTUB(GetDrive_TotalClusters                 ,0xff06adec) //  6
NHSTUB(GetFocusLensSubjectDistance            ,0xff17d3ec) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff17d84c) //  3
NHSTUB(GetImageFolder                         ,0xff1598b8) //  6
NHSTUB(GetKbdState                            ,0xff056474) //109
NHSTUB(GetMemInfo                             ,0xff00a29c) //115
NHSTUB(GetOpticalTemperature                  ,0xff05d084) //102
NHSTUB(GetParameterData                       ,0xff1b3360) //101
NHSTUB(GetPropertyCase                        ,0xff08a944) //102
NHSTUB(GetSystemTime                          ,0xff307628) //101
NHSTUB(GetVRAMHPixelsSize                     ,0xff04600c) //102
NHSTUB(GetVRAMVPixelsSize                     ,0xff046018) //102
NHSTUB(GetZoomLensCurrentPoint                ,0xff182660) //102
NHSTUB(GetZoomLensCurrentPosition             ,0xff2f14cc) //102
NHSTUB(GiveSemaphore                          ,0xff02b23c) //112
NHSTUB(IsStrobeChargeCompleted                ,0xff0e0cd0) //102
NHSTUB(LEDDrive                               ,0xff0557c0) //101
NHSTUB(LocalTime                              ,0xff08446c) //115
NHSTUB(LockMainPower                          ,0xff091884) //103
//NHSTUB(Lseek                                ,0xff0272a0) //101
NHSTUB(MakeDirectory_Fut                      ,0xff026a10) //116
NHSTUB(MakeSDCardBootable                     ,0xff06b04c) //105
NHSTUB(MoveFocusLensToDistance                ,0xff36e188) //102
NHSTUB(MoveIrisWithAv                         ,0xff303638) //102
NHSTUB(MoveZoomLensWithPoint                  ,0xff303dfc) //102
//NHSTUB(NewTaskShell                         ,0xff08a38c) //101
NHSTUB(Open                                   ,0xff026fbc) //101
NHSTUB(PB2Rec                                 ,0xff094a5c) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff0746e8) //102
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff0746c0) //102
NHSTUB(PT_PlaySound                           ,0xff07f848) //  6
NHSTUB(PostLogicalEventForNotPowerType        ,0xff08f3a8) //103
NHSTUB(PostLogicalEventToUI                   ,0xff08f3f4) //103
NHSTUB(PutInNdFilter                          ,0xff36bdd4) //102
NHSTUB(PutOutNdFilter                         ,0xff36be0c) //102
NHSTUB(Read                                   ,0xff00ad58) //101
NHSTUB(ReadFastDir                            ,0xff2dd404) //  6
NHSTUB(Rec2PB                                 ,0xff0931fc) //104
NHSTUB(RefreshPhysicalScreen                  ,0xff0aa058) //104
//NHSTUB(Remove                               ,0xff0271f8) //  6
NHSTUB(RenameFile_Fut                         ,0xff026908) //116
NHSTUB(Restart                                ,0xff02d058) //106
NHSTUB(ScreenLock                             ,0xff0ab250) //  4
NHSTUB(ScreenUnlock                           ,0xff0ab2b4) //  3
NHSTUB(SetAE_ShutterSpeed                     ,0xff371004) //102
NHSTUB(SetAutoShutdownTime                    ,0xff0918f8) //103
NHSTUB(SetCurrentCaptureModeType              ,0xff09ae08) //101
NHSTUB(SetFileAttributes                      ,0xff027488) //  6
NHSTUB(SetFileTimeStamp                       ,0xff027410) //  6
NHSTUB(SetLogicalEventActive                  ,0xff0915c0) //101
NHSTUB(SetParameterData                       ,0xff1b32d0) //101
NHSTUB(SetPropertyCase                        ,0xff08a828) //102
NHSTUB(SetScriptMode                          ,0xff091610) //101
NHSTUB(SleepTask                              ,0xff02b4e8) //101
NHSTUB(TakeSemaphore                          ,0xff02b16c) //101
NHSTUB(TurnOffBackLight                       ,0xff0a21b8) //104
NHSTUB(TurnOnBackLight                        ,0xff0a21a0) //104
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff1a4414) //101
NHSTUB(UnlockAF                               ,0xff028c10) //102
NHSTUB(UnlockMainPower                        ,0xff0917d8) //103
NHSTUB(VbattGet                               ,0xff023040) //101
NHSTUB(Write                                  ,0xff0270d8) //101
NHSTUB(WriteSDCard                            ,0xff16c828) //108
NHSTUB(_log                                   ,0xff3ac778) //111
NHSTUB(_log10                                 ,0xff3accb8) //112
NHSTUB(_pow                                   ,0xff3ace30) //114
NHSTUB(_sqrt                                  ,0xff3aed14) //  6
NHSTUB(add_ptp_handler                        ,0xff28aa1c) //  6
NHSTUB(apex2us                                ,0xff246bec) //  4
NHSTUB(close                                  ,0xff00abb4) //  6
NHSTUB(closedir                               ,0xff2dd260) //  4
NHSTUB(err_init_task                          ,0xff005fd4) //111
NHSTUB(exmem_alloc                            ,0xff085434) //101
NHSTUB(exmem_free                             ,0xff0854ac) //101
NHSTUB(free                                   ,0xff004244) //112
NHSTUB(kbd_p1_f                               ,0xff0249dc) //109
NHSTUB(kbd_p1_f_cont                          ,0xff0249e8) //109
NHSTUB(kbd_p2_f                               ,0xff0241c4) //109
NHSTUB(kbd_read_keys                          ,0xff024960) //109
NHSTUB(kbd_read_keys_r2                       ,0xff055c78) //109
NHSTUB(lseek                                  ,0xff0272a0) //101
NHSTUB(malloc                                 ,0xff0041ec) //112
NHSTUB(memcmp                                 ,0xff0108f4) //101
NHSTUB(memcpy                                 ,0xff030fec) //101
NHSTUB(memset                                 ,0xff245bec) //101
NHSTUB(mkdir                                  ,0xff027520) //109
NHSTUB(mktime_ext                             ,0xff0ac0c8) //  1
NHSTUB(open                                   ,0xff00ab04) //  6
NHSTUB(OpenFastDir                            ,0xff2dd2b0) //  6
NHSTUB(qsort                                  ,0xff359478) //  6
NHSTUB(rand                                   ,0xff245d2c) //  6
//NHSTUB(read                                 ,0xff00ad58) //101
NHSTUB(realloc                                ,0xff245c68) //115
NHSTUB(reboot_fw_update                       ,0xff2e28a0) //106
NHSTUB(set_control_event                      ,0xff0911b8) //111
NHSTUB(srand                                  ,0xff245d20) //  6
NHSTUB(stat                                   ,0xff0272e8) //109
NHSTUB(strcat                                 ,0xff0ab880) //  1
NHSTUB(strchr                                 ,0xff0040b8) //  1
NHSTUB(strcmp                                 ,0xff0108b0) //101
NHSTUB(strcpy                                 ,0xff010898) //101
NHSTUB(strftime                               ,0xff0abac8) //113
NHSTUB(strlen                                 ,0xff004104) //101
NHSTUB(strncmp                                ,0xff00406c) //  1
NHSTUB(strncpy                                ,0xff004030) //  1
NHSTUB(strrchr                                ,0xff0040dc) //  1
NHSTUB(strtol                                 ,0xff0312ec) //101
NHSTUB(strtolx                                ,0xff0310f0) //109
   DEF(task_CaptSeq                           ,0xff077628) //110
   DEF(task_ExpDrv                            ,0xff0c3e54) //110
   DEF(task_InitFileModules                   ,0xff095240) //110
   DEF(task_MovieRecord                       ,0xff1882f0) //110
   DEF(task_PhySw                             ,0xff0244f0) //110
   DEF(task_RotaryEncoder                     ,0xff05671c) //110
NHSTUB(time                                   ,0xff084a48) //109
NHSTUB(vsprintf                               ,0xff010858) //115
//NHSTUB(EngDrvIn                             ,0xff025820) //102
//NHSTUB(EngDrvOut                            ,0xff025808) //102
//NHSTUB(EngDrvRead                           ,0xff025828) //102
//NHSTUB(EngDrvBits                           ,0xff02583c) //102
//NHSTUB(GetSDProtect                         ,0xff024924) //101
//NHSTUB(StartRecModeMenu                     ,0xff08b3f0) //102
//NHSTUB(DispCon_ShowBitmapColorBar           ,0xff050edc) //102
//NHSTUB(ResetZoomLens                        ,0xff303d50) //102
//NHSTUB(ResetFocusLens                       ,0xff3028e4) //102
//NHSTUB(NR_GetDarkSubType                    ,0xff1905e4) //102
//NHSTUB(NR_SetDarkSubType                    ,0xff19051c) //102
//NHSTUB(SavePaletteData                      ,0xff3734b0) //102
//NHSTUB(GUISrv_StartGUISystem                ,0xff0a9870) //101
