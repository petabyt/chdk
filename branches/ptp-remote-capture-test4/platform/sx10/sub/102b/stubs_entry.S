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
//NHSTUB(kbd_pwr_off                          ,0xff84b810) //  2 60%    *** != 0x00000000
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
//    { 1, KEY_VIDEO           ,0x00000020 }, // Found @0xffb0adbc, levent 0x12
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
DEF(_nrflag,0x9b40) // Found @ ff94ca50 (0x9b44) & ff94ca6c (-0x04)
//static long *nrflag = (long*)(0x9b44-0x04);  // Found @ ff94ca50 & ff94ca68

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
//NHSTUB(CreateJumptable                      ,0xffad44bc) //  1
//NHSTUB(_uartr_req                           ,0xff81c294) //111
//NHSTUB(AllocateMemory                       ,0xffa67c20) //101
NHSTUB(AllocateUncacheableMemory              ,0xff827fcc) //112
NHSTUB(Close                                  ,0xff823a64) //101
NHSTUB(CreateTask                             ,0xff81aef4) //101
NHSTUB(DebugAssert                            ,0xff81b1cc) //111
NHSTUB(DeleteDirectory_Fut                    ,0xff8233f4) //116
NHSTUB(DeleteFile_Fut                         ,0xff823310) //112
NHSTUB(DoAFLock                               ,0xff825864) //102
NHSTUB(EnterToCompensationEVF                 ,0xff825b10) //104
NHSTUB(ExecuteEventProcedure                  ,0xff875a90) //104
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
//NHSTUB(FreeMemory                           ,0xffa67c18) //101
NHSTUB(FreeUncacheableMemory                  ,0xff82800c) //112
NHSTUB(Fseek_Fut                              ,0xff82362c) //101
NHSTUB(Fwrite_Fut                             ,0xff82358c) //101
NHSTUB(GetBatteryTemperature                  ,0xff84e660) //102
NHSTUB(GetCCDTemperature                      ,0xff84e5f0) //102
NHSTUB(GetCurrentAvValue                      ,0xff93bf24) //102
NHSTUB(GetDrive_ClusterSize                   ,0xff85ae98) //  1
NHSTUB(GetDrive_FreeClusters                  ,0xff85af00) //  1
NHSTUB(GetDrive_TotalClusters                 ,0xff85aecc) //  1
NHSTUB(GetFocusLensSubjectDistance            ,0xff93a3ac) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff93a6b8) //  3
NHSTUB(GetKbdState                            ,0xff84b660) //109
NHSTUB(GetMemInfo                             ,0xff813c24) //115
NHSTUB(GetOpticalTemperature                  ,0xff84e6d0) //102
NHSTUB(GetParameterData                       ,0xff9754d4) //101
NHSTUB(GetPropertyCase                        ,0xff879778) //102
NHSTUB(GetSystemTime                          ,0xffa67c78) //101
NHSTUB(GetVRAMHPixelsSize                     ,0xff83ccb4) //102
NHSTUB(GetVRAMVPixelsSize                     ,0xff83ccc0) //102
NHSTUB(GetZoomLensCurrentPoint                ,0xff9411d0) //102
NHSTUB(GetZoomLensCurrentPosition             ,0xffa5b350) //102
NHSTUB(GiveSemaphore                          ,0xff8279e8) //112
NHSTUB(IsStrobeChargeCompleted                ,0xff8b6aa0) //102
NHSTUB(LEDDrive                               ,0xff84ab48) //103
NHSTUB(LocalTime                              ,0xff87322c) //115
NHSTUB(LockMainPower                          ,0xff881010) //103
//NHSTUB(Lseek                                ,0xff823ba4) //101
NHSTUB(MakeDirectory_Fut                      ,0xff823384) //116
NHSTUB(MoveFocusLensToDistance                ,0xffacda58) //102
NHSTUB(MoveIrisWithAv                         ,0xffa6324c) //102
NHSTUB(MoveZoomLensWithPoint                  ,0xffa63974) //102
//NHSTUB(NewTaskShell                         ,0xff879220) //103
NHSTUB(Open                                   ,0xff823a3c) //101
NHSTUB(PB2Rec                                 ,0xff884078) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff86612c) //102
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff866104) //102
NHSTUB(PT_PlaySound                           ,0xff865a7c) //102
NHSTUB(PostLogicalEventForNotPowerType        ,0xff87ed3c) //103
NHSTUB(PostLogicalEventToUI                   ,0xff87ed88) //103
NHSTUB(PutInNdFilter                          ,0xffa637f8) //102
NHSTUB(PutOutNdFilter                         ,0xffa6381c) //102
NHSTUB(Read                                   ,0xff819a4c) //101
NHSTUB(ReadFastDir                            ,0xffa491c4) //  1
NHSTUB(Rec2PB                                 ,0xff882a00) //104
NHSTUB(RefreshPhysicalScreen                  ,0xff9df0e0) //104
//NHSTUB(Remove                               ,0xff823aac) //  1
NHSTUB(RenameFile_Fut                         ,0xff8232bc) //  1
NHSTUB(Restart                                ,0xff829848) //106
NHSTUB(SetAE_ShutterSpeed                     ,0xffad08e8) //102
NHSTUB(SetAutoShutdownTime                    ,0xff881084) //103
NHSTUB(SetCurrentCaptureModeType              ,0xff888754) //101
NHSTUB(SetFileAttributes                      ,0xff823d90) //  1
NHSTUB(SetFileTimeStamp                       ,0xff823d40) //  1
NHSTUB(SetLogicalEventActive                  ,0xff880cd0) //101
NHSTUB(SetParameterData                       ,0xff9753b0) //101
NHSTUB(SetPropertyCase                        ,0xff879670) //102
NHSTUB(SetScriptMode                          ,0xff880d20) //101
NHSTUB(SleepTask                              ,0xff827c50) //101
NHSTUB(TakeSemaphore                          ,0xff827918) //101
NHSTUB(TurnOffBackLight                       ,0xff88f32c) //104
NHSTUB(TurnOnBackLight                        ,0xff88f314) //104
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff9637e4) //103
NHSTUB(UnlockAF                               ,0xff82589c) //102
NHSTUB(UnlockMainPower                        ,0xff880f64) //103
NHSTUB(UpdateMBROnFlash                       ,0xff85acd8) //105
NHSTUB(VbattGet                               ,0xff82046c) //103
NHSTUB(Write                                  ,0xff823b10) //101
NHSTUB(WriteSDCard                            ,0xff92aa44) //108
NHSTUB(_log                                   ,0xffb01a40) //111
NHSTUB(_log10                                 ,0xffb006cc) //112
NHSTUB(_pow                                   ,0xffb0083c) //114
NHSTUB(_sqrt                                  ,0xffb0369c) //  1
NHSTUB(add_ptp_handler                        ,0xffa1731c) //  3
NHSTUB(apex2us                                ,0xff9e01c8) //  4
NHSTUB(close                                  ,0xff819864) //  1
NHSTUB(closedir                               ,0xffa49294) //  1
NHSTUB(err_init_task                          ,0xff814e80) //111
NHSTUB(exmem_alloc                            ,0xff87416c) //103
NHSTUB(exmem_free                             ,0xff8741e4) //103
NHSTUB(free                                   ,0xff813a7c) //112
NHSTUB(kbd_p1_f                               ,0xff821c10) //109
NHSTUB(kbd_p1_f_cont                          ,0xff821c1c) //109
NHSTUB(kbd_p2_f                               ,0xff821428) //109
NHSTUB(kbd_read_keys                          ,0xff821b14) //109
NHSTUB(kbd_read_keys_r2                       ,0xff84af6c) //109
NHSTUB(lseek                                  ,0xff823ba4) //101
NHSTUB(malloc                                 ,0xff8139a8) //112
NHSTUB(memcmp                                 ,0xff81cba4) //101
NHSTUB(memcpy                                 ,0xff89bb28) //101
NHSTUB(memset                                 ,0xff9df500) //101
NHSTUB(mkdir                                  ,0xff823e08) //109
NHSTUB(mktime_ext                             ,0xff89c394) //  1
NHSTUB(open                                   ,0xff8197b4) //  1
NHSTUB(OpenFastDir                            ,0xffa49130) //  1
NHSTUB(qsort                                  ,0xffab8288) //  1
NHSTUB(rand                                   ,0xff81ccac) //  1
//NHSTUB(read                                 ,0xff819a4c) //101
NHSTUB(realloc                                ,0xff813b5c) //115
NHSTUB(reboot_fw_update                       ,0xffa50bc4) //106
NHSTUB(set_control_event                      ,0xff88092c) //111
NHSTUB(srand                                  ,0xff81cca0) //  1
NHSTUB(stat                                   ,0xff823c70) //  1
NHSTUB(strcat                                 ,0xff89b93c) //  1
NHSTUB(strchr                                 ,0xff89b9c4) //  1
NHSTUB(strcmp                                 ,0xff81cb3c) //101
NHSTUB(strcpy                                 ,0xff81cb24) //101
NHSTUB(strftime                               ,0xff89bd9c) //  1
NHSTUB(strlen                                 ,0xff81cb80) //101
NHSTUB(strncmp                                ,0xff89b978) //  1
NHSTUB(strncpy                                ,0xff82db14) //  1
NHSTUB(strrchr                                ,0xff9df4d8) //  1
NHSTUB(strtol                                 ,0xff82dd4c) //101
NHSTUB(strtolx                                ,0xff82db50) //109
   DEF(task_CaptSeq                           ,0xff868c38) //107
   DEF(task_ExpDrv                            ,0xff8ad86c) //110
   DEF(task_InitFileModules                   ,0xff884af4) //107
   DEF(task_MovieRecord                       ,0xff864630) //107
   DEF(task_PhySw                             ,0xff821784) //107
NHSTUB(time                                   ,0xff87380c) //109
NHSTUB(vsprintf                               ,0xff81cae8) //115
//NHSTUB(write                                ,0xff823b10) //101
//NHSTUB(EngDrvIn                             ,0xff822a48) //102
//NHSTUB(EngDrvOut                            ,0xff822a30) //102
//NHSTUB(EngDrvRead                           ,0xff822a50) //102
//NHSTUB(EngDrvBits                           ,0xff822a64) //102
//NHSTUB(GetSDProtect                         ,0xff821aec) //103
//NHSTUB(StartRecModeMenu                     ,0xff87a288) //102
//NHSTUB(DispCon_ShowBitmapColorBar           ,0xff846bf4) //102
//NHSTUB(ResetZoomLens                        ,0xffa638c8) //102
//NHSTUB(ResetFocusLens                       ,0xffa62790) //102
//NHSTUB(NR_GetDarkSubType                    ,0xff94de7c) //102
//NHSTUB(NR_SetDarkSubType                    ,0xff94ddd0) //102
//NHSTUB(SavePaletteData                      ,0xffad29c4) //102
