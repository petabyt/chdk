// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R54 (DRYOS version 2.3, release #0054+p3)
//   Firmware Ver GM1.00B   // Found @ 0xff89af38, "GM1.00B" @ 0xff89af45
//   Firmware build timestamp: Nov 21 2013 21:23:30
//   Canon IXUS 157

// Values for makefile.inc
//   DIGIC = 41# DIGIC 4+
//   PLATFORMOSVER = 54
//   PLATFORMID = 12938# (0x328a) Found @ 0xffff0040
//   MAXRAMADDR = 0x07ffffff
//   MEMISOSTART = 0x0018eb58
//   KEYSYS = d4f# Found @ 0xff812740
//   NEED_ENCODED_DISKBOOT = 12# Found @ 0xff812750
//   ARAM_HEAP_START = 0x60e000# Found @ 0xff9a1014
//   ARAM_HEAP_SIZE  = 0x22000# Found @ 0xff9a0fd4

// Detected address ranges:
// ROM      0xff810000 - 0xffffffff (8323072 bytes)
// RAM code 0x006b1000 - 0x006c1400 copied from 0xffcc8f04 (  66560 bytes)
// RAM data 0x00001900 - 0x0000f720 copied from 0xffcbb0e4 (  56864 bytes)

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
NHSTUB(DeleteFile_Fut                         ,0xff826afc) //  1 90%
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff987d9c) //  3 95%
// ERROR: MakeDirectory_Fut is not found.                  //--- ---    *** != 0xff82760c
// ERROR: RefreshPhysicalScreen is not found.              //--- ---    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ffac5eec -> ffc84e9c
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x000104b0) // Found @0xff82bda8
DEF(physw_run                               ,0x00001c94) // Found @0xff82b900
DEF(physw_sleep_delay                       ,0x00001c9c) // Found @0xff82b900
DEF(levent_table                            ,0xffbe5b48) // Found @0xffbe5b48
DEF(FlashParamsTable                        ,0xffc85130) // Found @0xffc85130
DEF(movie_status                            ,0x00007028) // Found @0xff991ad4
DEF(video_compression_rate                  ,0x00006fdc) // Found @0xff992760
DEF(full_screen_refresh                     ,0x00007aec) // Found @0xff9b4668
DEF(canon_menu_active                       ,0x00003b10) // Found @0xff8a324c
DEF(canon_shoot_menu_active                 ,0x00009151) // Found @0xffa0f510
DEF(playrec_mode                            ,0x0000360c) // Found @0xff891950
DEF(zoom_status                             ,0x00005c7c) // Found @0xff931e40
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 2 int value(s), the first is the zoom focus length.
// there are 101 entries in the table - set NUM_FL to 101
//DEF(focus_len_table                         ,0xffffae14) // Found @0xffffae14,          stubs_min = 0xffffae14 (0xffffae14)
DEF(zoom_busy                               ,0x00006d98) // Found @0xff98a488
DEF(focus_busy                              ,0x00006c44) // Found @0xff9867b0
// Palette colour tables  found @ 0xffbe98e0
// Camera appears to have only 1 RAW buffer @ 0x43717e20 (Found @0xffb55ee0)
DEF(fileio_semaphore                        ,0x00001d0c) // Found @0xff82e160
DEF(exmem_alloc_table                       ,0x0001180c) // Found @0xff832b7c
DEF(exmem_types_table                       ,0xffcbb588) // Found @0x00001da4
DEF_CONST(exmem_type_count                  ,0x0000001b)
DEF(imager_active                           ,0x00002028) // Found @0xff8494d8 (0x2024 + 4)
DEF_CONST(uiprop_count                      ,0x0000009d) // Found @0xff9aa86c
DEF(cameracon_state                         ,0x00002308) // Found @0xff85546c

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x406f1000; }             // Found @0xff86306c
//void *vid_get_viewport_fb()      { return (void*)0x40846b80; }             // Found @0xffb544c8
DEF(viewport_fb_d                           ,0x00003284) // Found 0x3230 (@0xff8804c0) + 0x54 (@0xff8804f8)
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x3230+0x54)); } // Found @0xff8804c0 & 0xff8804f8
DEF(jpeg_count_str                          ,0x000e1320) // Found @0xff9faec8
//char *camera_jpeg_count_str()    { return (char*)0x000e1320; }             // Found @0xff9faec8
//int get_flash_params_count(void) { return 0xa6; }                          // Found @0xff9ab2f0

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x02000000 // Found @0xffb97998, levent 0x20a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x10000000 // Found @0xffb979a8, levent 0x202
//#define USB_IDX             2
//#define BATTCOVER_FLAG      0x04000000 // Found @0xffb979a0, levent 0x205
//#define BATTCOVER_IDX       2
//#define ANALOG_AV_FLAG      0x00000080 // Found @0xffb97938, levent 0x200 (non-inverted logic)
//#define ANALOG_AV_IDX       2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 2, KEY_SET             ,0x00000001 }, // Found @0xffb97900, levent 0x0a
//    { 2, KEY_UP              ,0x00000002 }, // Found @0xffb97908, levent 0x06
//    { 2, KEY_RIGHT           ,0x00000004 }, // Found @0xffb97910, levent 0x09
//    { 2, KEY_DOWN            ,0x00000008 }, // Found @0xffb97918, levent 0x07
//    { 2, KEY_LEFT            ,0x00000010 }, // Found @0xffb97920, levent 0x08
//    { 2, KEY_SHOOT_FULL      ,0x00000060 }, // Found @0xffb97930, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000040 }, // Found @0xffb97930, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00000020 }, // Found @0xffb97928, levent 0x00
//    { 2, KEY_POWER           ,0x00000100 }, // Found @0xffb97940, levent 0x100
//    { 2, KEY_PLAYBACK        ,0x00000200 }, // Found @0xffb97948, levent 0x101
//    { 2, KEY_HELP            ,0x00000800 }, // Found @0xffb97950, levent 0x0d
//    { 2, KEY_MENU            ,0x00001000 }, // Found @0xffb97958, levent 0x0e
//    { 2, KEY_VIDEO           ,0x00002000 }, // Found @0xffb97960, levent 0x02
//    { 2, KEY_ZOOM_OUT        ,0x00004000 }, // Found @0xffb97968, levent 0x04
//    { 2, KEY_ZOOM_IN         ,0x00008000 }, // Found @0xffb97970, levent 0x03
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#define CAM_RAW_ROWPIX    5248 // Found @0xff9640d4
//#define CAM_RAW_ROWS      3920 // Found @0xff9640dc
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff825e30
//#define CAM_DATE_FOLDER_NAMING 0x080 // Found @0xffa946a4 (pass as 3rd param to GetImageFolder)
//#define PARAM_CAMERA_NAME 3 // Found @0xffc841ec
//#define CAM_3ARG_DebugAssert 1

// Below goes in 'filewrite.c' or 'platform_camera.h':
//#define MAX_CHUNKS_FOR_FWT 7 // Found @0xffaa18f4

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
DEF(ctypes, 0xffb95178)

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
// pointer to TCB area: 0x19c4, found @ 0xffcca480

// LED table init @ 0xff93fbf4
// LED #1: 0xc022d200 (#98 in GPIO table), offset 0x98
// LED #2: 0xc022d1fc (#97 in GPIO table), offset 0x8
// GPIO table @ 0xffb973b0

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NHSTUB(AllocateUncacheableMemory              ,0xff825dec) //112
NHSTUB(Close                                  ,0xff827170) //120
NHSTUB(CreateBinarySemaphore                  ,0x006b784c) //115
NHSTUB(CreateTask                             ,0x006b562c) //120
NHSTUB(DebugAssert                            ,0x006b59c0) //107
NHSTUB(DeleteDirectory_Fut                    ,0xff826b70) //116
NHSTUB(DeleteSemaphore                        ,0x006b7930) //120
NHSTUB(DoAELock                               ,0xff83186c) //120
NHSTUB(DoAFLock                               ,0xff831530) //120
NHSTUB(EnterToCompensationEVF                 ,0xff8317d0) //104
NHSTUB(ExecuteEventProcedure                  ,0xff8335fc) //104
NHSTUB(ExitFromCompensationEVF                ,0xff831818) //104
NHSTUB(ExitTask                               ,0x006b595c) //120
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff841650) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff8417c4) //104
NHSTUB(Fclose_Fut                             ,0xff826c08) //120
NHSTUB(Feof_Fut                               ,0xff826df4) //  1
NHSTUB(Fflush_Fut                             ,0xff826e30) //  1
NHSTUB(Fgets_Fut                              ,0xff826d5c) //  6
NHSTUB(Fopen_Fut                              ,0xff826bc8) //120
NHSTUB(Fread_Fut                              ,0xff826cb4) //120
NHSTUB(FreeUncacheableMemory                  ,0xff825e28) //112
NHSTUB(Fseek_Fut                              ,0xff826da8) //120
NHSTUB(Fwrite_Fut                             ,0xff826d08) //120
NHSTUB(GetBatteryTemperature                  ,0xff86be00) //102
NHSTUB(GetCCDTemperature                      ,0xff86bd88) //102
NHSTUB(GetCurrentAvValue                      ,0xff884508) //120
NHSTUB(GetCurrentShutterSpeed                 ,0xff8c2c28) //120
NHSTUB(GetDrive_ClusterSize                   ,0xff82f7f4) //122
NHSTUB(GetDrive_FreeClusters                  ,0xff830040) //119
NHSTUB(GetDrive_TotalClusters                 ,0xff830014) //122
NHSTUB(GetFocusLensSubjectDistance            ,0xff9879b8) //102
NHSTUB(GetImageFolder                         ,0xff96b920) //122
NHSTUB(GetKbdState                            ,0xff86861c) //109
NHSTUB(GetMemInfo                             ,0xff8235cc) //115
NHSTUB(GetOpticalTemperature                  ,0xff86be78) //120
NHSTUB(GetParameterData                       ,0xff9ab2ac) //101
NHSTUB(GetPropertyCase                        ,0xff89c7d0) //101
NHSTUB(GetSystemTime                          ,0xffac3ae8) //120
NHSTUB(GetVRAMHPixelsSize                     ,0xff84df28) //120
NHSTUB(GetVRAMVPixelsSize                     ,0xff84df34) //120
NHSTUB(GetZoomLensCurrentPoint                ,0xff98a918) //120
NHSTUB(GetZoomLensCurrentPosition             ,0xffab2f54) //102
NHSTUB(GiveSemaphore                          ,0x006b7acc) //120
NHSTUB(IsStrobeChargeCompleted                ,0xff8f1828) //102
NHSTUB(LEDDrive                               ,0xff993518) //120
NHSTUB(LocalTime                              ,0x006b9a18) //115
NHSTUB(LockMainPower                          ,0xff89f124) //120
NHSTUB(MakeSDCardBootable                     ,0xff8304ec) //105
NHSTUB(MoveFocusLensToDistance                ,0xffb57ecc) //102
NHSTUB(MoveIrisWithAv                         ,0xffabe078) //120
NHSTUB(MoveZoomLensWithPoint                  ,0xffabe988) //120
NHSTUB(MoveOpticalZoomAt                      ,0xff830f88) //109
NHSTUB(Open                                   ,0xff8270a8) //120
NHSTUB(PB2Rec                                 ,0xff8572f4) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff9945e0) //102
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff9945b0) //102
NHSTUB(PT_PlaySound                           ,0xff8ac43c) //122
NHSTUB(PostLogicalEventForNotPowerType        ,0xff89e670) //120
NHSTUB(PostLogicalEventToUI                   ,0xff89e6bc) //120
NHSTUB(PutInNdFilter                          ,0xffabe740) //102
NHSTUB(PutOutNdFilter                         ,0xffabe764) //102
NHSTUB(Read                                   ,0xff824088) //120
NHSTUB(ReadFastDir                            ,0xffaa2df8) //115
NHSTUB(Rec2PB                                 ,0xff855a94) //104
NHSTUB(RenameFile_Fut                         ,0xff826a68) //116
NHSTUB(Restart                                ,0xff83669c) //122
NHSTUB(ScreenLock                             ,0xff8a2b80) //117
NHSTUB(ScreenUnlock                           ,0xff8a2bdc) //117
NHSTUB(SetAE_ShutterSpeed                     ,0xffb53358) //102
NHSTUB(SetAutoShutdownTime                    ,0xff89f198) //120
NHSTUB(SetCurrentCaptureModeType              ,0xff8a92e4) //120
NHSTUB(SetDate                                ,0xffb5517c) //120
NHSTUB(SetFileAttributes                      ,0xff827574) //  6
NHSTUB(SetFileTimeStamp                       ,0xff8274fc) //  6
NHSTUB(SetLogicalEventActive                  ,0xff89ed18) //120
NHSTUB(SetParameterData                       ,0xff9ab210) //101
NHSTUB(SetPropertyCase                        ,0xff89c62c) //101
NHSTUB(SetScriptMode                          ,0xff89ed6c) //120
NHSTUB(SleepTask                              ,0x006b8d88) //120
NHSTUB(TakeSemaphore                          ,0x006b79f4) //120
NHSTUB(TurnOffBackLight                       ,0xff8abce0) //104
NHSTUB(TurnOnBackLight                        ,0xff8abcc8) //104
NHSTUB(TurnOnDisplay                          ,0xff86344c) //120
NHSTUB(TurnOffDisplay                         ,0xff86345c) //120
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff9c7ee0) //120
NHSTUB(UnlockAE                               ,0xff831890) //120
NHSTUB(UnlockAF                               ,0xff831560) //120
NHSTUB(UnlockMainPower                        ,0xff89f07c) //120
NHSTUB(VbattGet                               ,0xff82ac10) //120
NHSTUB(Write                                  ,0xff8271c4) //120
NHSTUB(WriteSDCard                            ,0xff87e2b8) //108
NHSTUB(_log                                   ,0x006bd900) //111
NHSTUB(_log10                                 ,0x006bde40) //112
NHSTUB(_pow                                   ,0x006bdfb8) //121
NHSTUB(_sqrt                                  ,0x006bfbdc) //  6
NHSTUB(add_ptp_handler                        ,0xffa662b8) //121
NHSTUB(apex2us                                ,0xffa1c208) //121
NHSTUB(close                                  ,0xff823ee4) //109
NHSTUB(err_init_task                          ,0xff824978) //111
NHSTUB(exmem_alloc                            ,0xff833188) //101
NHSTUB(exmem_ualloc                           ,0xff832ff4) //101
NHSTUB(exmem_ufree                            ,0xff833134) //101
NHSTUB(free                                   ,0xff825220) //112
NHSTUB(get_nd_value                           ,0xffab07f4) //123
NHSTUB(get_current_nd_value                   ,0xffab0794) //122
NHSTUB(get_current_deltasv                    ,0xff8c3938) //122
NHSTUB(GetCurrentDriveBaseSvValue             ,0xff8c9648) //120
NHSTUB(kbd_p1_f                               ,0xff82bdf8) //109
NHSTUB(kbd_p1_f_cont                          ,0xff82be04) //109
NHSTUB(kbd_p2_f                               ,0xff82b598) //109
NHSTUB(kbd_read_keys                          ,0xff82bda8) //109
NHSTUB(kbd_read_keys_r2                       ,0xff868108) //109
NHSTUB(lseek                                  ,0xff82738c) //120
NHSTUB(malloc                                 ,0xff8251c8) //112
NHSTUB(memcmp                                 ,0xff824fa0) //120
NHSTUB(memcpy                                 ,0xff8b00cc) //120
NHSTUB(memset                                 ,0xffa16478) //120
NHSTUB(mkdir                                  ,0xff82760c) //121
NHSTUB(mktime_ext                             ,0xff8af954) //  1
NHSTUB(open                                   ,0xff823e34) //109
NHSTUB(OpenFastDir                            ,0xffaa2ca4) //115
NHSTUB(closedir                               ,0xffaa2c54) //121
NHSTUB(get_fstype                             ,0xff82f76c) //122
NHSTUB(qsort                                  ,0xffb18704) //  6
NHSTUB(rand                                   ,0xffa16448) //121
NHSTUB(realloc                                ,0xffa164f4) //115
NHSTUB(reboot_fw_update                       ,0xffac319c) //106
NHSTUB(set_control_event                      ,0xff89e9d8) //111
NHSTUB(srand                                  ,0xffa1643c) //122
NHSTUB(stat                                   ,0xff8273d4) //109
NHSTUB(strcat                                 ,0xff83702c) //  1
NHSTUB(strchr                                 ,0xff8370b4) //  1
NHSTUB(strcmp                                 ,0xff82509c) //120
NHSTUB(strcpy                                 ,0xff824f88) //120
NHSTUB(strftime                               ,0xff8af9a0) //113
NHSTUB(strlen                                 ,0xff8250e0) //120
NHSTUB(strncmp                                ,0xff837068) //  1
NHSTUB(strncpy                                ,0xff827d04) //  1
NHSTUB(strrchr                                ,0xff8b0218) //  1
NHSTUB(strtol                                 ,0xff837018) //101
NHSTUB(strtolx                                ,0xff836e1c) //109
   DEF(task_CaptSeq                           ,0xff88c07c) //120
   DEF(task_DvlpSeqTask                       ,0xff997e58) //120
   DEF(task_ExpDrv                            ,0xff8d918c) //120
   DEF(task_FileWrite                         ,0xffaa1894) //120
   DEF(task_InitFileModules                   ,0xff857bd0) //120
   DEF(task_MovieRecord                       ,0xff99282c) //120
   DEF(task_PhySw                             ,0xff82b8fc) //120
   DEF(hook_CreateTask                        ,0x006b562c) //105
NHSTUB(time                                   ,0x006b927c) //119
NHSTUB(vsprintf                               ,0xff827cc4) //115
NHSTUB(EngDrvRead                             ,0xff82bf04) //102
NHSTUB(PTM_GetCurrentItem                     ,0xff8a0d74) //105
NHSTUB(DisableISDriveError                    ,0xffabf494) //120
NHSTUB(CancelHPTimer                          ,0xff898fe0) //119
NHSTUB(SetHPTimerAfterNow                     ,0xff898ed8) //119
NHSTUB(SS_MFOn                                ,0xff994674) //120
NHSTUB(SS_MFOff                               ,0xff994684) //120
NHSTUB(GetAdChValue                           ,0xff8645f8) //120
NHSTUB(get_ptp_buf_size                       ,0xff91d94c) //122
NHSTUB(get_ptp_file_buf                       ,0xffa67f04) //121
NHSTUB(SetVideoOutType                        ,0xffb53ba4) //109
NHSTUB(GetVideoOutType                        ,0xffb53af0) //120
