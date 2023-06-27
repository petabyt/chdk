// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R45 (DRYOS version 2.3, release #0045)
//   Firmware Ver GM1.00A   // Found @ 0xff898a0c, "GM1.00A" @ 0xff898a19
//   Firmware build timestamp: Jul 12 2010 13:35:05
//   Canon PowerShot SX30 IS

// Values for makefile.inc
//   DIGIC = 40# DIGIC 4
//   PLATFORMOSVER = 45
//   PLATFORMID = 12816# (0x3210) Found @ 0xfffe0130
//   MAXRAMADDR = 0x07ffffff
//   MEMISOSTART = 0x0018122c
//   KEYSYS = d4b# Found @ 0xffff3680
//   NEED_ENCODED_DISKBOOT = 5# Found @ 0xffff3690
//   ARAM_HEAP_START = 0x3ce000# Found @ 0xff99c100
//   ARAM_HEAP_SIZE  = 0x32000# Found @ 0xff99c0c0

// Detected address ranges:
// ROM      0xff810000 - 0xffffffff (8323072 bytes)
// RAM data 0x00001900 - 0x000108b0 copied from 0xffc90600 (  61360 bytes)

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ffb00b8c -> ffc677d4
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00034574) // Found @0xff8349f0
DEF(physw_run                               ,0x00001c3c) // Found @0xff8345ec
DEF(physw_sleep_delay                       ,0x00001c44) // Found @0xff8345ec
DEF(levent_table                            ,0xffc0e70c) // Found @0xffc0e70c
DEF(FlashParamsTable                        ,0xffc679d8) // Found @0xffc679d8
DEF(movie_status                            ,0x00003524) // Found @0xff882fa0
DEF(video_compression_rate                  ,0x00003564) // Found @0xff883280
DEF(full_screen_refresh                     ,0x0000b190) // Found @0xffa467f4
DEF(canon_menu_active                       ,0x00003a2c) // Found @0xff89a544
DEF(canon_shoot_menu_active                 ,0x000098f9) // Found @0xff9de848
DEF(playrec_mode                            ,0x00003758) // Found @0xff88c6f0
DEF(zoom_status                             ,0x0000e7bc) // Found @0xffb04610
DEF(some_flag_for_af_scan                   ,0x000085c4) // Found @0xff990f4c
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 1 int value, which is the the zoom focus length.
// there are 201 entries in the table - set NUM_FL to 201
DEF(focus_len_table                         ,0xfffea5cc) // Found @0xfffea5cc
DEF(zoom_busy                               ,0x00003448) // Found @0xff87e610
DEF(focus_busy                              ,0x00007a70) // Found @0xff97dec8
DEF(recreview_hold                          ,0x0000468c) // Found @0xff8ac5e8
// Palette colour tables  found @ 0xffc2ac28
DEF(palette_control                         ,0x0000b190) // Found @0xffa46770
DEF(active_palette_buffer                   ,0x0000b198) // Found @0xffa46774
DEF(palette_buffer_ptr                      ,0x0000b19c) // Found @0xffa46c98
DEF(palette_buffer                          ,0x000cf994) // Found @0xffa46ca8
// Offset from start of palette_buffer to color data = 8 (Found @0xffb3ca18)
DEF(bitmap_buffer                           ,0x0000b1cc) // Found @0xffa4a700
DEF(active_bitmap_buffer                    ,0x0000b1c4) // Found @0xffa4a704
DEF(viewport_buffers                        ,0xffb96744) // Found @0xff851a1c
DEF(active_viewport_buffer                  ,0x000020a8) // Found @0xff8517cc
// Camera has 2 RAW buffers @ 0x4235f6b0 & 0x443b4960
//  Note: active buffer --> raw_buffers[ active_raw_buffer   *3]
//        other buffer  --> raw_buffers[(active_raw_buffer^1)*3]
DEF(raw_buffers                             ,0xffb990d0) // Found @0xffb990d0
DEF(active_raw_buffer                       ,0x000036ac) // Found @0xff8886f8
DEF(fileio_semaphore                        ,0x0000325c) // Found @0xff8756fc
DEF(exmem_alloc_table                       ,0x0003c0a8) // Found @0xff893ec4
DEF(exmem_types_table                       ,0xffc92578) // Found @0x00003878
DEF_CONST(exmem_type_count                  ,0x00000013)
DEF(imager_active                           ,0x00001fe4) // Found @0xff84e6cc (0x1fe0 + 4)
DEF_CONST(uiprop_count                      ,0x00000072) // Found @0xff9c1988
DEF(cameracon_state                         ,0x000040bc) // Found @0xff8a14d8

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x40471000; }             // Found @0xff85ed30
//void *vid_get_viewport_fb()      { return (void*)0x40587700; }             // Found @0xffb56960
DEF(viewport_fb_d                           ,0x00003308) // Found 0x32b0 (@0xff878ab0) + 0x58 (@0xff878ae8)
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x32b0+0x58)); } // Found @0xff878ab0 & 0xff878ae8
DEF(jpeg_count_str                          ,0x000cf2dc) // Found @0xffa3b9d8
//char *camera_jpeg_count_str()    { return (char*)0x000cf2dc; }             // Found @0xffa3b9d8
//int get_flash_params_count(void) { return 0x9a; }                          // Found @0xff9c2574

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffb9789c, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x04000000 // Found @0xffb978cc, levent 0x902
//#define USB_IDX             2
//#define BATTCOVER_FLAG      0x00008000 // Found @0xffb9788c, levent 0x905
//#define BATTCOVER_IDX       2
//#define HOTSHOE_FLAG        0x01000000 // Found @0xffb978bc, levent 0x904
//#define HOTSHOE_IDX         2
//#define ANALOG_AV_FLAG      0x02000000 // Found @0xffb978c4, levent 0x900 (non-inverted logic)
//#define ANALOG_AV_IDX       2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_UP              ,0x00000400 }, // Found @0xffb977d4, levent 0x04
//    { 0, KEY_DOWN            ,0x00000800 }, // Found @0xffb977dc, levent 0x05
//    { 0, KEY_LEFT            ,0x00001000 }, // Found @0xffb977e4, levent 0x06
//    { 0, KEY_RIGHT           ,0x00002000 }, // Found @0xffb977ec, levent 0x07
//    { 0, KEY_SET             ,0x00004000 }, // Found @0xffb977f4, levent 0x08
//    { 0, KEY_VIDEO           ,0x00008000 }, // Found @0xffb977fc, levent 0x12
//    { 0, KEY_DISPLAY         ,0x00020000 }, // Found @0xffb9780c, levent 0x0a
//    { 0, KEY_MENU            ,0x00040000 }, // Found @0xffb97814, levent 0x09
//    { 2, KEY_SHOOT_FULL      ,0x00000300 }, // Found @0xffb97874, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000200 }, // Found @0xffb97874, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00000100 }, // Found @0xffb9786c, levent 0x00
//    { 2, KEY_POWER           ,0x00000400 }, // Found @0xffb9787c, levent 0x600
//    { 2, KEY_PLAYBACK        ,0x00000800 }, // Found @0xffb97884, levent 0x601
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_RAW_ROWPIX    4464 // Found @0xff9577f8
//#define CAM_RAW_ROWS      3276 // Found @0xff957804
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff83afdc
//#define CAM_DATE_FOLDER_NAMING 0x400 // Found @0xffab8c2c (pass as 3rd param to GetImageFolder)
//#define PARAM_CAMERA_NAME 4 // Found @0xffc6a2ec

// Below goes in 'filewrite.c' or 'platform_camera.h':
//#define MAX_CHUNKS_FOR_FWT 7 // Found @0xffacbc4c

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
DEF(ctypes, 0xffb9603e)

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

// LED table init @ 0xff9343ac
// LED #1: 0xc0223030, offset 0x1d8
// LED #2: 0xc0220134, offset 0xa0

// For capt_seq.c
DEF(_nrflag,0x8608) // Found @ ff9954f8 (0x8600) & ff99552c (+0x08)
//static long *nrflag = (long*)(0x8600+0x08);  // Found @ ff9954f8 & ff99552c
//#define NR_AUTO (0)                          // have to explictly reset value back to 0 to enable auto

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NHSTUB(AllocateUncacheableMemory              ,0xff83af98) //112
NHSTUB(Close                                  ,0xff8370dc) //120
NHSTUB(CreateBinarySemaphore                  ,0xff83a778) //115
NHSTUB(CreateTask                             ,0xff81e8a0) //120
NHSTUB(DebugAssert                            ,0xff81eb78) //107
NHSTUB(DeleteDirectory_Fut                    ,0xff836b38) //116
NHSTUB(DeleteFile_Fut                         ,0xff836a54) //112
NHSTUB(DeleteSemaphore                        ,0xff83a838) //120
NHSTUB(DoAELock                               ,0xff838de8) //120
NHSTUB(DoAFLock                               ,0xff838ab8) //120
NHSTUB(EnterToCompensationEVF                 ,0xff838d44) //104
NHSTUB(ExecuteEventProcedure                  ,0xff895c98) //104
NHSTUB(ExitFromCompensationEVF                ,0xff838d88) //104
NHSTUB(ExitTask                               ,0xff81eb30) //120
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff8474fc) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff847688) //104
NHSTUB(Fclose_Fut                             ,0xff836bd0) //120
NHSTUB(Feof_Fut                               ,0xff836dbc) //  1
NHSTUB(Fflush_Fut                             ,0xff836df8) //  1
NHSTUB(Fgets_Fut                              ,0xff836d24) //  1
NHSTUB(Fopen_Fut                              ,0xff836b90) //120
NHSTUB(Fread_Fut                              ,0xff836c7c) //120
NHSTUB(FreeUncacheableMemory                  ,0xff83afd8) //112
NHSTUB(Fseek_Fut                              ,0xff836d70) //120
NHSTUB(Fwrite_Fut                             ,0xff836cd0) //120
NHSTUB(GetBatteryTemperature                  ,0xff8697ac) //102
NHSTUB(GetCCDTemperature                      ,0xff869738) //102
NHSTUB(GetCurrentAvValue                      ,0xff98060c) //120
NHSTUB(GetCurrentShutterSpeed                 ,0xff8be760) //120
NHSTUB(GetUsableMaxAv                         ,0xffb50898) //120
NHSTUB(GetUsableMinAv                         ,0xffb50880) //120
NHSTUB(GetDrive_ClusterSize                   ,0xff87724c) //122
NHSTUB(GetDrive_FreeClusters                  ,0xff8772ac) //119
NHSTUB(GetDrive_TotalClusters                 ,0xff877280) //119
NHSTUB(GetFocusLensSubjectDistance            ,0xff97ea0c) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff97ee84) //  3
NHSTUB(GetImageFolder                         ,0xff95f07c) //122
NHSTUB(GetKbdState                            ,0xff865a28) //109
NHSTUB(GetMemInfo                             ,0xff81a264) //115
NHSTUB(GetOpticalTemperature                  ,0xff869820) //120
NHSTUB(GetParameterData                       ,0xff9c2538) //101
NHSTUB(GetPropertyCase                        ,0xff8999a0) //102
NHSTUB(GetSystemTime                          ,0xffaedee0) //120
NHSTUB(GetVRAMHPixelsSize                     ,0xff85413c) //120
NHSTUB(GetVRAMVPixelsSize                     ,0xff854148) //120
NHSTUB(GetZoomLensCurrentPoint                ,0xff87efd4) //120
NHSTUB(GetZoomLensCurrentPosition             ,0xff986428) //102
NHSTUB(GiveSemaphore                          ,0xff83a9b4) //120
NHSTUB(IsStrobeChargeCompleted                ,0xff8ec140) //102
NHSTUB(LEDDrive                               ,0xff864bd4) //120
NHSTUB(LocalTime                              ,0xff893580) //115
NHSTUB(LockMainPower                          ,0xff8a0268) //120
NHSTUB(MakeDirectory_Fut                      ,0xff836ac8) //116
NHSTUB(MoveFocusLensToDistance                ,0xffb52c90) //102
NHSTUB(MoveIrisWithAv                         ,0xffae8c94) //120
NHSTUB(MoveZoomLensWithPoint                  ,0xffae938c) //120
NHSTUB(MoveOpticalZoomAt                      ,0xff83831c) //109
NHSTUB(Open                                   ,0xff837070) //120
NHSTUB(PB2Rec                                 ,0xff8a30d0) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff883c04) //120
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff883bdc) //120
NHSTUB(PT_PlaySound                           ,0xff88e634) //122
NHSTUB(PostLogicalEventForNotPowerType        ,0xff89e000) //120
NHSTUB(PostLogicalEventToUI                   ,0xff89e04c) //120
NHSTUB(PutInNdFilter                          ,0xffb50904) //102
NHSTUB(PutOutNdFilter                         ,0xffb5093c) //102
NHSTUB(Read                                   ,0xff81ad74) //120
NHSTUB(ReadFastDir                            ,0xffacdd20) //  4
NHSTUB(Rec2PB                                 ,0xff8a1b14) //104
NHSTUB(RefreshPhysicalScreen                  ,0xff8b80e8) //104
NHSTUB(RenameFile_Fut                         ,0xff8369c0) //116
NHSTUB(Restart                                ,0xff83c788) //122
NHSTUB(ScreenLock                             ,0xff8b9318) //117
NHSTUB(ScreenUnlock                           ,0xff8b937c) //117
NHSTUB(SetAE_ShutterSpeed                     ,0xffb55ad8) //102
NHSTUB(SetAutoShutdownTime                    ,0xff8a02dc) //120
NHSTUB(SetCurrentCaptureModeType              ,0xff8a9200) //120
NHSTUB(SetDate                                ,0xffb575bc) //120
NHSTUB(SetFileAttributes                      ,0xff8373d4) //  3
NHSTUB(SetFileTimeStamp                       ,0xff837378) //  4
NHSTUB(SetLogicalEventActive                  ,0xff89ffa4) //120
NHSTUB(SetParameterData                       ,0xff9c2410) //101
NHSTUB(SetPropertyCase                        ,0xff899878) //102
NHSTUB(SetScriptMode                          ,0xff89fff4) //120
NHSTUB(SleepTask                              ,0xff83ac1c) //120
NHSTUB(TakeSemaphore                          ,0xff83a8e4) //120
NHSTUB(TurnOffBackLight                       ,0xff8b0570) //104
NHSTUB(TurnOnBackLight                        ,0xff8b0558) //104
NHSTUB(TurnOnDisplay                          ,0xff85f0a8) //120
NHSTUB(TurnOffDisplay                         ,0xff85f0b8) //120
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff9aebdc) //120
NHSTUB(UnlockAE                               ,0xff838e0c) //120
NHSTUB(UnlockAF                               ,0xff838af0) //120
NHSTUB(UnlockMainPower                        ,0xff8a01bc) //120
NHSTUB(UpdateMBROnFlash                       ,0xff8770cc) //105
NHSTUB(VbattGet                               ,0xff833178) //120
NHSTUB(Write                                  ,0xff83716c) //120
NHSTUB(WriteSDCard                            ,0xff96da40) //108
NHSTUB(_log                                   ,0xffb93988) //111
NHSTUB(_log10                                 ,0xffb928cc) //112
NHSTUB(_pow                                   ,0xffb92a3c) //121
NHSTUB(_sqrt                                  ,0xffb94d54) //  1
NHSTUB(add_ptp_handler                        ,0xffa8e8d4) //121
NHSTUB(apex2us                                ,0xffa4e6e4) //121
NHSTUB(close                                  ,0xff81ab8c) //109
NHSTUB(err_init_task                          ,0xff815fd4) //111
NHSTUB(exmem_alloc                            ,0xff8944cc) //103
NHSTUB(exmem_ualloc                           ,0xff89431c) //103
NHSTUB(exmem_ufree                            ,0xff89446c) //103
NHSTUB(free                                   ,0xff814244) //112
NHSTUB(get_current_deltasv                    ,0xff8bf2a4) //122
NHSTUB(GetCurrentDriveBaseSvValue             ,0xff8c4f98) //123
NHSTUB(kbd_p1_f                               ,0xff834a68) //109
NHSTUB(kbd_p1_f_cont                          ,0xff834a74) //109
NHSTUB(kbd_p2_f                               ,0xff8342b8) //109
NHSTUB(kbd_read_keys                          ,0xff8349f0) //109
NHSTUB(kbd_read_keys_r2                       ,0xff8651a4) //109
NHSTUB(lseek                                  ,0xff8371f8) //120
NHSTUB(malloc                                 ,0xff8141e8) //112
NHSTUB(memcmp                                 ,0xff8206d0) //120
NHSTUB(memcpy                                 ,0xff840750) //120
NHSTUB(memset                                 ,0xffa4d6e0) //120
NHSTUB(mkdir                                  ,0xff837578) //109
NHSTUB(mktime_ext                             ,0xff8ba238) //  1
NHSTUB(open                                   ,0xff81aadc) //109
NHSTUB(OpenFastDir                            ,0xffacdbcc) //  4
NHSTUB(closedir                               ,0xffacdb7c) //121
NHSTUB(get_fstype                             ,0xff8772d0) //122
NHSTUB(qsort                                  ,0xffb404dc) //  4
NHSTUB(rand                                   ,0xffa4d820) //121
NHSTUB(realloc                                ,0xffa4d75c) //115
NHSTUB(reboot_fw_update                       ,0xffad3140) //106
NHSTUB(set_control_event                      ,0xff89fb94) //111
NHSTUB(srand                                  ,0xffa4d814) //122
NHSTUB(stat                                   ,0xff837240) //109
NHSTUB(strcat                                 ,0xff8b99f4) //  1
NHSTUB(strchr                                 ,0xff8140b4) //  1
NHSTUB(strcmp                                 ,0xff82068c) //120
NHSTUB(strcpy                                 ,0xff820674) //120
NHSTUB(strftime                               ,0xff8b9c40) //113
NHSTUB(strlen                                 ,0xff814100) //120
NHSTUB(strncmp                                ,0xff814068) //  1
NHSTUB(strncpy                                ,0xff81402c) //  1
NHSTUB(strrchr                                ,0xff8140d8) //  1
NHSTUB(strtol                                 ,0xff840a30) //101
NHSTUB(strtolx                                ,0xff840834) //109
   DEF(task_CaptSeq                           ,0xff886898) //120
   DEF(task_DvlpSeqTask                       ,0xff8882c8) //120
   DEF(task_ExpDrv                            ,0xff8d07f0) //120
   DEF(task_FileWrite                         ,0xffacbbf4) //120
   DEF(task_InitFileModules                   ,0xff8a3b24) //120
   DEF(task_MovieRecord                       ,0xff883320) //120
   DEF(task_PhySw                             ,0xff8345e8) //120
   DEF(task_RotaryEncoder                     ,0xff865d08) //120
NHSTUB(time                                   ,0xff893b60) //109
NHSTUB(vsprintf                               ,0xff820638) //115
NHSTUB(EngDrvRead                             ,0xff8358c0) //102
NHSTUB(PTM_GetCurrentItem                     ,0xff8a0b04) //105
NHSTUB(DisableISDriveError                    ,0xffaeb514) //120
NHSTUB(CancelHPTimer                          ,0xff895380) //119
NHSTUB(SetHPTimerAfterNow                     ,0xff895278) //119
NHSTUB(PT_MFOn                                ,0xff883c94) //120
NHSTUB(PT_MFOff                               ,0xff883ca4) //120
NHSTUB(GetAdChValue                           ,0xff860bd4) //120
NHSTUB(EnableHDMIPower                        ,0xff864464) //123
NHSTUB(DisableHDMIPower                       ,0xff86446c) //123
NHSTUB(get_ptp_buf_size                       ,0xff91c6e8) //122
NHSTUB(get_ptp_file_buf                       ,0xffa902fc) //121
NHSTUB(SetVideoOutType                        ,0xffb562f8) //109
NHSTUB(GetVideoOutType                        ,0xffb56228) //120
