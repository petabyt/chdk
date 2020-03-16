// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R45 (DRYOS version 2.3, release #0045)
//   Firmware Ver GM1.02E   // Found @ 0xff894ec8, "GM1.02E" @ 0xff894ed5
//   Firmware build timestamp: Apr 21 2011 19:03:58
//   Canon PowerShot SD4500 IS

// Values for makefile.inc
//   DIGIC = 40                  // DIGIC 4
//   PLATFORMOSVER = 45
//   PLATFORMID = 12792 (0x31f8) // Found @ 0xfffe0130
//   MAXRAMADDR = 0x07ffffff
//   MEMISOSTART = 0x00172bf8
//   KEYSYS = d4b                // Found @ 0xffff3624
//   NEED_ENCODED_DISKBOOT = 5   // Found @ 0xffff3634
//   ARAM_HEAP_START = 0x3ce000  // Found @ 0xff99467c
//   ARAM_HEAP_SIZE  = 0x32000   // Found @ 0xff99463c

// Detected address ranges:
// ROM      0xff810000 - 0xffffffff (8323072 bytes)
// RAM data 0x00001900 - 0x00010730 copied from 0xffc56ec8 (  60976 bytes)

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ffaf4ab0 -> ffc28f00
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00034408) // Found @0xff834b8c
DEF(physw_run                               ,0x00001c40) // Found @0xff834758
DEF(physw_sleep_delay                       ,0x00001c48) // Found @0xff834758
DEF(levent_table                            ,0xffbcdd3c) // Found @0xffbcdd3c
DEF(FlashParamsTable                        ,0xffc29104) // Found @0xffc29104
DEF(movie_status                            ,0x000078e4) // Found @0xff985998
DEF(video_compression_rate                  ,0x00007924) // Found @0xff986008
DEF(full_screen_refresh                     ,0x0000a348) // Found @0xffa2bf84
DEF(canon_menu_active                       ,0x00003844) // Found @0xff8969f4
DEF(canon_shoot_menu_active                 ,0x00008af5) // Found @0xff9c6634
DEF(playrec_mode                            ,0x00003578) // Found @0xff888ad8
DEF(zoom_status                             ,0x0000e2d0) // Found @0xffaf8034
DEF(some_flag_for_af_scan                   ,0x00007cbc) // Found @0xff989878
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 3 int value(s), the first is the zoom focus length.
// there are 101 entries in the table - set NUM_FL to 101
DEF(focus_len_table                         ,0xfffe9eac) // Found @0xfffe9eac
DEF(zoom_busy                               ,0x00007620) // Found @0xff97a488
DEF(focus_busy                              ,0x0000739c) // Found @0xff972bf0
DEF(recreview_hold                          ,0x00004298) // Found @0xff8a88a0
// Palette colour tables  found @ 0xffbe8ec0
DEF(palette_control                         ,0x0000a348) // Found @0xffa2bf00
DEF(active_palette_buffer                   ,0x0000a350) // Found @0xffa2bf04
DEF(palette_buffer_ptr                      ,0x0000a354) // Found @0xffa2c428
DEF(palette_buffer                          ,0x000b84ac) // Found @0xffa2c438
// Offset from start of palette_buffer to color data = 8 (Found @0xffb2a91c)
DEF(bitmap_buffer                           ,0x0000a384) // Found @0xffa310e8
DEF(active_bitmap_buffer                    ,0x0000a37c) // Found @0xffa310ec
DEF(viewport_buffers                        ,0xffb8c728) // Found @0xff851b20
DEF(active_viewport_buffer                  ,0x000020dc) // Found @0xff851860
// Camera has 2 RAW buffers @ 0x4132cd20 & 0x46000000
//  Note: active buffer --> raw_buffers[ active_raw_buffer   *3]
//        other buffer  --> raw_buffers[(active_raw_buffer^1)*3]
DEF(raw_buffers                             ,0xffb8eee4) // Found @0xffb8eee4
DEF(active_raw_buffer                       ,0x000034d4) // Found @0xff885294
DEF(fileio_semaphore                        ,0x000031d4) // Found @0xff873c98
DEF(exmem_alloc_table                       ,0x0003ca7c) // Found @0xff890380
DEF(exmem_types_table                       ,0xffc58c58) // Found @0x00003690
DEF_CONST(exmem_type_count                  ,0x00000013)
DEF(imager_active                           ,0x00002020) // Found @0xff84e638 (0x201c + 4)
DEF_CONST(uiprop_count                      ,0x00000072) // Found @0xff9b1480

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x40471000; }             // Found @0xff85d3b0
//void *vid_get_viewport_fb()      { return (void*)0x40587700; }             // Found @0xffb4cd00
DEF(viewport_fb_d                           ,0x00003288) // Found 0x3230 (@0xff877d3c) + 0x58 (@0xff877d74)
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x3230+0x58)); } // Found @0xff877d3c & 0xff877d74
DEF(jpeg_count_str                          ,0x000b7e00) // Found @0xffa239b0
//char *camera_jpeg_count_str()    { return (char*)0x000b7e00; }             // Found @0xffa239b0
//int get_flash_params_count(void) { return 0x9a; }                          // Found @0xff9b1e44

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffb8d718, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x00080000 // Found @0xffb8d728, levent 0x902
//#define USB_IDX             2
//#define BATTCOVER_FLAG      0x00008000 // Found @0xffb8d708, levent 0x905
//#define BATTCOVER_IDX       2
//#define ANALOG_AV_FLAG      0x00040000 // Found @0xffb8d720, levent 0x900 (non-inverted logic)
//#define ANALOG_AV_IDX       2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 1, KEY_VIDEO           ,0x00000080 }, // Found @0xffb8d678, levent 0x12
//    { 1, KEY_UP              ,0x00000400 }, // Found @0xffb8d690, levent 0x04
//    { 1, KEY_RIGHT           ,0x00000800 }, // Found @0xffb8d698, levent 0x07
//    { 1, KEY_SET             ,0x00001000 }, // Found @0xffb8d6a0, levent 0x08
//    { 1, KEY_LEFT            ,0x00008000 }, // Found @0xffb8d6b8, levent 0x06
//    { 1, KEY_MENU            ,0x00010000 }, // Found @0xffb8d6c0, levent 0x09
//    { 1, KEY_DOWN            ,0x00020000 }, // Found @0xffb8d6c8, levent 0x05
//    { 2, KEY_SHOOT_FULL      ,0x00002002 }, // Found @0xffb8d6e8, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00002000 }, // Found @0xffb8d700, levent 0x00
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000002 }, // Found @0xffb8d6e8, levent 0x01
//    { 2, KEY_POWER           ,0x00000008 }, // Found @0xffb8d6f0, levent 0x600
//    { 2, KEY_PLAYBACK        ,0x00000100 }, // Found @0xffb8d6f8, levent 0x601
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_RAW_ROWPIX    3816 // Found @0xff94b584
//#define CAM_RAW_ROWS      2784 // Found @0xff94b590
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff83b934
//#define CAM_DATE_FOLDER_NAMING 0x400 // Found @0xffa9fc08 (pass as 3rd param to GetImageFolder)
//#define PARAM_CAMERA_NAME 4 // Found @0xffc2b8ac

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
DEF(ctypes, 0xffb8bf3a)

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
// EXMEM_SUPER_NARROW   16
// EXMEM_CRAW_REC       17
// EXMEM_PCEVF          18

// ISR flag: 0x1968, pointer to current task's control block: 0x1964
// pointer to TCB area: 0x19f0, found @ 0xff816990

// LED table init @ 0xff929c54
// LED #1: 0xc0223030, offset 0x1d8
// LED #2: 0xc0220138, offset 0x4
// LED #3: 0xc0220130, offset 0x38

// For capt_seq.c
DEF(_nrflag,0x7d00) // Found @ ff98d9a8 (0x7cf8) & ff98d9e0 (+0x08)
//static long *nrflag = (long*)(0x7cf8+0x08);  // Found @ ff98d9a8 & ff98d9e0
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
NHSTUB(ExecuteEventProcedure                  ,0xff892154) //104
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
NHSTUB(GetCurrentAvValue                      ,0xff975344) //120
NHSTUB(GetCurrentShutterSpeed                 ,0xff8ba290) //120
NHSTUB(GetUsableMaxAv                         ,0xffb465a0) //120
NHSTUB(GetUsableMinAv                         ,0xffb46588) //120
NHSTUB(GetDrive_ClusterSize                   ,0xff8757e8) //122
NHSTUB(GetDrive_FreeClusters                  ,0xff875848) //119
NHSTUB(GetDrive_TotalClusters                 ,0xff87581c) //119
NHSTUB(GetFocusLensSubjectDistance            ,0xff9738d8) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff973d2c) //  3
NHSTUB(GetImageFolder                         ,0xff952ddc) //122
NHSTUB(GetKbdState                            ,0xff8633c4) //109
NHSTUB(GetMemInfo                             ,0xff81a264) //115
NHSTUB(GetOpticalTemperature                  ,0xff868410) //120
NHSTUB(GetParameterData                       ,0xff9b1e08) //101
NHSTUB(GetPropertyCase                        ,0xff895e5c) //102
NHSTUB(GetSystemTime                          ,0xffae58c4) //120
NHSTUB(GetVRAMHPixelsSize                     ,0xff854030) //120
NHSTUB(GetVRAMVPixelsSize                     ,0xff85403c) //120
NHSTUB(GetZoomLensCurrentPoint                ,0xff97af4c) //120
NHSTUB(GetZoomLensCurrentPosition             ,0xffacd358) //102
NHSTUB(GiveSemaphore                          ,0xff83b30c) //120
NHSTUB(IsStrobeChargeCompleted                ,0xff8e5da8) //102
NHSTUB(LEDDrive                               ,0xff8626a8) //120
NHSTUB(LocalTime                              ,0xff88fa3c) //115
NHSTUB(LockMainPower                          ,0xff89c758) //120
NHSTUB(MakeDirectory_Fut                      ,0xff837a4c) //116
NHSTUB(MoveFocusLensToDistance                ,0xffb4920c) //102
NHSTUB(MoveIrisWithAv                         ,0xffae0674) //120
NHSTUB(MoveZoomLensWithPoint                  ,0xffae0ef0) //120
NHSTUB(MoveOpticalZoomAt                      ,0xff839168) //109
NHSTUB(Open                                   ,0xff837ff4) //120
NHSTUB(PB2Rec                                 ,0xff89f7dc) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff880b20) //120
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff880af8) //120
NHSTUB(PT_PlaySound                           ,0xff88a8a4) //122
NHSTUB(PostLogicalEventForNotPowerType        ,0xff89a4b8) //120
NHSTUB(PostLogicalEventToUI                   ,0xff89a504) //120
NHSTUB(PutInNdFilter                          ,0xffb4660c) //102
NHSTUB(PutOutNdFilter                         ,0xffb46644) //102
NHSTUB(Read                                   ,0xff81ad74) //120
NHSTUB(ReadFastDir                            ,0xffab92d0) //  4
NHSTUB(Rec2PB                                 ,0xff89e084) //104
NHSTUB(RefreshPhysicalScreen                  ,0xff8b3d9c) //104
NHSTUB(RenameFile_Fut                         ,0xff837944) //116
NHSTUB(Restart                                ,0xff83d0dc) //122
NHSTUB(ScreenLock                             ,0xff8b4f60) //117
NHSTUB(ScreenUnlock                           ,0xff8b4fc4) //117
NHSTUB(SetAE_ShutterSpeed                     ,0xffb4bdac) //102
NHSTUB(SetAutoShutdownTime                    ,0xff89c7cc) //120
NHSTUB(SetCurrentCaptureModeType              ,0xff8a5a74) //120
NHSTUB(SetFileAttributes                      ,0xff838358) //  3
NHSTUB(SetFileTimeStamp                       ,0xff8382fc) //  4
NHSTUB(SetLogicalEventActive                  ,0xff89c494) //120
NHSTUB(SetParameterData                       ,0xff9b1d74) //101
NHSTUB(SetPropertyCase                        ,0xff895d34) //102
NHSTUB(SetScriptMode                          ,0xff89c4e4) //120
NHSTUB(SleepTask                              ,0xff83b574) //120
NHSTUB(TakeSemaphore                          ,0xff83b23c) //120
NHSTUB(TurnOffBackLight                       ,0xff8ac630) //104
NHSTUB(TurnOnBackLight                        ,0xff8ac618) //104
NHSTUB(TurnOnDisplay                          ,0xff85d720) //120
NHSTUB(TurnOffDisplay                         ,0xff85d730) //120
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff9a1470) //120
NHSTUB(UnlockAE                               ,0xff83988c) //120
NHSTUB(UnlockAF                               ,0xff8396a8) //120
NHSTUB(UnlockMainPower                        ,0xff89c6ac) //120
NHSTUB(UpdateMBROnFlash                       ,0xff875668) //105
NHSTUB(VbattGet                               ,0xff833308) //120
NHSTUB(Write                                  ,0xff8380f0) //120
NHSTUB(WriteSDCard                            ,0xff962fe8) //108
NHSTUB(_log                                   ,0xffb89048) //111
NHSTUB(_log10                                 ,0xffb87cd4) //112
NHSTUB(_pow                                   ,0xffb87e44) //121
NHSTUB(_sqrt                                  ,0xffb8ac50) //  1
NHSTUB(add_ptp_handler                        ,0xffa72c80) //121
NHSTUB(apex2us                                ,0xffa35054) //121
NHSTUB(close                                  ,0xff81ab8c) //109
NHSTUB(err_init_task                          ,0xff815fd4) //111
NHSTUB(exmem_alloc                            ,0xff890988) //103
NHSTUB(exmem_free                             ,0xff890a00) //103
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
NHSTUB(memset                                 ,0xffa34050) //120
NHSTUB(mkdir                                  ,0xff8384fc) //109
NHSTUB(mktime_ext                             ,0xff8b5d68) //  1
NHSTUB(open                                   ,0xff81aadc) //109
NHSTUB(OpenFastDir                            ,0xffab917c) //  4
NHSTUB(closedir                               ,0xffab912c) //121
NHSTUB(get_fstype                             ,0xff87586c) //122
NHSTUB(qsort                                  ,0xffb2e3d8) //  4
NHSTUB(rand                                   ,0xffa34190) //121
NHSTUB(realloc                                ,0xffa340cc) //115
NHSTUB(reboot_fw_update                       ,0xffabe6f0) //106
NHSTUB(set_control_event                      ,0xff89c084) //111
NHSTUB(srand                                  ,0xffa34184) //122
NHSTUB(stat                                   ,0xff8381c4) //109
NHSTUB(strcat                                 ,0xff8b5524) //  1
NHSTUB(strchr                                 ,0xff8140b4) //  1
NHSTUB(strcmp                                 ,0xff82070c) //120
NHSTUB(strcpy                                 ,0xff8206f4) //120
NHSTUB(strftime                               ,0xff8b5770) //113
NHSTUB(strlen                                 ,0xff814100) //120
NHSTUB(strncmp                                ,0xff814068) //  1
NHSTUB(strncpy                                ,0xff81402c) //  1
NHSTUB(strrchr                                ,0xff8140d8) //  1
NHSTUB(strtol                                 ,0xff8413ec) //101
NHSTUB(strtolx                                ,0xff8411f0) //109
   DEF(task_CaptSeq                           ,0xff8836d0) //120
   DEF(task_DvlpSeqTask                       ,0xff884e38) //120
   DEF(task_ExpDrv                            ,0xff8ccb28) //120
   DEF(task_FileWrite                         ,0xffab71a4) //120
   DEF(task_InitFileModules                   ,0xff8a0254) //120
   DEF(task_MovieRecord                       ,0xff9867f8) //120
   DEF(task_PhySw                             ,0xff834754) //120
   DEF(task_RotaryEncoder                     ,0xff863668) //120
NHSTUB(time                                   ,0xff89001c) //109
NHSTUB(vsprintf                               ,0xff8206b8) //115
NHSTUB(EngDrvRead                             ,0xff835a5c) //102
NHSTUB(PTM_GetCurrentItem                     ,0xff89d0a4) //105
NHSTUB(DisableISDriveError                    ,0xffae24d8) //120
NHSTUB(CancelHPTimer                          ,0xff89183c) //119
NHSTUB(SetHPTimerAfterNow                     ,0xff891734) //119
NHSTUB(PT_MFOn                                ,0xff880bb0) //120
NHSTUB(PT_MFOff                               ,0xff880bc0) //120
NHSTUB(GetAdChValue                           ,0xff85ee60) //120
NHSTUB(EnableHDMIPower                        ,0xff861f38) //123
NHSTUB(DisableHDMIPower                       ,0xff861f40) //123
NHSTUB(get_ptp_buf_size                       ,0xff912594) //122
NHSTUB(get_ptp_file_buf                       ,0xffa746a8) //121
