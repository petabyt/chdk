// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   Main firmware start: 0xfc020000
//   DRYOS R57 (DRYOS version 2.3, release #0057) @ 0xfc608084 ref @ 0xfc04686c
//   Firmware Ver GM1.10D   // Found @ 0xfc1fb03c, "GM1.10D" @ 0xfc1fb049

// Values for makefile.inc
//   PLATFORMOSVER = 57
//   MEMISOSTART = 0x3d6ffc
//   MEMBASEADDR = 0x8000
//   ARAM_HEAP_START = 0x0074e000 #  Found @0xfc18ec9c
//   ARAM_HEAP_SIZE = 0x00022000 #  Found @0xfc18ec76

// Detected address ranges:
// ROM      0xfc000000 - 0xfe000000 (33554432 bytes)
// RAM code 0x010e1000 - 0x01107d60 copied from 0xfceb18d0 ( 159072 bytes)
// RAM code 0xbfe10800 - 0xbfe1741d copied from 0xfced8630 (  27677 bytes)
// RAM data 0x00008000 - 0x00055334 copied from 0xfce6459c ( 316212 bytes)

// Zico Xtensa blobs:
// zico_0 0xbff20000 - 0xbff27938 copied from 0xfca326f8 (  31032 bytes)
// zico_1 0xbff00000 - 0xbff04b30 copied from 0xfca3a038 (  19248 bytes)
// zico_2 0x80a00000 - 0x80b15060 copied from 0xfca3eb70 (1134688 bytes)

// Found DryOS versions:
// 0xfc608084 main  "DRYOS version 2.3, release #0057"
// 0xfc61f510 other "DRYOS version 2.3, release #0057"
// 0xfca3fd20 other "DRYOS version 2.3, release #0057"

// Camera is interchangeable lens

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xfc142914
//#undef CAM_HAS_ND_FILTER // Camera does not have an ND filter
// Camera has an iris (CAM_HAS_IRIS_DIAPHRAGM default)

// physw_event_table 0xfc623cfc Found @0xfc07eeda
// Values below go in 'platform_kbd.h':
//#define SD_READONLY_FLAG    0x20000000 // Found @0xfc623d8c, levent 0x20a
//#define SD_READONLY_IDX     1
//#define USB_MASK            0x10000000 // Found @0xfc623dec, levent 0x202
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
// WARNING: Values only verified on sx280hs (R52) and g7x (R55p6) errors likely on other cams!
//KeyMap keymap[] = {
//    { 0, KEY_POWER           ,0x00000001 }, // Found @0xfc623cfc, levent 0x100 (uses inverted logic in physw_status)
//    { 0, KEY_PLAYBACK        ,0x00000002 }, // Found @0xfc623d04, levent 0x101 (uses inverted logic in physw_status)
//    { 1, KEY_SHOOT_FULL      ,0x00040001 }, // Found @0xfc623d2c, levent 0x01
//    { 1, KEY_SHOOT_HALF      ,0x00040000 }, // Found @0xfc623d7c, levent 0x00
//    { 1, KEY_SHOOT_FULL_ONLY ,0x00000001 }, // Found @0xfc623d2c, levent 0x01
//    { 1, KEY_VIDEO           ,0x00000008 }, // Found @0xfc623d34, levent 0x02
//    { 1, KEY_UP              ,0x00000020 }, // Found @0xfc623d3c, levent 0x06
//    { 1, KEY_DOWN            ,0x00000040 }, // Found @0xfc623d44, levent 0x07
//    { 1, KEY_RIGHT           ,0x00000080 }, // Found @0xfc623d4c, levent 0x09
//    { 1, KEY_LEFT            ,0x00000100 }, // Found @0xfc623d54, levent 0x08
//    { 1, KEY_SET             ,0x00000200 }, // Found @0xfc623d5c, levent 0x0a
//    { 1, KEY_MENU            ,0x00001000 }, // Found @0xfc623d74, levent 0x14
//    { 0, 0, 0 }
//};

// canon_mode_list 0xfc77efb0 Found @0xfc0e3dc8
// Check modemap values from 'platform/CAMERA/shooting.c':
// 32768  0x8000 In firmware but not in current modemap

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
// EXMEM_PHOTO_IN_MOVIE 32

// Values below can be overridden in 'stubs_min.S':
DEF(ctypes                            ,0xfc60812c) // Found @0xfc045b30
DEF(physw_run                         ,0x000082cc) // Found @0xfc08c8ca
DEF(physw_sleep_delay                 ,0x000082d4) // (0x82cc+0x8) Found @0xfc08c8ce
DEF(physw_status                      ,0x00056bec) // Found @0xfc08cbb4
DEF(fileio_semaphore                  ,0x00012030) // Found @0xfc07c0be
DEF(levent_table                      ,0xfc660af0) // Found @0xfc11269c
DEF(FlashParamsTable                  ,0xfc77f328) // Found @0xfc0e3ddc
DEF(playrec_mode                      ,0x0000b2f4) // (0xb2f0+0x4) Found @0xfc33e156
DEF(jpeg_count_str                    ,0x00190ac0) // Found @0xfc1a15f6
//DEF(zoom_busy                         ,0x00000000), ** != ** stubs_min = 0x00000001 (1)
//DEF(focus_busy                        ,0x00000000), ** != ** stubs_min = 0x00000001 (1)
DEF(imager_active                     ,0x0000861c) // (0x8618+0x4) Found @0xfc128198
//DEF(canon_menu_active                 ,0x0000b9a8),          stubs_min = 0x0000b9a8 (0x0000b9a8)
//DEF(_nrflag                           ,0x00029c00),          stubs_min = 0x00029c00 (0x29c00)
DEF(av_override_semaphore             ,0x0002e804) // Found @0xfc43f6cc
DEF(active_bitmap_buffer              ,0x0000b964) // (0xb924+0x40) Found @0xfc38c582
DEF_CONST(uiprop_count                      ,0x000000d1) // Found @0xfc27de04
DEF(exmem_alloc_table                 ,0x0005e2b8) // Found @0xfc08125a
DEF(exmem_types_table                 ,0xfce67974) // Found @0xfc08125e
DEF_CONST(exmem_type_count                  ,0x00000021) // Found @0xfce67974

//NHSTUB(DeleteDirectory_Fut                  ,0x00000000) //  0        *** != 0xfc38a185
//NHSTUB(DeleteFile_Fut                       ,0x00000000) //  0        *** != 0xfc38a13b
//NHSTUB(EnterToCompensationEVF               ,0x00000000) //  0        *** != 0xfc2a5f6b
//NHSTUB(ExitFromCompensationEVF              ,0x00000000) //  0        *** != 0xfc2a5fad
//NHSTUB(ExpCtrlTool_StartContiAE             ,0x00000000) //  0        *** != 0xfc2bb61b
//NHSTUB(ExpCtrlTool_StopContiAE              ,0x00000000) //  0        *** != 0xfc2bb7b1
//NHSTUB(Feof_Fut                             ,0x00000000) //  0        *** != 0xfc38a329
//NHSTUB(Fflush_Fut                           ,0x00000000) //  0        *** != 0xfc38a351
//NHSTUB(GetDrive_TotalClusters               ,0x00000000) //  0        *** != 0xfc076ab3
//NHSTUB(GetFocusLensSubjectDistanceFromLens  ,0x00000000) //  0        *** != 0xfc360e8b
//NHSTUB(GetImageFolder                       ,0x00000000) //  0        *** != 0xfc3134bd
//NHSTUB(MakeSDCardBootable                   ,0x00000000) //  0        *** != 0xfc3896e9
//NHSTUB(MoveFocusLensToDistance              ,0x00000000) //  0        *** != 0xfc43e66f
//NHSTUB(MoveZoomLensWithPoint                ,0xfc4402c1) //  0        *** != 0x00000000
//NHSTUB(PT_MoveOpticalZoomAt                 ,0xfc18ae45) //  0        *** != 0x00000000
//NHSTUB(PT_PlaySound                         ,0x00000000) //  0        *** != 0xfc38c91f
//NHSTUB(RenameFile_Fut                       ,0x00000000) //  0        *** != 0xfc38a0d9
//NHSTUB(Restart                              ,0x00000000) //  0        *** != 0xfc12790b
//NHSTUB(ScreenLock                           ,0x00000000) //  0        *** != 0xfc38c505
//NHSTUB(ScreenUnlock                         ,0x00000000) //  0        *** != 0xfc38c53b
//NHSTUB(SetFileAttributes                    ,0x00000000) //  0        *** != 0xfc389b19
//NHSTUB(SetFileTimeStamp                     ,0x00000000) //  0        *** != 0xfc389ad1
//NHSTUB(SetParameterData                     ,0x00000000) //  0        *** != 0xfc27e64f
//NHSTUB(WriteSDCard                          ,0x00000000) //  0        *** != 0x010e2c9d
//NHSTUB(apex2us                              ,0x00000000) //  0        *** != 0xfc1b1d07
//NHSTUB(displaybusyonscreen                  ,0x00000000) //  0        *** != 0xfc3273d3
//NHSTUB(undisplaybusyonscreen                ,0x00000000) //  0        *** != 0xfc327469
//NHSTUB(CancelHPTimer                        ,0x00000000) //  0        *** != 0xfc1faa7d
//NHSTUB(SetHPTimerAfterNow                   ,0x00000000) //  0        *** != 0xfc1fa9e5

NHSTUB(AllocateUncacheableMemory              ,0xfc1428e5) //  0
NHSTUB(Close                                  ,0xfc389885) //  0
NHSTUB(CreateBinarySemaphore                  ,0xbfe152f1) //  0
NHSTUB(CreateTask                             ,0xbfe14a41) //  0
NHSTUB(DebugAssert                            ,0x010e1009) //  0
NHSTUB(DoAELock                               ,0xfc2a6157) //  0
NHSTUB(DoAFLock                               ,0xfc2a5d83) //  0
NHSTUB2(ExecuteEventProcedure                  ,0xfc33e491) //  0
NHSTUB(ExitTask                               ,0xbfe14c23) //  0
NHSTUB(Fclose_Fut                             ,0xfc38a1e7) //  0
NHSTUB(Fgets_Fut                              ,0xfc38a2c5) //  0
NHSTUB(Fopen_Fut                              ,0xfc38a1bf) //  0
NHSTUB(Fread_Fut                              ,0xfc38a259) //  0
NHSTUB(FreeUncacheableMemory                  ,0xfc142911) //  0
NHSTUB(Fseek_Fut                              ,0xfc38a2f7) //  0
NHSTUB(Fwrite_Fut                             ,0xfc38a28f) //  0
NHSTUB(GetBatteryTemperature                  ,0xfc1f3941) //  0
NHSTUB(GetCCDTemperature                      ,0xfc1f38e5) //  0
NHSTUB(GetCurrentAvValue                      ,0xfc3398f9) //  0
NHSTUB(GetCurrentShutterSpeed                 ,0xfc142baf) //  0
NHSTUB(GetUsableMaxAv                         ,0xfc181a65) //  0
NHSTUB(GetUsableMinAv                         ,0xfc181a53) //  0
NHSTUB(GetDrive_ClusterSize                   ,0xfc388e7b) //  0
NHSTUB(GetDrive_FreeClusters                  ,0xfc38937f) //  0
NHSTUB(GetFocusLensSubjectDistance            ,0xfc360d0b) //  0
NHSTUB(GetKbdState                            ,0xfc07efad) //  0
NHSTUB(GetMemInfo                             ,0xfc5b6b9d) //  0
NHSTUB(GetOpticalTemperature                  ,0xfc1f399b) //  0
NHSTUB(GetParameterData                       ,0xfc27e6c7) //  0
NHSTUB(GetPropertyCase                        ,0xfc38822b) //  0
NHSTUB(GetSystemTime                          ,0xfc443929) //  0
NHSTUB(GetVRAMHPixelsSize                     ,0xfc12a4d3) //  0
NHSTUB(GetVRAMVPixelsSize                     ,0xfc12a4db) //  0
NHSTUB(GetZoomLensCurrentPoint                ,0xfc18639f) //  0
NHSTUB(GetZoomLensCurrentPosition             ,0xfc186353) //  0
NHSTUB(GiveSemaphore                          ,0xbfe1545d) //  0
NHSTUB(IsStrobeChargeCompleted                ,0xfc152295) //  0
NHSTUB(LEDDrive                               ,0xfc189ec5) //  0
NHSTUB(LocalTime                              ,0x010e1589) //  0
NHSTUB(LockMainPower                          ,0xfc1fb48d) //  0
NHSTUB(MakeDirectory_Fut                      ,0xfc389b6f) //  0
NHSTUB(MoveIrisWithAv                         ,0xfc43f6b9) //  0
NHSTUB(Open                                   ,0xfc389801) //  0
NHSTUB(PB2Rec                                 ,0xfc33ff7d) //  0
NHSTUB(PT_MoveDigitalZoomToWide               ,0xfc2a563d) //  0
NHSTUB(MoveOpticalZoomAt                      ,0xfc2a553d) //  0
NHSTUB(PostLogicalEventForNotPowerType        ,0xfc3858c9) //  0
NHSTUB(PostLogicalEventToUI                   ,0xfc3858fd) //  0
NHSTUB(Read                                   ,0xfc1ebe61) //  0
NHSTUB(ReadFastDir                            ,0xfc1168dd) //  0
NHSTUB(Rec2PB                                 ,0xfc33ffc1) //  0
NHSTUB(SetAE_ShutterSpeed                     ,0xfc5bb2a9) //  0
NHSTUB(SetAutoShutdownTime                    ,0xfc1fb4dd) //  0
NHSTUB(SetCurrentCaptureModeType              ,0xfc370ffb) //  0
NHSTUB(SetLogicalEventActive                  ,0xfc37948d) //  0
NHSTUB(SetPropertyCase                        ,0xfc3880d9) //  0
NHSTUB(SetScriptMode                          ,0xfc3794c5) //  0
NHSTUB(SleepTask                              ,0xbfe1496d) //  0
NHSTUB(TakeSemaphore                          ,0xbfe153e5) //  0
NHSTUB(TurnOffBackLight                       ,0xfc1f0abb) //  0
NHSTUB(TurnOnBackLight                        ,0xfc1f0a5f) //  0
NHSTUB(TurnOnDisplay                          ,0xfc177017) //  0
NHSTUB(TurnOffDisplay                         ,0xfc177029) //  0
NHSTUB(UnlockAE                               ,0xfc2a6175) //  0
NHSTUB(UnlockAF                               ,0xfc2a5db3) //  0
NHSTUB(UnlockMainPower                        ,0xfc1fb425) //  0
//NHSTUB(UnsetZoomForMovie                    ,0x00000000) //  0            == 0x00000000
NHSTUB(VbattGet                               ,0xfc12711b) //  0
NHSTUB(Write                                  ,0xfc3898bd) //  0
NHSTUB(_log                                   ,0x011033b8) //  0
NHSTUB(_log10                                 ,0x011038d8) //  0
NHSTUB(_pow                                   ,0x01103a40) //  0
NHSTUB(_sqrt                                  ,0x01105ac0) //  0
NHSTUB(add_ptp_handler                        ,0xfc307ad7) //  0
NHSTUB(close                                  ,0xfc1ebd5b) //  0
NHSTUB(exmem_alloc                            ,0xfc081793) //  0
NHSTUB(exmem_free                             ,0xfc0817d3) //  0
NHSTUB(free                                   ,0xfc38d427) //  0
NHSTUB(kbd_p1_f                               ,0xfc08cbad) //  0
NHSTUB(kbd_p1_f_cont                          ,0xfc08cbb5) //  0
NHSTUB(kbd_p2_f                               ,0xfc08c625) //  0
NHSTUB(kbd_read_keys                          ,0xfc08cb77) //  0
NHSTUB(kbd_read_keys_r2                       ,0xfc07eed1) //  0
NHSTUB(lseek                                  ,0xfc3899e1) //  0
NHSTUB(malloc                                 ,0xfc38d3f1) //  0
NHSTUB(memcmp                                 ,0xfc38d64d) //  0
NHSTUB(memcpy                                 ,0xfc20199d) //  0
NHSTUB(memset                                 ,0xfc1a7cf5) //  0
NHSTUB(mktime_ext                             ,0xfc201599) //  0
NHSTUB(open                                   ,0xfc1ebceb) //  0
NHSTUB(OpenFastDir                            ,0xfc11683d) //  0
NHSTUB(closedir                               ,0xfc116805) //  0
NHSTUB(get_fstype                             ,0xfc388e15) //  0
NHSTUB(qsort                                  ,0xfc3c5e35) //  0
NHSTUB(rand                                   ,0xfc1049f3) //  0
//NHSTUB(reboot_fw_update                     ,0x00000000) //  0            == 0x00000000
NHSTUB(set_control_event                      ,0xfc3792d1) //  0
NHSTUB(srand                                  ,0xfc1049ed) //  0
NHSTUB(stat                                   ,0xfc389a19) //  0
NHSTUB(strcat                                 ,0xfc38d22d) //  0
NHSTUB(strchr                                 ,0xfc201a5b) //  0
NHSTUB(strcmp                                 ,0xfc38d47d) //  0
NHSTUB(strcpy                                 ,0xfc38d459) //  0
NHSTUB(strftime                               ,0xfc2015c9) //  0
NHSTUB(strlen                                 ,0xfc38d4e1) //  0
NHSTUB(strncmp                                ,0xfc38d24f) //  0
NHSTUB(strncpy                                ,0xfc38d209) //  0
NHSTUB(strrchr                                ,0xfc13b359) //  0
NHSTUB(strtol                                 ,0xfc13b34b) //  0
//NHSTUB(strtolx                              ,0xfc13b209) //  0            == 0xfc13b209
   DEF(task_CaptSeq                           ,0xfc0bce67) //  0
   DEF(task_DvlpSeqTask                       ,0xfc10ffbb) //  0
   DEF(task_ExpDrv                            ,0xfc27baa1) //  0
   DEF(task_FileWrite                         ,0xfc0736b3) //  0
   DEF(task_InitFileModules                   ,0xfc0d4a01) //  0
   DEF(task_MovieRecord                       ,0xfc100c55) //  0
   DEF(task_PhySw                             ,0xfc08c8c9) //  0
   DEF(task_TouchPanel                        ,0xfc133401) //  0
   DEF(task_TricInitTask                      ,0xfc56075d) //  0
   DEF(hook_CreateTask                        ,0xbfe14a40) //  0
NHSTUB(time                                   ,0x010e11eb) //  0
NHSTUB(vsprintf                               ,0xfc1049bf) //  0
NHSTUB(EngDrvRead                             ,0xfc38d2b9) //  0
NHSTUB(PTM_GetCurrentItem                     ,0xfc37210d) //  0
NHSTUB(SetEventFlag                           ,0xbfe14e53) //  0
NHSTUB(transfer_src_overlay                   ,0xfc38ba49) //  0
NHSTUB(bzero                                  ,0x01100b74) //  0
NHSTUB(memset32                               ,0x01100b78) //  0
NHSTUB(PT_MFOn                                ,0xfc2a6ee9) //  0
NHSTUB(PT_MFOff                               ,0xfc2a6f19) //  0
NHSTUB(GetAdChValue                           ,0xfc1f1c83) //  0
NHSTUB(EnableHDMIPower                        ,0xfc131925) //  0
NHSTUB(DisableHDMIPower                       ,0xfc131955) //  0
