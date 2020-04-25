// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R47 (DRYOS version 2.3, release #0047)
//   Firmware Ver GM1.01A   // Found @ 0xff8938a0, "GM1.01A" @ 0xff8938ad
//   Firmware build timestamp: Feb 14 2011 15:25:52
//   Canon IXUS 115 HS

// Values for makefile.inc
//   DIGIC = 40# DIGIC 4
//   PLATFORMOSVER = 47
//   PLATFORMID = 12839# (0x3227) Found @ 0xfffe0040
//   MAXRAMADDR = 0x07ffffff
//   MEMISOSTART = 0x001745bc
//   KEYSYS = d4c# Found @ 0xffff3630
//   NEED_ENCODED_DISKBOOT = 6# Found @ 0xffff3640
//   ARAM_HEAP_START = 0x3ce000# Found @ 0xff990a74
//   ARAM_HEAP_SIZE  = 0x32000# Found @ 0xff990a34

// Detected address ranges:
// ROM      0xff810000 - 0xffffffff (8323072 bytes)
// RAM data 0x00001900 - 0x000102c0 copied from 0xffc7edd8 (  59840 bytes)

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ffafc608 -> ffc436c0
// Mode 33320 in firmware but not in current modemap
// Mode 33322 in firmware but not in current modemap

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00033f48) // Found @0xff834968
DEF(physw_run                               ,0x00001c44) // Found @0xff834508
DEF(physw_sleep_delay                       ,0x00001c4c) // Found @0xff834508
DEF(levent_table                            ,0xffbe12e4) // Found @0xffbe12e4
DEF(FlashParamsTable                        ,0xffc438fc) // Found @0xffc438fc
DEF(movie_status                            ,0x00006d54) // Found @0xff980d7c
DEF(video_compression_rate                  ,0x00006d94) // Found @0xff981838
DEF(full_screen_refresh                     ,0x00009ca4) // Found @0xffa2efa0
DEF(canon_menu_active                       ,0x000031b4) // Found @0xff8952c0
DEF(canon_shoot_menu_active                 ,0x0000836d) // Found @0xff9c4c44
DEF(playrec_mode                            ,0x00002ee0) // Found @0xff8871b4
DEF(zoom_status                             ,0x0000dd08) // Found @0xffaffce8
DEF(some_flag_for_af_scan                   ,0x00007158) // Found @0xff9853a0
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 3 int value(s), the first is the zoom focus length.
// there are 10 entries in the table - set NUM_FL to 10
DEF(focus_len_table                         ,0xfffe9ca8) // Found @0xfffe9ca8
DEF(zoom_busy                               ,0x00006c7c) // Found @0xff97c144
DEF(focus_busy                              ,0x00006afc) // Found @0xff97759c
DEF(recreview_hold                          ,0x00003874) // Found @0xff8a4ecc
// Palette colour tables  found @ 0xffbfe418
DEF(palette_control                         ,0x00009ca4) // Found @0xffa2ef1c
DEF(active_palette_buffer                   ,0x00009cac) // Found @0xffa2ef20
DEF(palette_buffer_ptr                      ,0x00009cb0) // Found @0xffa2f3e8
DEF(palette_buffer                          ,0x000bba50) // Found @0xffa2f3f8
// Offset from start of palette_buffer to color data = 8 (Found @0xffb32dcc)
DEF(bitmap_buffer                           ,0x00009ce4) // Found @0xffa32e44
DEF(active_bitmap_buffer                    ,0x00009cdc) // Found @0xffa32e48
DEF(viewport_buffers                        ,0xffb9868c) // Found @0xff8535c0
DEF(active_viewport_buffer                  ,0x0000216c) // Found @0xff853294
// Camera has 2 RAW buffers @ 0x413391a0 & 0x46000000
//  Note: active buffer --> raw_buffers[ active_raw_buffer   *3]
//        other buffer  --> raw_buffers[(active_raw_buffer^1)*3]
DEF(raw_buffers                             ,0xffb9ae44) // Found @0xffb9ae44
DEF(active_raw_buffer                       ,0x00002e3c) // Found @0xff8836b8
DEF(fileio_semaphore                        ,0x00002b44) // Found @0xff873180
DEF(exmem_alloc_table                       ,0x0003d628) // Found @0xff88edac
DEF(exmem_types_table                       ,0xffc804d4) // Found @0x00002ffc
DEF_CONST(exmem_type_count                  ,0x00000014)
DEF(imager_active                           ,0x000020a4) // Found @0xff84fe48 (0x20a0 + 4)
DEF_CONST(uiprop_count                      ,0x00000080) // Found @0xff9adb2c

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x40471000; }             // Found @0xff85f59c
//void *vid_get_viewport_fb()      { return (void*)0x405c6b80; }             // Found @0xffb56360
DEF(viewport_fb_d                           ,0x00002bf8) // Found 0x2ba0 (@0xff877260) + 0x58 (@0xff877298)
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x2ba0+0x58)); } // Found @0xff877260 & 0xff877298
DEF(jpeg_count_str                          ,0x000bb3a8) // Found @0xffa2629c
//char *camera_jpeg_count_str()    { return (char*)0x000bb3a8; }             // Found @0xffa2629c
//int get_flash_params_count(void) { return 0xa0; }                          // Found @0xff9ae4f0

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffb99710, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x04000000 // Found @0xffb99730, levent 0x902
//#define USB_IDX             2
//#define BATTCOVER_FLAG      0x00008000 // Found @0xffb99700, levent 0x905
//#define BATTCOVER_IDX       2
//#define ANALOG_AV_FLAG      0x00000008 // Found @0xffb99690, levent 0x900 (non-inverted logic)
//#define ANALOG_AV_IDX       0

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_PLAYBACK        ,0x00000001 }, // Found @0xffb99680, levent 0x601
//    { 0, KEY_POWER           ,0x00000002 }, // Found @0xffb99688, levent 0x600
//    { 1, KEY_MENU            ,0x01000000 }, // Found @0xffb996a0, levent 0x09
//    { 1, KEY_SET             ,0x04000000 }, // Found @0xffb996a8, levent 0x08
//    { 1, KEY_ZOOM_OUT        ,0x10000000 }, // Found @0xffb996b0, levent 0x03
//    { 1, KEY_ZOOM_IN         ,0x20000000 }, // Found @0xffb996b8, levent 0x02
//    { 1, KEY_VIDEO           ,0x80000000 }, // Found @0xffb996c8, levent 0x12
//    { 2, KEY_UP              ,0x00000001 }, // Found @0xffb996d0, levent 0x04
//    { 2, KEY_DOWN            ,0x00000002 }, // Found @0xffb996d8, levent 0x05
//    { 2, KEY_LEFT            ,0x00000004 }, // Found @0xffb996e0, levent 0x06
//    { 2, KEY_RIGHT           ,0x00000008 }, // Found @0xffb996e8, levent 0x07
//    { 2, KEY_SHOOT_FULL      ,0x00000030 }, // Found @0xffb996f8, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000020 }, // Found @0xffb996f8, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00000010 }, // Found @0xffb996f0, levent 0x00
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#define CAM_RAW_ROWPIX    4168 // Found @0xff94ff68
//#define CAM_RAW_ROWS      3060 // Found @0xff94ff74
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff83bba4
//#define CAM_DATE_FOLDER_NAMING 0x400 // Found @0xffaad034 (pass as 3rd param to GetImageFolder)
//#define PARAM_CAMERA_NAME 4 // Found @0xffc42a90

// Known propcases
// //      PROPCASE_AFSTEP 13
// #define PROPCASE_FOCUS_STATE 18
// #define PROPCASE_AV 23
// #define PROPCASE_BV 34
// //      PROPCASE_DELTA_DIGITALGAIN 77
// #define PROPCASE_DELTA_SV 79
// //      PROPCASE_DELTA_ND 80
// #define PROPCASE_EV_CORRECTION_2 211
// #define PROPCASE_ORIENTATION_SENSOR 223
// #define PROPCASE_SV_MARKET 250
// //      PROPCASE_SVFIX 251
// #define PROPCASE_TV 266
// Guessed propset: 4, 5

// Misc stuff
DEF(ctypes, 0xffb97e02)

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
// EXMEM_FILESTORE      12
// EXMEM_MOVIE_REC      13
// EXMEM_MOVIE_PLY      14
// EXMEM_WIDE           15
// EXMEM_NARROW         16
// EXMEM_SUPER_NARROW   17
// EXMEM_CRAW_REC       18
// EXMEM_PCEVF          19

// ISR flag: 0x1968, pointer to current task's control block: 0x1964
// pointer to TCB area: 0x19f0, found @ 0xff816984

// LED table init @ 0xff92d624
// LED #1: 0xc0220130, offset 0x4
// LED #2: 0xc0223030, offset 0x1d8

// For capt_seq.c
DEF(_nrflag,0x7194) // Found @ ff989d4c (0x718c) & ff989d88 (+0x08)
//static long *nrflag = (long*)(0x718c+0x08);  // Found @ ff989d4c & ff989d88
//#define NR_AUTO (0)                          // have to explictly reset value back to 0 to enable auto

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NHSTUB(AllocateUncacheableMemory              ,0xff83bb5c) //112
NHSTUB(Close                                  ,0xff837ebc) //120
NHSTUB(CreateBinarySemaphore                  ,0xff83b318) //115
NHSTUB(CreateTask                             ,0xff81e9b0) //120
NHSTUB(DebugAssert                            ,0xff81ec88) //107
NHSTUB(DeleteDirectory_Fut                    ,0xff8378b8) //116
NHSTUB(DeleteFile_Fut                         ,0xff8377d4) //112
NHSTUB(DoAELock                               ,0xff8399d0) //120
NHSTUB(DoAFLock                               ,0xff8396dc) //120
NHSTUB(EnterToCompensationEVF                 ,0xff839938) //104
NHSTUB(ExecuteEventProcedure                  ,0xff890b4c) //104
NHSTUB(ExitFromCompensationEVF                ,0xff83997c) //104
NHSTUB(ExitTask                               ,0xff81ec40) //120
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff8481e8) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff8482c0) //104
NHSTUB(Fclose_Fut                             ,0xff837950) //120
NHSTUB(Feof_Fut                               ,0xff837b3c) //  1
NHSTUB(Fflush_Fut                             ,0xff837b78) //  1
NHSTUB(Fgets_Fut                              ,0xff837aa4) //  6
NHSTUB(Fopen_Fut                              ,0xff837910) //120
NHSTUB(Fread_Fut                              ,0xff8379fc) //120
NHSTUB(FreeUncacheableMemory                  ,0xff83bb9c) //112
NHSTUB(Fseek_Fut                              ,0xff837af0) //120
NHSTUB(Fwrite_Fut                             ,0xff837a50) //120
NHSTUB(GetBatteryTemperature                  ,0xff8677dc) //102
NHSTUB(GetCCDTemperature                      ,0xff867768) //102
NHSTUB(GetCurrentAvValue                      ,0xff97902c) //120
NHSTUB(GetCurrentShutterSpeed                 ,0xff8b6c78) //120
NHSTUB(GetDrive_ClusterSize                   ,0xff874d54) //122
NHSTUB(GetDrive_FreeClusters                  ,0xff874dac) //119
NHSTUB(GetDrive_TotalClusters                 ,0xff874d84) //119
NHSTUB(GetFocusLensSubjectDistance            ,0xff978220) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff978680) //  3
NHSTUB(GetImageFolder                         ,0xff956f00) //122
NHSTUB(GetKbdState                            ,0xff8646f4) //109
NHSTUB(GetMemInfo                             ,0xff81a29c) //115
NHSTUB(GetOpticalTemperature                  ,0xff867850) //120
NHSTUB(GetParameterData                       ,0xff9ae4b0) //101
NHSTUB(GetPropertyCase                        ,0xff894810) //102
NHSTUB(GetSystemTime                          ,0xffaea954) //120
NHSTUB(GetVRAMHPixelsSize                     ,0xff855b74) //120
NHSTUB(GetVRAMVPixelsSize                     ,0xff855b80) //120
NHSTUB(GetZoomLensCurrentPoint                ,0xff97c4c8) //120
NHSTUB(GetZoomLensCurrentPosition             ,0xffad56d4) //102
NHSTUB(GiveSemaphore                          ,0xff83b554) //120
NHSTUB(IsStrobeChargeCompleted                ,0xff8e72f4) //102
NHSTUB(LEDDrive                               ,0xff863c4c) //120
NHSTUB(LocalTime                              ,0xff88e3dc) //115
NHSTUB(LockMainPower                          ,0xff89973c) //120
NHSTUB(MakeDirectory_Fut                      ,0xff837848) //116
NHSTUB(MakeSDCardBootable                     ,0xff874fe4) //105
NHSTUB(MoveFocusLensToDistance                ,0xffb5265c) //102
NHSTUB(MoveIrisWithAv                         ,0xffae7154) //120
NHSTUB(MoveZoomLensWithPoint                  ,0xffae780c) //120
NHSTUB(MoveOpticalZoomAt                      ,0xff8391b8) //109
NHSTUB(Open                                   ,0xff837df4) //120
NHSTUB(PB2Rec                                 ,0xff89c6dc) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff87e614) //120
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff87e5ec) //120
NHSTUB(PT_PlaySound                           ,0xff8891c8) //122
NHSTUB(PostLogicalEventForNotPowerType        ,0xff898ef8) //120
NHSTUB(PostLogicalEventToUI                   ,0xff898f44) //120
NHSTUB(PutInNdFilter                          ,0xffae7654) //102
NHSTUB(PutOutNdFilter                         ,0xffae7678) //102
NHSTUB(Read                                   ,0xff81ad58) //120
NHSTUB(ReadFastDir                            ,0xffac2e78) //  6
NHSTUB(Rec2PB                                 ,0xff89c71c) //104
NHSTUB(RefreshPhysicalScreen                  ,0xff8b06fc) //104
NHSTUB(RenameFile_Fut                         ,0xff837740) //116
NHSTUB(Restart                                ,0xff83d370) //122
NHSTUB(ScreenLock                             ,0xff8b18f4) //117
NHSTUB(ScreenUnlock                           ,0xff8b1958) //117
NHSTUB(SetAE_ShutterSpeed                     ,0xffb554d8) //102
NHSTUB(SetAutoShutdownTime                    ,0xff8997b0) //120
NHSTUB(SetCurrentCaptureModeType              ,0xff8a1ed4) //120
NHSTUB(SetFileAttributes                      ,0xff8382c0) //  6
NHSTUB(SetFileTimeStamp                       ,0xff838248) //  6
NHSTUB(SetLogicalEventActive                  ,0xff8994a4) //120
NHSTUB(SetParameterData                       ,0xff9ae420) //101
NHSTUB(SetPropertyCase                        ,0xff8946f4) //102
NHSTUB(SetScriptMode                          ,0xff8994f4) //120
NHSTUB(SleepTask                              ,0xff83b800) //120
NHSTUB(TakeSemaphore                          ,0xff83b484) //120
NHSTUB(TurnOffBackLight                       ,0xff8a8cbc) //104
NHSTUB(TurnOnBackLight                        ,0xff8a8ca4) //104
NHSTUB(TurnOnDisplay                          ,0xff85f9f8) //120
NHSTUB(TurnOffDisplay                         ,0xff85fa08) //120
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff99e2a0) //120
NHSTUB(UnlockAE                               ,0xff8399f4) //120
NHSTUB(UnlockAF                               ,0xff839714) //120
NHSTUB(UnlockMainPower                        ,0xff899690) //120
NHSTUB(UnsetZoomForMovie                      ,0xff9b52e4) //104
NHSTUB(VbattGet                               ,0xff833118) //120
NHSTUB(Write                                  ,0xff837f10) //120
NHSTUB(WriteSDCard                            ,0xff968358) //108
NHSTUB(_log                                   ,0xffb94928) //111
NHSTUB(_log10                                 ,0xffb94e68) //112
NHSTUB(_pow                                   ,0xffb94fe0) //121
NHSTUB(_sqrt                                  ,0xffb96c04) //  6
NHSTUB(add_ptp_handler                        ,0xffa7532c) //121
NHSTUB(apex2us                                ,0xffa37330) //121
NHSTUB(close                                  ,0xff81abb4) //109
NHSTUB(err_init_task                          ,0xff815fd4) //111
NHSTUB(exmem_alloc                            ,0xff88f3a4) //101
NHSTUB(exmem_free                             ,0xff88f41c) //101
NHSTUB(free                                   ,0xff814244) //112
NHSTUB(get_nd_value                           ,0xffad31c0) //123
NHSTUB(get_current_nd_value                   ,0xffad3160) //122
NHSTUB(kbd_p1_f                               ,0xff8349e4) //109
NHSTUB(kbd_p1_f_cont                          ,0xff8349f0) //109
NHSTUB(kbd_p2_f                               ,0xff8341d8) //109
NHSTUB(kbd_read_keys                          ,0xff834968) //109
NHSTUB(kbd_read_keys_r2                       ,0xff86410c) //109
NHSTUB(lseek                                  ,0xff8380d8) //120
NHSTUB(malloc                                 ,0xff8141ec) //112
NHSTUB(memcmp                                 ,0xff82092c) //120
NHSTUB(memcpy                                 ,0xff841250) //120
NHSTUB(memset                                 ,0xffa36330) //120
NHSTUB(mkdir                                  ,0xff838358) //109
NHSTUB(mktime_ext                             ,0xff8b276c) //  1
NHSTUB(open                                   ,0xff81ab04) //109
NHSTUB(OpenFastDir                            ,0xffac2d24) //  6
NHSTUB(closedir                               ,0xffac2cd4) //121
NHSTUB(get_fstype                             ,0xff874dcc) //122
NHSTUB(qsort                                  ,0xffb35a60) //  6
NHSTUB(rand                                   ,0xffa36470) //121
NHSTUB(realloc                                ,0xffa363ac) //115
NHSTUB(reboot_fw_update                       ,0xffac8314) //106
NHSTUB(set_control_event                      ,0xff899168) //111
NHSTUB(srand                                  ,0xffa36464) //122
NHSTUB(stat                                   ,0xff838120) //109
NHSTUB(strcat                                 ,0xff8b1f24) //  1
NHSTUB(strchr                                 ,0xff8140b8) //  1
NHSTUB(strcmp                                 ,0xff8208e8) //120
NHSTUB(strcpy                                 ,0xff8208d0) //120
NHSTUB(strftime                               ,0xff8b216c) //113
NHSTUB(strlen                                 ,0xff814104) //120
NHSTUB(strncmp                                ,0xff81406c) //  1
NHSTUB(strncpy                                ,0xff814030) //  1
NHSTUB(strrchr                                ,0xff8140dc) //  1
NHSTUB(strtol                                 ,0xff841550) //101
NHSTUB(strtolx                                ,0xff841354) //109
   DEF(task_CaptSeq                           ,0xff881368) //120
   DEF(task_DvlpSeqTask                       ,0xff8831e8) //120
   DEF(task_ExpDrv                            ,0xff8ca428) //120
   DEF(task_FileWrite                         ,0xffac0d28) //120
   DEF(task_InitFileModules                   ,0xff89d020) //120
   DEF(task_MovieRecord                       ,0xff982008) //120
   DEF(task_PhySw                             ,0xff834504) //120
NHSTUB(time                                   ,0xff88e9b8) //109
NHSTUB(vsprintf                               ,0xff820890) //115
NHSTUB(EngDrvRead                             ,0xff835830) //102
NHSTUB(PTM_GetCurrentItem                     ,0xff899fe8) //105
NHSTUB(DisableISDriveError                    ,0xffae81bc) //120
NHSTUB(CancelHPTimer                          ,0xff890234) //119
NHSTUB(SetHPTimerAfterNow                     ,0xff89012c) //119
NHSTUB(PT_MFOn                                ,0xff87e6a4) //120
NHSTUB(PT_MFOff                               ,0xff87e6b4) //120
NHSTUB(GetAdChValue                           ,0xff860e98) //120
NHSTUB(EnableHDMIPower                        ,0xff863804) //123
NHSTUB(DisableHDMIPower                       ,0xff86380c) //123
NHSTUB(get_ptp_buf_size                       ,0xff912d90) //122
NHSTUB(get_ptp_file_buf                       ,0xffa76eac) //121
NHSTUB(SetVideoOutType                        ,0xffb55d08) //109
