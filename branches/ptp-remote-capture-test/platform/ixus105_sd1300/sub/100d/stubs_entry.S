// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R43 (DRYOS version 2.3, release #0043)
//   Firmware Ver GM1.00D
//   Canon IXUS 105

// Values for makefile.inc
//   PLATFORMOSVER = 43
//   PLATFORMID = 12788 (0x31f4) // Found @ 0xfffe0130
//   MAXRAMADDR = 0x03ffffff
//   KEYSYS = d4a                // Found @ 0xffff1c18
//   NEED_ENCODED_DISKBOOT = 4   // Found @ 0xffff1c28

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NSTUB(GetDrive_FreeClusters                 ,0xffc24258) //  3        *** != 0xffc55b78
// ALT: NSTUB(GetDrive_FreeClusters, 0xffc55b78) // 4 9/0
//NSTUB(kbd_pwr_off                           ,0xffc47e04) //  2 64%    *** != 0x00000000
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ffc77d6c -> ffc748fc -> ffd3ef78 -> ffe29f0c -> ffef9ef8
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x0002f100) // Found @0xffc24574
DEF(physw_run                               ,0x00001c2c) // Found @0xffc241d8
DEF(physw_sleep_delay                       ,0x00001c2a) // Found @0xffc241d8
DEF(levent_table                            ,0xffec0320) // Found @0xffec0320
DEF(FlashParamsTable                        ,0xffefa0e8) // Found @0xffefa0e8
DEF(movie_status                            ,0x00005780) // Found @0xffd1bc1c
DEF(full_screen_refresh                     ,0x000076e8) // Found @0xffd8c5d4
DEF(canon_menu_active                       ,0x00002be0) // Found @0xffc7179c
DEF(canon_shoot_menu_active                 ,0x000068c9) // Found @0xffd50818
DEF(playrec_mode                            ,0x0000292c) // Found @0xffc64200
DEF(zoom_status                             ,0x00009f88) // Found @0xffe2c24c
DEF(some_flag_for_af_scan                   ,0x00005b28) // Found @0xffd1e584
DEF(zoom_busy                               ,0x000056e0) // Found @0xffd17c24
DEF(focus_busy                              ,0x00005584) // Found @0xffd135b8
DEF(recreview_hold                          ,0x000031d0) // Found @0xffc7d224

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x403f1000; }             // Found @0xffc43628
//void *vid_get_viewport_fb()      { return (void*)0x40507700; }             // Found @0xffe780c8
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x2670+0x58)); } // Found @0xffc571f4 & 0xffc57228
//char *camera_jpeg_count_str()    { return (char*)0x00077fdc; }             // Found @0xffd83ba4
//long hook_raw_size()             { return 0x011e4ee0; }                    // Found @0xffe7b480
//int get_flash_params_count(void) { return 0x94; }                          // Found @0xffd40034

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffea7b60, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x00040000 // Found @0xffea7b6c, levent 0x902
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_PLAYBACK        ,0x00000100 }, // Found @0xffea7a88, levent 0x601
//    { 0, KEY_POWER           ,0x00000200 }, // Found @0xffea7a94, levent 0x600
//    { 0, KEY_MENU            ,0x00000400 }, // Found @0xffea7aa0, levent 0x09
//    { 1, KEY_LEFT            ,0x08000000 }, // Found @0xffea7adc, levent 0x06
//    { 1, KEY_ZOOM_OUT        ,0x10000000 }, // Found @0xffea7ae8, levent 0x03
//    { 1, KEY_ZOOM_IN         ,0x20000000 }, // Found @0xffea7af4, levent 0x02
//    { 2, KEY_SET             ,0x00000001 }, // Found @0xffea7b00, levent 0x08
//    { 2, KEY_DOWN            ,0x00000002 }, // Found @0xffea7b0c, levent 0x05
//    { 2, KEY_DISPLAY         ,0x00000008 }, // Found @0xffea7b18, levent 0x0a
//    { 2, KEY_RIGHT           ,0x00000400 }, // Found @0xffea7b24, levent 0x07
//    { 2, KEY_UP              ,0x00000800 }, // Found @0xffea7b30, levent 0x04
//    { 2, KEY_SHOOT_FULL      ,0x00005000 }, // Found @0xffea7b3c, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00004000 }, // Found @0xffea7b48, levent 0x00
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00001000 }, // Found @0xffea7b3c, levent 0x01
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_RAW_ROWPIX    4104 // Found @0xffcf4dc4
//#define CAM_RAW_ROWS      3048 // Found @0xffcf4dd0
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xffc29e80

// Misc stuff
DEF(ctypes, 0xffea6726)

// For capt_seq.c
//static long *nrflag = (long*)(0x5b10-0x08);  // Found @ ffd20454 & ffd20470

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NSTUB(AllocateMemory                          ,0xffe1bd24) //101
NSTUB(AllocateUncacheableMemory               ,0xffc29e3c) //112
NSTUB(Close                                   ,0xffc26b54) //101
NSTUB(CreateTask                              ,0xffc0e83c) //101
NSTUB(DebugAssert                             ,0xffc0eb14) //111
NSTUB(DeleteDirectory_Fut                     ,0xffc265b0) //116
NSTUB(DeleteFile_Fut                          ,0xffc264cc) //112
NSTUB(DoAFLock                                ,0xffc27fe0) //102
NSTUB(EnterToCompensationEVF                  ,0xffc28090) //104
NSTUB(ExecuteEventProcedure                   ,0xffc6cef0) //104
NSTUB(ExitFromCompensationEVF                 ,0xffc280d4) //104
NSTUB(ExitTask                                ,0xffc0eacc) //101
NSTUB(ExpCtrlTool_StartContiAE                ,0xffc35864) //104
NSTUB(ExpCtrlTool_StopContiAE                 ,0xffc3593c) //104
NSTUB(Fclose_Fut                              ,0xffc26648) //101
NSTUB(Feof_Fut                                ,0xffc26834) //  1
NSTUB(Fflush_Fut                              ,0xffc26870) //  1
NSTUB(Fgets_Fut                               ,0xffc2679c) //  1
NSTUB(Fopen_Fut                               ,0xffc26608) //101
NSTUB(Fread_Fut                               ,0xffc266f4) //101
NSTUB(FreeMemory                              ,0xffe1bd1c) //101
NSTUB(FreeUncacheableMemory                   ,0xffc29e7c) //112
NSTUB(Fseek_Fut                               ,0xffc267e8) //101
NSTUB(Fwrite_Fut                              ,0xffc26748) //101
NSTUB(GetBatteryTemperature                   ,0xffc49edc) //102
NSTUB(GetCCDTemperature                       ,0xffc49e68) //102
NSTUB(GetCurrentAvValue                       ,0xffd14ed4) //102
NSTUB(GetDrive_ClusterSize                    ,0xffc55b18) //  4
NSTUB(GetDrive_TotalClusters                  ,0xffc55b4c) //  3
NSTUB(GetFocusLensSubjectDistance             ,0xffd14174) //102
NSTUB(GetFocusLensSubjectDistanceFromLens     ,0xffd145bc) //  3
NSTUB(GetImageFolder                          ,0xffcfbd88) //106
NSTUB(GetKbdState                             ,0xffc47dec) //109
NSTUB(GetMemInfo                              ,0xffc0a16c) //115
NSTUB(GetOpticalTemperature                   ,0xffc49f50) //102
NSTUB(GetParameterData                        ,0xffd3fff4) //101
NSTUB(GetPropertyCase                         ,0xffc70bfc) //102
NSTUB(GetSystemTime                           ,0xffe1bd7c) //101
NSTUB(GetVRAMHPixelsSize                      ,0xffcbe1e8) //102
NSTUB(GetVRAMVPixelsSize                      ,0xffcbe1f4) //102
NSTUB(GetZoomLensCurrentPoint                 ,0xffd17f9c) //102
NSTUB(GetZoomLensCurrentPosition              ,0xffe134c8) //102
NSTUB(GiveSemaphore                           ,0xffc29858) //112
NSTUB(IsStrobeChargeCompleted                 ,0xffcaec1c) //102
NSTUB(LEDDrive                                ,0xffc47398) //103
NSTUB(LocalTime                               ,0xffc6ab34) //115
NSTUB(LockMainPower                           ,0xffc74504) //103
NSTUB(Lseek                                   ,0xffc26c70) //101
NSTUB(MakeDirectory_Fut                       ,0xffc26540) //116
NSTUB(MoveFocusLensToDistance                 ,0xffe74b48) //102
NSTUB(MoveIrisWithAv                          ,0xffe18b58) //102
NSTUB(MoveZoomLensWithPoint                   ,0xffe190e8) //102
NSTUB(NewTaskShell                            ,0xffc70608) //103
NSTUB(Open                                    ,0xffc26ae8) //101
NSTUB(PB2Rec                                  ,0xffc7716c) //104
NSTUB(PT_MoveDigitalZoomToWide                ,0xffc5d76c) //102
NSTUB(PT_MoveOpticalZoomAt                    ,0xffc5d744) //102
NSTUB(PT_PlaySound                            ,0xffc65da4) //  7
NSTUB(PostLogicalEventForNotPowerType         ,0xffc73d34) //103
NSTUB(PostLogicalEventToUI                    ,0xffc73d80) //103
NSTUB(PutInNdFilter                           ,0xffe18f4c) //102
NSTUB(PutOutNdFilter                          ,0xffe18f70) //102
NSTUB(Read                                    ,0xffc0ac7c) //101
NSTUB(ReadFastDir                             ,0xffe09088) //  4
NSTUB(Rec2PB                                  ,0xffc771ac) //104
NSTUB(RefreshPhysicalScreen                   ,0xffd8cfbc) //104
NSTUB(Remove                                  ,0xffc26b88) //  4
NSTUB(RenameFile_Fut                          ,0xffc26438) //116
NSTUB(Restart                                 ,0xffc2b614) //106
NSTUB(ScreenLock                              ,0xffd8e168) //  3
NSTUB(ScreenUnlock                            ,0xffd8e1ac) //  7
NSTUB(SetAE_ShutterSpeed                      ,0xffe772d8) //102
NSTUB(SetAutoShutdownTime                     ,0xffc74578) //103
NSTUB(SetCurrentCaptureModeType               ,0xffc7ab90) //101
NSTUB(SetFileAttributes                       ,0xffc26e4c) //  3
NSTUB(SetFileTimeStamp                        ,0xffc26df0) //  4
NSTUB(SetLogicalEventActive                   ,0xffc7427c) //101
NSTUB(SetParameterData                        ,0xffd3ff64) //101
NSTUB(SetPropertyCase                         ,0xffc70acc) //102
NSTUB(SetScriptMode                           ,0xffc742cc) //101
NSTUB(SleepTask                               ,0xffc29ac0) //101
NSTUB(TakeSemaphore                           ,0xffc29788) //101
NSTUB(TurnOffBackLight                        ,0xffc7f854) //104
NSTUB(TurnOnBackLight                         ,0xffc7f83c) //104
NSTUB(UIFS_WriteFirmInfoToFile                ,0xffd3069c) //101
NSTUB(UnlockAF                                ,0xffc28018) //102
NSTUB(UnlockMainPower                         ,0xffc74458) //103
NSTUB(UnsetZoomForMovie                       ,0xffd45eb8) //104
NSTUB(UpdateMBROnFlash                        ,0xffc55998) //105
NSTUB(VbattGet                                ,0xffc22f14) //103
NSTUB(Write                                   ,0xffc26be4) //101
NSTUB(WriteSDCard                             ,0xffd074dc) //108
NSTUB(_log                                    ,0xffea4270) //111
NSTUB(_log10                                  ,0xffea31b4) //112
NSTUB(_pow                                    ,0xffea3324) //114
NSTUB(_sqrt                                   ,0xffea55d8) //  1
NSTUB(add_ptp_handler                         ,0xffdd75e0) //  3
NSTUB(apex2us                                 ,0xffd8f4b8) //  4
NSTUB(close                                   ,0xffc0aa94) //  1
NSTUB(closedir                                ,0xffe08ee4) //  4
NSTUB(err_init_task                           ,0xffc05f4c) //111
NSTUB(exmem_alloc                             ,0xffc6b7d4) //103
NSTUB(free                                    ,0xffc0415c) //112
NSTUB(kbd_p1_f                                ,0xffc245f0) //109
NSTUB(kbd_p1_f_cont                           ,0xffc245fc) //109
NSTUB(kbd_p2_f                                ,0xffc23ea4) //109
NSTUB(kbd_read_keys                           ,0xffc24574) //109
NSTUB(kbd_read_keys_r2                        ,0xffc47800) //109
NSTUB(lseek                                   ,0xffc26c70) //101
NSTUB(malloc                                  ,0xffc04100) //112
NSTUB(memcmp                                  ,0xffc1066c) //101
NSTUB(memcpy                                  ,0xffc2f3e0) //101
NSTUB(memset                                  ,0xffd8e4f0) //101
NSTUB(mkdir                                   ,0xffc26ff0) //109
NSTUB(mktime_ext                              ,0xffc84a0c) //  1
NSTUB(open                                    ,0xffc0a9e4) //  1
NSTUB(OpenFastDir                             ,0xffe08f34) //  4
NSTUB(qsort                                   ,0xffe5bcd4) //  4
NSTUB(rand                                    ,0xffc10774) //  1
NSTUB(read                                    ,0xffc0ac7c) //101
NSTUB(reboot_fw_update                        ,0xffe0a8fc) //106
NSTUB(set_control_event                       ,0xffc73f9c) //111
NSTUB(srand                                   ,0xffc10768) //  1
NSTUB(stat                                    ,0xffc26cb8) //109
NSTUB(strcat                                  ,0xffc841c8) //  1
NSTUB(strchr                                  ,0xffc03fe4) //  1
NSTUB(strcmp                                  ,0xffc10628) //101
NSTUB(strcpy                                  ,0xffc10610) //101
NSTUB(strftime                                ,0xffc84414) //113
NSTUB(strlen                                  ,0xffc04030) //101
NSTUB(strncmp                                 ,0xffc03f98) //  1
NSTUB(strncpy                                 ,0xffc03f5c) //  1
NSTUB(strrchr                                 ,0xffc04008) //  1
NSTUB(strtol                                  ,0xffc2f6c0) //101
NSTUB(strtolx                                 ,0xffc2f4c4) //109
  DEF(task_CaptSeq                            ,0xffc5fa2c) //107
  DEF(task_ExpDrv                             ,0xffc99668) //110
  DEF(task_InitFileModules                    ,0xffc77bf8) //107
  DEF(task_MovieRecord                        ,0xffd1be60) //107
  DEF(task_PhySw                              ,0xffc241d4) //107
NSTUB(time                                    ,0xffc6a9e8) //109
NSTUB(vsprintf                                ,0xffc105d4) //115
NSTUB(write                                   ,0xffc26be4) //101
