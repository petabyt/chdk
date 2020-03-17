// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R52 (DRYOS version 2.3, release #0052)
//   Firmware Ver GM1.01A   // Found @ 0xff08455c, "GM1.01A" @ 0xff084569
//   Firmware build timestamp: Sep 13 2013 12:46:12
//   Canon PowerShot SX510 HS

// Values for makefile.inc
//   DIGIC = 40# DIGIC 4
//   PLATFORMOSVER = 52
//   PLATFORMID = 12919# (0x3277) Found @ 0xfff40040
//   MAXRAMADDR = 0x07ffffff
//   MEMISOSTART = 0x00265a28
//   KEYSYS = d4e# Found @ 0xffff39bc
//   NEED_ENCODED_DISKBOOT = 11# Found @ 0xffff39cc
//   ARAM_HEAP_START = 0x60e000# Found @ 0xff1e2aec
//   ARAM_HEAP_SIZE  = 0x22000# Found @ 0xff1e2aac

// Detected address ranges:
// ROM      0xff000000 - 0xffffffff (16777216 bytes)
// RAM code 0x006b1000 - 0x006db5d0 copied from 0xff71925c ( 173520 bytes)
// RAM data 0x00001900 - 0x00017ba8 copied from 0xff702fb4 (  90792 bytes)

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NHSTUB(DeleteFile_Fut                       ,0xff006c18) //  1 90%        == 0xff006c18
//NHSTUB(GetFocusLensSubjectDistanceFromLens  ,0xff1c481c) //  3 90%        == 0xff1c481c
// ERROR: MakeDirectory_Fut is not found.                  //--- ---    *** != 0xff007728
// ERROR: RefreshPhysicalScreen is not found.              //--- ---    *** != 0x00000000
// ERROR: WriteSDCard is not found.                        //--- ---    *** != 0xff06506c

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff378390 -> ff63f61c
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x000188d4) // Found @0xff00c0c4
DEF(physw_run                               ,0x00001cfc) // Found @0xff00bc10
DEF(physw_sleep_delay                       ,0x00001d04) // Found @0xff00bc10
DEF(levent_table                            ,0xff5d5a54) // Found @0xff5d5a54
DEF(FlashParamsTable                        ,0xff63f89c) // Found @0xff63f89c
DEF(movie_status                            ,0x0000921c) // Found @0xff1d3b2c
DEF(video_compression_rate                  ,0x0000924c) // Found @0xff1d4da0
DEF(full_screen_refresh                     ,0x00009a50) // Found @0xff1f6d38
DEF(canon_menu_active                       ,0x00004168) // Found @0xff08e7f4
DEF(canon_shoot_menu_active                 ,0x0000b97d) // Found @0xff270148
DEF(playrec_mode                            ,0x00003778) // Found @0xff079f4c
DEF(zoom_status                             ,0x0000d9d4) // Found @0xff2faefc
DEF(some_flag_for_af_scan                   ,0x00024214) // Found @0xff370a48
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 2 int value(s), the first is the zoom focus length.
// there are 127 entries in the table - set NUM_FL to 127
DEF(focus_len_table                         ,0xfff4ad54) // Found @0xfff4ad54
DEF(zoom_busy                               ,0x0000354c) // Found @0xff06ce34
DEF(focus_busy                              ,0x00008d14) // Found @0xff1c3288
// Palette colour tables  found @ 0xff5d9e9c
// Camera has 2 RAW buffers @ 0x416b272c & 0x46004944
//  Note: active buffer --> raw_buffers[active_raw_buffer]
//        other buffer  --> raw_buffers[active_raw_buffer^1]
DEF(raw_buffers                             ,0xff590a98) // Found @0xff590a98
DEF(active_raw_buffer                       ,0x000036c4) // Found @0xff075014
DEF(fileio_semaphore                        ,0x00001d90) // Found @0xff00ebec
DEF(exmem_alloc_table                       ,0x00019cd4) // Found @0xff013d64
DEF(exmem_types_table                       ,0xff7034d8) // Found @0x00001e24
DEF_CONST(exmem_type_count                  ,0x0000001b)
DEF(imager_active                           ,0x000020fc) // Found @0xff02cd08 (0x20f8 + 4)
DEF_CONST(uiprop_count                      ,0x00000094) // Found @0xff1ea960

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x406f1000; }             // Found @0xff049118
//void *vid_get_viewport_fb()      { return (void*)0x40846b80; }             // Found @0xff44bc0c
DEF(jpeg_count_str                          ,0x000ef918) // Found @0xff257784
//char *camera_jpeg_count_str()    { return (char*)0x000ef918; }             // Found @0xff257784
//int get_flash_params_count(void) { return 0x99; }                          // Found @0xff1eb3e4

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x02000000 // Found @0xff568748, levent 0x20a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x10000000 // Found @0xff568758, levent 0x202
//#define USB_IDX             2
//#define BATTCOVER_FLAG      0x04000000 // Found @0xff568750, levent 0x205
//#define BATTCOVER_IDX       2
//#define ANALOG_AV_FLAG      0x04000000 // Found @0xff568700, levent 0x200 (non-inverted logic)
//#define ANALOG_AV_IDX       1

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_UP              ,0x00000400 }, // Found @0xff5686a8, levent 0x06
//    { 0, KEY_DOWN            ,0x00000800 }, // Found @0xff5686b0, levent 0x07
//    { 0, KEY_SET             ,0x00001000 }, // Found @0xff5686b8, levent 0x0a
//    { 0, KEY_RIGHT           ,0x00002000 }, // Found @0xff5686c0, levent 0x09
//    { 0, KEY_MENU            ,0x00008000 }, // Found @0xff5686d0, levent 0x0b
//    { 0, KEY_LEFT            ,0x00010000 }, // Found @0xff5686d8, levent 0x08
//    { 0, KEY_VIDEO           ,0x00020000 }, // Found @0xff5686e0, levent 0x02
//    { 0, KEY_DISPLAY         ,0x00040000 }, // Found @0xff5686e8, levent 0x0c
//    { 0, KEY_ERASE           ,0x00080000 }, // Found @0xff5686f0, levent 0x19
//    { 2, KEY_POWER           ,0x00000002 }, // Found @0xff568708, levent 0x100
//    { 2, KEY_PLAYBACK        ,0x00000008 }, // Found @0xff568710, levent 0x101
//    { 2, KEY_SHOOT_FULL      ,0x00000600 }, // Found @0xff568720, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000400 }, // Found @0xff568720, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00000200 }, // Found @0xff568718, levent 0x00
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#define CAM_RAW_ROWPIX    4168 // Found @0xff196e7c
//#define CAM_RAW_ROWS      3062 // Found @0xff196e88
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff005f4c
//#define CAM_DATE_FOLDER_NAMING 0x080 // Found @0xff32f684 (pass as 3rd param to GetImageFolder)
//#define PARAM_CAMERA_NAME 3 // Found @0xff63ea74
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
DEF(ctypes, 0xff567b4c)

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
// pointer to TCB area: 0x19c4, found @ 0xff71a8cc

// LED table init @ 0xff175150
// LED #1: 0xc022302c, offset 0x4
// LED #2: 0xc0223030, offset 0x104

// For capt_seq.c
DEF(_nrflag,0xcf68) // Found @ ff2adf48 (0xcf70) & ff2adf60 (-0x08)
//static long *nrflag = (long*)(0xcf70-0x08);  // Found @ ff2adf48 & ff2adf58

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NHSTUB(AllocateUncacheableMemory              ,0xff005f08) //112
NHSTUB(Close                                  ,0xff00728c) //120
NHSTUB(CreateBinarySemaphore                  ,0x006b7968) //115
NHSTUB(CreateTask                             ,0x006b5778) //120
//NHSTUB(DebugAssert                          ,0x006b5a58) //107            == 0x006b5a58
NHSTUB(DeleteDirectory_Fut                    ,0xff006c8c) //116
NHSTUB(DoAELock                               ,0xff012828) //120
NHSTUB(DoAFLock                               ,0xff012490) //120
NHSTUB(EnterToCompensationEVF                 ,0xff012780) //104
NHSTUB(ExecuteEventProcedure                  ,0xff014820) //104
NHSTUB(ExitFromCompensationEVF                ,0xff0127c8) //104
NHSTUB(ExitTask                               ,0x006b5a04) //120
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff0254d4) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff025648) //104
NHSTUB(Fclose_Fut                             ,0xff006d24) //120
NHSTUB(Feof_Fut                               ,0xff006f10) //  1
NHSTUB(Fflush_Fut                             ,0xff006f4c) //  1
NHSTUB(Fgets_Fut                              ,0xff006e78) //  6
NHSTUB(Fopen_Fut                              ,0xff006ce4) //120
NHSTUB(Fread_Fut                              ,0xff006dd0) //120
NHSTUB(FreeUncacheableMemory                  ,0xff005f44) //112
NHSTUB(Fseek_Fut                              ,0xff006ec4) //120
NHSTUB(Fwrite_Fut                             ,0xff006e24) //120
NHSTUB(GetBatteryTemperature                  ,0xff053244) //102
NHSTUB(GetCCDTemperature                      ,0xff0531cc) //102
NHSTUB(GetCurrentAvValue                      ,0xff06a6c8) //120
NHSTUB(GetCurrentShutterSpeed                 ,0xff0c76c0) //120
NHSTUB(GetUsableMaxAv                         ,0xff1978e0) //120
NHSTUB(GetUsableMinAv                         ,0xff1978c4) //120
NHSTUB(GetDrive_ClusterSize                   ,0xff010278) //122
NHSTUB(GetDrive_FreeClusters                  ,0xff010a90) //119
NHSTUB(GetDrive_TotalClusters                 ,0xff010a64) //122
NHSTUB(GetFocusLensSubjectDistance            ,0xff1c4438) //102
NHSTUB(GetImageFolder                         ,0xff19ea90) //122
NHSTUB(GetKbdState                            ,0xff04f49c) //109
NHSTUB(GetMemInfo                             ,0xff0036e4) //115
NHSTUB(GetOpticalTemperature                  ,0xff0532bc) //120
NHSTUB(GetParameterData                       ,0xff1eb3a0) //101
NHSTUB(GetPropertyCase                        ,0xff085d9c) //101
NHSTUB(GetSystemTime                          ,0xff3753d4) //120
NHSTUB(GetVRAMHPixelsSize                     ,0xff032c20) //120
NHSTUB(GetVRAMVPixelsSize                     ,0xff032c2c) //120
NHSTUB(GetZoomLensCurrentPoint                ,0xff06d2b4) //120
NHSTUB(GetZoomLensCurrentPosition             ,0xff1cca18) //102
NHSTUB(GiveSemaphore                          ,0x006b7bc8) //120
NHSTUB(IsStrobeChargeCompleted                ,0xff0f8e88) //102
NHSTUB(LEDDrive                               ,0xff1d6530) //120
NHSTUB(LocalTime                              ,0x006b9a38) //115
NHSTUB(LockMainPower                          ,0xff08a2fc) //120
NHSTUB(MoveFocusLensToDistance                ,0xff44752c) //102
NHSTUB(MoveIrisWithAv                         ,0xff36e960) //120
NHSTUB(MoveZoomLensWithPoint                  ,0xff36f37c) //120
NHSTUB(MoveOpticalZoomAt                      ,0xff011ab0) //109
NHSTUB(Open                                   ,0xff0071c4) //120
NHSTUB(PB2Rec                                 ,0xff03e120) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff1d7664) //102
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff1d7634) //102
NHSTUB(PT_PlaySound                           ,0xff09ad18) //122
NHSTUB(PostLogicalEventForNotPowerType        ,0xff087c30) //120
NHSTUB(PostLogicalEventToUI                   ,0xff087c7c) //120
NHSTUB(PutInNdFilter                          ,0xff445fb4) //102
NHSTUB(PutOutNdFilter                         ,0xff445ff0) //102
NHSTUB(Read                                   ,0xff0041a0) //120
NHSTUB(ReadFastDir                            ,0xff34cd90) //115
NHSTUB(Rec2PB                                 ,0xff03e160) //104
NHSTUB(RenameFile_Fut                         ,0xff006b84) //116
//NHSTUB(Restart                              ,0xff01786c) //122            == 0xff01786c
NHSTUB(ScreenLock                             ,0xff08dfe8) //117
NHSTUB(ScreenUnlock                           ,0xff08dfa0) //117
NHSTUB(SetAE_ShutterSpeed                     ,0xff44aa84) //102
NHSTUB(SetAutoShutdownTime                    ,0xff08a374) //120
NHSTUB(SetCurrentCaptureModeType              ,0xff097b68) //120
NHSTUB(SetFileAttributes                      ,0xff007690) //  6
NHSTUB(SetFileTimeStamp                       ,0xff007618) //  6
NHSTUB(SetLogicalEventActive                  ,0xff08a038) //120
NHSTUB(SetParameterData                       ,0xff1eb304) //101
NHSTUB(SetPropertyCase                        ,0xff085bfc) //101
NHSTUB(SetScriptMode                          ,0xff08a08c) //120
NHSTUB(SleepTask                              ,0x006b8d2c) //120
NHSTUB(TakeSemaphore                          ,0x006b7af0) //120
NHSTUB(TurnOffBackLight                       ,0xff09a5bc) //104
NHSTUB(TurnOnBackLight                        ,0xff09a5a4) //104
NHSTUB(TurnOnDisplay                          ,0xff04953c) //120
NHSTUB(TurnOffDisplay                         ,0xff04954c) //120
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff20b360) //120
NHSTUB(UnlockAE                               ,0xff01284c) //120
NHSTUB(UnlockAF                               ,0xff0124c0) //120
NHSTUB(UnlockMainPower                        ,0xff08a24c) //120
NHSTUB(VbattGet                               ,0xff00ae40) //120
NHSTUB(Write                                  ,0xff0072e0) //120
NHSTUB(_log                                   ,0x006d7138) //111
NHSTUB(_log10                                 ,0x006d7678) //112
NHSTUB(_pow                                   ,0x006d77f0) //121
NHSTUB(_sqrt                                  ,0x006d9608) //  6
NHSTUB(add_ptp_handler                        ,0xff132204) //121
NHSTUB(apex2us                                ,0xff2a7800) //121
NHSTUB(close                                  ,0xff003ffc) //109
NHSTUB(err_init_task                          ,0xff004a90) //111
NHSTUB(exmem_alloc                            ,0xff01436c) //101
NHSTUB(exmem_free                             ,0xff0143e4) //101
NHSTUB(free                                   ,0xff005338) //112
NHSTUB(kbd_p1_f                               ,0xff00c114) //109
NHSTUB(kbd_p1_f_cont                          ,0xff00c120) //109
NHSTUB(kbd_p2_f                               ,0xff00b8a8) //109
NHSTUB(kbd_read_keys                          ,0xff00c0c4) //109
NHSTUB(kbd_read_keys_r2                       ,0xff04ec64) //109
NHSTUB(lseek                                  ,0xff0074a8) //120
NHSTUB(malloc                                 ,0xff0052e0) //112
NHSTUB(memcmp                                 ,0xff0050b8) //120
NHSTUB(memcpy                                 ,0xff09fcac) //120
NHSTUB(memset                                 ,0xff27b254) //120
NHSTUB(mkdir                                  ,0xff007728) //121
NHSTUB(mktime_ext                             ,0xff09f440) //  1
NHSTUB(open                                   ,0xff003f4c) //109
NHSTUB(OpenFastDir                            ,0xff34cc3c) //115
NHSTUB(closedir                               ,0xff34cbec) //121
NHSTUB(get_fstype                             ,0xff0101f0) //122
NHSTUB(qsort                                  ,0xff27b1f4) //  6
NHSTUB(rand                                   ,0xff27ad2c) //121
NHSTUB(realloc                                ,0xff27b2d0) //115
NHSTUB(reboot_fw_update                       ,0xff374a20) //106
NHSTUB(set_control_event                      ,0xff089c2c) //111
NHSTUB(srand                                  ,0xff27ad20) //122
NHSTUB(stat                                   ,0xff0074f0) //109
NHSTUB(strcat                                 ,0xff018254) //  1
NHSTUB(strchr                                 ,0xff0182dc) //  1
NHSTUB(strcmp                                 ,0xff0051b4) //120
NHSTUB(strcpy                                 ,0xff0050a0) //120
NHSTUB(strftime                               ,0xff09f48c) //113
NHSTUB(strlen                                 ,0xff0051f8) //120
NHSTUB(strncmp                                ,0xff018290) //  1
NHSTUB(strncpy                                ,0xff007e20) //  1
NHSTUB(strrchr                                ,0xff09fdf8) //  1
NHSTUB(strtol                                 ,0xff018240) //101
NHSTUB(strtolx                                ,0xff018044) //109
   DEF(task_CaptSeq                           ,0xff072dc4) //120
   DEF(task_DvlpSeqTask                       ,0xff1db420) //120
   DEF(task_ExpDrv                            ,0xff0dece0) //120
   DEF(task_FileWrite                         ,0xff348704) //120
   DEF(task_InitFileModules                   ,0xff03e99c) //120
   DEF(task_MovieRecord                       ,0xff1d527c) //120
   DEF(task_PhySw                             ,0xff00bc0c) //120
   DEF(task_RotaryEncoder                     ,0xff04f774) //120
   DEF(hook_CreateTask                        ,0x006b5778) //105
NHSTUB(time                                   ,0x006b9210) //119
NHSTUB(vsprintf                               ,0xff007de0) //115
NHSTUB(EngDrvRead                             ,0xff00c220) //102
NHSTUB(PTM_GetCurrentItem                     ,0xff08bfe4) //105
NHSTUB(DisableISDriveError                    ,0xff36fe90) //120
NHSTUB(CancelHPTimer                          ,0xff082604) //119
NHSTUB(SetHPTimerAfterNow                     ,0xff0824fc) //119
NHSTUB(SS_MFOn                                ,0xff1d76f8) //120
NHSTUB(SS_MFOff                               ,0xff1d7708) //120
NHSTUB(GetAdChValue                           ,0xff04a8a8) //120
NHSTUB(EnableHDMIPower                        ,0xff04d47c) //123
NHSTUB(DisableHDMIPower                       ,0xff04d4d0) //123
NHSTUB(get_ptp_buf_size                       ,0xff12d60c) //122
NHSTUB(get_ptp_file_buf                       ,0xff2ea98c) //121
