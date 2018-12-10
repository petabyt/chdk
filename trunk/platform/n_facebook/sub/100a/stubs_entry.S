// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R52 (DRYOS version 2.3, release #0052)
//   Firmware Ver GM1.00A   // Found @ 0xff0cb588, "GM1.00A" @ 0xff0cb595
//   Firmware build timestamp: Jul 12 2013 11:24:38
//   Canon PowerShot N

// Values for makefile.inc
//   PLATFORMOSVER = 52
//   PLATFORMID = 12939 (0x328b) // Found @ 0xfff40040
//   MAXRAMADDR = 0x0fffffff
//   MEMISOSTART = 0x002f8aec
//   KEYSYS = d4d                // Found @ 0xffff3c38
//   NEED_ENCODED_DISKBOOT = 10   // Found @ 0xffff3c48
//   ARAM_HEAP_START = 0x5ce000  // Found @ 0xff2490e4
//   ARAM_HEAP_SIZE  = 0x22000   // Found @ 0xff2490a8

// Detected address ranges:
// ROM      0xff000000 - 0xffffffff (16777216 bytes)
// RAM code 0x00685000 - 0x006b081c copied from 0xff8e8f64 ( 178204 bytes)
// RAM data 0x00001900 - 0x0001b640 copied from 0xff8cf224 ( 105792 bytes)

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
NHSTUB(DeleteFile_Fut                         ,0xff034bb4) //  1 90%
// ERROR: MakeDirectory_Fut is not found.                  //--- ---    *** != 0xff0356c4
// ERROR: RefreshPhysicalScreen is not found.              //--- ---    *** != 0xff0399f8

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff3f2588 -> ff8985e0
// Mode 33339 in firmware but not in current modemap
// Mode 32784 in firmware but not in current modemap
// Mode 33334 in firmware but not in current modemap
// Mode 33295 in firmware but not in current modemap

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00040b44) // Found @0xff032410
DEF(physw_run                               ,0x00001e28) // Found @0xff031f64
DEF(physw_sleep_delay                       ,0x00001e30) // Found @0xff031f64
DEF(levent_table                            ,0xff666598) // Found @0xff666598
DEF(FlashParamsTable                        ,0xff898808) // Found @0xff898808
DEF(movie_status                            ,0x0000a5f4) // Found @0xff239904
DEF(video_compression_rate                  ,0x0000a624) // Found @0xff23abc0
DEF(full_screen_refresh                     ,0x0000b0f0) // Found @0xff2591cc
DEF(canon_menu_active                       ,0x0000418c) // Found @0xff0d4eb0
DEF(canon_shoot_menu_active                 ,0x0000cecd) // Found @0xff2d5acc
DEF(playrec_mode                            ,0x00003ba4) // Found @0xff0c04bc
DEF(zoom_status                             ,0x0000e990) // Found @0xff35a4a0
DEF(zoom_busy                               ,0x0000a488) // Found @0xff2341d0
DEF(focus_busy                              ,0x0000a324) // Found @0xff22f50c
DEF(recreview_hold                          ,0x00002db4) // Found @0xff08a244
// Camera has 2 RAW buffers @ 0x44000000 & 0x4adb23c0
//  Note: active buffer --> raw_buffers[active_raw_buffer]
//        other buffer  --> raw_buffers[active_raw_buffer^1]
DEF(raw_buffers                             ,0xff609ba8) // Found @0xff609ba8
DEF(active_raw_buffer                       ,0x00003af4) // Found @0xff0bc0b4
DEF(fileio_semaphore                        ,0x000037dc) // Found @0xff0aaa94
DEF(imager_active                           ,0x000024f8) // Found @0xff072ab8 (0x24f4 + 4)
DEF_CONST(uiprop_count                      ,0x00000083) // Found @0xff24f6b4

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x406c5000; }             // Found @0xff08d5d8
//void *vid_get_viewport_fb()      { return (void*)0x4081ab80; }             // Found @0xff4b7678
DEF(jpeg_count_str                          ,0x00220be0) // Found @0xff2c14cc
//char *camera_jpeg_count_str()    { return (char*)0x00220be0; }             // Found @0xff2c14cc
//int get_flash_params_count(void) { return 0x91; }                          // Found @0xff250098

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define USB_MASK            0x10000000 // Found @0xff5bd708, levent 0x202
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_POWER           ,0x00100000 }, // Found @0xff5bd680, levent 0x100
//    { 2, KEY_SHOOT_FULL      ,0x00000030 }, // Found @0xff5bd690, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000020 }, // Found @0xff5bd690, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00000010 }, // Found @0xff5bd688, levent 0x00
//    { 2, KEY_ZOOM_OUT        ,0x00000100 }, // Found @0xff5bd698, levent 0x04
//    { 2, KEY_ZOOM_IN         ,0x00000200 }, // Found @0xff5bd6a0, levent 0x03
//    { 2, KEY_PLAYBACK        ,0x00010000 }, // Found @0xff5bd6b0, levent 0x101
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#define CAM_RAW_ROWPIX    4176 // Found @0xff2016a4
//#define CAM_RAW_ROWS      3062 // Found @0xff2016b0
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff03a120
//#define CAM_DATE_FOLDER_NAMING 0x080 // Found @0xff3a8a28 (pass as 3rd param to GetImageFolder)
//#define PARAM_CAMERA_NAME 3 // Found @0xff897ad0

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
DEF(ctypes, 0xff5ba758)

// ISR flag: 0x1958, pointer to current task's control block: 0x1954
// pointer to TCB area: 0x19f8, found @ 0xff8eb188

// LED table init @ 0xff1c0554
// LED #1: unknown (index: 0x80000001), offset 0x4

// For capt_seq.c
DEF(_nrflag,0xdeb0) // Found @ ff2ff348 (0xdeb0) & ff2ff384 (+0x00)
//static long *nrflag = (long*)(0xdeb0+0x00);  // Found @ ff2ff348 & ff2ff384
//#define NR_AUTO (0)                          // have to explictly reset value back to 0 to enable auto

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NHSTUB(AllocateUncacheableMemory              ,0xff03a0d8) //112
NHSTUB(Close                                  ,0xff035228) //120
NHSTUB(CreateBinarySemaphore                  ,0x0068a8b0) //115
NHSTUB(CreateTask                             ,0x0068ab8c) //120
NHSTUB(DebugAssert                            ,0x0068b104) //107
NHSTUB(DeleteDirectory_Fut                    ,0xff034c28) //116
NHSTUB(DoAELock                               ,0xff036d88) //120
NHSTUB(DoAFLock                               ,0xff036ae4) //120
NHSTUB(EnterToCompensationEVF                 ,0xff036cf0) //104
NHSTUB(ExecuteEventProcedure                  ,0xff0c8488) //104
NHSTUB(ExitFromCompensationEVF                ,0xff036d34) //104
NHSTUB(ExitTask                               ,0x0068ae1c) //120
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff06b57c) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff06b6e4) //104
NHSTUB(Fclose_Fut                             ,0xff034cc0) //120
NHSTUB(Feof_Fut                               ,0xff034eac) //  1
NHSTUB(Fflush_Fut                             ,0xff034ee8) //  1
NHSTUB(Fgets_Fut                              ,0xff034e14) //  6
NHSTUB(Fopen_Fut                              ,0xff034c80) //120
NHSTUB(Fread_Fut                              ,0xff034d6c) //120
NHSTUB(FreeUncacheableMemory                  ,0xff03a118) //112
NHSTUB(Fseek_Fut                              ,0xff034e60) //120
NHSTUB(Fwrite_Fut                             ,0xff034dc0) //120
NHSTUB(GetBatteryTemperature                  ,0xff095d58) //102
NHSTUB(GetCCDTemperature                      ,0xff095ce4) //102
NHSTUB(GetCurrentAvValue                      ,0xff231484) //120
NHSTUB(GetCurrentShutterSpeed                 ,0xff113930) //120
NHSTUB(GetDrive_ClusterSize                   ,0xff0ac104) //122
NHSTUB(GetDrive_FreeClusters                  ,0xff0ac8e4) //119
NHSTUB(GetDrive_TotalClusters                 ,0xff0ac8bc) //122
NHSTUB(GetFocusLensSubjectDistance            ,0xff23063c) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff2309d0) //  3
NHSTUB(GetImageFolder                         ,0xff2090cc) //122
NHSTUB(GetKbdState                            ,0xff092fcc) //109
NHSTUB(GetMemInfo                             ,0xff0052c4) //115
NHSTUB(GetOpticalTemperature                  ,0xff095dcc) //120
NHSTUB(GetParameterData                       ,0xff250058) //101
NHSTUB(GetPropertyCase                        ,0xff0cc99c) //101
NHSTUB(GetSystemTime                          ,0xff3ef694) //120
NHSTUB(GetVRAMHPixelsSize                     ,0xff078240) //120
NHSTUB(GetVRAMVPixelsSize                     ,0xff07824c) //120
NHSTUB(GetZoomLensCurrentPoint                ,0xff234644) //120
NHSTUB(GetZoomLensCurrentPosition             ,0xff3da5c0) //102
NHSTUB(GiveSemaphore                          ,0x0068aaec) //120
NHSTUB(IsStrobeChargeCompleted                ,0xff14bca8) //102
NHSTUB(LEDDrive                               ,0xff23c4c8) //120
NHSTUB(LocalTime                              ,0x006937ec) //115
NHSTUB(LockMainPower                          ,0xff0cf678) //120
NHSTUB(MakeSDCardBootable                     ,0xff0acd68) //105
NHSTUB(MoveFocusLensToDistance                ,0xff4b31ec) //102
NHSTUB(MoveIrisWithAv                         ,0xff3eb024) //120
NHSTUB(MoveZoomLensWithPoint                  ,0xff3eb760) //120
NHSTUB(Open                                   ,0xff035160) //120
NHSTUB(PB2Rec                                 ,0xff082af4) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff23d604) //102
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff23d5d4) //102
NHSTUB(PT_PlaySound                           ,0xff0df6b8) //122
NHSTUB(PostLogicalEventForNotPowerType        ,0xff0cecdc) //120
NHSTUB(PostLogicalEventToUI                   ,0xff0ced28) //120
NHSTUB(PutInNdFilter                          ,0xff3eb538) //102
NHSTUB(PutOutNdFilter                         ,0xff3eb55c) //102
NHSTUB(Read                                   ,0xff005d80) //120
NHSTUB(ReadFastDir                            ,0xff3c4274) //115
NHSTUB(Rec2PB                                 ,0xff082b3c) //104
NHSTUB(RenameFile_Fut                         ,0xff034b20) //116
NHSTUB(Restart                                ,0xff03958c) //122
NHSTUB(ScreenLock                             ,0xff0d48e8) //117
NHSTUB(ScreenUnlock                           ,0xff0d493c) //117
NHSTUB(SetAE_ShutterSpeed                     ,0xff4b6550) //102
NHSTUB(SetAutoShutdownTime                    ,0xff0cf6ec) //120
NHSTUB(SetCurrentCaptureModeType              ,0xff0dcaac) //120
NHSTUB(SetFileAttributes                      ,0xff03562c) //  6
NHSTUB(SetFileTimeStamp                       ,0xff0355b4) //  6
NHSTUB(SetLogicalEventActive                  ,0xff0cf3e0) //120
NHSTUB(SetParameterData                       ,0xff24ffc4) //101
NHSTUB(SetPropertyCase                        ,0xff0cc80c) //101
NHSTUB(SetScriptMode                          ,0xff0cf474) //120
NHSTUB(SleepTask                              ,0x0068c4e8) //120
NHSTUB(TakeSemaphore                          ,0x0068aa1c) //120
NHSTUB(TurnOffBackLight                       ,0xff0defd4) //104
NHSTUB(TurnOnBackLight                        ,0xff0defbc) //104
NHSTUB(TurnOnDisplay                          ,0xff08d9e0) //120
NHSTUB(TurnOffDisplay                         ,0xff08d9f0) //120
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff26ce4c) //120
NHSTUB(UnlockAE                               ,0xff036dac) //120
NHSTUB(UnlockAF                               ,0xff036b14) //120
NHSTUB(UnlockMainPower                        ,0xff0cf5cc) //120
NHSTUB(VbattGet                               ,0xff031068) //120
NHSTUB(Write                                  ,0xff03527c) //120
NHSTUB(WriteSDCard                            ,0xff2211ec) //108
NHSTUB(_log                                   ,0x006ac0f8) //111
NHSTUB(_log10                                 ,0x006ac638) //112
NHSTUB(_pow                                   ,0x006ac7b0) //121
NHSTUB(_sqrt                                  ,0x006ae888) //  6
// ALT: NHSTUB(_sqrt, 0xffdf6b58) // 6 27/0
NHSTUB(add_ptp_handler                        ,0xff18a7c8) //121
NHSTUB(apex2us                                ,0xff2f8dbc) //121
NHSTUB(close                                  ,0xff005bdc) //109
NHSTUB(err_init_task                          ,0xff00432c) //111
NHSTUB(exmem_alloc                            ,0xff0c6e50) //101
NHSTUB(exmem_free                             ,0xff0c6ec8) //101
NHSTUB(free                                   ,0xff002efc) //112
NHSTUB(get_nd_value                           ,0xff3d811c) //123
NHSTUB(get_current_nd_value                   ,0xff3d80bc) //122
NHSTUB(kbd_p1_f                               ,0xff032460) //109
NHSTUB(kbd_p1_f_cont                          ,0xff03246c) //109
NHSTUB(kbd_p2_f                               ,0xff031bfc) //109
NHSTUB(kbd_read_keys                          ,0xff032410) //109
NHSTUB(kbd_read_keys_r2                       ,0xff092a5c) //109
NHSTUB(lseek                                  ,0xff035444) //120
NHSTUB(malloc                                 ,0xff002ea4) //112
NHSTUB(memcmp                                 ,0xff00b988) //120
NHSTUB(memcpy                                 ,0xff03ab64) //120
NHSTUB(memset                                 ,0xff0e3bf0) //120
NHSTUB(mkdir                                  ,0xff0356c4) //121
NHSTUB(mktime_ext                             ,0xff0e3098) //  1
NHSTUB(open                                   ,0xff005b2c) //109
NHSTUB(OpenFastDir                            ,0xff3c4120) //115
NHSTUB(closedir                               ,0xff3c40d0) //121
NHSTUB(get_fstype                             ,0xff0ac080) //122
NHSTUB(qsort                                  ,0xff2dddfc) //  6
NHSTUB(rand                                   ,0xff0e3af4) //121
NHSTUB(realloc                                ,0xff2dde5c) //115
NHSTUB(reboot_fw_update                       ,0xff3eed08) //106
NHSTUB(set_control_event                      ,0xff0cf050) //111
NHSTUB(srand                                  ,0xff0e3ae8) //122
NHSTUB(stat                                   ,0xff03548c) //109
NHSTUB(strcat                                 ,0xff0e3b24) //  1
NHSTUB(strchr                                 ,0xff002d70) //  1
NHSTUB(strcmp                                 ,0xff00ba84) //120
NHSTUB(strcpy                                 ,0xff00b970) //120
NHSTUB(strftime                               ,0xff0e30e4) //113
NHSTUB(strlen                                 ,0xff002dbc) //120
NHSTUB(strncmp                                ,0xff002d24) //  1
NHSTUB(strncpy                                ,0xff002ce8) //  1
NHSTUB(strrchr                                ,0xff002d94) //  1
NHSTUB(strtol                                 ,0xff03ab50) //101
NHSTUB(strtolx                                ,0xff03a954) //109
   DEF(task_CaptSeq                           ,0xff0b82ec) //120
   DEF(task_DvlpSeqTask                       ,0xff240e60) //120
   DEF(task_ExpDrv                            ,0xff12a2f0) //120
   DEF(task_FileWrite                         ,0xff3c03d4) //120
   DEF(task_InitFileModules                   ,0xff0834f8) //120
   DEF(task_MovieRecord                       ,0xff23b0e0) //120
   DEF(task_PhySw                             ,0xff031f60) //120
   DEF(task_TouchPanel                        ,0xff0974a4) //120
   DEF(hook_CreateTask                        ,0x0068ab8c) //105
NHSTUB(time                                   ,0x00693c94) //119
NHSTUB(vsprintf                               ,0xff00b820) //115
NHSTUB(EngDrvRead                             ,0xff033330) //102
NHSTUB(PTM_GetCurrentItem                     ,0xff0d0008) //105
NHSTUB(DisableISDriveError                    ,0xff3ec25c) //120
NHSTUB(CancelHPTimer                          ,0xff0c7b70) //119
NHSTUB(SetHPTimerAfterNow                     ,0xff0c7a68) //119
NHSTUB(SS_MFOn                                ,0xff23d698) //120
NHSTUB(SS_MFOff                               ,0xff23d6a8) //120
NHSTUB(GetAdChValue                           ,0xff08eb50) //120
