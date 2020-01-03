// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R59 (DRYOS version 2.3, release #0059+p3)
//   Firmware Ver GM1.00A   // Found @ 0xff8a37d8, "GM1.00A" @ 0xff8a37e5
//   Firmware build timestamp: Nov 11 2016 10:26:52
//   Canon IXUS 185 

// Values for makefile.inc
//   PLATFORMOSVER = 59
//   PLATFORMID = 13012 (0x32d4) // Found @ 0xffff0270
//   MAXRAMADDR = 0x07ffffff
//   MEMISOSTART = 0x0018aa24
//   KEYSYS = d4j                // Found @ 0xff812968
//   NEED_ENCODED_DISKBOOT = 17   // Found @ 0xff812978

// Detected address ranges:
// ROM      0xff810000 - 0xffffffff (8323072 bytes)
// RAM code 0x006b1000 - 0x006bea08 copied from 0xffd401cc (  55816 bytes)
// RAM data 0x00001900 - 0x0000f3c0 copied from 0xffd3270c (  56000 bytes)

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
NHSTUB(DeleteFile_Fut                         ,0xff826cec) //  1 90%
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff9abb7c) //  3 90%
// ERROR: MakeDirectory_Fut is not found.                  //--- ---    *** != 0xff827984
// ERROR: RefreshPhysicalScreen is not found.              //--- ---    *** != 0x00000000
// ERROR: TurnOffBackLight is not found.                   //--- ---    *** != 0x00000000
// ERROR: TurnOnBackLight is not found.                    //--- ---    *** != 0x00000000
// ERROR: close is not found.                              //--- ---    *** != 0xff823e5c
// ERROR: exmem_alloc is not found.                        //--- ---    *** != 0xff8345b8
// ERROR: open is not found.                               //--- ---    *** != 0xff823dac

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ffafe02c -> ffcf8ffc
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x0001015c) // Found @0xff82ce70
DEF(physw_run                               ,0x00001be4) // Found @0xff82c998
DEF(physw_sleep_delay                       ,0x00001bec) // Found @0xff82c998
DEF(levent_table                            ,0xffc378ec) // Found @0xffc378ec
DEF(FlashParamsTable                        ,0xffcf93c0) // Found @0xffcf93c0
DEF(movie_status                            ,0x00007014) // Found @0xff9b2f68
DEF(video_compression_rate                  ,0x00006fc4) // Found @0xff9b3c3c
DEF(full_screen_refresh                     ,0x00007b98) // Found @0xff9d7384
DEF(canon_menu_active                       ,0x00003e18) // Found @0xff8abfc0
DEF(canon_shoot_menu_active                 ,0x0000921d) // Found @0xffa34b60
//DEF(playrec_mode                            ,0x000038c0) // Found @0xff8998bc,          stubs_min = 0x000038c0 (0x000038C0)
DEF(zoom_status                             ,0x0000a3a0) // Found @0xff951b3c
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 2 int value(s), the first is the zoom focus length.
// there are 101 entries in the table - set NUM_FL to 101
DEF(focus_len_table                         ,0xffffcb7c) // Found @0xffffcb7c
DEF(zoom_busy                               ,0x00006ed0) // Found @0xff9ae368
DEF(focus_busy                              ,0x00006d9c) // Found @0xff9aa5e0
// Palette colour tables  found @ 0xffc3bcb8
// Camera appears to have only 1 RAW buffer @ 0x43727660 (Found @0xffba697c)
DEF(fileio_semaphore                        ,0x00001c64) // Found @0xff82f2a4
DEF(exmem_alloc_table                       ,0x00011724) // Found @0xff833eb4
DEF(exmem_types_table                       ,0xffd32b04) // Found @0x00001cf8
DEF_CONST(exmem_type_count                  ,0x00000015)
DEF(imager_active                           ,0x00001fc0) // Found @0xff84cb88 (0x1fbc + 4)
DEF_CONST(uiprop_count                      ,0x000000e9) // Found @0xff9cd4d8

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x40711000; }             // Found @0xff86ac90
//void *vid_get_viewport_fb()      { return (void*)0x40866b80; }             // Found @0xffba4e00
DEF(viewport_fb_d                           ,0x000035ec) // Found 0x3590 (@0xff8896f8) + 0x5c (@0xff889730)
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x3590+0x5c)); } // Found @0xff8896f8 & 0xff889730
DEF(jpeg_count_str                          ,0x000d7400) // Found @0xffa1e798
//char *camera_jpeg_count_str()    { return (char*)0x000d7400; }             // Found @0xffa1e798

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x02000000 // Found @0xffbf5a44, levent 0x30a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x10000000 // Found @0xffbf5a54, levent 0x302
//#define USB_IDX             2
//#define BATTCOVER_FLAG      0x04000000 // Found @0xffbf5a4c, levent 0x305
//#define BATTCOVER_IDX       2
//#define ANALOG_AV_FLAG      0x00002000 // Found @0xffbf59f4, levent 0x300 (non-inverted logic)
//#define ANALOG_AV_IDX       0

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_VIDEO           ,0x00000002 }, // Found @0xffbf59b4, levent 0x02
//    { 0, KEY_POWER           ,0x00000020 }, // Found @0xffbf59bc, levent 0x100
//    { 0, KEY_PLAYBACK        ,0x00000040 }, // Found @0xffbf59c4, levent 0x101
//    { 0, KEY_SET             ,0x00000100 }, // Found @0xffbf59cc, levent 0x0a
//    { 0, KEY_UP              ,0x00000200 }, // Found @0xffbf59d4, levent 0x06
//    { 0, KEY_RIGHT           ,0x00000400 }, // Found @0xffbf59dc, levent 0x09
//    { 0, KEY_DOWN            ,0x00000800 }, // Found @0xffbf59e4, levent 0x07
//    { 0, KEY_LEFT            ,0x00001000 }, // Found @0xffbf59ec, levent 0x08
//    { 0, KEY_HELP            ,0x00004000 }, // Found @0xffbf59fc, levent 0x0d
//    { 2, KEY_SHOOT_FULL      ,0x00000003 }, // Found @0xffbf5a14, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000002 }, // Found @0xffbf5a14, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00000001 }, // Found @0xffbf5a0c, levent 0x00
//    { 2, KEY_ZOOM_OUT        ,0x00000010 }, // Found @0xffbf5a1c, levent 0x04
//    { 2, KEY_ZOOM_IN         ,0x00000020 }, // Found @0xffbf5a24, levent 0x03
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#define CAM_DRYOS_2_3_R59 1 // Defined for cameras with DryOS version R59 or higher
//#define CAM_RAW_ROWPIX    5248 // Found @0xff985a80
//#define CAM_RAW_ROWS      3920 // Found @0xff985a88
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff828008
//#define CAM_DATE_FOLDER_NAMING 0x080 // Found @0xffacb464 (pass as 3rd param to GetImageFolder)
//#define PARAM_CAMERA_NAME 3 // Found @0xffcf7b48
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
DEF(ctypes, 0xffbf2d5c)

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
// pointer to TCB area: 0x19cc, found @ 0xffd4178c

// LED table init @ 0xff95fd3c
// LED #1: 0xc022d200 (#98 in GPIO table), offset 0x98
// LED #2: 0xc022d1fc (#97 in GPIO table), offset 0x8
// GPIO table @ 0xffbf5444

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NHSTUB(AllocateUncacheableMemory              ,0xff827fc4) //112
NHSTUB(Close                                  ,0xff827410) //120
NHSTUB(CreateBinarySemaphore                  ,0xff8280a8) //115
NHSTUB(CreateTask                             ,0xff82513c) //120
NHSTUB(DebugAssert                            ,0xff8254fc) //107
NHSTUB(DeleteDirectory_Fut                    ,0xff826d60) //116
NHSTUB(DoAELock                               ,0xff832b4c) //120
NHSTUB(DoAFLock                               ,0xff832784) //120
NHSTUB(EnterToCompensationEVF                 ,0xff832a74) //104
NHSTUB(ExecuteEventProcedure                  ,0xff83497c) //104
NHSTUB(ExitFromCompensationEVF                ,0xff832ac8) //104
NHSTUB(ExitTask                               ,0xff8254ac) //120
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff844c08) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff844f88) //104
NHSTUB(Fclose_Fut                             ,0xff826df8) //120
NHSTUB(Feof_Fut                               ,0xff826fe4) //  1
NHSTUB(Fflush_Fut                             ,0xff827020) //  1
NHSTUB(Fgets_Fut                              ,0xff826f4c) //  6
NHSTUB(Fopen_Fut                              ,0xff826db8) //120
NHSTUB(Fread_Fut                              ,0xff826ea4) //120
NHSTUB(FreeUncacheableMemory                  ,0xff828000) //112
NHSTUB(Fseek_Fut                              ,0xff826f98) //120
NHSTUB(Fwrite_Fut                             ,0xff826ef8) //120
NHSTUB(GetBatteryTemperature                  ,0xff873b84) //102
NHSTUB(GetCCDTemperature                      ,0xff873b10) //102
NHSTUB(GetCurrentAvValue                      ,0xff88d4ec) //120
NHSTUB(GetCurrentShutterSpeed                 ,0xff92005c) //120
NHSTUB(GetUsableMaxAv                         ,0xff986288) //120
NHSTUB(GetUsableMinAv                         ,0xff98626c) //120
NHSTUB(GetDrive_ClusterSize                   ,0xff830908) //122
NHSTUB(GetDrive_FreeClusters                  ,0xff8310b0) //119
NHSTUB(GetDrive_TotalClusters                 ,0xff831084) //122
NHSTUB(GetFocusLensSubjectDistance            ,0xff9ab798) //102
NHSTUB(GetImageFolder                         ,0xff98e1c8) //122
NHSTUB(GetKbdState                            ,0xff8702dc) //109
NHSTUB(GetMemInfo                             ,0xff823544) //115
NHSTUB(GetOpticalTemperature                  ,0xff873bf8) //120
NHSTUB(GetParameterData                       ,0xff9ce028) //101
NHSTUB(GetPropertyCase                        ,0xff8a50e0) //101
NHSTUB(GetSystemTime                          ,0xffafba38) //120
NHSTUB(GetVRAMHPixelsSize                     ,0xff8519cc) //120
NHSTUB(GetVRAMVPixelsSize                     ,0xff8519d8) //120
NHSTUB(GetZoomLensCurrentPoint                ,0xff9ae7fc) //120
NHSTUB(GetZoomLensCurrentPosition             ,0xffaec308) //102
NHSTUB(GiveSemaphore                          ,0xff828334) //120
NHSTUB(IsStrobeChargeCompleted                ,0xff8cee74) //102
NHSTUB(LEDDrive                               ,0xff9b4b44) //120
NHSTUB(LocalTime                              ,0xff8bb618) //115
NHSTUB(LockMainPower                          ,0xff8a7bc0) //120
NHSTUB(MakeSDCardBootable                     ,0xff831610) //105
NHSTUB(MoveFocusLensToDistance                ,0xffba89e0) //102
NHSTUB(MoveIrisWithAv                         ,0xffaf6b6c) //120
NHSTUB(MoveZoomLensWithPoint                  ,0xffaf6d20) //120
NHSTUB(MoveOpticalZoomAt                      ,0xff8320e4) //109
NHSTUB(Open                                   ,0xff8273ac) //120
NHSTUB(PB2Rec                                 ,0xff85ca40) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff9b5cb8) //102
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff9b5c88) //102
NHSTUB(PT_PlaySound                           ,0xff8b6310) //122
NHSTUB(PostLogicalEventForNotPowerType        ,0xff8a7054) //120
NHSTUB(PostLogicalEventToUI                   ,0xff8a70ac) //120
NHSTUB(PutInNdFilter                          ,0xffaf69d8) //102
NHSTUB(PutOutNdFilter                         ,0xffaf69fc) //102
NHSTUB(Read                                   ,0xff824000) //120
NHSTUB(ReadFastDir                            ,0xffadae60) //115
NHSTUB(Rec2PB                                 ,0xff85af64) //104
NHSTUB(RenameFile_Fut                         ,0xff826c58) //116
NHSTUB(Restart                                ,0xff837a00) //122
NHSTUB(ScreenLock                             ,0xff8ab86c) //117
NHSTUB(ScreenUnlock                           ,0xff8ab8c0) //117
NHSTUB(SetAE_ShutterSpeed                     ,0xffba3c20) //102
NHSTUB(SetAutoShutdownTime                    ,0xff8a7c34) //120
NHSTUB(SetCurrentCaptureModeType              ,0xff8b2a30) //120
NHSTUB(SetFileAttributes                      ,0xff8278ec) //  6
NHSTUB(SetFileTimeStamp                       ,0xff827874) //  6
NHSTUB(SetLogicalEventActive                  ,0xff8a7720) //120
NHSTUB(SetParameterData                       ,0xff9cdf88) //101
NHSTUB(SetPropertyCase                        ,0xff8a4f0c) //101
NHSTUB(SetScriptMode                          ,0xff8a7774) //120
NHSTUB(SleepTask                              ,0xff8390d4) //120
NHSTUB(TakeSemaphore                          ,0xff828250) //120
NHSTUB(TurnOnDisplay                          ,0xff86b070) //120
NHSTUB(TurnOffDisplay                         ,0xff86b080) //120
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff9eb678) //120
NHSTUB(UnlockAE                               ,0xff832bdc) //120
NHSTUB(UnlockAF                               ,0xff8327b4) //120
NHSTUB(UnlockMainPower                        ,0xff8a7b18) //120
NHSTUB(VbattGet                               ,0xff82bc3c) //120
NHSTUB(Write                                  ,0xff827b7c) //120
NHSTUB(WriteSDCard                            ,0xff8871d8) //108
NHSTUB(_log                                   ,0x006bb4b8) //111
NHSTUB(_log10                                 ,0x006bb9f8) //112
NHSTUB(_pow                                   ,0x006bbb70) //121
NHSTUB(_sqrt                                  ,0x006bd810) //  6
NHSTUB(add_ptp_handler                        ,0xffa8ff18) //121
NHSTUB(apex2us                                ,0xffa7b7d4) //121
NHSTUB(err_init_task                          ,0xff8248cc) //111
NHSTUB(free                                   ,0xff82583c) //112
NHSTUB(get_nd_value                           ,0xffae9ce4) //123
NHSTUB(get_current_nd_value                   ,0xffae9c84) //122
NHSTUB(kbd_p1_f                               ,0xff82cec0) //109
NHSTUB(kbd_p1_f_cont                          ,0xff82cecc) //109
NHSTUB(kbd_p2_f                               ,0xff82c5c4) //109
NHSTUB(kbd_read_keys                          ,0xff82ce70) //109
NHSTUB(kbd_read_keys_r2                       ,0xff86fc8c) //109
NHSTUB(lseek                                  ,0xff827720) //120
NHSTUB(malloc                                 ,0xff8257e4) //112
NHSTUB(memcmp                                 ,0xff8255bc) //120
NHSTUB(memcpy                                 ,0xff8bc01c) //120
NHSTUB(memset                                 ,0xffa38968) //120
NHSTUB(mkdir                                  ,0xff827984) //121
NHSTUB(mktime_ext                             ,0xff8bb8a4) //  1
NHSTUB(OpenFastDir                            ,0xffadad0c) //115
NHSTUB(closedir                               ,0xffadacbc) //121
NHSTUB(get_fstype                             ,0xff830880) //122
NHSTUB(qsort                                  ,0xffb5ecf8) //  6
NHSTUB(rand                                   ,0xffa38938) //121
NHSTUB(realloc                                ,0xffa389e4) //115
NHSTUB(reboot_fw_update                       ,0xffafa570) //106
NHSTUB(set_control_event                      ,0xff8a73e0) //111
NHSTUB(srand                                  ,0xffa3892c) //122
NHSTUB(stat                                   ,0xff827768) //109
NHSTUB(strcat                                 ,0xff839cec) //  1
NHSTUB(strchr                                 ,0xff839d74) //  1
NHSTUB(strcmp                                 ,0xff8256b8) //120
NHSTUB(strcpy                                 ,0xff8255a4) //120
NHSTUB(strftime                               ,0xff8bb8f0) //113
NHSTUB(strlen                                 ,0xff8256fc) //120
NHSTUB(strncmp                                ,0xff839d28) //  1
NHSTUB(strncpy                                ,0xff828c30) //  1
NHSTUB(strrchr                                ,0xff8bc168) //  1
NHSTUB(strtol                                 ,0xff839cd8) //101
NHSTUB(strtolx                                ,0xff839adc) //109
   DEF(task_CaptSeq                           ,0xff892484) //120
   DEF(task_DvlpSeqTask                       ,0xff9b9ca8) //120
   DEF(task_ExpDrv                            ,0xff8ea6dc) //120
   DEF(task_FileWrite                         ,0xffad9824) //120
   DEF(task_InitFileModules                   ,0xff85d4ec) //120
   DEF(task_MovieRecord                       ,0xff9b3d08) //120
   DEF(task_PhySw                             ,0xff82c994) //120
   DEF(hook_CreateTask                        ,0xff82513c) //105
NHSTUB(time                                   ,0xff839480) //119
NHSTUB(vsprintf                               ,0xff828bf0) //115
NHSTUB(EngDrvRead                             ,0xff82cfd0) //102
NHSTUB(PTM_GetCurrentItem                     ,0xff8a9818) //105
NHSTUB(CancelHPTimer                          ,0xff8a17a8) //119
NHSTUB(SetHPTimerAfterNow                     ,0xff8a16a0) //119
NHSTUB(SS_MFOn                                ,0xff9b5d4c) //120
NHSTUB(SS_MFOff                               ,0xff9b5d5c) //120
NHSTUB(GetAdChValue                           ,0xff86c25c) //120
NHSTUB(get_ptp_buf_size                       ,0xff93933c) //122
NHSTUB(get_ptp_file_buf                       ,0xffa91b94) //121
