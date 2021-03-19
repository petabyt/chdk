// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R55 (DRYOS version 2.3, release #0055+p6)
//   Firmware Ver GM1.00A   // Found @ 0xff89e7a0, "GM1.00A" @ 0xff89e7ad
//   Firmware build timestamp: Dec  3 2014 10:13:23
//   Canon IXUS 170

// Values for makefile.inc
//   DIGIC = 41# DIGIC 4+
//   PLATFORMOSVER = 55
//   PLATFORMID = 12972# (0x32ac) Found @ 0xffff0040
//   MAXRAMADDR = 0x07ffffff
//   MEMISOSTART = 0x001929d8
//   KEYSYS = d4g# Found @ 0xff812968
//   NEED_ENCODED_DISKBOOT = 13# Found @ 0xff812978
//   ARAM_HEAP_START = 0x60e000# Found @ 0xff9a9078
//   ARAM_HEAP_SIZE  = 0x22000# Found @ 0xff9a9038

// Detected address ranges:
// ROM      0xff810000 - 0xffffffff (8323072 bytes)
// RAM code 0x006b1000 - 0x006be858 copied from 0xffcee1fc (  55384 bytes)
// RAM data 0x00001900 - 0x0000fc7c copied from 0xffcdfe80 (  58236 bytes)

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NHSTUB(DeleteFile_Fut                       ,0xff8274a4) //  1 90%        == 0xff8274a4
//NHSTUB(GetFocusLensSubjectDistanceFromLens  ,0xff98e69c) //  3 90%        == 0xff98e69c
// ERROR: MakeDirectory_Fut is not found.                  //--- ---    *** != 0xff827fb4
// ERROR: RefreshPhysicalScreen is not found.              //--- ---    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ffad6950 -> ffca8a0c
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00010a44) // Found @0xff82dc98
DEF(physw_run                               ,0x00001c94) // Found @0xff82d7c8
DEF(physw_sleep_delay                       ,0x00001c9c) // Found @0xff82d7c8
DEF(levent_table                            ,0xffbf83d8) // Found @0xffbf83d8
DEF(FlashParamsTable                        ,0xffca8d44) // Found @0xffca8d44
DEF(movie_status                            ,0x000072c4) // Found @0xff998fe0
DEF(video_compression_rate                  ,0x00007274) // Found @0xff999ca8
DEF(full_screen_refresh                     ,0x00007dfc) // Found @0xff9bc8ac
DEF(canon_menu_active                       ,0x00003ba8) // Found @0xff8a6afc
DEF(canon_shoot_menu_active                 ,0x000094e5) // Found @0xffa18d64
DEF(playrec_mode                            ,0x00003698) // Found @0xff89506c
DEF(zoom_status                             ,0x00005efc) // Found @0xff937da0
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 2 int value(s), the first is the zoom focus length.
// there are 101 entries in the table - set NUM_FL to 101
DEF(focus_len_table                         ,0xffffae7c) // Found @0xffffae7c
//DEF(zoom_busy                               ,0x00007018) // Found @0xff990c98,          stubs_min = 0x00007018 (0x00007018)
//DEF(focus_busy                              ,0x00006ee0) // Found @0xff98d01c,          stubs_min = 0x00006ee0 (0x00006ee0)
// Palette colour tables  found @ 0xffbfc0a8
// Camera appears to have only 1 RAW buffer @ 0x43737e20 (Found @0xffb6b654)
DEF(fileio_semaphore                        ,0x00001d0c) // Found @0xff83008c
DEF(exmem_alloc_table                       ,0x00011d7c) // Found @0xff834a10
DEF(exmem_types_table                       ,0xffce0324) // Found @0x00001da4
DEF_CONST(exmem_type_count                  ,0x0000001e)
DEF(imager_active                           ,0x0000203c) // Found @0xff84b064 (0x2038 + 4)
DEF_CONST(uiprop_count                      ,0x000000c6) // Found @0xff9b276c

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x40711000; }             // Found @0xff86613c
//void *vid_get_viewport_fb()      { return (void*)0x40866b80; }             // Found @0xffb69c8c
DEF(jpeg_count_str                          ,0x000e1d78) // Found @0xffa03dfc
//char *camera_jpeg_count_str()    { return (char*)0x000e1d78; }             // Found @0xffa03dfc
//int get_flash_params_count(void) { return 0xd4; }                          // Found @0xff9b31f0

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x02000000 // Found @0xffbb0c20, levent 0x20a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x10000000 // Found @0xffbb0c30, levent 0x202
//#define USB_IDX             2
//#define BATTCOVER_FLAG      0x04000000 // Found @0xffbb0c28, levent 0x205
//#define BATTCOVER_IDX       2
//#define ANALOG_AV_FLAG      0x00002000 // Found @0xffbb0bc8, levent 0x200 (non-inverted logic)
//#define ANALOG_AV_IDX       0

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_VIDEO           ,0x00000002 }, // Found @0xffbb0b88, levent 0x02
//    { 0, KEY_POWER           ,0x00000020 }, // Found @0xffbb0b90, levent 0x100
//    { 0, KEY_PLAYBACK        ,0x00000040 }, // Found @0xffbb0b98, levent 0x101
//    { 0, KEY_SET             ,0x00000100 }, // Found @0xffbb0ba0, levent 0x0a
//    { 0, KEY_UP              ,0x00000200 }, // Found @0xffbb0ba8, levent 0x06
//    { 0, KEY_RIGHT           ,0x00000400 }, // Found @0xffbb0bb0, levent 0x09
//    { 0, KEY_DOWN            ,0x00000800 }, // Found @0xffbb0bb8, levent 0x07
//    { 0, KEY_LEFT            ,0x00001000 }, // Found @0xffbb0bc0, levent 0x08
//    { 0, KEY_HELP            ,0x00004000 }, // Found @0xffbb0bd0, levent 0x0d
//    { 0, KEY_MENU            ,0x00008000 }, // Found @0xffbb0bd8, levent 0x14
//    { 2, KEY_SHOOT_FULL      ,0x00000003 }, // Found @0xffbb0be8, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000002 }, // Found @0xffbb0be8, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00000001 }, // Found @0xffbb0be0, levent 0x00
//    { 2, KEY_ZOOM_OUT        ,0x00000010 }, // Found @0xffbb0bf0, levent 0x04
//    { 2, KEY_ZOOM_IN         ,0x00000020 }, // Found @0xffbb0bf8, levent 0x03
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#define CAM_RAW_ROWPIX    5248 // Found @0xff969f78
//#define CAM_RAW_ROWS      3920 // Found @0xff969f80
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff826238
//#define CAM_DATE_FOLDER_NAMING 0x080 // Found @0xffaa47f0 (pass as 3rd param to GetImageFolder)
//#define PARAM_CAMERA_NAME 3 // Found @0xffca79f0
//#define CAM_3ARG_DebugAssert 1

// Below goes in 'filewrite.c' or 'platform_camera.h':
//#define MAX_CHUNKS_FOR_FWT 7 // Found @0xffab1e5c

// Known propcases
// //      PROPCASE_AFSTEP 13
// #define PROPCASE_FOCUS_STATE 18
// #define PROPCASE_AV 23
// #define PROPCASE_BV 34
// //      PROPCASE_DELTA_DIGITALGAIN 77
// #define PROPCASE_DELTA_SV 79
// //      PROPCASE_DELTA_ND 80
// #define PROPCASE_EV_CORRECTION_2 210
// #define PROPCASE_ORIENTATION_SENSOR 222
// #define PROPCASE_SV_MARKET 249
// //      PROPCASE_SVFIX 250
// #define PROPCASE_TV 265
// Guessed propset: 6

// Misc stuff
DEF(ctypes, 0xffbadbc4)

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
// EXMEM_LENS_FIRMUP    16
// EXMEM_LENS_COMPENSATION 17
// EXMEM_FILESTORE      18
// EXMEM_MOVIE_REC      19
// EXMEM_MOVIE_PLY      20
// EXMEM_WIFI_RESIZE    21
// EXMEM_PCEVF          22
// EXMEM_WIDE           23
// EXMEM_NARROW         24
// EXMEM_AUTO_GIS_MODE  25
// EXMEM_NP_GIS_MODE    26
// EXMEM_TRIPODHDR_MODE 27
// EXMEM_HSHQ_MODE      28
// EXMEM_CRAW_REC       29

// ISR flag: 0x1944, pointer to current task's control block: 0x1940
// pointer to TCB area: 0x19c4, found @ 0xffcef7a4

// LED table init @ 0xff945d20
// LED #1: 0xc022d200 (#98 in GPIO table), offset 0x98
// LED #2: 0xc022d1fc (#97 in GPIO table), offset 0x8
// GPIO table @ 0xffbb061c

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NHSTUB(AllocateUncacheableMemory              ,0xff8261f4) //112
NHSTUB(Close                                  ,0xff827b18) //120
NHSTUB(CreateBinarySemaphore                  ,0xff8262cc) //115
NHSTUB(CreateTask                             ,0xff824a30) //120
NHSTUB(DebugAssert                            ,0xff824ddc) //107
NHSTUB(DeleteDirectory_Fut                    ,0xff827518) //116
NHSTUB(DoAELock                               ,0xff8336d4) //120
NHSTUB(DoAFLock                               ,0xff833398) //120
NHSTUB(EnterToCompensationEVF                 ,0xff833638) //104
NHSTUB(ExecuteEventProcedure                  ,0xff8354f4) //104
NHSTUB(ExitFromCompensationEVF                ,0xff833680) //104
NHSTUB(ExitTask                               ,0xff824d78) //120
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff8439e8) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff843b80) //104
NHSTUB(Fclose_Fut                             ,0xff8275b0) //120
NHSTUB(Feof_Fut                               ,0xff82779c) //  1
NHSTUB(Fflush_Fut                             ,0xff8277d8) //  1
NHSTUB(Fgets_Fut                              ,0xff827704) //  6
NHSTUB(Fopen_Fut                              ,0xff827570) //120
NHSTUB(Fread_Fut                              ,0xff82765c) //120
NHSTUB(FreeUncacheableMemory                  ,0xff826230) //112
NHSTUB(Fseek_Fut                              ,0xff827750) //120
NHSTUB(Fwrite_Fut                             ,0xff8276b0) //120
NHSTUB(GetBatteryTemperature                  ,0xff86ef40) //102
NHSTUB(GetCCDTemperature                      ,0xff86eec8) //102
NHSTUB(GetCurrentAvValue                      ,0xff887c30) //120
NHSTUB(GetCurrentShutterSpeed                 ,0xff8c640c) //120
NHSTUB(GetUsableMaxAv                         ,0xff96a780) //120
NHSTUB(GetUsableMinAv                         ,0xff96a764) //120
NHSTUB(GetDrive_ClusterSize                   ,0xff831724) //122
NHSTUB(GetDrive_FreeClusters                  ,0xff831f30) //119
NHSTUB(GetDrive_TotalClusters                 ,0xff831f04) //122
NHSTUB(GetFocusLensSubjectDistance            ,0xff98e2b8) //102
NHSTUB(GetImageFolder                         ,0xff972100) //122
NHSTUB(GetKbdState                            ,0xff86b770) //109
NHSTUB(GetMemInfo                             ,0xff823400) //115
NHSTUB(GetOpticalTemperature                  ,0xff86efb8) //120
NHSTUB(GetParameterData                       ,0xff9b31ac) //101
NHSTUB(GetPropertyCase                        ,0xff8a00b0) //101
NHSTUB(GetSystemTime                          ,0xffad4554) //120
NHSTUB(GetVRAMHPixelsSize                     ,0xff84fc04) //120
NHSTUB(GetVRAMVPixelsSize                     ,0xff84fc10) //120
NHSTUB(GetZoomLensCurrentPoint                ,0xff99111c) //120
NHSTUB(GetZoomLensCurrentPosition             ,0xffac48e8) //102
NHSTUB(GiveSemaphore                          ,0xff82654c) //120
NHSTUB(IsStrobeChargeCompleted                ,0xff8e5084) //102
NHSTUB(LEDDrive                               ,0xff99aa08) //120
NHSTUB(LocalTime                              ,0xff83e164) //115
NHSTUB(LockMainPower                          ,0xff8a29fc) //120
NHSTUB(MakeSDCardBootable                     ,0xff8322f8) //105
NHSTUB(MoveFocusLensToDistance                ,0xffb6d854) //102
NHSTUB(MoveIrisWithAv                         ,0xfface8f4) //120
NHSTUB(MoveZoomLensWithPoint                  ,0xffacf250) //120
NHSTUB(MoveOpticalZoomAt                      ,0xff832e24) //109
NHSTUB(Open                                   ,0xff827a50) //120
NHSTUB(PB2Rec                                 ,0xff85a2fc) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff99bb88) //102
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff99bb58) //102
NHSTUB(PT_PlaySound                           ,0xff8b0380) //122
NHSTUB(PostLogicalEventForNotPowerType        ,0xff8a1f48) //120
NHSTUB(PostLogicalEventToUI                   ,0xff8a1f94) //120
NHSTUB(PutInNdFilter                          ,0xffacf008) //102
NHSTUB(PutOutNdFilter                         ,0xffacf02c) //102
NHSTUB(Read                                   ,0xff823ebc) //120
NHSTUB(ReadFastDir                            ,0xffab33b0) //115
NHSTUB(Rec2PB                                 ,0xff8589e4) //104
NHSTUB(RenameFile_Fut                         ,0xff827410) //116
NHSTUB(Restart                                ,0xff8385a0) //122
NHSTUB(ScreenLock                             ,0xff8a6424) //117
NHSTUB(ScreenUnlock                           ,0xff8a6480) //117
NHSTUB(SetAE_ShutterSpeed                     ,0xffb68ac8) //102
NHSTUB(SetAutoShutdownTime                    ,0xff8a2a70) //120
NHSTUB(SetCurrentCaptureModeType              ,0xff8ad08c) //120
NHSTUB(SetDate                                ,0xffb6a940) //120
NHSTUB(SetFileAttributes                      ,0xff827f1c) //  6
NHSTUB(SetFileTimeStamp                       ,0xff827ea4) //  6
NHSTUB(SetLogicalEventActive                  ,0xff8a25f0) //120
NHSTUB(SetParameterData                       ,0xff9b3110) //101
NHSTUB(SetPropertyCase                        ,0xff89fed8) //101
NHSTUB(SetScriptMode                          ,0xff8a2644) //120
NHSTUB(SleepTask                              ,0xff82a760) //120
NHSTUB(TakeSemaphore                          ,0xff826474) //120
NHSTUB(TurnOffBackLight                       ,0xff8afa88) //104
NHSTUB(TurnOnBackLight                        ,0xff8afa70) //104
NHSTUB(TurnOnDisplay                          ,0xff86651c) //120
NHSTUB(TurnOffDisplay                         ,0xff86652c) //120
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff9d0860) //120
NHSTUB(UnlockAE                               ,0xff8336f8) //120
NHSTUB(UnlockAF                               ,0xff8333c8) //120
NHSTUB(UnlockMainPower                        ,0xff8a2954) //120
NHSTUB(VbattGet                               ,0xff82cab0) //120
NHSTUB(Write                                  ,0xff827b6c) //120
NHSTUB(WriteSDCard                            ,0xff881984) //108
NHSTUB(_log                                   ,0x006bb388) //111
//NHSTUB(_log10                               ,0x006bb8c8) //112            == 0x006bb8c8
NHSTUB(_pow                                   ,0x006bba40) //121
NHSTUB(_sqrt                                  ,0x006bd664) //  6
NHSTUB(add_ptp_handler                        ,0xffa7600c) //121
NHSTUB(apex2us                                ,0xffa2655c) //121
NHSTUB(close                                  ,0xff823d18) //109
NHSTUB(err_init_task                          ,0xff824798) //111
NHSTUB(exmem_alloc                            ,0xff8350dc) //101
NHSTUB(exmem_ualloc                           ,0xff834f48) //101
NHSTUB(exmem_ufree                            ,0xff835088) //101
NHSTUB(free                                   ,0xff825628) //112
NHSTUB(get_nd_value                           ,0xffac1ea4) //123
NHSTUB(get_current_nd_value                   ,0xffac1e44) //122
NHSTUB(get_current_deltasv                    ,0xff8c7130) //122
NHSTUB(GetCurrentDriveBaseSvValue             ,0xff8cd134) //120
NHSTUB(kbd_p1_f                               ,0xff82dce8) //109
NHSTUB(kbd_p1_f_cont                          ,0xff82dcf4) //109
NHSTUB(kbd_p2_f                               ,0xff82d460) //109
NHSTUB(kbd_read_keys                          ,0xff82dc98) //109
NHSTUB(kbd_read_keys_r2                       ,0xff86b230) //109
NHSTUB(lseek                                  ,0xff827d34) //120
NHSTUB(malloc                                 ,0xff8255d0) //112
NHSTUB(memcmp                                 ,0xff8253a8) //120
NHSTUB(memcpy                                 ,0xff8b41c8) //120
NHSTUB(memset                                 ,0xffa20574) //120
NHSTUB(mkdir                                  ,0xff827fb4) //121
NHSTUB(mktime_ext                             ,0xff8b3a50) //  1
NHSTUB(open                                   ,0xff823c68) //109
NHSTUB(OpenFastDir                            ,0xffab325c) //115
NHSTUB(closedir                               ,0xffab320c) //121
NHSTUB(get_fstype                             ,0xff83169c) //122
NHSTUB(qsort                                  ,0xffb2e154) //  6
NHSTUB(rand                                   ,0xffa20544) //121
NHSTUB(realloc                                ,0xffa205f0) //115
NHSTUB(reboot_fw_update                       ,0xffad3c08) //106
NHSTUB(set_control_event                      ,0xff8a22b0) //111
NHSTUB(srand                                  ,0xffa20538) //122
NHSTUB(stat                                   ,0xff827d7c) //109
NHSTUB(strcat                                 ,0xff838f48) //  1
NHSTUB(strchr                                 ,0xff838fd0) //  1
NHSTUB(strcmp                                 ,0xff8254a4) //120
NHSTUB(strcpy                                 ,0xff825390) //120
NHSTUB(strftime                               ,0xff8b3a9c) //113
NHSTUB(strlen                                 ,0xff8254e8) //120
NHSTUB(strncmp                                ,0xff838f84) //  1
NHSTUB(strncpy                                ,0xff8286ac) //  1
NHSTUB(strrchr                                ,0xff8b4314) //  1
NHSTUB(strtol                                 ,0xff838f34) //101
NHSTUB(strtolx                                ,0xff838d38) //109
   DEF(task_CaptSeq                           ,0xff88f788) //120
   DEF(task_DvlpSeqTask                       ,0xff99fb74) //120
   DEF(task_ExpDrv                            ,0xff8dd134) //120
   DEF(task_FileWrite                         ,0xffab1dfc) //120
   DEF(task_InitFileModules                   ,0xff85ab78) //120
   DEF(task_MovieRecord                       ,0xff999d74) //120
   DEF(task_PhySw                             ,0xff82d7c4) //120
   DEF(hook_CreateTask                        ,0xff824a30) //105
NHSTUB(time                                   ,0xff82ab10) //119
NHSTUB(vsprintf                               ,0xff82866c) //115
NHSTUB(EngDrvRead                             ,0xff82ddf8) //102
NHSTUB(PTM_GetCurrentItem                     ,0xff8a4680) //105
NHSTUB(DisableISDriveError                    ,0xffad06dc) //120
NHSTUB(CancelHPTimer                          ,0xff89c814) //119
NHSTUB(SetHPTimerAfterNow                     ,0xff89c70c) //119
NHSTUB(SS_MFOn                                ,0xff99bc1c) //120
NHSTUB(SS_MFOff                               ,0xff99bc2c) //120
NHSTUB(GetAdChValue                           ,0xff867758) //120
NHSTUB(get_ptp_buf_size                       ,0xff922754) //122
NHSTUB(get_ptp_file_buf                       ,0xffa77c68) //121
NHSTUB(SetVideoOutType                        ,0xffb69314) //109
NHSTUB(GetVideoOutType                        ,0xffb69260) //120
