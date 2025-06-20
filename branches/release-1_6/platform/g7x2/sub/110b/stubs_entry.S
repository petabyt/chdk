// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   Main firmware start: 0xe0020000
//   DRYOS R58 (DRYOS version 2.3, release #0058+p10) @ 0xe05d8220 ref @ 0xe05c54b4
//   Firmware Ver GM1.10B   // Found @ 0xe0503c3c, "GM1.10B" @ 0xe0503c49
//   VMSA detected, probably digic >= 7

// Values for makefile.inc
//   PLATFORMOSVER = 58
//   DIGIC = 70
//   MEMISOSTART = 0x2c460c
//   MEMBASEADDR = 0x8000
//   ARAM_HEAP_START = 0x006ce000#  Found @0xe0560ff4
//   ARAM_HEAP_SIZE = 0x00022000#  Found @0xe0560fcc

// Detected address ranges:
// ROM      0xe0000000 - 0xe2000000 (33554432 bytes)
// RAM data 0x00008000 - 0x0004c610 copied from 0xe0fd37b8 ( 280080 bytes)
// RAM code 0x01900000 - 0x0190139c copied from 0xe1017dc8 (   5020 bytes)
// TCM code 0xdffc4900 - 0xdffd0908 copied from 0xe1019164 (  49160 bytes)

// Zico Xtensa blobs:
// zico_0 0xbff20000 - 0xbff24ab8 copied from 0xe0e79d54 (  19128 bytes)
// zico_1 0xbff00000 - 0xbff08000 copied from 0xe0e7e814 (  32768 bytes)
// zico_2 0x80a00000 - 0x80ad4350 copied from 0xe0e8681c ( 869200 bytes)

// Found DryOS versions:
// 0xe0018d08 other "DRYOS version 2.3, release #0058+p10"
// 0xe05d8220 main  "DRYOS version 2.3, release #0058+p10"
// 0xe0c260f0 other "DRYOS version 2.3, release #0058+p10"
// 0xe0e870ac other "DRYOS version 2.3, release #0058+p7"
// 0xe123e380 other "DRYOS version 2.3, release #0058+p10"

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#define CAM_HAS_WIFI 1 // Firmware has wifi support (only define if camera has hardware)
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xe046e5a0
//#define CAM_HAS_ND_FILTER 1 // Camera has ND filter
// Camera has an iris (CAM_HAS_IRIS_DIAPHRAGM default)

// physw_event_table 0xe05df0e4 Found @0xe004e61c
// Values below go in 'platform_kbd.h':
//#define SD_READONLY_FLAG    0x00000020 // Found @0xe05df144, levent 0x30a
//#define SD_READONLY_IDX     1
//#define USB_MASK            0x00400000 // Found @0xe05df1fc, levent 0x302
//#define USB_IDX             2
//#define BATTCOVER_FLAG      0x00200000 // Found @0xe05df1f4, levent 0x305
//#define BATTCOVER_IDX       2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
// WARNING: Key name / function may vary! Values for unknown DryOS versions should not be trusted!
//KeyMap keymap[] = {
//    { 0, KEY_PLAYBACK        ,0x00008000 }, // Found @0xe05df0fc, levent 0x101
//    { 0, KEY_VIDEO           ,0x00010000 }, // Found @0xe05df104, levent 0x02
//    { 0, KEY_ZOOM_IN         ,0x00020000 }, // Found @0xe05df10c, levent 0x03
//    { 0, KEY_ZOOM_OUT        ,0x00040000 }, // Found @0xe05df114, levent 0x04
//    { 0, KEY_SHOOT_FULL      ,0x00180000 }, // Found @0xe05df11c, levent 0x01
//    { 0, KEY_SHOOT_HALF      ,0x00100000 }, // Found @0xe05df124, levent 0x00
//    { 0, KEY_SHOOT_FULL_ONLY ,0x00080000 }, // Found @0xe05df11c, levent 0x01
//    { 0, KEY_POWER           ,0x00200000 }, // Found @0xe05df12c, levent 0x100
//    { 0, KEY_WIFI            ,0x00400000 }, // Found @0xe05df134, levent 0x103
//    { 2, KEY_UP              ,0x00000200 }, // Found @0xe05df1a4, levent 0x06
//    { 2, KEY_DOWN            ,0x00000400 }, // Found @0xe05df1ac, levent 0x07
//    { 2, KEY_RIGHT           ,0x00000800 }, // Found @0xe05df1b4, levent 0x09
//    { 2, KEY_LEFT            ,0x00001000 }, // Found @0xe05df1bc, levent 0x08
//    { 2, KEY_SET             ,0x00002000 }, // Found @0xe05df1c4, levent 0x0a
//    { 0, 0, 0 }
//};

// canon_mode_list 0xe089d4c4 Found @0xe0036f2c
// Check modemap values from 'platform/CAMERA/shooting.c':
// 33297  0x8211 In firmware but not in current modemap
//  4174  0x104e In firmware but not in current modemap

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
// #define PROPCASE_SV_MARKET 258
// //      PROPCASE_SVFIX 259
// #define PROPCASE_TV 275
// Guessed propset: 13

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
DEF(ctypes                            ,0xe05d8380) // Found @0xe00386cc
DEF(physw_run                         ,0x00008370) // Found @0xe005b31a
DEF(physw_sleep_delay                 ,0x00008378) // (0x8370+0x8) Found @0xe005b31e
DEF(physw_status                      ,0x0004e440) // Found @0xe005b632
DEF(fileio_semaphore                  ,0x000111c4) // Found @0xe0036d16
DEF(levent_table                      ,0xe066c2a8) // Found @0xe00f3098
DEF(FlashParamsTable                  ,0xe089d884) // Found @0xe0036f40
DEF(playrec_mode                      ,0x0000c1d8) // (0xc1d4+0x4) Found @0xe02f082a
DEF(jpeg_count_str                    ,0x0014dd38) // Found @0xe01a81d8
DEF(zoom_busy                         ,0x00011664) // (0x11644+0x20) Found @0xe005f92a
DEF(focus_busy                        ,0x00011400) // (0x113f8+0x8) Found @0xe0372086
DEF(imager_active                     ,0x000086f4) // (0x86f0+0x4) Found @0xe045be1e
DEF(canon_menu_active                 ,0x0000ce08) // (0xce04+0x4) Found @0xe03756e0
DEF(file_counter_var                  ,0x00011084) // Found @0xe0402394
DEF(cameracon_state                   ,0x00008b54) // (0x8b44+0x10) Found @0xe035f8b8
DEF(_nrflag                           ,0x00026278) // (0x26274+0x4) Found @0xe005efac
DEF(av_override_semaphore             ,0x00036fb0) // Found @0xe0566ffc
DEF(active_bitmap_buffer              ,0x0000cdc0) // (0xcd74+0x4c) Found @0xe03789c2
DEF(displaytype                       ,0x000096f8) // (0x969c+0x5c) Found @0xe0439820
DEF(bitmap_buffer                     ,0x0000cdc4) // (0xcd74+0x50) Found @0xe03789c8
DEF(palette_control                   ,0x0001257c) // Found @0xe0344a6a
DEF(palette_buffer_ptr                ,0x00012594) // (0x1257c+0x18) Found @0xe0344a86
DEF(active_palette_buffer             ,0x0001258c) // (0x1257c+0x10) Found @0xe0344a6e
DEF(live_free_cluster_count           ,0x0015b1a0) // (0x15b168+0x38) Found @0xe00245e2
DEF_CONST(uiprop_count                      ,0x000000df) // Found @0xe0271bce
DEF(exmem_alloc_table                 ,0x00058288) // Found @0xe0055d96
DEF(exmem_types_table                 ,0xe0fd7a68) // Found @0xe0055d9a
DEF_CONST(exmem_type_count                  ,0x00000023) // Found @0xe0fd7a68
DEF(debug_logging_ptr                 ,0x000254f4) // Found @0xe01d039c
DEF(debug_logging_flag                ,0x000254fc) // Found @0xe01d0396
DEF(mzrm_sendmsg_ret_adr              ,0xe030671b)
DEF_CONST(fw_yuv_layer_buf                  ,0x4196a000) // Found @0xe01b8dda
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 2 int value(s), the first is the zoom focus length.
// there are 101 entries in the table - set NUM_FL to 101
DEF(focus_len_table                         ,0xe1f3169c) // Found @0xe1f3169c

//NHSTUB(GetImageFolder                       ,0x00000000) //  0        *** != 0xe0355015
//NHSTUB(RenameFile_Fut                       ,0x00000000) //  0        *** != 0xe0370e69
//NHSTUB(Restart                              ,0x00000000) //  0        *** != 0xe005b973
//NHSTUB(ScreenLock                           ,0xe03780e3) //  0        *** != 0x00000000
//NHSTUB(ScreenUnlock                         ,0xe03781f5) //  0        *** != 0x00000000
//NHSTUB(SetFileTimeStamp                     ,0x00000000) //  0        *** != 0xe0374179
//NHSTUB(WriteSDCard                          ,0x00000000) //  0        *** != 0xe051e963
//NHSTUB(reboot_fw_update                     ,0x00000000) //  0        *** != 0xe0526843

NHSTUB(AllocateUncacheableMemory              ,0xe046e571) //  0
NHSTUB(Close                                  ,0xe0373eb7) //  0
NHSTUB(CreateBinarySemaphore                  ,0xdffc9fd5) //  0
NHSTUB(CreateTask                             ,0xdffc93bb) //  0
NHSTUB(DebugAssert                            ,0xdffc96f5) //  0
NHSTUB(DeleteDirectory_Fut                    ,0xe0370f15) //  0
NHSTUB(DeleteFile_Fut                         ,0xe0370ecb) //  0
NHSTUB(DeleteSemaphore                        ,0xdffca05d) //  0
NHSTUB(DoAELock                               ,0xe0298e1d) //  0
NHSTUB(DoAFLock                               ,0xe02989e7) //  0
NHSTUB(EnterToCompensationEVF                 ,0xe0298d6d) //  0
NHSTUB2(ExecuteEventProcedure                  ,0xe03703e3) //  0
NHSTUB(ExitFromCompensationEVF                ,0xe0298dad) //  0
NHSTUB(ExitTask                               ,0xdffc95af) //  0
NHSTUB(ExpCtrlTool_StartContiAE               ,0xe02a1a91) //  0
NHSTUB(ExpCtrlTool_StopContiAE                ,0xe02a1bfd) //  0
NHSTUB(Fclose_Fut                             ,0xe0370f77) //  0
NHSTUB(Feof_Fut                               ,0xe03710c1) //  0
NHSTUB(Fflush_Fut                             ,0xe03710eb) //  0
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
NHSTUB(GetUsableMaxAv                         ,0xe056008d) //  0
NHSTUB(GetUsableMinAv                         ,0xe056007b) //  0
NHSTUB(get_nd_value                           ,0xe04fd7ab) //  0
NHSTUB(get_current_nd_value                   ,0xe04fd785) //  0
NHSTUB(get_current_deltasv                    ,0xe043af3d) //  0
NHSTUB(GetCurrentDriveBaseSvValue             ,0xe036a599) //  0
NHSTUB(GetDrive_ClusterSize                   ,0xe0374c35) //  0
NHSTUB(GetDrive_TotalClusters                 ,0xe0375125) //  0
NHSTUB(GetFocusLensSubjectDistance            ,0xe0372bf5) //  0
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xe0372eeb) //  0
NHSTUB(GetKbdState                            ,0xe004e73b) //  0
NHSTUB(GetMemInfo                             ,0xe0589bad) //  0
NHSTUB(GetOpticalTemperature                  ,0xe0401223) //  0
NHSTUB(GetParameterData                       ,0xe02725cf) //  0
//NHSTUB(GetPropertyCase                      ,0xe036af69) //  0            Overridden
NHSTUB(GetSystemTime                          ,0xe0569c53) //  0
NHSTUB(GetVRAMHPixelsSize                     ,0xe040bdf5) //  0
NHSTUB(GetVRAMVPixelsSize                     ,0xe040bdfd) //  0
NHSTUB(GetZoomLensCurrentPoint                ,0xe005fb75) //  0
NHSTUB(GetZoomLensCurrentPosition             ,0xe051b9d5) //  0
NHSTUB(GiveSemaphore                          ,0xdffca149) //  0
NHSTUB(IsStrobeChargeCompleted                ,0xe053b41f) //  0
NHSTUB(LEDDrive                               ,0xe0551f91) //  0
NHSTUB(LocalTime                              ,0xdffca8bb) //  0
NHSTUB(LockMainPower                          ,0xe04d05f7) //  0
NHSTUB(MakeDirectory_Fut                      ,0xe037422f) //  0
NHSTUB(MakeSDCardBootable                     ,0xe03754ef) //  0
NHSTUB(MoveFocusLensToDistance                ,0xe05921e3) //  0
NHSTUB(MoveIrisWithAv                         ,0xe0566fe9) //  0
NHSTUB(MoveZoomLensWithPoint                  ,0xe0567d75) //  0
NHSTUB(Open                                   ,0xe0373e7b) //  0
NHSTUB(PB2Rec                                 ,0xe035dfcb) //  0
NHSTUB(PT_MoveDigitalZoomToWide               ,0xe02982c3) //  0
NHSTUB(PT_MoveOpticalZoomAt                   ,0xe0552e35) //  0
NHSTUB(MoveOpticalZoomAt                      ,0xe02980f9) //  0
NHSTUB(PT_PlaySound                           ,0xe037e475) //  0
NHSTUB(PostLogicalEventForNotPowerType        ,0xe037a839) //  0
NHSTUB(PostLogicalEventToUI                   ,0xe037a86d) //  0
NHSTUB(PutInNdFilter                          ,0xe0592499) //  0
NHSTUB(PutOutNdFilter                         ,0xe05924bf) //  0
NHSTUB(Read                                   ,0xe0451397) //  0
NHSTUB(ReadFastDir                            ,0xe03fa8ff) //  0
NHSTUB(Rec2PB                                 ,0xe035e00f) //  0
NHSTUB(SetAE_ShutterSpeed                     ,0xe0583d25) //  0
NHSTUB(SetAutoShutdownTime                    ,0xe04d0647) //  0
NHSTUB(SetCurrentCaptureModeType              ,0xe037ca81) //  0
NHSTUB(SetDate                                ,0xe0585275) //  0
//NHSTUB(SetFileAttributes                    ,0x00000000) //  0            == 0x00000000
NHSTUB(SetLogicalEventActive                  ,0xe0371cdf) //  0
NHSTUB(SetParameterData                       ,0xe02724e3) //  0
NHSTUB(SetPropertyCase                        ,0xe036ae25) //  0
NHSTUB(SetScriptMode                          ,0xe0371d17) //  0
NHSTUB(SleepTask                              ,0xdffc9293) //  0
NHSTUB(TakeSemaphore                          ,0xdffca0cf) //  0
//NHSTUB(TurnOffBackLight                     ,0x00000000) //  0            == 0x00000000
//NHSTUB(TurnOnBackLight                      ,0x00000000) //  0            == 0x00000000
NHSTUB(TurnOnDisplay                          ,0xe01082cb) //  0
NHSTUB(TurnOffDisplay                         ,0xe043985d) //  0
NHSTUB(UnlockAE                               ,0xe0298e3b) //  0
NHSTUB(UnlockAF                               ,0xe0298a17) //  0
NHSTUB(UnlockMainPower                        ,0xe04d0593) //  0
//NHSTUB(UnsetZoomForMovie                    ,0x00000000) //  0            == 0x00000000
NHSTUB(VbattGet                               ,0xe04912e5) //  0
NHSTUB(Write                                  ,0xe0373e3d) //  0
NHSTUB(_log                                   ,0xdffcd8c5) //  0
NHSTUB(_log10                                 ,0xdffcdc39) //  0
NHSTUB(_pow                                   ,0xdffcdd31) //  0
NHSTUB(_sqrt                                  ,0xdffcf241) //  0
NHSTUB(add_ptp_handler                        ,0xe02f31db) //  0
NHSTUB(apex2us                                ,0xe0067ab3) //  0
NHSTUB(close                                  ,0xe0451293) //  0
NHSTUB(err_init_task                          ,0xe0020419) //  0
NHSTUB(exmem_alloc                            ,0xe005629b) //  0
NHSTUB(exmem_ualloc                           ,0xe005604f) //  0
NHSTUB(exmem_ufree                            ,0xe005625f) //  0
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
NHSTUB(memset                                 ,0xe04ac7dd) //  0
NHSTUB(mktime_ext                             ,0xe01d7c5d) //  0
NHSTUB(open                                   ,0xe0451221) //  0
NHSTUB(OpenFastDir                            ,0xe03fa861) //  0
NHSTUB(closedir                               ,0xe03fa829) //  0
NHSTUB(get_fstype                             ,0xe0374bcf) //  0
NHSTUB(qsort                                  ,0xe041ca3f) //  0
NHSTUB(rand                                   ,0xe052b613) //  0
NHSTUB(set_control_event                      ,0xe0371a61) //  0
NHSTUB(srand                                  ,0xe052b60d) //  0
NHSTUB(stat                                   ,0xe03740bd) //  0
NHSTUB(strcat                                 ,0xe0484f7b) //  0
NHSTUB(strchr                                 ,0xe045197f) //  0
NHSTUB(strcmp                                 ,0xe037a0c1) //  0
NHSTUB(strcpy                                 ,0xe037e6a5) //  0
NHSTUB(strftime                               ,0xe0523985) //  0
NHSTUB(strlen                                 ,0xe037e6c7) //  0
NHSTUB(strncmp                                ,0xe0422079) //  0
NHSTUB(strncpy                                ,0xe0484f57) //  0
NHSTUB(strrchr                                ,0xe04b23d9) //  0
NHSTUB(strtol                                 ,0xe04e84cb) //  0
NHSTUB(strtolx                                ,0xe04e8371) //  0
   DEF(task_CaptSeq                           ,0xe0032f57) //  0
   DEF(task_DvlpSeqTask                       ,0xe004b693) //  0
   DEF(task_ExpDrv                            ,0xe02d0ad9) //  0
   DEF(task_FileWrite                         ,0xe03af92b) //  0
   DEF(task_InitFileModules                   ,0xe04200b1) //  0
   DEF(task_MovieRecord                       ,0xe038f12f) //  0
   DEF(task_PhySw                             ,0xe005b319) //  0
   DEF(task_TouchPanel                        ,0xe0463a0b) //  0
   DEF(task_TricInitTask                      ,0xe025d527) //  0
   DEF(hook_CreateTask                        ,0xdffc93ba) //  0
NHSTUB(time                                   ,0xdffca509) //  0
NHSTUB(vsprintf                               ,0xe0463383) //  0
//NHSTUB(EngDrvRead                           ,0x00000000) //  0            == 0x00000000
NHSTUB(PTM_GetCurrentItem                     ,0xe0376d2b) //  0
NHSTUB(DisableISDriveError                    ,0xe056898f) //  0
NHSTUB(CancelHPTimer                          ,0xe03f4b5b) //  0
NHSTUB(SetHPTimerAfterNow                     ,0xe03f4ac1) //  0
NHSTUB(SetEventFlag                           ,0xdffc9939) //  0
NHSTUB(transfer_src_overlay                   ,0xe0377dbb) //  0
NHSTUB(bzero                                  ,0xdffcc545) //  0
NHSTUB(memset32                               ,0xdffcc549) //  0
NHSTUB(get_dial_hw_position                   ,0xe04d1bd9) //  0
NHSTUB(PT_MFOn                                ,0xe0299ea5) //  0
NHSTUB(PT_MFOff                               ,0xe0299ed9) //  0
NHSTUB(GetAdChValue                           ,0xe04d970b) //  0
NHSTUB(EnableHDMIPower                        ,0xe005bd31) //  0
NHSTUB(DisableHDMIPower                       ,0xe005bd67) //  0
NHSTUB(SetVideoOutType                        ,0xe058429f) //  0
NHSTUB(GetVideoOutType                        ,0xe058422b) //  0
NHSTUB(IsWirelessConnect                      ,0xe036787b) //  0
