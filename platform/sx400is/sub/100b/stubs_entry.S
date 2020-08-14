// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R55 (DRYOS version 2.3, release #0055+p6)
//   Firmware Ver GM1.00B   // Found @ 0xff89f678, "GM1.00B" @ 0xff89f685
//   Firmware build timestamp: Jun 12 2014 14:22:20
//   Canon PowerShot SX400 IS

// Values for makefile.inc
//   DIGIC = 41# DIGIC 4+
//   PLATFORMOSVER = 55
//   PLATFORMID = 12956# (0x329c) Found @ 0xffff0040
//   MAXRAMADDR = 0x07ffffff
//   MEMISOSTART = 0x001bade8
//   KEYSYS = d4h# Found @ 0xff81287c
//   NEED_ENCODED_DISKBOOT = 14# Found @ 0xff81288c
//   ARAM_HEAP_START = 0x60e000# Found @ 0xff9bd628
//   ARAM_HEAP_SIZE  = 0x22000# Found @ 0xff9bd5e8

// Detected address ranges:
// ROM      0xff810000 - 0xffffffff (8323072 bytes)
// RAM code 0x006b1000 - 0x006be81c copied from 0xffd56848 (  55324 bytes)
// RAM data 0x00001900 - 0x000113d0 copied from 0xffd46d78 (  64208 bytes)

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
NHSTUB(DeleteFile_Fut                         ,0xff8274a0) //  1 90%
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff99a034) //  3 95%
// ERROR: MakeDirectory_Fut is not found.                  //--- ---    *** != 0xff827fb0
// ERROR: RefreshPhysicalScreen is not found.              //--- ---    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ffb085e4 -> ffd00ad4
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00012184) // Found @0xff82dd34
DEF(physw_run                               ,0x00001c94) // Found @0xff82d858
DEF(physw_sleep_delay                       ,0x00001c9c) // Found @0xff82d858
DEF(levent_table                            ,0xffc45dfc) // Found @0xffc45dfc
DEF(FlashParamsTable                        ,0xffd00e0c) // Found @0xffd00e0c
DEF(movie_status                            ,0x0000757c) // Found @0xff9a7100
//DEF(video_compression_rate                  ,0x0000752c) // Found @0xff9a7dc8, ** != ** stubs_min = 0x000075ac (0x75AC)
DEF(full_screen_refresh                     ,0x00008414) // Found @0xff9d1544
DEF(canon_menu_active                       ,0x00003b68) // Found @0xff8a7990
DEF(canon_shoot_menu_active                 ,0x00009dad) // Found @0xffa3756c
DEF(playrec_mode                            ,0x00003658) // Found @0xff895f44
DEF(zoom_status                             ,0x0000b8d8) // Found @0xffa9bf90
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 2 int value(s), the first is the zoom focus length.
// there are 127 entries in the table - set NUM_FL to 127
DEF(focus_len_table                         ,0xffffae94) // Found @0xffffae94
DEF(zoom_busy                               ,0x00007264) // Found @0xff99e748
DEF(focus_busy                              ,0x00007064) // Found @0xff998a2c
// Palette colour tables  found @ 0xffc49af0
// Camera appears to have only 1 RAW buffer @ 0x42fb5130 (Found @0xffba36b0)
DEF(fileio_semaphore                        ,0x00001d0c) // Found @0xff830304
DEF(exmem_alloc_table                       ,0x000134dc) // Found @0xff834d04
DEF(exmem_types_table                       ,0xffd4721c) // Found @0x00001da4
DEF_CONST(exmem_type_count                  ,0x0000001e)
DEF(imager_active                           ,0x0000203c) // Found @0xff84bb7c (0x2038 + 4)
DEF_CONST(uiprop_count                      ,0x000000c6) // Found @0xff9c7430

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x40711000; }             // Found @0xff865754
//void *vid_get_viewport_fb()      { return (void*)0x40866b80; }             // Found @0xffba1ce8
DEF(jpeg_count_str                          ,0x0010ab00) // Found @0xffa22718
//char *camera_jpeg_count_str()    { return (char*)0x0010ab00; }             // Found @0xffa22718
//int get_flash_params_count(void) { return 0xd4; }                          // Found @0xff9c7eb4

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x02000000 // Found @0xffbf4c44, levent 0x20a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x10000000 // Found @0xffbf4c54, levent 0x202
//#define USB_IDX             2
//#define BATTCOVER_FLAG      0x04000000 // Found @0xffbf4c4c, levent 0x205
//#define BATTCOVER_IDX       2
//#define ANALOG_AV_FLAG      0x00000080 // Found @0xffbf4bdc, levent 0x200 (non-inverted logic)
//#define ANALOG_AV_IDX       2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 2, KEY_SET             ,0x00000001 }, // Found @0xffbf4ba4, levent 0x0a
//    { 2, KEY_UP              ,0x00000002 }, // Found @0xffbf4bac, levent 0x06
//    { 2, KEY_RIGHT           ,0x00000004 }, // Found @0xffbf4bb4, levent 0x09
//    { 2, KEY_DOWN            ,0x00000008 }, // Found @0xffbf4bbc, levent 0x07
//    { 2, KEY_LEFT            ,0x00000010 }, // Found @0xffbf4bc4, levent 0x08
//    { 2, KEY_SHOOT_FULL      ,0x00000060 }, // Found @0xffbf4bd4, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000040 }, // Found @0xffbf4bd4, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00000020 }, // Found @0xffbf4bcc, levent 0x00
//    { 2, KEY_POWER           ,0x00000100 }, // Found @0xffbf4be4, levent 0x100
//    { 2, KEY_PLAYBACK        ,0x00000200 }, // Found @0xffbf4bec, levent 0x101
//    { 2, KEY_HELP            ,0x00000400 }, // Found @0xffbf4bf4, levent 0x0d
//    { 2, KEY_MENU            ,0x00001000 }, // Found @0xffbf4c04, levent 0x14
//    { 2, KEY_VIDEO           ,0x00002000 }, // Found @0xffbf4c0c, levent 0x02
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#define CAM_RAW_ROWPIX    4704 // Found @0xff970830
//#define CAM_RAW_ROWS      3504 // Found @0xff97083c
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff826234
//#define CAM_DATE_FOLDER_NAMING 0x080 // Found @0xffac9420 (pass as 3rd param to GetImageFolder)
//#define PARAM_CAMERA_NAME 3 // Found @0xffcffab4
//#define CAM_3ARG_DebugAssert 1

// Below goes in 'filewrite.c' or 'platform_camera.h':
//#define MAX_CHUNKS_FOR_JPEG 7 // Found @0xffae0b78

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
DEF(ctypes, 0xffbf07a8)

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
// pointer to TCB area: 0x19c4, found @ 0xffd57df0

// LED table init @ 0xff94c5d0
// LED #1: 0xc022d200 (#98 in GPIO table), offset 0x98
// LED #2: 0xc022d1fc (#97 in GPIO table), offset 0x8
// GPIO table @ 0xffbf4620

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NHSTUB(AllocateUncacheableMemory              ,0xff8261f0) //112
NHSTUB(Close                                  ,0xff827b14) //120
NHSTUB(CreateBinarySemaphore                  ,0xff8262c8) //115
NHSTUB(CreateTask                             ,0xff824a2c) //120
NHSTUB(DebugAssert                            ,0xff824dd8) //107
NHSTUB(DeleteDirectory_Fut                    ,0xff827514) //116
NHSTUB(DoAELock                               ,0xff83394c) //120
NHSTUB(DoAFLock                               ,0xff833610) //120
NHSTUB(EnterToCompensationEVF                 ,0xff8338b0) //104
NHSTUB(ExecuteEventProcedure                  ,0xff8357e8) //104
NHSTUB(ExitFromCompensationEVF                ,0xff8338f8) //104
NHSTUB(ExitTask                               ,0xff824d74) //120
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff84457c) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff844714) //104
NHSTUB(Fclose_Fut                             ,0xff8275ac) //120
NHSTUB(Feof_Fut                               ,0xff827798) //  1
NHSTUB(Fflush_Fut                             ,0xff8277d4) //  1
NHSTUB(Fgets_Fut                              ,0xff827700) //  6
NHSTUB(Fopen_Fut                              ,0xff82756c) //120
NHSTUB(Fread_Fut                              ,0xff827658) //120
NHSTUB(FreeUncacheableMemory                  ,0xff82622c) //112
NHSTUB(Fseek_Fut                              ,0xff82774c) //120
NHSTUB(Fwrite_Fut                             ,0xff8276ac) //120
NHSTUB(GetBatteryTemperature                  ,0xff86e628) //102
NHSTUB(GetCCDTemperature                      ,0xff86e5b0) //102
NHSTUB(GetCurrentAvValue                      ,0xff88861c) //120
NHSTUB(GetCurrentShutterSpeed                 ,0xff8c9a3c) //120
NHSTUB(GetUsableMaxAv                         ,0xff9710d8) //120
NHSTUB(GetUsableMinAv                         ,0xff9710bc) //120
NHSTUB(GetDrive_ClusterSize                   ,0xff83199c) //122
NHSTUB(GetDrive_FreeClusters                  ,0xff8321a8) //119
NHSTUB(GetDrive_TotalClusters                 ,0xff83217c) //122
NHSTUB(GetFocusLensSubjectDistance            ,0xff999c50) //102
NHSTUB(GetImageFolder                         ,0xff9787b0) //122
NHSTUB(GetKbdState                            ,0xff86ae4c) //109
NHSTUB(GetMemInfo                             ,0xff8233fc) //115
NHSTUB(GetOpticalTemperature                  ,0xff86e6a0) //120
NHSTUB(GetParameterData                       ,0xff9c7e70) //101
NHSTUB(GetPropertyCase                        ,0xff8a0f88) //101
NHSTUB(GetSystemTime                          ,0xffb05920) //120
NHSTUB(GetVRAMHPixelsSize                     ,0xff850780) //120
NHSTUB(GetVRAMVPixelsSize                     ,0xff85078c) //120
NHSTUB(GetZoomLensCurrentPoint                ,0xff99ebd0) //120
NHSTUB(GetZoomLensCurrentPosition             ,0xffaf8008) //102
NHSTUB(GiveSemaphore                          ,0xff826548) //120
NHSTUB(IsStrobeChargeCompleted                ,0xff8e8d2c) //102
NHSTUB(LEDDrive                               ,0xff9aeef4) //120
NHSTUB(LocalTime                              ,0xff83ecf4) //115
NHSTUB(LockMainPower                          ,0xff8a3934) //120
NHSTUB(MakeSDCardBootable                     ,0xff832570) //105
NHSTUB(MoveFocusLensToDistance                ,0xffba58a4) //102
NHSTUB(MoveIrisWithAv                         ,0xffb006b4) //120
NHSTUB(MoveZoomLensWithPoint                  ,0xffb01114) //120
NHSTUB(MoveOpticalZoomAt                      ,0xff83309c) //109
NHSTUB(Open                                   ,0xff827a4c) //120
NHSTUB(PB2Rec                                 ,0xff85b140) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff9b0098) //102
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff9b0068) //102
NHSTUB(PT_PlaySound                           ,0xff8b3d44) //122
NHSTUB(PostLogicalEventForNotPowerType        ,0xff8a2e20) //120
NHSTUB(PostLogicalEventToUI                   ,0xff8a2e6c) //120
NHSTUB(PutInNdFilter                          ,0xffba5d18) //102
NHSTUB(PutOutNdFilter                         ,0xffba5d54) //102
NHSTUB(Read                                   ,0xff823eb8) //120
NHSTUB(ReadFastDir                            ,0xffae5310) //115
NHSTUB(Rec2PB                                 ,0xff859564) //104
NHSTUB(RenameFile_Fut                         ,0xff82740c) //116
NHSTUB(Restart                                ,0xff838894) //122
NHSTUB(ScreenLock                             ,0xff8a72b4) //117
NHSTUB(ScreenUnlock                           ,0xff8a7310) //117
NHSTUB(SetAE_ShutterSpeed                     ,0xffba0b24) //102
NHSTUB(SetAutoShutdownTime                    ,0xff8a39a8) //120
NHSTUB(SetCurrentCaptureModeType              ,0xff8b0bf4) //120
NHSTUB(SetFileAttributes                      ,0xff827f18) //  6
NHSTUB(SetFileTimeStamp                       ,0xff827ea0) //  6
NHSTUB(SetLogicalEventActive                  ,0xff8a3518) //120
NHSTUB(SetParameterData                       ,0xff9c7dd4) //101
NHSTUB(SetPropertyCase                        ,0xff8a0db0) //101
NHSTUB(SetScriptMode                          ,0xff8a35b0) //120
NHSTUB(SleepTask                              ,0xff82a75c) //120
NHSTUB(TakeSemaphore                          ,0xff826470) //120
NHSTUB(TurnOffBackLight                       ,0xff8b344c) //104
NHSTUB(TurnOnBackLight                        ,0xff8b3434) //104
NHSTUB(TurnOnDisplay                          ,0xff865b34) //120
NHSTUB(TurnOffDisplay                         ,0xff865b44) //120
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff9e5a3c) //120
NHSTUB(UnlockAE                               ,0xff833970) //120
NHSTUB(UnlockAF                               ,0xff833640) //120
NHSTUB(UnlockMainPower                        ,0xff8a388c) //120
NHSTUB(VbattGet                               ,0xff82cb40) //120
NHSTUB(Write                                  ,0xff827b68) //120
NHSTUB(WriteSDCard                            ,0xff880fe0) //108
NHSTUB(_log                                   ,0x006bb308) //111
NHSTUB(_log10                                 ,0x006bb848) //112
NHSTUB(_pow                                   ,0x006bb9c0) //121
NHSTUB(_sqrt                                  ,0x006bd5e4) //  6
NHSTUB(add_ptp_handler                        ,0xffa9562c) //121
NHSTUB(apex2us                                ,0xffa45070) //121
NHSTUB(close                                  ,0xff823d14) //109
NHSTUB(err_init_task                          ,0xff824794) //111
NHSTUB(exmem_alloc                            ,0xff8353d0) //101
NHSTUB(exmem_ualloc                           ,0xff83523c) //101
NHSTUB(exmem_ufree                            ,0xff83537c) //101
NHSTUB(free                                   ,0xff825624) //112
NHSTUB(kbd_p1_f                               ,0xff82dd84) //109
NHSTUB(kbd_p1_f_cont                          ,0xff82dd90) //109
NHSTUB(kbd_p2_f                               ,0xff82d4f0) //109
NHSTUB(kbd_read_keys                          ,0xff82dd34) //109
NHSTUB(kbd_read_keys_r2                       ,0xff86a7e8) //109
NHSTUB(lseek                                  ,0xff827d30) //120
NHSTUB(malloc                                 ,0xff8255cc) //112
NHSTUB(memcmp                                 ,0xff8253a4) //120
NHSTUB(memcpy                                 ,0xff8b7bb0) //120
NHSTUB(memset                                 ,0xffa3f03c) //120
NHSTUB(mkdir                                  ,0xff827fb0) //121
NHSTUB(mktime_ext                             ,0xff8b7438) //  1
NHSTUB(open                                   ,0xff823c64) //109
NHSTUB(OpenFastDir                            ,0xffae51bc) //115
NHSTUB(closedir                               ,0xffae516c) //121
NHSTUB(get_fstype                             ,0xff831914) //122
NHSTUB(qsort                                  ,0xffb688e0) //  6
NHSTUB(rand                                   ,0xffa3f00c) //121
NHSTUB(realloc                                ,0xffa3f0b8) //115
NHSTUB(reboot_fw_update                       ,0xffb04fd4) //106
NHSTUB(set_control_event                      ,0xff8a3188) //111
NHSTUB(srand                                  ,0xffa3f000) //122
NHSTUB(stat                                   ,0xff827d78) //109
NHSTUB(strcat                                 ,0xff83923c) //  1
NHSTUB(strchr                                 ,0xff8392c4) //  1
NHSTUB(strcmp                                 ,0xff8254a0) //120
NHSTUB(strcpy                                 ,0xff82538c) //120
NHSTUB(strftime                               ,0xff8b7484) //113
NHSTUB(strlen                                 ,0xff8254e4) //120
NHSTUB(strncmp                                ,0xff839278) //  1
NHSTUB(strncpy                                ,0xff8286a8) //  1
NHSTUB(strrchr                                ,0xff8b7cfc) //  1
NHSTUB(strtol                                 ,0xff839228) //101
NHSTUB(strtolx                                ,0xff83902c) //109
   DEF(task_CaptSeq                           ,0xff89065c) //120
   DEF(task_DvlpSeqTask                       ,0xff9b40d4) //120
   DEF(task_ExpDrv                            ,0xff8e0be4) //120
   DEF(task_FileWrite                         ,0xffae0b18) //120
   DEF(task_InitFileModules                   ,0xff85b9dc) //120
   DEF(task_MovieRecord                       ,0xff9a7e94) //120
   DEF(task_PhySw                             ,0xff82d854) //120
   DEF(hook_CreateTask                        ,0xff824a2c) //105
NHSTUB(time                                   ,0xff82ab0c) //119
NHSTUB(vsprintf                               ,0xff828668) //115
NHSTUB(EngDrvRead                             ,0xff82de94) //102
NHSTUB(PTM_GetCurrentItem                     ,0xff8a5520) //105
NHSTUB(DisableISDriveError                    ,0xffb01c20) //120
NHSTUB(CancelHPTimer                          ,0xff89d6ec) //119
NHSTUB(SetHPTimerAfterNow                     ,0xff89d5e4) //119
NHSTUB(SS_MFOn                                ,0xff9b012c) //120
NHSTUB(SS_MFOff                               ,0xff9b013c) //120
NHSTUB(GetAdChValue                           ,0xff866cd8) //120
NHSTUB(get_ptp_buf_size                       ,0xff928b90) //122
NHSTUB(get_ptp_file_buf                       ,0xffa97288) //121
NHSTUB(SetVideoOutType                        ,0xffba1370) //109
NHSTUB(GetVideoOutType                        ,0xffba12bc) //120
