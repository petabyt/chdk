// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   Main firmware start: 0xe0020000
//   DRYOS R58 (DRYOS version 2.3, release #0058+p10) @ 0xe05d81d4 ref @ 0xe05c5468
//   Firmware Ver GM1.01A   // Found @ 0xe0503c40, "GM1.01A" @ 0xe0503c4d

// Values for makefile.inc
//   PLATFORMOSVER = 58
//   MEMISOSTART = 0x2c460c
//   MEMBASEADDR = 0x8000
//   ARAM_HEAP_START = 0x006ce000 #  Found @0xe0560f88
//   ARAM_HEAP_SIZE = 0x00022000 #  Found @0xe0560f60

// Detected address ranges:
// ROM      0xe0000000 - 0xe2000000 (33554432 bytes)
// RAM data 0x00008000 - 0x0004c618 copied from 0xe0fd3770 ( 280088 bytes)
// RAM code 0x01900000 - 0x0190139c copied from 0xe1017d88 (   5020 bytes)
// RAM code 0xdffc4900 - 0xdffd0908 copied from 0xe1019124 (  49160 bytes)

// Zico Xtensa blobs:
// zico_0 0xbff20000 - 0xbff24ab8 copied from 0xe0e79d0c (  19128 bytes)
// zico_1 0xbff00000 - 0xbff08000 copied from 0xe0e7e7cc (  32768 bytes)
// zico_2 0x80a00000 - 0x80ad4350 copied from 0xe0e867d4 ( 869200 bytes)

// Found DryOS versions:
// 0xe0018d08 other "DRYOS version 2.3, release #0058+p10"
// 0xe05d81d4 main  "DRYOS version 2.3, release #0058+p10"
// 0xe0c260a8 other "DRYOS version 2.3, release #0058+p10"
// 0xe0e87064 other "DRYOS version 2.3, release #0058+p7"
// 0xe123e380 other "DRYOS version 2.3, release #0058+p10"

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xe046e5a0
//#define CAM_HAS_ND_FILTER 1 // Camera has ND filter
// Camera has an iris (CAM_HAS_IRIS_DIAPHRAGM default)

// physw_event_table 0xe05df098 Found @0xe004e61c
// Values below go in 'platform_kbd.h':
//#define SD_READONLY_FLAG    0x00000020 // Found @0xe05df0f8, levent 0x30a
//#define SD_READONLY_IDX     1
//#define USB_MASK            0x00400000 // Found @0xe05df1b0, levent 0x302
//#define USB_IDX             2
//#define BATTCOVER_FLAG      0x00200000 // Found @0xe05df1a8, levent 0x305
//#define BATTCOVER_IDX       2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
// WARNING: Values only verified on sx280hs (R52) and g7x (R55p6) errors likely on other cams!
//KeyMap keymap[] = {
//    { 0, KEY_PLAYBACK        ,0x00008000 }, // Found @0xe05df0b0, levent 0x101
//    { 0, KEY_VIDEO           ,0x00010000 }, // Found @0xe05df0b8, levent 0x02
//    { 0, KEY_ZOOM_IN         ,0x00020000 }, // Found @0xe05df0c0, levent 0x03
//    { 0, KEY_ZOOM_OUT        ,0x00040000 }, // Found @0xe05df0c8, levent 0x04
//    { 0, KEY_SHOOT_FULL      ,0x00180000 }, // Found @0xe05df0d0, levent 0x01
//    { 0, KEY_SHOOT_HALF      ,0x00100000 }, // Found @0xe05df0d8, levent 0x00
//    { 0, KEY_SHOOT_FULL_ONLY ,0x00080000 }, // Found @0xe05df0d0, levent 0x01
//    { 0, KEY_POWER           ,0x00200000 }, // Found @0xe05df0e0, levent 0x100
//    { 2, KEY_UP              ,0x00000200 }, // Found @0xe05df158, levent 0x06
//    { 2, KEY_DOWN            ,0x00000400 }, // Found @0xe05df160, levent 0x07
//    { 2, KEY_RIGHT           ,0x00000800 }, // Found @0xe05df168, levent 0x09
//    { 2, KEY_LEFT            ,0x00001000 }, // Found @0xe05df170, levent 0x08
//    { 2, KEY_SET             ,0x00002000 }, // Found @0xe05df178, levent 0x0a
//    { 0, 0, 0 }
//};

// canon_mode_list 0xe089d47c Found @0xe0036f2c
// Check modemap values from 'platform/CAMERA/shooting.c':
// 16455  0x4047 In firmware but not in current modemap
// 16460  0x404c In firmware but not in current modemap
// 16954  0x423a In firmware but not in current modemap
// 16968  0x4248 In firmware but not in current modemap
// 16970  0x424a In firmware but not in current modemap
// 16969  0x4249 In firmware but not in current modemap
// 16958  0x423e In firmware but not in current modemap
// 16971  0x424b In firmware but not in current modemap
// 16929  0x4221 In firmware but not in current modemap
// 16424  0x4028 In firmware but not in current modemap
//  2645  0x0a55 In firmware but not in current modemap
//  2654  0x0a5e In firmware but not in current modemap
//  2653  0x0a5d In firmware but not in current modemap
//  2655  0x0a5f In firmware but not in current modemap
// 33297  0x8211 In firmware but not in current modemap
//  4174  0x104e In firmware but not in current modemap
// Current modemap entry not found in firmware - MODE_VIDEO_M              2651
// Current modemap entry not found in firmware - MODE_VIDEO_IFRAME_MOVIE   2650
// Current modemap entry not found in firmware - MODE_VIDEO_STD            2643
// Current modemap entry not found in firmware - MODE_CREATIVE_EFFECT     33299
// Current modemap entry not found in firmware - MODE_STAR_PORTRAIT       16452
// Current modemap entry not found in firmware - MODE_POSTER_EFFECT       16947
// Current modemap entry not found in firmware - MODE_SUPER_VIVID         16946
// Current modemap entry not found in firmware - MODE_MONOCHROME          16959
// Current modemap entry not found in firmware - MODE_TOY_CAMERA          16955
// Current modemap entry not found in firmware - MODE_FISHEYE             16951
// Current modemap entry not found in firmware - MODE_NOSTALGIC           16945
// Current modemap entry not found in firmware - MODE_HDR                 16967

// Known propcases
// //      PROPCASE_AFSTEP 13
// #define PROPCASE_FOCUS_STATE 18
// #define PROPCASE_AV 23
// #define PROPCASE_BV 40
// //      PROPCASE_DELTA_DIGITALGAIN 84
//         PROPCASE_DELTA_SV not found
// //      PROPCASE_DELTA_ND 87
// //      PROPCASE_FELOCK 122
// #define PROPCASE_FLASH_ADJUST_MODE 129
// #define PROPCASE_FLASH_FIRE 130
// //      PROPCASE_HSCAPTURE 146
// #define PROPCASE_EV_CORRECTION_2 218
// #define PROPCASE_ORIENTATION_SENSOR 230
// #define PROPCASE_SV_MARKET 258
// //      PROPCASE_SVFIX 259
// #define PROPCASE_TV 275
// Guessed propset: uncertain (12 of 15 match), closest to 10

// EXMEM types:
// EXMEM_RAMDISK        0
// EXMEM_COM            1
// EXMEM_FORMATTER      2
// EXMEM_SHADING        3
// EXMEM_FAMODE         4
// EXMEM_FIRMUP         5
// EXMEM_FIRMUP_VRAM    6
// EXMEM_FIRMUP_INFLATE 7
// EXMEM_FIRMUP_PICTURESTYLE 8
// EXMEM_DVLPWORK       9
// EXMEM_EVF            10
// EXMEM_SCRIPT         11
// EXMEM_GPS            12
// EXMEM_FACEAUTH       13
// EXMEM_OHYEARLOG      14
// EXMEM_WIFI           15
// EXMEM_MULTI_PLY      16
// EXMEM_FEP            17
// EXMEM_LENS_FIRMUP    18
// EXMEM_LENS_COMPENSATION 19
// EXMEM_FILESTORE      20
// EXMEM_MOVIE_REC      21
// EXMEM_MOVIE_PLY      22
// EXMEM_WIFI_RESIZE    23
// EXMEM_PCEVF          24
// EXMEM_WIDE           25
// EXMEM_PIPELINE       26
// EXMEM_AUTO_GIS_MODE  27
// EXMEM_NP_GIS_MODE    28
// EXMEM_TRIPODHDR_MODE 29
// EXMEM_HSHQ_MODE      30
// EXMEM_CRAW_REC       31
// EXMEM_BACKBLUR       32
// EXMEM_ASTRO          33
// EXMEM_TIME_LAPSE_MOVIE 34

// Values below can be overridden in 'stubs_min.S':
DEF(ctypes                            ,0xe05d8334) // Found @0xe00386cc
DEF(physw_run                         ,0x00008370) // Found @0xe005b31a
DEF(physw_sleep_delay                 ,0x00008378) // (0x8370+0x8) Found @0xe005b31e
DEF(physw_status                      ,0x0004e448) // Found @0xe005b632
DEF(fileio_semaphore                  ,0x000111c4) // Found @0xe0036d16
DEF(levent_table                      ,0xe066c260) // Found @0xe00f3098
DEF(FlashParamsTable                  ,0xe089d83c) // Found @0xe0036f40
DEF(playrec_mode                      ,0x0000c1d8) // (0xc1d4+0x4) Found @0xe02f082a
DEF(jpeg_count_str                    ,0x0014dd38) // Found @0xe01a81d8
DEF(zoom_busy                         ,0x00011664) // (0x11644+0x20) Found @0xe005f92a
DEF(focus_busy                        ,0x0001141c) // (0x113f8+0x24) Found @0xe0372082
DEF(imager_active                     ,0x000086f4) // (0x86f0+0x4) Found @0xe045be1e
DEF(_nrflag                           ,0x00026278) // (0x26274+0x4) Found @0xe005efac
DEF(av_override_semaphore             ,0x00036fb8) // Found @0xe0566f90
DEF(active_bitmap_buffer              ,0x0000cdc0) // (0xcd74+0x4c) Found @0xe03789c2
DEF_CONST(uiprop_count                      ,0x000000df) // Found @0xe0271bce
DEF(exmem_alloc_table                 ,0x00058290) // Found @0xe0055d96
DEF(exmem_types_table                 ,0xe0fd7a20) // Found @0xe0055d9a
DEF_CONST(exmem_type_count                  ,0x00000023) // Found @0xe0fd7a20
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 2 int value(s), the first is the zoom focus length.
// there are 101 entries in the table - set NUM_FL to 101
DEF(focus_len_table                         ,0xe1f3169c) // Found @0xe1f3169c

//NHSTUB(TurnOnBackLight                      ,0xe0439adf) //  0        *** != 0x00000000
//NHSTUB(_sqrt                                ,0x00000000) //  0        *** != 0xdffcf241
//NHSTUB(strcat                               ,0x00000000) //  0        *** != 0xe04968ad
//NHSTUB(strchr                               ,0x00000000) //  0        *** != 0xe045197e
//   DEF(task_PhySw                           ,0x00000000) //  0        *** != 0xe005b319
//NHSTUB(SetHPTimerAfterNow                   ,0x00000000) //  0        *** != 0xe03f4ac1

NHSTUB(AllocateUncacheableMemory              ,0xe046e571) //  0
NHSTUB(Close                                  ,0xe0373eb7) //  0
NHSTUB(CreateBinarySemaphore                  ,0xdffc9fd5) //  0
NHSTUB(CreateTask                             ,0xdffc93bb) //  0
NHSTUB(DebugAssert                            ,0xdffc96f5) //  0
NHSTUB(DeleteDirectory_Fut                    ,0xe0370f15) //  0
NHSTUB(DeleteFile_Fut                         ,0xe0370ecb) //  0
NHSTUB(DoAELock                               ,0xe0298e1d) //  0
NHSTUB(DoAFLock                               ,0xe02989e7) //  0
//NHSTUB(EnterToCompensationEVF               ,0x00000000) //  0            == 0x00000000
NHSTUB2(ExecuteEventProcedure                  ,0xe03703e3) //  0
//NHSTUB(ExitFromCompensationEVF              ,0x00000000) //  0            == 0x00000000
NHSTUB(ExitTask                               ,0xdffc95af) //  0
//NHSTUB(ExpCtrlTool_StartContiAE             ,0x00000000) //  0            == 0x00000000
//NHSTUB(ExpCtrlTool_StopContiAE              ,0x00000000) //  0            == 0x00000000
NHSTUB(Fclose_Fut                             ,0xe0370f77) //  0
//NHSTUB(Feof_Fut                             ,0x00000000) //  0            == 0x00000000
//NHSTUB(Fflush_Fut                           ,0x00000000) //  0            == 0x00000000
NHSTUB(Fgets_Fut                              ,0xe037105b) //  0
NHSTUB(Fopen_Fut                              ,0xe0370f4f) //  0
NHSTUB(Fread_Fut                              ,0xe0370feb) //  0
NHSTUB(FreeUncacheableMemory                  ,0xe046e59d) //  0
NHSTUB(Fseek_Fut                              ,0xe037108d) //  0
NHSTUB(Fwrite_Fut                             ,0xe0371023) //  0
NHSTUB(GetBatteryTemperature                  ,0xe04011cd) //  0
NHSTUB(GetCCDTemperature                      ,0xe0401177) //  0
NHSTUB(GetCurrentAvValue                      ,0xe0062bad) //  0
NHSTUB(GetCurrentShutterSpeed                 ,0xe00720a9) //  0
NHSTUB(GetUsableMaxAv                         ,0xe0560021) //  0
NHSTUB(GetUsableMinAv                         ,0xe056000f) //  0
NHSTUB(get_nd_value                           ,0xe04fd7af) //  0
NHSTUB(get_current_nd_value                   ,0xe04fd789) //  0
NHSTUB(GetDrive_ClusterSize                   ,0xe0374c35) //  0
NHSTUB(GetDrive_FreeClusters                  ,0xe0375149) //  0
//NHSTUB(GetDrive_TotalClusters               ,0x00000000) //  0            == 0x00000000
NHSTUB(GetFocusLensSubjectDistance            ,0xe0372bf5) //  0
//NHSTUB(GetFocusLensSubjectDistanceFromLens  ,0x00000000) //  0            == 0x00000000
//NHSTUB(GetImageFolder                       ,0x00000000) //  0            == 0x00000000
NHSTUB(GetKbdState                            ,0xe004e73b) //  0
NHSTUB(GetMemInfo                             ,0xe0006ff1) //  0
NHSTUB(GetOpticalTemperature                  ,0xe0401223) //  0
NHSTUB(GetParameterData                       ,0xe02725cf) //  0
NHSTUB(GetPropertyCase                        ,0xe036af69) //  0
NHSTUB(GetSystemTime                          ,0xe0569be7) //  0
NHSTUB(GetVRAMHPixelsSize                     ,0xe040bdf5) //  0
NHSTUB(GetVRAMVPixelsSize                     ,0xe040bdfd) //  0
NHSTUB(GetZoomLensCurrentPoint                ,0xe005fb75) //  0
NHSTUB(GetZoomLensCurrentPosition             ,0xe005fb09) //  0
NHSTUB(GiveSemaphore                          ,0xdffca149) //  0
NHSTUB(IsStrobeChargeCompleted                ,0xe053b423) //  0
NHSTUB(LEDDrive                               ,0xe0551f95) //  0
NHSTUB(LocalTime                              ,0xdffca8bb) //  0
NHSTUB(LockMainPower                          ,0xe04d05fb) //  0
NHSTUB(MakeDirectory_Fut                      ,0xe037422f) //  0
//NHSTUB(MakeSDCardBootable                   ,0x00000000) //  0            == 0x00000000
NHSTUB(MoveFocusLensToDistance                ,0xe0592197) //  0
NHSTUB(MoveIrisWithAv                         ,0xe0566f7d) //  0
NHSTUB(MoveZoomLensWithPoint                  ,0xe0567d09) //  0
NHSTUB(Open                                   ,0xe0373e7b) //  0
NHSTUB(PB2Rec                                 ,0xe035dfcb) //  0
NHSTUB(PT_MoveDigitalZoomToWide               ,0xe02982c3) //  0
NHSTUB(PT_MoveOpticalZoomAt                   ,0xe0552e39) //  0
NHSTUB(MoveOpticalZoomAt                      ,0xe02980f9) //  0
//NHSTUB(PT_PlaySound                         ,0x00000000) //  0            == 0x00000000
NHSTUB(PostLogicalEventForNotPowerType        ,0xe037a839) //  0
NHSTUB(PostLogicalEventToUI                   ,0xe037a86d) //  0
NHSTUB(PutInNdFilter                          ,0xe059244d) //  0
NHSTUB(PutOutNdFilter                         ,0xe0592473) //  0
NHSTUB(Read                                   ,0xe0451397) //  0
NHSTUB(ReadFastDir                            ,0xe0373fef) //  0
NHSTUB(Rec2PB                                 ,0xe035e00f) //  0
//NHSTUB(RenameFile_Fut                       ,0x00000000) //  0            == 0x00000000
//NHSTUB(Restart                              ,0x00000000) //  0            == 0x00000000
//NHSTUB(ScreenLock                           ,0x00000000) //  0            == 0x00000000
//NHSTUB(ScreenUnlock                         ,0x00000000) //  0            == 0x00000000
NHSTUB(SetAE_ShutterSpeed                     ,0xe0583cd9) //  0
NHSTUB(SetAutoShutdownTime                    ,0xe04d064b) //  0
NHSTUB(SetCurrentCaptureModeType              ,0xe037ca81) //  0
//NHSTUB(SetFileAttributes                    ,0x00000000) //  0            == 0x00000000
//NHSTUB(SetFileTimeStamp                     ,0x00000000) //  0            == 0x00000000
NHSTUB(SetLogicalEventActive                  ,0xe0371cdf) //  0
//NHSTUB(SetParameterData                     ,0x00000000) //  0            == 0x00000000
NHSTUB(SetPropertyCase                        ,0xe036ae25) //  0
NHSTUB(SetScriptMode                          ,0xe0371d17) //  0
NHSTUB(SleepTask                              ,0xdffc9293) //  0
NHSTUB(TakeSemaphore                          ,0xdffca0cf) //  0
//NHSTUB(TurnOffBackLight                     ,0x00000000) //  0            == 0x00000000
NHSTUB(TurnOnDisplay                          ,0xe01082cb) //  0
NHSTUB(TurnOffDisplay                         ,0xe043985d) //  0
NHSTUB(UnlockAE                               ,0xe0298e3b) //  0
NHSTUB(UnlockAF                               ,0xe0298a17) //  0
NHSTUB(UnlockMainPower                        ,0xe04d0597) //  0
//NHSTUB(UnsetZoomForMovie                    ,0x00000000) //  0            == 0x00000000
NHSTUB(VbattGet                               ,0xe04912c5) //  0
NHSTUB(Write                                  ,0xe0373e3d) //  0
//NHSTUB(WriteSDCard                          ,0x00000000) //  0            == 0x00000000
NHSTUB(_log                                   ,0xdffcd8c5) //  0
NHSTUB(_log10                                 ,0xdffcdc39) //  0
NHSTUB(_pow                                   ,0xdffcdd31) //  0
NHSTUB(add_ptp_handler                        ,0xe02f31db) //  0
//NHSTUB(apex2us                              ,0x00000000) //  0            == 0x00000000
NHSTUB(close                                  ,0xe0451293) //  0
NHSTUB(exmem_alloc                            ,0xe005629b) //  0
NHSTUB(exmem_free                             ,0xe00562dd) //  0
NHSTUB(free                                   ,0xe0475173) //  0
NHSTUB(kbd_p1_f                               ,0xe005b62b) //  0
NHSTUB(kbd_p1_f_cont                          ,0xe005b633) //  0
NHSTUB(kbd_p2_f                               ,0xe005b079) //  0
NHSTUB(kbd_read_keys                          ,0xe005b5f5) //  0
NHSTUB(kbd_read_keys_r2                       ,0xe004e617) //  0
NHSTUB(lseek                                  ,0xe0374089) //  0
NHSTUB(malloc                                 ,0xe047513b) //  0
NHSTUB(memcmp                                 ,0xe03bf171) //  0
NHSTUB(memcpy                                 ,0xe03bf519) //  0
NHSTUB(memset                                 ,0xe04ac7e1) //  0
NHSTUB(mktime_ext                             ,0xe01d7c5d) //  0
NHSTUB(open                                   ,0xe0451221) //  0
NHSTUB(OpenFastDir                            ,0xe03fa861) //  0
NHSTUB(closedir                               ,0xe03fa829) //  0
NHSTUB(get_fstype                             ,0xe0374bcf) //  0
NHSTUB(qsort                                  ,0xe041ca3f) //  0
NHSTUB(rand                                   ,0xe052b617) //  0
//NHSTUB(reboot_fw_update                     ,0x00000000) //  0            == 0x00000000
NHSTUB(set_control_event                      ,0xe0371a61) //  0
NHSTUB(srand                                  ,0xe052b611) //  0
NHSTUB(stat                                   ,0xe03740bd) //  0
NHSTUB(strcmp                                 ,0xe037a0c1) //  0
NHSTUB(strcpy                                 ,0xe037e6a5) //  0
NHSTUB(strftime                               ,0xe0523989) //  0
NHSTUB(strlen                                 ,0xe037e6c7) //  0
NHSTUB(strncmp                                ,0xe0422079) //  0
NHSTUB(strncpy                                ,0xe0484f57) //  0
NHSTUB(strrchr                                ,0xe04b23dd) //  0
NHSTUB(strtol                                 ,0xe000f9d3) //  0
NHSTUB(strtolx                                ,0xe04e8375) //  0
   DEF(task_CaptSeq                           ,0xe0032f57) //  0
   DEF(task_DvlpSeqTask                       ,0xe004b693) //  0
   DEF(task_ExpDrv                            ,0xe02d0ad9) //  0
   DEF(task_FileWrite                         ,0xe03af92b) //  0
   DEF(task_InitFileModules                   ,0xe04200b1) //  0
   DEF(task_MovieRecord                       ,0xe038f12f) //  0
   DEF(task_TricInitTask                      ,0xe025d527) //  0
   DEF(hook_CreateTask                        ,0xdffc93ba) //  0
NHSTUB(time                                   ,0xdffca509) //  0
NHSTUB(vsprintf                               ,0xe0463383) //  0
//NHSTUB(EngDrvRead                           ,0x00000000) //  0            == 0x00000000
NHSTUB(PTM_GetCurrentItem                     ,0xe0376d2b) //  0
NHSTUB(DisableISDriveError                    ,0xe0568923) //  0
//NHSTUB(CancelHPTimer                        ,0x00000000) //  0            == 0x00000000
NHSTUB(SetEventFlag                           ,0xdffc9939) //  0
NHSTUB(transfer_src_overlay                   ,0xe0377dbb) //  0
NHSTUB(bzero                                  ,0xdffcc545) //  0
NHSTUB(memset32                               ,0xdffcc549) //  0
NHSTUB(PT_MFOn                                ,0xe0299ea5) //  0
NHSTUB(PT_MFOff                               ,0xe0299ed9) //  0
NHSTUB(GetAdChValue                           ,0xe04d970f) //  0
NHSTUB(EnableHDMIPower                        ,0xe005bd31) //  0
NHSTUB(DisableHDMIPower                       ,0xe005bd67) //  0
