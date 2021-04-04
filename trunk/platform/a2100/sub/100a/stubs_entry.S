// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R31 (DRYOS version 2.3, release #0031)
//   Firmware Ver GM1.00A   // Found @ 0xffc5833c, "GM1.00A" @ 0xffc58349
//   Firmware build timestamp: Jan  5 2009 15:59:12
//   Canon PowerShot A2100 IS

// Values for makefile.inc
//   DIGIC = 40# DIGIC 4
//   PLATFORMOSVER = 31
//   PLATFORMID = 12734# (0x31be) Found @ 0xfffe0130
//   MAXRAMADDR = 0x03ffffff
//   MEMISOSTART = 0x0012edb4
//   KEYSYS = d4# Found @ 0xffff1d14
//   NEED_ENCODED_DISKBOOT = 2# Found @ 0xffff1d24
//   ARAM_HEAP_START = 0x34e000# Found @ 0xffd037c4
//   ARAM_HEAP_SIZE  = 0x32000# Found @ 0xffd03784

// Detected address ranges:
// ROM      0xffc00000 - 0xffffffff (4194304 bytes)
// RAM data 0x00001900 - 0x0000b1f8 copied from 0xffed7374 (  39160 bytes)

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
NHSTUB(kbd_pwr_off                            ,0xffc30bd4) //  2 64%
NHSTUB(kbd_pwr_on                             ,0xffc30b94) //  2 82%

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ffdff8dc -> ffebdc2c
// Mode 16390 in firmware but not in current modemap
// Mode  2598 in firmware but not in current modemap

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x0000c664) // Found @0xffc11a0c
DEF(physw_run                               ,0x00001c24) // Found @0xffc11680
DEF(physw_sleep_delay                       ,0x00001c22) // Found @0xffc11680
DEF(levent_table                            ,0xffe95518) // Found @0xffe95518
DEF(FlashParamsTable                        ,0xffebde00) // Found @0xffebde00
DEF(movie_status                            ,0x00005670) // Found @0xffcf840c
DEF(canon_menu_active                       ,0x00002b78) // Found @0xffc59d6c
DEF(canon_shoot_menu_active                 ,0x0000690d) // Found @0xffd2c9a4
DEF(playrec_mode                            ,0x000028e8) // Found @0xffc4d404
DEF(zoom_status                             ,0x00009938) // Found @0xffe0110c
DEF(some_flag_for_af_scan                   ,0x00005b24) // Found @0xffcfab30
DEF(zoom_busy                               ,0x0000559c) // Found @0xffcf4b10
DEF(focus_busy                              ,0x00005498) // Found @0xffcef9e4
DEF(recreview_hold                          ,0x000030dc) // Found @0xffc657a0
// Palette colour tables  found @ 0xffea4ca4
DEF(active_palette_buffer                   ,0x000075f4) // Found @0xffd68508
DEF(palette_buffer_ptr                      ,0x00007604) // Found @0xffd681e0
// Offset from start of palette_buffer to color data = 12 (Found @0xffd672bc)
// Camera appears to have only 1 RAW buffer @ 0x4139e56c (Found @0xffe46704)
DEF(fileio_semaphore                        ,0x000025f4) // Found @0xffc3d318
DEF(exmem_alloc_table                       ,0x00012628) // Found @0xffc537e0
DEF(exmem_types_table                       ,0xffed843c) // Found @0x000029c8
DEF_CONST(exmem_type_count                  ,0x00000012)
DEF(imager_active                           ,0x00001e90) // Found @0xffc220ec (0x1e8c + 4)
DEF_CONST(uiprop_count                      ,0x0000006b) // Found @0xffd1c5a8
DEF(cameracon_state                         ,0x00002cec) // Found @0xffc5e010

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x403f1000; }             // Found @0xffc2c5cc
//void *vid_get_viewport_fb()      { return (void*)0x4076fcc0; }             // Found @0xffe441f8
DEF(viewport_fb_d                           ,0x00002680) // Found 0x2628 (@0xffc403a8) + 0x58 (@0xffc403e0)
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x2628+0x58)); } // Found @0xffc403a8 & 0xffc403e0
DEF(jpeg_count_str                          ,0x0002f55c) // Found @0xffd60580
//char *camera_jpeg_count_str()    { return (char*)0x0002f55c; }             // Found @0xffd60580
//int get_flash_params_count(void) { return 0x7a; }                          // Found @0xffd1cfec

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffe7172c, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x00040000 // Found @0xffe71738, levent 0x902
//#define USB_IDX             2
//#define BATTCOVER_FLAG      0x00004000 // Found @0xffe71714, levent 0x905
//#define BATTCOVER_IDX       2
//#define ANALOG_AV_FLAG      0x00002000 // Found @0xffe71618, levent 0x900 (non-inverted logic)
//#define ANALOG_AV_IDX       1

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 1, KEY_SET             ,0x01000000 }, // Found @0xffe71624, levent 0x08
//    { 1, KEY_MENU            ,0x02000000 }, // Found @0xffe71630, levent 0x09
//    { 1, KEY_DISPLAY         ,0x04000000 }, // Found @0xffe7163c, levent 0x0a
//    { 2, KEY_SHOOT_FULL      ,0x0000000c }, // Found @0xffe716a8, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000008 }, // Found @0xffe716a8, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00000004 }, // Found @0xffe7169c, levent 0x00
//    { 2, KEY_ZOOM_IN         ,0x00000010 }, // Found @0xffe716b4, levent 0x02
//    { 2, KEY_ZOOM_OUT        ,0x00000020 }, // Found @0xffe716c0, levent 0x03
//    { 2, KEY_POWER           ,0x00000040 }, // Found @0xffe716cc, levent 0x600 (uses inverted logic in physw_status)
//    { 2, KEY_PLAYBACK        ,0x00000080 }, // Found @0xffe716d8, levent 0x601 (uses inverted logic in physw_status)
//    { 2, KEY_UP              ,0x00000100 }, // Found @0xffe716e4, levent 0x04
//    { 2, KEY_DOWN            ,0x00000200 }, // Found @0xffe716f0, levent 0x05
//    { 2, KEY_RIGHT           ,0x00000400 }, // Found @0xffe716fc, levent 0x07
//    { 2, KEY_LEFT            ,0x00000800 }, // Found @0xffe71708, levent 0x06
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_RAW_ROWPIX    4104 // Found @0xffcc7c70
//#define CAM_RAW_ROWS      3048 // Found @0xffcc7c78
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xffc16edc
//#define PARAM_CAMERA_NAME 4 // Found @0xffebfe4c

// Below goes in 'filewrite.c' or 'platform_camera.h':
//#define MAX_CHUNKS_FOR_FWT 3 // Found @0xffddbce8

// Known propcases
// //      PROPCASE_AFSTEP 13
// #define PROPCASE_FOCUS_STATE 18
// #define PROPCASE_AV 23
// #define PROPCASE_BV 34
// //      PROPCASE_DELTA_DIGITALGAIN 77
// #define PROPCASE_DELTA_SV 79
// //      PROPCASE_DELTA_ND 80
// #define PROPCASE_EV_CORRECTION_2 207
// #define PROPCASE_ORIENTATION_SENSOR 219
// #define PROPCASE_SV_MARKET 246
// //      PROPCASE_SVFIX 247
// #define PROPCASE_TV 262
// Guessed propset: 2

// Misc stuff
DEF(ctypes, 0xffe70516)

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
// EXMEM_FILESTORE      11
// EXMEM_MOVIE_REC      12
// EXMEM_MOVIE_PLY      13
// EXMEM_WIDE           14
// EXMEM_NARROW         15
// EXMEM_CRAW_REC       16
// EXMEM_PCEVF          17

// ISR flag: 0x1960, pointer to current task's control block: 0x195c
// pointer to TCB area: 0x19ec, found @ 0xffc0574c

// LED table init @ 0xffcade50
// LED #1: 0xc022000c, offset 0x244
// LED #2: 0xc0220018, offset 0x204
// LED #3: 0xc0220014, offset 0x4
// LED #4: 0xc0220010, offset 0x44

// For capt_seq.c
DEF(_nrflag,0x5b08) // Found @ ffcfc85c (0x5b10) & ffcfc87c (-0x08)
//static long *nrflag = (long*)(0x5b10-0x08);  // Found @ ffcfc85c & ffcfc878

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NHSTUB(AllocateUncacheableMemory              ,0xffc16e98) //112
NHSTUB(Close                                  ,0xffc138e0) //120
NHSTUB(CreateBinarySemaphore                  ,0xffc16678) //115
NHSTUB(CreateTask                             ,0xffc0afac) //120
NHSTUB(DebugAssert                            ,0xffc0b284) //107
NHSTUB(DeleteDirectory_Fut                    ,0xffc13270) //116
NHSTUB(DeleteFile_Fut                         ,0xffc1318c) //112
NHSTUB(DoAELock                               ,0xffc15084) //120
NHSTUB(DoAFLock                               ,0xffc14f3c) //120
NHSTUB(EnterToCompensationEVF                 ,0xffc14fec) //104
NHSTUB(ExecuteEventProcedure                  ,0xffc554e4) //104
NHSTUB(ExitFromCompensationEVF                ,0xffc15030) //104
NHSTUB(ExitTask                               ,0xffc0b23c) //120
NHSTUB(ExpCtrlTool_StartContiAE               ,0xffc1f8d8) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xffc1fa1c) //104
NHSTUB(Fclose_Fut                             ,0xffc13308) //120
NHSTUB(Feof_Fut                               ,0xffc134f4) //  1
NHSTUB(Fflush_Fut                             ,0xffc13530) //  1
NHSTUB(Fgets_Fut                              ,0xffc1345c) //  1
NHSTUB(Fopen_Fut                              ,0xffc132c8) //120
NHSTUB(Fread_Fut                              ,0xffc133b4) //120
NHSTUB(FreeUncacheableMemory                  ,0xffc16ed8) //112
NHSTUB(Fseek_Fut                              ,0xffc134a8) //120
NHSTUB(Fwrite_Fut                             ,0xffc13408) //120
NHSTUB(GetBatteryTemperature                  ,0xffc32c7c) //102
NHSTUB(GetCCDTemperature                      ,0xffc32c08) //102
NHSTUB(GetCurrentAvValue                      ,0xffcf179c) //120
NHSTUB(GetCurrentShutterSpeed                 ,0xffc6ce58) //120
NHSTUB(GetDrive_ClusterSize                   ,0xffc3ec3c) //  5
NHSTUB(GetDrive_FreeClusters                  ,0xffc3ec94) //  5
NHSTUB(GetDrive_TotalClusters                 ,0xffc3ec68) //  5
NHSTUB(GetFocusLensSubjectDistance            ,0xffcf084c) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xffcf0c28) //  3
NHSTUB(GetKbdState                            ,0xffc30b60) //109
NHSTUB(GetMemInfo                             ,0xffc03be4) //115
NHSTUB(GetOpticalTemperature                  ,0xffc32cf4) //120
NHSTUB(GetParameterData                       ,0xffd1cfac) //101
NHSTUB(GetPropertyCase                        ,0xffc59250) //102
NHSTUB(GetSystemTime                          ,0xffdf5dbc) //120
NHSTUB(GetVRAMHPixelsSize                     ,0xffc959a8) //120
NHSTUB(GetVRAMVPixelsSize                     ,0xffc959b4) //120
NHSTUB(GetZoomLensCurrentPoint                ,0xffcf4e88) //120
NHSTUB(GetZoomLensCurrentPosition             ,0xffdedca8) //102
NHSTUB(GiveSemaphore                          ,0xffc168b4) //120
NHSTUB(IsStrobeChargeCompleted                ,0xffc87128) //102
NHSTUB(LEDDrive                               ,0xffc300c0) //120
NHSTUB(LocalTime                              ,0xffc531a8) //115
NHSTUB(LockMainPower                          ,0xffc5cb44) //120
NHSTUB(MakeDirectory_Fut                      ,0xffc13200) //116
NHSTUB(MoveFocusLensToDistance                ,0xffe40c28) //102
NHSTUB(MoveIrisWithAv                         ,0xffdf2fbc) //120
NHSTUB(MoveZoomLensWithPoint                  ,0xffdf3548) //120
NHSTUB(MoveOpticalZoomAt                      ,0xffc14b0c) //109
NHSTUB(Open                                   ,0xffc138b8) //120
NHSTUB(PB2Rec                                 ,0xffc5e5c4) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xffc46c90) //120
NHSTUB(PT_MoveOpticalZoomAt                   ,0xffc46c68) //120
NHSTUB(PT_PlaySound                           ,0xffc468a4) //102
NHSTUB(PostLogicalEventForNotPowerType        ,0xffc5c16c) //120
NHSTUB(PostLogicalEventToUI                   ,0xffc5c1b8) //120
NHSTUB(PutInNdFilter                          ,0xffdf33ac) //102
NHSTUB(PutOutNdFilter                         ,0xffdf33d0) //102
NHSTUB(Read                                   ,0xffc09ae4) //120
NHSTUB(ReadFastDir                            ,0xffde0144) //  1
NHSTUB(Rec2PB                                 ,0xffc5f9ac) //104
NHSTUB(RefreshPhysicalScreen                  ,0xffd6be30) //104
NHSTUB(RenameFile_Fut                         ,0xffc13138) //  1
NHSTUB(Restart                                ,0xffc185ec) //122
NHSTUB(SetAE_ShutterSpeed                     ,0xffe43408) //102
NHSTUB(SetAutoShutdownTime                    ,0xffc5cbb8) //120
NHSTUB(SetCurrentCaptureModeType              ,0xffc63140) //120
NHSTUB(SetDate                                ,0xffe44e44) //120
NHSTUB(SetFileAttributes                      ,0xffc13c0c) //  1
NHSTUB(SetFileTimeStamp                       ,0xffc13bbc) //  1
NHSTUB(SetLogicalEventActive                  ,0xffc5c8c0) //120
NHSTUB(SetParameterData                       ,0xffd1cf1c) //101
NHSTUB(SetPropertyCase                        ,0xffc59148) //102
NHSTUB(SetScriptMode                          ,0xffc5c910) //120
NHSTUB(SleepTask                              ,0xffc16b1c) //120
NHSTUB(TakeSemaphore                          ,0xffc167e4) //120
NHSTUB(TurnOffBackLight                       ,0xffc67d2c) //104
NHSTUB(TurnOnBackLight                        ,0xffc67d14) //104
NHSTUB(TurnOnDisplay                          ,0xffc2c694) //120
NHSTUB(TurnOffDisplay                         ,0xffc2c6a4) //120
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xffd0d7dc) //120
NHSTUB(UnlockAE                               ,0xffc150a8) //120
NHSTUB(UnlockAF                               ,0xffc14f74) //120
NHSTUB(UnlockMainPower                        ,0xffc5ca98) //120
NHSTUB(UnsetZoomForMovie                      ,0xffd22bf0) //104
NHSTUB(UpdateMBROnFlash                       ,0xffc3ea94) //105
NHSTUB(VbattGet                               ,0xffc10318) //120
NHSTUB(Write                                  ,0xffc1398c) //120
NHSTUB(WriteSDCard                            ,0xffce4718) //108
NHSTUB(_log                                   ,0xffe6e31c) //111
NHSTUB(_log10                                 ,0xffe6d260) //112
NHSTUB(_pow                                   ,0xffe6d3d0) //121
NHSTUB(_sqrt                                  ,0xffe6f684) //  1
NHSTUB(add_ptp_handler                        ,0xffdb1e84) //121
NHSTUB(apex2us                                ,0xffd6ced4) //121
NHSTUB(close                                  ,0xffc098fc) //109
NHSTUB(err_init_task                          ,0xffc04e2c) //111
NHSTUB(exmem_alloc                            ,0xffc53ddc) //103
NHSTUB(exmem_ualloc                           ,0xffc53c30) //103
NHSTUB(exmem_ufree                            ,0xffc53d7c) //103
NHSTUB(free                                   ,0xffc03a3c) //112
NHSTUB(get_nd_value                           ,0xffdeb7fc) //123
NHSTUB(get_current_nd_value                   ,0xffdeb7b8) //122
NHSTUB(get_current_deltasv                    ,0xffc6d9e8) //122
NHSTUB(GetCurrentDriveBaseSvValue             ,0xffc72bf0) //123
NHSTUB(kbd_p1_f                               ,0xffc11a90) //109
NHSTUB(kbd_p1_f_cont                          ,0xffc11a9c) //109
NHSTUB(kbd_p2_f                               ,0xffc1134c) //109
NHSTUB(kbd_read_keys                          ,0xffc11a0c) //109
NHSTUB(kbd_read_keys_r2                       ,0xffc304dc) //109
NHSTUB(lseek                                  ,0xffc13a20) //120
NHSTUB(malloc                                 ,0xffc03968) //112
NHSTUB(memcmp                                 ,0xffc0cc60) //120
NHSTUB(memcpy                                 ,0xffc6ba00) //120
NHSTUB(memset                                 ,0xffd6c1bc) //120
NHSTUB(mkdir                                  ,0xffc13c84) //109
NHSTUB(mktime_ext                             ,0xffc6c26c) //  1
NHSTUB(open                                   ,0xffc0984c) //109
NHSTUB(OpenFastDir                            ,0xffde00b0) //  1
NHSTUB(closedir                               ,0xffde0214) //  1
NHSTUB(qsort                                  ,0xffe27428) //  1
NHSTUB(rand                                   ,0xffc0cd68) //121
NHSTUB(realloc                                ,0xffc03b1c) //115
NHSTUB(reboot_fw_update                       ,0xffde3c28) //106
NHSTUB(set_control_event                      ,0xffc5c5f4) //111
NHSTUB(srand                                  ,0xffc0cd5c) //122
NHSTUB(stat                                   ,0xffc13aec) //  1
NHSTUB(strcat                                 ,0xffc6b814) //  1
NHSTUB(strchr                                 ,0xffc6b89c) //  1
NHSTUB(strcmp                                 ,0xffc0cbf8) //120
NHSTUB(strcpy                                 ,0xffc0cbe0) //120
NHSTUB(strftime                               ,0xffc6bc74) //  1
NHSTUB(strlen                                 ,0xffc0cc3c) //120
NHSTUB(strncmp                                ,0xffc6b850) //  1
NHSTUB(strncpy                                ,0xffc1c6d4) //  1
NHSTUB(strrchr                                ,0xffd6c194) //  1
NHSTUB(strtol                                 ,0xffc1c90c) //101
NHSTUB(strtolx                                ,0xffc1c710) //109
   DEF(task_CaptSeq                           ,0xffc48f48) //120
   DEF(task_DvlpSeqTask                       ,0xffcfd560) //120
   DEF(task_ExpDrv                            ,0xffc7ddf0) //120
   DEF(task_FileWrite                         ,0xffddbc84) //120
   DEF(task_InitFileModules                   ,0xffc6036c) //120
   DEF(task_MovieRecord                       ,0xffcf8660) //120
   DEF(task_PhySw                             ,0xffc1167c) //120
NHSTUB(time                                   ,0xffc5305c) //109
NHSTUB(vsprintf                               ,0xffc0cba4) //115
NHSTUB(EngDrvRead                             ,0xffc128cc) //102
NHSTUB(PTM_GetCurrentItem                     ,0xffc5d574) //105
NHSTUB(CancelHPTimer                          ,0xffc54bcc) //119
NHSTUB(SetHPTimerAfterNow                     ,0xffc54ac4) //119
NHSTUB(PT_MFOn                                ,0xffc46d08) //120
NHSTUB(PT_MFOff                               ,0xffc46d18) //120
NHSTUB(GetAdChValue                           ,0xffc2e0d4) //120
NHSTUB(get_ptp_buf_size                       ,0xffc9852c) //122
NHSTUB(get_ptp_file_buf                       ,0xffdb3a00) //121
NHSTUB(SetVideoOutType                        ,0xffe43bf4) //109
NHSTUB(GetVideoOutType                        ,0xffe43b58) //120
