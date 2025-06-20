// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R23 (DRYOS version 2.3, release #0023)
//   Firmware Ver GM1.00I   // Found @ 0xff86e880, "GM1.00I" @ 0xff86e88d
//   Firmware build timestamp: Jun 26 2008 07:11:54
//   Possible corrupt firmware dump - file size too small for start address 0xff810000
//     file size = 3.19MB, should be 7.94MB
//   Could not find Camera name - possible corrupt firmware dump

// Values for makefile.inc
//   DIGIC = 30# DIGIC III
//   PLATFORMOSVER = 23
//   PLATFORMID = ?           // Not found @ 0xfffe0130
//   MAXRAMADDR = 0x03ffffff
//   MEMISOSTART = 0x000b0b68

// Detected address ranges:
// ROM      0xff810000 - 0xffffffff (8323072 bytes)
// RAM data 0x00001900 - 0x000140e4 copied from 0xffb2e41c (  75748 bytes)

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NHSTUB(PutInNdFilter                        ,0xff9384e4) //102        *** != 0xffa0c578
//NHSTUB(PutOutNdFilter                       ,0xff938508) //102        *** != 0xffa0c5b0
//NHSTUB(kbd_pwr_off                          ,0xff84944c) //  2 67%    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ffa4c760 -> ffb08114
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x0001563c) // Found @0xff8230cc
DEF(physw_run                               ,0x00001ca4) // Found @0xff822d78
DEF(physw_sleep_delay                       ,0x00001ca2) // Found @0xff822d78
DEF(levent_table                            ,0xffae01d4) // Found @0xffae01d4
//DEF(FlashParamsTable                        ,0xffb082e0) // Found @0xffb082e0, ** != ** stubs_min = 0xffb082b8 (0xFFB082B8)
DEF(movie_status                            ,0x00005714) // Found @0xff85d220
DEF(canon_menu_active                       ,0x0000fdc8) // Found @0xff99b56c
DEF(canon_shoot_menu_active                 ,0x0000f33d) // Found @0xff96ac40
DEF(playrec_mode                            ,0x000058cc) // Found @0xff864a60
DEF(zoom_status                             ,0x0001264c) // Found @0xffa4e424
DEF(some_flag_for_af_scan                   ,0x0001253c) // Found @0xffa447c8
DEF(zoom_busy                               ,0x0000e260) // Found @0xff939f38
DEF(focus_busy                              ,0x0000e150) // Found @0xff934128
//DEF(recreview_hold                          ,0x00006400) // Found @0xff87cb64, ** != ** stubs_min = 0x0000f050 (0xF050)
// Camera has 2 RAW buffers @ 0x108297c0 & 0x11f8f740
//  Note: active buffer --> raw_buffers[ active_raw_buffer   *3]
//        other buffer  --> raw_buffers[(active_raw_buffer^1)*3]
DEF(raw_buffers                             ,0xffac6740) // Found @0xffac6740
DEF(active_raw_buffer                       ,0x0000586c) // Found @0xff861840
DEF(fileio_semaphore                        ,0x00002d68) // Found @0xff853fa8
DEF(exmem_alloc_table                       ,0x0001e85c) // Found @0xff86bd98
DEF(exmem_types_table                       ,0xffb324d0) // Found @0x000059b4
DEF_CONST(exmem_type_count                  ,0x00000012)
DEF(imager_active                           ,0x00002018) // Found @0xff838a28 (0x2014 + 4)
DEF_CONST(uiprop_count                      ,0x00000063) // Found @0xff955d54

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x10361000; }             // Found @0xff8451d0
//void *vid_get_viewport_fb()      { return (void*)0x1067b540; }             // Found @0xffa11304
DEF(viewport_fb_d                           ,0x000055a8) // Found 0x5558 (@0xff856268) + 0x50 (@0xff8562a0)
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x5558+0x50)); } // Found @0xff856268 & 0xff8562a0
DEF(jpeg_count_str                          ,0x00060354) // Found @0xff9afb7c
//char *camera_jpeg_count_str()    { return (char*)0x00060354; }             // Found @0xff9afb7c
//int get_flash_params_count(void) { return 0x72; }                          // Found @0xff9569a8

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffac6378, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x00040000 // Found @0xffac6380, levent 0x902
//#define USB_IDX             2
//#define BATTCOVER_FLAG      0x00008000 // Found @0xffac6280, levent 0x905
//#define BATTCOVER_IDX       0
//#define HOTSHOE_FLAG        0x00040000 // Found @0xffac6298, levent 0x904
//#define HOTSHOE_IDX         0
//#define ANALOG_AV_FLAG      0x02000000 // Found @0xffac62a0, levent 0x900 (non-inverted logic)
//#define ANALOG_AV_IDX       0

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_POWER           ,0x00010000 }, // Found @0xffac6288, levent 0x600 (uses inverted logic in physw_status)
//    { 0, KEY_PLAYBACK        ,0x00020000 }, // Found @0xffac6290, levent 0x601 (uses inverted logic in physw_status)
//    { 0, KEY_SHOOT_FULL      ,0xc0000000 }, // Found @0xffac62b0, levent 0x01
//    { 0, KEY_SHOOT_FULL_ONLY ,0x80000000 }, // Found @0xffac62b0, levent 0x01
//    { 0, KEY_SHOOT_HALF      ,0x40000000 }, // Found @0xffac62a8, levent 0x00
//    { 1, KEY_ZOOM_OUT        ,0x00000008 }, // Found @0xffac62d0, levent 0x03
//    { 1, KEY_ZOOM_IN         ,0x00000010 }, // Found @0xffac62d8, levent 0x02
//    { 1, KEY_LEFT            ,0x00010000 }, // Found @0xffac6308, levent 0x06
//    { 1, KEY_SET             ,0x00020000 }, // Found @0xffac6310, levent 0x08
//    { 1, KEY_RIGHT           ,0x00040000 }, // Found @0xffac6318, levent 0x07
//    { 1, KEY_DOWN            ,0x00080000 }, // Found @0xffac6320, levent 0x05
//    { 1, KEY_UP              ,0x00100000 }, // Found @0xffac6328, levent 0x04
//    { 1, KEY_DISPLAY         ,0x04000000 }, // Found @0xffac6340, levent 0x0a
//    { 1, KEY_MENU            ,0x08000000 }, // Found @0xffac6348, levent 0x09
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_RAW_ROWPIX    4104 // Found @0xffa0b290
//#define CAM_RAW_ROWS      3048 // Found @0xffa0b298
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x10000000 // Found @0xff82a7c4
//#define PARAM_CAMERA_NAME 4 // Found @0xffb0a814

// Below goes in 'filewrite.c' or 'platform_camera.h':
//#define MAX_CHUNKS_FOR_FWT 3 // Found @0xffa2ad1c

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
DEF(ctypes, 0xffac0b6a)

// EXMEM types:
// EXMEM_RAMDISK     0
// EXMEM_COM         1
// EXMEM_COMTMP      2
// EXMEM_FORMATTER   3
// EXMEM_SHADING     4
// EXMEM_FAMODE      5
// EXMEM_FIRMUP      6
// EXMEM_FIRMUP_VRAM 7
// EXMEM_DVLPWORK    8
// EXMEM_EVF         9
// EXMEM_SCRIPT      10
// EXMEM_FILESTORE   11
// EXMEM_MOVIE_REC   12
// EXMEM_MOVIE_PLY   13
// EXMEM_WIDE        14
// EXMEM_NARROW      15
// EXMEM_CRAW_REC    16
// EXMEM_PCEVF       17

// ISR flag: 0x195c, pointer to current task's control block: 0x1958
// pointer to TCB area: 0x1a14, found @ 0xff816100

// LED table init @ 0xff8f70c8
// LED #1: 0xc0220094, offset 0x244
// LED #2: 0xc02200b0, offset 0x384
// LED #3: 0xc022006c, offset 0x204
// LED #4: 0xc0220138, offset 0x84
// LED #5: 0xc0220068, offset 0xc4
// LED #6: 0xc0220134, offset 0x4
// LED #7: 0xc0220130, offset 0x44

// For capt_seq.c
DEF(_nrflag,0xe618) // Found @ ff9444f0 (0xe618)
//static long *nrflag = (long*)(0xe618);       // Found @ ff9444f0

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NHSTUB(AllocateUncacheableMemory              ,0xff82a788) //112
NHSTUB(Close                                  ,0xff82552c) //120
NHSTUB(CreateBinarySemaphore                  ,0xff81b820) //115
NHSTUB(CreateTask                             ,0xff81baf0) //120
NHSTUB(DebugAssert                            ,0xff81bfc8) //107
NHSTUB(DeleteDirectory_Fut                    ,0xff824e78) //116
NHSTUB(DeleteFile_Fut                         ,0xff824d94) //112
NHSTUB(DoAELock                               ,0xff827aa8) //120
NHSTUB(DoAFLock                               ,0xff8275cc) //120
NHSTUB(EnterToCompensationEVF                 ,0xff8279a8) //104
NHSTUB(ExecuteEventProcedure                  ,0xff81c1a8) //104
NHSTUB(ExitFromCompensationEVF                ,0xff8279f8) //104
NHSTUB(ExitTask                               ,0xff81bd80) //120
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff835600) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff8357c0) //104
NHSTUB(Fclose_Fut                             ,0xff824f10) //120
NHSTUB(Feof_Fut                               ,0xff8250fc) //  1
NHSTUB(Fflush_Fut                             ,0xff825138) //  1
NHSTUB(Fgets_Fut                              ,0xff825064) //  1
NHSTUB(Fopen_Fut                              ,0xff824ed0) //120
NHSTUB(Fread_Fut                              ,0xff824fbc) //120
NHSTUB(FreeUncacheableMemory                  ,0xff82a7bc) //112
NHSTUB(Fseek_Fut                              ,0xff8250b0) //120
NHSTUB(Fwrite_Fut                             ,0xff825010) //120
NHSTUB(GetBatteryTemperature                  ,0xff84bee8) //102
NHSTUB(GetCCDTemperature                      ,0xff84be78) //102
NHSTUB(GetCurrentAvValue                      ,0xff936dd4) //120
NHSTUB(GetCurrentShutterSpeed                 ,0xff8971f8) //120
NHSTUB(GetUsableMaxAv                         ,0xffa0c4f8) //120
NHSTUB(GetUsableMinAv                         ,0xffa0c4e0) //120
NHSTUB(GetDrive_ClusterSize                   ,0xff852754) //  1
NHSTUB(GetDrive_FreeClusters                  ,0xff8527f4) //  1
NHSTUB(GetDrive_TotalClusters                 ,0xff852788) //  1
NHSTUB(GetFocusLensSubjectDistance            ,0xff934c68) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff934f74) //  1
NHSTUB(GetKbdState                            ,0xff849300) //109
NHSTUB(GetMemInfo                             ,0xff813c58) //115
NHSTUB(GetOpticalTemperature                  ,0xff84bf58) //120
NHSTUB(GetParameterData                       ,0xff956968) //  1
NHSTUB(GetPropertyCase                        ,0xff86f768) //101
NHSTUB(GetSystemTime                          ,0xffa47df8) //120
NHSTUB(GetVRAMHPixelsSize                     ,0xff83dedc) //120
NHSTUB(GetVRAMVPixelsSize                     ,0xff83dee8) //120
NHSTUB(GetZoomLensCurrentPoint                ,0xff93a29c) //120
NHSTUB(GetZoomLensCurrentPosition             ,0xffa3e680) //102
NHSTUB(GiveSemaphore                          ,0xff81ba5c) //120
NHSTUB(IsStrobeChargeCompleted                ,0xff8c1344) //102
NHSTUB(LEDDrive                               ,0xff848890) //120
NHSTUB(LocalTime                              ,0xff86b538) //115
NHSTUB(LockMainPower                          ,0xff8731f0) //120
NHSTUB(MakeDirectory_Fut                      ,0xff824e08) //116
NHSTUB(MoveFocusLensToDistance                ,0xffa0e15c) //102
NHSTUB(MoveIrisWithAv                         ,0xff9371b4) //120
NHSTUB(MoveZoomLensWithPoint                  ,0xff93ad48) //120
NHSTUB(MoveOpticalZoomAt                      ,0xff826ad4) //109
NHSTUB(Open                                   ,0xff825504) //120
NHSTUB(PB2Rec                                 ,0xff876664) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff8668e0) //120
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff8668a8) //120
NHSTUB(PT_PlaySound                           ,0xff866454) //103
NHSTUB(PostLogicalEventForNotPowerType        ,0xff87118c) //120
NHSTUB(PostLogicalEventToUI                   ,0xff8711d8) //120
NHSTUB(Read                                   ,0xff81a378) //120
NHSTUB(ReadFastDir                            ,0xffa2cbd4) //  1
NHSTUB(Rec2PB                                 ,0xff875024) //104
NHSTUB(RefreshPhysicalScreen                  ,0xff9bdc0c) //104
NHSTUB(RenameFile_Fut                         ,0xff824d40) //  1
NHSTUB(Restart                                ,0xff82c7e4) //122
NHSTUB(SetAE_ShutterSpeed                     ,0xffa104b8) //102
NHSTUB(SetAutoShutdownTime                    ,0xff873264) //120
NHSTUB(SetCurrentCaptureModeType              ,0xff879f7c) //120
NHSTUB(SetDate                                ,0xffa11f4c) //120
NHSTUB(SetFileAttributes                      ,0xff825858) //  1
NHSTUB(SetFileTimeStamp                       ,0xff825808) //  1
NHSTUB(SetLogicalEventActive                  ,0xff872f28) //  1
NHSTUB(SetParameterData                       ,0xff956844) //101
NHSTUB(SetPropertyCase                        ,0xff86f660) //103
NHSTUB(SetScriptMode                          ,0xff872f78) //120
NHSTUB(SleepTask                              ,0xff82a610) //120
NHSTUB(TakeSemaphore                          ,0xff81b98c) //120
NHSTUB(TurnOffBackLight                       ,0xff87ff88) //104
NHSTUB(TurnOnBackLight                        ,0xff87ff70) //104
NHSTUB(TurnOnDisplay                          ,0xff845280) //120
NHSTUB(TurnOffDisplay                         ,0xff845290) //120
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff99c3b8) //120
NHSTUB(UnlockAE                               ,0xff827ae4) //120
NHSTUB(UnlockAF                               ,0xff827638) //120
NHSTUB(UnlockMainPower                        ,0xff873144) //120
NHSTUB(UnsetZoomForMovie                      ,0xff95d048) //104
NHSTUB(UpdateMBROnFlash                       ,0xff85251c) //105
NHSTUB(VbattGet                               ,0xff82199c) //120
NHSTUB(Write                                  ,0xff8255d8) //120
NHSTUB(WriteSDCard                            ,0xff928d00) //108
NHSTUB(_log                                   ,0xffabe6dc) //111
NHSTUB(_log10                                 ,0xffabd620) //112
NHSTUB(_pow                                   ,0xffabd790) //121
NHSTUB(_sqrt                                  ,0xffabfa44) //  1
NHSTUB(add_ptp_handler                        ,0xff8d897c) //121
NHSTUB(apex2us                                ,0xff9bf0c4) //121
NHSTUB(close                                  ,0xff81a190) //109
NHSTUB(err_init_task                          ,0xff814eb0) //111
NHSTUB(exmem_alloc                            ,0xff86c680) //102
NHSTUB(exmem_ualloc                           ,0xff86c4d0) //102
NHSTUB(exmem_ufree                            ,0xff86c610) //102
NHSTUB(free                                   ,0xff813ab0) //112
NHSTUB(get_nd_value                           ,0xffa3bea0) //122
NHSTUB(get_current_nd_value                   ,0xffa3be68) //122
NHSTUB(kbd_p1_f                               ,0xff8231c8) //109
NHSTUB(kbd_p1_f_cont                          ,0xff8231d4) //109
NHSTUB(kbd_p2_f                               ,0xff822a18) //109
NHSTUB(kbd_read_keys                          ,0xff8230cc) //109
NHSTUB(kbd_read_keys_r2                       ,0xff848dc8) //109
NHSTUB(lseek                                  ,0xff82566c) //120
NHSTUB(malloc                                 ,0xff8139dc) //112
NHSTUB(memcmp                                 ,0xff81e834) //120
NHSTUB(memcpy                                 ,0xff895cf0) //120
NHSTUB(memset                                 ,0xffa8d42c) //120
NHSTUB(mkdir                                  ,0xff8258d0) //109
NHSTUB(mktime_ext                             ,0xff89655c) //  1
NHSTUB(open                                   ,0xff81a0e0) //109
NHSTUB(OpenFastDir                            ,0xffa2cb40) //  1
NHSTUB(closedir                               ,0xffa2cca4) //  1
NHSTUB(qsort                                  ,0xff9be49c) //  1
NHSTUB(rand                                   ,0xff81e93c) //121
NHSTUB(realloc                                ,0xff813b90) //115
NHSTUB(reboot_fw_update                       ,0xffa34598) //106
NHSTUB(set_control_event                      ,0xff872c2c) //  1
NHSTUB(srand                                  ,0xff81e930) //122
NHSTUB(stat                                   ,0xff825738) //  1
NHSTUB(strcat                                 ,0xff895c1c) //  1
NHSTUB(strchr                                 ,0xff895ca4) //  1
NHSTUB(strcmp                                 ,0xff81e7cc) //120
NHSTUB(strcpy                                 ,0xff81e778) //120
NHSTUB(strftime                               ,0xff895f64) //  1
NHSTUB(strlen                                 ,0xff81e810) //120
NHSTUB(strncmp                                ,0xff895c58) //  1
NHSTUB(strncpy                                ,0xff81e790) //  1
NHSTUB(strrchr                                ,0xff895cc8) //  1
NHSTUB(strtol                                 ,0xff830d90) //101
NHSTUB(strtolx                                ,0xff830b94) //109
   DEF(task_CaptSeq                           ,0xff861210) //120
   DEF(task_DvlpSeqTask                       ,0xff9450e0) //120
   DEF(task_ExpDrv                            ,0xff8b8b90) //120
   DEF(task_FileWrite                         ,0xffa2acb8) //120
   DEF(task_InitFileModules                   ,0xff877284) //120
   DEF(task_MovieRecord                       ,0xff85d4c0) //120
   DEF(task_PhySw                             ,0xff822d74) //120
   DEF(task_RotaryEncoder                     ,0xff849530) //120
NHSTUB(time                                   ,0xff86ba3c) //109
NHSTUB(vsprintf                               ,0xff81e6f8) //115
NHSTUB(EngDrvRead                             ,0xff823fcc) //102
NHSTUB(PTM_GetCurrentItem                     ,0xff873c9c) //105
NHSTUB(CancelHPTimer                          ,0xff86d3cc) //119
NHSTUB(SetHPTimerAfterNow                     ,0xff86d2c4) //119
NHSTUB(MFOn                                   ,0xff866fec) //120
NHSTUB(MFOff                                  ,0xff866ffc) //120
NHSTUB(PT_MFOn                                ,0xff866940) //120
NHSTUB(PT_MFOff                               ,0xff866950) //120
NHSTUB(GetAdChValue                           ,0xff84682c) //120
NHSTUB(get_ptp_buf_size                       ,0xff8d1fa8) //122
NHSTUB(get_ptp_file_buf                       ,0xff9f2618) //121
NHSTUB(SetVideoOutType                        ,0xffa10cb8) //109
NHSTUB(GetVideoOutType                        ,0xffa10c1c) //120
