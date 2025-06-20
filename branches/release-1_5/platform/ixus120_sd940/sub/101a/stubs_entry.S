// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R39 (DRYOS version 2.3, release #0039)
//   Firmware Ver GM1.01A   // Found @ 0xff883a54, "GM1.01A" @ 0xff883a61
//   Firmware build timestamp: Jul  6 2009 19:53:50
//   Canon DIGITAL IXUS 120 IS

// Values for makefile.inc
//   DIGIC = 40# DIGIC 4
//   PLATFORMOSVER = 39
//   PLATFORMID = 12774# (0x31e6) Found @ 0xfffe0130
//   MAXRAMADDR = 0x03ffffff
//   MEMISOSTART = 0x0013ca18
//   KEYSYS = d4# Found @ 0xffff3564
//   NEED_ENCODED_DISKBOOT = 3# Found @ 0xffff3574
//   ARAM_HEAP_START = 0x34e000# Found @ 0xff94b258
//   ARAM_HEAP_SIZE  = 0x32000# Found @ 0xff94b218

// Detected address ranges:
// ROM      0xff810000 - 0xffffffff (8323072 bytes)
// RAM data 0x00001900 - 0x0000df04 copied from 0xffbbeae8 (  50692 bytes)

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NHSTUB(kbd_pwr_off                          ,0xff858e10) //  2 64%    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ffa759e0 -> ffb970f4
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00031b78) // Found @0xff833554
DEF(physw_run                               ,0x00001c44) // Found @0xff8331c8
DEF(physw_sleep_delay                       ,0x00001c42) // Found @0xff8331c8
DEF(levent_table                            ,0xffb41f14) // Found @0xffb41f14
DEF(FlashParamsTable                        ,0xffb972dc) // Found @0xffb972dc
DEF(movie_status                            ,0x00006260) // Found @0xff93d360
DEF(video_compression_rate                  ,0x0000628c) // Found @0xff93d5cc
DEF(full_screen_refresh                     ,0x00008bb0) // Found @0xff9cf9d4
DEF(canon_menu_active                       ,0x00002d48) // Found @0xff8854d4
DEF(canon_shoot_menu_active                 ,0x00007751) // Found @0xff97b9b4
DEF(playrec_mode                            ,0x00002a7c) // Found @0xff877af0
DEF(zoom_status                             ,0x0000b9dc) // Found @0xffa78278
DEF(some_flag_for_af_scan                   ,0x0000673c) // Found @0xff940350
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 3 int value(s), the first is the zoom focus length.
// there are 10 entries in the table - set NUM_FL to 10
DEF(focus_len_table                         ,0xfffe2a8c) // Found @0xfffe2a8c
DEF(zoom_busy                               ,0x000061cc) // Found @0xff93a434
DEF(focus_busy                              ,0x00006078) // Found @0xff9349ac
DEF(recreview_hold                          ,0x000033a4) // Found @0xff8942c8
// Palette colour tables  found @ 0xffb58a4c
DEF(active_palette_buffer                   ,0x00008bb8) // Found @0xff9cf910
DEF(palette_buffer_ptr                      ,0x00008bc4) // Found @0xff9cf5e4
// Offset from start of palette_buffer to color data = 8 (Found @0xffaafa2c)
// Camera appears to have only 1 RAW buffer @ 0x4219d120 (Found @0xffad6e60)
DEF(fileio_semaphore                        ,0x00002740) // Found @0xff866d8c
DEF(exmem_alloc_table                       ,0x00037f84) // Found @0xff87ee30
DEF(exmem_types_table                       ,0xffbbfd80) // Found @0x00002b98
DEF_CONST(exmem_type_count                  ,0x00000012)
DEF(imager_active                           ,0x00001f6c) // Found @0xff848a34 (0x1f68 + 4)
DEF_CONST(uiprop_count                      ,0x0000006e) // Found @0xff96a9c4

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x403f1000; }             // Found @0xff8532dc
//void *vid_get_viewport_fb()      { return (void*)0x4088b700; }             // Found @0xffad4734
DEF(viewport_fb_d                           ,0x000027e8) // Found 0x2790 (@0xff869dec) + 0x58 (@0xff869e24)
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x2790+0x58)); } // Found @0xff869dec & 0xff869e24
DEF(jpeg_count_str                          ,0x000700b0) // Found @0xff9c4130
//char *camera_jpeg_count_str()    { return (char*)0x000700b0; }             // Found @0xff9c4130
//int get_flash_params_count(void) { return 0x84; }                          // Found @0xff96b408

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffb0c754, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x00080000 // Found @0xffb0c76c, levent 0x902
//#define USB_IDX             2
//#define BATTCOVER_FLAG      0x00008000 // Found @0xffb0c73c, levent 0x905
//#define BATTCOVER_IDX       2
//#define ANALOG_AV_FLAG      0x00040000 // Found @0xffb0c760, levent 0x900 (non-inverted logic)
//#define ANALOG_AV_IDX       2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_SET             ,0x00000004 }, // Found @0xffb0c694, levent 0x08
//    { 0, KEY_DISPLAY         ,0x00000008 }, // Found @0xffb0c6a0, levent 0x0a
//    { 2, KEY_MENU            ,0x00000001 }, // Found @0xffb0c6b8, levent 0x09
//    { 2, KEY_ZOOM_IN         ,0x00000004 }, // Found @0xffb0c6c4, levent 0x02
//    { 2, KEY_ZOOM_OUT        ,0x00000008 }, // Found @0xffb0c6d0, levent 0x03
//    { 2, KEY_LEFT            ,0x00000010 }, // Found @0xffb0c6dc, levent 0x06
//    { 2, KEY_RIGHT           ,0x00000020 }, // Found @0xffb0c6e8, levent 0x07
//    { 2, KEY_DOWN            ,0x00000040 }, // Found @0xffb0c6f4, levent 0x05
//    { 2, KEY_UP              ,0x00000080 }, // Found @0xffb0c700, levent 0x04
//    { 2, KEY_SHOOT_FULL      ,0x00000300 }, // Found @0xffb0c718, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000200 }, // Found @0xffb0c718, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00000100 }, // Found @0xffb0c70c, levent 0x00
//    { 2, KEY_POWER           ,0x00000400 }, // Found @0xffb0c724, levent 0x600
//    { 2, KEY_PLAYBACK        ,0x00000800 }, // Found @0xffb0c730, levent 0x601
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_RAW_ROWPIX    4080 // Found @0xff9111f0
//#define CAM_RAW_ROWS      3048 // Found @0xff9111f8
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff8388dc
//#define CAM_DATE_FOLDER_NAMING 0x100 // Found @0xffa396f0 (pass as 3rd param to GetImageFolder)
//#define PARAM_CAMERA_NAME 4 // Found @0xffb99668

// Below goes in 'filewrite.c' or 'platform_camera.h':
//#define MAX_CHUNKS_FOR_FWT 4 // Found @0xffa48998

// Known propcases
// //      PROPCASE_AFSTEP 13
// #define PROPCASE_FOCUS_STATE 18
// #define PROPCASE_AV 23
// #define PROPCASE_BV 34
// //      PROPCASE_DELTA_DIGITALGAIN 77
// #define PROPCASE_DELTA_SV 79
// //      PROPCASE_DELTA_ND 80
// #define PROPCASE_EV_CORRECTION_2 209
// #define PROPCASE_ORIENTATION_SENSOR 221
// #define PROPCASE_SV_MARKET 248
// //      PROPCASE_SVFIX 249
// #define PROPCASE_TV 264
// Guessed propset: 3

// Misc stuff
DEF(ctypes, 0xffb0b20e)

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
// EXMEM_FILESTORE      11
// EXMEM_MOVIE_REC      12
// EXMEM_MOVIE_PLY      13
// EXMEM_WIDE           14
// EXMEM_NARROW         15
// EXMEM_CRAW_REC       16
// EXMEM_PCEVF          17

// ISR flag: 0x1964, pointer to current task's control block: 0x1960
// pointer to TCB area: 0x19f0, found @ 0xff81683c

// LED table init @ 0xff8f3888
// LED #1: 0xc0220130, offset 0x4
// LED #2: 0xc0220134, offset 0x44

// For capt_seq.c
DEF(_nrflag,0x6718) // Found @ ff9424b8 (0x6720) & ff9424d8 (-0x08)
//static long *nrflag = (long*)(0x6720-0x08);  // Found @ ff9424b8 & ff9424d4

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NHSTUB(AllocateUncacheableMemory              ,0xff838898) //112
NHSTUB(Close                                  ,0xff8353b4) //120
NHSTUB(CreateBinarySemaphore                  ,0xff838078) //115
NHSTUB(CreateTask                             ,0xff81e5b4) //120
NHSTUB(DebugAssert                            ,0xff81e88c) //107
NHSTUB(DeleteDirectory_Fut                    ,0xff834e24) //116
NHSTUB(DeleteFile_Fut                         ,0xff834d40) //112
NHSTUB(DoAELock                               ,0xff836a6c) //120
NHSTUB(DoAFLock                               ,0xff83687c) //120
NHSTUB(EnterToCompensationEVF                 ,0xff8369d4) //104
NHSTUB(ExecuteEventProcedure                  ,0xff880bf8) //104
NHSTUB(ExitFromCompensationEVF                ,0xff836a18) //104
NHSTUB(ExitTask                               ,0xff81e844) //120
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff844034) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff84410c) //104
NHSTUB(Fclose_Fut                             ,0xff834ebc) //120
NHSTUB(Feof_Fut                               ,0xff8350a8) //  1
NHSTUB(Fflush_Fut                             ,0xff8350e4) //  1
NHSTUB(Fgets_Fut                              ,0xff835010) //  1
NHSTUB(Fopen_Fut                              ,0xff834e7c) //120
NHSTUB(Fread_Fut                              ,0xff834f68) //120
NHSTUB(FreeUncacheableMemory                  ,0xff8388d8) //112
NHSTUB(Fseek_Fut                              ,0xff83505c) //120
NHSTUB(Fwrite_Fut                             ,0xff834fbc) //120
NHSTUB(GetBatteryTemperature                  ,0xff85bd0c) //102
NHSTUB(GetCCDTemperature                      ,0xff85bc98) //102
NHSTUB(GetCurrentAvValue                      ,0xff936558) //120
NHSTUB(GetCurrentShutterSpeed                 ,0xff8a2d50) //120
NHSTUB(GetDrive_ClusterSize                   ,0xff868774) //122
NHSTUB(GetDrive_FreeClusters                  ,0xff8687d4) //  3
NHSTUB(GetDrive_TotalClusters                 ,0xff8687a8) //  3
NHSTUB(GetFocusLensSubjectDistance            ,0xff935724) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff935b6c) //  3
NHSTUB(GetImageFolder                         ,0xff91901c) //122
NHSTUB(GetKbdState                            ,0xff858df8) //109
NHSTUB(GetMemInfo                             ,0xff81a070) //115
NHSTUB(GetOpticalTemperature                  ,0xff85bd80) //120
NHSTUB(GetParameterData                       ,0xff96b3c8) //101
NHSTUB(GetPropertyCase                        ,0xff884948) //102
NHSTUB(GetSystemTime                          ,0xffa69d0c) //120
NHSTUB(GetVRAMHPixelsSize                     ,0xff8da2e4) //120
NHSTUB(GetVRAMVPixelsSize                     ,0xff8da2f0) //120
NHSTUB(GetZoomLensCurrentPoint                ,0xff93a7a8) //120
NHSTUB(GetZoomLensCurrentPosition             ,0xffa5d91c) //102
NHSTUB(GiveSemaphore                          ,0xff8382b4) //120
NHSTUB(IsStrobeChargeCompleted                ,0xff8bc268) //102
NHSTUB(LEDDrive                               ,0xff8582f4) //120
NHSTUB(LocalTime                              ,0xff87e56c) //115
NHSTUB(LockMainPower                          ,0xff88aa60) //120
NHSTUB(MakeDirectory_Fut                      ,0xff834db4) //116
NHSTUB(MoveFocusLensToDistance                ,0xffad10c0) //102
NHSTUB(MoveIrisWithAv                         ,0xffa677f4) //120
NHSTUB(MoveZoomLensWithPoint                  ,0xffa67d80) //120
NHSTUB(MoveOpticalZoomAt                      ,0xff83640c) //109
NHSTUB(Open                                   ,0xff83535c) //120
NHSTUB(PB2Rec                                 ,0xff88d9fc) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff870934) //120
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff87090c) //120
NHSTUB(PT_PlaySound                           ,0xff879708) //102
NHSTUB(PostLogicalEventForNotPowerType        ,0xff88a298) //120
NHSTUB(PostLogicalEventToUI                   ,0xff88a2e4) //120
NHSTUB(PutInNdFilter                          ,0xffa67be4) //102
NHSTUB(PutOutNdFilter                         ,0xffa67c08) //102
NHSTUB(Read                                   ,0xff81ab78) //120
NHSTUB(ReadFastDir                            ,0xffa4d0d4) //  3
NHSTUB(Rec2PB                                 ,0xff88da3c) //104
NHSTUB(RefreshPhysicalScreen                  ,0xff9d1ea4) //104
NHSTUB(RenameFile_Fut                         ,0xff834cac) //116
NHSTUB(Restart                                ,0xff839ff0) //122
NHSTUB(ScreenLock                             ,0xff9d1c7c) //117
NHSTUB(ScreenUnlock                           ,0xff9d1cbc) //117
NHSTUB(SetAE_ShutterSpeed                     ,0xffad38ac) //102
NHSTUB(SetAutoShutdownTime                    ,0xff88aad4) //120
NHSTUB(SetCurrentCaptureModeType              ,0xff891b0c) //120
NHSTUB(SetDate                                ,0xffad5390) //120
NHSTUB(SetFileAttributes                      ,0xff835684) //  3
NHSTUB(SetFileTimeStamp                       ,0xff835640) //  3
NHSTUB(SetLogicalEventActive                  ,0xff88a7dc) //120
NHSTUB(SetParameterData                       ,0xff96b338) //101
NHSTUB(SetPropertyCase                        ,0xff88484c) //102
NHSTUB(SetScriptMode                          ,0xff88a82c) //120
NHSTUB(SleepTask                              ,0xff83851c) //120
NHSTUB(TakeSemaphore                          ,0xff8381e4) //120
NHSTUB(TurnOffBackLight                       ,0xff89764c) //104
NHSTUB(TurnOnBackLight                        ,0xff897634) //104
NHSTUB(TurnOnDisplay                          ,0xff8534e0) //120
NHSTUB(TurnOffDisplay                         ,0xff8534f0) //120
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff95673c) //120
NHSTUB(UnlockAE                               ,0xff836a90) //120
NHSTUB(UnlockAF                               ,0xff8368b4) //120
NHSTUB(UnlockMainPower                        ,0xff88a9b4) //120
NHSTUB(UnsetZoomForMovie                      ,0xff9712e4) //104
NHSTUB(UpdateMBROnFlash                       ,0xff8685f4) //105
NHSTUB(VbattGet                               ,0xff831df4) //120
NHSTUB(Write                                  ,0xff835444) //120
NHSTUB(WriteSDCard                            ,0xff926660) //108
NHSTUB(_log                                   ,0xffb08cd0) //111
NHSTUB(_log10                                 ,0xffb07c14) //112
NHSTUB(_pow                                   ,0xffb07d84) //121
NHSTUB(_sqrt                                  ,0xffb0a038) //  1
NHSTUB(add_ptp_handler                        ,0xffa16e20) //121
NHSTUB(apex2us                                ,0xff9d5394) //121
NHSTUB(close                                  ,0xff81a990) //109
NHSTUB(err_init_task                          ,0xff815f28) //111
NHSTUB(exmem_alloc                            ,0xff87f42c) //103
NHSTUB(exmem_ualloc                           ,0xff87f280) //103
NHSTUB(exmem_ufree                            ,0xff87f3cc) //103
NHSTUB(free                                   ,0xff814138) //112
NHSTUB(get_nd_value                           ,0xffa5b6a0) //123
NHSTUB(get_current_nd_value                   ,0xffa5b65c) //122
NHSTUB(kbd_p1_f                               ,0xff8335d0) //109
NHSTUB(kbd_p1_f_cont                          ,0xff8335dc) //109
NHSTUB(kbd_p2_f                               ,0xff832e94) //109
NHSTUB(kbd_read_keys                          ,0xff833554) //109
NHSTUB(kbd_read_keys_r2                       ,0xff8587b8) //109
NHSTUB(lseek                                  ,0xff8354d0) //120
NHSTUB(malloc                                 ,0xff8140dc) //112
NHSTUB(memcmp                                 ,0xff8203d8) //120
NHSTUB(memcpy                                 ,0xff83de48) //120
NHSTUB(memset                                 ,0xff9d43e4) //120
NHSTUB(mkdir                                  ,0xff835828) //109
NHSTUB(mktime_ext                             ,0xff89ea98) //  1
NHSTUB(open                                   ,0xff81a8e0) //109
NHSTUB(OpenFastDir                            ,0xffa4cfa0) //  3
NHSTUB(closedir                               ,0xffa4cf5c) //  3
NHSTUB(get_fstype                             ,0xff8687f8) //122
NHSTUB(qsort                                  ,0xffab56e8) //  1
NHSTUB(rand                                   ,0xff8204e0) //121
NHSTUB(realloc                                ,0xff9d4460) //115
NHSTUB(reboot_fw_update                       ,0xffa525e4) //106
NHSTUB(set_control_event                      ,0xff88a500) //111
NHSTUB(srand                                  ,0xff8204d4) //122
NHSTUB(stat                                   ,0xff83550c) //109
NHSTUB(strcat                                 ,0xff89e254) //  1
NHSTUB(strchr                                 ,0xff813fc0) //  1
NHSTUB(strcmp                                 ,0xff820394) //120
NHSTUB(strcpy                                 ,0xff82037c) //120
NHSTUB(strftime                               ,0xff89e4a0) //  1
NHSTUB(strlen                                 ,0xff81400c) //120
NHSTUB(strncmp                                ,0xff813f74) //  1
NHSTUB(strncpy                                ,0xff813f38) //  1
NHSTUB(strrchr                                ,0xff813fe4) //  1
NHSTUB(strtol                                 ,0xff83e128) //101
NHSTUB(strtolx                                ,0xff83df2c) //109
   DEF(task_CaptSeq                           ,0xff872f84) //120
   DEF(task_DvlpSeqTask                       ,0xff874488) //120
   DEF(task_ExpDrv                            ,0xff8b2f74) //120
   DEF(task_FileWrite                         ,0xffa48930) //120
   DEF(task_InitFileModules                   ,0xff88e520) //120
   DEF(task_MovieRecord                       ,0xff93d648) //120
   DEF(task_PhySw                             ,0xff8331c4) //120
NHSTUB(time                                   ,0xff87eae4) //109
NHSTUB(vsprintf                               ,0xff820340) //115
NHSTUB(EngDrvRead                             ,0xff834418) //102
NHSTUB(PTM_GetCurrentItem                     ,0xff88b47c) //105
NHSTUB(DisableISDriveError                    ,0xffa685a0) //120
NHSTUB(CancelHPTimer                          ,0xff8802e0) //119
NHSTUB(SetHPTimerAfterNow                     ,0xff8801d8) //119
NHSTUB(PT_MFOn                                ,0xff8709c4) //120
NHSTUB(PT_MFOff                               ,0xff8709d4) //120
NHSTUB(GetAdChValue                           ,0xff854b44) //120
NHSTUB(get_ptp_buf_size                       ,0xff8dd110) //122
NHSTUB(get_ptp_file_buf                       ,0xffa18808) //121
NHSTUB(SetVideoOutType                        ,0xffad40c8) //109
NHSTUB(GetVideoOutType                        ,0xffad3ffc) //120
