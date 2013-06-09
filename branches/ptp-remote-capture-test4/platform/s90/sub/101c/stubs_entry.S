// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R39 (DRYOS version 2.3, release #0039)
//   Firmware Ver GM1.01C
//   Possible corrupt firmware dump - file size to small for start address 0xff810000
//     file size = 7.15MB, should be 7.94MB
//   Could not find Camera name - possible corrupt firmware dump

// Values for makefile.inc
//   PLATFORMOSVER = 39
//   MAXRAMADDR = 0x03ffffff

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NHSTUB(SetScriptMode                        ,0xff894498) //101        *** != 0xff810f4c
//NHSTUB(kbd_pwr_off                          ,0xff85e3a4) //  2 60%    *** != 0xff833350
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff8984d8 -> ff894adc -> ff9936cc -> ffaaea90 -> ffbefb90
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x000330d8) // Found @0xff8335b4
DEF(physw_run                               ,0x00001c44) // Found @0xff83320c
DEF(physw_sleep_delay                       ,0x00001c42) // Found @0xff83320c
//DEF(levent_table                            ,0xffb8b680) // Found @0xffb8b680, ** != ** stubs_min = 0xff9915bc (0xFF9915BC)
DEF(FlashParamsTable                        ,0xffbefd80) // Found @0xffbefd80
DEF(movie_status                            ,0x00007ae8) // Found @0xff961658
DEF(full_screen_refresh                     ,0x0000a36c) // Found @0xffa07f84
DEF(canon_menu_active                       ,0x00003038) // Found @0xff88d6ac
DEF(canon_shoot_menu_active                 ,0x00008dd1) // Found @0xff9ab95c
DEF(playrec_mode                            ,0x00002d64) // Found @0xff87fa70
DEF(zoom_status                             ,0x00008aa4) // Found @0xff99bd30
DEF(some_flag_for_af_scan                   ,0x00007ff4) // Found @0xff9646e8
DEF(zoom_busy                               ,0x00007a14) // Found @0xff95d888
DEF(focus_busy                              ,0x000078dc) // Found @0xff957d98
//DEF(recreview_hold                          ,0x00003a94) // Found @0xff89e70c, ** != ** stubs_min = 0x00008a28 (0x8944+0xE4)

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x40471000; }             // Found @0xff858728
//void *vid_get_viewport_fb()      { return (void*)0x407e8a00; }             // Found @0xffaff4ec
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x2a20+0x58)); } // Found @0xff86fa48 & 0xff86fa80
//char *camera_jpeg_count_str()    { return (char*)0x0009792c; }             // Found @0xff9fc148
//long hook_raw_size()             { return 0x00ee9200; }                    // Found @0xffb027b8
//int get_flash_params_count(void) { return 0x85; }                          // Found @0xff994ccc

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffb3ac60, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x00200000 // Found @0xffb3ac78, levent 0x902
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_SHOOT_FULL      ,0x00000300 }, // Found @0xffb3ab4c, levent 0x01
//    { 0, KEY_SHOOT_FULL_ONLY ,0x00000200 }, // Found @0xffb3ab4c, levent 0x01
//    { 0, KEY_SHOOT_HALF      ,0x00000100 }, // Found @0xffb3ab40, levent 0x00
//    { 0, KEY_POWER           ,0x00000400 }, // Found @0xffb3ab58, levent 0x600
//    { 0, KEY_PLAYBACK        ,0x00000800 }, // Found @0xffb3ab64, levent 0x601
//    { 1, KEY_ZOOM_IN         ,0x00000010 }, // Found @0xffb3abc4, levent 0x02
//    { 1, KEY_ZOOM_OUT        ,0x00000020 }, // Found @0xffb3abd0, levent 0x03
//    { 1, KEY_LEFT            ,0x00000100 }, // Found @0xffb3abf4, levent 0x06
//    { 1, KEY_RIGHT           ,0x00000200 }, // Found @0xffb3ac00, levent 0x07
//    { 1, KEY_DOWN            ,0x00000400 }, // Found @0xffb3ac0c, levent 0x05
//    { 1, KEY_DISPLAY         ,0x00001000 }, // Found @0xffb3ac24, levent 0x0a
//    { 1, KEY_MENU            ,0x00002000 }, // Found @0xffb3ac30, levent 0x09
//    { 1, KEY_UP              ,0x00004000 }, // Found @0xffb3ac3c, levent 0x04
//    { 1, KEY_SET             ,0x00008000 }, // Found @0xffb3ac48, levent 0x08
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_RAW_ROWPIX    3744 // Found @0xff934648
//#define CAM_RAW_ROWS      2784 // Found @0xff934650
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff838e10

// Misc stuff
DEF(ctypes, 0xffb39582)

// For capt_seq.c
DEF(_nrflag,0x7fd0) // Found @ ff966b50 (0x7fd8) & ff966b70 (-0x08)
//static long *nrflag = (long*)(0x7fd8-0x08);  // Found @ ff966b50 & ff966b6c

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
//NHSTUB(CreateJumptable                      ,0xffb03240) //  1
//NHSTUB(_uartr_req                           ,0xff81f964) //111
//NHSTUB(AllocateMemory                       ,0xffa9d378) //101
NHSTUB(AllocateUncacheableMemory              ,0xff838dcc) //112
NHSTUB(Close                                  ,0xff835414) //101
NHSTUB(CreateTask                             ,0xff81e5b4) //101
NHSTUB(DebugAssert                            ,0xff81e88c) //111
NHSTUB(DeleteDirectory_Fut                    ,0xff834e84) //116
NHSTUB(DeleteFile_Fut                         ,0xff834da0) //112
NHSTUB(DoAFLock                               ,0xff836b98) //102
NHSTUB(EnterToCompensationEVF                 ,0xff836d3c) //104
NHSTUB(ExecuteEventProcedure                  ,0xff888d78) //104
NHSTUB(ExitFromCompensationEVF                ,0xff836d80) //104
NHSTUB(ExitTask                               ,0xff81e844) //101
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff844700) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff8447d8) //104
NHSTUB(Fclose_Fut                             ,0xff834f1c) //101
NHSTUB(Feof_Fut                               ,0xff835108) //  1
NHSTUB(Fflush_Fut                             ,0xff835144) //  1
NHSTUB(Fgets_Fut                              ,0xff835070) //  1
NHSTUB(Fopen_Fut                              ,0xff834edc) //101
NHSTUB(Fread_Fut                              ,0xff834fc8) //101
//NHSTUB(FreeMemory                           ,0xffa9d370) //101
NHSTUB(FreeUncacheableMemory                  ,0xff838e0c) //112
NHSTUB(Fseek_Fut                              ,0xff8350bc) //101
NHSTUB(Fwrite_Fut                             ,0xff83501c) //101
NHSTUB(GetBatteryTemperature                  ,0xff8615f0) //102
NHSTUB(GetCCDTemperature                      ,0xff86157c) //102
NHSTUB(GetCurrentAvValue                      ,0xff95a53c) //102
NHSTUB(GetDrive_ClusterSize                   ,0xff86e380) //  3
NHSTUB(GetDrive_FreeClusters                  ,0xff86e3e0) //  3
NHSTUB(GetDrive_TotalClusters                 ,0xff86e3b4) //  3
NHSTUB(GetFocusLensSubjectDistance            ,0xff958b10) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff958f58) //  3
NHSTUB(GetImageFolder                         ,0xff93c4d4) //106
NHSTUB(GetKbdState                            ,0xff85e258) //109
NHSTUB(GetMemInfo                             ,0xff81a070) //115
NHSTUB(GetOpticalTemperature                  ,0xff861664) //102
NHSTUB(GetParameterData                       ,0xff994c8c) //101
NHSTUB(GetPropertyCase                        ,0xff88cae0) //102
NHSTUB(GetSystemTime                          ,0xffa9d3d0) //101
NHSTUB(GetVRAMHPixelsSize                     ,0xff84f110) //102
NHSTUB(GetVRAMVPixelsSize                     ,0xff84f11c) //102
NHSTUB(GetZoomLensCurrentPoint                ,0xff95dbfc) //102
NHSTUB(GetZoomLensCurrentPosition             ,0xffa9101c) //102
NHSTUB(GiveSemaphore                          ,0xff8387e8) //112
NHSTUB(IsStrobeChargeCompleted                ,0xff8d878c) //102
NHSTUB(LEDDrive                               ,0xff85d648) //103
NHSTUB(LocalTime                              ,0xff8866ec) //115
NHSTUB(LockMainPower                          ,0xff8946f8) //103
//NHSTUB(Lseek                                ,0xff835530) //101
NHSTUB(MakeDirectory_Fut                      ,0xff834e14) //116
NHSTUB(MoveFocusLensToDistance                ,0xffafbf00) //102
NHSTUB(MoveIrisWithAv                         ,0xffa9ad44) //102
NHSTUB(MoveZoomLensWithPoint                  ,0xffa9b3b8) //102
//NHSTUB(NewTaskShell                         ,0xff88c58c) //103
NHSTUB(Open                                   ,0xff8353bc) //101
NHSTUB(PB2Rec                                 ,0xff897840) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff87772c) //102
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff877704) //102
NHSTUB(PT_PlaySound                           ,0xff881888) //102
NHSTUB(PostLogicalEventForNotPowerType        ,0xff892524) //103
NHSTUB(PostLogicalEventToUI                   ,0xff892570) //103
NHSTUB(PutInNdFilter                          ,0xffaf9c50) //102
NHSTUB(PutOutNdFilter                         ,0xffaf9c88) //102
NHSTUB(Read                                   ,0xff81ab78) //101
NHSTUB(ReadFastDir                            ,0xffa7d958) //  3
NHSTUB(Rec2PB                                 ,0xff897880) //104
NHSTUB(RefreshPhysicalScreen                  ,0xffa090fc) //104
//NHSTUB(Remove                               ,0xff835448) //  4
NHSTUB(RenameFile_Fut                         ,0xff834d0c) //116
NHSTUB(Restart                                ,0xff83a520) //106
NHSTUB(ScreenLock                             ,0xffa0a31c) //  3
NHSTUB(ScreenUnlock                           ,0xffa0a344) //  3
NHSTUB(SetAE_ShutterSpeed                     ,0xffafe6ac) //102
NHSTUB(SetAutoShutdownTime                    ,0xff89476c) //103
NHSTUB(SetCurrentCaptureModeType              ,0xff89b830) //101
NHSTUB(SetFileAttributes                      ,0xff8356e4) //  3
NHSTUB(SetFileTimeStamp                       ,0xff8356a0) //  3
NHSTUB(SetLogicalEventActive                  ,0xff894448) //101
NHSTUB(SetParameterData                       ,0xff994b68) //101
NHSTUB(SetPropertyCase                        ,0xff88c9dc) //102
NHSTUB(SleepTask                              ,0xff838a50) //101
NHSTUB(TakeSemaphore                          ,0xff838718) //101
NHSTUB(TurnOffBackLight                       ,0xff8a49c8) //104
NHSTUB(TurnOnBackLight                        ,0xff8a49b0) //104
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff97ec10) //105
NHSTUB(UnlockAF                               ,0xff836bd0) //102
NHSTUB(UnlockMainPower                        ,0xff89464c) //103
NHSTUB(UnsetZoomForMovie                      ,0xff8a0f30) //104
NHSTUB(UpdateMBROnFlash                       ,0xff86e200) //105
NHSTUB(VbattGet                               ,0xff831e04) //103
NHSTUB(Write                                  ,0xff8354a4) //101
NHSTUB(WriteSDCard                            ,0xff94a63c) //108
NHSTUB(_log                                   ,0xffb36808) //111
NHSTUB(_log10                                 ,0xffb35494) //112
NHSTUB(_pow                                   ,0xffb35604) //114
NHSTUB(_sqrt                                  ,0xffb383ac) //  1
NHSTUB(add_ptp_handler                        ,0xffa471d0) //  3
NHSTUB(apex2us                                ,0xffa0d9b8) //  4
NHSTUB(close                                  ,0xff81a990) //  1
NHSTUB(closedir                               ,0xffa7d7e0) //  3
NHSTUB(err_init_task                          ,0xff815f28) //111
NHSTUB(exmem_alloc                            ,0xff8875ac) //103
NHSTUB(exmem_free                             ,0xff887624) //103
NHSTUB(free                                   ,0xff814138) //112
NHSTUB(kbd_p1_f                               ,0xff833630) //109
NHSTUB(kbd_p1_f_cont                          ,0xff83363c) //109
NHSTUB(kbd_p2_f                               ,0xff832ed8) //109
NHSTUB(kbd_read_keys                          ,0xff8335b4) //109
NHSTUB(kbd_read_keys_r2                       ,0xff85db5c) //109
NHSTUB(lseek                                  ,0xff835530) //101
NHSTUB(malloc                                 ,0xff8140dc) //112
NHSTUB(memcmp                                 ,0xff8203e8) //101
NHSTUB(memcpy                                 ,0xff83e43c) //101
NHSTUB(memset                                 ,0xffa0ca08) //101
NHSTUB(mkdir                                  ,0xff835888) //109
NHSTUB(mktime_ext                             ,0xff8ac380) //  1
NHSTUB(open                                   ,0xff81a8e0) //  1
NHSTUB(OpenFastDir                            ,0xffa7d824) //  3
NHSTUB(qsort                                  ,0xffaec5e8) //  1
NHSTUB(rand                                   ,0xff8204f0) //  1
//NHSTUB(read                                 ,0xff81ab78) //101
NHSTUB(realloc                                ,0xffa0ca84) //115
NHSTUB(reboot_fw_update                       ,0xffa82e68) //106
NHSTUB(set_control_event                      ,0xff89409c) //111
NHSTUB(srand                                  ,0xff8204e4) //  1
NHSTUB(stat                                   ,0xff83556c) //109
NHSTUB(strcat                                 ,0xff8abb3c) //  1
NHSTUB(strchr                                 ,0xff813fc0) //  1
NHSTUB(strcmp                                 ,0xff8203a4) //101
NHSTUB(strcpy                                 ,0xff82038c) //101
NHSTUB(strftime                               ,0xff8abd88) //  1
NHSTUB(strlen                                 ,0xff81400c) //101
NHSTUB(strncmp                                ,0xff813f74) //  1
NHSTUB(strncpy                                ,0xff813f38) //  1
NHSTUB(strrchr                                ,0xff813fe4) //  1
NHSTUB(strtol                                 ,0xff83e71c) //101
NHSTUB(strtolx                                ,0xff83e520) //109
   DEF(task_CaptSeq                           ,0xff87a258) //107
   DEF(task_ExpDrv                            ,0xff8c0ed0) //110
   DEF(task_FileWrite                         ,0xffa791b0) //107
   DEF(task_InitFileModules                   ,0xff898364) //107
   DEF(task_MovieRecord                       ,0xff96193c) //107
   DEF(task_PhySw                             ,0xff833208) //107
   DEF(task_RotaryEncoder                     ,0xff85e508) //107
NHSTUB(time                                   ,0xff886c64) //109
NHSTUB(vsprintf                               ,0xff820350) //115
//NHSTUB(write                                ,0xff8354a4) //101
//NHSTUB(EngDrvIn                             ,0xff834470) //102
//NHSTUB(EngDrvOut                            ,0xff834458) //102
//NHSTUB(EngDrvRead                           ,0xff834478) //102
//NHSTUB(EngDrvBits                           ,0xff83448c) //102
//NHSTUB(GetSDProtect                         ,0xff83358c) //103
//NHSTUB(StartRecModeMenu                     ,0xff88d6a8) //102
//NHSTUB(DispCon_ShowBitmapColorBar           ,0xff8586e0) //102
//NHSTUB(ResetZoomLens                        ,0xffa9b30c) //102
//NHSTUB(ResetFocusLens                       ,0xffa99fe8) //102
//NHSTUB(NR_GetDarkSubType                    ,0xff969884) //102
//NHSTUB(NR_SetDarkSubType                    ,0xff9697dc) //102
//NHSTUB(SavePaletteData                      ,0xffb009e0) //102
//NHSTUB(GUISrv_StartGUISystem                ,0xff8ab8bc) //101
