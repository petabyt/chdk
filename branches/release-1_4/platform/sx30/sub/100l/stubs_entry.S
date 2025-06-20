// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R45 (DRYOS version 2.3, release #0045)
//   Firmware Ver GM1.00L   // Found @ 0xff898a38, "GM1.00L" @ 0xff898a45
//   Firmware build timestamp: Sep 15 2010 10:44:28
//   Canon PowerShot SX30 IS

// Values for makefile.inc
//   PLATFORMOSVER = 45
//   PLATFORMID = 12816 (0x3210) // Found @ 0xfffe0130
//   MAXRAMADDR = 0x07ffffff
//   MEMISOSTART = 0x0018124c
//   KEYSYS = d4b                // Found @ 0xffff3680
//   NEED_ENCODED_DISKBOOT = 5   // Found @ 0xffff3690
//   ARAM_HEAP_START = 0x3ce000  // Found @ 0xff99c3dc
//   ARAM_HEAP_SIZE  = 0x32000   // Found @ 0xff99c39c

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ffb00eb4 -> ffc67afc
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00034594) // Found @0xff8349f0
DEF(physw_run                               ,0x00001c3c) // Found @0xff8345ec
DEF(physw_sleep_delay                       ,0x00001c44) // Found @0xff8345ec
DEF(levent_table                            ,0xffc0ea34) // Found @0xffc0ea34
DEF(FlashParamsTable                        ,0xffc67d00) // Found @0xffc67d00
DEF(movie_status                            ,0x00003524) // Found @0xff882fb4
DEF(video_compression_rate                  ,0x00003564) // Found @0xff8832ac
DEF(full_screen_refresh                     ,0x0000b198) // Found @0xffa46b00
DEF(canon_menu_active                       ,0x00003a2c) // Found @0xff89a570
DEF(canon_shoot_menu_active                 ,0x00009901) // Found @0xff9deb54
DEF(playrec_mode                            ,0x00003758) // Found @0xff88c71c
DEF(zoom_status                             ,0x0000e7c4) // Found @0xffb04938
DEF(some_flag_for_af_scan                   ,0x000085cc) // Found @0xff991220
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 1 int value, which is the the zoom focus length.
// there are 201 entries in the table - set NUM_FL to 201
DEF(focus_len_table                         ,0xfffea5cc) // Found @0xfffea5cc
DEF(zoom_busy                               ,0x00003448) // Found @0xff87e640
DEF(focus_busy                              ,0x00007a74) // Found @0xff97df3c
DEF(recreview_hold                          ,0x0000468c) // Found @0xff8ac614
// Palette colour tables  found @ 0xffc2af50
DEF(palette_control                         ,0x0000b198) // Found @0xffa46a7c
DEF(active_palette_buffer                   ,0x0000b1a0) // Found @0xffa46a80
DEF(palette_buffer_ptr                      ,0x0000b1a4) // Found @0xffa46fa4
DEF(palette_buffer                          ,0x000cf9b4) // Found @0xffa46fb4
// Offset from start of palette_buffer to color data = 8 (Found @0xffb3cd40)
DEF(bitmap_buffer                           ,0x0000b1d4) // Found @0xffa4aa0c
DEF(active_bitmap_buffer                    ,0x0000b1cc) // Found @0xffa4aa10
DEF(viewport_buffers                        ,0xffb96a6c) // Found @0xff851a1c
DEF(active_viewport_buffer                  ,0x000020a8) // Found @0xff8517cc
// Camera has 2 RAW buffers @ 0x4235f6b0 & 0x443b4960
//  Note: active buffer --> raw_buffers[ active_raw_buffer   *3]
//        other buffer  --> raw_buffers[(active_raw_buffer^1)*3]
DEF(raw_buffers                             ,0xffb993f8) // Found @0xffb993f8
DEF(active_raw_buffer                       ,0x000036ac) // Found @0xff888724
DEF(fileio_semaphore                        ,0x0000325c) // Found @0xff8756fc
DEF_CONST(uiprop_count                      ,0x00000072) // Found @0xff9c1c64

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x40471000; }             // Found @0xff85ed30
//void *vid_get_viewport_fb()      { return (void*)0x40587700; }             // Found @0xffb56c88
DEF(viewport_fb_d                           ,0x00003308) // Found 0x32b0 (@0xff878ab0) + 0x58 (@0xff878ae8)
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x32b0+0x58)); } // Found @0xff878ab0 & 0xff878ae8
DEF(jpeg_count_str                          ,0x000cf2fc) // Found @0xffa3bce4
//char *camera_jpeg_count_str()    { return (char*)0x000cf2fc; }             // Found @0xffa3bce4
//int get_flash_params_count(void) { return 0x9a; }                          // Found @0xff9c2850

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffb97bc4, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x04000000 // Found @0xffb97bf4, levent 0x902
//#define USB_IDX             2
//#define BATTCOVER_FLAG      0x00008000 // Found @0xffb97bb4, levent 0x905
//#define BATTCOVER_IDX       2
//#define HOTSHOE_FLAG        0x01000000 // Found @0xffb97be4, levent 0x904
//#define HOTSHOE_IDX         2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_UP              ,0x00000400 }, // Found @0xffb97afc, levent 0x04
//    { 0, KEY_DOWN            ,0x00000800 }, // Found @0xffb97b04, levent 0x05
//    { 0, KEY_LEFT            ,0x00001000 }, // Found @0xffb97b0c, levent 0x06
//    { 0, KEY_RIGHT           ,0x00002000 }, // Found @0xffb97b14, levent 0x07
//    { 0, KEY_SET             ,0x00004000 }, // Found @0xffb97b1c, levent 0x08
//    { 0, KEY_VIDEO           ,0x00008000 }, // Found @0xffb97b24, levent 0x12
//    { 0, KEY_DISPLAY         ,0x00020000 }, // Found @0xffb97b34, levent 0x0a
//    { 0, KEY_MENU            ,0x00040000 }, // Found @0xffb97b3c, levent 0x09
//    { 2, KEY_SHOOT_FULL      ,0x00000300 }, // Found @0xffb97b9c, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000200 }, // Found @0xffb97b9c, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00000100 }, // Found @0xffb97b94, levent 0x00
//    { 2, KEY_POWER           ,0x00000400 }, // Found @0xffb97ba4, levent 0x600
//    { 2, KEY_PLAYBACK        ,0x00000800 }, // Found @0xffb97bac, levent 0x601
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_RAW_ROWPIX    4464 // Found @0xff95786c
//#define CAM_RAW_ROWS      3276 // Found @0xff957878
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff83afdc
//#define CAM_DATE_FOLDER_NAMING 0x400 // Found @0xffab8f38 (pass as 3rd param to GetImageFolder)
//#define PARAM_CAMERA_NAME 4 // Found @0xffc6a614

// Misc stuff
DEF(ctypes, 0xffb96366)

// LED table init @ 0xff934420
// LED #1: 0xc0223030, offset 0x1d8
// LED #2: 0xc0220134, offset 0xa0

// For capt_seq.c
DEF(_nrflag,0x8610) // Found @ ff9957d4 (0x8608) & ff995808 (+0x08)
//static long *nrflag = (long*)(0x8608+0x08);  // Found @ ff9957d4 & ff995808
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
NHSTUB(DoAELock                               ,0xff838de8) //120
NHSTUB(DoAFLock                               ,0xff838ab8) //120
NHSTUB(EnterToCompensationEVF                 ,0xff838d44) //104
NHSTUB(ExecuteEventProcedure                  ,0xff895cc4) //104
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
NHSTUB(GetCurrentAvValue                      ,0xff980680) //120
NHSTUB(GetDrive_ClusterSize                   ,0xff87724c) //122
NHSTUB(GetDrive_FreeClusters                  ,0xff8772ac) //119
NHSTUB(GetDrive_TotalClusters                 ,0xff877280) //119
NHSTUB(GetFocusLensSubjectDistance            ,0xff97ea80) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff97eef8) //  3
NHSTUB(GetImageFolder                         ,0xff95f0f0) //122
NHSTUB(GetKbdState                            ,0xff865a28) //109
NHSTUB(GetMemInfo                             ,0xff81a264) //115
NHSTUB(GetOpticalTemperature                  ,0xff869820) //120
NHSTUB(GetParameterData                       ,0xff9c2814) //101
NHSTUB(GetPropertyCase                        ,0xff8999cc) //102
NHSTUB(GetSystemTime                          ,0xffaee208) //120
NHSTUB(GetVRAMHPixelsSize                     ,0xff85413c) //120
NHSTUB(GetVRAMVPixelsSize                     ,0xff854148) //120
NHSTUB(GetZoomLensCurrentPoint                ,0xff87e9c4) //120
NHSTUB(GetZoomLensCurrentPosition             ,0xff9864ac) //102
NHSTUB(GiveSemaphore                          ,0xff83a9b4) //120
NHSTUB(IsStrobeChargeCompleted                ,0xff8ec16c) //102
NHSTUB(LEDDrive                               ,0xff864bd4) //120
NHSTUB(LocalTime                              ,0xff8935ac) //115
NHSTUB(LockMainPower                          ,0xff8a0294) //120
NHSTUB(MakeDirectory_Fut                      ,0xff836ac8) //116
NHSTUB(MoveFocusLensToDistance                ,0xffb52fb8) //102
NHSTUB(MoveIrisWithAv                         ,0xffae8fbc) //120
NHSTUB(MoveZoomLensWithPoint                  ,0xffae96b4) //120
NHSTUB(Open                                   ,0xff837070) //120
NHSTUB(PB2Rec                                 ,0xff8a30fc) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff883c30) //120
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff883c08) //120
NHSTUB(PT_PlaySound                           ,0xff88e660) //122
NHSTUB(PostLogicalEventForNotPowerType        ,0xff89e02c) //120
NHSTUB(PostLogicalEventToUI                   ,0xff89e078) //120
NHSTUB(PutInNdFilter                          ,0xffb50c2c) //102
NHSTUB(PutOutNdFilter                         ,0xffb50c64) //102
NHSTUB(Read                                   ,0xff81ad74) //120
NHSTUB(ReadFastDir                            ,0xfface02c) //  4
NHSTUB(Rec2PB                                 ,0xff8a1b40) //104
NHSTUB(RefreshPhysicalScreen                  ,0xff8b8114) //104
NHSTUB(RenameFile_Fut                         ,0xff8369c0) //116
NHSTUB(Restart                                ,0xff83c788) //122
NHSTUB(ScreenLock                             ,0xff8b9344) //117
NHSTUB(ScreenUnlock                           ,0xff8b93a8) //117
NHSTUB(SetAE_ShutterSpeed                     ,0xffb55e00) //102
NHSTUB(SetAutoShutdownTime                    ,0xff8a0308) //120
NHSTUB(SetCurrentCaptureModeType              ,0xff8a922c) //120
NHSTUB(SetFileAttributes                      ,0xff8373d4) //  3
NHSTUB(SetFileTimeStamp                       ,0xff837378) //  4
NHSTUB(SetLogicalEventActive                  ,0xff89ffd0) //120
NHSTUB(SetParameterData                       ,0xff9c26ec) //101
NHSTUB(SetPropertyCase                        ,0xff8998a4) //102
NHSTUB(SetScriptMode                          ,0xff8a0020) //120
NHSTUB(SleepTask                              ,0xff83ac1c) //120
NHSTUB(TakeSemaphore                          ,0xff83a8e4) //120
NHSTUB(TurnOffBackLight                       ,0xff8b059c) //104
NHSTUB(TurnOnBackLight                        ,0xff8b0584) //104
NHSTUB(TurnOnDisplay                          ,0xff85f0a8) //120
NHSTUB(TurnOffDisplay                         ,0xff85f0b8) //120
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff9aeeb8) //120
NHSTUB(UnlockAE                               ,0xff838e0c) //120
NHSTUB(UnlockAF                               ,0xff838af0) //120
NHSTUB(UnlockMainPower                        ,0xff8a01e8) //120
NHSTUB(UpdateMBROnFlash                       ,0xff8770cc) //105
NHSTUB(VbattGet                               ,0xff833178) //120
NHSTUB(Write                                  ,0xff83716c) //120
NHSTUB(WriteSDCard                            ,0xff96dab4) //108
NHSTUB(_log                                   ,0xffb93cb0) //111
NHSTUB(_log10                                 ,0xffb92bf4) //112
NHSTUB(_pow                                   ,0xffb92d64) //121
NHSTUB(_sqrt                                  ,0xffb9507c) //  1
NHSTUB(add_ptp_handler                        ,0xffa8ebe0) //121
NHSTUB(apex2us                                ,0xffa4e9f0) //121
NHSTUB(close                                  ,0xff81ab8c) //109
NHSTUB(err_init_task                          ,0xff815fd4) //111
NHSTUB(exmem_alloc                            ,0xff8944f8) //103
NHSTUB(exmem_free                             ,0xff894570) //103
NHSTUB(free                                   ,0xff814244) //112
NHSTUB(kbd_p1_f                               ,0xff834a68) //109
NHSTUB(kbd_p1_f_cont                          ,0xff834a74) //109
NHSTUB(kbd_p2_f                               ,0xff8342b8) //109
NHSTUB(kbd_read_keys                          ,0xff8349f0) //109
NHSTUB(kbd_read_keys_r2                       ,0xff8651a4) //109
NHSTUB(lseek                                  ,0xff8371f8) //120
NHSTUB(malloc                                 ,0xff8141e8) //112
NHSTUB(memcmp                                 ,0xff8206d0) //120
NHSTUB(memcpy                                 ,0xff840750) //120
NHSTUB(memset                                 ,0xffa4d9ec) //120
NHSTUB(mkdir                                  ,0xff837578) //109
NHSTUB(mktime_ext                             ,0xff8ba264) //  1
NHSTUB(open                                   ,0xff81aadc) //109
NHSTUB(OpenFastDir                            ,0xffacded8) //  4
NHSTUB(closedir                               ,0xffacde88) //121
NHSTUB(get_fstype                             ,0xff8772d0) //122
NHSTUB(qsort                                  ,0xffb40804) //  4
NHSTUB(rand                                   ,0xffa4db2c) //121
NHSTUB(realloc                                ,0xffa4da68) //115
NHSTUB(reboot_fw_update                       ,0xffad344c) //106
NHSTUB(set_control_event                      ,0xff89fbc0) //111
NHSTUB(srand                                  ,0xffa4db20) //122
NHSTUB(stat                                   ,0xff837240) //109
NHSTUB(strcat                                 ,0xff8b9a20) //  1
NHSTUB(strchr                                 ,0xff8140b4) //  1
NHSTUB(strcmp                                 ,0xff82068c) //120
NHSTUB(strcpy                                 ,0xff820674) //120
NHSTUB(strftime                               ,0xff8b9c6c) //113
NHSTUB(strlen                                 ,0xff814100) //120
NHSTUB(strncmp                                ,0xff814068) //  1
NHSTUB(strncpy                                ,0xff81402c) //  1
NHSTUB(strrchr                                ,0xff8140d8) //  1
NHSTUB(strtol                                 ,0xff840a30) //101
NHSTUB(strtolx                                ,0xff840834) //109
   DEF(task_CaptSeq                           ,0xff8868c4) //120
   DEF(task_DvlpSeqTask                       ,0xff8882f4) //120
   DEF(task_ExpDrv                            ,0xff8d081c) //120
   DEF(task_FileWrite                         ,0xffacbf00) //120
   DEF(task_InitFileModules                   ,0xff8a3b50) //120
   DEF(task_MovieRecord                       ,0xff88334c) //120
   DEF(task_PhySw                             ,0xff8345e8) //120
   DEF(task_RotaryEncoder                     ,0xff865d08) //120
NHSTUB(time                                   ,0xff893b8c) //109
NHSTUB(vsprintf                               ,0xff820638) //115
NHSTUB(EngDrvRead                             ,0xff8358c0) //102
NHSTUB(PTM_GetCurrentItem                     ,0xff8a0b30) //105
NHSTUB(CancelHPTimer                          ,0xff8953ac) //119
NHSTUB(SetHPTimerAfterNow                     ,0xff8952a4) //119
NHSTUB(PT_MFOn                                ,0xff883cc0) //120
NHSTUB(PT_MFOff                               ,0xff883cd0) //120
NHSTUB(GetAdChValue                           ,0xff860bd4) //120
