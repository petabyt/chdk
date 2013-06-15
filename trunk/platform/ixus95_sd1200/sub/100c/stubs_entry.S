// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R31 (DRYOS version 2.3, release #0031)
//   Firmware Ver GM1.00C
//   Canon DIGITAL IXUS 95 IS

// Values for makefile.inc
//   PLATFORMOSVER = 31
//   PLATFORMID = 12740 (0x31c4) // Found @ 0xfffe0130
//   MAXRAMADDR = 0x03ffffff
//   KEYSYS = d4                 // Found @ 0xffff1be4
//   NEED_ENCODED_DISKBOOT = 2   // Found @ 0xffff1bf4

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NHSTUB(DoAFLock                             ,0xffc15298) //102        *** != 0xffc47b8c
//NHSTUB(SetScriptMode                        ,0xffc5d99c) //101        *** != 0x00000000
//NHSTUB(UnlockAF                             ,0xffc152d0) //102        *** != 0xffc47b9c
//NHSTUB(WriteSDCard                          ,0xffce4300) //108        *** != 0xffce4118
//NHSTUB(kbd_read_keys                        ,0xffc11d70) //109        *** != 0xffc11d80
//NHSTUB(kbd_pwr_off                          ,0xffc30e1c) //  2 64%    *** != 0x00000000
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ffc614e8 -> ffc5dfb8 -> ffd1af7c -> ffdf7360 -> ffeb35d8
// Mode  2598 in firmware but not in current modemap
// Current modemap entry not found in firmware - MODE_VIDEO_COLOR_SWAP     2600
// Current modemap entry not found in firmware - MODE_VIDEO_COLOR_ACCENT   2599
// Current modemap entry not found in firmware - MODE_VIDEO_STD            2601
// Current modemap entry not found in firmware - MODE_STITCH              16906
// Current modemap entry not found in firmware - MODE_SCN_COLOR_SWAP      16924
// Current modemap entry not found in firmware - MODE_SCN_COLOR_ACCENT    16923
// Current modemap entry not found in firmware - MODE_M                   32769

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x0000c338) // Found @0xffc11d70
DEF(physw_run                               ,0x00001c34) // Found @0xffc119e4
DEF(physw_sleep_delay                       ,0x00001c32) // Found @0xffc119e4
DEF(levent_table                            ,0xffe8c7c4) // Found @0xffe8c7c4
DEF(FlashParamsTable                        ,0xffeb37a8) // Found @0xffeb37a8
//DEF(movie_status                            ,0x00005680) // Found @0xffcf8060, ** != ** stubs_min = 0x00005684 (0x5648+0x3c)
DEF(canon_menu_active                       ,0x00002bb0) // Found @0xffc5adf8
DEF(canon_shoot_menu_active                 ,0x0000681d) // Found @0xffd2a1ac
DEF(playrec_mode                            ,0x00002924) // Found @0xffc4e4ec
DEF(zoom_status                             ,0x000096b4) // Found @0xffdf8b90
DEF(some_flag_for_af_scan                   ,0x00005b4c) // Found @0xffcfa7ac
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 3 int value(s), the first is the zoom focus length.
// there are 7 entries in the table - set NUM_FL to 7
DEF(focus_len_table                         ,0xfffe2a8c) // Found @0xfffe2a8c
DEF(zoom_busy                               ,0x000055b0) // Found @0xffcf475c
DEF(focus_busy                              ,0x000054a8) // Found @0xffcef5cc
//DEF(recreview_hold                          ,0x00003110) // Found @0xffc6677c, ** != ** stubs_min = 0x0000660c (0x6548+0xC4)
// Palette colour tables  found @ 0xffe9ab78
DEF(active_palette_buffer                   ,0x000073e8) // Found @0xffd60078
DEF(palette_buffer_ptr                      ,0x000073fc) // Found @0xffd5ff2c
// Offset from start of palette_buffer to color data = 16 (Found @0xffd5edc0)
// Camera has 2 RAW buffers @ 0x40f30d7c & 0x424b358c
//  Note: active buffer --> raw_buffers[ active_raw_buffer   *3]
//        other buffer  --> raw_buffers[(active_raw_buffer^1)*3]
DEF(raw_buffers                             ,0xffe70c18) // Found @0xffe70c18
DEF(active_raw_buffer                       ,0x00002890) // Found @0xffc4b480

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x403f1000; }             // Found @0xffc2c9a8
//void *vid_get_viewport_fb()      { return (void*)0x4076f088; }             // Found @0xffe38210
DEF(viewport_fb_d                           ,0x000026b0) // Found 0x2658 (@0xffc40f88) + 0x58 (@0xffc40fc0)
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x2658+0x58)); } // Found @0xffc40f88 & 0xffc40fc0
DEF(jpeg_count_str                          ,0x0002f1d4) // Found @0xffd57dc0
//char *camera_jpeg_count_str()    { return (char*)0x0002f1d4; }             // Found @0xffd57dc0
//long hook_raw_size()             { return 0x00ec04f0; }                    // Found @0xffe3a7a0
//int get_flash_params_count(void) { return 0x7a; }                          // Found @0xffd1c038

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffe65ad0, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x00040000 // Found @0xffe65adc, levent 0x902
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 1, KEY_POWER           ,0x40000000 }, // Found @0xffe65a1c, levent 0x600
//    { 2, KEY_SHOOT_FULL      ,0x00000003 }, // Found @0xffe65a34, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000002 }, // Found @0xffe65a34, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00000001 }, // Found @0xffe65a28, levent 0x00
//    { 2, KEY_ZOOM_IN         ,0x00000004 }, // Found @0xffe65a40, levent 0x02
//    { 2, KEY_ZOOM_OUT        ,0x00000008 }, // Found @0xffe65a4c, levent 0x03
//    { 2, KEY_LEFT            ,0x00000010 }, // Found @0xffe65a58, levent 0x06
//    { 2, KEY_RIGHT           ,0x00000020 }, // Found @0xffe65a64, levent 0x07
//    { 2, KEY_DOWN            ,0x00000040 }, // Found @0xffe65a70, levent 0x05
//    { 2, KEY_UP              ,0x00000080 }, // Found @0xffe65a7c, levent 0x04
//    { 2, KEY_SET             ,0x00000100 }, // Found @0xffe65a88, levent 0x08
//    { 2, KEY_DISPLAY         ,0x00000200 }, // Found @0xffe65a94, levent 0x0a
//    { 2, KEY_MENU            ,0x00000400 }, // Found @0xffe65aa0, levent 0x09
//    { 2, KEY_PLAYBACK        ,0x00000800 }, // Found @0xffe65aac, levent 0x601
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_RAW_ROWPIX    3720 // Found @0xffcc787c
//#define CAM_RAW_ROWS      2772 // Found @0xffcc7884
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xffc172cc

// Misc stuff
DEF(ctypes, 0xffe648f6)

// For capt_seq.c
DEF(_nrflag,0x5b30) // Found @ ffcfc5c8 (0x5b38) & ffcfc5e8 (-0x08)
//static long *nrflag = (long*)(0x5b38-0x08);  // Found @ ffcfc5c8 & ffcfc5e4

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
//NHSTUB(CreateJumptable                      ,0xffe3b1e0) //  1
//NHSTUB(_uartr_req                           ,0xffc0c34c) //111
//NHSTUB(AllocateMemory                       ,0xffded8e8) //101
NHSTUB(AllocateUncacheableMemory              ,0xffc17288) //112
NHSTUB(Close                                  ,0xffc13c3c) //101
NHSTUB(CreateTask                             ,0xffc0afac) //101
NHSTUB(DebugAssert                            ,0xffc0b284) //111
NHSTUB(DeleteDirectory_Fut                    ,0xffc135cc) //116
NHSTUB(DeleteFile_Fut                         ,0xffc134e8) //112
NHSTUB(EnterToCompensationEVF                 ,0xffc15348) //104
NHSTUB(ExecuteEventProcedure                  ,0xffc565a8) //104
NHSTUB(ExitFromCompensationEVF                ,0xffc1538c) //104
NHSTUB(ExitTask                               ,0xffc0b23c) //101
NHSTUB(ExpCtrlTool_StartContiAE               ,0xffc1fcc4) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xffc1fe08) //104
NHSTUB(Fclose_Fut                             ,0xffc13664) //101
NHSTUB(Feof_Fut                               ,0xffc13850) //  1
NHSTUB(Fflush_Fut                             ,0xffc1388c) //  1
NHSTUB(Fgets_Fut                              ,0xffc137b8) //  1
NHSTUB(Fopen_Fut                              ,0xffc13624) //101
NHSTUB(Fread_Fut                              ,0xffc13710) //101
//NHSTUB(FreeMemory                           ,0xffded8e0) //101
NHSTUB(FreeUncacheableMemory                  ,0xffc172c8) //112
NHSTUB(Fseek_Fut                              ,0xffc13804) //101
NHSTUB(Fwrite_Fut                             ,0xffc13764) //101
NHSTUB(GetBatteryTemperature                  ,0xffc338cc) //102
NHSTUB(GetCCDTemperature                      ,0xffc33858) //102
NHSTUB(GetCurrentAvValue                      ,0xffcf1384) //102
NHSTUB(GetDrive_ClusterSize                   ,0xffc3f81c) //  5
NHSTUB(GetDrive_FreeClusters                  ,0xffc3f874) //  5
NHSTUB(GetDrive_TotalClusters                 ,0xffc3f848) //  5
NHSTUB(GetFocusLensSubjectDistance            ,0xffcf0434) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xffcf0810) //  3
NHSTUB(GetKbdState                            ,0xffc30e04) //109
NHSTUB(GetMemInfo                             ,0xffc03be4) //115
NHSTUB(GetOpticalTemperature                  ,0xffc33940) //102
NHSTUB(GetParameterData                       ,0xffd1bff8) //101
NHSTUB(GetPropertyCase                        ,0xffc5a2e8) //102
NHSTUB(GetSystemTime                          ,0xffded940) //101
NHSTUB(GetVRAMHPixelsSize                     ,0xffc966a8) //102
NHSTUB(GetVRAMVPixelsSize                     ,0xffc966b4) //102
NHSTUB(GetZoomLensCurrentPoint                ,0xffcf4ad4) //102
NHSTUB(GetZoomLensCurrentPosition             ,0xffde56b4) //102
NHSTUB(GiveSemaphore                          ,0xffc16ca4) //112
NHSTUB(IsStrobeChargeCompleted                ,0xffc88190) //102
NHSTUB(LEDDrive                               ,0xffc3043c) //103
NHSTUB(LocalTime                              ,0xffc5426c) //115
NHSTUB(LockMainPower                          ,0xffc5dbd0) //103
//NHSTUB(Lseek                                ,0xffc13d7c) //101
NHSTUB(MakeDirectory_Fut                      ,0xffc1355c) //116
NHSTUB(MoveFocusLensToDistance                ,0xffe34c40) //102
NHSTUB(MoveIrisWithAv                         ,0xffdea9c4) //102
NHSTUB(MoveZoomLensWithPoint                  ,0xffdeaf4c) //102
//NHSTUB(NewTaskShell                         ,0xffc59d94) //103
NHSTUB(Open                                   ,0xffc13c14) //101
NHSTUB(PB2Rec                                 ,0xffc608a0) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xffc47b54) //102
NHSTUB(PT_MoveOpticalZoomAt                   ,0xffc47b2c) //102
NHSTUB(PT_PlaySound                           ,0xffc47764) //102
NHSTUB(PostLogicalEventForNotPowerType        ,0xffc5d1f8) //103
NHSTUB(PostLogicalEventToUI                   ,0xffc5d244) //103
NHSTUB(PutInNdFilter                          ,0xffdeadb0) //102
NHSTUB(PutOutNdFilter                         ,0xffdeadd4) //102
NHSTUB(Read                                   ,0xffc09ae4) //101
NHSTUB(ReadFastDir                            ,0xffdd7a18) //  1
NHSTUB(Rec2PB                                 ,0xffc608e0) //104
NHSTUB(RefreshPhysicalScreen                  ,0xffd64c80) //104
//NHSTUB(Remove                               ,0xffc13c84) //  1
NHSTUB(RenameFile_Fut                         ,0xffc13494) //  1
NHSTUB(Restart                                ,0xffc189d8) //106
NHSTUB(SetAE_ShutterSpeed                     ,0xffe37420) //102
NHSTUB(SetAutoShutdownTime                    ,0xffc5dc44) //103
NHSTUB(SetCurrentCaptureModeType              ,0xffc6421c) //101
NHSTUB(SetFileAttributes                      ,0xffc13f68) //  1
NHSTUB(SetFileTimeStamp                       ,0xffc13f18) //  1
NHSTUB(SetLogicalEventActive                  ,0xffc5d94c) //101
NHSTUB(SetParameterData                       ,0xffd1bf68) //101
NHSTUB(SetPropertyCase                        ,0xffc5a1e4) //102
NHSTUB(SleepTask                              ,0xffc16f0c) //101
NHSTUB(TakeSemaphore                          ,0xffc16bd4) //101
NHSTUB(TurnOffBackLight                       ,0xffc68aa8) //104
NHSTUB(TurnOnBackLight                        ,0xffc68a90) //104
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xffd0d51c) //103
NHSTUB(UnlockMainPower                        ,0xffc5db24) //103
NHSTUB(UnsetZoomForMovie                      ,0xffd21b70) //104
NHSTUB(UpdateMBROnFlash                       ,0xffc3f674) //105
NHSTUB(VbattGet                               ,0xffc10644) //103
NHSTUB(Write                                  ,0xffc13ce8) //101
NHSTUB(_log                                   ,0xffe61ec0) //111
NHSTUB(_log10                                 ,0xffe60b4c) //112
NHSTUB(_pow                                   ,0xffe60cbc) //114
NHSTUB(_sqrt                                  ,0xffe63a64) //  1
NHSTUB(add_ptp_handler                        ,0xffdaa1a0) //  3
NHSTUB(apex2us                                ,0xffd65d38) //  4
NHSTUB(close                                  ,0xffc098fc) //  1
NHSTUB(closedir                               ,0xffdd7ae8) //  1
NHSTUB(err_init_task                          ,0xffc04e2c) //111
NHSTUB(exmem_alloc                            ,0xffc54ea0) //103
NHSTUB(exmem_free                             ,0xffc54f18) //103
NHSTUB(free                                   ,0xffc03a3c) //112
NHSTUB(kbd_p1_f                               ,0xffc11dec) //109
NHSTUB(kbd_p1_f_cont                          ,0xffc11df8) //109
NHSTUB(kbd_p2_f                               ,0xffc116b0) //109
NHSTUB(kbd_read_keys_r2                       ,0xffc30824) //109
NHSTUB(lseek                                  ,0xffc13d7c) //101
NHSTUB(malloc                                 ,0xffc03968) //112
NHSTUB(memcmp                                 ,0xffc0cc5c) //101
NHSTUB(memcpy                                 ,0xffc6cc38) //101
NHSTUB(memset                                 ,0xffd65020) //101
NHSTUB(mkdir                                  ,0xffc13fe0) //109
NHSTUB(mktime_ext                             ,0xffc6d4a4) //  1
NHSTUB(open                                   ,0xffc0984c) //  1
NHSTUB(OpenFastDir                            ,0xffdd7984) //  1
NHSTUB(qsort                                  ,0xffe1cc78) //  1
NHSTUB(rand                                   ,0xffc0cd64) //  1
//NHSTUB(read                                 ,0xffc09ae4) //101
NHSTUB(realloc                                ,0xffc03b1c) //115
NHSTUB(reboot_fw_update                       ,0xffddb4fc) //106
NHSTUB(set_control_event                      ,0xffc5d680) //111
NHSTUB(srand                                  ,0xffc0cd58) //  1
NHSTUB(stat                                   ,0xffc13e48) //  1
NHSTUB(strcat                                 ,0xffc6ca4c) //  1
NHSTUB(strchr                                 ,0xffc6cad4) //  1
NHSTUB(strcmp                                 ,0xffc0cbf4) //101
NHSTUB(strcpy                                 ,0xffc0cbdc) //101
NHSTUB(strftime                               ,0xffc6ceac) //  1
NHSTUB(strlen                                 ,0xffc0cc38) //101
NHSTUB(strncmp                                ,0xffc6ca88) //  1
NHSTUB(strncpy                                ,0xffc1cac0) //  1
NHSTUB(strrchr                                ,0xffd64ff8) //  1
NHSTUB(strtol                                 ,0xffc1ccf8) //101
NHSTUB(strtolx                                ,0xffc1cafc) //109
   DEF(task_CaptSeq                           ,0xffc49fe0) //110
   DEF(task_ExpDrv                            ,0xffc7ee88) //110
   DEF(task_InitFileModules                   ,0xffc61374) //110
   DEF(task_MovieRecord                       ,0xffcf82b4) //110
   DEF(task_PhySw                             ,0xffc119e0) //110
NHSTUB(time                                   ,0xffc54120) //109
NHSTUB(vsprintf                               ,0xffc0cba0) //115
//NHSTUB(write                                ,0xffc13ce8) //101
//NHSTUB(EngDrvIn                             ,0xffc12c20) //102
//NHSTUB(EngDrvOut                            ,0xffc12c08) //102
//NHSTUB(EngDrvRead                           ,0xffc12c28) //102
//NHSTUB(EngDrvBits                           ,0xffc12c3c) //102
//NHSTUB(GetSDProtect                         ,0xffc11d48) //103
//NHSTUB(StartRecModeMenu                     ,0xffc5adf4) //102
//NHSTUB(DispCon_ShowBitmapColorBar           ,0xffc2c974) //102
//NHSTUB(ResetZoomLens                        ,0xffdeaea0) //102
//NHSTUB(ResetFocusLens                       ,0xffde9e08) //102
//NHSTUB(NR_GetDarkSubType                    ,0xffcfd7d4) //102
//NHSTUB(NR_SetDarkSubType                    ,0xffcfd734) //102
//NHSTUB(SavePaletteData                      ,0xffe3953c) //102
