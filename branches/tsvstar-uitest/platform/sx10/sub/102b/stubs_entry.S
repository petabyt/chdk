// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R31 (DRYOS version 2.3, release #0031)
//   Firmware Ver GM1.02B
//   Canon PowerShot SX10 IS

// Values for makefile.inc
//   PLATFORMOSVER = 31
//   PLATFORMID = 12685 (0x318d) // Found @ 0xfffe0130
//   MAXRAMADDR = 0x03ffffff
//   KEYSYS = d4                 // Found @ 0xffff3570
//   NEED_ENCODED_DISKBOOT = 1   // Found @ 0xffff3580

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NSTUB(kbd_pwr_off                           ,0xff84b810) //  2 60%    *** != 0x00000000
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff884c68 -> ff8813f8 -> ff973f14 -> ffa79ab4 -> ffb744e0
// Current modemap entry not found in firmware - MODE_VIDEO_STD            3622

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00011ec4) // Found @0xff821b14
DEF(physw_run                               ,0x00001c30) // Found @0xff821788
DEF(physw_sleep_delay                       ,0x00001c2e) // Found @0xff821788
DEF(levent_table                            ,0xffb4ae24) // Found @0xffb4ae24
DEF(FlashParamsTable                        ,0xffb746b4) // Found @0xffb746b4
DEF(movie_status                            ,0x00005430) // Found @0xff8643a8
DEF(canon_menu_active                       ,0x000058d8) // Found @0xff87a28c
DEF(canon_shoot_menu_active                 ,0x0000ac29) // Found @0xff98cbc4
DEF(playrec_mode                            ,0x00005640) // Found @0xff86d2b8
DEF(zoom_status                             ,0x0000e3ec) // Found @0xffa7b780
DEF(some_flag_for_af_scan                   ,0x00009b58) // Found @0xff94a35c
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 1 int value, which is the the zoom focus length.
// there are 6 entries in the table - set NUM_FL to 6
DEF(focus_len_table                         ,0xffb77e38) // Found @0xffb77e38
DEF(zoom_busy                               ,0x00009100) // Found @0xff940890
DEF(focus_busy                              ,0x00008f8c) // Found @0xff9398a4
//DEF(recreview_hold                          ,0x0000645c) // Found @0xff88b600, ** != ** stubs_min = 0x0000a868 (0xA78C+0xDC)

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x403b1000; }             // Found @0xff846c28
//void *vid_get_viewport_fb()      { return (void*)0x4070d9d0; }             // Found @0xffad16d8
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x5260+0x58)); } // Found @0xff85c76c & 0xff85c7a4
//char *camera_jpeg_count_str()    { return (char*)0x0004c138; }             // Found @0xff9d28ec
//long hook_raw_size()             { return 0x00ec04f0; }                    // Found @0xffad3b5c
//int get_flash_params_count(void) { return 0x78; }                          // Found @0xff975514

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffb0aeb8, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x00040000 // Found @0xffb0aec4, levent 0x902
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_SHOOT_FULL      ,0x00000003 }, // Found @0xffb0ad44, levent 0x01
//    { 0, KEY_SHOOT_FULL_ONLY ,0x00000002 }, // Found @0xffb0ad44, levent 0x01
//    { 0, KEY_SHOOT_HALF      ,0x00000001 }, // Found @0xffb0ad38, levent 0x00
//    { 0, KEY_POWER           ,0x00002000 }, // Found @0xffb0ad50, levent 0x600
//    { 0, KEY_PLAYBACK        ,0x00004000 }, // Found @0xffb0ad5c, levent 0x601
//    { 1, KEY_SET             ,0x00000100 }, // Found @0xffb0ade0, levent 0x08
//    { 1, KEY_DISPLAY         ,0x00000200 }, // Found @0xffb0adec, levent 0x0a
//    { 1, KEY_UP              ,0x00000400 }, // Found @0xffb0adf8, levent 0x04
//    { 1, KEY_DOWN            ,0x00000800 }, // Found @0xffb0ae04, levent 0x05
//    { 1, KEY_RIGHT           ,0x00001000 }, // Found @0xffb0ae10, levent 0x07
//    { 1, KEY_LEFT            ,0x00002000 }, // Found @0xffb0ae1c, levent 0x06
//    { 1, KEY_MENU            ,0x00004000 }, // Found @0xffb0ae28, levent 0x09
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_RAW_ROWPIX    3720 // Found @0xffaca29c
//#define CAM_RAW_ROWS      2772 // Found @0xffaca2a4
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff828010

// Misc stuff
DEF(ctypes, 0xffb047c2)

// For capt_seq.c
//static long *nrflag = (long*)(0x9b44-0x04);  // Found @ ff94ca50 & ff94ca68

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NSTUB(AllocateMemory                          ,0xffa67c20) //101
NSTUB(AllocateUncacheableMemory               ,0xff827fcc) //112
NSTUB(Close                                   ,0xff823a64) //101
NSTUB(CreateTask                              ,0xff81aef4) //101
NSTUB(DebugAssert                             ,0xff81b1cc) //111
NSTUB(DeleteDirectory_Fut                     ,0xff8233f4) //  1
NSTUB(DeleteFile_Fut                          ,0xff823310) //112
NSTUB(DoAFLock                                ,0xff825864) //102
NSTUB(EnterToCompensationEVF                  ,0xff825b10) //104
NSTUB(ExecuteEventProcedure                   ,0xff875a90) //  1
NSTUB(ExitFromCompensationEVF                 ,0xff825b54) //104
NSTUB(ExitTask                                ,0xff81b184) //101
NSTUB(ExpCtrlTool_StartContiAE                ,0xff8311d8) //104
NSTUB(ExpCtrlTool_StopContiAE                 ,0xff83131c) //104
NSTUB(Fclose_Fut                              ,0xff82348c) //101
NSTUB(Feof_Fut                                ,0xff823678) //  1
NSTUB(Fflush_Fut                              ,0xff8236b4) //  1
NSTUB(Fgets_Fut                               ,0xff8235e0) //  1
NSTUB(Fopen_Fut                               ,0xff82344c) //101
NSTUB(Fread_Fut                               ,0xff823538) //101
NSTUB(FreeMemory                              ,0xffa67c18) //101
NSTUB(FreeUncacheableMemory                   ,0xff82800c) //112
NSTUB(Fseek_Fut                               ,0xff82362c) //101
NSTUB(Fwrite_Fut                              ,0xff82358c) //101
NSTUB(GetBatteryTemperature                   ,0xff84e660) //102
NSTUB(GetCCDTemperature                       ,0xff84e5f0) //102
NSTUB(GetCurrentAvValue                       ,0xff93bf24) //102
NSTUB(GetDrive_ClusterSize                    ,0xff85ae98) //  1
NSTUB(GetDrive_FreeClusters                   ,0xff85af00) //  1
NSTUB(GetDrive_TotalClusters                  ,0xff85aecc) //  1
NSTUB(GetFocusLensSubjectDistance             ,0xff93a3ac) //102
NSTUB(GetFocusLensSubjectDistanceFromLens     ,0xff93a6b8) //  3
NSTUB(GetKbdState                             ,0xff84b660) //109
NSTUB(GetMemInfo                              ,0xff813c24) //  1
NSTUB(GetOpticalTemperature                   ,0xff84e6d0) //102
NSTUB(GetParameterData                        ,0xff9754d4) //101
NSTUB(GetPropertyCase                         ,0xff879778) //102
NSTUB(GetSystemTime                           ,0xffa67c78) //101
NSTUB(GetVRAMHPixelsSize                      ,0xff83ccb4) //102
NSTUB(GetVRAMVPixelsSize                      ,0xff83ccc0) //102
NSTUB(GetZoomLensCurrentPoint                 ,0xff9411d0) //102
NSTUB(GetZoomLensCurrentPosition              ,0xffa5b350) //102
NSTUB(GiveSemaphore                           ,0xff8279e8) //112
NSTUB(IsStrobeChargeCompleted                 ,0xff8b6aa0) //102
NSTUB(LEDDrive                                ,0xff84ab48) //103
NSTUB(LocalTime                               ,0xff87322c) //  1
NSTUB(LockMainPower                           ,0xff881010) //103
NSTUB(Lseek                                   ,0xff823ba4) //101
NSTUB(MakeDirectory_Fut                       ,0xff823384) //  1
NSTUB(MoveFocusLensToDistance                 ,0xffacda58) //102
NSTUB(MoveIrisWithAv                          ,0xffa6324c) //102
NSTUB(MoveZoomLensWithPoint                   ,0xffa63974) //102
NSTUB(NewTaskShell                            ,0xff879220) //103
NSTUB(Open                                    ,0xff823a3c) //101
NSTUB(PB2Rec                                  ,0xff884078) //104
NSTUB(PT_MoveDigitalZoomToWide                ,0xff86612c) //102
NSTUB(PT_MoveOpticalZoomAt                    ,0xff866104) //102
NSTUB(PT_PlaySound                            ,0xff865a7c) //102
NSTUB(PostLogicalEventForNotPowerType         ,0xff87ed3c) //103
NSTUB(PostLogicalEventToUI                    ,0xff87ed88) //103
NSTUB(PutInNdFilter                           ,0xffa637f8) //102
NSTUB(PutOutNdFilter                          ,0xffa6381c) //102
NSTUB(Read                                    ,0xff819a4c) //101
NSTUB(ReadFastDir                             ,0xffa491c4) //  1
NSTUB(Rec2PB                                  ,0xff882a00) //104
NSTUB(RefreshPhysicalScreen                   ,0xff9df0e0) //104
NSTUB(Remove                                  ,0xff823aac) //  1
NSTUB(RenameFile_Fut                          ,0xff8232bc) //  1
NSTUB(Restart                                 ,0xff829848) //106
NSTUB(SetAE_ShutterSpeed                      ,0xffad08e8) //102
NSTUB(SetAutoShutdownTime                     ,0xff881084) //103
NSTUB(SetCurrentCaptureModeType               ,0xff888754) //101
NSTUB(SetFileAttributes                       ,0xff823d90) //  1
NSTUB(SetFileTimeStamp                        ,0xff823d40) //  1
NSTUB(SetLogicalEventActive                   ,0xff880cd0) //101
NSTUB(SetParameterData                        ,0xff9753b0) //101
NSTUB(SetPropertyCase                         ,0xff879670) //102
NSTUB(SetScriptMode                           ,0xff880d20) //101
NSTUB(SleepTask                               ,0xff827c50) //101
NSTUB(TakeSemaphore                           ,0xff827918) //101
NSTUB(TurnOffBackLight                        ,0xff88f32c) //104
NSTUB(TurnOnBackLight                         ,0xff88f314) //104
NSTUB(UIFS_WriteFirmInfoToFile                ,0xff9637e4) //103
NSTUB(UnlockAF                                ,0xff82589c) //102
NSTUB(UnlockMainPower                         ,0xff880f64) //103
NSTUB(UpdateMBROnFlash                        ,0xff85acd8) //105
NSTUB(VbattGet                                ,0xff82046c) //103
NSTUB(Write                                   ,0xff823b10) //101
NSTUB(WriteSDCard                             ,0xff92aa44) //108
NSTUB(_log                                    ,0xffb01a40) //111
NSTUB(_log10                                  ,0xffb006cc) //112
NSTUB(_pow                                    ,0xffb0083c) //114
NSTUB(_sqrt                                   ,0xffb0369c) //  1
NSTUB(add_ptp_handler                         ,0xffa1731c) //  3
NSTUB(apex2us                                 ,0xff9e01c8) //  4
NSTUB(close                                   ,0xff819864) //  1
NSTUB(closedir                                ,0xffa49294) //  1
NSTUB(err_init_task                           ,0xff814e80) //  4
NSTUB(exmem_alloc                             ,0xff87416c) //103
NSTUB(free                                    ,0xff813a7c) //112
NSTUB(kbd_p1_f                                ,0xff821c10) //109
NSTUB(kbd_p1_f_cont                           ,0xff821c1c) //109
NSTUB(kbd_p2_f                                ,0xff821428) //109
NSTUB(kbd_read_keys                           ,0xff821b14) //109
NSTUB(kbd_read_keys_r2                        ,0xff84af6c) //109
NSTUB(lseek                                   ,0xff823ba4) //101
NSTUB(malloc                                  ,0xff8139a8) //112
NSTUB(memcmp                                  ,0xff81cba4) //101
NSTUB(memcpy                                  ,0xff89bb28) //101
NSTUB(memset                                  ,0xff9df500) //101
NSTUB(mkdir                                   ,0xff823e08) //  1
// ALT: NSTUB(mkdir, 0xff823ea8) // 1 32/0
NSTUB(mktime_ext                              ,0xff89c394) //  1
NSTUB(open                                    ,0xff8197b4) //  1
NSTUB(opendir                                 ,0xffa49130) //  1
NSTUB(openfastdir                             ,0xffa49130) //  1
NSTUB(qsort                                   ,0xffab8288) //  1
NSTUB(rand                                    ,0xff81ccac) //  1
NSTUB(read                                    ,0xff819a4c) //101
NSTUB(reboot_fw_update                        ,0xffa50bc4) //  5
NSTUB(rename                                  ,0xff8232bc) //  1
NSTUB(set_control_event                       ,0xff88092c) //111
NSTUB(srand                                   ,0xff81cca0) //  1
NSTUB(stat                                    ,0xff823c70) //  1
NSTUB(strcat                                  ,0xff89b93c) //  1
NSTUB(strchr                                  ,0xff89b9c4) //  1
NSTUB(strcmp                                  ,0xff81cb3c) //101
NSTUB(strcpy                                  ,0xff81cb24) //101
NSTUB(strftime                                ,0xff89bd9c) //  1
NSTUB(strlen                                  ,0xff81cb80) //101
NSTUB(strncmp                                 ,0xff89b978) //  1
NSTUB(strncpy                                 ,0xff82db14) //  1
NSTUB(strrchr                                 ,0xff9df4d8) //  1
NSTUB(strtol                                  ,0xff82dd4c) //101
NSTUB(strtolx                                 ,0xff82db50) //109
  DEF(task_CaptSeq                            ,0xff868c38) //107
  DEF(task_ExpDrv                             ,0xff8ad86c) //110
  DEF(task_InitFileModules                    ,0xff884af4) //107
  DEF(task_MovieRecord                        ,0xff864630) //107
  DEF(task_PhySw                              ,0xff821784) //107
NSTUB(time                                    ,0xff87380c) //  2
NSTUB(vsprintf                                ,0xff81cae8) //  1
NSTUB(write                                   ,0xff823b10) //101
