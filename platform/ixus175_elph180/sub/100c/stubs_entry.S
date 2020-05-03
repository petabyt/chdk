// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R58 (DRYOS version 2.3, release #0058+p7)
//   Firmware Ver GM1.00C   // Found @ 0xff89dbac, "GM1.00C" @ 0xff89dbb9
//   Firmware build timestamp: May 12 2016 19:57:43
//   Canon IXUS 175

// Values for makefile.inc
//   DIGIC = 41# DIGIC 4+
//   PLATFORMOSVER = 58
//   PLATFORMID = 12993# (0x32c1) Found @ 0xffff0270
//   MAXRAMADDR = 0x07ffffff
//   MEMISOSTART = 0x001899d8
//   KEYSYS = d4i# Found @ 0xff812968
//   NEED_ENCODED_DISKBOOT = 16# Found @ 0xff812978
//   ARAM_HEAP_START = 0x60e000# Found @ 0xff9b8f58
//   ARAM_HEAP_SIZE  = 0x22000# Found @ 0xff9b8f18

// Detected address ranges:
// ROM      0xff810000 - 0xffffffff (8323072 bytes)
// RAM code 0x006b1000 - 0x006c1734 copied from 0xffd2b31c (  67380 bytes)
// RAM data 0x00001900 - 0x0000f3cc copied from 0xffd1d850 (  56012 bytes)

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
NHSTUB(DeleteFile_Fut                         ,0xff826a90) //  1 90%
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff9a13a0) //  3 90%
// ERROR: MakeDirectory_Fut is not found.                  //--- ---    *** != 0xff8277a4
// ERROR: RefreshPhysicalScreen is not found.              //--- ---    *** != 0x00000000
// ERROR: TurnOffBackLight is not found.                   //--- ---    *** != 0x00000000
// ERROR: TurnOnBackLight is not found.                    //--- ---    *** != 0x00000000
//NHSTUB(TurnOnDisplay                        ,0xff866c7c) //120        *** != 0xff859ef0
//NHSTUB(TurnOffDisplay                       ,0xff866c8c) //120        *** != 0xff85a8b4
// ERROR: close is not found.                              //--- ---    *** != 0xff823d60
// ERROR: open is not found.                               //--- ---    *** != 0xff823cb0

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ffaed6b0 -> ffce5408
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00010198) // Found @0xff82c154
DEF(physw_run                               ,0x00001c18) // Found @0xff82bc8c
DEF(physw_sleep_delay                       ,0x00001c20) // Found @0xff82bc8c
DEF(levent_table                            ,0xffc245ec) // Found @0xffc245ec
DEF(FlashParamsTable                        ,0xffce5784) // Found @0xffce5784
DEF(movie_status                            ,0x00007294) // Found @0xff9a8948
DEF(video_compression_rate                  ,0x00007244) // Found @0xff9a9610
DEF(full_screen_refresh                     ,0x00007dcc) // Found @0xff9cd828
DEF(canon_menu_active                       ,0x00003d18) // Found @0xff8a623c
DEF(canon_shoot_menu_active                 ,0x00009481) // Found @0xffa29424
DEF(playrec_mode                            ,0x000037f0) // Found @0xff8940fc
DEF(zoom_status                             ,0x00005fb0) // Found @0xff948048
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 2 int value(s), the first is the zoom focus length.
// there are 101 entries in the table - set NUM_FL to 101
DEF(focus_len_table                         ,0xffffcb7c) // Found @0xffffcb7c
DEF(zoom_busy                               ,0x00007150) // Found @0xff9a3b4c
DEF(focus_busy                              ,0x0000701c) // Found @0xff99fe5c
// Palette colour tables  found @ 0xffc28568
// Camera appears to have only 1 RAW buffer @ 0x43727660 (Found @0xffb95894)
DEF(fileio_semaphore                        ,0x00001c98) // Found @0xff82e58c
DEF(exmem_alloc_table                       ,0x000114fc) // Found @0xff833108
DEF(exmem_types_table                       ,0xffd1dc78) // Found @0x00001d28
DEF_CONST(exmem_type_count                  ,0x0000001f)
DEF(imager_active                           ,0x00001fb8) // Found @0xff8493c4 (0x1fb4 + 4)
DEF_CONST(uiprop_count                      ,0x000000d7) // Found @0xff9c32e4

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x40711000; }             // Found @0xff86689c
//void *vid_get_viewport_fb()      { return (void*)0x40866b80; }             // Found @0xffb93e14
DEF(viewport_fb_d                           ,0x00003534) // Found 0x34d8 (@0xff8853f8) + 0x5c (@0xff885430)
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x34d8+0x5c)); } // Found @0xff8853f8 & 0xff885430
DEF(jpeg_count_str                          ,0x000d77d4) // Found @0xffa13d38
//char *camera_jpeg_count_str()    { return (char*)0x000d77d4; }             // Found @0xffa13d38
//int get_flash_params_count(void) { return 0xf1; }                          // Found @0xff9c3e58

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x02000000 // Found @0xffbe3a2c, levent 0x30a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x10000000 // Found @0xffbe3a3c, levent 0x302
//#define USB_IDX             2
//#define BATTCOVER_FLAG      0x04000000 // Found @0xffbe3a34, levent 0x305
//#define BATTCOVER_IDX       2
//#define ANALOG_AV_FLAG      0x00002000 // Found @0xffbe39dc, levent 0x300 (non-inverted logic)
//#define ANALOG_AV_IDX       0

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_VIDEO           ,0x00000002 }, // Found @0xffbe399c, levent 0x02
//    { 0, KEY_POWER           ,0x00000020 }, // Found @0xffbe39a4, levent 0x100
//    { 0, KEY_PLAYBACK        ,0x00000040 }, // Found @0xffbe39ac, levent 0x101
//    { 0, KEY_SET             ,0x00000100 }, // Found @0xffbe39b4, levent 0x0a
//    { 0, KEY_UP              ,0x00000200 }, // Found @0xffbe39bc, levent 0x06
//    { 0, KEY_RIGHT           ,0x00000400 }, // Found @0xffbe39c4, levent 0x09
//    { 0, KEY_DOWN            ,0x00000800 }, // Found @0xffbe39cc, levent 0x07
//    { 0, KEY_LEFT            ,0x00001000 }, // Found @0xffbe39d4, levent 0x08
//    { 0, KEY_HELP            ,0x00004000 }, // Found @0xffbe39e4, levent 0x0d
//    { 2, KEY_SHOOT_FULL      ,0x00000003 }, // Found @0xffbe39fc, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000002 }, // Found @0xffbe39fc, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00000001 }, // Found @0xffbe39f4, levent 0x00
//    { 2, KEY_ZOOM_OUT        ,0x00000010 }, // Found @0xffbe3a04, levent 0x04
//    { 2, KEY_ZOOM_IN         ,0x00000020 }, // Found @0xffbe3a0c, levent 0x03
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#define CAM_RAW_ROWPIX    5248 // Found @0xff97c21c
//#define CAM_RAW_ROWS      3920 // Found @0xff97c224
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff825d74
//#define CAM_DATE_FOLDER_NAMING 0x080 // Found @0xffaba86c (pass as 3rd param to GetImageFolder)
//#define PARAM_CAMERA_NAME 3 // Found @0xffce41a8
//#define CAM_3ARG_DebugAssert 1

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
DEF(ctypes, 0xffbe0e34)

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
// EXMEM_FLASHAIR       16
// EXMEM_LENS_FIRMUP    17
// EXMEM_LENS_COMPENSATION 18
// EXMEM_FILESTORE      19
// EXMEM_MOVIE_REC      20
// EXMEM_MOVIE_PLY      21
// EXMEM_WIFI_RESIZE    22
// EXMEM_PCEVF          23
// EXMEM_WIDE           24
// EXMEM_NARROW         25
// EXMEM_AUTO_GIS_MODE  26
// EXMEM_NP_GIS_MODE    27
// EXMEM_TRIPODHDR_MODE 28
// EXMEM_HSHQ_MODE      29
// EXMEM_CRAW_REC       30

// ISR flag: 0x194c, pointer to current task's control block: 0x1948
// pointer to TCB area: 0x19cc, found @ 0xffd2c8d4

// LED table init @ 0xff956444
// LED #1: 0xc022d200 (#98 in GPIO table), offset 0x98
// LED #2: 0xc022d1fc (#97 in GPIO table), offset 0x8
// GPIO table @ 0xffbe342c

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NHSTUB(AllocateUncacheableMemory              ,0xff825d30) //112
NHSTUB(Close                                  ,0xff827210) //120
NHSTUB(CreateBinarySemaphore                  ,0x006b792c) //115
NHSTUB(CreateTask                             ,0x006b5714) //120
NHSTUB(DebugAssert                            ,0x006b5ac8) //107
NHSTUB(DeleteDirectory_Fut                    ,0xff826b04) //116
NHSTUB(DoAELock                               ,0xff831dbc) //120
NHSTUB(DoAFLock                               ,0xff831a70) //120
NHSTUB(EnterToCompensationEVF                 ,0xff831ce4) //104
NHSTUB(ExecuteEventProcedure                  ,0xff833c28) //104
NHSTUB(ExitFromCompensationEVF                ,0xff831d38) //104
NHSTUB(ExitTask                               ,0x006b5a68) //120
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff842648) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff842880) //104
NHSTUB(Fclose_Fut                             ,0xff826b9c) //120
NHSTUB(Feof_Fut                               ,0xff826d88) //  1
NHSTUB(Fflush_Fut                             ,0xff826dc4) //  1
NHSTUB(Fgets_Fut                              ,0xff826cf0) //  6
NHSTUB(Fopen_Fut                              ,0xff826b5c) //120
NHSTUB(Fread_Fut                              ,0xff826c48) //120
NHSTUB(FreeUncacheableMemory                  ,0xff825d6c) //112
NHSTUB(Fseek_Fut                              ,0xff826d3c) //120
NHSTUB(Fwrite_Fut                             ,0xff826c9c) //120
NHSTUB(GetBatteryTemperature                  ,0xff86f7dc) //102
NHSTUB(GetCCDTemperature                      ,0xff86f764) //102
NHSTUB(GetCurrentAvValue                      ,0xff889584) //120
NHSTUB(GetCurrentShutterSpeed                 ,0xff919e94) //120
NHSTUB(GetUsableMaxAv                         ,0xff97ca24) //120
NHSTUB(GetUsableMinAv                         ,0xff97ca08) //120
NHSTUB(GetDrive_ClusterSize                   ,0xff82fc50) //122
NHSTUB(GetDrive_FreeClusters                  ,0xff830400) //119
NHSTUB(GetDrive_TotalClusters                 ,0xff8303d4) //122
NHSTUB(GetFocusLensSubjectDistance            ,0xff9a0fbc) //102
NHSTUB(GetImageFolder                         ,0xff9844c8) //122
NHSTUB(GetKbdState                            ,0xff86bf14) //109
NHSTUB(GetMemInfo                             ,0xff823448) //115
NHSTUB(GetOpticalTemperature                  ,0xff86f854) //120
NHSTUB(GetParameterData                       ,0xff9c3e14) //101
NHSTUB(GetPropertyCase                        ,0xff89f494) //101
NHSTUB(GetSystemTime                          ,0xffaeb124) //120
NHSTUB(GetVRAMHPixelsSize                     ,0xff84e164) //120
NHSTUB(GetVRAMVPixelsSize                     ,0xff84e170) //120
NHSTUB(GetZoomLensCurrentPoint                ,0xff9a3fd8) //120
NHSTUB(GetZoomLensCurrentPosition             ,0xffadb804) //102
NHSTUB(GiveSemaphore                          ,0x006b7bb0) //120
NHSTUB(IsStrobeChargeCompleted                ,0xff8ce3e8) //102
NHSTUB(LEDDrive                               ,0xff9aa520) //120
NHSTUB(LocalTime                              ,0x006b9ad8) //115
NHSTUB(LockMainPower                          ,0xff8a1f40) //120
NHSTUB(MakeSDCardBootable                     ,0xff830908) //105
NHSTUB(MoveFocusLensToDistance                ,0xffb978c8) //102
NHSTUB(MoveIrisWithAv                         ,0xffae5d6c) //120
NHSTUB(MoveZoomLensWithPoint                  ,0xffae66c0) //120
NHSTUB(MoveOpticalZoomAt                      ,0xff8313e4) //109
NHSTUB(Open                                   ,0xff8271ac) //120
NHSTUB(PB2Rec                                 ,0xff858cf8) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff9ab690) //102
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff9ab660) //102
NHSTUB(PT_PlaySound                           ,0xff8b0020) //122
NHSTUB(PostLogicalEventForNotPowerType        ,0xff8a13e4) //120
NHSTUB(PostLogicalEventToUI                   ,0xff8a143c) //120
NHSTUB(PutInNdFilter                          ,0xffae6480) //102
NHSTUB(PutOutNdFilter                         ,0xffae64a4) //102
NHSTUB(Read                                   ,0xff823f04) //120
NHSTUB(ReadFastDir                            ,0xffaca21c) //115
NHSTUB(Rec2PB                                 ,0xff857594) //104
NHSTUB(RenameFile_Fut                         ,0xff8269fc) //116
NHSTUB(Restart                                ,0xff836cbc) //122
NHSTUB(ScreenLock                             ,0xff8a5b54) //117
NHSTUB(ScreenUnlock                           ,0xff8a5ba8) //117
NHSTUB(SetAE_ShutterSpeed                     ,0xffb92c34) //102
NHSTUB(SetAutoShutdownTime                    ,0xff8a1fb4) //120
NHSTUB(SetCurrentCaptureModeType              ,0xff8acb78) //120
NHSTUB(SetFileAttributes                      ,0xff82770c) //  6
NHSTUB(SetFileTimeStamp                       ,0xff827694) //  6
NHSTUB(SetLogicalEventActive                  ,0xff8a1aac) //120
NHSTUB(SetParameterData                       ,0xff9c3d78) //101
NHSTUB(SetPropertyCase                        ,0xff89f2b4) //101
NHSTUB(SetScriptMode                          ,0xff8a1b00) //120
NHSTUB(SleepTask                              ,0x006b8f0c) //120
NHSTUB(TakeSemaphore                          ,0x006b7ad4) //120
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff9e1c40) //120
NHSTUB(UnlockAE                               ,0xff831de0) //120
NHSTUB(UnlockAF                               ,0xff831aa0) //120
NHSTUB(UnlockMainPower                        ,0xff8a1e98) //120
NHSTUB(VbattGet                               ,0xff82af1c) //120
NHSTUB(Write                                  ,0xff827158) //120
NHSTUB(WriteSDCard                            ,0xff882ed8) //108
NHSTUB(_log                                   ,0x006bdb80) //111
NHSTUB(_log10                                 ,0x006be0c0) //112
NHSTUB(_pow                                   ,0x006be238) //121
NHSTUB(_sqrt                                  ,0x006bfed8) //  6
NHSTUB(add_ptp_handler                        ,0xffa7f0e0) //121
NHSTUB(apex2us                                ,0xffa6a7f4) //121
NHSTUB(err_init_task                          ,0xff8247d0) //111
NHSTUB(exmem_alloc                            ,0xff83380c) //101
NHSTUB(exmem_ualloc                           ,0xff833674) //101
NHSTUB(exmem_ufree                            ,0xff8337b8) //101
NHSTUB(free                                   ,0xff82507c) //112
NHSTUB(get_nd_value                           ,0xffad8eec) //123
NHSTUB(get_current_nd_value                   ,0xffad8e8c) //122
NHSTUB(kbd_p1_f                               ,0xff82c1a4) //109
NHSTUB(kbd_p1_f_cont                          ,0xff82c1b0) //109
NHSTUB(kbd_p2_f                               ,0xff82b8b8) //109
NHSTUB(kbd_read_keys                          ,0xff82c154) //109
NHSTUB(kbd_read_keys_r2                       ,0xff86b8c8) //109
NHSTUB(lseek                                  ,0xff827524) //120
NHSTUB(malloc                                 ,0xff825024) //112
NHSTUB(memcmp                                 ,0xff824dfc) //120
NHSTUB(memcpy                                 ,0xff8b4218) //120
NHSTUB(memset                                 ,0xffa2cc80) //120
NHSTUB(mkdir                                  ,0xff8277a4) //121
NHSTUB(mktime_ext                             ,0xff8b3aa0) //  1
NHSTUB(OpenFastDir                            ,0xffaca0c8) //115
NHSTUB(closedir                               ,0xffaca078) //121
NHSTUB(get_fstype                             ,0xff82fbc8) //122
NHSTUB(qsort                                  ,0xffb4f8a0) //  6
NHSTUB(rand                                   ,0xffa2cc50) //121
NHSTUB(realloc                                ,0xffa2ccfc) //115
NHSTUB(reboot_fw_update                       ,0xffaea7e0) //106
NHSTUB(set_control_event                      ,0xff8a176c) //111
NHSTUB(srand                                  ,0xffa2cc44) //122
NHSTUB(stat                                   ,0xff82756c) //109
NHSTUB(strcat                                 ,0xff837614) //  1
NHSTUB(strchr                                 ,0xff83769c) //  1
NHSTUB(strcmp                                 ,0xff824ef8) //120
NHSTUB(strcpy                                 ,0xff824de4) //120
NHSTUB(strftime                               ,0xff8b3aec) //113
NHSTUB(strlen                                 ,0xff824f3c) //120
NHSTUB(strncmp                                ,0xff837650) //  1
NHSTUB(strncpy                                ,0xff827e84) //  1
NHSTUB(strrchr                                ,0xff8b4364) //  1
NHSTUB(strtol                                 ,0xff837600) //101
NHSTUB(strtolx                                ,0xff837404) //109
   DEF(task_CaptSeq                           ,0xff88e214) //120
   DEF(task_DvlpSeqTask                       ,0xff9afa8c) //120
   DEF(task_ExpDrv                            ,0xff8e79a4) //120
   DEF(task_FileWrite                         ,0xffac8bb8) //120
   DEF(task_InitFileModules                   ,0xff8598a8) //120
   DEF(task_MovieRecord                       ,0xff9a96dc) //120
   DEF(task_PhySw                             ,0xff82bc88) //120
   DEF(hook_CreateTask                        ,0x006b5714) //105
NHSTUB(time                                   ,0x006b92ac) //119
NHSTUB(vsprintf                               ,0xff827e44) //115
NHSTUB(EngDrvRead                             ,0xff82c2b4) //102
NHSTUB(PTM_GetCurrentItem                     ,0xff8a3bbc) //105
NHSTUB(CancelHPTimer                          ,0xff89bbdc) //119
NHSTUB(SetHPTimerAfterNow                     ,0xff89bad4) //119
NHSTUB(SS_MFOn                                ,0xff9ab724) //120
NHSTUB(SS_MFOff                               ,0xff9ab734) //120
NHSTUB(GetAdChValue                           ,0xff867eac) //120
NHSTUB(get_ptp_buf_size                       ,0xff9330f4) //122
NHSTUB(get_ptp_file_buf                       ,0xffa80d58) //121
NHSTUB(SetVideoOutType                        ,0xffb93458) //109
