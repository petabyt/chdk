// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R31 (DRYOS version 2.3, release #0031)
//   Firmware Ver GM1.00B
//   Canon PowerShot A1000 IS

// Values for makefile.inc
//   PLATFORMOSVER = 31
//   PLATFORMID = 12686 (0x318e) // Found @ 0xfffe0130
//   MAXRAMADDR = 0x03ffffff
//   KEYSYS = d4                 // Found @ 0xffff1a9c
//   NEED_ENCODED_DISKBOOT = 1   // Found @ 0xffff1aac

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NSTUB(PT_PlaySound                          ,0xffc48c7c) //102        *** != 0xffc48fbc
//NSTUB(SetAE_ShutterSpeed                    ,0xffe42b88) //102        *** != 0xffe3de6c
//NSTUB(kbd_pwr_off                           ,0xffc3163c) //  2 64%    *** != 0xffc3164c
NSTUB(kbd_pwr_on                              ,0xffc315fc) //  2 82%

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ffc607f4 -> ffc5d1b8 -> ffd2c328 -> ffdfaf9c -> ffec9db0
// Current modemap entry not found in firmware - MODE_SCN_AQUARIUM        16407
// Current modemap entry not found in firmware - MODE_STITCH              33290
// Current modemap entry not found in firmware - MODE_M                   32769
// Current modemap entry not found in firmware - MODE_AV                  32770
// Current modemap entry not found in firmware - MODE_TV                  32771

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x0000f3f8) // Found @0xffc113ec
DEF(physw_run                               ,0x00001be4) // Found @0xffc11064
DEF(physw_sleep_delay                       ,0x00001be2) // Found @0xffc11064
DEF(levent_table                            ,0xffeab474) // Found @0xffeab474
DEF(FlashParamsTable                        ,0xffec9f7c) // Found @0xffec9f7c
DEF(movie_status                            ,0x000050a0) // Found @0xffc47cf8
DEF(canon_menu_active                       ,0x00005480) // Found @0xffc59fb8
DEF(canon_shoot_menu_active                 ,0x00009735) // Found @0xffd3b670
DEF(playrec_mode                            ,0x00005228) // Found @0xffc4ec4c
DEF(zoom_status                             ,0x0000c0a4) // Found @0xffdfc7b0
DEF(some_flag_for_af_scan                   ,0x000085a8) // Found @0xffd0a65c
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 3 int value(s), the first is the zoom focus length.
// there are 8 entries in the table - set NUM_FL to 8
DEF(focus_len_table                         ,0xfffe297c) // Found @0xfffe297c
DEF(zoom_busy                               ,0x00007fdc) // Found @0xffd03034
DEF(focus_busy                              ,0x00007ee4) // Found @0xffcfebb4
DEF(recreview_hold                          ,0x000059e4) // Found @0xffc65b4c

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x10361000; }             // Found @0xffc2ce78
//void *vid_get_viewport_fb()      { return (void*)0x10659de0; }             // Found @0xffe43978
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x4ee8+0x54)); } // Found @0xffc4177c & 0xffc417a8
//char *camera_jpeg_count_str()    { return (char*)0x0004506c; }             // Found @0xffd70d44
//long hook_raw_size()             { return 0x00ec04f0; }                    // Found @0xffe45d1c
//int get_flash_params_count(void) { return 0x77; }                          // Found @0xffd2d3e4

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffe75208, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x00040000 // Found @0xffe75214, levent 0x902
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 1, KEY_POWER           ,0x00004000 }, // Found @0xffe750c4, levent 0x600 (uses inverted logic in physw_status)
//    { 1, KEY_PLAYBACK        ,0x02000000 }, // Found @0xffe750e8, levent 0x601 (uses inverted logic in physw_status)
//    { 1, KEY_SHOOT_FULL      ,0xc0000000 }, // Found @0xffe75130, levent 0x01
//    { 1, KEY_SHOOT_FULL_ONLY ,0x80000000 }, // Found @0xffe75130, levent 0x01
//    { 1, KEY_SHOOT_HALF      ,0x40000000 }, // Found @0xffe75124, levent 0x00
//    { 2, KEY_ZOOM_IN         ,0x00000004 }, // Found @0xffe75154, levent 0x02
//    { 2, KEY_ZOOM_OUT        ,0x00000008 }, // Found @0xffe75160, levent 0x03
//    { 2, KEY_UP              ,0x00000010 }, // Found @0xffe7516c, levent 0x04
//    { 2, KEY_DOWN            ,0x00000020 }, // Found @0xffe75178, levent 0x05
//    { 2, KEY_RIGHT           ,0x00000040 }, // Found @0xffe75184, levent 0x07
//    { 2, KEY_LEFT            ,0x00000080 }, // Found @0xffe75190, levent 0x06
//    { 2, KEY_SET             ,0x00000100 }, // Found @0xffe7519c, levent 0x08
//    { 2, KEY_MENU            ,0x00000200 }, // Found @0xffe751a8, levent 0x09
//    { 2, KEY_DISPLAY         ,0x00000400 }, // Found @0xffe751b4, levent 0x0a
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_RAW_ROWPIX    3720 // Found @0xffe3cbe0
//#define CAM_RAW_ROWS      2772 // Found @0xffe3cbe8
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x10000000 // Found @0xffc171b8

// Misc stuff
DEF(ctypes, 0xffe74cee)

// For capt_seq.c
//static long *nrflag = (long*)(0x8598-0x04);  // Found @ ffd0c2d0 & ffd0c2e8

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NSTUB(AllocateMemory                          ,0xffdefe20) //101
NSTUB(AllocateUncacheableMemory               ,0xffc17174) //112
NSTUB(Close                                   ,0xffc13344) //101
NSTUB(CreateTask                              ,0xffc0b8c0) //101
NSTUB(DebugAssert                             ,0xffc0bd98) //111
NSTUB(DeleteDirectory_Fut                     ,0xffc12cd4) //116
NSTUB(DeleteFile_Fut                          ,0xffc12bf0) //112
NSTUB(DoAFLock                                ,0xffc14d9c) //102
NSTUB(EnterToCompensationEVF                  ,0xffc14fec) //104
NSTUB(ExecuteEventProcedure                   ,0xffc55764) //104
NSTUB(ExitFromCompensationEVF                 ,0xffc15030) //104
NSTUB(ExitTask                                ,0xffc0bb50) //101
NSTUB(ExpCtrlTool_StartContiAE                ,0xffc1fa68) //104
NSTUB(ExpCtrlTool_StopContiAE                 ,0xffc1fbac) //104
NSTUB(Fclose_Fut                              ,0xffc12d6c) //101
NSTUB(Feof_Fut                                ,0xffc12f58) //  1
NSTUB(Fflush_Fut                              ,0xffc12f94) //  1
NSTUB(Fgets_Fut                               ,0xffc12ec0) //  1
NSTUB(Fopen_Fut                               ,0xffc12d2c) //101
NSTUB(Fread_Fut                               ,0xffc12e18) //101
NSTUB(FreeMemory                              ,0xffdefe18) //101
NSTUB(FreeUncacheableMemory                   ,0xffc171b4) //112
NSTUB(Fseek_Fut                               ,0xffc12f0c) //101
NSTUB(Fwrite_Fut                              ,0xffc12e6c) //101
NSTUB(GetBatteryTemperature                   ,0xffc33738) //102
NSTUB(GetCCDTemperature                       ,0xffc336c8) //102
NSTUB(GetCurrentAvValue                       ,0xffd005ec) //102
NSTUB(GetDrive_ClusterSize                    ,0xffc3ffe0) //  1
NSTUB(GetDrive_FreeClusters                   ,0xffc40048) //  1
NSTUB(GetDrive_TotalClusters                  ,0xffc40014) //  1
NSTUB(GetFocusLensSubjectDistance             ,0xffcff6e4) //102
NSTUB(GetFocusLensSubjectDistanceFromLens     ,0xffcff9f0) //  3
NSTUB(GetKbdState                             ,0xffc315c8) //109
NSTUB(GetMemInfo                              ,0xffc03c28) //115
NSTUB(GetOpticalTemperature                   ,0xffc337a8) //102
NSTUB(GetParameterData                        ,0xffd2d3a4) //101
NSTUB(GetPropertyCase                         ,0xffc594cc) //102
NSTUB(GetSystemTime                           ,0xffdefe78) //101
NSTUB(GetVRAMHPixelsSize                      ,0xffca2420) //102
NSTUB(GetVRAMVPixelsSize                      ,0xffca242c) //102
NSTUB(GetZoomLensCurrentPoint                 ,0xffd033a4) //102
NSTUB(GetZoomLensCurrentPosition              ,0xffde9db0) //102
NSTUB(GiveSemaphore                           ,0xffc0b81c) //112
NSTUB(IsStrobeChargeCompleted                 ,0xffc8b28c) //102
NSTUB(LEDDrive                                ,0xffc30c9c) //103
NSTUB(LocalTime                               ,0xffc53768) //115
NSTUB(LockMainPower                           ,0xffc5cdd0) //103
NSTUB(Lseek                                   ,0xffc13484) //101
NSTUB(MakeDirectory_Fut                       ,0xffc12c64) //116
NSTUB(MoveFocusLensToDistance                 ,0xffe403bc) //102
NSTUB(MoveIrisWithAv                          ,0xffdec64c) //102
NSTUB(MoveZoomLensWithPoint                   ,0xffdecbd8) //102
NSTUB(NewTaskShell                            ,0xffc58f74) //103
NSTUB(Open                                    ,0xffc1331c) //101
NSTUB(PB2Rec                                  ,0xffc5e804) //104
NSTUB(PT_MoveDigitalZoomToWide                ,0xffc49094) //102
NSTUB(PT_MoveOpticalZoomAt                    ,0xffc4906c) //102
NSTUB(PostLogicalEventForNotPowerType         ,0xffc5c410) //103
NSTUB(PostLogicalEventToUI                    ,0xffc5c45c) //103
NSTUB(PutInNdFilter                           ,0xffdeca3c) //102
NSTUB(PutOutNdFilter                          ,0xffdeca60) //102
NSTUB(Read                                    ,0xffc0a138) //101
NSTUB(ReadFastDir                             ,0xffddc2b4) //  1
NSTUB(Rec2PB                                  ,0xffc5e858) //104
NSTUB(RefreshPhysicalScreen                   ,0xffd7a3c0) //104
NSTUB(Remove                                  ,0xffc1338c) //  1
NSTUB(RenameFile_Fut                          ,0xffc12b9c) //  1
NSTUB(Restart                                 ,0xffc189ec) //106
NSTUB(SetAutoShutdownTime                     ,0xffc5ce44) //103
NSTUB(SetCurrentCaptureModeType               ,0xffc634f8) //101
NSTUB(SetFileAttributes                       ,0xffc13670) //  1
NSTUB(SetFileTimeStamp                        ,0xffc13620) //  1
NSTUB(SetLogicalEventActive                   ,0xffc5cb4c) //101
NSTUB(SetParameterData                        ,0xffd2d314) //101
NSTUB(SetPropertyCase                         ,0xffc593c4) //102
NSTUB(SetScriptMode                           ,0xffc5cb9c) //101
NSTUB(SleepTask                               ,0xffc16ff8) //101
NSTUB(TakeSemaphore                           ,0xffc0b74c) //101
NSTUB(TurnOffBackLight                        ,0xffc67e6c) //104
NSTUB(TurnOnBackLight                         ,0xffc67e54) //104
NSTUB(UIFS_WriteFirmInfoToFile                ,0xffd2048c) //103
NSTUB(UnlockAF                                ,0xffc14dd4) //102
NSTUB(UnlockMainPower                         ,0xffc5cd24) //103
NSTUB(UnsetZoomForMovie                       ,0xffd32980) //104
NSTUB(UpdateMBROnFlash                        ,0xffc3fe20) //105
NSTUB(VbattGet                                ,0xffc10314) //103
NSTUB(Write                                   ,0xffc133f0) //101
NSTUB(WriteSDCard                             ,0xffcf4e38) //108
NSTUB(_log                                    ,0xffe72af4) //111
NSTUB(_log10                                  ,0xffe71a38) //112
NSTUB(_pow                                    ,0xffe71ba8) //114
NSTUB(_sqrt                                   ,0xffe73e5c) //  1
NSTUB(add_ptp_handler                         ,0xffdab87c) //  1
NSTUB(apex2us                                 ,0xffd7b3dc) //  4
NSTUB(close                                   ,0xffc09f50) //  1
NSTUB(closedir                                ,0xffddc384) //  1
NSTUB(err_init_task                           ,0xffc04e84) //111
NSTUB(exmem_alloc                             ,0xffc53f68) //103
NSTUB(free                                    ,0xffc03a80) //112
NSTUB(kbd_p1_f                                ,0xffc114f0) //109
NSTUB(kbd_p1_f_cont                           ,0xffc114fc) //109
NSTUB(kbd_p2_f                                ,0xffc10d04) //109
NSTUB(kbd_read_keys                           ,0xffc113ec) //109
NSTUB(kbd_read_keys_r2                        ,0xffc310b4) //109
NSTUB(lseek                                   ,0xffc13484) //101
NSTUB(malloc                                  ,0xffc039ac) //112
NSTUB(memcmp                                  ,0xffc0d8b4) //101
NSTUB(memcpy                                  ,0xffc6ce5c) //101
NSTUB(memset                                  ,0xffd7a714) //101
NSTUB(mkdir                                   ,0xffc136e8) //109
NSTUB(mktime_ext                              ,0xffc6d6c8) //  1
NSTUB(open                                    ,0xffc09ea0) //  1
NSTUB(OpenFastDir                             ,0xffddc220) //  1
NSTUB(qsort                                   ,0xffe2bbec) //  1
NSTUB(rand                                    ,0xffc0d9bc) //  1
NSTUB(read                                    ,0xffc0a138) //101
NSTUB(reboot_fw_update                        ,0xffde0b88) //106
NSTUB(set_control_event                       ,0xffc5c898) //  1
NSTUB(srand                                   ,0xffc0d9b0) //  1
NSTUB(stat                                    ,0xffc13550) //  1
NSTUB(strcat                                  ,0xffc6cc70) //  1
NSTUB(strchr                                  ,0xffc6ccf8) //  1
NSTUB(strcmp                                  ,0xffc0d84c) //101
NSTUB(strcpy                                  ,0xffc0d834) //101
NSTUB(strftime                                ,0xffc6d0d0) //  1
NSTUB(strlen                                  ,0xffc0d890) //101
NSTUB(strncmp                                 ,0xffc6ccac) //  1
NSTUB(strncpy                                 ,0xffc1cb54) //  1
NSTUB(strrchr                                 ,0xffd7a6ec) //  1
NSTUB(strtol                                  ,0xffc1cd8c) //101
NSTUB(strtolx                                 ,0xffc1cb90) //109
  DEF(task_CaptSeq                            ,0xffc4b22c) //107
  DEF(task_ExpDrv                             ,0xffc84248) //110
  DEF(task_InitFileModules                    ,0xffc60680) //107
  DEF(task_MovieRecord                        ,0xffc47f5c) //107
  DEF(task_PhySw                              ,0xffc11060) //107
NSTUB(time                                    ,0xffc5361c) //109
NSTUB(vsprintf                                ,0xffc0d7f8) //115
NSTUB(write                                   ,0xffc133f0) //101
