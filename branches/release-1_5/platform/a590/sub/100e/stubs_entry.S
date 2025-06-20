// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R23 (DRYOS version 2.3, release #0023)
//   Firmware Ver GM1.00E   // Found @ 0xffc5cbc8, "GM1.00E" @ 0xffc5cbd5
//   Firmware build timestamp: Jan  8 2008 16:57:22
//   Canon PowerShot A590 IS

// Values for makefile.inc
//   DIGIC = 30# DIGIC III
//   PLATFORMOSVER = 23
//   PLATFORMID = 12662# (0x3176) Found @ 0xfffe0130
//   MAXRAMADDR = 0x01ffffff
//   MEMISOSTART = 0x000a5304
//   KEYSYS = d3enc# Found @ 0xffff1ad8
//   NEED_ENCODED_DISKBOOT = 1# Found @ 0xffff1ab8
//   ARAM_HEAP_START = 0x2ce000# Found @ 0xffdf2578
//   ARAM_HEAP_SIZE  = 0x32000# Found @ 0xffdf2538

// Detected address ranges:
// ROM      0xffc00000 - 0xffffffff (4194304 bytes)
// RAM data 0x00001900 - 0x0000dc48 copied from 0xffed0d74 (  49992 bytes)

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NHSTUB(kbd_pwr_off                          ,0xffc356b8) //  2 67%    *** != 0xffc356c8
NHSTUB(kbd_pwr_on                             ,0xffc35678) //  2 86%

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ffdfe964 -> ffeaed68
// Mode 32791 in firmware but not in current modemap

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x0000f11c) // Found @0xffc11c30
DEF(physw_run                               ,0x00001bf0) // Found @0xffc118cc
DEF(physw_sleep_delay                       ,0x00001bee) // Found @0xffc118cc
DEF(levent_table                            ,0xffe8de18) // Found @0xffe8de18
DEF(FlashParamsTable                        ,0xffeaef24) // Found @0xffeaef24
DEF(movie_status                            ,0x000053c8) // Found @0xffc4b958
DEF(canon_menu_active                       ,0x00008d20) // Found @0xffd29ef8
DEF(canon_shoot_menu_active                 ,0x00009641) // Found @0xffd444a4
DEF(playrec_mode                            ,0x00005538) // Found @0xffc52108
DEF(zoom_status                             ,0x0000bfbc) // Found @0xffe00164
DEF(some_flag_for_af_scan                   ,0x0000bd3c) // Found @0xffdee828
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 3 int value(s), the first is the zoom focus length.
// there are 8 entries in the table - set NUM_FL to 8
DEF(focus_len_table                         ,0xfffe29ac) // Found @0xfffe29ac
DEF(zoom_busy                               ,0x00008050) // Found @0xffd0f95c
//DEF(focus_busy                              ,0x00007f4c) // Found @0xffd0a804, ** != ** stubs_min = 0x00009d50 (0x9D50)
//DEF(recreview_hold                          ,0x00005d34) // Found @0xffc6a6e4, ** != ** stubs_min = 0x000093ec (0x93ec)
// Camera appears to have only 1 RAW buffer @ 0x10f63920 (Found @0xffe44c60)
DEF(fileio_semaphore                        ,0x00002a1c) // Found @0xffc430b4
DEF(exmem_alloc_table                       ,0x00018cdc) // Found @0xffc57dd8
DEF(exmem_types_table                       ,0xffed4a78) // Found @0x00005604
DEF_CONST(exmem_type_count                  ,0x00000012)
DEF(imager_active                           ,0x00001edc) // Found @0xffc255fc (0x1ed8 + 4)
DEF_CONST(uiprop_count                      ,0x00000064) // Found @0xffd348b4

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x10361000; }             // Found @0xffc31338
//void *vid_get_viewport_fb()      { return (void*)0x10659e80; }             // Found @0xffe42a30
DEF(viewport_fb_d                           ,0x00005258) // Found 0x520c (@0xffc45330) + 0x4c (@0xffc45368)
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x520c+0x4c)); } // Found @0xffc45330 & 0xffc45368
DEF(jpeg_count_str                          ,0x00049344) // Found @0xffd727b0
//char *camera_jpeg_count_str()    { return (char*)0x00049344; }             // Found @0xffd727b0
//int get_flash_params_count(void) { return 0x73; }                          // Found @0xffd352f8

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffe6eda0, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x00040000 // Found @0xffe6edac, levent 0x902
//#define USB_IDX             2
//#define BATTCOVER_FLAG      0x00008000 // Found @0xffe6ed88, levent 0x905
//#define BATTCOVER_IDX       2
//#define ANALOG_AV_FLAG      0x00400000 // Found @0xffe6ec68, levent 0x900 (non-inverted logic)
//#define ANALOG_AV_IDX       1

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 1, KEY_POWER           ,0x00004000 }, // Found @0xffe6ec5c, levent 0x600 (uses inverted logic in physw_status)
//    { 1, KEY_SHOOT_FULL      ,0xc0000000 }, // Found @0xffe6ecc8, levent 0x01
//    { 1, KEY_SHOOT_FULL_ONLY ,0x80000000 }, // Found @0xffe6ecc8, levent 0x01
//    { 1, KEY_SHOOT_HALF      ,0x40000000 }, // Found @0xffe6ecbc, levent 0x00
//    { 2, KEY_ZOOM_IN         ,0x00000004 }, // Found @0xffe6ecec, levent 0x02
//    { 2, KEY_ZOOM_OUT        ,0x00000008 }, // Found @0xffe6ecf8, levent 0x03
//    { 2, KEY_UP              ,0x00000010 }, // Found @0xffe6ed04, levent 0x04
//    { 2, KEY_DOWN            ,0x00000020 }, // Found @0xffe6ed10, levent 0x05
//    { 2, KEY_RIGHT           ,0x00000040 }, // Found @0xffe6ed1c, levent 0x07
//    { 2, KEY_LEFT            ,0x00000080 }, // Found @0xffe6ed28, levent 0x06
//    { 2, KEY_SET             ,0x00000100 }, // Found @0xffe6ed34, levent 0x08
//    { 2, KEY_MENU            ,0x00000200 }, // Found @0xffe6ed40, levent 0x09
//    { 2, KEY_DISPLAY         ,0x00000400 }, // Found @0xffe6ed4c, levent 0x0a
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_RAW_ROWPIX    3336 // Found @0xffe3c240
//#define CAM_RAW_ROWS      2490 // Found @0xffe3c244
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x10000000 // Found @0xffc18320
//#define PARAM_CAMERA_NAME 4 // Found @0xffeb1014

// Below goes in 'filewrite.c' or 'platform_camera.h':
//#define MAX_CHUNKS_FOR_FWT 3 // Found @0xffdd646c

// Known propcases
// //      PROPCASE_AFSTEP 13
// #define PROPCASE_FOCUS_STATE 18
// #define PROPCASE_AV 23
// #define PROPCASE_BV 34
// //      PROPCASE_DELTA_DIGITALGAIN 77
// #define PROPCASE_DELTA_SV 79
// //      PROPCASE_DELTA_ND 80
// #define PROPCASE_EV_CORRECTION_2 207
// #define PROPCASE_ORIENTATION_SENSOR 219
// #define PROPCASE_SV_MARKET 246
// //      PROPCASE_SVFIX 247
// #define PROPCASE_TV 262
// Guessed propset: 2

// Misc stuff
DEF(ctypes, 0xffe69fd6)

// EXMEM types:
// EXMEM_RAMDISK     0
// EXMEM_COM         1
// EXMEM_COMTMP      2
// EXMEM_FORMATTER   3
// EXMEM_SHADING     4
// EXMEM_FAMODE      5
// EXMEM_FIRMUP      6
// EXMEM_FIRMUP_VRAM 7
// EXMEM_DVLPWORK    8
// EXMEM_EVF         9
// EXMEM_SCRIPT      10
// EXMEM_FILESTORE   11
// EXMEM_MOVIE_REC   12
// EXMEM_MOVIE_PLY   13
// EXMEM_WIDE        14
// EXMEM_NARROW      15
// EXMEM_CRAW_REC    16
// EXMEM_PCEVF       17

// ISR flag: 0x195c, pointer to current task's control block: 0x1958
// pointer to TCB area: 0x19f4, found @ 0xffc05ee4

// LED table init @ 0xffccc09c
// LED #1: 0xc02200d0, offset 0x84
// LED #2: 0xc02200c0, offset 0x244
// LED #3: 0xc02200c4, offset 0x204
// LED #4: 0xc02200cc, offset 0x4
// LED #5: 0xc02200c8, offset 0x44

// For capt_seq.c
DEF(_nrflag,0x85c0) // Found @ ffd18680 (0x85c0)
//static long *nrflag = (long*)(0x85c0);       // Found @ ffd18680

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NHSTUB(AllocateUncacheableMemory              ,0xffc182e4) //112
NHSTUB(Close                                  ,0xffc13b88) //120
NHSTUB(CreateBinarySemaphore                  ,0xffc0b608) //115
NHSTUB(CreateTask                             ,0xffc0b8e0) //120
NHSTUB(DebugAssert                            ,0xffc0bdb8) //107
NHSTUB(DeleteDirectory_Fut                    ,0xffc13518) //116
NHSTUB(DeleteFile_Fut                         ,0xffc13434) //112
NHSTUB(DoAELock                               ,0xffc16054) //120
NHSTUB(DoAFLock                               ,0xffc15b04) //120
NHSTUB(EnterToCompensationEVF                 ,0xffc15f54) //104
NHSTUB(ExecuteEventProcedure                  ,0xffc59eb4) //104
NHSTUB(ExitFromCompensationEVF                ,0xffc15fa4) //104
NHSTUB(ExitTask                               ,0xffc0bb70) //120
NHSTUB(ExpCtrlTool_StartContiAE               ,0xffc21f10) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xffc22054) //104
NHSTUB(Fclose_Fut                             ,0xffc135b0) //120
NHSTUB(Feof_Fut                               ,0xffc1379c) //  1
NHSTUB(Fflush_Fut                             ,0xffc137d8) //  1
NHSTUB(Fgets_Fut                              ,0xffc13704) //  1
NHSTUB(Fopen_Fut                              ,0xffc13570) //120
NHSTUB(Fread_Fut                              ,0xffc1365c) //120
NHSTUB(FreeUncacheableMemory                  ,0xffc18318) //112
NHSTUB(Fseek_Fut                              ,0xffc13750) //120
NHSTUB(Fwrite_Fut                             ,0xffc136b0) //120
NHSTUB(GetBatteryTemperature                  ,0xffc377b4) //102
NHSTUB(GetCCDTemperature                      ,0xffc37744) //102
NHSTUB(GetCurrentAvValue                      ,0xffd0ce14) //120
NHSTUB(GetCurrentShutterSpeed                 ,0xffc7633c) //120
NHSTUB(GetUsableMaxAv                         ,0xffe3d86c) //120
NHSTUB(GetUsableMinAv                         ,0xffe3d854) //120
NHSTUB(GetDrive_ClusterSize                   ,0xffc41688) //  1
NHSTUB(GetDrive_FreeClusters                  ,0xffc416f0) //  1
NHSTUB(GetDrive_TotalClusters                 ,0xffc416bc) //  1
NHSTUB(GetFocusLensSubjectDistance            ,0xffd0b310) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xffd0b61c) //  1
NHSTUB(GetKbdState                            ,0xffc35644) //109
NHSTUB(GetMemInfo                             ,0xffc03c40) //115
NHSTUB(GetOpticalTemperature                  ,0xffc37824) //120
NHSTUB(GetParameterData                       ,0xffd352b8) //101
NHSTUB(GetPropertyCase                        ,0xffc5dab4) //102
NHSTUB(GetSystemTime                          ,0xffdf1dcc) //120
NHSTUB(GetVRAMHPixelsSize                     ,0xffc2a77c) //120
NHSTUB(GetVRAMVPixelsSize                     ,0xffc2a788) //120
NHSTUB(GetZoomLensCurrentPoint                ,0xffd0fcc0) //120
NHSTUB(GetZoomLensCurrentPosition             ,0xffde89e0) //102
NHSTUB(GiveSemaphore                          ,0xffc0b844) //120
NHSTUB(IsStrobeChargeCompleted                ,0xffc9e3f0) //102
NHSTUB(LEDDrive                               ,0xffc34ce0) //120
NHSTUB(LocalTime                              ,0xffc57bd4) //115
NHSTUB(LockMainPower                          ,0xffc6211c) //120
NHSTUB(MakeDirectory_Fut                      ,0xffc134a8) //116
NHSTUB(MoveFocusLensToDistance                ,0xffe3f55c) //102
NHSTUB(MoveIrisWithAv                         ,0xffded984) //120
NHSTUB(MoveZoomLensWithPoint                  ,0xffdedfcc) //120
NHSTUB(MoveOpticalZoomAt                      ,0xffc151e8) //109
NHSTUB(Open                                   ,0xffc13b60) //120
NHSTUB(PB2Rec                                 ,0xffc64d3c) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xffc4cfcc) //120
NHSTUB(PT_MoveOpticalZoomAt                   ,0xffc4cfa4) //120
NHSTUB(PT_PlaySound                           ,0xffc4c8b8) //102
NHSTUB(PostLogicalEventForNotPowerType        ,0xffc6178c) //120
NHSTUB(PostLogicalEventToUI                   ,0xffc617d8) //120
NHSTUB(PutInNdFilter                          ,0xffe3d8d8) //102
NHSTUB(PutOutNdFilter                         ,0xffe3d910) //102
NHSTUB(Read                                   ,0xffc0a15c) //120
NHSTUB(ReadFastDir                            ,0xffdd96c0) //  1
NHSTUB(Rec2PB                                 ,0xffc64d6c) //104
NHSTUB(RefreshPhysicalScreen                  ,0xffd7c830) //104
NHSTUB(RenameFile_Fut                         ,0xffc133e0) //  1
NHSTUB(Restart                                ,0xffc19b5c) //122
NHSTUB(SetAE_ShutterSpeed                     ,0xffe41c40) //102
NHSTUB(SetAutoShutdownTime                    ,0xffc62190) //120
NHSTUB(SetCurrentCaptureModeType              ,0xffc68210) //120
NHSTUB(SetDate                                ,0xffe43660) //120
NHSTUB(SetFileAttributes                      ,0xffc13eb4) //  1
NHSTUB(SetFileTimeStamp                       ,0xffc13e64) //  1
NHSTUB(SetLogicalEventActive                  ,0xffc61eb8) //  1
NHSTUB(SetParameterData                       ,0xffd35228) //101
NHSTUB(SetPropertyCase                        ,0xffc5d9b4) //102
NHSTUB(SetScriptMode                          ,0xffc61f08) //120
NHSTUB(SleepTask                              ,0xffc18168) //120
NHSTUB(TakeSemaphore                          ,0xffc0b774) //120
NHSTUB(TurnOffBackLight                       ,0xffc6c570) //104
NHSTUB(TurnOnBackLight                        ,0xffc6c558) //104
NHSTUB(TurnOnDisplay                          ,0xffc313e8) //120
NHSTUB(TurnOffDisplay                         ,0xffc313f8) //120
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xffd2aa58) //120
NHSTUB(UnlockAE                               ,0xffc16084) //120
NHSTUB(UnlockAF                               ,0xffc15c1c) //120
NHSTUB(UnlockMainPower                        ,0xffc62070) //120
NHSTUB(UnsetZoomForMovie                      ,0xffd3a34c) //104
NHSTUB(UpdateMBROnFlash                       ,0xffc414c8) //105
NHSTUB(VbattGet                               ,0xffc105f4) //120
NHSTUB(Write                                  ,0xffc13c34) //120
NHSTUB(WriteSDCard                            ,0xffd01548) //108
NHSTUB(_log                                   ,0xffe67ddc) //111
NHSTUB(_log10                                 ,0xffe66d20) //112
NHSTUB(_pow                                   ,0xffe66e90) //121
NHSTUB(_sqrt                                  ,0xffe69144) //  1
NHSTUB(add_ptp_handler                        ,0xffdaa4e8) //121
NHSTUB(apex2us                                ,0xffd7dd6c) //121
NHSTUB(close                                  ,0xffc09f74) //109
NHSTUB(err_init_task                          ,0xffc04e98) //111
NHSTUB(exmem_alloc                            ,0xffc5869c) //103
NHSTUB(exmem_ualloc                           ,0xffc584ec) //103
NHSTUB(exmem_ufree                            ,0xffc5862c) //103
NHSTUB(free                                   ,0xffc03a98) //112
NHSTUB(kbd_p1_f                               ,0xffc11d34) //109
NHSTUB(kbd_p1_f_cont                          ,0xffc11d40) //109
NHSTUB(kbd_p2_f                               ,0xffc1156c) //109
NHSTUB(kbd_read_keys                          ,0xffc11c30) //109
NHSTUB(kbd_read_keys_r2                       ,0xffc35104) //109
NHSTUB(lseek                                  ,0xffc13cc8) //120
NHSTUB(malloc                                 ,0xffc039c4) //112
NHSTUB(memcmp                                 ,0xffc0d90c) //120
NHSTUB(memcpy                                 ,0xffc74f88) //120
NHSTUB(memset                                 ,0xffd7cbe4) //120
NHSTUB(mkdir                                  ,0xffc13f2c) //109
NHSTUB(mktime_ext                             ,0xffc757f4) //  1
NHSTUB(open                                   ,0xffc09ec4) //109
NHSTUB(OpenFastDir                            ,0xffdd962c) //  1
NHSTUB(closedir                               ,0xffdd9790) //  1
NHSTUB(qsort                                  ,0xffd7d0ec) //  1
NHSTUB(rand                                   ,0xffc0da14) //121
NHSTUB(realloc                                ,0xffc03b78) //115
NHSTUB(reboot_fw_update                       ,0xffdddf94) //106
NHSTUB(set_control_event                      ,0xffc61c0c) //  1
NHSTUB(srand                                  ,0xffc0da08) //122
NHSTUB(stat                                   ,0xffc13d94) //  1
NHSTUB(strcat                                 ,0xffc74d74) //  1
NHSTUB(strchr                                 ,0xffc74dfc) //  1
NHSTUB(strcmp                                 ,0xffc0d8a4) //120
NHSTUB(strcpy                                 ,0xffc0d88c) //120
NHSTUB(strftime                               ,0xffc751fc) //  1
NHSTUB(strlen                                 ,0xffc0d8e8) //120
NHSTUB(strncmp                                ,0xffc74db0) //  1
NHSTUB(strncpy                                ,0xffc1dcc8) //  1
NHSTUB(strrchr                                ,0xffc74e20) //  1
NHSTUB(strtol                                 ,0xffc1df00) //101
NHSTUB(strtolx                                ,0xffc1dd04) //109
   DEF(task_CaptSeq                           ,0xffc4f0f8) //120
   DEF(task_DvlpSeqTask                       ,0xffd191ac) //120
   DEF(task_ExpDrv                            ,0xffc973e4) //120
   DEF(task_FileWrite                         ,0xffdd6408) //120
   DEF(task_InitFileModules                   ,0xffc657b4) //120
   DEF(task_MovieRecord                       ,0xffc4bbbc) //120
   DEF(task_PhySw                             ,0xffc118c8) //120
NHSTUB(time                                   ,0xffc57a88) //109
NHSTUB(vsprintf                               ,0xffc0d80c) //115
NHSTUB(EngDrvRead                             ,0xffc12b74) //102
NHSTUB(PTM_GetCurrentItem                     ,0xffc62a6c) //105
NHSTUB(CancelHPTimer                          ,0xffc593f0) //119
NHSTUB(SetHPTimerAfterNow                     ,0xffc592e8) //119
NHSTUB(PT_MFOn                                ,0xffc4d044) //120
NHSTUB(PT_MFOff                               ,0xffc4d054) //120
NHSTUB(GetAdChValue                           ,0xffc3312c) //120
NHSTUB(get_ptp_buf_size                       ,0xffcabd70) //122
NHSTUB(get_ptp_file_buf                       ,0xffdabdbc) //121
NHSTUB(SetVideoOutType                        ,0xffe4242c) //109
NHSTUB(GetVideoOutType                        ,0xffe42390) //120
