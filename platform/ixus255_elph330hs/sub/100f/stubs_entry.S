// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R52 (DRYOS version 2.3, release #0052)
//   Firmware Ver GM1.00F   // Found @ 0xff0c9b34, "GM1.00F" @ 0xff0c9b41
//   Firmware build timestamp: Dec 20 2012 19:45:09
//   Canon IXUS 255 HS

// Values for makefile.inc
//   DIGIC = 50# DIGIC 5
//   PLATFORMOSVER = 52
//   PLATFORMID = 12904# (0x3268) Found @ 0xfff40040
//   MAXRAMADDR = 0x0fffffff
//   MEMISOSTART = 0x0026172c
//   KEYSYS = d4d# Found @ 0xffff3c28
//   NEED_ENCODED_DISKBOOT = 10# Found @ 0xffff3c38
//   ARAM_HEAP_START = 0x5ce000# Found @ 0xff23e7ec
//   ARAM_HEAP_SIZE  = 0x22000# Found @ 0xff23e7b0

// Detected address ranges:
// ROM      0xff000000 - 0xffffffff (16777216 bytes)
// RAM code 0x00685000 - 0x006afb54 copied from 0xff8986ec ( 174932 bytes)
// RAM data 0x00001900 - 0x00019f84 copied from 0xff880068 (  99972 bytes)

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
NHSTUB(DeleteFile_Fut                         ,0xff034ad0) //  1 90%
// ERROR: MakeDirectory_Fut is not found.                  //--- ---    *** != 0xff0355e0
// ERROR: RefreshPhysicalScreen is not found.              //--- ---    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff3e9438 -> ff840a60
// Mode 33339 in firmware but not in current modemap
// Mode 33295 in firmware but not in current modemap

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x0003f484) // Found @0xff032320
DEF(physw_run                               ,0x00001e20) // Found @0xff031e80
DEF(physw_sleep_delay                       ,0x00001e28) // Found @0xff031e80
DEF(levent_table                            ,0xff63cfbc) // Found @0xff63cfbc
DEF(FlashParamsTable                        ,0xff840ca4) // Found @0xff840ca4
DEF(movie_status                            ,0x00009564) // Found @0xff22f424
DEF(video_compression_rate                  ,0x00009594) // Found @0xff2306e0
DEF(full_screen_refresh                     ,0x0000a0d4) // Found @0xff24cd6c
DEF(canon_menu_active                       ,0x000040f8) // Found @0xff0d2c30
DEF(canon_shoot_menu_active                 ,0x0000bf8d) // Found @0xff2c93e0
DEF(playrec_mode                            ,0x00003b24) // Found @0xff0beab4
DEF(zoom_status                             ,0x0000d9a0) // Found @0xff34d99c
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 2 int value(s), the first is the zoom focus length.
// there are 101 entries in the table - set NUM_FL to 101
DEF(focus_len_table                         ,0xfff4d3e0) // Found @0xfff4d3e0
DEF(zoom_busy                               ,0x000093f0) // Found @0xff229cf4
DEF(focus_busy                              ,0x0000928c) // Found @0xff225090
DEF(recreview_hold                          ,0x00002d68) // Found @0xff08a5c8
// Palette colour tables  found @ 0xff643c08
DEF(active_palette_buffer                   ,0x0000a0dc) // Found @0xff24ccf0
DEF(palette_buffer_ptr                      ,0x0000a0e0) // Found @0xff24d1ac
// Offset from start of palette_buffer to color data = 4 (Found @0xff409dbc)
// Camera has 2 RAW buffers @ 0x44000000 & 0x4adb23c0
//  Note: active buffer --> raw_buffers[active_raw_buffer]
//        other buffer  --> raw_buffers[active_raw_buffer^1]
DEF(raw_buffers                             ,0xff5e3440) // Found @0xff5e3440
DEF(active_raw_buffer                       ,0x00003a74) // Found @0xff0ba69c
DEF(fileio_semaphore                        ,0x00003764) // Found @0xff0a93b0
DEF(exmem_alloc_table                       ,0x000a3ea8) // Found @0xff0c4f64
DEF(exmem_types_table                       ,0xff882358) // Found @0x00003bf0
DEF_CONST(exmem_type_count                  ,0x0000001c)
DEF(imager_active                           ,0x000024f0) // Found @0xff072944 (0x24ec + 4)
DEF_CONST(uiprop_count                      ,0x00000083) // Found @0xff2441c0

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x406c5000; }             // Found @0xff08dfd0
//void *vid_get_viewport_fb()      { return (void*)0x4081ab80; }             // Found @0xff49c3ac
DEF(viewport_fb_d                           ,0x00003818) // Found 0x37c4 (@0xff0ad76c) + 0x54 (@0xff0ad7a4)
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x37c4+0x54)); } // Found @0xff0ad76c & 0xff0ad7a4
DEF(jpeg_count_str                          ,0x00181248) // Found @0xff2b4948
//char *camera_jpeg_count_str()    { return (char*)0x00181248; }             // Found @0xff2b4948
//int get_flash_params_count(void) { return 0x91; }                          // Found @0xff244ba4

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x02000000 // Found @0xff5b8984, levent 0x20a
//#define SD_READONLY_IDX     1
//#define USB_MASK            0x10000000 // Found @0xff5b89c4, levent 0x202
//#define USB_IDX             2
//#define BATTCOVER_FLAG      0x04000000 // Found @0xff5b89b4, levent 0x205
//#define BATTCOVER_IDX       2
//#define ANALOG_AV_FLAG      0x08000000 // Found @0xff5b89bc, levent 0x200 (non-inverted logic)
//#define ANALOG_AV_IDX       2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_MENU            ,0x00000001 }, // Found @0xff5b891c, levent 0x0b
//    { 0, KEY_SET             ,0x00000002 }, // Found @0xff5b8924, levent 0x0a
//    { 0, KEY_VIDEO           ,0x00000020 }, // Found @0xff5b8934, levent 0x02
//    { 0, KEY_UP              ,0x00000040 }, // Found @0xff5b893c, levent 0x06
//    { 0, KEY_RIGHT           ,0x00000080 }, // Found @0xff5b8944, levent 0x09
//    { 0, KEY_LEFT            ,0x00000400 }, // Found @0xff5b894c, levent 0x08
//    { 0, KEY_DOWN            ,0x00000800 }, // Found @0xff5b8954, levent 0x07
//    { 1, KEY_SHOOT_FULL      ,0x00300000 }, // Found @0xff5b8964, levent 0x01
//    { 1, KEY_SHOOT_FULL_ONLY ,0x00200000 }, // Found @0xff5b8964, levent 0x01
//    { 1, KEY_SHOOT_HALF      ,0x00100000 }, // Found @0xff5b895c, levent 0x00
//    { 1, KEY_POWER           ,0x00400000 }, // Found @0xff5b896c, levent 0x100
//    { 1, KEY_PLAYBACK        ,0x00800000 }, // Found @0xff5b8974, levent 0x101
//    { 2, KEY_ZOOM_IN         ,0x00001000 }, // Found @0xff5b898c, levent 0x03
//    { 2, KEY_ZOOM_OUT        ,0x00004000 }, // Found @0xff5b8994, levent 0x04
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#define CAM_RAW_ROWPIX    4176 // Found @0xff1f7824
//#define CAM_RAW_ROWS      3062 // Found @0xff1f7830
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff03a200
//#define CAM_DATE_FOLDER_NAMING 0x080 // Found @0xff39bf4c (pass as 3rd param to GetImageFolder)
//#define PARAM_CAMERA_NAME 3 // Found @0xff83ff50

// Below goes in 'filewrite.c' or 'platform_camera.h':
//#define MAX_CHUNKS_FOR_JPEG 7 // Found @0xff3b66b0

// Known propcases
// //      PROPCASE_AFSTEP 13
// #define PROPCASE_FOCUS_STATE 18
// #define PROPCASE_AV 23
// #define PROPCASE_BV 34
// //      PROPCASE_DELTA_DIGITALGAIN 77
// #define PROPCASE_DELTA_SV 79
// //      PROPCASE_DELTA_ND 80
// #define PROPCASE_EV_CORRECTION_2 210
// #define PROPCASE_ORIENTATION_SENSOR 222
// #define PROPCASE_SV_MARKET 249
// //      PROPCASE_SVFIX 250
// #define PROPCASE_TV 265
// Guessed propset: 6

// Misc stuff
DEF(ctypes, 0xff5b5a08)

// EXMEM types:
// EXMEM_RAMDISK        0
// EXMEM_COM            1
// EXMEM_FORMATTER      2
// EXMEM_SHADING        3
// EXMEM_FAMODE         4
// EXMEM_FIRMUP         5
// EXMEM_FIRMUP_VRAM    6
// EXMEM_FIRMUP_INFLATE 7
// EXMEM_DVLPWORK       8
// EXMEM_EVF            9
// EXMEM_SCRIPT         10
// EXMEM_GPS            11
// EXMEM_FACEAUTH       12
// EXMEM_OHYEARLOG      13
// EXMEM_WIFI           14
// EXMEM_FILESTORE      15
// EXMEM_MOVIE_REC      16
// EXMEM_MOVIE_PLY      17
// EXMEM_WIDE           18
// EXMEM_NARROW         19
// EXMEM_AUTO_GIS_MODE  20
// EXMEM_NP_GIS_MODE    21
// EXMEM_TRIPODHDR_MODE 22
// EXMEM_HSHQ_MODE      23
// EXMEM_CRAW_REC       24
// EXMEM_PCEVF          25
// EXMEM_CREATIVE_SHOT  26
// EXMEM_WIFI_RESIZE    27

// ISR flag: 0x1958, pointer to current task's control block: 0x1954
// pointer to TCB area: 0x19f8, found @ 0xff89a910

// LED table init @ 0xff1c2dac
// LED #1: 0xc022c028 (#89 in GPIO table), offset 0x104
// LED #2: 0xc022c020 (#86 in GPIO table), offset 0x4
// GPIO table @ 0xff5b83dc

// For capt_seq.c
DEF(_nrflag,0xcf74) // Found @ ff2f3000 (0xcf74) & ff2f303c (+0x00)
//static long *nrflag = (long*)(0xcf74+0x00);  // Found @ ff2f3000 & ff2f303c
//#define NR_AUTO (0)                          // have to explictly reset value back to 0 to enable auto

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NHSTUB(AllocateUncacheableMemory              ,0xff03a1b8) //112
NHSTUB(Close                                  ,0xff035144) //120
NHSTUB(CreateBinarySemaphore                  ,0x0068a8b0) //115
NHSTUB(CreateTask                             ,0x0068ab8c) //120
NHSTUB(DebugAssert                            ,0x0068b104) //107
NHSTUB(DeleteDirectory_Fut                    ,0xff034b44) //116
NHSTUB(DoAELock                               ,0xff036cd4) //120
NHSTUB(DoAFLock                               ,0xff0369f4) //120
NHSTUB(EnterToCompensationEVF                 ,0xff036c3c) //104
NHSTUB(ExecuteEventProcedure                  ,0xff0c6b94) //104
NHSTUB(ExitFromCompensationEVF                ,0xff036c80) //104
NHSTUB(ExitTask                               ,0x0068ae1c) //120
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff06b5dc) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff06b744) //104
NHSTUB(Fclose_Fut                             ,0xff034bdc) //120
NHSTUB(Feof_Fut                               ,0xff034dc8) //  1
NHSTUB(Fflush_Fut                             ,0xff034e04) //  1
NHSTUB(Fgets_Fut                              ,0xff034d30) //  6
NHSTUB(Fopen_Fut                              ,0xff034b9c) //120
NHSTUB(Fread_Fut                              ,0xff034c88) //120
NHSTUB(FreeUncacheableMemory                  ,0xff03a1f8) //112
NHSTUB(Fseek_Fut                              ,0xff034d7c) //120
NHSTUB(Fwrite_Fut                             ,0xff034cdc) //120
NHSTUB(GetBatteryTemperature                  ,0xff0976f0) //102
NHSTUB(GetCCDTemperature                      ,0xff09767c) //102
NHSTUB(GetCurrentAvValue                      ,0xff226f4c) //120
NHSTUB(GetCurrentShutterSpeed                 ,0xff112c6c) //120
NHSTUB(GetDrive_ClusterSize                   ,0xff0aaa20) //122
NHSTUB(GetDrive_FreeClusters                  ,0xff0ab200) //119
NHSTUB(GetDrive_TotalClusters                 ,0xff0ab1d8) //122
NHSTUB(GetFocusLensSubjectDistance            ,0xff2261c0) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff226554) //  3
NHSTUB(GetImageFolder                         ,0xff1ff210) //122
NHSTUB(GetKbdState                            ,0xff094194) //109
NHSTUB(GetMemInfo                             ,0xff0052c4) //115
NHSTUB(GetOpticalTemperature                  ,0xff097764) //120
NHSTUB(GetParameterData                       ,0xff244b64) //101
NHSTUB(GetPropertyCase                        ,0xff0caf4c) //101
NHSTUB(GetSystemTime                          ,0xff3e4f78) //120
NHSTUB(GetVRAMHPixelsSize                     ,0xff078350) //120
NHSTUB(GetVRAMVPixelsSize                     ,0xff07835c) //120
NHSTUB(GetZoomLensCurrentPoint                ,0xff22a170) //120
NHSTUB(GetZoomLensCurrentPosition             ,0xff3cfa48) //102
NHSTUB(GiveSemaphore                          ,0x0068aaec) //120
NHSTUB(IsStrobeChargeCompleted                ,0xff14cbb4) //102
NHSTUB(LEDDrive                               ,0xff232014) //120
NHSTUB(LocalTime                              ,0x006937ec) //115
NHSTUB(LockMainPower                          ,0xff0cd3d0) //120
NHSTUB(MakeSDCardBootable                     ,0xff0ab684) //105
NHSTUB(MoveFocusLensToDistance                ,0xff497ec0) //102
NHSTUB(MoveIrisWithAv                         ,0xff3e0850) //120
NHSTUB(MoveZoomLensWithPoint                  ,0xff3e0f8c) //120
NHSTUB(MoveOpticalZoomAt                      ,0xff0364b8) //109
NHSTUB(Open                                   ,0xff03507c) //120
NHSTUB(PB2Rec                                 ,0xff082c98) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff233124) //102
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff2330f4) //102
NHSTUB(PT_PlaySound                           ,0xff0df468) //122
NHSTUB(PostLogicalEventForNotPowerType        ,0xff0ccac0) //120
NHSTUB(PostLogicalEventToUI                   ,0xff0ccb0c) //120
NHSTUB(PutInNdFilter                          ,0xff3e0d64) //102
NHSTUB(PutOutNdFilter                         ,0xff3e0d88) //102
NHSTUB(Read                                   ,0xff005d80) //120
NHSTUB(ReadFastDir                            ,0xff3ba4f4) //115
NHSTUB(Rec2PB                                 ,0xff082cd8) //104
NHSTUB(RenameFile_Fut                         ,0xff034a3c) //116
NHSTUB(Restart                                ,0xff039680) //122
NHSTUB(ScreenLock                             ,0xff0d265c) //117
NHSTUB(ScreenUnlock                           ,0xff0d26b0) //117
NHSTUB(SetAE_ShutterSpeed                     ,0xff49b224) //102
NHSTUB(SetAutoShutdownTime                    ,0xff0cd444) //120
NHSTUB(SetCurrentCaptureModeType              ,0xff0da4d0) //120
NHSTUB(SetDate                                ,0xff49d00c) //120
NHSTUB(SetFileAttributes                      ,0xff035548) //  6
NHSTUB(SetFileTimeStamp                       ,0xff0354d0) //  6
NHSTUB(SetLogicalEventActive                  ,0xff0cd148) //120
NHSTUB(SetParameterData                       ,0xff244ad0) //101
NHSTUB(SetPropertyCase                        ,0xff0cadb8) //101
NHSTUB(SetScriptMode                          ,0xff0cd198) //120
NHSTUB(SleepTask                              ,0x0068c4e8) //120
NHSTUB(TakeSemaphore                          ,0x0068aa1c) //120
NHSTUB(TurnOffBackLight                       ,0xff0ded34) //104
NHSTUB(TurnOnBackLight                        ,0xff0ded1c) //104
NHSTUB(TurnOnDisplay                          ,0xff08e3fc) //120
NHSTUB(TurnOffDisplay                         ,0xff08e40c) //120
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff260fa0) //120
NHSTUB(UnlockAE                               ,0xff036cf8) //120
NHSTUB(UnlockAF                               ,0xff036a24) //120
NHSTUB(UnlockMainPower                        ,0xff0cd324) //120
NHSTUB(VbattGet                               ,0xff030f94) //120
NHSTUB(Write                                  ,0xff035198) //120
NHSTUB(WriteSDCard                            ,0xff2172b4) //108
NHSTUB(_log                                   ,0x006ab808) //111
NHSTUB(_log10                                 ,0x006abd48) //112
NHSTUB(_pow                                   ,0x006abec0) //121
NHSTUB(_sqrt                                  ,0x006adcd8) //  6
NHSTUB(add_ptp_handler                        ,0xff184b10) //121
NHSTUB(apex2us                                ,0xff2ec614) //121
NHSTUB(close                                  ,0xff005bdc) //109
NHSTUB(err_init_task                          ,0xff00432c) //111
NHSTUB(exmem_alloc                            ,0xff0c555c) //101
NHSTUB(exmem_ualloc                           ,0xff0c53b0) //101
NHSTUB(exmem_ufree                            ,0xff0c54fc) //101
NHSTUB(free                                   ,0xff002efc) //112
NHSTUB(get_nd_value                           ,0xff3cd5ac) //123
NHSTUB(get_current_nd_value                   ,0xff3cd54c) //122
NHSTUB(kbd_p1_f                               ,0xff032370) //109
NHSTUB(kbd_p1_f_cont                          ,0xff03237c) //109
NHSTUB(kbd_p2_f                               ,0xff031b18) //109
NHSTUB(kbd_read_keys                          ,0xff032320) //109
NHSTUB(kbd_read_keys_r2                       ,0xff093b8c) //109
NHSTUB(lseek                                  ,0xff035360) //120
NHSTUB(malloc                                 ,0xff002ea4) //112
NHSTUB(memcmp                                 ,0xff00b988) //120
NHSTUB(memcpy                                 ,0xff03ac44) //120
NHSTUB(memset                                 ,0xff0e2f44) //120
NHSTUB(mkdir                                  ,0xff0355e0) //121
NHSTUB(mktime_ext                             ,0xff0e23ec) //  1
NHSTUB(open                                   ,0xff005b2c) //109
NHSTUB(OpenFastDir                            ,0xff3ba3a0) //115
NHSTUB(closedir                               ,0xff3ba350) //121
NHSTUB(get_fstype                             ,0xff0aa99c) //122
NHSTUB(qsort                                  ,0xff2d1654) //  6
NHSTUB(rand                                   ,0xff0e2e48) //121
NHSTUB(realloc                                ,0xff2d16b4) //115
NHSTUB(reboot_fw_update                       ,0xff3e45e8) //106
NHSTUB(set_control_event                      ,0xff0cce08) //111
NHSTUB(srand                                  ,0xff0e2e3c) //122
NHSTUB(stat                                   ,0xff0353a8) //109
NHSTUB(strcat                                 ,0xff0e2e78) //  1
NHSTUB(strchr                                 ,0xff002d70) //  1
NHSTUB(strcmp                                 ,0xff00ba84) //120
NHSTUB(strcpy                                 ,0xff00b970) //120
NHSTUB(strftime                               ,0xff0e2438) //113
NHSTUB(strlen                                 ,0xff002dbc) //120
NHSTUB(strncmp                                ,0xff002d24) //  1
NHSTUB(strncpy                                ,0xff002ce8) //  1
NHSTUB(strrchr                                ,0xff002d94) //  1
NHSTUB(strtol                                 ,0xff03ac30) //101
NHSTUB(strtolx                                ,0xff03aa34) //109
   DEF(task_CaptSeq                           ,0xff0b6984) //120
   DEF(task_DvlpSeqTask                       ,0xff23659c) //120
   DEF(task_ExpDrv                            ,0xff12941c) //120
   DEF(task_FileWrite                         ,0xff3b6654) //120
   DEF(task_InitFileModules                   ,0xff08360c) //120
   DEF(task_MovieRecord                       ,0xff230bfc) //120
   DEF(task_PhySw                             ,0xff031e7c) //120
   DEF(hook_CreateTask                        ,0x0068ab8c) //105
NHSTUB(time                                   ,0x00693c94) //119
NHSTUB(vsprintf                               ,0xff00b820) //115
NHSTUB(EngDrvRead                             ,0xff03324c) //102
NHSTUB(PTM_GetCurrentItem                     ,0xff0cde08) //105
NHSTUB(DisableISDriveError                    ,0xff3e1a88) //120
NHSTUB(CancelHPTimer                          ,0xff0c627c) //119
NHSTUB(SetHPTimerAfterNow                     ,0xff0c6174) //119
NHSTUB(SS_MFOn                                ,0xff2331b8) //120
NHSTUB(SS_MFOff                               ,0xff2331c8) //120
NHSTUB(GetAdChValue                           ,0xff08f738) //120
NHSTUB(EnableHDMIPower                        ,0xff092640) //123
NHSTUB(DisableHDMIPower                       ,0xff092694) //123
NHSTUB(get_ptp_buf_size                       ,0xff17eaf8) //122
NHSTUB(get_ptp_file_buf                       ,0xff33f5d8) //121
NHSTUB(SetVideoOutType                        ,0xff49baac) //109
NHSTUB(GetVideoOutType                        ,0xff49b9bc) //120
