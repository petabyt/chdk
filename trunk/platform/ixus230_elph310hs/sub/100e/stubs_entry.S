// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R49 (DRYOS version 2.3, release #0049)
//   Firmware Ver GM1.00E
//   Canon IXUS 230 HS

// Values for makefile.inc
//   PLATFORMOSVER = 49
//   PLATFORMID = 12855 (0x3237) // Found @ 0xfff40040
//   MAXRAMADDR = 0x07ffffff
//   MEMISOSTART = 0x00181a9c
//   KEYSYS = d4c                // Found @ 0xffff360c
//   NEED_ENCODED_DISKBOOT = 7   // Found @ 0xffff361c

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
NHSTUB(kbd_pwr_off                            ,0xff057fc8) //  2 60%
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff0931a8 -> ff08fab8 -> ff1b3bd0 -> ff301264 -> ff457cb8
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00034108) // Found @0xff025814
DEF(physw_run                               ,0x00001c4c) // Found @0xff0253ac
DEF(physw_sleep_delay                       ,0x00001c54) // Found @0xff0253ac
DEF(levent_table                            ,0xff3f7e40) // Found @0xff3f7e40
DEF(FlashParamsTable                        ,0xff457f10) // Found @0xff457f10
DEF(movie_status                            ,0x00006d04) // Found @0xff184760
DEF(video_compression_rate                  ,0x00006d44) // Found @0xff185fb0
DEF(full_screen_refresh                     ,0x00009a2c) // Found @0xff22fce0
DEF(canon_menu_active                       ,0x00003284) // Found @0xff08ae14
DEF(canon_shoot_menu_active                 ,0x000083bd) // Found @0xff1d0b64
DEF(playrec_mode                            ,0x00002fb0) // Found @0xff07cb48
DEF(zoom_status                             ,0x0000dacc) // Found @0xff304b78
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 2 int value(s), the first is the zoom focus length.
// there are 127 entries in the table - set NUM_FL to 127
DEF(focus_len_table                         ,0xfff4abc8) // Found @0xfff4abc8
DEF(zoom_busy                               ,0x00006ba0) // Found @0xff17f438
DEF(focus_busy                              ,0x00006a40) // Found @0xff17aa94
DEF(recreview_hold                          ,0x000038ec) // Found @0xff09a5d4
// Palette colour tables  found @ 0xff4111f4
DEF(palette_control                         ,0x00009a2c) // Found @0xff22fc5c
DEF(active_palette_buffer                   ,0x00009a34) // Found @0xff22fc60
DEF(palette_buffer_ptr                      ,0x00009a38) // Found @0xff230118
DEF(palette_buffer                          ,0x000b9c80) // Found @0xff230128
// Offset from start of palette_buffer to color data = 4 (Found @0xff34224c)
DEF(bitmap_buffer                           ,0x00009a70) // Found @0xff23396c
DEF(active_bitmap_buffer                    ,0x00009a68) // Found @0xff233970
//DEF(viewport_buffers                        ,0xff3a6fb4) // Found @0xff044548,          stubs_min = 0xff3a6fb4 (0xFF3A6FB4)
//DEF(active_viewport_buffer                  ,0x00002158) // Found @0xff044208,          stubs_min = 0x00002158 (0x2158)
// Camera has 2 RAW buffers @ 0x413391a0 & 0x46000000
//  Note: active buffer --> raw_buffers[active_raw_buffer]
//        other buffer  --> raw_buffers[active_raw_buffer^1]
DEF(raw_buffers                             ,0xff3b9bb4) // Found @0xff3b9bb4
DEF(active_raw_buffer                       ,0x00002f04) // Found @0xff078dcc

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x40471000; }             // Found @0xff053204
//void *vid_get_viewport_fb()      { return (void*)0x405c6b80; }             // Found @0xff365694
DEF(viewport_fb_d                           ,0x00002cb0) // Found 0x2c58 (@0xff06c234) + 0x58 (@0xff06c26c)
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x2c58+0x58)); } // Found @0xff06c234 & 0xff06c26c
DEF(jpeg_count_str                          ,0x000b9574) // Found @0xff2263bc
//char *camera_jpeg_count_str()    { return (char*)0x000b9574; }             // Found @0xff2263bc
//long hook_raw_size()             { return 0x0123eaf0; }                    // Found @0xff3684dc
//int get_flash_params_count(void) { return 0x9f; }                          // Found @0xff1b4c80

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xff3a8090, levent 0x20a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x04000000 // Found @0xff3a80b0, levent 0x202
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 2, KEY_MENU            ,0x00000001 }, // Found @0xff3a8010, levent 0x09
//    { 2, KEY_SET             ,0x00000002 }, // Found @0xff3a8018, levent 0x08
//    { 2, KEY_ZOOM_IN         ,0x00000004 }, // Found @0xff3a8020, levent 0x02
//    { 2, KEY_ZOOM_OUT        ,0x00000008 }, // Found @0xff3a8028, levent 0x03
//    { 2, KEY_LEFT            ,0x00000010 }, // Found @0xff3a8030, levent 0x06
//    { 2, KEY_RIGHT           ,0x00000020 }, // Found @0xff3a8038, levent 0x07
//    { 2, KEY_DOWN            ,0x00000040 }, // Found @0xff3a8040, levent 0x05
//    { 2, KEY_UP              ,0x00000080 }, // Found @0xff3a8048, levent 0x04
//    { 2, KEY_SHOOT_FULL      ,0x00000300 }, // Found @0xff3a8058, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000200 }, // Found @0xff3a8058, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00000100 }, // Found @0xff3a8050, levent 0x00
//    { 2, KEY_PLAYBACK        ,0x00000400 }, // Found @0xff3a8060, levent 0x101
//    { 2, KEY_POWER           ,0x00000800 }, // Found @0xff3a8068, levent 0x100
//    { 2, KEY_VIDEO           ,0x00004000 }, // Found @0xff3a8078, levent 0x19
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
DEF(ctypes, 0xff3a6852)

// For capt_seq.c
DEF(_nrflag,0x9b44) // Found @ ff23c3b0 (0x9b44) & ff23c3ec (+0x00)
//static long *nrflag = (long*)(0x9b44+0x00);  // Found @ ff23c3b0 & ff23c3ec
//#define NR_AUTO (0)                          // have to explictly reset value back to 0 to enable auto

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
//NHSTUB(CreateJumptable                      ,0xff3686a8) //  1
// ALT: NHSTUB(CreateJumptable, 0xff36a914) // 1 32/0
//NHSTUB(_uartr_req                           ,0xff00fef0) //111
//NHSTUB(StartRecModeMenu                     ,0xff08ae10) //102
//NHSTUB(AllocateMemory                       ,0xff2efd74) //101
NHSTUB(AllocateUncacheableMemory              ,0xff02be08) //112
NHSTUB(Close                                  ,0xff028024) //101
//NHSTUB(CreateBinarySemaphore                ,0xff02b5c4) //115
//NHSTUB(CreateCountingSemaphore              ,0xff02b62c) //105
NHSTUB(CreateTask                             ,0xff00eae4) //101
NHSTUB(DebugAssert                            ,0xff00edbc) //111
NHSTUB(DeleteDirectory_Fut                    ,0xff027a20) //116
NHSTUB(DeleteFile_Fut                         ,0xff02793c) //112
//NHSTUB(DeleteSemaphore                      ,0xff02b684) //105
NHSTUB(DoAFLock                               ,0xff0298cc) //102
NHSTUB(EnterToCompensationEVF                 ,0xff029b2c) //104
NHSTUB(ExecuteEventProcedure                  ,0xff0862bc) //104
NHSTUB(ExitFromCompensationEVF                ,0xff029b70) //104
NHSTUB(ExitTask                               ,0xff00ed74) //101
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff037a8c) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff037b6c) //104
NHSTUB(Fclose_Fut                             ,0xff027ab8) //101
NHSTUB(Feof_Fut                               ,0xff027ca4) //  1
NHSTUB(Fflush_Fut                             ,0xff027ce0) //  1
NHSTUB(Fgets_Fut                              ,0xff027c0c) //  6
NHSTUB(Fopen_Fut                              ,0xff027a78) //101
NHSTUB(Fread_Fut                              ,0xff027b64) //101
//NHSTUB(FreeMemory                           ,0xff2efd6c) //101
NHSTUB(FreeUncacheableMemory                  ,0xff02be48) //112
NHSTUB(Fseek_Fut                              ,0xff027c58) //101
NHSTUB(Fwrite_Fut                             ,0xff027bb8) //101
NHSTUB(GetBatteryTemperature                  ,0xff05b944) //102
NHSTUB(GetCCDTemperature                      ,0xff05b8d0) //102
NHSTUB(GetCurrentAvValue                      ,0xff17c8dc) //102
NHSTUB(GetDrive_ClusterSize                   ,0xff069cb0) //  6
NHSTUB(GetDrive_FreeClusters                  ,0xff069d08) //  6
NHSTUB(GetDrive_TotalClusters                 ,0xff069ce0) //  6
NHSTUB(GetFocusLensSubjectDistance            ,0xff17b810) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff17bc60) //  3
NHSTUB(GetImageFolder                         ,0xff156c74) //  6
NHSTUB(GetKbdState                            ,0xff057fb0) //109
NHSTUB(GetMemInfo                             ,0xff00a2ac) //115
NHSTUB(GetOpticalTemperature                  ,0xff05b9b8) //102
NHSTUB(GetParameterData                       ,0xff1b4c40) //101
NHSTUB(GetPropertyCase                        ,0xff08a35c) //102
NHSTUB(GetSystemTime                          ,0xff2efdcc) //101
NHSTUB(GetVRAMHPixelsSize                     ,0xff046c94) //102
NHSTUB(GetVRAMVPixelsSize                     ,0xff046ca0) //102
NHSTUB(GetZoomLensCurrentPoint                ,0xff17f8b0) //102
NHSTUB(GetZoomLensCurrentPosition             ,0xff2dbd18) //102
NHSTUB(GiveSemaphore                          ,0xff02b800) //112
NHSTUB(IsStrobeChargeCompleted                ,0xff0de288) //102
NHSTUB(LEDDrive                               ,0xff057508) //101
NHSTUB(LocalTime                              ,0xff083b54) //115
NHSTUB(LockMainPower                          ,0xff08f6b0) //103
//NHSTUB(Lseek                                ,0xff028240) //101
NHSTUB(MakeDirectory_Fut                      ,0xff0279b0) //116
NHSTUB(MakeSDCardBootable                     ,0xff069f40) //105
NHSTUB(MoveFocusLensToDistance                ,0xff3618d4) //102
NHSTUB(MoveIrisWithAv                         ,0xff2ec0d8) //102
NHSTUB(MoveZoomLensWithPoint                  ,0xff2ec80c) //102
//NHSTUB(NewTaskShell                         ,0xff089cdc) //101
NHSTUB(Open                                   ,0xff027f5c) //101
NHSTUB(PB2Rec                                 ,0xff0927cc) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff073c5c) //102
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff073c34) //102
NHSTUB(PT_PlaySound                           ,0xff07e868) //  6
NHSTUB(PostLogicalEventForNotPowerType        ,0xff08eda4) //103
NHSTUB(PostLogicalEventToUI                   ,0xff08edf0) //103
NHSTUB(PutInNdFilter                          ,0xff2ec5e4) //102
NHSTUB(PutOutNdFilter                         ,0xff2ec608) //102
NHSTUB(Read                                   ,0xff00ad68) //101
NHSTUB(ReadFastDir                            ,0xff2c99f8) //115
NHSTUB(Rec2PB                                 ,0xff09280c) //104
NHSTUB(RefreshPhysicalScreen                  ,0xff0a6da4) //104
//NHSTUB(Remove                               ,0xff028198) //  6
NHSTUB(RenameFile_Fut                         ,0xff0278a8) //116
NHSTUB(Restart                                ,0xff02d620) //106
NHSTUB(ScreenLock                             ,0xff0a7f9c) //117
NHSTUB(ScreenUnlock                           ,0xff0a8000) //117
NHSTUB(SetAE_ShutterSpeed                     ,0xff36480c) //102
NHSTUB(SetAutoShutdownTime                    ,0xff08f724) //103
NHSTUB(SetCurrentCaptureModeType              ,0xff097c44) //101
NHSTUB(SetFileAttributes                      ,0xff028428) //  6
NHSTUB(SetFileTimeStamp                       ,0xff0283b0) //  6
NHSTUB(SetLogicalEventActive                  ,0xff08f42c) //101
NHSTUB(SetParameterData                       ,0xff1b4bb0) //101
NHSTUB(SetPropertyCase                        ,0xff08a1d4) //102
NHSTUB(SetScriptMode                          ,0xff08f47c) //101
NHSTUB(SleepTask                              ,0xff02baac) //101
NHSTUB(TakeSemaphore                          ,0xff02b730) //101
NHSTUB(TurnOffBackLight                       ,0xff09f01c) //104
NHSTUB(TurnOnBackLight                        ,0xff09f004) //104
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff1a1c40) //101
NHSTUB(UnlockAF                               ,0xff029904) //102
NHSTUB(UnlockMainPower                        ,0xff08f604) //103
NHSTUB(VbattGet                               ,0xff023148) //101
NHSTUB(Write                                  ,0xff028078) //101
NHSTUB(WriteSDCard                            ,0xff16a9b4) //108
NHSTUB(_log                                   ,0xff3a3378) //111
NHSTUB(_log10                                 ,0xff3a38b8) //112
NHSTUB(_pow                                   ,0xff3a3a30) //114
NHSTUB(_sqrt                                  ,0xff3a5654) //  6
NHSTUB(add_ptp_handler                        ,0xff278404) //  6
NHSTUB(apex2us                                ,0xff236124) //  4
NHSTUB(close                                  ,0xff00abc4) //  6
NHSTUB(closedir                               ,0xff2c9854) //  4
NHSTUB(err_init_task                          ,0xff006020) //111
NHSTUB(exmem_alloc                            ,0xff084b14) //101
NHSTUB(exmem_free                             ,0xff084b8c) //101
NHSTUB(free                                   ,0xff004258) //112
NHSTUB(kbd_p1_f                               ,0xff025864) //109
NHSTUB(kbd_p1_f_cont                          ,0xff025870) //109
NHSTUB(kbd_p2_f                               ,0xff025044) //109
NHSTUB(kbd_read_keys                          ,0xff025814) //109
NHSTUB(kbd_read_keys_r2                       ,0xff0579c8) //109
NHSTUB(lseek                                  ,0xff028240) //101
NHSTUB(malloc                                 ,0xff004200) //112
NHSTUB(memcmp                                 ,0xff010a14) //101
NHSTUB(memcpy                                 ,0xff03152c) //101
NHSTUB(memset                                 ,0xff23415c) //101
NHSTUB(mkdir                                  ,0xff0284c0) //109
NHSTUB(mktime_ext                             ,0xff0a8df0) //  1
NHSTUB(open                                   ,0xff00ab14) //  6
NHSTUB(OpenFastDir                            ,0xff2c98a4) //115
NHSTUB(qsort                                  ,0xff342dfc) //  6
NHSTUB(rand                                   ,0xff234298) //  6
//NHSTUB(read                                 ,0xff00ad68) //101
NHSTUB(realloc                                ,0xff2341d8) //115
NHSTUB(reboot_fw_update                       ,0xff2cef38) //106
NHSTUB(set_control_event                      ,0xff08f0ec) //111
NHSTUB(srand                                  ,0xff23428c) //  6
NHSTUB(stat                                   ,0xff028288) //109
NHSTUB(strcat                                 ,0xff0a85a8) //  1
NHSTUB(strchr                                 ,0xff0040cc) //  1
NHSTUB(strcmp                                 ,0xff0109d0) //101
NHSTUB(strcpy                                 ,0xff0109b8) //101
NHSTUB(strftime                               ,0xff0a87f0) //113
NHSTUB(strlen                                 ,0xff004118) //101
NHSTUB(strncmp                                ,0xff004080) //  1
NHSTUB(strncpy                                ,0xff004044) //  1
NHSTUB(strrchr                                ,0xff0040f0) //  1
NHSTUB(strtol                                 ,0xff03182c) //101
NHSTUB(strtolx                                ,0xff031630) //109
   DEF(task_CaptSeq                           ,0xff0769f8) //110
   DEF(task_ExpDrv                            ,0xff0c0e24) //110
   DEF(task_InitFileModules                   ,0xff09301c) //110
   DEF(task_MovieRecord                       ,0xff18676c) //110
   DEF(task_PhySw                             ,0xff0253a8) //110
NHSTUB(time                                   ,0xff084130) //109
NHSTUB(vsprintf                               ,0xff010978) //115
//NHSTUB(write                                ,0xff028078) //101
//NHSTUB(EngDrvIn                             ,0xff02668c) //102
//NHSTUB(EngDrvOut                            ,0xff026674) //102
//NHSTUB(EngDrvRead                           ,0xff026694) //102
//NHSTUB(EngDrvBits                           ,0xff0266a8) //102
//NHSTUB(GetSDProtect                         ,0xff0257d4) //101
//NHSTUB(DispCon_ShowBitmapColorBar           ,0xff0531c0) //102
//NHSTUB(ResetZoomLens                        ,0xff2ec760) //102
//NHSTUB(ResetFocusLens                       ,0xff2eb2e0) //102
//NHSTUB(NR_GetDarkSubType                    ,0xff23c470) //102
//NHSTUB(NR_SetDarkSubType                    ,0xff23c3a8) //102
//NHSTUB(SavePaletteData                      ,0xff18a060) //102
//NHSTUB(GUISrv_StartGUISystem                ,0xff0a65bc) //101
