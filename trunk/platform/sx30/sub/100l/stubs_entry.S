// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R45 (DRYOS version 2.3, release #0045)
//   Firmware Ver GM1.00L
//   Canon PowerShot SX30 IS

// Values for makefile.inc
//   PLATFORMOSVER = 45
//   PLATFORMID = 12816 (0x3210) // Found @ 0xfffe0130
//   MAXRAMADDR = 0x07ffffff
//   KEYSYS = d4b                // Found @ 0xffff3680
//   NEED_ENCODED_DISKBOOT = 5   // Found @ 0xffff3690

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NHSTUB(kbd_pwr_off                          ,0xff865b9c) //  2 60%    *** != 0x00000000
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff8a3cc4 -> ff8a0690 -> ff9c12b8 -> ffb00eb4 -> ffc67afc
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00034594) // Found @0xff8349f0
DEF(physw_run                               ,0x00001c3c) // Found @0xff8345ec
DEF(physw_sleep_delay                       ,0x00001c44) // Found @0xff8345ec
DEF(levent_table                            ,0xffc0ea34) // Found @0xffc0ea34
DEF(FlashParamsTable                        ,0xffc67d00) // Found @0xffc67d00
DEF(movie_status                            ,0x00003524) // Found @0xff882fb4
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

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x40471000; }             // Found @0xff85ed30
//void *vid_get_viewport_fb()      { return (void*)0x40587700; }             // Found @0xffb56c88
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x32b0+0x58)); } // Found @0xff878ab0 & 0xff878ae8
//char *camera_jpeg_count_str()    { return (char*)0x000cf2fc; }             // Found @0xffa3bce4
//long hook_raw_size()             { return 0x014eb7e0; }                    // Found @0xffb5a148
//int get_flash_params_count(void) { return 0x9a; }                          // Found @0xff9c2850

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffb97bc4, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x04000000 // Found @0xffb97bf4, levent 0x902
//#define USB_IDX             2

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

// Misc stuff
DEF(ctypes, 0xffb96366)

// For capt_seq.c
DEF(_nrflag,0x8610) // Found @ ff9957d4 (0x8608) & ff995808 (+0x08)
//static long *nrflag = (long*)(0x8608+0x08);  // Found @ ff9957d4 & ff995808
//#define NR_AUTO (0)                          // have to explictly reset value back to 0 to enable auto

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
//NHSTUB(CreateJumptable                      ,0xffb5a310) //  1
//NHSTUB(_uartr_req                           ,0xff81fc4c) //111
//NHSTUB(AllocateMemory                       ,0xffaee1b0) //101
NHSTUB(AllocateUncacheableMemory              ,0xff83af98) //112
NHSTUB(Close                                  ,0xff8370dc) //101
NHSTUB(CreateTask                             ,0xff81e8a0) //101
NHSTUB(DebugAssert                            ,0xff81eb78) //111
NHSTUB(DeleteDirectory_Fut                    ,0xff836b38) //116
NHSTUB(DeleteFile_Fut                         ,0xff836a54) //112
NHSTUB(DoAFLock                               ,0xff838ab8) //102
NHSTUB(EnterToCompensationEVF                 ,0xff838d44) //104
NHSTUB(ExecuteEventProcedure                  ,0xff895cc4) //104
NHSTUB(ExitFromCompensationEVF                ,0xff838d88) //104
NHSTUB(ExitTask                               ,0xff81eb30) //101
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff8474fc) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff847688) //104
NHSTUB(Fclose_Fut                             ,0xff836bd0) //101
NHSTUB(Feof_Fut                               ,0xff836dbc) //  1
NHSTUB(Fflush_Fut                             ,0xff836df8) //  1
NHSTUB(Fgets_Fut                              ,0xff836d24) //  1
NHSTUB(Fopen_Fut                              ,0xff836b90) //101
NHSTUB(Fread_Fut                              ,0xff836c7c) //101
//NHSTUB(FreeMemory                           ,0xffaee1a8) //101
NHSTUB(FreeUncacheableMemory                  ,0xff83afd8) //112
NHSTUB(Fseek_Fut                              ,0xff836d70) //101
NHSTUB(Fwrite_Fut                             ,0xff836cd0) //101
NHSTUB(GetBatteryTemperature                  ,0xff8697ac) //102
NHSTUB(GetCCDTemperature                      ,0xff869738) //102
NHSTUB(GetCurrentAvValue                      ,0xff980680) //102
NHSTUB(GetDrive_ClusterSize                   ,0xff87724c) //  4
NHSTUB(GetDrive_FreeClusters                  ,0xff8772ac) //  4
NHSTUB(GetDrive_TotalClusters                 ,0xff877280) //  3
NHSTUB(GetFocusLensSubjectDistance            ,0xff97ea80) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff97eef8) //  3
NHSTUB(GetImageFolder                         ,0xff95f0f0) //106
NHSTUB(GetKbdState                            ,0xff865a28) //109
NHSTUB(GetMemInfo                             ,0xff81a264) //115
NHSTUB(GetOpticalTemperature                  ,0xff869820) //102
NHSTUB(GetParameterData                       ,0xff9c2814) //101
NHSTUB(GetPropertyCase                        ,0xff8999cc) //102
NHSTUB(GetSystemTime                          ,0xffaee208) //101
NHSTUB(GetVRAMHPixelsSize                     ,0xff85413c) //102
NHSTUB(GetVRAMVPixelsSize                     ,0xff854148) //102
NHSTUB(GetZoomLensCurrentPoint                ,0xff87e9c4) //102
NHSTUB(GetZoomLensCurrentPosition             ,0xff9864ac) //102
NHSTUB(GiveSemaphore                          ,0xff83a9b4) //112
NHSTUB(IsStrobeChargeCompleted                ,0xff8ec16c) //102
NHSTUB(LEDDrive                               ,0xff864bd4) //103
NHSTUB(LocalTime                              ,0xff8935ac) //115
NHSTUB(LockMainPower                          ,0xff8a0294) //103
//NHSTUB(Lseek                                ,0xff8371f8) //101
NHSTUB(MakeDirectory_Fut                      ,0xff836ac8) //116
NHSTUB(MoveFocusLensToDistance                ,0xffb52fb8) //102
NHSTUB(MoveIrisWithAv                         ,0xffae8fbc) //102
NHSTUB(MoveZoomLensWithPoint                  ,0xffae96b4) //102
//NHSTUB(NewTaskShell                         ,0xff8993e8) //103
NHSTUB(Open                                   ,0xff837070) //101
NHSTUB(PB2Rec                                 ,0xff8a30fc) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff883c30) //102
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff883c08) //102
NHSTUB(PT_PlaySound                           ,0xff88e660) //  4
NHSTUB(PostLogicalEventForNotPowerType        ,0xff89e02c) //103
NHSTUB(PostLogicalEventToUI                   ,0xff89e078) //103
NHSTUB(PutInNdFilter                          ,0xffb50c2c) //102
NHSTUB(PutOutNdFilter                         ,0xffb50c64) //102
NHSTUB(Read                                   ,0xff81ad74) //101
NHSTUB(ReadFastDir                            ,0xfface02c) //  4
NHSTUB(Rec2PB                                 ,0xff8a1b40) //104
NHSTUB(RefreshPhysicalScreen                  ,0xff8b8114) //104
//NHSTUB(Remove                               ,0xff837110) //  4
NHSTUB(RenameFile_Fut                         ,0xff8369c0) //116
NHSTUB(Restart                                ,0xff83c788) //106
NHSTUB(ScreenLock                             ,0xff8b9344) //  4
NHSTUB(ScreenUnlock                           ,0xff8b93a8) //  3
NHSTUB(SetAE_ShutterSpeed                     ,0xffb55e00) //102
NHSTUB(SetAutoShutdownTime                    ,0xff8a0308) //103
NHSTUB(SetCurrentCaptureModeType              ,0xff8a922c) //101
NHSTUB(SetFileAttributes                      ,0xff8373d4) //  3
NHSTUB(SetFileTimeStamp                       ,0xff837378) //  4
NHSTUB(SetLogicalEventActive                  ,0xff89ffd0) //101
NHSTUB(SetParameterData                       ,0xff9c26ec) //101
NHSTUB(SetPropertyCase                        ,0xff8998a4) //102
NHSTUB(SetScriptMode                          ,0xff8a0020) //101
NHSTUB(SleepTask                              ,0xff83ac1c) //101
NHSTUB(TakeSemaphore                          ,0xff83a8e4) //101
NHSTUB(TurnOffBackLight                       ,0xff8b059c) //104
NHSTUB(TurnOnBackLight                        ,0xff8b0584) //104
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff9aeeb8) //101
NHSTUB(UnlockAF                               ,0xff838af0) //102
NHSTUB(UnlockMainPower                        ,0xff8a01e8) //103
NHSTUB(UpdateMBROnFlash                       ,0xff8770cc) //105
NHSTUB(VbattGet                               ,0xff833178) //103
NHSTUB(Write                                  ,0xff83716c) //101
NHSTUB(WriteSDCard                            ,0xff96dab4) //108
NHSTUB(_log                                   ,0xffb93cb0) //111
NHSTUB(_log10                                 ,0xffb92bf4) //112
NHSTUB(_pow                                   ,0xffb92d64) //114
NHSTUB(_sqrt                                  ,0xffb9507c) //  1
NHSTUB(add_ptp_handler                        ,0xffa8ebe0) //  3
NHSTUB(apex2us                                ,0xffa4e9f0) //  4
NHSTUB(close                                  ,0xff81ab8c) //  1
NHSTUB(closedir                               ,0xffacde88) //  4
NHSTUB(err_init_task                          ,0xff815fd4) //111
NHSTUB(exmem_alloc                            ,0xff8944f8) //103
NHSTUB(exmem_free                             ,0xff894570) //103
NHSTUB(free                                   ,0xff814244) //112
NHSTUB(kbd_p1_f                               ,0xff834a68) //109
NHSTUB(kbd_p1_f_cont                          ,0xff834a74) //109
NHSTUB(kbd_p2_f                               ,0xff8342b8) //109
NHSTUB(kbd_read_keys                          ,0xff8349f0) //109
NHSTUB(kbd_read_keys_r2                       ,0xff8651a4) //109
NHSTUB(lseek                                  ,0xff8371f8) //101
NHSTUB(malloc                                 ,0xff8141e8) //112
NHSTUB(memcmp                                 ,0xff8206d0) //101
NHSTUB(memcpy                                 ,0xff840750) //101
NHSTUB(memset                                 ,0xffa4d9ec) //101
NHSTUB(mkdir                                  ,0xff837578) //109
NHSTUB(mktime_ext                             ,0xff8ba264) //  1
NHSTUB(open                                   ,0xff81aadc) //  1
NHSTUB(OpenFastDir                            ,0xffacded8) //  4
NHSTUB(qsort                                  ,0xffb40804) //  4
NHSTUB(rand                                   ,0xffa4db2c) //  4
//NHSTUB(read                                 ,0xff81ad74) //101
NHSTUB(realloc                                ,0xffa4da68) //115
NHSTUB(reboot_fw_update                       ,0xffad344c) //106
NHSTUB(set_control_event                      ,0xff89fbc0) //111
NHSTUB(srand                                  ,0xffa4db20) //  4
NHSTUB(stat                                   ,0xff837240) //109
NHSTUB(strcat                                 ,0xff8b9a20) //  1
NHSTUB(strchr                                 ,0xff8140b4) //  1
NHSTUB(strcmp                                 ,0xff82068c) //101
NHSTUB(strcpy                                 ,0xff820674) //101
NHSTUB(strftime                               ,0xff8b9c6c) //113
NHSTUB(strlen                                 ,0xff814100) //101
NHSTUB(strncmp                                ,0xff814068) //  1
NHSTUB(strncpy                                ,0xff81402c) //  1
NHSTUB(strrchr                                ,0xff8140d8) //  1
NHSTUB(strtol                                 ,0xff840a30) //101
NHSTUB(strtolx                                ,0xff840834) //109
   DEF(task_CaptSeq                           ,0xff8868c4) //107
   DEF(task_ExpDrv                            ,0xff8d081c) //110
   DEF(task_InitFileModules                   ,0xff8a3b50) //107
   DEF(task_MovieRecord                       ,0xff88334c) //107
   DEF(task_PhySw                             ,0xff8345e8) //107
   DEF(task_RotaryEncoder                     ,0xff865d08) //107
NHSTUB(time                                   ,0xff893b8c) //109
NHSTUB(vsprintf                               ,0xff820638) //115
//NHSTUB(write                                ,0xff83716c) //101
//NHSTUB(EngDrvIn                             ,0xff8358b8) //102
//NHSTUB(EngDrvOut                            ,0xff8358a0) //102
//NHSTUB(EngDrvRead                           ,0xff8358c0) //102
//NHSTUB(EngDrvBits                           ,0xff8358d4) //102
//NHSTUB(GetSDProtect                         ,0xff8349c0) //103
//NHSTUB(StartRecModeMenu                     ,0xff89a56c) //102
//NHSTUB(DispCon_ShowBitmapColorBar           ,0xff85ece8) //102
//NHSTUB(ResetZoomLens                        ,0xffae9608) //102
//NHSTUB(ResetFocusLens                       ,0xffae8504) //102
//NHSTUB(NR_GetDarkSubType                    ,0xff99587c) //102
//NHSTUB(NR_SetDarkSubType                    ,0xff9957cc) //102
//NHSTUB(SavePaletteData                      ,0xffb5828c) //102
//NHSTUB(GUISrv_StartGUISystem                ,0xff8b790c) //101
