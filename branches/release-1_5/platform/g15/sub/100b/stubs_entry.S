// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R51 (DRYOS version 2.3, release #0051)
//   Firmware Ver GM1.00B   // Found @ 0xff0986bc, "GM1.00B" @ 0xff0986c9
//   Firmware build timestamp: Aug  6 2012 17:21:09
//   Canon PowerShot G15

// Values for makefile.inc
//   DIGIC = 50# DIGIC 5
//   PLATFORMOSVER = 51
//   PLATFORMID = 12888# (0x3258) Found @ 0xfff40040
//   MAXRAMADDR = 0x0fffffff
//   MEMISOSTART = 0x0018b824
//   KEYSYS = d4c# Found @ 0xffff3c68
//   NEED_ENCODED_DISKBOOT = 9# Found @ 0xffff3c78
//   ARAM_HEAP_START = 0x5ce000# Found @ 0xff1f1700
//   ARAM_HEAP_SIZE  = 0x22000# Found @ 0xff1f16c4

// Detected address ranges:
// ROM      0xff000000 - 0xffffffff (16777216 bytes)
// RAM code 0x00685000 - 0x00695374 copied from 0xff745bc0 (  66420 bytes)
// RAM data 0x00001900 - 0x00016ac4 copied from 0xff7309fc (  86468 bytes)

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
NHSTUB(DeleteFile_Fut                         ,0xff01c4f0) //  1 90%
// ERROR: MakeDirectory_Fut is not found.                  //--- ---    *** != 0xff01d000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff395770 -> ff6f0ffc
// Mode 16924 in firmware but not in current modemap
// Mode  8745 in firmware but not in current modemap
// Mode 33295 in firmware but not in current modemap

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x0003ac0c) // Found @0xff01a3b8
DEF(physw_run                               ,0x00001d64) // Found @0xff019f14
DEF(physw_sleep_delay                       ,0x00001d6c) // Found @0xff019f14
DEF(levent_table                            ,0xff618310) // Found @0xff618310
DEF(FlashParamsTable                        ,0xff6f1280) // Found @0xff6f1280
DEF(movie_status                            ,0x0000944c) // Found @0xff1ddad8
DEF(video_compression_rate                  ,0x0000947c) // Found @0xff1ded90
DEF(full_screen_refresh                     ,0x00009d30) // Found @0xff1ff130
DEF(canon_menu_active                       ,0x00004470) // Found @0xff0a1920
DEF(canon_shoot_menu_active                 ,0x0000c18d) // Found @0xff29f8b4
DEF(playrec_mode                            ,0x00003988) // Found @0xff08ded0
DEF(zoom_status                             ,0x000069e0) // Found @0xff159738
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 2 int value(s), the first is the zoom focus length.
// there are 121 entries in the table - set NUM_FL to 121
DEF(focus_len_table                         ,0xfff4a700) // Found @0xfff4a700
DEF(zoom_busy                               ,0x00009300) // Found @0xff1d8ba4
DEF(focus_busy                              ,0x0000907c) // Found @0xff1d1a28
DEF(recreview_hold                          ,0x00002a28) // Found @0xff054378
// Palette colour tables  found @ 0xff61bfe4
DEF(palette_control                         ,0x00009d30) // Found @0xff1ff0ac
DEF(active_palette_buffer                   ,0x00009d38) // Found @0xff1ff0b0
DEF(palette_buffer_ptr                      ,0x00009d3c) // Found @0xff1ff568
DEF(palette_buffer                          ,0x000e181c) // Found @0xff1ff578
// Offset from start of palette_buffer to color data = 4 (Found @0xff3b3ab8)
DEF(bitmap_buffer                           ,0x00009d74) // Found @0xff202f5c
DEF(active_bitmap_buffer                    ,0x00009d6c) // Found @0xff202f60
// Camera has 2 RAW buffers @ 0x44000000 & 0x4ad65bc0
//  Note: active buffer --> raw_buffers[active_raw_buffer]
//        other buffer  --> raw_buffers[active_raw_buffer^1]
DEF(raw_buffers                             ,0xff4ca1f4) // Found @0xff4ca1f4
DEF(active_raw_buffer                       ,0x00003908) // Found @0xff089c68
DEF(fileio_semaphore                        ,0x000034d8) // Found @0xff0720bc
DEF(exmem_alloc_table                       ,0x00043d54) // Found @0xff093a9c
DEF(exmem_types_table                       ,0xff732b70) // Found @0x00003a74
DEF_CONST(exmem_type_count                  ,0x00000019)
DEF(imager_active                           ,0x00002158) // Found @0xff03b9a0 (0x2154 + 4)
DEF_CONST(uiprop_count                      ,0x0000008f) // Found @0xff1f5ba4

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x406c5000; }             // Found @0xff057d44
//void *vid_get_viewport_fb()      { return (void*)0x4081ab80; }             // Found @0xff4307e0
DEF(viewport_fb_d                           ,0x00003584) // Found 0x3530 (@0xff0760cc) + 0x54 (@0xff076104)
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x3530+0x54)); } // Found @0xff0760cc & 0xff076104
DEF(jpeg_count_str                          ,0x000e7034) // Found @0xff283048
//char *camera_jpeg_count_str()    { return (char*)0x000e7034; }             // Found @0xff283048
//int get_flash_params_count(void) { return 0xa6; }                          // Found @0xff1f67a0

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00000002 // Found @0xff4a0da4, levent 0x20a
//#define SD_READONLY_IDX     1
//#define USB_MASK            0x10000000 // Found @0xff4a0e0c, levent 0x202
//#define USB_IDX             2
//#define BATTCOVER_FLAG      0x00000100 // Found @0xff4a0db4, levent 0x205
//#define BATTCOVER_IDX       2
//#define HOTSHOE_FLAG        0x00000400 // Found @0xff4a0dbc, levent 0x204
//#define HOTSHOE_IDX         2
//#define ANALOG_AV_FLAG      0x08000000 // Found @0xff4a0e04, levent 0x200 (non-inverted logic)
//#define ANALOG_AV_IDX       2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_SET             ,0x00000800 }, // Found @0xff4a0d2c, levent 0x08
//    { 0, KEY_RIGHT           ,0x00001000 }, // Found @0xff4a0d34, levent 0x07
//    { 0, KEY_DOWN            ,0x00002000 }, // Found @0xff4a0d3c, levent 0x05
//    { 0, KEY_MENU            ,0x00004000 }, // Found @0xff4a0d44, levent 0x09
//    { 0, KEY_LEFT            ,0x00008000 }, // Found @0xff4a0d4c, levent 0x06
//    { 0, KEY_UP              ,0x00040000 }, // Found @0xff4a0d64, levent 0x04
//    { 0, KEY_ZOOM_IN         ,0x00100000 }, // Found @0xff4a0d74, levent 0x02
//    { 0, KEY_ZOOM_OUT        ,0x00200000 }, // Found @0xff4a0d7c, levent 0x03
//    { 2, KEY_POWER           ,0x00000800 }, // Found @0xff4a0dc4, levent 0x100
//    { 2, KEY_PLAYBACK        ,0x00008000 }, // Found @0xff4a0dcc, levent 0x101
//    { 2, KEY_SHOOT_FULL      ,0x000c0000 }, // Found @0xff4a0ddc, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00080000 }, // Found @0xff4a0ddc, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00040000 }, // Found @0xff4a0dd4, levent 0x00
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#define CAM_RAW_ROWPIX    4160 // Found @0xff1a77cc
//#define CAM_RAW_ROWS      3124 // Found @0xff1a77d4
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff020880
//#define CAM_DATE_FOLDER_NAMING 0x400 // Found @0xff34f61c (pass as 3rd param to GetImageFolder)
//#define PARAM_CAMERA_NAME 4 // Found @0xff6f0354

// Below goes in 'filewrite.c' or 'platform_camera.h':
//#define MAX_CHUNKS_FOR_FWT 7 // Found @0xff3678a4

// Known propcases
// //      PROPCASE_AFSTEP 13
// #define PROPCASE_FOCUS_STATE 18
// #define PROPCASE_AV 23
// #define PROPCASE_BV 34
// //      PROPCASE_DELTA_DIGITALGAIN 77
// #define PROPCASE_DELTA_SV 79
// //      PROPCASE_DELTA_ND 80
// #define PROPCASE_EV_CORRECTION_2 211
// #define PROPCASE_ORIENTATION_SENSOR 223
// #define PROPCASE_SV_MARKET 250
// //      PROPCASE_SVFIX 251
// #define PROPCASE_TV 266
// Guessed propset: 4, 5

// Misc stuff
DEF(ctypes, 0xff49f940)

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
// EXMEM_FILESTORE      14
// EXMEM_MOVIE_REC      15
// EXMEM_MOVIE_PLY      16
// EXMEM_WIDE           17
// EXMEM_NARROW         18
// EXMEM_AUTO_GIS_MODE  19
// EXMEM_NP_GIS_MODE    20
// EXMEM_TRIPODHDR_MODE 21
// EXMEM_HSHQ_MODE      22
// EXMEM_CRAW_REC       23
// EXMEM_PCEVF          24

// ISR flag: 0x1960, pointer to current task's control block: 0x195c
// pointer to TCB area: 0x1a00, found @ 0xff747de4

// LED table init @ 0xff16ede0
// LED #1: 0xc022c200 (#98 in GPIO table), offset 0x104
// LED #2: 0xc022c018 (#88 in GPIO table), offset 0x44
// LED #3: 0xc022c028 (#89 in GPIO table), offset 0x4
// GPIO table @ 0xff49fdc8

// For capt_seq.c
DEF(_nrflag,0xc39c) // Found @ ff2b0830 (0xc39c) & ff2b086c (+0x00)
//static long *nrflag = (long*)(0xc39c+0x00);  // Found @ ff2b0830 & ff2b086c
//#define NR_AUTO (0)                          // have to explictly reset value back to 0 to enable auto

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NHSTUB(AllocateUncacheableMemory              ,0xff020838) //112
NHSTUB(Close                                  ,0xff01cb64) //120
NHSTUB(CreateBinarySemaphore                  ,0x0068a8b0) //115
NHSTUB(CreateTask                             ,0x0068ab8c) //120
NHSTUB(DebugAssert                            ,0x0068b104) //107
NHSTUB(DeleteDirectory_Fut                    ,0xff01c564) //116
NHSTUB(DoAELock                               ,0xff01ed40) //120
NHSTUB(DoAFLock                               ,0xff01e8e0) //120
NHSTUB(EnterToCompensationEVF                 ,0xff01ec9c) //104
NHSTUB(ExecuteEventProcedure                  ,0xff0956c0) //104
NHSTUB(ExitFromCompensationEVF                ,0xff01ece0) //104
NHSTUB(ExitTask                               ,0x0068ae1c) //120
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff02e74c) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff02e8b4) //104
NHSTUB(Fclose_Fut                             ,0xff01c5fc) //120
NHSTUB(Feof_Fut                               ,0xff01c7e8) //  1
NHSTUB(Fflush_Fut                             ,0xff01c824) //  1
NHSTUB(Fgets_Fut                              ,0xff01c750) //  6
NHSTUB(Fopen_Fut                              ,0xff01c5bc) //120
NHSTUB(Fread_Fut                              ,0xff01c6a8) //120
NHSTUB(FreeUncacheableMemory                  ,0xff020878) //112
NHSTUB(Fseek_Fut                              ,0xff01c79c) //120
NHSTUB(Fwrite_Fut                             ,0xff01c6fc) //120
NHSTUB(GetBatteryTemperature                  ,0xff0622e8) //102
NHSTUB(GetCCDTemperature                      ,0xff062274) //102
NHSTUB(GetCurrentAvValue                      ,0xff07d4d0) //120
NHSTUB(GetCurrentShutterSpeed                 ,0xff0b50d4) //120
NHSTUB(GetUsableMaxAv                         ,0xff1a822c) //120
NHSTUB(GetUsableMinAv                         ,0xff1a8210) //120
NHSTUB(GetDrive_ClusterSize                   ,0xff073d0c) //122
NHSTUB(GetDrive_FreeClusters                  ,0xff073d64) //119
NHSTUB(GetDrive_TotalClusters                 ,0xff073d3c) //119
NHSTUB(GetFocusLensSubjectDistance            ,0xff1d2a40) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff1d2dfc) //  3
NHSTUB(GetImageFolder                         ,0xff1b14e4) //122
NHSTUB(GetKbdState                            ,0xff05e860) //109
NHSTUB(GetMemInfo                             ,0xff005280) //115
NHSTUB(GetOpticalTemperature                  ,0xff06235c) //120
NHSTUB(GetParameterData                       ,0xff1f6760) //101
NHSTUB(GetPropertyCase                        ,0xff0996f0) //101
NHSTUB(GetSystemTime                          ,0xff390e28) //120
NHSTUB(GetVRAMHPixelsSize                     ,0xff041770) //120
NHSTUB(GetVRAMVPixelsSize                     ,0xff04177c) //120
NHSTUB(GetZoomLensCurrentPoint                ,0xff1d9018) //120
NHSTUB(GetZoomLensCurrentPosition             ,0xff37be30) //102
NHSTUB(GiveSemaphore                          ,0x0068aaec) //120
NHSTUB(IsStrobeChargeCompleted                ,0xff036f38) //102
NHSTUB(LEDDrive                               ,0xff1e0bf0) //120
NHSTUB(LocalTime                              ,0x0068f420) //115
NHSTUB(LockMainPower                          ,0xff09dad4) //120
NHSTUB(MakeSDCardBootable                     ,0xff073f9c) //105
NHSTUB(MoveFocusLensToDistance                ,0xff42c324) //102
NHSTUB(MoveIrisWithAv                         ,0xff38cf8c) //120
NHSTUB(MoveZoomLensWithPoint                  ,0xff38d948) //120
NHSTUB(MoveOpticalZoomAt                      ,0xff01e010) //109
NHSTUB(Open                                   ,0xff01ca9c) //120
NHSTUB(PB2Rec                                 ,0xff049dd0) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff1e1cf0) //102
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff1e1cc8) //102
NHSTUB(PT_PlaySound                           ,0xff0900b0) //122
NHSTUB(PostLogicalEventForNotPowerType        ,0xff09b28c) //120
NHSTUB(PostLogicalEventToUI                   ,0xff09b2d8) //120
NHSTUB(PutInNdFilter                          ,0xff38d718) //102
NHSTUB(PutOutNdFilter                         ,0xff38d73c) //102
NHSTUB(Read                                   ,0xff005d3c) //120
NHSTUB(ReadFastDir                            ,0xff368a24) //115
NHSTUB(Rec2PB                                 ,0xff049e10) //104
NHSTUB(RefreshPhysicalScreen                  ,0xff0a0310) //104
NHSTUB(RenameFile_Fut                         ,0xff01c45c) //116
NHSTUB(Restart                                ,0xff02204c) //122
NHSTUB(ScreenLock                             ,0xff0a12e8) //117
NHSTUB(ScreenUnlock                           ,0xff0a134c) //117
NHSTUB(SetAE_ShutterSpeed                     ,0xff42f658) //102
NHSTUB(SetAutoShutdownTime                    ,0xff09db48) //120
NHSTUB(SetCurrentCaptureModeType              ,0xff0a9438) //120
NHSTUB(SetDate                                ,0xff431440) //120
NHSTUB(SetFileAttributes                      ,0xff01cf68) //  6
NHSTUB(SetFileTimeStamp                       ,0xff01cef0) //  6
NHSTUB(SetLogicalEventActive                  ,0xff09d820) //120
NHSTUB(SetParameterData                       ,0xff1f663c) //101
NHSTUB(SetPropertyCase                        ,0xff099568) //101
NHSTUB(SetScriptMode                          ,0xff09d870) //120
NHSTUB(SleepTask                              ,0x0068c4e4) //120
NHSTUB(TakeSemaphore                          ,0x0068aa1c) //120
NHSTUB(TurnOffBackLight                       ,0xff0ad224) //104
NHSTUB(TurnOnBackLight                        ,0xff0ad20c) //104
NHSTUB(TurnOnDisplay                          ,0xff058158) //120
NHSTUB(TurnOffDisplay                         ,0xff058168) //120
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff214a94) //120
NHSTUB(UnlockAE                               ,0xff01ed64) //120
NHSTUB(UnlockAF                               ,0xff01e918) //120
NHSTUB(UnlockMainPower                        ,0xff09da28) //120
NHSTUB(UnsetZoomForMovie                      ,0xff04fea0) //104
NHSTUB(VbattGet                               ,0xff018ad4) //120
NHSTUB(Write                                  ,0xff01cbb8) //120
NHSTUB(WriteSDCard                            ,0xff1c5bd4) //108
NHSTUB(_log                                   ,0x006915c0) //111
NHSTUB(_log10                                 ,0x00691b00) //112
NHSTUB(_pow                                   ,0x00691c78) //121
NHSTUB(_sqrt                                  ,0x00693bd8) //  6
NHSTUB(add_ptp_handler                        ,0xff2f7708) //121
NHSTUB(apex2us                                ,0xff2a9c7c) //121
NHSTUB(close                                  ,0xff005b98) //109
NHSTUB(err_init_task                          ,0xff004310) //111
NHSTUB(exmem_alloc                            ,0xff094094) //101
NHSTUB(exmem_ualloc                           ,0xff093ee8) //101
NHSTUB(exmem_ufree                            ,0xff094034) //101
NHSTUB(free                                   ,0xff002f0c) //112
NHSTUB(get_nd_value                           ,0xff3799b0) //122
NHSTUB(get_current_nd_value                   ,0xff379980) //122
NHSTUB(kbd_p1_f                               ,0xff01a408) //109
NHSTUB(kbd_p1_f_cont                          ,0xff01a414) //109
NHSTUB(kbd_p2_f                               ,0xff019bac) //109
NHSTUB(kbd_read_keys                          ,0xff01a3b8) //109
NHSTUB(kbd_read_keys_r2                       ,0xff05e000) //109
NHSTUB(lseek                                  ,0xff01cd80) //120
NHSTUB(malloc                                 ,0xff002eb4) //112
NHSTUB(memcmp                                 ,0xff00b5a4) //120
NHSTUB(memcpy                                 ,0xff02297c) //120
NHSTUB(memset                                 ,0xff2a7c24) //120
NHSTUB(mkdir                                  ,0xff01d000) //121
NHSTUB(mktime_ext                             ,0xff0b0a60) //  1
NHSTUB(open                                   ,0xff005ae8) //109
NHSTUB(OpenFastDir                            ,0xff3688d0) //115
NHSTUB(closedir                               ,0xff368880) //121
NHSTUB(get_fstype                             ,0xff073d84) //122
NHSTUB(qsort                                  ,0xff3f62d4) //  6
NHSTUB(rand                                   ,0xff2a7bf4) //121
NHSTUB(realloc                                ,0xff2a7ca0) //115
NHSTUB(reboot_fw_update                       ,0xff3903c0) //106
NHSTUB(set_control_event                      ,0xff09d414) //111
NHSTUB(srand                                  ,0xff2a7be8) //122
NHSTUB(stat                                   ,0xff01cdc8) //109
NHSTUB(strcat                                 ,0xff0b10fc) //  1
NHSTUB(strchr                                 ,0xff002d80) //  1
NHSTUB(strcmp                                 ,0xff00b6a0) //120
NHSTUB(strcpy                                 ,0xff00b58c) //120
NHSTUB(strftime                               ,0xff0b0aac) //113
NHSTUB(strlen                                 ,0xff002dcc) //120
NHSTUB(strncmp                                ,0xff002d34) //  1
NHSTUB(strncpy                                ,0xff002cf8) //  1
NHSTUB(strrchr                                ,0xff002da4) //  1
NHSTUB(strtol                                 ,0xff022968) //101
NHSTUB(strtolx                                ,0xff02276c) //109
   DEF(task_CaptSeq                           ,0xff0856d8) //120
   DEF(task_DvlpSeqTask                       ,0xff1e76bc) //120
   DEF(task_ExpDrv                            ,0xff0cb0a4) //120
   DEF(task_FileWrite                         ,0xff367848) //120
   DEF(task_InitFileModules                   ,0xff04a77c) //120
   DEF(task_MovieRecord                       ,0xff1df2b0) //120
   DEF(task_PhySw                             ,0xff019f10) //120
   DEF(task_RotaryEncoder                     ,0xff05ebb4) //120
   DEF(hook_CreateTask                        ,0x0068ab8c) //105
NHSTUB(time                                   ,0x0068f8c8) //  6
NHSTUB(vsprintf                               ,0xff00b43c) //115
NHSTUB(EngDrvRead                             ,0xff01b244) //102
NHSTUB(PTM_GetCurrentItem                     ,0xff09e764) //105
NHSTUB(DisableISDriveError                    ,0xff38e350) //120
NHSTUB(CancelHPTimer                          ,0xff094da8) //119
NHSTUB(SetHPTimerAfterNow                     ,0xff094ca0) //119
NHSTUB(SS_MFOn                                ,0xff1e1d80) //120
NHSTUB(SS_MFOff                               ,0xff1e1d90) //120
NHSTUB(GetAdChValue                           ,0xff059368) //120
NHSTUB(EnableHDMIPower                        ,0xff05d160) //123
NHSTUB(DisableHDMIPower                       ,0xff05d168) //123
NHSTUB(get_ptp_buf_size                       ,0xff1422a0) //122
NHSTUB(get_ptp_file_buf                       ,0xff2f91e0) //121
NHSTUB(SetVideoOutType                        ,0xff42fee0) //109
NHSTUB(GetVideoOutType                        ,0xff42fdf0) //120
