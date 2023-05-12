// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R58 (DRYOS version 2.3, release #0058+p7)
//   Firmware Ver GM1.00A   // Found @ 0xff0a760c, "GM1.00A" @ 0xff0a7619
//   Firmware build timestamp: Nov  4 2015 14:00:24
//   Canon IXUS 180

// Values for makefile.inc
//   DIGIC = 41# DIGIC 4+
//   PLATFORMOSVER = 58
//   PLATFORMID = 12992# (0x32c0) Found @ 0xfffe0270
//   MAXRAMADDR = 0x07ffffff
//   MEMISOSTART = 0x0028e6ec
//   KEYSYS = d4i# Found @ 0xff014590
//   NEED_ENCODED_DISKBOOT = 16# Found @ 0xff0145a0
//   ARAM_HEAP_START = 0x60e000# Found @ 0xff1ef624
//   ARAM_HEAP_SIZE  = 0x22000# Found @ 0xff1ef5e4

// Detected address ranges:
// ROM      0xff010000 - 0xffffffff (16711680 bytes)
// RAM code 0x006b1000 - 0x006e2d88 copied from 0xff767d78 ( 204168 bytes)
// RAM data 0x00001900 - 0x00013c50 copied from 0xff755a28 (  74576 bytes)

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
NHSTUB(DeleteFile_Fut                         ,0xff026a98) //  1 90%
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff1d5260) //  3 90%
// ERROR: MakeDirectory_Fut is not found.                  //--- ---    *** != 0xff0277ac
// ERROR: RefreshPhysicalScreen is not found.              //--- ---    *** != 0x00000000
// ERROR: TurnOffBackLight is not found.                   //--- ---    *** != 0x00000000
// ERROR: TurnOnBackLight is not found.                    //--- ---    *** != 0x00000000
// ERROR: close is not found.                              //--- ---    *** != 0xff023d68
// ERROR: open is not found.                               //--- ---    *** != 0xff023cb8

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff357224 -> ff6bdef8
// Mode 33332 in firmware but not in current modemap
// Current modemap entry not found in firmware - MODE_SMART_SHUTTER       33333
// Current modemap entry not found in firmware - MODE_HIGHSPEED_BURST     32778

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00014a18) // Found @0xff02c338
DEF(physw_run                               ,0x00001c18) // Found @0xff02be24
DEF(physw_sleep_delay                       ,0x00001c20) // Found @0xff02be24
DEF(levent_table                            ,0xff5f3780) // Found @0xff5f3780
DEF(FlashParamsTable                        ,0xff6be270) // Found @0xff6be270
DEF(movie_status                            ,0x00007d54) // Found @0xff1e0340
DEF(video_compression_rate                  ,0x00007d04) // Found @0xff1e1008
DEF(full_screen_refresh                     ,0x000088a4) // Found @0xff203f34
DEF(canon_menu_active                       ,0x00003f88) // Found @0xff0afd10
DEF(canon_shoot_menu_active                 ,0x0000a4a1) // Found @0xff26f3c4
DEF(zoom_status                             ,0x00006860) // Found @0xff1743c4
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 2 int value(s), the first is the zoom focus length.
// there are 101 entries in the table - set NUM_FL to 101
DEF(focus_len_table                         ,0xfffee67c) // Found @0xfffee67c
DEF(zoom_busy                               ,0x00007a98) // Found @0xff1d7c8c
DEF(focus_busy                              ,0x0000795c) // Found @0xff1d3d1c
// Palette colour tables  found @ 0xff5f7700
// Camera appears to have only 1 RAW buffer @ 0x43924c60 (Found @0xff43a610)
DEF(fileio_semaphore                        ,0x00001cb4) // Found @0xff02ee4c
DEF(exmem_alloc_table                       ,0x00015d7c) // Found @0xff033cd4
DEF(exmem_types_table                       ,0xff755e70) // Found @0x00001d48
DEF_CONST(exmem_type_count                  ,0x0000001e)
DEF(imager_active                           ,0x00001fd8) // Found @0xff04a094 (0x1fd4 + 4)
DEF_CONST(uiprop_count                      ,0x000000d7) // Found @0xff1f99b0
DEF(cameracon_state                         ,0x000023b0) // Found @0xff05b330

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x40711000; }             // Found @0xff06c888
//void *vid_get_viewport_fb()      { return (void*)0x40866b80; }             // Found @0xff438b5c
DEF(viewport_fb_d                           ,0x00003694) // Found 0x3638 (@0xff08a838) + 0x5c (@0xff08a870)
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x3638+0x5c)); } // Found @0xff08a838 & 0xff08a870
DEF(jpeg_count_str                          ,0x0010ed8c) // Found @0xff259524
//char *camera_jpeg_count_str()    { return (char*)0x0010ed8c; }             // Found @0xff259524
//int get_flash_params_count(void) { return 0xf1; }                          // Found @0xff1fa524

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00400000 // Found @0xff5ae59c, levent 0x30a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x01000000 // Found @0xff5ae5ac, levent 0x302
//#define USB_IDX             2
//#define BATTCOVER_FLAG      0x00800000 // Found @0xff5ae5a4, levent 0x305
//#define BATTCOVER_IDX       2
//#define ANALOG_AV_FLAG      0x00004000 // Found @0xff5ae51c, levent 0x300 (non-inverted logic)
//#define ANALOG_AV_IDX       0

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_SHOOT_FULL      ,0x0000000c }, // Found @0xff5ae504, levent 0x01
//    { 0, KEY_SHOOT_FULL_ONLY ,0x00000008 }, // Found @0xff5ae504, levent 0x01
//    { 0, KEY_SHOOT_HALF      ,0x00000004 }, // Found @0xff5ae4fc, levent 0x00
//    { 0, KEY_ZOOM_IN         ,0x00000200 }, // Found @0xff5ae50c, levent 0x03
//    { 0, KEY_ZOOM_OUT        ,0x00000400 }, // Found @0xff5ae514, levent 0x04
//    { 2, KEY_POWER           ,0x00000020 }, // Found @0xff5ae524, levent 0x100
//    { 2, KEY_PLAYBACK        ,0x00000080 }, // Found @0xff5ae534, levent 0x101
//    { 2, KEY_VIDEO           ,0x00000400 }, // Found @0xff5ae544, levent 0x02
//    { 2, KEY_SET             ,0x00000800 }, // Found @0xff5ae54c, levent 0x0a
//    { 2, KEY_LEFT            ,0x00001000 }, // Found @0xff5ae554, levent 0x08
//    { 2, KEY_UP              ,0x00002000 }, // Found @0xff5ae55c, levent 0x06
//    { 2, KEY_RIGHT           ,0x00004000 }, // Found @0xff5ae564, levent 0x09
//    { 2, KEY_DOWN            ,0x00008000 }, // Found @0xff5ae56c, levent 0x07
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#define CAM_RAW_ROWPIX    5248 // Found @0xff1a9348
//#define CAM_RAW_ROWS      3920 // Found @0xff1a9350
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff025d7c
//#define CAM_DATE_FOLDER_NAMING 0x080 // Found @0xff3194a8 (pass as 3rd param to GetImageFolder)
//#define PARAM_CAMERA_NAME 3 // Found @0xff6bcc94
//#define CAM_3ARG_DebugAssert 1
//#define CAM_HAS_WIFI 1 // Firmware has wifi support (only define if camera has hardware)

// Below goes in 'filewrite.c' or 'platform_camera.h':
//#define MAX_CHUNKS_FOR_FWT 7 // Found @0xff32ffd4

// Known propcases
// //      PROPCASE_AFSTEP 13
// #define PROPCASE_FOCUS_STATE 18
// #define PROPCASE_AV 23
// #define PROPCASE_BV 40
// //      PROPCASE_DELTA_DIGITALGAIN 84
// #define PROPCASE_DELTA_SV 86
// //      PROPCASE_DELTA_ND 87
// #define PROPCASE_EV_CORRECTION_2 218
// #define PROPCASE_ORIENTATION_SENSOR 230
// #define PROPCASE_SV_MARKET 257
//         PROPCASE_SVFIX not found
// #define PROPCASE_TV 274
// Guessed propset: 10

// Misc stuff
DEF(ctypes, 0xff5ab7f0)

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

// ISR flag: 0x194c, pointer to current task's control block: 0x1948
// pointer to TCB area: 0x19cc, found @ 0xff769330

// LED table init @ 0xff1829ec
// LED #1: 0xc022d200 (#98 in GPIO table), offset 0x98
// LED #2: 0xc022d1fc (#97 in GPIO table), offset 0x8
// GPIO table @ 0xff5adf8c

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NHSTUB(AllocateUncacheableMemory              ,0xff025d38) //112
NHSTUB(Close                                  ,0xff027218) //120
NHSTUB(CreateBinarySemaphore                  ,0x006b792c) //115
NHSTUB(CreateTask                             ,0x006b5714) //120
NHSTUB(DebugAssert                            ,0x006b5ac8) //107
NHSTUB(DeleteDirectory_Fut                    ,0xff026b0c) //116
NHSTUB(DeleteSemaphore                        ,0x006b7a10) //120
NHSTUB(DoAELock                               ,0xff032714) //120
NHSTUB(DoAFLock                               ,0xff0323c8) //120
NHSTUB(EnterToCompensationEVF                 ,0xff03263c) //104
NHSTUB(ExecuteEventProcedure                  ,0xff0347f4) //104
NHSTUB(ExitFromCompensationEVF                ,0xff032690) //104
NHSTUB(ExitTask                               ,0x006b5a68) //120
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff0433ac) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff0435e4) //104
NHSTUB(Fclose_Fut                             ,0xff026ba4) //120
NHSTUB(Feof_Fut                               ,0xff026d90) //  1
NHSTUB(Fflush_Fut                             ,0xff026dcc) //  1
NHSTUB(Fgets_Fut                              ,0xff026cf8) //  6
NHSTUB(Fopen_Fut                              ,0xff026b64) //120
NHSTUB(Fread_Fut                              ,0xff026c50) //120
NHSTUB(FreeUncacheableMemory                  ,0xff025d74) //112
NHSTUB(Fseek_Fut                              ,0xff026d44) //120
NHSTUB(Fwrite_Fut                             ,0xff026ca4) //120
NHSTUB(GetBatteryTemperature                  ,0xff075b98) //102
NHSTUB(GetCCDTemperature                      ,0xff075b20) //102
NHSTUB(GetCurrentAvValue                      ,0xff08e928) //120
NHSTUB(GetCurrentShutterSpeed                 ,0xff122618) //120
NHSTUB(GetUsableMaxAv                         ,0xff1a9b50) //120
NHSTUB(GetUsableMinAv                         ,0xff1a9b34) //120
NHSTUB(GetDrive_ClusterSize                   ,0xff030510) //122
NHSTUB(GetDrive_FreeClusters                  ,0xff030c7c) //119
NHSTUB(GetDrive_TotalClusters                 ,0xff030c50) //122
NHSTUB(GetFocusLensSubjectDistance            ,0xff1d4e7c) //102
NHSTUB(GetImageFolder                         ,0xff1b16fc) //122
NHSTUB(GetKbdState                            ,0xff071fe8) //109
NHSTUB(GetMemInfo                             ,0xff023450) //115
NHSTUB(GetOpticalTemperature                  ,0xff075c10) //120
NHSTUB(GetParameterData                       ,0xff1fa4e0) //101
NHSTUB(GetPropertyCase                        ,0xff0a8ef4) //101
NHSTUB(GetSystemTime                          ,0xff354c98) //120
NHSTUB(GetVRAMHPixelsSize                     ,0xff04f018) //120
NHSTUB(GetVRAMVPixelsSize                     ,0xff04f024) //120
NHSTUB(GetZoomLensCurrentPoint                ,0xff1d8118) //120
NHSTUB(GetZoomLensCurrentPosition             ,0xff3438d0) //102
NHSTUB(GiveSemaphore                          ,0x006b7bb0) //120
NHSTUB(IsStrobeChargeCompleted                ,0xff0d7184) //102
NHSTUB(LEDDrive                               ,0xff1e1f2c) //120
NHSTUB(LocalTime                              ,0x006b9ad8) //115
NHSTUB(LockMainPower                          ,0xff0ab9a0) //120
NHSTUB(MakeSDCardBootable                     ,0xff031184) //105
NHSTUB(MoveFocusLensToDistance                ,0xff43c8f0) //102
NHSTUB(MoveIrisWithAv                         ,0xff34e08c) //120
NHSTUB(MoveZoomLensWithPoint                  ,0xff34e9f8) //120
NHSTUB(MoveOpticalZoomAt                      ,0xff031ce8) //109
NHSTUB(Open                                   ,0xff0271b4) //120
NHSTUB(PB2Rec                                 ,0xff05bb8c) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff1e30a0) //102
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff1e3070) //102
NHSTUB(PT_PlaySound                           ,0xff0ba3e0) //122
NHSTUB(PostLogicalEventForNotPowerType        ,0xff0aae44) //120
NHSTUB(PostLogicalEventToUI                   ,0xff0aae9c) //120
NHSTUB(PutInNdFilter                          ,0xff34e7b0) //102
NHSTUB(PutOutNdFilter                         ,0xff34e7d4) //102
NHSTUB(Read                                   ,0xff023f0c) //120
NHSTUB(ReadFastDir                            ,0xff331a84) //115
NHSTUB(Rec2PB                                 ,0xff05bbe4) //104
NHSTUB(RenameFile_Fut                         ,0xff026a04) //116
NHSTUB(Restart                                ,0xff03788c) //122
NHSTUB(ScreenLock                             ,0xff0af628) //117
NHSTUB(ScreenUnlock                           ,0xff0af67c) //117
NHSTUB(SetAE_ShutterSpeed                     ,0xff43797c) //102
NHSTUB(SetAutoShutdownTime                    ,0xff0aba14) //120
NHSTUB(SetCurrentCaptureModeType              ,0xff0b6ee8) //120
NHSTUB(SetDate                                ,0xff43980c) //120
NHSTUB(SetFileAttributes                      ,0xff027714) //  6
NHSTUB(SetFileTimeStamp                       ,0xff02769c) //  6
NHSTUB(SetLogicalEventActive                  ,0xff0ab50c) //120
NHSTUB(SetParameterData                       ,0xff1fa444) //101
NHSTUB(SetPropertyCase                        ,0xff0a8d14) //101
NHSTUB(SetScriptMode                          ,0xff0ab560) //120
NHSTUB(SleepTask                              ,0x006b8f0c) //120
NHSTUB(TakeSemaphore                          ,0x006b7ad4) //120
NHSTUB(TurnOnDisplay                          ,0xff06cc68) //120
NHSTUB(TurnOffDisplay                         ,0xff06cc78) //120
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff2185e8) //120
NHSTUB(UnlockAE                               ,0xff0327a0) //120
NHSTUB(UnlockAF                               ,0xff0323f8) //120
NHSTUB(UnlockMainPower                        ,0xff0ab8f8) //120
NHSTUB(VbattGet                               ,0xff02b0b4) //120
NHSTUB(Write                                  ,0xff027160) //120
NHSTUB(WriteSDCard                            ,0x006ba9d0) //108
NHSTUB(_log                                   ,0x006de580) //111
NHSTUB(_log10                                 ,0x006deac0) //112
NHSTUB(_pow                                   ,0x006dec38) //121
NHSTUB(_sqrt                                  ,0x006e0a50) //  6
NHSTUB(add_ptp_handler                        ,0xff14b720) //121
NHSTUB(apex2us                                ,0xff2c9d14) //121
NHSTUB(err_init_task                          ,0xff0247d8) //111
NHSTUB(exmem_alloc                            ,0xff0343d8) //101
NHSTUB(exmem_ualloc                           ,0xff03423c) //101
NHSTUB(exmem_ufree                            ,0xff034384) //101
NHSTUB(free                                   ,0xff025084) //112
NHSTUB(get_nd_value                           ,0xff340f9c) //123
NHSTUB(get_current_nd_value                   ,0xff340f3c) //122
NHSTUB(get_current_deltasv                    ,0xff11edf0) //122
NHSTUB(GetCurrentDriveBaseSvValue             ,0xff0d0b8c) //120
NHSTUB(kbd_p1_f                               ,0xff02c388) //109
NHSTUB(kbd_p1_f_cont                          ,0xff02c394) //109
NHSTUB(kbd_p2_f                               ,0xff02ba50) //109
NHSTUB(kbd_read_keys                          ,0xff02c338) //109
NHSTUB(kbd_read_keys_r2                       ,0xff0719b4) //109
NHSTUB(lseek                                  ,0xff02752c) //120
NHSTUB(malloc                                 ,0xff02502c) //112
NHSTUB(memcmp                                 ,0xff024e04) //120
NHSTUB(memcpy                                 ,0xff0be77c) //120
NHSTUB(memset                                 ,0xff28a874) //120
NHSTUB(mkdir                                  ,0xff0277ac) //121
NHSTUB(mktime_ext                             ,0xff0bdf0c) //  1
NHSTUB(OpenFastDir                            ,0xff331930) //115
NHSTUB(closedir                               ,0xff3318e0) //121
NHSTUB(get_fstype                             ,0xff030488) //122
NHSTUB(qsort                                  ,0xff28a814) //  6
NHSTUB(rand                                   ,0xff0be74c) //121
NHSTUB(realloc                                ,0xff28a8f0) //115
NHSTUB(reboot_fw_update                       ,0xff3537cc) //106
NHSTUB(set_control_event                      ,0xff0ab1cc) //111
NHSTUB(srand                                  ,0xff0be740) //122
NHSTUB(stat                                   ,0xff027574) //109
NHSTUB(strcat                                 ,0xff0381e4) //  1
NHSTUB(strchr                                 ,0xff03826c) //  1
NHSTUB(strcmp                                 ,0xff024f00) //120
NHSTUB(strcpy                                 ,0xff024dec) //120
NHSTUB(strftime                               ,0xff0bdf8c) //113
NHSTUB(strlen                                 ,0xff024f44) //120
NHSTUB(strncmp                                ,0xff038220) //  1
NHSTUB(strncpy                                ,0xff027e8c) //  1
NHSTUB(strrchr                                ,0xff0be8c8) //  1
NHSTUB(strtol                                 ,0xff0381d0) //101
NHSTUB(strtolx                                ,0xff037fd4) //109
   DEF(task_CaptSeq                           ,0xff096768) //120
   DEF(task_DvlpSeqTask                       ,0xff1e7344) //120
   DEF(task_ExpDrv                            ,0xff0efc80) //120
   DEF(task_FileWrite                         ,0xff32ff78) //120
   DEF(task_InitFileModules                   ,0xff05e6d8) //120
   DEF(task_MovieRecord                       ,0xff1e10d4) //120
   DEF(task_PhySw                             ,0xff02be20) //120
   DEF(hook_CreateTask                        ,0x006b5714) //105
NHSTUB(time                                   ,0x006b92ac) //119
NHSTUB(vsprintf                               ,0xff027e4c) //115
NHSTUB(EngDrvRead                             ,0xff02c498) //102
NHSTUB(PTM_GetCurrentItem                     ,0xff0ad6c8) //105
NHSTUB(DisableISDriveError                    ,0xff34fd54) //120
NHSTUB(CancelHPTimer                          ,0xff0a563c) //119
NHSTUB(SetHPTimerAfterNow                     ,0xff0a5534) //119
NHSTUB(SS_MFOn                                ,0xff1e3134) //120
NHSTUB(SS_MFOff                               ,0xff1e3144) //120
NHSTUB(GetAdChValue                           ,0xff06de98) //120
NHSTUB(get_ptp_buf_size                       ,0xff13b8c0) //122
NHSTUB(get_ptp_file_buf                       ,0xff2dc830) //121
NHSTUB(SetVideoOutType                        ,0xff4381a0) //109
NHSTUB(GetVideoOutType                        ,0xff438114) //120
NHSTUB(IsWirelessConnect                      ,0xff061218) //122
