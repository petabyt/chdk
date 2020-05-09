// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R39 (DRYOS version 2.3, release #0039)
//   Firmware Ver GM1.01C   // Found @ 0xff88bbd4, "GM1.01C" @ 0xff88bbe1
//   Firmware build timestamp: Feb  3 2010 08:56:28
//   Possible corrupt firmware dump - file size too small for start address 0xff810000
//     file size = 7.15MB, should be 7.94MB
//   Could not find Camera name - possible corrupt firmware dump

// Values for makefile.inc
//   DIGIC = 40# DIGIC 4
//   PLATFORMOSVER = 39
//   PLATFORMID = ?           // Not found @ 0xfffe0130
//   MAXRAMADDR = 0x03ffffff
//   MEMISOSTART = 0x00141dbc
//   ARAM_HEAP_START = 0x3ce000# Found @ 0xff96ff2c
//   ARAM_HEAP_SIZE  = 0x32000# Found @ 0xff96feec

// Detected address ranges:
// ROM      0xff810000 - 0xffffffff (8323072 bytes)
// RAM data 0x00001900 - 0x0000f470 copied from 0xffc14e98 (  56176 bytes)

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NHSTUB(SetScriptMode                        ,0xff894498) //120        *** != 0xff810f4c
//NHSTUB(kbd_pwr_off                          ,0xff85e3a4) //  2 60%    *** != 0xff833350

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ffaaea90 -> ffbefb90
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x000330d8) // Found @0xff8335b4
DEF(physw_run                               ,0x00001c44) // Found @0xff83320c
DEF(physw_sleep_delay                       ,0x00001c42) // Found @0xff83320c
DEF(levent_table                            ,0xffb8b680) // Found @0xffb8b680
DEF(FlashParamsTable                        ,0xffbefd80) // Found @0xffbefd80
DEF(movie_status                            ,0x00007ae8) // Found @0xff961658
DEF(video_compression_rate                  ,0x00007b14) // Found @0xff9618c0
DEF(full_screen_refresh                     ,0x0000a36c) // Found @0xffa07f84
DEF(canon_menu_active                       ,0x00003038) // Found @0xff88d6ac
DEF(canon_shoot_menu_active                 ,0x00008dd1) // Found @0xff9ab95c
DEF(playrec_mode                            ,0x00002d64) // Found @0xff87fa70
DEF(zoom_status                             ,0x00008aa4) // Found @0xff99bd30
DEF(some_flag_for_af_scan                   ,0x00007ff4) // Found @0xff9646e8
DEF(zoom_busy                               ,0x00007a14) // Found @0xff95d888
DEF(focus_busy                              ,0x000078dc) // Found @0xff957d98
//DEF(recreview_hold                          ,0x00003a94) // Found @0xff89e70c, ** != ** stubs_min = 0x00008a28 (0x8944+0xE4)
// Palette colour tables  found @ 0xffba55c4
DEF(active_palette_buffer                   ,0x0000a374) // Found @0xffa07ec4
DEF(palette_buffer_ptr                      ,0x0000a380) // Found @0xffa07b98
// Offset from start of palette_buffer to color data = 8 (Found @0xffae56b8)
// Camera appears to have only 1 RAW buffer @ 0x4213a6ec (Found @0xffb0275c)
DEF(fileio_semaphore                        ,0x000029d0) // Found @0xff86c998
DEF(exmem_alloc_table                       ,0x0003a3e4) // Found @0xff886fb0
DEF(exmem_types_table                       ,0xffc16420) // Found @0x00002e88
DEF_CONST(exmem_type_count                  ,0x00000012)
DEF(imager_active                           ,0x00001fc8) // Found @0xff84a6f4 (0x1fc4 + 4)
DEF_CONST(uiprop_count                      ,0x0000006e) // Found @0xff994078

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x40471000; }             // Found @0xff858728
//void *vid_get_viewport_fb()      { return (void*)0x407e8a00; }             // Found @0xffaff4ec
DEF(viewport_fb_d                           ,0x00002a78) // Found 0x2a20 (@0xff86fa48) + 0x58 (@0xff86fa80)
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x2a20+0x58)); } // Found @0xff86fa48 & 0xff86fa80
DEF(jpeg_count_str                          ,0x0009792c) // Found @0xff9fc148
//char *camera_jpeg_count_str()    { return (char*)0x0009792c; }             // Found @0xff9fc148
//int get_flash_params_count(void) { return 0x85; }                          // Found @0xff994ccc

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffb3ac60, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x00200000 // Found @0xffb3ac78, levent 0x902
//#define USB_IDX             2
//#define BATTCOVER_FLAG      0x00008000 // Found @0xffb3ab7c, levent 0x905
//#define BATTCOVER_IDX       0
//#define ANALOG_AV_FLAG      0x00040000 // Found @0xffb3ac6c, levent 0x900 (non-inverted logic)
//#define ANALOG_AV_IDX       2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_SHOOT_FULL      ,0x00000300 }, // Found @0xffb3ab4c, levent 0x01
//    { 0, KEY_SHOOT_FULL_ONLY ,0x00000200 }, // Found @0xffb3ab4c, levent 0x01
//    { 0, KEY_SHOOT_HALF      ,0x00000100 }, // Found @0xffb3ab40, levent 0x00
//    { 0, KEY_POWER           ,0x00000400 }, // Found @0xffb3ab58, levent 0x600
//    { 0, KEY_PLAYBACK        ,0x00000800 }, // Found @0xffb3ab64, levent 0x601
//    { 1, KEY_ZOOM_IN         ,0x00000010 }, // Found @0xffb3abc4, levent 0x02
//    { 1, KEY_ZOOM_OUT        ,0x00000020 }, // Found @0xffb3abd0, levent 0x03
//    { 1, KEY_LEFT            ,0x00000100 }, // Found @0xffb3abf4, levent 0x06
//    { 1, KEY_RIGHT           ,0x00000200 }, // Found @0xffb3ac00, levent 0x07
//    { 1, KEY_DOWN            ,0x00000400 }, // Found @0xffb3ac0c, levent 0x05
//    { 1, KEY_DISPLAY         ,0x00001000 }, // Found @0xffb3ac24, levent 0x0a
//    { 1, KEY_MENU            ,0x00002000 }, // Found @0xffb3ac30, levent 0x09
//    { 1, KEY_UP              ,0x00004000 }, // Found @0xffb3ac3c, levent 0x04
//    { 1, KEY_SET             ,0x00008000 }, // Found @0xffb3ac48, levent 0x08
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_RAW_ROWPIX    3744 // Found @0xff934648
//#define CAM_RAW_ROWS      2784 // Found @0xff934650
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff838e10
//#define CAM_DATE_FOLDER_NAMING 0x100 // Found @0xffa69f28 (pass as 3rd param to GetImageFolder)
//#define PARAM_CAMERA_NAME 4 // Found @0xffbf2508

// Known propcases
// //      PROPCASE_AFSTEP 13
// #define PROPCASE_FOCUS_STATE 18
// #define PROPCASE_AV 23
// #define PROPCASE_BV 34
// //      PROPCASE_DELTA_DIGITALGAIN 77
// #define PROPCASE_DELTA_SV 79
// //      PROPCASE_DELTA_ND 80
// #define PROPCASE_EV_CORRECTION_2 209
// #define PROPCASE_ORIENTATION_SENSOR 221
// #define PROPCASE_SV_MARKET 248
// //      PROPCASE_SVFIX 249
// #define PROPCASE_TV 264
// Guessed propset: 3

// Misc stuff
DEF(ctypes, 0xffb39582)

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

// ISR flag: 0x1964, pointer to current task's control block: 0x1960
// pointer to TCB area: 0x19f0, found @ 0xff81683c

// LED table init @ 0xff916274
// LED #1: 0xc0220130, offset 0x4
// LED #2: 0xc0220134, offset 0x44

// For capt_seq.c
DEF(_nrflag,0x7fd0) // Found @ ff966b50 (0x7fd8) & ff966b70 (-0x08)
//static long *nrflag = (long*)(0x7fd8-0x08);  // Found @ ff966b50 & ff966b6c

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NHSTUB(AllocateUncacheableMemory              ,0xff838dcc) //112
NHSTUB(Close                                  ,0xff835414) //120
NHSTUB(CreateBinarySemaphore                  ,0xff8385ac) //115
NHSTUB(CreateTask                             ,0xff81e5b4) //120
NHSTUB(DebugAssert                            ,0xff81e88c) //107
NHSTUB(DeleteDirectory_Fut                    ,0xff834e84) //116
NHSTUB(DeleteFile_Fut                         ,0xff834da0) //112
NHSTUB(DoAELock                               ,0xff836de0) //120
NHSTUB(DoAFLock                               ,0xff836b98) //120
NHSTUB(EnterToCompensationEVF                 ,0xff836d3c) //104
NHSTUB(ExecuteEventProcedure                  ,0xff888d78) //104
NHSTUB(ExitFromCompensationEVF                ,0xff836d80) //104
NHSTUB(ExitTask                               ,0xff81e844) //120
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff844700) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff8447d8) //104
NHSTUB(Fclose_Fut                             ,0xff834f1c) //120
NHSTUB(Feof_Fut                               ,0xff835108) //  1
NHSTUB(Fflush_Fut                             ,0xff835144) //  1
NHSTUB(Fgets_Fut                              ,0xff835070) //  1
NHSTUB(Fopen_Fut                              ,0xff834edc) //120
NHSTUB(Fread_Fut                              ,0xff834fc8) //120
NHSTUB(FreeUncacheableMemory                  ,0xff838e0c) //112
NHSTUB(Fseek_Fut                              ,0xff8350bc) //120
NHSTUB(Fwrite_Fut                             ,0xff83501c) //120
NHSTUB(GetBatteryTemperature                  ,0xff8615f0) //102
NHSTUB(GetCCDTemperature                      ,0xff86157c) //102
NHSTUB(GetCurrentAvValue                      ,0xff95a53c) //120
NHSTUB(GetCurrentShutterSpeed                 ,0xff8b0638) //120
NHSTUB(GetUsableMaxAv                         ,0xffaf9be4) //120
NHSTUB(GetUsableMinAv                         ,0xffaf9bcc) //120
NHSTUB(GetDrive_ClusterSize                   ,0xff86e380) //122
NHSTUB(GetDrive_FreeClusters                  ,0xff86e3e0) //  3
NHSTUB(GetDrive_TotalClusters                 ,0xff86e3b4) //  3
NHSTUB(GetFocusLensSubjectDistance            ,0xff958b10) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff958f58) //  3
NHSTUB(GetImageFolder                         ,0xff93c4d4) //122
NHSTUB(GetKbdState                            ,0xff85e258) //109
NHSTUB(GetMemInfo                             ,0xff81a070) //115
NHSTUB(GetOpticalTemperature                  ,0xff861664) //120
NHSTUB(GetParameterData                       ,0xff994c8c) //101
NHSTUB(GetPropertyCase                        ,0xff88cae0) //102
NHSTUB(GetSystemTime                          ,0xffa9d3d0) //120
NHSTUB(GetVRAMHPixelsSize                     ,0xff84f110) //120
NHSTUB(GetVRAMVPixelsSize                     ,0xff84f11c) //120
NHSTUB(GetZoomLensCurrentPoint                ,0xff95dbfc) //120
NHSTUB(GetZoomLensCurrentPosition             ,0xffa9101c) //102
NHSTUB(GiveSemaphore                          ,0xff8387e8) //120
NHSTUB(IsStrobeChargeCompleted                ,0xff8d878c) //102
NHSTUB(LEDDrive                               ,0xff85d648) //120
NHSTUB(LocalTime                              ,0xff8866ec) //115
NHSTUB(LockMainPower                          ,0xff8946f8) //120
NHSTUB(MakeDirectory_Fut                      ,0xff834e14) //116
NHSTUB(MoveFocusLensToDistance                ,0xffafbf00) //102
NHSTUB(MoveIrisWithAv                         ,0xffa9ad44) //120
NHSTUB(MoveZoomLensWithPoint                  ,0xffa9b3b8) //120
NHSTUB(MoveOpticalZoomAt                      ,0xff836500) //109
NHSTUB(Open                                   ,0xff8353bc) //120
NHSTUB(PB2Rec                                 ,0xff897840) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff87772c) //120
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff877704) //120
NHSTUB(PT_PlaySound                           ,0xff881888) //102
NHSTUB(PostLogicalEventForNotPowerType        ,0xff892524) //120
NHSTUB(PostLogicalEventToUI                   ,0xff892570) //120
NHSTUB(PutInNdFilter                          ,0xffaf9c50) //102
NHSTUB(PutOutNdFilter                         ,0xffaf9c88) //102
NHSTUB(Read                                   ,0xff81ab78) //120
NHSTUB(ReadFastDir                            ,0xffa7d958) //  3
NHSTUB(Rec2PB                                 ,0xff897880) //104
NHSTUB(RefreshPhysicalScreen                  ,0xffa090fc) //104
NHSTUB(RenameFile_Fut                         ,0xff834d0c) //116
NHSTUB(Restart                                ,0xff83a520) //122
NHSTUB(ScreenLock                             ,0xffa0a31c) //117
NHSTUB(ScreenUnlock                           ,0xffa0a344) //117
NHSTUB(SetAE_ShutterSpeed                     ,0xffafe6ac) //102
NHSTUB(SetAutoShutdownTime                    ,0xff89476c) //120
NHSTUB(SetCurrentCaptureModeType              ,0xff89b830) //120
NHSTUB(SetFileAttributes                      ,0xff8356e4) //  3
NHSTUB(SetFileTimeStamp                       ,0xff8356a0) //  3
NHSTUB(SetLogicalEventActive                  ,0xff894448) //120
NHSTUB(SetParameterData                       ,0xff994b68) //101
NHSTUB(SetPropertyCase                        ,0xff88c9dc) //102
NHSTUB(SleepTask                              ,0xff838a50) //120
NHSTUB(TakeSemaphore                          ,0xff838718) //120
NHSTUB(TurnOffBackLight                       ,0xff8a49c8) //104
NHSTUB(TurnOnBackLight                        ,0xff8a49b0) //104
NHSTUB(TurnOnDisplay                          ,0xff85892c) //120
NHSTUB(TurnOffDisplay                         ,0xff85893c) //120
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff97ec10) //120
NHSTUB(UnlockAE                               ,0xff836e04) //120
NHSTUB(UnlockAF                               ,0xff836bd0) //120
NHSTUB(UnlockMainPower                        ,0xff89464c) //120
NHSTUB(UnsetZoomForMovie                      ,0xff8a0f30) //104
NHSTUB(UpdateMBROnFlash                       ,0xff86e200) //105
NHSTUB(VbattGet                               ,0xff831e04) //120
NHSTUB(Write                                  ,0xff8354a4) //120
NHSTUB(WriteSDCard                            ,0xff94a63c) //108
NHSTUB(_log                                   ,0xffb36808) //111
NHSTUB(_log10                                 ,0xffb35494) //112
NHSTUB(_pow                                   ,0xffb35604) //121
NHSTUB(_sqrt                                  ,0xffb383ac) //  1
NHSTUB(add_ptp_handler                        ,0xffa471d0) //121
NHSTUB(apex2us                                ,0xffa0d9b8) //121
NHSTUB(close                                  ,0xff81a990) //109
NHSTUB(err_init_task                          ,0xff815f28) //111
NHSTUB(exmem_alloc                            ,0xff8875ac) //103
NHSTUB(exmem_ualloc                           ,0xff887400) //103
NHSTUB(exmem_ufree                            ,0xff88754c) //103
NHSTUB(free                                   ,0xff814138) //112
NHSTUB(kbd_p1_f                               ,0xff833630) //109
NHSTUB(kbd_p1_f_cont                          ,0xff83363c) //109
NHSTUB(kbd_p2_f                               ,0xff832ed8) //109
NHSTUB(kbd_read_keys                          ,0xff8335b4) //109
NHSTUB(kbd_read_keys_r2                       ,0xff85db5c) //109
NHSTUB(lseek                                  ,0xff835530) //120
NHSTUB(malloc                                 ,0xff8140dc) //112
NHSTUB(memcmp                                 ,0xff8203e8) //120
NHSTUB(memcpy                                 ,0xff83e43c) //120
NHSTUB(memset                                 ,0xffa0ca08) //120
NHSTUB(mkdir                                  ,0xff835888) //109
NHSTUB(mktime_ext                             ,0xff8ac380) //  1
NHSTUB(open                                   ,0xff81a8e0) //109
NHSTUB(OpenFastDir                            ,0xffa7d824) //  3
NHSTUB(closedir                               ,0xffa7d7e0) //  3
NHSTUB(get_fstype                             ,0xff86e404) //122
NHSTUB(qsort                                  ,0xffaec5e8) //  1
NHSTUB(rand                                   ,0xff8204f0) //121
NHSTUB(realloc                                ,0xffa0ca84) //115
NHSTUB(reboot_fw_update                       ,0xffa82e68) //106
NHSTUB(set_control_event                      ,0xff89409c) //111
NHSTUB(srand                                  ,0xff8204e4) //122
NHSTUB(stat                                   ,0xff83556c) //109
NHSTUB(strcat                                 ,0xff8abb3c) //  1
NHSTUB(strchr                                 ,0xff813fc0) //  1
NHSTUB(strcmp                                 ,0xff8203a4) //120
NHSTUB(strcpy                                 ,0xff82038c) //120
NHSTUB(strftime                               ,0xff8abd88) //  1
NHSTUB(strlen                                 ,0xff81400c) //120
NHSTUB(strncmp                                ,0xff813f74) //  1
NHSTUB(strncpy                                ,0xff813f38) //  1
NHSTUB(strrchr                                ,0xff813fe4) //  1
NHSTUB(strtol                                 ,0xff83e71c) //101
NHSTUB(strtolx                                ,0xff83e520) //109
   DEF(task_CaptSeq                           ,0xff87a258) //120
   DEF(task_DvlpSeqTask                       ,0xff87bbf0) //120
   DEF(task_ExpDrv                            ,0xff8c0ed0) //120
   DEF(task_FileWrite                         ,0xffa791b0) //120
   DEF(task_InitFileModules                   ,0xff898364) //120
   DEF(task_MovieRecord                       ,0xff96193c) //120
   DEF(task_PhySw                             ,0xff833208) //120
   DEF(task_RotaryEncoder                     ,0xff85e508) //120
NHSTUB(time                                   ,0xff886c64) //109
NHSTUB(vsprintf                               ,0xff820350) //115
NHSTUB(EngDrvRead                             ,0xff834478) //102
NHSTUB(PTM_GetCurrentItem                     ,0xff895148) //105
NHSTUB(DisableISDriveError                    ,0xffa9bbd4) //120
NHSTUB(CancelHPTimer                          ,0xff888460) //119
NHSTUB(SetHPTimerAfterNow                     ,0xff888358) //119
NHSTUB(PT_MFOn                                ,0xff8777bc) //120
NHSTUB(PT_MFOff                               ,0xff8777cc) //120
NHSTUB(GetAdChValue                           ,0xff859ea8) //120
NHSTUB(get_ptp_buf_size                       ,0xff8ffb20) //122
NHSTUB(get_ptp_file_buf                       ,0xffa48bb8) //121
NHSTUB(SetVideoOutType                        ,0xffafeec8) //109
NHSTUB(GetVideoOutType                        ,0xffafedfc) //120
