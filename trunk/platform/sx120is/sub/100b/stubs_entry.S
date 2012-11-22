// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R39 (DRYOS version 2.3, release #0039)
//   Firmware Ver GM1.00B
//   Canon PowerShot SX120 IS

// Values for makefile.inc
//   PLATFORMOSVER = 39
//   PLATFORMID = 12768 (0x31e0) // Found @ 0xfffe0130
//   MAXRAMADDR = 0x03ffffff
//   KEYSYS = d4                 // Found @ 0xffff1d0c
//   NEED_ENCODED_DISKBOOT = 3   // Found @ 0xffff1d1c

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NSTUB(GetDrive_ClusterSize                  ,0xffc4591c) //  5        *** != 0xffc45918
//NSTUB(GetDrive_FreeClusters                 ,0xffc4597c) //  5        *** != 0xffc45978
//NSTUB(GetDrive_TotalClusters                ,0xffc45600) //  3        *** != 0xffc45948
// ALT: NSTUB(GetDrive_TotalClusters, 0xffc45880) // 3 11/0
// ALT: NSTUB(GetDrive_TotalClusters, 0xffc458ac) // 3 11/0
//NSTUB(RefreshPhysicalScreen                 ,0xffd90b78) //104        *** != 0xffd9098c
//NSTUB(ScreenUnlock                          ,0xffd9098c) //  3        *** != 0xffd90b78
//NSTUB(SetScriptMode                         ,0xffc65c00) //101        *** != 0xffc63b40
//NSTUB(kbd_pwr_off                           ,0xffc36f50) //  2 64%    *** != 0xffc36f60
NSTUB(kbd_pwr_on                              ,0xffc36f10) //  2 82%

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ffc69820 -> ffc66244 -> ffd38774 -> ffe1dae4 -> ffeec334
// Current modemap entry not found in firmware - MODE_VIDEO_COMPACT        2602

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x0000d148) // Found @0xffc119cc
DEF(physw_run                               ,0x00001bec) // Found @0xffc1163c
DEF(physw_sleep_delay                       ,0x00001bea) // Found @0xffc1163c
DEF(levent_table                            ,0xffeb9d1c) // Found @0xffeb9d1c
DEF(FlashParamsTable                        ,0xffeec518) // Found @0xffeec518
DEF(movie_status                            ,0x000061d8) // Found @0xffd1429c
DEF(full_screen_refresh                     ,0x0000829c) // Found @0xffd8ea50
DEF(canon_menu_active                       ,0x00002e8c) // Found @0xffc61838
DEF(canon_shoot_menu_active                 ,0x000072d5) // Found @0xffd4d33c
DEF(playrec_mode                            ,0x00002bcc) // Found @0xffc542ac
DEF(zoom_status                             ,0x0000a4d4) // Found @0xffe1f314
DEF(some_flag_for_af_scan                   ,0x000066ac) // Found @0xffd16e3c
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 3 int value(s), the first is the zoom focus length.
// there are 23 entries in the table - set NUM_FL to 23
DEF(focus_len_table                         ,0xfffe328c) // Found @0xfffe328c
DEF(zoom_busy                               ,0x00006108) // Found @0xffd10868
DEF(focus_busy                              ,0x00005ffc) // Found @0xffd0b93c
//DEF(recreview_hold                          ,0x000037c0) // Found @0xffc6ed0c, ** != ** stubs_min = 0x00006f34 (0x6E84+0xB0)

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x403f1000; }             // Found @0xffc32730
//void *vid_get_viewport_fb()      { return (void*)0x40768620; }             // Found @0xffe660b4
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x2904+0x58)); } // Found @0xffc470bc & 0xffc470e8
//char *camera_jpeg_count_str()    { return (char*)0x00052c6c; }             // Found @0xffd83d88
//long hook_raw_size()             { return 0x00ed09f0; }                    // Found @0xffe68804
//int get_flash_params_count(void) { return 0x84; }                          // Found @0xffd39830

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffe9a70c, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x00040000 // Found @0xffe9a718, levent 0x902
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 2, KEY_SHOOT_FULL      ,0x0000000c }, // Found @0xffe9a664, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000008 }, // Found @0xffe9a664, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00000004 }, // Found @0xffe9a658, levent 0x00
//    { 2, KEY_ZOOM_IN         ,0x00000010 }, // Found @0xffe9a670, levent 0x02
//    { 2, KEY_ZOOM_OUT        ,0x00000020 }, // Found @0xffe9a67c, levent 0x03
//    { 2, KEY_POWER           ,0x00000040 }, // Found @0xffe9a688, levent 0x600 (uses inverted logic in physw_status)
//    { 2, KEY_PLAYBACK        ,0x00000080 }, // Found @0xffe9a694, levent 0x601 (uses inverted logic in physw_status)
//    { 2, KEY_UP              ,0x00000100 }, // Found @0xffe9a6a0, levent 0x04
//    { 2, KEY_DOWN            ,0x00000200 }, // Found @0xffe9a6ac, levent 0x05
//    { 2, KEY_RIGHT           ,0x00000400 }, // Found @0xffe9a6b8, levent 0x07
//    { 2, KEY_LEFT            ,0x00000800 }, // Found @0xffe9a6c4, levent 0x06
//    { 2, KEY_SET             ,0x00001000 }, // Found @0xffe9a6d0, levent 0x08
//    { 2, KEY_MENU            ,0x00002000 }, // Found @0xffe9a6dc, levent 0x09
//    { 2, KEY_DISPLAY         ,0x00004000 }, // Found @0xffe9a6e8, levent 0x0a
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_RAW_ROWPIX    3728 // Found @0xffce4274
//#define CAM_RAW_ROWS      2778 // Found @0xffce427c
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xffc170b0

// Misc stuff
DEF(ctypes, 0xffe9450e)

// For capt_seq.c
//static long *nrflag = (long*)(0x6698-0x08);  // Found @ ffd18ed8 & ffd18ef4

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NSTUB(AllocateMemory                          ,0xffe142f0) //101
NSTUB(AllocateUncacheableMemory               ,0xffc1706c) //112
NSTUB(Close                                   ,0xffc13890) //101
NSTUB(CreateTask                              ,0xffc0ad70) //101
NSTUB(DebugAssert                             ,0xffc0b048) //111
NSTUB(DeleteDirectory_Fut                     ,0xffc13220) //  1
NSTUB(DeleteFile_Fut                          ,0xffc1313c) //112
NSTUB(DoAFLock                                ,0xffc1516c) //102
NSTUB(EnterToCompensationEVF                  ,0xffc152bc) //104
NSTUB(ExecuteEventProcedure                   ,0xffc5cf90) //  2
NSTUB(ExitFromCompensationEVF                 ,0xffc15300) //104
NSTUB(ExitTask                                ,0xffc0b000) //101
NSTUB(ExpCtrlTool_StartContiAE                ,0xffc1fb10) //104
NSTUB(ExpCtrlTool_StopContiAE                 ,0xffc1fbe8) //104
NSTUB(Fclose_Fut                              ,0xffc132b8) //101
NSTUB(Feof_Fut                                ,0xffc134a4) //  1
NSTUB(Fflush_Fut                              ,0xffc134e0) //  1
NSTUB(Fgets_Fut                               ,0xffc1340c) //  1
NSTUB(Fopen_Fut                               ,0xffc13278) //101
NSTUB(Fread_Fut                               ,0xffc13364) //101
NSTUB(FreeMemory                              ,0xffe142e8) //101
NSTUB(FreeUncacheableMemory                   ,0xffc170ac) //112
NSTUB(Fseek_Fut                               ,0xffc13458) //101
NSTUB(Fwrite_Fut                              ,0xffc133b8) //101
NSTUB(GetBatteryTemperature                   ,0xffc394d8) //102
NSTUB(GetCCDTemperature                       ,0xffc39464) //102
NSTUB(GetCurrentAvValue                       ,0xffd0e010) //102
NSTUB(GetFocusLensSubjectDistance             ,0xffd0c5f0) //102
NSTUB(GetFocusLensSubjectDistanceFromLens     ,0xffd0ca40) //  3
NSTUB(GetImageFolder                          ,0xffcec100) //106
NSTUB(GetKbdState                             ,0xffc36edc) //109
NSTUB(GetMemInfo                              ,0xffc08d8c) //  3
NSTUB(GetOpticalTemperature                   ,0xffc39550) //102
NSTUB(GetParameterData                        ,0xffd397f0) //101
NSTUB(GetPropertyCase                         ,0xffc60ce0) //102
NSTUB(GetSystemTime                           ,0xffe14348) //101
NSTUB(GetVRAMHPixelsSize                      ,0xffc29984) //102
NSTUB(GetVRAMVPixelsSize                      ,0xffc29990) //102
NSTUB(GetZoomLensCurrentPoint                 ,0xffd10bdc) //102
NSTUB(GetZoomLensCurrentPosition              ,0xffe0d1e4) //102
NSTUB(GiveSemaphore                           ,0xffc16a88) //112
NSTUB(IsStrobeChargeCompleted                 ,0xffc900b0) //102
NSTUB(LEDDrive                                ,0xffc36434) //103
NSTUB(LocalTime                               ,0xffc5ac40) //115
NSTUB(LockMainPower                           ,0xffc65e60) //103
NSTUB(Lseek                                   ,0xffc139d0) //101
NSTUB(MakeDirectory_Fut                       ,0xffc131b0) //116
NSTUB(MoveFocusLensToDistance                 ,0xffe62adc) //102
NSTUB(MoveIrisWithAv                          ,0xffe1237c) //102
NSTUB(MoveZoomLensWithPoint                   ,0xffe129c8) //102
NSTUB(NewTaskShell                            ,0xffc607a4) //103
NSTUB(Open                                    ,0xffc13868) //101
NSTUB(PB2Rec                                  ,0xffc678e0) //104
NSTUB(PT_MoveDigitalZoomToWide                ,0xffc4cf48) //102
NSTUB(PT_MoveOpticalZoomAt                    ,0xffc4cf20) //102
NSTUB(PT_PlaySound                            ,0xffc55fb8) //102
NSTUB(PostLogicalEventForNotPowerType         ,0xffc63d5c) //103
NSTUB(PostLogicalEventToUI                    ,0xffc63da8) //103
NSTUB(PutInNdFilter                           ,0xffe60828) //102
NSTUB(PutOutNdFilter                          ,0xffe60860) //102
NSTUB(Read                                    ,0xffc09894) //101
NSTUB(ReadFastDir                             ,0xffdfed14) //  1
NSTUB(Rec2PB                                  ,0xffc68cdc) //104
NSTUB(Remove                                  ,0xffc138d8) //  1
NSTUB(RenameFile_Fut                          ,0xffc130e8) //  1
NSTUB(Restart                                 ,0xffc187c0) //106
NSTUB(ScreenLock                              ,0xffd9094c) // 10
NSTUB(SetAE_ShutterSpeed                      ,0xffe652c4) //102
NSTUB(SetAutoShutdownTime                     ,0xffc65ed4) //103
NSTUB(SetCurrentCaptureModeType               ,0xffc6c288) //101
NSTUB(SetFileAttributes                       ,0xffc13bbc) //  1
NSTUB(SetFileTimeStamp                        ,0xffc13b6c) //  1
NSTUB(SetLogicalEventActive                   ,0xffc65bb0) //101
NSTUB(SetParameterData                        ,0xffd39760) //101
NSTUB(SetPropertyCase                         ,0xffc60be4) //102
NSTUB(SleepTask                               ,0xffc16cf0) //101
NSTUB(TakeSemaphore                           ,0xffc169b8) //101
NSTUB(TurnOffBackLight                        ,0xffc71424) //104
NSTUB(TurnOnBackLight                         ,0xffc7140c) //104
NSTUB(UIFS_WriteFirmInfoToFile                ,0xffd2b640) //103
NSTUB(UnlockAF                                ,0xffc151a4) //102
NSTUB(UnlockMainPower                         ,0xffc65db4) //103
NSTUB(UnsetZoomForMovie                       ,0xffd3fd2c) //104
NSTUB(UpdateMBROnFlash                        ,0xffc45758) //105
NSTUB(VbattGet                                ,0xffc10314) //103
NSTUB(Write                                   ,0xffc1393c) //101
NSTUB(WriteSDCard                             ,0xffcfff68) //108
NSTUB(_log                                    ,0xffe92070) //111
NSTUB(_log10                                  ,0xffe90fb4) //112
NSTUB(_pow                                    ,0xffe91124) //114
NSTUB(_sqrt                                   ,0xffe933d8) //  1
NSTUB(add_ptp_handler                         ,0xffdd0ac4) //  3
NSTUB(apex2us                                 ,0xffd91ac4) //  4
NSTUB(close                                   ,0xffc096ac) //  1
NSTUB(closedir                                ,0xffdfede4) //  1
NSTUB(err_init_task                           ,0xffc04c44) //  4
NSTUB(exmem_alloc                             ,0xffc5b874) //103
NSTUB(free                                    ,0xffc0379c) //112
NSTUB(kbd_p1_f                                ,0xffc11a50) //109
NSTUB(kbd_p1_f_cont                           ,0xffc11a5c) //109
NSTUB(kbd_p2_f                                ,0xffc11308) //109
NSTUB(kbd_read_keys                           ,0xffc119cc) //109
NSTUB(kbd_read_keys_r2                        ,0xffc36858) //109
NSTUB(lseek                                   ,0xffc139d0) //101
NSTUB(malloc                                  ,0xffc03740) //112
NSTUB(memcmp                                  ,0xffc0cbbc) //101
NSTUB(memcpy                                  ,0xffc75854) //101
NSTUB(memset                                  ,0xffd90cf4) //101
NSTUB(mkdir                                   ,0xffc13c34) //109
NSTUB(mktime_ext                              ,0xffc760c0) //  1
NSTUB(open                                    ,0xffc095fc) //  1
NSTUB(opendir                                 ,0xffdfec80) //  1
NSTUB(openfastdir                             ,0xffdfec80) //  1
NSTUB(qsort                                   ,0xffe4ef08) //  1
NSTUB(rand                                    ,0xffc0ccc4) //  1
NSTUB(read                                    ,0xffc09894) //101
NSTUB(reboot_fw_update                        ,0xffe027fc) //106
NSTUB(rename                                  ,0xffc130e8) //  1
NSTUB(set_control_event                       ,0xffc65804) //111
NSTUB(srand                                   ,0xffc0ccb8) //  1
NSTUB(stat                                    ,0xffc13a9c) //  1
NSTUB(strcat                                  ,0xffc75668) //  1
NSTUB(strchr                                  ,0xffc756f0) //  1
NSTUB(strcmp                                  ,0xffc0cb54) //101
NSTUB(strcpy                                  ,0xffc0cb3c) //101
NSTUB(strftime                                ,0xffc75ac8) //  1
NSTUB(strlen                                  ,0xffc0cb98) //101
NSTUB(strncmp                                 ,0xffc756a4) //  1
NSTUB(strncpy                                 ,0xffc1c5b0) //  1
NSTUB(strrchr                                 ,0xffd90ccc) //  1
NSTUB(strtol                                  ,0xffc1c7e8) //101
NSTUB(strtolx                                 ,0xffc1c5ec) //109
  DEF(task_CaptSeq                            ,0xffc4f640) //107
  DEF(task_ExpDrv                             ,0xffc86e80) //110
  DEF(task_InitFileModules                    ,0xffc696ac) //107
  DEF(task_MovieRecord                        ,0xffd144f0) //107
  DEF(task_PhySw                              ,0xffc11638) //107
  DEF(task_RotaryEncoder                      ,0xffc37070) //107
NSTUB(time                                    ,0xffc5aaf4) //  1
NSTUB(vsprintf                                ,0xffc0cb00) //  1
NSTUB(write                                   ,0xffc1393c) //101
