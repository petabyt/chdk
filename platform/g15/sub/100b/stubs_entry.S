// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R51 (DRYOS version 2.3, release #0051)
//   Firmware Ver GM1.00B
//   Canon PowerShot G15

// Values for makefile.inc
//   PLATFORMOSVER = 51
//   PLATFORMID = 12888 (0x3258) // Found @ 0xfff40040
//   MAXRAMADDR = 0x0fffffff
//   KEYSYS = d4c                // Found @ 0xffff3c68
//   NEED_ENCODED_DISKBOOT = 9   // Found @ 0xffff3c78

// Note, ROM copied to RAM :- from 0xff745bc0, to 0x00685000, len 16605 words.

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
NSTUB(DeleteFile_Fut                          ,0xff01c4f0) //  1 90%
// ERROR: MakeDirectory_Fut is not found.                  //--- ---    *** != 0xff01d000
// ERROR: kbd_pwr_off is not found.                        //--- ---    *** != 0x00000000
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff04a908 -> ff09e138 -> ff1f5208 -> ff395770 -> ff6f0ffc
// Mode 16924 in firmware but not in current modemap
// Mode  8745 in firmware but not in current modemap
// Mode 33295 in firmware but not in current modemap

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x0003ac0c) // Found @0xff01a3b8
DEF(physw_run                               ,0x00001d64) // Found @0xff019f14
DEF(physw_sleep_delay                       ,0x00001d6c) // Found @0xff019f14
DEF(levent_table                            ,0xff618310) // Found @0xff618310
DEF(FlashParamsTable                        ,0xff6f1280) // Found @0xff6f1280
DEF(full_screen_refresh                     ,0x00009d30) // Found @0xff1ff130
DEF(canon_menu_active                       ,0x00004470) // Found @0xff0a1920
DEF(canon_shoot_menu_active                 ,0x0000c18d) // Found @0xff29f8b4
DEF(playrec_mode                            ,0x00003988) // Found @0xff08ded0
DEF(zoom_status                             ,0x000069e0) // Found @0xff159738
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 2 int value(s), the first is the zoom focus length.
// there are 121 entries in the table - set NUM_FL to 121
DEF(focus_len_table                         ,0xfff4a700) // Found @0xfff4a700
DEF(zoom_busy                               ,0x00009300) // Found @0xff1d8ba4
DEF(focus_busy                              ,0x0000907c) // Found @0xff1d1a28
DEF(recreview_hold                          ,0x00002a28) // Found @0xff054378
DEF(palette_control                         ,0x00009d30) // Found @0xff1ff0ac
DEF(active_palette_buffer                   ,0x00009d38) // Found @0xff1ff0b0
DEF(palette_buffer                          ,0x000e181c) // Found @0xff1ff578
DEF(bitmap_buffer                           ,0x00009d74) // Found @0xff202f5c
DEF(active_bitmap_buffer                    ,0x00009d6c) // Found @0xff202f60

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x406c5000; }             // Found @0xff057d44
//void *vid_get_viewport_fb()      { return (void*)0x4081ab80; }             // Found @0xff4307e0
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x3530+0x54)); } // Found @0xff0760cc & 0xff076104
//char *camera_jpeg_count_str()    { return (char*)0x000e7034; }             // Found @0xff283048
//long hook_raw_size()             { return 0x01297380; }                    // Found @0xff43217c
//int get_flash_params_count(void) { return 0xa6; }                          // Found @0xff1f67a0

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00000002 // Found @0xff4a0da4, levent 0x20a
//#define SD_READONLY_IDX     1
//#define USB_MASK            0x10000000 // Found @0xff4a0e0c, levent 0x202
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_SET             ,0x00000800 }, // Found @0xff4a0d2c, levent 0x08
//    { 0, KEY_RIGHT           ,0x00001000 }, // Found @0xff4a0d34, levent 0x07
//    { 0, KEY_DOWN            ,0x00002000 }, // Found @0xff4a0d3c, levent 0x05
//    { 0, KEY_MENU            ,0x00004000 }, // Found @0xff4a0d44, levent 0x09
//    { 0, KEY_LEFT            ,0x00008000 }, // Found @0xff4a0d4c, levent 0x06
//    { 0, KEY_UP              ,0x00040000 }, // Found @0xff4a0d64, levent 0x04
//    { 0, KEY_ZOOM_IN         ,0x00100000 }, // Found @0xff4a0d74, levent 0x02
//    { 0, KEY_ZOOM_OUT        ,0x00200000 }, // Found @0xff4a0d7c, levent 0x03
//    { 2, KEY_POWER           ,0x00000800 }, // Found @0xff4a0dc4, levent 0x100
//    { 2, KEY_PLAYBACK        ,0x00008000 }, // Found @0xff4a0dcc, levent 0x101
//    { 2, KEY_SHOOT_FULL      ,0x000c0000 }, // Found @0xff4a0ddc, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00080000 }, // Found @0xff4a0ddc, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00040000 }, // Found @0xff4a0dd4, levent 0x00
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#define CAM_RAW_ROWPIX    4160 // Found @0xff1a77cc
//#define CAM_RAW_ROWS      3124 // Found @0xff1a77d4
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff020880

// Misc stuff
DEF(ctypes, 0xff49f940)

// For capt_seq.c
//static long *nrflag = (long*)(0xc39c+0x00);  // Found @ ff2b0830 & ff2b086c
//#define NR_AUTO (0)                          // have to explictly reset value back to 0 to enable auto

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
//NSTUB(CreateJumptable                       ,0xff432344) //  1
// ALT: NSTUB(CreateJumptable, 0xff434b34) // 1 32/0
//NSTUB(_uartr_req                            ,0xff00af50) //111
//NSTUB(AllocateMemory                        ,0xff390dd0) //101
NSTUB(AllocateUncacheableMemory               ,0xff020838) //112
NSTUB(Close                                   ,0xff01cb64) //101
NSTUB(CreateTask                              ,0x0068ab8c) //101
NSTUB(DebugAssert                             ,0x0068b104) //111
NSTUB(DeleteDirectory_Fut                     ,0xff01c564) //116
NSTUB(DoAFLock                                ,0xff01e8e0) //102
NSTUB(EnterToCompensationEVF                  ,0xff01ec9c) //104
NSTUB(ExecuteEventProcedure                   ,0xff0956c0) //104
NSTUB(ExitFromCompensationEVF                 ,0xff01ece0) //104
NSTUB(ExitTask                                ,0x0068ae1c) //101
NSTUB(ExpCtrlTool_StartContiAE                ,0xff02e74c) //104
NSTUB(ExpCtrlTool_StopContiAE                 ,0xff02e8b4) //104
NSTUB(Fclose_Fut                              ,0xff01c5fc) //101
NSTUB(Feof_Fut                                ,0xff01c7e8) //  1
NSTUB(Fflush_Fut                              ,0xff01c824) //  1
NSTUB(Fgets_Fut                               ,0xff01c750) //  6
NSTUB(Fopen_Fut                               ,0xff01c5bc) //101
NSTUB(Fread_Fut                               ,0xff01c6a8) //101
//NSTUB(FreeMemory                            ,0xff390dc8) //101
NSTUB(FreeUncacheableMemory                   ,0xff020878) //112
NSTUB(Fseek_Fut                               ,0xff01c79c) //101
NSTUB(Fwrite_Fut                              ,0xff01c6fc) //101
NSTUB(GetBatteryTemperature                   ,0xff0622e8) //102
NSTUB(GetCCDTemperature                       ,0xff062274) //102
NSTUB(GetCurrentAvValue                       ,0xff07d4d0) //102
NSTUB(GetDrive_ClusterSize                    ,0xff073d0c) //  6
NSTUB(GetDrive_FreeClusters                   ,0xff073d64) //  6
NSTUB(GetDrive_TotalClusters                  ,0xff073d3c) //  6
NSTUB(GetFocusLensSubjectDistance             ,0xff1d2a40) //102
NSTUB(GetFocusLensSubjectDistanceFromLens     ,0xff1d2dfc) //  3
NSTUB(GetImageFolder                          ,0xff1b14e4) // 11
NSTUB(GetKbdState                             ,0xff05e860) //109
NSTUB(GetMemInfo                              ,0xff005280) //115
NSTUB(GetOpticalTemperature                   ,0xff06235c) //102
NSTUB(GetParameterData                        ,0xff1f6760) //101
NSTUB(GetPropertyCase                         ,0xff0996f0) //101
NSTUB(GetSystemTime                           ,0xff390e28) //101
NSTUB(GetVRAMHPixelsSize                      ,0xff041770) //102
NSTUB(GetVRAMVPixelsSize                      ,0xff04177c) //102
NSTUB(GetZoomLensCurrentPoint                 ,0xff1d9018) //102
NSTUB(GetZoomLensCurrentPosition              ,0xff37be30) //102
NSTUB(GiveSemaphore                           ,0x0068aaec) //112
NSTUB(IsStrobeChargeCompleted                 ,0xff036f38) //102
NSTUB(LEDDrive                                ,0xff1e0bf0) //101
NSTUB(LocalTime                               ,0x0068f420) //115
NSTUB(LockMainPower                           ,0xff09dad4) //103
//NSTUB(Lseek                                 ,0xff01cd80) //101
NSTUB(MakeSDCardBootable                      ,0xff073f9c) //105
NSTUB(MoveFocusLensToDistance                 ,0xff42c324) //102
NSTUB(MoveIrisWithAv                          ,0xff38cf8c) //102
NSTUB(MoveZoomLensWithPoint                   ,0xff38d948) //102
//NSTUB(NewTaskShell                          ,0xff099074) //101
NSTUB(Open                                    ,0xff01ca9c) //101
NSTUB(PB2Rec                                  ,0xff049dd0) //104
NSTUB(PT_MoveDigitalZoomToWide                ,0xff1e1cf0) //102
NSTUB(PT_MoveOpticalZoomAt                    ,0xff1e1cc8) //102
NSTUB(PT_PlaySound                            ,0xff0900b0) // 11
NSTUB(PostLogicalEventForNotPowerType         ,0xff09b28c) //103
NSTUB(PostLogicalEventToUI                    ,0xff09b2d8) //103
NSTUB(PutInNdFilter                           ,0xff38d718) //102
NSTUB(PutOutNdFilter                          ,0xff38d73c) //102
NSTUB(Read                                    ,0xff005d3c) //101
NSTUB(ReadFastDir                             ,0xff368a24) //115
NSTUB(Rec2PB                                  ,0xff049e10) //104
NSTUB(RefreshPhysicalScreen                   ,0xff0a0310) //104
//NSTUB(Remove                                ,0xff01ccd8) //  6
NSTUB(RenameFile_Fut                          ,0xff01c45c) //116
NSTUB(Restart                                 ,0xff02204c) //106
NSTUB(ScreenLock                              ,0xff0a12e8) //  4
NSTUB(ScreenUnlock                            ,0xff0a134c) //  3
NSTUB(SetAE_ShutterSpeed                      ,0xff42f658) //102
NSTUB(SetAutoShutdownTime                     ,0xff09db48) //103
NSTUB(SetCurrentCaptureModeType               ,0xff0a9438) //101
NSTUB(SetFileAttributes                       ,0xff01cf68) //  6
NSTUB(SetFileTimeStamp                        ,0xff01cef0) //  6
NSTUB(SetLogicalEventActive                   ,0xff09d820) //101
NSTUB(SetParameterData                        ,0xff1f663c) //101
NSTUB(SetPropertyCase                         ,0xff099568) //101
NSTUB(SetScriptMode                           ,0xff09d870) //101
NSTUB(SleepTask                               ,0x0068c4e4) //101
NSTUB(TakeSemaphore                           ,0x0068aa1c) //101
NSTUB(TurnOffBackLight                        ,0xff0ad224) //104
NSTUB(TurnOnBackLight                         ,0xff0ad20c) //104
NSTUB(UIFS_WriteFirmInfoToFile                ,0xff214a94) //101
NSTUB(UnlockAF                                ,0xff01e918) //102
NSTUB(UnlockMainPower                         ,0xff09da28) //103
NSTUB(UnsetZoomForMovie                       ,0xff04fea0) //104
NSTUB(VbattGet                                ,0xff018ad4) //101
NSTUB(Write                                   ,0xff01cbb8) //101
NSTUB(WriteSDCard                             ,0xff1c5bd4) //108
NSTUB(_log                                    ,0x006915c0) //111
NSTUB(_log10                                  ,0x00691b00) //112
NSTUB(_pow                                    ,0x00691c78) //114
NSTUB(_sqrt                                   ,0x00693bd8) //  6
NSTUB(add_ptp_handler                         ,0xff2f7708) //  6
NSTUB(apex2us                                 ,0xff2a9c7c) //  4
NSTUB(close                                   ,0xff005b98) //  6
NSTUB(closedir                                ,0xff368880) //  4
NSTUB(err_init_task                           ,0xff004310) //111
NSTUB(exmem_alloc                             ,0xff094094) //101
NSTUB(free                                    ,0xff002f0c) //112
NSTUB(kbd_p1_f                                ,0xff01a408) //109
NSTUB(kbd_p1_f_cont                           ,0xff01a414) //109
NSTUB(kbd_p2_f                                ,0xff019bac) //109
NSTUB(kbd_read_keys                           ,0xff01a3b8) //109
NSTUB(kbd_read_keys_r2                        ,0xff05e000) //109
NSTUB(lseek                                   ,0xff01cd80) //101
NSTUB(malloc                                  ,0xff002eb4) //112
NSTUB(memcmp                                  ,0xff00b5a4) //101
NSTUB(memcpy                                  ,0xff02297c) //101
NSTUB(memset                                  ,0xff2a7c24) //101
NSTUB(mkdir                                   ,0xff01d000) //  6
NSTUB(mktime_ext                              ,0xff0b0a60) //  1
NSTUB(open                                    ,0xff005ae8) //  6
NSTUB(OpenFastDir                             ,0xff3688d0) //115
NSTUB(qsort                                   ,0xff3f62d4) //  6
NSTUB(rand                                    ,0xff2a7bf4) //  6
//NSTUB(read                                  ,0xff005d3c) //101
NSTUB(reboot_fw_update                        ,0xff3903c0) //106
NSTUB(set_control_event                       ,0xff09d414) //111
NSTUB(srand                                   ,0xff2a7be8) //  6
NSTUB(stat                                    ,0xff01cdc8) //109
NSTUB(strcat                                  ,0xff0b10fc) //  1
NSTUB(strchr                                  ,0xff002d80) //  1
NSTUB(strcmp                                  ,0xff00b6a0) //101
NSTUB(strcpy                                  ,0xff00b58c) //101
NSTUB(strftime                                ,0xff0b0aac) //113
NSTUB(strlen                                  ,0xff002dcc) //101
NSTUB(strncmp                                 ,0xff002d34) //  1
NSTUB(strncpy                                 ,0xff002cf8) //  1
NSTUB(strrchr                                 ,0xff002da4) //  1
NSTUB(strtol                                  ,0xff022968) //101
NSTUB(strtolx                                 ,0xff02276c) //109
  DEF(task_CaptSeq                            ,0xff0856d8) //110
  DEF(task_ExpDrv                             ,0xff0cb0a4) //110
  DEF(task_InitFileModules                    ,0xff04a77c) //110
  DEF(task_MovieRecord                        ,0xff1df2b0) //110
  DEF(task_PhySw                              ,0xff019f10) //110
  DEF(task_RotaryEncoder                      ,0xff05ebb4) //110
NSTUB(time                                    ,0x0068f8c8) //  6
NSTUB(vsprintf                                ,0xff00b43c) //115
//NSTUB(write                                 ,0xff01cbb8) //101
//NSTUB(GetSDProtect                          ,0xff01a36c) //101
//NSTUB(StartRecModeMenu                      ,0xff0a191c) //102
//NSTUB(DispCon_ShowBitmapColorBar            ,0xff057d00) //102
//NSTUB(ResetZoomLens                         ,0xff38d89c) //102
//NSTUB(ResetFocusLens                        ,0xff38c030) //102
//NSTUB(NR_GetDarkSubType                     ,0xff2b08f0) //102
//NSTUB(NR_SetDarkSubType                     ,0xff2b0828) //102
//NSTUB(SavePaletteData                       ,0xff1e238c) //102
//NSTUB(GUISrv_StartGUISystem                 ,0xff09fb64) //101
