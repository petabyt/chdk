// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R49 (DRYOS version 2.3, release #0049)
//   Firmware Ver GM1.00B
//   Canon PowerShot ELPH 310 HS

// Values for makefile.inc
//   PLATFORMID = 12855 (0x3237) // Found @ 0xfff40040
//   MAXRAMADDR = 0x07ffffff
//   KEYSYS = d4c                // Found @ 0xffff360c
//   NEED_ENCODED_DISKBOOT = 7   // Found @ 0xffff361c

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
NSTUB(kbd_pwr_off                             ,0xff057fc8) //  2 60%
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff0931a8 -> ff08fab8 -> ff1b3bac -> ff301224 -> ff457c78
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00034108) // Found @0xff025814
DEF(physw_run                               ,0x00001c4c) // Found @0xff0253ac
DEF(levent_table                            ,0xff3f7e00) // Found @0xff3f7e00
DEF(FlashParamsTable                        ,0xff457ed0) // Found @0xff457ed0
DEF(movie_status                            ,0x00006d04) // Found @0xff1854bc
DEF(full_screen_refresh                     ,0x00009a2c) // Found @0xff22fcbc
DEF(canon_menu_active                       ,0x00003284) // Found @0xff08ae14
DEF(canon_shoot_menu_active                 ,0x000083bd) // Found @0xff1d0b40
DEF(playrec_mode                            ,0x00002fb0) // Found @0xff07cb48
DEF(zoom_status                             ,0x0000dacc) // Found @0xff304b38
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 2 int value(s), the first is the zoom focus length.
// there are 127 entries in the table - set NUM_FL to 127
DEF(focus_len_table                         ,0xfff4abc8) // Found @0xfff4abc8
DEF(zoom_busy                               ,0x00006ba0) // Found @0xff17f438
DEF(focus_busy                              ,0x00006a40) // Found @0xff17aa94
DEF(recreview_hold                          ,0x000038ec) // Found @0xff09a5d4

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x40471000; }             // Found @0xff053204
//void *vid_get_viewport_fb()      { return (void*)0x405c6b80; }             // Found @0xff365654
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x2c58+0x58)); } // Found @0xff06c234 & 0xff06c26c
//char *camera_jpeg_count_str()    { return (char*)0x000b9574; }             // Found @0xff226398
//long hook_raw_size()             { return 0x0123eaf0; }                    // Found @0xff36849c
//int get_flash_params_count(void) { return 0x9f; }                          // Found @0xff1b4c5c

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xff3a8050, levent 0x20a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x04000000 // Found @0xff3a8070, levent 0x202
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 2, KEY_SHOOT_FULL      ,0x00000300 }, // Found @0xff3a8018, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000200 }, // Found @0xff3a8018, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00000100 }, // Found @0xff3a8010, levent 0x00
//    { 2, KEY_MENU            ,0x00000001 }, // Found @0xff3a7fd0, levent 0x09
//    { 2, KEY_SET             ,0x00000002 }, // Found @0xff3a7fd8, levent 0x08
//    { 2, KEY_ZOOM_IN         ,0x00000004 }, // Found @0xff3a7fe0, levent 0x02
//    { 2, KEY_ZOOM_OUT        ,0x00000008 }, // Found @0xff3a7fe8, levent 0x03
//    { 2, KEY_LEFT            ,0x00000010 }, // Found @0xff3a7ff0, levent 0x06
//    { 2, KEY_RIGHT           ,0x00000020 }, // Found @0xff3a7ff8, levent 0x07
//    { 2, KEY_DOWN            ,0x00000040 }, // Found @0xff3a8000, levent 0x05
//    { 2, KEY_UP              ,0x00000080 }, // Found @0xff3a8008, levent 0x04
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#define CAM_RAW_ROWPIX    4168 // Found @0xff14d678
//#define CAM_RAW_ROWS      3060 // Found @0xff14d684
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff02be50

// Misc stuff
DEF(ctypes, 0xff3a6812)

// For capt_seq.c
//static long *nrflag = (long*)(0x9b44+0x00);  // Found @ ff23c248 & ff23c2d0
//#define NR_AUTO (0)                          // have to explictly reset value back to 0 to enable auto

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NSTUB(AllocateMemory                          ,0xff2efd34) //101
NSTUB(AllocateUncacheableMemory               ,0xff02be08) //112
NSTUB(Close                                   ,0xff028024) //101
NSTUB(CreateTask                              ,0xff00eae4) //101
NSTUB(DebugAssert                             ,0xff00edbc) //111
NSTUB(DeleteDirectory_Fut                     ,0xff027a20) //  1
NSTUB(DeleteFile_Fut                          ,0xff02793c) //112
NSTUB(DoAFLock                                ,0xff0298cc) //102
NSTUB(EnterToCompensationEVF                  ,0xff029b2c) //104
NSTUB(ExecuteEventProcedure                   ,0xff0862bc) //  1
NSTUB(ExitFromCompensationEVF                 ,0xff029b70) //104
NSTUB(ExitTask                                ,0xff00ed74) //101
NSTUB(ExpCtrlTool_StartContiAE                ,0xff037a8c) //104
NSTUB(ExpCtrlTool_StopContiAE                 ,0xff037b6c) //104
NSTUB(Fclose_Fut                              ,0xff027ab8) //101
NSTUB(Feof_Fut                                ,0xff027ca4) //  1
NSTUB(Fflush_Fut                              ,0xff027ce0) //  1
NSTUB(Fgets_Fut                               ,0xff027c0c) //  6
NSTUB(Fopen_Fut                               ,0xff027a78) //101
NSTUB(Fread_Fut                               ,0xff027b64) //101
NSTUB(FreeMemory                              ,0xff2efd2c) //101
NSTUB(FreeUncacheableMemory                   ,0xff02be48) //112
NSTUB(Fseek_Fut                               ,0xff027c58) //101
NSTUB(Fwrite_Fut                              ,0xff027bb8) //101
NSTUB(GetBatteryTemperature                   ,0xff05b944) //102
NSTUB(GetCCDTemperature                       ,0xff05b8d0) //102
NSTUB(GetCurrentAvValue                       ,0xff17c8dc) //102
NSTUB(GetDrive_ClusterSize                    ,0xff069cb0) //  6
NSTUB(GetDrive_FreeClusters                   ,0xff069d08) //  6
NSTUB(GetDrive_TotalClusters                  ,0xff069ce0) //  6
NSTUB(GetFocusLensSubjectDistance             ,0xff17b810) //102
NSTUB(GetFocusLensSubjectDistanceFromLens     ,0xff17bc60) //  3
NSTUB(GetImageFolder                          ,0xff156c74) //  6
NSTUB(GetKbdState                             ,0xff057fb0) //109
NSTUB(GetMemInfo                              ,0xff00a2ac) //  3
NSTUB(GetOpticalTemperature                   ,0xff05b9b8) //102
NSTUB(GetParameterData                        ,0xff1b4c1c) //101
NSTUB(GetPropertyCase                         ,0xff08a35c) //102
NSTUB(GetSystemTime                           ,0xff2efd8c) //101
NSTUB(GetZoomLensCurrentPoint                 ,0xff17f8b4) //102
NSTUB(GetZoomLensCurrentPosition              ,0xff2dbcd8) //102
NSTUB(GiveSemaphore                           ,0xff02b800) //112
NSTUB(IsStrobeChargeCompleted                 ,0xff0de288) //102
NSTUB(LEDDrive                                ,0xff057508) //101
NSTUB(LocalTime                               ,0xff083b54) //  6
NSTUB(LockMainPower                           ,0xff08f6b0) //103
NSTUB(Lseek                                   ,0xff028240) //101
NSTUB(MakeDirectory_Fut                       ,0xff0279b0) //  6
NSTUB(MakeSDCardBootable                      ,0xff069f40) //105
NSTUB(MoveFocusLensToDistance                 ,0xff361894) //102
NSTUB(MoveIrisWithAv                          ,0xff2ec098) //102
NSTUB(MoveZoomLensWithPoint                   ,0xff2ec7cc) //102
NSTUB(NewTaskShell                            ,0xff089cdc) //101
NSTUB(Open                                    ,0xff027f5c) //101
NSTUB(PB2Rec                                  ,0xff0927cc) //104
NSTUB(PT_MoveDigitalZoomToWide                ,0xff073c5c) //102
NSTUB(PT_MoveOpticalZoomAt                    ,0xff073c34) //102
NSTUB(PT_PlaySound                            ,0xff07e868) //  6
NSTUB(PostLogicalEventForNotPowerType         ,0xff08eda4) //103
NSTUB(PostLogicalEventToUI                    ,0xff08edf0) //103
NSTUB(PutInNdFilter                           ,0xff2ec5a4) //102
NSTUB(PutOutNdFilter                          ,0xff2ec5c8) //102
NSTUB(Read                                    ,0xff00ad68) //101
NSTUB(ReadFastDir                             ,0xff2c99b8) //  6
NSTUB(Rec2PB                                  ,0xff09280c) //104
NSTUB(RefreshPhysicalScreen                   ,0xff0a6da4) //104
NSTUB(Remove                                  ,0xff028198) //  6
NSTUB(RenameFile_Fut                          ,0xff0278a8) //  6
NSTUB(Restart                                 ,0xff02d620) //106
NSTUB(ScreenLock                              ,0xff0a7f9c) //  4
NSTUB(ScreenUnlock                            ,0xff0a8000) //  3
NSTUB(SetAE_ShutterSpeed                      ,0xff3647cc) //102
NSTUB(SetAutoShutdownTime                     ,0xff08f724) //103
NSTUB(SetCurrentCaptureModeType               ,0xff097c44) //101
NSTUB(SetFileAttributes                       ,0xff028428) //  6
NSTUB(SetFileTimeStamp                        ,0xff0283b0) //  6
NSTUB(SetLogicalEventActive                   ,0xff08f42c) //101
NSTUB(SetParameterData                        ,0xff1b4b8c) //101
NSTUB(SetPropertyCase                         ,0xff08a1d4) //102
NSTUB(SetScriptMode                           ,0xff08f47c) //101
NSTUB(SleepTask                               ,0xff02baac) //101
NSTUB(TakeSemaphore                           ,0xff02b730) //101
NSTUB(TurnOffBackLight                        ,0xff09f01c) //104
NSTUB(TurnOnBackLight                         ,0xff09f004) //104
NSTUB(UIFS_WriteFirmInfoToFile                ,0xff1a1c1c) //101
NSTUB(UnlockAF                                ,0xff029904) //102
NSTUB(UnlockMainPower                         ,0xff08f604) //103
NSTUB(VbattGet                                ,0xff023148) //101
NSTUB(Write                                   ,0xff028078) //101
NSTUB(WriteSDCard                             ,0xff16a9b4) //108
NSTUB(_log                                    ,0xff3a3338) //111
NSTUB(_log10                                  ,0xff3a3878) //112
NSTUB(_pow                                    ,0xff3a39f0) //114
NSTUB(_sqrt                                   ,0xff3a5614) //  6
NSTUB(add_ptp_handler                         ,0xff2783c4) //  6
NSTUB(apex2us                                 ,0xff236100) //  4
NSTUB(close                                   ,0xff00abc4) //  6
NSTUB(closedir                                ,0xff2c9814) //  4
NSTUB(err_init_task                           ,0xff006020) //  4
NSTUB(exmem_alloc                             ,0xff084b14) //101
NSTUB(free                                    ,0xff004258) //112
NSTUB(kbd_p1_f                                ,0xff025864) //109
NSTUB(kbd_p1_f_cont                           ,0xff025870) //109
NSTUB(kbd_p2_f                                ,0xff025044) //109
NSTUB(kbd_read_keys                           ,0xff025814) //109
NSTUB(kbd_read_keys_r2                        ,0xff0579c8) //109
NSTUB(lseek                                   ,0xff028240) //101
NSTUB(malloc                                  ,0xff004200) //112
NSTUB(memcmp                                  ,0xff010a14) //101
NSTUB(memcpy                                  ,0xff03152c) //101
NSTUB(memset                                  ,0xff234138) //101
NSTUB(mkdir                                   ,0xff0284c0) //  6
NSTUB(mktime_ext                              ,0xff0a8df0) //  1
NSTUB(open                                    ,0xff00ab14) //  6
NSTUB(opendir                                 ,0xff2c9864) //  6
NSTUB(openfastdir                             ,0xff2c9864) //  6
NSTUB(qsort                                   ,0xff342dbc) //  6
NSTUB(rand                                    ,0xff234274) //  6
NSTUB(read                                    ,0xff00ad68) //101
NSTUB(reboot_fw_update                        ,0xff2ceef8) //  6
NSTUB(rename                                  ,0xff0278a8) //  6
NSTUB(set_control_event                       ,0xff08f0ec) //111
NSTUB(srand                                   ,0xff234268) //  6
NSTUB(stat                                    ,0xff028288) //  3
NSTUB(strcat                                  ,0xff0a85a8) //  1
NSTUB(strchr                                  ,0xff0040cc) //  1
NSTUB(strcmp                                  ,0xff0109d0) //101
NSTUB(strcpy                                  ,0xff0109b8) //101
NSTUB(strftime                                ,0xff0a87f0) //113
NSTUB(strlen                                  ,0xff004118) //101
NSTUB(strncmp                                 ,0xff004080) //  1
NSTUB(strncpy                                 ,0xff004044) //  1
NSTUB(strrchr                                 ,0xff0040f0) //  1
NSTUB(strtol                                  ,0xff03182c) //101
NSTUB(strtolx                                 ,0xff031630) //109
  DEF(task_CaptSeq                            ,0xff0769f8) //110
  DEF(task_ExpDrv                             ,0xff0c0e24) //110
  DEF(task_InitFileModules                    ,0xff09301c) //110
  DEF(task_MovieRecord                        ,0xff186748) //110
  DEF(task_PhySw                              ,0xff0253a8) //110
NSTUB(time                                    ,0xff084130) //  6
NSTUB(vsprintf                                ,0xff010978) //  6
NSTUB(write                                   ,0xff028078) //101
