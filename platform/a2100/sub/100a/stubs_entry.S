// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R31 (DRYOS version 2.3, release #0031)
//   Firmware Ver GM1.00A
//   Canon PowerShot A2100 IS

// Values for makefile.inc
//   PLATFORMOSVER = 31
//   PLATFORMID = 12734 (0x31be) // Found @ 0xfffe0130
//   MAXRAMADDR = 0x03ffffff
//   KEYSYS = d4                 // Found @ 0xffff1d14
//   NEED_ENCODED_DISKBOOT = 2   // Found @ 0xffff1d24

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
NSTUB(kbd_pwr_off                             ,0xffc30bd4) //  2 64%
NSTUB(kbd_pwr_on                              ,0xffc30b94) //  2 82%

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ffc604e0 -> ffc5cf2c -> ffd1bf30 -> ffdff8dc -> ffebdc2c
// Mode 16390 in firmware but not in current modemap
// Mode  2598 in firmware but not in current modemap
// Current modemap entry not found in firmware - MODE_VIDEO_COMPACT        2602
// Current modemap entry not found in firmware - MODE_VIDEO_STD            2600
// Current modemap entry not found in firmware - MODE_LONG_SHUTTER        32774

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x0000c664) // Found @0xffc11a0c
DEF(physw_run                               ,0x00001c24) // Found @0xffc11680
DEF(physw_sleep_delay                       ,0x00001c22) // Found @0xffc11680
DEF(levent_table                            ,0xffe95518) // Found @0xffe95518
DEF(FlashParamsTable                        ,0xffebde00) // Found @0xffebde00
DEF(movie_status                            ,0x00005670) // Found @0xffcf840c
DEF(canon_menu_active                       ,0x00002b78) // Found @0xffc59d6c
DEF(canon_shoot_menu_active                 ,0x0000690d) // Found @0xffd2c9a4
DEF(playrec_mode                            ,0x000028e8) // Found @0xffc4d404
DEF(zoom_status                             ,0x00009938) // Found @0xffe0110c
DEF(some_flag_for_af_scan                   ,0x00005b24) // Found @0xffcfab30
DEF(zoom_busy                               ,0x0000559c) // Found @0xffcf4b10
DEF(focus_busy                              ,0x00005498) // Found @0xffcef9e4
DEF(recreview_hold                          ,0x000030dc) // Found @0xffc657a0

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x403f1000; }             // Found @0xffc2c5cc
//void *vid_get_viewport_fb()      { return (void*)0x4076fcc0; }             // Found @0xffe441f8
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x2628+0x58)); } // Found @0xffc403a8 & 0xffc403e0
//char *camera_jpeg_count_str()    { return (char*)0x0002f55c; }             // Found @0xffd60580
//long hook_raw_size()             { return 0x011e4ee0; }                    // Found @0xffe46760
//int get_flash_params_count(void) { return 0x7a; }                          // Found @0xffd1cfec

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffe7172c, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x00040000 // Found @0xffe71738, levent 0x902
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 1, KEY_SET             ,0x01000000 }, // Found @0xffe71624, levent 0x08
//    { 1, KEY_MENU            ,0x02000000 }, // Found @0xffe71630, levent 0x09
//    { 1, KEY_DISPLAY         ,0x04000000 }, // Found @0xffe7163c, levent 0x0a
//    { 2, KEY_SHOOT_FULL      ,0x0000000c }, // Found @0xffe716a8, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000008 }, // Found @0xffe716a8, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00000004 }, // Found @0xffe7169c, levent 0x00
//    { 2, KEY_ZOOM_IN         ,0x00000010 }, // Found @0xffe716b4, levent 0x02
//    { 2, KEY_ZOOM_OUT        ,0x00000020 }, // Found @0xffe716c0, levent 0x03
//    { 2, KEY_POWER           ,0x00000040 }, // Found @0xffe716cc, levent 0x600 (uses inverted logic in physw_status)
//    { 2, KEY_PLAYBACK        ,0x00000080 }, // Found @0xffe716d8, levent 0x601 (uses inverted logic in physw_status)
//    { 2, KEY_UP              ,0x00000100 }, // Found @0xffe716e4, levent 0x04
//    { 2, KEY_DOWN            ,0x00000200 }, // Found @0xffe716f0, levent 0x05
//    { 2, KEY_RIGHT           ,0x00000400 }, // Found @0xffe716fc, levent 0x07
//    { 2, KEY_LEFT            ,0x00000800 }, // Found @0xffe71708, levent 0x06
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_RAW_ROWPIX    4104 // Found @0xffcc7c70
//#define CAM_RAW_ROWS      3048 // Found @0xffcc7c78
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xffc16edc

// Misc stuff
DEF(ctypes, 0xffe70516)

// For capt_seq.c
//static long *nrflag = (long*)(0x5b10-0x08);  // Found @ ffcfc85c & ffcfc878

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NSTUB(AllocateMemory                          ,0xffdf5d64) //101
NSTUB(AllocateUncacheableMemory               ,0xffc16e98) //112
NSTUB(Close                                   ,0xffc138e0) //101
NSTUB(CreateTask                              ,0xffc0afac) //101
NSTUB(DebugAssert                             ,0xffc0b284) //111
NSTUB(DeleteDirectory_Fut                     ,0xffc13270) //116
NSTUB(DeleteFile_Fut                          ,0xffc1318c) //112
NSTUB(DoAFLock                                ,0xffc14f3c) //102
NSTUB(EnterToCompensationEVF                  ,0xffc14fec) //104
NSTUB(ExecuteEventProcedure                   ,0xffc554e4) //104
NSTUB(ExitFromCompensationEVF                 ,0xffc15030) //104
NSTUB(ExitTask                                ,0xffc0b23c) //101
NSTUB(ExpCtrlTool_StartContiAE                ,0xffc1f8d8) //104
NSTUB(ExpCtrlTool_StopContiAE                 ,0xffc1fa1c) //104
NSTUB(Fclose_Fut                              ,0xffc13308) //101
NSTUB(Feof_Fut                                ,0xffc134f4) //  1
NSTUB(Fflush_Fut                              ,0xffc13530) //  1
NSTUB(Fgets_Fut                               ,0xffc1345c) //  1
NSTUB(Fopen_Fut                               ,0xffc132c8) //101
NSTUB(Fread_Fut                               ,0xffc133b4) //101
NSTUB(FreeMemory                              ,0xffdf5d5c) //101
NSTUB(FreeUncacheableMemory                   ,0xffc16ed8) //112
NSTUB(Fseek_Fut                               ,0xffc134a8) //101
NSTUB(Fwrite_Fut                              ,0xffc13408) //101
NSTUB(GetBatteryTemperature                   ,0xffc32c7c) //102
NSTUB(GetCCDTemperature                       ,0xffc32c08) //102
NSTUB(GetCurrentAvValue                       ,0xffcf179c) //102
NSTUB(GetDrive_ClusterSize                    ,0xffc3ec3c) //  5
NSTUB(GetDrive_FreeClusters                   ,0xffc3ec94) //  5
NSTUB(GetDrive_TotalClusters                  ,0xffc3ec68) //  5
NSTUB(GetFocusLensSubjectDistance             ,0xffcf084c) //102
NSTUB(GetFocusLensSubjectDistanceFromLens     ,0xffcf0c28) //  3
NSTUB(GetKbdState                             ,0xffc30b60) //109
NSTUB(GetMemInfo                              ,0xffc03be4) //115
NSTUB(GetOpticalTemperature                   ,0xffc32cf4) //102
NSTUB(GetParameterData                        ,0xffd1cfac) //101
NSTUB(GetPropertyCase                         ,0xffc59250) //102
NSTUB(GetSystemTime                           ,0xffdf5dbc) //101
NSTUB(GetVRAMHPixelsSize                      ,0xffc959a8) //102
NSTUB(GetVRAMVPixelsSize                      ,0xffc959b4) //102
NSTUB(GetZoomLensCurrentPoint                 ,0xffcf4e88) //102
NSTUB(GetZoomLensCurrentPosition              ,0xffdedca8) //102
NSTUB(GiveSemaphore                           ,0xffc168b4) //112
NSTUB(IsStrobeChargeCompleted                 ,0xffc87128) //102
NSTUB(LEDDrive                                ,0xffc300c0) //103
NSTUB(LocalTime                               ,0xffc531a8) //115
NSTUB(LockMainPower                           ,0xffc5cb44) //103
NSTUB(Lseek                                   ,0xffc13a20) //101
NSTUB(MakeDirectory_Fut                       ,0xffc13200) //116
NSTUB(MoveFocusLensToDistance                 ,0xffe40c28) //102
NSTUB(MoveIrisWithAv                          ,0xffdf2fbc) //102
NSTUB(MoveZoomLensWithPoint                   ,0xffdf3548) //102
NSTUB(NewTaskShell                            ,0xffc58cf4) //103
NSTUB(Open                                    ,0xffc138b8) //101
NSTUB(PB2Rec                                  ,0xffc5e5c4) //104
NSTUB(PT_MoveDigitalZoomToWide                ,0xffc46c90) //102
NSTUB(PT_MoveOpticalZoomAt                    ,0xffc46c68) //102
NSTUB(PT_PlaySound                            ,0xffc468a4) //102
NSTUB(PostLogicalEventForNotPowerType         ,0xffc5c16c) //103
NSTUB(PostLogicalEventToUI                    ,0xffc5c1b8) //103
NSTUB(PutInNdFilter                           ,0xffdf33ac) //102
NSTUB(PutOutNdFilter                          ,0xffdf33d0) //102
NSTUB(Read                                    ,0xffc09ae4) //101
NSTUB(ReadFastDir                             ,0xffde0144) //  1
NSTUB(Rec2PB                                  ,0xffc5f9ac) //104
NSTUB(RefreshPhysicalScreen                   ,0xffd6be30) //104
NSTUB(Remove                                  ,0xffc13928) //  1
NSTUB(RenameFile_Fut                          ,0xffc13138) //  1
NSTUB(Restart                                 ,0xffc185ec) //106
NSTUB(SetAE_ShutterSpeed                      ,0xffe43408) //102
NSTUB(SetAutoShutdownTime                     ,0xffc5cbb8) //103
NSTUB(SetCurrentCaptureModeType               ,0xffc63140) //101
NSTUB(SetFileAttributes                       ,0xffc13c0c) //  1
NSTUB(SetFileTimeStamp                        ,0xffc13bbc) //  1
NSTUB(SetLogicalEventActive                   ,0xffc5c8c0) //101
NSTUB(SetParameterData                        ,0xffd1cf1c) //101
NSTUB(SetPropertyCase                         ,0xffc59148) //102
NSTUB(SetScriptMode                           ,0xffc5c910) //101
NSTUB(SleepTask                               ,0xffc16b1c) //101
NSTUB(TakeSemaphore                           ,0xffc167e4) //101
NSTUB(TurnOffBackLight                        ,0xffc67d2c) //104
NSTUB(TurnOnBackLight                         ,0xffc67d14) //104
NSTUB(UIFS_WriteFirmInfoToFile                ,0xffd0d7dc) //101
NSTUB(UnlockAF                                ,0xffc14f74) //102
NSTUB(UnlockMainPower                         ,0xffc5ca98) //103
NSTUB(UnsetZoomForMovie                       ,0xffd22bf0) //104
NSTUB(UpdateMBROnFlash                        ,0xffc3ea94) //105
NSTUB(VbattGet                                ,0xffc10318) //103
NSTUB(Write                                   ,0xffc1398c) //101
NSTUB(WriteSDCard                             ,0xffce4718) //108
NSTUB(_log                                    ,0xffe6e31c) //111
NSTUB(_log10                                  ,0xffe6d260) //112
NSTUB(_pow                                    ,0xffe6d3d0) //114
NSTUB(_sqrt                                   ,0xffe6f684) //  1
NSTUB(add_ptp_handler                         ,0xffdb1e84) //  3
NSTUB(apex2us                                 ,0xffd6ced4) //  4
NSTUB(close                                   ,0xffc098fc) //  1
NSTUB(closedir                                ,0xffde0214) //  1
NSTUB(err_init_task                           ,0xffc04e2c) //111
NSTUB(exmem_alloc                             ,0xffc53ddc) //103
NSTUB(free                                    ,0xffc03a3c) //112
NSTUB(kbd_p1_f                                ,0xffc11a90) //109
NSTUB(kbd_p1_f_cont                           ,0xffc11a9c) //109
NSTUB(kbd_p2_f                                ,0xffc1134c) //109
NSTUB(kbd_read_keys                           ,0xffc11a0c) //109
NSTUB(kbd_read_keys_r2                        ,0xffc304dc) //109
NSTUB(lseek                                   ,0xffc13a20) //101
NSTUB(malloc                                  ,0xffc03968) //112
NSTUB(memcmp                                  ,0xffc0cc60) //101
NSTUB(memcpy                                  ,0xffc6ba00) //101
NSTUB(memset                                  ,0xffd6c1bc) //101
NSTUB(mkdir                                   ,0xffc13c84) //109
NSTUB(mktime_ext                              ,0xffc6c26c) //  1
NSTUB(open                                    ,0xffc0984c) //  1
NSTUB(OpenFastDir                             ,0xffde00b0) //  1
NSTUB(qsort                                   ,0xffe27428) //  1
NSTUB(rand                                    ,0xffc0cd68) //  1
NSTUB(read                                    ,0xffc09ae4) //101
NSTUB(reboot_fw_update                        ,0xffde3c28) //106
NSTUB(set_control_event                       ,0xffc5c5f4) //111
NSTUB(srand                                   ,0xffc0cd5c) //  1
NSTUB(stat                                    ,0xffc13aec) //  1
NSTUB(strcat                                  ,0xffc6b814) //  1
NSTUB(strchr                                  ,0xffc6b89c) //  1
NSTUB(strcmp                                  ,0xffc0cbf8) //101
NSTUB(strcpy                                  ,0xffc0cbe0) //101
NSTUB(strftime                                ,0xffc6bc74) //  1
NSTUB(strlen                                  ,0xffc0cc3c) //101
NSTUB(strncmp                                 ,0xffc6b850) //  1
NSTUB(strncpy                                 ,0xffc1c6d4) //  1
NSTUB(strrchr                                 ,0xffd6c194) //  1
NSTUB(strtol                                  ,0xffc1c90c) //101
NSTUB(strtolx                                 ,0xffc1c710) //109
  DEF(task_CaptSeq                            ,0xffc48f48) //107
  DEF(task_ExpDrv                             ,0xffc7ddf0) //110
  DEF(task_InitFileModules                    ,0xffc6036c) //107
  DEF(task_MovieRecord                        ,0xffcf8660) //107
  DEF(task_PhySw                              ,0xffc1167c) //107
NSTUB(time                                    ,0xffc5305c) //109
NSTUB(vsprintf                                ,0xffc0cba4) //115
NSTUB(write                                   ,0xffc1398c) //101
