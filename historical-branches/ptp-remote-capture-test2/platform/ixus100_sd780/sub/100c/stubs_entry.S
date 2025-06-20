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
NSTUB(kbd_pwr_off                             ,0xff843204) //  2 64%
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
NSTUB(AllocateMemory                          ,0xffa3df5c) //101
NSTUB(AllocateUncacheableMemory               ,0xff827448) //112
NSTUB(Close                                   ,0xff823c98) //101
NSTUB(CreateTask                              ,0xff81afac) //101
NSTUB(DebugAssert                             ,0xff81b284) //111
NSTUB(DeleteDirectory_Fut                     ,0xff823628) //116
NSTUB(DeleteFile_Fut                          ,0xff823544) //112
NSTUB(DoAFLock                                ,0xff825334) //102
NSTUB(EnterToCompensationEVF                  ,0xff825420) //104
NSTUB(ExecuteEventProcedure                   ,0xff86a518) //104
NSTUB(ExitFromCompensationEVF                 ,0xff825464) //104
NSTUB(ExitTask                                ,0xff81b23c) //101
NSTUB(ExpCtrlTool_StartContiAE                ,0xff82ff40) //104
NSTUB(ExpCtrlTool_StopContiAE                 ,0xff830084) //104
NSTUB(Fclose_Fut                              ,0xff8236c0) //101
NSTUB(Feof_Fut                                ,0xff8238ac) //  1
NSTUB(Fflush_Fut                              ,0xff8238e8) //  1
NSTUB(Fgets_Fut                               ,0xff823814) //  1
NSTUB(Fopen_Fut                               ,0xff823680) //101
NSTUB(Fread_Fut                               ,0xff82376c) //101
NSTUB(FreeMemory                              ,0xffa3df54) //101
NSTUB(FreeUncacheableMemory                   ,0xff827488) //112
NSTUB(Fseek_Fut                               ,0xff823860) //101
NSTUB(Fwrite_Fut                              ,0xff8237c0) //101
NSTUB(GetBatteryTemperature                   ,0xff845f30) //102
NSTUB(GetCCDTemperature                       ,0xff845ebc) //102
NSTUB(GetCurrentAvValue                       ,0xff913380) //102
NSTUB(GetDrive_ClusterSize                    ,0xff8523e8) //  5
NSTUB(GetDrive_FreeClusters                   ,0xff852440) //  5
NSTUB(GetDrive_TotalClusters                  ,0xff852414) //  5
NSTUB(GetFocusLensSubjectDistance             ,0xff912430) //102
NSTUB(GetFocusLensSubjectDistanceFromLens     ,0xff91280c) //  3
NSTUB(GetKbdState                             ,0xff8431ec) //109
NSTUB(GetMemInfo                              ,0xff813be4) //115
NSTUB(GetOpticalTemperature                   ,0xff845fa4) //102
NSTUB(GetParameterData                        ,0xff94532c) //101
NSTUB(GetPropertyCase                         ,0xff86e284) //102
NSTUB(GetSystemTime                           ,0xffa3dfb4) //101
NSTUB(GetVRAMHPixelsSize                      ,0xff8b1568) //102
NSTUB(GetVRAMVPixelsSize                      ,0xff8b1574) //102
NSTUB(GetZoomLensCurrentPoint                 ,0xff916a6c) //102
NSTUB(GetZoomLensCurrentPosition              ,0xffa31844) //102
NSTUB(GiveSemaphore                           ,0xff826e64) //112
NSTUB(IsStrobeChargeCompleted                 ,0xff8a35c8) //102
NSTUB(LEDDrive                                ,0xff842698) //103
NSTUB(LocalTime                               ,0xff867f08) //115
NSTUB(LockMainPower                           ,0xff874304) //103
NSTUB(Lseek                                   ,0xff823dd8) //101
NSTUB(MakeDirectory_Fut                       ,0xff8235b8) //116
NSTUB(MoveFocusLensToDistance                 ,0xffa94780) //102
NSTUB(MoveIrisWithAv                          ,0xffa3c0b4) //102
NSTUB(MoveZoomLensWithPoint                   ,0xffa3c640) //102
NSTUB(NewTaskShell                            ,0xff86dd28) //103
NSTUB(Open                                    ,0xff823c70) //101
NSTUB(PB2Rec                                  ,0xff8772bc) //104
NSTUB(PT_MoveDigitalZoomToWide                ,0xff85b138) //102
NSTUB(PT_MoveOpticalZoomAt                    ,0xff85b110) //102
NSTUB(PT_PlaySound                            ,0xff85ad20) //102
NSTUB(PostLogicalEventForNotPowerType         ,0xff87392c) //103
NSTUB(PostLogicalEventToUI                    ,0xff873978) //103
NSTUB(PutInNdFilter                           ,0xffa3c4a4) //102
NSTUB(PutOutNdFilter                          ,0xffa3c4c8) //102
NSTUB(Read                                    ,0xff819ae4) //101
NSTUB(ReadFastDir                             ,0xffa1fd94) //  1
NSTUB(Rec2PB                                  ,0xff8772fc) //104
NSTUB(RefreshPhysicalScreen                   ,0xff99cf18) //104
NSTUB(Remove                                  ,0xff823ce0) //  1
NSTUB(RenameFile_Fut                          ,0xff8234f0) //  1
NSTUB(Restart                                 ,0xff828b98) //106
NSTUB(SetAE_ShutterSpeed                      ,0xffa96f60) //102
NSTUB(SetAutoShutdownTime                     ,0xff874378) //103
NSTUB(SetCurrentCaptureModeType               ,0xff87b2c0) //101
NSTUB(SetFileAttributes                       ,0xff823fc4) //  1
NSTUB(SetFileTimeStamp                        ,0xff823f74) //  1
NSTUB(SetLogicalEventActive                   ,0xff874080) //101
NSTUB(SetParameterData                        ,0xff94529c) //101
NSTUB(SetPropertyCase                         ,0xff86e17c) //102
NSTUB(SetScriptMode                           ,0xff8740d0) //101
NSTUB(SleepTask                               ,0xff8270cc) //101
NSTUB(TakeSemaphore                           ,0xff826d94) //101
NSTUB(TurnOffBackLight                        ,0xff8810a0) //104
NSTUB(TurnOnBackLight                         ,0xff881088) //104
NSTUB(UIFS_WriteFirmInfoToFile                ,0xff931e7c) //101
NSTUB(UnlockAF                                ,0xff82536c) //102
NSTUB(UnlockMainPower                         ,0xff874258) //103
NSTUB(UnsetZoomForMovie                       ,0xff94afc4) //104
NSTUB(UpdateMBROnFlash                        ,0xff852240) //105
NSTUB(VbattGet                                ,0xff820644) //103
NSTUB(Write                                   ,0xff823d44) //101
NSTUB(WriteSDCard                             ,0xff903b38) //108
NSTUB(_log                                    ,0xffac9580) //111
NSTUB(_log10                                  ,0xffac820c) //112
NSTUB(_pow                                    ,0xffac837c) //114
NSTUB(_sqrt                                   ,0xffacb124) //  1
NSTUB(add_ptp_handler                         ,0xff9eabdc) //  3
NSTUB(apex2us                                 ,0xff9a010c) //  4
NSTUB(close                                   ,0xff8198fc) //  1
NSTUB(closedir                                ,0xffa1fe64) //  1
NSTUB(err_init_task                           ,0xff814e2c) //111
NSTUB(exmem_alloc                             ,0xff868dc8) //103
NSTUB(free                                    ,0xff813a3c) //112
NSTUB(kbd_p1_f                                ,0xff821e48) //109
NSTUB(kbd_p1_f_cont                           ,0xff821e54) //109
NSTUB(kbd_p2_f                                ,0xff82170c) //109
NSTUB(kbd_read_keys                           ,0xff821dcc) //109
NSTUB(kbd_read_keys_r2                        ,0xff842b6c) //109
NSTUB(lseek                                   ,0xff823dd8) //101
NSTUB(malloc                                  ,0xff813968) //112
NSTUB(memcmp                                  ,0xff81cc5c) //101
NSTUB(memcpy                                  ,0xff887900) //101
NSTUB(memset                                  ,0xff99f3f4) //101
NSTUB(mkdir                                   ,0xff82403c) //109
NSTUB(mktime_ext                              ,0xff88816c) //  1
NSTUB(open                                    ,0xff81984c) //  1
NSTUB(OpenFastDir                             ,0xffa1fd00) //  1
NSTUB(qsort                                   ,0xffa79a4c) //  1
NSTUB(rand                                    ,0xff81cd64) //  1
NSTUB(read                                    ,0xff819ae4) //101
NSTUB(reboot_fw_update                        ,0xffa27444) //106
NSTUB(set_control_event                       ,0xff873db4) //111
NSTUB(srand                                   ,0xff81cd58) //  1
NSTUB(stat                                    ,0xff823ea4) //  1
NSTUB(strcat                                  ,0xff887714) //  1
NSTUB(strchr                                  ,0xff88779c) //  1
NSTUB(strcmp                                  ,0xff81cbf4) //101
NSTUB(strcpy                                  ,0xff81cbdc) //101
NSTUB(strftime                                ,0xff887b74) //  1
NSTUB(strlen                                  ,0xff81cc38) //101
NSTUB(strncmp                                 ,0xff887750) //  1
NSTUB(strncpy                                 ,0xff82cd3c) //  1
NSTUB(strrchr                                 ,0xff99f3cc) //  1
NSTUB(strtol                                  ,0xff82cf74) //101
NSTUB(strtolx                                 ,0xff82cd78) //109
  DEF(task_CaptSeq                            ,0xff85d754) //107
  DEF(task_ExpDrv                             ,0xff899cc4) //110
  DEF(task_FileWrite                          ,0xffa1b8d4) //107
  DEF(task_InitFileModules                    ,0xff877dd0) //107
  DEF(task_MovieRecord                        ,0xff91a6ac) //107
  DEF(task_PhySw                              ,0xff821a3c) //107
NSTUB(time                                    ,0xff868480) //109
NSTUB(vsprintf                                ,0xff81cba0) //115
NSTUB(write                                   ,0xff823d44) //101
