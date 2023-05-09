// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R54 (DRYOS version 2.3, release #0054+p3)
//   Firmware Ver GM1.00D   // Found @ 0xff0a50f4, "GM1.00D" @ 0xff0a5101
//   Firmware build timestamp: Jan 14 2014 08:41:43
//   Canon PowerShot SX600 HS

// Values for makefile.inc
//   DIGIC = 41# DIGIC 4+
//   PLATFORMOSVER = 54
//   PLATFORMID = 12934# (0x3286) Found @ 0xfff40040
//   MAXRAMADDR = 0x0fffffff
//   MEMISOSTART = 0x002bec2c
//   KEYSYS = d4f# Found @ 0xff014364
//   NEED_ENCODED_DISKBOOT = 12# Found @ 0xff014374
//   ARAM_HEAP_START = 0x60e000# Found @ 0xff2214d0
//   ARAM_HEAP_SIZE  = 0x22000# Found @ 0xff221490

// Detected address ranges:
// ROM      0xff010000 - 0xffffffff (16711680 bytes)
// RAM code 0x006b1000 - 0x006dd880 copied from 0xff856738 ( 182400 bytes)
// RAM data 0x00001900 - 0x000186a4 copied from 0xff83f994 (  93604 bytes)

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
NHSTUB(DeleteFile_Fut                         ,0xff026b44) //  1 90%
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff1ff084) //  3 95%
// ERROR: MakeDirectory_Fut is not found.                  //--- ---    *** != 0xff027654
// ERROR: RefreshPhysicalScreen is not found.              //--- ---    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff3d326c -> ff77e21c
// Mode 33341 in firmware but not in current modemap

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00019430) // Found @0xff02bfd4
DEF(physw_run                               ,0x00001c94) // Found @0xff02bb18
DEF(physw_sleep_delay                       ,0x00001c9c) // Found @0xff02bb18
DEF(levent_table                            ,0xff6550a0) // Found @0xff6550a0
DEF(FlashParamsTable                        ,0xff77e4bc) // Found @0xff77e4bc
DEF(movie_status                            ,0x00009b84) // Found @0xff209710
DEF(video_compression_rate                  ,0x00009b34) // Found @0xff20a114
DEF(full_screen_refresh                     ,0x0000ab04) // Found @0xff233718
DEF(canon_menu_active                       ,0x00003cac) // Found @0xff0af948
DEF(canon_shoot_menu_active                 ,0x0000c921) // Found @0xff2ad42c
DEF(zoom_status                             ,0x0000ed40) // Found @0xff3461ec
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 2 int value(s), the first is the zoom focus length.
// there are 101 entries in the table - set NUM_FL to 101
DEF(focus_len_table                         ,0xfff4d62c) // Found @0xfff4d62c
DEF(zoom_busy                               ,0x000098f8) // Found @0xff2017e0
DEF(focus_busy                              ,0x000097a4) // Found @0xff1fdad0
// Palette colour tables  found @ 0xff65c4a4
// Camera has 2 RAW buffers @ 0x44000000 & 0x4a8013e0
//  Note: active buffer --> raw_buffers[active_raw_buffer]
//        other buffer  --> raw_buffers[active_raw_buffer^1]
DEF(raw_buffers                             ,0xff61aebc) // Found @0xff61aebc
DEF(active_raw_buffer                       ,0x000036ec) // Found @0xff096624
DEF(fileio_semaphore                        ,0x00001d28) // Found @0xff02eb40
DEF(exmem_alloc_table                       ,0x0001a7dc) // Found @0xff033900
DEF(exmem_types_table                       ,0xff83fe50) // Found @0x00001dbc
DEF_CONST(exmem_type_count                  ,0x0000001c)
DEF(imager_active                           ,0x00002084) // Found @0xff04ca54 (0x2080 + 4)
DEF_CONST(uiprop_count                      ,0x0000009d) // Found @0xff229758
DEF(cameracon_state                         ,0x00002340) // Found @0xff05a2e8

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x406f1000; }             // Found @0xff068dc4
//void *vid_get_viewport_fb()      { return (void*)0x40846b80; }             // Found @0xff4d6cf8
DEF(viewport_fb_d                           ,0x000033d4) // Found 0x3380 (@0xff088170) + 0x54 (@0xff0881a8)
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x3380+0x54)); } // Found @0xff088170 & 0xff0881a8
DEF(jpeg_count_str                          ,0x00155798) // Found @0xff297958
//char *camera_jpeg_count_str()    { return (char*)0x00155798; }             // Found @0xff297958
//int get_flash_params_count(void) { return 0xa6; }                          // Found @0xff22a1dc

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x02000000 // Found @0xff5fa0ec, levent 0x20a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x10000000 // Found @0xff5fa0fc, levent 0x202
//#define USB_IDX             2
//#define BATTCOVER_FLAG      0x04000000 // Found @0xff5fa0f4, levent 0x205
//#define BATTCOVER_IDX       2
//#define ANALOG_AV_FLAG      0x00000100 // Found @0xff5fa024, levent 0x200 (non-inverted logic)
//#define ANALOG_AV_IDX       0

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_MENU            ,0x00000200 }, // Found @0xff5fa02c, levent 0x0e
//    { 0, KEY_VIDEO           ,0x00000400 }, // Found @0xff5fa034, levent 0x02
//    { 0, KEY_SET             ,0x00000800 }, // Found @0xff5fa03c, levent 0x0a
//    { 0, KEY_LEFT            ,0x00001000 }, // Found @0xff5fa044, levent 0x08
//    { 0, KEY_UP              ,0x00002000 }, // Found @0xff5fa04c, levent 0x06
//    { 0, KEY_RIGHT           ,0x00004000 }, // Found @0xff5fa054, levent 0x09
//    { 0, KEY_DOWN            ,0x00008000 }, // Found @0xff5fa05c, levent 0x07
//    { 2, KEY_SHOOT_FULL      ,0x00000060 }, // Found @0xff5fa074, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000040 }, // Found @0xff5fa074, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00000020 }, // Found @0xff5fa06c, levent 0x00
//    { 2, KEY_PLAYBACK        ,0x00000080 }, // Found @0xff5fa07c, levent 0x101
//    { 2, KEY_POWER           ,0x00000100 }, // Found @0xff5fa084, levent 0x100
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#define CAM_RAW_ROWPIX    4768 // Found @0xff1cecf4
//#define CAM_RAW_ROWS      3516 // Found @0xff1ced00
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff025e78
//#define CAM_DATE_FOLDER_NAMING 0x080 // Found @0xff38a020 (pass as 3rd param to GetImageFolder)
//#define PARAM_CAMERA_NAME 3 // Found @0xff77d56c
//#define CAM_3ARG_DebugAssert 1
//#define CAM_HAS_WIFI 1 // Firmware has wifi support (only define if camera has hardware)

// Below goes in 'filewrite.c' or 'platform_camera.h':
//#define MAX_CHUNKS_FOR_FWT 7 // Found @0xff3a3994

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
DEF(ctypes, 0xff5f6ac8)

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
// EXMEM_WIFI_RESIZE    18
// EXMEM_PCEVF          19
// EXMEM_WIDE           20
// EXMEM_NARROW         21
// EXMEM_AUTO_GIS_MODE  22
// EXMEM_NP_GIS_MODE    23
// EXMEM_TRIPODHDR_MODE 24
// EXMEM_HSHQ_MODE      25
// EXMEM_CRAW_REC       26
// EXMEM_CREATIVE_SHOT  27

// ISR flag: 0x1944, pointer to current task's control block: 0x1940
// pointer to TCB area: 0x19c4, found @ 0xff857cb4

// LED table init @ 0xff19c8e0
// LED #1: 0xc022d200 (#98 in GPIO table), offset 0x98
// LED #2: 0xc022d1fc (#97 in GPIO table), offset 0x8
// GPIO table @ 0xff5f9ac8

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NHSTUB(AllocateUncacheableMemory              ,0xff025e34) //112
NHSTUB(Close                                  ,0xff0271b8) //120
NHSTUB(CreateBinarySemaphore                  ,0x006b784c) //115
NHSTUB(CreateTask                             ,0x006b562c) //120
NHSTUB(DebugAssert                            ,0x006b59c0) //107
NHSTUB(DeleteDirectory_Fut                    ,0xff026bb8) //116
NHSTUB(DeleteSemaphore                        ,0x006b7930) //120
NHSTUB(DoAELock                               ,0xff0322bc) //120
NHSTUB(DoAFLock                               ,0xff031f84) //120
NHSTUB(EnterToCompensationEVF                 ,0xff032220) //104
NHSTUB(ExecuteEventProcedure                  ,0xff034380) //104
NHSTUB(ExitFromCompensationEVF                ,0xff032268) //104
NHSTUB(ExitTask                               ,0x006b595c) //120
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff0448fc) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff044a70) //104
NHSTUB(Fclose_Fut                             ,0xff026c50) //120
NHSTUB(Feof_Fut                               ,0xff026e3c) //  1
NHSTUB(Fflush_Fut                             ,0xff026e78) //  1
NHSTUB(Fgets_Fut                              ,0xff026da4) //  6
NHSTUB(Fopen_Fut                              ,0xff026c10) //120
NHSTUB(Fread_Fut                              ,0xff026cfc) //120
NHSTUB(FreeUncacheableMemory                  ,0xff025e70) //112
NHSTUB(Fseek_Fut                              ,0xff026df0) //120
NHSTUB(Fwrite_Fut                             ,0xff026d50) //120
NHSTUB(GetBatteryTemperature                  ,0xff072c08) //102
NHSTUB(GetCCDTemperature                      ,0xff072b90) //102
NHSTUB(GetCurrentAvValue                      ,0xff08c4b8) //120
NHSTUB(GetCurrentShutterSpeed                 ,0xff0e7c68) //120
NHSTUB(GetDrive_ClusterSize                   ,0xff0301d4) //122
NHSTUB(GetDrive_FreeClusters                  ,0xff0309ec) //119
NHSTUB(GetDrive_TotalClusters                 ,0xff0309c0) //122
NHSTUB(GetFocusLensSubjectDistance            ,0xff1feca0) //102
NHSTUB(GetImageFolder                         ,0xff1d6944) //122
NHSTUB(GetKbdState                            ,0xff06edf4) //109
NHSTUB(GetMemInfo                             ,0xff023614) //115
NHSTUB(GetOpticalTemperature                  ,0xff072c80) //120
NHSTUB(GetParameterData                       ,0xff22a198) //101
NHSTUB(GetPropertyCase                        ,0xff0a69f0) //101
NHSTUB(GetSystemTime                          ,0xff3d0270) //120
NHSTUB(GetVRAMHPixelsSize                     ,0xff0513e8) //120
NHSTUB(GetVRAMVPixelsSize                     ,0xff0513f4) //120
NHSTUB(GetZoomLensCurrentPoint                ,0xff201c68) //120
NHSTUB(GetZoomLensCurrentPosition             ,0xff3bb550) //102
NHSTUB(GiveSemaphore                          ,0x006b7acc) //120
NHSTUB(IsStrobeChargeCompleted                ,0xff11cb80) //102
NHSTUB(LEDDrive                               ,0xff213f9c) //120
NHSTUB(LocalTime                              ,0x006b9a18) //115
NHSTUB(LockMainPower                          ,0xff0ab5c4) //120
NHSTUB(MakeSDCardBootable                     ,0xff030e98) //105
NHSTUB(MoveFocusLensToDistance                ,0xff4da678) //102
NHSTUB(MoveIrisWithAv                         ,0xff3c9bc8) //120
NHSTUB(MoveZoomLensWithPoint                  ,0xff3ca4d8) //120
NHSTUB(MoveOpticalZoomAt                      ,0xff031a28) //109
NHSTUB(Open                                   ,0xff0270f0) //120
NHSTUB(PB2Rec                                 ,0xff05aa28) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff21508c) //102
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff21505c) //102
NHSTUB(PT_PlaySound                           ,0xff0bbbb0) //122
NHSTUB(PostLogicalEventForNotPowerType        ,0xff0a889c) //120
NHSTUB(PostLogicalEventToUI                   ,0xff0a88e8) //120
NHSTUB(PutInNdFilter                          ,0xff3ca290) //102
NHSTUB(PutOutNdFilter                         ,0xff3ca2b4) //102
NHSTUB(Read                                   ,0xff0240d0) //120
NHSTUB(ReadFastDir                            ,0xff3a539c) //115
NHSTUB(Rec2PB                                 ,0xff05aa7c) //104
NHSTUB(RenameFile_Fut                         ,0xff026ab0) //116
NHSTUB(Restart                                ,0xff0373f0) //122
NHSTUB(ScreenLock                             ,0xff0af15c) //117
NHSTUB(ScreenUnlock                           ,0xff0af114) //117
NHSTUB(SetAE_ShutterSpeed                     ,0xff4d5b28) //102
NHSTUB(SetAutoShutdownTime                    ,0xff0ab638) //120
NHSTUB(SetCurrentCaptureModeType              ,0xff0b8d4c) //120
NHSTUB(SetDate                                ,0xff4d79ac) //120
NHSTUB(SetFileAttributes                      ,0xff0275bc) //  6
NHSTUB(SetFileTimeStamp                       ,0xff027544) //  6
NHSTUB(SetLogicalEventActive                  ,0xff0a8f44) //120
NHSTUB(SetParameterData                       ,0xff22a0fc) //101
NHSTUB(SetPropertyCase                        ,0xff0a6820) //101
NHSTUB(SetScriptMode                          ,0xff0a8f98) //120
NHSTUB(SleepTask                              ,0x006b8d88) //120
NHSTUB(TakeSemaphore                          ,0x006b79f4) //120
NHSTUB(TurnOffBackLight                       ,0xff0bb454) //104
NHSTUB(TurnOnBackLight                        ,0xff0bb43c) //104
NHSTUB(TurnOnDisplay                          ,0xff0691bc) //120
NHSTUB(TurnOffDisplay                         ,0xff0691cc) //120
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff248e1c) //120
NHSTUB(UnlockAE                               ,0xff0322e0) //120
NHSTUB(UnlockAF                               ,0xff031fb4) //120
NHSTUB(UnlockMainPower                        ,0xff0ab51c) //120
NHSTUB(VbattGet                               ,0xff02ae28) //120
NHSTUB(Write                                  ,0xff02720c) //120
NHSTUB(WriteSDCard                            ,0xff085f20) //108
NHSTUB(_log                                   ,0x006d8e90) //111
NHSTUB(_log10                                 ,0x006d93d0) //112
NHSTUB(_pow                                   ,0x006d9548) //121
NHSTUB(_sqrt                                  ,0x006db620) //  6
NHSTUB(add_ptp_handler                        ,0xff15450c) //121
NHSTUB(apex2us                                ,0xff2e523c) //121
NHSTUB(close                                  ,0xff023f2c) //109
NHSTUB(err_init_task                          ,0xff0249c0) //111
NHSTUB(exmem_alloc                            ,0xff033f0c) //101
NHSTUB(exmem_ualloc                           ,0xff033d78) //101
NHSTUB(exmem_ufree                            ,0xff033eb8) //101
NHSTUB(free                                   ,0xff025268) //112
NHSTUB(get_nd_value                           ,0xff3b8de8) //123
NHSTUB(get_current_nd_value                   ,0xff3b8d88) //122
NHSTUB(get_current_deltasv                    ,0xff0e8978) //122
NHSTUB(GetCurrentDriveBaseSvValue             ,0xff0ee52c) //120
NHSTUB(kbd_p1_f                               ,0xff02c024) //109
NHSTUB(kbd_p1_f_cont                          ,0xff02c030) //109
NHSTUB(kbd_p2_f                               ,0xff02b7b0) //109
NHSTUB(kbd_read_keys                          ,0xff02bfd4) //109
NHSTUB(kbd_read_keys_r2                       ,0xff06e640) //109
NHSTUB(lseek                                  ,0xff0273d4) //120
NHSTUB(malloc                                 ,0xff025210) //112
NHSTUB(memcmp                                 ,0xff024fe8) //120
NHSTUB(memcpy                                 ,0xff0bfa14) //120
NHSTUB(memset                                 ,0xff2b8450) //120
NHSTUB(mkdir                                  ,0xff027654) //121
NHSTUB(mktime_ext                             ,0xff0bf1a8) //  1
NHSTUB(open                                   ,0xff023e7c) //109
NHSTUB(OpenFastDir                            ,0xff3a5248) //115
NHSTUB(closedir                               ,0xff3a51f8) //121
NHSTUB(get_fstype                             ,0xff03014c) //122
NHSTUB(qsort                                  ,0xff2b83f0) //  6
NHSTUB(rand                                   ,0xff2b7f28) //121
NHSTUB(realloc                                ,0xff2b84cc) //115
NHSTUB(reboot_fw_update                       ,0xff3cf8e0) //106
NHSTUB(set_control_event                      ,0xff0a8c04) //111
NHSTUB(srand                                  ,0xff2b7f1c) //122
NHSTUB(stat                                   ,0xff02741c) //109
NHSTUB(strcat                                 ,0xff037d84) //  1
NHSTUB(strchr                                 ,0xff037e0c) //  1
NHSTUB(strcmp                                 ,0xff0250e4) //120
NHSTUB(strcpy                                 ,0xff024fd0) //120
NHSTUB(strftime                               ,0xff0bf1f4) //113
NHSTUB(strlen                                 ,0xff025128) //120
NHSTUB(strncmp                                ,0xff037dc0) //  1
NHSTUB(strncpy                                ,0xff027d4c) //  1
NHSTUB(strrchr                                ,0xff0bfb60) //  1
NHSTUB(strtol                                 ,0xff037d70) //101
NHSTUB(strtolx                                ,0xff037b74) //109
   DEF(task_CaptSeq                           ,0xff0942e0) //120
   DEF(task_DvlpSeqTask                       ,0xff218d40) //120
   DEF(task_ExpDrv                            ,0xff0ff890) //120
   DEF(task_FileWrite                         ,0xff3a3934) //120
   DEF(task_InitFileModules                   ,0xff05d3f0) //120
   DEF(task_MovieRecord                       ,0xff20b350) //120
   DEF(task_PhySw                             ,0xff02bb14) //120
   DEF(hook_CreateTask                        ,0x006b562c) //105
NHSTUB(time                                   ,0x006b927c) //119
NHSTUB(vsprintf                               ,0xff027d0c) //115
NHSTUB(EngDrvRead                             ,0xff02c130) //102
NHSTUB(PTM_GetCurrentItem                     ,0xff0ad1b0) //105
NHSTUB(DisableISDriveError                    ,0xff3cb14c) //120
NHSTUB(CancelHPTimer                          ,0xff0a319c) //119
NHSTUB(SetHPTimerAfterNow                     ,0xff0a3094) //119
NHSTUB(SS_MFOn                                ,0xff215120) //120
NHSTUB(SS_MFOff                               ,0xff215130) //120
NHSTUB(GetAdChValue                           ,0xff06a588) //120
NHSTUB(EnableHDMIPower                        ,0xff06d1b0) //123
NHSTUB(DisableHDMIPower                       ,0xff06d20c) //123
NHSTUB(get_ptp_buf_size                       ,0xff14f888) //122
NHSTUB(get_ptp_file_buf                       ,0xff3357e8) //121
NHSTUB(SetVideoOutType                        ,0xff4d63b4) //109
NHSTUB(GetVideoOutType                        ,0xff4d62c0) //120
NHSTUB(IsWirelessConnect                      ,0xff060370) //122
