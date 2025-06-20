// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R43 (DRYOS version 2.3, release #0043)
//   Firmware Ver GM1.00E
//   Canon PowerShot A495

// Values for makefile.inc
//   PLATFORMOSVER = 43
//   PLATFORMID = 12783 (0x31ef) // Found @ 0xfffe0130
//   MAXRAMADDR = 0x01ffffff
//   KEYSYS = d4a                // Found @ 0xffff1a2c
//   NEED_ENCODED_DISKBOOT = 4   // Found @ 0xffff1a3c

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NHSTUB(SetScriptMode                        ,0xffc6cc58) //101        *** != 0xffc00f70
NHSTUB(kbd_pwr_off                            ,0xffc435e4) //  2 64%
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ffc70720 -> ffc6d288 -> ffd2e1e4 -> ffe0ab10 -> ffecf748
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x0002e7f4) // Found @0xffc23b2c
DEF(physw_run                               ,0x00001bf0) // Found @0xffc23790
DEF(physw_sleep_delay                       ,0x00001bf8) // Found @0xffc23790
DEF(levent_table                            ,0xffea2dc0) // Found @0xffea2dc0
DEF(FlashParamsTable                        ,0xffecf93c) // Found @0xffecf93c
DEF(movie_status                            ,0x000054a0) // Found @0xffd0c7d8
DEF(full_screen_refresh                     ,0x00007370) // Found @0xffd7aa20
DEF(canon_menu_active                       ,0x00002a3c) // Found @0xffc6a11c
DEF(canon_shoot_menu_active                 ,0x000065b5) // Found @0xffd40144
DEF(playrec_mode                            ,0x00002798) // Found @0xffc5d900
DEF(zoom_status                             ,0x00009648) // Found @0xffe0d9ec
DEF(some_flag_for_af_scan                   ,0x00005848) // Found @0xffd0f144
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 3 int value(s), the first is the zoom focus length.
// there are 7 entries in the table - set NUM_FL to 7
DEF(focus_len_table                         ,0xfffe2990) // Found @0xfffe2990
DEF(zoom_busy                               ,0x00005424) // Found @0xffd09a08
DEF(focus_busy                              ,0x00005334) // Found @0xffd07040
//DEF(recreview_hold                          ,0x00003034) // Found @0xffc75924, ** != ** stubs_min = 0x0000630a (0x6308+2)
DEF(viewport_buffers                        ,0xffe8bde8) // Found @0xffcb586c
DEF(active_viewport_buffer                  ,0x00004110) // Found @0xffcb56b4

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x10361000; }             // Found @0xffc3f020
//void *vid_get_viewport_fb()      { return (void*)0x10648cc0; }             // Found @0xffe56a84
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x2540+0x54)); } // Found @0xffc52918 & 0xffc52950
//char *camera_jpeg_count_str()    { return (char*)0x0007486c; }             // Found @0xffd72050
//long hook_raw_size()             { return 0x00ec04f0; }                    // Found @0xffe59e0c
//int get_flash_params_count(void) { return 0x94; }                          // Found @0xffd2f2a0

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00040000 // Found @0xffe84fec, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x00080000 // Found @0xffe84ff8, levent 0x902
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_PLAYBACK        ,0x00020000 }, // Found @0xffe84f68, levent 0x601
//    { 0, KEY_POWER           ,0x00800000 }, // Found @0xffe84f80, levent 0x600
//    { 2, KEY_RIGHT           ,0x00000004 }, // Found @0xffe84f8c, levent 0x07
//    { 2, KEY_SHOOT_FULL      ,0x00000030 }, // Found @0xffe84fa4, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000020 }, // Found @0xffe84fa4, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00000010 }, // Found @0xffe84f98, levent 0x00
//    { 2, KEY_ZOOM_OUT        ,0x00000040 }, // Found @0xffe84fb0, levent 0x03
//    { 2, KEY_ZOOM_IN         ,0x00000080 }, // Found @0xffe84fbc, levent 0x02
//    { 2, KEY_SET             ,0x00000100 }, // Found @0xffe84fc8, levent 0x08
//    { 2, KEY_UP              ,0x00100000 }, // Found @0xffe85004, levent 0x04 (uses inverted logic in physw_status)
//    { 2, KEY_DOWN            ,0x00200000 }, // Found @0xffe85010, levent 0x05 (uses inverted logic in physw_status)
//    { 2, KEY_LEFT            ,0x00400000 }, // Found @0xffe8501c, levent 0x06 (uses inverted logic in physw_status)
//    { 2, KEY_MENU            ,0x01000000 }, // Found @0xffe85034, levent 0x09 (uses inverted logic in physw_status)
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_RAW_ROWPIX    3720 // Found @0xffcea4b8
//#define CAM_RAW_ROWS      2772 // Found @0xffcea4c4
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x10000000 // Found @0xffc2931c

// Misc stuff
DEF(ctypes, 0xffe84886)

// For capt_seq.c
DEF(_nrflag,0x5828) // Found @ ffd10f5c (0x5830) & ffd10f7c (-0x08)
//static long *nrflag = (long*)(0x5830-0x08);  // Found @ ffd10f5c & ffd10f78

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
//NHSTUB(CreateJumptable                      ,0xffe59fd4) //  1
//NHSTUB(_uartr_req                           ,0xffc10744) //111
//NHSTUB(AllocateMemory                       ,0xffdfd218) //101
NHSTUB(AllocateUncacheableMemory              ,0xffc292d8) //112
NHSTUB(Close                                  ,0xffc26108) //101
NHSTUB(CreateTask                             ,0xffc0f1a8) //101
NHSTUB(DebugAssert                            ,0xffc0f680) //111
NHSTUB(DeleteDirectory_Fut                    ,0xffc25b64) //116
NHSTUB(DeleteFile_Fut                         ,0xffc25a80) //112
NHSTUB(DoAFLock                               ,0xffc27554) //102
NHSTUB(EnterToCompensationEVF                 ,0xffc27604) //104
NHSTUB(ExecuteEventProcedure                  ,0xffc65870) //104
NHSTUB(ExitFromCompensationEVF                ,0xffc27648) //104
NHSTUB(ExitTask                               ,0xffc0f438) //101
NHSTUB(ExpCtrlTool_StartContiAE               ,0xffc34ce4) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xffc34dbc) //104
NHSTUB(Fclose_Fut                             ,0xffc25bfc) //101
NHSTUB(Feof_Fut                               ,0xffc25de8) //  1
NHSTUB(Fflush_Fut                             ,0xffc25e24) //  1
NHSTUB(Fgets_Fut                              ,0xffc25d50) //  1
NHSTUB(Fopen_Fut                              ,0xffc25bbc) //101
NHSTUB(Fread_Fut                              ,0xffc25ca8) //101
//NHSTUB(FreeMemory                           ,0xffdfd210) //101
NHSTUB(FreeUncacheableMemory                  ,0xffc29318) //112
NHSTUB(Fseek_Fut                              ,0xffc25d9c) //101
NHSTUB(Fwrite_Fut                             ,0xffc25cfc) //101
NHSTUB(GetBatteryTemperature                  ,0xffc4561c) //102
NHSTUB(GetCCDTemperature                      ,0xffc455a8) //102
NHSTUB(GetCurrentAvValue                      ,0xffd088c0) //102
NHSTUB(GetDrive_ClusterSize                   ,0xffc512c0) //  4
//NHSTUB(GetDrive_FreeClusters                ,0xffc51320) //  4            == 0xffc51320
NHSTUB(GetDrive_TotalClusters                 ,0xffc512f4) //  3
NHSTUB(GetFocusLensSubjectDistance            ,0xffd07bb8) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xffd08010) //  3
NHSTUB(GetImageFolder                         ,0xffcf1478) //106
NHSTUB(GetKbdState                            ,0xffc435cc) //109
NHSTUB(GetMemInfo                             ,0xffc0a7f8) //115
NHSTUB(GetOpticalTemperature                  ,0xffc45694) //102
NHSTUB(GetParameterData                       ,0xffd2f260) //101
NHSTUB(GetPropertyCase                        ,0xffc6957c) //102
NHSTUB(GetSystemTime                          ,0xffdfd270) //101
NHSTUB(GetVRAMHPixelsSize                     ,0xffcb6ca4) //102
NHSTUB(GetVRAMVPixelsSize                     ,0xffcb6cb0) //102
NHSTUB(GetZoomLensCurrentPoint                ,0xffd09d80) //102
NHSTUB(GetZoomLensCurrentPosition             ,0xffdf52bc) //102
NHSTUB(GiveSemaphore                          ,0xffc0f104) //112
NHSTUB(IsStrobeChargeCompleted                ,0xffca72b0) //102
NHSTUB(LEDDrive                               ,0xffc42bc4) //103
NHSTUB(LocalTime                              ,0xffc63580) //115
NHSTUB(LockMainPower                          ,0xffc6ce90) //103
//NHSTUB(Lseek                                ,0xffc26224) //101
NHSTUB(MakeDirectory_Fut                      ,0xffc25af4) //116
NHSTUB(MoveFocusLensToDistance                ,0xffe53504) //102
NHSTUB(MoveIrisWithAv                         ,0xffdfa960) //102
NHSTUB(MoveZoomLensWithPoint                  ,0xffdfaef0) //102
//NHSTUB(NewTaskShell                         ,0xffc68f88) //103
NHSTUB(Open                                   ,0xffc2609c) //101
NHSTUB(PB2Rec                                 ,0xffc6fae4) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xffc571c0) //102
NHSTUB(PT_MoveOpticalZoomAt                   ,0xffc57198) //102
NHSTUB(PT_PlaySound                           ,0xffc5f400) //  7
NHSTUB(PostLogicalEventForNotPowerType        ,0xffc6c6c0) //103
NHSTUB(PostLogicalEventToUI                   ,0xffc6c70c) //103
NHSTUB(PutInNdFilter                          ,0xffdfad54) //102
NHSTUB(PutOutNdFilter                         ,0xffdfad78) //102
NHSTUB(Read                                   ,0xffc0b308) //101
NHSTUB(ReadFastDir                            ,0xffdebca4) //  4
NHSTUB(Rec2PB                                 ,0xffc6fb24) //104
NHSTUB(RefreshPhysicalScreen                  ,0xffd7b3fc) //104
//NHSTUB(Remove                               ,0xffc2613c) //  4
NHSTUB(RenameFile_Fut                         ,0xffc259ec) //116
NHSTUB(Restart                                ,0xffc2aab0) //106
NHSTUB(ScreenLock                             ,0xffd7c5a8) //  3
NHSTUB(ScreenUnlock                           ,0xffd7c5ec) //  7
NHSTUB(SetAE_ShutterSpeed                     ,0xffe55c94) //102
NHSTUB(SetAutoShutdownTime                    ,0xffc6cf04) //103
NHSTUB(SetCurrentCaptureModeType              ,0xffc7323c) //101
NHSTUB(SetFileAttributes                      ,0xffc26400) //  3
NHSTUB(SetFileTimeStamp                       ,0xffc263a4) //  4
NHSTUB(SetLogicalEventActive                  ,0xffc6cc08) //101
NHSTUB(SetParameterData                       ,0xffd2f1d0) //101
NHSTUB(SetPropertyCase                        ,0xffc6944c) //102
NHSTUB(SleepTask                              ,0xffc2915c) //101
NHSTUB(TakeSemaphore                          ,0xffc0f034) //101
NHSTUB(TurnOffBackLight                       ,0xffc77f9c) //104
NHSTUB(TurnOnBackLight                        ,0xffc77f84) //104
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xffd1f9d4) //101
NHSTUB(UnlockAF                               ,0xffc2758c) //102
NHSTUB(UnlockMainPower                        ,0xffc6cde4) //103
NHSTUB(UnsetZoomForMovie                      ,0xffd3594c) //104
NHSTUB(UpdateMBROnFlash                       ,0xffc51140) //105
NHSTUB(VbattGet                               ,0xffc22be4) //103
NHSTUB(Write                                  ,0xffc26198) //101
NHSTUB(WriteSDCard                            ,0xffcfcbcc) //108
NHSTUB(_log                                   ,0xffe823e8) //111
NHSTUB(_log10                                 ,0xffe8132c) //112
NHSTUB(_pow                                   ,0xffe8149c) //114
NHSTUB(_sqrt                                  ,0xffe83750) //  1
NHSTUB(add_ptp_handler                        ,0xffdbec04) //  3
NHSTUB(apex2us                                ,0xffd7d8f8) //  4
NHSTUB(close                                  ,0xffc0b120) //  1
NHSTUB(closedir                               ,0xffdebb00) //  4
NHSTUB(err_init_task                          ,0xffc05f50) //111
NHSTUB(exmem_alloc                            ,0xffc64220) //103
NHSTUB(exmem_free                             ,0xffc64298) //103
NHSTUB(free                                   ,0xffc04160) //112
NHSTUB(kbd_p1_f                               ,0xffc23ba4) //109
NHSTUB(kbd_p1_f_cont                          ,0xffc23bb0) //109
NHSTUB(kbd_p2_f                               ,0xffc2345c) //109
NHSTUB(kbd_read_keys                          ,0xffc23b2c) //109
NHSTUB(kbd_read_keys_r2                       ,0xffc42fb0) //109
NHSTUB(lseek                                  ,0xffc26224) //101
NHSTUB(malloc                                 ,0xffc04104) //112
NHSTUB(memcmp                                 ,0xffc11318) //101
NHSTUB(memcpy                                 ,0xffc2e860) //101
NHSTUB(memset                                 ,0xffd7c930) //101
NHSTUB(mkdir                                  ,0xffc265a4) //109
NHSTUB(mktime_ext                             ,0xffc7cdbc) //  1
NHSTUB(open                                   ,0xffc0b070) //  1
NHSTUB(OpenFastDir                            ,0xffdebb50) //  4
NHSTUB(qsort                                  ,0xffe3c240) //  4
NHSTUB(rand                                   ,0xffc11420) //  1
//NHSTUB(read                                 ,0xffc0b308) //101
NHSTUB(realloc                                ,0xffd7c9ac) //115
NHSTUB(reboot_fw_update                       ,0xffded518) //106
NHSTUB(set_control_event                      ,0xffc6c928) //111
NHSTUB(srand                                  ,0xffc11414) //  1
NHSTUB(stat                                   ,0xffc2626c) //109
NHSTUB(strcat                                 ,0xffc7c578) //  1
NHSTUB(strchr                                 ,0xffc03fe8) //  1
NHSTUB(strcmp                                 ,0xffc112d4) //101
NHSTUB(strcpy                                 ,0xffc112bc) //101
NHSTUB(strftime                               ,0xffc7c7c4) //113
NHSTUB(strlen                                 ,0xffc04034) //101
NHSTUB(strncmp                                ,0xffc03f9c) //  1
NHSTUB(strncpy                                ,0xffc03f60) //  1
NHSTUB(strrchr                                ,0xffc0400c) //  1
NHSTUB(strtol                                 ,0xffc2eb40) //101
NHSTUB(strtolx                                ,0xffc2e944) //109
   DEF(task_CaptSeq                           ,0xffc59274) //107
   DEF(task_ExpDrv                            ,0xffc91654) //110
   DEF(task_FileWrite                         ,0xffde677c) //107
   DEF(task_InitFileModules                   ,0xffc705ac) //107
   DEF(task_MovieRecord                       ,0xffd0ca2c) //107
   DEF(task_PhySw                             ,0xffc2378c) //107
NHSTUB(time                                   ,0xffc63434) //109
NHSTUB(vsprintf                               ,0xffc11280) //115
//NHSTUB(write                                ,0xffc26198) //101
//NHSTUB(EngDrvIn                             ,0xffc249f0) //102
//NHSTUB(EngDrvOut                            ,0xffc249d8) //102
//NHSTUB(EngDrvRead                           ,0xffc249f8) //102
//NHSTUB(EngDrvBits                           ,0xffc24a0c) //102
//NHSTUB(GetSDProtect                         ,0xffc23b00) //103
//NHSTUB(StartRecModeMenu                     ,0xffc6a118) //102
//NHSTUB(DispCon_ShowBitmapColorBar           ,0xffc3efec) //102
//NHSTUB(ResetZoomLens                        ,0xffdfae44) //102
//NHSTUB(ResetFocusLens                       ,0xffdf9e44) //102
//NHSTUB(NR_GetDarkSubType                    ,0xffd1226c) //102
//NHSTUB(NR_SetDarkSubType                    ,0xffd121bc) //102
//NHSTUB(SavePaletteData                      ,0xffe57f38) //102
//NHSTUB(GUISrv_StartGUISystem                ,0xffc7bfb0) //101
