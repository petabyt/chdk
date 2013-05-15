// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R31 (DRYOS version 2.3, release #0031)
//   Firmware Ver GM1.00C
//   Canon PowerShot SD780 IS

// Values for makefile.inc
//   PLATFORMOSVER = 31
//   PLATFORMID = 12738 (0x31c2) // Found @ 0xfffe0130
//   MAXRAMADDR = 0x03ffffff
//   KEYSYS = d4                 // Found @ 0xffff3584
//   NEED_ENCODED_DISKBOOT = 2   // Found @ 0xffff3594

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
NHSTUB(kbd_pwr_off                            ,0xff843204) //  2 64%
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff877f44 -> ff8746ec -> ff9442b0 -> ffa4a604 -> ffb2e4d0
// Mode 16390 in firmware but not in current modemap
// Mode 16904 in firmware but not in current modemap
// Mode 16906 in firmware but not in current modemap
// Mode 16923 in firmware but not in current modemap
// Mode 16924 in firmware but not in current modemap
// Mode 16413 in firmware but not in current modemap
// Mode 16408 in firmware but not in current modemap
// Mode 16406 in firmware but not in current modemap
// Mode  2600 in firmware but not in current modemap
// Mode  2601 in firmware but not in current modemap
// Current modemap entry not found in firmware - MODE_LANDSCAPE           32780
// Current modemap entry not found in firmware - MODE_SCN_NIGHT_SCENE     16398
// Current modemap entry not found in firmware - MODE_VIDEO_SPEED          2598
// Current modemap entry not found in firmware - MODE_VIDEO_STD            2597

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x0000e238) // Found @0xff821dcc
DEF(physw_run                               ,0x00001c34) // Found @0xff821a40
DEF(physw_sleep_delay                       ,0x00001c32) // Found @0xff821a40
DEF(levent_table                            ,0xffb009f0) // Found @0xffb009f0
DEF(FlashParamsTable                        ,0xffb2e6ac) // Found @0xffb2e6ac
DEF(movie_status                            ,0x00005b10) // Found @0xff91a3c4
DEF(canon_menu_active                       ,0x00002ca0) // Found @0xff86edcc
DEF(canon_shoot_menu_active                 ,0x00006e29) // Found @0xff953cac
DEF(playrec_mode                            ,0x00002a08) // Found @0xff862160
DEF(zoom_status                             ,0x0000ac68) // Found @0xffa4be34
DEF(some_flag_for_af_scan                   ,0x00006068) // Found @0xff91d6b8
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 3 int value(s), the first is the zoom focus length.
// there are 7 entries in the table - set NUM_FL to 7
DEF(focus_len_table                         ,0xfffe2a8c) // Found @0xfffe2a8c
DEF(zoom_busy                               ,0x00005a3c) // Found @0xff9166f4
DEF(focus_busy                              ,0x00005938) // Found @0xff9115c8
//DEF(recreview_hold                          ,0x0000328c) // Found @0xff87dd40, ** != ** stubs_min = 0x00006c0c (0x6C0C)

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x403f1000; }             // Found @0xff83dae4
//void *vid_get_viewport_fb()      { return (void*)0x415f3570; }             // Found @0xffa97de8
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x26f4+0x58)); } // Found @0xff853cb4 & 0xff853cec
//char *camera_jpeg_count_str()    { return (char*)0x00033110; }             // Found @0xff98fafc
//long hook_raw_size()             { return 0x011ca240; }                    // Found @0xffa9a374
//int get_flash_params_count(void) { return 0x7a; }                          // Found @0xff94536c

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffacd584, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x00080000 // Found @0xffacd59c, levent 0x902
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_LEFT            ,0x00000001 }, // Found @0xffacd47c, levent 0x06
//    { 0, KEY_RIGHT           ,0x00000002 }, // Found @0xffacd488, levent 0x07
//    { 0, KEY_DOWN            ,0x00000004 }, // Found @0xffacd494, levent 0x05
//    { 0, KEY_UP              ,0x00000008 }, // Found @0xffacd4a0, levent 0x04
//    { 1, KEY_MENU            ,0x00000800 }, // Found @0xffacd4ac, levent 0x09
//    { 1, KEY_SET             ,0x00004000 }, // Found @0xffacd4b8, levent 0x08
//    { 1, KEY_POWER           ,0x00010000 }, // Found @0xffacd4c4, levent 0x600
//    { 1, KEY_PLAYBACK        ,0x00080000 }, // Found @0xffacd4e8, levent 0x601
//    { 2, KEY_SHOOT_FULL      ,0x00001001 }, // Found @0xffacd548, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00001000 }, // Found @0xffacd548, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00000001 }, // Found @0xffacd4f4, levent 0x00
//    { 2, KEY_DISPLAY         ,0x00000040 }, // Found @0xffacd530, levent 0x0a
//    { 2, KEY_ZOOM_OUT        ,0x00002000 }, // Found @0xffacd554, levent 0x03
//    { 2, KEY_ZOOM_IN         ,0x00004000 }, // Found @0xffacd560, levent 0x02
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_RAW_ROWPIX    4080 // Found @0xff8e6184
//#define CAM_RAW_ROWS      3048 // Found @0xff8e6188
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff82748c

// Misc stuff
DEF(ctypes, 0xffacc2ea)

// For capt_seq.c
//static long *nrflag = (long*)(0x6050-0x08);  // Found @ ff91f644 & ff91f660

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
//NHSTUB(CreateJumptable                      ,0xffa9adb4) //  1
//NHSTUB(_uartr_req                           ,0xff81c34c) //111
//NHSTUB(AllocateMemory                       ,0xffa3df5c) //101
NHSTUB(AllocateUncacheableMemory              ,0xff827448) //112
NHSTUB(Close                                  ,0xff823c98) //101
NHSTUB(CreateTask                             ,0xff81afac) //101
NHSTUB(DebugAssert                            ,0xff81b284) //111
NHSTUB(DeleteDirectory_Fut                    ,0xff823628) //116
NHSTUB(DeleteFile_Fut                         ,0xff823544) //112
NHSTUB(DoAFLock                               ,0xff825334) //102
NHSTUB(EnterToCompensationEVF                 ,0xff825420) //104
NHSTUB(ExecuteEventProcedure                  ,0xff86a518) //104
NHSTUB(ExitFromCompensationEVF                ,0xff825464) //104
NHSTUB(ExitTask                               ,0xff81b23c) //101
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff82ff40) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff830084) //104
NHSTUB(Fclose_Fut                             ,0xff8236c0) //101
NHSTUB(Feof_Fut                               ,0xff8238ac) //  1
NHSTUB(Fflush_Fut                             ,0xff8238e8) //  1
NHSTUB(Fgets_Fut                              ,0xff823814) //  1
NHSTUB(Fopen_Fut                              ,0xff823680) //101
NHSTUB(Fread_Fut                              ,0xff82376c) //101
//NHSTUB(FreeMemory                           ,0xffa3df54) //101
NHSTUB(FreeUncacheableMemory                  ,0xff827488) //112
NHSTUB(Fseek_Fut                              ,0xff823860) //101
NHSTUB(Fwrite_Fut                             ,0xff8237c0) //101
NHSTUB(GetBatteryTemperature                  ,0xff845f30) //102
NHSTUB(GetCCDTemperature                      ,0xff845ebc) //102
NHSTUB(GetCurrentAvValue                      ,0xff913380) //102
NHSTUB(GetDrive_ClusterSize                   ,0xff8523e8) //  5
NHSTUB(GetDrive_FreeClusters                  ,0xff852440) //  5
NHSTUB(GetDrive_TotalClusters                 ,0xff852414) //  5
NHSTUB(GetFocusLensSubjectDistance            ,0xff912430) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff91280c) //  3
NHSTUB(GetKbdState                            ,0xff8431ec) //109
NHSTUB(GetMemInfo                             ,0xff813be4) //115
NHSTUB(GetOpticalTemperature                  ,0xff845fa4) //102
NHSTUB(GetParameterData                       ,0xff94532c) //101
NHSTUB(GetPropertyCase                        ,0xff86e284) //102
NHSTUB(GetSystemTime                          ,0xffa3dfb4) //101
NHSTUB(GetVRAMHPixelsSize                     ,0xff8b1568) //102
NHSTUB(GetVRAMVPixelsSize                     ,0xff8b1574) //102
NHSTUB(GetZoomLensCurrentPoint                ,0xff916a6c) //102
NHSTUB(GetZoomLensCurrentPosition             ,0xffa31844) //102
NHSTUB(GiveSemaphore                          ,0xff826e64) //112
NHSTUB(IsStrobeChargeCompleted                ,0xff8a35c8) //102
NHSTUB(LEDDrive                               ,0xff842698) //103
NHSTUB(LocalTime                              ,0xff867f08) //115
NHSTUB(LockMainPower                          ,0xff874304) //103
//NHSTUB(Lseek                                ,0xff823dd8) //101
NHSTUB(MakeDirectory_Fut                      ,0xff8235b8) //116
NHSTUB(MoveFocusLensToDistance                ,0xffa94780) //102
NHSTUB(MoveIrisWithAv                         ,0xffa3c0b4) //102
NHSTUB(MoveZoomLensWithPoint                  ,0xffa3c640) //102
//NHSTUB(NewTaskShell                         ,0xff86dd28) //103
NHSTUB(Open                                   ,0xff823c70) //101
NHSTUB(PB2Rec                                 ,0xff8772bc) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff85b138) //102
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff85b110) //102
NHSTUB(PT_PlaySound                           ,0xff85ad20) //102
NHSTUB(PostLogicalEventForNotPowerType        ,0xff87392c) //103
NHSTUB(PostLogicalEventToUI                   ,0xff873978) //103
NHSTUB(PutInNdFilter                          ,0xffa3c4a4) //102
NHSTUB(PutOutNdFilter                         ,0xffa3c4c8) //102
NHSTUB(Read                                   ,0xff819ae4) //101
NHSTUB(ReadFastDir                            ,0xffa1fd94) //  1
NHSTUB(Rec2PB                                 ,0xff8772fc) //104
NHSTUB(RefreshPhysicalScreen                  ,0xff99cf18) //104
//NHSTUB(Remove                               ,0xff823ce0) //  1
NHSTUB(RenameFile_Fut                         ,0xff8234f0) //  1
NHSTUB(Restart                                ,0xff828b98) //106
NHSTUB(SetAE_ShutterSpeed                     ,0xffa96f60) //102
NHSTUB(SetAutoShutdownTime                    ,0xff874378) //103
NHSTUB(SetCurrentCaptureModeType              ,0xff87b2c0) //101
NHSTUB(SetFileAttributes                      ,0xff823fc4) //  1
NHSTUB(SetFileTimeStamp                       ,0xff823f74) //  1
NHSTUB(SetLogicalEventActive                  ,0xff874080) //101
NHSTUB(SetParameterData                       ,0xff94529c) //101
NHSTUB(SetPropertyCase                        ,0xff86e17c) //102
NHSTUB(SetScriptMode                          ,0xff8740d0) //101
NHSTUB(SleepTask                              ,0xff8270cc) //101
NHSTUB(TakeSemaphore                          ,0xff826d94) //101
NHSTUB(TurnOffBackLight                       ,0xff8810a0) //104
NHSTUB(TurnOnBackLight                        ,0xff881088) //104
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff931e7c) //101
NHSTUB(UnlockAF                               ,0xff82536c) //102
NHSTUB(UnlockMainPower                        ,0xff874258) //103
NHSTUB(UnsetZoomForMovie                      ,0xff94afc4) //104
NHSTUB(UpdateMBROnFlash                       ,0xff852240) //105
NHSTUB(VbattGet                               ,0xff820644) //103
NHSTUB(Write                                  ,0xff823d44) //101
NHSTUB(WriteSDCard                            ,0xff903b38) //108
NHSTUB(_log                                   ,0xffac9580) //111
NHSTUB(_log10                                 ,0xffac820c) //112
NHSTUB(_pow                                   ,0xffac837c) //114
NHSTUB(_sqrt                                  ,0xffacb124) //  1
NHSTUB(add_ptp_handler                        ,0xff9eabdc) //  3
NHSTUB(apex2us                                ,0xff9a010c) //  4
NHSTUB(close                                  ,0xff8198fc) //  1
NHSTUB(closedir                               ,0xffa1fe64) //  1
NHSTUB(err_init_task                          ,0xff814e2c) //111
NHSTUB(exmem_alloc                            ,0xff868dc8) //103
NHSTUB(free                                   ,0xff813a3c) //112
NHSTUB(kbd_p1_f                               ,0xff821e48) //109
NHSTUB(kbd_p1_f_cont                          ,0xff821e54) //109
NHSTUB(kbd_p2_f                               ,0xff82170c) //109
NHSTUB(kbd_read_keys                          ,0xff821dcc) //109
NHSTUB(kbd_read_keys_r2                       ,0xff842b6c) //109
NHSTUB(lseek                                  ,0xff823dd8) //101
NHSTUB(malloc                                 ,0xff813968) //112
NHSTUB(memcmp                                 ,0xff81cc5c) //101
NHSTUB(memcpy                                 ,0xff887900) //101
NHSTUB(memset                                 ,0xff99f3f4) //101
NHSTUB(mkdir                                  ,0xff82403c) //109
NHSTUB(mktime_ext                             ,0xff88816c) //  1
NHSTUB(open                                   ,0xff81984c) //  1
NHSTUB(OpenFastDir                            ,0xffa1fd00) //  1
NHSTUB(qsort                                  ,0xffa79a4c) //  1
NHSTUB(rand                                   ,0xff81cd64) //  1
//NHSTUB(read                                 ,0xff819ae4) //101
NHSTUB(reboot_fw_update                       ,0xffa27444) //106
NHSTUB(set_control_event                      ,0xff873db4) //111
NHSTUB(srand                                  ,0xff81cd58) //  1
NHSTUB(stat                                   ,0xff823ea4) //  1
NHSTUB(strcat                                 ,0xff887714) //  1
NHSTUB(strchr                                 ,0xff88779c) //  1
NHSTUB(strcmp                                 ,0xff81cbf4) //101
NHSTUB(strcpy                                 ,0xff81cbdc) //101
NHSTUB(strftime                               ,0xff887b74) //  1
NHSTUB(strlen                                 ,0xff81cc38) //101
NHSTUB(strncmp                                ,0xff887750) //  1
NHSTUB(strncpy                                ,0xff82cd3c) //  1
NHSTUB(strrchr                                ,0xff99f3cc) //  1
NHSTUB(strtol                                 ,0xff82cf74) //101
NHSTUB(strtolx                                ,0xff82cd78) //109
   DEF(task_CaptSeq                           ,0xff85d754) //107
   DEF(task_ExpDrv                            ,0xff899cc4) //110
   DEF(task_InitFileModules                   ,0xff877dd0) //107
   DEF(task_MovieRecord                       ,0xff91a6ac) //107
   DEF(task_PhySw                             ,0xff821a3c) //107
NHSTUB(time                                   ,0xff868480) //109
NHSTUB(vsprintf                               ,0xff81cba0) //115
//NHSTUB(write                                ,0xff823d44) //101
//NHSTUB(GetSDProtect                         ,0xff821da4) //103
//NHSTUB(StartRecModeMenu                     ,0xff86edc8) //102
//NHSTUB(DispCon_ShowBitmapColorBar           ,0xff83da9c) //102
//NHSTUB(ResetZoomLens                        ,0xffa3c594) //102
//NHSTUB(ResetFocusLens                       ,0xffa3b4f8) //102
//NHSTUB(NR_GetDarkSubType                    ,0xff921b54) //102
//NHSTUB(NR_SetDarkSubType                    ,0xff921aac) //102
//NHSTUB(SavePaletteData                      ,0xffa9911c) //102
