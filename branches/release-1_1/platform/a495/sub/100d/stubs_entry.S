// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R43 (DRYOS version 2.3, release #0043)
//   Firmware Ver GM1.00D
//   Canon PowerShot A495

// Values for makefile.inc
//   PLATFORMOSVER = 43
//   PLATFORMID = 12783 (0x31ef) // Found @ 0xfffe0130
//   MAXRAMADDR = 0x01ffffff
//   KEYSYS = d4a                // Found @ 0xffff1a2c
//   NEED_ENCODED_DISKBOOT = 4   // Found @ 0xffff1a3c

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NSTUB(SetScriptMode                         ,0xffc6cc08) //101        *** != 0xffc00f70
NSTUB(kbd_pwr_off                             ,0xffc435e4) //  2 64%
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ffc706d0 -> ffc6d238 -> ffd2e134 -> ffe0aa60 -> ffecf688
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x0002e7f4) // Found @0xffc23b2c
DEF(physw_run                               ,0x00001bf0) // Found @0xffc23790
DEF(physw_sleep_delay                       ,0x00001bf8) // Found @0xffc23790
DEF(levent_table                            ,0xffea2d00) // Found @0xffea2d00
DEF(FlashParamsTable                        ,0xffecf87c) // Found @0xffecf87c
DEF(movie_status                            ,0x000054a0) // Found @0xffd0c728
DEF(full_screen_refresh                     ,0x00007370) // Found @0xffd7a970
DEF(canon_menu_active                       ,0x00002a3c) // Found @0xffc6a0cc
DEF(canon_shoot_menu_active                 ,0x000065b5) // Found @0xffd40094
DEF(playrec_mode                            ,0x00002798) // Found @0xffc5d8b0
DEF(zoom_status                             ,0x00009648) // Found @0xffe0d93c
DEF(some_flag_for_af_scan                   ,0x00005848) // Found @0xffd0f094
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 3 int value(s), the first is the zoom focus length.
// there are 7 entries in the table - set NUM_FL to 7
DEF(focus_len_table                         ,0xfffe2990) // Found @0xfffe2990
DEF(zoom_busy                               ,0x00005424) // Found @0xffd09958
DEF(focus_busy                              ,0x00005334) // Found @0xffd06f90
//DEF(recreview_hold                          ,0x00003034) // Found @0xffc758d4, ** != ** stubs_min = 0x0000630a (0x6308+2)
DEF(viewport_buffers                        ,0xffe8bd28) // Found @0xffcb581c
DEF(active_viewport_buffer                  ,0x00004110) // Found @0xffcb5664

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x10361000; }             // Found @0xffc3f020
//void *vid_get_viewport_fb()      { return (void*)0x10648cc0; }             // Found @0xffe569d4
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x2540+0x54)); } // Found @0xffc528c8 & 0xffc52900
//char *camera_jpeg_count_str()    { return (char*)0x0007486c; }             // Found @0xffd71fa0
//long hook_raw_size()             { return 0x00ec04f0; }                    // Found @0xffe59d5c
//int get_flash_params_count(void) { return 0x94; }                          // Found @0xffd2f1f0

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00040000 // Found @0xffe84f2c, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x00080000 // Found @0xffe84f38, levent 0x902
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_PLAYBACK        ,0x00020000 }, // Found @0xffe84ea8, levent 0x601
//    { 0, KEY_POWER           ,0x00800000 }, // Found @0xffe84ec0, levent 0x600
//    { 2, KEY_RIGHT           ,0x00000004 }, // Found @0xffe84ecc, levent 0x07
//    { 2, KEY_SHOOT_FULL      ,0x00000030 }, // Found @0xffe84ee4, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000020 }, // Found @0xffe84ee4, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00000010 }, // Found @0xffe84ed8, levent 0x00
//    { 2, KEY_ZOOM_OUT        ,0x00000040 }, // Found @0xffe84ef0, levent 0x03
//    { 2, KEY_ZOOM_IN         ,0x00000080 }, // Found @0xffe84efc, levent 0x02
//    { 2, KEY_SET             ,0x00000100 }, // Found @0xffe84f08, levent 0x08
//    { 2, KEY_UP              ,0x00100000 }, // Found @0xffe84f44, levent 0x04 (uses inverted logic in physw_status)
//    { 2, KEY_DOWN            ,0x00200000 }, // Found @0xffe84f50, levent 0x05 (uses inverted logic in physw_status)
//    { 2, KEY_LEFT            ,0x00400000 }, // Found @0xffe84f5c, levent 0x06 (uses inverted logic in physw_status)
//    { 2, KEY_MENU            ,0x01000000 }, // Found @0xffe84f74, levent 0x09 (uses inverted logic in physw_status)
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_RAW_ROWPIX    3720 // Found @0xffcea468
//#define CAM_RAW_ROWS      2772 // Found @0xffcea474
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x10000000 // Found @0xffc2931c

// Misc stuff
DEF(ctypes, 0xffe847c6)

// For capt_seq.c
//static long *nrflag = (long*)(0x5830-0x08);  // Found @ ffd10eac & ffd10ec8

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
//NSTUB(CreateJumptable                       ,0xffe59f24) //  1
//NSTUB(_uartr_req                            ,0xffc10744) //111
//NSTUB(AllocateMemory                        ,0xffdfd168) //101
NSTUB(AllocateUncacheableMemory               ,0xffc292d8) //112
NSTUB(Close                                   ,0xffc26108) //101
NSTUB(CreateTask                              ,0xffc0f1a8) //101
NSTUB(DebugAssert                             ,0xffc0f680) //111
NSTUB(DeleteDirectory_Fut                     ,0xffc25b64) //116
NSTUB(DeleteFile_Fut                          ,0xffc25a80) //112
NSTUB(DoAFLock                                ,0xffc27554) //102
NSTUB(EnterToCompensationEVF                  ,0xffc27604) //104
NSTUB(ExecuteEventProcedure                   ,0xffc65820) //104
NSTUB(ExitFromCompensationEVF                 ,0xffc27648) //104
NSTUB(ExitTask                                ,0xffc0f438) //101
NSTUB(ExpCtrlTool_StartContiAE                ,0xffc34ce4) //104
NSTUB(ExpCtrlTool_StopContiAE                 ,0xffc34dbc) //104
NSTUB(Fclose_Fut                              ,0xffc25bfc) //101
NSTUB(Feof_Fut                                ,0xffc25de8) //  1
NSTUB(Fflush_Fut                              ,0xffc25e24) //  1
NSTUB(Fgets_Fut                               ,0xffc25d50) //  1
NSTUB(Fopen_Fut                               ,0xffc25bbc) //101
NSTUB(Fread_Fut                               ,0xffc25ca8) //101
//NSTUB(FreeMemory                            ,0xffdfd160) //101
NSTUB(FreeUncacheableMemory                   ,0xffc29318) //112
NSTUB(Fseek_Fut                               ,0xffc25d9c) //101
NSTUB(Fwrite_Fut                              ,0xffc25cfc) //101
NSTUB(GetBatteryTemperature                   ,0xffc4561c) //102
NSTUB(GetCCDTemperature                       ,0xffc455a8) //102
NSTUB(GetCurrentAvValue                       ,0xffd08810) //102
NSTUB(GetDrive_ClusterSize                    ,0xffc512c0) //  4
//NSTUB(GetDrive_FreeClusters                 ,0xffc51320) //  4            == 0xffc51320
NSTUB(GetDrive_TotalClusters                  ,0xffc512f4) //  3
NSTUB(GetFocusLensSubjectDistance             ,0xffd07b08) //102
NSTUB(GetFocusLensSubjectDistanceFromLens     ,0xffd07f60) //  3
NSTUB(GetImageFolder                          ,0xffcf1428) //106
NSTUB(GetKbdState                             ,0xffc435cc) //109
NSTUB(GetMemInfo                              ,0xffc0a7f8) //115
NSTUB(GetOpticalTemperature                   ,0xffc45694) //102
NSTUB(GetParameterData                        ,0xffd2f1b0) //101
NSTUB(GetPropertyCase                         ,0xffc6952c) //102
NSTUB(GetSystemTime                           ,0xffdfd1c0) //101
NSTUB(GetVRAMHPixelsSize                      ,0xffcb6c54) //102
NSTUB(GetVRAMVPixelsSize                      ,0xffcb6c60) //102
NSTUB(GetZoomLensCurrentPoint                 ,0xffd09cd0) //102
NSTUB(GetZoomLensCurrentPosition              ,0xffdf520c) //102
NSTUB(GiveSemaphore                           ,0xffc0f104) //112
NSTUB(IsStrobeChargeCompleted                 ,0xffca7260) //102
NSTUB(LEDDrive                                ,0xffc42bc4) //103
NSTUB(LocalTime                               ,0xffc63530) //115
NSTUB(LockMainPower                           ,0xffc6ce40) //103
//NSTUB(Lseek                                 ,0xffc26224) //101
NSTUB(MakeDirectory_Fut                       ,0xffc25af4) //116
NSTUB(MoveFocusLensToDistance                 ,0xffe53454) //102
NSTUB(MoveIrisWithAv                          ,0xffdfa8b0) //102
NSTUB(MoveZoomLensWithPoint                   ,0xffdfae40) //102
//NSTUB(NewTaskShell                          ,0xffc68f38) //103
NSTUB(Open                                    ,0xffc2609c) //101
NSTUB(PB2Rec                                  ,0xffc6fa94) //104
NSTUB(PT_MoveDigitalZoomToWide                ,0xffc57170) //102
NSTUB(PT_MoveOpticalZoomAt                    ,0xffc57148) //102
NSTUB(PT_PlaySound                            ,0xffc5f3b0) //  7
NSTUB(PostLogicalEventForNotPowerType         ,0xffc6c670) //103
NSTUB(PostLogicalEventToUI                    ,0xffc6c6bc) //103
NSTUB(PutInNdFilter                           ,0xffdfaca4) //102
NSTUB(PutOutNdFilter                          ,0xffdfacc8) //102
NSTUB(Read                                    ,0xffc0b308) //101
NSTUB(ReadFastDir                             ,0xffdebbf4) //  4
NSTUB(Rec2PB                                  ,0xffc6fad4) //104
NSTUB(RefreshPhysicalScreen                   ,0xffd7b34c) //104
//NSTUB(Remove                                ,0xffc2613c) //  4
NSTUB(RenameFile_Fut                          ,0xffc259ec) //116
NSTUB(Restart                                 ,0xffc2aab0) //106
NSTUB(ScreenLock                              ,0xffd7c4f8) //  3
NSTUB(ScreenUnlock                            ,0xffd7c53c) //  7
NSTUB(SetAE_ShutterSpeed                      ,0xffe55be4) //102
NSTUB(SetAutoShutdownTime                     ,0xffc6ceb4) //103
NSTUB(SetCurrentCaptureModeType               ,0xffc731ec) //101
NSTUB(SetFileAttributes                       ,0xffc26400) //  3
NSTUB(SetFileTimeStamp                        ,0xffc263a4) //  4
NSTUB(SetLogicalEventActive                   ,0xffc6cbb8) //101
NSTUB(SetParameterData                        ,0xffd2f120) //101
NSTUB(SetPropertyCase                         ,0xffc693fc) //102
NSTUB(SleepTask                               ,0xffc2915c) //101
NSTUB(TakeSemaphore                           ,0xffc0f034) //101
NSTUB(TurnOffBackLight                        ,0xffc77f4c) //104
NSTUB(TurnOnBackLight                         ,0xffc77f34) //104
NSTUB(UIFS_WriteFirmInfoToFile                ,0xffd1f924) //101
NSTUB(UnlockAF                                ,0xffc2758c) //102
NSTUB(UnlockMainPower                         ,0xffc6cd94) //103
NSTUB(UnsetZoomForMovie                       ,0xffd3589c) //104
NSTUB(UpdateMBROnFlash                        ,0xffc51140) //105
NSTUB(VbattGet                                ,0xffc22be4) //103
NSTUB(Write                                   ,0xffc26198) //101
NSTUB(WriteSDCard                             ,0xffcfcb1c) //108
NSTUB(_log                                    ,0xffe82328) //111
NSTUB(_log10                                  ,0xffe8126c) //112
NSTUB(_pow                                    ,0xffe813dc) //114
NSTUB(_sqrt                                   ,0xffe83690) //  1
NSTUB(add_ptp_handler                         ,0xffdbeb54) //  3
NSTUB(apex2us                                 ,0xffd7d848) //  4
NSTUB(close                                   ,0xffc0b120) //  1
NSTUB(closedir                                ,0xffdeba50) //  4
NSTUB(err_init_task                           ,0xffc05f50) //111
NSTUB(exmem_alloc                             ,0xffc641d0) //103
NSTUB(free                                    ,0xffc04160) //112
NSTUB(kbd_p1_f                                ,0xffc23ba4) //109
NSTUB(kbd_p1_f_cont                           ,0xffc23bb0) //109
NSTUB(kbd_p2_f                                ,0xffc2345c) //109
NSTUB(kbd_read_keys                           ,0xffc23b2c) //109
NSTUB(kbd_read_keys_r2                        ,0xffc42fb0) //109
NSTUB(lseek                                   ,0xffc26224) //101
NSTUB(malloc                                  ,0xffc04104) //112
NSTUB(memcmp                                  ,0xffc11318) //101
NSTUB(memcpy                                  ,0xffc2e860) //101
NSTUB(memset                                  ,0xffd7c880) //101
NSTUB(mkdir                                   ,0xffc265a4) //109
NSTUB(mktime_ext                              ,0xffc7cd6c) //  1
NSTUB(open                                    ,0xffc0b070) //  1
NSTUB(OpenFastDir                             ,0xffdebaa0) //  4
NSTUB(qsort                                   ,0xffe3c190) //  4
NSTUB(rand                                    ,0xffc11420) //  1
//NSTUB(read                                  ,0xffc0b308) //101
NSTUB(reboot_fw_update                        ,0xffded468) //106
NSTUB(set_control_event                       ,0xffc6c8d8) //111
NSTUB(srand                                   ,0xffc11414) //  1
NSTUB(stat                                    ,0xffc2626c) //109
NSTUB(strcat                                  ,0xffc7c528) //  1
NSTUB(strchr                                  ,0xffc03fe8) //  1
NSTUB(strcmp                                  ,0xffc112d4) //101
NSTUB(strcpy                                  ,0xffc112bc) //101
NSTUB(strftime                                ,0xffc7c774) //113
NSTUB(strlen                                  ,0xffc04034) //101
NSTUB(strncmp                                 ,0xffc03f9c) //  1
NSTUB(strncpy                                 ,0xffc03f60) //  1
NSTUB(strrchr                                 ,0xffc0400c) //  1
NSTUB(strtol                                  ,0xffc2eb40) //101
NSTUB(strtolx                                 ,0xffc2e944) //109
  DEF(task_CaptSeq                            ,0xffc59224) //107
  DEF(task_ExpDrv                             ,0xffc91604) //110
  DEF(task_InitFileModules                    ,0xffc7055c) //107
  DEF(task_MovieRecord                        ,0xffd0c97c) //107
  DEF(task_PhySw                              ,0xffc2378c) //107
NSTUB(time                                    ,0xffc633e4) //109
NSTUB(vsprintf                                ,0xffc11280) //115
//NSTUB(write                                 ,0xffc26198) //101
//NSTUB(GetSDProtect                          ,0xffc23b00) //103
//NSTUB(StartRecModeMenu                      ,0xffc6a0c8) //102
//NSTUB(DispCon_ShowBitmapColorBar            ,0xffc3efec) //102
//NSTUB(ResetZoomLens                         ,0xffdfad94) //102
//NSTUB(ResetFocusLens                        ,0xffdf9d94) //102
//NSTUB(NR_GetDarkSubType                     ,0xffd121bc) //102
//NSTUB(NR_SetDarkSubType                     ,0xffd1210c) //102
//NSTUB(SavePaletteData                       ,0xffe57e88) //102
//NSTUB(GUISrv_StartGUISystem                 ,0xffc7bf60) //101
