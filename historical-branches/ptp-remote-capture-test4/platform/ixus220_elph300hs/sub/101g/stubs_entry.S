// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R47 (DRYOS version 2.3, release #0047)
//   Firmware Ver GM1.01G
//   Canon IXUS 220HS

// Values for makefile.inc
//   PLATFORMOSVER = 47
//   PLATFORMID = 12841 (0x3229) // Found @ 0xfffe0040
//   MAXRAMADDR = 0x07ffffff
//   KEYSYS = d4c                // Found @ 0xffff3620
//   NEED_ENCODED_DISKBOOT = 6   // Found @ 0xffff3630

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
NHSTUB(kbd_pwr_off                            ,0xff865570) //  2 60%
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff89e7f8 -> ff89b194 -> ff9b139c -> ffb04244 -> ffc4eea0
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x0003418c) // Found @0xff834e18
DEF(physw_run                               ,0x00001c3c) // Found @0xff8349bc
DEF(physw_sleep_delay                       ,0x00001c44) // Found @0xff8349bc
DEF(levent_table                            ,0xffbeb268) // Found @0xffbeb268
DEF(FlashParamsTable                        ,0xffc4f0e0) // Found @0xffc4f0e0
DEF(movie_status                            ,0x00006dcc) // Found @0xff984bd0
DEF(full_screen_refresh                     ,0x00009d00) // Found @0xffa32dfc
DEF(canon_menu_active                       ,0x00003210) // Found @0xff896910
DEF(canon_shoot_menu_active                 ,0x000083d9) // Found @0xff9c8c1c
DEF(playrec_mode                            ,0x00002f38) // Found @0xff888774
DEF(zoom_status                             ,0x0000ded8) // Found @0xffb07900
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
DEF(viewport_buffers                        ,0xffba1c24) // Found @0xff853d4c
DEF(active_viewport_buffer                  ,0x00002168) // Found @0xff853a20

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x40471000; }             // Found @0xff85fd1c
//void *vid_get_viewport_fb()      { return (void*)0x405c6b80; }             // Found @0xffb5e17c
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x2c08+0x58)); } // Found @0xff878880 & 0xff8788b8
//char *camera_jpeg_count_str()    { return (char*)0x000babac; }             // Found @0xffa2a298
//long hook_raw_size()             { return 0x0123eaf0; }                    // Found @0xffb61674
//int get_flash_params_count(void) { return 0xa0; }                          // Found @0xff9b23d4

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffba2c18, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x04000000 // Found @0xffba2c38, levent 0x902
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 2, KEY_MENU            ,0x00000001 }, // Found @0xffba2b98, levent 0x09
//    { 2, KEY_SET             ,0x00000002 }, // Found @0xffba2ba0, levent 0x08
//    { 2, KEY_ZOOM_IN         ,0x00000004 }, // Found @0xffba2ba8, levent 0x02
//    { 2, KEY_ZOOM_OUT        ,0x00000008 }, // Found @0xffba2bb0, levent 0x03
//    { 2, KEY_LEFT            ,0x00000010 }, // Found @0xffba2bb8, levent 0x06
//    { 2, KEY_RIGHT           ,0x00000020 }, // Found @0xffba2bc0, levent 0x07
//    { 2, KEY_DOWN            ,0x00000040 }, // Found @0xffba2bc8, levent 0x05
//    { 2, KEY_UP              ,0x00000080 }, // Found @0xffba2bd0, levent 0x04
//    { 2, KEY_SHOOT_FULL      ,0x00000300 }, // Found @0xffba2be0, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000200 }, // Found @0xffba2be0, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00000100 }, // Found @0xffba2bd8, levent 0x00
//    { 2, KEY_POWER           ,0x00000400 }, // Found @0xffba2be8, levent 0x600
//    { 2, KEY_PLAYBACK        ,0x00000800 }, // Found @0xffba2bf0, levent 0x601
//    { 2, KEY_VIDEO           ,0x00004000 }, // Found @0xffba2c00, levent 0x12
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
DEF(ctypes, 0xffba014a)

// For capt_seq.c
DEF(_nrflag,0x7208) // Found @ ff98db88 (0x7200) & ff98dbc4 (+0x08)
//static long *nrflag = (long*)(0x7200+0x08);  // Found @ ff98db88 & ff98dbc4
//#define NR_AUTO (0)                          // have to explictly reset value back to 0 to enable auto

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
//NHSTUB(CreateJumptable                      ,0xffb61840) //  1
//NHSTUB(_uartr_req                           ,0xff81fe10) //111
//NHSTUB(AllocateMemory                       ,0xffaf253c) //101
NHSTUB(AllocateUncacheableMemory              ,0xff83c0a8) //112
NHSTUB(Close                                  ,0xff8383e8) //101
NHSTUB(CreateTask                             ,0xff81e9b0) //101
NHSTUB(DebugAssert                            ,0xff81ec88) //111
NHSTUB(DeleteDirectory_Fut                    ,0xff837de4) //116
NHSTUB(DeleteFile_Fut                         ,0xff837d00) //112
NHSTUB(DoAFLock                               ,0xff839c28) //102
NHSTUB(EnterToCompensationEVF                 ,0xff839e84) //104
NHSTUB(ExecuteEventProcedure                  ,0xff8920f8) //104
NHSTUB(ExitFromCompensationEVF                ,0xff839ec8) //104
NHSTUB(ExitTask                               ,0xff81ec40) //101
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff848730) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff848808) //104
NHSTUB(Fclose_Fut                             ,0xff837e7c) //101
NHSTUB(Feof_Fut                               ,0xff838068) //  1
NHSTUB(Fflush_Fut                             ,0xff8380a4) //  1
NHSTUB(Fgets_Fut                              ,0xff837fd0) //  6
NHSTUB(Fopen_Fut                              ,0xff837e3c) //101
NHSTUB(Fread_Fut                              ,0xff837f28) //101
//NHSTUB(FreeMemory                           ,0xffaf2534) //101
NHSTUB(FreeUncacheableMemory                  ,0xff83c0e8) //112
NHSTUB(Fseek_Fut                              ,0xff83801c) //101
NHSTUB(Fwrite_Fut                             ,0xff837f7c) //101
NHSTUB(GetBatteryTemperature                  ,0xff868d7c) //102
NHSTUB(GetCCDTemperature                      ,0xff868d08) //102
NHSTUB(GetCurrentAvValue                      ,0xff97cb48) //102
NHSTUB(GetDrive_ClusterSize                   ,0xff87630c) //  6
NHSTUB(GetDrive_FreeClusters                  ,0xff876364) //  6
NHSTUB(GetDrive_TotalClusters                 ,0xff87633c) //  6
NHSTUB(GetFocusLensSubjectDistance            ,0xff97bbe4) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff97c044) //  3
NHSTUB(GetImageFolder                         ,0xff959b4c) //  6
NHSTUB(GetKbdState                            ,0xff865558) //109
NHSTUB(GetMemInfo                             ,0xff81a29c) //115
NHSTUB(GetOpticalTemperature                  ,0xff868df0) //102
NHSTUB(GetParameterData                       ,0xff9b2394) //101
NHSTUB(GetPropertyCase                        ,0xff895e60) //102
NHSTUB(GetSystemTime                          ,0xffaf2594) //101
NHSTUB(GetVRAMHPixelsSize                     ,0xff856300) //102
NHSTUB(GetVRAMVPixelsSize                     ,0xff85630c) //102
NHSTUB(GetZoomLensCurrentPoint                ,0xff9801ec) //102
NHSTUB(GetZoomLensCurrentPosition             ,0xffadccd0) //102
NHSTUB(GiveSemaphore                          ,0xff83baa0) //112
NHSTUB(IsStrobeChargeCompleted                ,0xff8e8b94) //102
NHSTUB(LEDDrive                               ,0xff864a7c) //101
NHSTUB(LocalTime                              ,0xff88f988) //115
NHSTUB(LockMainPower                          ,0xff89ad84) //103
//NHSTUB(Lseek                                ,0xff838604) //101
NHSTUB(MakeDirectory_Fut                      ,0xff837d74) //116
NHSTUB(MakeSDCardBootable                     ,0xff87659c) //105
NHSTUB(MoveFocusLensToDistance                ,0xffb5a478) //102
NHSTUB(MoveIrisWithAv                         ,0xffaeed0c) //102
NHSTUB(MoveZoomLensWithPoint                  ,0xffaef3c4) //102
//NHSTUB(NewTaskShell                         ,0xff8958a8) //101
NHSTUB(Open                                   ,0xff838320) //101
NHSTUB(PB2Rec                                 ,0xff89dd28) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff87fbcc) //102
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff87fba4) //102
NHSTUB(PT_PlaySound                           ,0xff88a774) //  6
NHSTUB(PostLogicalEventForNotPowerType        ,0xff89a540) //103
NHSTUB(PostLogicalEventToUI                   ,0xff89a58c) //103
NHSTUB(PutInNdFilter                          ,0xffaef20c) //102
NHSTUB(PutOutNdFilter                         ,0xffaef230) //102
NHSTUB(Read                                   ,0xff81ad58) //101
NHSTUB(ReadFastDir                            ,0xffaca2bc) //  6
NHSTUB(Rec2PB                                 ,0xff89dd68) //104
NHSTUB(RefreshPhysicalScreen                  ,0xff8b1da0) //104
//NHSTUB(Remove                               ,0xff83855c) //  6
NHSTUB(RenameFile_Fut                         ,0xff837c6c) //116
NHSTUB(Restart                                ,0xff83d8bc) //106
NHSTUB(ScreenLock                             ,0xff8b2f98) //  4
NHSTUB(ScreenUnlock                           ,0xff8b2ffc) //  3
NHSTUB(SetAE_ShutterSpeed                     ,0xffb5d2f4) //102
NHSTUB(SetAutoShutdownTime                    ,0xff89adf8) //103
NHSTUB(SetCurrentCaptureModeType              ,0xff8a3510) //101
NHSTUB(SetFileAttributes                      ,0xff8387ec) //  6
NHSTUB(SetFileTimeStamp                       ,0xff838774) //  6
NHSTUB(SetLogicalEventActive                  ,0xff89aaec) //101
NHSTUB(SetParameterData                       ,0xff9b2304) //101
NHSTUB(SetPropertyCase                        ,0xff895d44) //102
NHSTUB(SetScriptMode                          ,0xff89ab3c) //101
NHSTUB(SleepTask                              ,0xff83bd4c) //101
NHSTUB(TakeSemaphore                          ,0xff83b9d0) //101
NHSTUB(TurnOffBackLight                       ,0xff8aa31c) //104
NHSTUB(TurnOnBackLight                        ,0xff8aa304) //104
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff9a2184) //101
NHSTUB(UnlockAF                               ,0xff839c60) //102
NHSTUB(UnlockMainPower                        ,0xff89acd8) //103
NHSTUB(VbattGet                               ,0xff833050) //101
NHSTUB(Write                                  ,0xff83843c) //101
NHSTUB(WriteSDCard                            ,0xff96b024) //108
NHSTUB(_log                                   ,0xffb9cc70) //111
NHSTUB(_log10                                 ,0xffb9d1b0) //112
NHSTUB(_pow                                   ,0xffb9d328) //114
NHSTUB(_sqrt                                  ,0xffb9ef4c) //  6
NHSTUB(add_ptp_handler                        ,0xffa7be20) //  6
NHSTUB(apex2us                                ,0xffa3b18c) //  4
NHSTUB(close                                  ,0xff81abb4) //  6
NHSTUB(closedir                               ,0xffaca118) //  4
NHSTUB(err_init_task                          ,0xff815fd4) //111
NHSTUB(exmem_alloc                            ,0xff890950) //101
NHSTUB(exmem_free                             ,0xff8909c8) //101
NHSTUB(free                                   ,0xff814244) //112
NHSTUB(kbd_p1_f                               ,0xff834e94) //109
NHSTUB(kbd_p1_f_cont                          ,0xff834ea0) //109
NHSTUB(kbd_p2_f                               ,0xff83468c) //109
NHSTUB(kbd_read_keys                          ,0xff834e18) //109
NHSTUB(kbd_read_keys_r2                       ,0xff864f74) //109
NHSTUB(lseek                                  ,0xff838604) //101
NHSTUB(malloc                                 ,0xff8141ec) //112
NHSTUB(memcmp                                 ,0xff820934) //101
NHSTUB(memcpy                                 ,0xff84179c) //101
NHSTUB(memset                                 ,0xffa3a18c) //101
NHSTUB(mkdir                                  ,0xff838884) //109
NHSTUB(mktime_ext                             ,0xff8b3e10) //  1
NHSTUB(open                                   ,0xff81ab04) //  6
NHSTUB(OpenFastDir                            ,0xffaca168) //  6
NHSTUB(qsort                                  ,0xffb3d6cc) //  6
NHSTUB(rand                                   ,0xffa3a2cc) //  6
//NHSTUB(read                                 ,0xff81ad58) //101
NHSTUB(realloc                                ,0xffa3a208) //115
NHSTUB(reboot_fw_update                       ,0xffacf758) //106
NHSTUB(set_control_event                      ,0xff89a7b0) //111
NHSTUB(srand                                  ,0xffa3a2c0) //  6
NHSTUB(stat                                   ,0xff83864c) //109
NHSTUB(strcat                                 ,0xff8b35c8) //  1
NHSTUB(strchr                                 ,0xff8140b8) //  1
NHSTUB(strcmp                                 ,0xff8208f0) //101
NHSTUB(strcpy                                 ,0xff8208d8) //101
NHSTUB(strftime                               ,0xff8b3810) //113
NHSTUB(strlen                                 ,0xff814104) //101
NHSTUB(strncmp                                ,0xff81406c) //  1
NHSTUB(strncpy                                ,0xff814030) //  1
NHSTUB(strrchr                                ,0xff8140dc) //  1
NHSTUB(strtol                                 ,0xff841a9c) //101
NHSTUB(strtolx                                ,0xff8418a0) //109
   DEF(task_CaptSeq                           ,0xff882920) //110
   DEF(task_ExpDrv                            ,0xff8cbcbc) //110
   DEF(task_FileWrite                         ,0xffac816c) //110
   DEF(task_InitFileModules                   ,0xff89e66c) //110
   DEF(task_MovieRecord                       ,0xff985e5c) //110
   DEF(task_PhySw                             ,0xff8349b8) //110
NHSTUB(time                                   ,0xff88ff64) //109
NHSTUB(vsprintf                               ,0xff820898) //115
//NHSTUB(write                                ,0xff83843c) //101
//NHSTUB(EngDrvIn                             ,0xff835d54) //102
//NHSTUB(EngDrvOut                            ,0xff835d3c) //102
//NHSTUB(EngDrvRead                           ,0xff835d5c) //102
//NHSTUB(EngDrvBits                           ,0xff835d70) //102
//NHSTUB(GetSDProtect                         ,0xff834de0) //101
//NHSTUB(StartRecModeMenu                     ,0xff89690c) //102
//NHSTUB(DispCon_ShowBitmapColorBar           ,0xff85fcd8) //102
//NHSTUB(ResetZoomLens                        ,0xffaef318) //102
//NHSTUB(ResetFocusLens                       ,0xffaedfe0) //102
//NHSTUB(NR_GetDarkSubType                    ,0xff98dc48) //102
//NHSTUB(NR_SetDarkSubType                    ,0xff98db80) //102
//NHSTUB(SavePaletteData                      ,0xffb5f788) //102
//NHSTUB(GUISrv_StartGUISystem                ,0xff8b15b8) //101
