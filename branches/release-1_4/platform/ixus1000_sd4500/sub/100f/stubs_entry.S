// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R45 (DRYOS version 2.3, release #0045)
//   Firmware Ver GM1.00F   // Found @ 0xff894e28, "GM1.00F" @ 0xff894e35
//   Firmware build timestamp: Sep  7 2010 17:48:22
//   Canon IXUS 1000HS

// Values for makefile.inc
//   PLATFORMOSVER = 45
//   PLATFORMID = 12792 (0x31f8) // Found @ 0xfffe0130
//   MAXRAMADDR = 0x07ffffff
//   MEMISOSTART = 0x00172bf8
//   KEYSYS = d4b                // Found @ 0xffff3624
//   NEED_ENCODED_DISKBOOT = 5   // Found @ 0xffff3634
//   ARAM_HEAP_START = 0x3ce000  // Found @ 0xff9944e8
//   ARAM_HEAP_SIZE  = 0x32000   // Found @ 0xff9944a8

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ffaf48e0 -> ffc28d2c
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00034408) // Found @0xff834b8c
DEF(physw_run                               ,0x00001c40) // Found @0xff834758
DEF(physw_sleep_delay                       ,0x00001c48) // Found @0xff834758
DEF(levent_table                            ,0xffbcdb68) // Found @0xffbcdb68
DEF(FlashParamsTable                        ,0xffc28f30) // Found @0xffc28f30
DEF(movie_status                            ,0x000078dc) // Found @0xff985804
DEF(video_compression_rate                  ,0x0000791c) // Found @0xff985e74
DEF(full_screen_refresh                     ,0x0000a340) // Found @0xffa2bdf0
DEF(canon_menu_active                       ,0x00003840) // Found @0xff896954
DEF(canon_shoot_menu_active                 ,0x00008aed) // Found @0xff9c64a0
DEF(playrec_mode                            ,0x00003574) // Found @0xff888a38
//DEF(zoom_status                             ,0x0000e2c8) // Found @0xffaf7e64, ** != ** stubs_min = 0x0000e2a8 (0xE2A8)
DEF(some_flag_for_af_scan                   ,0x00007cb4) // Found @0xff9896e4
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 3 int value(s), the first is the zoom focus length.
// there are 101 entries in the table - set NUM_FL to 101
DEF(focus_len_table                         ,0xfffe9eac) // Found @0xfffe9eac
DEF(zoom_busy                               ,0x00007618) // Found @0xff97a34c
DEF(focus_busy                              ,0x00007394) // Found @0xff972b30
//DEF(recreview_hold                          ,0x00004294) // Found @0xff8a8800, ** != ** stubs_min = 0x000087e8 (0x86FC+0xEC)
// Palette colour tables  found @ 0xffbe8cec
DEF(palette_control                         ,0x0000a340) // Found @0xffa2bd6c
DEF(active_palette_buffer                   ,0x0000a348) // Found @0xffa2bd70
DEF(palette_buffer_ptr                      ,0x0000a34c) // Found @0xffa2c294
DEF(palette_buffer                          ,0x000b84ac) // Found @0xffa2c2a4
// Offset from start of palette_buffer to color data = 8 (Found @0xffb2a74c)
DEF(bitmap_buffer                           ,0x0000a37c) // Found @0xffa30f54
DEF(active_bitmap_buffer                    ,0x0000a374) // Found @0xffa30f58
DEF(viewport_buffers                        ,0xffb8c55c) // Found @0xff851afc
DEF(active_viewport_buffer                  ,0x000020dc) // Found @0xff85183c
// Camera has 2 RAW buffers @ 0x4132cd20 & 0x46000000
//  Note: active buffer --> raw_buffers[ active_raw_buffer   *3]
//        other buffer  --> raw_buffers[(active_raw_buffer^1)*3]
DEF(raw_buffers                             ,0xffb8ed18) // Found @0xffb8ed18
DEF(active_raw_buffer                       ,0x000034d0) // Found @0xff8851f4
DEF(fileio_semaphore                        ,0x000031d4) // Found @0xff873c6c
DEF_CONST(uiprop_count                      ,0x00000072) // Found @0xff9b12ec

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x40471000; }             // Found @0xff85d384
//void *vid_get_viewport_fb()      { return (void*)0x40587700; }             // Found @0xffb4cb30
DEF(viewport_fb_d                           ,0x00003288) // Found 0x3230 (@0xff877d10) + 0x58 (@0xff877d48)
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x3230+0x58)); } // Found @0xff877d10 & 0xff877d48
DEF(jpeg_count_str                          ,0x000b7e00) // Found @0xffa2381c
//char *camera_jpeg_count_str()    { return (char*)0x000b7e00; }             // Found @0xffa2381c
//int get_flash_params_count(void) { return 0x9a; }                          // Found @0xff9b1cb0

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffb8d54c, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x00080000 // Found @0xffb8d55c, levent 0x902
//#define USB_IDX             2
//#define BATTCOVER_FLAG      0x00008000 // Found @0xffb8d53c, levent 0x905
//#define BATTCOVER_IDX       2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 1, KEY_VIDEO           ,0x00000080 }, // Found @0xffb8d4ac, levent 0x12
//    { 1, KEY_UP              ,0x00000400 }, // Found @0xffb8d4c4, levent 0x04
//    { 1, KEY_RIGHT           ,0x00000800 }, // Found @0xffb8d4cc, levent 0x07
//    { 1, KEY_SET             ,0x00001000 }, // Found @0xffb8d4d4, levent 0x08
//    { 1, KEY_LEFT            ,0x00008000 }, // Found @0xffb8d4ec, levent 0x06
//    { 1, KEY_MENU            ,0x00010000 }, // Found @0xffb8d4f4, levent 0x09
//    { 1, KEY_DOWN            ,0x00020000 }, // Found @0xffb8d4fc, levent 0x05
//    { 2, KEY_SHOOT_FULL      ,0x00002002 }, // Found @0xffb8d51c, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00002000 }, // Found @0xffb8d534, levent 0x00
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000002 }, // Found @0xffb8d51c, levent 0x01
//    { 2, KEY_POWER           ,0x00000008 }, // Found @0xffb8d524, levent 0x600
//    { 2, KEY_PLAYBACK        ,0x00000100 }, // Found @0xffb8d52c, levent 0x601
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_RAW_ROWPIX    3816 // Found @0xff94b4c4
//#define CAM_RAW_ROWS      2784 // Found @0xff94b4d0
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff83b934
//#define CAM_DATE_FOLDER_NAMING 0x400 // Found @0xffa9fa64 (pass as 3rd param to GetImageFolder)
//#define PARAM_CAMERA_NAME 4 // Found @0xffc2b6d8

// Misc stuff
DEF(ctypes, 0xffb8bd6e)

// LED table init @ 0xff929b94
// LED #1: 0xc0223030, offset 0x1d8
// LED #2: 0xc0220138, offset 0x4
// LED #3: 0xc0220130, offset 0x38

// For capt_seq.c
DEF(_nrflag,0x7cf8) // Found @ ff98d814 (0x7cf0) & ff98d84c (+0x08)
//static long *nrflag = (long*)(0x7cf0+0x08);  // Found @ ff98d814 & ff98d84c
//#define NR_AUTO (0)                          // have to explictly reset value back to 0 to enable auto

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NHSTUB(AllocateUncacheableMemory              ,0xff83b8f0) //112
NHSTUB(Close                                  ,0xff838060) //120
NHSTUB(CreateBinarySemaphore                  ,0xff83b0d0) //115
NHSTUB(CreateTask                             ,0xff81e8a0) //120
NHSTUB(DebugAssert                            ,0xff81eb78) //107
NHSTUB(DeleteDirectory_Fut                    ,0xff837abc) //116
NHSTUB(DeleteFile_Fut                         ,0xff8379d8) //112
NHSTUB(DoAELock                               ,0xff839868) //120
NHSTUB(DoAFLock                               ,0xff839670) //120
NHSTUB(EnterToCompensationEVF                 ,0xff839770) //104
NHSTUB(ExecuteEventProcedure                  ,0xff8920b4) //104
NHSTUB(ExitFromCompensationEVF                ,0xff8397b4) //104
NHSTUB(ExitTask                               ,0xff81eb30) //120
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff847d34) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff847ec0) //104
NHSTUB(Fclose_Fut                             ,0xff837b54) //120
NHSTUB(Feof_Fut                               ,0xff837d40) //  1
NHSTUB(Fflush_Fut                             ,0xff837d7c) //  1
NHSTUB(Fgets_Fut                              ,0xff837ca8) //  1
NHSTUB(Fopen_Fut                              ,0xff837b14) //120
NHSTUB(Fread_Fut                              ,0xff837c00) //120
NHSTUB(FreeUncacheableMemory                  ,0xff83b930) //112
NHSTUB(Fseek_Fut                              ,0xff837cf4) //120
NHSTUB(Fwrite_Fut                             ,0xff837c54) //120
NHSTUB(GetBatteryTemperature                  ,0xff868370) //102
NHSTUB(GetCCDTemperature                      ,0xff8682fc) //102
NHSTUB(GetCurrentAvValue                      ,0xff975264) //120
NHSTUB(GetDrive_ClusterSize                   ,0xff8757bc) //122
NHSTUB(GetDrive_FreeClusters                  ,0xff87581c) //119
NHSTUB(GetDrive_TotalClusters                 ,0xff8757f0) //119
NHSTUB(GetFocusLensSubjectDistance            ,0xff973818) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff973c6c) //  3
NHSTUB(GetImageFolder                         ,0xff952d1c) //122
NHSTUB(GetKbdState                            ,0xff863398) //109
NHSTUB(GetMemInfo                             ,0xff81a264) //115
NHSTUB(GetOpticalTemperature                  ,0xff8683e4) //120
NHSTUB(GetParameterData                       ,0xff9b1c74) //101
NHSTUB(GetPropertyCase                        ,0xff895dbc) //102
NHSTUB(GetSystemTime                          ,0xffae56f4) //120
NHSTUB(GetVRAMHPixelsSize                     ,0xff854000) //120
NHSTUB(GetVRAMVPixelsSize                     ,0xff85400c) //120
NHSTUB(GetZoomLensCurrentPoint                ,0xff97ae10) //120
NHSTUB(GetZoomLensCurrentPosition             ,0xffacd188) //102
NHSTUB(GiveSemaphore                          ,0xff83b30c) //120
NHSTUB(IsStrobeChargeCompleted                ,0xff8e5d08) //102
NHSTUB(LEDDrive                               ,0xff86267c) //120
NHSTUB(LocalTime                              ,0xff88f99c) //115
NHSTUB(LockMainPower                          ,0xff89c6b8) //120
NHSTUB(MakeDirectory_Fut                      ,0xff837a4c) //116
NHSTUB(MoveFocusLensToDistance                ,0xffb4903c) //102
NHSTUB(MoveIrisWithAv                         ,0xffae04a4) //120
NHSTUB(MoveZoomLensWithPoint                  ,0xffae0d20) //120
NHSTUB(Open                                   ,0xff837ff4) //120
NHSTUB(PB2Rec                                 ,0xff89f73c) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff880a80) //120
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff880a58) //120
NHSTUB(PT_PlaySound                           ,0xff88a804) //122
NHSTUB(PostLogicalEventForNotPowerType        ,0xff89a418) //120
NHSTUB(PostLogicalEventToUI                   ,0xff89a464) //120
NHSTUB(PutInNdFilter                          ,0xffb4643c) //102
NHSTUB(PutOutNdFilter                         ,0xffb46474) //102
NHSTUB(Read                                   ,0xff81ad74) //120
NHSTUB(ReadFastDir                            ,0xffab912c) //  4
NHSTUB(Rec2PB                                 ,0xff89dfe4) //104
NHSTUB(RefreshPhysicalScreen                  ,0xff8b3cfc) //104
NHSTUB(RenameFile_Fut                         ,0xff837944) //116
NHSTUB(Restart                                ,0xff83d0dc) //122
NHSTUB(ScreenLock                             ,0xff8b4ec0) //117
NHSTUB(ScreenUnlock                           ,0xff8b4f24) //117
NHSTUB(SetAE_ShutterSpeed                     ,0xffb4bbdc) //102
NHSTUB(SetAutoShutdownTime                    ,0xff89c72c) //120
NHSTUB(SetCurrentCaptureModeType              ,0xff8a59d4) //120
NHSTUB(SetFileAttributes                      ,0xff838358) //  3
NHSTUB(SetFileTimeStamp                       ,0xff8382fc) //  4
NHSTUB(SetLogicalEventActive                  ,0xff89c3f4) //120
NHSTUB(SetParameterData                       ,0xff9b1be0) //101
NHSTUB(SetPropertyCase                        ,0xff895c94) //102
NHSTUB(SetScriptMode                          ,0xff89c444) //120
NHSTUB(SleepTask                              ,0xff83b574) //120
NHSTUB(TakeSemaphore                          ,0xff83b23c) //120
NHSTUB(TurnOffBackLight                       ,0xff8ac590) //104
NHSTUB(TurnOnBackLight                        ,0xff8ac578) //104
NHSTUB(TurnOnDisplay                          ,0xff85d6f4) //120
NHSTUB(TurnOffDisplay                         ,0xff85d704) //120
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff9a12dc) //120
NHSTUB(UnlockAE                               ,0xff83988c) //120
NHSTUB(UnlockAF                               ,0xff8396a8) //120
NHSTUB(UnlockMainPower                        ,0xff89c60c) //120
NHSTUB(UpdateMBROnFlash                       ,0xff87563c) //105
NHSTUB(VbattGet                               ,0xff833308) //120
NHSTUB(Write                                  ,0xff8380f0) //120
NHSTUB(WriteSDCard                            ,0xff962f28) //108
NHSTUB(_log                                   ,0xffb88e7c) //111
NHSTUB(_log10                                 ,0xffb87b08) //112
NHSTUB(_pow                                   ,0xffb87c78) //121
NHSTUB(_sqrt                                  ,0xffb8aa84) //  1
NHSTUB(add_ptp_handler                        ,0xffa72adc) //121
NHSTUB(apex2us                                ,0xffa34ec0) //121
NHSTUB(close                                  ,0xff81ab8c) //109
NHSTUB(err_init_task                          ,0xff815fd4) //111
NHSTUB(exmem_alloc                            ,0xff8908e8) //103
NHSTUB(exmem_free                             ,0xff890960) //103
NHSTUB(free                                   ,0xff814244) //112
NHSTUB(kbd_p1_f                               ,0xff834c04) //109
NHSTUB(kbd_p1_f_cont                          ,0xff834c10) //109
NHSTUB(kbd_p2_f                               ,0xff834424) //109
NHSTUB(kbd_read_keys                          ,0xff834b8c) //109
NHSTUB(kbd_read_keys_r2                       ,0xff862be4) //109
NHSTUB(lseek                                  ,0xff83817c) //120
NHSTUB(malloc                                 ,0xff8141e8) //112
NHSTUB(memcmp                                 ,0xff820750) //120
NHSTUB(memcpy                                 ,0xff84110c) //120
NHSTUB(memset                                 ,0xffa33ebc) //120
NHSTUB(mkdir                                  ,0xff8384fc) //109
NHSTUB(mktime_ext                             ,0xff8b5cc8) //  1
NHSTUB(open                                   ,0xff81aadc) //109
NHSTUB(OpenFastDir                            ,0xffab8fd8) //  4
NHSTUB(closedir                               ,0xffab8f88) //121
NHSTUB(get_fstype                             ,0xff875840) //122
NHSTUB(qsort                                  ,0xffb2e208) //  4
NHSTUB(rand                                   ,0xffa33ffc) //121
NHSTUB(realloc                                ,0xffa33f38) //115
NHSTUB(reboot_fw_update                       ,0xffabe54c) //106
NHSTUB(set_control_event                      ,0xff89bfe4) //111
NHSTUB(srand                                  ,0xffa33ff0) //122
NHSTUB(stat                                   ,0xff8381c4) //109
NHSTUB(strcat                                 ,0xff8b5484) //  1
NHSTUB(strchr                                 ,0xff8140b4) //  1
NHSTUB(strcmp                                 ,0xff82070c) //120
NHSTUB(strcpy                                 ,0xff8206f4) //120
NHSTUB(strftime                               ,0xff8b56d0) //113
NHSTUB(strlen                                 ,0xff814100) //120
NHSTUB(strncmp                                ,0xff814068) //  1
NHSTUB(strncpy                                ,0xff81402c) //  1
NHSTUB(strrchr                                ,0xff8140d8) //  1
NHSTUB(strtol                                 ,0xff8413ec) //101
NHSTUB(strtolx                                ,0xff8411f0) //109
   DEF(task_CaptSeq                           ,0xff883630) //120
   DEF(task_DvlpSeqTask                       ,0xff884d98) //120
   DEF(task_ExpDrv                            ,0xff8cca88) //120
   DEF(task_FileWrite                         ,0xffab7000) //120
   DEF(task_InitFileModules                   ,0xff8a01b4) //120
   DEF(task_MovieRecord                       ,0xff986664) //120
   DEF(task_PhySw                             ,0xff834754) //120
   DEF(task_RotaryEncoder                     ,0xff86363c) //120
NHSTUB(time                                   ,0xff88ff7c) //109
NHSTUB(vsprintf                               ,0xff8206b8) //115
NHSTUB(EngDrvRead                             ,0xff835a5c) //102
NHSTUB(PTM_GetCurrentItem                     ,0xff89d004) //105
NHSTUB(CancelHPTimer                          ,0xff89179c) //119
NHSTUB(SetHPTimerAfterNow                     ,0xff891694) //119
NHSTUB(PT_MFOn                                ,0xff880b10) //120
NHSTUB(PT_MFOff                               ,0xff880b20) //120
NHSTUB(GetAdChValue                           ,0xff85ee34) //120
