// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R58 (DRYOS version 2.3, release #0058+p7)
//   Firmware Ver GM1.00B   // Found @ 0xff0aac74, "GM1.00B" @ 0xff0aac81
//   Firmware build timestamp: Oct 29 2015 10:54:13
//   Canon IXUS 285 HS

// Values for makefile.inc
//   DIGIC = 41# DIGIC 4+
//   PLATFORMOSVER = 58
//   PLATFORMID = 12989# (0x32bd) Found @ 0xfffe0270
//   MAXRAMADDR = 0x1fffffff
//   MEMISOSTART = 0x002f6598
//   KEYSYS = d4i# Found @ 0xff014590
//   NEED_ENCODED_DISKBOOT = 16# Found @ 0xff0145a0
//   ARAM_HEAP_START = 0x60e000# Found @ 0xff22d9e4
//   ARAM_HEAP_SIZE  = 0x22000# Found @ 0xff22d9a4

// Detected address ranges:
// ROM      0xff010000 - 0xffffffff (16711680 bytes)
// RAM code 0x006b1000 - 0x006e3f28 copied from 0xff90bc80 ( 208680 bytes)
// RAM data 0x00001900 - 0x000192a0 copied from 0xff8f42e0 (  96672 bytes)

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
NHSTUB(DeleteFile_Fut                         ,0xff026a98) //  1 90%
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff2092ac) //  3 90%
// ERROR: MakeDirectory_Fut is not found.                  //--- ---    *** != 0xff0277ac
// ERROR: RefreshPhysicalScreen is not found.              //--- ---    *** != 0x00000000
// ERROR: TurnOffBackLight is not found.                   //--- ---    *** != 0x00000000
// ERROR: TurnOnBackLight is not found.                    //--- ---    *** != 0x00000000
// ERROR: close is not found.                              //--- ---    *** != 0xff023d68
// ERROR: open is not found.                               //--- ---    *** != 0xff023cb8

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff3e2258 -> ff824c90
// Mode 33334 in firmware but not in current modemap
// Mode 33332 in firmware but not in current modemap
// Mode 33337 in firmware but not in current modemap
// Mode 33298 in firmware but not in current modemap
// Mode 33299 in firmware but not in current modemap

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x0001a078) // Found @0xff02c69c
DEF(physw_run                               ,0x00001c24) // Found @0xff02c18c
DEF(physw_sleep_delay                       ,0x00001c2c) // Found @0xff02c18c
DEF(levent_table                            ,0xff6df84c) // Found @0xff6df84c
DEF(FlashParamsTable                        ,0xff825014) // Found @0xff825014
DEF(movie_status                            ,0x0000a2e4) // Found @0xff214afc
DEF(video_compression_rate                  ,0x0000a294) // Found @0xff21557c
DEF(full_screen_refresh                     ,0x0000b1d8) // Found @0xff240e4c
DEF(canon_menu_active                       ,0x0000407c) // Found @0xff0b5560
DEF(canon_shoot_menu_active                 ,0x0000d895) // Found @0xff2c79ec
DEF(zoom_status                             ,0x0000eca0) // Found @0xff3473c8
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 2 int value(s), the first is the zoom focus length.
// there are 101 entries in the table - set NUM_FL to 101
DEF(focus_len_table                         ,0xfffee67c) // Found @0xfffee67c
DEF(zoom_busy                               ,0x0000a030) // Found @0xff20bc38
DEF(focus_busy                              ,0x00009ef8) // Found @0xff207d68
// Palette colour tables  found @ 0xff6e674c
// Camera has 2 RAW buffers @ 0x48000000 & 0x561c9d00
//  Note: active buffer --> raw_buffers[active_raw_buffer]
//        other buffer  --> raw_buffers[active_raw_buffer^1]
DEF(raw_buffers                             ,0xff69c688) // Found @0xff69c688
DEF(active_raw_buffer                       ,0x00003a7c) // Found @0xff09b498
DEF(fileio_semaphore                        ,0x00001cc0) // Found @0xff02f38c
DEF(exmem_alloc_table                       ,0x0001b434) // Found @0xff0342e8
DEF(exmem_types_table                       ,0xff8f4730) // Found @0x00001d50
DEF_CONST(exmem_type_count                  ,0x0000001f)
DEF(imager_active                           ,0x00001fe8) // Found @0xff04b1f8 (0x1fe4 + 4)
DEF_CONST(uiprop_count                      ,0x000000d7) // Found @0xff236814

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x40711000; }             // Found @0xff06cd40
//void *vid_get_viewport_fb()      { return (void*)0x40866b80; }             // Found @0xff4edb6c
DEF(viewport_fb_d                           ,0x00003744) // Found 0x36e8 (@0xff08ccbc) + 0x5c (@0xff08ccf4)
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x36e8+0x5c)); } // Found @0xff08ccbc & 0xff08ccf4
DEF(jpeg_count_str                          ,0x001577b0) // Found @0xff2b0848
//char *camera_jpeg_count_str()    { return (char*)0x001577b0; }             // Found @0xff2b0848
//int get_flash_params_count(void) { return 0xf1; }                          // Found @0xff237388

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00400000 // Found @0xff694f54, levent 0x30a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x01000000 // Found @0xff694f64, levent 0x302
//#define USB_IDX             2
//#define BATTCOVER_FLAG      0x00800000 // Found @0xff694f5c, levent 0x305
//#define BATTCOVER_IDX       2
//#define ANALOG_AV_FLAG      0x00000002 // Found @0xff694e9c, levent 0x300 (non-inverted logic)
//#define ANALOG_AV_IDX       0

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_VIDEO           ,0x00000040 }, // Found @0xff694eac, levent 0x02
//    { 0, KEY_SET             ,0x00000080 }, // Found @0xff694eb4, levent 0x0a
//    { 0, KEY_LEFT            ,0x00001000 }, // Found @0xff694ebc, levent 0x08
//    { 0, KEY_UP              ,0x00002000 }, // Found @0xff694ec4, levent 0x06
//    { 0, KEY_RIGHT           ,0x00004000 }, // Found @0xff694ecc, levent 0x09
//    { 0, KEY_DOWN            ,0x00008000 }, // Found @0xff694ed4, levent 0x07
//    { 2, KEY_SHOOT_FULL      ,0x00000060 }, // Found @0xff694ee4, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000040 }, // Found @0xff694ee4, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00000020 }, // Found @0xff694edc, levent 0x00
//    { 2, KEY_POWER           ,0x00000080 }, // Found @0xff694eec, levent 0x100
//    { 2, KEY_PLAYBACK        ,0x00000100 }, // Found @0xff694ef4, levent 0x101
//    { 2, KEY_ZOOM_OUT        ,0x00004000 }, // Found @0xff694f1c, levent 0x04
//    { 2, KEY_ZOOM_IN         ,0x00008000 }, // Found @0xff694f24, levent 0x03
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#define CAM_RAW_ROWPIX    5344 // Found @0xff1d8bac
//#define CAM_RAW_ROWS      3950 // Found @0xff1d8bb8
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff025d7c
//#define CAM_DATE_FOLDER_NAMING 0x080 // Found @0xff38a3d0 (pass as 3rd param to GetImageFolder)
//#define PARAM_CAMERA_NAME 3 // Found @0xff823a30
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
DEF(ctypes, 0xff691584)

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

// ISR flag: 0x194c, pointer to current task's control block: 0x1948
// pointer to TCB area: 0x19cc, found @ 0xff90d238

// LED table init @ 0xff1a42f0
// LED #1: 0xc022d1b0 (#65 in GPIO table), offset 0x98
// LED #2: 0xc022d1fc (#97 in GPIO table), offset 0x8
// GPIO table @ 0xff694924

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NHSTUB(AllocateUncacheableMemory              ,0xff025d38) //112
NHSTUB(Close                                  ,0xff027218) //120
NHSTUB(CreateBinarySemaphore                  ,0x006b792c) //115
NHSTUB(CreateTask                             ,0x006b5714) //120
NHSTUB(DebugAssert                            ,0x006b5ac8) //107
NHSTUB(DeleteDirectory_Fut                    ,0xff026b0c) //116
NHSTUB(DoAELock                               ,0xff032c7c) //120
NHSTUB(DoAFLock                               ,0xff032930) //120
NHSTUB(EnterToCompensationEVF                 ,0xff032ba4) //104
NHSTUB(ExecuteEventProcedure                  ,0xff034e08) //104
NHSTUB(ExitFromCompensationEVF                ,0xff032bf8) //104
NHSTUB(ExitTask                               ,0x006b5a68) //120
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff0442cc) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff044504) //104
NHSTUB(Fclose_Fut                             ,0xff026ba4) //120
NHSTUB(Feof_Fut                               ,0xff026d90) //  1
NHSTUB(Fflush_Fut                             ,0xff026dcc) //  1
NHSTUB(Fgets_Fut                              ,0xff026cf8) //  6
NHSTUB(Fopen_Fut                              ,0xff026b64) //120
NHSTUB(Fread_Fut                              ,0xff026c50) //120
NHSTUB(FreeUncacheableMemory                  ,0xff025d74) //112
NHSTUB(Fseek_Fut                              ,0xff026d44) //120
NHSTUB(Fwrite_Fut                             ,0xff026ca4) //120
NHSTUB(GetBatteryTemperature                  ,0xff077c5c) //102
NHSTUB(GetCCDTemperature                      ,0xff077be4) //102
NHSTUB(GetCurrentAvValue                      ,0xff09116c) //120
NHSTUB(GetCurrentShutterSpeed                 ,0xff13b2f4) //120
NHSTUB(GetUsableMaxAv                         ,0xff1d9478) //120
NHSTUB(GetUsableMinAv                         ,0xff1d945c) //120
NHSTUB(GetDrive_ClusterSize                   ,0xff030a50) //122
NHSTUB(GetDrive_FreeClusters                  ,0xff0311bc) //119
NHSTUB(GetDrive_TotalClusters                 ,0xff031190) //122
NHSTUB(GetFocusLensSubjectDistance            ,0xff208ec8) //102
NHSTUB(GetImageFolder                         ,0xff1e1280) //122
NHSTUB(GetKbdState                            ,0xff073d54) //109
NHSTUB(GetMemInfo                             ,0xff023450) //115
NHSTUB(GetOpticalTemperature                  ,0xff077cd4) //120
NHSTUB(GetParameterData                       ,0xff237344) //101
NHSTUB(GetPropertyCase                        ,0xff0ac55c) //101
NHSTUB(GetSystemTime                          ,0xff3de3f4) //120
NHSTUB(GetVRAMHPixelsSize                     ,0xff04ff08) //120
NHSTUB(GetVRAMVPixelsSize                     ,0xff04ff14) //120
NHSTUB(GetZoomLensCurrentPoint                ,0xff20c0bc) //120
NHSTUB(GetZoomLensCurrentPosition             ,0xff3c456c) //102
NHSTUB(GiveSemaphore                          ,0x006b7bb0) //120
NHSTUB(IsStrobeChargeCompleted                ,0xff0e758c) //102
NHSTUB(LEDDrive                               ,0xff21f8c4) //120
NHSTUB(LocalTime                              ,0x006b9ad8) //115
NHSTUB(LockMainPower                          ,0xff0b0f68) //120
NHSTUB(MakeSDCardBootable                     ,0xff0316c4) //105
NHSTUB(MoveFocusLensToDistance                ,0xff4f1888) //102
NHSTUB(MoveIrisWithAv                         ,0xff3d6ba0) //120
NHSTUB(MoveZoomLensWithPoint                  ,0xff3d750c) //120
NHSTUB(MoveOpticalZoomAt                      ,0xff032254) //109
NHSTUB(Open                                   ,0xff0271b4) //120
NHSTUB(PB2Rec                                 ,0xff05caa8) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff220a40) //102
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff220a10) //102
NHSTUB(PT_PlaySound                           ,0xff0c2da4) //122
NHSTUB(PostLogicalEventForNotPowerType        ,0xff0ae49c) //120
NHSTUB(PostLogicalEventToUI                   ,0xff0ae4f4) //120
NHSTUB(PutInNdFilter                          ,0xff3d72c4) //102
NHSTUB(PutOutNdFilter                         ,0xff3d72e8) //102
NHSTUB(Read                                   ,0xff023f0c) //120
NHSTUB(ReadFastDir                            ,0xff3acd64) //115
NHSTUB(Rec2PB                                 ,0xff05cb00) //104
NHSTUB(RenameFile_Fut                         ,0xff026a04) //116
NHSTUB(Restart                                ,0xff037ea0) //122
NHSTUB(ScreenLock                             ,0xff0b4d74) //117
NHSTUB(ScreenUnlock                           ,0xff0b4d2c) //117
NHSTUB(SetAE_ShutterSpeed                     ,0xff4ec92c) //102
NHSTUB(SetAutoShutdownTime                    ,0xff0b0fdc) //120
NHSTUB(SetCurrentCaptureModeType              ,0xff0bf9b8) //120
NHSTUB(SetFileAttributes                      ,0xff027714) //  6
NHSTUB(SetFileTimeStamp                       ,0xff02769c) //  6
NHSTUB(SetLogicalEventActive                  ,0xff0aeb64) //120
NHSTUB(SetParameterData                       ,0xff2372a8) //101
NHSTUB(SetPropertyCase                        ,0xff0ac37c) //101
NHSTUB(SetScriptMode                          ,0xff0aebb8) //120
NHSTUB(SleepTask                              ,0x006b8f0c) //120
NHSTUB(TakeSemaphore                          ,0x006b7ad4) //120
NHSTUB(TurnOnDisplay                          ,0xff06d138) //120
NHSTUB(TurnOffDisplay                         ,0xff06d148) //120
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff257274) //120
NHSTUB(UnlockAE                               ,0xff032d08) //120
NHSTUB(UnlockAF                               ,0xff032960) //120
NHSTUB(UnlockMainPower                        ,0xff0b0ec0) //120
NHSTUB(VbattGet                               ,0xff02b13c) //120
NHSTUB(Write                                  ,0xff027160) //120
NHSTUB(WriteSDCard                            ,0x006ba9e4) //108
NHSTUB(_log                                   ,0x006df1d8) //111
NHSTUB(_log10                                 ,0x006df718) //112
NHSTUB(_pow                                   ,0x006df890) //121
NHSTUB(_sqrt                                  ,0x006e1968) //  6
NHSTUB(add_ptp_handler                        ,0xff164844) //121
NHSTUB(apex2us                                ,0xff3275ec) //121
NHSTUB(err_init_task                          ,0xff0247d8) //111
NHSTUB(exmem_alloc                            ,0xff0349ec) //101
NHSTUB(exmem_free                             ,0xff034a54) //101
NHSTUB(free                                   ,0xff025084) //112
NHSTUB(get_nd_value                           ,0xff3c1c04) //123
NHSTUB(get_current_nd_value                   ,0xff3c1ba4) //122
NHSTUB(kbd_p1_f                               ,0xff02c6ec) //109
NHSTUB(kbd_p1_f_cont                          ,0xff02c6f8) //109
NHSTUB(kbd_p2_f                               ,0xff02bdb8) //109
NHSTUB(kbd_read_keys                          ,0xff02c69c) //109
NHSTUB(kbd_read_keys_r2                       ,0xff0735c8) //109
NHSTUB(lseek                                  ,0xff02752c) //120
NHSTUB(malloc                                 ,0xff02502c) //112
NHSTUB(memcmp                                 ,0xff024e04) //120
NHSTUB(memcpy                                 ,0xff0c71c8) //120
NHSTUB(memset                                 ,0xff2e3004) //120
NHSTUB(mkdir                                  ,0xff0277ac) //121
NHSTUB(mktime_ext                             ,0xff0c693c) //  1
NHSTUB(OpenFastDir                            ,0xff3acc10) //115
NHSTUB(closedir                               ,0xff3acbc0) //121
NHSTUB(get_fstype                             ,0xff0309c8) //122
NHSTUB(qsort                                  ,0xff2e2fa4) //  6
NHSTUB(rand                                   ,0xff0c7198) //121
NHSTUB(realloc                                ,0xff2e3080) //115
NHSTUB(reboot_fw_update                       ,0xff3dcd78) //106
NHSTUB(set_control_event                      ,0xff0ae824) //111
NHSTUB(srand                                  ,0xff0c718c) //122
NHSTUB(stat                                   ,0xff027574) //109
NHSTUB(strcat                                 ,0xff038800) //  1
NHSTUB(strchr                                 ,0xff038888) //  1
NHSTUB(strcmp                                 ,0xff024f00) //120
NHSTUB(strcpy                                 ,0xff024dec) //120
NHSTUB(strftime                               ,0xff0c69bc) //113
NHSTUB(strlen                                 ,0xff024f44) //120
NHSTUB(strncmp                                ,0xff03883c) //  1
NHSTUB(strncpy                                ,0xff027e8c) //  1
NHSTUB(strrchr                                ,0xff0c7314) //  1
NHSTUB(strtol                                 ,0xff0387ec) //101
NHSTUB(strtolx                                ,0xff0385f0) //109
   DEF(task_CaptSeq                           ,0xff098fdc) //120
   DEF(task_DvlpSeqTask                       ,0xff22527c) //120
   DEF(task_ExpDrv                            ,0xff1008e0) //120
   DEF(task_FileWrite                         ,0xff3ab258) //120
   DEF(task_InitFileModules                   ,0xff05f9e8) //120
   DEF(task_MovieRecord                       ,0xff2167dc) //120
   DEF(task_PhySw                             ,0xff02c188) //120
   DEF(hook_CreateTask                        ,0x006b5714) //105
NHSTUB(time                                   ,0x006b92ac) //119
NHSTUB(vsprintf                               ,0xff027e4c) //115
NHSTUB(EngDrvRead                             ,0xff02c7fc) //102
NHSTUB(PTM_GetCurrentItem                     ,0xff0b2c50) //105
NHSTUB(DisableISDriveError                    ,0xff3d8868) //120
NHSTUB(CancelHPTimer                          ,0xff0a8ca4) //119
NHSTUB(SetHPTimerAfterNow                     ,0xff0a8b9c) //119
NHSTUB(SS_MFOn                                ,0xff220ad4) //120
NHSTUB(SS_MFOff                               ,0xff220ae4) //120
NHSTUB(GetAdChValue                           ,0xff06e55c) //120
NHSTUB(get_ptp_buf_size                       ,0xff154980) //122
NHSTUB(get_ptp_file_buf                       ,0xff33918c) //121
