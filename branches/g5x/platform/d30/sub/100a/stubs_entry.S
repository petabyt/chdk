// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R50 (DRYOS version 2.3, release #0050)
//   Firmware Ver GM1.00A   // Found @ 0xff079358, "GM1.00A" @ 0xff079365
//   Firmware build timestamp: Jan 20 2014 19:08:20
//   Canon PowerShot D30

// Values for makefile.inc
//   PLATFORMOSVER = 50
//   PLATFORMID = 12932 (0x3284) // Found @ 0xfff40040
//   MAXRAMADDR = 0x07ffffff
//   MEMISOSTART = 0x00171710
//   KEYSYS = d4c                // Found @ 0xffff39e0
//   NEED_ENCODED_DISKBOOT = 8   // Found @ 0xffff39f0
//   ARAM_HEAP_START = 0x3ce000  // Found @ 0xff18cce8
//   ARAM_HEAP_SIZE  = 0x22000   // Found @ 0xff18ccac

// Detected address ranges:
// ROM      0xff000000 - 0xffffffff (16777216 bytes)
// RAM code 0x00471000 - 0x0048078c copied from 0xff4adcd0 (  63372 bytes)
// RAM data 0x00001900 - 0x0000fcbc copied from 0xff49f914 (  58300 bytes)

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NHSTUB(DeleteFile_Fut                       ,0xff020a70) //  1 90%        == 0xff020a70
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff1734c0) //  3 90%
//NHSTUB(LEDDrive                             ,0xff17e520) //120        *** != 0xff04bcf0
// ERROR: MakeDirectory_Fut is not found.                  //--- ---    *** != 0xff021580
//NHSTUB(RefreshPhysicalScreen                ,0xff09813c) //104        *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff2fe358 -> ff47c350
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00033df4) // Found @0xff01e874
DEF(physw_run                               ,0x00001c30) // Found @0xff01e424
DEF(physw_sleep_delay                       ,0x00001c38) // Found @0xff01e424
DEF(levent_table                            ,0xff412628) // Found @0xff412628
DEF(FlashParamsTable                        ,0xff47c5c0) // Found @0xff47c5c0
DEF(movie_status                            ,0x00006e04) // Found @0xff17ae10
DEF(video_compression_rate                  ,0x00006e44) // Found @0xff17c800
DEF(full_screen_refresh                     ,0x00009bdc) // Found @0xff227038
DEF(canon_menu_active                       ,0x00003244) // Found @0xff07b33c
DEF(canon_shoot_menu_active                 ,0x00008581) // Found @0xff1cc0e4
DEF(playrec_mode                            ,0x00002f78) // Found @0xff06e850
DEF(zoom_status                             ,0x0000d254) // Found @0xff300798
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 2 int value(s), the first is the zoom focus length.
// there are 129 entries in the table - set NUM_FL to 129
DEF(focus_len_table                         ,0xfff4abd8) // Found @0xfff4abd8
DEF(zoom_busy                               ,0x00006d0c) // Found @0xff176c9c
DEF(focus_busy                              ,0x00006b9c) // Found @0xff172194
DEF(recreview_hold                          ,0x000038e0) // Found @0xff08b7f0
// Palette colour tables  found @ 0xff42bb60
DEF(palette_control                         ,0x00009bdc) // Found @0xff226fb4
DEF(active_palette_buffer                   ,0x00009be4) // Found @0xff226fb8
DEF(palette_buffer_ptr                      ,0x00009be8) // Found @0xff227470
DEF(palette_buffer                          ,0x000c1174) // Found @0xff227480
// Offset from start of palette_buffer to color data = 4 (Found @0xff342b24)
DEF(bitmap_buffer                           ,0x00009c20) // Found @0xff22abb4
DEF(active_bitmap_buffer                    ,0x00009c18) // Found @0xff22abb8
DEF(viewport_buffers                        ,0xff3a3014) // Found @0xff03a4d8
DEF(active_viewport_buffer                  ,0x000020dc) // Found @0xff03a194
// Camera has 2 RAW buffers @ 0x4138ae00 & 0x46000000
//  Note: active buffer --> raw_buffers[active_raw_buffer]
//        other buffer  --> raw_buffers[active_raw_buffer^1]
DEF(raw_buffers                             ,0xff3b7c50) // Found @0xff3b7c50
DEF(active_raw_buffer                       ,0x00002ef4) // Found @0xff06b338
DEF(fileio_semaphore                        ,0x00002c2c) // Found @0xff05c134
DEF(imager_active                           ,0x00002010) // Found @0xff036b4c (0x200c + 4)
DEF_CONST(uiprop_count                      ,0x0000008e) // Found @0xff1aabc4

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x40491000; }             // Found @0xff04619c
//void *vid_get_viewport_fb()      { return (void*)0x405e6b80; }             // Found @0xff36129c
DEF(viewport_fb_d                           ,0x00002cdc) // Found 0x2c88 (@0xff05f52c) + 0x54 (@0xff05f564)
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x2c88+0x54)); } // Found @0xff05f52c & 0xff05f564
DEF(jpeg_count_str                          ,0x000c0a08) // Found @0xff21c3bc
//char *camera_jpeg_count_str()    { return (char*)0x000c0a08; }             // Found @0xff21c3bc
//int get_flash_params_count(void) { return 0xa6; }                          // Found @0xff1ab59c

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xff3a378c, levent 0x20a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x04000000 // Found @0xff3a37b4, levent 0x202
//#define USB_IDX             2
//#define BATTCOVER_FLAG      0x00008000 // Found @0xff3a377c, levent 0x205
//#define BATTCOVER_IDX       2
//#define ANALOG_AV_FLAG      0x00200000 // Found @0xff3a3704, levent 0x200 (non-inverted logic)
//#define ANALOG_AV_IDX       1

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 2, KEY_MENU            ,0x00000001 }, // Found @0xff3a370c, levent 0x09
//    { 2, KEY_SET             ,0x00000002 }, // Found @0xff3a3714, levent 0x08
//    { 2, KEY_ZOOM_IN         ,0x00000004 }, // Found @0xff3a371c, levent 0x02
//    { 2, KEY_ZOOM_OUT        ,0x00000008 }, // Found @0xff3a3724, levent 0x03
//    { 2, KEY_LEFT            ,0x00000010 }, // Found @0xff3a372c, levent 0x06
//    { 2, KEY_RIGHT           ,0x00000020 }, // Found @0xff3a3734, levent 0x07
//    { 2, KEY_DOWN            ,0x00000040 }, // Found @0xff3a373c, levent 0x05
//    { 2, KEY_UP              ,0x00000080 }, // Found @0xff3a3744, levent 0x04
//    { 2, KEY_SHOOT_FULL      ,0x00000300 }, // Found @0xff3a3754, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000200 }, // Found @0xff3a3754, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00000100 }, // Found @0xff3a374c, levent 0x00
//    { 2, KEY_PLAYBACK        ,0x00000400 }, // Found @0xff3a375c, levent 0x101
//    { 2, KEY_POWER           ,0x00000800 }, // Found @0xff3a3764, levent 0x100
//    { 2, KEY_VIDEO           ,0x00004000 }, // Found @0xff3a3774, levent 0x1a
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#define CAM_RAW_ROWPIX    4168 // Found @0xff146cf0
//#define CAM_RAW_ROWS      3060 // Found @0xff146cfc
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff02447c
//#define CAM_DATE_FOLDER_NAMING 0x400 // Found @0xff2aefc4 (pass as 3rd param to GetImageFolder)
//#define PARAM_CAMERA_NAME 4 // Found @0xff47b6bc

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
DEF(ctypes, 0xff3a2938)

// ISR flag: 0x1968, pointer to current task's control block: 0x1964
// pointer to TCB area: 0x19f4, found @ 0xff4afe68

// LED table init @ 0xff1234c4
// LED #1: 0xc0220130, offset 0x4
// LED #2: 0xc0223030, offset 0x104

// For capt_seq.c
DEF(_nrflag,0x9d04) // Found @ ff2334e0 (0x9d04) & ff23351c (+0x00)
//static long *nrflag = (long*)(0x9d04+0x00);  // Found @ ff2334e0 & ff23351c
//#define NR_AUTO (0)                          // have to explictly reset value back to 0 to enable auto

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NHSTUB(AllocateUncacheableMemory              ,0xff024434) //112
NHSTUB(Close                                  ,0xff0210e4) //120
NHSTUB(CreateBinarySemaphore                  ,0x004774c8) //115
NHSTUB(CreateTask                             ,0x00476824) //120
NHSTUB(DebugAssert                            ,0x00476afc) //107
NHSTUB(DeleteDirectory_Fut                    ,0xff020ae4) //116
NHSTUB(DoAELock                               ,0xff022f84) //120
NHSTUB(DoAFLock                               ,0xff022c94) //120
NHSTUB(EnterToCompensationEVF                 ,0xff022eec) //104
NHSTUB(ExecuteEventProcedure                  ,0xff076318) //104
NHSTUB(ExitFromCompensationEVF                ,0xff022f30) //104
NHSTUB(ExitTask                               ,0x00476ab4) //120
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff02dae0) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff02dc30) //104
NHSTUB(Fclose_Fut                             ,0xff020b7c) //120
NHSTUB(Feof_Fut                               ,0xff020d68) //  1
NHSTUB(Fflush_Fut                             ,0xff020da4) //  1
NHSTUB(Fgets_Fut                              ,0xff020cd0) //  6
NHSTUB(Fopen_Fut                              ,0xff020b3c) //120
NHSTUB(Fread_Fut                              ,0xff020c28) //120
NHSTUB(FreeUncacheableMemory                  ,0xff024474) //112
NHSTUB(Fseek_Fut                              ,0xff020d1c) //120
NHSTUB(Fwrite_Fut                             ,0xff020c7c) //120
NHSTUB(GetBatteryTemperature                  ,0xff04ffd4) //102
NHSTUB(GetCCDTemperature                      ,0xff04ff60) //102
NHSTUB(GetCurrentAvValue                      ,0xff173fc8) //120
NHSTUB(GetCurrentShutterSpeed                 ,0xff09d800) //120
NHSTUB(GetDrive_ClusterSize                   ,0xff05dd58) //122
NHSTUB(GetDrive_FreeClusters                  ,0xff05ddb0) //119
NHSTUB(GetDrive_TotalClusters                 ,0xff05dd88) //119
NHSTUB(GetFocusLensSubjectDistance            ,0xff173150) //102
NHSTUB(GetImageFolder                         ,0xff1503dc) //122
NHSTUB(GetKbdState                            ,0xff04c758) //109
NHSTUB(GetMemInfo                             ,0xff00509c) //115
NHSTUB(GetOpticalTemperature                  ,0xff050048) //120
NHSTUB(GetParameterData                       ,0xff1ab55c) //101
NHSTUB(GetPropertyCase                        ,0xff07a408) //102
NHSTUB(GetSystemTime                          ,0xff2ee600) //120
NHSTUB(GetVRAMHPixelsSize                     ,0xff03cc90) //120
NHSTUB(GetVRAMVPixelsSize                     ,0xff03cc9c) //120
NHSTUB(GetZoomLensCurrentPoint                ,0xff17711c) //120
NHSTUB(GetZoomLensCurrentPosition             ,0xff2d908c) //102
NHSTUB(GiveSemaphore                          ,0x00477704) //120
NHSTUB(IsStrobeChargeCompleted                ,0xff0ce384) //102
NHSTUB(LocalTime                              ,0x0047b1b8) //115
NHSTUB(LockMainPower                          ,0xff07ff30) //120
NHSTUB(MakeSDCardBootable                     ,0xff05dfd8) //105
NHSTUB(MoveFocusLensToDistance                ,0xff35d2f8) //102
NHSTUB(MoveIrisWithAv                         ,0xff2e8b30) //120
NHSTUB(MoveZoomLensWithPoint                  ,0xff2e9264) //120
NHSTUB(Open                                   ,0xff02101c) //120
NHSTUB(PB2Rec                                 ,0xff083244) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff066784) //120
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff06675c) //120
NHSTUB(PT_PlaySound                           ,0xff07080c) //122
NHSTUB(PostLogicalEventForNotPowerType        ,0xff07f624) //120
NHSTUB(PostLogicalEventToUI                   ,0xff07f670) //120
NHSTUB(PutInNdFilter                          ,0xff2e903c) //102
NHSTUB(PutOutNdFilter                         ,0xff2e9060) //102
NHSTUB(Read                                   ,0xff005b58) //120
NHSTUB(ReadFastDir                            ,0xff2c6788) //115
NHSTUB(Rec2PB                                 ,0xff081938) //104
NHSTUB(RenameFile_Fut                         ,0xff0209dc) //116
NHSTUB(Restart                                ,0xff025c9c) //122
NHSTUB(ScreenLock                             ,0xff09911c) //117
NHSTUB(ScreenUnlock                           ,0xff099180) //117
NHSTUB(SetAE_ShutterSpeed                     ,0xff360414) //102
NHSTUB(SetAutoShutdownTime                    ,0xff07ffa4) //120
NHSTUB(SetCurrentCaptureModeType              ,0xff088fb0) //120
NHSTUB(SetFileAttributes                      ,0xff0214e8) //  6
NHSTUB(SetFileTimeStamp                       ,0xff021470) //  6
NHSTUB(SetLogicalEventActive                  ,0xff07fcac) //120
NHSTUB(SetParameterData                       ,0xff1ab4cc) //101
NHSTUB(SetPropertyCase                        ,0xff07a25c) //102
NHSTUB(SetScriptMode                          ,0xff07fcfc) //120
NHSTUB(SleepTask                              ,0x004779b0) //120
NHSTUB(TakeSemaphore                          ,0x00477634) //120
NHSTUB(TurnOffBackLight                       ,0xff090308) //104
NHSTUB(TurnOnBackLight                        ,0xff0902f0) //104
NHSTUB(TurnOnDisplay                          ,0xff0465b0) //120
NHSTUB(TurnOffDisplay                         ,0xff0465c0) //120
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff197fd4) //120
NHSTUB(UnlockAE                               ,0xff022fa8) //120
NHSTUB(UnlockAF                               ,0xff022ccc) //120
NHSTUB(UnlockMainPower                        ,0xff07fe84) //120
NHSTUB(UnsetZoomForMovie                      ,0xff1bac80) //104
NHSTUB(VbattGet                               ,0xff01c408) //120
NHSTUB(Write                                  ,0xff021138) //120
NHSTUB(WriteSDCard                            ,0xff1656fc) //108
NHSTUB(_log                                   ,0x0047cce0) //111
NHSTUB(_log10                                 ,0x0047d220) //112
NHSTUB(_pow                                   ,0x0047d398) //121
NHSTUB(_sqrt                                  ,0x0047f0e4) //  6
NHSTUB(add_ptp_handler                        ,0xff273090) //121
NHSTUB(apex2us                                ,0xff22d8ec) //121
NHSTUB(close                                  ,0xff0059b4) //109
NHSTUB(err_init_task                          ,0xff00437c) //111
NHSTUB(exmem_alloc                            ,0xff074bc0) //101
NHSTUB(exmem_free                             ,0xff074c38) //101
NHSTUB(free                                   ,0xff002f78) //112
NHSTUB(get_nd_value                           ,0xff2d6d58) //123
NHSTUB(get_current_nd_value                   ,0xff2d6cf8) //122
NHSTUB(kbd_p1_f                               ,0xff01e8c4) //109
NHSTUB(kbd_p1_f_cont                          ,0xff01e8d0) //109
NHSTUB(kbd_p2_f                               ,0xff01e0bc) //109
NHSTUB(kbd_read_keys                          ,0xff01e874) //109
NHSTUB(kbd_read_keys_r2                       ,0xff04c20c) //109
NHSTUB(lseek                                  ,0xff021300) //120
NHSTUB(malloc                                 ,0xff002f20) //112
NHSTUB(memcmp                                 ,0xff00ae6c) //120
NHSTUB(memcpy                                 ,0xff0275c8) //120
NHSTUB(memset                                 ,0xff22b950) //120
NHSTUB(mkdir                                  ,0xff021580) //121
NHSTUB(mktime_ext                             ,0xff09967c) //  1
NHSTUB(open                                   ,0xff005904) //109
NHSTUB(OpenFastDir                            ,0xff2c6634) //115
NHSTUB(closedir                               ,0xff2c65e4) //121
NHSTUB(get_fstype                             ,0xff05ddd0) //122
NHSTUB(qsort                                  ,0xff22b8f0) //  6
NHSTUB(rand                                   ,0xff22b428) //121
NHSTUB(realloc                                ,0xff22b9cc) //115
NHSTUB(reboot_fw_update                       ,0xff2cbb64) //106
NHSTUB(set_control_event                      ,0xff07f96c) //111
NHSTUB(srand                                  ,0xff22b41c) //122
NHSTUB(stat                                   ,0xff021348) //109
NHSTUB(strcat                                 ,0xff099d18) //  1
NHSTUB(strchr                                 ,0xff002dec) //  1
NHSTUB(strcmp                                 ,0xff00af68) //120
NHSTUB(strcpy                                 ,0xff00ae54) //120
NHSTUB(strftime                               ,0xff0996c8) //113
NHSTUB(strlen                                 ,0xff002e38) //120
NHSTUB(strncmp                                ,0xff002da0) //  1
NHSTUB(strncpy                                ,0xff002d64) //  1
NHSTUB(strrchr                                ,0xff002e10) //  1
NHSTUB(strtol                                 ,0xff0275b4) //101
NHSTUB(strtolx                                ,0xff0273b8) //109
   DEF(task_CaptSeq                           ,0xff069390) //120
   DEF(task_DvlpSeqTask                       ,0xff1840c8) //120
   DEF(task_ExpDrv                            ,0xff0b2264) //120
   DEF(task_FileWrite                         ,0xff2c4fe8) //120
   DEF(task_InitFileModules                   ,0xff083a34) //120
   DEF(task_MovieRecord                       ,0xff17d034) //120
   DEF(task_PhySw                             ,0xff01e420) //120
NHSTUB(time                                   ,0x0047b794) //  6
NHSTUB(vsprintf                               ,0xff00ad04) //115
NHSTUB(EngDrvRead                             ,0xff01f86c) //102
NHSTUB(PTM_GetCurrentItem                     ,0xff08069c) //105
NHSTUB(DisableISDriveError                    ,0xff2e9e6c) //120
NHSTUB(CancelHPTimer                          ,0xff075a00) //119
NHSTUB(SetHPTimerAfterNow                     ,0xff0758f8) //119
NHSTUB(PT_MFOn                                ,0xff066834) //120
NHSTUB(PT_MFOff                               ,0xff066844) //120
NHSTUB(GetAdChValue                           ,0xff0479d8) //120
NHSTUB(EnableHDMIPower                        ,0xff04b710) //123
NHSTUB(DisableHDMIPower                       ,0xff04b718) //123
