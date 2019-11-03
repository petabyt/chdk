// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R54 (DRYOS version 2.3, release #0054+p3)
//   Firmware Ver GM1.00C   // Found @ 0xff89ae34, "GM1.00C" @ 0xff89ae41
//   Firmware build timestamp: Nov 21 2013 21:14:08
//   Canon IXUS 150

// Values for makefile.inc
//   PLATFORMOSVER = 54
//   PLATFORMID = 12935 (0x3287) // Found @ 0xffff0040
//   MAXRAMADDR = 0x07ffffff
//   MEMISOSTART = 0x00182980
//   KEYSYS = d4f                // Found @ 0xff812744
//   NEED_ENCODED_DISKBOOT = 12   // Found @ 0xff812754
//   ARAM_HEAP_START = 0x60e000  // Found @ 0xff9a1c9c
//   ARAM_HEAP_SIZE  = 0x22000   // Found @ 0xff9a1c5c

// Detected address ranges:
// ROM      0xff810000 - 0xffffffff (8323072 bytes)
// RAM code 0x006b1000 - 0x006c1400 copied from 0xffcd7394 (  66560 bytes)
// RAM data 0x00001900 - 0x0000f764 copied from 0xffcc9530 (  56932 bytes)

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
NHSTUB(DeleteFile_Fut                         ,0xff826afc) //  1 90%
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff9881b0) //  3 95%
// ERROR: MakeDirectory_Fut is not found.                  //--- ---    *** != 0xff82760c
// ERROR: RefreshPhysicalScreen is not found.              //--- ---    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ffac6aa4 -> ffc871ac
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x000104f0) // Found @0xff82bda8
DEF(physw_run                               ,0x00001c94) // Found @0xff82b900
DEF(physw_sleep_delay                       ,0x00001c9c) // Found @0xff82b900
DEF(levent_table                            ,0xffbe83dc) // Found @0xffbe83dc
DEF(FlashParamsTable                        ,0xffc87440) // Found @0xffc87440
DEF(movie_status                            ,0x00007070) // Found @0xff992758
//DEF(video_compression_rate                  ,0x00007024) // Found @0xff9933e4, ** != ** stubs_min = 0x000070a0 (0x70a0)
DEF(full_screen_refresh                     ,0x00007b34) // Found @0xff9b52ec
DEF(canon_menu_active                       ,0x00003b10) // Found @0xff8a3150
DEF(canon_shoot_menu_active                 ,0x00009199) // Found @0xffa100e0
DEF(playrec_mode                            ,0x00003608) // Found @0xff89184c
DEF(zoom_status                             ,0x00005c64) // Found @0xff9322fc
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 2 int value(s), the first is the zoom focus length.
// there are 101 entries in the table - set NUM_FL to 101
DEF(focus_len_table                         ,0xffffae14) // Found @0xffffae14
DEF(zoom_busy                               ,0x00006d78) // Found @0xff98a8b0
DEF(focus_busy                              ,0x00006c24) // Found @0xff986c84
// Palette colour tables  found @ 0xffbec15c
// Camera appears to have only 1 RAW buffer @ 0x42f95130 (Found @0xffb57724)
DEF(fileio_semaphore                        ,0x00001d0c) // Found @0xff82e160
DEF(exmem_alloc_table                       ,0x0001184c) // Found @0xff832b7c
DEF(exmem_types_table                       ,0xffcc99d4) // Found @0x00001da4
DEF_CONST(exmem_type_count                  ,0x0000001b)
DEF(imager_active                           ,0x00002028) // Found @0xff849518 (0x2024 + 4)
DEF_CONST(uiprop_count                      ,0x0000009d) // Found @0xff9ab4e8

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x406f1000; }             // Found @0xff862fc0
//void *vid_get_viewport_fb()      { return (void*)0x40846b80; }             // Found @0xffb55d0c
DEF(viewport_fb_d                           ,0x0000327c) // Found 0x3228 (@0xff8803a8) + 0x54 (@0xff8803e0)
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x3228+0x54)); } // Found @0xff8803a8 & 0xff8803e0
DEF(jpeg_count_str                          ,0x000d5168) // Found @0xff9fbabc
//char *camera_jpeg_count_str()    { return (char*)0x000d5168; }             // Found @0xff9fbabc
//int get_flash_params_count(void) { return 0xa6; }                          // Found @0xff9abf6c

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x02000000 // Found @0xffb994fc, levent 0x20a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x10000000 // Found @0xffb9950c, levent 0x202
//#define USB_IDX             2
//#define BATTCOVER_FLAG      0x04000000 // Found @0xffb99504, levent 0x205
//#define BATTCOVER_IDX       2
//#define ANALOG_AV_FLAG      0x00000080 // Found @0xffb9949c, levent 0x200 (non-inverted logic)
//#define ANALOG_AV_IDX       2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 2, KEY_SET             ,0x00000001 }, // Found @0xffb99464, levent 0x0a
//    { 2, KEY_UP              ,0x00000002 }, // Found @0xffb9946c, levent 0x06
//    { 2, KEY_RIGHT           ,0x00000004 }, // Found @0xffb99474, levent 0x09
//    { 2, KEY_DOWN            ,0x00000008 }, // Found @0xffb9947c, levent 0x07
//    { 2, KEY_LEFT            ,0x00000010 }, // Found @0xffb99484, levent 0x08
//    { 2, KEY_SHOOT_FULL      ,0x00000060 }, // Found @0xffb99494, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000040 }, // Found @0xffb99494, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00000020 }, // Found @0xffb9948c, levent 0x00
//    { 2, KEY_POWER           ,0x00000100 }, // Found @0xffb994a4, levent 0x100
//    { 2, KEY_PLAYBACK        ,0x00000200 }, // Found @0xffb994ac, levent 0x101
//    { 2, KEY_HELP            ,0x00000800 }, // Found @0xffb994b4, levent 0x0d
//    { 2, KEY_MENU            ,0x00001000 }, // Found @0xffb994bc, levent 0x0e
//    { 2, KEY_VIDEO           ,0x00002000 }, // Found @0xffb994c4, levent 0x02
//    { 2, KEY_ZOOM_OUT        ,0x00004000 }, // Found @0xffb994cc, levent 0x04
//    { 2, KEY_ZOOM_IN         ,0x00008000 }, // Found @0xffb994d4, levent 0x03
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#define CAM_RAW_ROWPIX    4704 // Found @0xff96462c
//#define CAM_RAW_ROWS      3504 // Found @0xff964638
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff825e30
//#define CAM_DATE_FOLDER_NAMING 0x080 // Found @0xffa95368 (pass as 3rd param to GetImageFolder)
//#define PARAM_CAMERA_NAME 3 // Found @0xffc86500
//#define CAM_3ARG_DebugAssert 1

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
DEF(ctypes, 0xffb96a18)

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

// ISR flag: 0x1944, pointer to current task's control block: 0x1940
// pointer to TCB area: 0x19c4, found @ 0xffcd8910

// LED table init @ 0xff9400e0
// LED #1: 0xc022d200 (#98 in GPIO table), offset 0x98
// LED #2: 0xc022d1fc (#97 in GPIO table), offset 0x8
// GPIO table @ 0xffb98f14

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NHSTUB(AllocateUncacheableMemory              ,0xff825dec) //112
NHSTUB(Close                                  ,0xff827170) //120
NHSTUB(CreateBinarySemaphore                  ,0x006b784c) //115
NHSTUB(CreateTask                             ,0x006b562c) //120
NHSTUB(DebugAssert                            ,0x006b59c0) //107
NHSTUB(DeleteDirectory_Fut                    ,0xff826b70) //116
NHSTUB(DoAELock                               ,0xff83186c) //120
NHSTUB(DoAFLock                               ,0xff831530) //120
NHSTUB(EnterToCompensationEVF                 ,0xff8317d0) //104
NHSTUB(ExecuteEventProcedure                  ,0xff8335fc) //104
NHSTUB(ExitFromCompensationEVF                ,0xff831818) //104
NHSTUB(ExitTask                               ,0x006b595c) //120
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff84161c) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff841790) //104
NHSTUB(Fclose_Fut                             ,0xff826c08) //120
NHSTUB(Feof_Fut                               ,0xff826df4) //  1
NHSTUB(Fflush_Fut                             ,0xff826e30) //  1
NHSTUB(Fgets_Fut                              ,0xff826d5c) //  6
NHSTUB(Fopen_Fut                              ,0xff826bc8) //120
NHSTUB(Fread_Fut                              ,0xff826cb4) //120
NHSTUB(FreeUncacheableMemory                  ,0xff825e28) //112
NHSTUB(Fseek_Fut                              ,0xff826da8) //120
NHSTUB(Fwrite_Fut                             ,0xff826d08) //120
NHSTUB(GetBatteryTemperature                  ,0xff86bd40) //102
NHSTUB(GetCCDTemperature                      ,0xff86bcc8) //102
NHSTUB(GetCurrentAvValue                      ,0xff8843f0) //120
NHSTUB(GetCurrentShutterSpeed                 ,0xff8c2b1c) //120
NHSTUB(GetDrive_ClusterSize                   ,0xff82f7f4) //122
NHSTUB(GetDrive_FreeClusters                  ,0xff830040) //119
NHSTUB(GetDrive_TotalClusters                 ,0xff830014) //122
NHSTUB(GetFocusLensSubjectDistance            ,0xff987dcc) //102
NHSTUB(GetImageFolder                         ,0xff96be7c) //122
NHSTUB(GetKbdState                            ,0xff86855c) //109
NHSTUB(GetMemInfo                             ,0xff8235cc) //115
NHSTUB(GetOpticalTemperature                  ,0xff86bdb8) //120
NHSTUB(GetParameterData                       ,0xff9abf28) //101
NHSTUB(GetPropertyCase                        ,0xff89c6c8) //101
NHSTUB(GetSystemTime                          ,0xffac46ac) //120
NHSTUB(GetVRAMHPixelsSize                     ,0xff84df90) //120
NHSTUB(GetVRAMVPixelsSize                     ,0xff84df9c) //120
NHSTUB(GetZoomLensCurrentPoint                ,0xff98ad40) //120
NHSTUB(GetZoomLensCurrentPosition             ,0xffab3a74) //102
NHSTUB(GiveSemaphore                          ,0x006b7acc) //120
NHSTUB(IsStrobeChargeCompleted                ,0xff8f19f8) //102
NHSTUB(LEDDrive                               ,0xff9941a0) //120
NHSTUB(LocalTime                              ,0x006b9a18) //115
NHSTUB(LockMainPower                          ,0xff89f01c) //120
NHSTUB(MakeSDCardBootable                     ,0xff8304ec) //105
NHSTUB(MoveFocusLensToDistance                ,0xffb59710) //102
NHSTUB(MoveIrisWithAv                         ,0xffabec44) //120
NHSTUB(MoveZoomLensWithPoint                  ,0xffabf554) //120
NHSTUB(MoveOpticalZoomAt                      ,0xff830f88) //109
NHSTUB(Open                                   ,0xff8270a8) //120
NHSTUB(PB2Rec                                 ,0xff85735c) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff995268) //102
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff995238) //102
NHSTUB(PT_PlaySound                           ,0xff8ac330) //122
NHSTUB(PostLogicalEventForNotPowerType        ,0xff89e568) //120
NHSTUB(PostLogicalEventToUI                   ,0xff89e5b4) //120
NHSTUB(PutInNdFilter                          ,0xffabf30c) //102
NHSTUB(PutOutNdFilter                         ,0xffabf330) //102
NHSTUB(Read                                   ,0xff824088) //120
NHSTUB(ReadFastDir                            ,0xffaa3ab8) //115
NHSTUB(Rec2PB                                 ,0xff855afc) //104
NHSTUB(RenameFile_Fut                         ,0xff826a68) //116
NHSTUB(Restart                                ,0xff836668) //122
NHSTUB(ScreenLock                             ,0xff8a2a78) //117
NHSTUB(ScreenUnlock                           ,0xff8a2ad4) //117
NHSTUB(SetAE_ShutterSpeed                     ,0xffb54b9c) //102
NHSTUB(SetAutoShutdownTime                    ,0xff89f090) //120
NHSTUB(SetCurrentCaptureModeType              ,0xff8a91e4) //120
NHSTUB(SetFileAttributes                      ,0xff827574) //  6
NHSTUB(SetFileTimeStamp                       ,0xff8274fc) //  6
NHSTUB(SetLogicalEventActive                  ,0xff89ec10) //120
NHSTUB(SetParameterData                       ,0xff9abe8c) //101
NHSTUB(SetPropertyCase                        ,0xff89c528) //101
NHSTUB(SetScriptMode                          ,0xff89ec64) //120
NHSTUB(SleepTask                              ,0x006b8d88) //120
NHSTUB(TakeSemaphore                          ,0x006b79f4) //120
NHSTUB(TurnOffBackLight                       ,0xff8abbd4) //104
NHSTUB(TurnOnBackLight                        ,0xff8abbbc) //104
NHSTUB(TurnOnDisplay                          ,0xff8633a0) //120
NHSTUB(TurnOffDisplay                         ,0xff8633b0) //120
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff9c8b44) //120
NHSTUB(UnlockAE                               ,0xff831890) //120
NHSTUB(UnlockAF                               ,0xff831560) //120
NHSTUB(UnlockMainPower                        ,0xff89ef74) //120
NHSTUB(VbattGet                               ,0xff82ac10) //120
NHSTUB(Write                                  ,0xff8271c4) //120
NHSTUB(WriteSDCard                            ,0xff87e1a0) //108
NHSTUB(_log                                   ,0x006bd900) //111
NHSTUB(_log10                                 ,0x006bde40) //112
NHSTUB(_pow                                   ,0x006bdfb8) //121
NHSTUB(_sqrt                                  ,0x006bfbdc) //  6
NHSTUB(add_ptp_handler                        ,0xffa67208) //121
NHSTUB(apex2us                                ,0xffa1cdcc) //121
NHSTUB(close                                  ,0xff823ee4) //109
NHSTUB(err_init_task                          ,0xff824978) //111
NHSTUB(exmem_alloc                            ,0xff833188) //101
NHSTUB(exmem_free                             ,0xff8331f0) //101
NHSTUB(free                                   ,0xff825220) //112
NHSTUB(get_nd_value                           ,0xffab1314) //123
NHSTUB(get_current_nd_value                   ,0xffab12b4) //122
NHSTUB(kbd_p1_f                               ,0xff82bdf8) //109
NHSTUB(kbd_p1_f_cont                          ,0xff82be04) //109
NHSTUB(kbd_p2_f                               ,0xff82b598) //109
NHSTUB(kbd_read_keys                          ,0xff82bda8) //109
NHSTUB(kbd_read_keys_r2                       ,0xff868048) //109
NHSTUB(lseek                                  ,0xff82738c) //120
NHSTUB(malloc                                 ,0xff8251c8) //112
NHSTUB(memcmp                                 ,0xff824fa0) //120
NHSTUB(memcpy                                 ,0xff8affc0) //120
NHSTUB(memset                                 ,0xffa1703c) //120
NHSTUB(mkdir                                  ,0xff82760c) //121
NHSTUB(mktime_ext                             ,0xff8af848) //  1
NHSTUB(open                                   ,0xff823e34) //109
NHSTUB(OpenFastDir                            ,0xffaa3964) //115
NHSTUB(closedir                               ,0xffaa3914) //121
NHSTUB(get_fstype                             ,0xff82f76c) //122
NHSTUB(qsort                                  ,0xffb19268) //  6
NHSTUB(rand                                   ,0xffa1700c) //121
NHSTUB(realloc                                ,0xffa170b8) //115
NHSTUB(reboot_fw_update                       ,0xffac3d60) //106
NHSTUB(set_control_event                      ,0xff89e8d0) //111
NHSTUB(srand                                  ,0xffa17000) //122
NHSTUB(stat                                   ,0xff8273d4) //109
NHSTUB(strcat                                 ,0xff836ff8) //  1
NHSTUB(strchr                                 ,0xff837080) //  1
NHSTUB(strcmp                                 ,0xff82509c) //120
NHSTUB(strcpy                                 ,0xff824f88) //120
NHSTUB(strftime                               ,0xff8af894) //113
NHSTUB(strlen                                 ,0xff8250e0) //120
NHSTUB(strncmp                                ,0xff837034) //  1
NHSTUB(strncpy                                ,0xff827d04) //  1
NHSTUB(strrchr                                ,0xff8b010c) //  1
NHSTUB(strtol                                 ,0xff836fe4) //101
NHSTUB(strtolx                                ,0xff836de8) //109
   DEF(task_CaptSeq                           ,0xff88bf78) //120
   DEF(task_DvlpSeqTask                       ,0xff998ae0) //120
   DEF(task_ExpDrv                            ,0xff8d94a0) //120
   DEF(task_FileWrite                         ,0xffaa2554) //120
   DEF(task_InitFileModules                   ,0xff857c38) //120
   DEF(task_MovieRecord                       ,0xff9934b0) //120
   DEF(task_PhySw                             ,0xff82b8fc) //120
   DEF(hook_CreateTask                        ,0x006b562c) //105
NHSTUB(time                                   ,0x006b927c) //119
NHSTUB(vsprintf                               ,0xff827cc4) //115
NHSTUB(EngDrvRead                             ,0xff82bf04) //102
NHSTUB(PTM_GetCurrentItem                     ,0xff8a0c6c) //105
NHSTUB(DisableISDriveError                    ,0xffac0058) //120
NHSTUB(CancelHPTimer                          ,0xff898edc) //119
NHSTUB(SetHPTimerAfterNow                     ,0xff898dd4) //119
NHSTUB(SS_MFOn                                ,0xff9952fc) //120
NHSTUB(SS_MFOff                               ,0xff99530c) //120
NHSTUB(GetAdChValue                           ,0xff864544) //120
NHSTUB(get_ptp_buf_size                       ,0xff91dd7c) //122
NHSTUB(get_ptp_file_buf                       ,0xffa68e54) //121
