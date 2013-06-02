// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R49 (DRYOS version 2.3, release #0049)
//   Firmware Ver GM1.00E
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
// Firmware modemap table found @ff09cf84 -> ff099208 -> ff205770 -> ff3877c4 -> ff626548
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x000386bc) // Found @0xff024db0
DEF(physw_run                               ,0x00001c3c) // Found @0xff02493c
DEF(physw_sleep_delay                       ,0x00001c44) // Found @0xff02493c
DEF(levent_table                            ,0xff5905c4) // Found @0xff5905c4
DEF(FlashParamsTable                        ,0xff6267ac) // Found @0xff6267ac
DEF(movie_status                            ,0x00009bfc) // Found @0xff1cb1b0
DEF(full_screen_refresh                     ,0x0000ca28) // Found @0xff297af0
DEF(canon_menu_active                       ,0x00004484) // Found @0xff0924cc
DEF(canon_shoot_menu_active                 ,0x0000b291) // Found @0xff22ca24
DEF(playrec_mode                            ,0x000041a4) // Found @0xff083ca8
DEF(zoom_status                             ,0x0000ad6c) // Found @0xff213958
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 2 int value(s), the first is the zoom focus length.
// there are 121 entries in the table - set NUM_FL to 121
DEF(focus_len_table                         ,0xfff4a4f8) // Found @0xfff4a4f8
DEF(zoom_busy                               ,0x00009b24) // Found @0xff1c6118
DEF(focus_busy                              ,0x00009940) // Found @0xff1bef10
DEF(recreview_hold                          ,0x00005008) // Found @0xff0a51b0
DEF(palette_control                         ,0x0000ca28) // Found @0xff297a6c
DEF(active_palette_buffer                   ,0x0000ca30) // Found @0xff297a70
DEF(palette_buffer                          ,0x000cf8d4) // Found @0xff297f38
DEF(bitmap_buffer                           ,0x0000ca6c) // Found @0xff29c9b0
DEF(active_bitmap_buffer                    ,0x0000ca64) // Found @0xff29c9b4
DEF(viewport_buffers                        ,0xff4531f0) // Found @0xff0466bc
DEF(active_viewport_buffer                  ,0x00002194) // Found @0xff046390

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x40685000; }             // Found @0xff051fbc
//void *vid_get_viewport_fb()      { return (void*)0x407dab80; }             // Found @0xff3fc0d0
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x3da0+0x58)); } // Found @0xff07007c & 0xff0700b4
//char *camera_jpeg_count_str()    { return (char*)0x000cf0cc; }             // Found @0xff289050
//long hook_raw_size()             { return 0x01297380; }                    // Found @0xff3feed8
//int get_flash_params_count(void) { return 0x9f; }                          // Found @0xff206d58

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00000800 // Found @0xff453804, levent 0x20a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x10000000 // Found @0xff453844, levent 0x202
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_DOWN            ,0x00000002 }, // Found @0xff453744, levent 0x05
//    { 0, KEY_LEFT            ,0x00000004 }, // Found @0xff45374c, levent 0x06
//    { 0, KEY_MENU            ,0x00000008 }, // Found @0xff453754, levent 0x09
//    { 0, KEY_SET             ,0x00000020 }, // Found @0xff453764, levent 0x08
//    { 0, KEY_UP              ,0x00000040 }, // Found @0xff45376c, levent 0x04
//    { 0, KEY_RIGHT           ,0x00000080 }, // Found @0xff453774, levent 0x07
//    { 0, KEY_VIDEO           ,0x00000100 }, // Found @0xff45377c, levent 0x19
//    { 0, KEY_ZOOM_OUT        ,0x00008000 }, // Found @0xff4537b4, levent 0x03
//    { 0, KEY_ZOOM_IN         ,0x00010000 }, // Found @0xff4537bc, levent 0x02
//    { 1, KEY_SHOOT_FULL      ,0x00300000 }, // Found @0xff4537e4, levent 0x01
//    { 1, KEY_SHOOT_FULL_ONLY ,0x00200000 }, // Found @0xff4537e4, levent 0x01
//    { 1, KEY_SHOOT_HALF      ,0x00100000 }, // Found @0xff4537dc, levent 0x00
//    { 1, KEY_POWER           ,0x00400000 }, // Found @0xff4537ec, levent 0x100
//    { 1, KEY_PLAYBACK        ,0x00800000 }, // Found @0xff4537f4, levent 0x101
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
DEF(ctypes, 0xff4524be)

// For capt_seq.c
//static long *nrflag = (long*)(0xcb38+0x00);  // Found @ ff2a57b4 & ff2a57f0
//#define NR_AUTO (0)                          // have to explictly reset value back to 0 to enable auto

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
//NHSTUB(CreateJumptable                      ,0xff3ff0a0) //  1
// ALT: NHSTUB(CreateJumptable, 0xff401324) // 1 32/0
//NHSTUB(_uartr_req                           ,0xff00ff3c) //111
//NHSTUB(AllocateMemory                       ,0xff37440c) //101
NHSTUB(AllocateUncacheableMemory              ,0xff02bd3c) //112
NHSTUB(Close                                  ,0xff0275bc) //101
NHSTUB(CreateTask                             ,0xff00eaf0) //101
NHSTUB(DebugAssert                            ,0xff00edc8) //111
NHSTUB(DeleteDirectory_Fut                    ,0xff026fb8) //116
NHSTUB(DeleteFile_Fut                         ,0xff026ed4) //112
NHSTUB(DoAFLock                               ,0xff029208) //102
NHSTUB(EnterToCompensationEVF                 ,0xff0295dc) //104
NHSTUB(ExecuteEventProcedure                  ,0xff08d868) //104
NHSTUB(ExitFromCompensationEVF                ,0xff029620) //104
NHSTUB(ExitTask                               ,0xff00ed80) //101
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff037d9c) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff037e7c) //104
NHSTUB(Fclose_Fut                             ,0xff027050) //101
NHSTUB(Feof_Fut                               ,0xff02723c) //  1
NHSTUB(Fflush_Fut                             ,0xff027278) //  1
NHSTUB(Fgets_Fut                              ,0xff0271a4) //  6
NHSTUB(Fopen_Fut                              ,0xff027010) //101
NHSTUB(Fread_Fut                              ,0xff0270fc) //101
//NHSTUB(FreeMemory                           ,0xff374404) //101
NHSTUB(FreeUncacheableMemory                  ,0xff02bd7c) //112
NHSTUB(Fseek_Fut                              ,0xff0271f0) //101
NHSTUB(Fwrite_Fut                             ,0xff027150) //101
NHSTUB(GetBatteryTemperature                  ,0xff05faac) //102
NHSTUB(GetCCDTemperature                      ,0xff05fa38) //102
NHSTUB(GetCurrentAvValue                      ,0xff1c1e48) //102
NHSTUB(GetDrive_ClusterSize                   ,0xff06e744) //  6
NHSTUB(GetDrive_FreeClusters                  ,0xff06e79c) //  6
NHSTUB(GetDrive_TotalClusters                 ,0xff06e774) //  6
NHSTUB(GetFocusLensSubjectDistance            ,0xff1bfc8c) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff1c00dc) //  3
NHSTUB(GetImageFolder                         ,0xff19a600) //  6
NHSTUB(GetKbdState                            ,0xff058f58) //109
NHSTUB(GetMemInfo                             ,0xff00a2b8) //115
NHSTUB(GetOpticalTemperature                  ,0xff05fb20) //102
NHSTUB(GetParameterData                       ,0xff206d18) //101
NHSTUB(GetPropertyCase                        ,0xff091950) //102
NHSTUB(GetSystemTime                          ,0xff374464) //101
NHSTUB(GetVRAMHPixelsSize                     ,0xff048f34) //102
NHSTUB(GetVRAMVPixelsSize                     ,0xff048f40) //102
NHSTUB(GetZoomLensCurrentPoint                ,0xff1c6590) //102
NHSTUB(GetZoomLensCurrentPosition             ,0xff35f998) //102
NHSTUB(GiveSemaphore                          ,0xff02b4bc) //112
NHSTUB(IsStrobeChargeCompleted                ,0xff0f2e64) //102
NHSTUB(LEDDrive                               ,0xff0582f8) //101
NHSTUB(LocalTime                              ,0xff08b22c) //115
NHSTUB(LockMainPower                          ,0xff098e00) //103
//NHSTUB(Lseek                                ,0xff0277d8) //101
NHSTUB(MakeDirectory_Fut                      ,0xff026f48) //116
NHSTUB(MakeSDCardBootable                     ,0xff06e9c4) //105
NHSTUB(MoveFocusLensToDistance                ,0xff3f8300) //102
NHSTUB(MoveIrisWithAv                         ,0xff370cac) //102
NHSTUB(MoveZoomLensWithPoint                  ,0xff371660) //102
//NHSTUB(NewTaskShell                         ,0xff091288) //101
NHSTUB(Open                                   ,0xff0274f4) //101
NHSTUB(PB2Rec                                 ,0xff09c3f4) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff079a78) //102
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff079a50) //102
NHSTUB(PT_PlaySound                           ,0xff085c9c) //  6
NHSTUB(PostLogicalEventForNotPowerType        ,0xff09671c) //103
NHSTUB(PostLogicalEventToUI                   ,0xff096768) //103
NHSTUB(PutInNdFilter                          ,0xff371438) //102
NHSTUB(PutOutNdFilter                         ,0xff37145c) //102
NHSTUB(Read                                   ,0xff00ad74) //101
NHSTUB(ReadFastDir                            ,0xff3498f4) //115
NHSTUB(Rec2PB                                 ,0xff09c434) //104
NHSTUB(RefreshPhysicalScreen                  ,0xff0b5954) //104
//NHSTUB(Remove                               ,0xff027730) //  6
NHSTUB(RenameFile_Fut                         ,0xff026e40) //116
NHSTUB(Restart                                ,0xff02d59c) //106
NHSTUB(ScreenLock                             ,0xff0b6b4c) //  4
NHSTUB(ScreenUnlock                           ,0xff0b6bb0) //  3
NHSTUB(SetAE_ShutterSpeed                     ,0xff3fb248) //102
NHSTUB(SetAutoShutdownTime                    ,0xff098e74) //103
NHSTUB(SetCurrentCaptureModeType              ,0xff0a24e0) //101
NHSTUB(SetFileAttributes                      ,0xff0279c0) //  6
NHSTUB(SetFileTimeStamp                       ,0xff027948) //  6
NHSTUB(SetLogicalEventActive                  ,0xff098b4c) //101
NHSTUB(SetParameterData                       ,0xff206bf4) //101
NHSTUB(SetPropertyCase                        ,0xff0917b4) //102
NHSTUB(SetScriptMode                          ,0xff098b9c) //101
NHSTUB(SleepTask                              ,0xff02b768) //101
NHSTUB(TakeSemaphore                          ,0xff02b3ec) //101
NHSTUB(TurnOffBackLight                       ,0xff0ad6b8) //104
NHSTUB(TurnOnBackLight                        ,0xff0ad6a0) //104
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff1f07bc) //101
NHSTUB(UnlockAF                               ,0xff029240) //102
NHSTUB(UnlockMainPower                        ,0xff098d54) //103
NHSTUB(VbattGet                               ,0xff02237c) //101
NHSTUB(Write                                  ,0xff027610) //101
NHSTUB(WriteSDCard                            ,0xff1b0930) //108
NHSTUB(_log                                   ,0xff44ef40) //111
NHSTUB(_log10                                 ,0xff44f408) //112
NHSTUB(_pow                                   ,0xff44f56c) //114
NHSTUB(_sqrt                                  ,0xff4512d4) //  6
NHSTUB(add_ptp_handler                        ,0xff2e69b0) //  6
NHSTUB(apex2us                                ,0xff29f17c) //  4
NHSTUB(close                                  ,0xff00abd0) //  6
NHSTUB(closedir                               ,0xff349750) //  4
NHSTUB(err_init_task                          ,0xff00602c) //111
NHSTUB(exmem_alloc                            ,0xff08c1ec) //101
NHSTUB(free                                   ,0xff004264) //112
NHSTUB(kbd_p1_f                               ,0xff024e00) //109
NHSTUB(kbd_p1_f_cont                          ,0xff024e0c) //109
NHSTUB(kbd_p2_f                               ,0xff0245d4) //109
NHSTUB(kbd_read_keys                          ,0xff024db0) //109
NHSTUB(kbd_read_keys_r2                       ,0xff0587c8) //109
NHSTUB(lseek                                  ,0xff0277d8) //101
NHSTUB(malloc                                 ,0xff00420c) //112
NHSTUB(memcmp                                 ,0xff010a60) //101
NHSTUB(memcpy                                 ,0xff0316c0) //101
NHSTUB(memset                                 ,0xff29d1a0) //101
NHSTUB(mkdir                                  ,0xff027a58) //109
NHSTUB(mktime_ext                             ,0xff0b79a0) //  1
NHSTUB(open                                   ,0xff00ab20) //  6
NHSTUB(OpenFastDir                            ,0xff3497a0) //115
NHSTUB(qsort                                  ,0xff3c8158) //  6
NHSTUB(rand                                   ,0xff29d2dc) //  6
//NHSTUB(read                                 ,0xff00ad74) //101
NHSTUB(reboot_fw_update                       ,0xff34f048) //106
NHSTUB(set_control_event                      ,0xff098740) //111
NHSTUB(srand                                  ,0xff29d2d0) //  6
NHSTUB(stat                                   ,0xff027820) //109
NHSTUB(strcat                                 ,0xff0b7158) //  1
NHSTUB(strchr                                 ,0xff0040d8) //  1
NHSTUB(strcmp                                 ,0xff010a1c) //101
NHSTUB(strcpy                                 ,0xff010a04) //101
NHSTUB(strftime                               ,0xff0b73a0) //113
NHSTUB(strlen                                 ,0xff004124) //101
NHSTUB(strncmp                                ,0xff00408c) //  1
NHSTUB(strncpy                                ,0xff004050) //  1
NHSTUB(strrchr                                ,0xff0040fc) //  1
NHSTUB(strtol                                 ,0xff0319c0) //101
NHSTUB(strtolx                                ,0xff0317c4) //109
   DEF(task_CaptSeq                           ,0xff07ccdc) //110
   DEF(task_ExpDrv                            ,0xff0cfb78) //110
   DEF(task_InitFileModules                   ,0xff09cdf8) //110
   DEF(task_MovieRecord                       ,0xff1cc43c) //110
   DEF(task_PhySw                             ,0xff024938) //110
   DEF(task_RotaryEncoder                     ,0xff05927c) //110
NHSTUB(time                                   ,0xff08b808) //109
NHSTUB(vsprintf                               ,0xff0109c4) //115
//NHSTUB(write                                ,0xff027610) //101
//NHSTUB(GetSDProtect                         ,0xff024d6c) //101
//NHSTUB(StartRecModeMenu                     ,0xff0924c8) //102
//NHSTUB(DispCon_ShowBitmapColorBar           ,0xff051f78) //102
//NHSTUB(ResetZoomLens                        ,0xff3715b4) //102
//NHSTUB(ResetFocusLens                       ,0xff36fe88) //102
//NHSTUB(NR_GetDarkSubType                    ,0xff2a5874) //102
//NHSTUB(NR_SetDarkSubType                    ,0xff2a57ac) //102
//NHSTUB(SavePaletteData                      ,0xff1cfd44) //102
//NHSTUB(GUISrv_StartGUISystem                ,0xff0b516c) //101
