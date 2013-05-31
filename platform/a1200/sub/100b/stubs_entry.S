// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R47 (DRYOS version 2.3, release #0047)
//   Firmware Ver GM1.00B
//   Canon PowerShot A1200

// Values for makefile.inc
//   PLATFORMOSVER = 47
//   PLATFORMID = 12843 (0x322b) // Found @ 0xfffe0040
//   MAXRAMADDR = 0x03ffffff
//   KEYSYS = d4c                // Found @ 0xffff3514
//   NEED_ENCODED_DISKBOOT = 6   // Found @ 0xffff3524

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NHSTUB(GetBatteryTemperature                ,0xff861844) //102        *** != 0x00000000
//NHSTUB(kbd_pwr_off                          ,0xff85f980) //  2 60%    *** != 0x00000000
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff892a40 -> ff88f250 -> ff98d844 -> ffac1ab0 -> ffbe6588
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00032954) // Found @0xff834310
DEF(physw_run                               ,0x00001c30) // Found @0xff833ed0
DEF(physw_sleep_delay                       ,0x00001c38) // Found @0xff833ed0
DEF(levent_table                            ,0xffb995e4) // Found @0xffb995e4
DEF(FlashParamsTable                        ,0xffbe67c4) // Found @0xffbe67c4
DEF(movie_status                            ,0x000065b4) // Found @0xff963af0
DEF(full_screen_refresh                     ,0x00008fd0) // Found @0xffa00a88
DEF(canon_menu_active                       ,0x00002ebc) // Found @0xff88aa24
DEF(canon_shoot_menu_active                 ,0x00007a6d) // Found @0xff9a7b88
DEF(playrec_mode                            ,0x00002be8) // Found @0xff87ceb4
DEF(zoom_status                             ,0x0000ca68) // Found @0xffac5184
DEF(some_flag_for_af_scan                   ,0x00006988) // Found @0xff9677fc
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 3 int value(s), the first is the zoom focus length.
// there are 8 entries in the table - set NUM_FL to 8
DEF(focus_len_table                         ,0xfffe2a98) // Found @0xfffe2a98
DEF(zoom_busy                               ,0x00006510) // Found @0xff960534
DEF(focus_busy                              ,0x00006420) // Found @0xff95d914
DEF(recreview_hold                          ,0x00003490) // Found @0xff897fa8
DEF(palette_control                         ,0x00008fd0) // Found @0xffa00a04
DEF(active_palette_buffer                   ,0x00008fd8) // Found @0xffa00a08
DEF(palette_buffer                          ,0x000b41e4) // Found @0xffa00dbc
DEF(viewport_buffers                        ,0xffb56ac8) // Found @0xff851578
DEF(active_viewport_buffer                  ,0x000020d8) // Found @0xff8512ec

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x403f1000; }             // Found @0xff85b414
//void *vid_get_viewport_fb()      { return (void*)0x40546b80; }             // Found @0xffb18b64
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x2970+0x58)); } // Found @0xff870968 & 0xff8709a0
//char *camera_jpeg_count_str()    { return (char*)0x000b3b14; }             // Found @0xff9f76c4
//long hook_raw_size()             { return 0x011e4ee0; }                    // Found @0xffb1c024
//int get_flash_params_count(void) { return 0xa0; }                          // Found @0xff98e87c

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffb57a2c, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x04000000 // Found @0xffb57a54, levent 0x902
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 2, KEY_SHOOT_FULL      ,0x0000000c }, // Found @0xffb579c4, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000008 }, // Found @0xffb579c4, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00000004 }, // Found @0xffb579bc, levent 0x00
//    { 2, KEY_ZOOM_IN         ,0x00000010 }, // Found @0xffb579cc, levent 0x02
//    { 2, KEY_ZOOM_OUT        ,0x00000020 }, // Found @0xffb579d4, levent 0x03
//    { 2, KEY_POWER           ,0x00000040 }, // Found @0xffb579dc, levent 0x600
//    { 2, KEY_PLAYBACK        ,0x00000080 }, // Found @0xffb579e4, levent 0x601
//    { 2, KEY_UP              ,0x00000100 }, // Found @0xffb579ec, levent 0x04
//    { 2, KEY_DOWN            ,0x00000200 }, // Found @0xffb579f4, levent 0x05
//    { 2, KEY_RIGHT           ,0x00000400 }, // Found @0xffb579fc, levent 0x07
//    { 2, KEY_LEFT            ,0x00000800 }, // Found @0xffb57a04, levent 0x06
//    { 2, KEY_SET             ,0x00001000 }, // Found @0xffb57a0c, levent 0x08
//    { 2, KEY_MENU            ,0x00002000 }, // Found @0xffb57a14, levent 0x09
//    { 2, KEY_DISPLAY         ,0x00004000 }, // Found @0xffb57a1c, levent 0x0a
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#define CAM_RAW_ROWPIX    4104 // Found @0xff937e98
//#define CAM_RAW_ROWS      3048 // Found @0xff937ea4
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff83a2e0

// Misc stuff
DEF(ctypes, 0xffb5634a)

// For capt_seq.c
//static long *nrflag = (long*)(0x69bc+0x08);  // Found @ ff96b9a4 & ff96b9e4
//#define NR_AUTO (0)                          // have to explictly reset value back to 0 to enable auto

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
//NHSTUB(CreateJumptable                      ,0xffb1c1f0) //  1
//NHSTUB(_uartr_req                           ,0xff81fd98) //111
//NHSTUB(AllocateMemory                       ,0xffab0480) //101
NHSTUB(AllocateUncacheableMemory              ,0xff83a298) //112
NHSTUB(Close                                  ,0xff836a34) //101
NHSTUB(CreateTask                             ,0xff81e9b0) //101
NHSTUB(DebugAssert                            ,0xff81ec88) //111
NHSTUB(DeleteDirectory_Fut                    ,0xff836430) //116
NHSTUB(DeleteFile_Fut                         ,0xff83634c) //112
NHSTUB(DoAFLock                               ,0xff8381a4) //102
NHSTUB(EnterToCompensationEVF                 ,0xff838400) //104
NHSTUB(ExecuteEventProcedure                  ,0xff886224) //104
NHSTUB(ExitFromCompensationEVF                ,0xff838444) //104
NHSTUB(ExitTask                               ,0xff81ec40) //101
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff846884) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff84695c) //104
NHSTUB(Fclose_Fut                             ,0xff8364c8) //101
NHSTUB(Feof_Fut                               ,0xff8366b4) //  1
NHSTUB(Fflush_Fut                             ,0xff8366f0) //  1
NHSTUB(Fgets_Fut                              ,0xff83661c) //  6
NHSTUB(Fopen_Fut                              ,0xff836488) //101
NHSTUB(Fread_Fut                              ,0xff836574) //101
//NHSTUB(FreeMemory                           ,0xffab0478) //101
NHSTUB(FreeUncacheableMemory                  ,0xff83a2d8) //112
NHSTUB(Fseek_Fut                              ,0xff836668) //101
NHSTUB(Fwrite_Fut                             ,0xff8365c8) //101
NHSTUB(GetCCDTemperature                      ,0xff8617d0) //102
NHSTUB(GetCurrentAvValue                      ,0xff95f4d4) //102
NHSTUB(GetDrive_ClusterSize                   ,0xff86f2cc) //  6
NHSTUB(GetDrive_FreeClusters                  ,0xff86f324) //  6
NHSTUB(GetDrive_TotalClusters                 ,0xff86f2fc) //  6
NHSTUB(GetFocusLensSubjectDistance            ,0xff95e598) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff95e9f8) //  3
NHSTUB(GetImageFolder                         ,0xff93ed28) //  6
NHSTUB(GetKbdState                            ,0xff85f968) //109
NHSTUB(GetMemInfo                             ,0xff81a29c) //115
NHSTUB(GetOpticalTemperature                  ,0xff8618bc) //102
NHSTUB(GetParameterData                       ,0xff98e83c) //101
NHSTUB(GetPropertyCase                        ,0xff889f8c) //102
NHSTUB(GetSystemTime                          ,0xffab04d8) //101
NHSTUB(GetVRAMHPixelsSize                     ,0xff8537e8) //102
NHSTUB(GetVRAMVPixelsSize                     ,0xff8537f4) //102
NHSTUB(GetZoomLensCurrentPoint                ,0xff9608b8) //102
NHSTUB(GetZoomLensCurrentPosition             ,0xffa9dd6c) //102
NHSTUB(GiveSemaphore                          ,0xff839c90) //112
NHSTUB(IsStrobeChargeCompleted                ,0xff8d5c10) //102
NHSTUB(LEDDrive                               ,0xff85ef84) //101
NHSTUB(LocalTime                              ,0xff883b14) //115
NHSTUB(LockMainPower                          ,0xff88ee44) //103
//NHSTUB(Lseek                                ,0xff836c50) //101
NHSTUB(MakeDirectory_Fut                      ,0xff8363c0) //116
NHSTUB(MakeSDCardBootable                     ,0xff86f55c) //105
NHSTUB(MoveFocusLensToDistance                ,0xffb14ec0) //102
NHSTUB(MoveIrisWithAv                         ,0xffaadb68) //102
NHSTUB(MoveZoomLensWithPoint                  ,0xffaae210) //102
//NHSTUB(NewTaskShell                         ,0xff8899d4) //101
NHSTUB(Open                                   ,0xff83696c) //101
NHSTUB(PB2Rec                                 ,0xff89200c) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff8757d8) //102
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff8757b0) //102
NHSTUB(PT_PlaySound                           ,0xff87eb58) //  6
NHSTUB(PostLogicalEventForNotPowerType        ,0xff88e610) //103
NHSTUB(PostLogicalEventToUI                   ,0xff88e65c) //103
NHSTUB(PutInNdFilter                          ,0xffaae058) //102
NHSTUB(PutOutNdFilter                         ,0xffaae07c) //102
NHSTUB(Read                                   ,0xff81ad58) //101
NHSTUB(ReadFastDir                            ,0xffa8b440) //  6
NHSTUB(Rec2PB                                 ,0xff89204c) //104
NHSTUB(RefreshPhysicalScreen                  ,0xff8a276c) //104
//NHSTUB(Remove                               ,0xff836ba8) //  6
NHSTUB(RenameFile_Fut                         ,0xff8362b8) //116
NHSTUB(Restart                                ,0xff83baa8) //106
NHSTUB(ScreenLock                             ,0xff8a39a4) //  4
NHSTUB(ScreenUnlock                           ,0xff8a3a08) //  3
NHSTUB(SetAE_ShutterSpeed                     ,0xffb17d3c) //102
NHSTUB(SetAutoShutdownTime                    ,0xff88eeb8) //103
NHSTUB(SetCurrentCaptureModeType              ,0xff895bac) //101
NHSTUB(SetFileAttributes                      ,0xff836e38) //  6
NHSTUB(SetFileTimeStamp                       ,0xff836dc0) //  6
NHSTUB(SetLogicalEventActive                  ,0xff88ebbc) //101
NHSTUB(SetParameterData                       ,0xff98e7ac) //101
NHSTUB(SetPropertyCase                        ,0xff889e70) //102
NHSTUB(SetScriptMode                          ,0xff88ec0c) //101
NHSTUB(SleepTask                              ,0xff839f3c) //101
NHSTUB(TakeSemaphore                          ,0xff839bc0) //101
NHSTUB(TurnOffBackLight                       ,0xff89b44c) //104
NHSTUB(TurnOnBackLight                        ,0xff89b434) //104
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff97fdac) //101
NHSTUB(UnlockAF                               ,0xff8381dc) //102
NHSTUB(UnlockMainPower                        ,0xff88ed98) //103
NHSTUB(UnsetZoomForMovie                      ,0xff997d88) //104
NHSTUB(VbattGet                               ,0xff832c94) //101
NHSTUB(Write                                  ,0xff836a88) //101
NHSTUB(WriteSDCard                            ,0xff94ec14) //108
NHSTUB(_log                                   ,0xffb52e70) //111
NHSTUB(_log10                                 ,0xffb533b0) //112
NHSTUB(_pow                                   ,0xffb53528) //114
NHSTUB(_sqrt                                  ,0xffb5514c) //  6
NHSTUB(add_ptp_handler                        ,0xffa41320) //  6
NHSTUB(apex2us                                ,0xffa05df0) //  4
NHSTUB(close                                  ,0xff81abb4) //  6
NHSTUB(closedir                               ,0xffa8b29c) //  4
NHSTUB(err_init_task                          ,0xff815fd4) //111
NHSTUB(exmem_alloc                            ,0xff884adc) //101
NHSTUB(exmem_free                             ,0xff884b54) //101
NHSTUB(free                                   ,0xff814244) //112
NHSTUB(kbd_p1_f                               ,0xff83438c) //109
NHSTUB(kbd_p1_f_cont                          ,0xff834398) //109
NHSTUB(kbd_p2_f                               ,0xff833ba0) //109
NHSTUB(kbd_read_keys                          ,0xff834310) //109
NHSTUB(kbd_read_keys_r2                       ,0xff85f3c4) //109
NHSTUB(lseek                                  ,0xff836c50) //101
NHSTUB(malloc                                 ,0xff8141ec) //112
NHSTUB(memcmp                                 ,0xff8208bc) //101
NHSTUB(memcpy                                 ,0xff83f8f0) //101
NHSTUB(memset                                 ,0xffa04df0) //101
NHSTUB(mkdir                                  ,0xff836ed0) //109
NHSTUB(mktime_ext                             ,0xff8a47e8) //  1
NHSTUB(open                                   ,0xff81ab04) //  6
NHSTUB(OpenFastDir                            ,0xffa8b2ec) //  6
NHSTUB(qsort                                  ,0xffaf6c54) //  6
NHSTUB(rand                                   ,0xffa04f30) //  6
//NHSTUB(read                                 ,0xff81ad58) //101
NHSTUB(realloc                                ,0xffa04e6c) //115
NHSTUB(reboot_fw_update                       ,0xffa908dc) //106
NHSTUB(set_control_event                      ,0xff88e880) //111
NHSTUB(srand                                  ,0xffa04f24) //  6
NHSTUB(stat                                   ,0xff836c98) //109
NHSTUB(strcat                                 ,0xff8a3fa0) //  1
NHSTUB(strchr                                 ,0xff8140b8) //  1
NHSTUB(strcmp                                 ,0xff820878) //101
NHSTUB(strcpy                                 ,0xff820860) //101
NHSTUB(strftime                               ,0xff8a41e8) //113
NHSTUB(strlen                                 ,0xff814104) //101
NHSTUB(strncmp                                ,0xff81406c) //  1
NHSTUB(strncpy                                ,0xff814030) //  1
NHSTUB(strrchr                                ,0xff8140dc) //  1
NHSTUB(strtol                                 ,0xff83fbf0) //101
NHSTUB(strtolx                                ,0xff83f9f4) //109
   DEF(task_CaptSeq                           ,0xff877db0) //110
   DEF(task_ExpDrv                            ,0xff8bb350) //110
   DEF(task_InitFileModules                   ,0xff8928c0) //110
   DEF(task_MovieRecord                       ,0xff9645bc) //110
   DEF(task_PhySw                             ,0xff833ecc) //110
NHSTUB(time                                   ,0xff8840f0) //109
NHSTUB(vsprintf                               ,0xff820820) //115
//NHSTUB(write                                ,0xff836a88) //101
//NHSTUB(EngDrvIn                             ,0xff8351d0) //102
//NHSTUB(EngDrvOut                            ,0xff8351b8) //102
//NHSTUB(EngDrvRead                           ,0xff8351d8) //102
//NHSTUB(EngDrvBits                           ,0xff8351ec) //102
//NHSTUB(GetSDProtect                         ,0xff8342d4) //101
//NHSTUB(StartRecModeMenu                     ,0xff88aa20) //102
//NHSTUB(DispCon_ShowBitmapColorBar           ,0xff85b3e4) //102
//NHSTUB(ResetZoomLens                        ,0xffaae164) //102
//NHSTUB(ResetFocusLens                       ,0xffaace40) //102
//NHSTUB(NR_GetDarkSubType                    ,0xff96ba74) //102
//NHSTUB(NR_SetDarkSubType                    ,0xff96b99c) //102
//NHSTUB(SavePaletteData                      ,0xffb1a150) //102
//NHSTUB(GUISrv_StartGUISystem                ,0xff8a1fe4) //101
