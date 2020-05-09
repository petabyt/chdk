// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   Main firmware start: 0xfc020000
//   DRYOS R57 (DRYOS version 2.3, release #0057) @ 0xfc56bcc8 ref @ 0xfc032ea4
//   Firmware Ver GM1.01A   // Found @ 0xfc4a3488, "GM1.01A" @ 0xfc4a3495

// Values for makefile.inc
//   PLATFORMOSVER = 57
//   DIGIC = 60
//   MEMISOSTART = 0x3c3998
//   MEMBASEADDR = 0x8000
//   ARAM_HEAP_START = 0x006ce000#  Found @0xfc4ad1e0
//   ARAM_HEAP_SIZE = 0x00022000#  Found @0xfc4ad1ba

// Detected address ranges:
// ROM      0xfc000000 - 0xfe000000 (33554432 bytes)
// RAM code 0x010e1000 - 0x01107bd0 copied from 0xfcd4742c ( 158672 bytes)
// TCM code 0xbfe10800 - 0xbfe17419 copied from 0xfcd6dffc (  27673 bytes)
// RAM data 0x00008000 - 0x00030e58 copied from 0xfcd1e5d4 ( 167512 bytes)
// EVEC     0x00000000 - 0x00000038 copied from 0xfc055948 (     56 bytes)

// Zico Xtensa blobs:
// zico_0 0xbff20000 - 0xbff27800 copied from 0xfcb2a320 (  30720 bytes)
// zico_1 0xbff00000 - 0xbff04b20 copied from 0xfcb31b28 (  19232 bytes)
// zico_2 0x80a00000 - 0x80b0d2d0 copied from 0xfcb36650 (1102544 bytes)

// Found DryOS versions:
// 0xfc56bcc8 main  "DRYOS version 2.3, release #0057"
// 0xfc5818f4 other "DRYOS version 2.3, release #0057"
// 0xfcb37680 other "DRYOS version 2.3, release #0057"

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xfc12fe20
//#undef CAM_HAS_ND_FILTER // Camera does not have an ND filter
// Camera has an iris (CAM_HAS_IRIS_DIAPHRAGM default)

// physw_event_table 0xfc5bfa70 Found @0xfc086b14
// Values below go in 'platform_kbd.h':
//#define SD_READONLY_FLAG    0x00000100 // Found @0xfc5bfae0, levent 0x20a
//#define SD_READONLY_IDX     1
//#define USB_MASK            0x00400000 // Found @0xfc5bfb78, levent 0x202
//#define USB_IDX             2
//#define BATTCOVER_FLAG      0x00200000 // Found @0xfc5bfb70, levent 0x205
//#define BATTCOVER_IDX       2
//#define ANALOG_AV_FLAG      0x00008000 // Found @0xfc5bfaf8, levent 0x200 (non-inverted logic)
//#define ANALOG_AV_IDX       1

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
// WARNING: Key name / function may vary! Values for unknown DryOS versions should not be trusted!
//KeyMap keymap[] = {
//    { 0, KEY_POWER           ,0x00000001 }, // Found @0xfc5bfa70, levent 0x100
//    { 0, KEY_PLAYBACK        ,0x00000002 }, // Found @0xfc5bfa78, levent 0x101
//    { 0, KEY_SHOOT_FULL      ,0x0000000c }, // Found @0xfc5bfa88, levent 0x01
//    { 0, KEY_SHOOT_FULL_ONLY ,0x00000008 }, // Found @0xfc5bfa88, levent 0x01
//    { 0, KEY_SHOOT_HALF      ,0x00000004 }, // Found @0xfc5bfa80, levent 0x00
//    { 0, KEY_VIDEO           ,0x00000100 }, // Found @0xfc5bfa98, levent 0x02
//    { 0, KEY_MENU            ,0x00000200 }, // Found @0xfc5bfaa0, levent 0x14
//    { 0, KEY_DISPLAY         ,0x00002000 }, // Found @0xfc5bfaa8, levent 0x0d
//    { 0, KEY_UP              ,0x00004000 }, // Found @0xfc5bfab0, levent 0x06
//    { 0, KEY_DOWN            ,0x00008000 }, // Found @0xfc5bfab8, levent 0x07
//    { 0, KEY_RIGHT           ,0x00010000 }, // Found @0xfc5bfac0, levent 0x09
//    { 1, KEY_LEFT            ,0x00000004 }, // Found @0xfc5bfac8, levent 0x08
//    { 1, KEY_SET             ,0x00000008 }, // Found @0xfc5bfad0, levent 0x0a
//    { 1, KEY_WIFI            ,0x00000020 }, // Found @0xfc5bfad8, levent 0x103
//    { 0, 0, 0 }
//};

// canon_mode_list 0xfc93b33c Found @0xfc077e1c
// Check modemap values from 'platform/CAMERA/shooting.c':
// 33297  0x8211 In firmware but not in current modemap

// Known propcases
// //      PROPCASE_AFSTEP 13
// #define PROPCASE_FOCUS_STATE 18
// #define PROPCASE_AV 23
// #define PROPCASE_BV 38
// //      PROPCASE_DELTA_DIGITALGAIN 82
// #define PROPCASE_DELTA_SV 84
// //      PROPCASE_DELTA_ND 85
// //      PROPCASE_FELOCK 120
// #define PROPCASE_FLASH_ADJUST_MODE 127
// #define PROPCASE_FLASH_FIRE 128
// //      PROPCASE_HSCAPTURE 144
// #define PROPCASE_EV_CORRECTION_2 216
// #define PROPCASE_ORIENTATION_SENSOR 228
// #define PROPCASE_SV_MARKET 255
//         PROPCASE_SVFIX not found
// #define PROPCASE_TV 272
// Guessed propset: 7, 9

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
DEF(ctypes                            ,0xfc56bd70) // Found @0xfc0321f0
DEF(physw_run                         ,0x000082c8) // Found @0xfc0cefc8
DEF(physw_sleep_delay                 ,0x000082d0) // (0x82c8+0x8) Found @0xfc0cefcc
DEF(physw_status                      ,0x00032710) // Found @0xfc0cf2f4
DEF(fileio_semaphore                  ,0x000134f0) // Found @0xfc07105a
DEF(levent_table                      ,0xfc64d988) // Found @0xfc0c297c
DEF(FlashParamsTable                  ,0xfc93b6b0) // Found @0xfc077e30
DEF(playrec_mode                      ,0x0000bb94) // (0xbb90+0x4) Found @0xfc29dc82
DEF(jpeg_count_str                    ,0x00158f7c) // Found @0xfc0c6a66
DEF(zoom_busy                         ,0x0000b840) // (0xb820+0x20) Found @0xfc0d8486
DEF(focus_busy                        ,0x000136e0) // (0x136d8+0x8) Found @0xfc32720e
DEF(imager_active                     ,0x0000860c) // (0x8608+0x4) Found @0xfc120434
DEF(canon_menu_active                 ,0x0000c694) // (0xc690+0x4) Found @0xfc2d1e8a
DEF(file_counter_var                  ,0x00013398) // Found @0xfc16e6ac
DEF(_nrflag                           ,0x0001c49c) // (0x1c498+0x4) Found @0xfc0adaa0
DEF(av_override_semaphore             ,0x00020bdc) // Found @0xfc540608
DEF(active_bitmap_buffer              ,0x0000c65c) // (0xc62c+0x30) Found @0xfc30a2fa
DEF(displaytype                       ,0x00009244) // (0x9204+0x40) Found @0xfc3246d2
DEF(bitmap_buffer                     ,0x0000c668) // (0xc62c+0x3c) Found @0xfc30a300
DEF(palette_control                   ,0x00014a40) // Found @0xfc2de736
DEF(palette_buffer_ptr                ,0x00014a58) // (0x14a40+0x18) Found @0xfc2de752
DEF(active_palette_buffer             ,0x00014a50) // (0x14a40+0x10) Found @0xfc2de73a
DEF_CONST(uiprop_count                      ,0x000000ce) // Found @0xfc0666a0
DEF(exmem_alloc_table                 ,0x0003a3ac) // Found @0xfc08e6f2
DEF(exmem_types_table                 ,0xfcd22234) // Found @0xfc08e6f6
DEF_CONST(exmem_type_count                  ,0x00000021) // Found @0xfcd22234
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 2 int value(s), the first is the zoom focus length.
// there are 112 entries in the table - set NUM_FL to 112
DEF(focus_len_table                         ,0xfdf3167c) // Found @0xfdf3167c

//NHSTUB(Feof_Fut                             ,0x00000000) //  0        *** != 0xfc326b11
//NHSTUB(Fflush_Fut                           ,0x00000000) //  0        *** != 0xfc326b39
//NHSTUB(GetDrive_TotalClusters               ,0x00000000) //  0        *** != 0xfc316d57
//NHSTUB(GetFocusLensSubjectDistanceFromLens  ,0x00000000) //  0        *** != 0xfc3281bb
//NHSTUB(GetImageFolder                       ,0x00000000) //  0        *** != 0xfc310b09
//NHSTUB(MakeSDCardBootable                   ,0x00000000) //  0        *** != 0xfc3170e5
//NHSTUB(RenameFile_Fut                       ,0x00000000) //  0        *** != 0xfc3268c1
//NHSTUB(SetFileAttributes                    ,0x00000000) //  0        *** != 0xfc317499
//NHSTUB(SetFileTimeStamp                     ,0x00000000) //  0        *** != 0xfc317451
//NHSTUB(apex2us                              ,0x00000000) //  0        *** != 0xfc1c8c83
//NHSTUB(CancelHPTimer                        ,0x00000000) //  0        *** != 0xfc126b7d

NHSTUB(AllocateUncacheableMemory              ,0xfc12fdf1) //  0
NHSTUB(Close                                  ,0xfc317205) //  0
NHSTUB(CreateBinarySemaphore                  ,0xbfe152ed) //  0
NHSTUB(CreateTask                             ,0xbfe14a3d) //  0
NHSTUB(DebugAssert                            ,0x010e1001) //  0
NHSTUB(DeleteDirectory_Fut                    ,0xfc32696d) //  0
NHSTUB(DeleteFile_Fut                         ,0xfc326923) //  0
NHSTUB(DoAELock                               ,0xfc2682e1) //  0
NHSTUB(DoAFLock                               ,0xfc267f67) //  0
//NHSTUB(EnterToCompensationEVF               ,0x00000000) //  0            == 0x00000000
NHSTUB2(ExecuteEventProcedure                  ,0xfc325ea9) //  0
//NHSTUB(ExitFromCompensationEVF              ,0x00000000) //  0            == 0x00000000
NHSTUB(ExitTask                               ,0xbfe14c1f) //  0
//NHSTUB(ExpCtrlTool_StartContiAE             ,0x00000000) //  0            == 0x00000000
//NHSTUB(ExpCtrlTool_StopContiAE              ,0x00000000) //  0            == 0x00000000
NHSTUB(Fclose_Fut                             ,0xfc3269cf) //  0
NHSTUB(Fgets_Fut                              ,0xfc326aad) //  0
NHSTUB(Fopen_Fut                              ,0xfc3269a7) //  0
NHSTUB(Fread_Fut                              ,0xfc326a41) //  0
NHSTUB(FreeUncacheableMemory                  ,0xfc12fe1d) //  0
NHSTUB(Fseek_Fut                              ,0xfc326adf) //  0
NHSTUB(Fwrite_Fut                             ,0xfc326a77) //  0
NHSTUB(GetBatteryTemperature                  ,0xfc396c05) //  0
NHSTUB(GetCCDTemperature                      ,0xfc396ba9) //  0
NHSTUB(GetCurrentAvValue                      ,0xfc0d8029) //  0
NHSTUB(GetCurrentShutterSpeed                 ,0xfc3a0ac3) //  0
NHSTUB(GetUsableMaxAv                         ,0xfc53a771) //  0
NHSTUB(GetUsableMinAv                         ,0xfc53a75f) //  0
NHSTUB(GetDrive_ClusterSize                   ,0xfc316877) //  0
NHSTUB(GetDrive_FreeClusters                  ,0xfc316d7b) //  0
NHSTUB(GetFocusLensSubjectDistance            ,0xfc327eb7) //  0
NHSTUB(GetKbdState                            ,0xfc086c39) //  0
NHSTUB(GetMemInfo                             ,0xfc565279) //  0
NHSTUB(GetOpticalTemperature                  ,0xfc396c5f) //  0
NHSTUB(GetParameterData                       ,0xfc066f63) //  0
NHSTUB(GetPropertyCase                        ,0xfc30fae5) //  0
NHSTUB(GetSystemTime                          ,0xfc542949) //  0
NHSTUB(GetVRAMHPixelsSize                     ,0xfc0d28c5) //  0
NHSTUB(GetVRAMVPixelsSize                     ,0xfc0d28cd) //  0
NHSTUB(GetZoomLensCurrentPoint                ,0xfc0d86d1) //  0
NHSTUB(GetZoomLensCurrentPosition             ,0xfc0d8665) //  0
NHSTUB(GiveSemaphore                          ,0xbfe15459) //  0
NHSTUB(IsStrobeChargeCompleted                ,0xfc0e7e8d) //  0
NHSTUB(LEDDrive                               ,0xfc4abc21) //  0
NHSTUB(LocalTime                              ,0x010e1581) //  0
NHSTUB(LockMainPower                          ,0xfc126fc1) //  0
NHSTUB(MakeDirectory_Fut                      ,0xfc3174ef) //  0
NHSTUB(MoveFocusLensToDistance                ,0xfc54daf5) //  0
NHSTUB(MoveIrisWithAv                         ,0xfc5405f5) //  0
NHSTUB(MoveZoomLensWithPoint                  ,0xfc540ea9) //  0
NHSTUB(Open                                   ,0xfc317181) //  0
NHSTUB(PB2Rec                                 ,0xfc2cfd3d) //  0
NHSTUB(PT_MoveDigitalZoomToWide               ,0xfc267763) //  0
NHSTUB(PT_MoveOpticalZoomAt                   ,0xfc4acb45) //  0
NHSTUB(MoveOpticalZoomAt                      ,0xfc267663) //  0
//NHSTUB(PT_PlaySound                         ,0xfc3061c1) //  0            == 0xfc3061c1
NHSTUB(PostLogicalEventForNotPowerType        ,0xfc2e3da5) //  0
NHSTUB(PostLogicalEventToUI                   ,0xfc2e3dd1) //  0
NHSTUB(PutInNdFilter                          ,0xfc54dddd) //  0
NHSTUB(PutOutNdFilter                         ,0xfc54de03) //  0
NHSTUB(Read                                   ,0xfc38d7ed) //  0
NHSTUB(ReadFastDir                            ,0xfc3f8459) //  0
NHSTUB(Rec2PB                                 ,0xfc2cfd7f) //  0
//NHSTUB(Restart                              ,0x00000000) //  0            == 0x00000000
NHSTUB(ScreenLock                             ,0xfc30a249) //  0
NHSTUB(ScreenUnlock                           ,0xfc30a287) //  0
NHSTUB(SetAE_ShutterSpeed                     ,0xfc566b15) //  0
NHSTUB(SetAutoShutdownTime                    ,0xfc127011) //  0
NHSTUB(SetCurrentCaptureModeType              ,0xfc2fa7e3) //  0
NHSTUB(SetLogicalEventActive                  ,0xfc2ffe6f) //  0
//NHSTUB(SetParameterData                     ,0x00000000) //  0            == 0x00000000
NHSTUB(SetPropertyCase                        ,0xfc30f9b3) //  0
NHSTUB(SetScriptMode                          ,0xfc2ffea7) //  0
NHSTUB(SleepTask                              ,0xbfe14969) //  0
NHSTUB(TakeSemaphore                          ,0xbfe153e1) //  0
NHSTUB(TurnOffBackLight                       ,0xfc324f41) //  0
NHSTUB(TurnOnBackLight                        ,0xfc324f01) //  0
NHSTUB(TurnOnDisplay                          ,0xfc0f0ddb) //  0
NHSTUB(TurnOffDisplay                         ,0xfc0f0ded) //  0
NHSTUB(UnlockAE                               ,0xfc2682ff) //  0
NHSTUB(UnlockAF                               ,0xfc267f8f) //  0
NHSTUB(UnlockMainPower                        ,0xfc126f5d) //  0
//NHSTUB(UnsetZoomForMovie                    ,0x00000000) //  0            == 0x00000000
NHSTUB(VbattGet                               ,0xfc0b2dd1) //  0
NHSTUB(Write                                  ,0xfc31723d) //  0
//NHSTUB(WriteSDCard                          ,0x00000000) //  0            == 0x00000000
NHSTUB(_log                                   ,0x011031c8) //  0
NHSTUB(_log10                                 ,0x011036e8) //  0
NHSTUB(_pow                                   ,0x01103850) //  0
NHSTUB(_sqrt                                  ,0x011058d0) //  0
NHSTUB(add_ptp_handler                        ,0xfc2c88b3) //  0
NHSTUB(close                                  ,0xfc38d6e7) //  0
NHSTUB(exmem_alloc                            ,0xfc08ec2b) //  0
NHSTUB(exmem_ualloc                           ,0xfc08eb35) //  0
NHSTUB(exmem_ufree                            ,0xfc08ebef) //  0
NHSTUB(free                                   ,0xfc328e4f) //  0
NHSTUB(kbd_p1_f                               ,0xfc0cf2ed) //  0
NHSTUB(kbd_p1_f_cont                          ,0xfc0cf2f5) //  0
NHSTUB(kbd_p2_f                               ,0xfc0ced65) //  0
NHSTUB(kbd_read_keys                          ,0xfc0cf2b7) //  0
NHSTUB(kbd_read_keys_r2                       ,0xfc086b11) //  0
NHSTUB(lseek                                  ,0xfc317361) //  0
NHSTUB(malloc                                 ,0xfc328e19) //  0
NHSTUB(memcmp                                 ,0xfc32906d) //  0
NHSTUB(memcpy                                 ,0xfc129fcd) //  0
NHSTUB(memset                                 ,0xfc4ad375) //  0
NHSTUB(mktime_ext                             ,0xfc397429) //  0
NHSTUB(open                                   ,0xfc38d677) //  0
NHSTUB(OpenFastDir                            ,0xfc3f83b9) //  0
NHSTUB(closedir                               ,0xfc3f8381) //  0
NHSTUB(get_fstype                             ,0xfc316811) //  0
NHSTUB(qsort                                  ,0xfc3cb131) //  0
NHSTUB(rand                                   ,0xfc397833) //  0
//NHSTUB(reboot_fw_update                     ,0x00000000) //  0            == 0x00000000
NHSTUB(set_control_event                      ,0xfc2ffbb5) //  0
NHSTUB(srand                                  ,0xfc39782d) //  0
NHSTUB(stat                                   ,0xfc317399) //  0
NHSTUB(strcat                                 ,0xfc328d55) //  0
NHSTUB(strchr                                 ,0xfc12a061) //  0
NHSTUB(strcmp                                 ,0xfc328ea5) //  0
NHSTUB(strcpy                                 ,0xfc328e81) //  0
NHSTUB(strftime                               ,0x010e1689) //  0
NHSTUB(strlen                                 ,0xfc328f59) //  0
NHSTUB(strncmp                                ,0xfc328d77) //  0
NHSTUB(strncpy                                ,0xfc32875d) //  0
NHSTUB(strrchr                                ,0xfc12a073) //  0
NHSTUB(strtol                                 ,0xfc129fbf) //  0
NHSTUB(strtolx                                ,0xfc129e7d) //  0
   DEF(task_CaptSeq                           ,0xfc0646b3) //  0
   DEF(task_DvlpSeqTask                       ,0xfc07c14b) //  0
   DEF(task_ExpDrv                            ,0xfc286543) //  0
   DEF(task_FileWrite                         ,0xfc3f7c99) //  0
   DEF(task_InitFileModules                   ,0xfc0d4309) //  0
   DEF(task_MovieRecord                       ,0xfc0a3863) //  0
   DEF(task_PhySw                             ,0xfc0cefc7) //  0
   DEF(task_TricInitTask                      ,0xfc4417a9) //  0
   DEF(hook_CreateTask                        ,0xbfe14a3c) //  0
NHSTUB(time                                   ,0x010e11e3) //  0
NHSTUB(vsprintf                               ,0xfc0de91b) //  0
NHSTUB(EngDrvRead                             ,0xfc328fad) //  0
NHSTUB(PTM_GetCurrentItem                     ,0xfc30f4a9) //  0
NHSTUB(DisableISDriveError                    ,0xfc541afb) //  0
NHSTUB(SetHPTimerAfterNow                     ,0xfc126ae5) //  0
NHSTUB(SetEventFlag                           ,0xbfe14e4f) //  0
NHSTUB(transfer_src_overlay                   ,0xfc309891) //  0
NHSTUB(bzero                                  ,0x01100b48) //  0
NHSTUB(memset32                               ,0x01100b4c) //  0
NHSTUB(get_dial_hw_position                   ,0xfc110d61) //  0
NHSTUB(PT_MFOn                                ,0xfc2691c1) //  0
NHSTUB(PT_MFOff                               ,0xfc2691f1) //  0
NHSTUB(GetAdChValue                           ,0xfc122bcf) //  0
NHSTUB(EnableHDMIPower                        ,0xfc0d67fd) //  0
NHSTUB(DisableHDMIPower                       ,0xfc0d6833) //  0
NHSTUB(SetVideoOutType                        ,0xfc5670a5) //  0
NHSTUB(GetVideoOutType                        ,0xfc567011) //  0
