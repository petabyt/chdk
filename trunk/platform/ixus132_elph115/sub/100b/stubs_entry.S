// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R52 (DRYOS version 2.3, release #0052)
//   Firmware Ver GM1.00B   // Found @ 0xff0c1540, "GM1.00B" @ 0xff0c154d
//   Firmware build timestamp: Jan 22 2013 11:42:53
//   Canon IXUS 132

// Values for makefile.inc
//   DIGIC = 40# DIGIC 4
//   PLATFORMOSVER = 52
//   PLATFORMID = 12925# (0x327d) Found @ 0xfff40040
//   MAXRAMADDR = 0x03ffffff
//   MEMISOSTART = 0x00242f28
//   KEYSYS = d4d# Found @ 0xffff1d2c
//   NEED_ENCODED_DISKBOOT = 10# Found @ 0xffff1d3c
//   ARAM_HEAP_START = 0x5ce000# Found @ 0xff2015b8
//   ARAM_HEAP_SIZE  = 0x22000# Found @ 0xff20157c

// Detected address ranges:
// ROM      0xff000000 - 0xffffffff (16777216 bytes)
// RAM code 0x00671000 - 0x0069badc copied from 0xff6934fc ( 174812 bytes)
// RAM data 0x00001900 - 0x00015584 copied from 0xff67f878 (  81028 bytes)

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NHSTUB(DeleteFile_Fut                       ,0xff033b68) //  1 90%        == 0xff033b68
// ERROR: MakeDirectory_Fut is not found.                  //--- ---    *** != 0xff034678
// ERROR: RefreshPhysicalScreen is not found.              //--- ---    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff369fe0 -> ff6172b0
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x0003a950) // Found @0xff0313b4
DEF(physw_run                               ,0x00001dec) // Found @0xff030f08
DEF(physw_sleep_delay                       ,0x00001df4) // Found @0xff030f08
DEF(levent_table                            ,0xff55b238) // Found @0xff55b238
DEF(FlashParamsTable                        ,0xff6174e4) // Found @0xff6174e4
DEF(movie_status                            ,0x00007c6c) // Found @0xff1f3958
DEF(video_compression_rate                  ,0x00007c9c) // Found @0xff1f40bc
DEF(full_screen_refresh                     ,0x000087a0) // Found @0xff20f1cc
DEF(canon_menu_active                       ,0x00003fa0) // Found @0xff0ca1ac
DEF(canon_shoot_menu_active                 ,0x0000a385) // Found @0xff27c338
DEF(playrec_mode                            ,0x000039c8) // Found @0xff0b5eec
DEF(zoom_status                             ,0x0000bbac) // Found @0xff2eea44
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 2 int value(s), the first is the zoom focus length.
// there are 101 entries in the table - set NUM_FL to 101
DEF(focus_len_table                         ,0xfff4a3e0) // Found @0xfff4a3e0
DEF(zoom_busy                               ,0x00007b20) // Found @0xff1ee63c
DEF(focus_busy                              ,0x00007990) // Found @0xff1e9638
DEF(recreview_hold                          ,0x00002d34) // Found @0xff088430
// Palette colour tables  found @ 0xff561e84
DEF(active_palette_buffer                   ,0x000087a8) // Found @0xff20f150
DEF(palette_buffer_ptr                      ,0x000087ac) // Found @0xff20f4e0
// Offset from start of palette_buffer to color data = 4 (Found @0xff38a928)
// Camera appears to have only 1 RAW buffer @ 0x42365c30 (Found @0xff4138e0)
DEF(fileio_semaphore                        ,0x0000367c) // Found @0xff0a401c
DEF(exmem_alloc_table                       ,0x0009ef4c) // Found @0xff0bc970
DEF(exmem_types_table                       ,0xff681a1c) // Found @0x00003aa4
DEF_CONST(exmem_type_count                  ,0x0000001b)
DEF(imager_active                           ,0x000024c0) // Found @0xff070c7c (0x24bc + 4)
DEF_CONST(uiprop_count                      ,0x00000083) // Found @0xff206770

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x406b1000; }             // Found @0xff08b488
//void *vid_get_viewport_fb()      { return (void*)0x40806b80; }             // Found @0xff411fc8
DEF(viewport_fb_d                           ,0x00003728) // Found 0x36d4 (@0xff0a7758) + 0x54 (@0xff0a7790)
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x36d4+0x54)); } // Found @0xff0a7758 & 0xff0a7790
DEF(jpeg_count_str                          ,0x00164144) // Found @0xff269a4c
//char *camera_jpeg_count_str()    { return (char*)0x00164144; }             // Found @0xff269a4c
//int get_flash_params_count(void) { return 0x91; }                          // Found @0xff207154

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x02000000 // Found @0xff4fb478, levent 0x20a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x10000000 // Found @0xff4fb488, levent 0x202
//#define USB_IDX             2
//#define BATTCOVER_FLAG      0x04000000 // Found @0xff4fb480, levent 0x205
//#define BATTCOVER_IDX       2
//#define ANALOG_AV_FLAG      0x02000000 // Found @0xff4fb3e0, levent 0x200 (non-inverted logic)
//#define ANALOG_AV_IDX       1

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 2, KEY_POWER           ,0x00000001 }, // Found @0xff4fb3e8, levent 0x100
//    { 2, KEY_PLAYBACK        ,0x00000002 }, // Found @0xff4fb3f0, levent 0x101
//    { 2, KEY_SHOOT_FULL      ,0x0000000c }, // Found @0xff4fb400, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000008 }, // Found @0xff4fb400, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00000004 }, // Found @0xff4fb3f8, levent 0x00
//    { 2, KEY_ZOOM_IN         ,0x00000010 }, // Found @0xff4fb408, levent 0x03
//    { 2, KEY_ZOOM_OUT        ,0x00000040 }, // Found @0xff4fb410, levent 0x04
//    { 2, KEY_UP              ,0x00000080 }, // Found @0xff4fb418, levent 0x06
//    { 2, KEY_DOWN            ,0x00000100 }, // Found @0xff4fb420, levent 0x07
//    { 2, KEY_RIGHT           ,0x00000200 }, // Found @0xff4fb428, levent 0x09
//    { 2, KEY_LEFT            ,0x00000400 }, // Found @0xff4fb430, levent 0x08
//    { 2, KEY_SET             ,0x00001000 }, // Found @0xff4fb438, levent 0x0a
//    { 2, KEY_MENU            ,0x00002000 }, // Found @0xff4fb440, levent 0x0b
//    { 2, KEY_VIDEO           ,0x00004000 }, // Found @0xff4fb448, levent 0x02
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#define CAM_RAW_ROWPIX    4704 // Found @0xff1bded4
//#define CAM_RAW_ROWS      3504 // Found @0xff1bdee0
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff038dd4
//#define CAM_DATE_FOLDER_NAMING 0x080 // Found @0xff32101c (pass as 3rd param to GetImageFolder)
//#define PARAM_CAMERA_NAME 3 // Found @0xff6167a0

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
DEF(ctypes, 0xff4f8e00)

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
// EXMEM_WIDE           18
// EXMEM_NARROW         19
// EXMEM_AUTO_GIS_MODE  20
// EXMEM_NP_GIS_MODE    21
// EXMEM_TRIPODHDR_MODE 22
// EXMEM_HSHQ_MODE      23
// EXMEM_CRAW_REC       24
// EXMEM_PCEVF          25
// EXMEM_WIFI_RESIZE    26

// ISR flag: 0x1958, pointer to current task's control block: 0x1954
// pointer to TCB area: 0x19e8, found @ 0xff695720

// LED table init @ 0xff19cfa4
// LED #1: 0xc0223030, offset 0x104
// LED #2: 0xc0220094, offset 0x4

// For capt_seq.c
DEF(_nrflag,0xb334) // Found @ ff2a481c (0xb334) & ff2a4858 (+0x00)
//static long *nrflag = (long*)(0xb334+0x00);  // Found @ ff2a481c & ff2a4858
//#define NR_AUTO (0)                          // have to explictly reset value back to 0 to enable auto

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NHSTUB(AllocateUncacheableMemory              ,0xff038d8c) //112
NHSTUB(Close                                  ,0xff0341dc) //120
NHSTUB(CreateBinarySemaphore                  ,0x006776c8) //115
NHSTUB(CreateTask                             ,0x006768b0) //120
NHSTUB(DebugAssert                            ,0x00676c28) //107
NHSTUB(DeleteDirectory_Fut                    ,0xff033bdc) //116
NHSTUB(DoAELock                               ,0xff035d10) //120
NHSTUB(DoAFLock                               ,0xff035a30) //120
NHSTUB(EnterToCompensationEVF                 ,0xff035c78) //104
NHSTUB(ExecuteEventProcedure                  ,0xff0be5a0) //104
NHSTUB(ExitFromCompensationEVF                ,0xff035cbc) //104
NHSTUB(ExitTask                               ,0x00676b40) //120
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff06a1a0) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff06a308) //104
NHSTUB(Fclose_Fut                             ,0xff033c74) //120
NHSTUB(Feof_Fut                               ,0xff033e60) //  1
NHSTUB(Fflush_Fut                             ,0xff033e9c) //  1
NHSTUB(Fgets_Fut                              ,0xff033dc8) //  6
NHSTUB(Fopen_Fut                              ,0xff033c34) //120
NHSTUB(Fread_Fut                              ,0xff033d20) //120
NHSTUB(FreeUncacheableMemory                  ,0xff038dcc) //112
NHSTUB(Fseek_Fut                              ,0xff033e14) //120
NHSTUB(Fwrite_Fut                             ,0xff033d74) //120
NHSTUB(GetBatteryTemperature                  ,0xff0933dc) //102
NHSTUB(GetCCDTemperature                      ,0xff093368) //102
NHSTUB(GetCurrentAvValue                      ,0xff1eb4f4) //120
NHSTUB(GetCurrentShutterSpeed                 ,0xff108ae0) //120
NHSTUB(GetDrive_ClusterSize                   ,0xff0a568c) //122
NHSTUB(GetDrive_FreeClusters                  ,0xff0a5e6c) //119
NHSTUB(GetDrive_TotalClusters                 ,0xff0a5e44) //122
NHSTUB(GetFocusLensSubjectDistance            ,0xff1ea768) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff1eaafc) //  3
NHSTUB(GetImageFolder                         ,0xff1c55bc) //122
NHSTUB(GetKbdState                            ,0xff0906c0) //109
NHSTUB(GetMemInfo                             ,0xff00506c) //115
NHSTUB(GetOpticalTemperature                  ,0xff093450) //120
NHSTUB(GetParameterData                       ,0xff207114) //101
NHSTUB(GetPropertyCase                        ,0xff0c2960) //101
NHSTUB(GetSystemTime                          ,0xff365b10) //120
NHSTUB(GetVRAMHPixelsSize                     ,0xff0766cc) //120
NHSTUB(GetVRAMVPixelsSize                     ,0xff0766d8) //120
NHSTUB(GetZoomLensCurrentPoint                ,0xff1eeab8) //120
NHSTUB(GetZoomLensCurrentPosition             ,0xff352090) //102
NHSTUB(GiveSemaphore                          ,0x00677904) //120
NHSTUB(IsStrobeChargeCompleted                ,0xff136138) //102
NHSTUB(LEDDrive                               ,0xff1f579c) //120
NHSTUB(LocalTime                              ,0x0067f6b0) //115
NHSTUB(LockMainPower                          ,0xff0c4dd8) //120
NHSTUB(MakeSDCardBootable                     ,0xff0a62f0) //105
NHSTUB(MoveFocusLensToDistance                ,0xff40db30) //102
NHSTUB(MoveIrisWithAv                         ,0xff3602a4) //120
NHSTUB(MoveZoomLensWithPoint                  ,0xff3609e0) //120
NHSTUB(MoveOpticalZoomAt                      ,0xff0354f4) //109
NHSTUB(Open                                   ,0xff034114) //120
NHSTUB(PB2Rec                                 ,0xff081738) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff1f68a0) //102
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff1f6870) //102
NHSTUB(PT_PlaySound                           ,0xff0d53c8) //122
NHSTUB(PostLogicalEventForNotPowerType        ,0xff0c44c8) //120
NHSTUB(PostLogicalEventToUI                   ,0xff0c4514) //120
NHSTUB(PutInNdFilter                          ,0xff3607b8) //102
NHSTUB(PutOutNdFilter                         ,0xff3607dc) //102
NHSTUB(Read                                   ,0xff005b28) //120
NHSTUB(ReadFastDir                            ,0xff33d178) //115
NHSTUB(Rec2PB                                 ,0xff081778) //104
NHSTUB(RenameFile_Fut                         ,0xff033ad4) //116
NHSTUB(Restart                                ,0xff038240) //122
NHSTUB(ScreenLock                             ,0xff0c9c9c) //117
NHSTUB(ScreenUnlock                           ,0xff0c9cf0) //117
NHSTUB(SetAE_ShutterSpeed                     ,0xff410ea0) //102
NHSTUB(SetAutoShutdownTime                    ,0xff0c4e4c) //120
NHSTUB(SetCurrentCaptureModeType              ,0xff0d2be8) //120
NHSTUB(SetFileAttributes                      ,0xff0345e0) //  6
NHSTUB(SetFileTimeStamp                       ,0xff034568) //  6
NHSTUB(SetLogicalEventActive                  ,0xff0c4b50) //120
NHSTUB(SetParameterData                       ,0xff207080) //101
NHSTUB(SetPropertyCase                        ,0xff0c27d0) //101
NHSTUB(SetScriptMode                          ,0xff0c4ba0) //120
NHSTUB(SleepTask                              ,0x00677bb0) //120
NHSTUB(TakeSemaphore                          ,0x00677834) //120
NHSTUB(TurnOffBackLight                       ,0xff0d4c94) //104
NHSTUB(TurnOnBackLight                        ,0xff0d4c7c) //104
NHSTUB(TurnOnDisplay                          ,0xff08b890) //120
NHSTUB(TurnOffDisplay                         ,0xff08b8a0) //120
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff22305c) //120
NHSTUB(UnlockAE                               ,0xff035d34) //120
NHSTUB(UnlockAF                               ,0xff035a60) //120
NHSTUB(UnlockMainPower                        ,0xff0c4d2c) //120
NHSTUB(VbattGet                               ,0xff03014c) //120
NHSTUB(Write                                  ,0xff034230) //120
NHSTUB(WriteSDCard                            ,0xff1dba1c) //108
NHSTUB(_log                                   ,0x00697808) //111
NHSTUB(_log10                                 ,0x00697d48) //112
NHSTUB(_pow                                   ,0x00697ec0) //121
NHSTUB(_sqrt                                  ,0x00699c5c) //  6
NHSTUB(add_ptp_handler                        ,0xff16a158) //121
NHSTUB(apex2us                                ,0xff29da2c) //121
NHSTUB(close                                  ,0xff005984) //109
NHSTUB(err_init_task                          ,0xff004320) //111
NHSTUB(exmem_alloc                            ,0xff0bcf68) //101
NHSTUB(exmem_free                             ,0xff0bcfe0) //101
NHSTUB(free                                   ,0xff002ef0) //112
NHSTUB(get_nd_value                           ,0xff34fbf4) //123
NHSTUB(get_current_nd_value                   ,0xff34fb94) //122
NHSTUB(kbd_p1_f                               ,0xff031404) //109
NHSTUB(kbd_p1_f_cont                          ,0xff031410) //109
NHSTUB(kbd_p2_f                               ,0xff030ba0) //109
NHSTUB(kbd_read_keys                          ,0xff0313b4) //109
NHSTUB(kbd_read_keys_r2                       ,0xff09011c) //109
NHSTUB(lseek                                  ,0xff0343f8) //120
NHSTUB(malloc                                 ,0xff002e98) //112
NHSTUB(memcmp                                 ,0xff00ad4c) //120
NHSTUB(memcpy                                 ,0xff039818) //120
NHSTUB(memset                                 ,0xff0d8db8) //120
NHSTUB(mkdir                                  ,0xff034678) //121
NHSTUB(mktime_ext                             ,0xff0d8260) //  1
NHSTUB(open                                   ,0xff0058d4) //109
NHSTUB(OpenFastDir                            ,0xff33d024) //115
NHSTUB(closedir                               ,0xff33cfd4) //121
NHSTUB(get_fstype                             ,0xff0a5608) //122
NHSTUB(qsort                                  ,0xff282a6c) //  6
NHSTUB(rand                                   ,0xff0d8cbc) //121
NHSTUB(realloc                                ,0xff282acc) //115
NHSTUB(reboot_fw_update                       ,0xff36517c) //106
NHSTUB(set_control_event                      ,0xff0c4810) //111
NHSTUB(srand                                  ,0xff0d8cb0) //122
NHSTUB(stat                                   ,0xff034440) //109
NHSTUB(strcat                                 ,0xff0d8cec) //  1
NHSTUB(strchr                                 ,0xff002d64) //  1
NHSTUB(strcmp                                 ,0xff00ae48) //120
NHSTUB(strcpy                                 ,0xff00ad34) //120
NHSTUB(strftime                               ,0xff0d82ac) //113
NHSTUB(strlen                                 ,0xff002db0) //120
NHSTUB(strncmp                                ,0xff002d18) //  1
NHSTUB(strncpy                                ,0xff002cdc) //  1
NHSTUB(strrchr                                ,0xff002d88) //  1
NHSTUB(strtol                                 ,0xff039804) //101
NHSTUB(strtolx                                ,0xff039608) //109
   DEF(task_CaptSeq                           ,0xff0b05bc) //120
   DEF(task_DvlpSeqTask                       ,0xff1f9b2c) //120
   DEF(task_ExpDrv                            ,0xff11d458) //120
   DEF(task_FileWrite                         ,0xff3392b4) //120
   DEF(task_InitFileModules                   ,0xff08208c) //120
   DEF(task_MovieRecord                       ,0xff1f4590) //120
   DEF(task_PhySw                             ,0xff030f04) //120
   DEF(hook_CreateTask                        ,0x006768b0) //105
NHSTUB(time                                   ,0x0067fb58) //119
NHSTUB(vsprintf                               ,0xff00abe4) //115
NHSTUB(EngDrvRead                             ,0xff0322e4) //102
NHSTUB(PTM_GetCurrentItem                     ,0xff0c5804) //105
NHSTUB(DisableISDriveError                    ,0xff3614dc) //120
NHSTUB(CancelHPTimer                          ,0xff0bdc88) //119
NHSTUB(SetHPTimerAfterNow                     ,0xff0bdb80) //119
NHSTUB(SS_MFOn                                ,0xff1f6934) //120
NHSTUB(SS_MFOff                               ,0xff1f6944) //120
NHSTUB(GetAdChValue                           ,0xff08c9e8) //120
NHSTUB(get_ptp_buf_size                       ,0xff1655b4) //122
NHSTUB(get_ptp_file_buf                       ,0xff2e07cc) //121
NHSTUB(SetVideoOutType                        ,0xff4116e8) //109
