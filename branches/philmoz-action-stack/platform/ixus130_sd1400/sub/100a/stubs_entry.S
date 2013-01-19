// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R43 (DRYOS version 2.3, release #0043)
//   Firmware Ver GM1.00A
//   Canon IXUS 130

// Values for makefile.inc
//   PLATFORMOSVER = 43
//   PLATFORMID = 12787 (0x31f3) // Found @ 0xfffe0130
//   MAXRAMADDR = 0x03ffffff
//   KEYSYS = d4a                // Found @ 0xffff3568
//   NEED_ENCODED_DISKBOOT = 4   // Found @ 0xffff3578

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NSTUB(kbd_pwr_off                           ,0xff85fb28) //  2 64%    *** != 0xff811800
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0xff811800

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff8947f0 -> ff891048 -> ff9850d4 -> ffaa2a80 -> ffbd0aa8
// Mode 33320 in firmware but not in current modemap
// Mode 33322 in firmware but not in current modemap

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00032800) // Found @0xff83459c
DEF(physw_run                               ,0x00001c2c) // Found @0xff834200
DEF(physw_sleep_delay                       ,0x00001c34) // Found @0xff834200
DEF(levent_table                            ,0xffb7a2d0) // Found @0xffb7a2d0
DEF(FlashParamsTable                        ,0xffbd0cac) // Found @0xffbd0cac
DEF(movie_status                            ,0x00006430) // Found @0xff95a250
DEF(full_screen_refresh                     ,0x00008dcc) // Found @0xff9f6b8c
DEF(canon_menu_active                       ,0x00002f60) // Found @0xff88cdc4
DEF(canon_shoot_menu_active                 ,0x000077c5) // Found @0xff997e10
DEF(playrec_mode                            ,0x00002c98) // Found @0xff87f1f4
DEF(zoom_status                             ,0x0000c6c4) // Found @0xffaa5f6c
DEF(some_flag_for_af_scan                   ,0x000067e8) // Found @0xff95d114
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 3 int value(s), the first is the zoom focus length.
// there are 8 entries in the table - set NUM_FL to 8
DEF(focus_len_table                         ,0xfffe2aa0) // Found @0xfffe2aa0
DEF(zoom_busy                               ,0x00006390) // Found @0xff955ea4
DEF(focus_busy                              ,0x00006234) // Found @0xff951764
DEF(recreview_hold                          ,0x000035c0) // Found @0xff89a95c

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x40431000; }             // Found @0xff859828
//void *vid_get_viewport_fb()      { return (void*)0x40547700; }             // Found @0xffb00ae4
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x29a0+0x58)); } // Found @0xff870cc0 & 0xff870cf8
//char *camera_jpeg_count_str()    { return (char*)0x0009eb4c; }             // Found @0xff9eac18
//long hook_raw_size()             { return 0x014d2400; }                    // Found @0xffb03eb0
//int get_flash_params_count(void) { return 0x94; }                          // Found @0xff986190

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffb3ea70, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x00080000 // Found @0xffb3ea88, levent 0x902
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_SET             ,0x00000004 }, // Found @0xffb3e9b0, levent 0x08
//    { 0, KEY_DISPLAY         ,0x00000008 }, // Found @0xffb3e9bc, levent 0x0a
//    { 2, KEY_MENU            ,0x00000001 }, // Found @0xffb3e9d4, levent 0x09
//    { 2, KEY_ZOOM_IN         ,0x00000004 }, // Found @0xffb3e9e0, levent 0x02
//    { 2, KEY_ZOOM_OUT        ,0x00000008 }, // Found @0xffb3e9ec, levent 0x03
//    { 2, KEY_LEFT            ,0x00000010 }, // Found @0xffb3e9f8, levent 0x06
//    { 2, KEY_RIGHT           ,0x00000020 }, // Found @0xffb3ea04, levent 0x07
//    { 2, KEY_DOWN            ,0x00000040 }, // Found @0xffb3ea10, levent 0x05
//    { 2, KEY_UP              ,0x00000080 }, // Found @0xffb3ea1c, levent 0x04
//    { 2, KEY_SHOOT_FULL      ,0x00000300 }, // Found @0xffb3ea34, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000200 }, // Found @0xffb3ea34, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00000100 }, // Found @0xffb3ea28, levent 0x00
//    { 2, KEY_POWER           ,0x00000400 }, // Found @0xffb3ea40, levent 0x600
//    { 2, KEY_PLAYBACK        ,0x00000800 }, // Found @0xffb3ea4c, levent 0x601
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_RAW_ROWPIX    4416 // Found @0xff92e1c8
//#define CAM_RAW_ROWS      3296 // Found @0xff92e1d0
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff83a1f8

// Misc stuff
DEF(ctypes, 0xffb3d52a)

// For capt_seq.c
//static long *nrflag = (long*)(0x67c8-0x08);  // Found @ ff95f0f8 & ff95f114

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NSTUB(AllocateMemory                          ,0xffa92a6c) //101
NSTUB(AllocateUncacheableMemory               ,0xff83a1b4) //112
NSTUB(Close                                   ,0xff836b78) //101
NSTUB(CreateTask                              ,0xff81e83c) //101
NSTUB(DebugAssert                             ,0xff81eb14) //111
NSTUB(DeleteDirectory_Fut                     ,0xff8365d4) //116
NSTUB(DeleteFile_Fut                          ,0xff8364f0) //112
NSTUB(DoAFLock                                ,0xff83809c) //102
NSTUB(EnterToCompensationEVF                  ,0xff8381e8) //104
NSTUB(ExecuteEventProcedure                   ,0xff8884e8) //104
NSTUB(ExitFromCompensationEVF                 ,0xff83822c) //104
NSTUB(ExitTask                                ,0xff81eacc) //101
NSTUB(ExpCtrlTool_StartContiAE                ,0xff845e30) //104
NSTUB(ExpCtrlTool_StopContiAE                 ,0xff845f08) //104
NSTUB(Fclose_Fut                              ,0xff83666c) //101
NSTUB(Feof_Fut                                ,0xff836858) //  1
NSTUB(Fflush_Fut                              ,0xff836894) //  1
NSTUB(Fgets_Fut                               ,0xff8367c0) //  1
NSTUB(Fopen_Fut                               ,0xff83662c) //101
NSTUB(Fread_Fut                               ,0xff836718) //101
NSTUB(FreeMemory                              ,0xffa92a64) //101
NSTUB(FreeUncacheableMemory                   ,0xff83a1f4) //112
NSTUB(Fseek_Fut                               ,0xff83680c) //101
NSTUB(Fwrite_Fut                              ,0xff83676c) //101
NSTUB(GetBatteryTemperature                   ,0xff862d18) //102
NSTUB(GetCCDTemperature                       ,0xff862ca4) //102
NSTUB(GetCurrentAvValue                       ,0xff953154) //102
NSTUB(GetDrive_ClusterSize                    ,0xff86f4b0) //  4
//NSTUB(GetDrive_FreeClusters                 ,0xff86f510) //  4            == 0xff86f510
NSTUB(GetDrive_TotalClusters                  ,0xff86f4e4) //  3
NSTUB(GetFocusLensSubjectDistance             ,0xff9523e4) //102
NSTUB(GetFocusLensSubjectDistanceFromLens     ,0xff95282c) //  3
NSTUB(GetImageFolder                          ,0xff935238) //106
NSTUB(GetKbdState                             ,0xff85fb10) //109
NSTUB(GetMemInfo                              ,0xff81a16c) //115
NSTUB(GetOpticalTemperature                   ,0xff862d8c) //102
NSTUB(GetParameterData                        ,0xff986150) //101
NSTUB(GetPropertyCase                         ,0xff88c1f4) //102
NSTUB(GetSystemTime                           ,0xffa92ac4) //101
NSTUB(GetVRAMHPixelsSize                      ,0xff85079c) //102
NSTUB(GetVRAMVPixelsSize                      ,0xff8507a8) //102
NSTUB(GetZoomLensCurrentPoint                 ,0xff95621c) //102
NSTUB(GetZoomLensCurrentPosition              ,0xffa86134) //102
NSTUB(GiveSemaphore                           ,0xff839bd0) //112
NSTUB(IsStrobeChargeCompleted                 ,0xff8d0bc0) //102
NSTUB(LEDDrive                                ,0xff85ef6c) //103
NSTUB(LocalTime                               ,0xff885ddc) //115
NSTUB(LockMainPower                           ,0xff890c50) //103
NSTUB(Lseek                                   ,0xff836c94) //101
NSTUB(MakeDirectory_Fut                       ,0xff836564) //116
NSTUB(MoveFocusLensToDistance                 ,0xffafd4c8) //102
NSTUB(MoveIrisWithAv                          ,0xffa90824) //102
NSTUB(MoveZoomLensWithPoint                   ,0xffa90db4) //102
NSTUB(NewTaskShell                            ,0xff88bc00) //103
NSTUB(Open                                    ,0xff836b0c) //101
NSTUB(PB2Rec                                  ,0xff893b90) //104
NSTUB(PT_MoveDigitalZoomToWide                ,0xff877bb4) //102
NSTUB(PT_MoveOpticalZoomAt                    ,0xff877b8c) //102
NSTUB(PT_PlaySound                            ,0xff880e64) //  7
NSTUB(PostLogicalEventForNotPowerType         ,0xff890480) //103
NSTUB(PostLogicalEventToUI                    ,0xff8904cc) //103
NSTUB(PutInNdFilter                           ,0xffa90c18) //102
NSTUB(PutOutNdFilter                          ,0xffa90c3c) //102
NSTUB(Read                                    ,0xff81ac7c) //101
NSTUB(ReadFastDir                             ,0xffa75154) //  4
NSTUB(Rec2PB                                  ,0xff893bd0) //104
NSTUB(RefreshPhysicalScreen                   ,0xff9f77c8) //104
NSTUB(Remove                                  ,0xff836bac) //  4
NSTUB(RenameFile_Fut                          ,0xff83645c) //116
NSTUB(Restart                                 ,0xff83b994) //106
NSTUB(ScreenLock                              ,0xff9f89f8) //  3
NSTUB(ScreenUnlock                            ,0xff9f8a3c) //  7
NSTUB(SetAE_ShutterSpeed                      ,0xffaffc58) //102
NSTUB(SetAutoShutdownTime                     ,0xff890cc4) //103
NSTUB(SetCurrentCaptureModeType               ,0xff897dcc) //101
NSTUB(SetFileAttributes                       ,0xff836e70) //  3
NSTUB(SetFileTimeStamp                        ,0xff836e14) //  4
NSTUB(SetLogicalEventActive                   ,0xff8909c8) //101
NSTUB(SetParameterData                        ,0xff9860c0) //101
NSTUB(SetPropertyCase                         ,0xff88c0c4) //102
NSTUB(SetScriptMode                           ,0xff890a18) //101
NSTUB(SleepTask                               ,0xff839e38) //101
NSTUB(TakeSemaphore                           ,0xff839b00) //101
NSTUB(TurnOffBackLight                        ,0xff89dee0) //104
NSTUB(TurnOnBackLight                         ,0xff89dec8) //104
NSTUB(UIFS_WriteFirmInfoToFile                ,0xff973418) //101
NSTUB(UnlockAF                                ,0xff838120) //102
NSTUB(UnlockMainPower                         ,0xff890ba4) //103
NSTUB(UnsetZoomForMovie                       ,0xff98c3a4) //104
NSTUB(UpdateMBROnFlash                        ,0xff86f330) //105
NSTUB(VbattGet                                ,0xff832f14) //103
NSTUB(Write                                   ,0xff836c08) //101
NSTUB(WriteSDCard                             ,0xff942aa0) //108
NSTUB(_log                                    ,0xffb3ae74) //111
NSTUB(_log10                                  ,0xffb39db8) //112
NSTUB(_pow                                    ,0xffb39f28) //114
NSTUB(_sqrt                                   ,0xffb3c240) //  1
NSTUB(add_ptp_handler                         ,0xffa33428) //  3
NSTUB(apex2us                                 ,0xff9fc26c) //  4
NSTUB(close                                   ,0xff81aa94) //  1
NSTUB(closedir                                ,0xffa74fb0) //  4
NSTUB(err_init_task                           ,0xff815f4c) //111
NSTUB(exmem_alloc                             ,0xff886d1c) //103
NSTUB(free                                    ,0xff81415c) //112
NSTUB(kbd_p1_f                                ,0xff834614) //109
NSTUB(kbd_p1_f_cont                           ,0xff834620) //109
NSTUB(kbd_p2_f                                ,0xff833ecc) //109
NSTUB(kbd_read_keys                           ,0xff83459c) //109
NSTUB(kbd_read_keys_r2                        ,0xff85f4cc) //109
NSTUB(lseek                                   ,0xff836c94) //101
NSTUB(malloc                                  ,0xff814100) //112
NSTUB(memcmp                                  ,0xff82066c) //101
NSTUB(memcpy                                  ,0xff83f81c) //101
NSTUB(memset                                  ,0xff9fb2a4) //101
NSTUB(mkdir                                   ,0xff837014) //109
NSTUB(mktime_ext                              ,0xff8a5a84) //  1
NSTUB(open                                    ,0xff81a9e4) //  1
NSTUB(OpenFastDir                             ,0xffa75000) //  4
NSTUB(qsort                                   ,0xffae5444) //  4
NSTUB(rand                                    ,0xff820774) //  1
NSTUB(read                                    ,0xff81ac7c) //101
NSTUB(reboot_fw_update                        ,0xffa7a598) //106
NSTUB(set_control_event                       ,0xff8906e8) //111
NSTUB(srand                                   ,0xff820768) //  1
NSTUB(stat                                    ,0xff836cdc) //109
NSTUB(strcat                                  ,0xff8a5240) //  1
NSTUB(strchr                                  ,0xff813fe4) //  1
NSTUB(strcmp                                  ,0xff820628) //101
NSTUB(strcpy                                  ,0xff820610) //101
NSTUB(strftime                                ,0xff8a548c) //113
NSTUB(strlen                                  ,0xff814030) //101
NSTUB(strncmp                                 ,0xff813f98) //  1
NSTUB(strncpy                                 ,0xff813f5c) //  1
NSTUB(strrchr                                 ,0xff814008) //  1
NSTUB(strtol                                  ,0xff83fafc) //101
NSTUB(strtolx                                 ,0xff83f900) //109
  DEF(task_CaptSeq                            ,0xff87a2c0) //107
  DEF(task_ExpDrv                             ,0xff8baad8) //110
  DEF(task_InitFileModules                    ,0xff89467c) //107
  DEF(task_MovieRecord                        ,0xff95a538) //107
  DEF(task_PhySw                              ,0xff8341fc) //107
NSTUB(time                                    ,0xff8863bc) //109
NSTUB(vsprintf                                ,0xff8205d4) //115
NSTUB(write                                   ,0xff836c08) //101
