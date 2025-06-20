// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R47 (DRYOS version 2.3, release #0047)
//   Firmware Ver GM1.01C
//   Canon PowerShot ELPH 300HS

// Values for makefile.inc
//   PLATFORMOSVER = 47
//   PLATFORMID = 12841 (0x3229) // Found @ 0xfffe0040
//   MAXRAMADDR = 0x07ffffff
//   KEYSYS = d4c                // Found @ 0xffff3620
//   NEED_ENCODED_DISKBOOT = 6   // Found @ 0xffff3630

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
NSTUB(kbd_pwr_off                             ,0xff865570) //  2 60%
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff89e7f8 -> ff89b194 -> ff9b139c -> ffb04210 -> ffc4ee68
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x0003418c) // Found @0xff834e18
DEF(physw_run                               ,0x00001c3c) // Found @0xff8349bc
DEF(physw_sleep_delay                       ,0x00001c44) // Found @0xff8349bc
DEF(levent_table                            ,0xffbeb230) // Found @0xffbeb230
DEF(FlashParamsTable                        ,0xffc4f0a8) // Found @0xffc4f0a8
DEF(movie_status                            ,0x00006dcc) // Found @0xff984bd0
DEF(full_screen_refresh                     ,0x00009d00) // Found @0xffa32dfc
DEF(canon_menu_active                       ,0x00003210) // Found @0xff896910
DEF(canon_shoot_menu_active                 ,0x000083d9) // Found @0xff9c8c1c
DEF(playrec_mode                            ,0x00002f38) // Found @0xff888774
DEF(zoom_status                             ,0x0000ded8) // Found @0xffb078cc
DEF(some_flag_for_af_scan                   ,0x000071cc) // Found @0xff989240
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 3 int value(s), the first is the zoom focus length.
// there are 64 entries in the table - set NUM_FL to 64
DEF(focus_len_table                         ,0xfffea288) // Found @0xfffea288
DEF(zoom_busy                               ,0x00006cf4) // Found @0xff97fd74
DEF(focus_busy                              ,0x00006b68) // Found @0xff97af60
DEF(recreview_hold                          ,0x00003828) // Found @0xff8a6510
DEF(palette_control                         ,0x00009d00) // Found @0xffa32d78
DEF(active_palette_buffer                   ,0x00009d08) // Found @0xffa32d7c
DEF(palette_buffer                          ,0x000bb254) // Found @0xffa33254
DEF(bitmap_buffer                           ,0x00009d40) // Found @0xffa36ca0
DEF(active_bitmap_buffer                    ,0x00009d38) // Found @0xffa36ca4
DEF(viewport_buffers                        ,0xffba1bec) // Found @0xff853d4c
DEF(active_viewport_buffer                  ,0x00002168) // Found @0xff853a20

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x40471000; }             // Found @0xff85fd1c
//void *vid_get_viewport_fb()      { return (void*)0x405c6b80; }             // Found @0xffb5e148
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x2c08+0x58)); } // Found @0xff878880 & 0xff8788b8
//char *camera_jpeg_count_str()    { return (char*)0x000babac; }             // Found @0xffa2a298
//long hook_raw_size()             { return 0x0123eaf0; }                    // Found @0xffb61640
//int get_flash_params_count(void) { return 0xa0; }                          // Found @0xff9b23d4

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffba2be0, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x04000000 // Found @0xffba2c00, levent 0x902
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 2, KEY_MENU            ,0x00000001 }, // Found @0xffba2b60, levent 0x09
//    { 2, KEY_SET             ,0x00000002 }, // Found @0xffba2b68, levent 0x08
//    { 2, KEY_ZOOM_IN         ,0x00000004 }, // Found @0xffba2b70, levent 0x02
//    { 2, KEY_ZOOM_OUT        ,0x00000008 }, // Found @0xffba2b78, levent 0x03
//    { 2, KEY_LEFT            ,0x00000010 }, // Found @0xffba2b80, levent 0x06
//    { 2, KEY_RIGHT           ,0x00000020 }, // Found @0xffba2b88, levent 0x07
//    { 2, KEY_DOWN            ,0x00000040 }, // Found @0xffba2b90, levent 0x05
//    { 2, KEY_UP              ,0x00000080 }, // Found @0xffba2b98, levent 0x04
//    { 2, KEY_SHOOT_FULL      ,0x00000300 }, // Found @0xffba2ba8, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000200 }, // Found @0xffba2ba8, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00000100 }, // Found @0xffba2ba0, levent 0x00
//    { 2, KEY_POWER           ,0x00000400 }, // Found @0xffba2bb0, levent 0x600
//    { 2, KEY_PLAYBACK        ,0x00000800 }, // Found @0xffba2bb8, levent 0x601
//    { 2, KEY_VIDEO           ,0x00004000 }, // Found @0xffba2bc8, levent 0x12
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#define CAM_RAW_ROWPIX    4168 // Found @0xff952bb4
//#define CAM_RAW_ROWS      3060 // Found @0xff952bc0
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff83c0f0

// Misc stuff
DEF(ctypes, 0xffba0112)

// For capt_seq.c
//static long *nrflag = (long*)(0x7200+0x08);  // Found @ ff98db88 & ff98dbc4
//#define NR_AUTO (0)                          // have to explictly reset value back to 0 to enable auto

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
//NSTUB(CreateJumptable                       ,0xffb6180c) //  1
//NSTUB(_uartr_req                            ,0xff81fe10) //111
//NSTUB(AllocateMemory                        ,0xffaf2508) //101
NSTUB(AllocateUncacheableMemory               ,0xff83c0a8) //112
NSTUB(Close                                   ,0xff8383e8) //101
NSTUB(CreateTask                              ,0xff81e9b0) //101
NSTUB(DebugAssert                             ,0xff81ec88) //111
NSTUB(DeleteDirectory_Fut                     ,0xff837de4) //116
NSTUB(DeleteFile_Fut                          ,0xff837d00) //112
NSTUB(DoAFLock                                ,0xff839c28) //102
NSTUB(EnterToCompensationEVF                  ,0xff839e84) //104
NSTUB(ExecuteEventProcedure                   ,0xff8920f8) //104
NSTUB(ExitFromCompensationEVF                 ,0xff839ec8) //104
NSTUB(ExitTask                                ,0xff81ec40) //101
NSTUB(ExpCtrlTool_StartContiAE                ,0xff848730) //104
NSTUB(ExpCtrlTool_StopContiAE                 ,0xff848808) //104
NSTUB(Fclose_Fut                              ,0xff837e7c) //101
NSTUB(Feof_Fut                                ,0xff838068) //  1
NSTUB(Fflush_Fut                              ,0xff8380a4) //  1
NSTUB(Fgets_Fut                               ,0xff837fd0) //  6
NSTUB(Fopen_Fut                               ,0xff837e3c) //101
NSTUB(Fread_Fut                               ,0xff837f28) //101
//NSTUB(FreeMemory                            ,0xffaf2500) //101
NSTUB(FreeUncacheableMemory                   ,0xff83c0e8) //112
NSTUB(Fseek_Fut                               ,0xff83801c) //101
NSTUB(Fwrite_Fut                              ,0xff837f7c) //101
NSTUB(GetBatteryTemperature                   ,0xff868d7c) //102
NSTUB(GetCCDTemperature                       ,0xff868d08) //102
NSTUB(GetCurrentAvValue                       ,0xff97cb48) //102
NSTUB(GetDrive_ClusterSize                    ,0xff87630c) //  6
NSTUB(GetDrive_FreeClusters                   ,0xff876364) //  6
NSTUB(GetDrive_TotalClusters                  ,0xff87633c) //  6
NSTUB(GetFocusLensSubjectDistance             ,0xff97bbe4) //102
NSTUB(GetFocusLensSubjectDistanceFromLens     ,0xff97c044) //  3
NSTUB(GetImageFolder                          ,0xff959b4c) //  6
NSTUB(GetKbdState                             ,0xff865558) //109
NSTUB(GetMemInfo                              ,0xff81a29c) //115
NSTUB(GetOpticalTemperature                   ,0xff868df0) //102
NSTUB(GetParameterData                        ,0xff9b2394) //101
NSTUB(GetPropertyCase                         ,0xff895e60) //102
NSTUB(GetSystemTime                           ,0xffaf2560) //101
NSTUB(GetVRAMHPixelsSize                      ,0xff856300) //102
NSTUB(GetVRAMVPixelsSize                      ,0xff85630c) //102
NSTUB(GetZoomLensCurrentPoint                 ,0xff9801ec) //102
NSTUB(GetZoomLensCurrentPosition              ,0xffadcc9c) //102
NSTUB(GiveSemaphore                           ,0xff83baa0) //112
NSTUB(IsStrobeChargeCompleted                 ,0xff8e8b94) //102
NSTUB(LEDDrive                                ,0xff864a7c) //101
NSTUB(LocalTime                               ,0xff88f988) //115
NSTUB(LockMainPower                           ,0xff89ad84) //103
//NSTUB(Lseek                                 ,0xff838604) //101
NSTUB(MakeDirectory_Fut                       ,0xff837d74) //116
NSTUB(MakeSDCardBootable                      ,0xff87659c) //105
NSTUB(MoveFocusLensToDistance                 ,0xffb5a444) //102
NSTUB(MoveIrisWithAv                          ,0xffaeecd8) //102
NSTUB(MoveZoomLensWithPoint                   ,0xffaef390) //102
//NSTUB(NewTaskShell                          ,0xff8958a8) //101
NSTUB(Open                                    ,0xff838320) //101
NSTUB(PB2Rec                                  ,0xff89dd28) //104
NSTUB(PT_MoveDigitalZoomToWide                ,0xff87fbcc) //102
NSTUB(PT_MoveOpticalZoomAt                    ,0xff87fba4) //102
NSTUB(PT_PlaySound                            ,0xff88a774) //  6
NSTUB(PostLogicalEventForNotPowerType         ,0xff89a540) //103
NSTUB(PostLogicalEventToUI                    ,0xff89a58c) //103
NSTUB(PutInNdFilter                           ,0xffaef1d8) //102
NSTUB(PutOutNdFilter                          ,0xffaef1fc) //102
NSTUB(Read                                    ,0xff81ad58) //101
NSTUB(ReadFastDir                             ,0xffaca2bc) //  6
NSTUB(Rec2PB                                  ,0xff89dd68) //104
NSTUB(RefreshPhysicalScreen                   ,0xff8b1da0) //104
//NSTUB(Remove                                ,0xff83855c) //  6
NSTUB(RenameFile_Fut                          ,0xff837c6c) //116
NSTUB(Restart                                 ,0xff83d8bc) //106
NSTUB(ScreenLock                              ,0xff8b2f98) //  4
NSTUB(ScreenUnlock                            ,0xff8b2ffc) //  3
NSTUB(SetAE_ShutterSpeed                      ,0xffb5d2c0) //102
NSTUB(SetAutoShutdownTime                     ,0xff89adf8) //103
NSTUB(SetCurrentCaptureModeType               ,0xff8a3510) //101
NSTUB(SetFileAttributes                       ,0xff8387ec) //  6
NSTUB(SetFileTimeStamp                        ,0xff838774) //  6
NSTUB(SetLogicalEventActive                   ,0xff89aaec) //101
NSTUB(SetParameterData                        ,0xff9b2304) //101
NSTUB(SetPropertyCase                         ,0xff895d44) //102
NSTUB(SetScriptMode                           ,0xff89ab3c) //101
NSTUB(SleepTask                               ,0xff83bd4c) //101
NSTUB(TakeSemaphore                           ,0xff83b9d0) //101
NSTUB(TurnOffBackLight                        ,0xff8aa31c) //104
NSTUB(TurnOnBackLight                         ,0xff8aa304) //104
NSTUB(UIFS_WriteFirmInfoToFile                ,0xff9a2184) //101
NSTUB(UnlockAF                                ,0xff839c60) //102
NSTUB(UnlockMainPower                         ,0xff89acd8) //103
NSTUB(VbattGet                                ,0xff833050) //101
NSTUB(Write                                   ,0xff83843c) //101
NSTUB(WriteSDCard                             ,0xff96b024) //108
NSTUB(_log                                    ,0xffb9cc38) //111
NSTUB(_log10                                  ,0xffb9d178) //112
NSTUB(_pow                                    ,0xffb9d2f0) //114
NSTUB(_sqrt                                   ,0xffb9ef14) //  6
NSTUB(add_ptp_handler                         ,0xffa7be20) //  6
NSTUB(apex2us                                 ,0xffa3b18c) //  4
NSTUB(close                                   ,0xff81abb4) //  6
NSTUB(closedir                                ,0xffaca118) //  4
NSTUB(err_init_task                           ,0xff815fd4) //111
NSTUB(exmem_alloc                             ,0xff890950) //101
NSTUB(free                                    ,0xff814244) //112
NSTUB(kbd_p1_f                                ,0xff834e94) //109
NSTUB(kbd_p1_f_cont                           ,0xff834ea0) //109
NSTUB(kbd_p2_f                                ,0xff83468c) //109
NSTUB(kbd_read_keys                           ,0xff834e18) //109
NSTUB(kbd_read_keys_r2                        ,0xff864f74) //109
NSTUB(lseek                                   ,0xff838604) //101
NSTUB(malloc                                  ,0xff8141ec) //112
NSTUB(memcmp                                  ,0xff820934) //101
NSTUB(memcpy                                  ,0xff84179c) //101
NSTUB(memset                                  ,0xffa3a18c) //101
NSTUB(mkdir                                   ,0xff838884) //109
NSTUB(mktime_ext                              ,0xff8b3e10) //  1
NSTUB(open                                    ,0xff81ab04) //  6
NSTUB(OpenFastDir                             ,0xffaca168) //  6
NSTUB(qsort                                   ,0xffb3d698) //  6
NSTUB(rand                                    ,0xffa3a2cc) //  6
//NSTUB(read                                  ,0xff81ad58) //101
NSTUB(reboot_fw_update                        ,0xffacf758) //106
NSTUB(set_control_event                       ,0xff89a7b0) //111
NSTUB(srand                                   ,0xffa3a2c0) //  6
NSTUB(stat                                    ,0xff83864c) //109
NSTUB(strcat                                  ,0xff8b35c8) //  1
NSTUB(strchr                                  ,0xff8140b8) //  1
NSTUB(strcmp                                  ,0xff8208f0) //101
NSTUB(strcpy                                  ,0xff8208d8) //101
NSTUB(strftime                                ,0xff8b3810) //113
NSTUB(strlen                                  ,0xff814104) //101
NSTUB(strncmp                                 ,0xff81406c) //  1
NSTUB(strncpy                                 ,0xff814030) //  1
NSTUB(strrchr                                 ,0xff8140dc) //  1
NSTUB(strtol                                  ,0xff841a9c) //101
NSTUB(strtolx                                 ,0xff8418a0) //109
  DEF(task_CaptSeq                            ,0xff882920) //110
  DEF(task_ExpDrv                             ,0xff8cbcbc) //110
  DEF(task_InitFileModules                    ,0xff89e66c) //110
  DEF(task_MovieRecord                        ,0xff985e5c) //110
  DEF(task_PhySw                              ,0xff8349b8) //110
NSTUB(time                                    ,0xff88ff64) //109
NSTUB(vsprintf                                ,0xff820898) //115
//NSTUB(write                                 ,0xff83843c) //101
//NSTUB(GetSDProtect                          ,0xff834de0) //101
//NSTUB(StartRecModeMenu                      ,0xff89690c) //102
//NSTUB(DispCon_ShowBitmapColorBar            ,0xff85fcd8) //102
//NSTUB(ResetZoomLens                         ,0xffaef2e4) //102
//NSTUB(ResetFocusLens                        ,0xffaedfac) //102
//NSTUB(NR_GetDarkSubType                     ,0xff98dc48) //102
//NSTUB(NR_SetDarkSubType                     ,0xff98db80) //102
//NSTUB(SavePaletteData                       ,0xffb5f754) //102
//NSTUB(GUISrv_StartGUISystem                 ,0xff8b15b8) //101
