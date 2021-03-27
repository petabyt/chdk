// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R58 (DRYOS version 2.3, release #0058+p7)
//   Firmware Ver GM1.00B   // Found @ 0xff0aec80, "GM1.00B" @ 0xff0aec8d
//   Firmware build timestamp: May 17 2016 11:38:20
//   Canon PowerShot SX620 HS

// Values for makefile.inc
//   DIGIC = 41# DIGIC 4+
//   PLATFORMOSVER = 58
//   PLATFORMID = 12995# (0x32c3) Found @ 0xfffe0270
//   MAXRAMADDR = 0x1fffffff
//   MEMISOSTART = 0x0032a990
//   KEYSYS = d4i# Found @ 0xff01459c
//   NEED_ENCODED_DISKBOOT = 16# Found @ 0xff0145ac
//   ARAM_HEAP_START = 0x60e000# Found @ 0xff23274c
//   ARAM_HEAP_SIZE  = 0x22000# Found @ 0xff23270c

// Detected address ranges:
// ROM      0xff010000 - 0xffffffff (16711680 bytes)
// RAM code 0x006b1000 - 0x006e3f28 copied from 0xff912534 ( 208680 bytes)
// RAM data 0x00001900 - 0x000194a8 copied from 0xff8fa98c (  97192 bytes)

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
NHSTUB(DeleteFile_Fut                         ,0xff026a98) //  1 90%
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff20ddc4) //  3 90%
// ERROR: MakeDirectory_Fut is not found.                  //--- ---    *** != 0xff0277ac
// ERROR: RefreshPhysicalScreen is not found.              //--- ---    *** != 0x00000000
// ERROR: TurnOffBackLight is not found.                   //--- ---    *** != 0x00000000
// ERROR: TurnOnBackLight is not found.                    //--- ---    *** != 0x00000000
// ERROR: close is not found.                              //--- ---    *** != 0xff023d68
// ERROR: open is not found.                               //--- ---    *** != 0xff023cb8

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff3e7664 -> ff82b360
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x0001a278) // Found @0xff02c584
DEF(physw_run                               ,0x00001c18) // Found @0xff02c068
DEF(physw_sleep_delay                       ,0x00001c20) // Found @0xff02c068
DEF(levent_table                            ,0xff6e7864) // Found @0xff6e7864
DEF(FlashParamsTable                        ,0xff82b6e4) // Found @0xff82b6e4
DEF(movie_status                            ,0x0000a48c) // Found @0xff2197a8
DEF(video_compression_rate                  ,0x0000a43c) // Found @0xff21a228
DEF(full_screen_refresh                     ,0x0000b380) // Found @0xff245c90
DEF(canon_menu_active                       ,0x00004204) // Found @0xff0b954c
DEF(canon_shoot_menu_active                 ,0x0000daa5) // Found @0xff2cd8e0
DEF(zoom_status                             ,0x00006fd4) // Found @0xff191984
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 2 int value(s), the first is the zoom focus length.
// there are 103 entries in the table - set NUM_FL to 103
DEF(focus_len_table                         ,0xfffeea7c) // Found @0xfffeea7c
DEF(zoom_busy                               ,0x0000a1d4) // Found @0xff210888
DEF(focus_busy                              ,0x0000a098) // Found @0xff20c874
// Camera has 2 RAW buffers @ 0x48000000 & 0x561c9d00
//  Note: active buffer --> raw_buffers[active_raw_buffer]
//        other buffer  --> raw_buffers[active_raw_buffer^1]
DEF(raw_buffers                             ,0xff6a2c60) // Found @0xff6a2c60
DEF(active_raw_buffer                       ,0x00003c04) // Found @0xff09f448
DEF(fileio_semaphore                        ,0x00001cb4) // Found @0xff02f274
DEF(exmem_alloc_table                       ,0x0001b64c) // Found @0xff034250
DEF(exmem_types_table                       ,0xff8fadd4) // Found @0x00001d48
DEF_CONST(exmem_type_count                  ,0x0000001f)
DEF(imager_active                           ,0x00001fe0) // Found @0xff04b1f0 (0x1fdc + 4)
DEF_CONST(uiprop_count                      ,0x000000d7) // Found @0xff23b57c

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x40711000; }             // Found @0xff070014
//void *vid_get_viewport_fb()      { return (void*)0x40866b80; }             // Found @0xff4f4188
DEF(viewport_fb_d                           ,0x0000388c) // Found 0x3830 (@0xff090530) + 0x5c (@0xff090568)
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x3830+0x5c)); } // Found @0xff090530 & 0xff090568
DEF(jpeg_count_str                          ,0x0018bb58) // Found @0xff2b6228
//char *camera_jpeg_count_str()    { return (char*)0x0018bb58; }             // Found @0xff2b6228
//int get_flash_params_count(void) { return 0xf1; }                          // Found @0xff23c0f0

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00400000 // Found @0xff69b414, levent 0x30a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x01000000 // Found @0xff69b424, levent 0x302
//#define USB_IDX             2
//#define BATTCOVER_FLAG      0x00800000 // Found @0xff69b41c, levent 0x305
//#define BATTCOVER_IDX       2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 2, KEY_SHOOT_FULL      ,0x00000018 }, // Found @0xff69b38c, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000010 }, // Found @0xff69b38c, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00000008 }, // Found @0xff69b384, levent 0x00
//    { 2, KEY_POWER           ,0x00000020 }, // Found @0xff69b394, levent 0x100
//    { 2, KEY_PLAYBACK        ,0x00000080 }, // Found @0xff69b3a4, levent 0x101
//    { 2, KEY_VIDEO           ,0x00000400 }, // Found @0xff69b3b4, levent 0x02
//    { 2, KEY_SET             ,0x00000800 }, // Found @0xff69b3bc, levent 0x0a
//    { 2, KEY_LEFT            ,0x00001000 }, // Found @0xff69b3c4, levent 0x08
//    { 2, KEY_UP              ,0x00002000 }, // Found @0xff69b3cc, levent 0x06
//    { 2, KEY_RIGHT           ,0x00004000 }, // Found @0xff69b3d4, levent 0x09
//    { 2, KEY_DOWN            ,0x00008000 }, // Found @0xff69b3dc, levent 0x07
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#define CAM_RAW_ROWPIX    5344 // Found @0xff1dd6b8
//#define CAM_RAW_ROWS      3950 // Found @0xff1dd6c4
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff025d7c
//#define CAM_DATE_FOLDER_NAMING 0x080 // Found @0xff38eef0 (pass as 3rd param to GetImageFolder)
//#define PARAM_CAMERA_NAME 3 // Found @0xff82a100
//#define CAM_3ARG_DebugAssert 1
//#define CAM_HAS_WIFI 1 // Firmware has wifi support (only define if camera has hardware)

// Below goes in 'filewrite.c' or 'platform_camera.h':
//#define MAX_CHUNKS_FOR_FWT 7 // Found @0xff3afdd4

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
DEF(ctypes, 0xff6979d4)

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
// EXMEM_CREATIVE_SHOT  30

// ISR flag: 0x194c, pointer to current task's control block: 0x1948
// pointer to TCB area: 0x19cc, found @ 0xff913aec

// LED table init @ 0xff1a8d50
// LED #1: 0xc022d200 (#98 in GPIO table), offset 0x98
// LED #2: 0xc022d1fc (#97 in GPIO table), offset 0x8
// GPIO table @ 0xff69adec

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NHSTUB(AllocateUncacheableMemory              ,0xff025d38) //112
NHSTUB(Close                                  ,0xff027218) //120
NHSTUB(CreateBinarySemaphore                  ,0x006b792c) //115
NHSTUB(CreateTask                             ,0x006b5714) //120
NHSTUB(DebugAssert                            ,0x006b5ac8) //107
NHSTUB(DeleteDirectory_Fut                    ,0xff026b0c) //116
NHSTUB(DoAELock                               ,0xff032b64) //120
NHSTUB(DoAFLock                               ,0xff032818) //120
NHSTUB(EnterToCompensationEVF                 ,0xff032a8c) //104
NHSTUB(ExecuteEventProcedure                  ,0xff034d70) //104
NHSTUB(ExitFromCompensationEVF                ,0xff032ae0) //104
NHSTUB(ExitTask                               ,0x006b5a68) //120
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff044244) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff04447c) //104
NHSTUB(Fclose_Fut                             ,0xff026ba4) //120
NHSTUB(Feof_Fut                               ,0xff026d90) //  1
NHSTUB(Fflush_Fut                             ,0xff026dcc) //  1
NHSTUB(Fgets_Fut                              ,0xff026cf8) //  6
NHSTUB(Fopen_Fut                              ,0xff026b64) //120
NHSTUB(Fread_Fut                              ,0xff026c50) //120
NHSTUB(FreeUncacheableMemory                  ,0xff025d74) //112
NHSTUB(Fseek_Fut                              ,0xff026d44) //120
NHSTUB(Fwrite_Fut                             ,0xff026ca4) //120
NHSTUB(GetBatteryTemperature                  ,0xff07b4c0) //102
NHSTUB(GetCCDTemperature                      ,0xff07b448) //102
NHSTUB(GetCurrentAvValue                      ,0xff0949f4) //120
NHSTUB(GetCurrentShutterSpeed                 ,0xff13fd20) //120
NHSTUB(GetUsableMaxAv                         ,0xff1ddf84) //120
NHSTUB(GetUsableMinAv                         ,0xff1ddf68) //120
NHSTUB(GetDrive_ClusterSize                   ,0xff030938) //122
NHSTUB(GetDrive_FreeClusters                  ,0xff0310a4) //119
NHSTUB(GetDrive_TotalClusters                 ,0xff031078) //122
NHSTUB(GetFocusLensSubjectDistance            ,0xff20d9e0) //102
NHSTUB(GetImageFolder                         ,0xff1e5d8c) //122
NHSTUB(GetKbdState                            ,0xff0777b0) //109
NHSTUB(GetMemInfo                             ,0xff023450) //115
NHSTUB(GetOpticalTemperature                  ,0xff07b538) //120
NHSTUB(GetParameterData                       ,0xff23c0ac) //101
NHSTUB(GetPropertyCase                        ,0xff0b0544) //101
NHSTUB(GetSystemTime                          ,0xff3e3808) //120
NHSTUB(GetVRAMHPixelsSize                     ,0xff04ff00) //120
NHSTUB(GetVRAMVPixelsSize                     ,0xff04ff0c) //120
NHSTUB(GetZoomLensCurrentPoint                ,0xff210d0c) //120
NHSTUB(GetZoomLensCurrentPosition             ,0xff3c94b8) //102
NHSTUB(GiveSemaphore                          ,0x006b7bb0) //120
NHSTUB(IsStrobeChargeCompleted                ,0xff0eb9e4) //102
NHSTUB(LEDDrive                               ,0xff22456c) //120
NHSTUB(LocalTime                              ,0x006b9ad8) //115
NHSTUB(LockMainPower                          ,0xff0b4f54) //120
NHSTUB(MakeSDCardBootable                     ,0xff0315ac) //105
NHSTUB(MoveFocusLensToDistance                ,0xff4f7ea4) //102
NHSTUB(MoveIrisWithAv                         ,0xff3dbae4) //120
NHSTUB(MoveZoomLensWithPoint                  ,0xff3dc450) //120
NHSTUB(MoveOpticalZoomAt                      ,0xff03213c) //109
NHSTUB(Open                                   ,0xff0271b4) //120
NHSTUB(PB2Rec                                 ,0xff05ca74) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff225710) //102
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff2256e0) //102
NHSTUB(PT_PlaySound                           ,0xff0c7180) //122
NHSTUB(PostLogicalEventForNotPowerType        ,0xff0b2488) //120
NHSTUB(PostLogicalEventToUI                   ,0xff0b24e0) //120
NHSTUB(PutInNdFilter                          ,0xff3dc208) //102
NHSTUB(PutOutNdFilter                         ,0xff3dc22c) //102
NHSTUB(Read                                   ,0xff023f0c) //120
NHSTUB(ReadFastDir                            ,0xff3b1884) //115
NHSTUB(Rec2PB                                 ,0xff05cad0) //104
NHSTUB(RenameFile_Fut                         ,0xff026a04) //116
NHSTUB(Restart                                ,0xff037e08) //122
NHSTUB(ScreenLock                             ,0xff0b8d60) //117
NHSTUB(ScreenUnlock                           ,0xff0b8d18) //117
NHSTUB(SetAE_ShutterSpeed                     ,0xff4f2f48) //102
NHSTUB(SetAutoShutdownTime                    ,0xff0b4fc8) //120
NHSTUB(SetCurrentCaptureModeType              ,0xff0c3ba8) //120
NHSTUB(SetDate                                ,0xff4f4e38) //120
NHSTUB(SetFileAttributes                      ,0xff027714) //  6
NHSTUB(SetFileTimeStamp                       ,0xff02769c) //  6
NHSTUB(SetLogicalEventActive                  ,0xff0b2b50) //120
NHSTUB(SetParameterData                       ,0xff23c010) //101
NHSTUB(SetPropertyCase                        ,0xff0b0370) //101
NHSTUB(SetScriptMode                          ,0xff0b2ba4) //120
NHSTUB(SleepTask                              ,0x006b8f0c) //120
NHSTUB(TakeSemaphore                          ,0x006b7ad4) //120
NHSTUB(TurnOnDisplay                          ,0xff07040c) //120
NHSTUB(TurnOffDisplay                         ,0xff07041c) //120
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff25bf14) //120
NHSTUB(UnlockAE                               ,0xff032bf0) //120
NHSTUB(UnlockAF                               ,0xff032848) //120
NHSTUB(UnlockMainPower                        ,0xff0b4eac) //120
NHSTUB(VbattGet                               ,0xff02b1bc) //120
NHSTUB(Write                                  ,0xff027160) //120
NHSTUB(WriteSDCard                            ,0x006ba9e4) //108
NHSTUB(_log                                   ,0x006df1d8) //111
NHSTUB(_log10                                 ,0x006df718) //112
NHSTUB(_pow                                   ,0x006df890) //121
NHSTUB(_sqrt                                  ,0x006e1968) //  6
NHSTUB(add_ptp_handler                        ,0xff169274) //121
NHSTUB(apex2us                                ,0xff32d6b4) //121
NHSTUB(err_init_task                          ,0xff0247d8) //111
NHSTUB(exmem_alloc                            ,0xff034954) //101
NHSTUB(exmem_ualloc                           ,0xff0347b8) //101
NHSTUB(exmem_ufree                            ,0xff034900) //101
NHSTUB(free                                   ,0xff025084) //112
NHSTUB(get_nd_value                           ,0xff3c6ba8) //123
NHSTUB(get_current_nd_value                   ,0xff3c6b48) //122
NHSTUB(get_current_deltasv                    ,0xff13c21c) //122
NHSTUB(GetCurrentDriveBaseSvValue             ,0xff0dd678) //120
NHSTUB(kbd_p1_f                               ,0xff02c5d4) //109
NHSTUB(kbd_p1_f_cont                          ,0xff02c5e0) //109
NHSTUB(kbd_p2_f                               ,0xff02bc94) //109
NHSTUB(kbd_read_keys                          ,0xff02c584) //109
NHSTUB(kbd_read_keys_r2                       ,0xff076e28) //109
NHSTUB(lseek                                  ,0xff02752c) //120
NHSTUB(malloc                                 ,0xff02502c) //112
NHSTUB(memcmp                                 ,0xff024e04) //120
NHSTUB(memcpy                                 ,0xff0cb620) //120
NHSTUB(memset                                 ,0xff2e8ef8) //120
NHSTUB(mkdir                                  ,0xff0277ac) //121
NHSTUB(mktime_ext                             ,0xff0cad94) //  1
NHSTUB(OpenFastDir                            ,0xff3b1730) //115
NHSTUB(closedir                               ,0xff3b16e0) //121
NHSTUB(get_fstype                             ,0xff0308b0) //122
NHSTUB(qsort                                  ,0xff2e8e98) //  6
NHSTUB(rand                                   ,0xff0cb5f0) //121
NHSTUB(realloc                                ,0xff2e8f74) //115
NHSTUB(reboot_fw_update                       ,0xff3e1ca8) //106
NHSTUB(set_control_event                      ,0xff0b2810) //111
NHSTUB(srand                                  ,0xff0cb5e4) //122
NHSTUB(stat                                   ,0xff027574) //109
NHSTUB(strcat                                 ,0xff038770) //  1
NHSTUB(strchr                                 ,0xff0387f8) //  1
NHSTUB(strcmp                                 ,0xff024f00) //120
NHSTUB(strcpy                                 ,0xff024dec) //120
NHSTUB(strftime                               ,0xff0cae14) //113
NHSTUB(strlen                                 ,0xff024f44) //120
NHSTUB(strncmp                                ,0xff0387ac) //  1
NHSTUB(strncpy                                ,0xff027e8c) //  1
NHSTUB(strrchr                                ,0xff0cb76c) //  1
NHSTUB(strtol                                 ,0xff03875c) //101
NHSTUB(strtolx                                ,0xff038560) //109
   DEF(task_CaptSeq                           ,0xff09cf8c) //120
   DEF(task_DvlpSeqTask                       ,0xff229f98) //120
   DEF(task_ExpDrv                            ,0xff104d14) //120
   DEF(task_FileWrite                         ,0xff3afd78) //120
   DEF(task_InitFileModules                   ,0xff05fa6c) //120
   DEF(task_MovieRecord                       ,0xff21b488) //120
   DEF(task_PhySw                             ,0xff02c064) //120
   DEF(hook_CreateTask                        ,0x006b5714) //105
NHSTUB(time                                   ,0x006b92ac) //119
NHSTUB(vsprintf                               ,0xff027e4c) //115
NHSTUB(EngDrvRead                             ,0xff02c6e4) //102
NHSTUB(PTM_GetCurrentItem                     ,0xff0b6c3c) //105
NHSTUB(DisableISDriveError                    ,0xff3dd778) //120
NHSTUB(CancelHPTimer                          ,0xff0accb0) //119
NHSTUB(SetHPTimerAfterNow                     ,0xff0acba8) //119
NHSTUB(SS_MFOn                                ,0xff2257a4) //120
NHSTUB(SS_MFOff                               ,0xff2257b4) //120
NHSTUB(GetAdChValue                           ,0xff071704) //120
NHSTUB(get_ptp_buf_size                       ,0xff1593ac) //122
NHSTUB(get_ptp_file_buf                       ,0xff33f254) //121
NHSTUB(SetVideoOutType                        ,0xff4f37ac) //109
NHSTUB(GetVideoOutType                        ,0xff4f36e0) //120
