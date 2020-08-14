// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R23 (DRYOS version 2.3, release #0023)
//   Firmware Ver GM1.00D   // Found @ 0xff86c370, "GM1.00D" @ 0xff86c37d
//   Firmware build timestamp: Jan 24 2008 18:26:41
//   Canon DIGITAL IXUS 90 IS

// Values for makefile.inc
//   DIGIC = 30# DIGIC III
//   PLATFORMOSVER = 23
//   PLATFORMID = 12660# (0x3174) Found @ 0xfffe0130
//   MAXRAMADDR = 0x03ffffff
//   MEMISOSTART = 0x000cbc48
//   KEYSYS = d3enc# Found @ 0xffff33e0
//   NEED_ENCODED_DISKBOOT = 1# Found @ 0xffff33c0
//   ARAM_HEAP_START = 0x2ce000# Found @ 0xffa2d9c4
//   ARAM_HEAP_SIZE  = 0x32000# Found @ 0xffa2d984

// Detected address ranges:
// ROM      0xff810000 - 0xffffffff (8323072 bytes)
// RAM data 0x00001900 - 0x0000f134 copied from 0xffb1cddc (  55348 bytes)

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NHSTUB(PutInNdFilter                        ,0xffa299b0) //102        *** != 0xffa82744
//NHSTUB(PutOutNdFilter                       ,0xffa299d4) //102        *** != 0xffa8277c

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ffa3dc58 -> ffaf7e70
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00010610) // Found @0xff821e48
DEF(physw_run                               ,0x00001c00) // Found @0xff821ae0
DEF(physw_sleep_delay                       ,0x00001bfe) // Found @0xff821ae0
DEF(levent_table                            ,0xffad2ce4) // Found @0xffad2ce4
DEF(FlashParamsTable                        ,0xffaf8034) // Found @0xffaf8034
DEF(movie_status                            ,0x000053cc) // Found @0xff859fec
DEF(canon_menu_active                       ,0x000099e8) // Found @0xff94fe8c
DEF(canon_shoot_menu_active                 ,0x00009fcd) // Found @0xff96c438
DEF(playrec_mode                            ,0x0000555c) // Found @0xff8613c4
DEF(zoom_status                             ,0x0000d474) // Found @0xffa3f458
DEF(some_flag_for_af_scan                   ,0x0000d1f8) // Found @0xffa2a328
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 3 int value(s), the first is the zoom focus length.
// there are 7 entries in the table - set NUM_FL to 7
DEF(focus_len_table                         ,0xfffe297c) // Found @0xfffe297c
DEF(zoom_busy                               ,0x00008a88) // Found @0xff932810
DEF(focus_busy                              ,0x00008994) // Found @0xff92e3bc
//DEF(recreview_hold                          ,0x000061a4) // Found @0xff87ee14, ** != ** stubs_min = 0x00009da4 (0x9CF8+0xAC)
// Camera has 2 RAW buffers @ 0x107d68c0 & 0x11b97b60
//  Note: active buffer --> raw_buffers[ active_raw_buffer   *3]
//        other buffer  --> raw_buffers[(active_raw_buffer^1)*3]
DEF(raw_buffers                             ,0xffab0cb4) // Found @0xffab0cb4
DEF(active_raw_buffer                       ,0x0000550c) // Found @0xff85e86c
DEF(fileio_semaphore                        ,0x00002a0c) // Found @0xff850f2c
DEF(exmem_alloc_table                       ,0x0001a2ac) // Found @0xff867580
DEF(exmem_types_table                       ,0xffb20b10) // Found @0x00005634
DEF_CONST(exmem_type_count                  ,0x00000012)
DEF(imager_active                           ,0x00001ef4) // Found @0xff8362f8 (0x1ef0 + 4)
DEF_CONST(uiprop_count                      ,0x00000064) // Found @0xff95cc24

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x10361000; }             // Found @0xff83e9ac
//void *vid_get_viewport_fb()      { return (void*)0x1065adc0; }             // Found @0xffa8797c
DEF(viewport_fb_d                           ,0x0000524c) // Found 0x51fc (@0xff8532b8) + 0x50 (@0xff8532f0)
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x51fc+0x50)); } // Found @0xff8532b8 & 0xff8532f0
DEF(jpeg_count_str                          ,0x0004c97c) // Found @0xff9a66f4
//char *camera_jpeg_count_str()    { return (char*)0x0004c97c; }             // Found @0xff9a66f4
//int get_flash_params_count(void) { return 0x73; }                          // Found @0xff95d668

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffab0780, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x00040000 // Found @0xffab078c, levent 0x902
//#define USB_IDX             2
//#define BATTCOVER_FLAG      0x00008000 // Found @0xffab0768, levent 0x905
//#define BATTCOVER_IDX       2
//#define ANALOG_AV_FLAG      0x00200000 // Found @0xffab0660, levent 0x900 (non-inverted logic)
//#define ANALOG_AV_IDX       0

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 1, KEY_POWER           ,0x40000000 }, // Found @0xffab06c0, levent 0x600
//    { 1, KEY_PLAYBACK        ,0x80000000 }, // Found @0xffab06cc, levent 0x601
//    { 2, KEY_SHOOT_FULL      ,0x00000003 }, // Found @0xffab06e4, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000002 }, // Found @0xffab06e4, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00000001 }, // Found @0xffab06d8, levent 0x00
//    { 2, KEY_ZOOM_IN         ,0x00000004 }, // Found @0xffab06f0, levent 0x02
//    { 2, KEY_ZOOM_OUT        ,0x00000008 }, // Found @0xffab06fc, levent 0x03
//    { 2, KEY_LEFT            ,0x00000010 }, // Found @0xffab0708, levent 0x06
//    { 2, KEY_RIGHT           ,0x00000020 }, // Found @0xffab0714, levent 0x07
//    { 2, KEY_DOWN            ,0x00000040 }, // Found @0xffab0720, levent 0x05
//    { 2, KEY_UP              ,0x00000080 }, // Found @0xffab072c, levent 0x04
//    { 2, KEY_SET             ,0x00000100 }, // Found @0xffab0738, levent 0x08
//    { 2, KEY_DISPLAY         ,0x00000200 }, // Found @0xffab0744, levent 0x0a
//    { 2, KEY_MENU            ,0x00000400 }, // Found @0xffab0750, levent 0x09
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_RAW_ROWPIX    3720 // Found @0xffa812ac
//#define CAM_RAW_ROWS      2772 // Found @0xffa812b4
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x10000000 // Found @0xff8285b8
//#define PARAM_CAMERA_NAME 4 // Found @0xffafa144

// Below goes in 'filewrite.c' or 'platform_camera.h':
//#define MAX_CHUNKS_FOR_JPEG 3 // Found @0xffa0f094

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
DEF(ctypes, 0xffab025a)

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
// pointer to TCB area: 0x19f4, found @ 0xff815e1c

// LED table init @ 0xff8ec010
// LED #1: 0xc02200d4, offset 0x204
// LED #2: 0xc0220134, offset 0x4
// LED #3: 0xc0220130, offset 0x44

// For capt_seq.c
DEF(_nrflag,0x91ac) // Found @ ff93d88c (0x91ac)
//static long *nrflag = (long*)(0x91ac);       // Found @ ff93d88c

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NHSTUB(AllocateUncacheableMemory              ,0xff82857c) //112
NHSTUB(Close                                  ,0xff823da0) //120
NHSTUB(CreateBinarySemaphore                  ,0xff81b540) //115
NHSTUB(CreateTask                             ,0xff81b818) //120
NHSTUB(DebugAssert                            ,0xff81bcf0) //107
NHSTUB(DeleteDirectory_Fut                    ,0xff823730) //116
NHSTUB(DeleteFile_Fut                         ,0xff82364c) //112
NHSTUB(DoAELock                               ,0xff825f88) //120
NHSTUB(DoAFLock                               ,0xff825b98) //120
NHSTUB(EnterToCompensationEVF                 ,0xff825e94) //104
NHSTUB(ExecuteEventProcedure                  ,0xff86965c) //104
NHSTUB(ExitFromCompensationEVF                ,0xff825ee4) //104
NHSTUB(ExitTask                               ,0xff81baa8) //120
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff832b14) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff832c58) //104
NHSTUB(Fclose_Fut                             ,0xff8237c8) //120
NHSTUB(Feof_Fut                               ,0xff8239b4) //  1
NHSTUB(Fflush_Fut                             ,0xff8239f0) //  1
NHSTUB(Fgets_Fut                              ,0xff82391c) //  1
NHSTUB(Fopen_Fut                              ,0xff823788) //120
NHSTUB(Fread_Fut                              ,0xff823874) //120
NHSTUB(FreeUncacheableMemory                  ,0xff8285b0) //112
NHSTUB(Fseek_Fut                              ,0xff823968) //120
NHSTUB(Fwrite_Fut                             ,0xff8238c8) //120
NHSTUB(GetBatteryTemperature                  ,0xff8455e0) //102
NHSTUB(GetCCDTemperature                      ,0xff845570) //102
NHSTUB(GetCurrentAvValue                      ,0xff92fdd0) //120
NHSTUB(GetCurrentShutterSpeed                 ,0xff895938) //120
NHSTUB(GetDrive_ClusterSize                   ,0xff84f500) //  1
NHSTUB(GetDrive_FreeClusters                  ,0xff84f568) //  1
NHSTUB(GetDrive_TotalClusters                 ,0xff84f534) //  1
NHSTUB(GetFocusLensSubjectDistance            ,0xff92eec8) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff92f1d4) //  1
NHSTUB(GetKbdState                            ,0xff842b28) //109
NHSTUB(GetMemInfo                             ,0xff813c40) //115
NHSTUB(GetOpticalTemperature                  ,0xff845650) //120
NHSTUB(GetParameterData                       ,0xff95d628) //101
NHSTUB(GetPropertyCase                        ,0xff86d25c) //102
NHSTUB(GetSystemTime                          ,0xffa2d218) //120
NHSTUB(GetVRAMHPixelsSize                     ,0xff8c8aec) //120
NHSTUB(GetVRAMVPixelsSize                     ,0xff8c8af8) //120
NHSTUB(GetZoomLensCurrentPoint                ,0xff932b74) //120
NHSTUB(GetZoomLensCurrentPosition             ,0xffa23268) //102
NHSTUB(GiveSemaphore                          ,0xff81b77c) //120
NHSTUB(IsStrobeChargeCompleted                ,0xff8bdc20) //102
NHSTUB(LEDDrive                               ,0xff8422b8) //120
NHSTUB(LocalTime                              ,0xff866d20) //115
NHSTUB(LockMainPower                          ,0xff875708) //120
NHSTUB(MakeDirectory_Fut                      ,0xff8236c0) //116
NHSTUB(MoveFocusLensToDistance                ,0xffa844b8) //102
NHSTUB(MoveIrisWithAv                         ,0xffa295c8) //120
NHSTUB(MoveZoomLensWithPoint                  ,0xffa29b4c) //120
NHSTUB(MoveOpticalZoomAt                      ,0xff825410) //109
NHSTUB(Open                                   ,0xff823d78) //120
NHSTUB(PB2Rec                                 ,0xff87871c) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff85be58) //120
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff85be30) //120
NHSTUB(PT_PlaySound                           ,0xff85b4b4) //102
NHSTUB(PostLogicalEventForNotPowerType        ,0xff8734c8) //120
NHSTUB(PostLogicalEventToUI                   ,0xff873514) //120
NHSTUB(Read                                   ,0xff81a094) //120
NHSTUB(ReadFastDir                            ,0xffa122e8) //  1
NHSTUB(Rec2PB                                 ,0xff877120) //104
NHSTUB(RefreshPhysicalScreen                  ,0xff9b0484) //104
NHSTUB(RenameFile_Fut                         ,0xff8235f8) //  1
NHSTUB(Restart                                ,0xff829df4) //122
NHSTUB(SetAE_ShutterSpeed                     ,0xffa86b8c) //102
NHSTUB(SetAutoShutdownTime                    ,0xff87577c) //120
NHSTUB(SetCurrentCaptureModeType              ,0xff87c5b8) //120
NHSTUB(SetFileAttributes                      ,0xff8240cc) //  1
NHSTUB(SetFileTimeStamp                       ,0xff82407c) //  1
NHSTUB(SetLogicalEventActive                  ,0xff8753e8) //  1
NHSTUB(SetParameterData                       ,0xff95d598) //101
NHSTUB(SetPropertyCase                        ,0xff86d15c) //102
NHSTUB(SetScriptMode                          ,0xff875438) //120
NHSTUB(SleepTask                              ,0xff828400) //120
NHSTUB(TakeSemaphore                          ,0xff81b6ac) //120
NHSTUB(TurnOffBackLight                       ,0xff881e30) //104
NHSTUB(TurnOnBackLight                        ,0xff881e18) //104
NHSTUB(TurnOnDisplay                          ,0xff83ea5c) //120
NHSTUB(TurnOffDisplay                         ,0xff83ea6c) //120
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff950de8) //120
NHSTUB(UnlockAE                               ,0xff825fb8) //120
NHSTUB(UnlockAF                               ,0xff825bdc) //120
NHSTUB(UnlockMainPower                        ,0xff87565c) //120
NHSTUB(UnsetZoomForMovie                      ,0xff962c8c) //104
NHSTUB(UpdateMBROnFlash                       ,0xff84f340) //105
NHSTUB(VbattGet                               ,0xff82072c) //120
NHSTUB(Write                                  ,0xff823e4c) //120
NHSTUB(WriteSDCard                            ,0xff922a68) //108
NHSTUB(_log                                   ,0xffaadd14) //111
NHSTUB(_log10                                 ,0xffaacc58) //112
NHSTUB(_pow                                   ,0xffaacdc8) //121
NHSTUB(_sqrt                                  ,0xffaaf134) //  1
NHSTUB(add_ptp_handler                        ,0xff9e0924) //121
NHSTUB(apex2us                                ,0xff9b19c0) //121
NHSTUB(close                                  ,0xff819eac) //109
NHSTUB(err_init_task                          ,0xff814e98) //111
NHSTUB(exmem_alloc                            ,0xff867e44) //103
NHSTUB(exmem_ualloc                           ,0xff867c94) //103
NHSTUB(exmem_ufree                            ,0xff867dd4) //103
NHSTUB(free                                   ,0xff813a98) //112
NHSTUB(get_nd_value                           ,0xffa20c44) //123
NHSTUB(get_current_nd_value                   ,0xffa20c00) //122
NHSTUB(kbd_p1_f                               ,0xff821f4c) //109
NHSTUB(kbd_p1_f_cont                          ,0xff821f58) //109
NHSTUB(kbd_p2_f                               ,0xff821780) //109
NHSTUB(kbd_read_keys                          ,0xff821e48) //109
NHSTUB(kbd_read_keys_r2                       ,0xff8426e0) //109
NHSTUB(kbd_pwr_off                            ,0xff842bac) //  2
NHSTUB(kbd_pwr_on                             ,0xff842b5c) //  2
NHSTUB(lseek                                  ,0xff823ee0) //120
NHSTUB(malloc                                 ,0xff8139c4) //112
NHSTUB(memcmp                                 ,0xff81d854) //120
NHSTUB(memcpy                                 ,0xff894584) //120
NHSTUB(memset                                 ,0xff9b0838) //120
NHSTUB(mkdir                                  ,0xff824144) //109
NHSTUB(mktime_ext                             ,0xff894df0) //  1
NHSTUB(open                                   ,0xff819dfc) //109
NHSTUB(OpenFastDir                            ,0xffa12254) //  1
NHSTUB(closedir                               ,0xffa123b8) //  1
NHSTUB(qsort                                  ,0xff9b0d40) //  1
NHSTUB(rand                                   ,0xff81d95c) //121
NHSTUB(realloc                                ,0xff813b78) //115
NHSTUB(reboot_fw_update                       ,0xffa19ce8) //106
NHSTUB(set_control_event                      ,0xff875064) //  1
NHSTUB(srand                                  ,0xff81d950) //122
NHSTUB(stat                                   ,0xff823fac) //  1
NHSTUB(strcat                                 ,0xff894370) //  1
NHSTUB(strchr                                 ,0xff8943f8) //  1
NHSTUB(strcmp                                 ,0xff81d7ec) //120
NHSTUB(strcpy                                 ,0xff81d7d4) //120
NHSTUB(strftime                               ,0xff8947f8) //  1
NHSTUB(strlen                                 ,0xff81d830) //120
NHSTUB(strncmp                                ,0xff8943ac) //  1
NHSTUB(strncpy                                ,0xff82e210) //  1
NHSTUB(strrchr                                ,0xff89441c) //  1
NHSTUB(strtol                                 ,0xff82e448) //101
NHSTUB(strtolx                                ,0xff82e24c) //109
   DEF(task_CaptSeq                           ,0xff85e2b0) //120
   DEF(task_DvlpSeqTask                       ,0xff93e424) //120
   DEF(task_ExpDrv                            ,0xff8b6a80) //120
   DEF(task_FileWrite                         ,0xffa0f030) //120
   DEF(task_InitFileModules                   ,0xff8791d0) //120
   DEF(task_MovieRecord                       ,0xff85a278) //120
   DEF(task_PhySw                             ,0xff821adc) //120
   DEF(task_RotaryEncoder                     ,0xff842c84) //120
NHSTUB(time                                   ,0xff867224) //109
NHSTUB(vsprintf                               ,0xff81d754) //115
NHSTUB(EngDrvRead                             ,0xff822d8c) //102
NHSTUB(PTM_GetCurrentItem                     ,0xff87603c) //105
NHSTUB(CancelHPTimer                          ,0xff868b98) //119
NHSTUB(SetHPTimerAfterNow                     ,0xff868a90) //119
NHSTUB(PT_MFOn                                ,0xff85bed0) //120
NHSTUB(PT_MFOff                               ,0xff85bee0) //120
NHSTUB(GetAdChValue                           ,0xff8405dc) //120
NHSTUB(get_ptp_buf_size                       ,0xff8cb4e0) //122
NHSTUB(get_ptp_file_buf                       ,0xff9e2254) //121
NHSTUB(SetVideoOutType                        ,0xffa87378) //109
NHSTUB(GetVideoOutType                        ,0xffa872dc) //120
