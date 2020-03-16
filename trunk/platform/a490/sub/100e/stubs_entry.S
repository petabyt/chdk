// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R43 (DRYOS version 2.3, release #0043)
//   Firmware Ver GM1.00E   // Found @ 0xffc68500, "GM1.00E" @ 0xffc6850d
//   Firmware build timestamp: Jan  7 2010 15:33:59
//   Canon PowerShot A490

// Values for makefile.inc
//   DIGIC = 30                  // DIGIC III
//   PLATFORMOSVER = 43
//   PLATFORMID = 12784 (0x31f0) // Found @ 0xfffe0130
//   MAXRAMADDR = 0x01ffffff
//   MEMISOSTART = 0x00129140
//   KEYSYS = d4a                // Found @ 0xffff1a0c
//   NEED_ENCODED_DISKBOOT = 4   // Found @ 0xffff1a1c
//   ARAM_HEAP_START = 0x2ce000  // Found @ 0xffd18218
//   ARAM_HEAP_SIZE  = 0x32000   // Found @ 0xffd181d8

// Detected address ranges:
// ROM      0xffc00000 - 0xffffffff (4194304 bytes)
// RAM data 0x00001900 - 0x0000ab04 copied from 0xffee6708 (  37380 bytes)

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NHSTUB(kbd_pwr_off                          ,0xffc435ec) //  2 64%    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ffe07d3c -> ffeca5dc
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x0002e754) // Found @0xffc23b2c
DEF(physw_run                               ,0x00001bf0) // Found @0xffc23790
DEF(physw_sleep_delay                       ,0x00001bee) // Found @0xffc23790
DEF(levent_table                            ,0xffe9ff24) // Found @0xffe9ff24
DEF(FlashParamsTable                        ,0xffeca7cc) // Found @0xffeca7cc
DEF(movie_status                            ,0x00005470) // Found @0xffd0c6a4
DEF(full_screen_refresh                     ,0x000072e8) // Found @0xffd794c4
DEF(canon_menu_active                       ,0x00002a3c) // Found @0xffc6a028
DEF(canon_shoot_menu_active                 ,0x00006571) // Found @0xffd3fa70
DEF(playrec_mode                            ,0x00002798) // Found @0xffc5d828
DEF(zoom_status                             ,0x000095a8) // Found @0xffe0ac18
DEF(some_flag_for_af_scan                   ,0x00005818) // Found @0xffd0f010
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 3 int value(s), the first is the zoom focus length.
// there are 7 entries in the table - set NUM_FL to 7
DEF(focus_len_table                         ,0xfffe2990) // Found @0xfffe2990
DEF(zoom_busy                               ,0x000053f0) // Found @0xffd09900
DEF(focus_busy                              ,0x00005300) // Found @0xffd06f38
DEF(recreview_hold                          ,0x0000302c) // Found @0xffc757dc
DEF(viewport_buffers                        ,0xffe88f64) // Found @0xffcb55c4
DEF(active_viewport_buffer                  ,0x000040f8) // Found @0xffcb540c
// Camera appears to have only 1 RAW buffer @ 0x10e52420 (Found @0xffe56fac)
DEF(fileio_semaphore                        ,0x000024ec) // Found @0xffc4f7b8
DEF(exmem_alloc_table                       ,0x000336e0) // Found @0xffc63b4c
DEF(exmem_types_table                       ,0xffee7694) // Found @0x0000288c
DEF_CONST(exmem_type_count                  ,0x00000012)
DEF(imager_active                           ,0x00001e58) // Found @0xffc381dc (0x1e54 + 4)
DEF_CONST(uiprop_count                      ,0x00000074) // Found @0xffd2e6a0

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x10361000; }             // Found @0xffc3f024
//void *vid_get_viewport_fb()      { return (void*)0x10648cc0; }             // Found @0xffe53c80
DEF(viewport_fb_d                           ,0x00002594) // Found 0x2540 (@0xffc52914) + 0x54 (@0xffc5294c)
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x2540+0x54)); } // Found @0xffc52914 & 0xffc5294c
DEF(jpeg_count_str                          ,0x0007571c) // Found @0xffd70afc
//char *camera_jpeg_count_str()    { return (char*)0x0007571c; }             // Found @0xffd70afc
//int get_flash_params_count(void) { return 0x94; }                          // Found @0xffd2f0e4

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00040000 // Found @0xffe8217c, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x00080000 // Found @0xffe82188, levent 0x902
//#define USB_IDX             2
//#define BATTCOVER_FLAG      0x00010000 // Found @0xffe82164, levent 0x905
//#define BATTCOVER_IDX       2
//#define ANALOG_AV_FLAG      0x00100000 // Found @0xffe82104, levent 0x900 (non-inverted logic)
//#define ANALOG_AV_IDX       0

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_PLAYBACK        ,0x00020000 }, // Found @0xffe820f8, levent 0x601
//    { 0, KEY_POWER           ,0x00800000 }, // Found @0xffe82110, levent 0x600
//    { 2, KEY_RIGHT           ,0x00000004 }, // Found @0xffe8211c, levent 0x07
//    { 2, KEY_SHOOT_FULL      ,0x00000030 }, // Found @0xffe82134, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000020 }, // Found @0xffe82134, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00000010 }, // Found @0xffe82128, levent 0x00
//    { 2, KEY_ZOOM_OUT        ,0x00000040 }, // Found @0xffe82140, levent 0x03
//    { 2, KEY_ZOOM_IN         ,0x00000080 }, // Found @0xffe8214c, levent 0x02
//    { 2, KEY_SET             ,0x00000100 }, // Found @0xffe82158, levent 0x08
//    { 2, KEY_UP              ,0x00100000 }, // Found @0xffe82194, levent 0x04 (uses inverted logic in physw_status)
//    { 2, KEY_DOWN            ,0x00200000 }, // Found @0xffe821a0, levent 0x05 (uses inverted logic in physw_status)
//    { 2, KEY_LEFT            ,0x00400000 }, // Found @0xffe821ac, levent 0x06 (uses inverted logic in physw_status)
//    { 2, KEY_MENU            ,0x01000000 }, // Found @0xffe821c4, levent 0x09 (uses inverted logic in physw_status)
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_RAW_ROWPIX    3720 // Found @0xffcea098
//#define CAM_RAW_ROWS      2772 // Found @0xffcea0a4
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x10000000 // Found @0xffc29320
//#define CAM_DATE_FOLDER_NAMING 0x100 // Found @0xffdd89f8 (pass as 3rd param to GetImageFolder)
//#define PARAM_CAMERA_NAME 4 // Found @0xffecc770

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
DEF(ctypes, 0xffe81a16)

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
// pointer to TCB area: 0x19f4, found @ 0xffc06f94

// LED table init @ 0xffcd272c
// LED #1: 0xc0220088, offset 0x170
// LED #2: 0xc0220080, offset 0x1d8

// For capt_seq.c
DEF(_nrflag,0x57f8) // Found @ ffd10e24 (0x5800) & ffd10e44 (-0x08)
//static long *nrflag = (long*)(0x5800-0x08);  // Found @ ffd10e24 & ffd10e40

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NHSTUB(AllocateUncacheableMemory              ,0xffc292dc) //112
NHSTUB(Close                                  ,0xffc2610c) //120
NHSTUB(CreateBinarySemaphore                  ,0xffc0eec8) //115
NHSTUB(CreateTask                             ,0xffc0f1a8) //120
NHSTUB(DebugAssert                            ,0xffc0f680) //107
NHSTUB(DeleteDirectory_Fut                    ,0xffc25b68) //116
NHSTUB(DeleteFile_Fut                         ,0xffc25a84) //112
NHSTUB(DoAELock                               ,0xffc276a0) //120
NHSTUB(DoAFLock                               ,0xffc27558) //120
NHSTUB(EnterToCompensationEVF                 ,0xffc27608) //104
NHSTUB(ExecuteEventProcedure                  ,0xffc65798) //104
NHSTUB(ExitFromCompensationEVF                ,0xffc2764c) //104
NHSTUB(ExitTask                               ,0xffc0f438) //120
NHSTUB(ExpCtrlTool_StartContiAE               ,0xffc34ce8) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xffc34dc0) //104
NHSTUB(Fclose_Fut                             ,0xffc25c00) //120
NHSTUB(Feof_Fut                               ,0xffc25dec) //  1
NHSTUB(Fflush_Fut                             ,0xffc25e28) //  1
NHSTUB(Fgets_Fut                              ,0xffc25d54) //  1
NHSTUB(Fopen_Fut                              ,0xffc25bc0) //120
NHSTUB(Fread_Fut                              ,0xffc25cac) //120
NHSTUB(FreeUncacheableMemory                  ,0xffc2931c) //112
NHSTUB(Fseek_Fut                              ,0xffc25da0) //120
NHSTUB(Fwrite_Fut                             ,0xffc25d00) //120
NHSTUB(GetBatteryTemperature                  ,0xffc45624) //102
NHSTUB(GetCCDTemperature                      ,0xffc455b0) //102
NHSTUB(GetCurrentAvValue                      ,0xffd087b8) //120
NHSTUB(GetCurrentShutterSpeed                 ,0xffc80b7c) //120
NHSTUB(GetDrive_ClusterSize                   ,0xffc512bc) //122
NHSTUB(GetDrive_FreeClusters                  ,0xffc5131c) //  4
NHSTUB(GetDrive_TotalClusters                 ,0xffc512f0) //  3
NHSTUB(GetFocusLensSubjectDistance            ,0xffd07ab0) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xffd07f08) //  3
NHSTUB(GetImageFolder                         ,0xffcf1058) //122
NHSTUB(GetKbdState                            ,0xffc435d4) //109
NHSTUB(GetMemInfo                             ,0xffc0a7f8) //115
NHSTUB(GetOpticalTemperature                  ,0xffc4569c) //120
NHSTUB(GetParameterData                       ,0xffd2f0a4) //101
NHSTUB(GetPropertyCase                        ,0xffc694a4) //102
NHSTUB(GetSystemTime                          ,0xffdfa4b0) //120
NHSTUB(GetVRAMHPixelsSize                     ,0xffcb69fc) //120
NHSTUB(GetVRAMVPixelsSize                     ,0xffcb6a08) //120
NHSTUB(GetZoomLensCurrentPoint                ,0xffd09c78) //120
NHSTUB(GetZoomLensCurrentPosition             ,0xffdf24f4) //102
NHSTUB(GiveSemaphore                          ,0xffc0f104) //120
NHSTUB(IsStrobeChargeCompleted                ,0xffca6ff0) //102
NHSTUB(LEDDrive                               ,0xffc42bc8) //120
NHSTUB(LocalTime                              ,0xffc634a8) //115
NHSTUB(LockMainPower                          ,0xffc6cd7c) //120
NHSTUB(MakeDirectory_Fut                      ,0xffc25af8) //116
NHSTUB(MoveFocusLensToDistance                ,0xffe50700) //102
NHSTUB(MoveIrisWithAv                         ,0xffdf7b98) //120
NHSTUB(MoveZoomLensWithPoint                  ,0xffdf8124) //120
NHSTUB(MoveOpticalZoomAt                      ,0xffc27148) //109
NHSTUB(Open                                   ,0xffc260a0) //120
NHSTUB(PB2Rec                                 ,0xffc6f9e8) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xffc570e8) //120
NHSTUB(PT_MoveOpticalZoomAt                   ,0xffc570c0) //120
NHSTUB(PT_PlaySound                           ,0xffc5f328) //122
NHSTUB(PostLogicalEventForNotPowerType        ,0xffc6c5ac) //120
NHSTUB(PostLogicalEventToUI                   ,0xffc6c5f8) //120
NHSTUB(PutInNdFilter                          ,0xffdf7f88) //102
NHSTUB(PutOutNdFilter                         ,0xffdf7fac) //102
NHSTUB(Read                                   ,0xffc0b308) //120
NHSTUB(ReadFastDir                            ,0xffde8ef0) //  4
NHSTUB(Rec2PB                                 ,0xffc6fa28) //104
NHSTUB(RefreshPhysicalScreen                  ,0xffd79ea0) //104
NHSTUB(RenameFile_Fut                         ,0xffc259f0) //116
NHSTUB(Restart                                ,0xffc2aab4) //122
NHSTUB(ScreenLock                             ,0xffd7b04c) //117
NHSTUB(ScreenUnlock                           ,0xffd7b090) //117
NHSTUB(SetAE_ShutterSpeed                     ,0xffe52e90) //102
NHSTUB(SetAutoShutdownTime                    ,0xffc6cdf0) //120
NHSTUB(SetCurrentCaptureModeType              ,0xffc7310c) //120
NHSTUB(SetFileAttributes                      ,0xffc26404) //  3
NHSTUB(SetFileTimeStamp                       ,0xffc263a8) //  4
NHSTUB(SetLogicalEventActive                  ,0xffc6caf4) //120
NHSTUB(SetParameterData                       ,0xffd2f014) //101
NHSTUB(SetPropertyCase                        ,0xffc69374) //102
NHSTUB(SetScriptMode                          ,0xffc6cb44) //120
NHSTUB(SleepTask                              ,0xffc29160) //120
NHSTUB(TakeSemaphore                          ,0xffc0f034) //120
NHSTUB(TurnOffBackLight                       ,0xffc77d88) //104
NHSTUB(TurnOnBackLight                        ,0xffc77d70) //104
NHSTUB(TurnOnDisplay                          ,0xffc3f300) //120
NHSTUB(TurnOffDisplay                         ,0xffc3f32c) //120
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xffd1f818) //120
NHSTUB(UnlockAE                               ,0xffc276c4) //120
NHSTUB(UnlockAF                               ,0xffc27590) //120
NHSTUB(UnlockMainPower                        ,0xffc6ccd0) //120
NHSTUB(UnsetZoomForMovie                      ,0xffd35564) //104
NHSTUB(UpdateMBROnFlash                       ,0xffc5113c) //105
NHSTUB(VbattGet                               ,0xffc22be4) //120
NHSTUB(Write                                  ,0xffc2619c) //120
NHSTUB(WriteSDCard                            ,0xffcfc7ac) //108
NHSTUB(_log                                   ,0xffe7f578) //111
NHSTUB(_log10                                 ,0xffe7e4bc) //112
NHSTUB(_pow                                   ,0xffe7e62c) //121
NHSTUB(_sqrt                                  ,0xffe808e0) //  1
NHSTUB(add_ptp_handler                        ,0xffdbd384) //121
NHSTUB(apex2us                                ,0xffd7c39c) //121
NHSTUB(close                                  ,0xffc0b120) //109
NHSTUB(err_init_task                          ,0xffc05f50) //111
NHSTUB(exmem_alloc                            ,0xffc64148) //103
NHSTUB(exmem_free                             ,0xffc641c0) //103
NHSTUB(free                                   ,0xffc04160) //112
NHSTUB(get_nd_value                           ,0xffdf0830) //123
NHSTUB(get_current_nd_value                   ,0xffdf07ec) //122
NHSTUB(kbd_p1_f                               ,0xffc23ba8) //109
NHSTUB(kbd_p1_f_cont                          ,0xffc23bb4) //109
NHSTUB(kbd_p2_f                               ,0xffc2345c) //109
NHSTUB(kbd_read_keys                          ,0xffc23b2c) //109
NHSTUB(kbd_read_keys_r2                       ,0xffc42fb8) //109
NHSTUB(lseek                                  ,0xffc26228) //120
NHSTUB(malloc                                 ,0xffc04104) //112
NHSTUB(memcmp                                 ,0xffc11318) //120
NHSTUB(memcpy                                 ,0xffc2e864) //120
NHSTUB(memset                                 ,0xffd7b3d4) //120
NHSTUB(mkdir                                  ,0xffc265a8) //109
NHSTUB(mktime_ext                             ,0xffc7cba0) //  1
NHSTUB(open                                   ,0xffc0b070) //109
NHSTUB(OpenFastDir                            ,0xffde8d9c) //  4
NHSTUB(closedir                               ,0xffde8d4c) //121
NHSTUB(get_fstype                             ,0xffc51340) //122
NHSTUB(qsort                                  ,0xffe39418) //  4
NHSTUB(rand                                   ,0xffc11420) //121
NHSTUB(realloc                                ,0xffd7b450) //115
NHSTUB(reboot_fw_update                       ,0xffdea764) //106
NHSTUB(set_control_event                      ,0xffc6c814) //111
NHSTUB(srand                                  ,0xffc11414) //122
NHSTUB(stat                                   ,0xffc26270) //109
NHSTUB(strcat                                 ,0xffc7c35c) //  1
NHSTUB(strchr                                 ,0xffc03fe8) //  1
NHSTUB(strcmp                                 ,0xffc112d4) //120
NHSTUB(strcpy                                 ,0xffc112bc) //120
NHSTUB(strftime                               ,0xffc7c5a8) //113
NHSTUB(strlen                                 ,0xffc04034) //120
NHSTUB(strncmp                                ,0xffc03f9c) //  1
NHSTUB(strncpy                                ,0xffc03f60) //  1
NHSTUB(strrchr                                ,0xffc0400c) //  1
NHSTUB(strtol                                 ,0xffc2eb44) //101
NHSTUB(strtolx                                ,0xffc2e948) //109
   DEF(task_CaptSeq                           ,0xffc5919c) //120
   DEF(task_DvlpSeqTask                       ,0xffd11a54) //120
   DEF(task_ExpDrv                            ,0xffc91388) //120
   DEF(task_FileWrite                         ,0xffde39c8) //120
   DEF(task_InitFileModules                   ,0xffc704b4) //120
   DEF(task_MovieRecord                       ,0xffd0c8f8) //120
   DEF(task_PhySw                             ,0xffc2378c) //120
NHSTUB(time                                   ,0xffc6335c) //109
NHSTUB(vsprintf                               ,0xffc11280) //115
NHSTUB(EngDrvRead                             ,0xffc249fc) //102
NHSTUB(PTM_GetCurrentItem                     ,0xffc6d7c4) //105
NHSTUB(CancelHPTimer                          ,0xffc64e80) //119
NHSTUB(SetHPTimerAfterNow                     ,0xffc64d78) //119
NHSTUB(PT_MFOn                                ,0xffc57178) //120
NHSTUB(PT_MFOff                               ,0xffc57188) //120
NHSTUB(GetAdChValue                           ,0xffc409b0) //120
NHSTUB(get_ptp_buf_size                       ,0xffcb98b4) //122
NHSTUB(get_ptp_file_buf                       ,0xffdbed1c) //121
