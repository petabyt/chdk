// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R49 (DRYOS version 2.3, release #0049)
//   Firmware Ver GM1.00F
//   Canon PowerShot SX40 HS

// Values for makefile.inc
//   PLATFORMOSVER = 49
//   PLATFORMID = 12856 (0x3238) // Found @ 0xfff40040
//   MAXRAMADDR = 0x0fffffff
//   KEYSYS = d4c                // Found @ 0xffff3b48
//   NEED_ENCODED_DISKBOOT = 7   // Found @ 0xffff3b58

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
// ERROR: kbd_pwr_off is not found.                        //--- ---    *** != 0x00000000
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff09bd3c -> ff0985bc -> ff2047c4 -> ff36a8ec -> ff607d14
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00037548) // Found @0xff024dd8
DEF(physw_run                               ,0x00001c10) // Found @0xff024968
DEF(physw_sleep_delay                       ,0x00001c18) // Found @0xff024968
DEF(levent_table                            ,0xff593a0c) // Found @0xff593a0c
DEF(FlashParamsTable                        ,0xff607f74) // Found @0xff607f74
DEF(movie_status                            ,0x00002f1c) // Found @0xff0772a8
DEF(full_screen_refresh                     ,0x0000c2d8) // Found @0xff2917e4
DEF(canon_menu_active                       ,0x000034f0) // Found @0xff091b6c
DEF(canon_shoot_menu_active                 ,0x0000ab6d) // Found @0xff22a708
DEF(playrec_mode                            ,0x00003214) // Found @0xff083504
DEF(zoom_status                             ,0x000111f8) // Found @0xff36e6dc
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 1 int value, which is the the zoom focus length.
// there are 201 entries in the table - set NUM_FL to 201
DEF(focus_len_table                         ,0xfff4a7b4) // Found @0xfff4a7b4
DEF(zoom_busy                               ,0x00002e2c) // Found @0xff071c6c
DEF(focus_busy                              ,0x00008d08) // Found @0xff1bbe84
DEF(recreview_hold                          ,0x000041e4) // Found @0xff0a443c
DEF(palette_control                         ,0x0000c2d8) // Found @0xff291760
DEF(active_palette_buffer                   ,0x0000c2e0) // Found @0xff291764
DEF(palette_buffer                          ,0x000df7f0) // Found @0xff291c2c
DEF(bitmap_buffer                           ,0x0000c31c) // Found @0xff295470
DEF(active_bitmap_buffer                    ,0x0000c314) // Found @0xff295474
DEF(viewport_buffers                        ,0xff43457c) // Found @0xff045ba8
DEF(active_viewport_buffer                  ,0x0000215c) // Found @0xff045820

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x40685000; }             // Found @0xff0515dc
//void *vid_get_viewport_fb()      { return (void*)0x407dab80; }             // Found @0xff3e0b3c
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x2ca0+0x58)); } // Found @0xff06bfac & 0xff06bfe4
//char *camera_jpeg_count_str()    { return (char*)0x000df0e8; }             // Found @0xff28543c
//long hook_raw_size()             { return 0x01247a60; }                    // Found @0xff3e3940
//int get_flash_params_count(void) { return 0x9f; }                          // Found @0xff205db8

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00000002 // Found @0xff434b6c, levent 0x20a
//#define SD_READONLY_IDX     1
//#define USB_MASK            0x40000000 // Found @0xff434be4, levent 0x202
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_UP              ,0x00000400 }, // Found @0xff434aec, levent 0x04
//    { 0, KEY_DOWN            ,0x00000800 }, // Found @0xff434af4, levent 0x05
//    { 0, KEY_LEFT            ,0x00001000 }, // Found @0xff434afc, levent 0x06
//    { 0, KEY_RIGHT           ,0x00002000 }, // Found @0xff434b04, levent 0x07
//    { 0, KEY_SET             ,0x00004000 }, // Found @0xff434b0c, levent 0x08
//    { 0, KEY_VIDEO           ,0x00008000 }, // Found @0xff434b14, levent 0x19
//    { 0, KEY_DISPLAY         ,0x00020000 }, // Found @0xff434b24, levent 0x0a
//    { 0, KEY_MENU            ,0x00040000 }, // Found @0xff434b2c, levent 0x09
//    { 2, KEY_POWER           ,0x00000800 }, // Found @0xff434b8c, levent 0x100
//    { 2, KEY_PLAYBACK        ,0x00001000 }, // Found @0xff434b94, levent 0x101
//    { 2, KEY_SHOOT_FULL      ,0x0000c000 }, // Found @0xff434bac, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00008000 }, // Found @0xff434bac, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00004000 }, // Found @0xff434ba4, levent 0x00
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#define CAM_RAW_ROWPIX    4176 // Found @0xff18e050
//#define CAM_RAW_ROWS      3060 // Found @0xff18e05c
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff02bea8

// Misc stuff
DEF(ctypes, 0xff43381a)

// For capt_seq.c
//static long *nrflag = (long*)(0xc3f8+0x00);  // Found @ ff29e39c & ff29e3d8
//#define NR_AUTO (0)                          // have to explictly reset value back to 0 to enable auto

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
//NSTUB(CreateJumptable                       ,0xff3e3b08) //  1
// ALT: NSTUB(CreateJumptable, 0xff3e5fb4) // 1 32/0
//NSTUB(_uartr_req                            ,0xff00ff24) //111
//NSTUB(AllocateMemory                        ,0xff359768) //101
NSTUB(AllocateUncacheableMemory               ,0xff02be60) //112
NSTUB(Close                                   ,0xff0275e4) //101
NSTUB(CreateTask                              ,0xff00eaf0) //101
NSTUB(DebugAssert                             ,0xff00edc8) //111
NSTUB(DeleteDirectory_Fut                     ,0xff026fe0) //116
NSTUB(DeleteFile_Fut                          ,0xff026efc) //112
NSTUB(DoAFLock                                ,0xff029330) //102
NSTUB(EnterToCompensationEVF                  ,0xff029704) //104
NSTUB(ExecuteEventProcedure                   ,0xff08d004) //104
NSTUB(ExitFromCompensationEVF                 ,0xff029748) //104
NSTUB(ExitTask                                ,0xff00ed80) //101
NSTUB(ExpCtrlTool_StartContiAE                ,0xff037bf0) //104
NSTUB(ExpCtrlTool_StopContiAE                 ,0xff037cd0) //104
NSTUB(Fclose_Fut                              ,0xff027078) //101
NSTUB(Feof_Fut                                ,0xff027264) //  1
NSTUB(Fflush_Fut                              ,0xff0272a0) //  1
NSTUB(Fgets_Fut                               ,0xff0271cc) //  6
NSTUB(Fopen_Fut                               ,0xff027038) //101
NSTUB(Fread_Fut                               ,0xff027124) //101
//NSTUB(FreeMemory                            ,0xff359760) //101
NSTUB(FreeUncacheableMemory                   ,0xff02bea0) //112
NSTUB(Fseek_Fut                               ,0xff027218) //101
NSTUB(Fwrite_Fut                              ,0xff027178) //101
NSTUB(GetBatteryTemperature                   ,0xff05bbe8) //102
NSTUB(GetCCDTemperature                       ,0xff05bb74) //102
NSTUB(GetCurrentAvValue                       ,0xff1bebc0) //102
NSTUB(GetDrive_ClusterSize                    ,0xff06a60c) //  6
NSTUB(GetDrive_FreeClusters                   ,0xff06a664) //  6
NSTUB(GetDrive_TotalClusters                  ,0xff06a63c) //  6
NSTUB(GetFocusLensSubjectDistance             ,0xff1bca7c) //102
NSTUB(GetFocusLensSubjectDistanceFromLens     ,0xff1bcde8) //  3
NSTUB(GetImageFolder                          ,0xff197660) //  6
NSTUB(GetKbdState                             ,0xff057c04) //109
NSTUB(GetMemInfo                              ,0xff00a2b8) //115
NSTUB(GetOpticalTemperature                   ,0xff05bc5c) //102
NSTUB(GetParameterData                        ,0xff205d78) //101
NSTUB(GetPropertyCase                         ,0xff0910a4) //102
NSTUB(GetSystemTime                           ,0xff3597c0) //101
NSTUB(GetVRAMHPixelsSize                      ,0xff0487f0) //102
NSTUB(GetVRAMVPixelsSize                      ,0xff0487fc) //102
NSTUB(GetZoomLensCurrentPoint                 ,0xff071ffc) //102
NSTUB(GetZoomLensCurrentPosition              ,0xff1c4fb8) //102
NSTUB(GiveSemaphore                           ,0xff02b5e0) //112
NSTUB(IsStrobeChargeCompleted                 ,0xff0efe04) //102
NSTUB(LEDDrive                                ,0xff056e58) //101
NSTUB(LocalTime                               ,0xff08a9c8) //115
NSTUB(LockMainPower                           ,0xff0981b4) //103
//NSTUB(Lseek                                 ,0xff027800) //101
NSTUB(MakeDirectory_Fut                       ,0xff026f70) //116
NSTUB(MakeSDCardBootable                      ,0xff06a89c) //105
NSTUB(MoveFocusLensToDistance                 ,0xff3dc670) //102
NSTUB(MoveIrisWithAv                          ,0xff355078) //102
NSTUB(MoveZoomLensWithPoint                   ,0xff3558d4) //102
//NSTUB(NewTaskShell                          ,0xff090a24) //101
NSTUB(Open                                    ,0xff02751c) //101
NSTUB(PB2Rec                                  ,0xff09b3ac) //104
NSTUB(PT_MoveDigitalZoomToWide                ,0xff0790a8) //102
NSTUB(PT_MoveOpticalZoomAt                    ,0xff079080) //102
NSTUB(PT_PlaySound                            ,0xff085438) //  6
NSTUB(PostLogicalEventForNotPowerType         ,0xff095b98) //103
NSTUB(PostLogicalEventToUI                    ,0xff095be4) //103
NSTUB(PutInNdFilter                           ,0xff3da154) //102
NSTUB(PutOutNdFilter                          ,0xff3da18c) //102
NSTUB(Read                                    ,0xff00ad74) //101
NSTUB(ReadFastDir                             ,0xff3396d0) //115
NSTUB(Rec2PB                                  ,0xff099b1c) //104
NSTUB(RefreshPhysicalScreen                   ,0xff0b1a24) //104
//NSTUB(Remove                                ,0xff027758) //  6
NSTUB(RenameFile_Fut                          ,0xff026e68) //116
NSTUB(Restart                                 ,0xff02d6a0) //106
NSTUB(ScreenLock                              ,0xff0b2c50) //  4
NSTUB(ScreenUnlock                            ,0xff0b2cb4) //  3
NSTUB(SetAE_ShutterSpeed                      ,0xff3dfcb4) //102
NSTUB(SetAutoShutdownTime                     ,0xff098228) //103
NSTUB(SetCurrentCaptureModeType               ,0xff0a1650) //101
NSTUB(SetFileAttributes                       ,0xff0279e8) //  6
NSTUB(SetFileTimeStamp                        ,0xff027970) //  6
NSTUB(SetLogicalEventActive                   ,0xff097ef0) //101
NSTUB(SetParameterData                        ,0xff205c54) //101
NSTUB(SetPropertyCase                         ,0xff090f1c) //102
NSTUB(SetScriptMode                           ,0xff097f8c) //101
NSTUB(SleepTask                               ,0xff02b88c) //101
NSTUB(TakeSemaphore                           ,0xff02b510) //101
NSTUB(TurnOffBackLight                        ,0xff0a96b0) //104
NSTUB(TurnOnBackLight                         ,0xff0a9698) //104
NSTUB(UIFS_WriteFirmInfoToFile                ,0xff1f15b8) //101
NSTUB(UnlockAF                                ,0xff029368) //102
NSTUB(UnlockMainPower                         ,0xff098108) //103
NSTUB(VbattGet                                ,0xff022364) //101
NSTUB(Write                                   ,0xff027638) //101
NSTUB(WriteSDCard                             ,0xff1ab470) //108
NSTUB(_log                                    ,0xff430340) //111
NSTUB(_log10                                  ,0xff430880) //112
NSTUB(_pow                                    ,0xff4309f8) //114
NSTUB(_sqrt                                   ,0xff43261c) //  6
NSTUB(add_ptp_handler                         ,0xff2dfff4) //  6
NSTUB(apex2us                                 ,0xff297c28) //  4
NSTUB(close                                   ,0xff00abd0) //  6
NSTUB(closedir                                ,0xff33952c) //  4
NSTUB(err_init_task                           ,0xff00602c) //111
NSTUB(exmem_alloc                             ,0xff08b988) //101
NSTUB(free                                    ,0xff004264) //112
NSTUB(kbd_p1_f                                ,0xff024e28) //109
NSTUB(kbd_p1_f_cont                           ,0xff024e34) //109
NSTUB(kbd_p2_f                                ,0xff024600) //109
NSTUB(kbd_read_keys                           ,0xff024dd8) //109
NSTUB(kbd_read_keys_r2                        ,0xff05730c) //109
NSTUB(lseek                                   ,0xff027800) //101
NSTUB(malloc                                  ,0xff00420c) //112
NSTUB(memcmp                                  ,0xff010a48) //101
NSTUB(memcpy                                  ,0xff03169c) //101
NSTUB(memset                                  ,0xff295c60) //101
NSTUB(mkdir                                   ,0xff027a80) //109
NSTUB(mktime_ext                              ,0xff0b3bc0) //  1
NSTUB(open                                    ,0xff00ab20) //  6
NSTUB(OpenFastDir                             ,0xff33957c) //115
NSTUB(qsort                                   ,0xff3ae9d4) //  6
NSTUB(rand                                    ,0xff295d9c) //  6
//NSTUB(read                                  ,0xff00ad74) //101
NSTUB(reboot_fw_update                        ,0xff33ee24) //106
NSTUB(set_control_event                       ,0xff097a94) //111
NSTUB(srand                                   ,0xff295d90) //  6
NSTUB(stat                                    ,0xff027848) //109
NSTUB(strcat                                  ,0xff0b3378) //  1
NSTUB(strchr                                  ,0xff0040d8) //  1
NSTUB(strcmp                                  ,0xff010a04) //101
NSTUB(strcpy                                  ,0xff0109ec) //101
NSTUB(strftime                                ,0xff0b35c0) //113
NSTUB(strlen                                  ,0xff004124) //101
NSTUB(strncmp                                 ,0xff00408c) //  1
NSTUB(strncpy                                 ,0xff004050) //  1
NSTUB(strrchr                                 ,0xff0040fc) //  1
NSTUB(strtol                                  ,0xff03199c) //101
NSTUB(strtolx                                 ,0xff0317a0) //109
  DEF(task_CaptSeq                            ,0xff07c46c) //110
  DEF(task_ExpDrv                             ,0xff0cc430) //110
  DEF(task_InitFileModules                    ,0xff09bbb0) //110
  DEF(task_MovieRecord                        ,0xff07854c) //110
  DEF(task_PhySw                              ,0xff024964) //110
  DEF(task_RotaryEncoder                      ,0xff057f64) //110
NSTUB(time                                    ,0xff08afa4) //109
NSTUB(vsprintf                                ,0xff0109ac) //115
//NSTUB(write                                 ,0xff027638) //101
//NSTUB(GetSDProtect                          ,0xff024d90) //101
//NSTUB(StartRecModeMenu                      ,0xff091b68) //102
//NSTUB(DispCon_ShowBitmapColorBar            ,0xff051598) //102
//NSTUB(ResetZoomLens                         ,0xff355828) //102
//NSTUB(ResetFocusLens                        ,0xff354404) //102
//NSTUB(NR_GetDarkSubType                     ,0xff29e45c) //102
//NSTUB(NR_SetDarkSubType                     ,0xff29e394) //102
//NSTUB(SavePaletteData                       ,0xff1d23b0) //102
//NSTUB(GUISrv_StartGUISystem                 ,0xff0b123c) //101
