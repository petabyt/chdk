// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R52 (DRYOS version 2.3, release #0052)
//   Firmware Ver GM1.00A   // Found @ 0xff889710, "GM1.00A" @ 0xff88971d
//   Firmware build timestamp: May 22 2013 13:22:39
//   Canon PowerShot SX170 IS

// Values for makefile.inc
//   DIGIC = 40# DIGIC 4
//   PLATFORMOSVER = 52
//   PLATFORMID = 12918# (0x3276) Found @ 0xfffe0040
//   MAXRAMADDR = 0x03ffffff
//   MEMISOSTART = 0x0016fb10
//   KEYSYS = d4e# Found @ 0xffff1d44
//   NEED_ENCODED_DISKBOOT = 11# Found @ 0xffff1d54
//   ARAM_HEAP_START = 0x34e000# Found @ 0xff99db0c
//   ARAM_HEAP_SIZE  = 0x22000# Found @ 0xff99dacc

// Detected address ranges:
// ROM      0xff810000 - 0xffffffff (8323072 bytes)
// RAM code 0x003f1000 - 0x00400670 copied from 0xffcd5e6c (  63088 bytes)
// RAM data 0x00001900 - 0x00010e98 copied from 0xffcc68d4 (  62872 bytes)

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NHSTUB(DeleteFile_Fut                       ,0xff816bd0) //  1 90%        == 0xff816bd0
//NHSTUB(GetFocusLensSubjectDistanceFromLens  ,0xff983bfc) //  3 90%        == 0xff983bfc
// ERROR: MakeDirectory_Fut is not found.                  //--- ---    *** != 0xff8176e0
// ERROR: RefreshPhysicalScreen is not found.              //--- ---    *** != 0x00000000
// ERROR: WriteSDCard is not found.                        //--- ---    *** != 0xff86e074

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ffae03b0 -> ffc60e14
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00011bc0) // Found @0xff81be44
DEF(physw_run                               ,0x00001cf4) // Found @0xff81b990
DEF(physw_sleep_delay                       ,0x00001cfc) // Found @0xff81b990
DEF(levent_table                            ,0xffc08360) // Found @0xffc08360
DEF(FlashParamsTable                        ,0xffc6108c) // Found @0xffc6108c
DEF(movie_status                            ,0x000074e4) // Found @0xff98ebe8
DEF(video_compression_rate                  ,0x00007514) // Found @0xff98f358
DEF(full_screen_refresh                     ,0x00007cd8) // Found @0xff9b103c
DEF(canon_menu_active                       ,0x00003f14) // Found @0xff8933f8
DEF(canon_shoot_menu_active                 ,0x000097cd) // Found @0xffa1bc50
DEF(playrec_mode                            ,0x00003678) // Found @0xff8802ac
DEF(zoom_status                             ,0x0000b084) // Found @0xffa73630
DEF(some_flag_for_af_scan                   ,0x0001d950) // Found @0xffad8fd4
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 2 int value(s), the first is the zoom focus length.
// there are 127 entries in the table - set NUM_FL to 127
DEF(focus_len_table                         ,0xfffeabf8) // Found @0xfffeabf8
DEF(zoom_busy                               ,0x00007378) // Found @0xff9892d8
DEF(focus_busy                              ,0x0000714c) // Found @0xff982780
// Palette colour tables  found @ 0xffc0bcf0
// Camera appears to have only 1 RAW buffer @ 0x420e5c30 (Found @0xffb64e18)
DEF(fileio_semaphore                        ,0x00001d6c) // Found @0xff81e394
DEF(exmem_alloc_table                       ,0x00012f34) // Found @0xff823134
DEF(exmem_types_table                       ,0xffcc6dd8) // Found @0x00001e04
DEF_CONST(exmem_type_count                  ,0x0000001b)
DEF(imager_active                           ,0x0000209c) // Found @0xff83a308 (0x2098 + 4)
DEF_CONST(uiprop_count                      ,0x00000094) // Found @0xff9a579c

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x40431000; }             // Found @0xff8539b0
//void *vid_get_viewport_fb()      { return (void*)0x40586b80; }             // Found @0xffb63494
DEF(jpeg_count_str                          ,0x000cb220) // Found @0xffa04ddc
//char *camera_jpeg_count_str()    { return (char*)0x000cb220; }             // Found @0xffa04ddc
//int get_flash_params_count(void) { return 0x99; }                          // Found @0xff9a6220

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x02000000 // Found @0xffbacbf8, levent 0x20a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x10000000 // Found @0xffbacc08, levent 0x202
//#define USB_IDX             2
//#define BATTCOVER_FLAG      0x04000000 // Found @0xffbacc00, levent 0x205
//#define BATTCOVER_IDX       2
//#define ANALOG_AV_FLAG      0x00002000 // Found @0xffbacb20, levent 0x200 (non-inverted logic)
//#define ANALOG_AV_IDX       0

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_DISPLAY         ,0x80000000 }, // Found @0xffbacb28, levent 0x0c
//    { 1, KEY_SET             ,0x00000001 }, // Found @0xffbacb30, levent 0x0a
//    { 1, KEY_MENU            ,0x00800000 }, // Found @0xffbacb48, levent 0x0b
//    { 1, KEY_ERASE           ,0x08000000 }, // Found @0xffbacb50, levent 0x19
//    { 1, KEY_SHOOT_FULL      ,0x30000000 }, // Found @0xffbacb60, levent 0x01
//    { 1, KEY_SHOOT_FULL_ONLY ,0x20000000 }, // Found @0xffbacb60, levent 0x01
//    { 1, KEY_SHOOT_HALF      ,0x10000000 }, // Found @0xffbacb58, levent 0x00
//    { 1, KEY_UP              ,0x40000000 }, // Found @0xffbacb68, levent 0x06
//    { 1, KEY_DOWN            ,0x80000000 }, // Found @0xffbacb70, levent 0x07
//    { 2, KEY_VIDEO           ,0x00000001 }, // Found @0xffbacb78, levent 0x02
//    { 2, KEY_PLAYBACK        ,0x00000008 }, // Found @0xffbacb80, levent 0x101
//    { 2, KEY_POWER           ,0x00000020 }, // Found @0xffbacb88, levent 0x100
//    { 2, KEY_RIGHT           ,0x00001000 }, // Found @0xffbacbb0, levent 0x09
//    { 2, KEY_LEFT            ,0x00002000 }, // Found @0xffbacbb8, levent 0x08
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#define CAM_RAW_ROWPIX    4704 // Found @0xff959c2c
//#define CAM_RAW_ROWS      3504 // Found @0xff959c38
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff815f04
//#define CAM_DATE_FOLDER_NAMING 0x080 // Found @0xffa9ec90 (pass as 3rd param to GetImageFolder)
//#define PARAM_CAMERA_NAME 3 // Found @0xffc6026c
//#define CAM_3ARG_DebugAssert 1

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
DEF(ctypes, 0xffbac308)

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
// EXMEM_FILESTORE      15
// EXMEM_MOVIE_REC      16
// EXMEM_MOVIE_PLY      17
// EXMEM_WIFI_RESIZE    18
// EXMEM_PCEVF          19
// EXMEM_WIDE           20
// EXMEM_NARROW         21
// EXMEM_AUTO_GIS_MODE  22
// EXMEM_NP_GIS_MODE    23
// EXMEM_TRIPODHDR_MODE 24
// EXMEM_HSHQ_MODE      25
// EXMEM_CRAW_REC       26

// ISR flag: 0x1944, pointer to current task's control block: 0x1940
// pointer to TCB area: 0x19c4, found @ 0xffcd74dc

// LED table init @ 0xff938ac4
// LED #1: 0xc0223030, offset 0x104
// LED #2: 0xc0220120, offset 0x4

// For capt_seq.c
DEF(_nrflag,0xa8f8) // Found @ ffa2fe18 (0xa900) & ffa2fe30 (-0x08)
//static long *nrflag = (long*)(0xa900-0x08);  // Found @ ffa2fe18 & ffa2fe28

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NHSTUB(AllocateUncacheableMemory              ,0xff815ec0) //112
NHSTUB(Close                                  ,0xff817244) //120
NHSTUB(CreateBinarySemaphore                  ,0x003f7968) //115
NHSTUB(CreateTask                             ,0x003f5778) //120
NHSTUB(DebugAssert                            ,0x003f5a58) //107
NHSTUB(DeleteDirectory_Fut                    ,0xff816c44) //116
NHSTUB(DoAELock                               ,0xff821d94) //120
NHSTUB(DoAFLock                               ,0xff8219fc) //120
NHSTUB(EnterToCompensationEVF                 ,0xff821cec) //104
NHSTUB(ExecuteEventProcedure                  ,0xff823bf0) //104
NHSTUB(ExitFromCompensationEVF                ,0xff821d34) //104
NHSTUB(ExitTask                               ,0x003f5a04) //120
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff832c1c) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff832d90) //104
NHSTUB(Fclose_Fut                             ,0xff816cdc) //120
NHSTUB(Feof_Fut                               ,0xff816ec8) //  1
NHSTUB(Fflush_Fut                             ,0xff816f04) //  1
NHSTUB(Fgets_Fut                              ,0xff816e30) //  6
NHSTUB(Fopen_Fut                              ,0xff816c9c) //120
NHSTUB(Fread_Fut                              ,0xff816d88) //120
NHSTUB(FreeUncacheableMemory                  ,0xff815efc) //112
NHSTUB(Fseek_Fut                              ,0xff816e7c) //120
NHSTUB(Fwrite_Fut                             ,0xff816ddc) //120
NHSTUB(GetBatteryTemperature                  ,0xff85c2c0) //102
NHSTUB(GetCCDTemperature                      ,0xff85c248) //102
NHSTUB(GetCurrentAvValue                      ,0xff8733a8) //120
NHSTUB(GetCurrentShutterSpeed                 ,0xff8b530c) //120
NHSTUB(GetUsableMaxAv                         ,0xff95a600) //120
NHSTUB(GetUsableMinAv                         ,0xff95a5e4) //120
NHSTUB(GetDrive_ClusterSize                   ,0xff81fa20) //122
NHSTUB(GetDrive_FreeClusters                  ,0xff82026c) //119
NHSTUB(GetDrive_TotalClusters                 ,0xff820240) //122
NHSTUB(GetFocusLensSubjectDistance            ,0xff983818) //102
NHSTUB(GetImageFolder                         ,0xff961580) //122
NHSTUB(GetKbdState                            ,0xff858e1c) //109
NHSTUB(GetMemInfo                             ,0xff81369c) //115
NHSTUB(GetOpticalTemperature                  ,0xff85c338) //120
NHSTUB(GetParameterData                       ,0xff9a61dc) //101
NHSTUB(GetPropertyCase                        ,0xff88af50) //101
NHSTUB(GetSystemTime                          ,0xffadd748) //120
NHSTUB(GetVRAMHPixelsSize                     ,0xff83fa30) //120
NHSTUB(GetVRAMVPixelsSize                     ,0xff83fa3c) //120
NHSTUB(GetZoomLensCurrentPoint                ,0xff989758) //120
NHSTUB(GetZoomLensCurrentPosition             ,0xffac8d30) //102
NHSTUB(GiveSemaphore                          ,0x003f7bc8) //120
NHSTUB(IsStrobeChargeCompleted                ,0xff8e5114) //102
NHSTUB(LEDDrive                               ,0xff990a60) //120
NHSTUB(LocalTime                              ,0x003f9a38) //115
NHSTUB(LockMainPower                          ,0xff88f230) //120
NHSTUB(MoveFocusLensToDistance                ,0xffb5f020) //102
NHSTUB(MoveIrisWithAv                         ,0xffad6c08) //120
NHSTUB(MoveZoomLensWithPoint                  ,0xffad7624) //120
NHSTUB(MoveOpticalZoomAt                      ,0xff821248) //109
NHSTUB(Open                                   ,0xff81717c) //120
NHSTUB(PB2Rec                                 ,0xff84948c) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff991b8c) //102
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff991b5c) //102
NHSTUB(PT_PlaySound                           ,0xff89f1b4) //122
NHSTUB(PostLogicalEventForNotPowerType        ,0xff88cde4) //120
NHSTUB(PostLogicalEventToUI                   ,0xff88ce30) //120
NHSTUB(PutInNdFilter                          ,0xffb5daa8) //102
NHSTUB(PutOutNdFilter                         ,0xffb5dae4) //102
NHSTUB(Read                                   ,0xff814158) //120
NHSTUB(ReadFastDir                            ,0xffab6e78) //115
NHSTUB(Rec2PB                                 ,0xff8494cc) //104
NHSTUB(RenameFile_Fut                         ,0xff816b3c) //116
NHSTUB(Restart                                ,0xff826c3c) //122
NHSTUB(ScreenLock                             ,0xff892d08) //117
NHSTUB(ScreenUnlock                           ,0xff892d5c) //117
NHSTUB(SetAE_ShutterSpeed                     ,0xffb6236c) //102
NHSTUB(SetAutoShutdownTime                    ,0xff88f2a8) //120
NHSTUB(SetCurrentCaptureModeType              ,0xff89c068) //120
NHSTUB(SetFileAttributes                      ,0xff817648) //  6
NHSTUB(SetFileTimeStamp                       ,0xff8175d0) //  6
NHSTUB(SetLogicalEventActive                  ,0xff88ef6c) //120
NHSTUB(SetParameterData                       ,0xff9a6140) //101
NHSTUB(SetPropertyCase                        ,0xff88adb0) //101
NHSTUB(SetScriptMode                          ,0xff88efc0) //120
NHSTUB(SleepTask                              ,0x003f8d2c) //120
NHSTUB(TakeSemaphore                          ,0x003f7af0) //120
NHSTUB(TurnOffBackLight                       ,0xff89ea58) //104
NHSTUB(TurnOnBackLight                        ,0xff89ea40) //104
NHSTUB(TurnOnDisplay                          ,0xff853db0) //120
NHSTUB(TurnOffDisplay                         ,0xff853dc0) //120
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff9c501c) //120
NHSTUB(UnlockAE                               ,0xff821e24) //120
NHSTUB(UnlockAF                               ,0xff821a2c) //120
NHSTUB(UnlockMainPower                        ,0xff88f180) //120
NHSTUB(VbattGet                               ,0xff81abc8) //120
NHSTUB(Write                                  ,0xff817298) //120
NHSTUB(_log                                   ,0x003fcbc8) //111
NHSTUB(_log10                                 ,0x003fd108) //112
NHSTUB(_pow                                   ,0x003fd280) //121
NHSTUB(_sqrt                                  ,0x003feea4) //  6
NHSTUB(add_ptp_handler                        ,0xffa6cea4) //121
NHSTUB(apex2us                                ,0xffa28c80) //121
NHSTUB(close                                  ,0xff813fb4) //109
NHSTUB(err_init_task                          ,0xff814a48) //111
NHSTUB(exmem_alloc                            ,0xff82373c) //101
NHSTUB(exmem_ualloc                           ,0xff82358c) //101
NHSTUB(exmem_ufree                            ,0xff8236d8) //101
NHSTUB(free                                   ,0xff8152f0) //112
NHSTUB(kbd_p1_f                               ,0xff81be94) //109
NHSTUB(kbd_p1_f_cont                          ,0xff81bea0) //109
NHSTUB(kbd_p2_f                               ,0xff81b628) //109
NHSTUB(kbd_read_keys                          ,0xff81be44) //109
NHSTUB(kbd_read_keys_r2                       ,0xff8586dc) //109
NHSTUB(lseek                                  ,0xff817460) //120
NHSTUB(malloc                                 ,0xff815298) //112
NHSTUB(memcmp                                 ,0xff815070) //120
NHSTUB(memcpy                                 ,0xff8a2bcc) //120
NHSTUB(memset                                 ,0xffa2346c) //120
NHSTUB(mkdir                                  ,0xff8176e0) //121
NHSTUB(mktime_ext                             ,0xff8a2454) //  1
NHSTUB(open                                   ,0xff813f04) //109
NHSTUB(OpenFastDir                            ,0xffab6d24) //115
NHSTUB(closedir                               ,0xffab6cd4) //121
NHSTUB(get_fstype                             ,0xff81f998) //122
NHSTUB(qsort                                  ,0xffb3a16c) //  6
NHSTUB(rand                                   ,0xffa2343c) //121
NHSTUB(realloc                                ,0xffa234e8) //115
NHSTUB(reboot_fw_update                       ,0xffadcdd0) //106
NHSTUB(set_control_event                      ,0xff88eb60) //111
NHSTUB(srand                                  ,0xffa23430) //122
NHSTUB(stat                                   ,0xff8174a8) //109
NHSTUB(strcat                                 ,0xff82761c) //  1
NHSTUB(strchr                                 ,0xff8276a4) //  1
NHSTUB(strcmp                                 ,0xff81516c) //120
NHSTUB(strcpy                                 ,0xff815058) //120
NHSTUB(strftime                               ,0xff8a24a0) //113
NHSTUB(strlen                                 ,0xff8151b0) //120
NHSTUB(strncmp                                ,0xff827658) //  1
NHSTUB(strncpy                                ,0xff817dd8) //  1
NHSTUB(strrchr                                ,0xff8a2d18) //  1
NHSTUB(strtol                                 ,0xff827608) //101
NHSTUB(strtolx                                ,0xff82740c) //109
   DEF(task_CaptSeq                           ,0xff87a64c) //120
   DEF(task_DvlpSeqTask                       ,0xff99581c) //120
   DEF(task_ExpDrv                            ,0xff8cb99c) //120
   DEF(task_FileWrite                         ,0xffab5b20) //120
   DEF(task_InitFileModules                   ,0xff849e18) //120
   DEF(task_MovieRecord                       ,0xff98f82c) //120
   DEF(task_PhySw                             ,0xff81b98c) //120
   DEF(task_RotaryEncoder                     ,0xff858f98) //120
   DEF(hook_CreateTask                        ,0x003f5778) //105
NHSTUB(time                                   ,0x003f9210) //119
NHSTUB(vsprintf                               ,0xff817d98) //115
NHSTUB(EngDrvRead                             ,0xff81bfa0) //102
NHSTUB(PTM_GetCurrentItem                     ,0xff890ec8) //105
NHSTUB(DisableISDriveError                    ,0xffad8138) //120
NHSTUB(CancelHPTimer                          ,0xff8877b8) //119
NHSTUB(SetHPTimerAfterNow                     ,0xff8876b0) //119
NHSTUB(SS_MFOn                                ,0xff991c20) //120
NHSTUB(SS_MFOff                               ,0xff991c30) //120
NHSTUB(GetAdChValue                           ,0xff854f30) //120
NHSTUB(get_ptp_buf_size                       ,0xff916980) //122
NHSTUB(get_ptp_file_buf                       ,0xffa6e9f8) //121
NHSTUB(SetVideoOutType                        ,0xffb62bb4) //109
NHSTUB(GetVideoOutType                        ,0xffb62b04) //120
