// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   Main firmware start: 0xfc020000
//   DRYOS R55 (DRYOS version 2.3, release #0055+p6)
//   Firmware Ver GM1.00D   // Found @ 0xfc1591f8, "GM1.00D" @ 0xfc159205

// Values for makefile.inc
//   PLATFORMOSVER = 55
//   MEMISOSTART = 0x36a354
//   MEMBASEADDR = 0x8000
//   ARAM_HEAP_START = 0x006ce000 #  Found @0xfc101938
//   ARAM_HEAP_SIZE = 0x00022000 #  Found @0xfc101912

// Detected address ranges:
// ROM      0xfc000000 - 0xfe000000 (33554432 bytes)
// RAM code 0x010e1000 - 0x0110dc1c copied from 0xfcd67030 ( 183324 bytes)
// RAM data 0x00008000 - 0x000352b8 copied from 0xfcd39d78 ( 185016 bytes)

// Zico Xtensa blobs:
// zico_0 0xbff20000 - 0xbff277b8 copied from 0xfcb212e4 (  30648 bytes)
// zico_1 0xbff00000 - 0xbff04ad0 copied from 0xfcb28aa4 (  19152 bytes)
// zico_2 0x80a00000 - 0x80b06100 copied from 0xfcb2d57c (1073408 bytes)

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xfc0ef0fc
//#define CAM_HAS_ND_FILTER 1 // Camera has ND filter
// Camera has an iris (CAM_HAS_IRIS_DIAPHRAGM default)

// physw_event_table 0xfc613714 Found @0xfc075c9a
// Values below go in 'platform_kbd.h':
//#define SD_READONLY_FLAG    0x20000000 // Found @0xfc6137f4, levent 0x20a
//#define SD_READONLY_IDX     1
//#define USB_MASK            0x10000000 // Found @0xfc613834, levent 0x202
//#define USB_IDX             2
//#define BATTCOVER_FLAG      0x04000000 // Found @0xfc61382c, levent 0x205
//#define BATTCOVER_IDX       2
//#define ANALOG_AV_FLAG      0x00008000 // Found @0xfc6137e4, levent 0x200 (non-inverted logic)
//#define ANALOG_AV_IDX       1

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
// WARNING: Values only verified on sx280hs (R52) and g7x (R55p6) errors likely on other cams!
//KeyMap keymap[] = {
//    { 0, KEY_SHOOT_FULL      ,0x00040001 }, // Found @0xfc613714, levent 0x01
//    { 0, KEY_SHOOT_HALF      ,0x00040000 }, // Found @0xfc61378c, levent 0x00
//    { 0, KEY_SHOOT_FULL_ONLY ,0x00000001 }, // Found @0xfc613714, levent 0x01
//    { 0, KEY_ZOOM_OUT        ,0x00000002 }, // Found @0xfc61371c, levent 0x04
//    { 0, KEY_ZOOM_IN         ,0x00000004 }, // Found @0xfc613724, levent 0x03
//    { 0, KEY_VIDEO           ,0x00000008 }, // Found @0xfc61372c, levent 0x02
//    { 0, KEY_MENU            ,0x00000010 }, // Found @0xfc613734, levent 0x14
//    { 0, KEY_UP              ,0x00000020 }, // Found @0xfc61373c, levent 0x06
//    { 0, KEY_DOWN            ,0x00000040 }, // Found @0xfc613744, levent 0x07
//    { 0, KEY_RIGHT           ,0x00000080 }, // Found @0xfc61374c, levent 0x09
//    { 0, KEY_LEFT            ,0x00000100 }, // Found @0xfc613754, levent 0x08
//    { 0, KEY_SET             ,0x00000200 }, // Found @0xfc61375c, levent 0x0a
//    { 0, KEY_PLAYBACK        ,0x00000800 }, // Found @0xfc61376c, levent 0x101
//    { 0, KEY_POWER           ,0x00020000 }, // Found @0xfc613784, levent 0x100
//    { 0, 0, 0 }
//};

// canon_mode_list 0xfc94b408 Found @0xfc118650
// Check modemap values from 'platform/CAMERA/shooting.c':
// 33297  0x8211 In firmware but not in current modemap
//  4172  0x104c In firmware but not in current modemap

// Known propcases
// //      PROPCASE_AFSTEP 13
// #define PROPCASE_FOCUS_STATE 18
// #define PROPCASE_AV 23
// #define PROPCASE_BV 38
// //      PROPCASE_DELTA_DIGITALGAIN 82
// #define PROPCASE_DELTA_SV 84
// //      PROPCASE_DELTA_ND 85
// #define PROPCASE_EV_CORRECTION_2 216
// #define PROPCASE_ORIENTATION_SENSOR 228
// #define PROPCASE_SV_MARKET 255
//         PROPCASE_SVFIX not found
// #define PROPCASE_TV 272
// Guessed propset: 7, 9

// Values below can be overridden in 'stubs_min.S':
DEF(ctypes                            ,0xfc5bd39c)
DEF(physw_run                         ,0x000082c8) // Found @0xfc0780c2
DEF(physw_sleep_delay                 ,0x000082d0) // (0x82c8+0x8) Found @0xfc0780c6
DEF(physw_status                      ,0x00036c10) // Found @0xfc0783fe
DEF(fileio_semaphore                  ,0x000139b8) // Found @0xfc073b86
DEF(levent_table                      ,0xfc6deb34) // Found @0xfc0d09b4
DEF(FlashParamsTable                  ,0xfc94b76c) // Found @0xfc118664
DEF(playrec_mode                      ,0x0000bec4) // (0xbec0+0x4) Found @0xfc2f77ea
DEF(jpeg_count_str                    ,0x0015d630) // Found @0xfc103a94
DEF(zoom_busy                         ,0x00013e18) // (0x13df8+0x20) Found @0xfc1dac7e
DEF(focus_busy                        ,0x00013bb0) // (0x13ba8+0x8) Found @0xfc31ef16
DEF(imager_active                     ,0x00008664) // (0x8660+0x4) Found @0xfc138a18
DEF(_nrflag                           ,0x0001fa4c) // (0x1fa48+0x4) Found @0xfc383b70
DEF(active_bitmap_buffer              ,0x0000ca38) // (0xca04+0x34) Found @0xfc362058
DEF_CONST(uiprop_count                      ,0x000000c7) // Found @0xfc0af556

//NHSTUB(Feof_Fut                             ,0x00000000) //  0        *** != 0xfc325d21
//NHSTUB(Fflush_Fut                           ,0x00000000) //  0        *** != 0xfc325d49
//NHSTUB(GetDrive_TotalClusters               ,0x00000000) //  0        *** != 0xfc357bd7
//NHSTUB(GetFocusLensSubjectDistanceFromLens  ,0x00000000) //  0        *** != 0xfc31fdfd
//NHSTUB(GetImageFolder                       ,0x00000000) //  0        *** != 0xfc320ebf
//NHSTUB(MakeSDCardBootable                   ,0x00000000) //  0        *** != 0xfc357f65
//NHSTUB(RenameFile_Fut                       ,0x00000000) //  0        *** != 0xfc325ad1
//NHSTUB(SetFileAttributes                    ,0x00000000) //  0        *** != 0xfc358319
//NHSTUB(SetFileTimeStamp                     ,0x00000000) //  0        *** != 0xfc3582d1
//NHSTUB(apex2us                              ,0x00000000) //  0        *** != 0xfc382687
//NHSTUB(CancelHPTimer                        ,0x00000000) //  0        *** != 0xfc158e25

NHSTUB(AllocateUncacheableMemory              ,0xfc0ef0cd) //  0
NHSTUB(Close                                  ,0xfc358085) //  0
NHSTUB(CreateBinarySemaphore                  ,0x010e5965) //  0
NHSTUB(CreateTask                             ,0x010e5089) //  0
NHSTUB(DebugAssert                            ,0x010e5cb9) //  0
NHSTUB(DeleteDirectory_Fut                    ,0xfc325b7d) //  0
NHSTUB(DeleteFile_Fut                         ,0xfc325b33) //  0
NHSTUB(DoAELock                               ,0xfc283949) //  0
NHSTUB(DoAFLock                               ,0xfc2835af) //  0
//NHSTUB(EnterToCompensationEVF               ,0x00000000) //  0            == 0x00000000
NHSTUB2(ExecuteEventProcedure                  ,0xfc326065) //  0
//NHSTUB(ExitFromCompensationEVF              ,0x00000000) //  0            == 0x00000000
NHSTUB(ExitTask                               ,0x010e526b) //  0
//NHSTUB(ExpCtrlTool_StartContiAE             ,0x00000000) //  0            == 0x00000000
//NHSTUB(ExpCtrlTool_StopContiAE              ,0x00000000) //  0            == 0x00000000
NHSTUB(Fclose_Fut                             ,0xfc325bdf) //  0
NHSTUB(Fgets_Fut                              ,0xfc325cbd) //  0
NHSTUB(Fopen_Fut                              ,0xfc325bb7) //  0
NHSTUB(Fread_Fut                              ,0xfc325c51) //  0
NHSTUB(FreeUncacheableMemory                  ,0xfc0ef0f9) //  0
NHSTUB(Fseek_Fut                              ,0xfc325cef) //  0
NHSTUB(Fwrite_Fut                             ,0xfc325c87) //  0
NHSTUB(GetBatteryTemperature                  ,0xfc1403f9) //  0
NHSTUB(GetCCDTemperature                      ,0xfc14039d) //  0
NHSTUB(GetCurrentAvValue                      ,0xfc14816d) //  0
NHSTUB(GetCurrentShutterSpeed                 ,0xfc16e733) //  0
NHSTUB(GetUsableMaxAv                         ,0xfc469dc1) //  0
NHSTUB(GetUsableMinAv                         ,0xfc469daf) //  0
NHSTUB(get_nd_value                           ,0xfc3cf713) //  0
NHSTUB(get_current_nd_value                   ,0xfc3cf6ef) //  0
NHSTUB(GetDrive_ClusterSize                   ,0xfc3576f7) //  0
NHSTUB(GetDrive_FreeClusters                  ,0xfc357bfb) //  0
NHSTUB(GetFocusLensSubjectDistance            ,0xfc31fb03) //  0
NHSTUB(GetKbdState                            ,0xfc075d95) //  0
NHSTUB(GetMemInfo                             ,0xfc455ec5) //  0
NHSTUB(GetOpticalTemperature                  ,0xfc140453) //  0
NHSTUB(GetParameterData                       ,0xfc0afe85) //  0
NHSTUB(GetPropertyCase                        ,0xfc34a777) //  0
NHSTUB(GetSystemTime                          ,0xfc3d88a9) //  0
NHSTUB(GetVRAMHPixelsSize                     ,0xfc13bef1) //  0
NHSTUB(GetVRAMVPixelsSize                     ,0xfc13bef9) //  0
NHSTUB(GetZoomLensCurrentPoint                ,0xfc1daec9) //  0
NHSTUB(GetZoomLensCurrentPosition             ,0xfc1dae5d) //  0
NHSTUB(GiveSemaphore                          ,0x010e5ad1) //  0
NHSTUB(IsStrobeChargeCompleted                ,0xfc1862a5) //  0
NHSTUB(LEDDrive                               ,0xfc1e23a1) //  0
NHSTUB(LocalTime                              ,0x010e61cd) //  0
NHSTUB(LockMainPower                          ,0xfc15941f) //  0
NHSTUB(MakeDirectory_Fut                      ,0xfc35836f) //  0
NHSTUB(MoveFocusLensToDistance                ,0xfc4f39a1) //  0
NHSTUB(MoveIrisWithAv                         ,0xfc3d1aed) //  0
NHSTUB(MoveZoomLensWithPoint                  ,0xfc3d2489) //  0
NHSTUB(Open                                   ,0xfc358001) //  0
NHSTUB(PB2Rec                                 ,0xfc0deac5) //  0
NHSTUB(PT_MoveDigitalZoomToWide               ,0xfc282fd3) //  0
NHSTUB(PT_MoveOpticalZoomAt                   ,0xfc1e32d5) //  0
NHSTUB(PT_PlaySound                           ,0xfc35980d) //  0
NHSTUB(PostLogicalEventForNotPowerType        ,0xfc3594c9) //  0
NHSTUB(PostLogicalEventToUI                   ,0xfc3594f5) //  0
NHSTUB(PutInNdFilter                          ,0xfc4f3c91) //  0
NHSTUB(PutOutNdFilter                         ,0xfc4f3cb7) //  0
NHSTUB(Read                                   ,0xfc134541) //  0
NHSTUB(ReadFastDir                            ,0xfc1184e9) //  0
NHSTUB(Rec2PB                                 ,0xfc0deb09) //  0
//NHSTUB(RefreshPhysicalScreen                ,0x00000000) //  0            == 0x00000000
//NHSTUB(Restart                              ,0x00000000) //  0            == 0x00000000
NHSTUB(ScreenLock                             ,0xfc361fc3) //  0
NHSTUB(ScreenUnlock                           ,0xfc362001) //  0
NHSTUB(SetAE_ShutterSpeed                     ,0xfc4f02c9) //  0
NHSTUB(SetAutoShutdownTime                    ,0xfc15946b) //  0
NHSTUB(SetCurrentCaptureModeType              ,0xfc331c07) //  0
NHSTUB(SetLogicalEventActive                  ,0xfc34b71f) //  0
//NHSTUB(SetParameterData                     ,0x00000000) //  0            == 0x00000000
NHSTUB(SetPropertyCase                        ,0xfc34a643) //  0
NHSTUB(SetScriptMode                          ,0xfc34b757) //  0
NHSTUB(SleepTask                              ,0x010e4ff1) //  0
NHSTUB(TakeSemaphore                          ,0x010e5a59) //  0
NHSTUB(TurnOffBackLight                       ,0xfc32a827) //  0
NHSTUB(TurnOnBackLight                        ,0xfc32a7e9) //  0
NHSTUB(TurnOnDisplay                          ,0xfc0cd291) //  0
NHSTUB(TurnOffDisplay                         ,0xfc0cd2a3) //  0
NHSTUB(UnlockAE                               ,0xfc283967) //  0
NHSTUB(UnlockAF                               ,0xfc2835df) //  0
NHSTUB(UnlockMainPower                        ,0xfc1593bb) //  0
//NHSTUB(UnsetZoomForMovie                    ,0x00000000) //  0            == 0x00000000
NHSTUB(VbattGet                               ,0xfc134e01) //  0
NHSTUB(Write                                  ,0xfc3580bd) //  0
//NHSTUB(WriteSDCard                          ,0x00000000) //  0            == 0x00000000
NHSTUB(_log                                   ,0x01109310) //  0
NHSTUB(_log10                                 ,0x01109830) //  0
NHSTUB(_pow                                   ,0x01109998) //  0
NHSTUB(_sqrt                                  ,0x0110ba18) //  0
NHSTUB(add_ptp_handler                        ,0xfc0f38b7) //  0
NHSTUB(close                                  ,0xfc13443b) //  0
NHSTUB(exmem_alloc                            ,0xfc079dbb) //  0
NHSTUB(exmem_free                             ,0xfc079dfb) //  0
NHSTUB(free                                   ,0xfc3623ef) //  0
NHSTUB(kbd_p1_f                               ,0xfc0783f7) //  0
NHSTUB(kbd_p1_f_cont                          ,0xfc0783ff) //  0
NHSTUB(kbd_p2_f                               ,0xfc077e8d) //  0
NHSTUB(kbd_read_keys                          ,0xfc0783c1) //  0
NHSTUB(kbd_read_keys_r2                       ,0xfc075c97) //  0
NHSTUB(lseek                                  ,0xfc3581e1) //  0
NHSTUB(malloc                                 ,0xfc3623b9) //  0
NHSTUB(memcmp                                 ,0xfc362571) //  0
NHSTUB(memcpy                                 ,0xfc0e7d41) //  0
NHSTUB(memset                                 ,0xfc1096fd) //  0
NHSTUB(mktime_ext                             ,0xfc45773d) //  0
NHSTUB(open                                   ,0xfc1343cb) //  0
NHSTUB(OpenFastDir                            ,0xfc118449) //  0
NHSTUB(closedir                               ,0xfc118411) //  0
NHSTUB(get_fstype                             ,0xfc357691) //  0
NHSTUB(qsort                                  ,0xfc248dd9) //  0
NHSTUB(rand                                   ,0xfc161a83) //  0
//NHSTUB(reboot_fw_update                     ,0x00000000) //  0            == 0x00000000
NHSTUB(set_control_event                      ,0xfc34b499) //  0
NHSTUB(srand                                  ,0xfc161a7d) //  0
NHSTUB(stat                                   ,0xfc358219) //  0
NHSTUB(strcat                                 ,0xfc362421) //  0
NHSTUB(strchr                                 ,0xfc161af5) //  0
NHSTUB(strcmp                                 ,0xfc3624ed) //  0
NHSTUB(strcpy                                 ,0xfc3624c9) //  0
NHSTUB(strftime                               ,0xfc1614f5) //  0
NHSTUB(strlen                                 ,0xfc36254b) //  0
NHSTUB(strncmp                                ,0xfc161acb) //  0
NHSTUB(strncpy                                ,0xfc362443) //  0
NHSTUB(strrchr                                ,0xfc0e7dd5) //  0
NHSTUB(strtol                                 ,0xfc161a6f) //  0
NHSTUB(strtolx                                ,0xfc16192d) //  0
   DEF(task_CaptSeq                           ,0xfc1501d9) //  0
   DEF(task_DvlpSeqTask                       ,0xfc1e6837) //  0
   DEF(task_ExpDrv                            ,0xfc2a5751) //  0
   DEF(task_FileWrite                         ,0xfc06b31d) //  0
   DEF(task_InitFileModules                   ,0xfc0c22d1) //  0
   DEF(task_MovieRecord                       ,0xfc14cd13) //  0
   DEF(task_PhySw                             ,0xfc0780c1) //  0
   DEF(task_TouchPanel                        ,0xfc0e2223) //  0
   DEF(task_TricInitTask                      ,0xfc50743d) //  0
   DEF(hook_CreateTask                        ,0x010e5088) //  0
NHSTUB(time                                   ,0x010e5e9b) //  0
NHSTUB(vsprintf                               ,0xfc0c38cf) //  0
NHSTUB(EngDrvRead                             ,0xfc360b25) //  0
NHSTUB(PTM_GetCurrentItem                     ,0xfc34b29f) //  0
NHSTUB(DisableISDriveError                    ,0xfc3d2a2d) //  0
NHSTUB(SetHPTimerAfterNow                     ,0xfc158d8d) //  0
NHSTUB(SetEventFlag                           ,0x010e549b) //  0
NHSTUB(transfer_src_overlay                   ,0xfc36168b) //  0
NHSTUB(bzero                                  ,0x01106b5c) //  0
NHSTUB(memset32                               ,0x01106b60) //  0
NHSTUB(PT_MFOn                                ,0xfc2849d9) //  0
NHSTUB(PT_MFOff                               ,0xfc284a0d) //  0
NHSTUB(GetAdChValue                           ,0xfc0e103b) //  0
NHSTUB(EnableHDMIPower                        ,0xfc0c3389) //  0
NHSTUB(DisableHDMIPower                       ,0xfc0c33bf) //  0
