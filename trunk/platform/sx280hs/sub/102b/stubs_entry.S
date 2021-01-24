// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   Main firmware start: 0xfc020000
//   DRYOS R52 (DRYOS version 2.3, release #0052) @ 0xfc480fe0 ref @ 0xfc063df4
//   Firmware Ver GM1.02B   // Found @ 0xfc142888, "GM1.02B" @ 0xfc142895

// Values for makefile.inc
//   PLATFORMOSVER = 52
//   DIGIC = 60
//   MEMISOSTART = 0x2bd558
//   MEMBASEADDR = 0x8000
//   ARAM_HEAP_START = 0x005ce000#  Found @0xfc1abe80
//   ARAM_HEAP_SIZE = 0x00022000#  Found @0xfc1abe5a

// Detected address ranges:
// ROM      0xfc000000 - 0xfe000000 (33554432 bytes)
// RAM code 0x010c1000 - 0x010e03c4 copied from 0xfc9538d4 ( 127940 bytes)
// RAM data 0x00008000 - 0x00029460 copied from 0xfc932474 ( 136288 bytes)
// EVEC     0x00000000 - 0x00000038 copied from 0xfc04f248 (     56 bytes)

// Zico Xtensa blobs:
// zico_0 0xbff20000 - 0xbff257c8 copied from 0xfc764784 (  22472 bytes)
// zico_1 0x80a00000 - 0x80afd2e8 copied from 0xfc769f60 (1037032 bytes)

// Omar ARM blobs:
// omar_0 0xdff00000 - 0xdff01610 copied from 0xfc481208 (   5648 bytes)
// omar_1 0x40600000 - 0x40650ce4 copied from 0xfc482818 ( 330980 bytes)

// Found DryOS versions:
// 0xfc480fe0 main  "DRYOS version 2.3, release #0052"
// 0xfc499140 other "DRYOS version 2.3, release #0052"
// 0xfc76adf0 other "DRYOS version 2.3, release #0052"

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xfc15a814
//#undef CAM_HAS_ND_FILTER // Camera does not have an ND filter
// Camera has an iris (CAM_HAS_IRIS_DIAPHRAGM default)

// physw_event_table 0xfc4d3e34 Found @0xfc060920
// Values below go in 'platform_kbd.h':
//#define SD_READONLY_FLAG    0x20000000 // Found @0xfc4d3ef4, levent 0x20a
//#define SD_READONLY_IDX     1
//#define USB_MASK            0x10000000 // Found @0xfc4d3f24, levent 0x202
//#define USB_IDX             2
//#define BATTCOVER_FLAG      0x00000200 // Found @0xfc4d3f04, levent 0x205
//#define BATTCOVER_IDX       2
//#define ANALOG_AV_FLAG      0x00008000 // Found @0xfc4d3edc, levent 0x200 (non-inverted logic)
//#define ANALOG_AV_IDX       1

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
// WARNING: Key name / function may vary! Values for unknown DryOS versions should not be trusted!
//KeyMap keymap[] = {
//    { 0, KEY_POWER           ,0x00000001 }, // Found @0xfc4d3e34, levent 0x100
//    { 0, KEY_PLAYBACK        ,0x00000002 }, // Found @0xfc4d3e3c, levent 0x101
//    { 0, KEY_SHOOT_FULL      ,0x0000000c }, // Found @0xfc4d3e4c, levent 0x01
//    { 0, KEY_SHOOT_FULL_ONLY ,0x00000008 }, // Found @0xfc4d3e4c, levent 0x01
//    { 0, KEY_SHOOT_HALF      ,0x00000004 }, // Found @0xfc4d3e44, levent 0x00
//    { 0, KEY_VIDEO           ,0x00000100 }, // Found @0xfc4d3e54, levent 0x02
//    { 0, KEY_MENU            ,0x00000200 }, // Found @0xfc4d3e5c, levent 0x0b
//    { 0, KEY_DISPLAY         ,0x00002000 }, // Found @0xfc4d3e64, levent 0x0c
//    { 0, KEY_UP              ,0x00004000 }, // Found @0xfc4d3e6c, levent 0x06
//    { 0, KEY_DOWN            ,0x00008000 }, // Found @0xfc4d3e74, levent 0x07
//    { 0, KEY_RIGHT           ,0x00010000 }, // Found @0xfc4d3e7c, levent 0x09
//    { 0, KEY_LEFT            ,0x00020000 }, // Found @0xfc4d3e84, levent 0x08
//    { 0, KEY_SET             ,0x00040000 }, // Found @0xfc4d3e8c, levent 0x0a
//    { 0, 0, 0 }
//};

// canon_mode_list 0xfc731150 Found @0xfc10ac10
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
//DEF(ctypes                            ,0xfc481088),          stubs_min = 0xfc481088 (0xfc481088)
//DEF(physw_run                         ,0x00008328),          stubs_min = 0x00008328 (0x00008328)
//DEF(physw_sleep_delay                 ,0x00008330),          stubs_min = 0x00008330 (0x00008330)
//DEF(physw_status                      ,0x0002ae70),          stubs_min = 0x0002ae70 (0x0002ae70)
//DEF(fileio_semaphore                  ,0x000103b4),          stubs_min = 0x000103b4 (0x000103b4)
//DEF(levent_table                      ,0xfc512594),          stubs_min = 0xfc512594 (0xfc512594)
//DEF(FlashParamsTable                  ,0xfc7313a0),          stubs_min = 0xfc7313a0 (0xfc7313a0)
//DEF(playrec_mode                      ,0x0000a140),          stubs_min = 0x0000a140 (0x0000a140)
//DEF(jpeg_count_str                    ,0x000e4308),          stubs_min = 0x000e4308 (0x000e4308)
//DEF(zoom_busy                         ,0x00010814),          stubs_min = 0x00010814 (0x00010814)
//DEF(focus_busy                        ,0x00010694),          stubs_min = 0x00010694 (0x00010694)
DEF(imager_active                     ,0x00008624) // (0x8620+0x4) Found @0xfc132c7a
//DEF(canon_menu_active                 ,0x0000ac58),          stubs_min = 0x0000ac58 (0x0000ac58)
//DEF(file_counter_var                  ,0x000102dc),          stubs_min = 0x000102dc (0x000102dc)
DEF(av_override_semaphore             ,0x0001bfa0) // Found @0xfc3b7d9c
DEF(active_bitmap_buffer              ,0x0000ac14) // (0xabdc+0x38) Found @0xfc143c7e
//DEF(displaytype                       ,0x00008eb8),          stubs_min = 0x00008eb8 (0x8eb8)
//DEF(bitmap_buffer                     ,0x0000ac18),          stubs_min = 0x0000ac18 (0xac18)
DEF(palette_control                   ,0x00012a94) // Found @0xfc2b0ed2
DEF(palette_buffer_ptr                ,0x00012aac) // (0x12a94+0x18) Found @0xfc2b0ef0
DEF(active_palette_buffer             ,0x00012aa0) // (0x12a94+0xc) Found @0xfc2b0ed8
DEF(live_free_cluster_count           ,0x000eac10) // (0xeabd8+0x38) Found @0xfc053f28
DEF_CONST(uiprop_count                      ,0x00000083) // Found @0xfc090128
DEF(exmem_alloc_table                 ,0x0003280c) // Found @0xfc06225a
DEF(exmem_types_table                 ,0xfc934684) // Found @0xfc06225e
DEF_CONST(exmem_type_count                  ,0x0000001c) // Found @0xfc934684
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 2 int value(s), the first is the zoom focus length.
// there are 101 entries in the table - set NUM_FL to 101
//DEF(focus_len_table                         ,0xfdf6ad20) // Found @0xfdf6ad20,          stubs_min = 0xfdf6ad20 (0xfdf6ad20)

//NHSTUB(EnterToCompensationEVF               ,0x00000000) //  0        *** != 0xfc20deb7
//NHSTUB(ExitFromCompensationEVF              ,0x00000000) //  0        *** != 0xfc20def3
//NHSTUB(ExpCtrlTool_StartContiAE             ,0x00000000) //  0        *** != 0xfc204f97
//NHSTUB(ExpCtrlTool_StopContiAE              ,0x00000000) //  0        *** != 0xfc205077
//NHSTUB(Feof_Fut                             ,0x00000000) //  0        *** != 0xfc28fef1
//NHSTUB(Fflush_Fut                           ,0x00000000) //  0        *** != 0xfc28ff19
//NHSTUB(GetDrive_TotalClusters               ,0x00000000) //  0        *** != 0xfc2a4b67
//NHSTUB(GetFocusLensSubjectDistanceFromLens  ,0x00000000) //  0        *** != 0xfc28c84f
//NHSTUB(GetImageFolder                       ,0x00000000) //  0        *** != 0xfc25d4d9
//NHSTUB(MakeSDCardBootable                   ,0x00000000) //  0        *** != 0xfc2a4f67
//NHSTUB(RenameFile_Fut                       ,0x00000000) //  0        *** != 0xfc28fca1
//NHSTUB(Restart                              ,0x00000000) //  0        *** != 0xfc095c41
//NHSTUB(SetFileAttributes                    ,0x00000000) //  0        *** != 0xfc2a5319
//NHSTUB(SetFileTimeStamp                     ,0x00000000) //  0        *** != 0xfc2a52d1
//NHSTUB(SetParameterData                     ,0x00000000) //  0        *** != 0xfc09089f
//NHSTUB(TurnOffBackLight                     ,0xfc136705) //  0        *** != 0xfc0d2997
//NHSTUB(TurnOnBackLight                      ,0xfc1366c7) //  0        *** != 0xfc0d2985
//NHSTUB(WriteSDCard                          ,0x00000000) //  0        *** != 0xfc19bb17
//NHSTUB(apex2us                              ,0x00000000) //  0        *** != 0xfc0a950f
//NHSTUB(err_init_task                        ,0x00000000) //  0        *** != 0xfc04f3b9
//NHSTUB(realloc                              ,0x00000000) //  0        *** != 0xfc42adb1
//NHSTUB(reboot_fw_update                     ,0x00000000) //  0        *** != 0xfc335235
//NHSTUB(CancelHPTimer                        ,0x00000000) //  0        *** != 0xfc1423c9

NHSTUB(AllocateUncacheableMemory              ,0xfc15a7e5) //  0
NHSTUB(Close                                  ,0xfc2a5085) //  0
NHSTUB(CreateBinarySemaphore                  ,0x010c5915) //  0
NHSTUB(CreateTask                             ,0x010c51fd) //  0
NHSTUB(DebugAssert                            ,0x010c5c3d) //  0
NHSTUB(DeleteDirectory_Fut                    ,0xfc28fd4d) //  0
NHSTUB(DeleteFile_Fut                         ,0xfc28fd03) //  0
NHSTUB(DoAELock                               ,0xfc20df41) //  0
NHSTUB(DoAFLock                               ,0xfc20dc47) //  0
NHSTUB2(ExecuteEventProcedure                  ,0xfc29ab19) //  0
NHSTUB(ExitTask                               ,0x010c5369) //  0
NHSTUB(Fclose_Fut                             ,0xfc28fdaf) //  0
NHSTUB(Fgets_Fut                              ,0xfc28fe8d) //  0
NHSTUB(Fopen_Fut                              ,0xfc28fd87) //  0
NHSTUB(Fread_Fut                              ,0xfc28fe21) //  0
NHSTUB(FreeUncacheableMemory                  ,0xfc15a811) //  0
NHSTUB(Fseek_Fut                              ,0xfc28febf) //  0
NHSTUB(Fwrite_Fut                             ,0xfc28fe57) //  0
NHSTUB(GetBatteryTemperature                  ,0xfc138e15) //  0
NHSTUB(GetCCDTemperature                      ,0xfc138db9) //  0
NHSTUB(GetCurrentAvValue                      ,0xfc19e9b9) //  0
NHSTUB(GetCurrentShutterSpeed                 ,0xfc2a6523) //  0
NHSTUB(GetUsableMaxAv                         ,0xfc197eaf) //  0
NHSTUB(GetUsableMinAv                         ,0xfc197e9d) //  0
NHSTUB(GetDrive_ClusterSize                   ,0xfc2a4637) //  0
NHSTUB(GetDrive_FreeClusters                  ,0xfc2a4b8b) //  0
NHSTUB(GetFocusLensSubjectDistance            ,0xfc28c58b) //  0
NHSTUB(GetKbdState                            ,0xfc05f577) //  0
NHSTUB(GetMemInfo                             ,0xfc12dfb1) //  0
NHSTUB(GetOpticalTemperature                  ,0xfc138e6f) //  0
NHSTUB(GetParameterData                       ,0xfc09091f) //  0
NHSTUB(GetPropertyCase                        ,0xfc297839) //  0
NHSTUB(GetSystemTime                          ,0xfc3b980d) //  0
NHSTUB(GetVRAMHPixelsSize                     ,0xfc134981) //  0
NHSTUB(GetVRAMVPixelsSize                     ,0xfc134989) //  0
NHSTUB(GetZoomLensCurrentPoint                ,0xfc1a0c71) //  0
NHSTUB(GetZoomLensCurrentPosition             ,0xfc1a0c05) //  0
NHSTUB(GiveSemaphore                          ,0x010c5a6d) //  0
NHSTUB(IsStrobeChargeCompleted                ,0xfc17196b) //  0
NHSTUB(LEDDrive                               ,0xfc1a73d9) //  0
NHSTUB(LocalTime                              ,0x010c6239) //  0
NHSTUB(LockMainPower                          ,0xfc142d85) //  0
NHSTUB(MakeDirectory_Fut                      ,0xfc2a536f) //  0
NHSTUB(MoveFocusLensToDistance                ,0xfc3de38b) //  0
NHSTUB(MoveIrisWithAv                         ,0xfc3b7d89) //  0
NHSTUB(MoveZoomLensWithPoint                  ,0xfc3b850f) //  0
NHSTUB(Open                                   ,0xfc2a5001) //  0
NHSTUB(PB2Rec                                 ,0xfc0c0985) //  0
NHSTUB(PT_MoveDigitalZoomToWide               ,0xfc20d741) //  0
NHSTUB(PT_MoveOpticalZoomAt                   ,0xfc1a827d) //  0
NHSTUB(MoveOpticalZoomAt                      ,0xfc20d665) //  0
NHSTUB(PT_PlaySound                           ,0xfc148f2d) //  0
NHSTUB(PostLogicalEventForNotPowerType        ,0xfc2a60e1) //  0
NHSTUB(PostLogicalEventToUI                   ,0xfc2a610d) //  0
NHSTUB(PutInNdFilter                          ,0xfc3dd8f9) //  0
NHSTUB(PutOutNdFilter                         ,0xfc3dd91f) //  0
NHSTUB(Read                                   ,0xfc0ba575) //  0
NHSTUB(ReadFastDir                            ,0xfc1081d1) //  0
NHSTUB(Rec2PB                                 ,0xfc0c09b7) //  0
NHSTUB(ScreenLock                             ,0xfc143bd3) //  0
NHSTUB(ScreenUnlock                           ,0xfc143c0b) //  0
NHSTUB(SetAE_ShutterSpeed                     ,0xfc3e0505) //  0
NHSTUB(SetAutoShutdownTime                    ,0xfc142dd1) //  0
NHSTUB(SetCurrentCaptureModeType              ,0xfc27666d) //  0
NHSTUB(SetDate                                ,0xfc3e193d) //  0
NHSTUB(SetLogicalEventActive                  ,0xfc2b00db) //  0
NHSTUB(SetPropertyCase                        ,0xfc297713) //  0
NHSTUB(SetScriptMode                          ,0xfc2b0113) //  0
NHSTUB(SleepTask                              ,0x010c5179) //  0
NHSTUB(TakeSemaphore                          ,0x010c59f9) //  0
NHSTUB(TurnOnDisplay                          ,0xfc0eb6b5) //  0
NHSTUB(TurnOffDisplay                         ,0xfc0eb6c7) //  0
NHSTUB(UnlockAE                               ,0xfc20df5f) //  0
NHSTUB(UnlockAF                               ,0xfc20dc6f) //  0
NHSTUB(UnlockMainPower                        ,0xfc142d25) //  0
//NHSTUB(UnsetZoomForMovie                    ,0x00000000) //  0            == 0x00000000
NHSTUB(VbattGet                               ,0xfc12ec71) //  0
NHSTUB(Write                                  ,0xfc2a50bd) //  0
NHSTUB(_log                                   ,0x010dbe08) //  0
NHSTUB(_log10                                 ,0x010dc328) //  0
NHSTUB(_pow                                   ,0x010dc490) //  0
NHSTUB(_sqrt                                  ,0x010de238) //  0
NHSTUB(add_ptp_handler                        ,0xfc0df5c3) //  0
NHSTUB(close                                  ,0xfc0ba46f) //  0
NHSTUB(displaybusyonscreen                    ,0xfc14a149) //  0
NHSTUB(exmem_alloc                            ,0xfc062729) //  0
NHSTUB(exmem_ualloc                           ,0xfc0624fb) //  0
NHSTUB(exmem_ufree                            ,0xfc0626df) //  0
NHSTUB(free                                   ,0xfc2b7eeb) //  0
NHSTUB(kbd_p1_f                               ,0xfc0604e5) //  0
NHSTUB(kbd_p1_f_cont                          ,0xfc0604ed) //  0
NHSTUB(kbd_p2_f                               ,0xfc05ffc1) //  0
NHSTUB(kbd_read_keys                          ,0xfc0604af) //  0
NHSTUB(kbd_read_keys_r2                       ,0xfc06091d) //  0
NHSTUB(lseek                                  ,0xfc2a51e1) //  0
NHSTUB(malloc                                 ,0xfc2b7eb5) //  0
NHSTUB(memcmp                                 ,0xfc2b7f93) //  0
NHSTUB(memcpy                                 ,0xfc0d32e1) //  0
NHSTUB(memset                                 ,0xfc2be999) //  0
NHSTUB(mktime_ext                             ,0xfc14a5dd) //  0
NHSTUB(open                                   ,0xfc0ba3ff) //  0
NHSTUB(OpenFastDir                            ,0xfc108131) //  0
NHSTUB(closedir                               ,0xfc1080f9) //  0
NHSTUB(get_fstype                             ,0xfc2a45d1) //  0
NHSTUB(qsort                                  ,0xfc2be953) //  0
NHSTUB(rand                                   ,0xfc0d32c3) //  0
NHSTUB(set_control_event                      ,0xfc2afe21) //  0
NHSTUB(srand                                  ,0xfc0d32bd) //  0
NHSTUB(stat                                   ,0xfc2a5219) //  0
NHSTUB(strcat                                 ,0xfc14a9c9) //  0
NHSTUB(strchr                                 ,0xfc0d3375) //  0
NHSTUB(strcmp                                 ,0xfc2b7de5) //  0
NHSTUB(strcpy                                 ,0xfc2b7e19) //  0
NHSTUB(strftime                               ,0xfc14a60d) //  0
NHSTUB(strlen                                 ,0xfc2b7e29) //  0
NHSTUB(strncmp                                ,0xfc14aa15) //  0
NHSTUB(strncpy                                ,0xfc2b7df5) //  0
NHSTUB(strrchr                                ,0xfc0d3387) //  0
NHSTUB(strtol                                 ,0xfc09b63b) //  0
NHSTUB(strtolx                                ,0xfc09b4f9) //  0
   DEF(task_CaptSeq                           ,0xfc0cdb9f) //  0
   DEF(task_DvlpSeqTask                       ,0xfc1aa7fb) //  0
   DEF(task_ExpDrv                            ,0xfc1e93c9) //  0
   DEF(task_FileWrite                         ,0xfc05509d) //  0
   DEF(task_InitFileModules                   ,0xfc088221) //  0
   DEF(task_MovieRecord                       ,0xfc1a5d09) //  0
   DEF(task_PhySw                             ,0xfc0601f5) //  0
   DEF(task_TricInitTask                      ,0xfc373d31) //  0
   DEF(hook_CreateTask                        ,0x010c51fc) //  0
NHSTUB(time                                   ,0x010c5ef1) //  0
NHSTUB(vsprintf                               ,0xfc09b4cb) //  0
NHSTUB(undisplaybusyonscreen                  ,0xfc14a27f) //  0
NHSTUB(EngDrvRead                             ,0xfc2b7cab) //  0
NHSTUB(PTM_GetCurrentItem                     ,0xfc2b064f) //  0
NHSTUB(DisableISDriveError                    ,0xfc3b8a9d) //  0
//NHSTUB(SetHPTimerAfterNow                   ,0xfc142331) //  0            == 0xfc142331
NHSTUB(SetEventFlag                           ,0x010c5569) //  0
NHSTUB(transfer_src_overlay                   ,0xfc143345) //  0
NHSTUB(bzero                                  ,0x010da260) //  0
NHSTUB(memset32                               ,0x010da264) //  0
NHSTUB(get_dial_hw_position                   ,0xfc32be43) //  0
NHSTUB(PT_MFOn                                ,0xfc20ee17) //  0
NHSTUB(PT_MFOff                               ,0xfc20ee47) //  0
NHSTUB(GetAdChValue                           ,0xfc0c33c7) //  0
NHSTUB(EnableHDMIPower                        ,0xfc099f1b) //  0
NHSTUB(DisableHDMIPower                       ,0xfc099f51) //  0
NHSTUB(SetVideoOutType                        ,0xfc3e0a95) //  0
NHSTUB(GetVideoOutType                        ,0xfc3e0a05) //  0
