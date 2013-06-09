// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R45 (DRYOS version 2.3, release #0045)
//   Firmware Ver GM1.00H
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
// Firmware modemap table found @ff8a3cc0 -> ff8a068c -> ff9c1110 -> ffb00d0c -> ffc67954
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00034594) // Found @0xff8349f0
DEF(physw_run                               ,0x00001c3c) // Found @0xff8345ec
DEF(physw_sleep_delay                       ,0x00001c44) // Found @0xff8345ec
DEF(levent_table                            ,0xffc0e88c) // Found @0xffc0e88c
DEF(FlashParamsTable                        ,0xffc67b58) // Found @0xffc67b58
DEF(movie_status                            ,0x00003524) // Found @0xff882fc8
DEF(full_screen_refresh                     ,0x0000b198) // Found @0xffa46958
DEF(canon_menu_active                       ,0x00003a2c) // Found @0xff89a56c
DEF(canon_shoot_menu_active                 ,0x00009901) // Found @0xff9de9ac
DEF(playrec_mode                            ,0x00003758) // Found @0xff88c718
DEF(zoom_status                             ,0x0000e7c4) // Found @0xffb04790
DEF(some_flag_for_af_scan                   ,0x000085cc) // Found @0xff991078
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 1 int value, which is the the zoom focus length.
// there are 201 entries in the table - set NUM_FL to 201
DEF(focus_len_table                         ,0xfffea5cc) // Found @0xfffea5cc
DEF(zoom_busy                               ,0x00003448) // Found @0xff87e640
DEF(focus_busy                              ,0x00007a74) // Found @0xff97df38
DEF(recreview_hold                          ,0x0000468c) // Found @0xff8ac610
// Palette colour tables  found @ 0xffc2ada8
DEF(palette_control                         ,0x0000b198) // Found @0xffa468d4
DEF(active_palette_buffer                   ,0x0000b1a0) // Found @0xffa468d8
DEF(palette_buffer_ptr                      ,0x0000b1a4) // Found @0xffa46dfc
DEF(palette_buffer                          ,0x000cf9b4) // Found @0xffa46e0c
// Offset from start of palette_buffer to color data = 8 (Found @0xffb3cb98)
DEF(bitmap_buffer                           ,0x0000b1d4) // Found @0xffa4a864
DEF(active_bitmap_buffer                    ,0x0000b1cc) // Found @0xffa4a868
DEF(viewport_buffers                        ,0xffb968c4) // Found @0xff851a1c
DEF(active_viewport_buffer                  ,0x000020a8) // Found @0xff8517cc

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x40471000; }             // Found @0xff85ed30
//void *vid_get_viewport_fb()      { return (void*)0x40587700; }             // Found @0xffb56ae0
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x32b0+0x58)); } // Found @0xff878ab0 & 0xff878ae8
//char *camera_jpeg_count_str()    { return (char*)0x000cf2fc; }             // Found @0xffa3bb3c
//long hook_raw_size()             { return 0x014eb7e0; }                    // Found @0xffb59fa0
//int get_flash_params_count(void) { return 0x9a; }                          // Found @0xff9c26a8

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffb97a1c, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x04000000 // Found @0xffb97a4c, levent 0x902
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_UP              ,0x00000400 }, // Found @0xffb97954, levent 0x04
//    { 0, KEY_DOWN            ,0x00000800 }, // Found @0xffb9795c, levent 0x05
//    { 0, KEY_LEFT            ,0x00001000 }, // Found @0xffb97964, levent 0x06
//    { 0, KEY_RIGHT           ,0x00002000 }, // Found @0xffb9796c, levent 0x07
//    { 0, KEY_SET             ,0x00004000 }, // Found @0xffb97974, levent 0x08
//    { 0, KEY_VIDEO           ,0x00008000 }, // Found @0xffb9797c, levent 0x12
//    { 0, KEY_DISPLAY         ,0x00020000 }, // Found @0xffb9798c, levent 0x0a
//    { 0, KEY_MENU            ,0x00040000 }, // Found @0xffb97994, levent 0x09
//    { 2, KEY_SHOOT_FULL      ,0x00000300 }, // Found @0xffb979f4, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000200 }, // Found @0xffb979f4, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00000100 }, // Found @0xffb979ec, levent 0x00
//    { 2, KEY_POWER           ,0x00000400 }, // Found @0xffb979fc, levent 0x600
//    { 2, KEY_PLAYBACK        ,0x00000800 }, // Found @0xffb97a04, levent 0x601
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_RAW_ROWPIX    4464 // Found @0xff957868
//#define CAM_RAW_ROWS      3276 // Found @0xff957874
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff83afdc

// Misc stuff
DEF(ctypes, 0xffb961be)

// For capt_seq.c
DEF(_nrflag,0x8610) // Found @ ff99562c (0x8608) & ff995660 (+0x08)
//static long *nrflag = (long*)(0x8608+0x08);  // Found @ ff99562c & ff995660
//#define NR_AUTO (0)                          // have to explictly reset value back to 0 to enable auto

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
//NHSTUB(CreateJumptable                      ,0xffb5a168) //  1
//NHSTUB(_uartr_req                           ,0xff81fc4c) //111
//NHSTUB(AllocateMemory                       ,0xffaee008) //101
NHSTUB(AllocateUncacheableMemory              ,0xff83af98) //112
NHSTUB(Close                                  ,0xff8370dc) //101
NHSTUB(CreateTask                             ,0xff81e8a0) //101
NHSTUB(DebugAssert                            ,0xff81eb78) //111
NHSTUB(DeleteDirectory_Fut                    ,0xff836b38) //116
NHSTUB(DeleteFile_Fut                         ,0xff836a54) //112
NHSTUB(DoAFLock                               ,0xff838ab8) //102
NHSTUB(EnterToCompensationEVF                 ,0xff838d44) //104
NHSTUB(ExecuteEventProcedure                  ,0xff895cc0) //104
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
//NHSTUB(FreeMemory                           ,0xffaee000) //101
NHSTUB(FreeUncacheableMemory                  ,0xff83afd8) //112
NHSTUB(Fseek_Fut                              ,0xff836d70) //101
NHSTUB(Fwrite_Fut                             ,0xff836cd0) //101
NHSTUB(GetBatteryTemperature                  ,0xff8697ac) //102
NHSTUB(GetCCDTemperature                      ,0xff869738) //102
NHSTUB(GetCurrentAvValue                      ,0xff98067c) //102
NHSTUB(GetDrive_ClusterSize                   ,0xff87724c) //  4
NHSTUB(GetDrive_FreeClusters                  ,0xff8772ac) //  4
NHSTUB(GetDrive_TotalClusters                 ,0xff877280) //  3
NHSTUB(GetFocusLensSubjectDistance            ,0xff97ea7c) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff97eef4) //  3
NHSTUB(GetImageFolder                         ,0xff95f0ec) //106
NHSTUB(GetKbdState                            ,0xff865a28) //109
NHSTUB(GetMemInfo                             ,0xff81a264) //115
NHSTUB(GetOpticalTemperature                  ,0xff869820) //102
NHSTUB(GetParameterData                       ,0xff9c266c) //101
NHSTUB(GetPropertyCase                        ,0xff8999c8) //102
NHSTUB(GetSystemTime                          ,0xffaee060) //101
NHSTUB(GetVRAMHPixelsSize                     ,0xff85413c) //102
NHSTUB(GetVRAMVPixelsSize                     ,0xff854148) //102
NHSTUB(GetZoomLensCurrentPoint                ,0xff87e9c4) //102
NHSTUB(GetZoomLensCurrentPosition             ,0xff9864a8) //102
NHSTUB(GiveSemaphore                          ,0xff83a9b4) //112
NHSTUB(IsStrobeChargeCompleted                ,0xff8ec168) //102
NHSTUB(LEDDrive                               ,0xff864bd4) //103
NHSTUB(LocalTime                              ,0xff8935a8) //115
NHSTUB(LockMainPower                          ,0xff8a0290) //103
//NHSTUB(Lseek                                ,0xff8371f8) //101
NHSTUB(MakeDirectory_Fut                      ,0xff836ac8) //116
NHSTUB(MoveFocusLensToDistance                ,0xffb52e10) //102
NHSTUB(MoveIrisWithAv                         ,0xffae8e14) //102
NHSTUB(MoveZoomLensWithPoint                  ,0xffae950c) //102
//NHSTUB(NewTaskShell                         ,0xff8993e4) //103
NHSTUB(Open                                   ,0xff837070) //101
NHSTUB(PB2Rec                                 ,0xff8a30f8) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff883c2c) //102
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff883c04) //102
NHSTUB(PT_PlaySound                           ,0xff88e65c) //  4
NHSTUB(PostLogicalEventForNotPowerType        ,0xff89e028) //103
NHSTUB(PostLogicalEventToUI                   ,0xff89e074) //103
NHSTUB(PutInNdFilter                          ,0xffb50a84) //102
NHSTUB(PutOutNdFilter                         ,0xffb50abc) //102
NHSTUB(Read                                   ,0xff81ad74) //101
NHSTUB(ReadFastDir                            ,0xffacde84) //  4
NHSTUB(Rec2PB                                 ,0xff8a1b3c) //104
NHSTUB(RefreshPhysicalScreen                  ,0xff8b8110) //104
//NHSTUB(Remove                               ,0xff837110) //  4
NHSTUB(RenameFile_Fut                         ,0xff8369c0) //116
NHSTUB(Restart                                ,0xff83c788) //106
NHSTUB(ScreenLock                             ,0xff8b9340) //  4
NHSTUB(ScreenUnlock                           ,0xff8b93a4) //  3
NHSTUB(SetAE_ShutterSpeed                     ,0xffb55c58) //102
NHSTUB(SetAutoShutdownTime                    ,0xff8a0304) //103
NHSTUB(SetCurrentCaptureModeType              ,0xff8a9228) //101
NHSTUB(SetFileAttributes                      ,0xff8373d4) //  3
NHSTUB(SetFileTimeStamp                       ,0xff837378) //  4
NHSTUB(SetLogicalEventActive                  ,0xff89ffcc) //101
NHSTUB(SetParameterData                       ,0xff9c2544) //101
NHSTUB(SetPropertyCase                        ,0xff8998a0) //102
NHSTUB(SetScriptMode                          ,0xff8a001c) //101
NHSTUB(SleepTask                              ,0xff83ac1c) //101
NHSTUB(TakeSemaphore                          ,0xff83a8e4) //101
NHSTUB(TurnOffBackLight                       ,0xff8b0598) //104
NHSTUB(TurnOnBackLight                        ,0xff8b0580) //104
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff9aed10) //101
NHSTUB(UnlockAF                               ,0xff838af0) //102
NHSTUB(UnlockMainPower                        ,0xff8a01e4) //103
NHSTUB(UpdateMBROnFlash                       ,0xff8770cc) //105
NHSTUB(VbattGet                               ,0xff833178) //103
NHSTUB(Write                                  ,0xff83716c) //101
NHSTUB(WriteSDCard                            ,0xff96dab0) //108
NHSTUB(_log                                   ,0xffb93b08) //111
NHSTUB(_log10                                 ,0xffb92a4c) //112
NHSTUB(_pow                                   ,0xffb92bbc) //114
NHSTUB(_sqrt                                  ,0xffb94ed4) //  1
NHSTUB(add_ptp_handler                        ,0xffa8ea38) //  3
NHSTUB(apex2us                                ,0xffa4e848) //  4
NHSTUB(close                                  ,0xff81ab8c) //  1
NHSTUB(closedir                               ,0xffacdce0) //  4
NHSTUB(err_init_task                          ,0xff815fd4) //111
NHSTUB(exmem_alloc                            ,0xff8944f4) //103
NHSTUB(exmem_free                             ,0xff89456c) //103
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
NHSTUB(memset                                 ,0xffa4d844) //101
NHSTUB(mkdir                                  ,0xff837578) //109
NHSTUB(mktime_ext                             ,0xff8ba260) //  1
NHSTUB(open                                   ,0xff81aadc) //  1
NHSTUB(OpenFastDir                            ,0xffacdd30) //  4
NHSTUB(qsort                                  ,0xffb4065c) //  4
NHSTUB(rand                                   ,0xffa4d984) //  4
//NHSTUB(read                                 ,0xff81ad74) //101
NHSTUB(realloc                                ,0xffa4d8c0) //115
NHSTUB(reboot_fw_update                       ,0xffad32a4) //106
NHSTUB(set_control_event                      ,0xff89fbbc) //111
NHSTUB(srand                                  ,0xffa4d978) //  4
NHSTUB(stat                                   ,0xff837240) //109
NHSTUB(strcat                                 ,0xff8b9a1c) //  1
NHSTUB(strchr                                 ,0xff8140b4) //  1
NHSTUB(strcmp                                 ,0xff82068c) //101
NHSTUB(strcpy                                 ,0xff820674) //101
NHSTUB(strftime                               ,0xff8b9c68) //113
NHSTUB(strlen                                 ,0xff814100) //101
NHSTUB(strncmp                                ,0xff814068) //  1
NHSTUB(strncpy                                ,0xff81402c) //  1
NHSTUB(strrchr                                ,0xff8140d8) //  1
NHSTUB(strtol                                 ,0xff840a30) //101
NHSTUB(strtolx                                ,0xff840834) //109
   DEF(task_CaptSeq                           ,0xff8868c0) //107
   DEF(task_ExpDrv                            ,0xff8d0818) //110
   DEF(task_InitFileModules                   ,0xff8a3b4c) //107
   DEF(task_MovieRecord                       ,0xff883348) //107
   DEF(task_PhySw                             ,0xff8345e8) //107
   DEF(task_RotaryEncoder                     ,0xff865d08) //107
NHSTUB(time                                   ,0xff893b88) //109
NHSTUB(vsprintf                               ,0xff820638) //115
//NHSTUB(write                                ,0xff83716c) //101
//NHSTUB(EngDrvIn                             ,0xff8358b8) //102
//NHSTUB(EngDrvOut                            ,0xff8358a0) //102
//NHSTUB(EngDrvRead                           ,0xff8358c0) //102
//NHSTUB(EngDrvBits                           ,0xff8358d4) //102
//NHSTUB(GetSDProtect                         ,0xff8349c0) //103
//NHSTUB(StartRecModeMenu                     ,0xff89a568) //102
//NHSTUB(DispCon_ShowBitmapColorBar           ,0xff85ece8) //102
//NHSTUB(ResetZoomLens                        ,0xffae9460) //102
//NHSTUB(ResetFocusLens                       ,0xffae835c) //102
//NHSTUB(NR_GetDarkSubType                    ,0xff9956d4) //102
//NHSTUB(NR_SetDarkSubType                    ,0xff995624) //102
//NHSTUB(SavePaletteData                      ,0xffb580e4) //102
//NHSTUB(GUISrv_StartGUISystem                ,0xff8b7908) //101
