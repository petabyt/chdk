// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R23 (DRYOS version 2.3, release #0023)
//   Firmware Ver GM1.00C
//   Canon PowerShot A580

// Values for makefile.inc
//   PLATFORMOSVER = 23
//   PLATFORMID = 12663 (0x3177) // Found @ 0xfffe0130
//   MAXRAMADDR = 0x01ffffff
//   KEYSYS = d3enc              // Found @ 0xffff1ac0
//   NEED_ENCODED_DISKBOOT = 1   // Found @ 0xffff1aa0

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NHSTUB(kbd_pwr_off                          ,0xffc3193c) //  2 67%    *** != 0x00000000
NHSTUB(kbd_pwr_on                             ,0xffc318fc) //  2 86%

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ffc60014 -> ffc5cbf0 -> ffd2bdd4 -> ffdf11e4 -> ffe9ed50
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x0000ebdc) // Found @0xffc11c24
DEF(physw_run                               ,0x00001bf0) // Found @0xffc118c0
DEF(physw_sleep_delay                       ,0x00001bee) // Found @0xffc118c0
DEF(levent_table                            ,0xffe7fb44) // Found @0xffe7fb44
DEF(FlashParamsTable                        ,0xffe9ef08) // Found @0xffe9ef08
DEF(movie_status                            ,0x000051b0) // Found @0xffc46414
DEF(canon_menu_active                       ,0x00008bdc) // Found @0xffd2170c
DEF(canon_shoot_menu_active                 ,0x000094b9) // Found @0xffd3a7e0
DEF(playrec_mode                            ,0x00005320) // Found @0xffc4c9f4
DEF(zoom_status                             ,0x0000ba7c) // Found @0xffdf29e4
DEF(some_flag_for_af_scan                   ,0x0000b808) // Found @0xffde1abc
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 3 int value(s), the first is the zoom focus length.
// there are 8 entries in the table - set NUM_FL to 8
DEF(focus_len_table                         ,0xfffe297c) // Found @0xfffe297c
DEF(zoom_busy                               ,0x00007f4c) // Found @0xffd085dc
//DEF(focus_busy                              ,0x00007e58) // Found @0xffd04170, ** != ** stubs_min = 0x00009d50 (0x9D50)
//DEF(recreview_hold                          ,0x00005b14) // Found @0xffc64f18, ** != ** stubs_min = 0x0000abe8 (0xABE8)

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x10361000; }             // Found @0xffc2d5c4
//void *vid_get_viewport_fb()      { return (void*)0x10659e80; }             // Found @0xffe36590
DEF(viewport_fb_d                           ,0x0000509c) // Found 0x5050 (@0xffc415bc) + 0x4c (@0xffc415f4)
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x5050+0x4c)); } // Found @0xffc415bc & 0xffc415f4
DEF(jpeg_count_str                          ,0x00048ae0) // Found @0xffd67320
//char *camera_jpeg_count_str()    { return (char*)0x00048ae0; }             // Found @0xffd67320
//long hook_raw_size()             { return 0x009e6fc4; }                    // Found @0xffe3881c
//int get_flash_params_count(void) { return 0x73; }                          // Found @0xffd2ce90

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffe5c768, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x00040000 // Found @0xffe5c774, levent 0x902
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 1, KEY_POWER           ,0x00004000 }, // Found @0xffe5c630, levent 0x600 (uses inverted logic in physw_status)
//    { 1, KEY_SHOOT_FULL      ,0xc0000000 }, // Found @0xffe5c690, levent 0x01
//    { 1, KEY_SHOOT_FULL_ONLY ,0x80000000 }, // Found @0xffe5c690, levent 0x01
//    { 1, KEY_SHOOT_HALF      ,0x40000000 }, // Found @0xffe5c684, levent 0x00
//    { 2, KEY_ZOOM_IN         ,0x00000004 }, // Found @0xffe5c6b4, levent 0x02
//    { 2, KEY_ZOOM_OUT        ,0x00000008 }, // Found @0xffe5c6c0, levent 0x03
//    { 2, KEY_UP              ,0x00000010 }, // Found @0xffe5c6cc, levent 0x04
//    { 2, KEY_DOWN            ,0x00000020 }, // Found @0xffe5c6d8, levent 0x05
//    { 2, KEY_RIGHT           ,0x00000040 }, // Found @0xffe5c6e4, levent 0x07
//    { 2, KEY_LEFT            ,0x00000080 }, // Found @0xffe5c6f0, levent 0x06
//    { 2, KEY_SET             ,0x00000100 }, // Found @0xffe5c6fc, levent 0x08
//    { 2, KEY_MENU            ,0x00000200 }, // Found @0xffe5c708, levent 0x09
//    { 2, KEY_DISPLAY         ,0x00000400 }, // Found @0xffe5c714, levent 0x0a
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_RAW_ROWPIX    3336 // Found @0xffe2ff80
//#define CAM_RAW_ROWS      2490 // Found @0xffe2ff84
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x10000000 // Found @0xffc17e64

// Misc stuff
DEF(ctypes, 0xffe5c222)

// For capt_seq.c
DEF(_nrflag,0x8450) // Found @ ffd0f424 (0x8450)
//static long *nrflag = (long*)(0x8450);       // Found @ ffd0f424

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
//NHSTUB(CreateJumptable                      ,0xffe389e4) //  1
//NHSTUB(_uartr_req                           ,0xffc0ce68) //111
//NHSTUB(AllocateMemory                       ,0xffde4fd4) //101
NHSTUB(AllocateUncacheableMemory              ,0xffc17e28) //112
NHSTUB(Close                                  ,0xffc13b7c) //101
NHSTUB(CreateTask                             ,0xffc0b8e0) //101
NHSTUB(DebugAssert                            ,0xffc0bdb8) //111
NHSTUB(DeleteDirectory_Fut                    ,0xffc1350c) //116
NHSTUB(DeleteFile_Fut                         ,0xffc13428) //112
NHSTUB(DoAFLock                               ,0xffc157b4) //102
NHSTUB(EnterToCompensationEVF                 ,0xffc15aa4) //104
NHSTUB(ExecuteEventProcedure                  ,0xffc5459c) //104
NHSTUB(ExitFromCompensationEVF                ,0xffc15bf0) //104
NHSTUB(ExitTask                               ,0xffc0bb70) //101
NHSTUB(ExpCtrlTool_StartContiAE               ,0xffc218b8) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xffc219fc) //104
NHSTUB(Fclose_Fut                             ,0xffc135a4) //101
NHSTUB(Feof_Fut                               ,0xffc13790) //  1
NHSTUB(Fflush_Fut                             ,0xffc137cc) //  1
NHSTUB(Fgets_Fut                              ,0xffc136f8) //  1
NHSTUB(Fopen_Fut                              ,0xffc13564) //101
NHSTUB(Fread_Fut                              ,0xffc13650) //101
//NHSTUB(FreeMemory                           ,0xffde4fcc) //101
NHSTUB(FreeUncacheableMemory                  ,0xffc17e5c) //112
NHSTUB(Fseek_Fut                              ,0xffc13744) //101
NHSTUB(Fwrite_Fut                             ,0xffc136a4) //101
NHSTUB(GetBatteryTemperature                  ,0xffc33a38) //102
NHSTUB(GetCCDTemperature                      ,0xffc339c8) //102
NHSTUB(GetCurrentAvValue                      ,0xffd05b84) //102
NHSTUB(GetDrive_ClusterSize                   ,0xffc3d914) //  1
NHSTUB(GetDrive_FreeClusters                  ,0xffc3d97c) //  1
NHSTUB(GetDrive_TotalClusters                 ,0xffc3d948) //  1
NHSTUB(GetFocusLensSubjectDistance            ,0xffd04c7c) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xffd04f88) //  1
NHSTUB(GetKbdState                            ,0xffc318c8) //109
NHSTUB(GetMemInfo                             ,0xffc03c40) //115
NHSTUB(GetOpticalTemperature                  ,0xffc33aa8) //102
NHSTUB(GetParameterData                       ,0xffd2ce50) //101
NHSTUB(GetPropertyCase                        ,0xffc5819c) //102
NHSTUB(GetSystemTime                          ,0xffde502c) //101
NHSTUB(GetVRAMHPixelsSize                     ,0xffca3318) //102
NHSTUB(GetVRAMVPixelsSize                     ,0xffca3324) //102
NHSTUB(GetZoomLensCurrentPoint                ,0xffd08940) //102
NHSTUB(GetZoomLensCurrentPosition             ,0xffddc3ac) //102
NHSTUB(GiveSemaphore                          ,0xffc0b844) //112
NHSTUB(IsStrobeChargeCompleted                ,0xffc981b0) //102
NHSTUB(LEDDrive                               ,0xffc30f6c) //103
NHSTUB(LocalTime                              ,0xffc522bc) //115
NHSTUB(LockMainPower                          ,0xffc5c808) //103
//NHSTUB(Lseek                                ,0xffc13cbc) //101
NHSTUB(MakeDirectory_Fut                      ,0xffc1349c) //116
NHSTUB(MoveFocusLensToDistance                ,0xffe330bc) //102
NHSTUB(MoveIrisWithAv                         ,0xffde12f0) //102
NHSTUB(MoveZoomLensWithPoint                  ,0xffde1874) //102
//NHSTUB(NewTaskShell                         ,0xffc57c60) //103
NHSTUB(Open                                   ,0xffc13b54) //101
NHSTUB(PB2Rec                                 ,0xffc5f428) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xffc47a88) //102
NHSTUB(PT_MoveOpticalZoomAt                   ,0xffc47a60) //102
NHSTUB(PT_PlaySound                           ,0xffc47374) //102
NHSTUB(PostLogicalEventForNotPowerType        ,0xffc5be78) //103
NHSTUB(PostLogicalEventToUI                   ,0xffc5bec4) //103
NHSTUB(PutInNdFilter                          ,0xffde16d8) //102
NHSTUB(PutOutNdFilter                         ,0xffde16fc) //102
NHSTUB(Read                                   ,0xffc0a15c) //101
NHSTUB(ReadFastDir                            ,0xffdce864) //  1
NHSTUB(Rec2PB                                 ,0xffc5f458) //104
NHSTUB(RefreshPhysicalScreen                  ,0xffd70a80) //104
//NHSTUB(Remove                               ,0xffc13bc4) //  1
NHSTUB(RenameFile_Fut                         ,0xffc133d4) //  1
NHSTUB(Restart                                ,0xffc196a0) //106
NHSTUB(SetAE_ShutterSpeed                     ,0xffe357a0) //102
NHSTUB(SetAutoShutdownTime                    ,0xffc5c87c) //103
NHSTUB(SetCurrentCaptureModeType              ,0xffc62ac4) //101
NHSTUB(SetFileAttributes                      ,0xffc13ea8) //  1
NHSTUB(SetFileTimeStamp                       ,0xffc13e58) //  1
NHSTUB(SetLogicalEventActive                  ,0xffc5c5a4) //  1
NHSTUB(SetParameterData                       ,0xffd2cdc0) //101
NHSTUB(SetPropertyCase                        ,0xffc5809c) //102
NHSTUB(SetScriptMode                          ,0xffc5c5f4) //101
NHSTUB(SleepTask                              ,0xffc17cac) //101
NHSTUB(TakeSemaphore                          ,0xffc0b774) //101
NHSTUB(TurnOffBackLight                       ,0xffc66d58) //104
NHSTUB(TurnOnBackLight                        ,0xffc66d40) //104
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xffd220a8) //103
NHSTUB(UnlockAF                               ,0xffc158cc) //102
NHSTUB(UnlockMainPower                        ,0xffc5c75c) //103
NHSTUB(UnsetZoomForMovie                      ,0xffd31f0c) //104
NHSTUB(UpdateMBROnFlash                       ,0xffc3d754) //105
NHSTUB(VbattGet                               ,0xffc105e8) //103
NHSTUB(Write                                  ,0xffc13c28) //101
NHSTUB(WriteSDCard                            ,0xffcfaf54) //108
NHSTUB(_log                                   ,0xffe5a028) //111
NHSTUB(_log10                                 ,0xffe58f6c) //112
NHSTUB(_pow                                   ,0xffe590dc) //114
NHSTUB(_sqrt                                  ,0xffe5b390) //  1
NHSTUB(add_ptp_handler                        ,0xffd9fb1c) //  1
NHSTUB(apex2us                                ,0xffd71fbc) //  4
NHSTUB(close                                  ,0xffc09f74) //  1
NHSTUB(closedir                               ,0xffdce934) //  1
NHSTUB(err_init_task                          ,0xffc04e98) //111
NHSTUB(exmem_alloc                            ,0xffc52d84) //103
NHSTUB(exmem_free                             ,0xffc52dfc) //103
NHSTUB(free                                   ,0xffc03a98) //112
NHSTUB(kbd_p1_f                               ,0xffc11d28) //109
NHSTUB(kbd_p1_f_cont                          ,0xffc11d34) //109
NHSTUB(kbd_p2_f                               ,0xffc11560) //109
NHSTUB(kbd_read_keys                          ,0xffc11c24) //109
NHSTUB(kbd_read_keys_r2                       ,0xffc3138c) //109
NHSTUB(lseek                                  ,0xffc13cbc) //101
NHSTUB(malloc                                 ,0xffc039c4) //112
NHSTUB(memcmp                                 ,0xffc0d90c) //101
NHSTUB(memcpy                                 ,0xffc6f708) //101
NHSTUB(memset                                 ,0xffd70e34) //101
NHSTUB(mkdir                                  ,0xffc13f20) //109
NHSTUB(mktime_ext                             ,0xffc6ff74) //  1
NHSTUB(open                                   ,0xffc09ec4) //  1
NHSTUB(OpenFastDir                            ,0xffdce7d0) //  1
NHSTUB(qsort                                  ,0xffd7133c) //  1
NHSTUB(rand                                   ,0xffc0da14) //  1
//NHSTUB(read                                 ,0xffc0a15c) //101
NHSTUB(realloc                                ,0xffc03b78) //115
NHSTUB(reboot_fw_update                       ,0xffdd3138) //106
NHSTUB(set_control_event                      ,0xffc5c2f8) //  1
NHSTUB(srand                                  ,0xffc0da08) //  1
NHSTUB(stat                                   ,0xffc13d88) //  1
NHSTUB(strcat                                 ,0xffc6f4f4) //  1
NHSTUB(strchr                                 ,0xffc6f57c) //  1
NHSTUB(strcmp                                 ,0xffc0d8a4) //101
NHSTUB(strcpy                                 ,0xffc0d88c) //101
NHSTUB(strftime                               ,0xffc6f97c) //  1
NHSTUB(strlen                                 ,0xffc0d8e8) //101
NHSTUB(strncmp                                ,0xffc6f530) //  1
NHSTUB(strncpy                                ,0xffc1d80c) //  1
NHSTUB(strrchr                                ,0xffc6f5a0) //  1
NHSTUB(strtol                                 ,0xffc1da44) //101
NHSTUB(strtolx                                ,0xffc1d848) //109
   DEF(task_CaptSeq                           ,0xffc49b38) //110
   DEF(task_ExpDrv                            ,0xffc91194) //110
   DEF(task_InitFileModules                   ,0xffc5fea0) //110
   DEF(task_MovieRecord                       ,0xffc46678) //110
   DEF(task_PhySw                             ,0xffc118bc) //110
NHSTUB(time                                   ,0xffc52170) //109
NHSTUB(vsprintf                               ,0xffc0d80c) //115
//NHSTUB(write                                ,0xffc13c28) //101
//NHSTUB(EngDrvIn                             ,0xffc12b60) //102
//NHSTUB(EngDrvOut                            ,0xffc12b48) //102
//NHSTUB(EngDrvRead                           ,0xffc12b68) //102
//NHSTUB(EngDrvBits                           ,0xffc12b7c) //102
//NHSTUB(GetSDProtect                         ,0xffc11c04) //103
//NHSTUB(StartRecModeMenu                     ,0xffd21708) //102
//NHSTUB(DispCon_ShowBitmapColorBar           ,0xffc2d590) //102
//NHSTUB(ResetZoomLens                        ,0xffde17c8) //102
//NHSTUB(ResetFocusLens                       ,0xffde07d0) //102
//NHSTUB(NR_GetDarkSubType                    ,0xffd10550) //102
//NHSTUB(NR_SetDarkSubType                    ,0xffd104dc) //102
//NHSTUB(SavePaletteData                      ,0xffe377fc) //102
