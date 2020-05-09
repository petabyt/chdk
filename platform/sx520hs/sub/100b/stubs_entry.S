// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R55 (DRYOS version 2.3, release #0055+p6)
//   Firmware Ver GM1.00B   // Found @ 0xff0ae9c4, "GM1.00B" @ 0xff0ae9d1
//   Firmware build timestamp: Jul 14 2014 17:09:18
//   Canon PowerShot SX520 HS

// Values for makefile.inc
//   DIGIC = 41# DIGIC 4+
//   PLATFORMOSVER = 55
//   PLATFORMID = 12955# (0x329b) Found @ 0xfffe0040
//   MAXRAMADDR = 0x0fffffff
//   MEMISOSTART = 0x002ff248
//   KEYSYS = d4h# Found @ 0xff0144a4
//   NEED_ENCODED_DISKBOOT = 14# Found @ 0xff0144b4
//   ARAM_HEAP_START = 0x60e000# Found @ 0xff22c00c
//   ARAM_HEAP_SIZE  = 0x22000# Found @ 0xff22bfcc

// Detected address ranges:
// ROM      0xff010000 - 0xffffffff (16711680 bytes)
// RAM code 0x006b1000 - 0x006e28c4 copied from 0xff8c9278 ( 202948 bytes)
// RAM data 0x00001900 - 0x00019888 copied from 0xff8b12f0 (  98184 bytes)

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NHSTUB(DeleteFile_Fut                       ,0xff026928) //  1 90%        == 0xff026928
//NHSTUB(GetFocusLensSubjectDistanceFromLens  ,0xff203974) //  3 90%        == 0xff203974
// ERROR: MakeDirectory_Fut is not found.                  //--- ---    *** != 0xff027438
// ERROR: RefreshPhysicalScreen is not found.              //--- ---    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff3dd5fc -> ff7ddb58
// Mode 16948 in firmware but not in current modemap
// Mode 16950 in firmware but not in current modemap

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x0001a644) // Found @0xff02bf9c
DEF(physw_run                               ,0x00001ca0) // Found @0xff02ba38
DEF(physw_sleep_delay                       ,0x00001ca8) // Found @0xff02ba38
DEF(levent_table                            ,0xff6980ec) // Found @0xff6980ec
DEF(FlashParamsTable                        ,0xff7ddea8) // Found @0xff7ddea8
DEF(movie_status                            ,0x0000a5cc) // Found @0xff2136b8
//DEF(video_compression_rate                  ,0x0000a57c) // Found @0xff214120, ** != ** stubs_min = 0x0000a5fc (0xa580+0x7c)
DEF(full_screen_refresh                     ,0x0000b5b4) // Found @0xff23ea34
DEF(canon_menu_active                       ,0x000040dc) // Found @0xff0b8fa8
DEF(canon_shoot_menu_active                 ,0x0000d821) // Found @0xff2d02f8
DEF(zoom_status                             ,0x0000f9fc) // Found @0xff35b33c
DEF(some_flag_for_af_scan                   ,0x000281d4) // Found @0xff3d6dac
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 2 int value(s), the first is the zoom focus length.
// there are 195 entries in the table - set NUM_FL to 195
DEF(focus_len_table                         ,0xfffee354) // Found @0xfffee354
DEF(zoom_busy                               ,0x0000386c) // Found @0xff0950cc
DEF(focus_busy                              ,0x00009fc4) // Found @0xff20227c
// Palette colour tables  found @ 0xff69edbc
// Camera has 2 RAW buffers @ 0x44000000 & 0x4a8013e0
//  Note: active buffer --> raw_buffers[active_raw_buffer]
//        other buffer  --> raw_buffers[active_raw_buffer^1]
DEF(raw_buffers                             ,0xff650604) // Found @0xff650604
DEF(active_raw_buffer                       ,0x00003a94) // Found @0xff09eccc
DEF(fileio_semaphore                        ,0x00001d34) // Found @0xff02ec08
DEF(exmem_alloc_table                       ,0x0001ba24) // Found @0xff034100
DEF(exmem_types_table                       ,0xff8b17bc) // Found @0x00001dcc
DEF_CONST(exmem_type_count                  ,0x0000001f)
DEF(imager_active                           ,0x000020a8) // Found @0xff04c7d8 (0x20a4 + 4)
DEF_CONST(uiprop_count                      ,0x000000c8) // Found @0xff234694

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x40711000; }             // Found @0xff06e5d4
//void *vid_get_viewport_fb()      { return (void*)0x40866b80; }             // Found @0xff4d2de0
DEF(jpeg_count_str                          ,0x0018b064) // Found @0xff2aff38
//char *camera_jpeg_count_str()    { return (char*)0x0018b064; }             // Found @0xff2aff38
//int get_flash_params_count(void) { return 0xdc; }                          // Found @0xff235118

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x02000000 // Found @0xff63ef08, levent 0x20a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x10000000 // Found @0xff63ef18, levent 0x202
//#define USB_IDX             2
//#define BATTCOVER_FLAG      0x04000000 // Found @0xff63ef10, levent 0x205
//#define BATTCOVER_IDX       2
//#define ANALOG_AV_FLAG      0x00000004 // Found @0xff63eea0, levent 0x200 (non-inverted logic)
//#define ANALOG_AV_IDX       2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_UP              ,0x00000400 }, // Found @0xff63ee50, levent 0x06
//    { 0, KEY_DOWN            ,0x00000800 }, // Found @0xff63ee58, levent 0x07
//    { 0, KEY_SET             ,0x00001000 }, // Found @0xff63ee60, levent 0x0a
//    { 0, KEY_RIGHT           ,0x00002000 }, // Found @0xff63ee68, levent 0x09
//    { 0, KEY_LEFT            ,0x00004000 }, // Found @0xff63ee70, levent 0x08
//    { 0, KEY_MENU            ,0x00008000 }, // Found @0xff63ee78, levent 0x14
//    { 0, KEY_VIDEO           ,0x00020000 }, // Found @0xff63ee88, levent 0x02
//    { 2, KEY_SHOOT_FULL      ,0x00000060 }, // Found @0xff63eeb8, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000040 }, // Found @0xff63eeb8, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00000020 }, // Found @0xff63eeb0, levent 0x00
//    { 2, KEY_POWER           ,0x00000080 }, // Found @0xff63eec0, levent 0x100
//    { 2, KEY_PLAYBACK        ,0x00000100 }, // Found @0xff63eec8, levent 0x101
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#define CAM_RAW_ROWPIX    4768 // Found @0xff1d3454
//#define CAM_RAW_ROWS      3516 // Found @0xff1d3460
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff025c5c
//#define CAM_DATE_FOLDER_NAMING 0x080 // Found @0xff39591c (pass as 3rd param to GetImageFolder)
//#define PARAM_CAMERA_NAME 3 // Found @0xff7dcaa0
//#define CAM_3ARG_DebugAssert 1

// Known propcases
// //      PROPCASE_AFSTEP 13
// #define PROPCASE_FOCUS_STATE 18
// #define PROPCASE_AV 23
// #define PROPCASE_BV 35
// //      PROPCASE_DELTA_DIGITALGAIN 79
// #define PROPCASE_DELTA_SV 81
// //      PROPCASE_DELTA_ND 82
// #define PROPCASE_EV_CORRECTION_2 213
// #define PROPCASE_ORIENTATION_SENSOR 225
// #define PROPCASE_SV_MARKET 252
// //      PROPCASE_SVFIX 253
// #define PROPCASE_TV 269
// Guessed propset: 8

// Misc stuff
DEF(ctypes, 0xff63aeac)

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
// EXMEM_CREATIVE_SHOT  30

// ISR flag: 0x1944, pointer to current task's control block: 0x1940
// pointer to TCB area: 0x19c4, found @ 0xff8ca820

// LED table init @ 0xff19eadc
// LED #1: 0xc022d034 (#100 in GPIO table), offset 0x98
// LED #2: 0xc022d1fc (#97 in GPIO table), offset 0x8
// GPIO table @ 0xff63e888

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NHSTUB(AllocateUncacheableMemory              ,0xff025c18) //112
NHSTUB(Close                                  ,0xff026f9c) //120
NHSTUB(CreateBinarySemaphore                  ,0x006b7890) //115
NHSTUB(CreateTask                             ,0x006b5658) //120
NHSTUB(DebugAssert                            ,0x006b5a04) //107
NHSTUB(DeleteDirectory_Fut                    ,0xff02699c) //116
NHSTUB(DoAELock                               ,0xff0329d8) //120
NHSTUB(DoAFLock                               ,0xff0325cc) //120
NHSTUB(EnterToCompensationEVF                 ,0xff0328c8) //104
NHSTUB(ExecuteEventProcedure                  ,0xff034be8) //104
NHSTUB(ExitFromCompensationEVF                ,0xff032978) //104
NHSTUB(ExitTask                               ,0x006b59a0) //120
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff044938) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff044ad0) //104
NHSTUB(Fclose_Fut                             ,0xff026a34) //120
NHSTUB(Feof_Fut                               ,0xff026c20) //  1
NHSTUB(Fflush_Fut                             ,0xff026c5c) //  1
NHSTUB(Fgets_Fut                              ,0xff026b88) //  6
NHSTUB(Fopen_Fut                              ,0xff0269f4) //120
NHSTUB(Fread_Fut                              ,0xff026ae0) //120
NHSTUB(FreeUncacheableMemory                  ,0xff025c54) //112
NHSTUB(Fseek_Fut                              ,0xff026bd4) //120
NHSTUB(Fwrite_Fut                             ,0xff026b34) //120
NHSTUB(GetBatteryTemperature                  ,0xff078c70) //102
NHSTUB(GetCCDTemperature                      ,0xff078bf8) //102
NHSTUB(GetCurrentAvValue                      ,0xff092bfc) //120
NHSTUB(GetCurrentShutterSpeed                 ,0xff0df218) //120
NHSTUB(GetUsableMaxAv                         ,0xff1d3d84) //120
NHSTUB(GetUsableMinAv                         ,0xff1d3d68) //120
NHSTUB(GetDrive_ClusterSize                   ,0xff03029c) //122
NHSTUB(GetDrive_FreeClusters                  ,0xff030aa8) //119
NHSTUB(GetDrive_TotalClusters                 ,0xff030a7c) //122
NHSTUB(GetFocusLensSubjectDistance            ,0xff203590) //102
NHSTUB(GetImageFolder                         ,0xff1db864) //122
NHSTUB(GetKbdState                            ,0xff074634) //109
NHSTUB(GetMemInfo                             ,0xff023408) //115
NHSTUB(GetOpticalTemperature                  ,0xff078ce8) //120
NHSTUB(GetParameterData                       ,0xff2350d4) //101
NHSTUB(GetPropertyCase                        ,0xff0b02cc) //101
NHSTUB(GetSystemTime                          ,0xff3da5d0) //120
NHSTUB(GetVRAMHPixelsSize                     ,0xff0513e0) //120
NHSTUB(GetVRAMVPixelsSize                     ,0xff0513ec) //120
NHSTUB(GetZoomLensCurrentPoint                ,0xff095554) //120
NHSTUB(GetZoomLensCurrentPosition             ,0xff20a708) //102
NHSTUB(GiveSemaphore                          ,0x006b7b10) //120
NHSTUB(IsStrobeChargeCompleted                ,0xff10022c) //102
NHSTUB(LEDDrive                               ,0xff21de48) //120
NHSTUB(LocalTime                              ,0x006b98e8) //115
NHSTUB(LockMainPower                          ,0xff0b4ba4) //120
NHSTUB(MakeSDCardBootable                     ,0xff030e70) //105
NHSTUB(MoveFocusLensToDistance                ,0xff4d69cc) //102
NHSTUB(MoveIrisWithAv                         ,0xff3d4d58) //120
NHSTUB(MoveZoomLensWithPoint                  ,0xff3d57d0) //120
NHSTUB(MoveOpticalZoomAt                      ,0xff031a98) //109
NHSTUB(Open                                   ,0xff026ed4) //120
NHSTUB(PB2Rec                                 ,0xff05effc) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff21eff0) //102
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff21efc0) //102
NHSTUB(PT_PlaySound                           ,0xff0c69d8) //122
NHSTUB(PostLogicalEventForNotPowerType        ,0xff0b2164) //120
NHSTUB(PostLogicalEventToUI                   ,0xff0b21b0) //120
NHSTUB(PutInNdFilter                          ,0xff4d7198) //102
NHSTUB(PutOutNdFilter                         ,0xff4d71d4) //102
NHSTUB(Read                                   ,0xff023ec4) //120
NHSTUB(ReadFastDir                            ,0xff3b0c64) //115
NHSTUB(Rec2PB                                 ,0xff05f054) //104
NHSTUB(RenameFile_Fut                         ,0xff026894) //116
NHSTUB(Restart                                ,0xff037c88) //122
NHSTUB(ScreenLock                             ,0xff0b87bc) //117
NHSTUB(ScreenUnlock                           ,0xff0b8774) //117
NHSTUB(SetAE_ShutterSpeed                     ,0xff4d1bbc) //102
NHSTUB(SetAutoShutdownTime                    ,0xff0b4c18) //120
NHSTUB(SetCurrentCaptureModeType              ,0xff0c320c) //120
NHSTUB(SetFileAttributes                      ,0xff0273a0) //  6
NHSTUB(SetFileTimeStamp                       ,0xff027328) //  6
NHSTUB(SetLogicalEventActive                  ,0xff0b280c) //120
NHSTUB(SetParameterData                       ,0xff235038) //101
NHSTUB(SetPropertyCase                        ,0xff0b00fc) //101
NHSTUB(SetScriptMode                          ,0xff0b2860) //120
NHSTUB(SleepTask                              ,0x006b8dcc) //120
NHSTUB(TakeSemaphore                          ,0x006b7a38) //120
NHSTUB(TurnOffBackLight                       ,0xff0c60e4) //104
NHSTUB(TurnOnBackLight                        ,0xff0c60cc) //104
NHSTUB(TurnOnDisplay                          ,0xff06e9cc) //120
NHSTUB(TurnOffDisplay                         ,0xff06e9dc) //120
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff25486c) //120
NHSTUB(UnlockAE                               ,0xff0329fc) //120
NHSTUB(UnlockAF                               ,0xff0325fc) //120
NHSTUB(UnlockMainPower                        ,0xff0b4afc) //120
NHSTUB(VbattGet                               ,0xff02ab3c) //120
NHSTUB(Write                                  ,0xff026ff0) //120
NHSTUB(WriteSDCard                            ,0x006ba7ec) //108
NHSTUB(_log                                   ,0x006ddca0) //111
NHSTUB(_log10                                 ,0x006de1e0) //112
NHSTUB(_pow                                   ,0x006de358) //121
NHSTUB(_sqrt                                  ,0x006e0430) //  6
NHSTUB(add_ptp_handler                        ,0xff156b40) //121
NHSTUB(apex2us                                ,0xff2f67ec) //121
NHSTUB(close                                  ,0xff023d20) //109
NHSTUB(err_init_task                          ,0xff0247a0) //111
NHSTUB(exmem_alloc                            ,0xff0347d0) //101
NHSTUB(exmem_ualloc                           ,0xff034634) //101
NHSTUB(exmem_ufree                            ,0xff03477c) //101
NHSTUB(free                                   ,0xff02504c) //112
NHSTUB(kbd_p1_f                               ,0xff02bfec) //109
NHSTUB(kbd_p1_f_cont                          ,0xff02bff8) //109
NHSTUB(kbd_p2_f                               ,0xff02b6d0) //109
NHSTUB(kbd_read_keys                          ,0xff02bf9c) //109
NHSTUB(kbd_read_keys_r2                       ,0xff073da8) //109
NHSTUB(lseek                                  ,0xff0271b8) //120
NHSTUB(malloc                                 ,0xff024ff4) //112
NHSTUB(memcmp                                 ,0xff024dcc) //120
NHSTUB(memcpy                                 ,0xff0cbe18) //120
NHSTUB(memset                                 ,0xff2ef8e0) //120
NHSTUB(mkdir                                  ,0xff027438) //121
NHSTUB(mktime_ext                             ,0xff0cb578) //  1
NHSTUB(open                                   ,0xff023c70) //109
NHSTUB(OpenFastDir                            ,0xff3b0b10) //115
NHSTUB(closedir                               ,0xff3b0ac0) //121
NHSTUB(get_fstype                             ,0xff030214) //122
NHSTUB(qsort                                  ,0xff2ef880) //  6
NHSTUB(rand                                   ,0xff0cbde8) //121
NHSTUB(realloc                                ,0xff2ef95c) //115
NHSTUB(reboot_fw_update                       ,0xff3d9c44) //106
NHSTUB(set_control_event                      ,0xff0b24cc) //111
NHSTUB(srand                                  ,0xff0cbddc) //122
NHSTUB(stat                                   ,0xff027200) //109
NHSTUB(strcat                                 ,0xff038638) //  1
NHSTUB(strchr                                 ,0xff0386c0) //  1
NHSTUB(strcmp                                 ,0xff024ec8) //120
NHSTUB(strcpy                                 ,0xff024db4) //120
NHSTUB(strftime                               ,0xff0cb5f8) //113
NHSTUB(strlen                                 ,0xff024f0c) //120
NHSTUB(strncmp                                ,0xff038674) //  1
NHSTUB(strncpy                                ,0xff027b30) //  1
NHSTUB(strrchr                                ,0xff0cbf64) //  1
NHSTUB(strtol                                 ,0xff038624) //101
NHSTUB(strtolx                                ,0xff038428) //109
   DEF(task_CaptSeq                           ,0xff09c8a0) //120
   DEF(task_DvlpSeqTask                       ,0xff22360c) //120
   DEF(task_ExpDrv                            ,0xff0f7800) //120
   DEF(task_FileWrite                         ,0xff3af1f0) //120
   DEF(task_InitFileModules                   ,0xff061c60) //120
   DEF(task_MovieRecord                       ,0xff215358) //120
   DEF(task_PhySw                             ,0xff02ba34) //120
   DEF(task_RotaryEncoder                     ,0xff07487c) //120
   DEF(hook_CreateTask                        ,0x006b5658) //105
NHSTUB(time                                   ,0x006b917c) //119
NHSTUB(vsprintf                               ,0xff027af0) //115
NHSTUB(EngDrvRead                             ,0xff02c0bc) //102
NHSTUB(PTM_GetCurrentItem                     ,0xff0b675c) //105
NHSTUB(DisableISDriveError                    ,0xff3d62dc) //120
NHSTUB(CancelHPTimer                          ,0xff0aca38) //119
NHSTUB(SetHPTimerAfterNow                     ,0xff0ac930) //119
NHSTUB(SS_MFOn                                ,0xff21f084) //120
NHSTUB(SS_MFOff                               ,0xff21f094) //120
NHSTUB(GetAdChValue                           ,0xff06fd98) //120
NHSTUB(EnableHDMIPower                        ,0xff07281c) //123
NHSTUB(DisableHDMIPower                       ,0xff072870) //123
NHSTUB(get_ptp_buf_size                       ,0xff148de4) //122
NHSTUB(get_ptp_file_buf                       ,0xff34b858) //121
NHSTUB(SetVideoOutType                        ,0xff4d2448) //109
NHSTUB(GetVideoOutType                        ,0xff4d2354) //120
