// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R55 (DRYOS version 2.3, release #0055+p6)
//   Firmware Ver GM1.00C   // Found @ 0xff89fc98, "GM1.00C" @ 0xff89fca5
//   Firmware build timestamp: Nov  4 2015 12:03:51
//   Canon PowerShot SX410 IS

// Values for makefile.inc
//   DIGIC = 41# DIGIC 4+
//   PLATFORMOSVER = 55
//   PLATFORMID = 12973# (0x32ad) Found @ 0xffff0040
//   MAXRAMADDR = 0x07ffffff
//   MEMISOSTART = 0x001bdf3c
//   KEYSYS = d4g# Found @ 0xff812968
//   NEED_ENCODED_DISKBOOT = 13# Found @ 0xff812978
//   ARAM_HEAP_START = 0x60e000# Found @ 0xff9bf6c8
//   ARAM_HEAP_SIZE  = 0x22000# Found @ 0xff9bf688

// Detected address ranges:
// ROM      0xff810000 - 0xffffffff (8323072 bytes)
// RAM code 0x006b1000 - 0x006be8d0 copied from 0xffd52b40 (  55504 bytes)
// RAM data 0x00001900 - 0x00011460 copied from 0xffd42fe0 (  64352 bytes)

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
NHSTUB(DeleteFile_Fut                         ,0xff8274a4) //  1 90%
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff99a984) //  3 90%
// ERROR: MakeDirectory_Fut is not found.                  //--- ---    *** != 0xff827fb4
// ERROR: RefreshPhysicalScreen is not found.              //--- ---    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ffb0c5d0 -> ffd018e4
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00012224) // Found @0xff82dd38
DEF(physw_run                               ,0x00001c94) // Found @0xff82d85c
DEF(physw_sleep_delay                       ,0x00001c9c) // Found @0xff82d85c
DEF(levent_table                            ,0xffc492e0) // Found @0xffc492e0
DEF(FlashParamsTable                        ,0xffd01c1c) // Found @0xffd01c1c
DEF(movie_status                            ,0x000075cc) // Found @0xff9a9138
//DEF(video_compression_rate                  ,0x0000757c) // Found @0xff9a9e00, ** != ** stubs_min = 0x000075fc (0x75FC)
DEF(full_screen_refresh                     ,0x0000845c) // Found @0xff9d3624
DEF(canon_menu_active                       ,0x00003b88) // Found @0xff8a7fd0
DEF(canon_shoot_menu_active                 ,0x00009df5) // Found @0xffa39660
DEF(playrec_mode                            ,0x00003678) // Found @0xff896564
DEF(zoom_status                             ,0x0000b8f0) // Found @0xffa9e020
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 2 int value(s), the first is the zoom focus length.
// there are 122 entries in the table - set NUM_FL to 122
//DEF(focus_len_table                         ,0xffffae7c) // Found @0xffffae7c,          stubs_min = 0xffffae7c (0xffffae7c)
DEF(zoom_busy                               ,0x00007294) // Found @0xff99f8fc
DEF(focus_busy                              ,0x00007090) // Found @0xff999304
// Palette colour tables  found @ 0xffc4cfd4
// Camera appears to have only 1 RAW buffer @ 0x452bbf40 (Found @0xffba8700)
DEF(fileio_semaphore                        ,0x00001d0c) // Found @0xff830308
DEF(exmem_alloc_table                       ,0x0001357c) // Found @0xff834d08
DEF(exmem_types_table                       ,0xffd43484) // Found @0x00001da4
DEF_CONST(exmem_type_count                  ,0x0000001e)
DEF(imager_active                           ,0x00002040) // Found @0xff84bc00 (0x203c + 4)
DEF_CONST(uiprop_count                      ,0x000000c6) // Found @0xff9c94d0

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x40711000; }             // Found @0xff865788
//void *vid_get_viewport_fb()      { return (void*)0x40866b80; }             // Found @0xffba6d38
DEF(jpeg_count_str                          ,0x0010aed8) // Found @0xffa24808
//char *camera_jpeg_count_str()    { return (char*)0x0010aed8; }             // Found @0xffa24808
//int get_flash_params_count(void) { return 0xd4; }                          // Found @0xff9c9f54

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x02000000 // Found @0xffbf90b8, levent 0x20a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x10000000 // Found @0xffbf90c8, levent 0x202
//#define USB_IDX             2
//#define BATTCOVER_FLAG      0x04000000 // Found @0xffbf90c0, levent 0x205
//#define BATTCOVER_IDX       2
//#define ANALOG_AV_FLAG      0x00002000 // Found @0xffbf9040, levent 0x200 (non-inverted logic)
//#define ANALOG_AV_IDX       0

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_VIDEO           ,0x00000002 }, // Found @0xffbf9000, levent 0x02
//    { 0, KEY_POWER           ,0x00000020 }, // Found @0xffbf9008, levent 0x100
//    { 0, KEY_PLAYBACK        ,0x00000040 }, // Found @0xffbf9010, levent 0x101
//    { 0, KEY_SET             ,0x00000100 }, // Found @0xffbf9018, levent 0x0a
//    { 0, KEY_UP              ,0x00000200 }, // Found @0xffbf9020, levent 0x06
//    { 0, KEY_RIGHT           ,0x00000400 }, // Found @0xffbf9028, levent 0x09
//    { 0, KEY_DOWN            ,0x00000800 }, // Found @0xffbf9030, levent 0x07
//    { 0, KEY_LEFT            ,0x00001000 }, // Found @0xffbf9038, levent 0x08
//    { 0, KEY_HELP            ,0x00004000 }, // Found @0xffbf9048, levent 0x0d
//    { 0, KEY_MENU            ,0x00008000 }, // Found @0xffbf9050, levent 0x14
//    { 2, KEY_SHOOT_FULL      ,0x00000003 }, // Found @0xffbf9060, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000002 }, // Found @0xffbf9060, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00000001 }, // Found @0xffbf9058, levent 0x00
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#define CAM_RAW_ROWPIX    5248 // Found @0xff970e2c
//#define CAM_RAW_ROWS      3920 // Found @0xff970e34
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff826238
//#define CAM_DATE_FOLDER_NAMING 0x080 // Found @0xffacb490 (pass as 3rd param to GetImageFolder)
//#define PARAM_CAMERA_NAME 3 // Found @0xffd008c4
//#define CAM_3ARG_DebugAssert 1

// Below goes in 'filewrite.c' or 'platform_camera.h':
//#define MAX_CHUNKS_FOR_JPEG 7 // Found @0xffae2be8

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
DEF(ctypes, 0xffbf5da4)

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

// ISR flag: 0x1944, pointer to current task's control block: 0x1940
// pointer to TCB area: 0x19c4, found @ 0xffd540e8

// LED table init @ 0xff94cbc0
// LED #1: 0xc022d200 (#98 in GPIO table), offset 0x98
// LED #2: 0xc022d1fc (#97 in GPIO table), offset 0x8
// GPIO table @ 0xffbf8a94

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NHSTUB(AllocateUncacheableMemory              ,0xff8261f4) //112
NHSTUB(Close                                  ,0xff827b18) //120
NHSTUB(CreateBinarySemaphore                  ,0xff8262cc) //115
NHSTUB(CreateTask                             ,0xff824a30) //120
NHSTUB(DebugAssert                            ,0xff824ddc) //107
NHSTUB(DeleteDirectory_Fut                    ,0xff827518) //116
NHSTUB(DoAELock                               ,0xff833950) //120
NHSTUB(DoAFLock                               ,0xff833614) //120
NHSTUB(EnterToCompensationEVF                 ,0xff8338b4) //104
NHSTUB(ExecuteEventProcedure                  ,0xff8357ec) //104
NHSTUB(ExitFromCompensationEVF                ,0xff8338fc) //104
NHSTUB(ExitTask                               ,0xff824d78) //120
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff844580) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff844718) //104
NHSTUB(Fclose_Fut                             ,0xff8275b0) //120
NHSTUB(Feof_Fut                               ,0xff82779c) //  1
NHSTUB(Fflush_Fut                             ,0xff8277d8) //  1
NHSTUB(Fgets_Fut                              ,0xff827704) //  6
NHSTUB(Fopen_Fut                              ,0xff827570) //120
NHSTUB(Fread_Fut                              ,0xff82765c) //120
NHSTUB(FreeUncacheableMemory                  ,0xff826230) //112
NHSTUB(Fseek_Fut                              ,0xff827750) //120
NHSTUB(Fwrite_Fut                             ,0xff8276b0) //120
NHSTUB(GetBatteryTemperature                  ,0xff86e6d0) //102
NHSTUB(GetCCDTemperature                      ,0xff86e658) //102
NHSTUB(GetCurrentAvValue                      ,0xff888814) //120
NHSTUB(GetCurrentShutterSpeed                 ,0xff8ca07c) //120
NHSTUB(GetUsableMaxAv                         ,0xff9716d0) //120
NHSTUB(GetUsableMinAv                         ,0xff9716b4) //120
NHSTUB(GetDrive_ClusterSize                   ,0xff8319a0) //122
NHSTUB(GetDrive_FreeClusters                  ,0xff8321ac) //119
NHSTUB(GetDrive_TotalClusters                 ,0xff832180) //122
NHSTUB(GetFocusLensSubjectDistance            ,0xff99a5a0) //102
NHSTUB(GetImageFolder                         ,0xff9790bc) //122
NHSTUB(GetKbdState                            ,0xff86af00) //109
NHSTUB(GetMemInfo                             ,0xff823400) //115
NHSTUB(GetOpticalTemperature                  ,0xff86e748) //120
NHSTUB(GetParameterData                       ,0xff9c9f10) //101
NHSTUB(GetPropertyCase                        ,0xff8a15a8) //101
NHSTUB(GetSystemTime                          ,0xffb09904) //120
NHSTUB(GetVRAMHPixelsSize                     ,0xff850790) //120
NHSTUB(GetVRAMVPixelsSize                     ,0xff85079c) //120
NHSTUB(GetZoomLensCurrentPoint                ,0xff99fd80) //120
NHSTUB(GetZoomLensCurrentPosition             ,0xffafae58) //102
NHSTUB(GiveSemaphore                          ,0xff82654c) //120
NHSTUB(IsStrobeChargeCompleted                ,0xff8e91f4) //102
NHSTUB(LEDDrive                               ,0xff9b0f94) //120
NHSTUB(LocalTime                              ,0xff83ecf8) //115
NHSTUB(LockMainPower                          ,0xff8a3f54) //120
NHSTUB(MakeSDCardBootable                     ,0xff832574) //105
NHSTUB(MoveFocusLensToDistance                ,0xffbaa900) //102
NHSTUB(MoveIrisWithAv                         ,0xffb03b70) //120
NHSTUB(MoveZoomLensWithPoint                  ,0xffb0461c) //120
NHSTUB(MoveOpticalZoomAt                      ,0xff8330a0) //109
NHSTUB(Open                                   ,0xff827a50) //120
NHSTUB(PB2Rec                                 ,0xff85b168) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff9b2138) //102
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff9b2108) //102
NHSTUB(PT_PlaySound                           ,0xff8b4384) //122
NHSTUB(PostLogicalEventForNotPowerType        ,0xff8a3440) //120
NHSTUB(PostLogicalEventToUI                   ,0xff8a348c) //120
NHSTUB(PutInNdFilter                          ,0xffbaad74) //102
NHSTUB(PutOutNdFilter                         ,0xffbaadb0) //102
NHSTUB(Read                                   ,0xff823ebc) //120
NHSTUB(ReadFastDir                            ,0xffae7380) //115
NHSTUB(Rec2PB                                 ,0xff859570) //104
NHSTUB(RenameFile_Fut                         ,0xff827410) //116
NHSTUB(Restart                                ,0xff838898) //122
NHSTUB(ScreenLock                             ,0xff8a78f4) //117
NHSTUB(ScreenUnlock                           ,0xff8a7950) //117
NHSTUB(SetAE_ShutterSpeed                     ,0xffba5b74) //102
NHSTUB(SetAutoShutdownTime                    ,0xff8a3fc8) //120
NHSTUB(SetCurrentCaptureModeType              ,0xff8b1234) //120
NHSTUB(SetFileAttributes                      ,0xff827f1c) //  6
NHSTUB(SetFileTimeStamp                       ,0xff827ea4) //  6
NHSTUB(SetLogicalEventActive                  ,0xff8a3b38) //120
NHSTUB(SetParameterData                       ,0xff9c9e74) //101
NHSTUB(SetPropertyCase                        ,0xff8a13d0) //101
NHSTUB(SetScriptMode                          ,0xff8a3bd0) //120
NHSTUB(SleepTask                              ,0xff82a760) //120
NHSTUB(TakeSemaphore                          ,0xff826474) //120
NHSTUB(TurnOffBackLight                       ,0xff8b3a8c) //104
NHSTUB(TurnOnBackLight                        ,0xff8b3a74) //104
NHSTUB(TurnOnDisplay                          ,0xff865b68) //120
NHSTUB(TurnOffDisplay                         ,0xff865b78) //120
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff9e7b24) //120
NHSTUB(UnlockAE                               ,0xff833974) //120
NHSTUB(UnlockAF                               ,0xff833644) //120
NHSTUB(UnlockMainPower                        ,0xff8a3eac) //120
NHSTUB(VbattGet                               ,0xff82cb44) //120
NHSTUB(Write                                  ,0xff827b6c) //120
NHSTUB(WriteSDCard                            ,0xff881104) //108
NHSTUB(_log                                   ,0x006bb388) //111
NHSTUB(_log10                                 ,0x006bb8c8) //112
NHSTUB(_pow                                   ,0x006bba40) //121
NHSTUB(_sqrt                                  ,0x006bd664) //  6
NHSTUB(add_ptp_handler                        ,0xffa976bc) //121
NHSTUB(apex2us                                ,0xffa47164) //121
NHSTUB(close                                  ,0xff823d18) //109
NHSTUB(err_init_task                          ,0xff824798) //111
NHSTUB(exmem_alloc                            ,0xff8353d4) //101
NHSTUB(exmem_ualloc                           ,0xff835240) //101
NHSTUB(exmem_ufree                            ,0xff835380) //101
NHSTUB(free                                   ,0xff825628) //112
NHSTUB(kbd_p1_f                               ,0xff82dd88) //109
NHSTUB(kbd_p1_f_cont                          ,0xff82dd94) //109
NHSTUB(kbd_p2_f                               ,0xff82d4f4) //109
NHSTUB(kbd_read_keys                          ,0xff82dd38) //109
NHSTUB(kbd_read_keys_r2                       ,0xff86a8a4) //109
NHSTUB(lseek                                  ,0xff827d34) //120
NHSTUB(malloc                                 ,0xff8255d0) //112
NHSTUB(memcmp                                 ,0xff8253a8) //120
NHSTUB(memcpy                                 ,0xff8b81f0) //120
NHSTUB(memset                                 ,0xffa41130) //120
NHSTUB(mkdir                                  ,0xff827fb4) //121
NHSTUB(mktime_ext                             ,0xff8b7a78) //  1
NHSTUB(open                                   ,0xff823c68) //109
NHSTUB(OpenFastDir                            ,0xffae722c) //115
NHSTUB(closedir                               ,0xffae71dc) //121
NHSTUB(get_fstype                             ,0xff831918) //122
NHSTUB(qsort                                  ,0xffb6c8cc) //  6
NHSTUB(rand                                   ,0xffa41100) //121
NHSTUB(realloc                                ,0xffa411ac) //115
NHSTUB(reboot_fw_update                       ,0xffb08fb8) //106
NHSTUB(set_control_event                      ,0xff8a37a8) //111
NHSTUB(srand                                  ,0xffa410f4) //122
NHSTUB(stat                                   ,0xff827d7c) //109
NHSTUB(strcat                                 ,0xff839240) //  1
NHSTUB(strchr                                 ,0xff8392c8) //  1
NHSTUB(strcmp                                 ,0xff8254a4) //120
NHSTUB(strcpy                                 ,0xff825390) //120
NHSTUB(strftime                               ,0xff8b7ac4) //113
NHSTUB(strlen                                 ,0xff8254e8) //120
NHSTUB(strncmp                                ,0xff83927c) //  1
NHSTUB(strncpy                                ,0xff8286ac) //  1
NHSTUB(strrchr                                ,0xff8b833c) //  1
NHSTUB(strtol                                 ,0xff83922c) //101
NHSTUB(strtolx                                ,0xff839030) //109
   DEF(task_CaptSeq                           ,0xff890ccc) //120
   DEF(task_DvlpSeqTask                       ,0xff9b6174) //120
   DEF(task_ExpDrv                            ,0xff8e0de0) //120
   DEF(task_FileWrite                         ,0xffae2b88) //120
   DEF(task_InitFileModules                   ,0xff85ba04) //120
   DEF(task_MovieRecord                       ,0xff9a9ecc) //120
   DEF(task_PhySw                             ,0xff82d858) //120
   DEF(hook_CreateTask                        ,0xff824a30) //105
NHSTUB(time                                   ,0xff82ab10) //119
NHSTUB(vsprintf                               ,0xff82866c) //115
NHSTUB(EngDrvRead                             ,0xff82de98) //102
NHSTUB(PTM_GetCurrentItem                     ,0xff8a5b64) //105
NHSTUB(DisableISDriveError                    ,0xffb056c8) //120
NHSTUB(CancelHPTimer                          ,0xff89dd0c) //119
NHSTUB(SetHPTimerAfterNow                     ,0xff89dc04) //119
NHSTUB(SS_MFOn                                ,0xff9b21cc) //120
NHSTUB(SS_MFOff                               ,0xff9b21dc) //120
NHSTUB(GetAdChValue                           ,0xff866da0) //120
NHSTUB(get_ptp_buf_size                       ,0xff928eac) //122
NHSTUB(get_ptp_file_buf                       ,0xffa99318) //121
NHSTUB(SetVideoOutType                        ,0xffba63c0) //109
NHSTUB(GetVideoOutType                        ,0xffba630c) //120
