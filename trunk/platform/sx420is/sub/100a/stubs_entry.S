// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R58 (DRYOS version 2.3, release #0058+p7)
//   Firmware Ver GM1.00A   // Found @ 0xff0a80c0, "GM1.00A" @ 0xff0a80cd
//   Firmware build timestamp: Nov 18 2015 13:56:06
//   Canon PowerShot SX420 IS

// Values for makefile.inc
//   DIGIC = 41# DIGIC 4+
//   PLATFORMOSVER = 58
//   PLATFORMID = 12991# (0x32bf) Found @ 0xfffe0270
//   MAXRAMADDR = 0x0fffffff
//   MEMISOSTART = 0x002b8c4c
//   KEYSYS = d4i# Found @ 0xff014590
//   NEED_ENCODED_DISKBOOT = 16# Found @ 0xff0145a0
//   ARAM_HEAP_START = 0x60e000# Found @ 0xff1ff5b8
//   ARAM_HEAP_SIZE  = 0x22000# Found @ 0xff1ff578

// Detected address ranges:
// ROM      0xff010000 - 0xffffffff (16711680 bytes)
// RAM code 0x006b1000 - 0x006e2d88 copied from 0xff7bad88 ( 204168 bytes)
// RAM data 0x00001900 - 0x0001510c copied from 0xff7a757c (  79884 bytes)

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
NHSTUB(DeleteFile_Fut                         ,0xff026a98) //  1 90%
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff1da9f0) //  3 90%
// ERROR: MakeDirectory_Fut is not found.                  //--- ---    *** != 0xff0277ac
// ERROR: RefreshPhysicalScreen is not found.              //--- ---    *** != 0x00000000
// ERROR: TurnOffBackLight is not found.                   //--- ---    *** != 0x00000000
// ERROR: TurnOnBackLight is not found.                    //--- ---    *** != 0x00000000
// ERROR: close is not found.                              //--- ---    *** != 0xff023d68
// ERROR: open is not found.                               //--- ---    *** != 0xff023cb8

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff37ac14 -> ff704c58
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00015ed8) // Found @0xff02c3dc
DEF(physw_run                               ,0x00001c18) // Found @0xff02bebc
DEF(physw_sleep_delay                       ,0x00001c20) // Found @0xff02bebc
DEF(levent_table                            ,0xff631544) // Found @0xff631544
DEF(FlashParamsTable                        ,0xff704fd4) // Found @0xff704fd4
DEF(movie_status                            ,0x00007fec) // Found @0xff1e96c8
DEF(video_compression_rate                  ,0x00007f9c) // Found @0xff1ea390
DEF(full_screen_refresh                     ,0x00008e98) // Found @0xff214620
DEF(canon_menu_active                       ,0x00003f58) // Found @0xff0b07a0
DEF(canon_shoot_menu_active                 ,0x0000ad39) // Found @0xff28a544
DEF(zoom_status                             ,0x0000c15c) // Found @0xff306664
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 2 int value(s), the first is the zoom focus length.
// there are 125 entries in the table - set NUM_FL to 125
DEF(focus_len_table                         ,0xfffecb7c) // Found @0xfffecb7c
DEF(zoom_busy                               ,0x00007cb4) // Found @0xff1dfecc
DEF(focus_busy                              ,0x00007aa8) // Found @0xff1d94ac
// Palette colour tables  found @ 0xff6354e8
// Camera appears to have only 1 RAW buffer @ 0x454a8d60 (Found @0xff465be4)
DEF(fileio_semaphore                        ,0x00001cb4) // Found @0xff02f0cc
DEF(exmem_alloc_table                       ,0x0001725c) // Found @0xff033eb4
DEF(exmem_types_table                       ,0xff7a79c4) // Found @0x00001d48
DEF_CONST(exmem_type_count                  ,0x0000001e)
DEF(imager_active                           ,0x00001fdc) // Found @0xff04ab14 (0x1fd8 + 4)
DEF_CONST(uiprop_count                      ,0x000000d7) // Found @0xff20a088

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x40711000; }             // Found @0xff06ba6c
//void *vid_get_viewport_fb()      { return (void*)0x40866b80; }             // Found @0xff464130
DEF(viewport_fb_d                           ,0x00003624) // Found 0x35c8 (@0xff089af4) + 0x5c (@0xff089b2c)
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x35c8+0x5c)); } // Found @0xff089af4 & 0xff089b2c
DEF(jpeg_count_str                          ,0x0013799c) // Found @0xff274980
//char *camera_jpeg_count_str()    { return (char*)0x0013799c; }             // Found @0xff274980
//int get_flash_params_count(void) { return 0xf1; }                          // Found @0xff20abfc

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x01000000 // Found @0xff5e5ad8, levent 0x30a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x04000000 // Found @0xff5e5ae8, levent 0x302
//#define USB_IDX             2
//#define BATTCOVER_FLAG      0x02000000 // Found @0xff5e5ae0, levent 0x305
//#define BATTCOVER_IDX       2
//#define ANALOG_AV_FLAG      0x00004000 // Found @0xff5e5a48, levent 0x300 (non-inverted logic)
//#define ANALOG_AV_IDX       0

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_SHOOT_FULL      ,0x0000000c }, // Found @0xff5e5a20, levent 0x01
//    { 0, KEY_SHOOT_FULL_ONLY ,0x00000008 }, // Found @0xff5e5a20, levent 0x01
//    { 0, KEY_SHOOT_HALF      ,0x00000004 }, // Found @0xff5e5a18, levent 0x00
//    { 2, KEY_POWER           ,0x00000020 }, // Found @0xff5e5a60, levent 0x100
//    { 2, KEY_PLAYBACK        ,0x00000080 }, // Found @0xff5e5a70, levent 0x101
//    { 2, KEY_VIDEO           ,0x00000400 }, // Found @0xff5e5a80, levent 0x02
//    { 2, KEY_SET             ,0x00000800 }, // Found @0xff5e5a88, levent 0x0a
//    { 2, KEY_LEFT            ,0x00001000 }, // Found @0xff5e5a90, levent 0x08
//    { 2, KEY_UP              ,0x00002000 }, // Found @0xff5e5a98, levent 0x06
//    { 2, KEY_RIGHT           ,0x00004000 }, // Found @0xff5e5aa0, levent 0x09
//    { 2, KEY_DOWN            ,0x00008000 }, // Found @0xff5e5aa8, levent 0x07
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#define CAM_RAW_ROWPIX    5248 // Found @0xff1ad8b8
//#define CAM_RAW_ROWS      3920 // Found @0xff1ad8c0
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff025d7c
//#define CAM_DATE_FOLDER_NAMING 0x080 // Found @0xff338294 (pass as 3rd param to GetImageFolder)
//#define PARAM_CAMERA_NAME 3 // Found @0xff7039f8
//#define CAM_3ARG_DebugAssert 1
//#define CAM_HAS_WIFI 1 // Firmware has wifi support (only define if camera has hardware)

// Below goes in 'filewrite.c' or 'platform_camera.h':
//#define MAX_CHUNKS_FOR_FWT 7 // Found @0xff351d44

// Known propcases
// //      PROPCASE_AFSTEP 13
// #define PROPCASE_FOCUS_STATE 18
// #define PROPCASE_AV 23
// #define PROPCASE_BV 40
// //      PROPCASE_DELTA_DIGITALGAIN 84
// #define PROPCASE_DELTA_SV 86
// //      PROPCASE_DELTA_ND 87
// #define PROPCASE_EV_CORRECTION_2 218
// #define PROPCASE_ORIENTATION_SENSOR 230
// #define PROPCASE_SV_MARKET 257
//         PROPCASE_SVFIX not found
// #define PROPCASE_TV 274
// Guessed propset: 10

// Misc stuff
DEF(ctypes, 0xff5e29e8)

// EXMEM types:
// EXMEM_RAMDISK        0
// EXMEM_COM            1
// EXMEM_FORMATTER      2
// EXMEM_SHADING        3
// EXMEM_FAMODE         4
// EXMEM_FIRMUP         5
// EXMEM_FIRMUP_VRAM    6
// EXMEM_FIRMUP_INFLATE 7
// EXMEM_FIRMUP_PICTURESTYLE 8
// EXMEM_DVLPWORK       9
// EXMEM_EVF            10
// EXMEM_SCRIPT         11
// EXMEM_GPS            12
// EXMEM_FACEAUTH       13
// EXMEM_OHYEARLOG      14
// EXMEM_WIFI           15
// EXMEM_LENS_FIRMUP    16
// EXMEM_LENS_COMPENSATION 17
// EXMEM_FILESTORE      18
// EXMEM_MOVIE_REC      19
// EXMEM_MOVIE_PLY      20
// EXMEM_WIFI_RESIZE    21
// EXMEM_PCEVF          22
// EXMEM_WIDE           23
// EXMEM_NARROW         24
// EXMEM_AUTO_GIS_MODE  25
// EXMEM_NP_GIS_MODE    26
// EXMEM_TRIPODHDR_MODE 27
// EXMEM_HSHQ_MODE      28
// EXMEM_CRAW_REC       29

// ISR flag: 0x194c, pointer to current task's control block: 0x1948
// pointer to TCB area: 0x19cc, found @ 0xff7bc340

// LED table init @ 0xff189488
// LED #1: 0xc022d200 (#98 in GPIO table), offset 0x98
// LED #2: 0xc022d1fc (#97 in GPIO table), offset 0x8
// GPIO table @ 0xff5e54a4

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NHSTUB(AllocateUncacheableMemory              ,0xff025d38) //112
NHSTUB(Close                                  ,0xff027218) //120
NHSTUB(CreateBinarySemaphore                  ,0x006b792c) //115
NHSTUB(CreateTask                             ,0x006b5714) //120
NHSTUB(DebugAssert                            ,0x006b5ac8) //107
NHSTUB(DeleteDirectory_Fut                    ,0xff026b0c) //116
NHSTUB(DoAELock                               ,0xff032898) //120
NHSTUB(DoAFLock                               ,0xff032548) //120
NHSTUB(EnterToCompensationEVF                 ,0xff0327c0) //104
NHSTUB(ExecuteEventProcedure                  ,0xff0349d4) //104
NHSTUB(ExitFromCompensationEVF                ,0xff032814) //104
NHSTUB(ExitTask                               ,0x006b5a68) //120
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff043e30) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff044068) //104
NHSTUB(Fclose_Fut                             ,0xff026ba4) //120
NHSTUB(Feof_Fut                               ,0xff026d90) //  1
NHSTUB(Fflush_Fut                             ,0xff026dcc) //  1
NHSTUB(Fgets_Fut                              ,0xff026cf8) //  6
NHSTUB(Fopen_Fut                              ,0xff026b64) //120
NHSTUB(Fread_Fut                              ,0xff026c50) //120
NHSTUB(FreeUncacheableMemory                  ,0xff025d74) //112
NHSTUB(Fseek_Fut                              ,0xff026d44) //120
NHSTUB(Fwrite_Fut                             ,0xff026ca4) //120
NHSTUB(GetBatteryTemperature                  ,0xff074ec4) //102
NHSTUB(GetCCDTemperature                      ,0xff074e4c) //102
NHSTUB(GetCurrentAvValue                      ,0xff08f07c) //120
NHSTUB(GetCurrentShutterSpeed                 ,0xff127f10) //120
NHSTUB(GetUsableMaxAv                         ,0xff1ae15c) //120
NHSTUB(GetUsableMinAv                         ,0xff1ae140) //120
NHSTUB(GetDrive_ClusterSize                   ,0xff030790) //122
NHSTUB(GetDrive_FreeClusters                  ,0xff030efc) //119
NHSTUB(GetDrive_TotalClusters                 ,0xff030ed0) //122
NHSTUB(GetFocusLensSubjectDistance            ,0xff1da60c) //102
NHSTUB(GetImageFolder                         ,0xff1b5d60) //122
NHSTUB(GetKbdState                            ,0xff071314) //109
NHSTUB(GetMemInfo                             ,0xff023450) //115
NHSTUB(GetOpticalTemperature                  ,0xff074f3c) //120
NHSTUB(GetParameterData                       ,0xff20abb8) //101
NHSTUB(GetPropertyCase                        ,0xff0a99a8) //101
NHSTUB(GetSystemTime                          ,0xff377e9c) //120
NHSTUB(GetVRAMHPixelsSize                     ,0xff04fa98) //120
NHSTUB(GetVRAMVPixelsSize                     ,0xff04faa4) //120
NHSTUB(GetZoomLensCurrentPoint                ,0xff1e0350) //120
NHSTUB(GetZoomLensCurrentPosition             ,0xff367fec) //102
NHSTUB(GiveSemaphore                          ,0x006b7bb0) //120
NHSTUB(IsStrobeChargeCompleted                ,0xff0da8f0) //102
NHSTUB(LEDDrive                               ,0xff1f1e1c) //120
NHSTUB(LocalTime                              ,0x006b9ad8) //115
NHSTUB(LockMainPower                          ,0xff0ac4b4) //120
NHSTUB(MakeSDCardBootable                     ,0xff031404) //105
NHSTUB(MoveFocusLensToDistance                ,0xff467ec4) //102
NHSTUB(MoveIrisWithAv                         ,0xff371180) //120
NHSTUB(MoveZoomLensWithPoint                  ,0xff371c4c) //120
NHSTUB(MoveOpticalZoomAt                      ,0xff031f38) //109
NHSTUB(Open                                   ,0xff0271b4) //120
NHSTUB(PB2Rec                                 ,0xff05c610) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff1f2fb4) //102
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff1f2f84) //102
NHSTUB(PT_PlaySound                           ,0xff0bda14) //122
NHSTUB(PostLogicalEventForNotPowerType        ,0xff0ab8f8) //120
NHSTUB(PostLogicalEventToUI                   ,0xff0ab950) //120
NHSTUB(PutInNdFilter                          ,0xff4682d4) //102
NHSTUB(PutOutNdFilter                         ,0xff468310) //102
NHSTUB(Read                                   ,0xff023f0c) //120
NHSTUB(ReadFastDir                            ,0xff3537f4) //115
NHSTUB(Rec2PB                                 ,0xff05c668) //104
NHSTUB(RenameFile_Fut                         ,0xff026a04) //116
NHSTUB(Restart                                ,0xff037a6c) //122
NHSTUB(ScreenLock                             ,0xff0b00b8) //117
NHSTUB(ScreenUnlock                           ,0xff0b010c) //117
NHSTUB(SetAE_ShutterSpeed                     ,0xff462f50) //102
NHSTUB(SetAutoShutdownTime                    ,0xff0ac528) //120
NHSTUB(SetCurrentCaptureModeType              ,0xff0ba860) //120
NHSTUB(SetDate                                ,0xff464de0) //120
NHSTUB(SetFileAttributes                      ,0xff027714) //  6
NHSTUB(SetFileTimeStamp                       ,0xff02769c) //  6
NHSTUB(SetLogicalEventActive                  ,0xff0ac010) //120
NHSTUB(SetParameterData                       ,0xff20ab1c) //101
NHSTUB(SetPropertyCase                        ,0xff0a97c8) //101
NHSTUB(SetScriptMode                          ,0xff0ac0a8) //120
NHSTUB(SleepTask                              ,0x006b8f0c) //120
NHSTUB(TakeSemaphore                          ,0x006b7ad4) //120
NHSTUB(TurnOnDisplay                          ,0xff06be4c) //120
NHSTUB(TurnOffDisplay                         ,0xff06be5c) //120
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff22939c) //120
NHSTUB(UnlockAE                               ,0xff0328bc) //120
NHSTUB(UnlockAF                               ,0xff032578) //120
NHSTUB(UnlockMainPower                        ,0xff0ac40c) //120
NHSTUB(VbattGet                               ,0xff02b14c) //120
NHSTUB(Write                                  ,0xff027160) //120
NHSTUB(WriteSDCard                            ,0x006ba9d0) //108
NHSTUB(_log                                   ,0x006de580) //111
NHSTUB(_log10                                 ,0x006deac0) //112
NHSTUB(_pow                                   ,0x006dec38) //121
NHSTUB(_sqrt                                  ,0x006e0a50) //  6
NHSTUB(add_ptp_handler                        ,0xff151550) //121
NHSTUB(apex2us                                ,0xff2e5910) //121
NHSTUB(err_init_task                          ,0xff0247d8) //111
NHSTUB(exmem_alloc                            ,0xff0345b8) //101
NHSTUB(exmem_ualloc                           ,0xff03441c) //101
NHSTUB(exmem_ufree                            ,0xff034564) //101
NHSTUB(free                                   ,0xff025084) //112
NHSTUB(get_current_deltasv                    ,0xff12469c) //122
NHSTUB(GetCurrentDriveBaseSvValue             ,0xff0d3e44) //120
NHSTUB(kbd_p1_f                               ,0xff02c42c) //109
NHSTUB(kbd_p1_f_cont                          ,0xff02c438) //109
NHSTUB(kbd_p2_f                               ,0xff02bae8) //109
NHSTUB(kbd_read_keys                          ,0xff02c3dc) //109
NHSTUB(kbd_read_keys_r2                       ,0xff070bac) //109
NHSTUB(lseek                                  ,0xff02752c) //120
NHSTUB(malloc                                 ,0xff02502c) //112
NHSTUB(memcmp                                 ,0xff024e04) //120
NHSTUB(memcpy                                 ,0xff0c1dec) //120
NHSTUB(memset                                 ,0xff2a5a00) //120
NHSTUB(mkdir                                  ,0xff0277ac) //121
NHSTUB(mktime_ext                             ,0xff0c157c) //  1
NHSTUB(OpenFastDir                            ,0xff3536a0) //115
NHSTUB(closedir                               ,0xff353650) //121
NHSTUB(get_fstype                             ,0xff030708) //122
NHSTUB(qsort                                  ,0xff2a59a0) //  6
NHSTUB(rand                                   ,0xff0c1dbc) //121
NHSTUB(realloc                                ,0xff2a5a7c) //115
NHSTUB(reboot_fw_update                       ,0xff3769d0) //106
NHSTUB(set_control_event                      ,0xff0abc80) //111
NHSTUB(srand                                  ,0xff0c1db0) //122
NHSTUB(stat                                   ,0xff027574) //109
NHSTUB(strcat                                 ,0xff0383c4) //  1
NHSTUB(strchr                                 ,0xff03844c) //  1
NHSTUB(strcmp                                 ,0xff024f00) //120
NHSTUB(strcpy                                 ,0xff024dec) //120
NHSTUB(strftime                               ,0xff0c15fc) //113
NHSTUB(strlen                                 ,0xff024f44) //120
NHSTUB(strncmp                                ,0xff038400) //  1
NHSTUB(strncpy                                ,0xff027e8c) //  1
NHSTUB(strrchr                                ,0xff0c1f38) //  1
NHSTUB(strtol                                 ,0xff0383b0) //101
NHSTUB(strtolx                                ,0xff0381b4) //109
   DEF(task_CaptSeq                           ,0xff097614) //120
   DEF(task_DvlpSeqTask                       ,0xff1f728c) //120
   DEF(task_ExpDrv                            ,0xff0f3524) //120
   DEF(task_FileWrite                         ,0xff351ce8) //120
   DEF(task_InitFileModules                   ,0xff05f530) //120
   DEF(task_MovieRecord                       ,0xff1ea45c) //120
   DEF(task_PhySw                             ,0xff02beb8) //120
   DEF(hook_CreateTask                        ,0x006b5714) //105
NHSTUB(time                                   ,0x006b92ac) //119
NHSTUB(vsprintf                               ,0xff027e4c) //115
NHSTUB(EngDrvRead                             ,0xff02c53c) //102
NHSTUB(PTM_GetCurrentItem                     ,0xff0ae168) //105
NHSTUB(DisableISDriveError                    ,0xff372f74) //120
NHSTUB(CancelHPTimer                          ,0xff0a60f0) //119
NHSTUB(SetHPTimerAfterNow                     ,0xff0a5fe8) //119
NHSTUB(SS_MFOn                                ,0xff1f3048) //120
NHSTUB(SS_MFOff                               ,0xff1f3058) //120
NHSTUB(GetAdChValue                           ,0xff06d070) //120
NHSTUB(get_ptp_buf_size                       ,0xff14167c) //122
NHSTUB(get_ptp_file_buf                       ,0xff2f8428) //121
NHSTUB(SetVideoOutType                        ,0xff463774) //109
NHSTUB(GetVideoOutType                        ,0xff4636e8) //120
