// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R49 (DRYOS version 2.3, release #0049)
//   Firmware Ver GM1.00I
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
// Firmware modemap table found @ff09bd3c -> ff0985bc -> ff2047e4 -> ff36a90c -> ff607d34
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00037548) // Found @0xff024dd8
DEF(physw_run                               ,0x00001c10) // Found @0xff024968
DEF(physw_sleep_delay                       ,0x00001c18) // Found @0xff024968
DEF(levent_table                            ,0xff593a2c) // Found @0xff593a2c
DEF(FlashParamsTable                        ,0xff607f94) // Found @0xff607f94
DEF(movie_status                            ,0x00002f1c) // Found @0xff0772a8
DEF(full_screen_refresh                     ,0x0000c2d8) // Found @0xff291804
DEF(canon_menu_active                       ,0x000034f0) // Found @0xff091b6c
DEF(canon_shoot_menu_active                 ,0x0000ab6d) // Found @0xff22a728
DEF(playrec_mode                            ,0x00003214) // Found @0xff083504
DEF(zoom_status                             ,0x000111f8) // Found @0xff36e6fc
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 1 int value, which is the the zoom focus length.
// there are 201 entries in the table - set NUM_FL to 201
DEF(focus_len_table                         ,0xfff4a7b4) // Found @0xfff4a7b4
DEF(zoom_busy                               ,0x00002e2c) // Found @0xff071c6c
DEF(focus_busy                              ,0x00008d08) // Found @0xff1bbea4
DEF(recreview_hold                          ,0x000041e4) // Found @0xff0a443c
DEF(palette_control                         ,0x0000c2d8) // Found @0xff291780
DEF(active_palette_buffer                   ,0x0000c2e0) // Found @0xff291784
DEF(palette_buffer                          ,0x000df7f0) // Found @0xff291c4c
DEF(bitmap_buffer                           ,0x0000c31c) // Found @0xff295490
DEF(active_bitmap_buffer                    ,0x0000c314) // Found @0xff295494
DEF(viewport_buffers                        ,0xff43459c) // Found @0xff045ba8
DEF(active_viewport_buffer                  ,0x0000215c) // Found @0xff045820

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x40685000; }             // Found @0xff0515dc
//void *vid_get_viewport_fb()      { return (void*)0x407dab80; }             // Found @0xff3e0b5c
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x2ca0+0x58)); } // Found @0xff06bfac & 0xff06bfe4
//char *camera_jpeg_count_str()    { return (char*)0x000df0e8; }             // Found @0xff28545c
//long hook_raw_size()             { return 0x01247a60; }                    // Found @0xff3e3960
//int get_flash_params_count(void) { return 0x9f; }                          // Found @0xff205dd8

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00000002 // Found @0xff434b8c, levent 0x20a
//#define SD_READONLY_IDX     1
//#define USB_MASK            0x40000000 // Found @0xff434c04, levent 0x202
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_UP              ,0x00000400 }, // Found @0xff434b0c, levent 0x04
//    { 0, KEY_DOWN            ,0x00000800 }, // Found @0xff434b14, levent 0x05
//    { 0, KEY_LEFT            ,0x00001000 }, // Found @0xff434b1c, levent 0x06
//    { 0, KEY_RIGHT           ,0x00002000 }, // Found @0xff434b24, levent 0x07
//    { 0, KEY_SET             ,0x00004000 }, // Found @0xff434b2c, levent 0x08
//    { 0, KEY_VIDEO           ,0x00008000 }, // Found @0xff434b34, levent 0x19
//    { 0, KEY_DISPLAY         ,0x00020000 }, // Found @0xff434b44, levent 0x0a
//    { 0, KEY_MENU            ,0x00040000 }, // Found @0xff434b4c, levent 0x09
//    { 2, KEY_POWER           ,0x00000800 }, // Found @0xff434bac, levent 0x100
//    { 2, KEY_PLAYBACK        ,0x00001000 }, // Found @0xff434bb4, levent 0x101
//    { 2, KEY_SHOOT_FULL      ,0x0000c000 }, // Found @0xff434bcc, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00008000 }, // Found @0xff434bcc, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00004000 }, // Found @0xff434bc4, levent 0x00
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#define CAM_RAW_ROWPIX    4176 // Found @0xff18e070
//#define CAM_RAW_ROWS      3060 // Found @0xff18e07c
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff02bea8

// Misc stuff
DEF(ctypes, 0xff43383a)

// For capt_seq.c
DEF(_nrflag,0xc3f8) // Found @ ff29e3bc (0xc3f8) & ff29e3f8 (+0x00)
//static long *nrflag = (long*)(0xc3f8+0x00);  // Found @ ff29e3bc & ff29e3f8
//#define NR_AUTO (0)                          // have to explictly reset value back to 0 to enable auto

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
//NHSTUB(CreateJumptable                      ,0xff3e3b28) //  1
// ALT: NHSTUB(CreateJumptable, 0xff3e5fd4) // 1 32/0
//NHSTUB(_uartr_req                           ,0xff00ff24) //111
//NHSTUB(AllocateMemory                       ,0xff359788) //101
NHSTUB(AllocateUncacheableMemory              ,0xff02be60) //112
NHSTUB(Close                                  ,0xff0275e4) //101
NHSTUB(CreateTask                             ,0xff00eaf0) //101
NHSTUB(DebugAssert                            ,0xff00edc8) //111
NHSTUB(DeleteDirectory_Fut                    ,0xff026fe0) //116
NHSTUB(DeleteFile_Fut                         ,0xff026efc) //112
NHSTUB(DoAFLock                               ,0xff029330) //102
NHSTUB(EnterToCompensationEVF                 ,0xff029704) //104
NHSTUB(ExecuteEventProcedure                  ,0xff08d004) //104
NHSTUB(ExitFromCompensationEVF                ,0xff029748) //104
NHSTUB(ExitTask                               ,0xff00ed80) //101
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff037bf0) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff037cd0) //104
NHSTUB(Fclose_Fut                             ,0xff027078) //101
NHSTUB(Feof_Fut                               ,0xff027264) //  1
NHSTUB(Fflush_Fut                             ,0xff0272a0) //  1
NHSTUB(Fgets_Fut                              ,0xff0271cc) //  6
NHSTUB(Fopen_Fut                              ,0xff027038) //101
NHSTUB(Fread_Fut                              ,0xff027124) //101
//NHSTUB(FreeMemory                           ,0xff359780) //101
NHSTUB(FreeUncacheableMemory                  ,0xff02bea0) //112
NHSTUB(Fseek_Fut                              ,0xff027218) //101
NHSTUB(Fwrite_Fut                             ,0xff027178) //101
NHSTUB(GetBatteryTemperature                  ,0xff05bbe8) //102
NHSTUB(GetCCDTemperature                      ,0xff05bb74) //102
NHSTUB(GetCurrentAvValue                      ,0xff1bebe0) //102
NHSTUB(GetDrive_ClusterSize                   ,0xff06a60c) //  6
NHSTUB(GetDrive_FreeClusters                  ,0xff06a664) //  6
NHSTUB(GetDrive_TotalClusters                 ,0xff06a63c) //  6
NHSTUB(GetFocusLensSubjectDistance            ,0xff1bca9c) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff1bce08) //  3
NHSTUB(GetImageFolder                         ,0xff197680) //  6
NHSTUB(GetKbdState                            ,0xff057c04) //109
NHSTUB(GetMemInfo                             ,0xff00a2b8) //115
NHSTUB(GetOpticalTemperature                  ,0xff05bc5c) //102
NHSTUB(GetParameterData                       ,0xff205d98) //101
NHSTUB(GetPropertyCase                        ,0xff0910a4) //102
NHSTUB(GetSystemTime                          ,0xff3597e0) //101
NHSTUB(GetVRAMHPixelsSize                     ,0xff0487f0) //102
NHSTUB(GetVRAMVPixelsSize                     ,0xff0487fc) //102
NHSTUB(GetZoomLensCurrentPoint                ,0xff071ffc) //102
NHSTUB(GetZoomLensCurrentPosition             ,0xff1c4fd8) //102
NHSTUB(GiveSemaphore                          ,0xff02b5e0) //112
NHSTUB(IsStrobeChargeCompleted                ,0xff0efe04) //102
NHSTUB(LEDDrive                               ,0xff056e58) //101
NHSTUB(LocalTime                              ,0xff08a9c8) //115
NHSTUB(LockMainPower                          ,0xff0981b4) //103
//NHSTUB(Lseek                                ,0xff027800) //101
NHSTUB(MakeDirectory_Fut                      ,0xff026f70) //116
NHSTUB(MakeSDCardBootable                     ,0xff06a89c) //105
NHSTUB(MoveFocusLensToDistance                ,0xff3dc690) //102
NHSTUB(MoveIrisWithAv                         ,0xff355098) //102
NHSTUB(MoveZoomLensWithPoint                  ,0xff3558f4) //102
//NHSTUB(NewTaskShell                         ,0xff090a24) //101
NHSTUB(Open                                   ,0xff02751c) //101
NHSTUB(PB2Rec                                 ,0xff09b3ac) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff0790a8) //102
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff079080) //102
NHSTUB(PT_PlaySound                           ,0xff085438) //  6
NHSTUB(PostLogicalEventForNotPowerType        ,0xff095b98) //103
NHSTUB(PostLogicalEventToUI                   ,0xff095be4) //103
NHSTUB(PutInNdFilter                          ,0xff3da174) //102
NHSTUB(PutOutNdFilter                         ,0xff3da1ac) //102
NHSTUB(Read                                   ,0xff00ad74) //101
NHSTUB(ReadFastDir                            ,0xff3396f0) //115
NHSTUB(Rec2PB                                 ,0xff099b1c) //104
NHSTUB(RefreshPhysicalScreen                  ,0xff0b1a24) //104
//NHSTUB(Remove                               ,0xff027758) //  6
NHSTUB(RenameFile_Fut                         ,0xff026e68) //116
NHSTUB(Restart                                ,0xff02d6a0) //106
NHSTUB(ScreenLock                             ,0xff0b2c50) //  4
NHSTUB(ScreenUnlock                           ,0xff0b2cb4) //  3
NHSTUB(SetAE_ShutterSpeed                     ,0xff3dfcd4) //102
NHSTUB(SetAutoShutdownTime                    ,0xff098228) //103
NHSTUB(SetCurrentCaptureModeType              ,0xff0a1650) //101
NHSTUB(SetFileAttributes                      ,0xff0279e8) //  6
NHSTUB(SetFileTimeStamp                       ,0xff027970) //  6
NHSTUB(SetLogicalEventActive                  ,0xff097ef0) //101
NHSTUB(SetParameterData                       ,0xff205c74) //101
NHSTUB(SetPropertyCase                        ,0xff090f1c) //102
NHSTUB(SetScriptMode                          ,0xff097f8c) //101
NHSTUB(SleepTask                              ,0xff02b88c) //101
NHSTUB(TakeSemaphore                          ,0xff02b510) //101
NHSTUB(TurnOffBackLight                       ,0xff0a96b0) //104
NHSTUB(TurnOnBackLight                        ,0xff0a9698) //104
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff1f15d8) //101
NHSTUB(UnlockAF                               ,0xff029368) //102
NHSTUB(UnlockMainPower                        ,0xff098108) //103
NHSTUB(VbattGet                               ,0xff022364) //101
NHSTUB(Write                                  ,0xff027638) //101
NHSTUB(WriteSDCard                            ,0xff1ab490) //108
NHSTUB(_log                                   ,0xff430360) //111
NHSTUB(_log10                                 ,0xff4308a0) //112
NHSTUB(_pow                                   ,0xff430a18) //114
NHSTUB(_sqrt                                  ,0xff43263c) //  6
NHSTUB(add_ptp_handler                        ,0xff2e0014) //  6
NHSTUB(apex2us                                ,0xff297c48) //  4
NHSTUB(close                                  ,0xff00abd0) //  6
NHSTUB(closedir                               ,0xff33954c) //  4
NHSTUB(err_init_task                          ,0xff00602c) //111
NHSTUB(exmem_alloc                            ,0xff08b988) //101
NHSTUB(exmem_free                             ,0xff08ba00) //101
NHSTUB(free                                   ,0xff004264) //112
NHSTUB(kbd_p1_f                               ,0xff024e28) //109
NHSTUB(kbd_p1_f_cont                          ,0xff024e34) //109
NHSTUB(kbd_p2_f                               ,0xff024600) //109
NHSTUB(kbd_read_keys                          ,0xff024dd8) //109
NHSTUB(kbd_read_keys_r2                       ,0xff05730c) //109
NHSTUB(lseek                                  ,0xff027800) //101
NHSTUB(malloc                                 ,0xff00420c) //112
NHSTUB(memcmp                                 ,0xff010a48) //101
NHSTUB(memcpy                                 ,0xff03169c) //101
NHSTUB(memset                                 ,0xff295c80) //101
NHSTUB(mkdir                                  ,0xff027a80) //109
NHSTUB(mktime_ext                             ,0xff0b3bc0) //  1
NHSTUB(open                                   ,0xff00ab20) //  6
NHSTUB(OpenFastDir                            ,0xff33959c) //115
NHSTUB(qsort                                  ,0xff3ae9f4) //  6
NHSTUB(rand                                   ,0xff295dbc) //  6
//NHSTUB(read                                 ,0xff00ad74) //101
NHSTUB(realloc                                ,0xff295cfc) //115
NHSTUB(reboot_fw_update                       ,0xff33ee44) //106
NHSTUB(set_control_event                      ,0xff097a94) //111
NHSTUB(srand                                  ,0xff295db0) //  6
NHSTUB(stat                                   ,0xff027848) //109
NHSTUB(strcat                                 ,0xff0b3378) //  1
NHSTUB(strchr                                 ,0xff0040d8) //  1
NHSTUB(strcmp                                 ,0xff010a04) //101
NHSTUB(strcpy                                 ,0xff0109ec) //101
NHSTUB(strftime                               ,0xff0b35c0) //113
NHSTUB(strlen                                 ,0xff004124) //101
NHSTUB(strncmp                                ,0xff00408c) //  1
NHSTUB(strncpy                                ,0xff004050) //  1
NHSTUB(strrchr                                ,0xff0040fc) //  1
NHSTUB(strtol                                 ,0xff03199c) //101
NHSTUB(strtolx                                ,0xff0317a0) //109
   DEF(task_CaptSeq                           ,0xff07c46c) //110
   DEF(task_ExpDrv                            ,0xff0cc430) //110
   DEF(task_FileWrite                         ,0xff337528) //110
   DEF(task_InitFileModules                   ,0xff09bbb0) //110
   DEF(task_MovieRecord                       ,0xff07854c) //110
   DEF(task_PhySw                             ,0xff024964) //110
   DEF(task_RotaryEncoder                     ,0xff057f64) //110
NHSTUB(time                                   ,0xff08afa4) //109
NHSTUB(vsprintf                               ,0xff0109ac) //115
//NHSTUB(write                                ,0xff027638) //101
//NHSTUB(EngDrvIn                             ,0xff025c4c) //102
//NHSTUB(EngDrvOut                            ,0xff025c34) //102
//NHSTUB(EngDrvRead                           ,0xff025c54) //102
//NHSTUB(EngDrvBits                           ,0xff025c68) //102
//NHSTUB(GetSDProtect                         ,0xff024d90) //101
//NHSTUB(StartRecModeMenu                     ,0xff091b68) //102
//NHSTUB(DispCon_ShowBitmapColorBar           ,0xff051598) //102
//NHSTUB(ResetZoomLens                        ,0xff355848) //102
//NHSTUB(ResetFocusLens                       ,0xff354424) //102
//NHSTUB(NR_GetDarkSubType                    ,0xff29e47c) //102
//NHSTUB(NR_SetDarkSubType                    ,0xff29e3b4) //102
//NHSTUB(SavePaletteData                      ,0xff1d23d0) //102
//NHSTUB(GUISrv_StartGUISystem                ,0xff0b123c) //101
