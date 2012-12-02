// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R43 (DRYOS version 2.3, release #0043)
//   Firmware Ver GM1.00C
//   Canon PowerShot SX210 IS

// Values for makefile.inc
//   PLATFORMOSVER = 43
//   PLATFORMID = 12790 (0x31f6) // Found @ 0xfffe0130
//   MAXRAMADDR = 0x03ffffff
//   KEYSYS = d4a                // Found @ 0xffff3570
//   NEED_ENCODED_DISKBOOT = 4   // Found @ 0xffff3580

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
NSTUB(kbd_pwr_off                             ,0xff861ed0) //  2 60%
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff89b2a8 -> ff8979b0 -> ff99c92c -> ffad1940 -> ffc093b4
// Mode 16940 in firmware but not in current modemap
// Mode 33320 in firmware but not in current modemap
// Mode 33322 in firmware but not in current modemap
// Mode 33321 in firmware but not in current modemap

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x000336c4) // Found @0xff83466c
DEF(physw_run                               ,0x00001c30) // Found @0xff8342c4
DEF(physw_sleep_delay                       ,0x00001c38) // Found @0xff8342c4
DEF(levent_table                            ,0xffbc1084) // Found @0xffbc1084
DEF(FlashParamsTable                        ,0xffc095bc) // Found @0xffc095bc
DEF(movie_status                            ,0x0000720c) // Found @0xff96de58
DEF(full_screen_refresh                     ,0x00009d08) // Found @0xffa1cf64
DEF(canon_menu_active                       ,0x0000368c) // Found @0xff891c4c
DEF(canon_shoot_menu_active                 ,0x00008511) // Found @0xff9b5a6c
DEF(playrec_mode                            ,0x000033bc) // Found @0xff883e64
//DEF(zoom_status                             ,0x0000d544) // Found @0xffad4e40, ** != ** stubs_min = 0x0000d524 (0xD524)
DEF(some_flag_for_af_scan                   ,0x000075d8) // Found @0xff970d5c
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 3 int value(s), the first is the zoom focus length.
// there are 126 entries in the table - set NUM_FL to 126
DEF(focus_len_table                         ,0xfffea1cc) // Found @0xfffea1cc
DEF(zoom_busy                               ,0x00007140) // Found @0xff969464
DEF(focus_busy                              ,0x00006fc8) // Found @0xff9639d0
//DEF(recreview_hold                          ,0x00004140) // Found @0xff8a3648, ** != ** stubs_min = 0x00008144 (0x804C+0xF8)

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x40431000; }             // Found @0xff85be4c
//void *vid_get_viewport_fb()      { return (void*)0x40547700; }             // Found @0xffb2c7b4
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x30b8+0x58)); } // Found @0xff8750cc & 0xff875104
//char *camera_jpeg_count_str()    { return (char*)0x000a05dc; }             // Found @0xffa0e708
//long hook_raw_size()             { return 0x014d2400; }                    // Found @0xffb2fb88
//int get_flash_params_count(void) { return 0x94; }                          // Found @0xff99d9e8

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffb65924, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x00080000 // Found @0xffb6592c, levent 0x902
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_POWER           ,0x00000008 }, // Found @0xffb6583c, levent 0x600
//    { 0, KEY_UP              ,0x00000080 }, // Found @0xffb6584c, levent 0x04
//    { 0, KEY_DOWN            ,0x00000100 }, // Found @0xffb65854, levent 0x05
//    { 0, KEY_SHOOT_FULL      ,0x00002002 }, // Found @0xffb65834, levent 0x01
//    { 0, KEY_SHOOT_HALF      ,0x00002000 }, // Found @0xffb6585c, levent 0x00
//    { 0, KEY_SHOOT_FULL_ONLY ,0x00000002 }, // Found @0xffb65834, levent 0x01
//    { 0, KEY_PLAYBACK        ,0x00800000 }, // Found @0xffb6586c, levent 0x601
//    { 1, KEY_RIGHT           ,0x00004000 }, // Found @0xffb658ec, levent 0x07
//    { 1, KEY_LEFT            ,0x00008000 }, // Found @0xffb658f4, levent 0x06
//    { 1, KEY_SET             ,0x00010000 }, // Found @0xffb658fc, levent 0x08
//    { 1, KEY_DISPLAY         ,0x00020000 }, // Found @0xffb65904, levent 0x0a
//    { 1, KEY_MENU            ,0x00040000 }, // Found @0xffb6590c, levent 0x09
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_RAW_ROWPIX    4416 // Found @0xff93e0b8
//#define CAM_RAW_ROWS      3296 // Found @0xff93e0c0
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff83a69c

// Misc stuff
DEF(ctypes, 0xffb642a6)

// For capt_seq.c
//static long *nrflag = (long*)(0x75b8-0x08);  // Found @ ff972f8c & ff972fa8

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NSTUB(AllocateMemory                          ,0xffac3f54) //101
NSTUB(AllocateUncacheableMemory               ,0xff83a658) //112
NSTUB(Close                                   ,0xff836c50) //101
NSTUB(CreateTask                              ,0xff81e83c) //101
NSTUB(DebugAssert                             ,0xff81eb14) //111
NSTUB(DeleteDirectory_Fut                     ,0xff8366ac) //116
NSTUB(DeleteFile_Fut                          ,0xff8365c8) //112
NSTUB(DoAFLock                                ,0xff8383f0) //102
NSTUB(EnterToCompensationEVF                  ,0xff838598) //104
NSTUB(ExecuteEventProcedure                   ,0xff88d364) //104
NSTUB(ExitFromCompensationEVF                 ,0xff8385dc) //104
NSTUB(ExitTask                                ,0xff81eacc) //101
NSTUB(ExpCtrlTool_StartContiAE                ,0xff846458) //104
NSTUB(ExpCtrlTool_StopContiAE                 ,0xff846530) //104
NSTUB(Fclose_Fut                              ,0xff836744) //101
NSTUB(Feof_Fut                                ,0xff836930) //  1
NSTUB(Fflush_Fut                              ,0xff83696c) //  1
NSTUB(Fgets_Fut                               ,0xff836898) //  1
NSTUB(Fopen_Fut                               ,0xff836704) //101
NSTUB(Fread_Fut                               ,0xff8367f0) //101
NSTUB(FreeMemory                              ,0xffac3f4c) //101
NSTUB(FreeUncacheableMemory                   ,0xff83a698) //112
NSTUB(Fseek_Fut                               ,0xff8368e4) //101
NSTUB(Fwrite_Fut                              ,0xff836844) //101
NSTUB(GetBatteryTemperature                   ,0xff866f08) //102
NSTUB(GetCCDTemperature                       ,0xff866e94) //102
NSTUB(GetCurrentAvValue                       ,0xff9665d4) //102
NSTUB(GetDrive_ClusterSize                    ,0xff873868) //  4
NSTUB(GetDrive_FreeClusters                   ,0xff834348) //  3
// ALT: NSTUB(GetDrive_FreeClusters, 0xff8738c8) // 4 9/0
NSTUB(GetDrive_TotalClusters                  ,0xff87389c) //  3
NSTUB(GetFocusLensSubjectDistance             ,0xff964644) //102
NSTUB(GetFocusLensSubjectDistanceFromLens     ,0xff9649cc) //  3
NSTUB(GetImageFolder                          ,0xff94513c) //106
NSTUB(GetKbdState                             ,0xff861d88) //109
NSTUB(GetMemInfo                              ,0xff81a16c) //115
NSTUB(GetOpticalTemperature                   ,0xff866f7c) //102
NSTUB(GetParameterData                        ,0xff99d9a8) //101
NSTUB(GetPropertyCase                         ,0xff891070) //102
NSTUB(GetSystemTime                           ,0xffac3fac) //101
NSTUB(GetVRAMHPixelsSize                      ,0xff851458) //102
NSTUB(GetVRAMVPixelsSize                      ,0xff851464) //102
NSTUB(GetZoomLensCurrentPoint                 ,0xff9698ac) //102
NSTUB(GetZoomLensCurrentPosition              ,0xffab484c) //102
NSTUB(GiveSemaphore                           ,0xff83a074) //112
NSTUB(IsStrobeChargeCompleted                 ,0xff8da74c) //102
NSTUB(LEDDrive                                ,0xff860ff8) //103
NSTUB(LocalTime                               ,0xff88ac58) //115
NSTUB(LockMainPower                           ,0xff8975b4) //103
NSTUB(Lseek                                   ,0xff836d6c) //101
NSTUB(MakeDirectory_Fut                       ,0xff83663c) //116
NSTUB(MoveFocusLensToDistance                 ,0xffb2918c) //102
NSTUB(MoveIrisWithAv                          ,0xffac169c) //102
NSTUB(MoveZoomLensWithPoint                   ,0xffac1d10) //102
NSTUB(NewTaskShell                            ,0xff890a7c) //103
NSTUB(Open                                    ,0xff836be4) //101
NSTUB(PB2Rec                                  ,0xff89a7a8) //104
NSTUB(PT_MoveDigitalZoomToWide                ,0xff87c00c) //102
NSTUB(PT_MoveOpticalZoomAt                    ,0xff87bfe4) //102
NSTUB(PT_PlaySound                            ,0xff885cd0) //  7
NSTUB(PostLogicalEventForNotPowerType         ,0xff89538c) //103
NSTUB(PostLogicalEventToUI                    ,0xff8953d8) //103
NSTUB(PutInNdFilter                           ,0xffb26e48) //102
NSTUB(PutOutNdFilter                          ,0xffb26e80) //102
NSTUB(Read                                    ,0xff81ac7c) //101
NSTUB(ReadFastDir                             ,0xffaa1d20) //  4
NSTUB(Rec2PB                                  ,0xff899080) //104
NSTUB(RefreshPhysicalScreen                   ,0xffa1db68) //104
NSTUB(Remove                                  ,0xff836c84) //  4
NSTUB(RenameFile_Fut                          ,0xff836534) //116
NSTUB(Restart                                 ,0xff83be34) //106
NSTUB(ScreenLock                              ,0xffa1ed98) //  3
NSTUB(ScreenUnlock                            ,0xffa1eddc) //  7
NSTUB(SetAE_ShutterSpeed                      ,0xffb2b928) //102
NSTUB(SetAutoShutdownTime                     ,0xff897628) //103
NSTUB(SetCurrentCaptureModeType               ,0xff8a0618) //101
NSTUB(SetFileAttributes                       ,0xff836f48) //  3
NSTUB(SetFileTimeStamp                        ,0xff836eec) //  4
NSTUB(SetLogicalEventActive                   ,0xff8972f0) //101
NSTUB(SetParameterData                        ,0xff99d918) //101
NSTUB(SetPropertyCase                         ,0xff890f40) //102
NSTUB(SetScriptMode                           ,0xff897340) //101
NSTUB(SleepTask                               ,0xff83a2dc) //101
NSTUB(TakeSemaphore                           ,0xff839fa4) //101
NSTUB(TurnOffBackLight                        ,0xff8a732c) //104
NSTUB(TurnOnBackLight                         ,0xff8a7314) //104
NSTUB(UIFS_WriteFirmInfoToFile                ,0xff98a11c) //103
NSTUB(UnlockAF                                ,0xff838480) //102
NSTUB(UnlockMainPower                         ,0xff897508) //103
NSTUB(UpdateMBROnFlash                        ,0xff8736e8) //105
NSTUB(VbattGet                                ,0xff832ffc) //103
NSTUB(Write                                   ,0xff836ce0) //101
NSTUB(WriteSDCard                             ,0xff95416c) //108
NSTUB(_log                                    ,0xffb613b4) //111
NSTUB(_log10                                  ,0xffb60040) //112
NSTUB(_pow                                    ,0xffb601b0) //114
NSTUB(_sqrt                                   ,0xffb62fbc) //  1
NSTUB(add_ptp_handler                         ,0xffa5c93c) //  3
NSTUB(apex2us                                 ,0xffa2260c) //  4
NSTUB(close                                   ,0xff81aa94) //  1
NSTUB(closedir                                ,0xffaa1b7c) //  4
NSTUB(err_init_task                           ,0xff815f4c) //111
NSTUB(exmem_alloc                             ,0xff88bb98) //103
NSTUB(free                                    ,0xff81415c) //112
NSTUB(kbd_p1_f                                ,0xff8346e4) //109
NSTUB(kbd_p1_f_cont                           ,0xff8346f0) //109
NSTUB(kbd_p2_f                                ,0xff833f90) //109
NSTUB(kbd_read_keys                           ,0xff83466c) //109
NSTUB(kbd_read_keys_r2                        ,0xff861580) //109
NSTUB(lseek                                   ,0xff836d6c) //101
NSTUB(malloc                                  ,0xff814100) //112
NSTUB(memcmp                                  ,0xff82067c) //101
NSTUB(memcpy                                  ,0xff83fdb4) //101
NSTUB(memset                                  ,0xffa21644) //101
NSTUB(mkdir                                   ,0xff8370ec) //109
NSTUB(mktime_ext                              ,0xff8af464) //  1
NSTUB(open                                    ,0xff81a9e4) //  1
NSTUB(OpenFastDir                             ,0xffaa1bcc) //  4
NSTUB(qsort                                   ,0xffb17f74) //  4
NSTUB(rand                                    ,0xff820784) //  1
NSTUB(read                                    ,0xff81ac7c) //101
NSTUB(reboot_fw_update                        ,0xffaa7164) //106
NSTUB(set_control_event                       ,0xff896f40) //111
NSTUB(srand                                   ,0xff820778) //  1
NSTUB(stat                                    ,0xff836db4) //109
NSTUB(strcat                                  ,0xff8aec20) //  1
NSTUB(strchr                                  ,0xff813fe4) //  1
NSTUB(strcmp                                  ,0xff820638) //101
NSTUB(strcpy                                  ,0xff820620) //101
NSTUB(strftime                                ,0xff8aee6c) //113
NSTUB(strlen                                  ,0xff814030) //101
NSTUB(strncmp                                 ,0xff813f98) //  1
NSTUB(strncpy                                 ,0xff813f5c) //  1
NSTUB(strrchr                                 ,0xff814008) //  1
NSTUB(strtol                                  ,0xff840094) //101
NSTUB(strtolx                                 ,0xff83fe98) //109
  DEF(task_CaptSeq                            ,0xff87eb90) //107
  DEF(task_ExpDrv                             ,0xff8c475c) //107
  DEF(task_InitFileModules                    ,0xff89b134) //107
  DEF(task_MovieRecord                        ,0xff96e110) //107
  DEF(task_PhySw                              ,0xff8342c0) //107
  DEF(task_RotaryEncoder                      ,0xff862024) //107
NSTUB(time                                    ,0xff88b238) //109
NSTUB(vsprintf                                ,0xff8205e4) //115
NSTUB(write                                   ,0xff836ce0) //101
