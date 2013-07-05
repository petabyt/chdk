// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R23 (DRYOS version 2.3, release #0023)
//   Firmware Ver GM1.00B
//   Canon PowerShot SX100 IS

// Values for makefile.inc
//   PLATFORMOSVER = 23
//   PLATFORMID = 12638 (0x315e) // Found @ 0xfffe0130
//   MAXRAMADDR = 0x01ffffff
//   MEMISOSTART = 0x0009f498
//   KEYSYS = d3                 // Found @ 0xffff1a04
//   NEED_ENCODED_DISKBOOT = 1   // Found @ 0xffff19e4

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NHSTUB(GetZoomLensCurrentPosition           ,0xffdeac68) //102        *** != 0xffd0e36c
//NHSTUB(MoveFocusLensToDistance              ,0xffdc0d2c) //102        *** != 0xffdc0c60
//NHSTUB(kbd_pwr_off                          ,0xffc37f10) //  2 67%    *** != 0x00000000
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ffc636cc -> ffc5fae8 -> ffd257ec -> ffdf5da4 -> ffe9e7ec
// Mode  2598 in firmware but not in current modemap
// Current modemap entry not found in firmware - MODE_INDOOR              32785

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00010c1c) // Found @0xffc130f4
DEF(physw_run                               ,0x00001ca4) // Found @0xffc12da0
DEF(physw_sleep_delay                       ,0x00001ca2) // Found @0xffc12da0
DEF(levent_table                            ,0xffe7cb2c) // Found @0xffe7cb2c
DEF(FlashParamsTable                        ,0xffe9e9a4) // Found @0xffe9e9a4
DEF(movie_status                            ,0x00005588) // Found @0xffc4abb0
DEF(canon_menu_active                       ,0x0000bafc) // Found @0xffd60bac
DEF(canon_shoot_menu_active                 ,0x0000b1fd) // Found @0xffd38074
DEF(playrec_mode                            ,0x00005724) // Found @0xffc51650
DEF(zoom_status                             ,0x0000de14) // Found @0xffdf759c
DEF(some_flag_for_af_scan                   ,0x0000dd08) // Found @0xffdef954
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 3 int value(s), the first is the zoom focus length.
// there are 23 entries in the table - set NUM_FL to 23
DEF(focus_len_table                         ,0xfffe31ac) // Found @0xfffe31ac
DEF(zoom_busy                               ,0x0000a424) // Found @0xffd0e030
DEF(focus_busy                              ,0x0000a318) // Found @0xffd08328
//DEF(recreview_hold                          ,0x000061d8) // Found @0xffc68cc0, ** != ** stubs_min = 0x0000af6c (0xAF6C)
// Camera appears to have only 1 RAW buffer @ 0x10f6c860 (Found @0xffdc5d2c)

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x10361000; }             // Found @0xffc33cb8
//void *vid_get_viewport_fb()      { return (void*)0x1065a4d0; }             // Found @0xffdc3e8c
DEF(viewport_fb_d                           ,0x00005424) // Found 0x53d8 (@0xffc44160) + 0x4c (@0xffc44198)
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x53d8+0x4c)); } // Found @0xffc44160 & 0xffc44198
DEF(jpeg_count_str                          ,0x00059a1c) // Found @0xffd6d324
//char *camera_jpeg_count_str()    { return (char*)0x00059a1c; }             // Found @0xffd6d324
//long hook_raw_size()             { return 0x009dcce0; }                    // Found @0xffdc5d88
//int get_flash_params_count(void) { return 0x72; }                          // Found @0xffd268a8

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffe5f9c8, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x00040000 // Found @0xffe5f9d0, levent 0x902
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_SHOOT_FULL      ,0x0000000c }, // Found @0xffe5f908, levent 0x01
//    { 0, KEY_SHOOT_FULL_ONLY ,0x00000008 }, // Found @0xffe5f908, levent 0x01
//    { 0, KEY_SHOOT_HALF      ,0x00000004 }, // Found @0xffe5f900, levent 0x00
//    { 0, KEY_POWER           ,0x00004000 }, // Found @0xffe5f910, levent 0x600 (uses inverted logic in physw_status)
//    { 0, KEY_PLAYBACK        ,0x00800000 }, // Found @0xffe5f928, levent 0x601 (uses inverted logic in physw_status)
//    { 1, KEY_ZOOM_IN         ,0x00000100 }, // Found @0xffe5f958, levent 0x02
//    { 1, KEY_ZOOM_OUT        ,0x00000200 }, // Found @0xffe5f960, levent 0x03
//    { 1, KEY_SET             ,0x00010000 }, // Found @0xffe5f968, levent 0x08
//    { 1, KEY_UP              ,0x00020000 }, // Found @0xffe5f970, levent 0x04
//    { 1, KEY_LEFT            ,0x00040000 }, // Found @0xffe5f978, levent 0x06
//    { 1, KEY_DOWN            ,0x00080000 }, // Found @0xffe5f980, levent 0x05
//    { 1, KEY_RIGHT           ,0x00100000 }, // Found @0xffe5f988, levent 0x07
//    { 1, KEY_MENU            ,0x02000000 }, // Found @0xffe5f998, levent 0x09
//    { 1, KEY_DISPLAY         ,0x04000000 }, // Found @0xffe5f9a0, levent 0x0a
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_RAW_ROWPIX    3336 // Found @0xffdbdd8c
//#define CAM_RAW_ROWS      2480 // Found @0xffdbdd94
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x10000000 // Found @0xffc19e6c

// Misc stuff
DEF(ctypes, 0xffe5a47e)

// For capt_seq.c
DEF(_nrflag,0xa5fc) // Found @ ffd15b90 (0xa5fc)
//static long *nrflag = (long*)(0xa5fc);       // Found @ ffd15b90

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
//NHSTUB(CreateJumptable                      ,0xffdc62a8) //  1
//NHSTUB(_uartr_req                           ,0xffc0ddb8) //111
//NHSTUB(StartRecModeMenu                     ,0xffd60ba8) //102
//NHSTUB(AllocateMemory                       ,0xffdf2ec0) //103
NHSTUB(AllocateUncacheableMemory              ,0xffc19e30) //112
NHSTUB(Close                                  ,0xffc1504c) //101
//NHSTUB(CreateBinarySemaphore                ,0xffc0b8e8) //115
//NHSTUB(CreateCountingSemaphore              ,0xffc0b950) //105
NHSTUB(CreateTask                             ,0xffc0bbb8) //101
NHSTUB(DebugAssert                            ,0xffc0c090) //111
NHSTUB(DeleteDirectory_Fut                    ,0xffc14998) //116
NHSTUB(DeleteFile_Fut                         ,0xffc148b4) //112
//NHSTUB(DeleteSemaphore                      ,0xffc0b9a8) //105
NHSTUB(DoAFLock                               ,0xffc16f5c) //103
NHSTUB(EnterToCompensationEVF                 ,0xffc172d4) //104
NHSTUB(ExecuteEventProcedure                  ,0xffc0c270) //104
NHSTUB(ExitFromCompensationEVF                ,0xffc17324) //104
NHSTUB(ExitTask                               ,0xffc0be48) //101
NHSTUB(ExpCtrlTool_StartContiAE               ,0xffc249b8) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xffc24b78) //104
NHSTUB(Fclose_Fut                             ,0xffc14a30) //101
NHSTUB(Feof_Fut                               ,0xffc14c1c) //  1
NHSTUB(Fflush_Fut                             ,0xffc14c58) //  1
NHSTUB(Fgets_Fut                              ,0xffc14b84) //  1
NHSTUB(Fopen_Fut                              ,0xffc149f0) //101
NHSTUB(Fread_Fut                              ,0xffc14adc) //101
//NHSTUB(FreeMemory                           ,0xffdf2eac) //103
NHSTUB(FreeUncacheableMemory                  ,0xffc19e64) //112
NHSTUB(Fseek_Fut                              ,0xffc14bd0) //101
NHSTUB(Fwrite_Fut                             ,0xffc14b30) //101
NHSTUB(GetBatteryTemperature                  ,0xffc3a31c) //102
NHSTUB(GetCCDTemperature                      ,0xffc3a2ac) //102
NHSTUB(GetCurrentAvValue                      ,0xffd0afd4) //102
NHSTUB(GetDrive_ClusterSize                   ,0xffc4066c) //  1
NHSTUB(GetDrive_FreeClusters                  ,0xffc4070c) //  1
NHSTUB(GetDrive_TotalClusters                 ,0xffc406a0) //  1
NHSTUB(GetFocusLensSubjectDistance            ,0xffd08e68) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xffd09174) //  1
NHSTUB(GetKbdState                            ,0xffc37dc0) //109
NHSTUB(GetMemInfo                             ,0xffc03c58) //115
NHSTUB(GetOpticalTemperature                  ,0xffc3a38c) //102
NHSTUB(GetParameterData                       ,0xffd26868) //101
NHSTUB(GetPropertyCase                        ,0xffc5bc8c) //101
NHSTUB(GetSystemTime                          ,0xffdf2fc8) //  1
NHSTUB(GetVRAMHPixelsSize                     ,0xffc2cd38) //102
NHSTUB(GetVRAMVPixelsSize                     ,0xffc2cd44) //102
NHSTUB(GetZoomLensCurrentPoint                ,0xffd0e394) //102
NHSTUB(GiveSemaphore                          ,0xffc0bb24) //112
NHSTUB(IsStrobeChargeCompleted                ,0xffc9ef68) //102
NHSTUB(LEDDrive                               ,0xffc373b4) //103
NHSTUB(LocalTime                              ,0xffc580b8) //115
NHSTUB(LockMainPower                          ,0xffc5f714) //103
//NHSTUB(Lseek                                ,0xffc1518c) //101
NHSTUB(MakeDirectory_Fut                      ,0xffc14928) //116
NHSTUB(MoveIrisWithAv                         ,0xffd0b3b4) //102
NHSTUB(MoveZoomLensWithPoint                  ,0xffd0ee40) //102
//NHSTUB(NewTaskShell                         ,0xffc5b710) //103
NHSTUB(Open                                   ,0xffc15024) //101
NHSTUB(PB2Rec                                 ,0xffc62938) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xffc5342c) //103
NHSTUB(PT_MoveOpticalZoomAt                   ,0xffc533f4) //103
NHSTUB(PT_PlaySound                           ,0xffc52fa0) //103
NHSTUB(PostLogicalEventForNotPowerType        ,0xffc5d6b0) //103
NHSTUB(PostLogicalEventToUI                   ,0xffc5d6fc) //103
NHSTUB(PutInNdFilter                          ,0xffdbf138) //102
NHSTUB(PutOutNdFilter                         ,0xffdbf170) //102
NHSTUB(Read                                   ,0xffc0a440) //101
NHSTUB(ReadFastDir                            ,0xffddc67c) //  1
NHSTUB(Rec2PB                                 ,0xffc61564) //104
NHSTUB(RefreshPhysicalScreen                  ,0xffd79fa0) //104
//NHSTUB(Remove                               ,0xffc15094) //  1
NHSTUB(RenameFile_Fut                         ,0xffc14860) //  1
NHSTUB(Restart                                ,0xffc1be8c) //106
NHSTUB(SetAE_ShutterSpeed                     ,0xffdc3088) //102
NHSTUB(SetAutoShutdownTime                    ,0xffc5f788) //103
NHSTUB(SetCurrentCaptureModeType              ,0xffc66210) //101
NHSTUB(SetFileAttributes                      ,0xffc15378) //  1
NHSTUB(SetFileTimeStamp                       ,0xffc15328) //  1
NHSTUB(SetLogicalEventActive                  ,0xffc5f44c) //  1
NHSTUB(SetParameterData                       ,0xffd267d8) //101
NHSTUB(SetPropertyCase                        ,0xffc5bb84) //103
NHSTUB(SetScriptMode                          ,0xffc5f49c) //101
NHSTUB(SleepTask                              ,0xffc19cb8) //101
NHSTUB(TakeSemaphore                          ,0xffc0ba54) //101
NHSTUB(TurnOffBackLight                       ,0xffc6bd54) //104
NHSTUB(TurnOnBackLight                        ,0xffc6bd3c) //104
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xffd61640) //103
NHSTUB(UnlockAF                               ,0xffc16fc8) //103
NHSTUB(UnlockMainPower                        ,0xffc5f668) //103
NHSTUB(UnsetZoomForMovie                      ,0xffd2cf98) //104
NHSTUB(UpdateMBROnFlash                       ,0xffc40434) //105
NHSTUB(VbattGet                               ,0xffc119cc) //101
NHSTUB(Write                                  ,0xffc150f8) //101
NHSTUB(WriteSDCard                            ,0xffcff4e8) //108
NHSTUB(_log                                   ,0xffe57ff0) //111
NHSTUB(_log10                                 ,0xffe56f34) //112
NHSTUB(_pow                                   ,0xffe570a4) //114
NHSTUB(_sqrt                                  ,0xffe59358) //  1
NHSTUB(add_ptp_handler                        ,0xffcb53a4) //  1
NHSTUB(apex2us                                ,0xffd7b458) //  4
NHSTUB(close                                  ,0xffc0a258) //  1
NHSTUB(closedir                               ,0xffddc74c) //  1
NHSTUB(err_init_task                          ,0xffc04eb0) //111
NHSTUB(exmem_alloc                            ,0xffc58ba4) //102
NHSTUB(exmem_free                             ,0xffc58c1c) //102
NHSTUB(free                                   ,0xffc03ab0) //112
NHSTUB(kbd_p1_f                               ,0xffc131f0) //109
NHSTUB(kbd_p1_f_cont                          ,0xffc131fc) //109
NHSTUB(kbd_p2_f                               ,0xffc12a40) //109
NHSTUB(kbd_read_keys                          ,0xffc130f4) //109
NHSTUB(kbd_read_keys_r2                       ,0xffc378cc) //109
NHSTUB(lseek                                  ,0xffc1518c) //101
NHSTUB(malloc                                 ,0xffc039dc) //112
NHSTUB(memcmp                                 ,0xffc0e8f0) //101
NHSTUB(memcpy                                 ,0xffc76644) //101
NHSTUB(memset                                 ,0xffe2aa8c) //101
NHSTUB(mkdir                                  ,0xffc153f0) //109
NHSTUB(mktime_ext                             ,0xffc76eb0) //  1
NHSTUB(open                                   ,0xffc0a1a8) //  1
NHSTUB(OpenFastDir                            ,0xffddc5e8) //  1
NHSTUB(qsort                                  ,0xffd7a830) //  1
NHSTUB(rand                                   ,0xffc0e9f8) //  1
//NHSTUB(read                                 ,0xffc0a440) //101
NHSTUB(realloc                                ,0xffc03b90) //115
NHSTUB(reboot_fw_update                       ,0xffde101c) //106
NHSTUB(set_control_event                      ,0xffc5f150) //  1
NHSTUB(srand                                  ,0xffc0e9ec) //  1
NHSTUB(stat                                   ,0xffc15258) //  1
NHSTUB(strcat                                 ,0xffc76570) //  1
NHSTUB(strchr                                 ,0xffc765f8) //  1
NHSTUB(strcmp                                 ,0xffc0e888) //101
NHSTUB(strcpy                                 ,0xffc0e834) //101
NHSTUB(strftime                               ,0xffc768b8) //  1
NHSTUB(strlen                                 ,0xffc0e8cc) //101
NHSTUB(strncmp                                ,0xffc765ac) //  1
NHSTUB(strncpy                                ,0xffc0e84c) //  1
NHSTUB(strrchr                                ,0xffc7661c) //  1
NHSTUB(strtol                                 ,0xffc20338) //101
NHSTUB(strtolx                                ,0xffc2013c) //109
   DEF(task_CaptSeq                           ,0xffc4e2ac) //110
   DEF(task_ExpDrv                            ,0xffc98ee4) //110
   DEF(task_FileWrite                         ,0xffdda764) //110
   DEF(task_InitFileModules                   ,0xffc63558) //110
   DEF(task_MovieRecord                       ,0xffc4ae14) //110
   DEF(task_PhySw                             ,0xffc12d9c) //110
NHSTUB(time                                   ,0xffc57f6c) //109
NHSTUB(vsprintf                               ,0xffc0e7b4) //115
//NHSTUB(write                                ,0xffc150f8) //101
//NHSTUB(EngDrvIn                             ,0xffc13fec) //102
//NHSTUB(EngDrvOut                            ,0xffc13fd4) //102
//NHSTUB(EngDrvRead                           ,0xffc13ff4) //102
//NHSTUB(EngDrvBits                           ,0xffc14008) //102
//NHSTUB(GetSDProtect                         ,0xffc130bc) //102
//NHSTUB(DispCon_ShowBitmapColorBar           ,0xffc33c84) //102
//NHSTUB(ResetZoomLens                        ,0xffd0ed94) //102
//NHSTUB(ResetFocusLens                       ,0xffd09988) //102
//NHSTUB(NR_GetDarkSubType                    ,0xffd16d10) //102
//NHSTUB(NR_SetDarkSubType                    ,0xffd16c9c) //102
//NHSTUB(SavePaletteData                      ,0xffdc5114) //102
