// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   Main firmware start: 0xfc020000
//   DRYOS R59 (DRYOS version 2.3, release #0059+p4) @ 0xfc5e2500 ref @ 0xfc048e34
//   Firmware Ver GM1.00C   // Found @ 0xfc3b38a0, "GM1.00C" @ 0xfc3b38ad

// Values for makefile.inc
//   PLATFORMOSVER = 59
//   DIGIC = 60
//   MEMISOSTART = 0x3976c0
//   MEMBASEADDR = 0x8000
//   ARAM_HEAP_START = 0x006ce000#  Found @0xfc3edc70
//   ARAM_HEAP_SIZE = 0x00022000#  Found @0xfc3edc44

// Detected address ranges:
// ROM      0xfc000000 - 0xfe000000 (33554432 bytes)
// RAM code 0x010e1000 - 0x010fc278 copied from 0xfcdcd810 ( 111224 bytes)
// TCM code 0xbfe10800 - 0xbfe1633d copied from 0xfcde8a88 (  23357 bytes)
// RAM data 0x00008000 - 0x000347d4 copied from 0xfcda103c ( 182228 bytes)
// EVEC     0x00000000 - 0x00000038 copied from 0xfc05c9f0 (     56 bytes)

// Zico Xtensa blobs:
// zico_0 0xbff20000 - 0xbff27a50 copied from 0xfcb951dc (  31312 bytes)
// zico_1 0xbff00000 - 0xbff04ad0 copied from 0xfcb9cc34 (  19152 bytes)
// zico_2 0x80a00000 - 0x80b16788 copied from 0xfcba170c (1140616 bytes)

// Omar ARM blobs:
// omar_0 0xdff00000 - 0xdff00f48 copied from 0xfc5e2570 (   3912 bytes)
// omar_1 0x40700000 - 0x407506f4 copied from 0xfc5e34b8 ( 329460 bytes)

// Found DryOS versions:
// 0xfc5e2500 main  "DRYOS version 2.3, release #0059+p4"
// 0xfc5f92f4 other "DRYOS version 2.3, release #0059+p4"
// 0xfcba28dc other "DRYOS version 2.3, release #0058+p8"
// 0xfd29b220 other "DRYOS version 2.3, release #0059+p3"

// CreateTask is not in RAM code
// use hook_CreateTask_low instead

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#define CAM_DRYOS_2_3_R59 1 // Defined for cameras with DryOS version R59 or higher
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xfc1d4d54
//#undef CAM_HAS_ND_FILTER // Camera does not have an ND filter
// Camera has an iris (CAM_HAS_IRIS_DIAPHRAGM default)

// physw_event_table 0xfc637df0 Found @0xfc505f7a
// Values below go in 'platform_kbd.h':
//#define SD_READONLY_FLAG    0x20000000 // Found @0xfc637eb8, levent 0x30a
//#define SD_READONLY_IDX     1
//#define USB_MASK            0x00800000 // Found @0xfc637f00, levent 0x302
//#define USB_IDX             2
//#define BATTCOVER_FLAG      0x00400000 // Found @0xfc637ef8, levent 0x305
//#define BATTCOVER_IDX       2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
// WARNING: Key name / function may vary! Values for unknown DryOS versions should not be trusted!
//KeyMap keymap[] = {
//    { 0, KEY_MENU            ,0x00000020 }, // Found @0xfc637e18, levent 0x15
//    { 0, KEY_UP              ,0x00000040 }, // Found @0xfc637e20, levent 0x06
//    { 0, KEY_DOWN            ,0x00000080 }, // Found @0xfc637e28, levent 0x07
//    { 0, KEY_RIGHT           ,0x00000100 }, // Found @0xfc637e30, levent 0x09
//    { 0, KEY_SET             ,0x00000200 }, // Found @0xfc637e38, levent 0x0a
//    { 0, KEY_LEFT            ,0x00000400 }, // Found @0xfc637e40, levent 0x08
//    { 0, KEY_PLAYBACK        ,0x00000800 }, // Found @0xfc637e48, levent 0x101
//    { 0, KEY_ERASE           ,0x00001000 }, // Found @0xfc637e50, levent 0x0b
//    { 0, KEY_VIDEO           ,0x00002000 }, // Found @0xfc637e58, levent 0x02
//    { 0, KEY_WIFI            ,0x00010000 }, // Found @0xfc637e60, levent 0x103
//    { 0, KEY_POWER           ,0x00020000 }, // Found @0xfc637e68, levent 0x100
//    { 1, KEY_SHOOT_FULL      ,0x00000c00 }, // Found @0xfc637ea8, levent 0x01
//    { 1, KEY_SHOOT_FULL_ONLY ,0x00000800 }, // Found @0xfc637ea8, levent 0x01
//    { 1, KEY_SHOOT_HALF      ,0x00000400 }, // Found @0xfc637ea0, levent 0x00
//    { 0, 0, 0 }
//};

// canon_mode_list 0xfc98b1d0 Found @0xfc071134
// Check modemap values from 'platform/CAMERA/shooting.c':
// 33297  0x8211 In firmware but not in current modemap

// Known propcases
// //      PROPCASE_AFSTEP 13
// #define PROPCASE_FOCUS_STATE 18
// #define PROPCASE_AV 23
// #define PROPCASE_BV 40
// //      PROPCASE_DELTA_DIGITALGAIN 85
// #define PROPCASE_DELTA_SV 87
// //      PROPCASE_DELTA_ND 88
// //      PROPCASE_FELOCK 123
// #define PROPCASE_FLASH_ADJUST_MODE 130
// #define PROPCASE_FLASH_FIRE 131
// //      PROPCASE_HSCAPTURE 147
// #define PROPCASE_EV_CORRECTION_2 220
// #define PROPCASE_ORIENTATION_SENSOR 232
// #define PROPCASE_SV_MARKET 260
// //      PROPCASE_SVFIX 261
// #define PROPCASE_TV 277
// Guessed propset: 12

// EXMEM types:
// EXMEM_RAMDISK        0
// EXMEM_COM            1
// EXMEM_FORMATTER      2
// EXMEM_FIRMUP         3
// EXMEM_FIRMUP_INFLATE 4
// EXMEM_FIRMUP_PICTURESTYLE 5
// EXMEM_DVLPWORK       6
// EXMEM_GPS            7
// EXMEM_FACEAUTH       8
// EXMEM_OHYEARLOG      9
// EXMEM_WIFI           10
// EXMEM_MULTI_PLY      11
// EXMEM_FEP            12
// EXMEM_LENS_FIRMUP    13
// EXMEM_LENS_COMPENSATION 14
// EXMEM_FILESTORE      15
// EXMEM_MOVIE_REC      16
// EXMEM_MOVIE_PLY      17
// EXMEM_WIDE           18
// EXMEM_AUTO_GIS_MODE  19
// EXMEM_NP_GIS_MODE    20
// EXMEM_TRIPODHDR_MODE 21
// EXMEM_HSHQ_MODE      22
// EXMEM_CRAW_REC       23
// EXMEM_CREATIVE_SHOT  24

// Values below can be overridden in 'stubs_min.S':
DEF(ctypes                            ,0xfc699f34) // Found @0xfc03746c
DEF(physw_run                         ,0x00008190) // Found @0xfc5897da
DEF(physw_sleep_delay                 ,0x00008198) // (0x8190+0x8) Found @0xfc5897de
DEF(physw_status                      ,0x0003578c) // Found @0xfc589b26
DEF(fileio_semaphore                  ,0x000139b0) // Found @0xfc069a2a
DEF(levent_table                      ,0xfc717e28) // Found @0xfc089ce0
DEF(FlashParamsTable                  ,0xfc98b5b0) // Found @0xfc071148
DEF(playrec_mode                      ,0x0000c144) // (0xc140+0x4) Found @0xfc309b52
DEF(jpeg_count_str                    ,0x00135428) // Found @0xfc07fe00
DEF(zoom_busy                         ,0x0000bcf0) // (0xbcd0+0x20) Found @0xfc0edfea
DEF(focus_busy                        ,0x00013be4) // (0x13bdc+0x8) Found @0xfc3335da
DEF(imager_active                     ,0x0000858c) // (0x8588+0x4) Found @0xfc3aa324
DEF(canon_menu_active                 ,0x0000ce74) // (0xce6c+0x8) Found @0xfc31fdfc
DEF(file_counter_var                  ,0x000138e0) // Found @0xfc17d074
DEF(_nrflag                           ,0x0001c508) // (0x1c504+0x4) Found @0xfc1ed66e
DEF(av_override_semaphore             ,0x00020cdc) // Found @0xfc43fa30
DEF(active_bitmap_buffer              ,0x0000ce28) // (0xcddc+0x4c) Found @0xfc348e00
DEF(displaytype                       ,0x0000964c) // (0x95f0+0x5c) Found @0xfc0e36c4
DEF(bitmap_buffer                     ,0x0000ce2c) // (0xcddc+0x50) Found @0xfc348e06
DEF_CONST(uiprop_count                      ,0x000000ea) // Found @0xfc06a720
DEF(exmem_alloc_table                 ,0x0003ec6c) // Found @0xfc3b27de
DEF(exmem_types_table                 ,0xfcda5260) // Found @0xfc3b27e2
DEF_CONST(exmem_type_count                  ,0x00000019) // Found @0xfcda5260
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 2 int value(s), the first is the zoom focus length.
// there are 127 entries in the table - set NUM_FL to 127
//DEF(focus_len_table                         ,0xfdf3167c) // Found @0xfdf3167c,          stubs_min = 0xfdf3167c (0xfdf3167c)

//NHSTUB(Feof_Fut                             ,0x00000000) //  0        *** != 0xfc34c961
//NHSTUB(Fflush_Fut                           ,0x00000000) //  0        *** != 0xfc34c989
//NHSTUB(GetDrive_TotalClusters               ,0x00000000) //  0        *** != 0xfc35260f
//NHSTUB(GetFocusLensSubjectDistanceFromLens  ,0x00000000) //  0        *** != 0xfc3344bb
//NHSTUB(GetImageFolder                       ,0x00000000) //  0        *** != 0xfc32f3e7
//NHSTUB(MakeSDCardBootable                   ,0x00000000) //  0        *** != 0xfc3529d5
//NHSTUB(RenameFile_Fut                       ,0x00000000) //  0        *** != 0xfc34c711
//NHSTUB(SetFileAttributes                    ,0x00000000) //  0        *** != 0xfc3517fb
//NHSTUB(SetFileTimeStamp                     ,0x00000000) //  0        *** != 0xfc3517b3
//NHSTUB(SetParameterData                     ,0xfc06af67) //  0        *** != 0x00000000
//NHSTUB(_pow                                 ,0x00000000) //  0        *** != 0x010f8718
//NHSTUB(apex2us                              ,0x00000000) //  0        *** != 0xfc219833
//NHSTUB(exmem_alloc                          ,0x00000000) //  0        *** != 0xfc3b2ddd
//NHSTUB(exmem_ualloc                         ,0x00000000) //  0        *** != 0xfc3b2d51
//NHSTUB(exmem_ufree                          ,0x00000000) //  0        *** != 0xfc3b2dad
//NHSTUB(CancelHPTimer                        ,0x00000000) //  0        *** != 0xfc3b3591

NHSTUB(CreateTask_low                         ,0xbfe10b85) //  0
NHSTUB(AllocateUncacheableMemory              ,0xfc1d4d25) //  0
NHSTUB(Close                                  ,0xfc3514f3) //  0
NHSTUB(CreateBinarySemaphore                  ,0xfc362e91) //  0
NHSTUB(CreateTask                             ,0xfc35c1ab) //  0
NHSTUB(DebugAssert                            ,0xfc3a893d) //  0
NHSTUB(DeleteDirectory_Fut                    ,0xfc34c7bd) //  0
NHSTUB(DeleteFile_Fut                         ,0xfc34c773) //  0
NHSTUB(DoAELock                               ,0xfc27fca3) //  0
NHSTUB(DoAFLock                               ,0xfc27f8b5) //  0
//NHSTUB(EnterToCompensationEVF               ,0x00000000) //  0            == 0x00000000
NHSTUB2(ExecuteEventProcedure                  ,0xfc369261) //  0
//NHSTUB(ExitFromCompensationEVF              ,0x00000000) //  0            == 0x00000000
NHSTUB(ExitTask                               ,0xfc35c399) //  0
//NHSTUB(ExpCtrlTool_StartContiAE             ,0x00000000) //  0            == 0x00000000
//NHSTUB(ExpCtrlTool_StopContiAE              ,0x00000000) //  0            == 0x00000000
NHSTUB(Fclose_Fut                             ,0xfc34c81f) //  0
NHSTUB(Fgets_Fut                              ,0xfc34c8fd) //  0
NHSTUB(Fopen_Fut                              ,0xfc34c7f7) //  0
NHSTUB(Fread_Fut                              ,0xfc34c891) //  0
NHSTUB(FreeUncacheableMemory                  ,0xfc1d4d51) //  0
NHSTUB(Fseek_Fut                              ,0xfc34c92f) //  0
NHSTUB(Fwrite_Fut                             ,0xfc34c8c7) //  0
NHSTUB(GetBatteryTemperature                  ,0xfc3afb1b) //  0
NHSTUB(GetCCDTemperature                      ,0xfc3afac5) //  0
NHSTUB(GetCurrentAvValue                      ,0xfc0edb41) //  0
NHSTUB(GetCurrentShutterSpeed                 ,0xfc3c6b51) //  0
NHSTUB(GetUsableMaxAv                         ,0xfc3dfcf1) //  0
NHSTUB(GetUsableMinAv                         ,0xfc3dfcdf) //  0
NHSTUB(GetDrive_ClusterSize                   ,0xfc352135) //  0
NHSTUB(GetDrive_FreeClusters                  ,0xfc352633) //  0
NHSTUB(GetFocusLensSubjectDistance            ,0xfc3341c1) //  0
NHSTUB(GetKbdState                            ,0xfc5060cd) //  0
NHSTUB(GetMemInfo                             ,0xfc504c9d) //  0
NHSTUB(GetOpticalTemperature                  ,0xfc3afb6f) //  0
NHSTUB(GetParameterData                       ,0xfc06afdf) //  0
NHSTUB(GetPropertyCase                        ,0xfc35b665) //  0
NHSTUB(GetSystemTime                          ,0xfc442a25) //  0
NHSTUB(GetVRAMHPixelsSize                     ,0xfc0e0cd5) //  0
NHSTUB(GetVRAMVPixelsSize                     ,0xfc0e0cdd) //  0
NHSTUB(GetZoomLensCurrentPoint                ,0xfc0ee23d) //  0
NHSTUB(GetZoomLensCurrentPosition             ,0xfc0ee1d1) //  0
NHSTUB(GiveSemaphore                          ,0xfc362ffd) //  0
NHSTUB(IsStrobeChargeCompleted                ,0xfc11ebbd) //  0
NHSTUB(LEDDrive                               ,0xfc3e9dc9) //  0
NHSTUB(LocalTime                              ,0xfc3b3ad5) //  0
NHSTUB(LockMainPower                          ,0xfc0fdddf) //  0
NHSTUB(MakeDirectory_Fut                      ,0xfc351867) //  0
NHSTUB(MoveFocusLensToDistance                ,0xfc52e705) //  0
NHSTUB(MoveIrisWithAv                         ,0xfc43fa1d) //  0
NHSTUB(MoveZoomLensWithPoint                  ,0xfc43fd63) //  0
NHSTUB(Open                                   ,0xfc3514b5) //  0
NHSTUB(PB2Rec                                 ,0xfc31c543) //  0
NHSTUB(PT_MoveDigitalZoomToWide               ,0xfc27f087) //  0
NHSTUB(PT_MoveOpticalZoomAt                   ,0xfc3ead69) //  0
NHSTUB(MoveOpticalZoomAt                      ,0xfc27ef87) //  0
NHSTUB(PT_PlaySound                           ,0xfc344929) //  0
NHSTUB(PostLogicalEventForNotPowerType        ,0xfc35bef1) //  0
NHSTUB(PostLogicalEventToUI                   ,0xfc35bf25) //  0
NHSTUB(PutInNdFilter                          ,0xfc52e9a5) //  0
NHSTUB(PutOutNdFilter                         ,0xfc52e9cb) //  0
NHSTUB(Read                                   ,0xfc3a9269) //  0
NHSTUB(ReadFastDir                            ,0xfc436cd1) //  0
NHSTUB(Rec2PB                                 ,0xfc31c611) //  0
//NHSTUB(Restart                              ,0x00000000) //  0            == 0x00000000
NHSTUB(ScreenLock                             ,0xfc3484c1) //  0
NHSTUB(ScreenUnlock                           ,0xfc3485cb) //  0
NHSTUB(SetAE_ShutterSpeed                     ,0xfc52be69) //  0
NHSTUB(SetAutoShutdownTime                    ,0xfc0fde2f) //  0
NHSTUB(SetCurrentCaptureModeType              ,0xfc355e67) //  0
NHSTUB(SetDate                                ,0xfc52d38f) //  0
NHSTUB(SetLogicalEventActive                  ,0xfc3411fd) //  0
NHSTUB(SetPropertyCase                        ,0xfc35b511) //  0
NHSTUB(SetScriptMode                          ,0xfc341235) //  0
NHSTUB(SleepTask                              ,0xfc3690b9) //  0
NHSTUB(TakeSemaphore                          ,0xfc362f85) //  0
//NHSTUB(TurnOffBackLight                     ,0x00000000) //  0            == 0x00000000
//NHSTUB(TurnOnBackLight                      ,0x00000000) //  0            == 0x00000000
NHSTUB(TurnOnDisplay                          ,0xfc166ec7) //  0
NHSTUB(TurnOffDisplay                         ,0xfc0e3701) //  0
NHSTUB(UnlockAE                               ,0xfc27fcc1) //  0
NHSTUB(UnlockAF                               ,0xfc27f8dd) //  0
NHSTUB(UnlockMainPower                        ,0xfc0fdd75) //  0
//NHSTUB(UnsetZoomForMovie                    ,0x00000000) //  0            == 0x00000000
NHSTUB(VbattGet                               ,0xfc0dbcbb) //  0
NHSTUB(Write                                  ,0xfc35198f) //  0
//NHSTUB(WriteSDCard                          ,0x00000000) //  0            == 0x00000000
NHSTUB(_log                                   ,0x010f8090) //  0
NHSTUB(_log10                                 ,0x010f85b0) //  0
NHSTUB(_sqrt                                  ,0x010fa798) //  0
NHSTUB(add_ptp_handler                        ,0xfc322223) //  0
NHSTUB(close                                  ,0xfc3a9163) //  0
NHSTUB(free                                   ,0xfc369e93) //  0
NHSTUB(kbd_p1_f                               ,0xfc589b1f) //  0
NHSTUB(kbd_p1_f_cont                          ,0xfc589b27) //  0
NHSTUB(kbd_p2_f                               ,0xfc589535) //  0
NHSTUB(kbd_read_keys                          ,0xfc589ae9) //  0
NHSTUB(kbd_read_keys_r2                       ,0xfc505f77) //  0
NHSTUB(lseek                                  ,0xfc3516d1) //  0
NHSTUB(malloc                                 ,0xfc369e5d) //  0
NHSTUB(memcmp                                 ,0xfc36a039) //  0
NHSTUB(memcpy                                 ,0xfc3b47f9) //  0
NHSTUB(memset                                 ,0xfc5117b9) //  0
NHSTUB(mktime_ext                             ,0xfc506e95) //  0
NHSTUB(open                                   ,0xfc3a90f3) //  0
NHSTUB(OpenFastDir                            ,0xfc436c31) //  0
NHSTUB(closedir                               ,0xfc436bf9) //  0
NHSTUB(get_fstype                             ,0xfc3520cf) //  0
NHSTUB(qsort                                  ,0xfc3ee291) //  0
NHSTUB(rand                                   ,0xfc3b47db) //  0
//NHSTUB(reboot_fw_update                     ,0x00000000) //  0            == 0x00000000
NHSTUB(set_control_event                      ,0xfc340ef1) //  0
NHSTUB(srand                                  ,0xfc3b47d5) //  0
NHSTUB(stat                                   ,0xfc351709) //  0
NHSTUB(strcat                                 ,0xfc369dc1) //  0
NHSTUB(strchr                                 ,0xfc3b48e1) //  0
NHSTUB(strcmp                                 ,0xfc369ee9) //  0
NHSTUB(strcpy                                 ,0xfc369ec5) //  0
NHSTUB(strftime                               ,0xfc3b4351) //  0
NHSTUB(strlen                                 ,0xfc369fd1) //  0
NHSTUB(strncmp                                ,0xfc3b48b7) //  0
NHSTUB(strncpy                                ,0xfc369f6b) //  0
NHSTUB(strrchr                                ,0xfc1021e5) //  0
NHSTUB(strtol                                 ,0xfc50706b) //  0
NHSTUB(strtolx                                ,0xfc506f29) //  0
   DEF(task_CaptSeq                           ,0xfc0f2b07) //  0
   DEF(task_DvlpSeqTask                       ,0xfc18f013) //  0
   DEF(task_ExpDrv                            ,0xfc2af0a3) //  0
   DEF(task_InitFileModules                   ,0xfc0972a5) //  0
   DEF(task_MovieRecord                       ,0xfc18a5e3) //  0
   DEF(task_PhySw                             ,0xfc5897d9) //  0
   DEF(task_TricInitTask                      ,0xfc521901) //  0
   DEF(hook_CreateTask_low                    ,0xbfe10b84) //  0
NHSTUB(time                                   ,0xfc101e5b) //  0
NHSTUB(vsprintf                               ,0xfc1021bf) //  0
NHSTUB(EngDrvRead                             ,0xfc3630d5) //  0
NHSTUB(PTM_GetCurrentItem                     ,0xfc35ab07) //  0
NHSTUB(DisableISDriveError                    ,0xfc4409f1) //  0
NHSTUB(SetHPTimerAfterNow                     ,0xfc3b34f9) //  0
NHSTUB(SetEventFlag                           ,0xfc369b95) //  0
NHSTUB(transfer_src_overlay                   ,0xfc348195) //  0
NHSTUB(bzero                                  ,0x010f54d8) //  0
NHSTUB(memset32                               ,0x010f54dc) //  0
NHSTUB(get_dial_hw_position                   ,0xfc3e4391) //  0
NHSTUB(PT_MFOn                                ,0xfc280b13) //  0
NHSTUB(PT_MFOff                               ,0xfc280b43) //  0
NHSTUB(GetAdChValue                           ,0xfc3acb6b) //  0
NHSTUB(EnableHDMIPower                        ,0xfc0e4be7) //  0
NHSTUB(DisableHDMIPower                       ,0xfc0e4c1d) //  0
NHSTUB(SetVideoOutType                        ,0xfc52c3d9) //  0
NHSTUB(GetVideoOutType                        ,0xfc52c365) //  0
