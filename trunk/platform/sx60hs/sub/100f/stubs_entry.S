// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   Main firmware start: 0xfc020000
//   DRYOS R55 (DRYOS version 2.3, release #0055+p6) @ 0xfc57be80 ref @ 0xfc03c518
//   Firmware Ver GM1.00F   // Found @ 0xfc15c1ec, "GM1.00F" @ 0xfc15c1f9

// Values for makefile.inc
//   PLATFORMOSVER = 55
//   DIGIC = 60
//   MEMISOSTART = 0x3a8bb0
//   MEMBASEADDR = 0x8000
//   ARAM_HEAP_START = 0x006ce000#  Found @0xfc1014bc
//   ARAM_HEAP_SIZE = 0x00022000#  Found @0xfc101496

// Detected address ranges:
// ROM      0xfc000000 - 0xfe000000 (33554432 bytes)
// RAM code 0x010e1000 - 0x0110daa4 copied from 0xfcd16b8c ( 182948 bytes)
// RAM data 0x00008000 - 0x0003260c copied from 0xfccec580 ( 173580 bytes)
// EVEC     0x00000000 - 0x00000038 copied from 0xfc05ef74 (     56 bytes)

// Zico Xtensa blobs:
// zico_0 0xbff20000 - 0xbff277b8 copied from 0xfcad2ac8 (  30648 bytes)
// zico_1 0xbff00000 - 0xbff04ad0 copied from 0xfcada288 (  19152 bytes)
// zico_2 0x80a00000 - 0x80b060f0 copied from 0xfcaded60 (1073392 bytes)

// Found DryOS versions:
// 0xfc57be80 main  "DRYOS version 2.3, release #0055+p6"
// 0xfc591738 other "DRYOS version 2.3, release #0055+p6"
// 0xfcadfd90 other "DRYOS version 2.3, release #0055+p6"

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xfc16cbb0
//#undef CAM_HAS_ND_FILTER // Camera does not have an ND filter
// Camera has an iris (CAM_HAS_IRIS_DIAPHRAGM default)

// physw_event_table 0xfc5cfb3c Found @0xfc070708
// Values below go in 'platform_kbd.h':
//#define SD_READONLY_FLAG    0x20000000 // Found @0xfc5cfc1c, levent 0x20a
//#define SD_READONLY_IDX     1
//#define USB_MASK            0x10000000 // Found @0xfc5cfc8c, levent 0x202
//#define USB_IDX             2
//#define BATTCOVER_FLAG      0x04000000 // Found @0xfc5cfc84, levent 0x205
//#define BATTCOVER_IDX       2
//#define HOTSHOE_FLAG        0x00000800 // Found @0xfc5cfbf4, levent 0x204
//#define HOTSHOE_IDX         1
//#define ANALOG_AV_FLAG      0x00008000 // Found @0xfc5cfbfc, levent 0x200 (non-inverted logic)
//#define ANALOG_AV_IDX       1

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
// WARNING: Key name / function may vary! Values for unknown DryOS versions should not be trusted!
//KeyMap keymap[] = {
//    { 0, KEY_SHOOT_FULL      ,0x00040001 }, // Found @0xfc5cfb3c, levent 0x01
//    { 0, KEY_SHOOT_HALF      ,0x00040000 }, // Found @0xfc5cfbc4, levent 0x00
//    { 0, KEY_SHOOT_FULL_ONLY ,0x00000001 }, // Found @0xfc5cfb3c, levent 0x01
//    { 0, KEY_VIDEO           ,0x00000008 }, // Found @0xfc5cfb54, levent 0x02
//    { 0, KEY_MENU            ,0x00000010 }, // Found @0xfc5cfb5c, levent 0x14
//    { 0, KEY_UP              ,0x00000020 }, // Found @0xfc5cfb64, levent 0x06
//    { 0, KEY_DOWN            ,0x00000040 }, // Found @0xfc5cfb6c, levent 0x07
//    { 0, KEY_RIGHT           ,0x00000080 }, // Found @0xfc5cfb74, levent 0x09
//    { 0, KEY_LEFT            ,0x00000100 }, // Found @0xfc5cfb7c, levent 0x08
//    { 0, KEY_SET             ,0x00000200 }, // Found @0xfc5cfb84, levent 0x0a
//    { 0, KEY_WIFI            ,0x00002000 }, // Found @0xfc5cfba4, levent 0x103
//    { 0, KEY_PLAYBACK        ,0x00010000 }, // Found @0xfc5cfbb4, levent 0x101
//    { 0, KEY_POWER           ,0x00020000 }, // Found @0xfc5cfbbc, levent 0x100
//    { 0, 0, 0 }
//};

// canon_mode_list 0xfc901e98 Found @0xfc1198c8
// Check modemap values from 'platform/CAMERA/shooting.c':
//  2648  0x0a58 In firmware but not in current modemap
// 33297  0x8211 In firmware but not in current modemap
//  4173  0x104d In firmware but not in current modemap
//  4174  0x104e In firmware but not in current modemap

// Known propcases
// //      PROPCASE_AFSTEP 13
// #define PROPCASE_FOCUS_STATE 18
// #define PROPCASE_AV 23
// #define PROPCASE_BV 35
// //      PROPCASE_DELTA_DIGITALGAIN 79
// #define PROPCASE_DELTA_SV 81
// //      PROPCASE_DELTA_ND 82
// //      PROPCASE_FELOCK 117
// #define PROPCASE_FLASH_ADJUST_MODE 124
// #define PROPCASE_FLASH_FIRE 125
// //      PROPCASE_HSCAPTURE 141
// #define PROPCASE_EV_CORRECTION_2 213
// #define PROPCASE_ORIENTATION_SENSOR 225
// #define PROPCASE_SV_MARKET 252
// //      PROPCASE_SVFIX 253
// #define PROPCASE_TV 269
// Guessed propset: 8

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

// Values below can be overridden in 'stubs_min.S':
DEF(ctypes                            ,0xfc57bf28) // Found @0xfc03b84c
DEF(physw_run                         ,0x000082c8) // Found @0xfc07306a
DEF(physw_sleep_delay                 ,0x000082d0) // (0x82c8+0x8) Found @0xfc07306e
DEF(physw_status                      ,0x00033f64) // Found @0xfc0733a6
DEF(fileio_semaphore                  ,0x00013294) // Found @0xfc06e622
DEF(levent_table                      ,0xfc66aa18) // Found @0xfc0cc574
DEF(FlashParamsTable                  ,0xfc9021f4) // Found @0xfc1198dc
DEF(playrec_mode                      ,0x0000bb84) // (0xbb80+0x4) Found @0xfc2d79ba
DEF(jpeg_count_str                    ,0x0019b134) // Found @0xfc10379a
DEF(zoom_busy                         ,0x0000b85c) // (0xb840+0x1c) Found @0xfc2edaa0
DEF(focus_busy                        ,0x00013488) // (0x13480+0x8) Found @0xfc2f9df6
DEF(imager_active                     ,0x00008688) // (0x8684+0x4) Found @0xfc13b2ac
//DEF(canon_menu_active                 ,0x0000c240),          stubs_min = 0x0000c240 (0x0000c238+0x8)
//DEF(file_counter_var                  ,0x00013148),          stubs_min = 0x00013148 (0x00013148)
DEF(_nrflag                           ,0x0001e858) // (0x1e854+0x4) Found @0xfc347a2c
//DEF(av_override_semaphore             ,0x0002569c),          stubs_min = 0x0002569c (0x0002569c)
//DEF(active_bitmap_buffer              ,0x0000c200), ** != ** stubs_min = 0x0000c1fc (0xc1fc)
//DEF(displaytype                       ,0x00009284),          stubs_min = 0x00009284 (0x9284)
//DEF(bitmap_buffer                     ,0x0000c204),          stubs_min = 0x0000c204 (0xc204)
DEF(palette_control                   ,0x00014bd4) // Found @0xfc333f22
DEF(palette_buffer_ptr                ,0x00014bec) // (0x14bd4+0x18) Found @0xfc333f3e
DEF(active_palette_buffer             ,0x00014be4) // (0x14bd4+0x10) Found @0xfc333f26
DEF_CONST(uiprop_count                      ,0x000000c7) // Found @0xfc0aa3ce
DEF(exmem_alloc_table                 ,0x0003c9c4) // Found @0xfc070d46
DEF(exmem_types_table                 ,0xfccf01d4) // Found @0xfc070d4a
DEF_CONST(exmem_type_count                  ,0x00000021) // Found @0xfccf01d4
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 1 int value, which is the the zoom focus length.
// there are 201 entries in the table - set NUM_FL to 201
//DEF(focus_len_table                         ,0xfdf317ec) // Found @0xfdf317ec,          stubs_min = 0xfdf317ec (0xfdf317ec)

//NHSTUB(EnterToCompensationEVF               ,0x00000000) //  0        *** != 0xfc2766c5
//NHSTUB(ExitFromCompensationEVF              ,0x00000000) //  0        *** != 0xfc2766ff
//NHSTUB(ExpCtrlTool_StartContiAE             ,0x00000000) //  0        *** != 0xfc264e5b
//NHSTUB(ExpCtrlTool_StopContiAE              ,0x00000000) //  0        *** != 0xfc264f47
//NHSTUB(Feof_Fut                             ,0x00000000) //  0        *** != 0xfc301dad
//NHSTUB(Fflush_Fut                           ,0x00000000) //  0        *** != 0xfc301dd5
//NHSTUB(GetDrive_TotalClusters               ,0x00000000) //  0        *** != 0xfc3324eb
//NHSTUB(GetFocusLensSubjectDistanceFromLens  ,0x00000000) //  0        *** != 0xfc2fabc1
//NHSTUB(GetImageFolder                       ,0x00000000) //  0        *** != 0xfc30ba5d
//NHSTUB(MakeSDCardBootable                   ,0x00000000) //  0        *** != 0xfc33284d
//NHSTUB(RenameFile_Fut                       ,0x00000000) //  0        *** != 0xfc301b5d
//NHSTUB(Restart                              ,0x00000000) //  0        *** != 0xfc0b96e5
//NHSTUB(SetFileAttributes                    ,0x00000000) //  0        *** != 0xfc332c01
//NHSTUB(SetFileTimeStamp                     ,0x00000000) //  0        *** != 0xfc332bb9
//NHSTUB(SetParameterData                     ,0x00000000) //  0        *** != 0xfc322acf
//NHSTUB(WriteSDCard                          ,0x00000000) //  0        *** != 0xfcd1d6b7
//NHSTUB(apex2us                              ,0x00000000) //  0        *** != 0xfc3468bb
//NHSTUB(displaybusyonscreen                  ,0x00000000) //  0        *** != 0xfc319671
//NHSTUB(reboot_fw_update                     ,0x00000000) //  0        *** != 0xfc3a1177
//NHSTUB(undisplaybusyonscreen                ,0x00000000) //  0        *** != 0xfc319709
//NHSTUB(EngDrvOut                            ,0x00000000) //  0        *** != 0xfc337d9e
//NHSTUB(EngDrvBits                           ,0x00000000) //  0        *** != 0xfc337dd8
//NHSTUB(CancelHPTimer                        ,0x00000000) //  0        *** != 0xfc15bbfd

NHSTUB(AllocateUncacheableMemory              ,0xfc16cb81) //  0
NHSTUB(Close                                  ,0xfc33296d) //  0
//NHSTUB(CreateBinarySemaphore                ,0x010e5939) //  0            == 0x010e5939
NHSTUB(CreateTask                             ,0x010e5089) //  0
NHSTUB(DebugAssert                            ,0x010e5c8d) //  0
NHSTUB(DeleteDirectory_Fut                    ,0xfc301c09) //  0
NHSTUB(DeleteFile_Fut                         ,0xfc301bbf) //  0
NHSTUB(DoAELock                               ,0xfc27674d) //  0
NHSTUB(DoAFLock                               ,0xfc276391) //  0
NHSTUB2(ExecuteEventProcedure                  ,0xfc3020f1) //  0
NHSTUB(ExitTask                               ,0x010e526b) //  0
NHSTUB(Fclose_Fut                             ,0xfc301c6b) //  0
NHSTUB(Fgets_Fut                              ,0xfc301d49) //  0
NHSTUB(Fopen_Fut                              ,0xfc301c43) //  0
NHSTUB(Fread_Fut                              ,0xfc301cdd) //  0
NHSTUB(FreeUncacheableMemory                  ,0xfc16cbad) //  0
NHSTUB(Fseek_Fut                              ,0xfc301d7b) //  0
NHSTUB(Fwrite_Fut                             ,0xfc301d13) //  0
NHSTUB(GetBatteryTemperature                  ,0xfc143bc5) //  0
NHSTUB(GetCCDTemperature                      ,0xfc143b69) //  0
NHSTUB(GetCurrentAvValue                      ,0xfc14e00d) //  0
NHSTUB(GetCurrentShutterSpeed                 ,0xfc16d4e3) //  0
NHSTUB(GetUsableMaxAv                         ,0xfc1c1c61) //  0
NHSTUB(GetUsableMinAv                         ,0xfc1c1c4f) //  0
NHSTUB(GetDrive_ClusterSize                   ,0xfc33200b) //  0
NHSTUB(GetDrive_FreeClusters                  ,0xfc33250f) //  0
NHSTUB(GetFocusLensSubjectDistance            ,0xfc2fa8df) //  0
NHSTUB(GetKbdState                            ,0xfc0707e9) //  0
NHSTUB(GetMemInfo                             ,0xfc41e355) //  0
NHSTUB(GetOpticalTemperature                  ,0xfc143c1f) //  0
NHSTUB(GetParameterData                       ,0xfc0aacfd) //  0
NHSTUB(GetPropertyCase                        ,0xfc321ee1) //  0
NHSTUB(GetSystemTime                          ,0xfc3a46a9) //  0
NHSTUB(GetVRAMHPixelsSize                     ,0xfc13e7ad) //  0
NHSTUB(GetVRAMVPixelsSize                     ,0xfc13e7b5) //  0
NHSTUB(GetZoomLensCurrentPoint                ,0xfc2edc6b) //  0
NHSTUB(GetZoomLensCurrentPosition             ,0xfc2eda75) //  0
NHSTUB(GiveSemaphore                          ,0x010e5aa5) //  0
NHSTUB(IsStrobeChargeCompleted                ,0xfc13ad3f) //  0
NHSTUB(LEDDrive                               ,0xfc1d9495) //  0
NHSTUB(LocalTime                              ,0x010e61a1) //  0
NHSTUB(LockMainPower                          ,0xfc15c413) //  0
NHSTUB(MakeDirectory_Fut                      ,0xfc332c57) //  0
NHSTUB(MoveFocusLensToDistance                ,0xfc4b4d07) //  0
NHSTUB(MoveIrisWithAv                         ,0xfc39d585) //  0
NHSTUB(MoveZoomLensWithPoint                  ,0xfc39dd4f) //  0
NHSTUB(Open                                   ,0xfc3328e9) //  0
NHSTUB(PB2Rec                                 ,0xfc0de3a9) //  0
NHSTUB(PT_MoveDigitalZoomToWide               ,0xfc275c47) //  0
NHSTUB(PT_MoveOpticalZoomAt                   ,0xfc1da3c1) //  0
NHSTUB(MoveOpticalZoomAt                      ,0xfc275a71) //  0
NHSTUB(PT_PlaySound                           ,0xfc333df1) //  0
NHSTUB(PostLogicalEventForNotPowerType        ,0xfc332fd1) //  0
NHSTUB(PostLogicalEventToUI                   ,0xfc332ffd) //  0
NHSTUB(PutInNdFilter                          ,0xfc4b5571) //  0
NHSTUB(PutOutNdFilter                         ,0xfc4b5597) //  0
NHSTUB(Read                                   ,0xfc136eb9) //  0
NHSTUB(ReadFastDir                            ,0xfc11934d) //  0
NHSTUB(Rec2PB                                 ,0xfc0de3ef) //  0
NHSTUB(ScreenLock                             ,0xfc3379d5) //  0
NHSTUB(ScreenUnlock                           ,0xfc337a13) //  0
NHSTUB(SetAE_ShutterSpeed                     ,0xfc3fbeb5) //  0
NHSTUB(SetAutoShutdownTime                    ,0xfc15c45f) //  0
NHSTUB(SetCurrentCaptureModeType              ,0xfc2fd1a1) //  0
NHSTUB(SetLogicalEventActive                  ,0xfc3230df) //  0
NHSTUB(SetPropertyCase                        ,0xfc321daf) //  0
NHSTUB(SetScriptMode                          ,0xfc323117) //  0
NHSTUB(SleepTask                              ,0x010e4ff1) //  0
NHSTUB(TakeSemaphore                          ,0x010e5a2d) //  0
NHSTUB(TurnOffBackLight                       ,0xfc305195) //  0
NHSTUB(TurnOnBackLight                        ,0xfc30514b) //  0
NHSTUB(TurnOnDisplay                          ,0xfc0c87b1) //  0
NHSTUB(TurnOffDisplay                         ,0xfc0c87c3) //  0
NHSTUB(UnlockAE                               ,0xfc27676b) //  0
NHSTUB(UnlockAF                               ,0xfc2763c1) //  0
NHSTUB(UnlockMainPower                        ,0xfc15c3af) //  0
NHSTUB(VbattGet                               ,0xfc137779) //  0
NHSTUB(Write                                  ,0xfc3329a5) //  0
NHSTUB(_log                                   ,0x01109198) //  0
NHSTUB(_log10                                 ,0x011096b8) //  0
NHSTUB(_pow                                   ,0x01109820) //  0
NHSTUB(_sqrt                                  ,0x0110b8a0) //  0
NHSTUB(add_ptp_handler                        ,0xfc0f4933) //  0
NHSTUB(close                                  ,0xfc136db3) //  0
NHSTUB(exmem_alloc                            ,0xfc07127f) //  0
NHSTUB(exmem_ualloc                           ,0xfc071189) //  0
NHSTUB(exmem_ufree                            ,0xfc071243) //  0
NHSTUB(free                                   ,0xfc337f3b) //  0
NHSTUB(kbd_p1_f                               ,0xfc07339f) //  0
NHSTUB(kbd_p1_f_cont                          ,0xfc0733a7) //  0
NHSTUB(kbd_p2_f                               ,0xfc072e35) //  0
NHSTUB(kbd_read_keys                          ,0xfc073369) //  0
NHSTUB(kbd_read_keys_r2                       ,0xfc070705) //  0
NHSTUB(lseek                                  ,0xfc332ac9) //  0
NHSTUB(malloc                                 ,0xfc337f05) //  0
NHSTUB(memcmp                                 ,0xfc3380bd) //  0
NHSTUB(memcpy                                 ,0xfc0e7d9d) //  0
NHSTUB(memset                                 ,0xfc10924d) //  0
NHSTUB(mktime_ext                             ,0xfc41ee59) //  0
NHSTUB(open                                   ,0xfc136d43) //  0
NHSTUB(OpenFastDir                            ,0xfc1192ad) //  0
NHSTUB(closedir                               ,0xfc119275) //  0
NHSTUB(get_fstype                             ,0xfc331fa5) //  0
NHSTUB(qsort                                  ,0xfc437499) //  0
NHSTUB(rand                                   ,0xfc1619cf) //  0
NHSTUB(set_control_event                      ,0xfc322ead) //  0
NHSTUB(srand                                  ,0xfc1619c9) //  0
NHSTUB(stat                                   ,0xfc332b01) //  0
NHSTUB(strcat                                 ,0xfc337f91) //  0
NHSTUB(strchr                                 ,0xfc161a41) //  0
NHSTUB(strcmp                                 ,0xfc338039) //  0
NHSTUB(strcpy                                 ,0xfc338015) //  0
NHSTUB(strftime                               ,0xfc1615a5) //  0
NHSTUB(strlen                                 ,0xfc338097) //  0
NHSTUB(strncmp                                ,0xfc161a17) //  0
NHSTUB(strncpy                                ,0xfc337f6d) //  0
NHSTUB(strrchr                                ,0xfc0e7e31) //  0
NHSTUB(strtol                                 ,0xfc0e7d8f) //  0
NHSTUB(strtolx                                ,0xfc0e7c4d) //  0
   DEF(task_CaptSeq                           ,0xfc15275f) //  0
   DEF(task_DvlpSeqTask                       ,0xfc1dda03) //  0
   DEF(task_ExpDrv                            ,0xfc291ccf) //  0
   DEF(task_FileWrite                         ,0xfc065dc7) //  0
   DEF(task_InitFileModules                   ,0xfc0bda11) //  0
   DEF(task_MovieRecord                       ,0xfc1d6c85) //  0
   DEF(task_PhySw                             ,0xfc073069) //  0
   DEF(task_TricInitTask                      ,0xfc404981) //  0
   DEF(hook_CreateTask                        ,0x010e5088) //  0
NHSTUB(time                                   ,0x010e5e6f) //  0
NHSTUB(vsprintf                               ,0xfc0bf85b) //  0
NHSTUB(EngDrvRead                             ,0xfc337dcd) //  0
NHSTUB(PTM_GetCurrentItem                     ,0xfc322a49) //  0
NHSTUB(DisableISDriveError                    ,0xfc39f0e5) //  0
NHSTUB(SetHPTimerAfterNow                     ,0xfc15bb65) //  0
NHSTUB(SetEventFlag                           ,0x010e549b) //  0
NHSTUB(transfer_src_overlay                   ,0xfc337089) //  0
NHSTUB(bzero                                  ,0x01106b1c) //  0
NHSTUB(memset32                               ,0x01106b20) //  0
//NHSTUB(get_dial_hw_position                 ,0xfc119805) //  0            == 0xfc119805
NHSTUB(PT_MFOn                                ,0xfc27775b) //  0
NHSTUB(PT_MFOff                               ,0xfc27778f) //  0
NHSTUB(GetAdChValue                           ,0xfc0e1773) //  0
NHSTUB(EnableHDMIPower                        ,0xfc0bdd99) //  0
NHSTUB(DisableHDMIPower                       ,0xfc0bddc9) //  0
NHSTUB(SetVideoOutType                        ,0xfc3fc445) //  0
NHSTUB(GetVideoOutType                        ,0xfc3fc3b1) //  0
