// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R51 (DRYOS version 2.3, release #0051)
//   Firmware Ver GM1.00B
//   Canon PowerShot SX50 HS

// Values for makefile.inc
//   PLATFORMOSVER = 51
//   PLATFORMID = 12889 (0x3259) // Found @ 0xfff40040
//   MAXRAMADDR = 0x0fffffff
//   KEYSYS = d4c                // Found @ 0xffff3c7c
//   NEED_ENCODED_DISKBOOT = 9   // Found @ 0xffff3c8c

// Note, ROM copied to RAM :- from 0xff746a70, to 0x00685000, len 15789 words.

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
NSTUB(DeleteFile_Fut                          ,0xff01c468) //  1 90%
// ERROR: MakeDirectory_Fut is not found.                  //--- ---    *** != 0xff01cf78
// ERROR: kbd_pwr_off is not found.                        //--- ---    *** != 0x00000000
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff04aac8 -> ff09f920 -> ff20474c -> ff3947cc -> ff6edfdc
// Mode  8756 in firmware but not in current modemap
// Mode 32805 in firmware but not in current modemap
// Mode 33295 in firmware but not in current modemap

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x0003ae8c) // Found @0xff01a330
DEF(physw_run                               ,0x00001d64) // Found @0xff019e90
DEF(physw_sleep_delay                       ,0x00001d6c) // Found @0xff019e90
DEF(levent_table                            ,0xff62ef08) // Found @0xff62ef08
DEF(FlashParamsTable                        ,0xff6ee260) // Found @0xff6ee260
DEF(full_screen_refresh                     ,0x0000a7b8) // Found @0xff20e67c
DEF(canon_menu_active                       ,0x000046f4) // Found @0xff0a3084
DEF(canon_shoot_menu_active                 ,0x0000cb39) // Found @0xff2aa31c
DEF(playrec_mode                            ,0x00003bd8) // Found @0xff08f900
DEF(zoom_status                             ,0x0000d6b4) // Found @0xff307204
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 1 int value, which is the the zoom focus length.
// there are 201 entries in the table - set NUM_FL to 201
DEF(focus_len_table                         ,0xfff4d5c4) // Found @0xfff4d5c4
DEF(zoom_busy                               ,0x000037f4) // Found @0xff07b05c
DEF(focus_busy                              ,0x000096e4) // Found @0xff1da95c
DEF(recreview_hold                          ,0x00002ae8) // Found @0xff0527b4
DEF(palette_control                         ,0x0000a7b8) // Found @0xff20e5f8
DEF(active_palette_buffer                   ,0x0000a7c0) // Found @0xff20e5fc
DEF(palette_buffer                          ,0x0010b190) // Found @0xff20eac4
DEF(bitmap_buffer                           ,0x0000a7fc) // Found @0xff2124a8
DEF(active_bitmap_buffer                    ,0x0000a7f4) // Found @0xff2124ac

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x406c5000; }             // Found @0xff056b6c
//void *vid_get_viewport_fb()      { return (void*)0x4081ab80; }             // Found @0xff431694
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x3650+0x54)); } // Found @0xff074f14 & 0xff074f4c
//char *camera_jpeg_count_str()    { return (char*)0x00110a74; }             // Found @0xff28ee48
//long hook_raw_size()             { return 0x0124ab50; }                    // Found @0xff43302c
//int get_flash_params_count(void) { return 0xa6; }                          // Found @0xff205ce4

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00000002 // Found @0xff49e5dc, levent 0x20a
//#define SD_READONLY_IDX     1
//#define USB_MASK            0x10000000 // Found @0xff49e64c, levent 0x202
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_SET             ,0x00000400 }, // Found @0xff49e55c, levent 0x08
//    { 0, KEY_DISPLAY         ,0x00000800 }, // Found @0xff49e564, levent 0x0a
//    { 0, KEY_DOWN            ,0x00001000 }, // Found @0xff49e56c, levent 0x05
//    { 0, KEY_MENU            ,0x00002000 }, // Found @0xff49e574, levent 0x09
//    { 0, KEY_LEFT            ,0x00004000 }, // Found @0xff49e57c, levent 0x06
//    { 0, KEY_UP              ,0x00040000 }, // Found @0xff49e59c, levent 0x04
//    { 0, KEY_RIGHT           ,0x00080000 }, // Found @0xff49e5a4, levent 0x07
//    { 2, KEY_POWER           ,0x00000800 }, // Found @0xff49e5fc, levent 0x100
//    { 2, KEY_PLAYBACK        ,0x00001000 }, // Found @0xff49e604, levent 0x101
//    { 2, KEY_SHOOT_FULL      ,0x0000c000 }, // Found @0xff49e61c, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00008000 }, // Found @0xff49e61c, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00004000 }, // Found @0xff49e614, levent 0x00
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
DEF(ctypes, 0xff49d1d8)

// For capt_seq.c
//static long *nrflag = (long*)(0xa414+0x0c);  // Found @ ff1f526c & ff1f5288

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NSTUB(AllocateMemory                          ,0xff38fe2c) //101
NSTUB(AllocateUncacheableMemory               ,0xff02093c) //112
NSTUB(Close                                   ,0xff01cadc) //101
NSTUB(CreateTask                              ,0x0068ab8c) //101
NSTUB(DebugAssert                             ,0x0068b104) //111
NSTUB(DeleteDirectory_Fut                     ,0xff01c4dc) //116
NSTUB(DoAFLock                                ,0xff01e97c) //102
NSTUB(EnterToCompensationEVF                  ,0xff01ed34) //104
NSTUB(ExecuteEventProcedure                   ,0xff097190) //104
NSTUB(ExitFromCompensationEVF                 ,0xff01ed78) //104
NSTUB(ExitTask                                ,0x0068ae1c) //101
NSTUB(ExpCtrlTool_StartContiAE                ,0xff02e7c0) //104
NSTUB(ExpCtrlTool_StopContiAE                 ,0xff02e928) //104
NSTUB(Fclose_Fut                              ,0xff01c574) //101
NSTUB(Feof_Fut                                ,0xff01c760) //  1
NSTUB(Fflush_Fut                              ,0xff01c79c) //  1
NSTUB(Fgets_Fut                               ,0xff01c6c8) //  6
NSTUB(Fopen_Fut                               ,0xff01c534) //101
NSTUB(Fread_Fut                               ,0xff01c620) //101
NSTUB(FreeMemory                              ,0xff38fe24) //101
NSTUB(FreeUncacheableMemory                   ,0xff02097c) //112
NSTUB(Fseek_Fut                               ,0xff01c714) //101
NSTUB(Fwrite_Fut                              ,0xff01c674) //101
NSTUB(GetBatteryTemperature                   ,0xff061324) //102
NSTUB(GetCCDTemperature                       ,0xff0612b0) //102
NSTUB(GetCurrentAvValue                       ,0xff1dd750) //102
NSTUB(GetDrive_ClusterSize                    ,0xff072b54) //  6
NSTUB(GetDrive_FreeClusters                   ,0xff072bac) //  6
NSTUB(GetDrive_TotalClusters                  ,0xff072b84) //  6
NSTUB(GetFocusLensSubjectDistance             ,0xff1db6dc) //102
NSTUB(GetFocusLensSubjectDistanceFromLens     ,0xff1dbb20) //  3
//NSTUB(GetImageFolder                        ,0xff1b8488) // 11            == 0xff1b8488
NSTUB(GetKbdState                             ,0xff05d908) //109
NSTUB(GetMemInfo                              ,0xff005280) //115
NSTUB(GetOpticalTemperature                   ,0xff061398) //102
NSTUB(GetParameterData                        ,0xff205ca4) //101
NSTUB(GetPropertyCase                         ,0xff09b1c0) //101
NSTUB(GetSystemTime                           ,0xff38fe84) //101
NSTUB(GetVRAMHPixelsSize                      ,0xff04191c) //102
NSTUB(GetVRAMVPixelsSize                      ,0xff041928) //102
NSTUB(GetZoomLensCurrentPoint                 ,0xff07b3ec) //102
NSTUB(GetZoomLensCurrentPosition              ,0xff1e4b98) //102
NSTUB(GiveSemaphore                           ,0x0068aaec) //112
NSTUB(IsStrobeChargeCompleted                 ,0xff037018) //102
NSTUB(LEDDrive                                ,0xff1f0e54) //101
//NSTUB(LocalTime                             ,0x0068f420) //115            == 0x0068f420
NSTUB(LockMainPower                           ,0xff09f41c) //103
NSTUB(Lseek                                   ,0xff01ccf8) //101
NSTUB(MakeSDCardBootable                      ,0xff072de4) //105
NSTUB(MoveFocusLensToDistance                 ,0xff42ca14) //102
NSTUB(MoveIrisWithAv                          ,0xff38b16c) //102
NSTUB(MoveZoomLensWithPoint                   ,0xff38ba18) //102
NSTUB(NewTaskShell                            ,0xff09ab44) //101
NSTUB(Open                                    ,0xff01ca14) //101
NSTUB(PB2Rec                                  ,0xff04a06c) //104
NSTUB(PT_MoveDigitalZoomToWide                ,0xff1f1f54) //102
NSTUB(PT_MoveOpticalZoomAt                    ,0xff1f1f2c) //102
NSTUB(PT_PlaySound                            ,0xff091b80) // 11
NSTUB(PostLogicalEventForNotPowerType         ,0xff09cd38) //103
NSTUB(PostLogicalEventToUI                    ,0xff09cd84) //103
NSTUB(PutInNdFilter                           ,0xff42b450) //102
NSTUB(PutOutNdFilter                          ,0xff42b48c) //102
NSTUB(Read                                    ,0xff005d3c) //101
NSTUB(ReadFastDir                             ,0xff36e4b4) //115
NSTUB(Rec2PB                                  ,0xff048798) //104
NSTUB(RefreshPhysicalScreen                   ,0xff0a191c) //104
NSTUB(Remove                                  ,0xff01cc50) //  6
NSTUB(RenameFile_Fut                          ,0xff01c3d4) //116
NSTUB(Restart                                 ,0xff022150) //106
NSTUB(ScreenLock                              ,0xff0a2928) //  4
NSTUB(ScreenUnlock                            ,0xff0a298c) //  3
NSTUB(SetAE_ShutterSpeed                      ,0xff43050c) //102
NSTUB(SetAutoShutdownTime                     ,0xff09f490) //103
NSTUB(SetCurrentCaptureModeType               ,0xff0aab9c) //101
NSTUB(SetFileAttributes                       ,0xff01cee0) //  6
NSTUB(SetFileTimeStamp                        ,0xff01ce68) //  6
NSTUB(SetLogicalEventActive                   ,0xff09f158) //101
NSTUB(SetParameterData                        ,0xff205b80) //101
NSTUB(SetPropertyCase                         ,0xff09b038) //101
NSTUB(SetScriptMode                           ,0xff09f1f4) //101
NSTUB(SleepTask                               ,0x0068c4e4) //101
NSTUB(TakeSemaphore                           ,0x0068aa1c) //101
NSTUB(TurnOffBackLight                        ,0xff0ae5b0) //104
NSTUB(TurnOnBackLight                         ,0xff0ae598) //104
NSTUB(UIFS_WriteFirmInfoToFile                ,0xff223ce0) //101
NSTUB(UnlockAF                                ,0xff01ea04) //102
NSTUB(UnlockMainPower                         ,0xff09f370) //103
NSTUB(VbattGet                                ,0xff018ae4) //101
NSTUB(Write                                   ,0xff01cb30) //101
NSTUB(WriteSDCard                             ,0xff1ccb54) //108
NSTUB(_log                                    ,0x00690cd8) //111
NSTUB(_log10                                  ,0x00693890) //112
NSTUB(_pow                                    ,0x00691390) //114
NSTUB(_sqrt                                   ,0x00693030) //  6
NSTUB(add_ptp_handler                         ,0xff3000d4) //  6
NSTUB(apex2us                                 ,0xff2b4aa0) //  4
NSTUB(close                                   ,0xff005b98) //  6
NSTUB(closedir                                ,0xff36e310) //  4
NSTUB(err_init_task                           ,0xff004310) //111
NSTUB(exmem_alloc                             ,0xff095b64) //101
NSTUB(free                                    ,0xff002f0c) //112
NSTUB(kbd_p1_f                                ,0xff01a380) //109
NSTUB(kbd_p1_f_cont                           ,0xff01a38c) //109
NSTUB(kbd_p2_f                                ,0xff019b28) //109
NSTUB(kbd_read_keys                           ,0xff01a330) //109
NSTUB(kbd_read_keys_r2                        ,0xff05cff0) //109
NSTUB(lseek                                   ,0xff01ccf8) //101
NSTUB(malloc                                  ,0xff002eb4) //112
NSTUB(memcmp                                  ,0xff00b5a4) //101
NSTUB(memcpy                                  ,0xff022a84) //101
NSTUB(memset                                  ,0xff2b2a48) //101
NSTUB(mkdir                                   ,0xff01cf78) //  6
NSTUB(mktime_ext                              ,0xff0b1d60) //  1
NSTUB(open                                    ,0xff005ae8) //  6
NSTUB(OpenFastDir                             ,0xff36e360) //115
NSTUB(qsort                                   ,0xff3f8320) //  6
NSTUB(rand                                    ,0xff2b2a18) //  6
NSTUB(read                                    ,0xff005d3c) //101
//NSTUB(reboot_fw_update                      ,0xff38f4d8) //106            == 0xff38f4d8
NSTUB(set_control_event                       ,0xff09ecfc) //111
NSTUB(srand                                   ,0xff2b2a0c) //  6
NSTUB(stat                                    ,0xff01cd40) //109
NSTUB(strcat                                  ,0xff0b23fc) //  1
NSTUB(strchr                                  ,0xff002d80) //  1
NSTUB(strcmp                                  ,0xff00b6a0) //101
NSTUB(strcpy                                  ,0xff00b58c) //101
NSTUB(strftime                                ,0xff0b1dac) //113
NSTUB(strlen                                  ,0xff002dcc) //101
NSTUB(strncmp                                 ,0xff002d34) //  1
NSTUB(strncpy                                 ,0xff002cf8) //  1
NSTUB(strrchr                                 ,0xff002da4) //  1
NSTUB(strtol                                  ,0xff022a70) //101
NSTUB(strtolx                                 ,0xff022874) //109
  DEF(task_CaptSeq                            ,0xff085a8c) //110
  DEF(task_ExpDrv                             ,0xff0cca8c) //110
  DEF(task_InitFileModules                    ,0xff04a93c) //110
  DEF(task_MovieRecord                        ,0xff0813c0) //110
  DEF(task_PhySw                              ,0xff019e8c) //110
  DEF(task_RotaryEncoder                      ,0xff05dc5c) //110
NSTUB(time                                    ,0x0068f8c8) //  6
NSTUB(vsprintf                                ,0xff00b43c) //115
NSTUB(write                                   ,0xff01cb30) //101
