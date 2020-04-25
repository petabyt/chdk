// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R31 (DRYOS version 2.3, release #0031)
//   Firmware Ver GM1.00A   // Found @ 0xff86ed90, "GM1.00A" @ 0xff86ed9d
//   Firmware build timestamp: Jan 29 2009 13:03:40
//   Canon DIGITAL IXUS 990 IS

// Values for makefile.inc
//   DIGIC = 40# DIGIC 4
//   PLATFORMOSVER = 31
//   PLATFORMID = 12737# (0x31c1) Found @ 0xfffe0130
//   MAXRAMADDR = 0x03ffffff
//   MEMISOSTART = 0x001487c4
//   KEYSYS = d4# Found @ 0xffff3564
//   NEED_ENCODED_DISKBOOT = 2# Found @ 0xffff3574
//   ARAM_HEAP_START = 0x34e000# Found @ 0xff92e398
//   ARAM_HEAP_SIZE  = 0x32000# Found @ 0xff92e358

// Detected address ranges:
// ROM      0xff810000 - 0xffffffff (8323072 bytes)
// RAM data 0x00001900 - 0x0000d974 copied from 0xffb84e78 (  49268 bytes)

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
NHSTUB(kbd_pwr_off                            ,0xff843f84) //  2 64%

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ffa63a3c -> ffb60ae0
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x0000edf8) // Found @0xff821dcc
DEF(physw_run                               ,0x00001c34) // Found @0xff821a3c
DEF(physw_sleep_delay                       ,0x00001c32) // Found @0xff821a3c
DEF(levent_table                            ,0xffb2f2e8) // Found @0xffb2f2e8
DEF(FlashParamsTable                        ,0xffb60cbc) // Found @0xffb60cbc
DEF(movie_status                            ,0x00006000) // Found @0xff920ecc
DEF(video_compression_rate                  ,0x0000602c) // Found @0xff92108c
DEF(canon_menu_active                       ,0x00002d18) // Found @0xff8707f8
DEF(canon_shoot_menu_active                 ,0x00007259) // Found @0xff95e964
DEF(playrec_mode                            ,0x00002a80) // Found @0xff863b70
DEF(zoom_status                             ,0x0000b534) // Found @0xffa65e2c
DEF(some_flag_for_af_scan                   ,0x0000653c) // Found @0xff924104
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 3 int value(s), the first is the zoom focus length.
// there are 12 entries in the table - set NUM_FL to 12
DEF(focus_len_table                         ,0xfffe2a8c) // Found @0xfffe2a8c
DEF(zoom_busy                               ,0x00005f30) // Found @0xff91d070
DEF(focus_busy                              ,0x00005e28) // Found @0xff917ee0
//DEF(recreview_hold                          ,0x000036ec) // Found @0xff881920, ** != ** stubs_min = 0x00000001 (1)
// Palette colour tables  found @ 0xffb482cc
DEF(active_palette_buffer                   ,0x00008670) // Found @0xff9b2dcc
DEF(palette_buffer_ptr                      ,0x00008680) // Found @0xff9b2a90
// Offset from start of palette_buffer to color data = 12 (Found @0xff9b1a3c)
// Camera appears to have only 1 RAW buffer @ 0x41ec0600 (Found @0xffabcbe8)
DEF(fileio_semaphore                        ,0x00002720) // Found @0xff851e6c
DEF(exmem_alloc_table                       ,0x000155b4) // Found @0xff86a1ec
DEF(exmem_types_table                       ,0xffb860e0) // Found @0x00002b68
DEF_CONST(exmem_type_count                  ,0x00000012)
DEF(imager_active                           ,0x00001ec0) // Found @0xff832f2c (0x1ebc + 4)
DEF_CONST(uiprop_count                      ,0x0000006b) // Found @0xff94c444

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x403f1000; }             // Found @0xff83db4c
//void *vid_get_viewport_fb()      { return (void*)0x4126f570; }             // Found @0xffaba6cc
DEF(viewport_fb_d                           ,0x000027ac) // Found 0x2754 (@0xff85505c) + 0x58 (@0xff855094)
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x2754+0x58)); } // Found @0xff85505c & 0xff855094
DEF(jpeg_count_str                          ,0x000345e0) // Found @0xff9a6de8
//char *camera_jpeg_count_str()    { return (char*)0x000345e0; }             // Found @0xff9a6de8
//int get_flash_params_count(void) { return 0x7a; }                          // Found @0xff94ce88

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffaf1330, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x00080000 // Found @0xffaf1348, levent 0x902
//#define USB_IDX             2
//#define BATTCOVER_FLAG      0x00008000 // Found @0xffaf1318, levent 0x905
//#define BATTCOVER_IDX       2
//#define ANALOG_AV_FLAG      0x00040000 // Found @0xffaf133c, levent 0x900 (non-inverted logic)
//#define ANALOG_AV_IDX       2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_SET             ,0x00000004 }, // Found @0xffaf1264, levent 0x08
//    { 0, KEY_DISPLAY         ,0x00000008 }, // Found @0xffaf1270, levent 0x0a
//    { 2, KEY_MENU            ,0x00000001 }, // Found @0xffaf1288, levent 0x09
//    { 2, KEY_ZOOM_IN         ,0x00000004 }, // Found @0xffaf12a0, levent 0x02
//    { 2, KEY_ZOOM_OUT        ,0x00000008 }, // Found @0xffaf12ac, levent 0x03
//    { 2, KEY_LEFT            ,0x00000010 }, // Found @0xffaf12b8, levent 0x06
//    { 2, KEY_RIGHT           ,0x00000020 }, // Found @0xffaf12c4, levent 0x07
//    { 2, KEY_DOWN            ,0x00000040 }, // Found @0xffaf12d0, levent 0x05
//    { 2, KEY_UP              ,0x00000080 }, // Found @0xffaf12dc, levent 0x04
//    { 2, KEY_SHOOT_FULL      ,0x00000300 }, // Found @0xffaf12f4, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000200 }, // Found @0xffaf12f4, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00000100 }, // Found @0xffaf12e8, levent 0x00
//    { 2, KEY_POWER           ,0x00000400 }, // Found @0xffaf1300, levent 0x600
//    { 2, KEY_PLAYBACK        ,0x00000800 }, // Found @0xffaf130c, levent 0x601
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_RAW_ROWPIX    4080 // Found @0xff8eb9cc
//#define CAM_RAW_ROWS      3048 // Found @0xff8eb9d0
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff8274e8
//#define PARAM_CAMERA_NAME 4 // Found @0xffb62f78

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
DEF(ctypes, 0xffaf0092)

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
// pointer to TCB area: 0x19ec, found @ 0xff81574c

// LED table init @ 0xff8d03f0
// LED #1: 0xc0220138, offset 0x204
// LED #2: 0xc0220130, offset 0x4
// LED #3: 0xc0220134, offset 0x44

// For capt_seq.c
DEF(_nrflag,0x6518) // Found @ ff9260ac (0x6520) & ff9260cc (-0x08)
//static long *nrflag = (long*)(0x6520-0x08);  // Found @ ff9260ac & ff9260c8

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NHSTUB(AllocateUncacheableMemory              ,0xff8274a4) //112
NHSTUB(Close                                  ,0xff823c98) //120
NHSTUB(CreateBinarySemaphore                  ,0xff826c84) //115
NHSTUB(CreateTask                             ,0xff81afac) //120
NHSTUB(DebugAssert                            ,0xff81b284) //107
NHSTUB(DeleteDirectory_Fut                    ,0xff823628) //116
NHSTUB(DeleteFile_Fut                         ,0xff823544) //112
NHSTUB(DoAELock                               ,0xff82556c) //120
NHSTUB(DoAFLock                               ,0xff825380) //120
NHSTUB(EnterToCompensationEVF                 ,0xff82546c) //104
NHSTUB(ExecuteEventProcedure                  ,0xff86bf38) //104
NHSTUB(ExitFromCompensationEVF                ,0xff8254b0) //104
NHSTUB(ExitTask                               ,0xff81b23c) //120
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff830008) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff83014c) //104
NHSTUB(Fclose_Fut                             ,0xff8236c0) //120
NHSTUB(Feof_Fut                               ,0xff8238ac) //  1
NHSTUB(Fflush_Fut                             ,0xff8238e8) //  1
NHSTUB(Fgets_Fut                              ,0xff823814) //  1
NHSTUB(Fopen_Fut                              ,0xff823680) //120
NHSTUB(Fread_Fut                              ,0xff82376c) //120
NHSTUB(FreeUncacheableMemory                  ,0xff8274e4) //112
NHSTUB(Fseek_Fut                              ,0xff823860) //120
NHSTUB(Fwrite_Fut                             ,0xff8237c0) //120
NHSTUB(GetBatteryTemperature                  ,0xff8472b8) //102
NHSTUB(GetCCDTemperature                      ,0xff847244) //102
NHSTUB(GetCurrentAvValue                      ,0xff919c98) //120
NHSTUB(GetCurrentShutterSpeed                 ,0xff88cfa4) //120
NHSTUB(GetDrive_ClusterSize                   ,0xff853790) //  5
NHSTUB(GetDrive_FreeClusters                  ,0xff8537e8) //  5
NHSTUB(GetDrive_TotalClusters                 ,0xff8537bc) //  5
NHSTUB(GetFocusLensSubjectDistance            ,0xff918d48) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff919124) //  3
NHSTUB(GetKbdState                            ,0xff843f6c) //109
NHSTUB(GetMemInfo                             ,0xff813be4) //115
NHSTUB(GetOpticalTemperature                  ,0xff84732c) //120
NHSTUB(GetParameterData                       ,0xff94ce48) //101
NHSTUB(GetPropertyCase                        ,0xff86fca4) //102
NHSTUB(GetSystemTime                          ,0xffa57f08) //120
NHSTUB(GetVRAMHPixelsSize                     ,0xff8b67c8) //120
NHSTUB(GetVRAMVPixelsSize                     ,0xff8b67d4) //120
NHSTUB(GetZoomLensCurrentPoint                ,0xff91d3e4) //120
NHSTUB(GetZoomLensCurrentPosition             ,0xffa4b6e8) //102
NHSTUB(GiveSemaphore                          ,0xff826ec0) //120
NHSTUB(IsStrobeChargeCompleted                ,0xff8a7748) //102
NHSTUB(LEDDrive                               ,0xff843460) //120
NHSTUB(LocalTime                              ,0xff869928) //115
NHSTUB(LockMainPower                          ,0xff87769c) //120
NHSTUB(MakeDirectory_Fut                      ,0xff8235b8) //116
NHSTUB(MoveFocusLensToDistance                ,0xffab7064) //102
NHSTUB(MoveIrisWithAv                         ,0xffa5600c) //120
NHSTUB(MoveZoomLensWithPoint                  ,0xffa56594) //120
NHSTUB(MoveOpticalZoomAt                      ,0xff824edc) //109
NHSTUB(Open                                   ,0xff823c70) //120
NHSTUB(PB2Rec                                 ,0xff87a684) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff85ca34) //120
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff85ca0c) //120
NHSTUB(PT_PlaySound                           ,0xff85c610) //102
NHSTUB(PostLogicalEventForNotPowerType        ,0xff8753c4) //120
NHSTUB(PostLogicalEventToUI                   ,0xff875410) //120
NHSTUB(PutInNdFilter                          ,0xffa563f8) //102
NHSTUB(PutOutNdFilter                         ,0xffa5641c) //102
NHSTUB(Read                                   ,0xff819ae4) //120
NHSTUB(ReadFastDir                            ,0xffa37da8) //  1
NHSTUB(Rec2PB                                 ,0xff87a6c4) //104
NHSTUB(RefreshPhysicalScreen                  ,0xff9b7dc8) //104
NHSTUB(RenameFile_Fut                         ,0xff8234f0) //  1
NHSTUB(Restart                                ,0xff828bf4) //122
NHSTUB(SetAE_ShutterSpeed                     ,0xffab9844) //102
NHSTUB(SetAutoShutdownTime                    ,0xff877710) //120
NHSTUB(SetCurrentCaptureModeType              ,0xff87eda0) //120
NHSTUB(SetFileAttributes                      ,0xff823fc4) //  1
NHSTUB(SetFileTimeStamp                       ,0xff823f74) //  1
NHSTUB(SetLogicalEventActive                  ,0xff8773ec) //120
NHSTUB(SetParameterData                       ,0xff94cdb8) //101
NHSTUB(SetPropertyCase                        ,0xff86fb9c) //102
NHSTUB(SetScriptMode                          ,0xff87743c) //120
NHSTUB(SleepTask                              ,0xff827128) //120
NHSTUB(TakeSemaphore                          ,0xff826df0) //120
NHSTUB(TurnOffBackLight                       ,0xff88524c) //104
NHSTUB(TurnOnBackLight                        ,0xff885234) //104
NHSTUB(TurnOnDisplay                          ,0xff83dc2c) //120
NHSTUB(TurnOffDisplay                         ,0xff83dc3c) //120
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff93911c) //120
NHSTUB(UnlockAE                               ,0xff825590) //120
NHSTUB(UnlockAF                               ,0xff8253b8) //120
NHSTUB(UnlockMainPower                        ,0xff8775f0) //120
NHSTUB(UnsetZoomForMovie                      ,0xff952fbc) //104
NHSTUB(UpdateMBROnFlash                       ,0xff8535e8) //105
NHSTUB(VbattGet                               ,0xff820654) //120
NHSTUB(Write                                  ,0xff823d44) //120
NHSTUB(WriteSDCard                            ,0xff90a2a8) //108
NHSTUB(_log                                   ,0xffaed328) //111
NHSTUB(_log10                                 ,0xffaebfb4) //112
NHSTUB(_pow                                   ,0xffaec124) //121
NHSTUB(_sqrt                                  ,0xffaeeecc) //  1
NHSTUB(add_ptp_handler                        ,0xffa02464) //121
NHSTUB(apex2us                                ,0xff9bafbc) //121
NHSTUB(close                                  ,0xff8198fc) //109
NHSTUB(err_init_task                          ,0xff814e2c) //111
NHSTUB(exmem_alloc                            ,0xff86a7e8) //103
NHSTUB(exmem_free                             ,0xff86a860) //103
NHSTUB(free                                   ,0xff813a3c) //112
NHSTUB(get_nd_value                           ,0xffa490a4) //123
NHSTUB(get_current_nd_value                   ,0xffa49060) //122
NHSTUB(kbd_p1_f                               ,0xff821e48) //109
NHSTUB(kbd_p1_f_cont                          ,0xff821e54) //109
NHSTUB(kbd_p2_f                               ,0xff821708) //109
NHSTUB(kbd_read_keys                          ,0xff821dcc) //109
NHSTUB(kbd_read_keys_r2                       ,0xff843930) //109
NHSTUB(lseek                                  ,0xff823dd8) //120
NHSTUB(malloc                                 ,0xff813968) //112
NHSTUB(memcmp                                 ,0xff81cc6c) //120
NHSTUB(memcpy                                 ,0xff88bb4c) //120
NHSTUB(memset                                 ,0xff9ba2a4) //120
NHSTUB(mkdir                                  ,0xff82403c) //109
NHSTUB(mktime_ext                             ,0xff88c3b8) //  1
NHSTUB(open                                   ,0xff81984c) //109
NHSTUB(OpenFastDir                            ,0xffa37d14) //  1
NHSTUB(closedir                               ,0xffa37e78) //  1
NHSTUB(qsort                                  ,0xffa9c834) //  1
NHSTUB(rand                                   ,0xff81cd74) //121
NHSTUB(realloc                                ,0xff813b1c) //115
NHSTUB(reboot_fw_update                       ,0xffa3f458) //106
NHSTUB(set_control_event                      ,0xff877050) //111
NHSTUB(srand                                  ,0xff81cd68) //122
NHSTUB(stat                                   ,0xff823ea4) //  1
NHSTUB(strcat                                 ,0xff88b960) //  1
NHSTUB(strchr                                 ,0xff88b9e8) //  1
NHSTUB(strcmp                                 ,0xff81cc04) //120
NHSTUB(strcpy                                 ,0xff81cbec) //120
NHSTUB(strftime                               ,0xff88bdc0) //  1
NHSTUB(strlen                                 ,0xff81cc48) //120
NHSTUB(strncmp                                ,0xff88b99c) //  1
NHSTUB(strncpy                                ,0xff82ce04) //  1
NHSTUB(strrchr                                ,0xff9ba27c) //  1
NHSTUB(strtol                                 ,0xff82d03c) //101
NHSTUB(strtolx                                ,0xff82ce40) //109
   DEF(task_CaptSeq                           ,0xff85f074) //120
   DEF(task_DvlpSeqTask                       ,0xff860510) //120
   DEF(task_ExpDrv                            ,0xff89df1c) //120
   DEF(task_FileWrite                         ,0xffa338e8) //120
   DEF(task_InitFileModules                   ,0xff87b1a0) //120
   DEF(task_MovieRecord                       ,0xff921108) //120
   DEF(task_PhySw                             ,0xff821a38) //120
   DEF(task_RotaryEncoder                     ,0xff84405c) //120
NHSTUB(time                                   ,0xff869ea0) //109
NHSTUB(vsprintf                               ,0xff81cbb0) //115
NHSTUB(EngDrvRead                             ,0xff822c84) //102
NHSTUB(PTM_GetCurrentItem                     ,0xff8780b0) //105
NHSTUB(CancelHPTimer                          ,0xff86b620) //119
NHSTUB(SetHPTimerAfterNow                     ,0xff86b518) //119
NHSTUB(PT_MFOn                                ,0xff85caac) //120
NHSTUB(PT_MFOff                               ,0xff85cabc) //120
NHSTUB(GetAdChValue                           ,0xff8404ac) //120
NHSTUB(get_ptp_buf_size                       ,0xff8b9538) //122
NHSTUB(get_ptp_file_buf                       ,0xffa04038) //121
NHSTUB(SetVideoOutType                        ,0xffaba060) //109
