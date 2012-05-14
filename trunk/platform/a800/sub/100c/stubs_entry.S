// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R47 (DRYOS version 2.3, release #0047)
//   Firmware Ver GM1.00C
//   Canon PowerShot A800

// Values for makefile.inc
//   PLATFORMOSVER = 47
//   PLATFORMID = 12838 (0x3226) // Found @ 0xfffe0040
//   MAXRAMADDR = 0x01ffffff
//   KEYSYS = d4c                // Found @ 0xffff1a20
//   NEED_ENCODED_DISKBOOT = 6   // Found @ 0xffff1a30

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NSTUB(GetBatteryTemperature                 ,0xffc45dec) //102        *** != 0x00000000
NSTUB(kbd_pwr_off                             ,0xffc43e84) //  2 60%
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0x00000000
//NSTUB(mkdir                                 ,0xffc267f8) //  6 53%    *** != 0xffc267fc
// ERROR: rand is not found.                               //--- ---    *** != 0x00000000
// ERROR: srand is not found.                              //--- ---    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ffc739fc -> ffc7069c -> ffd39ee8 -> ffe267b8 -> ffee9f18
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x0002f048) // Found @0xffc23c3c
DEF(physw_run                               ,0x00001bf8) // Found @0xffc237fc
DEF(levent_table                            ,0xffeba314) // Found @0xffeba314
DEF(FlashParamsTable                        ,0xffeea13c) // Found @0xffeea13c
DEF(movie_status                            ,0x000056b8) // Found @0xffd18138
DEF(full_screen_refresh                     ,0x00007810) // Found @0xffd88cc8
DEF(canon_menu_active                       ,0x00002a98) // Found @0xffc6c4e8
DEF(canon_shoot_menu_active                 ,0x000068a9) // Found @0xffd4c494
DEF(playrec_mode                            ,0x000027e4) // Found @0xffc5f96c
DEF(zoom_status                             ,0x0000a050) // Found @0xffe2a418
DEF(some_flag_for_af_scan                   ,0x00005a70) // Found @0xffd1b170
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 3 int value(s), the first is the zoom focus length.
// there are 7 entries in the table - set NUM_FL to 7
DEF(focus_len_table                         ,0xfffe2ee8) // Found @0xfffe2ee8
DEF(zoom_busy                               ,0x0000560c) // Found @0xffd14e64
DEF(focus_busy                              ,0x0000551c) // Found @0xffd125c4
DEF(recreview_hold                          ,0x000030d4) // Found @0xffc78de0
DEF(palette_control                         ,0x00007810) // Found @0xffd88c44
DEF(active_palette_buffer                   ,0x00007818) // Found @0xffd88c48
DEF(palette_buffer                          ,0x00088f3c) // Found @0xffd88ff0

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x10361000; }             // Found @0xffc3fafc
//void *vid_get_viewport_fb()      { return (void*)0x1068c2e0; }             // Found @0xffe6fb60
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x2588+0x54)); } // Found @0xffc543b8 & 0xffc543f0
//char *camera_jpeg_count_str()    { return (char*)0x00088994; }             // Found @0xffd810bc
//long hook_raw_size()             { return 0x00ec04f0; }                    // Found @0xffe73000
//int get_flash_params_count(void) { return 0xa0; }                          // Found @0xffd3af20

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffe9db68, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x01000000 // Found @0xffe9db88, levent 0x902
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 2, KEY_ZOOM_OUT        ,0x00000040 }, // Found @0xffe9db40, levent 0x03
//    { 2, KEY_ZOOM_IN         ,0x00000080 }, // Found @0xffe9db48, levent 0x02
//    { 2, KEY_SET             ,0x00000100 }, // Found @0xffe9db50, levent 0x08
//    { 2, KEY_RIGHT           ,0x00000200 }, // Found @0xffe9db58, levent 0x07
//    { 2, KEY_UP              ,0x02000000 }, // Found @0xffe9db90, levent 0x04
//    { 2, KEY_DOWN            ,0x04000000 }, // Found @0xffe9db98, levent 0x05
//    { 2, KEY_LEFT            ,0x08000000 }, // Found @0xffe9dba0, levent 0x06
//    { 2, KEY_MENU            ,0x20000000 }, // Found @0xffe9dbb0, levent 0x09
//    { 2, KEY_SHOOT_FULL      ,0x00000030 }, // Found @0xffe9db38, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000020 }, // Found @0xffe9db38, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00000010 }, // Found @0xffe9db30, levent 0x00
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#define CAM_RAW_ROWPIX    3720 // Found @0xffcf3210
//#define CAM_RAW_ROWS      2772 // Found @0xffcf321c
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x10000000 // Found @0xffc29904

// Misc stuff
DEF(ctypes, 0xffe9d276)

// For capt_seq.c
//static long *nrflag = (long*)(0x5a8c+0x08);  // Found @ ffd1d88c & ffd1d8d0
//#define NR_AUTO (0)                          // have to explictly reset value back to 0 to enable auto

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NSTUB(AllocateMemory                          ,0xffe193b0) //101
NSTUB(AllocateUncacheableMemory               ,0xffc298bc) //112
NSTUB(Close                                   ,0xffc26360) //101
NSTUB(CreateTask                              ,0xffc0f290) //101
NSTUB(DebugAssert                             ,0xffc0f768) //111
NSTUB(DeleteDirectory_Fut                     ,0xffc25d5c) //  1
NSTUB(DeleteFile_Fut                          ,0xffc25c78) //112
NSTUB(DoAFLock                                ,0xffc27a24) //102
NSTUB(EnterToCompensationEVF                  ,0xffc27ad4) //104
NSTUB(ExecuteEventProcedure                   ,0xffc67d18) //  1
NSTUB(ExitFromCompensationEVF                 ,0xffc27b18) //104
NSTUB(ExitTask                                ,0xffc0f520) //101
NSTUB(ExpCtrlTool_StartContiAE                ,0xffc358f8) //104
NSTUB(ExpCtrlTool_StopContiAE                 ,0xffc35a78) //104
NSTUB(Fclose_Fut                              ,0xffc25df4) //101
NSTUB(Feof_Fut                                ,0xffc25fe0) //  1
NSTUB(Fflush_Fut                              ,0xffc2601c) //  1
NSTUB(Fgets_Fut                               ,0xffc25f48) //  6
NSTUB(Fopen_Fut                               ,0xffc25db4) //101
NSTUB(Fread_Fut                               ,0xffc25ea0) //101
NSTUB(FreeMemory                              ,0xffe193a8) //101
NSTUB(FreeUncacheableMemory                   ,0xffc298fc) //112
NSTUB(Fseek_Fut                               ,0xffc25f94) //101
NSTUB(Fwrite_Fut                              ,0xffc25ef4) //101
NSTUB(GetCCDTemperature                       ,0xffc45d78) //102
NSTUB(GetCurrentAvValue                       ,0xffd13ed4) //102
NSTUB(GetDrive_ClusterSize                    ,0xffc52da4) //  6
NSTUB(GetDrive_FreeClusters                   ,0xffc52dfc) //  6
NSTUB(GetDrive_TotalClusters                  ,0xffc52dd4) //  6
NSTUB(GetFocusLensSubjectDistance             ,0xffd1313c) //102
NSTUB(GetFocusLensSubjectDistanceFromLens     ,0xffd13598) //  3
NSTUB(GetImageFolder                          ,0xffcfa088) //  6
NSTUB(GetKbdState                             ,0xffc43e6c) //109
NSTUB(GetMemInfo                              ,0xffc0a8a0) //  3
NSTUB(GetOpticalTemperature                   ,0xffc45e64) //102
NSTUB(GetParameterData                        ,0xffd3aee0) //101
NSTUB(GetPropertyCase                         ,0xffc6ba84) //102
NSTUB(GetSystemTime                           ,0xffe19408) //101
NSTUB(GetZoomLensCurrentPoint                 ,0xffd151e8) //102
NSTUB(GetZoomLensCurrentPosition              ,0xffe09db4) //102
NSTUB(GiveSemaphore                           ,0xffc0f1f0) //112
NSTUB(IsStrobeChargeCompleted                 ,0xffcaf2c8) //102
NSTUB(LEDDrive                                ,0xffc43538) //101
NSTUB(LocalTime                               ,0xffc65708) //  6
NSTUB(LockMainPower                           ,0xffc70290) //103
NSTUB(Lseek                                   ,0xffc2657c) //101
NSTUB(MakeDirectory_Fut                       ,0xffc25cec) //  6
NSTUB(MakeSDCardBootable                      ,0xffc53034) //105
NSTUB(MoveFocusLensToDistance                 ,0xffe6befc) //102
NSTUB(MoveIrisWithAv                          ,0xffe15be0) //102
NSTUB(MoveZoomLensWithPoint                   ,0xffe16284) //102
NSTUB(NewTaskShell                            ,0xffc6b4c8) //101
NSTUB(Open                                    ,0xffc26298) //101
NSTUB(PB2Rec                                  ,0xffc72f50) //104
NSTUB(PT_MoveDigitalZoomToWide                ,0xffc58dec) //102
NSTUB(PT_MoveOpticalZoomAt                    ,0xffc58dc4) //102
NSTUB(PT_PlaySound                            ,0xffc61544) //  6
NSTUB(PostLogicalEventForNotPowerType         ,0xffc6fabc) //103
NSTUB(PostLogicalEventToUI                    ,0xffc6fb08) //103
NSTUB(PutInNdFilter                           ,0xffe160cc) //102
NSTUB(PutOutNdFilter                          ,0xffe160f0) //102
NSTUB(Read                                    ,0xffc0b35c) //101
NSTUB(ReadFastDir                             ,0xffdff8d0) //  6
NSTUB(Rec2PB                                  ,0xffc72f90) //104
NSTUB(RefreshPhysicalScreen                   ,0xffc80098) //104
NSTUB(Remove                                  ,0xffc264d4) //  6
NSTUB(RenameFile_Fut                          ,0xffc25be4) //  6
NSTUB(Restart                                 ,0xffc2b0d8) //106
NSTUB(ScreenLock                              ,0xffc81278) //  4
NSTUB(ScreenUnlock                            ,0xffc812dc) //  3
NSTUB(SetAE_ShutterSpeed                      ,0xffe6ed78) //102
NSTUB(SetAutoShutdownTime                     ,0xffc70304) //103
NSTUB(SetCurrentCaptureModeType               ,0xffc76628) //101
NSTUB(SetFileAttributes                       ,0xffc26764) //  6
NSTUB(SetFileTimeStamp                        ,0xffc266ec) //  6
NSTUB(SetLogicalEventActive                   ,0xffc70008) //101
NSTUB(SetParameterData                        ,0xffd3ae50) //101
NSTUB(SetPropertyCase                         ,0xffc6b968) //102
NSTUB(SetScriptMode                           ,0xffc70058) //101
NSTUB(SleepTask                               ,0xffc29760) //101
NSTUB(TakeSemaphore                           ,0xffc0f120) //101
NSTUB(TurnOffBackLight                        ,0xffc7b568) //104
NSTUB(TurnOnBackLight                         ,0xffc7b550) //104
NSTUB(UIFS_WriteFirmInfoToFile                ,0xffd2db9c) //101
NSTUB(UnlockAF                                ,0xffc27a5c) //102
NSTUB(UnlockMainPower                         ,0xffc701e4) //103
NSTUB(UnsetZoomForMovie                       ,0xffd41454) //104
NSTUB(VbattGet                                ,0xffc22b4c) //101
NSTUB(Write                                   ,0xffc263b4) //101
NSTUB(WriteSDCard                             ,0xffd07b28) //108
NSTUB(_log                                    ,0xffe99ea0) //111
NSTUB(_log10                                  ,0xffe9a3e0) //112
NSTUB(_pow                                    ,0xffe9a558) //114
NSTUB(_sqrt                                   ,0xffe9c17c) //  6
NSTUB(add_ptp_handler                         ,0xffdd53ac) //  6
NSTUB(apex2us                                 ,0xffd8dfd0) //  4
NSTUB(close                                   ,0xffc0b1b8) //  6
NSTUB(closedir                                ,0xffdff72c) //  4
NSTUB(err_init_task                           ,0xffc05fd8) //  4
NSTUB(exmem_alloc                             ,0xffc666d0) //101
NSTUB(free                                    ,0xffc04248) //112
NSTUB(kbd_p1_f                                ,0xffc23cb8) //109
NSTUB(kbd_p1_f_cont                           ,0xffc23cc4) //109
NSTUB(kbd_p2_f                                ,0xffc234cc) //109
NSTUB(kbd_read_keys                           ,0xffc23c3c) //109
NSTUB(kbd_read_keys_r2                        ,0xffc43878) //109
NSTUB(lseek                                   ,0xffc2657c) //101
NSTUB(malloc                                  ,0xffc041f0) //112
NSTUB(memcmp                                  ,0xffc114d8) //101
NSTUB(memcpy                                  ,0xffc2ee6c) //101
NSTUB(memset                                  ,0xffd8d00c) //101
NSTUB(mktime_ext                              ,0xffc82008) //  1
NSTUB(open                                    ,0xffc0b108) //  6
NSTUB(opendir                                 ,0xffdff77c) //  6
NSTUB(openfastdir                             ,0xffdff77c) //  6
NSTUB(qsort                                   ,0xffe527f0) //  6
NSTUB(read                                    ,0xffc0b35c) //101
NSTUB(reboot_fw_update                        ,0xffe01178) //  6
NSTUB(rename                                  ,0xffc25be4) //  6
NSTUB(set_control_event                       ,0xffc6fd2c) //111
NSTUB(stat                                    ,0xffc265c4) //  3
NSTUB(strcat                                  ,0xffc817c0) //  1
NSTUB(strchr                                  ,0xffc040bc) //  1
NSTUB(strcmp                                  ,0xffc11494) //101
NSTUB(strcpy                                  ,0xffc1147c) //101
NSTUB(strftime                                ,0xffc81a08) //113
NSTUB(strlen                                  ,0xffc04108) //101
NSTUB(strncmp                                 ,0xffc04070) //  1
NSTUB(strncpy                                 ,0xffc04034) //  1
NSTUB(strrchr                                 ,0xffc040e0) //  1
NSTUB(strtol                                  ,0xffc2f16c) //101
NSTUB(strtolx                                 ,0xffc2ef70) //109
  DEF(task_CaptSeq                            ,0xffc5b06c) //110
  DEF(task_ExpDrv                             ,0xffc98190) //110
  DEF(task_InitFileModules                    ,0xffc7387c) //110
  DEF(task_MovieRecord                        ,0xffd18384) //110
  DEF(task_PhySw                              ,0xffc237f8) //110
NSTUB(time                                    ,0xffc65ce4) //  6
NSTUB(vsprintf                                ,0xffc1143c) //  6
NSTUB(write                                   ,0xffc263b4) //101
