// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R50 (DRYOS version 2.3, release #0050)
//   Firmware Ver GM1.00A   // Found @ 0xff07f440, "GM1.00A" @ 0xff07f44d
//   Firmware build timestamp: Dec 26 2011 10:15:58
//   Canon PowerShot SX240 HS

// Values for makefile.inc
//   DIGIC = 50# DIGIC 5
//   PLATFORMOSVER = 50
//   PLATFORMID = 12869# (0x3245) Found @ 0xfff40040
//   MAXRAMADDR = 0x0fffffff
//   MEMISOSTART = 0x00193a24
//   KEYSYS = d4c# Found @ 0xffff3ce0
//   NEED_ENCODED_DISKBOOT = 8# Found @ 0xffff3cf0
//   ARAM_HEAP_START = 0x5ce000# Found @ 0xff1c9000
//   ARAM_HEAP_SIZE  = 0x22000# Found @ 0xff1c8fc4

// Detected address ranges:
// ROM      0xff000000 - 0xffffffff (16777216 bytes)
// RAM code 0x00685000 - 0x0069544c copied from 0xff6808fc (  66636 bytes)
// RAM data 0x00001900 - 0x00014778 copied from 0xff66da84 (  77432 bytes)

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NHSTUB(DeleteFile_Fut                       ,0xff02163c) //  1 90%        == 0xff02163c
//NHSTUB(LEDDrive                             ,0xff1b980c) //120        *** != 0xff04d06c
// ERROR: MakeDirectory_Fut is not found.                  //--- ---    *** != 0xff02214c

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff365dac -> ff63fe50
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x000388e4) // Found @0xff01f5ac
DEF(physw_run                               ,0x00001c60) // Found @0xff01f158
DEF(physw_sleep_delay                       ,0x00001c68) // Found @0xff01f158
DEF(levent_table                            ,0xff587530) // Found @0xff587530
DEF(FlashParamsTable                        ,0xff6400cc) // Found @0xff6400cc
DEF(movie_status                            ,0x0000ab7c) // Found @0xff1b6098
DEF(video_compression_rate                  ,0x0000abbc) // Found @0xff1b7a8c
DEF(full_screen_refresh                     ,0x0000dbe8) // Found @0xff27c44c
DEF(canon_menu_active                       ,0x000034d4) // Found @0xff0813dc
DEF(canon_shoot_menu_active                 ,0x0000c2f9) // Found @0xff2133b8
DEF(playrec_mode                            ,0x00003224) // Found @0xff074ec0
DEF(zoom_status                             ,0x0001150c) // Found @0xff3681dc
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 2 int value(s), the first is the zoom focus length.
// there are 101 entries in the table - set NUM_FL to 101
DEF(focus_len_table                         ,0xfff4bcf0) // Found @0xfff4bcf0
DEF(zoom_busy                               ,0x0000aa14) // Found @0xff1b0f84
DEF(focus_busy                              ,0x0000a870) // Found @0xff1aa4ec
DEF(recreview_hold                          ,0x00003ff0) // Found @0xff094c20
// Palette colour tables  found @ 0xff5a5b04
DEF(palette_control                         ,0x0000dbe8) // Found @0xff27c3c8
DEF(active_palette_buffer                   ,0x0000dbf0) // Found @0xff27c3cc
DEF(palette_buffer_ptr                      ,0x0000dbf4) // Found @0xff27c884
DEF(palette_buffer                          ,0x000ddb24) // Found @0xff27c894
// Offset from start of palette_buffer to color data = 4 (Found @0xff3aca78)
DEF(bitmap_buffer                           ,0x0000dc24) // Found @0xff2810d4
DEF(active_bitmap_buffer                    ,0x0000dc1c) // Found @0xff2810d8
DEF(viewport_buffers                        ,0xff44102c) // Found @0xff03d9bc
DEF(active_viewport_buffer                  ,0x000021b0) // Found @0xff03d658
// Camera has 2 RAW buffers @ 0x44000000 & 0x4adb54a0
//  Note: active buffer --> raw_buffers[active_raw_buffer]
//        other buffer  --> raw_buffers[active_raw_buffer^1]
DEF(raw_buffers                             ,0xff455054) // Found @0xff455054
DEF(active_raw_buffer                       ,0x00003194) // Found @0xff0715e0
DEF(fileio_semaphore                        ,0x00002e60) // Found @0xff05ed14
DEF(exmem_alloc_table                       ,0x00042034) // Found @0xff07a7e0
DEF(exmem_types_table                       ,0xff66f48c) // Found @0x00003308
DEF_CONST(exmem_type_count                  ,0x00000017)
DEF(imager_active                           ,0x000020e8) // Found @0xff03a214 (0x20e4 + 4)
DEF_CONST(uiprop_count                      ,0x0000008d) // Found @0xff1f35b4

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x406c5000; }             // Found @0xff047848
//void *vid_get_viewport_fb()      { return (void*)0x4081ab80; }             // Found @0xff3e366c
DEF(viewport_fb_d                           ,0x00002f14) // Found 0x2ec0 (@0xff062d0c) + 0x54 (@0xff062d44)
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x2ec0+0x54)); } // Found @0xff062d0c & 0xff062d44
DEF(jpeg_count_str                          ,0x000dd3b4) // Found @0xff26fdec
//char *camera_jpeg_count_str()    { return (char*)0x000dd3b4; }             // Found @0xff26fdec
//int get_flash_params_count(void) { return 0xa6; }                          // Found @0xff1f3f8c

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00080000 // Found @0xff441600, levent 0x20a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x10000000 // Found @0xff441638, levent 0x202
//#define USB_IDX             2
//#define BATTCOVER_FLAG      0x00200000 // Found @0xff441540, levent 0x205
//#define BATTCOVER_IDX       1
//#define ANALOG_AV_FLAG      0x04000000 // Found @0xff441628, levent 0x200 (non-inverted logic)
//#define ANALOG_AV_IDX       2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 1, KEY_POWER           ,0x00400000 }, // Found @0xff441548, levent 0x100
//    { 1, KEY_PLAYBACK        ,0x00800000 }, // Found @0xff441550, levent 0x101
//    { 1, KEY_SHOOT_FULL      ,0x03000000 }, // Found @0xff441560, levent 0x01
//    { 1, KEY_SHOOT_FULL_ONLY ,0x02000000 }, // Found @0xff441560, levent 0x01
//    { 1, KEY_SHOOT_HALF      ,0x01000000 }, // Found @0xff441558, levent 0x00
//    { 2, KEY_VIDEO           ,0x00000020 }, // Found @0xff4415b0, levent 0x1a
//    { 2, KEY_MENU            ,0x00000040 }, // Found @0xff4415b8, levent 0x09
//    { 2, KEY_DISPLAY         ,0x00000080 }, // Found @0xff4415c0, levent 0x0a
//    { 2, KEY_UP              ,0x00000100 }, // Found @0xff4415c8, levent 0x04
//    { 2, KEY_DOWN            ,0x00000200 }, // Found @0xff4415d0, levent 0x05
//    { 2, KEY_RIGHT           ,0x00000400 }, // Found @0xff4415d8, levent 0x07
//    { 2, KEY_LEFT            ,0x00000800 }, // Found @0xff4415e0, levent 0x06
//    { 2, KEY_SET             ,0x00001000 }, // Found @0xff4415e8, levent 0x08
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#define CAM_RAW_ROWPIX    4176 // Found @0xff17db18
//#define CAM_RAW_ROWS      3060 // Found @0xff17db24
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff025754
//#define CAM_DATE_FOLDER_NAMING 0x400 // Found @0xff316e80 (pass as 3rd param to GetImageFolder)
//#define PARAM_CAMERA_NAME 4 // Found @0xff63f1b8

// Below goes in 'filewrite.c' or 'platform_camera.h':
//#define MAX_CHUNKS_FOR_FWT 7 // Found @0xff32e7d8

// Known propcases
// //      PROPCASE_AFSTEP 13
// #define PROPCASE_FOCUS_STATE 18
// #define PROPCASE_AV 23
// #define PROPCASE_BV 34
// //      PROPCASE_DELTA_DIGITALGAIN 77
// #define PROPCASE_DELTA_SV 79
// //      PROPCASE_DELTA_ND 80
// #define PROPCASE_EV_CORRECTION_2 211
// #define PROPCASE_ORIENTATION_SENSOR 223
// #define PROPCASE_SV_MARKET 250
// //      PROPCASE_SVFIX 251
// #define PROPCASE_TV 266
// Guessed propset: 4, 5

// Misc stuff
DEF(ctypes, 0xff440368)

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
// EXMEM_FILESTORE      13
// EXMEM_MOVIE_REC      14
// EXMEM_MOVIE_PLY      15
// EXMEM_WIDE           16
// EXMEM_NARROW         17
// EXMEM_GIS_MODE       18
// EXMEM_TRIPODHDR_MODE 19
// EXMEM_HSHQ_MODE      20
// EXMEM_CRAW_REC       21
// EXMEM_PCEVF          22

// ISR flag: 0x1968, pointer to current task's control block: 0x1964
// pointer to TCB area: 0x1a04, found @ 0xff682a94

// LED table init @ 0xff14739c
// LED #1: 0xc022c200 (#98 in GPIO table), offset 0x104
// LED #2: 0xc022c028 (#89 in GPIO table), offset 0x4
// GPIO table @ 0xff440860

// For capt_seq.c
DEF(_nrflag,0xdd10) // Found @ ff28a044 (0xdd10) & ff28a080 (+0x00)
//static long *nrflag = (long*)(0xdd10+0x00);  // Found @ ff28a044 & ff28a080
//#define NR_AUTO (0)                          // have to explictly reset value back to 0 to enable auto

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NHSTUB(AllocateUncacheableMemory              ,0xff02570c) //112
NHSTUB(Close                                  ,0xff021cb0) //120
NHSTUB(CreateBinarySemaphore                  ,0x0068a824) //115
NHSTUB(CreateTask                             ,0x0068ab00) //120
NHSTUB(DebugAssert                            ,0x0068afd8) //107
NHSTUB(DeleteDirectory_Fut                    ,0xff0216b0) //116
NHSTUB(DoAELock                               ,0xff023cbc) //120
NHSTUB(DoAFLock                               ,0xff02390c) //120
NHSTUB(EnterToCompensationEVF                 ,0xff023bb0) //104
NHSTUB(ExecuteEventProcedure                  ,0xff07c400) //104
NHSTUB(ExitFromCompensationEVF                ,0xff023bf4) //104
NHSTUB(ExitTask                               ,0x0068ad90) //120
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff02ee68) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff02efb8) //104
NHSTUB(Fclose_Fut                             ,0xff021748) //120
NHSTUB(Feof_Fut                               ,0xff021934) //  1
NHSTUB(Fflush_Fut                             ,0xff021970) //  1
NHSTUB(Fgets_Fut                              ,0xff02189c) //  6
NHSTUB(Fopen_Fut                              ,0xff021708) //120
NHSTUB(Fread_Fut                              ,0xff0217f4) //120
NHSTUB(FreeUncacheableMemory                  ,0xff02574c) //112
NHSTUB(Fseek_Fut                              ,0xff0218e8) //120
NHSTUB(Fwrite_Fut                             ,0xff021848) //120
NHSTUB(GetBatteryTemperature                  ,0xff0523ac) //102
NHSTUB(GetCCDTemperature                      ,0xff052338) //102
NHSTUB(GetCurrentAvValue                      ,0xff1ad358) //120
NHSTUB(GetCurrentShutterSpeed                 ,0xff0a6eb4) //120
NHSTUB(GetUsableMaxAv                         ,0xff3dd190) //120
NHSTUB(GetUsableMinAv                         ,0xff3dd178) //120
NHSTUB(GetDrive_ClusterSize                   ,0xff06093c) //122
NHSTUB(GetDrive_FreeClusters                  ,0xff060994) //119
NHSTUB(GetDrive_TotalClusters                 ,0xff06096c) //119
NHSTUB(GetFocusLensSubjectDistance            ,0xff1ab2b0) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff1ab700) //  3
NHSTUB(GetImageFolder                         ,0xff18722c) //122
NHSTUB(GetKbdState                            ,0xff04dce8) //109
NHSTUB(GetMemInfo                             ,0xff0052e0) //115
NHSTUB(GetOpticalTemperature                  ,0xff052420) //120
NHSTUB(GetParameterData                       ,0xff1f3f4c) //101
NHSTUB(GetPropertyCase                        ,0xff080520) //102
NHSTUB(GetSystemTime                          ,0xff358364) //120
NHSTUB(GetVRAMHPixelsSize                     ,0xff03fe34) //120
NHSTUB(GetVRAMVPixelsSize                     ,0xff03fe40) //120
NHSTUB(GetZoomLensCurrentPoint                ,0xff1b13fc) //120
NHSTUB(GetZoomLensCurrentPosition             ,0xff345770) //102
NHSTUB(GiveSemaphore                          ,0x0068aa60) //120
NHSTUB(IsStrobeChargeCompleted                ,0xff0de27c) //102
NHSTUB(LocalTime                              ,0x0068f2f4) //115
NHSTUB(LockMainPower                          ,0xff087fe8) //120
NHSTUB(MakeSDCardBootable                     ,0xff060bbc) //105
NHSTUB(MoveFocusLensToDistance                ,0xff3df6bc) //102
NHSTUB(MoveIrisWithAv                         ,0xff354bc0) //120
NHSTUB(MoveZoomLensWithPoint                  ,0xff3553fc) //120
NHSTUB(MoveOpticalZoomAt                      ,0xff02315c) //109
NHSTUB(Open                                   ,0xff021be8) //120
NHSTUB(PB2Rec                                 ,0xff08b370) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff06a190) //120
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff06a168) //120
NHSTUB(PT_PlaySound                           ,0xff076e60) //122
NHSTUB(PostLogicalEventForNotPowerType        ,0xff08598c) //120
NHSTUB(PostLogicalEventToUI                   ,0xff0859d8) //120
NHSTUB(PutInNdFilter                          ,0xff3dd204) //102
NHSTUB(PutOutNdFilter                         ,0xff3dd23c) //102
NHSTUB(Read                                   ,0xff005d9c) //120
NHSTUB(ReadFastDir                            ,0xff32ff18) //115
NHSTUB(Rec2PB                                 ,0xff08b3b0) //104
NHSTUB(RefreshPhysicalScreen                  ,0xff0a180c) //104
NHSTUB(RenameFile_Fut                         ,0xff0215a8) //116
NHSTUB(Restart                                ,0xff026f7c) //122
NHSTUB(ScreenLock                             ,0xff0a27ec) //117
NHSTUB(ScreenUnlock                           ,0xff0a2850) //117
NHSTUB(SetAE_ShutterSpeed                     ,0xff3e27e4) //102
NHSTUB(SetAutoShutdownTime                    ,0xff08805c) //120
NHSTUB(SetCurrentCaptureModeType              ,0xff08f718) //120
NHSTUB(SetDate                                ,0xff3e42c8) //120
NHSTUB(SetFileAttributes                      ,0xff0220b4) //  6
NHSTUB(SetFileTimeStamp                       ,0xff02203c) //  6
NHSTUB(SetLogicalEventActive                  ,0xff087d24) //120
NHSTUB(SetParameterData                       ,0xff1f3ebc) //101
NHSTUB(SetPropertyCase                        ,0xff080380) //102
NHSTUB(SetScriptMode                          ,0xff087dc0) //120
NHSTUB(SleepTask                              ,0x0068c2e8) //120
NHSTUB(TakeSemaphore                          ,0x0068a990) //120
NHSTUB(TurnOffBackLight                       ,0xff09953c) //104
NHSTUB(TurnOnBackLight                        ,0xff099524) //104
NHSTUB(TurnOnDisplay                          ,0xff047c5c) //120
NHSTUB(TurnOffDisplay                         ,0xff047c6c) //120
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff1d78ec) //120
NHSTUB(UnlockAE                               ,0xff023ce0) //120
NHSTUB(UnlockAF                               ,0xff023944) //120
NHSTUB(UnlockMainPower                        ,0xff087f3c) //120
NHSTUB(VbattGet                               ,0xff01d0f0) //120
NHSTUB(Write                                  ,0xff021d04) //120
NHSTUB(WriteSDCard                            ,0xff19d9f8) //108
NHSTUB(_log                                   ,0x006915c8) //111
NHSTUB(_log10                                 ,0x00691b08) //112
NHSTUB(_pow                                   ,0x00691c80) //121
NHSTUB(_sqrt                                  ,0x00693c8c) //  6
NHSTUB(add_ptp_handler                        ,0xff2c815c) //121
NHSTUB(apex2us                                ,0xff283e20) //121
NHSTUB(close                                  ,0xff005bf8) //109
NHSTUB(err_init_task                          ,0xff004388) //111
NHSTUB(exmem_alloc                            ,0xff07add4) //101
NHSTUB(exmem_ualloc                           ,0xff07ac2c) //101
NHSTUB(exmem_ufree                            ,0xff07ad74) //101
NHSTUB(free                                   ,0xff002f84) //112
NHSTUB(kbd_p1_f                               ,0xff01f5fc) //109
NHSTUB(kbd_p1_f_cont                          ,0xff01f608) //109
NHSTUB(kbd_p2_f                               ,0xff01edf0) //109
NHSTUB(kbd_read_keys                          ,0xff01f5ac) //109
NHSTUB(kbd_read_keys_r2                       ,0xff04d560) //109
NHSTUB(lseek                                  ,0xff021ecc) //120
NHSTUB(malloc                                 ,0xff002f2c) //112
NHSTUB(memcmp                                 ,0xff00b99c) //120
NHSTUB(memcpy                                 ,0xff028900) //120
NHSTUB(memset                                 ,0xff281e84) //120
NHSTUB(mkdir                                  ,0xff02214c) //121
NHSTUB(mktime_ext                             ,0xff0a2d4c) //  1
NHSTUB(open                                   ,0xff005b48) //109
NHSTUB(OpenFastDir                            ,0xff32fdc4) //115
NHSTUB(closedir                               ,0xff32fd74) //121
NHSTUB(get_fstype                             ,0xff0609b4) //122
NHSTUB(qsort                                  ,0xff281e24) //  6
NHSTUB(rand                                   ,0xff28195c) //121
NHSTUB(realloc                                ,0xff281f00) //115
NHSTUB(reboot_fw_update                       ,0xff335510) //106
NHSTUB(set_control_event                      ,0xff0878c8) //111
NHSTUB(srand                                  ,0xff281950) //122
NHSTUB(stat                                   ,0xff021f14) //109
NHSTUB(strcat                                 ,0xff0a33cc) //  1
NHSTUB(strchr                                 ,0xff002df8) //  1
NHSTUB(strcmp                                 ,0xff00ba98) //120
NHSTUB(strcpy                                 ,0xff00b984) //120
NHSTUB(strftime                               ,0xff0a2d98) //113
NHSTUB(strlen                                 ,0xff002e44) //120
NHSTUB(strncmp                                ,0xff002dac) //  1
NHSTUB(strncpy                                ,0xff002d70) //  1
NHSTUB(strrchr                                ,0xff002e1c) //  1
NHSTUB(strtol                                 ,0xff0288ec) //101
NHSTUB(strtolx                                ,0xff0286f0) //109
   DEF(task_CaptSeq                           ,0xff06d6bc) //120
   DEF(task_DvlpSeqTask                       ,0xff1c00d4) //120
   DEF(task_ExpDrv                            ,0xff0bc1b0) //120
   DEF(task_FileWrite                         ,0xff32e778) //120
   DEF(task_InitFileModules                   ,0xff08bbc4) //120
   DEF(task_MovieRecord                       ,0xff1b82c0) //120
   DEF(task_PhySw                             ,0xff01f154) //120
   DEF(task_RotaryEncoder                     ,0xff04deb0) //120
NHSTUB(time                                   ,0x0068f8d0) //  6
NHSTUB(vsprintf                               ,0xff00b834) //115
NHSTUB(EngDrvRead                             ,0xff020438) //102
NHSTUB(PTM_GetCurrentItem                     ,0xff088798) //105
NHSTUB(DisableISDriveError                    ,0xff355dfc) //120
NHSTUB(CancelHPTimer                          ,0xff07bae8) //119
NHSTUB(SetHPTimerAfterNow                     ,0xff07b9e0) //119
NHSTUB(PT_MFOn                                ,0xff06a240) //120
NHSTUB(PT_MFOff                               ,0xff06a250) //120
NHSTUB(GetAdChValue                           ,0xff0490c8) //120
NHSTUB(EnableHDMIPower                        ,0xff04c280) //123
NHSTUB(DisableHDMIPower                       ,0xff04c288) //123
NHSTUB(get_ptp_buf_size                       ,0xff123098) //122
NHSTUB(get_ptp_file_buf                       ,0xff2c9c30) //121
NHSTUB(SetVideoOutType                        ,0xff3e3014) //109
NHSTUB(GetVideoOutType                        ,0xff3e2f48) //120
