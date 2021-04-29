// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   Main firmware start: 0xfc020000
//   DRYOS R55 (DRYOS version 2.3, release #0055+p6) @ 0xfc5e2e94 ref @ 0xfc03d55c
//   Firmware Ver GM1.21A   // Found @ 0xfc1fcf10, "GM1.21A" @ 0xfc1fcf1d

// Values for makefile.inc
//   PLATFORMOSVER = 55
//   DIGIC = 60
//   MEMISOSTART = 0x3a7cc8
//   MEMBASEADDR = 0x8000
//   ARAM_HEAP_START = 0x0074e000#  Found @0xfc18e230
//   ARAM_HEAP_SIZE = 0x00022000#  Found @0xfc18e20a

// Detected address ranges:
// ROM      0xfc000000 - 0xfe000000 (33554432 bytes)
// RAM code 0x010e1000 - 0x011074ac copied from 0xfcc988a0 ( 156844 bytes)
// TCM code 0xbfe10800 - 0xbfe17391 copied from 0xfccbed4c (  27537 bytes)
// RAM data 0x00008000 - 0x00050770 copied from 0xfcc50130 ( 296816 bytes)
// EVEC     0x00000000 - 0x00000038 copied from 0xfc062ffc (     56 bytes)

// Zico Xtensa blobs:
// zico_0 0xbff20000 - 0xbff277b8 copied from 0xfca003b8 (  30648 bytes)
// zico_1 0xbff00000 - 0xbff04ad0 copied from 0xfca07b78 (  19152 bytes)
// zico_2 0x80a00000 - 0x80b06220 copied from 0xfca0c650 (1073696 bytes)

// Omar ARM blobs:
// omar_0 0xdff00000 - 0xdff00e84 copied from 0xfc5e30bc (   3716 bytes)
// omar_1 0x40780000 - 0x40794010 copied from 0xfc5e3f40 (  81936 bytes)

// Found DryOS versions:
// 0xfc5e2e94 main  "DRYOS version 2.3, release #0055+p6"
// 0xfc5f683c other "DRYOS version 2.3, release #0055+p6"
// 0xfca0d680 other "DRYOS version 2.3, release #0055+p6"

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#define CAM_ILC 1 // Camera is interchangeable lens
//#define CAM_HAS_WIFI 1 // Firmware has wifi support (only define if camera has hardware)
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xfc1537cc
//#undef CAM_HAS_ND_FILTER // Camera does not have an ND filter
// Camera has an iris (CAM_HAS_IRIS_DIAPHRAGM default)

// physw_event_table 0xfc5fa014 Found @0xfc074ec0
// Values below go in 'platform_kbd.h':
//#define SD_READONLY_FLAG    0x20000000 // Found @0xfc5fa0ec, levent 0x20a
//#define SD_READONLY_IDX     1
//#define USB_MASK            0x10000000 // Found @0xfc5fa154, levent 0x202
//#define USB_IDX             2
//#define BATTCOVER_FLAG      0x01000000 // Found @0xfc5fa074, levent 0x205
//#define BATTCOVER_IDX       0
//#define HOTSHOE_FLAG        0x00010000 // Found @0xfc5fa10c, levent 0x204
//#define HOTSHOE_IDX         2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
// WARNING: Key name / function may vary! Values for unknown DryOS versions should not be trusted!
//KeyMap keymap[] = {
//    { 0, KEY_POWER           ,0x00000001 }, // Found @0xfc5fa014, levent 0x100 (uses inverted logic in physw_status)
//    { 0, KEY_PLAYBACK        ,0x00000002 }, // Found @0xfc5fa01c, levent 0x101 (uses inverted logic in physw_status)
//    { 1, KEY_SHOOT_FULL      ,0x00040001 }, // Found @0xfc5fa07c, levent 0x01
//    { 1, KEY_SHOOT_HALF      ,0x00040000 }, // Found @0xfc5fa0dc, levent 0x00
//    { 1, KEY_SHOOT_FULL_ONLY ,0x00000001 }, // Found @0xfc5fa07c, levent 0x01
//    { 1, KEY_VIDEO           ,0x00000008 }, // Found @0xfc5fa084, levent 0x02
//    { 1, KEY_MENU            ,0x00000010 }, // Found @0xfc5fa08c, levent 0x14
//    { 1, KEY_UP              ,0x00000020 }, // Found @0xfc5fa094, levent 0x06
//    { 1, KEY_DOWN            ,0x00000040 }, // Found @0xfc5fa09c, levent 0x07
//    { 1, KEY_RIGHT           ,0x00000080 }, // Found @0xfc5fa0a4, levent 0x09
//    { 1, KEY_LEFT            ,0x00000100 }, // Found @0xfc5fa0ac, levent 0x08
//    { 1, KEY_SET             ,0x00000200 }, // Found @0xfc5fa0b4, levent 0x0a
//    { 1, KEY_DISPLAY         ,0x00000400 }, // Found @0xfc5fa0bc, levent 0x0d
//    { 0, 0, 0 }
//};

// canon_mode_list 0xfc747b40 Found @0xfc0e15b0
// Check modemap values from 'platform/CAMERA/shooting.c':
// 33289  0x8209 In firmware but not in current modemap
//  8778  0x224a In firmware but not in current modemap
//  8777  0x2249 In firmware but not in current modemap
//  8776  0x2248 In firmware but not in current modemap
// 16423  0x4027 In firmware but not in current modemap
// 16424  0x4028 In firmware but not in current modemap
// 16405  0x4015 In firmware but not in current modemap
// 16904  0x4208 In firmware but not in current modemap
//  2649  0x0a59 In firmware but not in current modemap
//  4172  0x104c In firmware but not in current modemap
// Current modemap entry not found in firmware - MODE_VIDEO_STAR_TIME_LAPSE 16459
// Current modemap entry not found in firmware - MODE_VIDEO_IFRAME_MOVIE   2650
// Current modemap entry not found in firmware - MODE_CREATIVE_EFFECT     33299
// Current modemap entry not found in firmware - MODE_FIREWORK            16416
// Current modemap entry not found in firmware - MODE_SNOW                16414
// Current modemap entry not found in firmware - MODE_UNDERWATER          16929
// Current modemap entry not found in firmware - MODE_STAR_TRAILS         16454
// Current modemap entry not found in firmware - MODE_STAR_NIGHTSCAPE     16453
// Current modemap entry not found in firmware - MODE_STAR_PORTRAIT       16452
// Current modemap entry not found in firmware - MODE_WINK_SELF_TIMER     16950
// Current modemap entry not found in firmware - MODE_SMART_SHUTTER       16949
// Current modemap entry not found in firmware - MODE_FACE_SELF_TIMER     16948
// Current modemap entry not found in firmware - MODE_POSTER_EFFECT        8755
// Current modemap entry not found in firmware - MODE_SUPER_VIVID          8754
// Current modemap entry not found in firmware - MODE_MONOCHROME           8767
// Current modemap entry not found in firmware - MODE_BACKGROUND_DEFOCUS   8764
// Current modemap entry not found in firmware - MODE_NOSTALGIC            8753

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
// EXMEM_PHOTO_IN_MOVIE 32

// Values below can be overridden in 'stubs_min.S':
DEF(ctypes                            ,0xfc5e2f3c) // Found @0xfc03c888
DEF(physw_run                         ,0x000082cc) // Found @0xfc083bc6
DEF(physw_sleep_delay                 ,0x000082d4) // (0x82cc+0x8) Found @0xfc083bca
DEF(physw_status                      ,0x000520c8) // Found @0xfc083eb4
DEF(fileio_semaphore                  ,0x000125d0) // Found @0xfc06e1f2
DEF(levent_table                      ,0xfc638b14) // Found @0xfc113248
DEF(FlashParamsTable                  ,0xfc747e90) // Found @0xfc0e15c4
DEF(playrec_mode                      ,0x0000b474) // (0xb470+0x4) Found @0xfc325d32
DEF(jpeg_count_str                    ,0x0016cc9c) // Found @0xfc1a0b68
//DEF(zoom_busy                         ,0x00000000), ** != ** stubs_min = 0x00000001 (1)
//DEF(focus_busy                        ,0x00000000), ** != ** stubs_min = 0x00000001 (1)
DEF(imager_active                     ,0x000086c4) // (0x86c0+0x4) Found @0xfc131b2c
DEF(canon_menu_active                 ,0x0000c1ac) // (0xc1a8+0x4) Found @0xfc32df6e
DEF(file_counter_var                  ,0x00012484) // Found @0xfc2571f4
DEF(cameracon_state                   ,0x00008b14) // (0x8b04+0x10) Found @0xfc32c4c4
DEF(_nrflag                           ,0x000287dc) // (0x287d4+0x8) Found @0xfc3f577e
DEF(av_override_semaphore             ,0x0003deac) // Found @0xfc44c860
DEF(active_bitmap_buffer              ,0x0000c170) // (0xc13c+0x34) Found @0xfc37fa10
DEF(displaytype                       ,0x00009990) // (0x9950+0x40) Found @0xfc35df72
DEF(bitmap_buffer                     ,0x0000c174) // (0xc13c+0x38) Found @0xfc37fa16
DEF(palette_control                   ,0x000136c8) // Found @0xfc354a22
DEF(palette_buffer_ptr                ,0x000136e0) // (0x136c8+0x18) Found @0xfc354a3e
DEF(active_palette_buffer             ,0x000136d8) // (0x136c8+0x10) Found @0xfc354a26
DEF(live_free_cluster_count           ,0x00178558) // (0x178520+0x38) Found @0xfc067480
DEF_CONST(uiprop_count                      ,0x000000c7) // Found @0xfc277b36
DEF(exmem_alloc_table                 ,0x0005a474) // Found @0xfc07882a
DEF(exmem_types_table                 ,0xfcc53688) // Found @0xfc07882e
DEF_CONST(exmem_type_count                  ,0x00000021) // Found @0xfcc53688

//NHSTUB(DeleteDirectory_Fut                  ,0x00000000) //  0        *** != 0xfc3742b5
//NHSTUB(DeleteFile_Fut                       ,0x00000000) //  0        *** != 0xfc37426b
//NHSTUB(EnterToCompensationEVF               ,0x00000000) //  0        *** != 0xfc0aa66b
//NHSTUB(ExitFromCompensationEVF              ,0x00000000) //  0        *** != 0xfc0aa6a7
//NHSTUB(ExpCtrlTool_StartContiAE             ,0x00000000) //  0        *** != 0xfc2aaba5
//NHSTUB(ExpCtrlTool_StopContiAE              ,0x00000000) //  0        *** != 0xfc2aadf9
//NHSTUB(Feof_Fut                             ,0x00000000) //  0        *** != 0xfc374459
//NHSTUB(Fflush_Fut                           ,0x00000000) //  0        *** != 0xfc374481
//NHSTUB(GetDrive_TotalClusters               ,0x00000000) //  0        *** != 0xfc06bf33
//NHSTUB(GetFocusLensSubjectDistanceFromLens  ,0x00000000) //  0        *** != 0xfc35ff47
//NHSTUB(GetImageFolder                       ,0x00000000) //  0        *** != 0xfc303c95
//NHSTUB(MakeSDCardBootable                   ,0x00000000) //  0        *** != 0xfc37a6ed
//NHSTUB(MoveFocusLensToDistance              ,0x00000000) //  0        *** != 0xfc44bbcd
//NHSTUB(PutInNdFilter                        ,0x00000000) //  0        *** != 0xfc44d271
//NHSTUB(PutOutNdFilter                       ,0x00000000) //  0        *** != 0xfc44d28b
//NHSTUB(RenameFile_Fut                       ,0x00000000) //  0        *** != 0xfc374209
//NHSTUB(Restart                              ,0x00000000) //  0        *** != 0xfc1312cd
//NHSTUB(ScreenUnlock                         ,0x00000000) //  0        *** != 0xfc37f9b9
//NHSTUB(SetFileAttributes                    ,0x00000000) //  0        *** != 0xfc37ab35
//NHSTUB(SetFileTimeStamp                     ,0x00000000) //  0        *** != 0xfc37aaed
//NHSTUB(SetParameterData                     ,0x00000000) //  0        *** != 0xfc2783f1
//NHSTUB(WriteSDCard                          ,0x00000000) //  0        *** != 0xfcc9a3a3
//NHSTUB(apex2us                              ,0x00000000) //  0        *** != 0xfc3f457f
//NHSTUB(displaybusyonscreen                  ,0x00000000) //  0        *** != 0xfc3331c7
//NHSTUB(err_init_task                        ,0x00000000) //  0        *** != 0xfc06316b
//NHSTUB(realloc                              ,0x00000000) //  0        *** != 0xfc4fa339
//NHSTUB(reboot_fw_update                     ,0x00000000) //  0        *** != 0xfc4504e1
//NHSTUB(undisplaybusyonscreen                ,0x00000000) //  0        *** != 0xfc33325d
//NHSTUB(CancelHPTimer                        ,0x00000000) //  0        *** != 0xfc1fcc29
//NHSTUB(SetHPTimerAfterNow                   ,0x00000000) //  0        *** != 0xfc1fcb91

NHSTUB(AllocateUncacheableMemory              ,0xfc15379d) //  0
NHSTUB(Close                                  ,0xfc37a8a1) //  0
//NHSTUB(CreateBinarySemaphore                ,0xbfe1530d) //  0            == 0xbfe1530d
NHSTUB(CreateTask                             ,0xbfe14a31) //  0
NHSTUB(DebugAssert                            ,0x010e1001) //  0
NHSTUB(DoAELock                               ,0xfc0aa83f) //  0
NHSTUB(DoAFLock                               ,0xfc0aa4a1) //  0
NHSTUB2(ExecuteEventProcedure                  ,0xfc327d55) //  0
NHSTUB(ExitTask                               ,0xbfe14c13) //  0
NHSTUB(Fclose_Fut                             ,0xfc374317) //  0
NHSTUB(Fgets_Fut                              ,0xfc3743f5) //  0
NHSTUB(Fopen_Fut                              ,0xfc3742ef) //  0
NHSTUB(Fread_Fut                              ,0xfc374389) //  0
NHSTUB(FreeUncacheableMemory                  ,0xfc1537c9) //  0
NHSTUB(Fseek_Fut                              ,0xfc374427) //  0
NHSTUB(Fwrite_Fut                             ,0xfc3743bf) //  0
NHSTUB(GetBatteryTemperature                  ,0xfc1f6175) //  0
NHSTUB(GetCCDTemperature                      ,0xfc1f6119) //  0
NHSTUB(GetCurrentAvValue                      ,0xfc318edb) //  0
NHSTUB(GetCurrentShutterSpeed                 ,0xfc3603cf) //  0
NHSTUB(GetUsableMaxAv                         ,0xfc181389) //  0
NHSTUB(GetUsableMinAv                         ,0xfc181377) //  0
NHSTUB(get_current_deltasv                    ,0xfc20cf47) //  0
NHSTUB(GetCurrentDriveBaseSvValue             ,0xfc306a47) //  0
NHSTUB(GetDrive_ClusterSize                   ,0xfc379e7f) //  0
NHSTUB(GetFocusLensSubjectDistance            ,0xfc35fdc7) //  0
NHSTUB(GetKbdState                            ,0xfc075053) //  0
NHSTUB(GetMemInfo                             ,0xfc5a18b5) //  0
NHSTUB(GetOpticalTemperature                  ,0xfc1f61cf) //  0
NHSTUB(GetParameterData                       ,0xfc278465) //  0
NHSTUB(GetPropertyCase                        ,0xfc373839) //  0
NHSTUB(GetSystemTime                          ,0xfc450dc1) //  0
NHSTUB(GetVRAMHPixelsSize                     ,0xfc133e8d) //  0
NHSTUB(GetVRAMVPixelsSize                     ,0xfc133e95) //  0
NHSTUB(GetZoomLensCurrentPoint                ,0xfc186307) //  0
NHSTUB(GetZoomLensCurrentPosition             ,0xfc1862bb) //  0
NHSTUB(GiveSemaphore                          ,0xbfe15479) //  0
NHSTUB(IsStrobeChargeCompleted                ,0xfc4f3419) //  0
NHSTUB(LEDDrive                               ,0xfc189091) //  0
NHSTUB(LocalTime                              ,0x010e1515) //  0
NHSTUB(LockMainPower                          ,0xfc1fd117) //  0
NHSTUB(MakeDirectory_Fut                      ,0xfc37ab8b) //  0
NHSTUB(MoveIrisWithAv                         ,0xfc44c84d) //  0
NHSTUB(Open                                   ,0xfc37a81d) //  0
NHSTUB(PB2Rec                                 ,0xfc32a9d1) //  0
NHSTUB(PT_PlaySound                           ,0xfc3779db) //  0
NHSTUB(PostLogicalEventForNotPowerType        ,0xfc37eba1) //  0
NHSTUB(PostLogicalEventToUI                   ,0xfc37ebd5) //  0
NHSTUB(Read                                   ,0xfc1ee5ed) //  0
NHSTUB(ReadFastDir                            ,0xfc11c72d) //  0
NHSTUB(Rec2PB                                 ,0xfc32aa17) //  0
NHSTUB(ScreenLock                             ,0xfc37f97b) //  0
NHSTUB(SetAE_ShutterSpeed                     ,0xfc5a5529) //  0
NHSTUB(SetAutoShutdownTime                    ,0xfc1fd163) //  0
NHSTUB(SetCurrentCaptureModeType              ,0xfc36cd65) //  0
NHSTUB(SetDate                                ,0xfc5a69e1) //  0
NHSTUB(SetLogicalEventActive                  ,0xfc36370d) //  0
NHSTUB(SetPropertyCase                        ,0xfc3736e7) //  0
NHSTUB(SetScriptMode                          ,0xfc363745) //  0
NHSTUB(SleepTask                              ,0xbfe14999) //  0
NHSTUB(TakeSemaphore                          ,0xbfe15401) //  0
NHSTUB(TurnOffBackLight                       ,0xfc35ea21) //  0
NHSTUB(TurnOnBackLight                        ,0xfc35e9c7) //  0
NHSTUB(TurnOnDisplay                          ,0xfc177dfd) //  0
NHSTUB(TurnOffDisplay                         ,0xfc177e0f) //  0
NHSTUB(UnlockAE                               ,0xfc0aa85d) //  0
NHSTUB(UnlockAF                               ,0xfc0aa4d1) //  0
NHSTUB(UnlockMainPower                        ,0xfc1fd0af) //  0
NHSTUB(VbattGet                               ,0xfc130cdb) //  0
NHSTUB(Write                                  ,0xfc37a8d9) //  0
NHSTUB(_log                                   ,0x01102bc8) //  0
NHSTUB(_log10                                 ,0x011030e8) //  0
NHSTUB(_pow                                   ,0x01103250) //  0
NHSTUB(_sqrt                                  ,0x011052d0) //  0
NHSTUB(add_ptp_handler                        ,0xfc16bacf) //  0
NHSTUB(close                                  ,0xfc1ee4e7) //  0
NHSTUB(exmem_alloc                            ,0xfc078d63) //  0
NHSTUB(exmem_ualloc                           ,0xfc078c6d) //  0
NHSTUB(exmem_ufree                            ,0xfc078d27) //  0
NHSTUB(free                                   ,0xfc38022b) //  0
NHSTUB(kbd_p1_f                               ,0xfc083ead) //  0
NHSTUB(kbd_p1_f_cont                          ,0xfc083eb5) //  0
NHSTUB(kbd_p2_f                               ,0xfc083915) //  0
NHSTUB(kbd_read_keys                          ,0xfc083e77) //  0
NHSTUB(kbd_read_keys_r2                       ,0xfc074eb7) //  0
NHSTUB(lseek                                  ,0xfc37a9fd) //  0
NHSTUB(malloc                                 ,0xfc3801f5) //  0
NHSTUB(memcmp                                 ,0xfc380479) //  0
NHSTUB(memcpy                                 ,0xfc2003a5) //  0
NHSTUB(memset                                 ,0xfc115ad5) //  0
NHSTUB(mktime_ext                             ,0xfc1fffb5) //  0
NHSTUB(open                                   ,0xfc1ee477) //  0
NHSTUB(OpenFastDir                            ,0xfc11c68d) //  0
NHSTUB(closedir                               ,0xfc11c655) //  0
NHSTUB(get_fstype                             ,0xfc379e19) //  0
NHSTUB(qsort                                  ,0xfc3c8a4d) //  0
NHSTUB(rand                                   ,0xfc0fc1cf) //  0
NHSTUB(set_control_event                      ,0xfc363481) //  0
NHSTUB(srand                                  ,0xfc0fc1c9) //  0
NHSTUB(stat                                   ,0xfc37aa35) //  0
NHSTUB(strcat                                 ,0xfc38025d) //  0
NHSTUB(strchr                                 ,0xfc20048d) //  0
NHSTUB(strcmp                                 ,0xfc3803a5) //  0
NHSTUB(strcpy                                 ,0xfc38027f) //  0
NHSTUB(strftime                               ,0xfc1fffe5) //  0
NHSTUB(strlen                                 ,0xfc380403) //  0
NHSTUB(strncmp                                ,0xfc200463) //  0
NHSTUB(strncpy                                ,0xfc37c29d) //  0
NHSTUB(strrchr                                ,0xfc14c325) //  0
NHSTUB(strtol                                 ,0xfc14c317) //  0
//NHSTUB(strtolx                              ,0xfc14c1d5) //  0            == 0xfc14c1d5
   DEF(task_CaptSeq                           ,0xfc0bd907) //  0
   DEF(task_DvlpSeqTask                       ,0xfc110b67) //  0
   DEF(task_ExpDrv                            ,0xfc2bc871) //  0
   DEF(task_FileWrite                         ,0xfc068b89) //  0
   DEF(task_InitFileModules                   ,0xfc0f79a1) //  0
   DEF(task_MovieRecord                       ,0xfc142bcd) //  0
   DEF(task_PhySw                             ,0xfc083bc5) //  0
   DEF(task_TouchPanel                        ,0xfc13c205) //  0
   DEF(task_TricInitTask                      ,0xfc554551) //  0
   DEF(hook_CreateTask                        ,0xbfe14a30) //  0
NHSTUB(time                                   ,0x010e11e3) //  0
NHSTUB(vsprintf                               ,0xfc0d7383) //  0
NHSTUB(EngDrvRead                             ,0xfc3802d1) //  0
NHSTUB(PTM_GetCurrentItem                     ,0xfc36e907) //  0
NHSTUB(DisableISDriveError                    ,0xfc44dded) //  0
NHSTUB(SetEventFlag                           ,0xbfe14e43) //  0
NHSTUB(transfer_src_overlay                   ,0xfc37f043) //  0
NHSTUB(bzero                                  ,0x01100410) //  0
NHSTUB(memset32                               ,0x01100414) //  0
NHSTUB(get_dial_hw_position                   ,0xfc1c19c5) //  0
NHSTUB(PT_MFOn                                ,0xfc0ab61d) //  0
NHSTUB(PT_MFOff                               ,0xfc0ab651) //  0
NHSTUB(GetAdChValue                           ,0xfc1f35ef) //  0
NHSTUB(EnableHDMIPower                        ,0xfc13b4cd) //  0
NHSTUB(DisableHDMIPower                       ,0xfc13b4fd) //  0
NHSTUB(SetVideoOutType                        ,0xfc5a5abd) //  0
NHSTUB(GetVideoOutType                        ,0xfc5a5a29) //  0
NHSTUB(IsWirelessConnect                      ,0xfc357cc7) //  0
