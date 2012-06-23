// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R43 (DRYOS version 2.3, release #0043)
//   Firmware Ver GM1.00E
//   Canon PowerShot A490

// Values for makefile.inc
//   PLATFORMOSVER = 43
//   PLATFORMID = 12784 (0x31f0) // Found @ 0xfffe0130
//   MAXRAMADDR = 0x01ffffff
//   KEYSYS = d4a                // Found @ 0xffff1a0c
//   NEED_ENCODED_DISKBOOT = 4   // Found @ 0xffff1a1c

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NSTUB(kbd_pwr_off                           ,0xffc435ec) //  2 64%    *** != 0x00000000
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ffc70628 -> ffc6d174 -> ffd2e028 -> ffe07d3c -> ffeca5dc
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x0002e754) // Found @0xffc23b2c
DEF(physw_run                               ,0x00001bf0) // Found @0xffc23790
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

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x10361000; }             // Found @0xffc3f024
//void *vid_get_viewport_fb()      { return (void*)0x10648cc0; }             // Found @0xffe53c80
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x2540+0x54)); } // Found @0xffc52914 & 0xffc5294c
//char *camera_jpeg_count_str()    { return (char*)0x0007571c; }             // Found @0xffd70afc
//long hook_raw_size()             { return 0x00ec04f0; }                    // Found @0xffe57008
//int get_flash_params_count(void) { return 0x94; }                          // Found @0xffd2f0e4

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00040000 // Found @0xffe8217c, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x00080000 // Found @0xffe82188, levent 0x902
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 2, KEY_RIGHT           ,0x00000004 }, // Found @0xffe8211c, levent 0x07
//    { 2, KEY_ZOOM_OUT        ,0x00000040 }, // Found @0xffe82140, levent 0x03
//    { 2, KEY_ZOOM_IN         ,0x00000080 }, // Found @0xffe8214c, levent 0x02
//    { 2, KEY_SET             ,0x00000100 }, // Found @0xffe82158, levent 0x08
//    { 2, KEY_UP              ,0x00100000 }, // Found @0xffe82194, levent 0x04
//    { 2, KEY_DOWN            ,0x00200000 }, // Found @0xffe821a0, levent 0x05
//    { 2, KEY_LEFT            ,0x00400000 }, // Found @0xffe821ac, levent 0x06
//    { 2, KEY_MENU            ,0x01000000 }, // Found @0xffe821c4, levent 0x09
//    { 2, KEY_SHOOT_FULL      ,0x00000030 }, // Found @0xffe82134, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000020 }, // Found @0xffe82134, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00000010 }, // Found @0xffe82128, levent 0x00
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_RAW_ROWPIX    3720 // Found @0xffcea098
//#define CAM_RAW_ROWS      2772 // Found @0xffcea0a4
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x10000000 // Found @0xffc29320

// Misc stuff
DEF(ctypes, 0xffe81a16)

// For capt_seq.c
//static long *nrflag = (long*)(0x5800-0x08);  // Found @ ffd10e24 & ffd10e40

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NSTUB(AllocateMemory                          ,0xffdfa458) //101
NSTUB(AllocateUncacheableMemory               ,0xffc292dc) //112
NSTUB(Close                                   ,0xffc2610c) //101
NSTUB(CreateTask                              ,0xffc0f1a8) //101
NSTUB(DebugAssert                             ,0xffc0f680) //111
NSTUB(DeleteDirectory_Fut                     ,0xffc25b68) //  1
NSTUB(DeleteFile_Fut                          ,0xffc25a84) //112
NSTUB(DoAFLock                                ,0xffc27558) //102
NSTUB(EnterToCompensationEVF                  ,0xffc27608) //104
NSTUB(ExecuteEventProcedure                   ,0xffc65798) //  1
NSTUB(ExitFromCompensationEVF                 ,0xffc2764c) //104
NSTUB(ExitTask                                ,0xffc0f438) //101
NSTUB(ExpCtrlTool_StartContiAE                ,0xffc34ce8) //104
NSTUB(ExpCtrlTool_StopContiAE                 ,0xffc34dc0) //104
NSTUB(Fclose_Fut                              ,0xffc25c00) //101
NSTUB(Feof_Fut                                ,0xffc25dec) //  1
NSTUB(Fflush_Fut                              ,0xffc25e28) //  1
NSTUB(Fgets_Fut                               ,0xffc25d54) //  1
NSTUB(Fopen_Fut                               ,0xffc25bc0) //101
NSTUB(Fread_Fut                               ,0xffc25cac) //101
NSTUB(FreeMemory                              ,0xffdfa450) //101
NSTUB(FreeUncacheableMemory                   ,0xffc2931c) //112
NSTUB(Fseek_Fut                               ,0xffc25da0) //101
NSTUB(Fwrite_Fut                              ,0xffc25d00) //101
NSTUB(GetBatteryTemperature                   ,0xffc45624) //102
NSTUB(GetCCDTemperature                       ,0xffc455b0) //102
NSTUB(GetCurrentAvValue                       ,0xffd087b8) //102
NSTUB(GetDrive_ClusterSize                    ,0xffc512bc) //  4
NSTUB(GetDrive_FreeClusters                   ,0xffc23810) //  3
// ALT: NSTUB(GetDrive_FreeClusters, 0xffc5131c) // 4 9/0
NSTUB(GetDrive_TotalClusters                  ,0xffc512f0) //  3
NSTUB(GetFocusLensSubjectDistance             ,0xffd07ab0) //102
NSTUB(GetFocusLensSubjectDistanceFromLens     ,0xffd07f08) //  3
NSTUB(GetImageFolder                          ,0xffcf1058) //106
NSTUB(GetKbdState                             ,0xffc435d4) //109
NSTUB(GetMemInfo                              ,0xffc0a7f8) //  3
NSTUB(GetOpticalTemperature                   ,0xffc4569c) //102
NSTUB(GetParameterData                        ,0xffd2f0a4) //101
NSTUB(GetPropertyCase                         ,0xffc694a4) //102
NSTUB(GetSystemTime                           ,0xffdfa4b0) //101
NSTUB(GetVRAMHPixelsSize                      ,0xffcb69fc) //102
NSTUB(GetVRAMVPixelsSize                      ,0xffcb6a08) //102
NSTUB(GetZoomLensCurrentPoint                 ,0xffd09c78) //102
NSTUB(GetZoomLensCurrentPosition              ,0xffdf24f4) //102
NSTUB(GiveSemaphore                           ,0xffc0f104) //112
NSTUB(IsStrobeChargeCompleted                 ,0xffca6ff0) //102
NSTUB(LEDDrive                                ,0xffc42bc8) //103
NSTUB(LocalTime                               ,0xffc634a8) //  1
NSTUB(LockMainPower                           ,0xffc6cd7c) //103
NSTUB(Lseek                                   ,0xffc26228) //101
NSTUB(MakeDirectory_Fut                       ,0xffc25af8) //  1
NSTUB(MoveFocusLensToDistance                 ,0xffe50700) //102
NSTUB(MoveIrisWithAv                          ,0xffdf7b98) //102
NSTUB(MoveZoomLensWithPoint                   ,0xffdf8124) //102
NSTUB(NewTaskShell                            ,0xffc68eb0) //103
NSTUB(Open                                    ,0xffc260a0) //101
NSTUB(PB2Rec                                  ,0xffc6f9e8) //104
NSTUB(PT_MoveDigitalZoomToWide                ,0xffc570e8) //102
NSTUB(PT_MoveOpticalZoomAt                    ,0xffc570c0) //102
NSTUB(PT_PlaySound                            ,0xffc5f328) //  7
NSTUB(PostLogicalEventForNotPowerType         ,0xffc6c5ac) //103
NSTUB(PostLogicalEventToUI                    ,0xffc6c5f8) //103
NSTUB(PutInNdFilter                           ,0xffdf7f88) //102
NSTUB(PutOutNdFilter                          ,0xffdf7fac) //102
NSTUB(Read                                    ,0xffc0b308) //101
NSTUB(ReadFastDir                             ,0xffde8ef0) //  4
NSTUB(Rec2PB                                  ,0xffc6fa28) //104
NSTUB(RefreshPhysicalScreen                   ,0xffd79ea0) //104
NSTUB(Remove                                  ,0xffc26140) //  4
NSTUB(RenameFile_Fut                          ,0xffc259f0) //  4
NSTUB(Restart                                 ,0xffc2aab4) //106
NSTUB(ScreenLock                              ,0xffd7b04c) //  3
NSTUB(ScreenUnlock                            ,0xffd7b090) //  7
NSTUB(SetAE_ShutterSpeed                      ,0xffe52e90) //102
NSTUB(SetAutoShutdownTime                     ,0xffc6cdf0) //103
NSTUB(SetCurrentCaptureModeType               ,0xffc7310c) //101
NSTUB(SetFileAttributes                       ,0xffc26404) //  3
NSTUB(SetFileTimeStamp                        ,0xffc263a8) //  4
NSTUB(SetLogicalEventActive                   ,0xffc6caf4) //101
NSTUB(SetParameterData                        ,0xffd2f014) //101
NSTUB(SetPropertyCase                         ,0xffc69374) //102
NSTUB(SetScriptMode                           ,0xffc6cb44) //101
NSTUB(SleepTask                               ,0xffc29160) //101
NSTUB(TakeSemaphore                           ,0xffc0f034) //101
NSTUB(TurnOffBackLight                        ,0xffc77d88) //104
NSTUB(TurnOnBackLight                         ,0xffc77d70) //104
NSTUB(UIFS_WriteFirmInfoToFile                ,0xffd1f818) //101
NSTUB(UnlockAF                                ,0xffc27590) //102
NSTUB(UnlockMainPower                         ,0xffc6ccd0) //103
NSTUB(UnsetZoomForMovie                       ,0xffd35564) //104
NSTUB(UpdateMBROnFlash                        ,0xffc5113c) //105
NSTUB(VbattGet                                ,0xffc22be4) //103
NSTUB(Write                                   ,0xffc2619c) //101
NSTUB(WriteSDCard                             ,0xffcfc7ac) //108
NSTUB(_log                                    ,0xffe7f578) //111
NSTUB(_log10                                  ,0xffe7e4bc) //112
NSTUB(_pow                                    ,0xffe7e62c) //114
NSTUB(_sqrt                                   ,0xffe808e0) //  1
NSTUB(add_ptp_handler                         ,0xffdbd384) //  3
NSTUB(apex2us                                 ,0xffd7c39c) //  4
NSTUB(close                                   ,0xffc0b120) //  1
NSTUB(closedir                                ,0xffde8d4c) //  4
NSTUB(err_init_task                           ,0xffc05f50) //  4
NSTUB(exmem_alloc                             ,0xffc64148) //103
NSTUB(free                                    ,0xffc04160) //112
NSTUB(kbd_p1_f                                ,0xffc23ba8) //109
NSTUB(kbd_p1_f_cont                           ,0xffc23bb4) //109
NSTUB(kbd_p2_f                                ,0xffc2345c) //109
NSTUB(kbd_read_keys                           ,0xffc23b2c) //109
NSTUB(kbd_read_keys_r2                        ,0xffc42fb8) //109
NSTUB(lseek                                   ,0xffc26228) //101
NSTUB(malloc                                  ,0xffc04104) //112
NSTUB(memcmp                                  ,0xffc11318) //101
NSTUB(memcpy                                  ,0xffc2e864) //101
NSTUB(memset                                  ,0xffd7b3d4) //101
NSTUB(mkdir                                   ,0xffc265a8) //  4
NSTUB(mktime_ext                              ,0xffc7cba0) //  1
NSTUB(open                                    ,0xffc0b070) //  1
NSTUB(opendir                                 ,0xffde8d9c) //  4
NSTUB(openfastdir                             ,0xffde8d9c) //  4
NSTUB(qsort                                   ,0xffe39418) //  4
NSTUB(rand                                    ,0xffc11420) //  1
NSTUB(read                                    ,0xffc0b308) //101
NSTUB(reboot_fw_update                        ,0xffdea764) //  1
NSTUB(rename                                  ,0xffc259f0) //  4
NSTUB(set_control_event                       ,0xffc6c814) //111
NSTUB(srand                                   ,0xffc11414) //  1
NSTUB(stat                                    ,0xffc26270) //  3
NSTUB(strcat                                  ,0xffc7c35c) //  1
NSTUB(strchr                                  ,0xffc03fe8) //  1
NSTUB(strcmp                                  ,0xffc112d4) //101
NSTUB(strcpy                                  ,0xffc112bc) //101
NSTUB(strftime                                ,0xffc7c5a8) //113
NSTUB(strlen                                  ,0xffc04034) //101
NSTUB(strncmp                                 ,0xffc03f9c) //  1
NSTUB(strncpy                                 ,0xffc03f60) //  1
NSTUB(strrchr                                 ,0xffc0400c) //  1
NSTUB(strtol                                  ,0xffc2eb44) //101
NSTUB(strtolx                                 ,0xffc2e948) //109
  DEF(task_CaptSeq                            ,0xffc5919c) //107
  DEF(task_ExpDrv                             ,0xffc91388) //110
  DEF(task_InitFileModules                    ,0xffc704b4) //107
  DEF(task_MovieRecord                        ,0xffd0c8f8) //107
  DEF(task_PhySw                              ,0xffc2378c) //107
NSTUB(time                                    ,0xffc6335c) //  1
NSTUB(vsprintf                                ,0xffc11280) //  4
NSTUB(write                                   ,0xffc2619c) //101
