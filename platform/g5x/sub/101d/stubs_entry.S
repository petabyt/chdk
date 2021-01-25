// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   Main firmware start: 0xfc020000
//   DRYOS R58 (DRYOS version 2.3, release #0058+p3) @ 0xfc67753c ref @ 0xfc0405a8
//   Firmware Ver GM1.01D   // Found @ 0xfc45472c, "GM1.01D" @ 0xfc454739

// Values for makefile.inc
//   PLATFORMOSVER = 58
//   DIGIC = 60
//   MEMISOSTART = 0x39124c
//   MEMBASEADDR = 0x8000
//   ARAM_HEAP_START = 0x006ce000#  Found @0xfc5e51a0
//   ARAM_HEAP_SIZE = 0x00022000#  Found @0xfc5e517a

// Detected address ranges:
// ROM      0xfc000000 - 0xfe000000 (33554432 bytes)
// RAM code 0x010e1000 - 0x010fbd18 copied from 0xfcee2190 ( 109848 bytes)
// TCM code 0xbfe10800 - 0xbfe176a9 copied from 0xfcefcea8 (  28329 bytes)
// RAM data 0x00008000 - 0x0003d674 copied from 0xfceacb1c ( 218740 bytes)
// EVEC     0x00000000 - 0x00000038 copied from 0xfc06630c (     56 bytes)

// Zico Xtensa blobs:
// zico_0 0xbff20000 - 0xbff27a30 copied from 0xfcc91490 (  31280 bytes)
// zico_1 0xbff00000 - 0xbff04ad0 copied from 0xfcc98ec8 (  19152 bytes)
// zico_2 0x80a00000 - 0x80b16748 copied from 0xfcc9d9a0 (1140552 bytes)

// Omar ARM blobs:
// omar_0 0xdff00000 - 0xdff00e90 copied from 0xfc677774 (   3728 bytes)
// omar_1 0x40700000 - 0x407505a0 copied from 0xfc678604 ( 329120 bytes)

// Found DryOS versions:
// 0xfc67753c main  "DRYOS version 2.3, release #0058+p3"
// 0xfc68e318 other "DRYOS version 2.3, release #0058+p3"
// 0xfcc9eb60 other "DRYOS version 2.3, release #0058+p3"

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xfc16f648
//#define CAM_HAS_ND_FILTER 1 // Camera has ND filter
// Camera has an iris (CAM_HAS_IRIS_DIAPHRAGM default)

// physw_event_table 0xfc6cea08 Found @0xfc09b5a0
// Values below go in 'platform_kbd.h':
//#define SD_READONLY_FLAG    0x20000000 // Found @0xfc6ceaf0, levent 0x30a
//#define SD_READONLY_IDX     1
//#define USB_MASK            0x00800000 // Found @0xfc6ceb40, levent 0x302
//#define USB_IDX             2
//#define BATTCOVER_FLAG      0x00400000 // Found @0xfc6ceb38, levent 0x305
//#define BATTCOVER_IDX       2
//#define HOTSHOE_FLAG        0x00010000 // Found @0xfc6ceb08, levent 0x304
//#define HOTSHOE_IDX         2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
// WARNING: Key name / function may vary! Values for unknown DryOS versions should not be trusted!
//KeyMap keymap[] = {
//    { 0, KEY_SHOOT_FULL      ,0x00040001 }, // Found @0xfc6cea08, levent 0x01
//    { 0, KEY_SHOOT_HALF      ,0x00040000 }, // Found @0xfc6cea88, levent 0x00
//    { 0, KEY_SHOOT_FULL_ONLY ,0x00000001 }, // Found @0xfc6cea08, levent 0x01
//    { 0, KEY_ZOOM_OUT        ,0x00000002 }, // Found @0xfc6cea10, levent 0x04
//    { 0, KEY_ZOOM_IN         ,0x00000004 }, // Found @0xfc6cea18, levent 0x03
//    { 0, KEY_VIDEO           ,0x00000008 }, // Found @0xfc6cea20, levent 0x02
//    { 0, KEY_UP              ,0x00000020 }, // Found @0xfc6cea30, levent 0x06
//    { 0, KEY_DOWN            ,0x00000040 }, // Found @0xfc6cea38, levent 0x07
//    { 0, KEY_RIGHT           ,0x00000080 }, // Found @0xfc6cea40, levent 0x09
//    { 0, KEY_LEFT            ,0x00000100 }, // Found @0xfc6cea48, levent 0x08
//    { 0, KEY_SET             ,0x00000200 }, // Found @0xfc6cea50, levent 0x0a
//    { 0, KEY_PLAYBACK        ,0x00000800 }, // Found @0xfc6cea60, levent 0x101
//    { 0, KEY_WIFI            ,0x00010000 }, // Found @0xfc6cea78, levent 0x103
//    { 0, KEY_POWER           ,0x00020000 }, // Found @0xfc6cea80, levent 0x100
//    { 0, 0, 0 }
//};

// canon_mode_list 0xfca80578 Found @0xfc07de1c
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
DEF(ctypes                            ,0xfc6775f4) // Found @0xfc03f86c
DEF(physw_run                         ,0x000082d8) // Found @0xfc0ece22
DEF(physw_sleep_delay                 ,0x000082e0) // (0x82d8+0x8) Found @0xfc0ece26
DEF(physw_status                      ,0x0003ef4c) // Found @0xfc0ed152
DEF(fileio_semaphore                  ,0x00014848) // Found @0xfc07dce6
DEF(levent_table                      ,0xfc76c5ac) // Found @0xfc0bcb38
DEF(FlashParamsTable                  ,0xfca80914) // Found @0xfc07de30
DEF(playrec_mode                      ,0x0000c4a8) // (0xc4a4+0x4) Found @0xfc318f1e
DEF(jpeg_count_str                    ,0x0016a9c0) // Found @0xfc1303e8
DEF(zoom_busy                         ,0x00014c94) // (0x14c74+0x20) Found @0xfc1caa5e
DEF(focus_busy                        ,0x00014a3c) // (0x14a34+0x8) Found @0xfc3b93a0
DEF(imager_active                     ,0x00008648) // (0x8644+0x4) Found @0xfc44fd38
DEF(canon_menu_active                 ,0x0000d180) // (0xd17c+0x4) Found @0xfc36444a
DEF(file_counter_var                  ,0x000146ec) // Found @0xfc111e68
DEF(_nrflag                           ,0x000223b4) // (0x223b0+0x4) Found @0xfc0b2364
DEF(av_override_semaphore             ,0x00027134) // Found @0xfc660990
DEF(active_bitmap_buffer              ,0x0000d13c) // (0xd0f4+0x48) Found @0xfc3bed5a
DEF(displaytype                       ,0x00009794) // (0x9738+0x5c) Found @0xfc15a792
DEF(bitmap_buffer                     ,0x0000d140) // (0xd0f4+0x4c) Found @0xfc3bed60
DEF(palette_control                   ,0x00015ae0) // Found @0xfc378226
DEF(palette_buffer_ptr                ,0x00015af8) // (0x15ae0+0x18) Found @0xfc378242
DEF(active_palette_buffer             ,0x00015af0) // (0x15ae0+0x10) Found @0xfc37822a
DEF(live_free_cluster_count           ,0x00171310) // (0x1712d8+0x38) Found @0xfc06e1e8
DEF_CONST(uiprop_count                      ,0x000000d7) // Found @0xfc2a63fe
DEF(exmem_alloc_table                 ,0x00047438) // Found @0xfc0a3386
DEF(exmem_types_table                 ,0xfceb1098) // Found @0xfc0a338a
DEF_CONST(exmem_type_count                  ,0x00000023) // Found @0xfceb1098
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 2 int value(s), the first is the zoom focus length.
// there are 101 entries in the table - set NUM_FL to 101
DEF(focus_len_table                         ,0xfdf3169c) // Found @0xfdf3169c

//NHSTUB(EnterToCompensationEVF               ,0x00000000) //  0        *** != 0xfc2d390d
//NHSTUB(ExitFromCompensationEVF              ,0x00000000) //  0        *** != 0xfc2d394f
//NHSTUB(ExpCtrlTool_StartContiAE             ,0x00000000) //  0        *** != 0xfc2cdb83
//NHSTUB(ExpCtrlTool_StopContiAE              ,0x00000000) //  0        *** != 0xfc2cdd75
//NHSTUB(Feof_Fut                             ,0x00000000) //  0        *** != 0xfc3b9005
//NHSTUB(Fflush_Fut                           ,0x00000000) //  0        *** != 0xfc3b902d
//NHSTUB(GetDrive_TotalClusters               ,0x00000000) //  0        *** != 0xfc3b73b7
//NHSTUB(GetFocusLensSubjectDistanceFromLens  ,0x00000000) //  0        *** != 0xfc3ba24b
//NHSTUB(GetImageFolder                       ,0x00000000) //  0        *** != 0xfc39d67d
//NHSTUB(MakeSDCardBootable                   ,0x00000000) //  0        *** != 0xfc3b68d7
//NHSTUB(PT_PlaySound                         ,0xfc3bde51) //  0        *** != 0x00000000
//NHSTUB(RenameFile_Fut                       ,0x00000000) //  0        *** != 0xfc3b8db5
//NHSTUB(ScreenLock                           ,0xfc3becdd) //  0        *** != 0x00000000
//NHSTUB(ScreenUnlock                         ,0xfc3bed13) //  0        *** != 0x00000000
//NHSTUB(SetFileTimeStamp                     ,0x00000000) //  0        *** != 0xfc3b5f2f
//NHSTUB(TurnOffBackLight                     ,0x00000000) //  0        *** != 0xfc15bb35
//NHSTUB(TurnOnBackLight                      ,0x00000000) //  0        *** != 0xfc15bb31
//NHSTUB(apex2us                              ,0x00000000) //  0        *** != 0xfc25f5f3
//NHSTUB(err_init_task                        ,0x00000000) //  0        *** != 0xfc06647b
//NHSTUB(realloc                              ,0x00000000) //  0        *** != 0xfc5e5385
//NHSTUB(reboot_fw_update                     ,0x00000000) //  0        *** != 0xfc28b9a5
//NHSTUB(CancelHPTimer                        ,0x00000000) //  0        *** != 0xfc165d89

NHSTUB(AllocateUncacheableMemory              ,0xfc16f619) //  0
NHSTUB(Close                                  ,0xfc3b5c63) //  0
NHSTUB(CreateBinarySemaphore                  ,0xbfe15305) //  0
NHSTUB(CreateTask                             ,0xbfe149e5) //  0
NHSTUB(DebugAssert                            ,0x010e1009) //  0
NHSTUB(DeleteDirectory_Fut                    ,0xfc3b8e61) //  0
NHSTUB(DeleteFile_Fut                         ,0xfc3b8e17) //  0
NHSTUB(DoAELock                               ,0xfc2d39bf) //  0
NHSTUB(DoAFLock                               ,0xfc2d3531) //  0
NHSTUB2(ExecuteEventProcedure                  ,0xfc3b7a41) //  0
NHSTUB(ExitTask                               ,0xbfe14bc7) //  0
NHSTUB(Fclose_Fut                             ,0xfc3b8ec3) //  0
NHSTUB(Fgets_Fut                              ,0xfc3b8fa1) //  0
NHSTUB(Fopen_Fut                              ,0xfc3b8e9b) //  0
NHSTUB(Fread_Fut                              ,0xfc3b8f35) //  0
NHSTUB(FreeUncacheableMemory                  ,0xfc16f645) //  0
NHSTUB(Fseek_Fut                              ,0xfc3b8fd3) //  0
NHSTUB(Fwrite_Fut                             ,0xfc3b8f6b) //  0
NHSTUB(GetBatteryTemperature                  ,0xfc4538d1) //  0
NHSTUB(GetCCDTemperature                      ,0xfc453875) //  0
NHSTUB(GetCurrentAvValue                      ,0xfc164bc9) //  0
NHSTUB(GetCurrentShutterSpeed                 ,0xfc470beb) //  0
NHSTUB(GetUsableMaxAv                         ,0xfc5e294d) //  0
NHSTUB(GetUsableMinAv                         ,0xfc5e293b) //  0
NHSTUB(get_nd_value                           ,0xfc4ea86f) //  0
NHSTUB(get_current_nd_value                   ,0xfc4ea849) //  0
NHSTUB(GetDrive_ClusterSize                   ,0xfc3b6ed7) //  0
//NHSTUB(GetDrive_FreeClusters                ,0xfc3b73db) //  0            Overridden
NHSTUB(GetFocusLensSubjectDistance            ,0xfc3b9f51) //  0
NHSTUB(GetKbdState                            ,0xfc09b723) //  0
NHSTUB(GetMemInfo                             ,0xfc675399) //  0
NHSTUB(GetOpticalTemperature                  ,0xfc45392b) //  0
NHSTUB(GetParameterData                       ,0xfc2a6deb) //  0
NHSTUB(GetPropertyCase                        ,0xfc3b8387) //  0
NHSTUB(GetSystemTime                          ,0xfc662ff5) //  0
NHSTUB(GetVRAMHPixelsSize                     ,0xfc0c6b11) //  0
NHSTUB(GetVRAMVPixelsSize                     ,0xfc0c6b19) //  0
NHSTUB(GetZoomLensCurrentPoint                ,0xfc1caca9) //  0
NHSTUB(GetZoomLensCurrentPosition             ,0xfc1cac3d) //  0
NHSTUB(GiveSemaphore                          ,0xbfe15471) //  0
NHSTUB(IsStrobeChargeCompleted                ,0xfc0c41a7) //  0
NHSTUB(LEDDrive                               ,0xfc5e3bc9) //  0
NHSTUB(LocalTime                              ,0x010e1589) //  0
NHSTUB(LockMainPower                          ,0xfc39ac11) //  0
NHSTUB(MakeDirectory_Fut                      ,0xfc3b5fe7) //  0
//NHSTUB(MoveFocusLensToDistance              ,0xfc667c81) //  0            Overridden
NHSTUB(MoveIrisWithAv                         ,0xfc66097d) //  0
NHSTUB(MoveZoomLensWithPoint                  ,0xfc6613ad) //  0
NHSTUB(Open                                   ,0xfc3b5c27) //  0
NHSTUB(PB2Rec                                 ,0xfc364f53) //  0
NHSTUB(PT_MoveDigitalZoomToWide               ,0xfc2d2efb) //  0
NHSTUB(PT_MoveOpticalZoomAt                   ,0xfc5e4b05) //  0
NHSTUB(MoveOpticalZoomAt                      ,0xfc2d2d31) //  0
NHSTUB(PostLogicalEventForNotPowerType        ,0xfc3bd79d) //  0
NHSTUB(PostLogicalEventToUI                   ,0xfc3bd7d1) //  0
//NHSTUB(PutInNdFilter                        ,0xfc667f29) //  0            Overridden
//NHSTUB(PutOutNdFilter                       ,0xfc667f4f) //  0            Overridden
NHSTUB(Read                                   ,0xfc151589) //  0
NHSTUB(ReadFastDir                            ,0xfc282ef1) //  0
NHSTUB(Rec2PB                                 ,0xfc364f97) //  0
//NHSTUB(Restart                              ,0x00000000) //  0            Overridden
NHSTUB(SetAE_ShutterSpeed                     ,0xfc664669) //  0
NHSTUB(SetAutoShutdownTime                    ,0xfc39ac61) //  0
NHSTUB(SetCurrentCaptureModeType              ,0xfc3881bf) //  0
NHSTUB(SetDate                                ,0xfc665b45) //  0
//NHSTUB(SetFileAttributes                    ,0x00000000) //  0            == 0x00000000
NHSTUB(SetLogicalEventActive                  ,0xfc39b36b) //  0
NHSTUB(SetParameterData                       ,0xfc2a6cff) //  0
NHSTUB(SetPropertyCase                        ,0xfc3b8253) //  0
NHSTUB(SetScriptMode                          ,0xfc39b3a3) //  0
NHSTUB(SleepTask                              ,0xbfe14969) //  0
NHSTUB(TakeSemaphore                          ,0xbfe153f9) //  0
NHSTUB(TurnOnDisplay                          ,0xfc0ba83f) //  0
NHSTUB(TurnOffDisplay                         ,0xfc15b0f7) //  0
NHSTUB(UnlockAE                               ,0xfc2d39dd) //  0
NHSTUB(UnlockAF                               ,0xfc2d3561) //  0
NHSTUB(UnlockMainPower                        ,0xfc39abad) //  0
//NHSTUB(UnsetZoomForMovie                    ,0x00000000) //  0            == 0x00000000
NHSTUB(VbattGet                               ,0xfc0c2823) //  0
NHSTUB(Write                                  ,0xfc3b5be9) //  0
//NHSTUB(WriteSDCard                          ,0x00000000) //  0            == 0x00000000
NHSTUB(_log                                   ,0x010f7518) //  0
NHSTUB(_log10                                 ,0x010f7a38) //  0
NHSTUB(_pow                                   ,0x010f7ba0) //  0
NHSTUB(_sqrt                                  ,0x010f9c20) //  0
NHSTUB(add_ptp_handler                        ,0xfc35b3a3) //  0
NHSTUB(close                                  ,0xfc151483) //  0
NHSTUB(exmem_alloc                            ,0xfc0a38ef) //  0
NHSTUB(exmem_ualloc                           ,0xfc0a37f9) //  0
NHSTUB(exmem_ufree                            ,0xfc0a38b3) //  0
NHSTUB(free                                   ,0xfc3bf2cf) //  0
NHSTUB(kbd_p1_f                               ,0xfc0ed14b) //  0
NHSTUB(kbd_p1_f_cont                          ,0xfc0ed153) //  0
NHSTUB(kbd_p2_f                               ,0xfc0ecb7d) //  0
NHSTUB(kbd_read_keys                          ,0xfc0ed115) //  0
NHSTUB(kbd_read_keys_r2                       ,0xfc09b59d) //  0
NHSTUB(lseek                                  ,0xfc3b5e3f) //  0
NHSTUB(malloc                                 ,0xfc3bf299) //  0
NHSTUB(memcmp                                 ,0xfc3bf941) //  0
NHSTUB(memcpy                                 ,0xfc16c20d) //  0
NHSTUB(memset                                 ,0xfc493b0d) //  0
NHSTUB(mktime_ext                             ,0xfc457261) //  0
NHSTUB(open                                   ,0xfc151413) //  0
NHSTUB(OpenFastDir                            ,0xfc282e51) //  0
NHSTUB(closedir                               ,0xfc282e19) //  0
NHSTUB(get_fstype                             ,0xfc3b6e71) //  0
NHSTUB(qsort                                  ,0xfc22f395) //  0
NHSTUB(rand                                   ,0xfc457617) //  0
NHSTUB(set_control_event                      ,0xfc39b0a9) //  0
NHSTUB(srand                                  ,0xfc457611) //  0
NHSTUB(stat                                   ,0xfc3b5e77) //  0
NHSTUB(strcat                                 ,0xfc3bf1d5) //  0
NHSTUB(strchr                                 ,0xfc16c2a1) //  0
NHSTUB(strcmp                                 ,0xfc3bf931) //  0
NHSTUB(strcpy                                 ,0xfc3bf301) //  0
NHSTUB(strftime                               ,0x010e1691) //  0
NHSTUB(strlen                                 ,0xfc3bf4c5) //  0
NHSTUB(strncmp                                ,0xfc3bf1f7) //  0
NHSTUB(strncpy                                ,0xfc3bb0fd) //  0
NHSTUB(strrchr                                ,0xfc16c2b3) //  0
NHSTUB(strtol                                 ,0xfc16c1ff) //  0
NHSTUB(strtolx                                ,0xfc16c0bd) //  0
   DEF(task_CaptSeq                           ,0xfc07498d) //  0
   DEF(task_DvlpSeqTask                       ,0xfc091e67) //  0
   DEF(task_ExpDrv                            ,0xfc2f6417) //  0
   DEF(task_FileWrite                         ,0xfc4e848d) //  0
   DEF(task_InitFileModules                   ,0xfc157609) //  0
   DEF(task_MovieRecord                       ,0xfc0b7515) //  0
   DEF(task_PhySw                             ,0xfc0ece21) //  0
   DEF(task_TouchPanel                        ,0xfc15e9c7) //  0
   DEF(task_TricInitTask                      ,0xfc5422b1) //  0
   DEF(hook_CreateTask                        ,0xbfe149e4) //  0
NHSTUB(time                                   ,0x010e11eb) //  0
NHSTUB(vsprintf                               ,0xfc0f5b3b) //  0
NHSTUB(EngDrvRead                             ,0xfc3bf3a5) //  0
NHSTUB(PTM_GetCurrentItem                     ,0xfc3ae385) //  0
NHSTUB(DisableISDriveError                    ,0xfc661e21) //  0
NHSTUB(SetHPTimerAfterNow                     ,0xfc165cf1) //  0
NHSTUB(SetEventFlag                           ,0xbfe14df7) //  0
NHSTUB(transfer_src_overlay                   ,0xfc3be1b5) //  0
NHSTUB(bzero                                  ,0x010f4cd8) //  0
NHSTUB(memset32                               ,0x010f4cdc) //  0
NHSTUB(get_dial_hw_position                   ,0xfc286679) //  0
NHSTUB(PT_MFOn                                ,0xfc2d4a6d) //  0
NHSTUB(PT_MFOff                               ,0xfc2d4aa1) //  0
NHSTUB(GetAdChValue                           ,0xfc15c443) //  0
NHSTUB(EnableHDMIPower                        ,0xfc0f06b1) //  0
NHSTUB(DisableHDMIPower                       ,0xfc0f06e1) //  0
NHSTUB(SetVideoOutType                        ,0xfc664bd9) //  0
NHSTUB(GetVideoOutType                        ,0xfc664b65) //  0
