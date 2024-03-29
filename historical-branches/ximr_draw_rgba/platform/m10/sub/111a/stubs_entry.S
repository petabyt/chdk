// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   Main firmware start: 0xfc020000
//   DRYOS R57 (DRYOS version 2.3, release #0057) @ 0xfc6080e8 ref @ 0xfc04686c
//   Firmware Ver GM1.11A   // Found @ 0xfc1fb044, "GM1.11A" @ 0xfc1fb051

// Values for makefile.inc
//   PLATFORMOSVER = 57
//   DIGIC = 60
//   MEMISOSTART = 0x3d6ffc
//   MEMBASEADDR = 0x8000
//   ARAM_HEAP_START = 0x0074e000#  Found @0xfc18eca4
//   ARAM_HEAP_SIZE = 0x00022000#  Found @0xfc18ec7e

// Detected address ranges:
// ROM      0xfc000000 - 0xfe000000 (33554432 bytes)
// RAM code 0x010e1000 - 0x01107d60 copied from 0xfceb1938 ( 159072 bytes)
// TCM code 0xbfe10800 - 0xbfe1741d copied from 0xfced8698 (  27677 bytes)
// RAM data 0x00008000 - 0x00055334 copied from 0xfce64604 ( 316212 bytes)
// EVEC     0x00000000 - 0x00000038 copied from 0xfc06c5b4 (     56 bytes)

// Zico Xtensa blobs:
// zico_0 0xbff20000 - 0xbff27938 copied from 0xfca32760 (  31032 bytes)
// zico_1 0xbff00000 - 0xbff04b30 copied from 0xfca3a0a0 (  19248 bytes)
// zico_2 0x80a00000 - 0x80b15060 copied from 0xfca3ebd8 (1134688 bytes)

// Omar ARM blobs:
// omar_0 0xdff00000 - 0xdff00e88 copied from 0xfc608310 (   3720 bytes)
// omar_1 0x40780000 - 0x407986b0 copied from 0xfc609198 ( 100016 bytes)

// Found DryOS versions:
// 0xfc6080e8 main  "DRYOS version 2.3, release #0057"
// 0xfc61f574 other "DRYOS version 2.3, release #0057"
// 0xfca3fd88 other "DRYOS version 2.3, release #0057"

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#define CAM_ILC 1 // Camera is interchangeable lens
//#define CAM_HAS_WIFI 1 // Firmware has wifi support (only define if camera has hardware)
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xfc142914
//#undef CAM_HAS_ND_FILTER // Camera does not have an ND filter
// Camera has an iris (CAM_HAS_IRIS_DIAPHRAGM default)

// physw_event_table 0xfc623d60 Found @0xfc07eeda
// Values below go in 'platform_kbd.h':
//#define SD_READONLY_FLAG    0x20000000 // Found @0xfc623df0, levent 0x20a
//#define SD_READONLY_IDX     1
//#define USB_MASK            0x10000000 // Found @0xfc623e50, levent 0x202
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
// WARNING: Key name / function may vary! Values for unknown DryOS versions should not be trusted!
//KeyMap keymap[] = {
//    { 0, KEY_POWER           ,0x00000001 }, // Found @0xfc623d60, levent 0x100 (uses inverted logic in physw_status)
//    { 0, KEY_PLAYBACK        ,0x00000002 }, // Found @0xfc623d68, levent 0x101 (uses inverted logic in physw_status)
//    { 0, KEY_WIFI            ,0x00000004 }, // Found @0xfc623d70, levent 0x103 (uses inverted logic in physw_status)
//    { 1, KEY_SHOOT_FULL      ,0x00040001 }, // Found @0xfc623d90, levent 0x01
//    { 1, KEY_SHOOT_HALF      ,0x00040000 }, // Found @0xfc623de0, levent 0x00
//    { 1, KEY_SHOOT_FULL_ONLY ,0x00000001 }, // Found @0xfc623d90, levent 0x01
//    { 1, KEY_VIDEO           ,0x00000008 }, // Found @0xfc623d98, levent 0x02
//    { 1, KEY_UP              ,0x00000020 }, // Found @0xfc623da0, levent 0x06
//    { 1, KEY_DOWN            ,0x00000040 }, // Found @0xfc623da8, levent 0x07
//    { 1, KEY_RIGHT           ,0x00000080 }, // Found @0xfc623db0, levent 0x09
//    { 1, KEY_LEFT            ,0x00000100 }, // Found @0xfc623db8, levent 0x08
//    { 1, KEY_SET             ,0x00000200 }, // Found @0xfc623dc0, levent 0x0a
//    { 1, KEY_MENU            ,0x00001000 }, // Found @0xfc623dd8, levent 0x14
//    { 0, 0, 0 }
//};

// canon_mode_list 0xfc77f018 Found @0xfc0e3dc8
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
DEF(ctypes                            ,0xfc608190) // Found @0xfc045b30
DEF(physw_run                         ,0x000082cc) // Found @0xfc08c8ca
DEF(physw_sleep_delay                 ,0x000082d4) // (0x82cc+0x8) Found @0xfc08c8ce
DEF(physw_status                      ,0x00056bec) // Found @0xfc08cbb4
DEF(fileio_semaphore                  ,0x00012030) // Found @0xfc07c0be
DEF(levent_table                      ,0xfc660b58) // Found @0xfc11269c
DEF(FlashParamsTable                  ,0xfc77f390) // Found @0xfc0e3ddc
DEF(playrec_mode                      ,0x0000b2f4) // (0xb2f0+0x4) Found @0xfc33e1ba
DEF(jpeg_count_str                    ,0x00190ac0) // Found @0xfc1a15fe
//DEF(zoom_busy                         ,0x00000000), ** != ** stubs_min = 0x00000001 (1)
//DEF(focus_busy                        ,0x00000000), ** != ** stubs_min = 0x00000001 (1)
DEF(imager_active                     ,0x0000861c) // (0x8618+0x4) Found @0xfc128198
DEF(canon_menu_active                 ,0x0000b9a8) // (0xb9a4+0x4) Found @0xfc35d38e
DEF(file_counter_var                  ,0x00011ee4) // Found @0xfc24a2fc
DEF(cameracon_state                   ,0x00008a74) // (0x8a64+0x10) Found @0xfc3419d6
DEF(_nrflag                           ,0x00029c00) // (0x29bf8+0x8) Found @0xfc3ef476
DEF(av_override_semaphore             ,0x0002e804) // Found @0xfc43f730
DEF(active_bitmap_buffer              ,0x0000b964) // (0xb924+0x40) Found @0xfc38c5e6
DEF(displaytype                       ,0x00009740) // (0x96f0+0x50) Found @0xfc1f025a
DEF(bitmap_buffer                     ,0x0000b968) // (0xb924+0x44) Found @0xfc38c5ec
DEF(palette_control                   ,0x00013528) // Found @0xfc359a20
DEF(palette_buffer_ptr                ,0x00013540) // (0x13528+0x18) Found @0xfc359a3c
DEF(active_palette_buffer             ,0x00013538) // (0x13528+0x10) Found @0xfc359a24
DEF(live_free_cluster_count           ,0x0019c5e8) // (0x19c5b0+0x38) Found @0xfc07085c
DEF_CONST(uiprop_count                      ,0x000000d1) // Found @0xfc27de34
DEF(exmem_alloc_table                 ,0x0005e2b8) // Found @0xfc08125a
DEF(exmem_types_table                 ,0xfce679dc) // Found @0xfc08125e
DEF_CONST(exmem_type_count                  ,0x00000021) // Found @0xfce679dc
DEF(debug_logging_ptr                 ,0x00029ae0) // Found @0xfc3ea7f6
DEF(debug_logging_flag                ,0x00029ad8) // Found @0xfc3ea7f0
DEF(mzrm_sendmsg_ret_adr              ,0xfc3150ff)
DEF_CONST(fw_yuv_layer_buf                  ,0x41141000) // Found @0xfc23d51a

//NHSTUB(DeleteDirectory_Fut                  ,0x00000000) //  0        *** != 0xfc38a1e9
//NHSTUB(DeleteFile_Fut                       ,0x00000000) //  0        *** != 0xfc38a19f
//NHSTUB(GetFocusLensSubjectDistanceFromLens  ,0xfc360eef) //  0        *** != 0x00000000
//NHSTUB(GetImageFolder                       ,0x00000000) //  0        *** != 0xfc313521
//NHSTUB(RenameFile_Fut                       ,0x00000000) //  0        *** != 0xfc38a13d
//NHSTUB(Restart                              ,0x00000000) //  0        *** != 0xfc12790b
//NHSTUB(SetFileAttributes                    ,0x00000000) //  0        *** != 0xfc389b7d
//NHSTUB(SetFileTimeStamp                     ,0x00000000) //  0        *** != 0xfc389b35
//NHSTUB(SetParameterData                     ,0x00000000) //  0        *** != 0xfc27e67f
//NHSTUB(WriteSDCard                          ,0x00000000) //  0        *** != 0x010e2c9d
//NHSTUB(displaybusyonscreen                  ,0x00000000) //  0        *** != 0xfc327437
//NHSTUB(undisplaybusyonscreen                ,0x00000000) //  0        *** != 0xfc3274cd
//NHSTUB(SetHPTimerAfterNow                   ,0x00000000) //  0        *** != 0xfc1fa9ed

NHSTUB(AllocateUncacheableMemory              ,0xfc1428e5) //  0
NHSTUB(Close                                  ,0xfc3898e9) //  0
NHSTUB(CreateBinarySemaphore                  ,0xbfe152f1) //  0
NHSTUB(CreateTask                             ,0xbfe14a41) //  0
NHSTUB(DebugAssert                            ,0x010e1009) //  0
NHSTUB(DeleteSemaphore                        ,0xbfe15375) //  0
NHSTUB(DoAELock                               ,0xfc2a61bb) //  0
NHSTUB(DoAFLock                               ,0xfc2a5de7) //  0
//NHSTUB(EnterToCompensationEVF               ,0xfc2a5fcf) //  0            == 0xfc2a5fcf
NHSTUB2(ExecuteEventProcedure                  ,0xfc33e4f5) //  0
//NHSTUB(ExitFromCompensationEVF              ,0xfc2a6011) //  0            == 0xfc2a6011
NHSTUB(ExitTask                               ,0xbfe14c23) //  0
//NHSTUB(ExpCtrlTool_StartContiAE             ,0xfc2bb67f) //  0            == 0xfc2bb67f
//NHSTUB(ExpCtrlTool_StopContiAE              ,0xfc2bb815) //  0            == 0xfc2bb815
NHSTUB(Fclose_Fut                             ,0xfc38a24b) //  0
//NHSTUB(Feof_Fut                             ,0xfc38a38d) //  0            == 0xfc38a38d
//NHSTUB(Fflush_Fut                           ,0xfc38a3b5) //  0            == 0xfc38a3b5
NHSTUB(Fgets_Fut                              ,0xfc38a329) //  0
NHSTUB(Fopen_Fut                              ,0xfc38a223) //  0
NHSTUB(Fread_Fut                              ,0xfc38a2bd) //  0
NHSTUB(FreeUncacheableMemory                  ,0xfc142911) //  0
NHSTUB(Fseek_Fut                              ,0xfc38a35b) //  0
NHSTUB(Fwrite_Fut                             ,0xfc38a2f3) //  0
NHSTUB(GetBatteryTemperature                  ,0xfc1f3949) //  0
NHSTUB(GetCCDTemperature                      ,0xfc1f38ed) //  0
NHSTUB(GetCurrentAvValue                      ,0xfc33995d) //  0
NHSTUB(GetCurrentShutterSpeed                 ,0xfc142baf) //  0
NHSTUB(GetUsableMaxAv                         ,0xfc181a6d) //  0
NHSTUB(GetUsableMinAv                         ,0xfc181a5b) //  0
NHSTUB(get_current_deltasv                    ,0xfc20f5a7) //  0
NHSTUB(GetCurrentDriveBaseSvValue             ,0xfc317ad7) //  0
NHSTUB(GetDrive_ClusterSize                   ,0xfc388edf) //  0
//NHSTUB(GetDrive_TotalClusters               ,0xfc3893bf) //  0            == 0xfc3893bf
NHSTUB(GetFocusLensSubjectDistance            ,0xfc360d6f) //  0
NHSTUB(GetKbdState                            ,0xfc07efad) //  0
NHSTUB(GetMemInfo                             ,0xfc5b6c01) //  0
NHSTUB(GetOpticalTemperature                  ,0xfc1f39a3) //  0
NHSTUB(GetParameterData                       ,0xfc27e6f7) //  0
NHSTUB(GetPropertyCase                        ,0xfc38828f) //  0
NHSTUB(GetSystemTime                          ,0xfc44398d) //  0
NHSTUB(GetVRAMHPixelsSize                     ,0xfc12a4d3) //  0
NHSTUB(GetVRAMVPixelsSize                     ,0xfc12a4db) //  0
NHSTUB(GetZoomLensCurrentPoint                ,0xfc1863a7) //  0
NHSTUB(GetZoomLensCurrentPosition             ,0xfc18635b) //  0
NHSTUB(GiveSemaphore                          ,0xbfe1545d) //  0
NHSTUB(IsStrobeChargeCompleted                ,0xfc152295) //  0
NHSTUB(LEDDrive                               ,0xfc189ecd) //  0
NHSTUB(LocalTime                              ,0x010e1589) //  0
NHSTUB(LockMainPower                          ,0xfc1fb495) //  0
NHSTUB(MakeDirectory_Fut                      ,0xfc389bd3) //  0
//NHSTUB(MakeSDCardBootable                   ,0xfc38974d) //  0            == 0xfc38974d
//NHSTUB(MoveFocusLensToDistance              ,0x00000000) //  0            == 0x00000000
NHSTUB(MoveIrisWithAv                         ,0xfc43f71d) //  0
NHSTUB(Open                                   ,0xfc389865) //  0
NHSTUB(PB2Rec                                 ,0xfc33ffe1) //  0
NHSTUB(PT_PlaySound                           ,0xfc38c983) //  0
NHSTUB(PostLogicalEventForNotPowerType        ,0xfc38592d) //  0
NHSTUB(PostLogicalEventToUI                   ,0xfc385961) //  0
NHSTUB(Read                                   ,0xfc1ebe69) //  0
NHSTUB(ReadFastDir                            ,0xfc1168dd) //  0
NHSTUB(Rec2PB                                 ,0xfc340025) //  0
NHSTUB(ScreenLock                             ,0xfc38c569) //  0
NHSTUB(ScreenUnlock                           ,0xfc38c59f) //  0
NHSTUB(SetAE_ShutterSpeed                     ,0xfc5bb30d) //  0
NHSTUB(SetAutoShutdownTime                    ,0xfc1fb4e5) //  0
NHSTUB(SetCurrentCaptureModeType              ,0xfc37105f) //  0
NHSTUB(SetDate                                ,0xfc5bc7c5) //  0
NHSTUB(SetLogicalEventActive                  ,0xfc3794f1) //  0
NHSTUB(SetPropertyCase                        ,0xfc38813d) //  0
NHSTUB(SetScriptMode                          ,0xfc379529) //  0
NHSTUB(SleepTask                              ,0xbfe1496d) //  0
NHSTUB(TakeSemaphore                          ,0xbfe153e5) //  0
NHSTUB(TurnOffBackLight                       ,0xfc1f0ac3) //  0
NHSTUB(TurnOnBackLight                        ,0xfc1f0a67) //  0
NHSTUB(TurnOnDisplay                          ,0xfc17701f) //  0
NHSTUB(TurnOffDisplay                         ,0xfc177031) //  0
NHSTUB(UnlockAE                               ,0xfc2a61d9) //  0
NHSTUB(UnlockAF                               ,0xfc2a5e17) //  0
NHSTUB(UnlockMainPower                        ,0xfc1fb42d) //  0
NHSTUB(VbattGet                               ,0xfc12711b) //  0
NHSTUB(Write                                  ,0xfc389921) //  0
NHSTUB(_log                                   ,0x011033b8) //  0
NHSTUB(_log10                                 ,0x011038d8) //  0
NHSTUB(_pow                                   ,0x01103a40) //  0
NHSTUB(_sqrt                                  ,0x01105ac0) //  0
NHSTUB(add_ptp_handler                        ,0xfc307b3b) //  0
//NHSTUB(apex2us                              ,0xfc1b1d0f) //  0            == 0xfc1b1d0f
NHSTUB(close                                  ,0xfc1ebd63) //  0
NHSTUB(err_init_task                          ,0xfc06c723) //  0
NHSTUB(exmem_alloc                            ,0xfc081793) //  0
NHSTUB(exmem_ualloc                           ,0xfc08169d) //  0
NHSTUB(exmem_ufree                            ,0xfc081757) //  0
NHSTUB(free                                   ,0xfc38d48b) //  0
NHSTUB(kbd_p1_f                               ,0xfc08cbad) //  0
NHSTUB(kbd_p1_f_cont                          ,0xfc08cbb5) //  0
NHSTUB(kbd_p2_f                               ,0xfc08c625) //  0
NHSTUB(kbd_read_keys                          ,0xfc08cb77) //  0
NHSTUB(kbd_read_keys_r2                       ,0xfc07eed1) //  0
NHSTUB(lseek                                  ,0xfc389a45) //  0
NHSTUB(malloc                                 ,0xfc38d455) //  0
NHSTUB(memcmp                                 ,0xfc38d6b1) //  0
NHSTUB(memcpy                                 ,0xfc2019a5) //  0
NHSTUB(memset                                 ,0xfc1a7cfd) //  0
NHSTUB(mktime_ext                             ,0xfc2015a1) //  0
NHSTUB(open                                   ,0xfc1ebcf3) //  0
NHSTUB(OpenFastDir                            ,0xfc11683d) //  0
NHSTUB(closedir                               ,0xfc116805) //  0
NHSTUB(get_fstype                             ,0xfc388e79) //  0
NHSTUB(qsort                                  ,0xfc3c5e99) //  0
NHSTUB(rand                                   ,0xfc1049f3) //  0
//NHSTUB(reboot_fw_update                     ,0x00000000) //  0            == 0x00000000
NHSTUB(set_control_event                      ,0xfc379335) //  0
NHSTUB(srand                                  ,0xfc1049ed) //  0
NHSTUB(stat                                   ,0xfc389a7d) //  0
NHSTUB(strcat                                 ,0xfc38d291) //  0
NHSTUB(strchr                                 ,0xfc201a63) //  0
NHSTUB(strcmp                                 ,0xfc38d4e1) //  0
NHSTUB(strcpy                                 ,0xfc38d4bd) //  0
NHSTUB(strftime                               ,0xfc2015d1) //  0
NHSTUB(strlen                                 ,0xfc38d545) //  0
NHSTUB(strncmp                                ,0xfc38d2b3) //  0
NHSTUB(strncpy                                ,0xfc38d26d) //  0
NHSTUB(strrchr                                ,0xfc13b359) //  0
NHSTUB(strtol                                 ,0xfc13b34b) //  0
NHSTUB(strtolx                                ,0xfc13b209) //  0
   DEF(task_CaptSeq                           ,0xfc0bce67) //  0
   DEF(task_DvlpSeqTask                       ,0xfc10ffbb) //  0
   DEF(task_ExpDrv                            ,0xfc27bad1) //  0
   DEF(task_FileWrite                         ,0xfc0736b3) //  0
   DEF(task_InitFileModules                   ,0xfc0d4a01) //  0
   DEF(task_MovieRecord                       ,0xfc100c55) //  0
   DEF(task_PhySw                             ,0xfc08c8c9) //  0
   DEF(task_TouchPanel                        ,0xfc133401) //  0
   DEF(task_TricInitTask                      ,0xfc5607c1) //  0
   DEF(hook_CreateTask                        ,0xbfe14a40) //  0
NHSTUB(time                                   ,0x010e11eb) //  0
NHSTUB(vsprintf                               ,0xfc1049bf) //  0
NHSTUB(EngDrvRead                             ,0xfc38d31d) //  0
NHSTUB(PTM_GetCurrentItem                     ,0xfc372171) //  0
//NHSTUB(CancelHPTimer                        ,0xfc1faa85) //  0            == 0xfc1faa85
NHSTUB(SetEventFlag                           ,0xbfe14e53) //  0
NHSTUB(transfer_src_overlay                   ,0xfc38baad) //  0
NHSTUB(bzero                                  ,0x01100b74) //  0
NHSTUB(memset32                               ,0x01100b78) //  0
NHSTUB(get_dial_hw_position                   ,0xfc43660d) //  0
NHSTUB(PT_MFOn                                ,0xfc2a6f4d) //  0
NHSTUB(PT_MFOff                               ,0xfc2a6f7d) //  0
NHSTUB(GetAdChValue                           ,0xfc1f1c8b) //  0
NHSTUB(EnableHDMIPower                        ,0xfc131925) //  0
NHSTUB(DisableHDMIPower                       ,0xfc131955) //  0
NHSTUB(SetVideoOutType                        ,0xfc5bb8a1) //  0
NHSTUB(GetVideoOutType                        ,0xfc5bb80d) //  0
NHSTUB(IsWirelessConnect                      ,0xfc31d925) //  0
