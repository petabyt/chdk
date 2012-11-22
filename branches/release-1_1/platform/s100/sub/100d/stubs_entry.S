// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R49 (DRYOS version 2.3, release #0049)
//   Firmware Ver GM1.00D
//   Canon PowerShot S100

// Values for makefile.inc
//   PLATFORMOSVER = 49
//   PLATFORMID = 12854 (0x3236) // Found @ 0xfff40040
//   MAXRAMADDR = 0x0fffffff
//   KEYSYS = d4c                // Found @ 0xffff3b28
//   NEED_ENCODED_DISKBOOT = 7   // Found @ 0xffff3b38

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
// ERROR: kbd_pwr_off is not found.                        //--- ---    *** != 0x00000000
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff09cf84 -> ff099208 -> ff205770 -> ff3877bc -> ff626540
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
//DEF(physw_status                            ,0x000386bc) // Found @0xff024db0,          stubs_min = 0x000386bc (0x000386bc)
//DEF(physw_run                               ,0x00001c3c) // Found @0xff02493c,          stubs_min = 0x00001c3c (0x00001c3c)
DEF(physw_sleep_delay                       ,0x00001c44) // Found @0xff02493c
//DEF(levent_table                            ,0xff5905bc) // Found @0xff5905bc,          stubs_min = 0xff5905bc (0xff5905bc)
//DEF(FlashParamsTable                        ,0xff6267a4) // Found @0xff6267a4,          stubs_min = 0xff6267a4 (0xff6267a4)
//DEF(movie_status                            ,0x00009bfc) // Found @0xff1cb1b0,          stubs_min = 0x00009bfc (0x00009bfc)
//DEF(full_screen_refresh                     ,0x0000ca28) // Found @0xff297af0,          stubs_min = 0x0000ca28 (0x0000ca28)
//DEF(canon_menu_active                       ,0x00004484) // Found @0xff0924cc,          stubs_min = 0x00004484 (0x00004484)
//DEF(canon_shoot_menu_active                 ,0x0000b291) // Found @0xff22ca24,          stubs_min = 0x0000b291 (0x0000b291)
//DEF(playrec_mode                            ,0x000041a4) // Found @0xff083ca8,          stubs_min = 0x000041a4 (0x000041a4)
//DEF(zoom_status                             ,0x0000ad6c) // Found @0xff213958,          stubs_min = 0x0000ad6c (0x0000ad6c)
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 2 int value(s), the first is the zoom focus length.
// there are 121 entries in the table - set NUM_FL to 121
//DEF(focus_len_table                         ,0xfff4a4f8) // Found @0xfff4a4f8,          stubs_min = 0xfff4a4f8 (0xfff4a4f8)
//DEF(zoom_busy                               ,0x00009b24) // Found @0xff1c6118,          stubs_min = 0x00009b24 (0x00009b24)
//DEF(focus_busy                              ,0x00009940) // Found @0xff1bef10,          stubs_min = 0x00009940 (0x00009940)
//DEF(recreview_hold                          ,0x00005008) // Found @0xff0a51b0,          stubs_min = 0x00005008 (0x00005008)
DEF(palette_control                         ,0x0000ca28) // Found @0xff297a6c
DEF(active_palette_buffer                   ,0x0000ca30) // Found @0xff297a70
DEF(palette_buffer                          ,0x000cf8d4) // Found @0xff297f38
DEF(bitmap_buffer                           ,0x0000ca6c) // Found @0xff29c9b0
DEF(active_bitmap_buffer                    ,0x0000ca64) // Found @0xff29c9b4

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x40685000; }             // Found @0xff051fbc
//void *vid_get_viewport_fb()      { return (void*)0x407dab80; }             // Found @0xff3fc0c8
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x3da0+0x58)); } // Found @0xff07007c & 0xff0700b4
//char *camera_jpeg_count_str()    { return (char*)0x000cf0cc; }             // Found @0xff289050
//long hook_raw_size()             { return 0x01297380; }                    // Found @0xff3feed0
//int get_flash_params_count(void) { return 0x9f; }                          // Found @0xff206d58

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00000800 // Found @0xff4537fc, levent 0x20a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x10000000 // Found @0xff45383c, levent 0x202
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_DOWN            ,0x00000002 }, // Found @0xff45373c, levent 0x05
//    { 0, KEY_LEFT            ,0x00000004 }, // Found @0xff453744, levent 0x06
//    { 0, KEY_MENU            ,0x00000008 }, // Found @0xff45374c, levent 0x09
//    { 0, KEY_SET             ,0x00000020 }, // Found @0xff45375c, levent 0x08
//    { 0, KEY_UP              ,0x00000040 }, // Found @0xff453764, levent 0x04
//    { 0, KEY_RIGHT           ,0x00000080 }, // Found @0xff45376c, levent 0x07
//    { 0, KEY_VIDEO           ,0x00000100 }, // Found @0xff453774, levent 0x19
//    { 0, KEY_ZOOM_OUT        ,0x00008000 }, // Found @0xff4537ac, levent 0x03
//    { 0, KEY_ZOOM_IN         ,0x00010000 }, // Found @0xff4537b4, levent 0x02
//    { 1, KEY_SHOOT_FULL      ,0x00300000 }, // Found @0xff4537dc, levent 0x01
//    { 1, KEY_SHOOT_FULL_ONLY ,0x00200000 }, // Found @0xff4537dc, levent 0x01
//    { 1, KEY_SHOOT_HALF      ,0x00100000 }, // Found @0xff4537d4, levent 0x00
//    { 1, KEY_POWER           ,0x00400000 }, // Found @0xff4537e4, levent 0x100
//    { 1, KEY_PLAYBACK        ,0x00800000 }, // Found @0xff4537ec, levent 0x101
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#define CAM_RAW_ROWPIX    4160 // Found @0xff190f44
//#define CAM_RAW_ROWS      3124 // Found @0xff190f4c
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff02bd84

// Misc stuff
DEF(ctypes, 0xff4524b6)

// For capt_seq.c
//static long *nrflag = (long*)(0xcb38+0x00);  // Found @ ff2a56cc & ff2a5714
//#define NR_AUTO (0)                          // have to explictly reset value back to 0 to enable auto

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NSTUB(AllocateMemory                          ,0xff374404) //101
NSTUB(AllocateUncacheableMemory               ,0xff02bd3c) //112
NSTUB(Close                                   ,0xff0275bc) //101
NSTUB(CreateTask                              ,0xff00eaf0) //101
NSTUB(DebugAssert                             ,0xff00edc8) //111
NSTUB(DeleteDirectory_Fut                     ,0xff026fb8) //  1
NSTUB(DeleteFile_Fut                          ,0xff026ed4) //112
NSTUB(DoAFLock                                ,0xff029208) //102
NSTUB(EnterToCompensationEVF                  ,0xff0295dc) //104
NSTUB(ExecuteEventProcedure                   ,0xff08d868) //  2
NSTUB(ExitFromCompensationEVF                 ,0xff029620) //104
NSTUB(ExitTask                                ,0xff00ed80) //101
NSTUB(ExpCtrlTool_StartContiAE                ,0xff037d9c) //104
NSTUB(ExpCtrlTool_StopContiAE                 ,0xff037e7c) //104
NSTUB(Fclose_Fut                              ,0xff027050) //101
NSTUB(Feof_Fut                                ,0xff02723c) //  1
NSTUB(Fflush_Fut                              ,0xff027278) //  1
NSTUB(Fgets_Fut                               ,0xff0271a4) //  6
NSTUB(Fopen_Fut                               ,0xff027010) //101
NSTUB(Fread_Fut                               ,0xff0270fc) //101
NSTUB(FreeMemory                              ,0xff3743fc) //101
NSTUB(FreeUncacheableMemory                   ,0xff02bd7c) //112
NSTUB(Fseek_Fut                               ,0xff0271f0) //101
NSTUB(Fwrite_Fut                              ,0xff027150) //101
NSTUB(GetBatteryTemperature                   ,0xff05faac) //102
NSTUB(GetCCDTemperature                       ,0xff05fa38) //102
NSTUB(GetCurrentAvValue                       ,0xff1c1e48) //102
NSTUB(GetDrive_ClusterSize                    ,0xff06e744) //  6
NSTUB(GetDrive_FreeClusters                   ,0xff06e79c) //  6
NSTUB(GetDrive_TotalClusters                  ,0xff06e774) //  6
NSTUB(GetFocusLensSubjectDistance             ,0xff1bfc8c) //102
NSTUB(GetFocusLensSubjectDistanceFromLens     ,0xff1c00dc) //  3
NSTUB(GetImageFolder                          ,0xff19a600) //  6
NSTUB(GetKbdState                             ,0xff058f58) //109
NSTUB(GetMemInfo                              ,0xff00a2b8) //  3
NSTUB(GetOpticalTemperature                   ,0xff05fb20) //102
NSTUB(GetParameterData                        ,0xff206d18) //101
NSTUB(GetPropertyCase                         ,0xff091950) //102
NSTUB(GetSystemTime                           ,0xff37445c) //101
NSTUB(GetVRAMHPixelsSize                      ,0xff048f34) //102
NSTUB(GetVRAMVPixelsSize                      ,0xff048f40) //102
NSTUB(GetZoomLensCurrentPoint                 ,0xff1c6590) //102
NSTUB(GetZoomLensCurrentPosition              ,0xff35f990) //102
NSTUB(GiveSemaphore                           ,0xff02b4bc) //112
NSTUB(IsStrobeChargeCompleted                 ,0xff0f2e64) //102
NSTUB(LEDDrive                                ,0xff0582f8) //101
NSTUB(LocalTime                               ,0xff08b22c) //115
NSTUB(LockMainPower                           ,0xff098e00) //103
NSTUB(Lseek                                   ,0xff0277d8) //101
NSTUB(MakeDirectory_Fut                       ,0xff026f48) //116
NSTUB(MakeSDCardBootable                      ,0xff06e9c4) //105
NSTUB(MoveFocusLensToDistance                 ,0xff3f82f8) //102
NSTUB(MoveIrisWithAv                          ,0xff370ca4) //102
NSTUB(MoveZoomLensWithPoint                   ,0xff371658) //102
NSTUB(NewTaskShell                            ,0xff091288) //101
NSTUB(Open                                    ,0xff0274f4) //101
NSTUB(PB2Rec                                  ,0xff09c3f4) //104
NSTUB(PT_MoveDigitalZoomToWide                ,0xff079a78) //102
NSTUB(PT_MoveOpticalZoomAt                    ,0xff079a50) //102
NSTUB(PT_PlaySound                            ,0xff085c9c) //  6
NSTUB(PostLogicalEventForNotPowerType         ,0xff09671c) //103
NSTUB(PostLogicalEventToUI                    ,0xff096768) //103
NSTUB(PutInNdFilter                           ,0xff371430) //102
NSTUB(PutOutNdFilter                          ,0xff371454) //102
NSTUB(Read                                    ,0xff00ad74) //101
NSTUB(ReadFastDir                             ,0xff3498ec) //  6
NSTUB(Rec2PB                                  ,0xff09c434) //104
NSTUB(RefreshPhysicalScreen                   ,0xff0b5954) //104
NSTUB(Remove                                  ,0xff027730) //  6
NSTUB(RenameFile_Fut                          ,0xff026e40) //  6
NSTUB(Restart                                 ,0xff02d59c) //106
NSTUB(ScreenLock                              ,0xff0b6b4c) //  4
NSTUB(ScreenUnlock                            ,0xff0b6bb0) //  3
NSTUB(SetAE_ShutterSpeed                      ,0xff3fb240) //102
NSTUB(SetAutoShutdownTime                     ,0xff098e74) //103
NSTUB(SetCurrentCaptureModeType               ,0xff0a24e0) //101
NSTUB(SetFileAttributes                       ,0xff0279c0) //  6
NSTUB(SetFileTimeStamp                        ,0xff027948) //  6
NSTUB(SetLogicalEventActive                   ,0xff098b4c) //101
NSTUB(SetParameterData                        ,0xff206bf4) //101
NSTUB(SetPropertyCase                         ,0xff0917b4) //102
NSTUB(SetScriptMode                           ,0xff098b9c) //101
NSTUB(SleepTask                               ,0xff02b768) //101
NSTUB(TakeSemaphore                           ,0xff02b3ec) //101
NSTUB(TurnOffBackLight                        ,0xff0ad6b8) //104
NSTUB(TurnOnBackLight                         ,0xff0ad6a0) //104
NSTUB(UIFS_WriteFirmInfoToFile                ,0xff1f07bc) //101
NSTUB(UnlockAF                                ,0xff029240) //102
NSTUB(UnlockMainPower                         ,0xff098d54) //103
NSTUB(VbattGet                                ,0xff02237c) //101
NSTUB(Write                                   ,0xff027610) //101
NSTUB(WriteSDCard                             ,0xff1b0930) //108
NSTUB(_log                                    ,0xff44ef38) //111
NSTUB(_log10                                  ,0xff44f400) //112
NSTUB(_pow                                    ,0xff44f564) //114
NSTUB(_sqrt                                   ,0xff4512cc) //  6
NSTUB(add_ptp_handler                         ,0xff2e69a8) //  6
NSTUB(apex2us                                 ,0xff29f17c) //  4
NSTUB(close                                   ,0xff00abd0) //  6
NSTUB(closedir                                ,0xff349748) //  4
NSTUB(err_init_task                           ,0xff00602c) //  4
NSTUB(exmem_alloc                             ,0xff08c1ec) //101
NSTUB(free                                    ,0xff004264) //112
NSTUB(kbd_p1_f                                ,0xff024e00) //109
NSTUB(kbd_p1_f_cont                           ,0xff024e0c) //109
NSTUB(kbd_p2_f                                ,0xff0245d4) //109
NSTUB(kbd_read_keys                           ,0xff024db0) //109
NSTUB(kbd_read_keys_r2                        ,0xff0587c8) //109
NSTUB(lseek                                   ,0xff0277d8) //101
NSTUB(malloc                                  ,0xff00420c) //112
NSTUB(memcmp                                  ,0xff010a60) //101
NSTUB(memcpy                                  ,0xff0316c0) //101
NSTUB(memset                                  ,0xff29d1a0) //101
NSTUB(mkdir                                   ,0xff027a58) //109
NSTUB(mktime_ext                              ,0xff0b79a0) //  1
NSTUB(open                                    ,0xff00ab20) //  6
NSTUB(opendir                                 ,0xff349798) //  6
NSTUB(openfastdir                             ,0xff349798) //  6
NSTUB(qsort                                   ,0xff3c8150) //  6
NSTUB(rand                                    ,0xff29d2dc) //  6
NSTUB(read                                    ,0xff00ad74) //101
NSTUB(reboot_fw_update                        ,0xff34f040) //106
NSTUB(rename                                  ,0xff026e40) //  6
NSTUB(set_control_event                       ,0xff098740) //111
NSTUB(srand                                   ,0xff29d2d0) //  6
NSTUB(stat                                    ,0xff027820) //  3
NSTUB(strcat                                  ,0xff0b7158) //  1
NSTUB(strchr                                  ,0xff0040d8) //  1
NSTUB(strcmp                                  ,0xff010a1c) //101
NSTUB(strcpy                                  ,0xff010a04) //101
NSTUB(strftime                                ,0xff0b73a0) //113
NSTUB(strlen                                  ,0xff004124) //101
NSTUB(strncmp                                 ,0xff00408c) //  1
NSTUB(strncpy                                 ,0xff004050) //  1
NSTUB(strrchr                                 ,0xff0040fc) //  1
NSTUB(strtol                                  ,0xff0319c0) //101
NSTUB(strtolx                                 ,0xff0317c4) //109
  DEF(task_CaptSeq                            ,0xff07ccdc) //110
  DEF(task_ExpDrv                             ,0xff0cfb78) //110
  DEF(task_InitFileModules                    ,0xff09cdf8) //110
  DEF(task_MovieRecord                        ,0xff1cc43c) //110
  DEF(task_PhySw                              ,0xff024938) //110
  DEF(task_RotaryEncoder                      ,0xff05927c) //110
NSTUB(time                                    ,0xff08b808) //  6
NSTUB(vsprintf                                ,0xff0109c4) //  6
NSTUB(write                                   ,0xff027610) //101
