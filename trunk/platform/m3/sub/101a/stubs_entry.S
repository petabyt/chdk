// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   Main firmware start: 0xfc020000
//   DRYOS R55 (DRYOS version 2.3, release #0055+p6)
//   Firmware Ver GM1.01A   // Found @ 0xfc1fce98, "GM1.01A" @ 0xfc1fcea5

// Values for makefile.inc
//   PLATFORMOSVER = 55
//   MEMISOSTART = 0x3a7c80
//   MEMBASEADDR = 0x8000
//   ARAM_HEAP_START = 0x0074e000 #  Found @0xfc18e0f8
//   ARAM_HEAP_SIZE = 0x00022000 #  Found @0xfc18e0d2

// Detected address ranges:
// ROM      0xfc000000 - 0xfe000000 (33554432 bytes)
// RAM code 0x010e1000 - 0x011074ac copied from 0xfccabee8 ( 156844 bytes)
// RAM code 0xbfe10800 - 0xbfe17391 copied from 0xfccd2394 (  27537 bytes)
// RAM data 0x00008000 - 0x00050740 copied from 0xfcc637a8 ( 296768 bytes)

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xfc1536d4

// physw_event_table 0xfc5f99f8 Found @0xfc074ec0
// Values below go in 'platform_kbd.h':
//#define SD_READONLY_FLAG    0x20000000 // Found @0xfc5f9ad0, levent 0x20a
//#define SD_READONLY_IDX     1
//#define USB_MASK            0x10000000 // Found @0xfc5f9b38, levent 0x202
//#define USB_IDX             2
//#define BATTCOVER_FLAG      0x01000000 // Found @0xfc5f9a58, levent 0x205
//#define BATTCOVER_IDX       0
//#define HOTSHOE_FLAG        0x00010000 // Found @0xfc5f9af0, levent 0x204
//#define HOTSHOE_IDX         2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
// WARNING: Values only verified on sx280hs (R52) and g7x (R55p6) errors likely on other cams!
//KeyMap keymap[] = {
//    { 0, KEY_POWER           ,0x00000001 }, // Found @0xfc5f99f8, levent 0x100 (uses inverted logic in physw_status)
//    { 0, KEY_PLAYBACK        ,0x00000002 }, // Found @0xfc5f9a00, levent 0x101 (uses inverted logic in physw_status)
//    { 1, KEY_SHOOT_FULL      ,0x00040001 }, // Found @0xfc5f9a60, levent 0x01
//    { 1, KEY_SHOOT_HALF      ,0x00040000 }, // Found @0xfc5f9ac0, levent 0x00
//    { 1, KEY_SHOOT_FULL_ONLY ,0x00000001 }, // Found @0xfc5f9a60, levent 0x01
//    { 1, KEY_VIDEO           ,0x00000008 }, // Found @0xfc5f9a68, levent 0x02
//    { 1, KEY_MENU            ,0x00000010 }, // Found @0xfc5f9a70, levent 0x14
//    { 1, KEY_UP              ,0x00000020 }, // Found @0xfc5f9a78, levent 0x06
//    { 1, KEY_DOWN            ,0x00000040 }, // Found @0xfc5f9a80, levent 0x07
//    { 1, KEY_RIGHT           ,0x00000080 }, // Found @0xfc5f9a88, levent 0x09
//    { 1, KEY_LEFT            ,0x00000100 }, // Found @0xfc5f9a90, levent 0x08
//    { 1, KEY_SET             ,0x00000200 }, // Found @0xfc5f9a98, levent 0x0a
//    { 1, KEY_HELP            ,0x00000400 }, // Found @0xfc5f9aa0, levent 0x0d
//    { 0, 0, 0 }
//};

// canon_mode_list 0xfc747a68 Found @0xfc0e15b0
// Check modemap values from 'platform/CAMERA/shooting.c':
// 33289  0x8209 In firmware but not in current modemap
//  8778  0x224a In firmware but not in current modemap
//  8777  0x2249 In firmware but not in current modemap
//  8776  0x2248 In firmware but not in current modemap
// 16423  0x4027 In firmware but not in current modemap
// 16424  0x4028 In firmware but not in current modemap
// 16405  0x4015 In firmware but not in current modemap
// 16904  0x4208 In firmware but not in current modemap
//  2649  0x0a59 In firmware but not in current modemap
//  4172  0x104c In firmware but not in current modemap
// Current modemap entry not found in firmware - MODE_VIDEO_STAR_TIME_LAPSE 16459
// Current modemap entry not found in firmware - MODE_VIDEO_IFRAME_MOVIE   2650
// Current modemap entry not found in firmware - MODE_CREATIVE_EFFECT     33299
// Current modemap entry not found in firmware - MODE_FIREWORK            16416
// Current modemap entry not found in firmware - MODE_SNOW                16414
// Current modemap entry not found in firmware - MODE_UNDERWATER          16929
// Current modemap entry not found in firmware - MODE_STAR_TRAILS         16454
// Current modemap entry not found in firmware - MODE_STAR_NIGHTSCAPE     16453
// Current modemap entry not found in firmware - MODE_STAR_PORTRAIT       16452
// Current modemap entry not found in firmware - MODE_WINK_SELF_TIMER     16950
// Current modemap entry not found in firmware - MODE_SMART_SHUTTER       16949
// Current modemap entry not found in firmware - MODE_FACE_SELF_TIMER     16948
// Current modemap entry not found in firmware - MODE_POSTER_EFFECT        8755
// Current modemap entry not found in firmware - MODE_SUPER_VIVID          8754
// Current modemap entry not found in firmware - MODE_MONOCHROME           8767
// Current modemap entry not found in firmware - MODE_BACKGROUND_DEFOCUS   8764
// Current modemap entry not found in firmware - MODE_NOSTALGIC            8753

// Values below can be overridden in 'stubs_min.S':
//DEF(ctypes                            ,0xfc5e29f4),          stubs_min = 0xfc5e29f4 (0xFC5E29F4)
//DEF(physw_run                         ,0x000082cc),          stubs_min = 0x000082cc (0x000082CC)
//DEF(physw_sleep_delay                 ,0x000082d4),          stubs_min = 0x000082d4 (0x000082D4)
//DEF(physw_status                      ,0x00052098),          stubs_min = 0x00052098 (0x00052098)
//DEF(fileio_semaphore                  ,0x000125ac),          stubs_min = 0x000125ac (0x000125AC)
//DEF(levent_table                      ,0xfc63846c),          stubs_min = 0xfc63846c (0xFC63846C)
//DEF(FlashParamsTable                  ,0xfc747db8),          stubs_min = 0xfc747db8 (0xFC747DB8)
//DEF(playrec_mode                      ,0x0000b454),          stubs_min = 0x0000b454 (0x0000B454)
//DEF(jpeg_count_str                    ,0x0016cc64),          stubs_min = 0x0016cc64 (0x0016CC64)
//DEF(zoom_busy                         ,0x00000000), ** != ** stubs_min = 0x00000001 (1)
//DEF(focus_busy                        ,0x00000000), ** != ** stubs_min = 0x00000001 (1)
DEF_CONST(uiprop_count                      ,0x000000c7) // Found @0xfc277c02

//NHSTUB(Close                                ,0xfc37a501) //  0      <-veneer 0xfc37a579
//NHSTUB(DebugAssert                          ,0x010e1001) //  0      <-veneer 0xfc302410
//NHSTUB(DeleteDirectory_Fut                  ,0x00000000) //  0        *** != 0xfc373f15
//NHSTUB(DeleteFile_Fut                       ,0x00000000) //  0        *** != 0xfc373ecb
//NHSTUB(EnterToCompensationEVF               ,0x00000000) //  0        *** != 0xfc0aa66b
//NHSTUB(ExitFromCompensationEVF              ,0x00000000) //  0        *** != 0xfc0aa6a7
//NHSTUB(ExitTask                             ,0xbfe14c13) //  0      <-veneer 0xfc3022c8
//NHSTUB(ExpCtrlTool_StartContiAE             ,0x00000000) //  0        *** != 0xfc2aac61
//NHSTUB(ExpCtrlTool_StopContiAE              ,0x00000000) //  0        *** != 0xfc2aaeb5
//NHSTUB(Feof_Fut                             ,0x00000000) //  0        *** != 0xfc3740b9
//NHSTUB(Fflush_Fut                           ,0x00000000) //  0        *** != 0xfc3740e1
//NHSTUB(GetBatteryTemperature                ,0xfc1f60fd) //  0      <-veneer 0xfc1f6261
//NHSTUB(GetCCDTemperature                    ,0xfc1f60a1) //  0      <-veneer 0xfc1f625f
//NHSTUB(GetDrive_TotalClusters               ,0x00000000) //  0        *** != 0xfc06bf33
//NHSTUB(GetFocusLensSubjectDistanceFromLens  ,0x00000000) //  0        *** != 0xfc35fcab
//NHSTUB(GetImageFolder                       ,0x00000000) //  0        *** != 0xfc303c41
//NHSTUB(GetKbdState                          ,0xfc075053) //  0      <-veneer 0xfc07425b
//NHSTUB(GetOpticalTemperature                ,0xfc1f6157) //  0      <-veneer 0xfc1f625d
//NHSTUB(LocalTime                            ,0x010e1515) //  0        *** != 0xfccac3fd
//NHSTUB(MakeSDCardBootable                   ,0x00000000) //  0        *** != 0xfc37a34d
//NHSTUB(MoveFocusLensToDistance              ,0x00000000) //  0        *** != 0xfc44b80d
//NHSTUB(Open                                 ,0xfc37a47d) //  0      <-veneer 0xfc37a577
//NHSTUB(PutInNdFilter                        ,0x00000000) //  0        *** != 0xfc44ceb1
//NHSTUB(PutOutNdFilter                       ,0x00000000) //  0        *** != 0xfc44cecb
//NHSTUB(RefreshPhysicalScreen                ,0x00000000) //  0        *** != 0xfc37ef9f
//NHSTUB(RenameFile_Fut                       ,0x00000000) //  0        *** != 0xfc373e69
//NHSTUB(Restart                              ,0x00000000) //  0        *** != 0xfc1311dd
//NHSTUB(ScreenUnlock                         ,0x00000000) //  0        *** != 0xfc37f619
//NHSTUB(SetFileAttributes                    ,0x00000000) //  0        *** != 0xfc37a795
//NHSTUB(SetFileTimeStamp                     ,0x00000000) //  0        *** != 0xfc37a74d
//NHSTUB(SetParameterData                     ,0x00000000) //  0        *** != 0xfc2784bd
//NHSTUB(SleepTask                            ,0xbfe14999) //  0      <-veneer 0xfc3022e0
//NHSTUB(TurnOffBackLight                     ,0xfc35e73f) //  0        *** != 0xfc14b9e7
//NHSTUB(TurnOnBackLight                      ,0xfc35e6eb) //  0        *** != 0xfc14b9d5
//NHSTUB(TurnOnDisplay                        ,0xfc177ccd) //  0        *** != 0xfc14b9ad
//NHSTUB(TurnOffDisplay                       ,0xfc177cdf) //  0        *** != 0xfc14b9c3
//NHSTUB(VbattGet                             ,0xfc130beb) //  0      <-veneer 0xfc188f55
//NHSTUB(Write                                ,0xfc37a539) //  0      <-veneer 0xfc37a61f
//NHSTUB(WriteSDCard                          ,0x00000000) //  0        *** != 0xfccad9eb
//NHSTUB(_log10                               ,0x011030e8) //  0      <-veneer 0xfc302380
//NHSTUB(_pow                                 ,0x01103250) //  0      <-veneer 0xfc3017a8
//NHSTUB(apex2us                              ,0x00000000) //  0        *** != 0xfc3f41df
//NHSTUB(displaybusyonscreen                  ,0x00000000) //  0        *** != 0xfc332ff7
//NHSTUB(err_init_task                        ,0x00000000) //  0        *** != 0xfc06316b
//NHSTUB(realloc                              ,0x00000000) //  0        *** != 0xfc4f9f61
//NHSTUB(reboot_fw_update                     ,0x00000000) //  0        *** != 0xfc450121
//NHSTUB(strcmp                               ,0xfc380005) //  0      <-veneer 0xfc37fff1
//NHSTUB(strtolx                              ,0x00000000) //  0        *** != 0xfc14c0dd
//NHSTUB(time                                 ,0x010e11e3) //  0      <-veneer 0xfc302048
//NHSTUB(undisplaybusyonscreen                ,0x00000000) //  0        *** != 0xfc33308d
//NHSTUB(CancelHPTimer                        ,0x00000000) //  0        *** != 0xfc1fcbb1
//NHSTUB(SetHPTimerAfterNow                   ,0x00000000) //  0        *** != 0xfc1fcb19

//NHSTUB(AllocateUncacheableMemory            ,0xfc1536a5) //  0            == 0xfc1536a5
//NHSTUB(CreateTask                           ,0xbfe14a31) //  0            == 0xbfe14a31
//NHSTUB(DoAELock                             ,0xfc0aa83f) //  0            == 0xfc0aa83f
//NHSTUB(DoAFLock                             ,0xfc0aa4a1) //  0            == 0xfc0aa4a1
//NHSTUB2(ExecuteEventProcedure                ,0xfc327cc5) //  0            == 0xfc327cc5
//NHSTUB(Fclose_Fut                           ,0xfc373f77) //  0            == 0xfc373f77
//NHSTUB(Fgets_Fut                            ,0xfc374055) //  0            == 0xfc374055
//NHSTUB(Fopen_Fut                            ,0xfc373f4f) //  0            == 0xfc373f4f
//NHSTUB(Fread_Fut                            ,0xfc373fe9) //  0            == 0xfc373fe9
//NHSTUB(FreeUncacheableMemory                ,0xfc1536d1) //  0            == 0xfc1536d1
//NHSTUB(Fseek_Fut                            ,0xfc374087) //  0            == 0xfc374087
//NHSTUB(Fwrite_Fut                           ,0xfc37401f) //  0            == 0xfc37401f
//NHSTUB(GetCurrentAvValue                    ,0xfc318e87) //  0            == 0xfc318e87
//NHSTUB(GetDrive_ClusterSize                 ,0xfc379adf) //  0            == 0xfc379adf
//NHSTUB(GetDrive_FreeClusters                ,0xfc379fe3) //  0            == 0xfc379fe3
//NHSTUB(GetFocusLensSubjectDistance          ,0xfc35fb2b) //  0            == 0xfc35fb2b
//NHSTUB(GetMemInfo                           ,0xfc5a136d) //  0            == 0xfc5a136d
//NHSTUB(GetParameterData                     ,0xfc278531) //  0            == 0xfc278531
//NHSTUB(GetPropertyCase                      ,0xfc373499) //  0            == 0xfc373499
//NHSTUB(GetSystemTime                        ,0xfc450a01) //  0            == 0xfc450a01
//NHSTUB(GetVRAMHPixelsSize                   ,0xfc133d9d) //  0            == 0xfc133d9d
//NHSTUB(GetVRAMVPixelsSize                   ,0xfc133da5) //  0            == 0xfc133da5
//NHSTUB(GetZoomLensCurrentPoint              ,0xfc1861cf) //  0            == 0xfc1861cf
//NHSTUB(GetZoomLensCurrentPosition           ,0xfc186183) //  0            == 0xfc186183
//NHSTUB(GiveSemaphore                        ,0xbfe15479) //  0            == 0xbfe15479
//NHSTUB(IsStrobeChargeCompleted              ,0xfc4f3041) //  0            == 0xfc4f3041
//NHSTUB(LEDDrive                             ,0xfc188f59) //  0            == 0xfc188f59
//NHSTUB(LockMainPower                        ,0xfc1fd09f) //  0            == 0xfc1fd09f
//NHSTUB(MakeDirectory_Fut                    ,0xfc37a7eb) //  0            == 0xfc37a7eb
//NHSTUB(MoveIrisWithAv                       ,0xfc44c48d) //  0            == 0xfc44c48d
//NHSTUB(MoveZoomLensWithPoint                ,0xfc44d049) //  0            == 0xfc44d049
//NHSTUB(PB2Rec                               ,0xfc32a941) //  0            == 0xfc32a941
//NHSTUB(PT_MoveDigitalZoomToWide             ,0xfc0a9e45) //  0            == 0xfc0a9e45
//NHSTUB(PT_MoveOpticalZoomAt                 ,0xfc189ec1) //  0            == 0xfc189ec1
//NHSTUB(PT_PlaySound                         ,0xfc37763b) //  0            == 0xfc37763b
//NHSTUB(PostLogicalEventForNotPowerType      ,0xfc37e801) //  0            == 0xfc37e801
//NHSTUB(PostLogicalEventToUI                 ,0xfc37e835) //  0            == 0xfc37e835
//NHSTUB(Read                                 ,0xfc1ee4b5) //  0            == 0xfc1ee4b5
//NHSTUB(ReadFastDir                          ,0xfc11c63d) //  0            == 0xfc11c63d
//NHSTUB(Rec2PB                               ,0xfc32a987) //  0            == 0xfc32a987
//NHSTUB(ScreenLock                           ,0xfc37f5db) //  0            == 0xfc37f5db
//NHSTUB(SetAE_ShutterSpeed                   ,0xfc5a4fe1) //  0            == 0xfc5a4fe1
//NHSTUB(SetAutoShutdownTime                  ,0xfc1fd0eb) //  0            == 0xfc1fd0eb
//NHSTUB(SetCurrentCaptureModeType            ,0xfc36cac9) //  0            == 0xfc36cac9
//NHSTUB(SetLogicalEventActive                ,0xfc363471) //  0            == 0xfc363471
//NHSTUB(SetPropertyCase                      ,0xfc373347) //  0            == 0xfc373347
//NHSTUB(SetScriptMode                        ,0xfc3634a9) //  0            == 0xfc3634a9
//NHSTUB(TakeSemaphore                        ,0xbfe15401) //  0            == 0xbfe15401
//NHSTUB(UIFS_WriteFirmInfoToFile             ,0xfc38b533) //  0            == 0xfc38b533
//NHSTUB(UnlockAE                             ,0xfc0aa85d) //  0            == 0xfc0aa85d
//NHSTUB(UnlockAF                             ,0xfc0aa4d1) //  0            == 0xfc0aa4d1
//NHSTUB(UnlockMainPower                      ,0xfc1fd037) //  0            == 0xfc1fd037
//NHSTUB(UnsetZoomForMovie                    ,0x00000000) //  0            == 0x00000000
//NHSTUB(_log                                 ,0x01102bc8) //  0            == 0x01102bc8
//NHSTUB(_sqrt                                ,0x011052d0) //  0            == 0x011052d0
//NHSTUB(add_ptp_handler                      ,0xfc16b9d7) //  0            == 0xfc16b9d7
//NHSTUB(close                                ,0xfc1ee3af) //  0            == 0xfc1ee3af
//NHSTUB(exmem_alloc                          ,0xfc078d63) //  0            == 0xfc078d63
//NHSTUB(exmem_free                           ,0xfc078da3) //  0            == 0xfc078da3
//NHSTUB(free                                 ,0xfc37fe8b) //  0            == 0xfc37fe8b
//NHSTUB(kbd_p1_f                             ,0xfc083ead) //  0            == 0xfc083ead
//NHSTUB(kbd_p1_f_cont                        ,0xfc083eb5) //  0            == 0xfc083eb5
//NHSTUB(kbd_p2_f                             ,0xfc083915) //  0            == 0xfc083915
//NHSTUB(kbd_read_keys                        ,0xfc083e77) //  0            == 0xfc083e77
//NHSTUB(kbd_read_keys_r2                     ,0xfc074eb7) //  0            == 0xfc074eb7
//NHSTUB(lseek                                ,0xfc37a65d) //  0            == 0xfc37a65d
//NHSTUB(malloc                               ,0xfc37fe55) //  0            == 0xfc37fe55
//NHSTUB(memcmp                               ,0xfc3800d9) //  0            == 0xfc3800d9
//NHSTUB(memcpy                               ,0xfc200331) //  0            == 0xfc200331
//NHSTUB(memset                               ,0xfc1159e5) //  0            == 0xfc1159e5
//NHSTUB(mktime_ext                           ,0xfc1fff41) //  0            == 0xfc1fff41
//NHSTUB(open                                 ,0xfc1ee33f) //  0            == 0xfc1ee33f
//NHSTUB(OpenFastDir                          ,0xfc11c59d) //  0            == 0xfc11c59d
//NHSTUB(closedir                             ,0xfc11c565) //  0            == 0xfc11c565
//NHSTUB(get_fstype                           ,0xfc379a79) //  0            == 0xfc379a79
//NHSTUB(qsort                                ,0xfc3c86ad) //  0            == 0xfc3c86ad
//NHSTUB(rand                                 ,0xfc0fc1ab) //  0            == 0xfc0fc1ab
//NHSTUB(set_control_event                    ,0xfc3631e5) //  0            == 0xfc3631e5
//NHSTUB(srand                                ,0xfc0fc1a5) //  0            == 0xfc0fc1a5
//NHSTUB(stat                                 ,0xfc37a695) //  0            == 0xfc37a695
//NHSTUB(strcat                               ,0xfc37febd) //  0            == 0xfc37febd
//NHSTUB(strchr                               ,0xfc200419) //  0            == 0xfc200419
//NHSTUB(strcpy                               ,0xfc37fedf) //  0            == 0xfc37fedf
//NHSTUB(strftime                             ,0xfc1fff71) //  0            == 0xfc1fff71
//NHSTUB(strlen                               ,0xfc380063) //  0            == 0xfc380063
//NHSTUB(strncmp                              ,0xfc2003ef) //  0            == 0xfc2003ef
//NHSTUB(strncpy                              ,0xfc37befd) //  0            == 0xfc37befd
//NHSTUB(strrchr                              ,0xfc14c22d) //  0            == 0xfc14c22d
//NHSTUB(strtol                               ,0xfc14c21f) //  0            == 0xfc14c21f
//   DEF(task_CaptSeq                         ,0xfc0bd907) //  0            == 0xfc0bd907
   DEF(task_DvlpSeqTask                       ,0xfc110a77) //  0
//   DEF(task_ExpDrv                          ,0xfc2bc92d) //  0            == 0xfc2bc92d
//   DEF(task_FileWrite                       ,0xfc068b89) //  0            == 0xfc068b89
//   DEF(task_InitFileModules                 ,0xfc0f79a1) //  0            == 0xfc0f79a1
//   DEF(task_MovieRecord                     ,0xfc142ad5) //  0            == 0xfc142ad5
//   DEF(task_PhySw                           ,0xfc083bc5) //  0            == 0xfc083bc5
   DEF(task_TouchPanel                        ,0xfc13c10d) //  0
   DEF(hook_CreateTask                        ,0xbfe14a30) //  0
//NHSTUB(vsprintf                             ,0xfc0d7383) //  0            == 0xfc0d7383
//NHSTUB(EngDrvRead                           ,0xfc37ff31) //  0            == 0xfc37ff31
//NHSTUB(PTM_GetCurrentItem                   ,0xfc36e567) //  0            == 0xfc36e567
NHSTUB(DisableISDriveError                    ,0xfc44da2d) //  0
NHSTUB(bzero                                  ,0x01100410) //  0
NHSTUB(memset32                               ,0x01100414) //  0
//NHSTUB(PT_MFOn                              ,0xfc0ab61d) //  0            == 0xfc0ab61d
//NHSTUB(PT_MFOff                             ,0xfc0ab651) //  0            == 0xfc0ab651
//NHSTUB(GetAdChValue                         ,0xfc1f3577) //  0            == 0xfc1f3577
