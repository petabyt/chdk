// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   Main firmware start: 0xfc020000
//   DRYOS R52 (DRYOS version 2.3, release #0052) @ 0xfc481074 ref @ 0xfc063df4
//   Firmware Ver GM1.02C   // Found @ 0xfc142888, "GM1.02C" @ 0xfc142895

// Values for makefile.inc
//   PLATFORMOSVER = 52
//   DIGIC = 60
//   MEMISOSTART = 0x2bd558
//   MEMBASEADDR = 0x8000
//   ARAM_HEAP_START = 0x005ce000#  Found @0xfc1abe94
//   ARAM_HEAP_SIZE = 0x00022000#  Found @0xfc1abe6e

// Detected address ranges:
// ROM      0xfc000000 - 0xfe000000 (33554432 bytes)
// RAM code 0x010c1000 - 0x010e03c4 copied from 0xfc953974 ( 127940 bytes)
// RAM data 0x00008000 - 0x00029460 copied from 0xfc932514 ( 136288 bytes)
// EVEC     0x00000000 - 0x00000038 copied from 0xfc04f248 (     56 bytes)

// Zico Xtensa blobs:
// zico_0 0xbff20000 - 0xbff257c8 copied from 0xfc764824 (  22472 bytes)
// zico_1 0x80a00000 - 0x80afd2e8 copied from 0xfc76a000 (1037032 bytes)

// Omar ARM blobs:
// omar_0 0xdff00000 - 0xdff01610 copied from 0xfc48129c (   5648 bytes)
// omar_1 0x40600000 - 0x40650ce4 copied from 0xfc4828ac ( 330980 bytes)

// Found DryOS versions:
// 0xfc481074 main  "DRYOS version 2.3, release #0052"
// 0xfc4991d4 other "DRYOS version 2.3, release #0052"
// 0xfc76ae90 other "DRYOS version 2.3, release #0052"

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#define CAM_HAS_WIFI 1 // Firmware has wifi support (only define if camera has hardware)
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xfc15a814
//#undef CAM_HAS_ND_FILTER // Camera does not have an ND filter
// Camera has an iris (CAM_HAS_IRIS_DIAPHRAGM default)

// physw_event_table 0xfc4d3ec8 Found @0xfc060920
// Values below go in 'platform_kbd.h':
//#define SD_READONLY_FLAG    0x20000000 // Found @0xfc4d3f88, levent 0x20a
//#define SD_READONLY_IDX     1
//#define USB_MASK            0x10000000 // Found @0xfc4d3fb8, levent 0x202
//#define USB_IDX             2
//#define BATTCOVER_FLAG      0x00000200 // Found @0xfc4d3f98, levent 0x205
//#define BATTCOVER_IDX       2
//#define ANALOG_AV_FLAG      0x00008000 // Found @0xfc4d3f70, levent 0x200 (non-inverted logic)
//#define ANALOG_AV_IDX       1

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
// WARNING: Key name / function may vary! Values for unknown DryOS versions should not be trusted!
//KeyMap keymap[] = {
//    { 0, KEY_POWER           ,0x00000001 }, // Found @0xfc4d3ec8, levent 0x100
//    { 0, KEY_PLAYBACK        ,0x00000002 }, // Found @0xfc4d3ed0, levent 0x101
//    { 0, KEY_SHOOT_FULL      ,0x0000000c }, // Found @0xfc4d3ee0, levent 0x01
//    { 0, KEY_SHOOT_FULL_ONLY ,0x00000008 }, // Found @0xfc4d3ee0, levent 0x01
//    { 0, KEY_SHOOT_HALF      ,0x00000004 }, // Found @0xfc4d3ed8, levent 0x00
//    { 0, KEY_VIDEO           ,0x00000100 }, // Found @0xfc4d3ee8, levent 0x02
//    { 0, KEY_MENU            ,0x00000200 }, // Found @0xfc4d3ef0, levent 0x0b
//    { 0, KEY_DISPLAY         ,0x00002000 }, // Found @0xfc4d3ef8, levent 0x0c
//    { 0, KEY_UP              ,0x00004000 }, // Found @0xfc4d3f00, levent 0x06
//    { 0, KEY_DOWN            ,0x00008000 }, // Found @0xfc4d3f08, levent 0x07
//    { 0, KEY_RIGHT           ,0x00010000 }, // Found @0xfc4d3f10, levent 0x09
//    { 0, KEY_LEFT            ,0x00020000 }, // Found @0xfc4d3f18, levent 0x08
//    { 0, KEY_SET             ,0x00040000 }, // Found @0xfc4d3f20, levent 0x0a
//    { 0, 0, 0 }
//};

// canon_mode_list 0xfc7311f0 Found @0xfc10ac10
// Check modemap values from 'platform/CAMERA/shooting.c':
// 33295  0x820f In firmware but not in current modemap

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
// EXMEM_FILESTORE      16
// EXMEM_MOVIE_REC      17
// EXMEM_MOVIE_PLY      18
// EXMEM_WIDE           19
// EXMEM_NARROW         20
// EXMEM_AUTO_GIS_MODE  21
// EXMEM_NP_GIS_MODE    22
// EXMEM_TRIPODHDR_MODE 23
// EXMEM_HSHQ_MODE      24
// EXMEM_CRAW_REC       25
// EXMEM_PCEVF          26
// EXMEM_WIFI_RESIZE    27

// Values below can be overridden in 'stubs_min.S':
//DEF(ctypes                            ,0xfc48111c),          stubs_min = 0xfc48111c (0xfc48111c)
//DEF(physw_run                         ,0x00008328),          stubs_min = 0x00008328 (0x00008328)
//DEF(physw_sleep_delay                 ,0x00008330),          stubs_min = 0x00008330 (0x00008330)
//DEF(physw_status                      ,0x0002ae70),          stubs_min = 0x0002ae70 (0x0002ae70)
//DEF(fileio_semaphore                  ,0x000103b4),          stubs_min = 0x000103b4 (0x000103b4)
//DEF(levent_table                      ,0xfc512634),          stubs_min = 0xfc512634 (0xfc512634)
//DEF(FlashParamsTable                  ,0xfc731440),          stubs_min = 0xfc731440 (0xfc731440)
//DEF(playrec_mode                      ,0x0000a140),          stubs_min = 0x0000a140 (0x0000a140)
//DEF(jpeg_count_str                    ,0x000e4308),          stubs_min = 0x000e4308 (0x000e4308)
//DEF(zoom_busy                         ,0x00010814),          stubs_min = 0x00010814 (0x00010814)
//DEF(focus_busy                        ,0x00010694),          stubs_min = 0x00010694 (0x00010694)
DEF(imager_active                     ,0x00008624) // (0x8620+0x4) Found @0xfc132c7a
//DEF(canon_menu_active                 ,0x0000ac58),          stubs_min = 0x0000ac58 (0x0000ac58)
//DEF(file_counter_var                  ,0x000102dc),          stubs_min = 0x000102dc (0x000102dc)
DEF(cameracon_state                   ,0x00008918) // (0x8908+0x10) Found @0xfc0c1998
DEF(av_override_semaphore             ,0x0001bfa0) // Found @0xfc3b7e2c
DEF(active_bitmap_buffer              ,0x0000ac14) // (0xabdc+0x38) Found @0xfc143c7e
//DEF(displaytype                       ,0x00008eb8),          stubs_min = 0x00008eb8 (0x8eb8)
//DEF(bitmap_buffer                     ,0x0000ac18),          stubs_min = 0x0000ac18 (0xac18)
DEF(palette_control                   ,0x00012a94) // Found @0xfc2b0f4e
DEF(palette_buffer_ptr                ,0x00012aac) // (0x12a94+0x18) Found @0xfc2b0f6c
DEF(active_palette_buffer             ,0x00012aa0) // (0x12a94+0xc) Found @0xfc2b0f54
DEF(live_free_cluster_count           ,0x000eac10) // (0xeabd8+0x38) Found @0xfc053f28
DEF_CONST(uiprop_count                      ,0x00000083) // Found @0xfc090128
DEF(exmem_alloc_table                 ,0x0003280c) // Found @0xfc06225a
DEF(exmem_types_table                 ,0xfc934724) // Found @0xfc06225e
DEF_CONST(exmem_type_count                  ,0x0000001c) // Found @0xfc934724
DEF(debug_logging_ptr                 ,0x00017fc8) // Found @0xfc3a854a
DEF(debug_logging_flag                ,0x00017fc0) // Found @0xfc3a8544
DEF(mzrm_sendmsg_ret_adr              ,0xfc254853)
DEF_CONST(fw_yuv_layer_buf                  ,0x41815800) // Found @0xfc186ed8
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 2 int value(s), the first is the zoom focus length.
// there are 101 entries in the table - set NUM_FL to 101
//DEF(focus_len_table                         ,0xfdf6ad20) // Found @0xfdf6ad20,          stubs_min = 0xfdf6ad20 (0xfdf6ad20)

//NHSTUB(GetImageFolder                       ,0x00000000) //  0        *** != 0xfc25d561
//NHSTUB(RenameFile_Fut                       ,0x00000000) //  0        *** != 0xfc28fd11
//NHSTUB(Restart                              ,0x00000000) //  0        *** != 0xfc095c41
//NHSTUB(SetFileAttributes                    ,0x00000000) //  0        *** != 0xfc2a5395
//NHSTUB(SetFileTimeStamp                     ,0x00000000) //  0        *** != 0xfc2a534d
//NHSTUB(SetParameterData                     ,0x00000000) //  0        *** != 0xfc09089f
//NHSTUB(TurnOffBackLight                     ,0xfc136705) //  0        *** != 0xfc0d2997
//NHSTUB(TurnOnBackLight                      ,0xfc1366c7) //  0        *** != 0xfc0d2985
//NHSTUB(WriteSDCard                          ,0x00000000) //  0        *** != 0xfc19bb17
//NHSTUB(realloc                              ,0x00000000) //  0        *** != 0xfc42ae41
//NHSTUB(reboot_fw_update                     ,0x00000000) //  0        *** != 0xfc3352b1
//NHSTUB(CancelHPTimer                        ,0x00000000) //  0        *** != 0xfc1423c9

NHSTUB(AllocateUncacheableMemory              ,0xfc15a7e5) //  0
NHSTUB(Close                                  ,0xfc2a5101) //  0
NHSTUB(CreateBinarySemaphore                  ,0x010c5915) //  0
NHSTUB(CreateTask                             ,0x010c51fd) //  0
NHSTUB(DebugAssert                            ,0x010c5c3d) //  0
NHSTUB(DeleteDirectory_Fut                    ,0xfc28fdbd) //  0
NHSTUB(DeleteFile_Fut                         ,0xfc28fd73) //  0
NHSTUB(DeleteSemaphore                        ,0x010c598f) //  0
NHSTUB(DoAELock                               ,0xfc20df55) //  0
NHSTUB(DoAFLock                               ,0xfc20dc5b) //  0
//NHSTUB(EnterToCompensationEVF               ,0xfc20decb) //  0            == 0xfc20decb
NHSTUB2(ExecuteEventProcedure                  ,0xfc29ab95) //  0
//NHSTUB(ExitFromCompensationEVF              ,0xfc20df07) //  0            == 0xfc20df07
NHSTUB(ExitTask                               ,0x010c5369) //  0
//NHSTUB(ExpCtrlTool_StartContiAE             ,0xfc204fab) //  0            == 0xfc204fab
//NHSTUB(ExpCtrlTool_StopContiAE              ,0xfc20508b) //  0            == 0xfc20508b
NHSTUB(Fclose_Fut                             ,0xfc28fe1f) //  0
//NHSTUB(Feof_Fut                             ,0xfc28ff61) //  0            == 0xfc28ff61
//NHSTUB(Fflush_Fut                           ,0xfc28ff89) //  0            == 0xfc28ff89
NHSTUB(Fgets_Fut                              ,0xfc28fefd) //  0
NHSTUB(Fopen_Fut                              ,0xfc28fdf7) //  0
NHSTUB(Fread_Fut                              ,0xfc28fe91) //  0
NHSTUB(FreeUncacheableMemory                  ,0xfc15a811) //  0
NHSTUB(Fseek_Fut                              ,0xfc28ff2f) //  0
NHSTUB(Fwrite_Fut                             ,0xfc28fec7) //  0
NHSTUB(GetBatteryTemperature                  ,0xfc138e15) //  0
NHSTUB(GetCCDTemperature                      ,0xfc138db9) //  0
NHSTUB(GetCurrentAvValue                      ,0xfc19e9b9) //  0
NHSTUB(GetCurrentShutterSpeed                 ,0xfc2a659f) //  0
NHSTUB(GetUsableMaxAv                         ,0xfc197eaf) //  0
NHSTUB(GetUsableMinAv                         ,0xfc197e9d) //  0
NHSTUB(get_current_deltasv                    ,0xfc15b557) //  0
NHSTUB(GetCurrentDriveBaseSvValue             ,0xfc15f9bd) //  0
NHSTUB(GetDrive_ClusterSize                   ,0xfc2a46b3) //  0
//NHSTUB(GetDrive_TotalClusters               ,0xfc2a4be3) //  0            == 0xfc2a4be3
NHSTUB(GetFocusLensSubjectDistance            ,0xfc28c613) //  0
//NHSTUB(GetFocusLensSubjectDistanceFromLens  ,0xfc28c8d7) //  0            == 0xfc28c8d7
NHSTUB(GetKbdState                            ,0xfc05f577) //  0
NHSTUB(GetMemInfo                             ,0xfc12dfb1) //  0
NHSTUB(GetOpticalTemperature                  ,0xfc138e6f) //  0
NHSTUB(GetParameterData                       ,0xfc09091f) //  0
NHSTUB(GetPropertyCase                        ,0xfc2978b5) //  0
NHSTUB(GetSystemTime                          ,0xfc3b989d) //  0
NHSTUB(GetVRAMHPixelsSize                     ,0xfc134981) //  0
NHSTUB(GetVRAMVPixelsSize                     ,0xfc134989) //  0
NHSTUB(GetZoomLensCurrentPoint                ,0xfc1a0c71) //  0
NHSTUB(GetZoomLensCurrentPosition             ,0xfc32facd) //  0
NHSTUB(GiveSemaphore                          ,0x010c5a6d) //  0
NHSTUB(IsStrobeChargeCompleted                ,0xfc17196b) //  0
NHSTUB(LEDDrive                               ,0xfc1a73ed) //  0
NHSTUB(LocalTime                              ,0x010c6239) //  0
NHSTUB(LockMainPower                          ,0xfc142d85) //  0
NHSTUB(MakeDirectory_Fut                      ,0xfc2a53eb) //  0
//NHSTUB(MakeSDCardBootable                   ,0xfc2a4fe3) //  0            == 0xfc2a4fe3
NHSTUB(MoveFocusLensToDistance                ,0xfc3de41b) //  0
NHSTUB(MoveIrisWithAv                         ,0xfc3b7e19) //  0
NHSTUB(MoveZoomLensWithPoint                  ,0xfc3b859f) //  0
NHSTUB(Open                                   ,0xfc2a507d) //  0
NHSTUB(PB2Rec                                 ,0xfc0c0985) //  0
NHSTUB(PT_MoveDigitalZoomToWide               ,0xfc20d755) //  0
NHSTUB(PT_MoveOpticalZoomAt                   ,0xfc1a8291) //  0
NHSTUB(MoveOpticalZoomAt                      ,0xfc20d679) //  0
NHSTUB(PT_PlaySound                           ,0xfc148f2d) //  0
NHSTUB(PostLogicalEventForNotPowerType        ,0xfc2a615d) //  0
NHSTUB(PostLogicalEventToUI                   ,0xfc2a6189) //  0
NHSTUB(PutInNdFilter                          ,0xfc3dd989) //  0
NHSTUB(PutOutNdFilter                         ,0xfc3dd9af) //  0
NHSTUB(Read                                   ,0xfc0ba575) //  0
NHSTUB(ReadFastDir                            ,0xfc1081d1) //  0
NHSTUB(Rec2PB                                 ,0xfc0c09b7) //  0
NHSTUB(ScreenLock                             ,0xfc143bd3) //  0
NHSTUB(ScreenUnlock                           ,0xfc143c0b) //  0
NHSTUB(SetAE_ShutterSpeed                     ,0xfc3e0595) //  0
NHSTUB(SetAutoShutdownTime                    ,0xfc142dd1) //  0
NHSTUB(SetCurrentCaptureModeType              ,0xfc2766f5) //  0
NHSTUB(SetDate                                ,0xfc3e19cd) //  0
NHSTUB(SetLogicalEventActive                  ,0xfc2b0157) //  0
NHSTUB(SetPropertyCase                        ,0xfc29778f) //  0
NHSTUB(SetScriptMode                          ,0xfc2b018f) //  0
NHSTUB(SleepTask                              ,0x010c5179) //  0
NHSTUB(TakeSemaphore                          ,0x010c59f9) //  0
NHSTUB(TurnOnDisplay                          ,0xfc0eb6b5) //  0
NHSTUB(TurnOffDisplay                         ,0xfc0eb6c7) //  0
NHSTUB(UnlockAE                               ,0xfc20df73) //  0
NHSTUB(UnlockAF                               ,0xfc20dc83) //  0
NHSTUB(UnlockMainPower                        ,0xfc142d25) //  0
//NHSTUB(UnsetZoomForMovie                    ,0x00000000) //  0            == 0x00000000
NHSTUB(VbattGet                               ,0xfc12ec71) //  0
NHSTUB(Write                                  ,0xfc2a5139) //  0
NHSTUB(_log                                   ,0x010dbe08) //  0
NHSTUB(_log10                                 ,0x010dc328) //  0
NHSTUB(_pow                                   ,0x010dc490) //  0
NHSTUB(_sqrt                                  ,0x010de238) //  0
NHSTUB(add_ptp_handler                        ,0xfc0df5c3) //  0
//NHSTUB(apex2us                              ,0xfc0a950f) //  0            == 0xfc0a950f
NHSTUB(close                                  ,0xfc0ba46f) //  0
NHSTUB(displaybusyonscreen                    ,0xfc14a149) //  0
//NHSTUB(err_init_task                        ,0xfc04f3b9) //  0            == 0xfc04f3b9
NHSTUB(exmem_alloc                            ,0xfc062729) //  0
NHSTUB(exmem_ualloc                           ,0xfc0624fb) //  0
NHSTUB(exmem_ufree                            ,0xfc0626df) //  0
NHSTUB(free                                   ,0xfc2b7f67) //  0
NHSTUB(kbd_p1_f                               ,0xfc0604e5) //  0
NHSTUB(kbd_p1_f_cont                          ,0xfc0604ed) //  0
NHSTUB(kbd_p2_f                               ,0xfc05ffc1) //  0
NHSTUB(kbd_read_keys                          ,0xfc0604af) //  0
NHSTUB(kbd_read_keys_r2                       ,0xfc06091d) //  0
NHSTUB(lseek                                  ,0xfc2a525d) //  0
NHSTUB(malloc                                 ,0xfc2b7f31) //  0
NHSTUB(memcmp                                 ,0xfc2b800f) //  0
NHSTUB(memcpy                                 ,0xfc0d32e1) //  0
NHSTUB(memset                                 ,0xfc2bea15) //  0
NHSTUB(mktime_ext                             ,0xfc14a5dd) //  0
NHSTUB(open                                   ,0xfc0ba3ff) //  0
NHSTUB(OpenFastDir                            ,0xfc108131) //  0
NHSTUB(closedir                               ,0xfc1080f9) //  0
NHSTUB(get_fstype                             ,0xfc2a464d) //  0
NHSTUB(qsort                                  ,0xfc2be9cf) //  0
NHSTUB(rand                                   ,0xfc0d32c3) //  0
NHSTUB(set_control_event                      ,0xfc2afe9d) //  0
NHSTUB(srand                                  ,0xfc0d32bd) //  0
NHSTUB(stat                                   ,0xfc2a5295) //  0
NHSTUB(strcat                                 ,0xfc14a9c9) //  0
NHSTUB(strchr                                 ,0xfc0d3375) //  0
NHSTUB(strcmp                                 ,0xfc2b7e61) //  0
NHSTUB(strcpy                                 ,0xfc2b7e95) //  0
NHSTUB(strftime                               ,0xfc14a60d) //  0
NHSTUB(strlen                                 ,0xfc2b7ea5) //  0
NHSTUB(strncmp                                ,0xfc14aa15) //  0
NHSTUB(strncpy                                ,0xfc2b7e71) //  0
NHSTUB(strrchr                                ,0xfc0d3387) //  0
NHSTUB(strtol                                 ,0xfc09b63b) //  0
NHSTUB(strtolx                                ,0xfc09b4f9) //  0
   DEF(task_CaptSeq                           ,0xfc0cdb9f) //  0
   DEF(task_DvlpSeqTask                       ,0xfc1aa80f) //  0
   DEF(task_ExpDrv                            ,0xfc1e93dd) //  0
   DEF(task_FileWrite                         ,0xfc05509d) //  0
   DEF(task_InitFileModules                   ,0xfc088221) //  0
   DEF(task_MovieRecord                       ,0xfc1a5d1d) //  0
   DEF(task_PhySw                             ,0xfc0601f5) //  0
   DEF(task_TricInitTask                      ,0xfc373dc1) //  0
   DEF(hook_CreateTask                        ,0x010c51fc) //  0
NHSTUB(time                                   ,0x010c5ef1) //  0
NHSTUB(vsprintf                               ,0xfc09b4cb) //  0
NHSTUB(undisplaybusyonscreen                  ,0xfc14a27f) //  0
NHSTUB(EngDrvRead                             ,0xfc2b7d27) //  0
NHSTUB(PTM_GetCurrentItem                     ,0xfc2b06cb) //  0
NHSTUB(DisableISDriveError                    ,0xfc3b8b2d) //  0
//NHSTUB(SetHPTimerAfterNow                   ,0xfc142331) //  0            == 0xfc142331
NHSTUB(SetEventFlag                           ,0x010c5569) //  0
NHSTUB(transfer_src_overlay                   ,0xfc143345) //  0
NHSTUB(bzero                                  ,0x010da260) //  0
NHSTUB(memset32                               ,0x010da264) //  0
NHSTUB(get_dial_hw_position                   ,0xfc32bebf) //  0
NHSTUB(PT_MFOn                                ,0xfc20ee2b) //  0
NHSTUB(PT_MFOff                               ,0xfc20ee5b) //  0
NHSTUB(GetAdChValue                           ,0xfc0c33c7) //  0
NHSTUB(EnableHDMIPower                        ,0xfc099f1b) //  0
NHSTUB(DisableHDMIPower                       ,0xfc099f51) //  0
NHSTUB(SetVideoOutType                        ,0xfc3e0b25) //  0
NHSTUB(GetVideoOutType                        ,0xfc3e0a95) //  0
NHSTUB(IsWirelessConnect                      ,0xfc134c67) //  0
