// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R23 (DRYOS version 2.3, release #0023)
//   Firmware Ver GM1.01A
//   Canon DIGITAL IXUS 80 IS

// Values for makefile.inc
//   PLATFORMID = 12676 (0x3184) // Found @ 0xfffe0130
//   MAXRAMADDR = 0x01ffffff
//   KEYSYS = d3enc              // Found @ 0xffff3308
//   NEED_ENCODED_DISKBOOT = 1   // Found @ 0xffff32e8

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NSTUB(ExpCtrlTool_StartContiAE              ,0xff832a98) //104        *** != 0x00000000
//NSTUB(ExpCtrlTool_StopContiAE               ,0xff832bdc) //104        *** != 0x00000000
//NSTUB(PutInNdFilter                         ,0xffa237c8) //102        *** != 0xffa7aacc
//NSTUB(PutOutNdFilter                        ,0xffa237ec) //102        *** != 0xffa7ab04

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff8772b4 -> ff873c7c -> ff95a39c -> ffa37720 -> ffaede88
// Mode  2598 in firmware but not in current modemap
// Mode  2603 in firmware but not in current modemap

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00010370) // Found @0xff821efc
DEF(physw_run                               ,0x00001c00) // Found @0xff821b98
DEF(levent_table                            ,0xffacac68) // Found @0xffacac68
//DEF(FlashParamsTable                        ,0xffaee048) // Found @0xffaee048, ** != ** stubs_min = 0xffaee050 (0xffaee050)
//DEF(movie_status                            ,0x000053a4) // Found @0xff859b9c, ** != ** stubs_min = 0x000053b4 (0x53b4)
DEF(canon_menu_active                       ,0x000094e8) // Found @0xff94cb3c
DEF(canon_shoot_menu_active                 ,0x00009e2d) // Found @0xff969e40
DEF(playrec_mode                            ,0x00005534) // Found @0xff860ee8
DEF(zoom_status                             ,0x0000d1cc) // Found @0xffa38f20
DEF(some_flag_for_af_scan                   ,0x0000cf50) // Found @0xffa24140
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 3 int value(s), the first is the zoom focus length.
// there are 7 entries in the table - set NUM_FL to 7
DEF(focus_len_table                         ,0xfffe297c) // Found @0xfffe297c
DEF(zoom_busy                               ,0x000085f0) // Found @0xff92ee60
//DEF(focus_busy                              ,0x000084fc) // Found @0xff92aa0c, ** != ** stubs_min = 0x00008578 (0x8578)
//DEF(recreview_hold                          ,0x00005dc4) // Found @0xff87ccf8, ** != ** stubs_min = 0x00009c0c (0x9c0c)

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x10361000; }             // Found @0xff83e91c
//void *vid_get_viewport_fb()      { return (void*)0x1065ade0; }             // Found @0xffa7fd14
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x51d4+0x50)); } // Found @0xff852e8c & 0xff852ec4
//char *camera_jpeg_count_str()    { return (char*)0x0004c2c4; }             // Found @0xff9a0e30
//long hook_raw_size()             { return 0x009dcce0; }                    // Found @0xffa81f84
//int get_flash_params_count(void) { return 0x73; }                          // Found @0xff95b458

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffaa8a98, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x00040000 // Found @0xffaa8aa4, levent 0x902
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 2, KEY_ZOOM_IN         ,0x00000004 }, // Found @0xffaa8a08, levent 0x02
//    { 2, KEY_ZOOM_OUT        ,0x00000008 }, // Found @0xffaa8a14, levent 0x03
//    { 2, KEY_LEFT            ,0x00000010 }, // Found @0xffaa8a20, levent 0x06
//    { 2, KEY_RIGHT           ,0x00000020 }, // Found @0xffaa8a2c, levent 0x07
//    { 2, KEY_DOWN            ,0x00000040 }, // Found @0xffaa8a38, levent 0x05
//    { 2, KEY_UP              ,0x00000080 }, // Found @0xffaa8a44, levent 0x04
//    { 2, KEY_SET             ,0x00000100 }, // Found @0xffaa8a50, levent 0x08
//    { 2, KEY_DISPLAY         ,0x00000200 }, // Found @0xffaa8a5c, levent 0x0a
//    { 2, KEY_SHOOT_FULL      ,0x00000003 }, // Found @0xffaa89fc, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000002 }, // Found @0xffaa89fc, levent 0x01
//    { 2, KEY_MENU            ,0x00000400 }, // Found @0xffaa8a68, levent 0x09
//    { 2, KEY_SHOOT_HALF      ,0x00000001 }, // Found @0xffaa89f0, levent 0x00
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_RAW_ROWPIX    3336 // Found @0xffa7963c
//#define CAM_RAW_ROWS      2480 // Found @0xffa79644
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x10000000 // Found @0xff82866c

// Misc stuff
DEF(ctypes, 0xffaa858a)

// For capt_seq.c
//static long *nrflag = (long*)(0x8d14);       // Found @ ff939e90

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NSTUB(AllocateMemory                          ,0xffa26fe8) //101
NSTUB(AllocateUncacheableMemory               ,0xff828630) //112
NSTUB(Close                                   ,0xff823e54) //101
NSTUB(CreateTask                              ,0xff81b8e0) //101
NSTUB(DebugAssert                             ,0xff81bdb8) //111
NSTUB(DeleteDirectory_Fut                     ,0xff8237e4) //  1
NSTUB(DeleteFile_Fut                          ,0xff823700) //112
NSTUB(DoAFLock                                ,0xff825c4c) //102
NSTUB(EnterToCompensationEVF                  ,0xff825f48) //104
NSTUB(ExecuteEventProcedure                   ,0xff869180) //  1
NSTUB(ExitFromCompensationEVF                 ,0xff825f98) //104
NSTUB(ExitTask                                ,0xff81bb70) //101
NSTUB(Fclose_Fut                              ,0xff82387c) //101
NSTUB(Feof_Fut                                ,0xff823a68) //  1
NSTUB(Fflush_Fut                              ,0xff823aa4) //  1
NSTUB(Fgets_Fut                               ,0xff8239d0) //  1
NSTUB(Fopen_Fut                               ,0xff82383c) //101
NSTUB(Fread_Fut                               ,0xff823928) //101
NSTUB(FreeMemory                              ,0xffa26fe0) //101
NSTUB(FreeUncacheableMemory                   ,0xff828664) //112
NSTUB(Fseek_Fut                               ,0xff823a1c) //101
NSTUB(Fwrite_Fut                              ,0xff82397c) //101
NSTUB(GetBatteryTemperature                   ,0xff845214) //102
NSTUB(GetCCDTemperature                       ,0xff8451a4) //102
NSTUB(GetCurrentAvValue                       ,0xff92c420) //102
NSTUB(GetDrive_ClusterSize                    ,0xff84f0d4) //  1
NSTUB(GetDrive_FreeClusters                   ,0xff84f13c) //  1
NSTUB(GetDrive_TotalClusters                  ,0xff84f108) //  1
NSTUB(GetFocusLensSubjectDistance             ,0xff92b518) //102
NSTUB(GetFocusLensSubjectDistanceFromLens     ,0xff92b824) //  1
NSTUB(GetKbdState                             ,0xff842a04) //109
NSTUB(GetMemInfo                              ,0xff813c40) //  1
NSTUB(GetOpticalTemperature                   ,0xff845284) //102
NSTUB(GetParameterData                        ,0xff95b418) //101
NSTUB(GetPropertyCase                         ,0xff86cd80) //102
NSTUB(GetSystemTime                           ,0xffa27040) //101
NSTUB(GetZoomLensCurrentPoint                 ,0xff92f1c4) //102
NSTUB(GetZoomLensCurrentPosition              ,0xffa1d080) //102
NSTUB(GiveSemaphore                           ,0xff81b844) //112
NSTUB(IsStrobeChargeCompleted                 ,0xff8bae5c) //102
NSTUB(LEDDrive                                ,0xff842228) //103
NSTUB(LocalTime                               ,0xff866844) //  1
NSTUB(LockMainPower                           ,0xff873894) //103
NSTUB(Lseek                                   ,0xff823f94) //101
NSTUB(MakeDirectory_Fut                       ,0xff823774) //  1
NSTUB(MoveFocusLensToDistance                 ,0xffa7c840) //102
NSTUB(MoveIrisWithAv                          ,0xffa233e0) //102
NSTUB(MoveZoomLensWithPoint                   ,0xffa23964) //102
NSTUB(NewTaskShell                            ,0xff86c844) //103
NSTUB(Open                                    ,0xff823e2c) //101
NSTUB(PB2Rec                                  ,0xff876538) //104
NSTUB(PT_MoveDigitalZoomToWide                ,0xff85ba08) //102
NSTUB(PT_MoveOpticalZoomAt                    ,0xff85b9e0) //102
NSTUB(PT_PlaySound                            ,0xff85b064) //102
NSTUB(PostLogicalEventForNotPowerType         ,0xff872f04) //103
NSTUB(PostLogicalEventToUI                    ,0xff872f50) //103
NSTUB(Read                                    ,0xff81a15c) //101
NSTUB(ReadFastDir                             ,0xffa0c138) //  1
NSTUB(Rec2PB                                  ,0xff876568) //104
NSTUB(RefreshPhysicalScreen                   ,0xff9aabf8) //104
NSTUB(Remove                                  ,0xff823e9c) //  1
NSTUB(RenameFile_Fut                          ,0xff8236ac) //  1
NSTUB(Restart                                 ,0xff829ea8) //106
NSTUB(SetAE_ShutterSpeed                      ,0xffa7ef24) //102
NSTUB(SetAutoShutdownTime                     ,0xff873908) //103
NSTUB(SetCurrentCaptureModeType               ,0xff87a4b0) //101
NSTUB(SetFileAttributes                       ,0xff824180) //  1
NSTUB(SetFileTimeStamp                        ,0xff824130) //  1
NSTUB(SetLogicalEventActive                   ,0xff873630) //  1
NSTUB(SetParameterData                        ,0xff95b388) //101
NSTUB(SetPropertyCase                         ,0xff86cc80) //102
NSTUB(SetScriptMode                           ,0xff873680) //101
NSTUB(SleepTask                               ,0xff8284b4) //101
NSTUB(TakeSemaphore                           ,0xff81b774) //101
NSTUB(TurnOffBackLight                        ,0xff87fd7c) //104
NSTUB(TurnOnBackLight                         ,0xff87fd64) //104
NSTUB(UIFS_WriteFirmInfoToFile                ,0xff94daa4) //103
NSTUB(UnlockAF                                ,0xff825c90) //102
NSTUB(UnlockMainPower                         ,0xff8737e8) //103
NSTUB(UnsetZoomForMovie                       ,0xff960a4c) //104
NSTUB(UpdateMBROnFlash                        ,0xff84ef14) //105
NSTUB(VbattGet                                ,0xff8207e4) //103
NSTUB(Write                                   ,0xff823f00) //101
NSTUB(WriteSDCard                             ,0xff91f0c8) //108
NSTUB(_log                                    ,0xffaa6044) //111
NSTUB(_log10                                  ,0xffaa4f88) //112
NSTUB(_pow                                    ,0xffaa50f8) //114
NSTUB(_sqrt                                   ,0xffaa7464) //  1
NSTUB(add_ptp_handler                         ,0xff9dab00) //  1
NSTUB(apex2us                                 ,0xff9ac134) //  4
NSTUB(close                                   ,0xff819f74) //  1
NSTUB(closedir                                ,0xffa0c208) //  1
NSTUB(err_init_task                           ,0xff814e98) //  4
NSTUB(exmem_alloc                             ,0xff867968) //103
NSTUB(free                                    ,0xff813a98) //112
NSTUB(kbd_p1_f                                ,0xff822000) //109
NSTUB(kbd_p1_f_cont                           ,0xff82200c) //109
NSTUB(kbd_p2_f                                ,0xff821838) //109
NSTUB(kbd_pwr_off                             ,0xff842a88) //  2
NSTUB(kbd_pwr_on                              ,0xff842a38) //  2
NSTUB(kbd_read_keys                           ,0xff821efc) //109
NSTUB(kbd_read_keys_r2                        ,0xff8425e8) //109
NSTUB(lseek                                   ,0xff823f94) //101
NSTUB(malloc                                  ,0xff8139c4) //112
NSTUB(memcmp                                  ,0xff81d90c) //101
NSTUB(memcpy                                  ,0xff892234) //101
NSTUB(memset                                  ,0xff9aafac) //101
NSTUB(mkdir                                   ,0xff8241f8) //  1
// ALT: NSTUB(mkdir, 0xff824298) // 1 32/0
NSTUB(mktime_ext                              ,0xff892aa0) //  1
NSTUB(open                                    ,0xff819ec4) //  1
NSTUB(opendir                                 ,0xffa0c0a4) //  1
NSTUB(openfastdir                             ,0xffa0c0a4) //  1
NSTUB(qsort                                   ,0xff9ab4b4) //  1
NSTUB(rand                                    ,0xff81da14) //  1
NSTUB(read                                    ,0xff81a15c) //101
NSTUB(reboot_fw_update                        ,0xffa13b38) //  5
NSTUB(rename                                  ,0xff8236ac) //  1
NSTUB(set_control_event                       ,0xff873384) //  1
NSTUB(srand                                   ,0xff81da08) //  1
NSTUB(stat                                    ,0xff824060) //  1
NSTUB(strcat                                  ,0xff892020) //  1
NSTUB(strchr                                  ,0xff8920a8) //  1
NSTUB(strcmp                                  ,0xff81d8a4) //101
NSTUB(strcpy                                  ,0xff81d88c) //101
NSTUB(strftime                                ,0xff8924a8) //  1
NSTUB(strlen                                  ,0xff81d8e8) //101
NSTUB(strncmp                                 ,0xff89205c) //  1
NSTUB(strncpy                                 ,0xff82e194) //  1
NSTUB(strrchr                                 ,0xff8920cc) //  1
NSTUB(strtol                                  ,0xff82e3cc) //101
NSTUB(strtolx                                 ,0xff82e1d0) //109
  DEF(task_CaptSeq                            ,0xff85de08) //107
  DEF(task_ExpDrv                             ,0xff8b3d68) //110
  DEF(task_InitFileModules                    ,0xff877140) //107
  DEF(task_MovieRecord                        ,0xff859e28) //107
  DEF(task_PhySw                              ,0xff821b94) //107
NSTUB(time                                    ,0xff866d48) //  2
NSTUB(vsprintf                                ,0xff81d80c) //  1
NSTUB(write                                   ,0xff823f00) //101
