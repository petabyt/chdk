// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R45 (DRYOS version 2.3, release #0045)
//   Firmware Ver GM1.02D   // Found @ 0xff894e54, "GM1.02D" @ 0xff894e61
//   Firmware build timestamp: Mar  1 2011 09:05:49
//   Canon IXUS 1000HS

// Values for makefile.inc
//   PLATFORMOSVER = 45
//   PLATFORMID = 12792 (0x31f8) // Found @ 0xfffe0130
//   MAXRAMADDR = 0x07ffffff
//   MEMISOSTART = 0x00172bf8
//   KEYSYS = d4b                // Found @ 0xffff3624
//   NEED_ENCODED_DISKBOOT = 5   // Found @ 0xffff3634
//   ARAM_HEAP_START = 0x3ce000  // Found @ 0xff9945b0
//   ARAM_HEAP_SIZE  = 0x32000   // Found @ 0xff994570

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ffaf49e4 -> ffc28e2c
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00034408) // Found @0xff834b8c
DEF(physw_run                               ,0x00001c40) // Found @0xff834758
DEF(physw_sleep_delay                       ,0x00001c48) // Found @0xff834758
DEF(levent_table                            ,0xffbcdc68) // Found @0xffbcdc68
DEF(FlashParamsTable                        ,0xffc29030) // Found @0xffc29030
DEF(movie_status                            ,0x000078dc) // Found @0xff9858cc
DEF(video_compression_rate                  ,0x0000791c) // Found @0xff985f3c
DEF(full_screen_refresh                     ,0x0000a340) // Found @0xffa2beb8
DEF(canon_menu_active                       ,0x00003840) // Found @0xff896980
DEF(canon_shoot_menu_active                 ,0x00008aed) // Found @0xff9c6568
DEF(playrec_mode                            ,0x00003574) // Found @0xff888a64
DEF(zoom_status                             ,0x0000e2c8) // Found @0xffaf7f68
DEF(some_flag_for_af_scan                   ,0x00007cb4) // Found @0xff9897ac
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 3 int value(s), the first is the zoom focus length.
// there are 101 entries in the table - set NUM_FL to 101
DEF(focus_len_table                         ,0xfffe9eac) // Found @0xfffe9eac
DEF(zoom_busy                               ,0x00007618) // Found @0xff97a414
DEF(focus_busy                              ,0x00007394) // Found @0xff972b7c
DEF(recreview_hold                          ,0x00004294) // Found @0xff8a882c
// Palette colour tables  found @ 0xffbe8dec
DEF(palette_control                         ,0x0000a340) // Found @0xffa2be34
DEF(active_palette_buffer                   ,0x0000a348) // Found @0xffa2be38
DEF(palette_buffer_ptr                      ,0x0000a34c) // Found @0xffa2c35c
DEF(palette_buffer                          ,0x000b84ac) // Found @0xffa2c36c
// Offset from start of palette_buffer to color data = 8 (Found @0xffb2a850)
DEF(bitmap_buffer                           ,0x0000a37c) // Found @0xffa3101c
DEF(active_bitmap_buffer                    ,0x0000a374) // Found @0xffa31020
DEF(viewport_buffers                        ,0xffb8c65c) // Found @0xff851b20
DEF(active_viewport_buffer                  ,0x000020dc) // Found @0xff851860
// Camera has 2 RAW buffers @ 0x4132cd20 & 0x46000000
//  Note: active buffer --> raw_buffers[ active_raw_buffer   *3]
//        other buffer  --> raw_buffers[(active_raw_buffer^1)*3]
DEF(raw_buffers                             ,0xffb8ee18) // Found @0xffb8ee18
DEF(active_raw_buffer                       ,0x000034d0) // Found @0xff885220
DEF(fileio_semaphore                        ,0x000031d4) // Found @0xff873c98
DEF_CONST(uiprop_count                      ,0x00000072) // Found @0xff9b13b4

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x40471000; }             // Found @0xff85d3b0
//void *vid_get_viewport_fb()      { return (void*)0x40587700; }             // Found @0xffb4cc34
DEF(viewport_fb_d                           ,0x00003288) // Found 0x3230 (@0xff877d3c) + 0x58 (@0xff877d74)
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x3230+0x58)); } // Found @0xff877d3c & 0xff877d74
DEF(jpeg_count_str                          ,0x000b7e00) // Found @0xffa238e4
//char *camera_jpeg_count_str()    { return (char*)0x000b7e00; }             // Found @0xffa238e4
//int get_flash_params_count(void) { return 0x9a; }                          // Found @0xff9b1d78

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffb8d64c, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x00080000 // Found @0xffb8d65c, levent 0x902
//#define USB_IDX             2
//#define BATTCOVER_FLAG      0x00008000 // Found @0xffb8d63c, levent 0x905
//#define BATTCOVER_IDX       2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 1, KEY_VIDEO           ,0x00000080 }, // Found @0xffb8d5ac, levent 0x12
//    { 1, KEY_UP              ,0x00000400 }, // Found @0xffb8d5c4, levent 0x04
//    { 1, KEY_RIGHT           ,0x00000800 }, // Found @0xffb8d5cc, levent 0x07
//    { 1, KEY_SET             ,0x00001000 }, // Found @0xffb8d5d4, levent 0x08
//    { 1, KEY_LEFT            ,0x00008000 }, // Found @0xffb8d5ec, levent 0x06
//    { 1, KEY_MENU            ,0x00010000 }, // Found @0xffb8d5f4, levent 0x09
//    { 1, KEY_DOWN            ,0x00020000 }, // Found @0xffb8d5fc, levent 0x05
//    { 2, KEY_SHOOT_FULL      ,0x00002002 }, // Found @0xffb8d61c, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00002000 }, // Found @0xffb8d634, levent 0x00
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000002 }, // Found @0xffb8d61c, levent 0x01
//    { 2, KEY_POWER           ,0x00000008 }, // Found @0xffb8d624, levent 0x600
//    { 2, KEY_PLAYBACK        ,0x00000100 }, // Found @0xffb8d62c, levent 0x601
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_RAW_ROWPIX    3816 // Found @0xff94b510
//#define CAM_RAW_ROWS      2784 // Found @0xff94b51c
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff83b934
//#define CAM_DATE_FOLDER_NAMING 0x400 // Found @0xffa9fb3c (pass as 3rd param to GetImageFolder)
//#define PARAM_CAMERA_NAME 4 // Found @0xffc2b7d8

// Misc stuff
DEF(ctypes, 0xffb8be6e)

// LED table init @ 0xff929be0
// LED #1: 0xc0223030, offset 0x1d8
// LED #2: 0xc0220138, offset 0x4
// LED #3: 0xc0220130, offset 0x38

// For capt_seq.c
DEF(_nrflag,0x7cf8) // Found @ ff98d8dc (0x7cf0) & ff98d914 (+0x08)
//static long *nrflag = (long*)(0x7cf0+0x08);  // Found @ ff98d8dc & ff98d914
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
NHSTUB(ExecuteEventProcedure                  ,0xff8920e0) //104
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
NHSTUB(GetBatteryTemperature                  ,0xff86839c) //102
NHSTUB(GetCCDTemperature                      ,0xff868328) //102
NHSTUB(GetCurrentAvValue                      ,0xff9752d0) //120
NHSTUB(GetDrive_ClusterSize                   ,0xff8757e8) //122
NHSTUB(GetDrive_FreeClusters                  ,0xff875848) //119
NHSTUB(GetDrive_TotalClusters                 ,0xff87581c) //119
NHSTUB(GetFocusLensSubjectDistance            ,0xff973864) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff973cb8) //  3
NHSTUB(GetImageFolder                         ,0xff952d68) //122
NHSTUB(GetKbdState                            ,0xff8633c4) //109
NHSTUB(GetMemInfo                             ,0xff81a264) //115
NHSTUB(GetOpticalTemperature                  ,0xff868410) //120
NHSTUB(GetParameterData                       ,0xff9b1d3c) //101
NHSTUB(GetPropertyCase                        ,0xff895de8) //102
NHSTUB(GetSystemTime                          ,0xffae57f8) //120
NHSTUB(GetVRAMHPixelsSize                     ,0xff854030) //120
NHSTUB(GetVRAMVPixelsSize                     ,0xff85403c) //120
NHSTUB(GetZoomLensCurrentPoint                ,0xff97aed8) //120
NHSTUB(GetZoomLensCurrentPosition             ,0xffacd28c) //102
NHSTUB(GiveSemaphore                          ,0xff83b30c) //120
NHSTUB(IsStrobeChargeCompleted                ,0xff8e5d34) //102
NHSTUB(LEDDrive                               ,0xff8626a8) //120
NHSTUB(LocalTime                              ,0xff88f9c8) //115
NHSTUB(LockMainPower                          ,0xff89c6e4) //120
NHSTUB(MakeDirectory_Fut                      ,0xff837a4c) //116
NHSTUB(MoveFocusLensToDistance                ,0xffb49140) //102
NHSTUB(MoveIrisWithAv                         ,0xffae05a8) //120
NHSTUB(MoveZoomLensWithPoint                  ,0xffae0e24) //120
NHSTUB(Open                                   ,0xff837ff4) //120
NHSTUB(PB2Rec                                 ,0xff89f768) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff880aac) //120
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff880a84) //120
NHSTUB(PT_PlaySound                           ,0xff88a830) //122
NHSTUB(PostLogicalEventForNotPowerType        ,0xff89a444) //120
NHSTUB(PostLogicalEventToUI                   ,0xff89a490) //120
NHSTUB(PutInNdFilter                          ,0xffb46540) //102
NHSTUB(PutOutNdFilter                         ,0xffb46578) //102
NHSTUB(Read                                   ,0xff81ad74) //120
NHSTUB(ReadFastDir                            ,0xffab9204) //  4
NHSTUB(Rec2PB                                 ,0xff89e010) //104
NHSTUB(RefreshPhysicalScreen                  ,0xff8b3d28) //104
NHSTUB(RenameFile_Fut                         ,0xff837944) //116
NHSTUB(Restart                                ,0xff83d0dc) //122
NHSTUB(ScreenLock                             ,0xff8b4eec) //117
NHSTUB(ScreenUnlock                           ,0xff8b4f50) //117
NHSTUB(SetAE_ShutterSpeed                     ,0xffb4bce0) //102
NHSTUB(SetAutoShutdownTime                    ,0xff89c758) //120
NHSTUB(SetCurrentCaptureModeType              ,0xff8a5a00) //120
NHSTUB(SetFileAttributes                      ,0xff838358) //  3
NHSTUB(SetFileTimeStamp                       ,0xff8382fc) //  4
NHSTUB(SetLogicalEventActive                  ,0xff89c420) //120
NHSTUB(SetParameterData                       ,0xff9b1ca8) //101
NHSTUB(SetPropertyCase                        ,0xff895cc0) //102
NHSTUB(SetScriptMode                          ,0xff89c470) //120
NHSTUB(SleepTask                              ,0xff83b574) //120
NHSTUB(TakeSemaphore                          ,0xff83b23c) //120
NHSTUB(TurnOffBackLight                       ,0xff8ac5bc) //104
NHSTUB(TurnOnBackLight                        ,0xff8ac5a4) //104
NHSTUB(TurnOnDisplay                          ,0xff85d720) //120
NHSTUB(TurnOffDisplay                         ,0xff85d730) //120
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff9a13a4) //120
NHSTUB(UnlockAE                               ,0xff83988c) //120
NHSTUB(UnlockAF                               ,0xff8396a8) //120
NHSTUB(UnlockMainPower                        ,0xff89c638) //120
NHSTUB(UpdateMBROnFlash                       ,0xff875668) //105
NHSTUB(VbattGet                               ,0xff833308) //120
NHSTUB(Write                                  ,0xff8380f0) //120
NHSTUB(WriteSDCard                            ,0xff962f74) //108
NHSTUB(_log                                   ,0xffb88f7c) //111
NHSTUB(_log10                                 ,0xffb87c08) //112
NHSTUB(_pow                                   ,0xffb87d78) //121
NHSTUB(_sqrt                                  ,0xffb8ab84) //  1
NHSTUB(add_ptp_handler                        ,0xffa72bb4) //121
NHSTUB(apex2us                                ,0xffa34f88) //121
NHSTUB(close                                  ,0xff81ab8c) //109
NHSTUB(err_init_task                          ,0xff815fd4) //111
NHSTUB(exmem_alloc                            ,0xff890914) //103
NHSTUB(exmem_free                             ,0xff89098c) //103
NHSTUB(free                                   ,0xff814244) //112
NHSTUB(kbd_p1_f                               ,0xff834c04) //109
NHSTUB(kbd_p1_f_cont                          ,0xff834c10) //109
NHSTUB(kbd_p2_f                               ,0xff834424) //109
NHSTUB(kbd_read_keys                          ,0xff834b8c) //109
NHSTUB(kbd_read_keys_r2                       ,0xff862c10) //109
NHSTUB(lseek                                  ,0xff83817c) //120
NHSTUB(malloc                                 ,0xff8141e8) //112
NHSTUB(memcmp                                 ,0xff820750) //120
NHSTUB(memcpy                                 ,0xff84110c) //120
NHSTUB(memset                                 ,0xffa33f84) //120
NHSTUB(mkdir                                  ,0xff8384fc) //109
NHSTUB(mktime_ext                             ,0xff8b5cf4) //  1
NHSTUB(open                                   ,0xff81aadc) //109
NHSTUB(OpenFastDir                            ,0xffab90b0) //  4
NHSTUB(closedir                               ,0xffab9060) //121
NHSTUB(get_fstype                             ,0xff87586c) //122
NHSTUB(qsort                                  ,0xffb2e30c) //  4
NHSTUB(rand                                   ,0xffa340c4) //121
NHSTUB(realloc                                ,0xffa34000) //115
NHSTUB(reboot_fw_update                       ,0xffabe624) //106
NHSTUB(set_control_event                      ,0xff89c010) //111
NHSTUB(srand                                  ,0xffa340b8) //122
NHSTUB(stat                                   ,0xff8381c4) //109
NHSTUB(strcat                                 ,0xff8b54b0) //  1
NHSTUB(strchr                                 ,0xff8140b4) //  1
NHSTUB(strcmp                                 ,0xff82070c) //120
NHSTUB(strcpy                                 ,0xff8206f4) //120
NHSTUB(strftime                               ,0xff8b56fc) //113
NHSTUB(strlen                                 ,0xff814100) //120
NHSTUB(strncmp                                ,0xff814068) //  1
NHSTUB(strncpy                                ,0xff81402c) //  1
NHSTUB(strrchr                                ,0xff8140d8) //  1
NHSTUB(strtol                                 ,0xff8413ec) //101
NHSTUB(strtolx                                ,0xff8411f0) //109
   DEF(task_CaptSeq                           ,0xff88365c) //120
   DEF(task_DvlpSeqTask                       ,0xff884dc4) //120
   DEF(task_ExpDrv                            ,0xff8ccab4) //120
   DEF(task_FileWrite                         ,0xffab70d8) //120
   DEF(task_InitFileModules                   ,0xff8a01e0) //120
   DEF(task_MovieRecord                       ,0xff98672c) //120
   DEF(task_PhySw                             ,0xff834754) //120
   DEF(task_RotaryEncoder                     ,0xff863668) //120
NHSTUB(time                                   ,0xff88ffa8) //109
NHSTUB(vsprintf                               ,0xff8206b8) //115
NHSTUB(EngDrvRead                             ,0xff835a5c) //102
NHSTUB(PTM_GetCurrentItem                     ,0xff89d030) //105
NHSTUB(CancelHPTimer                          ,0xff8917c8) //119
NHSTUB(SetHPTimerAfterNow                     ,0xff8916c0) //119
NHSTUB(PT_MFOn                                ,0xff880b3c) //120
NHSTUB(PT_MFOff                               ,0xff880b4c) //120
NHSTUB(GetAdChValue                           ,0xff85ee60) //120
