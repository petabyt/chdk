// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R57 (DRYOS version 2.3, release #0057)
//   Firmware Ver GM1.00A   // Found @ 0xff0aaf88, "GM1.00A" @ 0xff0aaf95
//   Firmware build timestamp: Nov 27 2014 13:29:00
//   Canon PowerShot SX610 HS

// Values for makefile.inc
//   DIGIC = 41# DIGIC 4+
//   PLATFORMOSVER = 57
//   PLATFORMID = 12967# (0x32a7) Found @ 0xfffe0040
//   MAXRAMADDR = 0x1fffffff
//   MEMISOSTART = 0x002ce584
//   KEYSYS = d4g# Found @ 0xff014590
//   NEED_ENCODED_DISKBOOT = 13# Found @ 0xff0145a0
//   ARAM_HEAP_START = 0x60e000# Found @ 0xff228d60
//   ARAM_HEAP_SIZE  = 0x22000# Found @ 0xff228d20

// Detected address ranges:
// ROM      0xff010000 - 0xffffffff (16711680 bytes)
// RAM code 0x006b1000 - 0x006e2d28 copied from 0xff864ff4 ( 204072 bytes)
// RAM data 0x00001900 - 0x00018ae4 copied from 0xff84de10 (  94692 bytes)

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
NHSTUB(DeleteFile_Fut                         ,0xff026984) //  1 90%
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff205078) //  3 90%
// ERROR: MakeDirectory_Fut is not found.                  //--- ---    *** != 0xff027494
// ERROR: RefreshPhysicalScreen is not found.              //--- ---    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff3ca584 -> ff7b791c
// Mode 33337 in firmware but not in current modemap
// Mode 33332 in firmware but not in current modemap
// Mode 33334 in firmware but not in current modemap
// Mode 33333 in firmware but not in current modemap

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00019804) // Found @0xff02bdfc
DEF(physw_run                               ,0x00001c9c) // Found @0xff02b8e0
DEF(physw_sleep_delay                       ,0x00001ca4) // Found @0xff02b8e0
DEF(levent_table                            ,0xff687dc4) // Found @0xff687dc4
DEF(FlashParamsTable                        ,0xff7b7c80) // Found @0xff7b7c80
DEF(movie_status                            ,0x0000a3b4) // Found @0xff210060
DEF(video_compression_rate                  ,0x0000a364) // Found @0xff210ae4
DEF(full_screen_refresh                     ,0x0000b290) // Found @0xff23ba54
DEF(canon_menu_active                       ,0x0000410c) // Found @0xff0b571c
DEF(canon_shoot_menu_active                 ,0x0000d185) // Found @0xff2ba540
DEF(zoom_status                             ,0x0000e5ac) // Found @0xff338c10
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 2 int value(s), the first is the zoom focus length.
// there are 101 entries in the table - set NUM_FL to 101
DEF(focus_len_table                         ,0xfffed67c) // Found @0xfffed67c
DEF(zoom_busy                               ,0x0000a110) // Found @0xff2076d4
DEF(focus_busy                              ,0x00009fd8) // Found @0xff2039f8
// Palette colour tables  found @ 0xff68eb74
// Camera has 2 RAW buffers @ 0x48000000 & 0x561c9d00
//  Note: active buffer --> raw_buffers[active_raw_buffer]
//        other buffer  --> raw_buffers[active_raw_buffer^1]
DEF(raw_buffers                             ,0xff641f00) // Found @0xff641f00
DEF(active_raw_buffer                       ,0x00003b2c) // Found @0xff09bcb4
DEF(fileio_semaphore                        ,0x00001d40) // Found @0xff02eaec
DEF(exmem_alloc_table                       ,0x0001ab94) // Found @0xff0339ac
DEF(exmem_types_table                       ,0xff84e2e4) // Found @0x00001dd4
DEF_CONST(exmem_type_count                  ,0x0000001f)
DEF(imager_active                           ,0x0000208c) // Found @0xff04c0a8 (0x2088 + 4)
DEF_CONST(uiprop_count                      ,0x000000ce) // Found @0xff23155c

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x40711000; }             // Found @0xff06da58
//void *vid_get_viewport_fb()      { return (void*)0x40866b80; }             // Found @0xff4c6db0
DEF(jpeg_count_str                          ,0x001557fc) // Found @0xff2a2e78
//char *camera_jpeg_count_str()    { return (char*)0x001557fc; }             // Found @0xff2a2e78
//int get_flash_params_count(void) { return 0xe3; }                          // Found @0xff2320d0

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00400000 // Found @0xff636634, levent 0x20a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x01000000 // Found @0xff636644, levent 0x202
//#define USB_IDX             2
//#define BATTCOVER_FLAG      0x00800000 // Found @0xff63663c, levent 0x205
//#define BATTCOVER_IDX       2
//#define ANALOG_AV_FLAG      0x00000040 // Found @0xff63657c, levent 0x200 (non-inverted logic)
//#define ANALOG_AV_IDX       0

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_VIDEO           ,0x00000004 }, // Found @0xff636564, levent 0x02
//    { 0, KEY_SET             ,0x00000008 }, // Found @0xff63656c, levent 0x0a
//    { 0, KEY_MENU            ,0x00000080 }, // Found @0xff636584, levent 0x14
//    { 0, KEY_LEFT            ,0x00001000 }, // Found @0xff63658c, levent 0x08
//    { 0, KEY_UP              ,0x00002000 }, // Found @0xff636594, levent 0x06
//    { 0, KEY_RIGHT           ,0x00004000 }, // Found @0xff63659c, levent 0x09
//    { 0, KEY_DOWN            ,0x00008000 }, // Found @0xff6365a4, levent 0x07
//    { 2, KEY_SHOOT_FULL      ,0x00000060 }, // Found @0xff6365bc, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000040 }, // Found @0xff6365bc, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00000020 }, // Found @0xff6365b4, levent 0x00
//    { 2, KEY_PLAYBACK        ,0x00000080 }, // Found @0xff6365c4, levent 0x101
//    { 2, KEY_POWER           ,0x00000100 }, // Found @0xff6365cc, levent 0x100
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#define CAM_RAW_ROWPIX    5344 // Found @0xff1d507c
//#define CAM_RAW_ROWS      3950 // Found @0xff1d5088
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff025c5c
//#define CAM_DATE_FOLDER_NAMING 0x080 // Found @0xff37d4c0 (pass as 3rd param to GetImageFolder)
//#define PARAM_CAMERA_NAME 3 // Found @0xff7b67d4
//#define CAM_3ARG_DebugAssert 1

// Below goes in 'filewrite.c' or 'platform_camera.h':
//#define MAX_CHUNKS_FOR_JPEG 7 // Found @0xff3974e4

// Known propcases
// //      PROPCASE_AFSTEP 13
// #define PROPCASE_FOCUS_STATE 18
// #define PROPCASE_AV 23
// #define PROPCASE_BV 38
// //      PROPCASE_DELTA_DIGITALGAIN 82
// #define PROPCASE_DELTA_SV 84
// //      PROPCASE_DELTA_ND 85
// #define PROPCASE_EV_CORRECTION_2 216
// #define PROPCASE_ORIENTATION_SENSOR 228
// #define PROPCASE_SV_MARKET 255
// //      PROPCASE_SVFIX 256
// #define PROPCASE_TV 272
// Guessed propset: 7, 9

// Misc stuff
DEF(ctypes, 0xff632c90)

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
// pointer to TCB area: 0x19c4, found @ 0xff86659c

// LED table init @ 0xff1a029c
// LED #1: 0xc022d200 (#98 in GPIO table), offset 0x98
// LED #2: 0xc022d1fc (#97 in GPIO table), offset 0x8
// GPIO table @ 0xff635ff8

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NHSTUB(AllocateUncacheableMemory              ,0xff025c18) //112
NHSTUB(Close                                  ,0xff026ff8) //120
NHSTUB(CreateBinarySemaphore                  ,0x006b7884) //115
NHSTUB(CreateTask                             ,0x006b5658) //120
NHSTUB(DebugAssert                            ,0x006b59f8) //107
NHSTUB(DeleteDirectory_Fut                    ,0xff0269f8) //116
NHSTUB(DoAELock                               ,0xff0322ec) //120
NHSTUB(DoAFLock                               ,0xff031fb8) //120
NHSTUB(EnterToCompensationEVF                 ,0xff032250) //104
NHSTUB(ExecuteEventProcedure                  ,0xff034494) //104
NHSTUB(ExitFromCompensationEVF                ,0xff032298) //104
NHSTUB(ExitTask                               ,0x006b5994) //120
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff044064) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff044280) //104
NHSTUB(Fclose_Fut                             ,0xff026a90) //120
NHSTUB(Feof_Fut                               ,0xff026c7c) //  1
NHSTUB(Fflush_Fut                             ,0xff026cb8) //  1
NHSTUB(Fgets_Fut                              ,0xff026be4) //  6
NHSTUB(Fopen_Fut                              ,0xff026a50) //120
NHSTUB(Fread_Fut                              ,0xff026b3c) //120
NHSTUB(FreeUncacheableMemory                  ,0xff025c54) //112
NHSTUB(Fseek_Fut                              ,0xff026c30) //120
NHSTUB(Fwrite_Fut                             ,0xff026b90) //120
NHSTUB(GetBatteryTemperature                  ,0xff078860) //102
NHSTUB(GetCCDTemperature                      ,0xff0787e8) //102
NHSTUB(GetCurrentAvValue                      ,0xff091614) //120
NHSTUB(GetCurrentShutterSpeed                 ,0xff0db164) //120
NHSTUB(GetUsableMaxAv                         ,0xff1d5910) //120
NHSTUB(GetUsableMinAv                         ,0xff1d58f4) //120
NHSTUB(GetDrive_ClusterSize                   ,0xff030180) //122
NHSTUB(GetDrive_FreeClusters                  ,0xff030958) //119
NHSTUB(GetDrive_TotalClusters                 ,0xff03092c) //122
NHSTUB(GetFocusLensSubjectDistance            ,0xff204c94) //102
NHSTUB(GetImageFolder                         ,0xff1dd75c) //122
NHSTUB(GetKbdState                            ,0xff074a2c) //109
NHSTUB(GetMemInfo                             ,0xff023408) //115
NHSTUB(GetOpticalTemperature                  ,0xff0788d8) //120
NHSTUB(GetParameterData                       ,0xff23208c) //101
NHSTUB(GetPropertyCase                        ,0xff0ac894) //101
NHSTUB(GetSystemTime                          ,0xff3c75a0) //120
NHSTUB(GetVRAMHPixelsSize                     ,0xff050c68) //120
NHSTUB(GetVRAMVPixelsSize                     ,0xff050c74) //120
NHSTUB(GetZoomLensCurrentPoint                ,0xff207b58) //120
NHSTUB(GetZoomLensCurrentPosition             ,0xff3b06c4) //102
NHSTUB(GiveSemaphore                          ,0x006b7b04) //120
NHSTUB(IsStrobeChargeCompleted                ,0xff109238) //102
NHSTUB(LEDDrive                               ,0xff21a8c8) //120
NHSTUB(LocalTime                              ,0x006b9998) //115
NHSTUB(LockMainPower                          ,0xff0b1258) //120
NHSTUB(MakeSDCardBootable                     ,0xff030d68) //105
NHSTUB(MoveFocusLensToDistance                ,0xff4caa20) //102
NHSTUB(MoveIrisWithAv                         ,0xff3c0ef4) //120
NHSTUB(MoveZoomLensWithPoint                  ,0xff3c1850) //120
NHSTUB(MoveOpticalZoomAt                      ,0xff03192c) //109
NHSTUB(Open                                   ,0xff026f30) //120
NHSTUB(PB2Rec                                 ,0xff05d588) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff21ba64) //102
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff21ba34) //102
NHSTUB(PT_PlaySound                           ,0xff0c28ec) //122
NHSTUB(PostLogicalEventForNotPowerType        ,0xff0ae7e0) //120
NHSTUB(PostLogicalEventToUI                   ,0xff0ae838) //120
NHSTUB(PutInNdFilter                          ,0xff3c1608) //102
NHSTUB(PutOutNdFilter                         ,0xff3c162c) //102
NHSTUB(Read                                   ,0xff023ec4) //120
NHSTUB(ReadFastDir                            ,0xff398f60) //115
NHSTUB(Rec2PB                                 ,0xff05d5e0) //104
NHSTUB(RenameFile_Fut                         ,0xff0268f0) //116
NHSTUB(Restart                                ,0xff037528) //122
NHSTUB(ScreenLock                             ,0xff0b4e24) //117
NHSTUB(ScreenUnlock                           ,0xff0b4ddc) //117
NHSTUB(SetAE_ShutterSpeed                     ,0xff4c5b8c) //102
NHSTUB(SetAutoShutdownTime                    ,0xff0b12cc) //120
NHSTUB(SetCurrentCaptureModeType              ,0xff0bf550) //120
NHSTUB(SetDate                                ,0xff4c7a64) //120
NHSTUB(SetFileAttributes                      ,0xff0273fc) //  6
NHSTUB(SetFileTimeStamp                       ,0xff027384) //  6
NHSTUB(SetLogicalEventActive                  ,0xff0aeeb8) //120
NHSTUB(SetParameterData                       ,0xff231ff0) //101
NHSTUB(SetPropertyCase                        ,0xff0ac6bc) //101
NHSTUB(SetScriptMode                          ,0xff0aef0c) //120
NHSTUB(SleepTask                              ,0x006b8d54) //120
NHSTUB(TakeSemaphore                          ,0x006b7a2c) //120
NHSTUB(TurnOffBackLight                       ,0xff0c1f74) //104
NHSTUB(TurnOnBackLight                        ,0xff0c1fc0) //104
NHSTUB(TurnOnDisplay                          ,0xff06de50) //120
NHSTUB(TurnOffDisplay                         ,0xff06de60) //120
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff251a8c) //120
NHSTUB(UnlockAE                               ,0xff032310) //120
NHSTUB(UnlockAF                               ,0xff031fe8) //120
NHSTUB(UnlockMainPower                        ,0xff0b11b0) //120
NHSTUB(VbattGet                               ,0xff02ab7c) //120
NHSTUB(Write                                  ,0xff02704c) //120
NHSTUB(WriteSDCard                            ,0x006ba89c) //108
NHSTUB(_log                                   ,0x006ddda8) //111
NHSTUB(_log10                                 ,0x006de2e8) //112
NHSTUB(_pow                                   ,0x006de6b0) //121
NHSTUB(_sqrt                                  ,0x006e0788) //  6
NHSTUB(add_ptp_handler                        ,0xff15d8d4) //121
NHSTUB(apex2us                                ,0xff2d95bc) //121
NHSTUB(close                                  ,0xff023d20) //109
NHSTUB(err_init_task                          ,0xff0247a0) //111
NHSTUB(exmem_alloc                            ,0xff03407c) //101
NHSTUB(exmem_ualloc                           ,0xff033ee0) //101
NHSTUB(exmem_ufree                            ,0xff034028) //101
NHSTUB(free                                   ,0xff02504c) //112
NHSTUB(get_nd_value                           ,0xff3adc80) //123
NHSTUB(get_current_nd_value                   ,0xff3adc20) //122
NHSTUB(kbd_p1_f                               ,0xff02be4c) //109
NHSTUB(kbd_p1_f_cont                          ,0xff02be58) //109
NHSTUB(kbd_p2_f                               ,0xff02b53c) //109
NHSTUB(kbd_read_keys                          ,0xff02bdfc) //109
NHSTUB(kbd_read_keys_r2                       ,0xff0742a4) //109
NHSTUB(lseek                                  ,0xff027214) //120
NHSTUB(malloc                                 ,0xff024ff4) //112
NHSTUB(memcmp                                 ,0xff024dcc) //120
NHSTUB(memcpy                                 ,0xff0c7d1c) //120
NHSTUB(memset                                 ,0xff2d2ef0) //120
NHSTUB(mkdir                                  ,0xff027494) //121
NHSTUB(mktime_ext                             ,0xff0c7460) //  1
NHSTUB(open                                   ,0xff023c70) //109
NHSTUB(OpenFastDir                            ,0xff398e0c) //115
NHSTUB(closedir                               ,0xff398dbc) //121
NHSTUB(get_fstype                             ,0xff0300f8) //122
NHSTUB(qsort                                  ,0xff2d2e90) //  6
NHSTUB(rand                                   ,0xff0c7cec) //121
NHSTUB(realloc                                ,0xff2d2f6c) //115
NHSTUB(reboot_fw_update                       ,0xff3c6c50) //106
NHSTUB(set_control_event                      ,0xff0aeb78) //111
NHSTUB(srand                                  ,0xff0c7ce0) //122
NHSTUB(stat                                   ,0xff02725c) //109
NHSTUB(strcat                                 ,0xff037e4c) //  1
NHSTUB(strchr                                 ,0xff037ed4) //  1
NHSTUB(strcmp                                 ,0xff024ec8) //120
NHSTUB(strcpy                                 ,0xff024db4) //120
NHSTUB(strftime                               ,0xff0c74e0) //113
NHSTUB(strlen                                 ,0xff024f0c) //120
NHSTUB(strncmp                                ,0xff037e88) //  1
NHSTUB(strncpy                                ,0xff027b6c) //  1
NHSTUB(strrchr                                ,0xff0c7e68) //  1
NHSTUB(strtol                                 ,0xff037e38) //101
NHSTUB(strtolx                                ,0xff037c3c) //109
   DEF(task_CaptSeq                           ,0xff0998e8) //120
   DEF(task_DvlpSeqTask                       ,0xff2201b8) //120
   DEF(task_ExpDrv                            ,0xff0fc5c8) //120
   DEF(task_FileWrite                         ,0xff397488) //120
   DEF(task_InitFileModules                   ,0xff0602c0) //120
   DEF(task_MovieRecord                       ,0xff211d34) //120
   DEF(task_PhySw                             ,0xff02b8dc) //120
   DEF(hook_CreateTask                        ,0x006b5658) //105
NHSTUB(time                                   ,0x006b9180) //119
NHSTUB(vsprintf                               ,0xff027b2c) //115
NHSTUB(EngDrvRead                             ,0xff02bf5c) //102
NHSTUB(PTM_GetCurrentItem                     ,0xff0b2e04) //105
NHSTUB(DisableISDriveError                    ,0xff3c2cdc) //120
NHSTUB(CancelHPTimer                          ,0xff0a8fe8) //119
NHSTUB(SetHPTimerAfterNow                     ,0xff0a8ee0) //119
NHSTUB(SS_MFOn                                ,0xff21baf8) //120
NHSTUB(SS_MFOff                               ,0xff21bb08) //120
NHSTUB(GetAdChValue                           ,0xff06f280) //120
NHSTUB(EnableHDMIPower                        ,0xff072e38) //123
NHSTUB(DisableHDMIPower                       ,0xff072e8c) //123
NHSTUB(get_ptp_buf_size                       ,0xff14fcfc) //122
NHSTUB(get_ptp_file_buf                       ,0xff32983c) //121
NHSTUB(SetVideoOutType                        ,0xff4c6418) //109
NHSTUB(GetVideoOutType                        ,0xff4c6324) //120
