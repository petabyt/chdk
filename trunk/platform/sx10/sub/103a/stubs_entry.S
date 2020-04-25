// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R31 (DRYOS version 2.3, release #0031)
//   Firmware Ver GM1.03A   // Found @ 0xff878868, "GM1.03A" @ 0xff878875
//   Firmware build timestamp: Apr 16 2009 09:16:03
//   Canon PowerShot SX10 IS

// Values for makefile.inc
//   DIGIC = 40# DIGIC 4
//   PLATFORMOSVER = 31
//   PLATFORMID = 12685# (0x318d) Found @ 0xfffe0130
//   MAXRAMADDR = 0x03ffffff
//   MEMISOSTART = 0x000acb74
//   KEYSYS = d4# Found @ 0xffff3570
//   NEED_ENCODED_DISKBOOT = 1# Found @ 0xffff3580
//   ARAM_HEAP_START = 0x30e000# Found @ 0xff956434
//   ARAM_HEAP_SIZE  = 0x32000# Found @ 0xff9563f4

// Detected address ranges:
// ROM      0xff810000 - 0xffffffff (8323072 bytes)
// RAM data 0x00001900 - 0x00010a58 copied from 0xffb9b3ec (  61784 bytes)

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NHSTUB(kbd_pwr_off                          ,0xff84b810) //  2 60%    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ffa79ac8 -> ffb744f8
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00011ec4) // Found @0xff821b14
DEF(physw_run                               ,0x00001c30) // Found @0xff821788
DEF(physw_sleep_delay                       ,0x00001c2e) // Found @0xff821788
DEF(levent_table                            ,0xffb4ae38) // Found @0xffb4ae38
DEF(FlashParamsTable                        ,0xffb746cc) // Found @0xffb746cc
DEF(movie_status                            ,0x00005430) // Found @0xff8643a8
DEF(video_compression_rate                  ,0x0000545c) // Found @0xff8645b4
DEF(canon_menu_active                       ,0x000058d8) // Found @0xff87a28c
DEF(canon_shoot_menu_active                 ,0x0000ac29) // Found @0xff98cbd8
DEF(playrec_mode                            ,0x00005640) // Found @0xff86d2b8
DEF(zoom_status                             ,0x0000e3ec) // Found @0xffa7b794
DEF(some_flag_for_af_scan                   ,0x00009b58) // Found @0xff94a35c
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 1 int value, which is the the zoom focus length.
// there are 6 entries in the table - set NUM_FL to 6
DEF(focus_len_table                         ,0xffb77e50) // Found @0xffb77e50
DEF(zoom_busy                               ,0x00009100) // Found @0xff940890
DEF(focus_busy                              ,0x00008f8c) // Found @0xff9398a4
//DEF(recreview_hold                          ,0x0000645c) // Found @0xff88b600, ** != ** stubs_min = 0x0000a868 (0xA78C+0xDC)
// Camera has 2 RAW buffers @ 0x40f65b18 & 0x424f1948
//  Note: active buffer --> raw_buffers[ active_raw_buffer   *3]
//        other buffer  --> raw_buffers[(active_raw_buffer^1)*3]
DEF(raw_buffers                             ,0xffb0b67c) // Found @0xffb0b67c
DEF(active_raw_buffer                       ,0x000055e4) // Found @0xff86a60c
DEF(fileio_semaphore                        ,0x00002a58) // Found @0xff8596b8
DEF(exmem_alloc_table                       ,0x0001c298) // Found @0xff873b70
DEF(exmem_types_table                       ,0xffb9f21c) // Found @0x00005730
DEF_CONST(exmem_type_count                  ,0x00000012)
DEF(imager_active                           ,0x00001fb4) // Found @0xff837768 (0x1fb0 + 4)
DEF_CONST(uiprop_count                      ,0x00000069) // Found @0xff9748c0

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x403b1000; }             // Found @0xff846c28
//void *vid_get_viewport_fb()      { return (void*)0x4070d9d0; }             // Found @0xffad16ec
DEF(viewport_fb_d                           ,0x000052b8) // Found 0x5260 (@0xff85c76c) + 0x58 (@0xff85c7a4)
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x5260+0x58)); } // Found @0xff85c76c & 0xff85c7a4
DEF(jpeg_count_str                          ,0x0004c138) // Found @0xff9d2900
//char *camera_jpeg_count_str()    { return (char*)0x0004c138; }             // Found @0xff9d2900
//int get_flash_params_count(void) { return 0x78; }                          // Found @0xff975514

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffb0aecc, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x00040000 // Found @0xffb0aed8, levent 0x902
//#define USB_IDX             2
//#define BATTCOVER_FLAG      0x00008000 // Found @0xffb0ad7c, levent 0x905
//#define BATTCOVER_IDX       0
//#define HOTSHOE_FLAG        0x10000000 // Found @0xffb0af08, levent 0x904
//#define HOTSHOE_IDX         2
//#define ANALOG_AV_FLAG      0x02000000 // Found @0xffb0ad88, levent 0x900 (non-inverted logic)
//#define ANALOG_AV_IDX       0

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_SHOOT_FULL      ,0x00000003 }, // Found @0xffb0ad58, levent 0x01
//    { 0, KEY_SHOOT_FULL_ONLY ,0x00000002 }, // Found @0xffb0ad58, levent 0x01
//    { 0, KEY_SHOOT_HALF      ,0x00000001 }, // Found @0xffb0ad4c, levent 0x00
//    { 0, KEY_POWER           ,0x00002000 }, // Found @0xffb0ad64, levent 0x600
//    { 0, KEY_PLAYBACK        ,0x00004000 }, // Found @0xffb0ad70, levent 0x601
//    { 1, KEY_VIDEO           ,0x00000020 }, // Found @0xffb0add0, levent 0x12
//    { 1, KEY_SET             ,0x00000100 }, // Found @0xffb0adf4, levent 0x08
//    { 1, KEY_DISPLAY         ,0x00000200 }, // Found @0xffb0ae00, levent 0x0a
//    { 1, KEY_UP              ,0x00000400 }, // Found @0xffb0ae0c, levent 0x04
//    { 1, KEY_DOWN            ,0x00000800 }, // Found @0xffb0ae18, levent 0x05
//    { 1, KEY_RIGHT           ,0x00001000 }, // Found @0xffb0ae24, levent 0x07
//    { 1, KEY_LEFT            ,0x00002000 }, // Found @0xffb0ae30, levent 0x06
//    { 1, KEY_MENU            ,0x00004000 }, // Found @0xffb0ae3c, levent 0x09
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_RAW_ROWPIX    3720 // Found @0xffaca2b0
//#define CAM_RAW_ROWS      2772 // Found @0xffaca2b8
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff828010
//#define PARAM_CAMERA_NAME 4 // Found @0xffb76ae4

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
DEF(ctypes, 0xffb047d6)

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

// ISR flag: 0x195c, pointer to current task's control block: 0x1958
// pointer to TCB area: 0x19e8, found @ 0xff815724

// LED table init @ 0xff8f4d34
// LED #1: 0xc02200b4, offset 0x244
// LED #2: 0xc02200b8, offset 0x144
// LED #3: 0xc0220060, offset 0x204
// LED #4: 0xc022005c, offset 0x1c4

// For capt_seq.c
DEF(_nrflag,0x9b40) // Found @ ff94ca50 (0x9b44) & ff94ca6c (-0x04)
//static long *nrflag = (long*)(0x9b44-0x04);  // Found @ ff94ca50 & ff94ca68

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NHSTUB(AllocateUncacheableMemory              ,0xff827fcc) //112
NHSTUB(Close                                  ,0xff823a64) //120
NHSTUB(CreateBinarySemaphore                  ,0xff8277ac) //115
NHSTUB(CreateTask                             ,0xff81aef4) //120
NHSTUB(DebugAssert                            ,0xff81b1cc) //107
NHSTUB(DeleteDirectory_Fut                    ,0xff8233f4) //116
NHSTUB(DeleteFile_Fut                         ,0xff823310) //112
NHSTUB(DoAELock                               ,0xff825bb4) //120
NHSTUB(DoAFLock                               ,0xff825864) //120
NHSTUB(EnterToCompensationEVF                 ,0xff825b10) //104
NHSTUB(ExecuteEventProcedure                  ,0xff875a90) //104
NHSTUB(ExitFromCompensationEVF                ,0xff825b54) //104
NHSTUB(ExitTask                               ,0xff81b184) //120
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff8311d8) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff83131c) //104
NHSTUB(Fclose_Fut                             ,0xff82348c) //120
NHSTUB(Feof_Fut                               ,0xff823678) //  1
NHSTUB(Fflush_Fut                             ,0xff8236b4) //  1
NHSTUB(Fgets_Fut                              ,0xff8235e0) //  1
NHSTUB(Fopen_Fut                              ,0xff82344c) //120
NHSTUB(Fread_Fut                              ,0xff823538) //120
NHSTUB(FreeUncacheableMemory                  ,0xff82800c) //112
NHSTUB(Fseek_Fut                              ,0xff82362c) //120
NHSTUB(Fwrite_Fut                             ,0xff82358c) //120
NHSTUB(GetBatteryTemperature                  ,0xff84e660) //102
NHSTUB(GetCCDTemperature                      ,0xff84e5f0) //102
NHSTUB(GetCurrentAvValue                      ,0xff93bf24) //120
NHSTUB(GetCurrentShutterSpeed                 ,0xff89cf98) //120
NHSTUB(GetUsableMaxAv                         ,0xffacb994) //120
NHSTUB(GetUsableMinAv                         ,0xffacb97c) //120
NHSTUB(GetDrive_ClusterSize                   ,0xff85ae98) //  1
NHSTUB(GetDrive_FreeClusters                  ,0xff85af00) //  1
NHSTUB(GetDrive_TotalClusters                 ,0xff85aecc) //  1
NHSTUB(GetFocusLensSubjectDistance            ,0xff93a3ac) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff93a6b8) //  3
NHSTUB(GetKbdState                            ,0xff84b660) //109
NHSTUB(GetMemInfo                             ,0xff813c24) //115
NHSTUB(GetOpticalTemperature                  ,0xff84e6d0) //120
NHSTUB(GetParameterData                       ,0xff9754d4) //101
NHSTUB(GetPropertyCase                        ,0xff879778) //102
NHSTUB(GetSystemTime                          ,0xffa67c8c) //120
NHSTUB(GetVRAMHPixelsSize                     ,0xff83ccb4) //120
NHSTUB(GetVRAMVPixelsSize                     ,0xff83ccc0) //120
NHSTUB(GetZoomLensCurrentPoint                ,0xff9411d0) //120
NHSTUB(GetZoomLensCurrentPosition             ,0xffa5b364) //102
NHSTUB(GiveSemaphore                          ,0xff8279e8) //120
NHSTUB(IsStrobeChargeCompleted                ,0xff8b6aa0) //102
NHSTUB(LEDDrive                               ,0xff84ab48) //120
NHSTUB(LocalTime                              ,0xff87322c) //115
NHSTUB(LockMainPower                          ,0xff881010) //120
NHSTUB(MakeDirectory_Fut                      ,0xff823384) //116
NHSTUB(MoveFocusLensToDistance                ,0xffacda6c) //102
NHSTUB(MoveIrisWithAv                         ,0xffa63260) //120
NHSTUB(MoveZoomLensWithPoint                  ,0xffa63988) //120
NHSTUB(MoveOpticalZoomAt                      ,0xff82505c) //109
NHSTUB(Open                                   ,0xff823a3c) //120
NHSTUB(PB2Rec                                 ,0xff884078) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff86612c) //120
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff866104) //120
NHSTUB(PT_PlaySound                           ,0xff865a7c) //102
NHSTUB(PostLogicalEventForNotPowerType        ,0xff87ed3c) //120
NHSTUB(PostLogicalEventToUI                   ,0xff87ed88) //120
NHSTUB(PutInNdFilter                          ,0xffa6380c) //102
NHSTUB(PutOutNdFilter                         ,0xffa63830) //102
NHSTUB(Read                                   ,0xff819a4c) //120
NHSTUB(ReadFastDir                            ,0xffa491d8) //  1
NHSTUB(Rec2PB                                 ,0xff882a00) //104
NHSTUB(RefreshPhysicalScreen                  ,0xff9df0f4) //104
NHSTUB(RenameFile_Fut                         ,0xff8232bc) //  1
NHSTUB(Restart                                ,0xff829848) //122
NHSTUB(SetAE_ShutterSpeed                     ,0xffad08fc) //102
NHSTUB(SetAutoShutdownTime                    ,0xff881084) //120
NHSTUB(SetCurrentCaptureModeType              ,0xff888754) //120
NHSTUB(SetFileAttributes                      ,0xff823d90) //  1
NHSTUB(SetFileTimeStamp                       ,0xff823d40) //  1
NHSTUB(SetLogicalEventActive                  ,0xff880cd0) //120
NHSTUB(SetParameterData                       ,0xff9753b0) //101
NHSTUB(SetPropertyCase                        ,0xff879670) //102
NHSTUB(SetScriptMode                          ,0xff880d20) //120
NHSTUB(SleepTask                              ,0xff827c50) //120
NHSTUB(TakeSemaphore                          ,0xff827918) //120
NHSTUB(TurnOffBackLight                       ,0xff88f32c) //104
NHSTUB(TurnOnBackLight                        ,0xff88f314) //104
NHSTUB(TurnOnDisplay                          ,0xff846cf0) //120
NHSTUB(TurnOffDisplay                         ,0xff846d00) //120
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff9637e4) //120
NHSTUB(UnlockAE                               ,0xff825bd8) //120
NHSTUB(UnlockAF                               ,0xff82589c) //120
NHSTUB(UnlockMainPower                        ,0xff880f64) //120
NHSTUB(UpdateMBROnFlash                       ,0xff85acd8) //105
NHSTUB(VbattGet                               ,0xff82046c) //120
NHSTUB(Write                                  ,0xff823b10) //120
NHSTUB(WriteSDCard                            ,0xff92aa44) //108
NHSTUB(_log                                   ,0xffb01a54) //111
NHSTUB(_log10                                 ,0xffb006e0) //112
NHSTUB(_pow                                   ,0xffb00850) //121
NHSTUB(_sqrt                                  ,0xffb036b0) //  1
NHSTUB(add_ptp_handler                        ,0xffa17330) //121
NHSTUB(apex2us                                ,0xff9e01dc) //121
NHSTUB(close                                  ,0xff819864) //109
NHSTUB(err_init_task                          ,0xff814e80) //111
NHSTUB(exmem_alloc                            ,0xff87416c) //103
NHSTUB(exmem_free                             ,0xff8741e4) //103
NHSTUB(free                                   ,0xff813a7c) //112
NHSTUB(get_current_nd_value                   ,0xffa5989c) //122
NHSTUB(kbd_p1_f                               ,0xff821c10) //109
NHSTUB(kbd_p1_f_cont                          ,0xff821c1c) //109
NHSTUB(kbd_p2_f                               ,0xff821428) //109
NHSTUB(kbd_read_keys                          ,0xff821b14) //109
NHSTUB(kbd_read_keys_r2                       ,0xff84af6c) //109
NHSTUB(lseek                                  ,0xff823ba4) //120
NHSTUB(malloc                                 ,0xff8139a8) //112
NHSTUB(memcmp                                 ,0xff81cba4) //120
NHSTUB(memcpy                                 ,0xff89bb28) //120
NHSTUB(memset                                 ,0xff9df514) //120
NHSTUB(mkdir                                  ,0xff823e08) //109
NHSTUB(mktime_ext                             ,0xff89c394) //  1
NHSTUB(open                                   ,0xff8197b4) //109
NHSTUB(OpenFastDir                            ,0xffa49144) //  1
NHSTUB(closedir                               ,0xffa492a8) //  1
NHSTUB(qsort                                  ,0xffab829c) //  1
NHSTUB(rand                                   ,0xff81ccac) //121
NHSTUB(realloc                                ,0xff813b5c) //115
NHSTUB(reboot_fw_update                       ,0xffa50bd8) //106
NHSTUB(set_control_event                      ,0xff88092c) //111
NHSTUB(srand                                  ,0xff81cca0) //122
NHSTUB(stat                                   ,0xff823c70) //  1
NHSTUB(strcat                                 ,0xff89b93c) //  1
NHSTUB(strchr                                 ,0xff89b9c4) //  1
NHSTUB(strcmp                                 ,0xff81cb3c) //120
NHSTUB(strcpy                                 ,0xff81cb24) //120
NHSTUB(strftime                               ,0xff89bd9c) //  1
NHSTUB(strlen                                 ,0xff81cb80) //120
NHSTUB(strncmp                                ,0xff89b978) //  1
NHSTUB(strncpy                                ,0xff82db14) //  1
NHSTUB(strrchr                                ,0xff9df4ec) //  1
NHSTUB(strtol                                 ,0xff82dd4c) //101
NHSTUB(strtolx                                ,0xff82db50) //109
   DEF(task_CaptSeq                           ,0xff868c38) //120
   DEF(task_DvlpSeqTask                       ,0xff94d808) //120
   DEF(task_ExpDrv                            ,0xff8ad86c) //120
   DEF(task_FileWrite                         ,0xffa45af8) //120
   DEF(task_InitFileModules                   ,0xff884af4) //120
   DEF(task_MovieRecord                       ,0xff864630) //120
   DEF(task_PhySw                             ,0xff821784) //120
   DEF(task_RotaryEncoder                     ,0xff84b8d8) //120
NHSTUB(time                                   ,0xff87380c) //109
NHSTUB(vsprintf                               ,0xff81cae8) //115
NHSTUB(EngDrvRead                             ,0xff822a50) //102
NHSTUB(PTM_GetCurrentItem                     ,0xff881890) //105
NHSTUB(CancelHPTimer                          ,0xff874fcc) //119
NHSTUB(SetHPTimerAfterNow                     ,0xff874ec4) //119
NHSTUB(PT_MFOn                                ,0xff8661a4) //120
NHSTUB(PT_MFOff                               ,0xff8661b4) //120
NHSTUB(GetAdChValue                           ,0xff848c64) //120
NHSTUB(get_ptp_buf_size                       ,0xff8d7c24) //122
NHSTUB(get_ptp_file_buf                       ,0xffa18cb4) //121
NHSTUB(SetVideoOutType                        ,0xffad10e8) //109
