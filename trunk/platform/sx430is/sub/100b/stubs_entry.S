// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R59 (DRYOS version 2.3, release #0059+p3)
//   Firmware Ver GM1.00B   // Found @ 0xff0acddc, "GM1.00B" @ 0xff0acde9
//   Firmware build timestamp: Nov 18 2016 10:09:29
//   Canon PowerShot SX430 IS

// Values for makefile.inc
//   DIGIC = 41# DIGIC 4+
//   PLATFORMOSVER = 59
//   PLATFORMID = 13013# (0x32d5) Found @ 0xfffe0270
//   MAXRAMADDR = 0x0fffffff
//   MEMISOSTART = 0x002b9464
//   KEYSYS = d4j# Found @ 0xff014590
//   NEED_ENCODED_DISKBOOT = 17# Found @ 0xff0145a0
//   ARAM_HEAP_START = 0x9400001# Found @ 0xff201610
//   ARAM_HEAP_SIZE  = 0x0# Found @ 0x00000000

// Detected address ranges:
// ROM      0xff010000 - 0xffffffff (16711680 bytes)
// RAM code 0x006b1000 - 0x006e01c4 copied from 0xff7cf0a8 ( 192964 bytes)
// RAM data 0x00001900 - 0x00014f30 copied from 0xff7bba78 (  79408 bytes)

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
NHSTUB(DeleteFile_Fut                         ,0xff026cf0) //  1 90%
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff1dd2f0) //  3 90%
// ERROR: MakeDirectory_Fut is not found.                  //--- ---    *** != 0xff027988
// ERROR: RefreshPhysicalScreen is not found.              //--- ---    *** != 0x00000000
// ERROR: TurnOffBackLight is not found.                   //--- ---    *** != 0x00000000
// ERROR: TurnOnBackLight is not found.                    //--- ---    *** != 0x00000000
// ERROR: close is not found.                              //--- ---    *** != 0xff023e60
// ERROR: exmem_ualloc is not found.                       //--- ---    *** != 0xff035288
// ERROR: exmem_ufree is not found.                        //--- ---    *** != 0xff035320
// ERROR: open is not found.                               //--- ---    *** != 0xff023db0

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff388c58 -> ff7186b4
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00015cbc) // Found @0xff02d104
DEF(physw_run                               ,0x00001be4) // Found @0xff02cbd4
DEF(physw_sleep_delay                       ,0x00001bec) // Found @0xff02cbd4
DEF(levent_table                            ,0xff643b8c) // Found @0xff643b8c
DEF(FlashParamsTable                        ,0xff718a78) // Found @0xff718a78
DEF(movie_status                            ,0x00007c0c) // Found @0xff1ec01c
DEF(video_compression_rate                  ,0x00007bbc) // Found @0xff1eccf0
DEF(full_screen_refresh                     ,0x00008b00) // Found @0xff216670
DEF(canon_menu_active                       ,0x0000403c) // Found @0xff0b55d4
DEF(canon_shoot_menu_active                 ,0x0000a9e5) // Found @0xff28ef1c
DEF(zoom_status                             ,0x0001118c) // Found @0xff312d4c
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 2 int value(s), the first is the zoom focus length.
// there are 127 entries in the table - set NUM_FL to 127
DEF(focus_len_table                         ,0xfffecb7c) // Found @0xfffecb7c
DEF(zoom_busy                               ,0x000078f0) // Found @0xff1e27f8
DEF(focus_busy                              ,0x000076e4) // Found @0xff1dbd54
// Palette colour tables  found @ 0xff647f80
// Camera appears to have only 1 RAW buffer @ 0x454a8d60 (Found @0xff47565c)
DEF(fileio_semaphore                        ,0x00001c80) // Found @0xff02fdf0
DEF(exmem_alloc_table                       ,0x0001729c) // Found @0xff034c5c
DEF(exmem_types_table                       ,0xff7bbe88) // Found @0x00001d10
DEF_CONST(exmem_type_count                  ,0x00000015)
DEF(imager_active                           ,0x00001fdc) // Found @0xff04dd08 (0x1fd8 + 4)
DEF_CONST(uiprop_count                      ,0x000000e9) // Found @0xff20c770

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x40711000; }             // Found @0xff06fca8
//void *vid_get_viewport_fb()      { return (void*)0x40866b80; }             // Found @0xff473aac
DEF(viewport_fb_d                           ,0x000036d8) // Found 0x367c (@0xff08d2cc) + 0x5c (@0xff08d304)
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x367c+0x5c)); } // Found @0xff08d2cc & 0xff08d304
DEF(jpeg_count_str                          ,0x00111318) // Found @0xff279060
//char *camera_jpeg_count_str()    { return (char*)0x00111318; }             // Found @0xff279060

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x01000000 // Found @0xff5f76cc, levent 0x30a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x04000000 // Found @0xff5f76dc, levent 0x302
//#define USB_IDX             2
//#define BATTCOVER_FLAG      0x02000000 // Found @0xff5f76d4, levent 0x305
//#define BATTCOVER_IDX       2
//#define ANALOG_AV_FLAG      0x00004000 // Found @0xff5f763c, levent 0x300 (non-inverted logic)
//#define ANALOG_AV_IDX       0

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_SHOOT_FULL      ,0x0000000c }, // Found @0xff5f7614, levent 0x01
//    { 0, KEY_SHOOT_FULL_ONLY ,0x00000008 }, // Found @0xff5f7614, levent 0x01
//    { 0, KEY_SHOOT_HALF      ,0x00000004 }, // Found @0xff5f760c, levent 0x00
//    { 2, KEY_POWER           ,0x00000020 }, // Found @0xff5f7654, levent 0x100
//    { 2, KEY_PLAYBACK        ,0x00000080 }, // Found @0xff5f7664, levent 0x101
//    { 2, KEY_VIDEO           ,0x00000400 }, // Found @0xff5f7674, levent 0x02
//    { 2, KEY_SET             ,0x00000800 }, // Found @0xff5f767c, levent 0x0a
//    { 2, KEY_LEFT            ,0x00001000 }, // Found @0xff5f7684, levent 0x08
//    { 2, KEY_UP              ,0x00002000 }, // Found @0xff5f768c, levent 0x06
//    { 2, KEY_RIGHT           ,0x00004000 }, // Found @0xff5f7694, levent 0x09
//    { 2, KEY_DOWN            ,0x00008000 }, // Found @0xff5f769c, levent 0x07
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#define CAM_DRYOS_2_3_R59 1 // Defined for cameras with DryOS version R59 or higher
//#define CAM_RAW_ROWPIX    5248 // Found @0xff1b23b4
//#define CAM_RAW_ROWS      3920 // Found @0xff1b23bc
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff02800c
//#define CAM_DATE_FOLDER_NAMING 0x080 // Found @0xff34434c (pass as 3rd param to GetImageFolder)
//#define PARAM_CAMERA_NAME 3 // Found @0xff717200
//#define CAM_3ARG_DebugAssert 1

// Known propcases
// //      PROPCASE_AFSTEP 13
// #define PROPCASE_FOCUS_STATE 18
// #define PROPCASE_AV 23
// #define PROPCASE_BV 40
// //      PROPCASE_DELTA_DIGITALGAIN 85
// #define PROPCASE_DELTA_SV 87
// //      PROPCASE_DELTA_ND 88
// #define PROPCASE_EV_CORRECTION_2 219
// #define PROPCASE_ORIENTATION_SENSOR 231
// #define PROPCASE_SV_MARKET 259
// //      PROPCASE_SVFIX 260
// #define PROPCASE_TV 276
// Guessed propset: uncertain (3 of 8 match), closest to 10
// Port's propset (11) may be set incorrectly

// Misc stuff
DEF(ctypes, 0xff5f45d8)

// EXMEM types:
// EXMEM_COM            0
// EXMEM_FORMATTER      1
// EXMEM_FIRMUP         2
// EXMEM_FIRMUP_INFLATE 3
// EXMEM_FIRMUP_PICTURESTYLE 4
// EXMEM_DVLPWORK       5
// EXMEM_GPS            6
// EXMEM_FACEAUTH       7
// EXMEM_OHYEARLOG      8
// EXMEM_WIFI           9
// EXMEM_LENS_FIRMUP    10
// EXMEM_LENS_COMPENSATION 11
// EXMEM_FILESTORE      12
// EXMEM_MOVIE_REC      13
// EXMEM_MOVIE_PLY      14
// EXMEM_WIDE           15
// EXMEM_AUTO_GIS_MODE  16
// EXMEM_NP_GIS_MODE    17
// EXMEM_TRIPODHDR_MODE 18
// EXMEM_HSHQ_MODE      19
// EXMEM_CRAW_REC       20

// ISR flag: 0x194c, pointer to current task's control block: 0x1948
// pointer to TCB area: 0x19cc, found @ 0xff7d0668

// LED table init @ 0xff18e0e8
// LED #1: 0xc022d200 (#98 in GPIO table), offset 0x98
// LED #2: 0xc022d1fc (#97 in GPIO table), offset 0x8
// GPIO table @ 0xff5f7098

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NHSTUB(AllocateUncacheableMemory              ,0xff027fc8) //112
NHSTUB(Close                                  ,0xff027414) //120
NHSTUB(CreateBinarySemaphore                  ,0xff0280ac) //115
NHSTUB(CreateTask                             ,0xff025140) //120
NHSTUB(DebugAssert                            ,0xff025500) //107
NHSTUB(DeleteDirectory_Fut                    ,0xff026d64) //116
NHSTUB(DoAELock                               ,0xff033624) //120
NHSTUB(DoAFLock                               ,0xff033264) //120
NHSTUB(EnterToCompensationEVF                 ,0xff03354c) //104
NHSTUB(ExecuteEventProcedure                  ,0xff035724) //104
NHSTUB(ExitFromCompensationEVF                ,0xff0335a0) //104
NHSTUB(ExitTask                               ,0xff0254b0) //120
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff045d84) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff046104) //104
NHSTUB(Fclose_Fut                             ,0xff026dfc) //120
NHSTUB(Feof_Fut                               ,0xff026fe8) //  1
NHSTUB(Fflush_Fut                             ,0xff027024) //  1
NHSTUB(Fgets_Fut                              ,0xff026f50) //  6
NHSTUB(Fopen_Fut                              ,0xff026dbc) //120
NHSTUB(Fread_Fut                              ,0xff026ea8) //120
NHSTUB(FreeUncacheableMemory                  ,0xff028004) //112
NHSTUB(Fseek_Fut                              ,0xff026f9c) //120
NHSTUB(Fwrite_Fut                             ,0xff026efc) //120
NHSTUB(GetBatteryTemperature                  ,0xff0790cc) //102
NHSTUB(GetCCDTemperature                      ,0xff079058) //102
NHSTUB(GetCurrentAvValue                      ,0xff09250c) //120
NHSTUB(GetCurrentShutterSpeed                 ,0xff12e82c) //120
NHSTUB(GetUsableMaxAv                         ,0xff1b2c58) //120
NHSTUB(GetUsableMinAv                         ,0xff1b2c3c) //120
NHSTUB(GetDrive_ClusterSize                   ,0xff031454) //122
NHSTUB(GetDrive_FreeClusters                  ,0xff031bb8) //119
NHSTUB(GetDrive_TotalClusters                 ,0xff031b8c) //122
NHSTUB(GetFocusLensSubjectDistance            ,0xff1dcf0c) //102
NHSTUB(GetImageFolder                         ,0xff1bacf8) //122
NHSTUB(GetKbdState                            ,0xff07553c) //109
NHSTUB(GetMemInfo                             ,0xff023548) //115
NHSTUB(GetOpticalTemperature                  ,0xff079140) //120
NHSTUB(GetParameterData                       ,0xff20d2c0) //101
NHSTUB(GetPropertyCase                        ,0xff0ae6e4) //101
NHSTUB(GetSystemTime                          ,0xff385e74) //120
NHSTUB(GetVRAMHPixelsSize                     ,0xff052d34) //120
NHSTUB(GetVRAMVPixelsSize                     ,0xff052d40) //120
NHSTUB(GetZoomLensCurrentPoint                ,0xff1e2c84) //120
NHSTUB(GetZoomLensCurrentPosition             ,0xff376c40) //102
NHSTUB(GiveSemaphore                          ,0xff028338) //120
NHSTUB(IsStrobeChargeCompleted                ,0xff0db6c0) //102
NHSTUB(LEDDrive                               ,0xff1f477c) //120
NHSTUB(LocalTime                              ,0xff0c8e60) //115
NHSTUB(LockMainPower                          ,0xff0b1224) //120
NHSTUB(MakeSDCardBootable                     ,0xff032118) //105
NHSTUB(MoveFocusLensToDistance                ,0xff47796c) //102
NHSTUB(MoveIrisWithAv                         ,0xff37ffd4) //120
NHSTUB(MoveZoomLensWithPoint                  ,0xff3804bc) //120
NHSTUB(MoveOpticalZoomAt                      ,0xff032c40) //109
NHSTUB(Open                                   ,0xff0273b0) //120
NHSTUB(PB2Rec                                 ,0xff05f8b4) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff1f5914) //102
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff1f58e4) //102
NHSTUB(PT_PlaySound                           ,0xff0c3360) //122
NHSTUB(PostLogicalEventForNotPowerType        ,0xff0b0658) //120
NHSTUB(PostLogicalEventToUI                   ,0xff0b06b0) //120
NHSTUB(PutInNdFilter                          ,0xff477d7c) //102
NHSTUB(PutOutNdFilter                         ,0xff477db8) //102
NHSTUB(Read                                   ,0xff024004) //120
NHSTUB(ReadFastDir                            ,0xff3625f0) //115
NHSTUB(Rec2PB                                 ,0xff05f914) //104
NHSTUB(RenameFile_Fut                         ,0xff026c5c) //116
NHSTUB(Restart                                ,0xff0387ac) //122
NHSTUB(ScreenLock                             ,0xff0b4e80) //117
NHSTUB(ScreenUnlock                           ,0xff0b4ed4) //117
NHSTUB(SetAE_ShutterSpeed                     ,0xff4728cc) //102
NHSTUB(SetAutoShutdownTime                    ,0xff0b1298) //120
NHSTUB(SetCurrentCaptureModeType              ,0xff0bfe50) //120
NHSTUB(SetFileAttributes                      ,0xff0278f0) //  6
NHSTUB(SetFileTimeStamp                       ,0xff027878) //  6
NHSTUB(SetLogicalEventActive                  ,0xff0b0d74) //120
NHSTUB(SetParameterData                       ,0xff20d220) //101
NHSTUB(SetPropertyCase                        ,0xff0ae510) //101
NHSTUB(SetScriptMode                          ,0xff0b0e0c) //120
NHSTUB(SleepTask                              ,0xff039e80) //120
NHSTUB(TakeSemaphore                          ,0xff028254) //120
NHSTUB(TurnOnDisplay                          ,0xff070088) //120
NHSTUB(TurnOffDisplay                         ,0xff070098) //120
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff22d680) //120
NHSTUB(UnlockAE                               ,0xff0336b4) //120
NHSTUB(UnlockAF                               ,0xff033294) //120
NHSTUB(UnlockMainPower                        ,0xff0b117c) //120
NHSTUB(VbattGet                               ,0xff02be78) //120
NHSTUB(Write                                  ,0xff027b80) //120
NHSTUB(WriteSDCard                            ,0x006b8324) //108
NHSTUB(_log                                   ,0x006dc020) //111
NHSTUB(_log10                                 ,0x006dc560) //112
NHSTUB(_pow                                   ,0x006dc6d8) //121
NHSTUB(_sqrt                                  ,0x006de4f0) //  6
NHSTUB(add_ptp_handler                        ,0xff1585fc) //121
NHSTUB(apex2us                                ,0xff2ef70c) //121
NHSTUB(err_init_task                          ,0xff0248d0) //111
NHSTUB(free                                   ,0xff025840) //112
NHSTUB(kbd_p1_f                               ,0xff02d154) //109
NHSTUB(kbd_p1_f_cont                          ,0xff02d160) //109
NHSTUB(kbd_p2_f                               ,0xff02c800) //109
NHSTUB(kbd_read_keys                          ,0xff02d104) //109
NHSTUB(kbd_read_keys_r2                       ,0xff074dbc) //109
NHSTUB(lseek                                  ,0xff027724) //120
NHSTUB(malloc                                 ,0xff0257e8) //112
NHSTUB(memcmp                                 ,0xff0255c0) //120
NHSTUB(memcpy                                 ,0xff0c995c) //120
NHSTUB(memset                                 ,0xff2aa420) //120
NHSTUB(mkdir                                  ,0xff027988) //121
NHSTUB(mktime_ext                             ,0xff0c90ec) //  1
NHSTUB(OpenFastDir                            ,0xff36249c) //115
NHSTUB(closedir                               ,0xff36244c) //121
NHSTUB(get_fstype                             ,0xff0313cc) //122
NHSTUB(qsort                                  ,0xff2aa3c0) //  6
NHSTUB(rand                                   ,0xff0c992c) //121
NHSTUB(realloc                                ,0xff2aa49c) //115
NHSTUB(reboot_fw_update                       ,0xff3849a8) //106
NHSTUB(set_control_event                      ,0xff0b09e4) //111
NHSTUB(srand                                  ,0xff0c9920) //122
NHSTUB(stat                                   ,0xff02776c) //109
NHSTUB(strcat                                 ,0xff03aa98) //  1
NHSTUB(strchr                                 ,0xff03ab20) //  1
NHSTUB(strcmp                                 ,0xff0256bc) //120
NHSTUB(strcpy                                 ,0xff0255a8) //120
NHSTUB(strftime                               ,0xff0c916c) //113
NHSTUB(strlen                                 ,0xff025700) //120
NHSTUB(strncmp                                ,0xff03aad4) //  1
NHSTUB(strncpy                                ,0xff028c34) //  1
NHSTUB(strrchr                                ,0xff0c9aa8) //  1
NHSTUB(strtol                                 ,0xff03aa84) //101
NHSTUB(strtolx                                ,0xff03a888) //109
   DEF(task_CaptSeq                           ,0xff09ab90) //120
   DEF(task_DvlpSeqTask                       ,0xff1f97e8) //120
   DEF(task_ExpDrv                            ,0xff0f6564) //120
   DEF(task_FileWrite                         ,0xff35dd00) //120
   DEF(task_InitFileModules                   ,0xff062d2c) //120
   DEF(task_MovieRecord                       ,0xff1ecdbc) //120
   DEF(task_PhySw                             ,0xff02cbd0) //120
   DEF(hook_CreateTask                        ,0xff025140) //105
NHSTUB(time                                   ,0xff03a22c) //119
NHSTUB(vsprintf                               ,0xff028bf4) //115
NHSTUB(EngDrvRead                             ,0xff02d264) //102
NHSTUB(PTM_GetCurrentItem                     ,0xff0b2e80) //105
NHSTUB(DisableISDriveError                    ,0xff3818bc) //120
NHSTUB(CancelHPTimer                          ,0xff0aadac) //119
NHSTUB(SetHPTimerAfterNow                     ,0xff0aaca4) //119
NHSTUB(SS_MFOn                                ,0xff1f59a8) //120
NHSTUB(SS_MFOff                               ,0xff1f59b8) //120
NHSTUB(GetAdChValue                           ,0xff071268) //120
NHSTUB(get_ptp_buf_size                       ,0xff14801c) //122
NHSTUB(get_ptp_file_buf                       ,0xff302490) //121
NHSTUB(SetVideoOutType                        ,0xff4730f0) //109
