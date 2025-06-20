// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R23 (DRYOS version 2.3, release #0023)
//   Firmware Ver GM1.00C   // Found @ 0xff86be94, "GM1.00C" @ 0xff86bea1
//   Firmware build timestamp: Jan  8 2008 16:56:15
//   Possible corrupt firmware dump - file size too small for start address 0xff810000
//     file size = 7.92MB, should be 7.94MB
//   Canon DIGITAL IXUS 82 IS

// Values for makefile.inc
//   PLATFORMOSVER = 23
//   PLATFORMID = 12676 (0x3184) // Found @ 0xfffe0130
//   MAXRAMADDR = 0x01ffffff
//   MEMISOSTART = 0x000bff60
//   KEYSYS = d3enc              // Found @ 0xffff3308
//   NEED_ENCODED_DISKBOOT = 1   // Found @ 0xffff32e8
//   ARAM_HEAP_START = 0x2ce000  // Found @ 0xffa277f0
//   ARAM_HEAP_SIZE  = 0x32000   // Found @ 0xffa277b0

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NHSTUB(PutInNdFilter                        ,0xffa237cc) //102        *** != 0xffa7aad0
//NHSTUB(PutOutNdFilter                       ,0xffa237f0) //102        *** != 0xffa7ab08

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ffa37724 -> ffaede90
// Mode  2598 in firmware but not in current modemap
// Mode  2603 in firmware but not in current modemap

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00010370) // Found @0xff821efc
DEF(physw_run                               ,0x00001c00) // Found @0xff821b98
DEF(physw_sleep_delay                       ,0x00001bfe) // Found @0xff821b98
DEF(levent_table                            ,0xffacac6c) // Found @0xffacac6c
DEF(FlashParamsTable                        ,0xffaee050) // Found @0xffaee050
DEF(movie_status                            ,0x000053a4) // Found @0xff859b9c
DEF(canon_menu_active                       ,0x000094e8) // Found @0xff94cb3c
DEF(canon_shoot_menu_active                 ,0x00009e2d) // Found @0xff969e40
DEF(playrec_mode                            ,0x00005534) // Found @0xff860ee8
DEF(zoom_status                             ,0x0000d1cc) // Found @0xffa38f24
DEF(some_flag_for_af_scan                   ,0x0000cf50) // Found @0xffa24144
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 3 int value(s), the first is the zoom focus length.
// there are 7 entries in the table - set NUM_FL to 7
DEF(focus_len_table                         ,0xfffe297c) // Found @0xfffe297c
DEF(zoom_busy                               ,0x000085f0) // Found @0xff92ee60
DEF(focus_busy                              ,0x000084fc) // Found @0xff92aa0c
DEF(recreview_hold                          ,0x00005dc4) // Found @0xff87ccf8
// Camera appears to have only 1 RAW buffer @ 0x10f3f400 (Found @0xffa81f2c)
DEF(fileio_semaphore                        ,0x000029e4) // Found @0xff850b00
DEF_CONST(uiprop_count                      ,0x00000064) // Found @0xff95aa14

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x10361000; }             // Found @0xff83e91c
//void *vid_get_viewport_fb()      { return (void*)0x1065ade0; }             // Found @0xffa7fd18
DEF(viewport_fb_d                           ,0x00005224) // Found 0x51d4 (@0xff852e8c) + 0x50 (@0xff852ec4)
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x51d4+0x50)); } // Found @0xff852e8c & 0xff852ec4
DEF(jpeg_count_str                          ,0x0004c2c4) // Found @0xff9a0e30
//char *camera_jpeg_count_str()    { return (char*)0x0004c2c4; }             // Found @0xff9a0e30
//int get_flash_params_count(void) { return 0x73; }                          // Found @0xff95b458

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffaa8a9c, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x00040000 // Found @0xffaa8aa8, levent 0x902
//#define USB_IDX             2
//#define BATTCOVER_FLAG      0x00008000 // Found @0xffaa8a84, levent 0x905
//#define BATTCOVER_IDX       2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 1, KEY_POWER           ,0x40000000 }, // Found @0xffaa89e8, levent 0x600
//    { 2, KEY_SHOOT_FULL      ,0x00000003 }, // Found @0xffaa8a00, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000002 }, // Found @0xffaa8a00, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00000001 }, // Found @0xffaa89f4, levent 0x00
//    { 2, KEY_ZOOM_IN         ,0x00000004 }, // Found @0xffaa8a0c, levent 0x02
//    { 2, KEY_ZOOM_OUT        ,0x00000008 }, // Found @0xffaa8a18, levent 0x03
//    { 2, KEY_LEFT            ,0x00000010 }, // Found @0xffaa8a24, levent 0x06
//    { 2, KEY_RIGHT           ,0x00000020 }, // Found @0xffaa8a30, levent 0x07
//    { 2, KEY_DOWN            ,0x00000040 }, // Found @0xffaa8a3c, levent 0x05
//    { 2, KEY_UP              ,0x00000080 }, // Found @0xffaa8a48, levent 0x04
//    { 2, KEY_SET             ,0x00000100 }, // Found @0xffaa8a54, levent 0x08
//    { 2, KEY_DISPLAY         ,0x00000200 }, // Found @0xffaa8a60, levent 0x0a
//    { 2, KEY_MENU            ,0x00000400 }, // Found @0xffaa8a6c, levent 0x09
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_RAW_ROWPIX    3336 // Found @0xffa79640
//#define CAM_RAW_ROWS      2480 // Found @0xffa79648
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x10000000 // Found @0xff82866c
//#define PARAM_CAMERA_NAME 4 // Found @0xffaf0124

// Misc stuff
DEF(ctypes, 0xffaa858e)

// LED table init @ 0xff8e8f10
// LED #1: 0xc02200d4, offset 0x204
// LED #2: 0xc0220138, offset 0x84
// LED #3: 0xc02200d0, offset 0xc4
// LED #4: 0xc0220134, offset 0x4
// LED #5: 0xc0220130, offset 0x44

// For capt_seq.c
DEF(_nrflag,0x8d14) // Found @ ff939e90 (0x8d14)
//static long *nrflag = (long*)(0x8d14);       // Found @ ff939e90

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NHSTUB(AllocateUncacheableMemory              ,0xff828630) //112
NHSTUB(Close                                  ,0xff823e54) //120
NHSTUB(CreateBinarySemaphore                  ,0xff81b608) //115
NHSTUB(CreateTask                             ,0xff81b8e0) //120
NHSTUB(DebugAssert                            ,0xff81bdb8) //107
NHSTUB(DeleteDirectory_Fut                    ,0xff8237e4) //116
NHSTUB(DeleteFile_Fut                         ,0xff823700) //112
NHSTUB(DoAELock                               ,0xff82603c) //120
NHSTUB(DoAFLock                               ,0xff825c4c) //120
NHSTUB(EnterToCompensationEVF                 ,0xff825f48) //104
NHSTUB(ExecuteEventProcedure                  ,0xff869180) //104
NHSTUB(ExitFromCompensationEVF                ,0xff825f98) //104
NHSTUB(ExitTask                               ,0xff81bb70) //120
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff832a98) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff832bdc) //104
NHSTUB(Fclose_Fut                             ,0xff82387c) //120
NHSTUB(Feof_Fut                               ,0xff823a68) //  1
NHSTUB(Fflush_Fut                             ,0xff823aa4) //  1
NHSTUB(Fgets_Fut                              ,0xff8239d0) //  1
NHSTUB(Fopen_Fut                              ,0xff82383c) //120
NHSTUB(Fread_Fut                              ,0xff823928) //120
NHSTUB(FreeUncacheableMemory                  ,0xff828664) //112
NHSTUB(Fseek_Fut                              ,0xff823a1c) //120
NHSTUB(Fwrite_Fut                             ,0xff82397c) //120
NHSTUB(GetBatteryTemperature                  ,0xff845214) //102
NHSTUB(GetCCDTemperature                      ,0xff8451a4) //102
NHSTUB(GetCurrentAvValue                      ,0xff92c420) //120
NHSTUB(GetDrive_ClusterSize                   ,0xff84f0d4) //  1
NHSTUB(GetDrive_FreeClusters                  ,0xff84f13c) //  1
NHSTUB(GetDrive_TotalClusters                 ,0xff84f108) //  1
NHSTUB(GetFocusLensSubjectDistance            ,0xff92b518) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff92b824) //  1
NHSTUB(GetKbdState                            ,0xff842a04) //109
NHSTUB(GetMemInfo                             ,0xff813c40) //115
NHSTUB(GetOpticalTemperature                  ,0xff845284) //120
NHSTUB(GetParameterData                       ,0xff95b418) //101
NHSTUB(GetPropertyCase                        ,0xff86cd80) //102
NHSTUB(GetSystemTime                          ,0xffa27044) //120
NHSTUB(GetVRAMHPixelsSize                     ,0xff8c5d1c) //120
NHSTUB(GetVRAMVPixelsSize                     ,0xff8c5d28) //120
NHSTUB(GetZoomLensCurrentPoint                ,0xff92f1c4) //120
NHSTUB(GetZoomLensCurrentPosition             ,0xffa1d084) //102
NHSTUB(GiveSemaphore                          ,0xff81b844) //120
NHSTUB(IsStrobeChargeCompleted                ,0xff8bae5c) //102
NHSTUB(LEDDrive                               ,0xff842228) //120
NHSTUB(LocalTime                              ,0xff866844) //115
NHSTUB(LockMainPower                          ,0xff873894) //120
NHSTUB(MakeDirectory_Fut                      ,0xff823774) //116
NHSTUB(MoveFocusLensToDistance                ,0xffa7c844) //102
NHSTUB(MoveIrisWithAv                         ,0xffa233e4) //120
NHSTUB(MoveZoomLensWithPoint                  ,0xffa23968) //120
NHSTUB(Open                                   ,0xff823e2c) //120
NHSTUB(PB2Rec                                 ,0xff876538) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff85ba08) //120
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff85b9e0) //120
NHSTUB(PT_PlaySound                           ,0xff85b064) //102
NHSTUB(PostLogicalEventForNotPowerType        ,0xff872f04) //120
NHSTUB(PostLogicalEventToUI                   ,0xff872f50) //120
NHSTUB(Read                                   ,0xff81a15c) //120
NHSTUB(ReadFastDir                            ,0xffa0c13c) //  1
NHSTUB(Rec2PB                                 ,0xff876568) //104
NHSTUB(RefreshPhysicalScreen                  ,0xff9aabf8) //104
NHSTUB(RenameFile_Fut                         ,0xff8236ac) //  1
NHSTUB(Restart                                ,0xff829ea8) //122
NHSTUB(SetAE_ShutterSpeed                     ,0xffa7ef28) //102
NHSTUB(SetAutoShutdownTime                    ,0xff873908) //120
NHSTUB(SetCurrentCaptureModeType              ,0xff87a4b0) //120
NHSTUB(SetFileAttributes                      ,0xff824180) //  1
NHSTUB(SetFileTimeStamp                       ,0xff824130) //  1
NHSTUB(SetLogicalEventActive                  ,0xff873630) //  1
NHSTUB(SetParameterData                       ,0xff95b388) //101
NHSTUB(SetPropertyCase                        ,0xff86cc80) //102
NHSTUB(SetScriptMode                          ,0xff873680) //120
NHSTUB(SleepTask                              ,0xff8284b4) //120
NHSTUB(TakeSemaphore                          ,0xff81b774) //120
NHSTUB(TurnOffBackLight                       ,0xff87fd7c) //104
NHSTUB(TurnOnBackLight                        ,0xff87fd64) //104
NHSTUB(TurnOnDisplay                          ,0xff83e9cc) //120
NHSTUB(TurnOffDisplay                         ,0xff83e9dc) //120
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff94daa4) //120
NHSTUB(UnlockAE                               ,0xff82606c) //120
NHSTUB(UnlockAF                               ,0xff825c90) //120
NHSTUB(UnlockMainPower                        ,0xff8737e8) //120
NHSTUB(UnsetZoomForMovie                      ,0xff960a4c) //104
NHSTUB(UpdateMBROnFlash                       ,0xff84ef14) //105
NHSTUB(VbattGet                               ,0xff8207e4) //120
NHSTUB(Write                                  ,0xff823f00) //120
NHSTUB(WriteSDCard                            ,0xff91f0c8) //108
NHSTUB(_log                                   ,0xffaa6048) //111
NHSTUB(_log10                                 ,0xffaa4f8c) //112
NHSTUB(_pow                                   ,0xffaa50fc) //121
NHSTUB(_sqrt                                  ,0xffaa7468) //  1
NHSTUB(add_ptp_handler                        ,0xff9dab04) //121
NHSTUB(apex2us                                ,0xff9ac134) //121
NHSTUB(close                                  ,0xff819f74) //109
NHSTUB(err_init_task                          ,0xff814e98) //111
NHSTUB(exmem_alloc                            ,0xff867968) //103
NHSTUB(exmem_free                             ,0xff8679e0) //103
NHSTUB(free                                   ,0xff813a98) //112
NHSTUB(kbd_p1_f                               ,0xff822000) //109
NHSTUB(kbd_p1_f_cont                          ,0xff82200c) //109
NHSTUB(kbd_p2_f                               ,0xff821838) //109
NHSTUB(kbd_read_keys                          ,0xff821efc) //109
NHSTUB(kbd_read_keys_r2                       ,0xff8425e8) //109
NHSTUB(kbd_pwr_off                            ,0xff842a88) //  2
NHSTUB(kbd_pwr_on                             ,0xff842a38) //  2
NHSTUB(lseek                                  ,0xff823f94) //120
NHSTUB(malloc                                 ,0xff8139c4) //112
NHSTUB(memcmp                                 ,0xff81d90c) //120
NHSTUB(memcpy                                 ,0xff892234) //120
NHSTUB(memset                                 ,0xff9aafac) //120
NHSTUB(mkdir                                  ,0xff8241f8) //109
NHSTUB(mktime_ext                             ,0xff892aa0) //  1
NHSTUB(open                                   ,0xff819ec4) //109
NHSTUB(OpenFastDir                            ,0xffa0c0a8) //  1
NHSTUB(closedir                               ,0xffa0c20c) //  1
NHSTUB(qsort                                  ,0xff9ab4b4) //  1
NHSTUB(rand                                   ,0xff81da14) //121
NHSTUB(realloc                                ,0xff813b78) //115
NHSTUB(reboot_fw_update                       ,0xffa13b3c) //106
NHSTUB(set_control_event                      ,0xff873384) //  1
NHSTUB(srand                                  ,0xff81da08) //122
NHSTUB(stat                                   ,0xff824060) //  1
NHSTUB(strcat                                 ,0xff892020) //  1
NHSTUB(strchr                                 ,0xff8920a8) //  1
NHSTUB(strcmp                                 ,0xff81d8a4) //120
NHSTUB(strcpy                                 ,0xff81d88c) //120
NHSTUB(strftime                               ,0xff8924a8) //  1
NHSTUB(strlen                                 ,0xff81d8e8) //120
NHSTUB(strncmp                                ,0xff89205c) //  1
NHSTUB(strncpy                                ,0xff82e194) //  1
NHSTUB(strrchr                                ,0xff8920cc) //  1
NHSTUB(strtol                                 ,0xff82e3cc) //101
NHSTUB(strtolx                                ,0xff82e1d0) //109
   DEF(task_CaptSeq                           ,0xff85de08) //120
   DEF(task_DvlpSeqTask                       ,0xff93a9e4) //120
   DEF(task_ExpDrv                            ,0xff8b3d68) //120
   DEF(task_FileWrite                         ,0xffa08e84) //120
   DEF(task_InitFileModules                   ,0xff877140) //120
   DEF(task_MovieRecord                       ,0xff859e28) //120
   DEF(task_PhySw                             ,0xff821b94) //120
NHSTUB(time                                   ,0xff866d48) //109
NHSTUB(vsprintf                               ,0xff81d80c) //115
NHSTUB(EngDrvRead                             ,0xff822e40) //102
NHSTUB(PTM_GetCurrentItem                     ,0xff8741c8) //105
NHSTUB(CancelHPTimer                          ,0xff8686bc) //119
NHSTUB(SetHPTimerAfterNow                     ,0xff8685b4) //119
NHSTUB(PT_MFOn                                ,0xff85ba80) //120
NHSTUB(PT_MFOff                               ,0xff85ba90) //120
NHSTUB(GetAdChValue                           ,0xff84054c) //120
