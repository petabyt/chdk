// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R52 (DRYOS version 2.3, release #0052)
//   Firmware Ver GM1.00A   // Found @ 0xff0cb588, "GM1.00A" @ 0xff0cb595
//   Firmware build timestamp: Feb 28 2013 12:00:21
//   Canon PowerShot N

// Values for makefile.inc
//   PLATFORMOSVER = 52
//   PLATFORMID = 12894 (0x325e) // Found @ 0xfff40040
//   MAXRAMADDR = 0x0fffffff
//   MEMISOSTART = 0x002f8b2c
//   KEYSYS = d4d                // Found @ 0xffff3c38
//   NEED_ENCODED_DISKBOOT = 10   // Found @ 0xffff3c48

// Note, ROM copied to RAM :- from 0xff8e9e9c, to 0x00685000, len 44551 words.
//   ARAM_HEAP_START = 0x5ce000  // Found @ 0xff2490b8
//   ARAM_HEAP_SIZE  = 0x22000   // Found @ 0xff24907c

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
NHSTUB(DeleteFile_Fut                         ,0xff034bb4) //  1 90%
// ERROR: MakeDirectory_Fut is not found.                  //--- ---    *** != 0xff0356c4
// ERROR: RefreshPhysicalScreen is not found.              //--- ---    *** != 0xff0399f8

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff3f2834 -> ff899458
// Mode 33339 in firmware but not in current modemap
// Mode 32784 in firmware but not in current modemap
// Mode 33334 in firmware but not in current modemap
// Mode 33295 in firmware but not in current modemap
// Current modemap entry not found in firmware - MODE_VIDEO_SPEED         33796
// Current modemap entry not found in firmware - MODE_VIDEO_STD           33792

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00040b64) // Found @0xff032410
DEF(physw_run                               ,0x00001e28) // Found @0xff031f64
DEF(physw_sleep_delay                       ,0x00001e30) // Found @0xff031f64
DEF(levent_table                            ,0xff666ac0) // Found @0xff666ac0
DEF(FlashParamsTable                        ,0xff899680) // Found @0xff899680
DEF(movie_status                            ,0x0000a5f4) // Found @0xff2398bc
DEF(video_compression_rate                  ,0x0000a624) // Found @0xff23ab78
DEF(full_screen_refresh                     ,0x0000b0f0) // Found @0xff2591a8
DEF(canon_menu_active                       ,0x0000418c) // Found @0xff0d4eb0
DEF(canon_shoot_menu_active                 ,0x0000cedd) // Found @0xff2d5d78
DEF(playrec_mode                            ,0x00003ba4) // Found @0xff0c04bc
DEF(zoom_status                             ,0x0000e9a0) // Found @0xff35a74c
DEF(zoom_busy                               ,0x0000a488) // Found @0xff234188
DEF(focus_busy                              ,0x0000a324) // Found @0xff22f4c4
DEF(recreview_hold                          ,0x00002db4) // Found @0xff08a244
// Camera has 2 RAW buffers @ 0x44000000 & 0x4adb23c0
//  Note: active buffer --> raw_buffers[active_raw_buffer]
//        other buffer  --> raw_buffers[active_raw_buffer^1]
DEF(raw_buffers                             ,0xff60a0d0) // Found @0xff60a0d0
DEF(active_raw_buffer                       ,0x00003af4) // Found @0xff0bc0b4
DEF(fileio_semaphore                        ,0x000037dc) // Found @0xff0aaa94
DEF_CONST(uiprop_count                      ,0x00000083) // Found @0xff24f688

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x406c5000; }             // Found @0xff08d5d8
//void *vid_get_viewport_fb()      { return (void*)0x4081ab80; }             // Found @0xff4b7ba4
DEF(jpeg_count_str                          ,0x00220c20) // Found @0xff2c1778
//char *camera_jpeg_count_str()    { return (char*)0x00220c20; }             // Found @0xff2c1778
//int get_flash_params_count(void) { return 0x91; }                          // Found @0xff25006c

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define USB_MASK            0x10000000 // Found @0xff5bdc30, levent 0x202
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_POWER           ,0x00100000 }, // Found @0xff5bdba8, levent 0x100
//    { 2, KEY_SHOOT_FULL      ,0x00000030 }, // Found @0xff5bdbb8, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000020 }, // Found @0xff5bdbb8, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00000010 }, // Found @0xff5bdbb0, levent 0x00
//    { 2, KEY_UP              ,0x00000100 }, // Found @0xff5bdbc0, levent 0x04
//    { 2, KEY_ZOOM_OUT        ,0x00000200 }, // Found @0xff5bdbc8, levent 0x03
//    { 2, KEY_PLAYBACK        ,0x00010000 }, // Found @0xff5bdbd8, levent 0x101
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#define CAM_RAW_ROWPIX    4176 // Found @0xff20165c
//#define CAM_RAW_ROWS      3062 // Found @0xff201668
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff03a120
//#define CAM_DATE_FOLDER_NAMING 0x080 // Found @0xff3a8cd4 (pass as 3rd param to GetImageFolder)
//#define PARAM_CAMERA_NAME 3 // Found @0xff89894c

// Misc stuff
DEF(ctypes, 0xff5bac84)

// LED table init @ 0xff1c050c
// LED #1: unknown (index: 0x80000001), offset 0x4

// For capt_seq.c
DEF(_nrflag,0xdec0) // Found @ ff2ff5f4 (0xdec0) & ff2ff630 (+0x00)
//static long *nrflag = (long*)(0xdec0+0x00);  // Found @ ff2ff5f4 & ff2ff630
//#define NR_AUTO (0)                          // have to explictly reset value back to 0 to enable auto

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NHSTUB(AllocateUncacheableMemory              ,0xff03a0d8) //112
NHSTUB(Close                                  ,0xff035228) //120
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
NHSTUB(GetCurrentAvValue                      ,0xff23143c) //120
NHSTUB(GetDrive_ClusterSize                   ,0xff0ac104) //122
NHSTUB(GetDrive_FreeClusters                  ,0xff0ac8e4) //119
NHSTUB(GetDrive_TotalClusters                 ,0xff0ac8bc) //122
NHSTUB(GetFocusLensSubjectDistance            ,0xff2305f4) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff230988) //  3
NHSTUB(GetImageFolder                         ,0xff209084) //122
NHSTUB(GetKbdState                            ,0xff092fcc) //109
NHSTUB(GetMemInfo                             ,0xff0052c4) //115
NHSTUB(GetOpticalTemperature                  ,0xff095dcc) //120
NHSTUB(GetParameterData                       ,0xff25002c) //101
NHSTUB(GetPropertyCase                        ,0xff0cc99c) //101
NHSTUB(GetSystemTime                          ,0xff3ef940) //120
NHSTUB(GetVRAMHPixelsSize                     ,0xff078240) //120
NHSTUB(GetVRAMVPixelsSize                     ,0xff07824c) //120
NHSTUB(GetZoomLensCurrentPoint                ,0xff2345fc) //120
NHSTUB(GetZoomLensCurrentPosition             ,0xff3da86c) //102
NHSTUB(GiveSemaphore                          ,0x0068aaec) //120
NHSTUB(IsStrobeChargeCompleted                ,0xff14bcac) //102
NHSTUB(LEDDrive                               ,0xff23c49c) //120
NHSTUB(LocalTime                              ,0x006937ec) //115
NHSTUB(LockMainPower                          ,0xff0cf678) //120
NHSTUB(MakeSDCardBootable                     ,0xff0acd68) //105
NHSTUB(MoveFocusLensToDistance                ,0xff4b3718) //102
NHSTUB(MoveIrisWithAv                         ,0xff3eb2d0) //120
NHSTUB(MoveZoomLensWithPoint                  ,0xff3eba0c) //120
NHSTUB(Open                                   ,0xff035160) //120
NHSTUB(PB2Rec                                 ,0xff082af4) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff23d5d8) //102
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff23d5a8) //102
NHSTUB(PT_PlaySound                           ,0xff0df6bc) //122
NHSTUB(PostLogicalEventForNotPowerType        ,0xff0cecdc) //120
NHSTUB(PostLogicalEventToUI                   ,0xff0ced28) //120
NHSTUB(PutInNdFilter                          ,0xff3eb7e4) //102
NHSTUB(PutOutNdFilter                         ,0xff3eb808) //102
NHSTUB(Read                                   ,0xff005d80) //120
NHSTUB(ReadFastDir                            ,0xff3c4520) //115
NHSTUB(Rec2PB                                 ,0xff082b3c) //104
NHSTUB(RenameFile_Fut                         ,0xff034b20) //116
NHSTUB(Restart                                ,0xff03958c) //122
NHSTUB(ScreenLock                             ,0xff0d48e8) //117
NHSTUB(ScreenUnlock                           ,0xff0d493c) //117
NHSTUB(SetAE_ShutterSpeed                     ,0xff4b6a7c) //102
NHSTUB(SetAutoShutdownTime                    ,0xff0cf6ec) //120
NHSTUB(SetCurrentCaptureModeType              ,0xff0dcab0) //120
NHSTUB(SetFileAttributes                      ,0xff03562c) //  6
NHSTUB(SetFileTimeStamp                       ,0xff0355b4) //  6
NHSTUB(SetLogicalEventActive                  ,0xff0cf3e0) //120
NHSTUB(SetParameterData                       ,0xff24ff98) //101
NHSTUB(SetPropertyCase                        ,0xff0cc80c) //101
NHSTUB(SetScriptMode                          ,0xff0cf474) //120
NHSTUB(SleepTask                              ,0x0068c4e8) //120
NHSTUB(TakeSemaphore                          ,0x0068aa1c) //120
NHSTUB(TurnOffBackLight                       ,0xff0defd8) //104
NHSTUB(TurnOnBackLight                        ,0xff0defc0) //104
NHSTUB(TurnOnDisplay                          ,0xff08d9e0) //120
NHSTUB(TurnOffDisplay                         ,0xff08d9f0) //120
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff26ce28) //120
NHSTUB(UnlockAE                               ,0xff036dac) //120
NHSTUB(UnlockAF                               ,0xff036b14) //120
NHSTUB(UnlockMainPower                        ,0xff0cf5cc) //120
NHSTUB(VbattGet                               ,0xff031068) //120
NHSTUB(Write                                  ,0xff03527c) //120
NHSTUB(WriteSDCard                            ,0xff2211a4) //108
NHSTUB(_log                                   ,0x006ac0f8) //111
NHSTUB(_log10                                 ,0x006ac638) //112
NHSTUB(_pow                                   ,0x006ac7b0) //121
NHSTUB(_sqrt                                  ,0x006ae888) //  6
// ALT: NHSTUB(_sqrt, 0xffdf6b58) // 6 27/0
NHSTUB(add_ptp_handler                        ,0xff18a7cc) //121
NHSTUB(apex2us                                ,0xff2f9068) //121
NHSTUB(close                                  ,0xff005bdc) //109
NHSTUB(err_init_task                          ,0xff00432c) //111
NHSTUB(exmem_alloc                            ,0xff0c6e50) //101
NHSTUB(exmem_free                             ,0xff0c6ec8) //101
NHSTUB(free                                   ,0xff002efc) //112
NHSTUB(kbd_p1_f                               ,0xff032460) //109
NHSTUB(kbd_p1_f_cont                          ,0xff03246c) //109
NHSTUB(kbd_p2_f                               ,0xff031bfc) //109
NHSTUB(kbd_read_keys                          ,0xff032410) //109
NHSTUB(kbd_read_keys_r2                       ,0xff092a5c) //109
NHSTUB(lseek                                  ,0xff035444) //120
NHSTUB(malloc                                 ,0xff002ea4) //112
NHSTUB(memcmp                                 ,0xff00b988) //120
NHSTUB(memcpy                                 ,0xff03ab64) //120
NHSTUB(memset                                 ,0xff0e3bf4) //120
NHSTUB(mkdir                                  ,0xff0356c4) //121
NHSTUB(mktime_ext                             ,0xff0e309c) //  1
NHSTUB(open                                   ,0xff005b2c) //109
NHSTUB(OpenFastDir                            ,0xff3c43cc) //115
NHSTUB(closedir                               ,0xff3c437c) //121
NHSTUB(get_fstype                             ,0xff0ac080) //122
NHSTUB(qsort                                  ,0xff2de0a8) //  6
NHSTUB(rand                                   ,0xff0e3af8) //121
NHSTUB(realloc                                ,0xff2de108) //115
NHSTUB(reboot_fw_update                       ,0xff3eefb4) //106
NHSTUB(set_control_event                      ,0xff0cf050) //111
NHSTUB(srand                                  ,0xff0e3aec) //122
NHSTUB(stat                                   ,0xff03548c) //109
NHSTUB(strcat                                 ,0xff0e3b28) //  1
NHSTUB(strchr                                 ,0xff002d70) //  1
NHSTUB(strcmp                                 ,0xff00ba84) //120
NHSTUB(strcpy                                 ,0xff00b970) //120
NHSTUB(strftime                               ,0xff0e30e8) //113
NHSTUB(strlen                                 ,0xff002dbc) //120
NHSTUB(strncmp                                ,0xff002d24) //  1
NHSTUB(strncpy                                ,0xff002ce8) //  1
NHSTUB(strrchr                                ,0xff002d94) //  1
NHSTUB(strtol                                 ,0xff03ab50) //101
NHSTUB(strtolx                                ,0xff03a954) //109
   DEF(task_CaptSeq                           ,0xff0b82ec) //120
   DEF(task_ExpDrv                            ,0xff12a2f4) //120
   DEF(task_FileWrite                         ,0xff3c0680) //120
   DEF(task_InitFileModules                   ,0xff0834f8) //120
   DEF(task_MovieRecord                       ,0xff23b098) //120
   DEF(task_PhySw                             ,0xff031f60) //120
   DEF(task_TouchPanel                        ,0xff0974a4) //120
   DEF(hook_CreateTask                        ,0x0068ab8c) //105
NHSTUB(time                                   ,0x00693c94) //119
NHSTUB(vsprintf                               ,0xff00b820) //115
NHSTUB(EngDrvRead                             ,0xff033330) //102
NHSTUB(PTM_GetCurrentItem                     ,0xff0d0008) //105
NHSTUB(CancelHPTimer                          ,0xff0c7b70) //119
NHSTUB(SetHPTimerAfterNow                     ,0xff0c7a68) //119
NHSTUB(SS_MFOn                                ,0xff23d66c) //120
NHSTUB(SS_MFOff                               ,0xff23d67c) //120
NHSTUB(GetAdChValue                           ,0xff08eb50) //120
