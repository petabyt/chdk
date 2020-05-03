// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R57 (DRYOS version 2.3, release #0057)
//   Firmware Ver GM1.00A   // Found @ 0xff0aaf8c, "GM1.00A" @ 0xff0aaf99
//   Firmware build timestamp: Jan 29 2015 13:35:11
//   Canon PowerShot ELPH 350 HS

// Values for makefile.inc
//   DIGIC = 41# DIGIC 4+
//   PLATFORMOSVER = 57
//   PLATFORMID = 12971# (0x32ab) Found @ 0xfffe0040
//   MAXRAMADDR = 0x1fffffff
//   MEMISOSTART = 0x002cf204
//   KEYSYS = d4g# Found @ 0xff014590
//   NEED_ENCODED_DISKBOOT = 13# Found @ 0xff0145a0
//   ARAM_HEAP_START = 0x60e000# Found @ 0xff228514
//   ARAM_HEAP_SIZE  = 0x22000# Found @ 0xff2284d4

// Detected address ranges:
// ROM      0xff010000 - 0xffffffff (16711680 bytes)
// RAM code 0x006b1000 - 0x006e2d30 copied from 0xff8642f4 ( 204080 bytes)
// RAM data 0x00001900 - 0x000189bc copied from 0xff84d238 (  94396 bytes)

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
NHSTUB(DeleteFile_Fut                         ,0xff026984) //  1 90%
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff20489c) //  3 90%
// ERROR: MakeDirectory_Fut is not found.                  //--- ---    *** != 0xff027494
// ERROR: RefreshPhysicalScreen is not found.              //--- ---    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff3c95fc -> ff7b6d44
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x000196e4) // Found @0xff02bf80
DEF(physw_run                               ,0x00001ca8) // Found @0xff02ba70
DEF(physw_sleep_delay                       ,0x00001cb0) // Found @0xff02ba70
DEF(levent_table                            ,0xff6875c0) // Found @0xff6875c0
DEF(FlashParamsTable                        ,0xff7b70a8) // Found @0xff7b70a8
DEF(movie_status                            ,0x0000a24c) // Found @0xff20f934
DEF(video_compression_rate                  ,0x0000a1fc) // Found @0xff2103bc
DEF(full_screen_refresh                     ,0x0000b124) // Found @0xff23b26c
DEF(canon_menu_active                       ,0x000040e4) // Found @0xff0b56c4
DEF(canon_shoot_menu_active                 ,0x0000d025) // Found @0xff2b9a88
DEF(zoom_status                             ,0x0000e464) // Found @0xff3380c8
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 2 int value(s), the first is the zoom focus length.
// there are 101 entries in the table - set NUM_FL to 101
DEF(focus_len_table                         ,0xfffed67c) // Found @0xfffed67c
DEF(zoom_busy                               ,0x00009fa0) // Found @0xff206ee4
DEF(focus_busy                              ,0x00009e68) // Found @0xff20321c
// Palette colour tables  found @ 0xff68e37c
// Camera has 2 RAW buffers @ 0x48000000 & 0x561c9d00
//  Note: active buffer --> raw_buffers[active_raw_buffer]
//        other buffer  --> raw_buffers[active_raw_buffer^1]
DEF(raw_buffers                             ,0xff642ac4) // Found @0xff642ac4
DEF(active_raw_buffer                       ,0x00003afc) // Found @0xff09bcb0
DEF(fileio_semaphore                        ,0x00001d4c) // Found @0xff02ec70
DEF(exmem_alloc_table                       ,0x0001aa64) // Found @0xff033bb8
DEF(exmem_types_table                       ,0xff84d71c) // Found @0x00001de4
DEF_CONST(exmem_type_count                  ,0x0000001f)
DEF(imager_active                           ,0x0000209c) // Found @0xff04c7cc (0x2098 + 4)
DEF_CONST(uiprop_count                      ,0x000000ce) // Found @0xff230d64

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x40711000; }             // Found @0xff06dff4
//void *vid_get_viewport_fb()      { return (void*)0x40866b80; }             // Found @0xff4c6d8c
DEF(jpeg_count_str                          ,0x00155810) // Found @0xff2a2808
//char *camera_jpeg_count_str()    { return (char*)0x00155810; }             // Found @0xff2a2808
//int get_flash_params_count(void) { return 0xe3; }                          // Found @0xff2318d8

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00400000 // Found @0xff63743c, levent 0x20a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x01000000 // Found @0xff63744c, levent 0x202
//#define USB_IDX             2
//#define BATTCOVER_FLAG      0x00800000 // Found @0xff637444, levent 0x205
//#define BATTCOVER_IDX       2
//#define ANALOG_AV_FLAG      0x00000002 // Found @0xff637384, levent 0x200 (non-inverted logic)
//#define ANALOG_AV_IDX       0

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_MENU            ,0x00000008 }, // Found @0xff63738c, levent 0x14
//    { 0, KEY_VIDEO           ,0x00000040 }, // Found @0xff637394, levent 0x02
//    { 0, KEY_SET             ,0x00000080 }, // Found @0xff63739c, levent 0x0a
//    { 0, KEY_LEFT            ,0x00001000 }, // Found @0xff6373a4, levent 0x08
//    { 0, KEY_UP              ,0x00002000 }, // Found @0xff6373ac, levent 0x06
//    { 0, KEY_RIGHT           ,0x00004000 }, // Found @0xff6373b4, levent 0x09
//    { 0, KEY_DOWN            ,0x00008000 }, // Found @0xff6373bc, levent 0x07
//    { 2, KEY_SHOOT_FULL      ,0x00000060 }, // Found @0xff6373cc, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000040 }, // Found @0xff6373cc, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00000020 }, // Found @0xff6373c4, levent 0x00
//    { 2, KEY_POWER           ,0x00000080 }, // Found @0xff6373d4, levent 0x100
//    { 2, KEY_PLAYBACK        ,0x00000100 }, // Found @0xff6373dc, levent 0x101
//    { 2, KEY_ZOOM_OUT        ,0x00004000 }, // Found @0xff637404, levent 0x04
//    { 2, KEY_ZOOM_IN         ,0x00008000 }, // Found @0xff63740c, levent 0x03
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#define CAM_RAW_ROWPIX    5344 // Found @0xff1d4804
//#define CAM_RAW_ROWS      3950 // Found @0xff1d4810
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff025c5c
//#define CAM_DATE_FOLDER_NAMING 0x080 // Found @0xff37c540 (pass as 3rd param to GetImageFolder)
//#define PARAM_CAMERA_NAME 3 // Found @0xff7b5bfc
//#define CAM_3ARG_DebugAssert 1

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
DEF(ctypes, 0xff633aac)

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
// pointer to TCB area: 0x19c4, found @ 0xff86589c

// LED table init @ 0xff19fa14
// LED #1: 0xc022d1b0 (#65 in GPIO table), offset 0x98
// LED #2: 0xc022d1fc (#97 in GPIO table), offset 0x8
// GPIO table @ 0xff636e18

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NHSTUB(AllocateUncacheableMemory              ,0xff025c18) //112
NHSTUB(Close                                  ,0xff026ff8) //120
NHSTUB(CreateBinarySemaphore                  ,0x006b7884) //115
NHSTUB(CreateTask                             ,0x006b5658) //120
NHSTUB(DebugAssert                            ,0x006b59f8) //107
NHSTUB(DeleteDirectory_Fut                    ,0xff0269f8) //116
NHSTUB(DoAELock                               ,0xff03257c) //120
NHSTUB(DoAFLock                               ,0xff032180) //120
NHSTUB(EnterToCompensationEVF                 ,0xff032440) //104
NHSTUB(ExecuteEventProcedure                  ,0xff0346a0) //104
NHSTUB(ExitFromCompensationEVF                ,0xff032494) //104
NHSTUB(ExitTask                               ,0x006b5994) //120
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff0445d8) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff044810) //104
NHSTUB(Fclose_Fut                             ,0xff026a90) //120
NHSTUB(Feof_Fut                               ,0xff026c7c) //  1
NHSTUB(Fflush_Fut                             ,0xff026cb8) //  1
NHSTUB(Fgets_Fut                              ,0xff026be4) //  6
NHSTUB(Fopen_Fut                              ,0xff026a50) //120
NHSTUB(Fread_Fut                              ,0xff026b3c) //120
NHSTUB(FreeUncacheableMemory                  ,0xff025c54) //112
NHSTUB(Fseek_Fut                              ,0xff026c30) //120
NHSTUB(Fwrite_Fut                             ,0xff026b90) //120
NHSTUB(GetBatteryTemperature                  ,0xff078cfc) //102
NHSTUB(GetCCDTemperature                      ,0xff078c84) //102
NHSTUB(GetCurrentAvValue                      ,0xff091b04) //120
NHSTUB(GetCurrentShutterSpeed                 ,0xff0db150) //120
NHSTUB(GetUsableMaxAv                         ,0xff1d5098) //120
NHSTUB(GetUsableMinAv                         ,0xff1d507c) //120
NHSTUB(GetDrive_ClusterSize                   ,0xff030304) //122
NHSTUB(GetDrive_FreeClusters                  ,0xff030adc) //119
NHSTUB(GetDrive_TotalClusters                 ,0xff030ab0) //122
NHSTUB(GetFocusLensSubjectDistance            ,0xff2044b8) //102
NHSTUB(GetImageFolder                         ,0xff1dced8) //122
NHSTUB(GetKbdState                            ,0xff074ebc) //109
NHSTUB(GetMemInfo                             ,0xff023408) //115
NHSTUB(GetOpticalTemperature                  ,0xff078d74) //120
NHSTUB(GetParameterData                       ,0xff231894) //101
NHSTUB(GetPropertyCase                        ,0xff0ac880) //101
NHSTUB(GetSystemTime                          ,0xff3c6604) //120
NHSTUB(GetVRAMHPixelsSize                     ,0xff051370) //120
NHSTUB(GetVRAMVPixelsSize                     ,0xff05137c) //120
NHSTUB(GetZoomLensCurrentPoint                ,0xff207368) //120
NHSTUB(GetZoomLensCurrentPosition             ,0xff3af538) //102
NHSTUB(GiveSemaphore                          ,0x006b7b04) //120
NHSTUB(IsStrobeChargeCompleted                ,0xff1095d4) //102
NHSTUB(LEDDrive                               ,0xff21a198) //120
NHSTUB(LocalTime                              ,0x006b9998) //115
NHSTUB(LockMainPower                          ,0xff0b1234) //120
NHSTUB(MakeSDCardBootable                     ,0xff030eec) //105
NHSTUB(MoveFocusLensToDistance                ,0xff4caa6c) //102
NHSTUB(MoveIrisWithAv                         ,0xff3bff50) //120
NHSTUB(MoveZoomLensWithPoint                  ,0xff3c08bc) //120
NHSTUB(MoveOpticalZoomAt                      ,0xff031aa8) //109
NHSTUB(Open                                   ,0xff026f30) //120
NHSTUB(PB2Rec                                 ,0xff05dd40) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff21b310) //102
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff21b2e0) //102
NHSTUB(PT_PlaySound                           ,0xff0c28f8) //122
NHSTUB(PostLogicalEventForNotPowerType        ,0xff0ae7c0) //120
NHSTUB(PostLogicalEventToUI                   ,0xff0ae818) //120
NHSTUB(PutInNdFilter                          ,0xff3c0674) //102
NHSTUB(PutOutNdFilter                         ,0xff3c0698) //102
NHSTUB(Read                                   ,0xff023ec4) //120
NHSTUB(ReadFastDir                            ,0xff39808c) //115
NHSTUB(Rec2PB                                 ,0xff05dd98) //104
NHSTUB(RenameFile_Fut                         ,0xff0268f0) //116
NHSTUB(Restart                                ,0xff037734) //122
NHSTUB(ScreenLock                             ,0xff0b4f00) //117
NHSTUB(ScreenUnlock                           ,0xff0b4eb8) //117
NHSTUB(SetAE_ShutterSpeed                     ,0xff4c5b68) //102
NHSTUB(SetAutoShutdownTime                    ,0xff0b12a8) //120
NHSTUB(SetCurrentCaptureModeType              ,0xff0bf5bc) //120
NHSTUB(SetFileAttributes                      ,0xff0273fc) //  6
NHSTUB(SetFileTimeStamp                       ,0xff027384) //  6
NHSTUB(SetLogicalEventActive                  ,0xff0aee94) //120
NHSTUB(SetParameterData                       ,0xff2317f8) //101
NHSTUB(SetPropertyCase                        ,0xff0ac6b4) //101
NHSTUB(SetScriptMode                          ,0xff0aeee8) //120
NHSTUB(SleepTask                              ,0x006b8d54) //120
NHSTUB(TakeSemaphore                          ,0x006b7a2c) //120
NHSTUB(TurnOffBackLight                       ,0xff0c1f80) //104
NHSTUB(TurnOnBackLight                        ,0xff0c1fcc) //104
NHSTUB(TurnOnDisplay                          ,0xff06e3ec) //120
NHSTUB(TurnOffDisplay                         ,0xff06e3fc) //120
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff2512d8) //120
NHSTUB(UnlockAE                               ,0xff0325a0) //120
NHSTUB(UnlockAF                               ,0xff0321b0) //120
NHSTUB(UnlockMainPower                        ,0xff0b118c) //120
NHSTUB(VbattGet                               ,0xff02ab20) //120
NHSTUB(Write                                  ,0xff02704c) //120
NHSTUB(WriteSDCard                            ,0x006ba8a4) //108
NHSTUB(_log                                   ,0x006dddb0) //111
NHSTUB(_log10                                 ,0x006de2f0) //112
NHSTUB(_pow                                   ,0x006de6b8) //121
NHSTUB(_sqrt                                  ,0x006e0790) //  6
NHSTUB(add_ptp_handler                        ,0xff15d814) //121
NHSTUB(apex2us                                ,0xff2d8b04) //121
NHSTUB(close                                  ,0xff023d20) //109
NHSTUB(err_init_task                          ,0xff0247a0) //111
NHSTUB(exmem_alloc                            ,0xff034288) //101
NHSTUB(exmem_ualloc                           ,0xff0340ec) //101
NHSTUB(exmem_ufree                            ,0xff034234) //101
NHSTUB(free                                   ,0xff02504c) //112
NHSTUB(get_nd_value                           ,0xff3acaf8) //123
NHSTUB(get_current_nd_value                   ,0xff3aca98) //122
NHSTUB(kbd_p1_f                               ,0xff02bfd0) //109
NHSTUB(kbd_p1_f_cont                          ,0xff02bfdc) //109
NHSTUB(kbd_p2_f                               ,0xff02b6cc) //109
NHSTUB(kbd_read_keys                          ,0xff02bf80) //109
NHSTUB(kbd_read_keys_r2                       ,0xff074858) //109
NHSTUB(lseek                                  ,0xff027214) //120
NHSTUB(malloc                                 ,0xff024ff4) //112
NHSTUB(memcmp                                 ,0xff024dcc) //120
NHSTUB(memcpy                                 ,0xff0c7d08) //120
NHSTUB(memset                                 ,0xff2d2438) //120
NHSTUB(mkdir                                  ,0xff027494) //121
NHSTUB(mktime_ext                             ,0xff0c744c) //  1
NHSTUB(open                                   ,0xff023c70) //109
NHSTUB(OpenFastDir                            ,0xff397f38) //115
NHSTUB(closedir                               ,0xff397ee8) //121
NHSTUB(get_fstype                             ,0xff03027c) //122
NHSTUB(qsort                                  ,0xff2d23d8) //  6
NHSTUB(rand                                   ,0xff0c7cd8) //121
NHSTUB(realloc                                ,0xff2d24b4) //115
NHSTUB(reboot_fw_update                       ,0xff3c5cb4) //106
NHSTUB(set_control_event                      ,0xff0aeb54) //111
NHSTUB(srand                                  ,0xff0c7ccc) //122
NHSTUB(stat                                   ,0xff02725c) //109
NHSTUB(strcat                                 ,0xff038058) //  1
NHSTUB(strchr                                 ,0xff0380e0) //  1
NHSTUB(strcmp                                 ,0xff024ec8) //120
NHSTUB(strcpy                                 ,0xff024db4) //120
NHSTUB(strftime                               ,0xff0c74cc) //113
NHSTUB(strlen                                 ,0xff024f0c) //120
NHSTUB(strncmp                                ,0xff038094) //  1
NHSTUB(strncpy                                ,0xff027b6c) //  1
NHSTUB(strrchr                                ,0xff0c7e54) //  1
NHSTUB(strtol                                 ,0xff038044) //101
NHSTUB(strtolx                                ,0xff037e48) //109
   DEF(task_CaptSeq                           ,0xff0998ac) //120
   DEF(task_DvlpSeqTask                       ,0xff21f9b0) //120
   DEF(task_ExpDrv                            ,0xff0fc8b0) //120
   DEF(task_FileWrite                         ,0xff3965b4) //120
   DEF(task_InitFileModules                   ,0xff060a90) //120
   DEF(task_MovieRecord                       ,0xff21160c) //120
   DEF(task_PhySw                             ,0xff02ba6c) //120
   DEF(hook_CreateTask                        ,0x006b5658) //105
NHSTUB(time                                   ,0x006b9180) //119
NHSTUB(vsprintf                               ,0xff027b2c) //115
NHSTUB(EngDrvRead                             ,0xff02c0e0) //102
NHSTUB(PTM_GetCurrentItem                     ,0xff0b2de0) //105
NHSTUB(DisableISDriveError                    ,0xff3c1968) //120
NHSTUB(CancelHPTimer                          ,0xff0a8fec) //119
NHSTUB(SetHPTimerAfterNow                     ,0xff0a8ee4) //119
NHSTUB(SS_MFOn                                ,0xff21b3a4) //120
NHSTUB(SS_MFOff                               ,0xff21b3b4) //120
NHSTUB(GetAdChValue                           ,0xff06f820) //120
NHSTUB(EnableHDMIPower                        ,0xff0733d8) //123
NHSTUB(DisableHDMIPower                       ,0xff07342c) //123
NHSTUB(get_ptp_buf_size                       ,0xff14fb3c) //122
NHSTUB(get_ptp_file_buf                       ,0xff328ce0) //121
NHSTUB(SetVideoOutType                        ,0xff4c63f4) //109
