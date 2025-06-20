// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R43 (DRYOS version 2.3, release #0043)
//   Firmware Ver GM1.00B
//   Canon IXUS 105

// Values for makefile.inc
//   PLATFORMOSVER = 43
//   PLATFORMID = 12788 (0x31f4) // Found @ 0xfffe0130
//   MAXRAMADDR = 0x03ffffff
//   KEYSYS = d4a                // Found @ 0xffff1c18
//   NEED_ENCODED_DISKBOOT = 4   // Found @ 0xffff1c28

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NHSTUB(kbd_pwr_off                          ,0xffc47e04) //  2 64%    *** != 0x00000000
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ffc77d1c -> ffc748ac -> ffd3eec8 -> ffe29f08 -> ffef9ee0
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x0002f100) // Found @0xffc24574
DEF(physw_run                               ,0x00001c2c) // Found @0xffc241d8
DEF(physw_sleep_delay                       ,0x00001c2a) // Found @0xffc241d8
DEF(levent_table                            ,0xffec030c) // Found @0xffec030c
DEF(FlashParamsTable                        ,0xffefa0d0) // Found @0xffefa0d0
DEF(movie_status                            ,0x00005780) // Found @0xffd1bb6c
DEF(full_screen_refresh                     ,0x000076e8) // Found @0xffd8c524
DEF(canon_menu_active                       ,0x00002be0) // Found @0xffc7174c
DEF(canon_shoot_menu_active                 ,0x000068c9) // Found @0xffd50768
DEF(playrec_mode                            ,0x0000292c) // Found @0xffc641b0
DEF(zoom_status                             ,0x00009f88) // Found @0xffe2c248
DEF(some_flag_for_af_scan                   ,0x00005b28) // Found @0xffd1e4d4
DEF(zoom_busy                               ,0x000056e0) // Found @0xffd17b74
DEF(focus_busy                              ,0x00005584) // Found @0xffd13508
DEF(recreview_hold                          ,0x000031d0) // Found @0xffc7d1d4
DEF(viewport_buffers                        ,0xffeaec48) // Found @0xffcbde7c
DEF(active_viewport_buffer                  ,0x00004270) // Found @0xffcbdd74

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x403f1000; }             // Found @0xffc43628
//void *vid_get_viewport_fb()      { return (void*)0x40507700; }             // Found @0xffe780c4
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x2670+0x58)); } // Found @0xffc571a4 & 0xffc571d8
//char *camera_jpeg_count_str()    { return (char*)0x00077fdc; }             // Found @0xffd83af4
//long hook_raw_size()             { return 0x011e4ee0; }                    // Found @0xffe7b47c
//int get_flash_params_count(void) { return 0x94; }                          // Found @0xffd3ff84

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffea7b4c, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x00040000 // Found @0xffea7b58, levent 0x902
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_PLAYBACK        ,0x00000100 }, // Found @0xffea7a74, levent 0x601
//    { 0, KEY_POWER           ,0x00000200 }, // Found @0xffea7a80, levent 0x600
//    { 0, KEY_MENU            ,0x00000400 }, // Found @0xffea7a8c, levent 0x09
//    { 1, KEY_LEFT            ,0x08000000 }, // Found @0xffea7ac8, levent 0x06
//    { 1, KEY_ZOOM_OUT        ,0x10000000 }, // Found @0xffea7ad4, levent 0x03
//    { 1, KEY_ZOOM_IN         ,0x20000000 }, // Found @0xffea7ae0, levent 0x02
//    { 2, KEY_SET             ,0x00000001 }, // Found @0xffea7aec, levent 0x08
//    { 2, KEY_DOWN            ,0x00000002 }, // Found @0xffea7af8, levent 0x05
//    { 2, KEY_DISPLAY         ,0x00000008 }, // Found @0xffea7b04, levent 0x0a
//    { 2, KEY_RIGHT           ,0x00000400 }, // Found @0xffea7b10, levent 0x07
//    { 2, KEY_UP              ,0x00000800 }, // Found @0xffea7b1c, levent 0x04
//    { 2, KEY_SHOOT_FULL      ,0x00005000 }, // Found @0xffea7b28, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00004000 }, // Found @0xffea7b34, levent 0x00
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00001000 }, // Found @0xffea7b28, levent 0x01
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_RAW_ROWPIX    4104 // Found @0xffcf4d74
//#define CAM_RAW_ROWS      3048 // Found @0xffcf4d80
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xffc29e80

// Misc stuff
DEF(ctypes, 0xffea6712)

// For capt_seq.c
DEF(_nrflag,0x5b08) // Found @ ffd203a4 (0x5b10) & ffd203c4 (-0x08)
//static long *nrflag = (long*)(0x5b10-0x08);  // Found @ ffd203a4 & ffd203c0

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
//NHSTUB(CreateJumptable                      ,0xffe7beb4) //  1
//NHSTUB(_uartr_req                           ,0xffc0fbe8) //111
//NHSTUB(AllocateMemory                       ,0xffe1bd20) //101
NHSTUB(AllocateUncacheableMemory              ,0xffc29e3c) //112
NHSTUB(Close                                  ,0xffc26b54) //101
NHSTUB(CreateTask                             ,0xffc0e83c) //101
NHSTUB(DebugAssert                            ,0xffc0eb14) //111
NHSTUB(DeleteDirectory_Fut                    ,0xffc265b0) //116
NHSTUB(DeleteFile_Fut                         ,0xffc264cc) //112
NHSTUB(DoAFLock                               ,0xffc27fe0) //102
NHSTUB(EnterToCompensationEVF                 ,0xffc28090) //104
NHSTUB(ExecuteEventProcedure                  ,0xffc6cea0) //104
NHSTUB(ExitFromCompensationEVF                ,0xffc280d4) //104
NHSTUB(ExitTask                               ,0xffc0eacc) //101
NHSTUB(ExpCtrlTool_StartContiAE               ,0xffc35864) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xffc3593c) //104
NHSTUB(Fclose_Fut                             ,0xffc26648) //101
NHSTUB(Feof_Fut                               ,0xffc26834) //  1
NHSTUB(Fflush_Fut                             ,0xffc26870) //  1
NHSTUB(Fgets_Fut                              ,0xffc2679c) //  1
NHSTUB(Fopen_Fut                              ,0xffc26608) //101
NHSTUB(Fread_Fut                              ,0xffc266f4) //101
//NHSTUB(FreeMemory                           ,0xffe1bd18) //101
NHSTUB(FreeUncacheableMemory                  ,0xffc29e7c) //112
NHSTUB(Fseek_Fut                              ,0xffc267e8) //101
NHSTUB(Fwrite_Fut                             ,0xffc26748) //101
NHSTUB(GetBatteryTemperature                  ,0xffc49edc) //102
NHSTUB(GetCCDTemperature                      ,0xffc49e68) //102
NHSTUB(GetCurrentAvValue                      ,0xffd14e24) //102
NHSTUB(GetDrive_ClusterSize                   ,0xffc55b18) //  4
NHSTUB(GetDrive_FreeClusters                  ,0xffc55b78) //  4
NHSTUB(GetDrive_TotalClusters                 ,0xffc55b4c) //  3
NHSTUB(GetFocusLensSubjectDistance            ,0xffd140c4) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xffd1450c) //  3
NHSTUB(GetImageFolder                         ,0xffcfbd38) //106
NHSTUB(GetKbdState                            ,0xffc47dec) //109
NHSTUB(GetMemInfo                             ,0xffc0a16c) //115
NHSTUB(GetOpticalTemperature                  ,0xffc49f50) //102
NHSTUB(GetParameterData                       ,0xffd3ff44) //101
NHSTUB(GetPropertyCase                        ,0xffc70bac) //102
NHSTUB(GetSystemTime                          ,0xffe1bd78) //101
NHSTUB(GetVRAMHPixelsSize                     ,0xffcbe198) //102
NHSTUB(GetVRAMVPixelsSize                     ,0xffcbe1a4) //102
NHSTUB(GetZoomLensCurrentPoint                ,0xffd17eec) //102
NHSTUB(GetZoomLensCurrentPosition             ,0xffe134c4) //102
NHSTUB(GiveSemaphore                          ,0xffc29858) //112
NHSTUB(IsStrobeChargeCompleted                ,0xffcaebcc) //102
NHSTUB(LEDDrive                               ,0xffc47398) //103
NHSTUB(LocalTime                              ,0xffc6aae4) //115
NHSTUB(LockMainPower                          ,0xffc744b4) //103
//NHSTUB(Lseek                                ,0xffc26c70) //101
NHSTUB(MakeDirectory_Fut                      ,0xffc26540) //116
NHSTUB(MoveFocusLensToDistance                ,0xffe74b44) //102
NHSTUB(MoveIrisWithAv                         ,0xffe18b54) //102
NHSTUB(MoveZoomLensWithPoint                  ,0xffe190e4) //102
//NHSTUB(NewTaskShell                         ,0xffc705b8) //103
NHSTUB(Open                                   ,0xffc26ae8) //101
NHSTUB(PB2Rec                                 ,0xffc7711c) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xffc5d71c) //102
NHSTUB(PT_MoveOpticalZoomAt                   ,0xffc5d6f4) //102
NHSTUB(PT_PlaySound                           ,0xffc65d54) //  7
NHSTUB(PostLogicalEventForNotPowerType        ,0xffc73ce4) //103
NHSTUB(PostLogicalEventToUI                   ,0xffc73d30) //103
NHSTUB(PutInNdFilter                          ,0xffe18f48) //102
NHSTUB(PutOutNdFilter                         ,0xffe18f6c) //102
NHSTUB(Read                                   ,0xffc0ac7c) //101
NHSTUB(ReadFastDir                            ,0xffe09084) //  4
NHSTUB(Rec2PB                                 ,0xffc7715c) //104
NHSTUB(RefreshPhysicalScreen                  ,0xffd8cf0c) //104
//NHSTUB(Remove                               ,0xffc26b88) //  4
NHSTUB(RenameFile_Fut                         ,0xffc26438) //116
NHSTUB(Restart                                ,0xffc2b614) //106
NHSTUB(ScreenLock                             ,0xffd8e0b8) //  3
NHSTUB(ScreenUnlock                           ,0xffd8e0fc) //  7
NHSTUB(SetAE_ShutterSpeed                     ,0xffe772d4) //102
NHSTUB(SetAutoShutdownTime                    ,0xffc74528) //103
NHSTUB(SetCurrentCaptureModeType              ,0xffc7ab40) //101
NHSTUB(SetFileAttributes                      ,0xffc26e4c) //  3
NHSTUB(SetFileTimeStamp                       ,0xffc26df0) //  4
NHSTUB(SetLogicalEventActive                  ,0xffc7422c) //101
NHSTUB(SetParameterData                       ,0xffd3feb4) //101
NHSTUB(SetPropertyCase                        ,0xffc70a7c) //102
NHSTUB(SetScriptMode                          ,0xffc7427c) //101
NHSTUB(SleepTask                              ,0xffc29ac0) //101
NHSTUB(TakeSemaphore                          ,0xffc29788) //101
NHSTUB(TurnOffBackLight                       ,0xffc7f804) //104
NHSTUB(TurnOnBackLight                        ,0xffc7f7ec) //104
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xffd305ec) //101
NHSTUB(UnlockAF                               ,0xffc28018) //102
NHSTUB(UnlockMainPower                        ,0xffc74408) //103
NHSTUB(UnsetZoomForMovie                      ,0xffd45e08) //104
NHSTUB(UpdateMBROnFlash                       ,0xffc55998) //105
NHSTUB(VbattGet                               ,0xffc22f14) //103
NHSTUB(Write                                  ,0xffc26be4) //101
NHSTUB(WriteSDCard                            ,0xffd0742c) //108
NHSTUB(_log                                   ,0xffea425c) //111
NHSTUB(_log10                                 ,0xffea31a0) //112
NHSTUB(_pow                                   ,0xffea3310) //114
NHSTUB(_sqrt                                  ,0xffea55c4) //  1
NHSTUB(add_ptp_handler                        ,0xffdd75dc) //  3
NHSTUB(apex2us                                ,0xffd8f408) //  4
NHSTUB(close                                  ,0xffc0aa94) //  1
NHSTUB(closedir                               ,0xffe08ee0) //  4
NHSTUB(err_init_task                          ,0xffc05f4c) //111
NHSTUB(exmem_alloc                            ,0xffc6b784) //103
NHSTUB(exmem_free                             ,0xffc6b7fc) //103
NHSTUB(free                                   ,0xffc0415c) //112
NHSTUB(kbd_p1_f                               ,0xffc245f0) //109
NHSTUB(kbd_p1_f_cont                          ,0xffc245fc) //109
NHSTUB(kbd_p2_f                               ,0xffc23ea4) //109
NHSTUB(kbd_read_keys                          ,0xffc24574) //109
NHSTUB(kbd_read_keys_r2                       ,0xffc47800) //109
NHSTUB(lseek                                  ,0xffc26c70) //101
NHSTUB(malloc                                 ,0xffc04100) //112
NHSTUB(memcmp                                 ,0xffc1066c) //101
NHSTUB(memcpy                                 ,0xffc2f3e0) //101
NHSTUB(memset                                 ,0xffd8e440) //101
NHSTUB(mkdir                                  ,0xffc26ff0) //109
NHSTUB(mktime_ext                             ,0xffc849bc) //  1
NHSTUB(open                                   ,0xffc0a9e4) //  1
NHSTUB(OpenFastDir                            ,0xffe08f30) //  4
NHSTUB(qsort                                  ,0xffe5bcd0) //  4
NHSTUB(rand                                   ,0xffc10774) //  1
//NHSTUB(read                                 ,0xffc0ac7c) //101
NHSTUB(realloc                                ,0xffd8e4bc) //115
NHSTUB(reboot_fw_update                       ,0xffe0a8f8) //106
NHSTUB(set_control_event                      ,0xffc73f4c) //111
NHSTUB(srand                                  ,0xffc10768) //  1
NHSTUB(stat                                   ,0xffc26cb8) //109
NHSTUB(strcat                                 ,0xffc84178) //  1
NHSTUB(strchr                                 ,0xffc03fe4) //  1
NHSTUB(strcmp                                 ,0xffc10628) //101
NHSTUB(strcpy                                 ,0xffc10610) //101
NHSTUB(strftime                               ,0xffc843c4) //113
NHSTUB(strlen                                 ,0xffc04030) //101
NHSTUB(strncmp                                ,0xffc03f98) //  1
NHSTUB(strncpy                                ,0xffc03f5c) //  1
NHSTUB(strrchr                                ,0xffc04008) //  1
NHSTUB(strtol                                 ,0xffc2f6c0) //101
NHSTUB(strtolx                                ,0xffc2f4c4) //109
   DEF(task_CaptSeq                           ,0xffc5f9dc) //107
   DEF(task_ExpDrv                            ,0xffc99618) //110
   DEF(task_FileWrite                         ,0xffe03b5c) //107
   DEF(task_InitFileModules                   ,0xffc77ba8) //107
   DEF(task_MovieRecord                       ,0xffd1bdb0) //107
   DEF(task_PhySw                             ,0xffc241d4) //107
NHSTUB(time                                   ,0xffc6a998) //109
NHSTUB(vsprintf                               ,0xffc105d4) //115
//NHSTUB(write                                ,0xffc26be4) //101
//NHSTUB(EngDrvIn                             ,0xffc2543c) //102
//NHSTUB(EngDrvOut                            ,0xffc25424) //102
//NHSTUB(EngDrvRead                           ,0xffc25444) //102
//NHSTUB(EngDrvBits                           ,0xffc25458) //102
//NHSTUB(GetSDProtect                         ,0xffc24548) //103
//NHSTUB(StartRecModeMenu                     ,0xffc71748) //102
//NHSTUB(DispCon_ShowBitmapColorBar           ,0xffc435f4) //102
//NHSTUB(ResetZoomLens                        ,0xffe19038) //102
//NHSTUB(ResetFocusLens                       ,0xffe17e58) //102
//NHSTUB(NR_GetDarkSubType                    ,0xffd218f0) //102
//NHSTUB(NR_SetDarkSubType                    ,0xffd21830) //102
//NHSTUB(SavePaletteData                      ,0xffe79588) //102
//NHSTUB(GUISrv_StartGUISystem                ,0xffc83a78) //101
