// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R59 (DRYOS version 2.3, release #0059+p3)
//   Firmware Ver GM1.00D   // Found @ 0xff0ac3bc, "GM1.00D" @ 0xff0ac3c9
//   Firmware build timestamp: Nov 14 2016 10:10:59
//   Canon IXUS 190 

// Values for makefile.inc
//   DIGIC = 41# DIGIC 4+
//   PLATFORMOSVER = 59
//   PLATFORMID = 13011# (0x32d3) Found @ 0xfffe0270
//   MAXRAMADDR = 0x07ffffff
//   MEMISOSTART = 0x0028e804
//   KEYSYS = d4j# Found @ 0xff014590
//   NEED_ENCODED_DISKBOOT = 17# Found @ 0xff0145a0

// Detected address ranges:
// ROM      0xff010000 - 0xffffffff (16711680 bytes)
// RAM code 0x006b1000 - 0x006e01c4 copied from 0xff7762e0 ( 192964 bytes)
// RAM data 0x00001900 - 0x00013904 copied from 0xff7642dc (  73732 bytes)

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
NHSTUB(DeleteFile_Fut                         ,0xff026cf0) //  1 90%
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff1d54f0) //  3 90%
// ERROR: MakeDirectory_Fut is not found.                  //--- ---    *** != 0xff027988
// ERROR: RefreshPhysicalScreen is not found.              //--- ---    *** != 0x00000000
// ERROR: TurnOffBackLight is not found.                   //--- ---    *** != 0x00000000
// ERROR: TurnOnBackLight is not found.                    //--- ---    *** != 0x00000000
// ERROR: close is not found.                              //--- ---    *** != 0xff023e60
// ERROR: exmem_ualloc is not found.                       //--- ---    *** != 0xff034fd8
// ERROR: exmem_ufree is not found.                        //--- ---    *** != 0xff035070
// ERROR: open is not found.                               //--- ---    *** != 0xff023db0

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff361518 -> ff6cc3b4
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x0001469c) // Found @0xff02d0ac
DEF(physw_run                               ,0x00001be4) // Found @0xff02cb88
DEF(physw_sleep_delay                       ,0x00001bec) // Found @0xff02cb88
DEF(levent_table                            ,0xff6000f8) // Found @0xff6000f8
DEF(FlashParamsTable                        ,0xff6cc774) // Found @0xff6cc774
DEF(movie_status                            ,0x000078e4) // Found @0xff1e078c
DEF(video_compression_rate                  ,0x00007894) // Found @0xff1e1460
DEF(full_screen_refresh                     ,0x0000847c) // Found @0xff203ab4
DEF(canon_menu_active                       ,0x0000407c) // Found @0xff0b4bd4
DEF(canon_shoot_menu_active                 ,0x0000a0a1) // Found @0xff272b60
DEF(zoom_status                             ,0x0000b62c) // Found @0xff179148
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 2 int value(s), the first is the zoom focus length.
// there are 101 entries in the table - set NUM_FL to 101
DEF(focus_len_table                         ,0xfffee67c) // Found @0xfffee67c
DEF(zoom_busy                               ,0x00007648) // Found @0xff1d8058
DEF(focus_busy                              ,0x0000750c) // Found @0xff1d3f54
// Palette colour tables  found @ 0xff6044c8
// Camera appears to have only 1 RAW buffer @ 0x43924c60 (Found @0xff4450bc)
DEF(fileio_semaphore                        ,0x00001c80) // Found @0xff02fbbc
DEF(exmem_alloc_table                       ,0x00015c64) // Found @0xff0349ac
DEF(exmem_types_table                       ,0xff7646ec) // Found @0x00001d10
DEF_CONST(exmem_type_count                  ,0x00000015)
DEF(imager_active                           ,0x00001fdc) // Found @0xff04d808 (0x1fd8 + 4)
DEF_CONST(uiprop_count                      ,0x000000e9) // Found @0xff1f9bc8
DEF(cameracon_state                         ,0x000023cc) // Found @0xff05eac0

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x40711000; }             // Found @0xff070edc
//void *vid_get_viewport_fb()      { return (void*)0x40866b80; }             // Found @0xff44350c
DEF(viewport_fb_d                           ,0x0000374c) // Found 0x36f0 (@0xff08e3f8) + 0x5c (@0xff08e430)
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x36f0+0x5c)); } // Found @0xff08e3f8 & 0xff08e430
DEF(jpeg_count_str                          ,0x000e8200) // Found @0xff25c6d0
//char *camera_jpeg_count_str()    { return (char*)0x000e8200; }             // Found @0xff25c6d0

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00400000 // Found @0xff5ba4b4, levent 0x30a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x01000000 // Found @0xff5ba4c4, levent 0x302
//#define USB_IDX             2
//#define BATTCOVER_FLAG      0x00800000 // Found @0xff5ba4bc, levent 0x305
//#define BATTCOVER_IDX       2
//#define ANALOG_AV_FLAG      0x00004000 // Found @0xff5ba434, levent 0x300 (non-inverted logic)
//#define ANALOG_AV_IDX       0

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_SHOOT_FULL      ,0x0000000c }, // Found @0xff5ba41c, levent 0x01
//    { 0, KEY_SHOOT_FULL_ONLY ,0x00000008 }, // Found @0xff5ba41c, levent 0x01
//    { 0, KEY_SHOOT_HALF      ,0x00000004 }, // Found @0xff5ba414, levent 0x00
//    { 0, KEY_ZOOM_IN         ,0x00000200 }, // Found @0xff5ba424, levent 0x03
//    { 0, KEY_ZOOM_OUT        ,0x00000400 }, // Found @0xff5ba42c, levent 0x04
//    { 2, KEY_POWER           ,0x00000020 }, // Found @0xff5ba43c, levent 0x100
//    { 2, KEY_PLAYBACK        ,0x00000080 }, // Found @0xff5ba44c, levent 0x101
//    { 2, KEY_VIDEO           ,0x00000400 }, // Found @0xff5ba45c, levent 0x02
//    { 2, KEY_SET             ,0x00000800 }, // Found @0xff5ba464, levent 0x0a
//    { 2, KEY_LEFT            ,0x00001000 }, // Found @0xff5ba46c, levent 0x08
//    { 2, KEY_UP              ,0x00002000 }, // Found @0xff5ba474, levent 0x06
//    { 2, KEY_RIGHT           ,0x00004000 }, // Found @0xff5ba47c, levent 0x09
//    { 2, KEY_DOWN            ,0x00008000 }, // Found @0xff5ba484, levent 0x07
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#define CAM_DRYOS_2_3_R59 1 // Defined for cameras with DryOS version R59 or higher
//#define CAM_RAW_ROWPIX    5248 // Found @0xff1ab7d8
//#define CAM_RAW_ROWS      3920 // Found @0xff1ab7e0
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff02800c
//#define CAM_DATE_FOLDER_NAMING 0x080 // Found @0xff3216d8 (pass as 3rd param to GetImageFolder)
//#define PARAM_CAMERA_NAME 3 // Found @0xff6caefc
//#define CAM_3ARG_DebugAssert 1
//#define CAM_HAS_WIFI 1 // Firmware has wifi support (only define if camera has hardware)

// Below goes in 'filewrite.c' or 'platform_camera.h':
//#define MAX_CHUNKS_FOR_FWT 7 // Found @0xff3381e8

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
// Guessed propset: 11

// Misc stuff
DEF(ctypes, 0xff5b7640)

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
// pointer to TCB area: 0x19cc, found @ 0xff7778a0

// LED table init @ 0xff187524
// LED #1: 0xc022d200 (#98 in GPIO table), offset 0x98
// LED #2: 0xc022d1fc (#97 in GPIO table), offset 0x8
// GPIO table @ 0xff5b9ea4

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NHSTUB(AllocateUncacheableMemory              ,0xff027fc8) //112
NHSTUB(Close                                  ,0xff027414) //120
NHSTUB(CreateBinarySemaphore                  ,0xff0280ac) //115
NHSTUB(CreateTask                             ,0xff025140) //120
NHSTUB(DebugAssert                            ,0xff025500) //107
NHSTUB(DeleteDirectory_Fut                    ,0xff026d64) //116
NHSTUB(DeleteSemaphore                        ,0xff028190) //120
NHSTUB(DoAELock                               ,0xff0333f0) //120
NHSTUB(DoAFLock                               ,0xff033030) //120
NHSTUB(EnterToCompensationEVF                 ,0xff033318) //104
NHSTUB(ExecuteEventProcedure                  ,0xff035474) //104
NHSTUB(ExitFromCompensationEVF                ,0xff03336c) //104
NHSTUB(ExitTask                               ,0xff0254b0) //120
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff0458ac) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff045c2c) //104
NHSTUB(Fclose_Fut                             ,0xff026dfc) //120
NHSTUB(Feof_Fut                               ,0xff026fe8) //  1
NHSTUB(Fflush_Fut                             ,0xff027024) //  1
NHSTUB(Fgets_Fut                              ,0xff026f50) //  6
NHSTUB(Fopen_Fut                              ,0xff026dbc) //120
NHSTUB(Fread_Fut                              ,0xff026ea8) //120
NHSTUB(FreeUncacheableMemory                  ,0xff028004) //112
NHSTUB(Fseek_Fut                              ,0xff026f9c) //120
NHSTUB(Fwrite_Fut                             ,0xff026efc) //120
NHSTUB(GetBatteryTemperature                  ,0xff07a1a0) //102
NHSTUB(GetCCDTemperature                      ,0xff07a12c) //102
NHSTUB(GetCurrentAvValue                      ,0xff092160) //120
NHSTUB(GetCurrentShutterSpeed                 ,0xff128038) //120
NHSTUB(GetUsableMaxAv                         ,0xff1abfe0) //120
NHSTUB(GetUsableMinAv                         ,0xff1abfc4) //120
NHSTUB(GetDrive_ClusterSize                   ,0xff031220) //122
NHSTUB(GetDrive_FreeClusters                  ,0xff031984) //119
NHSTUB(GetDrive_TotalClusters                 ,0xff031958) //122
NHSTUB(GetFocusLensSubjectDistance            ,0xff1d510c) //102
NHSTUB(GetImageFolder                         ,0xff1b4028) //122
NHSTUB(GetKbdState                            ,0xff076610) //109
NHSTUB(GetMemInfo                             ,0xff023548) //115
NHSTUB(GetOpticalTemperature                  ,0xff07a214) //120
NHSTUB(GetParameterData                       ,0xff1fa718) //101
NHSTUB(GetPropertyCase                        ,0xff0adcc4) //101
NHSTUB(GetSystemTime                          ,0xff35ef24) //120
NHSTUB(GetVRAMHPixelsSize                     ,0xff052834) //120
NHSTUB(GetVRAMVPixelsSize                     ,0xff052840) //120
NHSTUB(GetZoomLensCurrentPoint                ,0xff1d84ec) //120
NHSTUB(GetZoomLensCurrentPosition             ,0xff34e8c0) //102
NHSTUB(GiveSemaphore                          ,0xff028338) //120
NHSTUB(IsStrobeChargeCompleted                ,0xff0d7168) //102
NHSTUB(LEDDrive                               ,0xff1e237c) //120
NHSTUB(LocalTime                              ,0xff0c4ff0) //115
NHSTUB(LockMainPower                          ,0xff0b07a4) //120
NHSTUB(MakeSDCardBootable                     ,0xff031ee4) //105
NHSTUB(MoveFocusLensToDistance                ,0xff4473cc) //102
NHSTUB(MoveIrisWithAv                         ,0xff35939c) //120
NHSTUB(MoveZoomLensWithPoint                  ,0xff359550) //120
NHSTUB(MoveOpticalZoomAt                      ,0xff032a0c) //109
NHSTUB(Open                                   ,0xff0273b0) //120
NHSTUB(PB2Rec                                 ,0xff05f3b4) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff1e34f0) //102
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff1e34c0) //102
NHSTUB(PT_PlaySound                           ,0xff0bfc30) //122
NHSTUB(PostLogicalEventForNotPowerType        ,0xff0afc38) //120
NHSTUB(PostLogicalEventToUI                   ,0xff0afc90) //120
NHSTUB(PutInNdFilter                          ,0xff359200) //102
NHSTUB(PutOutNdFilter                         ,0xff359224) //102
NHSTUB(Read                                   ,0xff024004) //120
NHSTUB(ReadFastDir                            ,0xff33ca7c) //115
NHSTUB(Rec2PB                                 ,0xff05f414) //104
NHSTUB(RenameFile_Fut                         ,0xff026c5c) //116
NHSTUB(Restart                                ,0xff0384fc) //122
NHSTUB(ScreenLock                             ,0xff0b4484) //117
NHSTUB(ScreenUnlock                           ,0xff0b44d8) //117
NHSTUB(SetAE_ShutterSpeed                     ,0xff44232c) //102
NHSTUB(SetAutoShutdownTime                    ,0xff0b0818) //120
NHSTUB(SetCurrentCaptureModeType              ,0xff0bc3b0) //120
NHSTUB(SetDate                                ,0xff4441f4) //120
NHSTUB(SetFileAttributes                      ,0xff0278f0) //  6
NHSTUB(SetFileTimeStamp                       ,0xff027878) //  6
NHSTUB(SetLogicalEventActive                  ,0xff0b0304) //120
NHSTUB(SetParameterData                       ,0xff1fa678) //101
NHSTUB(SetPropertyCase                        ,0xff0adaf0) //101
NHSTUB(SetScriptMode                          ,0xff0b0358) //120
NHSTUB(SleepTask                              ,0xff039bd0) //120
NHSTUB(TakeSemaphore                          ,0xff028254) //120
NHSTUB(TurnOnDisplay                          ,0xff0712bc) //120
NHSTUB(TurnOffDisplay                         ,0xff0712cc) //120
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff21a1dc) //120
NHSTUB(UnlockAE                               ,0xff033480) //120
NHSTUB(UnlockAF                               ,0xff033060) //120
NHSTUB(UnlockMainPower                        ,0xff0b06fc) //120
NHSTUB(VbattGet                               ,0xff02be2c) //120
NHSTUB(Write                                  ,0xff027b80) //120
NHSTUB(WriteSDCard                            ,0x006b8324) //108
NHSTUB(_log                                   ,0x006dc020) //111
NHSTUB(_log10                                 ,0x006dc560) //112
NHSTUB(_pow                                   ,0x006dc6d8) //121
NHSTUB(_sqrt                                  ,0x006de4f0) //  6
NHSTUB(add_ptp_handler                        ,0xff1518dc) //121
NHSTUB(apex2us                                ,0xff2d2d8c) //121
NHSTUB(err_init_task                          ,0xff0248d0) //111
NHSTUB(free                                   ,0xff025840) //112
NHSTUB(get_nd_value                           ,0xff34c264) //123
NHSTUB(get_current_nd_value                   ,0xff34c204) //122
NHSTUB(get_current_deltasv                    ,0xff1246dc) //122
NHSTUB(GetCurrentDriveBaseSvValue             ,0xff0d075c) //120
NHSTUB(kbd_p1_f                               ,0xff02d0fc) //109
NHSTUB(kbd_p1_f_cont                          ,0xff02d108) //109
NHSTUB(kbd_p2_f                               ,0xff02c7b4) //109
NHSTUB(kbd_read_keys                          ,0xff02d0ac) //109
NHSTUB(kbd_read_keys_r2                       ,0xff075fe0) //109
NHSTUB(lseek                                  ,0xff027724) //120
NHSTUB(malloc                                 ,0xff0257e8) //112
NHSTUB(memcmp                                 ,0xff0255c0) //120
NHSTUB(memcpy                                 ,0xff0c5aec) //120
NHSTUB(memset                                 ,0xff28e630) //120
NHSTUB(mkdir                                  ,0xff027988) //121
NHSTUB(mktime_ext                             ,0xff0c527c) //  1
NHSTUB(OpenFastDir                            ,0xff33c928) //115
NHSTUB(closedir                               ,0xff33c8d8) //121
NHSTUB(get_fstype                             ,0xff031198) //122
NHSTUB(qsort                                  ,0xff28e5d0) //  6
NHSTUB(rand                                   ,0xff0c5abc) //121
NHSTUB(realloc                                ,0xff28e6ac) //115
NHSTUB(reboot_fw_update                       ,0xff35da58) //106
NHSTUB(set_control_event                      ,0xff0affc4) //111
NHSTUB(srand                                  ,0xff0c5ab0) //122
NHSTUB(stat                                   ,0xff02776c) //109
NHSTUB(strcat                                 ,0xff03a7e8) //  1
NHSTUB(strchr                                 ,0xff03a870) //  1
NHSTUB(strcmp                                 ,0xff0256bc) //120
NHSTUB(strcpy                                 ,0xff0255a8) //120
NHSTUB(strftime                               ,0xff0c52fc) //113
NHSTUB(strlen                                 ,0xff025700) //120
NHSTUB(strncmp                                ,0xff03a824) //  1
NHSTUB(strncpy                                ,0xff028c34) //  1
NHSTUB(strrchr                                ,0xff0c5c38) //  1
NHSTUB(strtol                                 ,0xff03a7d4) //101
NHSTUB(strtolx                                ,0xff03a5d8) //109
   DEF(task_CaptSeq                           ,0xff09a174) //120
   DEF(task_DvlpSeqTask                       ,0xff1e7378) //120
   DEF(task_ExpDrv                            ,0xff0f1f5c) //120
   DEF(task_FileWrite                         ,0xff33818c) //120
   DEF(task_InitFileModules                   ,0xff062470) //120
   DEF(task_MovieRecord                       ,0xff1e152c) //120
   DEF(task_PhySw                             ,0xff02cb84) //120
   DEF(hook_CreateTask                        ,0xff025140) //105
NHSTUB(time                                   ,0xff039f7c) //119
NHSTUB(vsprintf                               ,0xff028bf4) //115
NHSTUB(EngDrvRead                             ,0xff02d20c) //102
NHSTUB(PTM_GetCurrentItem                     ,0xff0b2474) //105
NHSTUB(DisableISDriveError                    ,0xff35a950) //120
NHSTUB(CancelHPTimer                          ,0xff0aa38c) //119
NHSTUB(SetHPTimerAfterNow                     ,0xff0aa284) //119
NHSTUB(SS_MFOn                                ,0xff1e3584) //120
NHSTUB(SS_MFOff                               ,0xff1e3594) //120
NHSTUB(GetAdChValue                           ,0xff0724a8) //120
NHSTUB(get_ptp_buf_size                       ,0xff141360) //122
NHSTUB(get_ptp_file_buf                       ,0xff2e5b10) //121
NHSTUB(SetVideoOutType                        ,0xff442b50) //109
NHSTUB(GetVideoOutType                        ,0xff442ac4) //120
NHSTUB(IsWirelessConnect                      ,0xff06652c) //122
