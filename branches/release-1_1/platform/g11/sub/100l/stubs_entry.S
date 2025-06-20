// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R39 (DRYOS version 2.3, release #0039)
//   Firmware Ver GM1.00L
//   Canon PowerShot G11

// Values for makefile.inc
//   PLATFORMOSVER = 39
//   PLATFORMID = 12767 (0x31df) // Found @ 0xfffe0130
//   MAXRAMADDR = 0x03ffffff
//   KEYSYS = d4                 // Found @ 0xffff35a8
//   NEED_ENCODED_DISKBOOT = 3   // Found @ 0xffff35b8

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NSTUB(SetScriptMode                         ,0xff895134) //101        *** != 0xff810f4c
//NSTUB(TurnOffBackLight                      ,0xff8a34dc) //104        *** != 0xff8a348c
NSTUB(kbd_pwr_off                             ,0xff86043c) //  2 64%
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff89914c -> ff895788 -> ff995478 -> ffab4a38 -> ffbe71cc
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00032578) // Found @0xff833584
DEF(physw_run                               ,0x00001c44) // Found @0xff8331f4
DEF(physw_sleep_delay                       ,0x00001c42) // Found @0xff8331f4
DEF(levent_table                            ,0xffb95fe0) // Found @0xffb95fe0
DEF(FlashParamsTable                        ,0xffbe73c0) // Found @0xffbe73c0
DEF(movie_status                            ,0x00006d90) // Found @0xff962a78
DEF(full_screen_refresh                     ,0x00009840) // Found @0xffa0ee98
DEF(canon_menu_active                       ,0x0000303c) // Found @0xff88e2cc
DEF(canon_shoot_menu_active                 ,0x00008259) // Found @0xff9afaf4
DEF(playrec_mode                            ,0x00002d64) // Found @0xff8805a8
DEF(zoom_status                             ,0x0000c868) // Found @0xffab7924
DEF(some_flag_for_af_scan                   ,0x000072b4) // Found @0xff9660f0
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 3 int value(s), the first is the zoom focus length.
// there are 14 entries in the table - set NUM_FL to 14
DEF(focus_len_table                         ,0xfffe2a8c) // Found @0xfffe2a8c
DEF(zoom_busy                               ,0x00006cc0) // Found @0xff95ec54
DEF(focus_busy                              ,0x00006bb4) // Found @0xff959c48
//DEF(recreview_hold                          ,0x00003be4) // Found @0xff89fb4c, ** != ** stubs_min = 0x00007dd8 (0x7D00+0xD8)

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x40471000; }             // Found @0xff85a4c0
//void *vid_get_viewport_fb()      { return (void*)0x40587700; }             // Found @0xffb0696c
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x2a50+0x58)); } // Found @0xff871348 & 0xff871380
//char *camera_jpeg_count_str()    { return (char*)0x00097234; }             // Found @0xffa012ac
//long hook_raw_size()             { return 0x00ee9200; }                    // Found @0xffb09c24
//int get_flash_params_count(void) { return 0x84; }                          // Found @0xff996a78

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffb477ac, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x00100000 // Found @0xffb477d0, levent 0x902
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_ZOOM_OUT        ,0x00000008 }, // Found @0xffb47638, levent 0x03
//    { 0, KEY_ZOOM_IN         ,0x00000010 }, // Found @0xffb47644, levent 0x02
//    { 0, KEY_LEFT            ,0x00000400 }, // Found @0xffb4768c, levent 0x06
//    { 0, KEY_SET             ,0x00000800 }, // Found @0xffb47698, levent 0x08
//    { 0, KEY_RIGHT           ,0x00001000 }, // Found @0xffb476a4, levent 0x07
//    { 0, KEY_DOWN            ,0x00002000 }, // Found @0xffb476b0, levent 0x05
//    { 0, KEY_UP              ,0x00004000 }, // Found @0xffb476bc, levent 0x04
//    { 0, KEY_DISPLAY         ,0x00020000 }, // Found @0xffb476e0, levent 0x0a
//    { 0, KEY_MENU            ,0x00040000 }, // Found @0xffb476ec, levent 0x09
//    { 2, KEY_SHOOT_FULL      ,0x00000003 }, // Found @0xffb47770, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000002 }, // Found @0xffb47770, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00000001 }, // Found @0xffb47764, levent 0x00
//    { 2, KEY_POWER           ,0x00000004 }, // Found @0xffb4777c, levent 0x600 (uses inverted logic in physw_status)
//    { 2, KEY_PLAYBACK        ,0x00000008 }, // Found @0xffb47788, levent 0x601 (uses inverted logic in physw_status)
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_RAW_ROWPIX    3744 // Found @0xff935818
//#define CAM_RAW_ROWS      2784 // Found @0xff935820
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff839460

// Misc stuff
DEF(ctypes, 0xffb40586)

// For capt_seq.c
//static long *nrflag = (long*)(0x7298-0x08);  // Found @ ff9689d8 & ff9689f4

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
//NSTUB(CreateJumptable                       ,0xffb0a6ac) //  1
//NSTUB(_uartr_req                            ,0xff81f968) //111
//NSTUB(AllocateMemory                        ,0xffaa36f8) //101
NSTUB(AllocateUncacheableMemory               ,0xff83941c) //112
NSTUB(Close                                   ,0xff8359b0) //101
NSTUB(CreateTask                              ,0xff81e5b4) //101
NSTUB(DebugAssert                             ,0xff81e88c) //111
NSTUB(DeleteDirectory_Fut                     ,0xff835420) //116
NSTUB(DeleteFile_Fut                          ,0xff83533c) //112
NSTUB(DoAFLock                                ,0xff837158) //102
NSTUB(EnterToCompensationEVF                  ,0xff8373d8) //104
NSTUB(ExecuteEventProcedure                   ,0xff889954) //104
NSTUB(ExitFromCompensationEVF                 ,0xff83741c) //104
NSTUB(ExitTask                                ,0xff81e844) //101
NSTUB(ExpCtrlTool_StartContiAE                ,0xff844ce0) //104
NSTUB(ExpCtrlTool_StopContiAE                 ,0xff844db8) //104
NSTUB(Fclose_Fut                              ,0xff8354b8) //101
NSTUB(Feof_Fut                                ,0xff8356a4) //  1
NSTUB(Fflush_Fut                              ,0xff8356e0) //  1
NSTUB(Fgets_Fut                               ,0xff83560c) //  1
NSTUB(Fopen_Fut                               ,0xff835478) //101
NSTUB(Fread_Fut                               ,0xff835564) //101
//NSTUB(FreeMemory                            ,0xffaa36f0) //101
NSTUB(FreeUncacheableMemory                   ,0xff83945c) //112
NSTUB(Fseek_Fut                               ,0xff835658) //101
NSTUB(Fwrite_Fut                              ,0xff8355b8) //101
NSTUB(GetBatteryTemperature                   ,0xff8635d8) //102
NSTUB(GetCCDTemperature                       ,0xff863564) //102
NSTUB(GetCurrentAvValue                       ,0xff95c3ec) //102
NSTUB(GetDrive_ClusterSize                    ,0xff86fc80) //  3
NSTUB(GetDrive_FreeClusters                   ,0xff86fce0) //  3
NSTUB(GetDrive_TotalClusters                  ,0xff86fcb4) //  3
NSTUB(GetFocusLensSubjectDistance             ,0xff95a9c0) //102
NSTUB(GetFocusLensSubjectDistanceFromLens     ,0xff95ae08) //  3
NSTUB(GetImageFolder                          ,0xff93d6a4) //106
NSTUB(GetKbdState                             ,0xff860424) //109
NSTUB(GetMemInfo                              ,0xff81a070) //115
NSTUB(GetOpticalTemperature                   ,0xff86364c) //102
NSTUB(GetParameterData                        ,0xff996a38) //101
NSTUB(GetPropertyCase                         ,0xff88d700) //102
NSTUB(GetSystemTime                           ,0xffaa3750) //101
NSTUB(GetVRAMHPixelsSize                      ,0xff850b08) //102
NSTUB(GetVRAMVPixelsSize                      ,0xff850b14) //102
NSTUB(GetZoomLensCurrentPoint                 ,0xff95efc8) //102
NSTUB(GetZoomLensCurrentPosition              ,0xffa9695c) //102
NSTUB(GiveSemaphore                           ,0xff838e38) //112
NSTUB(IsStrobeChargeCompleted                 ,0xff8db440) //102
NSTUB(LEDDrive                                ,0xff85f674) //103
NSTUB(LocalTime                               ,0xff8872c8) //115
NSTUB(LockMainPower                           ,0xff895394) //103
//NSTUB(Lseek                                 ,0xff835acc) //101
NSTUB(MakeDirectory_Fut                       ,0xff8353b0) //116
NSTUB(MoveFocusLensToDistance                 ,0xffb03388) //102
NSTUB(MoveIrisWithAv                          ,0xffaa0604) //102
NSTUB(MoveZoomLensWithPoint                   ,0xffaa0d1c) //102
//NSTUB(NewTaskShell                          ,0xff88d1ac) //103
NSTUB(Open                                    ,0xff835958) //101
NSTUB(PB2Rec                                  ,0xff8984b0) //104
NSTUB(PT_MoveDigitalZoomToWide                ,0xff8781c8) //102
NSTUB(PT_MoveOpticalZoomAt                    ,0xff8781a0) //102
NSTUB(PT_PlaySound                            ,0xff882464) //102
NSTUB(PostLogicalEventForNotPowerType         ,0xff8931c0) //103
NSTUB(PostLogicalEventToUI                    ,0xff89320c) //103
NSTUB(PutInNdFilter                           ,0xffaa0b80) //102
NSTUB(PutOutNdFilter                          ,0xffaa0ba4) //102
NSTUB(Read                                    ,0xff81ab78) //101
NSTUB(ReadFastDir                             ,0xffa8442c) //  3
NSTUB(Rec2PB                                  ,0xff8984f0) //104
NSTUB(RefreshPhysicalScreen                   ,0xffa10094) //104
//NSTUB(Remove                                ,0xff8359e4) //  4
NSTUB(RenameFile_Fut                          ,0xff8352a8) //116
NSTUB(Restart                                 ,0xff83ab70) //106
NSTUB(ScreenLock                              ,0xffa112c4) //  3
NSTUB(ScreenUnlock                            ,0xffa112ec) //  3
NSTUB(SetAE_ShutterSpeed                      ,0xffb05b2c) //102
NSTUB(SetAutoShutdownTime                     ,0xff895408) //103
NSTUB(SetCurrentCaptureModeType               ,0xff89cb6c) //101
NSTUB(SetFileAttributes                       ,0xff835c80) //  3
NSTUB(SetFileTimeStamp                        ,0xff835c3c) //  3
NSTUB(SetLogicalEventActive                   ,0xff8950e4) //101
NSTUB(SetParameterData                        ,0xff996914) //101
NSTUB(SetPropertyCase                         ,0xff88d5fc) //102
NSTUB(SleepTask                               ,0xff8390a0) //101
NSTUB(TakeSemaphore                           ,0xff838d68) //101
NSTUB(TurnOnBackLight                         ,0xff8a34c4) //104
NSTUB(UIFS_WriteFirmInfoToFile                ,0xff98071c) //105
NSTUB(UnlockAF                                ,0xff837190) //102
NSTUB(UnlockMainPower                         ,0xff8952e8) //103
NSTUB(UnsetZoomForMovie                       ,0xff99cfe4) //104
NSTUB(UpdateMBROnFlash                        ,0xff86fb00) //105
NSTUB(VbattGet                                ,0xff831e08) //103
NSTUB(Write                                   ,0xff835a40) //101
NSTUB(WriteSDCard                             ,0xff94b804) //108
NSTUB(_log                                    ,0xffb3e048) //111
NSTUB(_log10                                  ,0xffb3cf8c) //112
NSTUB(_pow                                    ,0xffb3d0fc) //114
NSTUB(_sqrt                                   ,0xffb3f3b0) //  1
NSTUB(add_ptp_handler                         ,0xffa4e04c) //  3
NSTUB(apex2us                                 ,0xffa14a7c) //  4
NSTUB(close                                   ,0xff81a990) //  1
NSTUB(closedir                                ,0xffa842b4) //  3
NSTUB(err_init_task                           ,0xff815f28) //111
NSTUB(exmem_alloc                             ,0xff888188) //103
NSTUB(free                                    ,0xff814138) //112
NSTUB(kbd_p1_f                                ,0xff833600) //109
NSTUB(kbd_p1_f_cont                           ,0xff83360c) //109
NSTUB(kbd_p2_f                                ,0xff832ec0) //109
NSTUB(kbd_read_keys                           ,0xff833584) //109
NSTUB(kbd_read_keys_r2                        ,0xff85fb94) //109
NSTUB(lseek                                   ,0xff835acc) //101
NSTUB(malloc                                  ,0xff8140dc) //112
NSTUB(memcmp                                  ,0xff8203ec) //101
NSTUB(memcpy                                  ,0xff83ea1c) //101
NSTUB(memset                                  ,0xffa13acc) //101
NSTUB(mkdir                                   ,0xff835e24) //109
NSTUB(mktime_ext                              ,0xff8ab0a0) //  1
NSTUB(open                                    ,0xff81a8e0) //  1
NSTUB(OpenFastDir                             ,0xffa842f8) //  3
NSTUB(qsort                                   ,0xffaf3a98) //  1
NSTUB(rand                                    ,0xff8204f4) //  1
//NSTUB(read                                  ,0xff81ab78) //101
NSTUB(reboot_fw_update                        ,0xffa8993c) //106
NSTUB(set_control_event                       ,0xff894d38) //111
NSTUB(srand                                   ,0xff8204e8) //  1
NSTUB(stat                                    ,0xff835b08) //109
NSTUB(strcat                                  ,0xff8aa85c) //  1
NSTUB(strchr                                  ,0xff813fc0) //  1
NSTUB(strcmp                                  ,0xff8203a8) //101
NSTUB(strcpy                                  ,0xff820390) //101
NSTUB(strftime                                ,0xff8aaaa8) //  1
NSTUB(strlen                                  ,0xff81400c) //101
NSTUB(strncmp                                 ,0xff813f74) //  1
NSTUB(strncpy                                 ,0xff813f38) //  1
NSTUB(strrchr                                 ,0xff813fe4) //  1
NSTUB(strtol                                  ,0xff83ecfc) //101
NSTUB(strtolx                                 ,0xff83eb00) //109
  DEF(task_CaptSeq                            ,0xff87b18c) //107
  DEF(task_ExpDrv                             ,0xff8bfbf8) //107
  DEF(task_InitFileModules                    ,0xff898fd8) //107
  DEF(task_MovieRecord                        ,0xff962cb0) //107
  DEF(task_PhySw                              ,0xff8331f0) //107
  DEF(task_RotaryEncoder                      ,0xff860554) //107
NSTUB(time                                    ,0xff887840) //109
NSTUB(vsprintf                                ,0xff820354) //115
//NSTUB(write                                 ,0xff835a40) //101
//NSTUB(GetSDProtect                          ,0xff83355c) //103
//NSTUB(StartRecModeMenu                      ,0xff88e2c8) //102
//NSTUB(DispCon_ShowBitmapColorBar            ,0xff85a478) //102
//NSTUB(ResetZoomLens                         ,0xffaa0c70) //102
//NSTUB(ResetFocusLens                        ,0xffa9f8a8) //102
//NSTUB(NR_GetDarkSubType                     ,0xff96b674) //102
//NSTUB(NR_SetDarkSubType                     ,0xff96b5cc) //102
//NSTUB(SavePaletteData                       ,0xffb07e4c) //102
//NSTUB(GUISrv_StartGUISystem                 ,0xff8aa5dc) //101
