// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   Main firmware start: 0xfc020000
//   DRYOS R54 (DRYOS version 2.3, release #0054+p3)
//   Firmware Ver GM1.00D   // Found @ 0xfc136788, "GM1.00D" @ 0xfc136795

// Values for makefile.inc
//   PLATFORMOSVER = 54
//   MEMISOSTART = 0x35bb28
//   MEMBASEADDR = 0x8000
//   ARAM_HEAP_START = 0x006ce000 #  Found @0xfc1bc94c
//   ARAM_HEAP_SIZE = 0x00022000 #  Found @0xfc1bc926

// Detected address ranges:
// ROM      0xfc000000 - 0xfe000000 (33554432 bytes)
// RAM code 0x010c1000 - 0x010df808 copied from 0xfcc64f9c ( 124936 bytes)
// RAM data 0x00008000 - 0x0002efdc copied from 0xfcc3dfc0 ( 159708 bytes)

// Zico Xtensa blobs:
// zico_0 0xbff20000 - 0xbff27398 copied from 0xfca30f2c (  29592 bytes)
// zico_1 0xbff00000 - 0xbff04a70 copied from 0xfca382cc (  19056 bytes)
// zico_2 0x80a00000 - 0x80b09020 copied from 0xfca3cd44 (1085472 bytes)

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xfc148d64
//#undef CAM_HAS_ND_FILTER // Camera does not have an ND filter
// Camera has an iris (CAM_HAS_IRIS_DIAPHRAGM default)

// physw_event_table 0xfc569720 Found @0xfc06e124
// Values below go in 'platform_kbd.h':
//#define SD_READONLY_FLAG    0x20000000 // Found @0xfc5697a8, levent 0x20a
//#define SD_READONLY_IDX     1
//#define USB_MASK            0x10000000 // Found @0xfc569828, levent 0x202
//#define USB_IDX             2
//#define BATTCOVER_FLAG      0x04000000 // Found @0xfc569820, levent 0x205
//#define BATTCOVER_IDX       2
//#define ANALOG_AV_FLAG      0x00008000 // Found @0xfc569790, levent 0x200 (non-inverted logic)
//#define ANALOG_AV_IDX       1

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
// WARNING: Values only verified on sx280hs (R52) and g7x (R55p6) errors likely on other cams!
//KeyMap keymap[] = {
//    { 0, KEY_POWER           ,0x00000001 }, // Found @0xfc569720, levent 0x100
//    { 0, KEY_PLAYBACK        ,0x00000002 }, // Found @0xfc569728, levent 0x101
//    { 0, KEY_SHOOT_FULL      ,0x0000000c }, // Found @0xfc569738, levent 0x01
//    { 0, KEY_SHOOT_FULL_ONLY ,0x00000008 }, // Found @0xfc569738, levent 0x01
//    { 0, KEY_SHOOT_HALF      ,0x00000004 }, // Found @0xfc569730, levent 0x00
//    { 0, KEY_VIDEO           ,0x00000100 }, // Found @0xfc569740, levent 0x02
//    { 0, KEY_MENU            ,0x00000200 }, // Found @0xfc569748, levent 0x0e
//    { 0, KEY_HELP            ,0x00002000 }, // Found @0xfc569750, levent 0x0d
//    { 0, KEY_UP              ,0x00004000 }, // Found @0xfc569758, levent 0x06
//    { 0, KEY_DOWN            ,0x00008000 }, // Found @0xfc569760, levent 0x07
//    { 0, KEY_RIGHT           ,0x00010000 }, // Found @0xfc569768, levent 0x09
//    { 1, KEY_LEFT            ,0x00000004 }, // Found @0xfc569770, levent 0x08
//    { 1, KEY_SET             ,0x00000008 }, // Found @0xfc569778, levent 0x0a
//    { 0, 0, 0 }
//};

// canon_mode_list 0xfc8677b4 Found @0xfc3762e4
// Check modemap values from 'platform/CAMERA/shooting.c':
// 33335  0x8237 In firmware but not in current modemap
// 32832  0x8040 In firmware but not in current modemap
// 16943  0x422f In firmware but not in current modemap
// 16945  0x4231 In firmware but not in current modemap
// 33295  0x820f In firmware but not in current modemap

// Known propcases
// //      PROPCASE_AFSTEP 13
// #define PROPCASE_FOCUS_STATE 18
// #define PROPCASE_AV 23
// #define PROPCASE_BV 34
// //      PROPCASE_DELTA_DIGITALGAIN 77
// #define PROPCASE_DELTA_SV 79
// //      PROPCASE_DELTA_ND 80
// #define PROPCASE_EV_CORRECTION_2 210
// #define PROPCASE_ORIENTATION_SENSOR 222
// #define PROPCASE_SV_MARKET 249
// //      PROPCASE_SVFIX 250
// #define PROPCASE_TV 265
// Guessed propset: 6

// EXMEM types:
// EXMEM_RAMDISK        0
// EXMEM_COM            1
// EXMEM_FORMATTER      2
// EXMEM_SHADING        3
// EXMEM_FAMODE         4
// EXMEM_FIRMUP         5
// EXMEM_FIRMUP_VRAM    6
// EXMEM_FIRMUP_INFLATE 7
// EXMEM_DVLPWORK       8
// EXMEM_EVF            9
// EXMEM_SCRIPT         10
// EXMEM_GPS            11
// EXMEM_FACEAUTH       12
// EXMEM_OHYEARLOG      13
// EXMEM_WIFI           14
// EXMEM_MULTI_PLY      15
// EXMEM_FEP            16
// EXMEM_FILESTORE      17
// EXMEM_MOVIE_REC      18
// EXMEM_MOVIE_PLY      19
// EXMEM_WIFI_RESIZE    20
// EXMEM_PCEVF          21
// EXMEM_WIDE           22
// EXMEM_NARROW         23
// EXMEM_AUTO_GIS_MODE  24
// EXMEM_NP_GIS_MODE    25
// EXMEM_TRIPODHDR_MODE 26
// EXMEM_HSHQ_MODE      27
// EXMEM_CRAW_REC       28
// EXMEM_CREATIVE_SHOT  29
// EXMEM_BACKBLUR       30

// Values below can be overridden in 'stubs_min.S':
DEF(ctypes                            ,0xfc514d0c)
DEF(physw_run                         ,0x000082c8) // Found @0xfc07a0be
DEF(physw_sleep_delay                 ,0x000082d0) // (0x82c8+0x8) Found @0xfc07a0c2
DEF(physw_status                      ,0x000308b0) // Found @0xfc07a3bc
DEF(fileio_semaphore                  ,0x00013264) // Found @0xfc06c076
DEF(levent_table                      ,0xfc6359c0) // Found @0xfc0bb214
DEF(FlashParamsTable                  ,0xfc867a6c) // Found @0xfc3762f8
DEF(playrec_mode                      ,0x0000bbb4) // (0xbbb0+0x4) Found @0xfc2b7296
DEF(jpeg_count_str                    ,0x00157130) // Found @0xfc1f5b46
DEF(zoom_busy                         ,0x0000b88c) // (0xb86c+0x20) Found @0xfc12aa4e
DEF(focus_busy                        ,0x00013448) // (0x13440+0x8) Found @0xfc2dc156
DEF(imager_active                     ,0x0000863c) // (0x8638+0x4) Found @0xfc11ce32
DEF(_nrflag                           ,0x0001b8e4) // (0x1b8e0+0x4) Found @0xfc31471a
DEF(active_bitmap_buffer              ,0x0000c784) // (0xc754+0x30) Found @0xfc30d428
DEF_CONST(uiprop_count                      ,0x0000009d) // Found @0xfc0bb6b8
DEF(exmem_alloc_table                 ,0x00037a40) // Found @0xfc06e71e
DEF(exmem_types_table                 ,0xfcc41c3c) // Found @0xfc06e722
DEF_CONST(exmem_type_count                  ,0x0000001f) // Found @0xfcc41c3c

//NHSTUB(EnterToCompensationEVF               ,0x00000000) //  0        *** != 0xfc25c275
//NHSTUB(ExitFromCompensationEVF              ,0x00000000) //  0        *** != 0xfc25c2af
//NHSTUB(ExpCtrlTool_StartContiAE             ,0x00000000) //  0        *** != 0xfc24d425
//NHSTUB(ExpCtrlTool_StopContiAE              ,0x00000000) //  0        *** != 0xfc24d505
//NHSTUB(Feof_Fut                             ,0x00000000) //  0        *** != 0xfc2d7e91
//NHSTUB(Fflush_Fut                           ,0x00000000) //  0        *** != 0xfc2d7eb9
//NHSTUB(GetDrive_TotalClusters               ,0x00000000) //  0        *** != 0xfc307aad
//NHSTUB(GetFocusLensSubjectDistanceFromLens  ,0x00000000) //  0        *** != 0xfc2dd03d
//NHSTUB(GetImageFolder                       ,0x00000000) //  0        *** != 0xfc2e08d5
//NHSTUB(MakeSDCardBootable                   ,0x00000000) //  0        *** != 0xfc307ebb
//NHSTUB(RenameFile_Fut                       ,0x00000000) //  0        *** != 0xfc2d7c41
//NHSTUB(Restart                              ,0x00000000) //  0        *** != 0xfc0a6eed
//NHSTUB(SetFileAttributes                    ,0x00000000) //  0        *** != 0xfc30826d
//NHSTUB(SetFileTimeStamp                     ,0x00000000) //  0        *** != 0xfc308225
//NHSTUB(SetParameterData                     ,0x00000000) //  0        *** != 0xfc0bbe2f
//NHSTUB(WriteSDCard                          ,0x00000000) //  0        *** != 0xfc0e857d
//NHSTUB(apex2us                              ,0x00000000) //  0        *** != 0xfc31375f
//NHSTUB(reboot_fw_update                     ,0x00000000) //  0        *** != 0xfc370cb1
//NHSTUB(CancelHPTimer                        ,0x00000000) //  0        *** != 0xfc1361c1

NHSTUB(AllocateUncacheableMemory              ,0xfc148d35) //  0
NHSTUB(Close                                  ,0xfc307fd9) //  0
NHSTUB(CreateBinarySemaphore                  ,0x010c5919) //  0
NHSTUB(CreateTask                             ,0x010c5075) //  0
NHSTUB(DebugAssert                            ,0x010c5c6d) //  0
NHSTUB(DeleteDirectory_Fut                    ,0xfc2d7ced) //  0
NHSTUB(DeleteFile_Fut                         ,0xfc2d7ca3) //  0
NHSTUB(DoAELock                               ,0xfc25c2fd) //  0
NHSTUB(DoAFLock                               ,0xfc25bf8b) //  0
NHSTUB2(ExecuteEventProcedure                  ,0xfc2ddc65) //  0
NHSTUB(ExitTask                               ,0x010c5249) //  0
NHSTUB(Fclose_Fut                             ,0xfc2d7d4f) //  0
NHSTUB(Fgets_Fut                              ,0xfc2d7e2d) //  0
NHSTUB(Fopen_Fut                              ,0xfc2d7d27) //  0
NHSTUB(Fread_Fut                              ,0xfc2d7dc1) //  0
NHSTUB(FreeUncacheableMemory                  ,0xfc148d61) //  0
NHSTUB(Fseek_Fut                              ,0xfc2d7e5f) //  0
NHSTUB(Fwrite_Fut                             ,0xfc2d7df7) //  0
NHSTUB(GetBatteryTemperature                  ,0xfc1245f9) //  0
NHSTUB(GetCCDTemperature                      ,0xfc12459d) //  0
NHSTUB(GetCurrentAvValue                      ,0xfc12a5f1) //  0
NHSTUB(GetCurrentShutterSpeed                 ,0xfc14982b) //  0
NHSTUB(GetUsableMaxAv                         ,0xfc1a2d47) //  0
NHSTUB(GetUsableMinAv                         ,0xfc1a2d35) //  0
NHSTUB(GetDrive_ClusterSize                   ,0xfc3075a3) //  0
NHSTUB(GetDrive_FreeClusters                  ,0xfc307ad1) //  0
NHSTUB(GetFocusLensSubjectDistance            ,0xfc2dcd43) //  0
NHSTUB(GetKbdState                            ,0xfc06e207) //  0
NHSTUB(GetMemInfo                             ,0xfc3d4e4d) //  0
NHSTUB(GetOpticalTemperature                  ,0xfc124653) //  0
NHSTUB(GetParameterData                       ,0xfc0bbeaf) //  0
NHSTUB(GetPropertyCase                        ,0xfc2ef619) //  0
NHSTUB(GetSystemTime                          ,0xfc40e8a9) //  0
NHSTUB(GetVRAMHPixelsSize                     ,0xfc120139) //  0
NHSTUB(GetVRAMVPixelsSize                     ,0xfc120141) //  0
NHSTUB(GetZoomLensCurrentPoint                ,0xfc12ac99) //  0
NHSTUB(GetZoomLensCurrentPosition             ,0xfc12ac2d) //  0
NHSTUB(GiveSemaphore                          ,0x010c5a85) //  0
NHSTUB(IsStrobeChargeCompleted                ,0xfc16c76f) //  0
NHSTUB(LEDDrive                               ,0xfc1b69dd) //  0
NHSTUB(LocalTime                              ,0x010c6281) //  0
NHSTUB(LockMainPower                          ,0xfc136d3b) //  0
NHSTUB(MakeDirectory_Fut                      ,0xfc3082c3) //  0
NHSTUB(MoveFocusLensToDistance                ,0xfc45d3c7) //  0
NHSTUB(MoveIrisWithAv                         ,0xfc40cce5) //  0
NHSTUB(MoveZoomLensWithPoint                  ,0xfc40d495) //  0
NHSTUB(Open                                   ,0xfc307f55) //  0
NHSTUB(PB2Rec                                 ,0xfc0cd7a9) //  0
NHSTUB(PT_MoveDigitalZoomToWide               ,0xfc25b8e3) //  0
NHSTUB(PT_MoveOpticalZoomAt                   ,0xfc1b7861) //  0
NHSTUB(MoveOpticalZoomAt                      ,0xfc25b709) //  0
NHSTUB(PT_PlaySound                           ,0xfc13a1c5) //  0
NHSTUB(PostLogicalEventForNotPowerType        ,0xfc305f85) //  0
NHSTUB(PostLogicalEventToUI                   ,0xfc305fb1) //  0
NHSTUB(PutInNdFilter                          ,0xfc45d6a9) //  0
NHSTUB(PutOutNdFilter                         ,0xfc45d6cf) //  0
NHSTUB(Read                                   ,0xfc119c45) //  0
NHSTUB(ReadFastDir                            ,0xfc0fafd1) //  0
NHSTUB(Rec2PB                                 ,0xfc0cd7e7) //  0
NHSTUB(ScreenLock                             ,0xfc30d377) //  0
NHSTUB(ScreenUnlock                           ,0xfc30d3b5) //  0
NHSTUB(SetAE_ShutterSpeed                     ,0xfc459ed9) //  0
NHSTUB(SetAutoShutdownTime                    ,0xfc136d87) //  0
NHSTUB(SetCurrentCaptureModeType              ,0xfc2de889) //  0
NHSTUB(SetLogicalEventActive                  ,0xfc3069cf) //  0
NHSTUB(SetPropertyCase                        ,0xfc2ef4e3) //  0
NHSTUB(SetScriptMode                          ,0xfc306a07) //  0
NHSTUB(SleepTask                              ,0x010c4fdd) //  0
NHSTUB(TakeSemaphore                          ,0x010c5a0d) //  0
NHSTUB(TurnOffBackLight                       ,0xfc12138f) //  0
NHSTUB(TurnOnBackLight                        ,0xfc12134f) //  0
NHSTUB(TurnOnDisplay                          ,0xfc0e3a7d) //  0
NHSTUB(TurnOffDisplay                         ,0xfc0e3a8f) //  0
NHSTUB(UnlockAE                               ,0xfc25c31b) //  0
NHSTUB(UnlockAF                               ,0xfc25bfb3) //  0
NHSTUB(UnlockMainPower                        ,0xfc136cd7) //  0
//NHSTUB(UnsetZoomForMovie                    ,0x00000000) //  0            == 0x00000000
NHSTUB(VbattGet                               ,0xfc11a603) //  0
NHSTUB(Write                                  ,0xfc308011) //  0
NHSTUB(_log                                   ,0x010daf58) //  0
NHSTUB(_log10                                 ,0x010db478) //  0
NHSTUB(_pow                                   ,0x010db5e0) //  0
NHSTUB(_sqrt                                  ,0x010dd660) //  0
NHSTUB(add_ptp_handler                        ,0xfc0b2b47) //  0
NHSTUB(close                                  ,0xfc119b3f) //  0
NHSTUB(exmem_alloc                            ,0xfc06ebed) //  0
NHSTUB(exmem_free                             ,0xfc06ec2d) //  0
NHSTUB(free                                   ,0xfc30fc1f) //  0
NHSTUB(kbd_p1_f                               ,0xfc07a3b5) //  0
NHSTUB(kbd_p1_f_cont                          ,0xfc07a3bd) //  0
NHSTUB(kbd_p2_f                               ,0xfc079e89) //  0
NHSTUB(kbd_read_keys                          ,0xfc07a37f) //  0
NHSTUB(kbd_read_keys_r2                       ,0xfc06e121) //  0
NHSTUB(lseek                                  ,0xfc308135) //  0
NHSTUB(malloc                                 ,0xfc30fbe9) //  0
NHSTUB(memcmp                                 ,0xfc30fc63) //  0
NHSTUB(memcpy                                 ,0xfc0d9221) //  0
NHSTUB(memset                                 ,0xfc1fec91) //  0
NHSTUB(mktime_ext                             ,0xfc3d6acd) //  0
NHSTUB(open                                   ,0xfc119acf) //  0
NHSTUB(OpenFastDir                            ,0xfc0faf31) //  0
NHSTUB(closedir                               ,0xfc0faef9) //  0
NHSTUB(get_fstype                             ,0xfc30753d) //  0
NHSTUB(qsort                                  ,0xfc3ed7ad) //  0
NHSTUB(rand                                   ,0xfc1fec73) //  0
NHSTUB(set_control_event                      ,0xfc306715) //  0
NHSTUB(srand                                  ,0xfc1fec6d) //  0
NHSTUB(stat                                   ,0xfc30816d) //  0
NHSTUB(strcat                                 ,0xfc30faa1) //  0
NHSTUB(strchr                                 ,0xfc13c909) //  0
NHSTUB(strcmp                                 ,0xfc30fb0b) //  0
NHSTUB(strcpy                                 ,0xfc30fae7) //  0
NHSTUB(strftime                               ,0xfc13c341) //  0
NHSTUB(strlen                                 ,0xfc30fb5d) //  0
NHSTUB(strncmp                                ,0xfc13c8df) //  0
NHSTUB(strncpy                                ,0xfc30fac3) //  0
NHSTUB(strrchr                                ,0xfc0d92b5) //  0
NHSTUB(strtol                                 ,0xfc13c8a7) //  0
NHSTUB(strtolx                                ,0xfc13c765) //  0
   DEF(task_CaptSeq                           ,0xfc12ded5) //  0
   DEF(task_DvlpSeqTask                       ,0xfc1ba5c3) //  0
   DEF(task_ExpDrv                            ,0xfc276a8d) //  0
   DEF(task_FileWrite                         ,0xfc0640ad) //  0
   DEF(task_InitFileModules                   ,0xfc0aa0f9) //  0
   DEF(task_MovieRecord                       ,0xfc1b41af) //  0
   DEF(task_PhySw                             ,0xfc07a0bd) //  0
   DEF(task_TricInitTask                      ,0xfc3c5f15) //  0
   DEF(hook_CreateTask                        ,0x010c5074) //  0
NHSTUB(time                                   ,0x010c5f21) //  0
NHSTUB(vsprintf                               ,0xfc0afa5b) //  0
NHSTUB(EngDrvRead                             ,0xfc30f98d) //  0
NHSTUB(PTM_GetCurrentItem                     ,0xfc30f70d) //  0
NHSTUB(DisableISDriveError                    ,0xfc40db25) //  0
NHSTUB(SetHPTimerAfterNow                     ,0xfc136129) //  0
NHSTUB(SetEventFlag                           ,0x010c547b) //  0
NHSTUB(transfer_src_overlay                   ,0xfc30ca55) //  0
NHSTUB(bzero                                  ,0x010d87a0) //  0
NHSTUB(memset32                               ,0x010d87a4) //  0
NHSTUB(PT_MFOn                                ,0xfc25d1ef) //  0
NHSTUB(PT_MFOff                               ,0xfc25d21f) //  0
NHSTUB(GetAdChValue                           ,0xfc0cf6f3) //  0
NHSTUB(EnableHDMIPower                        ,0xfc0ab41b) //  0
NHSTUB(DisableHDMIPower                       ,0xfc0ab451) //  0
