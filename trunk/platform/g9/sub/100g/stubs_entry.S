// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R23 (DRYOS version 2.3, release #0023)
//   Firmware Ver GM1.00G
//   Canon PowerShot G9

// Values for makefile.inc
//   PLATFORMOSVER = 23
//   PLATFORMID = 12634 (0x315a) // Found @ 0xfffe0130
//   MAXRAMADDR = 0x03ffffff
//   KEYSYS = d3                 // Found @ 0xffff31f0
//   NEED_ENCODED_DISKBOOT = 1   // Found @ 0xffff31d0

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NHSTUB(PutInNdFilter                        ,0xff9384d8) //102        *** != 0xffa0c550
//NHSTUB(PutOutNdFilter                       ,0xff9384fc) //102        *** != 0xffa0c588
//NHSTUB(kbd_pwr_off                          ,0xff84944c) //  2 67%    *** != 0x00000000
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0x00000000
//NHSTUB(strcmp                               ,0xff81e7cc) //101        *** != 0xff81e7f4
//NHSTUB(write                                ,0xff8255d8) //101        *** != 0xff81a3d8

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff8773f8 -> ff8735c4 -> ff95539c -> ffa4c738 -> ffb080ec
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x0001563c) // Found @0xff8230cc
DEF(physw_run                               ,0x00001ca4) // Found @0xff822d78
DEF(physw_sleep_delay                       ,0x00001ca2) // Found @0xff822d78
DEF(levent_table                            ,0xffae01ac) // Found @0xffae01ac
DEF(FlashParamsTable                        ,0xffb082b8) // Found @0xffb082b8
DEF(movie_status                            ,0x00005714) // Found @0xff85d220
DEF(canon_menu_active                       ,0x0000fdc8) // Found @0xff99b544
DEF(canon_shoot_menu_active                 ,0x0000f33d) // Found @0xff96ac18
DEF(playrec_mode                            ,0x000058cc) // Found @0xff864a60
DEF(zoom_status                             ,0x0001264c) // Found @0xffa4e3fc
DEF(some_flag_for_af_scan                   ,0x0001253c) // Found @0xffa447a0
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 3 int value(s), the first is the zoom focus length.
// there are 14 entries in the table - set NUM_FL to 14
DEF(focus_len_table                         ,0xfffe299c) // Found @0xfffe299c
DEF(zoom_busy                               ,0x0000e260) // Found @0xff939f2c
DEF(focus_busy                              ,0x0000e150) // Found @0xff93411c
//DEF(recreview_hold                          ,0x00006400) // Found @0xff87cb64, ** != ** stubs_min = 0x0000f050 (0xF050)

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x10361000; }             // Found @0xff8451d0
//void *vid_get_viewport_fb()      { return (void*)0x1067b540; }             // Found @0xffa112dc
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x5558+0x50)); } // Found @0xff856268 & 0xff8562a0
//char *camera_jpeg_count_str()    { return (char*)0x00060354; }             // Found @0xff9afb54
//long hook_raw_size()             { return 0x00ee9710; }                    // Found @0xffa131a0
//int get_flash_params_count(void) { return 0x72; }                          // Found @0xff95699c

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffac6350, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x00040000 // Found @0xffac6358, levent 0x902
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_POWER           ,0x00010000 }, // Found @0xffac6260, levent 0x600 (uses inverted logic in physw_status)
//    { 0, KEY_PLAYBACK        ,0x00020000 }, // Found @0xffac6268, levent 0x601 (uses inverted logic in physw_status)
//    { 0, KEY_SHOOT_FULL      ,0xc0000000 }, // Found @0xffac6288, levent 0x01
//    { 0, KEY_SHOOT_FULL_ONLY ,0x80000000 }, // Found @0xffac6288, levent 0x01
//    { 0, KEY_SHOOT_HALF      ,0x40000000 }, // Found @0xffac6280, levent 0x00
//    { 1, KEY_ZOOM_OUT        ,0x00000008 }, // Found @0xffac62a8, levent 0x03
//    { 1, KEY_ZOOM_IN         ,0x00000010 }, // Found @0xffac62b0, levent 0x02
//    { 1, KEY_LEFT            ,0x00010000 }, // Found @0xffac62e0, levent 0x06
//    { 1, KEY_SET             ,0x00020000 }, // Found @0xffac62e8, levent 0x08
//    { 1, KEY_RIGHT           ,0x00040000 }, // Found @0xffac62f0, levent 0x07
//    { 1, KEY_DOWN            ,0x00080000 }, // Found @0xffac62f8, levent 0x05
//    { 1, KEY_UP              ,0x00100000 }, // Found @0xffac6300, levent 0x04
//    { 1, KEY_DISPLAY         ,0x04000000 }, // Found @0xffac6318, levent 0x0a
//    { 1, KEY_MENU            ,0x08000000 }, // Found @0xffac6320, levent 0x09
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_RAW_ROWPIX    4104 // Found @0xffa0b268
//#define CAM_RAW_ROWS      3048 // Found @0xffa0b270
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x10000000 // Found @0xff82a7c4

// Misc stuff
DEF(ctypes, 0xffac0b42)

// For capt_seq.c
DEF(_nrflag,0xe618) // Found @ ff9444e4 (0xe618)
//static long *nrflag = (long*)(0xe618);       // Found @ ff9444e4

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
//NHSTUB(CreateJumptable                      ,0xffa136d0) //  1
//NHSTUB(_uartr_req                           ,0xff81dcfc) //111
//NHSTUB(AllocateMemory                       ,0xffa47cc8) //103
NHSTUB(AllocateUncacheableMemory              ,0xff82a788) //112
NHSTUB(Close                                  ,0xff82552c) //101
NHSTUB(CreateTask                             ,0xff81baf0) //101
NHSTUB(DebugAssert                            ,0xff81bfc8) //111
NHSTUB(DeleteDirectory_Fut                    ,0xff824e78) //116
NHSTUB(DeleteFile_Fut                         ,0xff824d94) //112
NHSTUB(DoAFLock                               ,0xff8275cc) //103
NHSTUB(EnterToCompensationEVF                 ,0xff8279a8) //104
NHSTUB(ExecuteEventProcedure                  ,0xff81c1a8) //104
NHSTUB(ExitFromCompensationEVF                ,0xff8279f8) //104
NHSTUB(ExitTask                               ,0xff81bd80) //101
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff835600) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff8357c0) //104
NHSTUB(Fclose_Fut                             ,0xff824f10) //101
NHSTUB(Feof_Fut                               ,0xff8250fc) //  1
NHSTUB(Fflush_Fut                             ,0xff825138) //  1
NHSTUB(Fgets_Fut                              ,0xff825064) //  1
NHSTUB(Fopen_Fut                              ,0xff824ed0) //101
NHSTUB(Fread_Fut                              ,0xff824fbc) //101
//NHSTUB(FreeMemory                           ,0xffa47cb4) //103
NHSTUB(FreeUncacheableMemory                  ,0xff82a7bc) //112
NHSTUB(Fseek_Fut                              ,0xff8250b0) //101
NHSTUB(Fwrite_Fut                             ,0xff825010) //101
NHSTUB(GetBatteryTemperature                  ,0xff84bee8) //102
NHSTUB(GetCCDTemperature                      ,0xff84be78) //102
NHSTUB(GetCurrentAvValue                      ,0xff936dc8) //102
NHSTUB(GetDrive_ClusterSize                   ,0xff852754) //  1
NHSTUB(GetDrive_FreeClusters                  ,0xff8527f4) //  1
NHSTUB(GetDrive_TotalClusters                 ,0xff852788) //  1
NHSTUB(GetFocusLensSubjectDistance            ,0xff934c5c) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff934f68) //  1
NHSTUB(GetKbdState                            ,0xff849300) //109
NHSTUB(GetMemInfo                             ,0xff813c58) //115
NHSTUB(GetOpticalTemperature                  ,0xff84bf58) //102
NHSTUB(GetParameterData                       ,0xff95695c) //  1
NHSTUB(GetPropertyCase                        ,0xff86f768) //101
NHSTUB(GetSystemTime                          ,0xffa47dd0) //  1
NHSTUB(GetVRAMHPixelsSize                     ,0xff83dedc) //102
NHSTUB(GetVRAMVPixelsSize                     ,0xff83dee8) //102
NHSTUB(GetZoomLensCurrentPoint                ,0xff93a290) //102
NHSTUB(GetZoomLensCurrentPosition             ,0xffa3e658) //102
NHSTUB(GiveSemaphore                          ,0xff81ba5c) //112
NHSTUB(IsStrobeChargeCompleted                ,0xff8c1344) //102
NHSTUB(LEDDrive                               ,0xff848890) //103
NHSTUB(LocalTime                              ,0xff86b538) //115
NHSTUB(LockMainPower                          ,0xff8731f0) //103
//NHSTUB(Lseek                                ,0xff82566c) //101
NHSTUB(MakeDirectory_Fut                      ,0xff824e08) //116
NHSTUB(MoveFocusLensToDistance                ,0xffa0e134) //102
NHSTUB(MoveIrisWithAv                         ,0xff9371a8) //102
NHSTUB(MoveZoomLensWithPoint                  ,0xff93ad3c) //102
//NHSTUB(NewTaskShell                         ,0xff86f1ec) //103
NHSTUB(Open                                   ,0xff825504) //101
NHSTUB(PB2Rec                                 ,0xff876664) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff8668e0) //103
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff8668a8) //103
NHSTUB(PT_PlaySound                           ,0xff866454) //103
NHSTUB(PostLogicalEventForNotPowerType        ,0xff87118c) //103
NHSTUB(PostLogicalEventToUI                   ,0xff8711d8) //103
NHSTUB(Read                                   ,0xff81a378) //101
NHSTUB(ReadFastDir                            ,0xffa2cbac) //  1
NHSTUB(Rec2PB                                 ,0xff875024) //104
NHSTUB(RefreshPhysicalScreen                  ,0xff9bdbe4) //104
//NHSTUB(Remove                               ,0xff825574) //  1
NHSTUB(RenameFile_Fut                         ,0xff824d40) //  1
NHSTUB(Restart                                ,0xff82c7e4) //106
NHSTUB(SetAE_ShutterSpeed                     ,0xffa10490) //102
NHSTUB(SetAutoShutdownTime                    ,0xff873264) //103
NHSTUB(SetCurrentCaptureModeType              ,0xff879f7c) //101
NHSTUB(SetFileAttributes                      ,0xff825858) //  1
NHSTUB(SetFileTimeStamp                       ,0xff825808) //  1
NHSTUB(SetLogicalEventActive                  ,0xff872f28) //  1
NHSTUB(SetParameterData                       ,0xff956838) //101
NHSTUB(SetPropertyCase                        ,0xff86f660) //103
NHSTUB(SetScriptMode                          ,0xff872f78) //101
NHSTUB(SleepTask                              ,0xff82a610) //101
NHSTUB(TakeSemaphore                          ,0xff81b98c) //101
NHSTUB(TurnOffBackLight                       ,0xff87ff88) //104
NHSTUB(TurnOnBackLight                        ,0xff87ff70) //104
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff99c390) //103
NHSTUB(UnlockAF                               ,0xff827638) //103
NHSTUB(UnlockMainPower                        ,0xff873144) //103
NHSTUB(UnsetZoomForMovie                      ,0xff95d03c) //104
NHSTUB(UpdateMBROnFlash                       ,0xff85251c) //105
NHSTUB(VbattGet                               ,0xff82199c) //101
NHSTUB(Write                                  ,0xff8255d8) //101
NHSTUB(WriteSDCard                            ,0xff928cf4) //108
NHSTUB(_log                                   ,0xffabe6b4) //111
NHSTUB(_log10                                 ,0xffabd5f8) //112
NHSTUB(_pow                                   ,0xffabd768) //114
NHSTUB(_sqrt                                  ,0xffabfa1c) //  1
NHSTUB(add_ptp_handler                        ,0xff8d897c) //  1
NHSTUB(apex2us                                ,0xff9bf09c) //  4
NHSTUB(close                                  ,0xff81a190) //  1
NHSTUB(closedir                               ,0xffa2cc7c) //  1
NHSTUB(err_init_task                          ,0xff814eb0) //111
NHSTUB(exmem_alloc                            ,0xff86c680) //102
NHSTUB(exmem_free                             ,0xff86c6f8) //102
NHSTUB(free                                   ,0xff813ab0) //112
NHSTUB(kbd_p1_f                               ,0xff8231c8) //109
NHSTUB(kbd_p1_f_cont                          ,0xff8231d4) //109
NHSTUB(kbd_p2_f                               ,0xff822a18) //109
NHSTUB(kbd_read_keys                          ,0xff8230cc) //109
NHSTUB(kbd_read_keys_r2                       ,0xff848dc8) //109
NHSTUB(lseek                                  ,0xff82566c) //101
NHSTUB(malloc                                 ,0xff8139dc) //112
NHSTUB(memcmp                                 ,0xff81e834) //101
NHSTUB(memcpy                                 ,0xff895cf0) //101
NHSTUB(memset                                 ,0xffa8d404) //101
NHSTUB(mkdir                                  ,0xff8258d0) //109
NHSTUB(mktime_ext                             ,0xff89655c) //  1
NHSTUB(open                                   ,0xff81a0e0) //  1
NHSTUB(OpenFastDir                            ,0xffa2cb18) //  1
NHSTUB(qsort                                  ,0xff9be474) //  1
NHSTUB(rand                                   ,0xff81e93c) //  1
//NHSTUB(read                                 ,0xff81a378) //101
NHSTUB(realloc                                ,0xff813b90) //115
NHSTUB(reboot_fw_update                       ,0xffa34570) //106
NHSTUB(set_control_event                      ,0xff872c2c) //  1
NHSTUB(srand                                  ,0xff81e930) //  1
NHSTUB(stat                                   ,0xff825738) //  1
NHSTUB(strcat                                 ,0xff895c1c) //  1
NHSTUB(strchr                                 ,0xff895ca4) //  1
NHSTUB(strcpy                                 ,0xff81e778) //101
NHSTUB(strftime                               ,0xff895f64) //  1
NHSTUB(strlen                                 ,0xff81e810) //101
NHSTUB(strncmp                                ,0xff895c58) //  1
NHSTUB(strncpy                                ,0xff81e790) //  1
NHSTUB(strrchr                                ,0xff895cc8) //  1
NHSTUB(strtol                                 ,0xff830d90) //101
NHSTUB(strtolx                                ,0xff830b94) //109
   DEF(task_CaptSeq                           ,0xff861210) //110
   DEF(task_ExpDrv                            ,0xff8b8b90) //110
   DEF(task_InitFileModules                   ,0xff877284) //110
   DEF(task_MovieRecord                       ,0xff85d4c0) //110
   DEF(task_PhySw                             ,0xff822d74) //110
NHSTUB(time                                   ,0xff86ba3c) //109
NHSTUB(vsprintf                               ,0xff81e6f8) //115
//NHSTUB(EngDrvIn                             ,0xff823fc4) //102
//NHSTUB(EngDrvOut                            ,0xff823fac) //102
//NHSTUB(EngDrvRead                           ,0xff823fcc) //102
//NHSTUB(EngDrvBits                           ,0xff823fe0) //102
//NHSTUB(GetSDProtect                         ,0xff823094) //102
//NHSTUB(StartRecModeMenu                     ,0xff99b540) //102
//NHSTUB(DispCon_ShowBitmapColorBar           ,0xff84519c) //102
//NHSTUB(ResetZoomLens                        ,0xff93ac90) //102
//NHSTUB(ResetFocusLens                       ,0xff93577c) //102
//NHSTUB(NR_GetDarkSubType                    ,0xff945710) //102
//NHSTUB(NR_SetDarkSubType                    ,0xff94569c) //102
//NHSTUB(SavePaletteData                      ,0xffa12560) //102
