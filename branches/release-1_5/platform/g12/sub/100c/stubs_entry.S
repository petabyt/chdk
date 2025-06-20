// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R45 (DRYOS version 2.3, release #0045)
//   Firmware Ver GM1.00C   // Found @ 0xff894554, "GM1.00C" @ 0xff894561
//   Firmware build timestamp: Aug  3 2010 15:53:15
//   Canon PowerShot G12

// Values for makefile.inc
//   DIGIC = 40# DIGIC 4
//   PLATFORMOSVER = 45
//   PLATFORMID = 12815# (0x320f) Found @ 0xfffe0130
//   MAXRAMADDR = 0x07ffffff
//   MEMISOSTART = 0x0016e820
//   KEYSYS = d4b# Found @ 0xffff36ac
//   NEED_ENCODED_DISKBOOT = 5# Found @ 0xffff36bc
//   ARAM_HEAP_START = 0x3ce000# Found @ 0xff9966d8
//   ARAM_HEAP_SIZE  = 0x32000# Found @ 0xff996698

// Detected address ranges:
// ROM      0xff810000 - 0xffffffff (8323072 bytes)
// RAM data 0x00001900 - 0x00010798 copied from 0xffcb1c20 (  61080 bytes)

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ffb1ec88 -> ffc89550
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00034474) // Found @0xff8349f4
DEF(physw_run                               ,0x00001c3c) // Found @0xff8345f0
DEF(physw_sleep_delay                       ,0x00001c44) // Found @0xff8345f0
DEF(levent_table                            ,0xffc0be90) // Found @0xffc0be90
DEF(FlashParamsTable                        ,0xffc89760) // Found @0xffc89760
DEF(movie_status                            ,0x000072d4) // Found @0xff986d94
DEF(video_compression_rate                  ,0x00007314) // Found @0xff986fe8
DEF(full_screen_refresh                     ,0x0000a5dc) // Found @0xffa53ca8
DEF(canon_menu_active                       ,0x00003214) // Found @0xff896098
DEF(canon_shoot_menu_active                 ,0x00008afd) // Found @0xff9dc72c
DEF(playrec_mode                            ,0x00002f38) // Found @0xff8880fc
DEF(zoom_status                             ,0x0000e590) // Found @0xffb22750
DEF(some_flag_for_af_scan                   ,0x000076b4) // Found @0xff98a808
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 3 int value(s), the first is the zoom focus length.
// there are 14 entries in the table - set NUM_FL to 14
DEF(focus_len_table                         ,0xfffe2a80) // Found @0xfffe2a80
DEF(zoom_busy                               ,0x000071e8) // Found @0xff98166c
DEF(focus_busy                              ,0x000070c0) // Found @0xff97d6c8
DEF(recreview_hold                          ,0x00003f50) // Found @0xff8a8134
// Palette colour tables  found @ 0xffc2c654
DEF(palette_control                         ,0x0000a5dc) // Found @0xffa53c24
DEF(active_palette_buffer                   ,0x0000a5e4) // Found @0xffa53c28
DEF(palette_buffer_ptr                      ,0x0000a5e8) // Found @0xffa5414c
DEF(palette_buffer                          ,0x000bbf5c) // Found @0xffa5415c
// Offset from start of palette_buffer to color data = 8 (Found @0xffb5b2dc)
DEF(bitmap_buffer                           ,0x0000a618) // Found @0xffa57bb4
DEF(active_bitmap_buffer                    ,0x0000a610) // Found @0xffa57bb8
DEF(viewport_buffers                        ,0xffbb822c) // Found @0xff851f24
DEF(active_viewport_buffer                  ,0x000020ac) // Found @0xff851cf0
// Camera has 2 RAW buffers @ 0x41269150 & 0x46000000
//  Note: active buffer --> raw_buffers[ active_raw_buffer   *3]
//        other buffer  --> raw_buffers[(active_raw_buffer^1)*3]
DEF(raw_buffers                             ,0xffbbad74) // Found @0xffbbad74
DEF(active_raw_buffer                       ,0x00002e94) // Found @0xff8842ac
DEF(fileio_semaphore                        ,0x00002bbc) // Found @0xff874df8
DEF(exmem_alloc_table                       ,0x0003bfc8) // Found @0xff88f9d0
DEF(exmem_types_table                       ,0xffcb3380) // Found @0x00003060
DEF_CONST(exmem_type_count                  ,0x00000013)
DEF(imager_active                           ,0x00001ff0) // Found @0xff84ebc0 (0x1fec + 4)
DEF_CONST(uiprop_count                      ,0x00000072) // Found @0xff9be134

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x40471000; }             // Found @0xff85ea60
//void *vid_get_viewport_fb()      { return (void*)0x40587700; }             // Found @0xffb75568
DEF(viewport_fb_d                           ,0x00002c68) // Found 0x2c10 (@0xff8781ac) + 0x58 (@0xff8781e4)
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x2c10+0x58)); } // Found @0xff8781ac & 0xff8781e4
DEF(jpeg_count_str                          ,0x000bb618) // Found @0xffa43608
//char *camera_jpeg_count_str()    { return (char*)0x000bb618; }             // Found @0xffa43608
//int get_flash_params_count(void) { return 0x9a; }                          // Found @0xff9bed20

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffbb9448, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x04000000 // Found @0xffbb9478, levent 0x902
//#define USB_IDX             2
//#define BATTCOVER_FLAG      0x00008000 // Found @0xffbb9438, levent 0x905
//#define BATTCOVER_IDX       2
//#define HOTSHOE_FLAG        0x01000000 // Found @0xffbb9468, levent 0x904
//#define HOTSHOE_IDX         2
//#define ANALOG_AV_FLAG      0x02000000 // Found @0xffbb9470, levent 0x900 (non-inverted logic)
//#define ANALOG_AV_IDX       2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_ZOOM_IN         ,0x00000020 }, // Found @0xffbb9350, levent 0x02
//    { 0, KEY_ZOOM_OUT        ,0x00000800 }, // Found @0xffbb9380, levent 0x03
//    { 0, KEY_LEFT            ,0x00001000 }, // Found @0xffbb9388, levent 0x06
//    { 0, KEY_SET             ,0x00002000 }, // Found @0xffbb9390, levent 0x08
//    { 0, KEY_RIGHT           ,0x00004000 }, // Found @0xffbb9398, levent 0x07
//    { 0, KEY_DOWN            ,0x00008000 }, // Found @0xffbb93a0, levent 0x05
//    { 0, KEY_UP              ,0x00010000 }, // Found @0xffbb93a8, levent 0x04
//    { 0, KEY_DISPLAY         ,0x00100000 }, // Found @0xffbb93c0, levent 0x0a
//    { 0, KEY_MENU            ,0x00200000 }, // Found @0xffbb93c8, levent 0x09
//    { 2, KEY_SHOOT_FULL      ,0x00000003 }, // Found @0xffbb9420, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000002 }, // Found @0xffbb9420, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00000001 }, // Found @0xffbb9418, levent 0x00
//    { 2, KEY_POWER           ,0x00000004 }, // Found @0xffbb9428, levent 0x600 (uses inverted logic in physw_status)
//    { 2, KEY_PLAYBACK        ,0x00000008 }, // Found @0xffbb9430, levent 0x601 (uses inverted logic in physw_status)
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_RAW_ROWPIX    3744 // Found @0xff9579d0
//#define CAM_RAW_ROWS      2784 // Found @0xff9579d8
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff83af74
//#define CAM_DATE_FOLDER_NAMING 0x400 // Found @0xffacdab4 (pass as 3rd param to GetImageFolder)
//#define PARAM_CAMERA_NAME 4 // Found @0xffc8c38c

// Below goes in 'filewrite.c' or 'platform_camera.h':
//#define MAX_CHUNKS_FOR_FWT 7 // Found @0xffae0b3c

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
DEF(ctypes, 0xffbb7b42)

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

// LED table init @ 0xff9337d0
// LED #1: 0xc0223030, offset 0x1d8
// LED #2: 0xc022012c, offset 0x2dc
// LED #3: 0xc0220128, offset 0x310
// LED #4: 0xc0220138, offset 0x6c
// LED #5: 0xc0220124, offset 0xa0
// LED #6: 0xc0220134, offset 0x4
// LED #7: 0xc0220130, offset 0x38

// For capt_seq.c
DEF(_nrflag,0x7704) // Found @ ff98fadc (0x76fc) & ff98fb10 (+0x08)
//static long *nrflag = (long*)(0x76fc+0x08);  // Found @ ff98fadc & ff98fb10
//#define NR_AUTO (0)                          // have to explictly reset value back to 0 to enable auto

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NHSTUB(AllocateUncacheableMemory              ,0xff83af30) //112
NHSTUB(Close                                  ,0xff8370e0) //120
NHSTUB(CreateBinarySemaphore                  ,0xff83a710) //115
NHSTUB(CreateTask                             ,0xff81e8a0) //120
NHSTUB(DebugAssert                            ,0xff81eb78) //107
NHSTUB(DeleteDirectory_Fut                    ,0xff836b3c) //116
NHSTUB(DeleteFile_Fut                         ,0xff836a58) //112
NHSTUB(DoAELock                               ,0xff838dc8) //120
NHSTUB(DoAFLock                               ,0xff838940) //120
NHSTUB(EnterToCompensationEVF                 ,0xff838d24) //104
NHSTUB(ExecuteEventProcedure                  ,0xff8917a4) //104
NHSTUB(ExitFromCompensationEVF                ,0xff838d68) //104
NHSTUB(ExitTask                               ,0xff81eb30) //120
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff847454) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff8475ec) //104
NHSTUB(Fclose_Fut                             ,0xff836bd4) //120
NHSTUB(Feof_Fut                               ,0xff836dc0) //  1
NHSTUB(Fflush_Fut                             ,0xff836dfc) //  1
NHSTUB(Fgets_Fut                              ,0xff836d28) //  1
NHSTUB(Fopen_Fut                              ,0xff836b94) //120
NHSTUB(Fread_Fut                              ,0xff836c80) //120
NHSTUB(FreeUncacheableMemory                  ,0xff83af70) //112
NHSTUB(Fseek_Fut                              ,0xff836d74) //120
NHSTUB(Fwrite_Fut                             ,0xff836cd4) //120
NHSTUB(GetBatteryTemperature                  ,0xff868f80) //102
NHSTUB(GetCCDTemperature                      ,0xff868f0c) //102
NHSTUB(GetCurrentAvValue                      ,0xff97fcb8) //120
NHSTUB(GetCurrentShutterSpeed                 ,0xff8ba0b0) //120
NHSTUB(GetUsableMaxAv                         ,0xffb6fc4c) //120
NHSTUB(GetUsableMinAv                         ,0xffb6fc34) //120
NHSTUB(GetDrive_ClusterSize                   ,0xff876948) //122
NHSTUB(GetDrive_FreeClusters                  ,0xff8769a8) //119
NHSTUB(GetDrive_TotalClusters                 ,0xff87697c) //119
NHSTUB(GetFocusLensSubjectDistance            ,0xff97e348) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff97e794) //  3
NHSTUB(GetImageFolder                         ,0xff95f2fc) //122
NHSTUB(GetKbdState                            ,0xff865678) //109
NHSTUB(GetMemInfo                             ,0xff81a264) //115
NHSTUB(GetOpticalTemperature                  ,0xff868ff4) //120
NHSTUB(GetParameterData                       ,0xff9bece4) //101
NHSTUB(GetPropertyCase                        ,0xff8954f0) //102
NHSTUB(GetSystemTime                          ,0xffb08d38) //120
NHSTUB(GetVRAMHPixelsSize                     ,0xff854320) //120
NHSTUB(GetVRAMVPixelsSize                     ,0xff85432c) //120
NHSTUB(GetZoomLensCurrentPoint                ,0xff9819e0) //120
NHSTUB(GetZoomLensCurrentPosition             ,0xffaf6874) //102
NHSTUB(GiveSemaphore                          ,0xff83a94c) //120
NHSTUB(IsStrobeChargeCompleted                ,0xff8ea5f0) //102
NHSTUB(LEDDrive                               ,0xff8647ec) //120
NHSTUB(LocalTime                              ,0xff88f08c) //115
NHSTUB(LockMainPower                          ,0xff89c204) //120
NHSTUB(MakeDirectory_Fut                      ,0xff836acc) //116
NHSTUB(MoveFocusLensToDistance                ,0xffb71f98) //102
NHSTUB(MoveIrisWithAv                         ,0xffb04878) //120
NHSTUB(MoveZoomLensWithPoint                  ,0xffb05008) //120
NHSTUB(MoveOpticalZoomAt                      ,0xff8382cc) //109
NHSTUB(Open                                   ,0xff837074) //120
NHSTUB(PB2Rec                                 ,0xff89f18c) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff87f5c0) //120
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff87f598) //120
NHSTUB(PT_PlaySound                           ,0xff88a140) //122
NHSTUB(PostLogicalEventForNotPowerType        ,0xff899b70) //120
NHSTUB(PostLogicalEventToUI                   ,0xff899bbc) //120
NHSTUB(PutInNdFilter                          ,0xffb04e6c) //102
NHSTUB(PutOutNdFilter                         ,0xffb04e90) //102
NHSTUB(Read                                   ,0xff81ad74) //120
NHSTUB(ReadFastDir                            ,0xffae2c14) //  4
NHSTUB(Rec2PB                                 ,0xff89f1cc) //104
NHSTUB(RefreshPhysicalScreen                  ,0xff8b3a68) //104
NHSTUB(RenameFile_Fut                         ,0xff8369c4) //116
NHSTUB(Restart                                ,0xff83c71c) //122
NHSTUB(ScreenLock                             ,0xff8b4c98) //117
NHSTUB(ScreenUnlock                           ,0xff8b4cfc) //117
NHSTUB(SetAE_ShutterSpeed                     ,0xffb746e0) //102
NHSTUB(SetAutoShutdownTime                    ,0xff89c278) //120
NHSTUB(SetCurrentCaptureModeType              ,0xff8a4d44) //120
NHSTUB(SetDate                                ,0xffb761c4) //120
NHSTUB(SetFileAttributes                      ,0xff8373d8) //  3
NHSTUB(SetFileTimeStamp                       ,0xff83737c) //  4
NHSTUB(SetLogicalEventActive                  ,0xff89bf40) //120
NHSTUB(SetParameterData                       ,0xff9bebbc) //101
NHSTUB(SetPropertyCase                        ,0xff8953c8) //102
NHSTUB(SetScriptMode                          ,0xff89bf90) //120
NHSTUB(SleepTask                              ,0xff83abb4) //120
NHSTUB(TakeSemaphore                          ,0xff83a87c) //120
NHSTUB(TurnOffBackLight                       ,0xff8abd94) //104
NHSTUB(TurnOnBackLight                        ,0xff8abd7c) //104
NHSTUB(TurnOnDisplay                          ,0xff85edb0) //120
NHSTUB(TurnOffDisplay                         ,0xff85edc0) //120
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff9a9e90) //120
NHSTUB(UnlockAE                               ,0xff838dec) //120
NHSTUB(UnlockAF                               ,0xff838978) //120
NHSTUB(UnlockMainPower                        ,0xff89c158) //120
NHSTUB(UnsetZoomForMovie                      ,0xff9c57d0) //104
NHSTUB(UpdateMBROnFlash                       ,0xff8767c8) //105
NHSTUB(VbattGet                               ,0xff833180) //120
NHSTUB(Write                                  ,0xff837170) //120
NHSTUB(WriteSDCard                            ,0xff96e820) //108
NHSTUB(_log                                   ,0xffbb4c50) //111
NHSTUB(_log10                                 ,0xffbb38dc) //112
NHSTUB(_pow                                   ,0xffbb3a4c) //121
NHSTUB(_sqrt                                  ,0xffbb6858) //  1
NHSTUB(add_ptp_handler                        ,0xffa9d20c) //121
NHSTUB(apex2us                                ,0xffa5c23c) //121
NHSTUB(close                                  ,0xff81ab8c) //109
NHSTUB(err_init_task                          ,0xff815fd4) //111
NHSTUB(exmem_alloc                            ,0xff88ffd8) //103
NHSTUB(exmem_ualloc                           ,0xff88fe28) //103
NHSTUB(exmem_ufree                            ,0xff88ff78) //103
NHSTUB(free                                   ,0xff814244) //112
NHSTUB(get_nd_value                           ,0xffaf47e0) //122
NHSTUB(get_current_nd_value                   ,0xffaf47b0) //122
NHSTUB(kbd_p1_f                               ,0xff834a6c) //109
NHSTUB(kbd_p1_f_cont                          ,0xff834a78) //109
NHSTUB(kbd_p2_f                               ,0xff8342bc) //109
NHSTUB(kbd_read_keys                          ,0xff8349f4) //109
NHSTUB(kbd_read_keys_r2                       ,0xff864d8c) //109
NHSTUB(lseek                                  ,0xff8371fc) //120
NHSTUB(malloc                                 ,0xff8141e8) //112
NHSTUB(memcmp                                 ,0xff8206d8) //120
NHSTUB(memcpy                                 ,0xff840674) //120
NHSTUB(memset                                 ,0xffa5b224) //120
NHSTUB(mkdir                                  ,0xff83757c) //109
NHSTUB(mktime_ext                             ,0xff8b5b6c) //  1
NHSTUB(open                                   ,0xff81aadc) //109
NHSTUB(OpenFastDir                            ,0xffae2ac0) //  4
NHSTUB(closedir                               ,0xffae2a70) //121
NHSTUB(get_fstype                             ,0xff8769cc) //122
NHSTUB(qsort                                  ,0xffb5fa2c) //  4
NHSTUB(rand                                   ,0xffa5b364) //121
NHSTUB(realloc                                ,0xffa5b2a0) //115
NHSTUB(reboot_fw_update                       ,0xffae8034) //106
NHSTUB(set_control_event                      ,0xff89bb30) //111
NHSTUB(srand                                  ,0xffa5b358) //122
NHSTUB(stat                                   ,0xff837244) //109
NHSTUB(strcat                                 ,0xff8b5328) //  1
NHSTUB(strchr                                 ,0xff8140b4) //  1
NHSTUB(strcmp                                 ,0xff820694) //120
NHSTUB(strcpy                                 ,0xff82067c) //120
NHSTUB(strftime                               ,0xff8b5574) //113
NHSTUB(strlen                                 ,0xff814100) //120
NHSTUB(strncmp                                ,0xff814068) //  1
NHSTUB(strncpy                                ,0xff81402c) //  1
NHSTUB(strrchr                                ,0xff8140d8) //  1
NHSTUB(strtol                                 ,0xff840954) //101
NHSTUB(strtolx                                ,0xff840758) //109
   DEF(task_CaptSeq                           ,0xff88261c) //120
   DEF(task_DvlpSeqTask                       ,0xff883e7c) //120
   DEF(task_ExpDrv                            ,0xff8cc0d0) //120
   DEF(task_FileWrite                         ,0xffae0ae4) //120
   DEF(task_InitFileModules                   ,0xff89fc7c) //120
   DEF(task_MovieRecord                       ,0xff987088) //120
   DEF(task_PhySw                             ,0xff8345ec) //120
   DEF(task_RotaryEncoder                     ,0xff8657ec) //120
NHSTUB(time                                   ,0xff88f66c) //109
NHSTUB(vsprintf                               ,0xff820640) //115
NHSTUB(EngDrvRead                             ,0xff8358c4) //102
NHSTUB(PTM_GetCurrentItem                     ,0xff89cb70) //105
NHSTUB(DisableISDriveError                    ,0xffb05850) //120
NHSTUB(CancelHPTimer                          ,0xff890e8c) //119
NHSTUB(SetHPTimerAfterNow                     ,0xff890d84) //119
NHSTUB(PT_MFOn                                ,0xff87f650) //120
NHSTUB(PT_MFOff                               ,0xff87f660) //120
NHSTUB(GetAdChValue                           ,0xff860500) //120
NHSTUB(EnableHDMIPower                        ,0xff8642d8) //123
NHSTUB(DisableHDMIPower                       ,0xff8642e0) //123
NHSTUB(get_ptp_buf_size                       ,0xff918490) //122
NHSTUB(get_ptp_file_buf                       ,0xffa9ec34) //121
NHSTUB(SetVideoOutType                        ,0xffb74f00) //109
NHSTUB(GetVideoOutType                        ,0xffb74e30) //120
