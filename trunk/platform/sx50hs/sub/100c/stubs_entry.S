// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R51 (DRYOS version 2.3, release #0051)
//   Firmware Ver GM1.00C
//   Canon PowerShot SX50 HS

// Values for makefile.inc
//   PLATFORMOSVER = 51
//   PLATFORMID = 12889 (0x3259) // Found @ 0xfff40040
//   MAXRAMADDR = 0x0fffffff
//   KEYSYS = d4c                // Found @ 0xffff3c7c
//   NEED_ENCODED_DISKBOOT = 9   // Found @ 0xffff3c8c

// Note, ROM copied to RAM :- from 0xff746ac8, to 0x00685000, len 15789 words.

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
NHSTUB(DeleteFile_Fut                         ,0xff01c468) //  1 90%
// ERROR: MakeDirectory_Fut is not found.                  //--- ---    *** != 0xff01cf78
// ERROR: kbd_pwr_off is not found.                        //--- ---    *** != 0x00000000
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff04aac8 -> ff09f920 -> ff204794 -> ff394820 -> ff6ee034
// Mode 32805 in firmware but not in current modemap
// Mode 33295 in firmware but not in current modemap

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x0003ae8c) // Found @0xff01a330
DEF(physw_run                               ,0x00001d64) // Found @0xff019e90
DEF(physw_sleep_delay                       ,0x00001d6c) // Found @0xff019e90
DEF(levent_table                            ,0xff62ef5c) // Found @0xff62ef5c
DEF(FlashParamsTable                        ,0xff6ee2b8) // Found @0xff6ee2b8
DEF(video_compression_rate                  ,0x00003924) // Found @0xff080e10
DEF(full_screen_refresh                     ,0x0000a7b8) // Found @0xff20e6c4
DEF(canon_menu_active                       ,0x000046f4) // Found @0xff0a3084
DEF(canon_shoot_menu_active                 ,0x0000cb39) // Found @0xff2aa370
DEF(playrec_mode                            ,0x00003bd8) // Found @0xff08f900
DEF(zoom_status                             ,0x0000d6b4) // Found @0xff307258
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 1 int value, which is the the zoom focus length.
// there are 201 entries in the table - set NUM_FL to 201
DEF(focus_len_table                         ,0xfff4d5c4) // Found @0xfff4d5c4
DEF(zoom_busy                               ,0x000037f4) // Found @0xff07b05c
DEF(focus_busy                              ,0x000096e4) // Found @0xff1da9a4
DEF(recreview_hold                          ,0x00002ae8) // Found @0xff0527b4
// Palette colour tables  found @ 0xff632c30
DEF(palette_control                         ,0x0000a7b8) // Found @0xff20e640
DEF(active_palette_buffer                   ,0x0000a7c0) // Found @0xff20e644
DEF(palette_buffer_ptr                      ,0x0000a7c4) // Found @0xff20eafc
DEF(palette_buffer                          ,0x0010b190) // Found @0xff20eb0c
// Offset from start of palette_buffer to color data = 4 (Found @0xff3b4558)
DEF(bitmap_buffer                           ,0x0000a7fc) // Found @0xff2124f0
DEF(active_bitmap_buffer                    ,0x0000a7f4) // Found @0xff2124f4

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x406c5000; }             // Found @0xff056b6c
//void *vid_get_viewport_fb()      { return (void*)0x4081ab80; }             // Found @0xff4316e8
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x3650+0x54)); } // Found @0xff074f14 & 0xff074f4c
//char *camera_jpeg_count_str()    { return (char*)0x00110a74; }             // Found @0xff28ee9c
//long hook_raw_size()             { return 0x0124ab50; }                    // Found @0xff433080
//int get_flash_params_count(void) { return 0xa6; }                          // Found @0xff205d2c

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00000002 // Found @0xff49e630, levent 0x20a
//#define SD_READONLY_IDX     1
//#define USB_MASK            0x10000000 // Found @0xff49e6a0, levent 0x202
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_SET             ,0x00000400 }, // Found @0xff49e5b0, levent 0x08
//    { 0, KEY_DISPLAY         ,0x00000800 }, // Found @0xff49e5b8, levent 0x0a
//    { 0, KEY_DOWN            ,0x00001000 }, // Found @0xff49e5c0, levent 0x05
//    { 0, KEY_MENU            ,0x00002000 }, // Found @0xff49e5c8, levent 0x09
//    { 0, KEY_LEFT            ,0x00004000 }, // Found @0xff49e5d0, levent 0x06
//    { 0, KEY_UP              ,0x00040000 }, // Found @0xff49e5f0, levent 0x04
//    { 0, KEY_RIGHT           ,0x00080000 }, // Found @0xff49e5f8, levent 0x07
//    { 2, KEY_POWER           ,0x00000800 }, // Found @0xff49e650, levent 0x100
//    { 2, KEY_PLAYBACK        ,0x00001000 }, // Found @0xff49e658, levent 0x101
//    { 2, KEY_SHOOT_FULL      ,0x0000c000 }, // Found @0xff49e670, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00008000 }, // Found @0xff49e670, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00004000 }, // Found @0xff49e668, levent 0x00
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#define CAM_RAW_ROWPIX    4176 // Found @0xff1ae73c
//#define CAM_RAW_ROWS      3062 // Found @0xff1ae748
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff020984

// Misc stuff
DEF(ctypes, 0xff49d22c)

// For capt_seq.c
DEF(_nrflag,0xcd4c) // Found @ ff2bb2fc (0xcd4c) & ff2bb338 (+0x00)
//static long *nrflag = (long*)(0xcd4c+0x00);  // Found @ ff2bb2fc & ff2bb338
//#define NR_AUTO (0)                          // have to explictly reset value back to 0 to enable auto

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
//NHSTUB(CreateJumptable                      ,0xff433248) //  1
// ALT: NHSTUB(CreateJumptable, 0xff435ccc) // 1 32/0
//NHSTUB(_uartr_req                           ,0xff00af50) //111
//NHSTUB(AllocateMemory                       ,0xff38fe80) //101
NHSTUB(AllocateUncacheableMemory              ,0xff02093c) //112
NHSTUB(Close                                  ,0xff01cadc) //101
NHSTUB(CreateTask                             ,0x0068ab8c) //101
NHSTUB(DebugAssert                            ,0x0068b104) //111
NHSTUB(DeleteDirectory_Fut                    ,0xff01c4dc) //116
NHSTUB(DoAFLock                               ,0xff01e97c) //102
NHSTUB(EnterToCompensationEVF                 ,0xff01ed34) //104
NHSTUB(ExecuteEventProcedure                  ,0xff097190) //104
NHSTUB(ExitFromCompensationEVF                ,0xff01ed78) //104
NHSTUB(ExitTask                               ,0x0068ae1c) //101
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff02e7c0) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff02e928) //104
NHSTUB(Fclose_Fut                             ,0xff01c574) //101
NHSTUB(Feof_Fut                               ,0xff01c760) //  1
NHSTUB(Fflush_Fut                             ,0xff01c79c) //  1
NHSTUB(Fgets_Fut                              ,0xff01c6c8) //  6
NHSTUB(Fopen_Fut                              ,0xff01c534) //101
NHSTUB(Fread_Fut                              ,0xff01c620) //101
//NHSTUB(FreeMemory                           ,0xff38fe78) //101
NHSTUB(FreeUncacheableMemory                  ,0xff02097c) //112
NHSTUB(Fseek_Fut                              ,0xff01c714) //101
NHSTUB(Fwrite_Fut                             ,0xff01c674) //101
NHSTUB(GetBatteryTemperature                  ,0xff061324) //102
NHSTUB(GetCCDTemperature                      ,0xff0612b0) //102
NHSTUB(GetCurrentAvValue                      ,0xff1dd798) //102
NHSTUB(GetDrive_ClusterSize                   ,0xff072b54) //  6
NHSTUB(GetDrive_FreeClusters                  ,0xff072bac) //  6
NHSTUB(GetDrive_TotalClusters                 ,0xff072b84) //  6
NHSTUB(GetFocusLensSubjectDistance            ,0xff1db724) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff1dbb68) //  3
//NHSTUB(GetImageFolder                       ,0xff1b8488) // 11            == 0xff1b8488
NHSTUB(GetKbdState                            ,0xff05d908) //109
NHSTUB(GetMemInfo                             ,0xff005280) //115
NHSTUB(GetOpticalTemperature                  ,0xff061398) //102
NHSTUB(GetParameterData                       ,0xff205cec) //101
NHSTUB(GetPropertyCase                        ,0xff09b1c0) //101
NHSTUB(GetSystemTime                          ,0xff38fed8) //101
NHSTUB(GetVRAMHPixelsSize                     ,0xff04191c) //102
NHSTUB(GetVRAMVPixelsSize                     ,0xff041928) //102
NHSTUB(GetZoomLensCurrentPoint                ,0xff07b3ec) //102
NHSTUB(GetZoomLensCurrentPosition             ,0xff1e4be0) //102
NHSTUB(GiveSemaphore                          ,0x0068aaec) //112
NHSTUB(IsStrobeChargeCompleted                ,0xff037018) //102
NHSTUB(LEDDrive                               ,0xff1f0e9c) //101
//NHSTUB(LocalTime                            ,0x0068f420) //115            == 0x0068f420
NHSTUB(LockMainPower                          ,0xff09f41c) //103
//NHSTUB(Lseek                                ,0xff01ccf8) //101
NHSTUB(MakeSDCardBootable                     ,0xff072de4) //105
NHSTUB(MoveFocusLensToDistance                ,0xff42ca68) //102
NHSTUB(MoveIrisWithAv                         ,0xff38b1c0) //102
NHSTUB(MoveZoomLensWithPoint                  ,0xff38ba6c) //102
//NHSTUB(NewTaskShell                         ,0xff09ab44) //101
NHSTUB(Open                                   ,0xff01ca14) //101
NHSTUB(PB2Rec                                 ,0xff04a06c) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff1f1f9c) //102
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff1f1f74) //102
NHSTUB(PT_PlaySound                           ,0xff091b80) // 11
NHSTUB(PostLogicalEventForNotPowerType        ,0xff09cd38) //103
NHSTUB(PostLogicalEventToUI                   ,0xff09cd84) //103
NHSTUB(PutInNdFilter                          ,0xff42b4a4) //102
NHSTUB(PutOutNdFilter                         ,0xff42b4e0) //102
NHSTUB(Read                                   ,0xff005d3c) //101
NHSTUB(ReadFastDir                            ,0xff36e508) //115
NHSTUB(Rec2PB                                 ,0xff048798) //104
NHSTUB(RefreshPhysicalScreen                  ,0xff0a191c) //104
//NHSTUB(Remove                               ,0xff01cc50) //  6
NHSTUB(RenameFile_Fut                         ,0xff01c3d4) //116
NHSTUB(Restart                                ,0xff022150) //106
NHSTUB(ScreenLock                             ,0xff0a2928) //  4
NHSTUB(ScreenUnlock                           ,0xff0a298c) //  3
NHSTUB(SetAE_ShutterSpeed                     ,0xff430560) //102
NHSTUB(SetAutoShutdownTime                    ,0xff09f490) //103
NHSTUB(SetCurrentCaptureModeType              ,0xff0aab9c) //101
NHSTUB(SetFileAttributes                      ,0xff01cee0) //  6
NHSTUB(SetFileTimeStamp                       ,0xff01ce68) //  6
NHSTUB(SetLogicalEventActive                  ,0xff09f158) //101
NHSTUB(SetParameterData                       ,0xff205bc8) //101
NHSTUB(SetPropertyCase                        ,0xff09b038) //101
NHSTUB(SetScriptMode                          ,0xff09f1f4) //101
NHSTUB(SleepTask                              ,0x0068c4e4) //101
NHSTUB(TakeSemaphore                          ,0x0068aa1c) //101
NHSTUB(TurnOffBackLight                       ,0xff0ae5b0) //104
NHSTUB(TurnOnBackLight                        ,0xff0ae598) //104
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff223d28) //101
NHSTUB(UnlockAF                               ,0xff01ea04) //102
NHSTUB(UnlockMainPower                        ,0xff09f370) //103
NHSTUB(VbattGet                               ,0xff018ae4) //101
NHSTUB(Write                                  ,0xff01cb30) //101
NHSTUB(WriteSDCard                            ,0xff1ccb9c) //108
NHSTUB(_log                                   ,0x00690cd8) //111
NHSTUB(_log10                                 ,0x00691218) //112
NHSTUB(_pow                                   ,0x00691390) //114
NHSTUB(_sqrt                                  ,0x00693030) //  6
NHSTUB(add_ptp_handler                        ,0xff300128) //  6
NHSTUB(apex2us                                ,0xff2b4af4) //  4
NHSTUB(close                                  ,0xff005b98) //  6
NHSTUB(closedir                               ,0xff36e364) //  4
NHSTUB(err_init_task                          ,0xff004310) //111
NHSTUB(exmem_alloc                            ,0xff095b64) //101
NHSTUB(exmem_free                             ,0xff095bdc) //101
NHSTUB(free                                   ,0xff002f0c) //112
NHSTUB(kbd_p1_f                               ,0xff01a380) //109
NHSTUB(kbd_p1_f_cont                          ,0xff01a38c) //109
NHSTUB(kbd_p2_f                               ,0xff019b28) //109
NHSTUB(kbd_read_keys                          ,0xff01a330) //109
NHSTUB(kbd_read_keys_r2                       ,0xff05cff0) //109
NHSTUB(lseek                                  ,0xff01ccf8) //101
NHSTUB(malloc                                 ,0xff002eb4) //112
NHSTUB(memcmp                                 ,0xff00b5a4) //101
NHSTUB(memcpy                                 ,0xff022a84) //101
NHSTUB(memset                                 ,0xff2b2a9c) //101
NHSTUB(mkdir                                  ,0xff01cf78) //  6
NHSTUB(mktime_ext                             ,0xff0b1d60) //  1
NHSTUB(open                                   ,0xff005ae8) //  6
NHSTUB(OpenFastDir                            ,0xff36e3b4) //115
NHSTUB(qsort                                  ,0xff3f8374) //  6
NHSTUB(rand                                   ,0xff2b2a6c) //  6
//NHSTUB(read                                 ,0xff005d3c) //101
NHSTUB(realloc                                ,0xff2b2b18) //115
NHSTUB(reboot_fw_update                       ,0xff38f52c) //106
NHSTUB(set_control_event                      ,0xff09ecfc) //111
NHSTUB(srand                                  ,0xff2b2a60) //  6
NHSTUB(stat                                   ,0xff01cd40) //109
NHSTUB(strcat                                 ,0xff0b23fc) //  1
NHSTUB(strchr                                 ,0xff002d80) //  1
NHSTUB(strcmp                                 ,0xff00b6a0) //101
NHSTUB(strcpy                                 ,0xff00b58c) //101
NHSTUB(strftime                               ,0xff0b1dac) //113
NHSTUB(strlen                                 ,0xff002dcc) //101
NHSTUB(strncmp                                ,0xff002d34) //  1
NHSTUB(strncpy                                ,0xff002cf8) //  1
NHSTUB(strrchr                                ,0xff002da4) //  1
NHSTUB(strtol                                 ,0xff022a70) //101
NHSTUB(strtolx                                ,0xff022874) //109
   DEF(task_CaptSeq                           ,0xff085a8c) //110
   DEF(task_ExpDrv                            ,0xff0cca8c) //110
   DEF(task_InitFileModules                   ,0xff04a93c) //110
   DEF(task_MovieRecord                       ,0xff0813c0) //110
   DEF(task_PhySw                             ,0xff019e8c) //110
   DEF(task_RotaryEncoder                     ,0xff05dc5c) //110
   DEF(hook_CreateTask                        ,0x0068ab8c) //105
   DEF(hook_CreateTask2                       ,0x0068af04) //107
NHSTUB(time                                   ,0x0068f8c8) //  6
NHSTUB(vsprintf                               ,0xff00b43c) //115
//NHSTUB(write                                ,0xff01cb30) //101
//NHSTUB(EngDrvIn                             ,0xff01b1b4) //102
//NHSTUB(EngDrvOut                            ,0xff01b19c) //102
//NHSTUB(EngDrvRead                           ,0xff01b1bc) //102
//NHSTUB(EngDrvBits                           ,0xff01b1d0) //102
//NHSTUB(GetSDProtect                         ,0xff01a2e8) //101
//NHSTUB(StartRecModeMenu                     ,0xff0a3080) //102
//NHSTUB(DispCon_ShowBitmapColorBar           ,0xff056b28) //102
//NHSTUB(ResetZoomLens                        ,0xff38b9c0) //102
//NHSTUB(ResetFocusLens                       ,0xff38a42c) //102
//NHSTUB(NR_GetDarkSubType                    ,0xff2bb3bc) //102
//NHSTUB(NR_SetDarkSubType                    ,0xff2bb2f4) //102
//NHSTUB(SavePaletteData                      ,0xff1f2638) //102
//NHSTUB(GUISrv_StartGUISystem                ,0xff0a1170) //101
