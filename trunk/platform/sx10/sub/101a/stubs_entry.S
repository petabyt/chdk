// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R31 (DRYOS version 2.3, release #0031)
//   Firmware Ver GM1.01A
//   Canon PowerShot SX10 IS

// Values for makefile.inc
//   PLATFORMOSVER = 31
//   PLATFORMID = 12685 (0x318d) // Found @ 0xfffe0130
//   MAXRAMADDR = 0x03ffffff
//   KEYSYS = d4                 // Found @ 0xffff3570
//   NEED_ENCODED_DISKBOOT = 1   // Found @ 0xffff3580

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NHSTUB(kbd_pwr_off                          ,0xff84b810) //  2 60%    *** != 0x00000000
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff884bc8 -> ff881358 -> ff973e74 -> ffa79988 -> ffb74388
// Current modemap entry not found in firmware - MODE_VIDEO_STD            3622

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00011ec4) // Found @0xff821b14
DEF(physw_run                               ,0x00001c30) // Found @0xff821788
DEF(physw_sleep_delay                       ,0x00001c2e) // Found @0xff821788
DEF(levent_table                            ,0xffb4acc8) // Found @0xffb4acc8
DEF(FlashParamsTable                        ,0xffb7455c) // Found @0xffb7455c
DEF(movie_status                            ,0x00005430) // Found @0xff864304
DEF(canon_menu_active                       ,0x000058d8) // Found @0xff87a1ec
DEF(canon_shoot_menu_active                 ,0x0000ac29) // Found @0xff98cb24
DEF(playrec_mode                            ,0x00005640) // Found @0xff86d218
DEF(zoom_status                             ,0x0000e3e0) // Found @0xffa7b654
DEF(some_flag_for_af_scan                   ,0x00009b58) // Found @0xff94a2bc
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 1 int value, which is the the zoom focus length.
// there are 6 entries in the table - set NUM_FL to 6
DEF(focus_len_table                         ,0xffb77ce0) // Found @0xffb77ce0
DEF(zoom_busy                               ,0x00009100) // Found @0xff9407f0
DEF(focus_busy                              ,0x00008f8c) // Found @0xff939804
//DEF(recreview_hold                          ,0x0000645c) // Found @0xff88b560, ** != ** stubs_min = 0x0000a868 (0xA78C+0xDC)

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x403b1000; }             // Found @0xff846c28
//void *vid_get_viewport_fb()      { return (void*)0x4070d9d0; }             // Found @0xffad15ac
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x5260+0x58)); } // Found @0xff85c76c & 0xff85c7a4
//char *camera_jpeg_count_str()    { return (char*)0x0004c138; }             // Found @0xff9d284c
//long hook_raw_size()             { return 0x00ec04f0; }                    // Found @0xffad3a30
//int get_flash_params_count(void) { return 0x78; }                          // Found @0xff975474

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffb0ad5c, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x00040000 // Found @0xffb0ad68, levent 0x902
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_SHOOT_FULL      ,0x00000003 }, // Found @0xffb0abe8, levent 0x01
//    { 0, KEY_SHOOT_FULL_ONLY ,0x00000002 }, // Found @0xffb0abe8, levent 0x01
//    { 0, KEY_SHOOT_HALF      ,0x00000001 }, // Found @0xffb0abdc, levent 0x00
//    { 0, KEY_POWER           ,0x00002000 }, // Found @0xffb0abf4, levent 0x600
//    { 0, KEY_PLAYBACK        ,0x00004000 }, // Found @0xffb0ac00, levent 0x601
//    { 1, KEY_VIDEO           ,0x00000020 }, // Found @0xffb0ac60, levent 0x12
//    { 1, KEY_SET             ,0x00000100 }, // Found @0xffb0ac84, levent 0x08
//    { 1, KEY_DISPLAY         ,0x00000200 }, // Found @0xffb0ac90, levent 0x0a
//    { 1, KEY_UP              ,0x00000400 }, // Found @0xffb0ac9c, levent 0x04
//    { 1, KEY_DOWN            ,0x00000800 }, // Found @0xffb0aca8, levent 0x05
//    { 1, KEY_RIGHT           ,0x00001000 }, // Found @0xffb0acb4, levent 0x07
//    { 1, KEY_LEFT            ,0x00002000 }, // Found @0xffb0acc0, levent 0x06
//    { 1, KEY_MENU            ,0x00004000 }, // Found @0xffb0accc, levent 0x09
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_RAW_ROWPIX    3720 // Found @0xffaca170
//#define CAM_RAW_ROWS      2772 // Found @0xffaca178
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff828010

// Misc stuff
DEF(ctypes, 0xffb04666)

// For capt_seq.c
//static long *nrflag = (long*)(0x9b44-0x04);  // Found @ ff94c9b0 & ff94c9c8

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
//NHSTUB(CreateJumptable                      ,0xffad4390) //  1
//NHSTUB(_uartr_req                           ,0xff81c294) //111
//NHSTUB(AllocateMemory                       ,0xffa67af4) //101
NHSTUB(AllocateUncacheableMemory              ,0xff827fcc) //112
NHSTUB(Close                                  ,0xff823a64) //101
NHSTUB(CreateTask                             ,0xff81aef4) //101
NHSTUB(DebugAssert                            ,0xff81b1cc) //111
NHSTUB(DeleteDirectory_Fut                    ,0xff8233f4) //116
NHSTUB(DeleteFile_Fut                         ,0xff823310) //112
NHSTUB(DoAFLock                               ,0xff825864) //102
NHSTUB(EnterToCompensationEVF                 ,0xff825b10) //104
NHSTUB(ExecuteEventProcedure                  ,0xff8759f0) //104
NHSTUB(ExitFromCompensationEVF                ,0xff825b54) //104
NHSTUB(ExitTask                               ,0xff81b184) //101
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff8311d8) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff83131c) //104
NHSTUB(Fclose_Fut                             ,0xff82348c) //101
NHSTUB(Feof_Fut                               ,0xff823678) //  1
NHSTUB(Fflush_Fut                             ,0xff8236b4) //  1
NHSTUB(Fgets_Fut                              ,0xff8235e0) //  1
NHSTUB(Fopen_Fut                              ,0xff82344c) //101
NHSTUB(Fread_Fut                              ,0xff823538) //101
//NHSTUB(FreeMemory                           ,0xffa67aec) //101
NHSTUB(FreeUncacheableMemory                  ,0xff82800c) //112
NHSTUB(Fseek_Fut                              ,0xff82362c) //101
NHSTUB(Fwrite_Fut                             ,0xff82358c) //101
NHSTUB(GetBatteryTemperature                  ,0xff84e660) //102
NHSTUB(GetCCDTemperature                      ,0xff84e5f0) //102
NHSTUB(GetCurrentAvValue                      ,0xff93be84) //102
NHSTUB(GetDrive_ClusterSize                   ,0xff85ae98) //  1
NHSTUB(GetDrive_FreeClusters                  ,0xff85af00) //  1
NHSTUB(GetDrive_TotalClusters                 ,0xff85aecc) //  1
NHSTUB(GetFocusLensSubjectDistance            ,0xff93a30c) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff93a618) //  3
NHSTUB(GetKbdState                            ,0xff84b660) //109
NHSTUB(GetMemInfo                             ,0xff813c24) //115
NHSTUB(GetOpticalTemperature                  ,0xff84e6d0) //102
NHSTUB(GetParameterData                       ,0xff975434) //101
NHSTUB(GetPropertyCase                        ,0xff8796d8) //102
NHSTUB(GetSystemTime                          ,0xffa67b4c) //101
NHSTUB(GetVRAMHPixelsSize                     ,0xff83ccb4) //102
NHSTUB(GetVRAMVPixelsSize                     ,0xff83ccc0) //102
NHSTUB(GetZoomLensCurrentPoint                ,0xff941130) //102
NHSTUB(GetZoomLensCurrentPosition             ,0xffa5b24c) //102
NHSTUB(GiveSemaphore                          ,0xff8279e8) //112
NHSTUB(IsStrobeChargeCompleted                ,0xff8b6a00) //102
NHSTUB(LEDDrive                               ,0xff84ab48) //103
NHSTUB(LocalTime                              ,0xff87318c) //115
NHSTUB(LockMainPower                          ,0xff880f70) //103
//NHSTUB(Lseek                                ,0xff823ba4) //101
NHSTUB(MakeDirectory_Fut                      ,0xff823384) //116
NHSTUB(MoveFocusLensToDistance                ,0xffacd92c) //102
NHSTUB(MoveIrisWithAv                         ,0xffa63120) //102
NHSTUB(MoveZoomLensWithPoint                  ,0xffa63848) //102
//NHSTUB(NewTaskShell                         ,0xff879180) //103
NHSTUB(Open                                   ,0xff823a3c) //101
NHSTUB(PB2Rec                                 ,0xff883fd8) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff86608c) //102
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff866064) //102
NHSTUB(PT_PlaySound                           ,0xff8659dc) //102
NHSTUB(PostLogicalEventForNotPowerType        ,0xff87ec9c) //103
NHSTUB(PostLogicalEventToUI                   ,0xff87ece8) //103
NHSTUB(PutInNdFilter                          ,0xffa636cc) //102
NHSTUB(PutOutNdFilter                         ,0xffa636f0) //102
NHSTUB(Read                                   ,0xff819a4c) //101
NHSTUB(ReadFastDir                            ,0xffa49124) //  1
NHSTUB(Rec2PB                                 ,0xff882960) //104
NHSTUB(RefreshPhysicalScreen                  ,0xff9df040) //104
//NHSTUB(Remove                               ,0xff823aac) //  1
NHSTUB(RenameFile_Fut                         ,0xff8232bc) //  1
NHSTUB(Restart                                ,0xff829848) //106
NHSTUB(SetAE_ShutterSpeed                     ,0xffad07bc) //102
NHSTUB(SetAutoShutdownTime                    ,0xff880fe4) //103
NHSTUB(SetCurrentCaptureModeType              ,0xff8886b4) //101
NHSTUB(SetFileAttributes                      ,0xff823d90) //  1
NHSTUB(SetFileTimeStamp                       ,0xff823d40) //  1
NHSTUB(SetLogicalEventActive                  ,0xff880c30) //101
NHSTUB(SetParameterData                       ,0xff975310) //101
NHSTUB(SetPropertyCase                        ,0xff8795d0) //102
NHSTUB(SetScriptMode                          ,0xff880c80) //101
NHSTUB(SleepTask                              ,0xff827c50) //101
NHSTUB(TakeSemaphore                          ,0xff827918) //101
NHSTUB(TurnOffBackLight                       ,0xff88f28c) //104
NHSTUB(TurnOnBackLight                        ,0xff88f274) //104
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff963744) //103
NHSTUB(UnlockAF                               ,0xff82589c) //102
NHSTUB(UnlockMainPower                        ,0xff880ec4) //103
NHSTUB(UpdateMBROnFlash                       ,0xff85acd8) //105
NHSTUB(VbattGet                               ,0xff82046c) //103
NHSTUB(Write                                  ,0xff823b10) //101
NHSTUB(WriteSDCard                            ,0xff92a9a4) //108
NHSTUB(_log                                   ,0xffb018e4) //111
NHSTUB(_log10                                 ,0xffb00570) //112
NHSTUB(_pow                                   ,0xffb006e0) //114
NHSTUB(_sqrt                                  ,0xffb03540) //  1
NHSTUB(add_ptp_handler                        ,0xffa1727c) //  3
NHSTUB(apex2us                                ,0xff9e0128) //  4
NHSTUB(close                                  ,0xff819864) //  1
NHSTUB(closedir                               ,0xffa491f4) //  1
NHSTUB(err_init_task                          ,0xff814e80) //111
NHSTUB(exmem_alloc                            ,0xff8740cc) //103
NHSTUB(exmem_free                             ,0xff874144) //103
NHSTUB(free                                   ,0xff813a7c) //112
NHSTUB(kbd_p1_f                               ,0xff821c10) //109
NHSTUB(kbd_p1_f_cont                          ,0xff821c1c) //109
NHSTUB(kbd_p2_f                               ,0xff821428) //109
NHSTUB(kbd_read_keys                          ,0xff821b14) //109
NHSTUB(kbd_read_keys_r2                       ,0xff84af6c) //109
NHSTUB(lseek                                  ,0xff823ba4) //101
NHSTUB(malloc                                 ,0xff8139a8) //112
NHSTUB(memcmp                                 ,0xff81cba4) //101
NHSTUB(memcpy                                 ,0xff89ba88) //101
NHSTUB(memset                                 ,0xff9df460) //101
NHSTUB(mkdir                                  ,0xff823e08) //109
NHSTUB(mktime_ext                             ,0xff89c2f4) //  1
NHSTUB(open                                   ,0xff8197b4) //  1
NHSTUB(OpenFastDir                            ,0xffa49090) //  1
NHSTUB(qsort                                  ,0xffab815c) //  1
NHSTUB(rand                                   ,0xff81ccac) //  1
//NHSTUB(read                                 ,0xff819a4c) //101
NHSTUB(realloc                                ,0xff813b5c) //115
NHSTUB(reboot_fw_update                       ,0xffa50b24) //106
NHSTUB(set_control_event                      ,0xff88088c) //111
NHSTUB(srand                                  ,0xff81cca0) //  1
NHSTUB(stat                                   ,0xff823c70) //  1
NHSTUB(strcat                                 ,0xff89b89c) //  1
NHSTUB(strchr                                 ,0xff89b924) //  1
NHSTUB(strcmp                                 ,0xff81cb3c) //101
NHSTUB(strcpy                                 ,0xff81cb24) //101
NHSTUB(strftime                               ,0xff89bcfc) //  1
NHSTUB(strlen                                 ,0xff81cb80) //101
NHSTUB(strncmp                                ,0xff89b8d8) //  1
NHSTUB(strncpy                                ,0xff82db14) //  1
NHSTUB(strrchr                                ,0xff9df438) //  1
NHSTUB(strtol                                 ,0xff82dd4c) //101
NHSTUB(strtolx                                ,0xff82db50) //109
   DEF(task_CaptSeq                           ,0xff868b98) //107
   DEF(task_ExpDrv                            ,0xff8ad7cc) //110
   DEF(task_InitFileModules                   ,0xff884a54) //107
   DEF(task_MovieRecord                       ,0xff86458c) //107
   DEF(task_PhySw                             ,0xff821784) //107
NHSTUB(time                                   ,0xff87376c) //109
NHSTUB(vsprintf                               ,0xff81cae8) //115
//NHSTUB(write                                ,0xff823b10) //101
NHSTUB(EngDrvIn                               ,0xffa2a314) //102
NHSTUB(EngDrvOut                              ,0xffa2a2f8) //102
NHSTUB(EngDrvRead                             ,0xffa2a31c) //102
NHSTUB(EngDrvBits                             ,0xffa2a324) //102
//NHSTUB(GetSDProtect                         ,0xff821aec) //103
//NHSTUB(StartRecModeMenu                     ,0xff87a1e8) //102
//NHSTUB(DispCon_ShowBitmapColorBar           ,0xff846bf4) //102
//NHSTUB(ResetZoomLens                        ,0xffa6379c) //102
//NHSTUB(ResetFocusLens                       ,0xffa62664) //102
//NHSTUB(NR_GetDarkSubType                    ,0xff94dddc) //102
//NHSTUB(NR_SetDarkSubType                    ,0xff94dd30) //102
//NHSTUB(SavePaletteData                      ,0xffad2898) //102
