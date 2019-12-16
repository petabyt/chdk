// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   Main firmware start: 0xfc020000
//   DRYOS R52 (DRYOS version 2.3, release #0052) @ 0xfc51e9fc ref @ 0xfc04a0f8
//   Firmware Ver GM1.00H   // Found @ 0xfc158a38, "GM1.00H" @ 0xfc158a45

// Values for makefile.inc
//   PLATFORMOSVER = 52
//   MEMISOSTART = 0x3077e0
//   MEMBASEADDR = 0x8000
//   ARAM_HEAP_START = 0x006ce000 #  Found @0xfc111e9c
//   ARAM_HEAP_SIZE = 0x00022000 #  Found @0xfc111e76

// Detected address ranges:
// ROM      0xfc000000 - 0xfdfffffc (33554428 bytes)
// RAM code 0x010c1000 - 0x010df4e8 copied from 0xfcbebac8 ( 124136 bytes)
// RAM data 0x00008000 - 0x00031898 copied from 0xfcbc2230 ( 170136 bytes)

// Zico Xtensa blobs:
// zico_0 0xbff20000 - 0xbff27300 copied from 0xfc9c5b2c (  29440 bytes)
// zico_1 0xbff00000 - 0xbff04780 copied from 0xfc9cce34 (  18304 bytes)
// zico_2 0x80a00000 - 0x80afc208 copied from 0xfc9d15bc (1032712 bytes)

// Found DryOS versions:
// 0xfc51e9fc main  "DRYOS version 2.3, release #0052"
// 0xfc536a2c other "DRYOS version 2.3, release #0052"
// 0xfc9d4c3c other "DRYOS version 2.3, release #0052"

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xfc0f9bb4
//#define CAM_HAS_ND_FILTER 1 // Camera has ND filter
// Camera has an iris (CAM_HAS_IRIS_DIAPHRAGM default)

// physw_event_table 0xfc571968 Found @0xfc0714a0
// Values below go in 'platform_kbd.h':
//#define SD_READONLY_FLAG    0x20000000 // Found @0xfc571a58, levent 0x20a
//#define SD_READONLY_IDX     1
//#define USB_MASK            0x10000000 // Found @0xfc571a88, levent 0x202
//#define USB_IDX             2
//#define BATTCOVER_FLAG      0x00000200 // Found @0xfc571a68, levent 0x205
//#define BATTCOVER_IDX       2
//#define HOTSHOE_FLAG        0x00000010 // Found @0xfc571a10, levent 0x204
//#define HOTSHOE_IDX         1
//#define ANALOG_AV_FLAG      0x00008000 // Found @0xfc571a40, levent 0x200 (non-inverted logic)
//#define ANALOG_AV_IDX       1

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
// WARNING: Key name / function may vary! Values for unknown DryOS versions should not be trusted!
//KeyMap keymap[] = {
//    { 0, KEY_ZOOM_OUT        ,0x00000002 }, // Found @0xfc571968, levent 0x04
//    { 0, KEY_ZOOM_IN         ,0x00000004 }, // Found @0xfc571970, levent 0x03
//    { 0, KEY_VIDEO           ,0x00000008 }, // Found @0xfc571978, levent 0x02
//    { 0, KEY_MENU            ,0x00000010 }, // Found @0xfc571980, levent 0x0b
//    { 0, KEY_UP              ,0x00000020 }, // Found @0xfc571988, levent 0x06
//    { 0, KEY_DOWN            ,0x00000040 }, // Found @0xfc571990, levent 0x07
//    { 0, KEY_RIGHT           ,0x00000080 }, // Found @0xfc571998, levent 0x09
//    { 0, KEY_LEFT            ,0x00000100 }, // Found @0xfc5719a0, levent 0x08
//    { 0, KEY_SET             ,0x00000200 }, // Found @0xfc5719a8, levent 0x0a
//    { 0, KEY_PLAYBACK        ,0x00010000 }, // Found @0xfc5719d0, levent 0x101
//    { 0, KEY_POWER           ,0x00020000 }, // Found @0xfc5719d8, levent 0x100
//    { 0, KEY_SHOOT_FULL      ,0x000c0000 }, // Found @0xfc5719e8, levent 0x01
//    { 0, KEY_SHOOT_FULL_ONLY ,0x00080000 }, // Found @0xfc5719e8, levent 0x01
//    { 0, KEY_SHOOT_HALF      ,0x00040000 }, // Found @0xfc5719e0, levent 0x00
//    { 0, 0, 0 }
//};

// canon_mode_list 0xfc7f898c Found @0xfc1244d8
// Check modemap values from 'platform/CAMERA/shooting.c':
// 32830  0x803e In firmware but not in current modemap
// 32777  0x8009 In firmware but not in current modemap
// 33332  0x8234 In firmware but not in current modemap
// 33295  0x820f In firmware but not in current modemap
//  4163  0x1043 In firmware but not in current modemap
//  4164  0x1044 In firmware but not in current modemap

// Known propcases
// //      PROPCASE_AFSTEP 13
// #define PROPCASE_FOCUS_STATE 18
// #define PROPCASE_AV 23
// #define PROPCASE_BV 34
// //      PROPCASE_DELTA_DIGITALGAIN 77
// #define PROPCASE_DELTA_SV 79
// //      PROPCASE_DELTA_ND 80
// //      PROPCASE_FELOCK 114
// #define PROPCASE_FLASH_ADJUST_MODE 121
// #define PROPCASE_FLASH_FIRE 122
// //      PROPCASE_HSCAPTURE 138
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
// EXMEM_BACKBLUR       29
// EXMEM_ASTRO          30

// Values below can be overridden in 'stubs_min.S':
DEF(ctypes                            ,0xfc51eaa4) // Found @0xfc03b7fc
DEF(physw_run                         ,0x00008324) // Found @0xfc070d66
DEF(physw_sleep_delay                 ,0x0000832c) // (0x8324+0x8) Found @0xfc070d6a
DEF(physw_status                      ,0x00033110) // Found @0xfc071054
DEF(fileio_semaphore                  ,0x000125cc) // Found @0xfc06c016
DEF(levent_table                      ,0xfc5de3a4) // Found @0xfc0cbe58
DEF(FlashParamsTable                  ,0xfc7f8c24) // Found @0xfc1244ec
DEF(playrec_mode                      ,0x0000be44) // (0xbe40+0x4) Found @0xfc2ba3a2
DEF(jpeg_count_str                    ,0x000eb498) // Found @0xfc1189c6
DEF(zoom_busy                         ,0x000129e0) // (0x129c0+0x20) Found @0xfc1cbad6
DEF(focus_busy                        ,0x000127b0) // (0x127a8+0x8) Found @0xfc2c68ca
DEF(imager_active                     ,0x00008710) // (0x870c+0x4) Found @0xfc14180a
//DEF(canon_menu_active                 ,0x0000c9b4),          stubs_min = 0x0000c9b4 (0x0000c9ac+0x8)
//DEF(file_counter_var                  ,0x000124f8),          stubs_min = 0x000124f8 (0x000124f8)
DEF(_nrflag                           ,0x0001c020) // (0x1c014+0xc) Found @0xfc33be14
DEF(av_override_semaphore             ,0x000231c8) // Found @0xfc38cfa8
//DEF(active_bitmap_buffer              ,0x0000c980), ** != ** stubs_min = 0x0000c97c (0xC97C)
//DEF(bitmap_buffer                     ,0x0000c984),          stubs_min = 0x0000c984 (0xC984)
DEF_CONST(uiprop_count                      ,0x00000094) // Found @0xfc0cc5c0
DEF(exmem_alloc_table                 ,0x0003a828) // Found @0xfc071a0e
DEF(exmem_types_table                 ,0xfcbc6144) // Found @0xfc071a12
DEF_CONST(exmem_type_count                  ,0x0000001f) // Found @0xfcbc6144
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 2 int value(s), the first is the zoom focus length.
// there are 121 entries in the table - set NUM_FL to 121
//DEF(focus_len_table                         ,0xfdf2bd38) // Found @0xfdf2bd38,          stubs_min = 0xfdf2bd38 (0xfdf2bd38)

//NHSTUB(EnterToCompensationEVF               ,0x00000000) //  0        *** != 0xfc254c45
//NHSTUB(ExitFromCompensationEVF              ,0x00000000) //  0        *** != 0xfc254c81
//NHSTUB(ExpCtrlTool_StartContiAE             ,0x00000000) //  0        *** != 0xfc2428d1
//NHSTUB(ExpCtrlTool_StopContiAE              ,0x00000000) //  0        *** != 0xfc2429b1
//NHSTUB(Feof_Fut                             ,0x00000000) //  0        *** != 0xfc2b0365
//NHSTUB(Fflush_Fut                           ,0x00000000) //  0        *** != 0xfc2b038d
//NHSTUB(GetDrive_TotalClusters               ,0x00000000) //  0        *** != 0xfc3092d5
//NHSTUB(GetFocusLensSubjectDistanceFromLens  ,0x00000000) //  0        *** != 0xfc2c77b1
//NHSTUB(GetImageFolder                       ,0x00000000) //  0        *** != 0xfc2abc11
//NHSTUB(MakeSDCardBootable                   ,0x00000000) //  0        *** != 0xfc3096e3
//NHSTUB(RenameFile_Fut                       ,0x00000000) //  0        *** != 0xfc2b0115
//NHSTUB(Restart                              ,0x00000000) //  0        *** != 0xfc0b59b5
//NHSTUB(SetFileAttributes                    ,0x00000000) //  0        *** != 0xfc309a61
//NHSTUB(SetFileTimeStamp                     ,0x00000000) //  0        *** != 0xfc309a4d
//NHSTUB(SetParameterData                     ,0x00000000) //  0        *** != 0xfc0ccdf1
//NHSTUB(WriteSDCard                          ,0x00000000) //  0        *** != 0xfc10e525
//NHSTUB(apex2us                              ,0x00000000) //  0        *** != 0xfc33792f
//NHSTUB(err_init_task                        ,0x00000000) //  0        *** != 0xfc5237bd
//NHSTUB(realloc                              ,0x00000000) //  0        *** != 0xfc4c5a79
//NHSTUB(reboot_fw_update                     ,0x00000000) //  0        *** != 0xfc39050d
//NHSTUB(CancelHPTimer                        ,0x00000000) //  0        *** != 0xfc158795
//NHSTUB(SetHPTimerAfterNow                   ,0x00000000) //  0        *** != 0xfc1586fd

NHSTUB(AllocateUncacheableMemory              ,0xfc0f9b85) //  0
NHSTUB(Close                                  ,0xfc309801) //  0
NHSTUB(CreateBinarySemaphore                  ,0x010c5965) //  0
NHSTUB(CreateTask                             ,0x010c5239) //  0
NHSTUB(DebugAssert                            ,0x010c5c8d) //  0
NHSTUB(DeleteDirectory_Fut                    ,0xfc2b01c1) //  0
NHSTUB(DeleteFile_Fut                         ,0xfc2b0177) //  0
NHSTUB(DoAELock                               ,0xfc254ccf) //  0
NHSTUB(DoAFLock                               ,0xfc254a09) //  0
NHSTUB2(ExecuteEventProcedure                  ,0xfc2de669) //  0
NHSTUB(ExitTask                               ,0x010c539b) //  0
NHSTUB(Fclose_Fut                             ,0xfc2b0223) //  0
NHSTUB(Fgets_Fut                              ,0xfc2b0301) //  0
NHSTUB(Fopen_Fut                              ,0xfc2b01fb) //  0
NHSTUB(Fread_Fut                              ,0xfc2b0295) //  0
NHSTUB(FreeUncacheableMemory                  ,0xfc0f9bb1) //  0
NHSTUB(Fseek_Fut                              ,0xfc2b0333) //  0
NHSTUB(Fwrite_Fut                             ,0xfc2b02cb) //  0
NHSTUB(GetBatteryTemperature                  ,0xfc14a161) //  0
NHSTUB(GetCCDTemperature                      ,0xfc14a105) //  0
NHSTUB(GetCurrentAvValue                      ,0xfc14e8dd) //  0
NHSTUB(GetCurrentShutterSpeed                 ,0xfc2e0dc7) //  0
NHSTUB(GetUsableMaxAv                         ,0xfc1c10cb) //  0
NHSTUB(GetUsableMinAv                         ,0xfc1c10b9) //  0
NHSTUB(get_nd_value                           ,0xfc38abd9) //  0
NHSTUB(get_current_nd_value                   ,0xfc38abb5) //  0
NHSTUB(GetDrive_ClusterSize                   ,0xfc308dc9) //  0
NHSTUB(GetDrive_FreeClusters                  ,0xfc3092f9) //  0
NHSTUB(GetFocusLensSubjectDistance            ,0xfc2c74b7) //  0
NHSTUB(GetKbdState                            ,0xfc06ec77) //  0
NHSTUB(GetMemInfo                             ,0xfc404945) //  0
NHSTUB(GetOpticalTemperature                  ,0xfc14a1bb) //  0
NHSTUB(GetParameterData                       ,0xfc0cced9) //  0
NHSTUB(GetPropertyCase                        ,0xfc2eaaeb) //  0
NHSTUB(GetSystemTime                          ,0xfc390bc1) //  0
NHSTUB(GetVRAMHPixelsSize                     ,0xfc1449b9) //  0
NHSTUB(GetVRAMVPixelsSize                     ,0xfc1449c1) //  0
NHSTUB(GetZoomLensCurrentPoint                ,0xfc1cbd21) //  0
NHSTUB(GetZoomLensCurrentPosition             ,0xfc1cbcb5) //  0
NHSTUB(GiveSemaphore                          ,0x010c5abd) //  0
NHSTUB(IsStrobeChargeCompleted                ,0xfc141383) //  0
NHSTUB(LEDDrive                               ,0xfc1d11dd) //  0
NHSTUB(LocalTime                              ,0x010c6289) //  0
NHSTUB(LockMainPower                          ,0xfc158f69) //  0
NHSTUB(MakeDirectory_Fut                      ,0xfc309aeb) //  0
NHSTUB(MoveFocusLensToDistance                ,0xfc3eb787) //  0
NHSTUB(MoveIrisWithAv                         ,0xfc38cf95) //  0
NHSTUB(MoveZoomLensWithPoint                  ,0xfc38d823) //  0
NHSTUB(Open                                   ,0xfc30977d) //  0
NHSTUB(PB2Rec                                 ,0xfc0e7401) //  0
NHSTUB(PT_MoveDigitalZoomToWide               ,0xfc25442d) //  0
NHSTUB(PT_MoveOpticalZoomAt                   ,0xfc1d20a1) //  0
NHSTUB(MoveOpticalZoomAt                      ,0xfc25432d) //  0
NHSTUB(PT_PlaySound                           ,0xfc15d8f5) //  0
NHSTUB(PostLogicalEventForNotPowerType        ,0xfc309e7d) //  0
NHSTUB(PostLogicalEventToUI                   ,0xfc309ea9) //  0
NHSTUB(PutInNdFilter                          ,0xfc3eb409) //  0
NHSTUB(PutOutNdFilter                         ,0xfc3eb42f) //  0
NHSTUB(Read                                   ,0xfc13d195) //  0
NHSTUB(ReadFastDir                            ,0xfc12427d) //  0
NHSTUB(Rec2PB                                 ,0xfc0e7433) //  0
NHSTUB(ScreenLock                             ,0xfc15a943) //  0
NHSTUB(ScreenUnlock                           ,0xfc15a981) //  0
NHSTUB(SetAE_ShutterSpeed                     ,0xfc46c955) //  0
NHSTUB(SetAutoShutdownTime                    ,0xfc158fb5) //  0
NHSTUB(SetCurrentCaptureModeType              ,0xfc2d5741) //  0
NHSTUB(SetLogicalEventActive                  ,0xfc3082d3) //  0
NHSTUB(SetPropertyCase                        ,0xfc2ea9d5) //  0
NHSTUB(SetScriptMode                          ,0xfc30830b) //  0
NHSTUB(SleepTask                              ,0x010c51b5) //  0
NHSTUB(TakeSemaphore                          ,0x010c5a49) //  0
NHSTUB(TurnOffBackLight                       ,0xfc146a9f) //  0
NHSTUB(TurnOnBackLight                        ,0xfc146a43) //  0
NHSTUB(TurnOnDisplay                          ,0xfc103bc5) //  0
NHSTUB(TurnOffDisplay                         ,0xfc103bd7) //  0
NHSTUB(UnlockAE                               ,0xfc254ced) //  0
NHSTUB(UnlockAF                               ,0xfc254a39) //  0
NHSTUB(UnlockMainPower                        ,0xfc158f09) //  0
NHSTUB(VbattGet                               ,0xfc0e43fb) //  0
NHSTUB(Write                                  ,0xfc309839) //  0
NHSTUB(_log                                   ,0x010dac50) //  0
NHSTUB(_log10                                 ,0x010db170) //  0
NHSTUB(_pow                                   ,0x010db2d8) //  0
NHSTUB(_sqrt                                  ,0x010dd358) //  0
NHSTUB(add_ptp_handler                        ,0xfc0bd39f) //  0
NHSTUB(close                                  ,0xfc13d08f) //  0
NHSTUB(displaybusyonscreen                    ,0xfc15f22b) //  0
NHSTUB(exmem_alloc                            ,0xfc071edd) //  0
NHSTUB(exmem_free                             ,0xfc071f2d) //  0
NHSTUB(free                                   ,0xfc30e293) //  0
NHSTUB(kbd_p1_f                               ,0xfc07104d) //  0
NHSTUB(kbd_p1_f_cont                          ,0xfc071055) //  0
NHSTUB(kbd_p2_f                               ,0xfc070b31) //  0
NHSTUB(kbd_read_keys                          ,0xfc071017) //  0
NHSTUB(kbd_read_keys_r2                       ,0xfc07149d) //  0
NHSTUB(lseek                                  ,0xfc30995d) //  0
NHSTUB(malloc                                 ,0xfc30e25d) //  0
NHSTUB(memcmp                                 ,0xfc30e2db) //  0
NHSTUB(memcpy                                 ,0xfc0f916d) //  0
NHSTUB(memset                                 ,0xfc11d111) //  0
NHSTUB(mktime_ext                             ,0xfc4052e1) //  0
NHSTUB(open                                   ,0xfc13d01f) //  0
NHSTUB(OpenFastDir                            ,0xfc1241dd) //  0
NHSTUB(closedir                               ,0xfc1241a5) //  0
NHSTUB(get_fstype                             ,0xfc308d63) //  0
NHSTUB(qsort                                  ,0xfc40b759) //  0
NHSTUB(rand                                   ,0xfc11d0f3) //  0
NHSTUB(set_control_event                      ,0xfc30804d) //  0
NHSTUB(srand                                  ,0xfc11d0ed) //  0
NHSTUB(stat                                   ,0xfc309995) //  0
NHSTUB(strcat                                 ,0xfc30e101) //  0
NHSTUB(strchr                                 ,0xfc15fa93) //  0
NHSTUB(strcmp                                 ,0xfc30e15b) //  0
NHSTUB(strcpy                                 ,0xfc30e16b) //  0
NHSTUB(strftime                               ,0xfc15f645) //  0
NHSTUB(strlen                                 ,0xfc30e1d1) //  0
NHSTUB(strncmp                                ,0xfc15fa69) //  0
NHSTUB(strncpy                                ,0xfc30e123) //  0
NHSTUB(strrchr                                ,0xfc0f922b) //  0
NHSTUB(strtol                                 ,0xfc0f915f) //  0
NHSTUB(strtolx                                ,0xfc0f901d) //  0
   DEF(task_CaptSeq                           ,0xfc0f24a3) //  0
   DEF(task_DvlpSeqTask                       ,0xfc1d5567) //  0
   DEF(task_ExpDrv                            ,0xfc226b3b) //  0
   DEF(task_FileWrite                         ,0xfc06385f) //  0
   DEF(task_InitFileModules                   ,0xfc0b9259) //  0
   DEF(task_MovieRecord                       ,0xfc150ca1) //  0
   DEF(task_PhySw                             ,0xfc070d65) //  0
   DEF(task_TricInitTask                      ,0xfc47ebbb) //  0
   DEF(hook_CreateTask                        ,0x010c5238) //  0
NHSTUB(time                                   ,0x010c5f41) //  0
NHSTUB(vsprintf                               ,0xfc0bbd03) //  0
NHSTUB(undisplaybusyonscreen                  ,0xfc15f361) //  0
NHSTUB(EngDrvRead                             ,0xfc30d90d) //  0
NHSTUB(PTM_GetCurrentItem                     ,0xfc3072c5) //  0
NHSTUB(DisableISDriveError                    ,0xfc38ddbf) //  0
NHSTUB(SetEventFlag                           ,0x010c5599) //  0
NHSTUB(transfer_src_overlay                   ,0xfc15a05b) //  0
NHSTUB(bzero                                  ,0x010d8498) //  0
NHSTUB(memset32                               ,0x010d849c) //  0
//NHSTUB(get_dial_hw_position                 ,0xfc42fa53) //  0            == 0xfc42fa53
NHSTUB(PT_MFOn                                ,0xfc255cad) //  0
NHSTUB(PT_MFOff                               ,0xfc255ce1) //  0
NHSTUB(GetAdChValue                           ,0xfc0e95b7) //  0
NHSTUB(EnableHDMIPower                        ,0xfc0ba5bb) //  0
NHSTUB(DisableHDMIPower                       ,0xfc0ba5eb) //  0
