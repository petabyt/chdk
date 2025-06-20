// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   Main firmware start: 0xfc020000
//   DRYOS R58 (DRYOS version 2.3, release #0058+p3) @ 0xfc6774f0 ref @ 0xfc0405a8
//   Firmware Ver GM1.01A   // Found @ 0xfc4546e0, "GM1.01A" @ 0xfc4546ed

// Values for makefile.inc
//   PLATFORMOSVER = 58
//   DIGIC = 60
//   MEMISOSTART = 0x39124c
//   MEMBASEADDR = 0x8000
//   ARAM_HEAP_START = 0x006ce000#  Found @0xfc5e5154
//   ARAM_HEAP_SIZE = 0x00022000#  Found @0xfc5e512e

// Detected address ranges:
// ROM      0xfc000000 - 0xfe000000 (33554432 bytes)
// RAM code 0x010e1000 - 0x010fbd18 copied from 0xfcee2140 ( 109848 bytes)
// TCM code 0xbfe10800 - 0xbfe176a9 copied from 0xfcefce58 (  28329 bytes)
// RAM data 0x00008000 - 0x0003d674 copied from 0xfceacacc ( 218740 bytes)
// EVEC     0x00000000 - 0x00000038 copied from 0xfc06630c (     56 bytes)

// Zico Xtensa blobs:
// zico_0 0xbff20000 - 0xbff27a30 copied from 0xfcc91440 (  31280 bytes)
// zico_1 0xbff00000 - 0xbff04ad0 copied from 0xfcc98e78 (  19152 bytes)
// zico_2 0x80a00000 - 0x80b16748 copied from 0xfcc9d950 (1140552 bytes)

// Omar ARM blobs:
// omar_0 0xdff00000 - 0xdff00e90 copied from 0xfc677728 (   3728 bytes)
// omar_1 0x40700000 - 0x407505a0 copied from 0xfc6785b8 ( 329120 bytes)

// Found DryOS versions:
// 0xfc6774f0 main  "DRYOS version 2.3, release #0058+p3"
// 0xfc68e2cc other "DRYOS version 2.3, release #0058+p3"
// 0xfcc9eb10 other "DRYOS version 2.3, release #0058+p3"

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xfc16f620
//#define CAM_HAS_ND_FILTER 1 // Camera has ND filter
// Camera has an iris (CAM_HAS_IRIS_DIAPHRAGM default)

// physw_event_table 0xfc6ce9bc Found @0xfc09b5a0
// Values below go in 'platform_kbd.h':
//#define SD_READONLY_FLAG    0x20000000 // Found @0xfc6ceaa4, levent 0x30a
//#define SD_READONLY_IDX     1
//#define USB_MASK            0x00800000 // Found @0xfc6ceaf4, levent 0x302
//#define USB_IDX             2
//#define BATTCOVER_FLAG      0x00400000 // Found @0xfc6ceaec, levent 0x305
//#define BATTCOVER_IDX       2
//#define HOTSHOE_FLAG        0x00010000 // Found @0xfc6ceabc, levent 0x304
//#define HOTSHOE_IDX         2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
// WARNING: Key name / function may vary! Values for unknown DryOS versions should not be trusted!
//KeyMap keymap[] = {
//    { 0, KEY_SHOOT_FULL      ,0x00040001 }, // Found @0xfc6ce9bc, levent 0x01
//    { 0, KEY_SHOOT_HALF      ,0x00040000 }, // Found @0xfc6cea3c, levent 0x00
//    { 0, KEY_SHOOT_FULL_ONLY ,0x00000001 }, // Found @0xfc6ce9bc, levent 0x01
//    { 0, KEY_ZOOM_OUT        ,0x00000002 }, // Found @0xfc6ce9c4, levent 0x04
//    { 0, KEY_ZOOM_IN         ,0x00000004 }, // Found @0xfc6ce9cc, levent 0x03
//    { 0, KEY_VIDEO           ,0x00000008 }, // Found @0xfc6ce9d4, levent 0x02
//    { 0, KEY_UP              ,0x00000020 }, // Found @0xfc6ce9e4, levent 0x06
//    { 0, KEY_DOWN            ,0x00000040 }, // Found @0xfc6ce9ec, levent 0x07
//    { 0, KEY_RIGHT           ,0x00000080 }, // Found @0xfc6ce9f4, levent 0x09
//    { 0, KEY_LEFT            ,0x00000100 }, // Found @0xfc6ce9fc, levent 0x08
//    { 0, KEY_SET             ,0x00000200 }, // Found @0xfc6cea04, levent 0x0a
//    { 0, KEY_PLAYBACK        ,0x00000800 }, // Found @0xfc6cea14, levent 0x101
//    { 0, KEY_WIFI            ,0x00010000 }, // Found @0xfc6cea2c, levent 0x103
//    { 0, KEY_POWER           ,0x00020000 }, // Found @0xfc6cea34, levent 0x100
//    { 0, 0, 0 }
//};

// canon_mode_list 0xfca80528 Found @0xfc07de1c
// Check modemap values from 'platform/CAMERA/shooting.c':
// 33297  0x8211 In firmware but not in current modemap
//  4172  0x104c In firmware but not in current modemap

// Known propcases
// //      PROPCASE_AFSTEP 13
// #define PROPCASE_FOCUS_STATE 18
// #define PROPCASE_AV 23
// #define PROPCASE_BV 40
// //      PROPCASE_DELTA_DIGITALGAIN 84
// #define PROPCASE_DELTA_SV 86
// //      PROPCASE_DELTA_ND 87
// //      PROPCASE_FELOCK 122
// #define PROPCASE_FLASH_ADJUST_MODE 129
// #define PROPCASE_FLASH_FIRE 130
// //      PROPCASE_HSCAPTURE 146
// #define PROPCASE_EV_CORRECTION_2 218
// #define PROPCASE_ORIENTATION_SENSOR 230
// #define PROPCASE_SV_MARKET 257
// //      PROPCASE_SVFIX 258
// #define PROPCASE_TV 274
// Guessed propset: 10

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
// EXMEM_NARROW         26
// EXMEM_AUTO_GIS_MODE  27
// EXMEM_NP_GIS_MODE    28
// EXMEM_TRIPODHDR_MODE 29
// EXMEM_HSHQ_MODE      30
// EXMEM_CRAW_REC       31
// EXMEM_CREATIVE_SHOT  32
// EXMEM_BACKBLUR       33
// EXMEM_ASTRO          34

// Values below can be overridden in 'stubs_min.S':
DEF(ctypes                            ,0xfc6775a8) // Found @0xfc03f86c
DEF(physw_run                         ,0x000082d8) // Found @0xfc0ece22
DEF(physw_sleep_delay                 ,0x000082e0) // (0x82d8+0x8) Found @0xfc0ece26
DEF(physw_status                      ,0x0003ef4c) // Found @0xfc0ed152
DEF(fileio_semaphore                  ,0x00014848) // Found @0xfc07dce6
DEF(levent_table                      ,0xfc76c55c) // Found @0xfc0bcb38
DEF(FlashParamsTable                  ,0xfca808c4) // Found @0xfc07de30
DEF(playrec_mode                      ,0x0000c4a8) // (0xc4a4+0x4) Found @0xfc318ef6
DEF(jpeg_count_str                    ,0x0016a9c0) // Found @0xfc1303e8
DEF(zoom_busy                         ,0x00014c94) // (0x14c74+0x20) Found @0xfc1caa36
DEF(focus_busy                        ,0x00014a3c) // (0x14a34+0x8) Found @0xfc3b9354
DEF(imager_active                     ,0x00008648) // (0x8644+0x4) Found @0xfc44fcec
DEF(canon_menu_active                 ,0x0000d180) // (0xd17c+0x4) Found @0xfc364422
DEF(file_counter_var                  ,0x000146ec) // Found @0xfc111e68
DEF(_nrflag                           ,0x000223b4) // (0x223b0+0x4) Found @0xfc0b2364
DEF(av_override_semaphore             ,0x00027134) // Found @0xfc660944
DEF(active_bitmap_buffer              ,0x0000d13c) // (0xd0f4+0x48) Found @0xfc3bed0e
DEF(displaytype                       ,0x00009794) // (0x9738+0x5c) Found @0xfc15a792
DEF(bitmap_buffer                     ,0x0000d140) // (0xd0f4+0x4c) Found @0xfc3bed14
DEF(palette_control                   ,0x00015ae0) // Found @0xfc3781fe
DEF(palette_buffer_ptr                ,0x00015af8) // (0x15ae0+0x18) Found @0xfc37821a
DEF(active_palette_buffer             ,0x00015af0) // (0x15ae0+0x10) Found @0xfc378202
DEF_CONST(uiprop_count                      ,0x000000d7) // Found @0xfc2a63d6
DEF(exmem_alloc_table                 ,0x00047438) // Found @0xfc0a3386
DEF(exmem_types_table                 ,0xfceb1048) // Found @0xfc0a338a
DEF_CONST(exmem_type_count                  ,0x00000023) // Found @0xfceb1048
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 2 int value(s), the first is the zoom focus length.
// there are 101 entries in the table - set NUM_FL to 101
DEF(focus_len_table                         ,0xfdf3169c) // Found @0xfdf3169c

//NHSTUB(EnterToCompensationEVF               ,0x00000000) //  0        *** != 0xfc2d38e5
//NHSTUB(ExitFromCompensationEVF              ,0x00000000) //  0        *** != 0xfc2d3927
//NHSTUB(ExpCtrlTool_StartContiAE             ,0x00000000) //  0        *** != 0xfc2cdb5b
//NHSTUB(ExpCtrlTool_StopContiAE              ,0x00000000) //  0        *** != 0xfc2cdd4d
//NHSTUB(Feof_Fut                             ,0x00000000) //  0        *** != 0xfc3b8fb9
//NHSTUB(Fflush_Fut                           ,0x00000000) //  0        *** != 0xfc3b8fe1
//NHSTUB(GetDrive_TotalClusters               ,0x00000000) //  0        *** != 0xfc3b736b
//NHSTUB(GetFocusLensSubjectDistanceFromLens  ,0x00000000) //  0        *** != 0xfc3ba1ff
//NHSTUB(GetImageFolder                       ,0x00000000) //  0        *** != 0xfc39d631
//NHSTUB(MakeSDCardBootable                   ,0x00000000) //  0        *** != 0xfc3b688b
//NHSTUB(PT_PlaySound                         ,0xfc3bde05) //  0        *** != 0x00000000
//NHSTUB(RenameFile_Fut                       ,0x00000000) //  0        *** != 0xfc3b8d69
//NHSTUB(ScreenLock                           ,0xfc3bec91) //  0        *** != 0x00000000
//NHSTUB(ScreenUnlock                         ,0xfc3becc7) //  0        *** != 0x00000000
//NHSTUB(SetFileTimeStamp                     ,0x00000000) //  0        *** != 0xfc3b5ee3
//NHSTUB(TurnOffBackLight                     ,0x00000000) //  0        *** != 0xfc15bb35
//NHSTUB(TurnOnBackLight                      ,0x00000000) //  0        *** != 0xfc15bb31
//NHSTUB(apex2us                              ,0x00000000) //  0        *** != 0xfc25f5cb
//NHSTUB(err_init_task                        ,0x00000000) //  0        *** != 0xfc06647b
//NHSTUB(realloc                              ,0x00000000) //  0        *** != 0xfc5e5339
//NHSTUB(reboot_fw_update                     ,0x00000000) //  0        *** != 0xfc28b97d
//NHSTUB(CancelHPTimer                        ,0x00000000) //  0        *** != 0xfc165d89

NHSTUB(AllocateUncacheableMemory              ,0xfc16f5f1) //  0
NHSTUB(Close                                  ,0xfc3b5c17) //  0
NHSTUB(CreateBinarySemaphore                  ,0xbfe15305) //  0
NHSTUB(CreateTask                             ,0xbfe149e5) //  0
NHSTUB(DebugAssert                            ,0x010e1009) //  0
NHSTUB(DeleteDirectory_Fut                    ,0xfc3b8e15) //  0
NHSTUB(DeleteFile_Fut                         ,0xfc3b8dcb) //  0
NHSTUB(DoAELock                               ,0xfc2d3997) //  0
NHSTUB(DoAFLock                               ,0xfc2d3509) //  0
NHSTUB2(ExecuteEventProcedure                  ,0xfc3b79f5) //  0
NHSTUB(ExitTask                               ,0xbfe14bc7) //  0
NHSTUB(Fclose_Fut                             ,0xfc3b8e77) //  0
NHSTUB(Fgets_Fut                              ,0xfc3b8f55) //  0
NHSTUB(Fopen_Fut                              ,0xfc3b8e4f) //  0
NHSTUB(Fread_Fut                              ,0xfc3b8ee9) //  0
NHSTUB(FreeUncacheableMemory                  ,0xfc16f61d) //  0
NHSTUB(Fseek_Fut                              ,0xfc3b8f87) //  0
NHSTUB(Fwrite_Fut                             ,0xfc3b8f1f) //  0
NHSTUB(GetBatteryTemperature                  ,0xfc453885) //  0
NHSTUB(GetCCDTemperature                      ,0xfc453829) //  0
NHSTUB(GetCurrentAvValue                      ,0xfc164bc9) //  0
NHSTUB(GetCurrentShutterSpeed                 ,0xfc470b9f) //  0
NHSTUB(GetUsableMaxAv                         ,0xfc5e2901) //  0
NHSTUB(GetUsableMinAv                         ,0xfc5e28ef) //  0
NHSTUB(get_nd_value                           ,0xfc4ea823) //  0
NHSTUB(get_current_nd_value                   ,0xfc4ea7fd) //  0
NHSTUB(GetDrive_ClusterSize                   ,0xfc3b6e8b) //  0
NHSTUB(GetDrive_FreeClusters                  ,0xfc3b738f) //  0
NHSTUB(GetFocusLensSubjectDistance            ,0xfc3b9f05) //  0
NHSTUB(GetKbdState                            ,0xfc09b723) //  0
NHSTUB(GetMemInfo                             ,0xfc67534d) //  0
NHSTUB(GetOpticalTemperature                  ,0xfc4538df) //  0
NHSTUB(GetParameterData                       ,0xfc2a6dc3) //  0
NHSTUB(GetPropertyCase                        ,0xfc3b833b) //  0
NHSTUB(GetSystemTime                          ,0xfc662fa9) //  0
NHSTUB(GetVRAMHPixelsSize                     ,0xfc0c6b11) //  0
NHSTUB(GetVRAMVPixelsSize                     ,0xfc0c6b19) //  0
NHSTUB(GetZoomLensCurrentPoint                ,0xfc1cac81) //  0
NHSTUB(GetZoomLensCurrentPosition             ,0xfc1cac15) //  0
NHSTUB(GiveSemaphore                          ,0xbfe15471) //  0
NHSTUB(IsStrobeChargeCompleted                ,0xfc0c41a7) //  0
NHSTUB(LEDDrive                               ,0xfc5e3b7d) //  0
NHSTUB(LocalTime                              ,0x010e1589) //  0
NHSTUB(LockMainPower                          ,0xfc39abc5) //  0
NHSTUB(MakeDirectory_Fut                      ,0xfc3b5f9b) //  0
//NHSTUB(MoveFocusLensToDistance              ,0xfc667c35) //  0            Overridden
NHSTUB(MoveIrisWithAv                         ,0xfc660931) //  0
NHSTUB(MoveZoomLensWithPoint                  ,0xfc661361) //  0
NHSTUB(Open                                   ,0xfc3b5bdb) //  0
NHSTUB(PB2Rec                                 ,0xfc364f2b) //  0
NHSTUB(PT_MoveDigitalZoomToWide               ,0xfc2d2ed3) //  0
NHSTUB(PT_MoveOpticalZoomAt                   ,0xfc5e4ab9) //  0
NHSTUB(MoveOpticalZoomAt                      ,0xfc2d2d09) //  0
NHSTUB(PostLogicalEventForNotPowerType        ,0xfc3bd751) //  0
NHSTUB(PostLogicalEventToUI                   ,0xfc3bd785) //  0
//NHSTUB(PutInNdFilter                        ,0xfc667edd) //  0            Overridden
//NHSTUB(PutOutNdFilter                       ,0xfc667f03) //  0            Overridden
NHSTUB(Read                                   ,0xfc151589) //  0
NHSTUB(ReadFastDir                            ,0xfc282ec9) //  0
NHSTUB(Rec2PB                                 ,0xfc364f6f) //  0
//NHSTUB(Restart                              ,0x00000000) //  0            Overridden
NHSTUB(SetAE_ShutterSpeed                     ,0xfc66461d) //  0
NHSTUB(SetAutoShutdownTime                    ,0xfc39ac15) //  0
NHSTUB(SetCurrentCaptureModeType              ,0xfc388173) //  0
NHSTUB(SetDate                                ,0xfc665af9) //  0
//NHSTUB(SetFileAttributes                    ,0x00000000) //  0            == 0x00000000
NHSTUB(SetLogicalEventActive                  ,0xfc39b31f) //  0
NHSTUB(SetParameterData                       ,0xfc2a6cd7) //  0
NHSTUB(SetPropertyCase                        ,0xfc3b8207) //  0
NHSTUB(SetScriptMode                          ,0xfc39b357) //  0
NHSTUB(SleepTask                              ,0xbfe14969) //  0
NHSTUB(TakeSemaphore                          ,0xbfe153f9) //  0
NHSTUB(TurnOnDisplay                          ,0xfc0ba83f) //  0
NHSTUB(TurnOffDisplay                         ,0xfc15b0f7) //  0
NHSTUB(UnlockAE                               ,0xfc2d39b5) //  0
NHSTUB(UnlockAF                               ,0xfc2d3539) //  0
NHSTUB(UnlockMainPower                        ,0xfc39ab61) //  0
//NHSTUB(UnsetZoomForMovie                    ,0x00000000) //  0            == 0x00000000
NHSTUB(VbattGet                               ,0xfc0c2823) //  0
NHSTUB(Write                                  ,0xfc3b5b9d) //  0
//NHSTUB(WriteSDCard                          ,0x00000000) //  0            == 0x00000000
NHSTUB(_log                                   ,0x010f7518) //  0
NHSTUB(_log10                                 ,0x010f7a38) //  0
NHSTUB(_pow                                   ,0x010f7ba0) //  0
NHSTUB(_sqrt                                  ,0x010f9c20) //  0
NHSTUB(add_ptp_handler                        ,0xfc35b37b) //  0
NHSTUB(close                                  ,0xfc151483) //  0
NHSTUB(exmem_alloc                            ,0xfc0a38ef) //  0
NHSTUB(exmem_ualloc                           ,0xfc0a37f9) //  0
NHSTUB(exmem_ufree                            ,0xfc0a38b3) //  0
NHSTUB(free                                   ,0xfc3bf283) //  0
NHSTUB(kbd_p1_f                               ,0xfc0ed14b) //  0
NHSTUB(kbd_p1_f_cont                          ,0xfc0ed153) //  0
NHSTUB(kbd_p2_f                               ,0xfc0ecb7d) //  0
NHSTUB(kbd_read_keys                          ,0xfc0ed115) //  0
NHSTUB(kbd_read_keys_r2                       ,0xfc09b59d) //  0
NHSTUB(lseek                                  ,0xfc3b5df3) //  0
NHSTUB(malloc                                 ,0xfc3bf24d) //  0
NHSTUB(memcmp                                 ,0xfc3bf8f5) //  0
NHSTUB(memcpy                                 ,0xfc16c20d) //  0
NHSTUB(memset                                 ,0xfc493ac1) //  0
NHSTUB(mktime_ext                             ,0xfc457215) //  0
NHSTUB(open                                   ,0xfc151413) //  0
NHSTUB(OpenFastDir                            ,0xfc282e29) //  0
NHSTUB(closedir                               ,0xfc282df1) //  0
NHSTUB(get_fstype                             ,0xfc3b6e25) //  0
NHSTUB(qsort                                  ,0xfc22f36d) //  0
NHSTUB(rand                                   ,0xfc4575cb) //  0
NHSTUB(set_control_event                      ,0xfc39b05d) //  0
NHSTUB(srand                                  ,0xfc4575c5) //  0
NHSTUB(stat                                   ,0xfc3b5e2b) //  0
NHSTUB(strcat                                 ,0xfc3bf189) //  0
NHSTUB(strchr                                 ,0xfc16c2a1) //  0
NHSTUB(strcmp                                 ,0xfc3bf8e5) //  0
NHSTUB(strcpy                                 ,0xfc3bf2b5) //  0
NHSTUB(strftime                               ,0x010e1691) //  0
NHSTUB(strlen                                 ,0xfc3bf479) //  0
NHSTUB(strncmp                                ,0xfc3bf1ab) //  0
NHSTUB(strncpy                                ,0xfc3bb0b1) //  0
NHSTUB(strrchr                                ,0xfc16c2b3) //  0
NHSTUB(strtol                                 ,0xfc16c1ff) //  0
NHSTUB(strtolx                                ,0xfc16c0bd) //  0
   DEF(task_CaptSeq                           ,0xfc07498d) //  0
   DEF(task_DvlpSeqTask                       ,0xfc091e67) //  0
   DEF(task_ExpDrv                            ,0xfc2f63ef) //  0
   DEF(task_FileWrite                         ,0xfc4e8441) //  0
   DEF(task_InitFileModules                   ,0xfc157609) //  0
   DEF(task_MovieRecord                       ,0xfc0b7515) //  0
   DEF(task_PhySw                             ,0xfc0ece21) //  0
   DEF(task_TouchPanel                        ,0xfc15e9c7) //  0
   DEF(task_TricInitTask                      ,0xfc542265) //  0
   DEF(hook_CreateTask                        ,0xbfe149e4) //  0
NHSTUB(time                                   ,0x010e11eb) //  0
NHSTUB(vsprintf                               ,0xfc0f5b3b) //  0
NHSTUB(EngDrvRead                             ,0xfc3bf359) //  0
NHSTUB(PTM_GetCurrentItem                     ,0xfc3ae339) //  0
NHSTUB(DisableISDriveError                    ,0xfc661dd5) //  0
NHSTUB(SetHPTimerAfterNow                     ,0xfc165cf1) //  0
NHSTUB(SetEventFlag                           ,0xbfe14df7) //  0
NHSTUB(transfer_src_overlay                   ,0xfc3be169) //  0
NHSTUB(bzero                                  ,0x010f4cd8) //  0
NHSTUB(memset32                               ,0x010f4cdc) //  0
NHSTUB(get_dial_hw_position                   ,0xfc286651) //  0
NHSTUB(PT_MFOn                                ,0xfc2d4a45) //  0
NHSTUB(PT_MFOff                               ,0xfc2d4a79) //  0
NHSTUB(GetAdChValue                           ,0xfc15c443) //  0
NHSTUB(EnableHDMIPower                        ,0xfc0f06b1) //  0
NHSTUB(DisableHDMIPower                       ,0xfc0f06e1) //  0
NHSTUB(SetVideoOutType                        ,0xfc664b8d) //  0
NHSTUB(GetVideoOutType                        ,0xfc664b19) //  0
